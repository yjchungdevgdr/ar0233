/*
 * isc_dev.c - ISC generic i2c driver.
 *
 * Copyright (c) 2015, NVIDIA Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/i2c.h>
#include <linux/miscdevice.h>
#include <linux/regulator/consumer.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/regmap.h>
#include <media/isc-dev.h>
#include <media/isc-mgr.h>

/*#define DEBUG_I2C_TRAFFIC */

struct isc_dev_info {
	struct i2c_client *i2c_client;
	struct device *dev;
	struct miscdevice miscdev;
	struct regmap_config regmap_cfg;
	struct regmap *regmap;
	struct isc_dev_platform_data *pdata;
	atomic_t in_use;
	struct mutex mutex;
	u8 power_is_on;
	char devname[32];
	struct isc_dev_package package;
	struct isc_dev_pkg rw_pkg;
#if (defined(DEBUG) || defined(DEBUG_I2C_TRAFFIC))
	char dump_buf[32 + 3 * 16];
#endif
};

static const struct regmap_config default_regmap_config = {
	.reg_bits = 16,
	.val_bits = 8,
};

static void isc_dev_dump(
	const char *str,
	struct isc_dev_info *info,
	unsigned int offset,
	u8 *buf, size_t size)
{
#if (defined(DEBUG) || defined(DEBUG_I2C_TRAFFIC))
	int len;
	int i;

	len = sprintf(info->dump_buf, "%s %04x =", str, offset);
	for (i = 0; i < size && len < sizeof(info->dump_buf) - 1; i++)
		len += sprintf(info->dump_buf + len, " %02x", buf[i]);
	info->dump_buf[len] = 0;
	dev_err(info->dev, "%s\n", info->dump_buf);
#endif
}

static int isc_dev_raw_rd(
	struct isc_dev_info *info, unsigned int offset, void *val, size_t size)
{
	int ret = -ENODEV;

	dev_dbg(info->dev, "%s\n", __func__);
	mutex_lock(&info->mutex);
	if (info->power_is_on) {
		ret = regmap_raw_read(info->regmap, offset, val, size);
	} else
		dev_err(info->dev, "%s: power is off.\n", __func__);
	mutex_unlock(&info->mutex);

	if (!ret)
		isc_dev_dump(__func__, info, offset, val, size);

	return ret;
}

static int isc_dev_raw_wr(
	struct isc_dev_info *info, unsigned int offset, void *val, size_t size)
{
	int ret = -ENODEV;

	dev_dbg(info->dev, "%s\n", __func__);
	isc_dev_dump(__func__, info, offset, val, size);

	mutex_lock(&info->mutex);
	if (info->power_is_on)
		ret = regmap_raw_write(
			info->regmap, offset, val, size);
	else
		dev_err(info->dev, "%s: power is off.\n", __func__);
	mutex_unlock(&info->mutex);

	return ret;
}

static int isc_dev_raw_rw(struct isc_dev_info *info)
{
	struct isc_dev_pkg *pkg = &info->rw_pkg;
	void *u_ptr = (void *)pkg->buffer;
	u8 *buf;
	int ret = -ENODEV;

	dev_dbg(info->dev, "%s\n", __func__);

	buf = kzalloc(pkg->size, GFP_KERNEL);
	if (buf == NULL) {
		dev_err(info->dev, "%s: Unable to allocate memory!\n",
			__func__);
		return -ENOMEM;
	}
	if (pkg->flags & ISC_DEV_PKG_FLAG_WR) {
		/* write to device */
		if (copy_from_user(buf,
			(const void __user *)u_ptr, pkg->size)) {
			dev_err(info->dev, "%s copy_from_user err line %d\n",
				__func__, __LINE__);
			kfree(buf);
			return -EFAULT;
		}
		ret = isc_dev_raw_wr(info, pkg->offset, buf, pkg->size);
	} else {
		/* read from device */
		ret = isc_dev_raw_rd(info, pkg->offset, buf, pkg->size);
		if (!ret && copy_to_user(
			(void __user *)u_ptr, buf, pkg->size)) {
			dev_err(info->dev, "%s copy_to_user err line %d\n",
				__func__, __LINE__);
			ret = -EINVAL;
		}
	}

	kfree(buf);
	return ret;
}

static int isc_dev_get_pkg(
	struct isc_dev_info *info, unsigned long arg, bool is_compat)
{
	if (is_compat) {
		struct isc_dev_pkg32 pkg32;
		if (copy_from_user(&pkg32,
			(const void __user *)arg, sizeof(pkg32))) {
			dev_err(info->dev, "%s copy_from_user err line %d\n",
				__func__, __LINE__);
			return -EFAULT;
		}
		info->rw_pkg.offset = pkg32.offset;
		info->rw_pkg.size = pkg32.size;
		info->rw_pkg.flags = pkg32.flags;
		info->rw_pkg.buffer = (unsigned long)pkg32.buffer;
	} else if (copy_from_user(&info->rw_pkg,
		(const void __user *)arg, sizeof(info->rw_pkg))) {
		dev_err(info->dev, "%s copy_from_user err line %d\n",
			__func__, __LINE__);
		return -EFAULT;
	}

	if ((void __user *)info->rw_pkg.buffer == NULL) {
		dev_err(info->dev, "%s package buffer NULL\n", __func__);
		return -EINVAL;
	}

	if (!info->rw_pkg.size ||
		(info->rw_pkg.size > 4000)) {
		dev_err(info->dev, "%s invalid package size %d\n",
			__func__, info->rw_pkg.size);
		return -EINVAL;
	}

	return 0;
}

/* to be deprecated. */
static int isc_dev_get_package(struct isc_dev_info *info, unsigned long arg)
{
	if (copy_from_user(&info->package,
		(const void __user *)arg, sizeof(info->package))) {
		dev_err(info->dev, "%s copy_from_user err line %d\n",
			__func__, __LINE__);
		return -EFAULT;
	}

	if (!info->package.size ||
		(info->package.size > sizeof(info->package.buf))) {
		dev_err(info->dev, "%s invalid package size %d\n",
			__func__, info->package.size);
		return -EINVAL;
	}

	return 0;
}

/* to be deprecated. */
static inline int isc_dev_set_package(
	struct isc_dev_info *info, unsigned long arg)
{
	if (copy_to_user((void __user *)arg, &info->package,
		sizeof(info->package))) {
		dev_err(info->dev, "%s copy_to_user err line %d\n",
			__func__, __LINE__);
		return -EFAULT;
	}

	return 0;
}

static long isc_dev_ioctl(struct file *file,
			unsigned int cmd, unsigned long arg)
{
	struct isc_dev_info *info = file->private_data;
	int err = 0;

	switch (cmd) {
	/* to be deprecated. */
	case ISC_DEV_IOCTL_READ:
		err = isc_dev_get_package(info, arg);
		if (err)
			break;

		err = isc_dev_raw_rd(info, info->package.offset,
			info->package.buf, info->package.size);
		if (err)
			break;

		err = isc_dev_set_package(info, arg);
		break;
	/* to be deprecated. */
	case ISC_DEV_IOCTL_WRITE:
		err = isc_dev_get_package(info, arg);
		if (err)
			break;

		err = isc_dev_raw_wr(info, info->package.offset,
			info->package.buf, info->package.size);
		break;
	case ISC_DEV_IOCTL_RDWR:
		err = isc_dev_get_pkg(info, arg, false);
		if (err)
			break;

		err = isc_dev_raw_rw(info);
		break;
	default:
		dev_dbg(info->dev, "%s: invalid cmd %x\n", __func__, cmd);
		return -EINVAL;
	}

	return err;
}

#ifdef CONFIG_COMPAT
static long isc_dev_ioctl32(struct file *file,
			unsigned int cmd, unsigned long arg)
{
	struct isc_dev_info *info = file->private_data;
	int err = 0;

	switch (cmd) {
	case ISC_DEV_IOCTL_RDWR32:
		err = isc_dev_get_pkg(info, arg, true);
		if (err)
			break;

		err = isc_dev_raw_rw(info);
		break;
	default:
		return isc_dev_ioctl(file, cmd, arg);
	}

	return err;
}
#endif

static int isc_dev_open(struct inode *inode, struct file *file)
{
	struct miscdevice *miscdev = file->private_data;
	struct isc_dev_info *info;

	info = container_of(miscdev, struct isc_dev_info, miscdev);
	if (!info)
		return -ENODEV;

	if (atomic_xchg(&info->in_use, 1))
		return -EBUSY;

	file->private_data = info;
	info->power_is_on = 1;
	dev_dbg(info->dev, "%s\n", __func__);
	return 0;
}

int isc_dev_release(struct inode *inode, struct file *file)
{
	struct isc_dev_info *info = file->private_data;

	dev_dbg(info->dev, "%s\n", __func__);
	info->power_is_on = 0;
	file->private_data = NULL;
	WARN_ON(!atomic_xchg(&info->in_use, 0));
	return 0;
}

static const struct file_operations isc_dev_fileops = {
	.owner = THIS_MODULE,
	.open = isc_dev_open,
	.unlocked_ioctl = isc_dev_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl = isc_dev_ioctl32,
#endif
	.release = isc_dev_release,
};

static int isc_dev_probe(struct i2c_client *client,
			const struct i2c_device_id *id)
{
	struct isc_dev_info *info;
	int err;

	dev_dbg(&client->dev, "%s: initializing link @%x-%04x\n",
		__func__, client->adapter->nr, client->addr);

	info = devm_kzalloc(
		&client->dev, sizeof(struct isc_dev_info), GFP_KERNEL);
	if (!info) {
		pr_err("%s: Unable to allocate memory!\n", __func__);
		return -ENOMEM;
	}

	mutex_init(&info->mutex);

	if (client->dev.platform_data) {
		info->pdata = client->dev.platform_data;
		dev_dbg(&client->dev, "pdata: %p\n", info->pdata);
	} else
		dev_notice(&client->dev, "%s NO platform data\n", __func__);

	if (info->pdata && info->pdata->regmap_cfg.name)
		memcpy(&info->regmap_cfg, &info->pdata->regmap_cfg,
			sizeof(info->regmap_cfg));
	else
		memcpy(&info->regmap_cfg, &default_regmap_config,
			sizeof(info->regmap_cfg));
	dev_dbg(&client->dev, "    %s - %d %d %d %d\n",
		info->regmap_cfg.name, info->regmap_cfg.reg_bits,
		info->regmap_cfg.val_bits, info->regmap_cfg.pad_bits,
		info->regmap_cfg.num_ranges);
	info->regmap = devm_regmap_init_i2c(client, &info->regmap_cfg);
	if (IS_ERR(info->regmap)) {
		dev_err(&client->dev,
			"regmap init failed: %ld\n", PTR_ERR(info->regmap));
		return -ENODEV;
	}

	info->i2c_client = client;
	info->dev = &client->dev;

	if (info->pdata && info->pdata->drv_name)
		strncpy(info->devname, info->pdata->drv_name,
			sizeof(info->devname));
	else
		snprintf(info->devname, sizeof(info->devname),
			"isc-dev.%u.%02x", client->adapter->nr, client->addr);

	info->miscdev.name = info->devname;
	info->miscdev.fops = &isc_dev_fileops;
	info->miscdev.minor = MISC_DYNAMIC_MINOR;
	info->miscdev.parent = &client->dev;
	err = misc_register(&info->miscdev);
	if (err) {
		pr_err("%s: Unable to register misc device!\n", __func__);
		devm_kfree(&client->dev, info);
		return err;
	}

	i2c_set_clientdata(client, info);
	return 0;
}

static int isc_dev_remove(struct i2c_client *client)
{
	struct isc_dev_info *info = i2c_get_clientdata(client);

	dev_dbg(info->dev, "%s\n", __func__);
	isc_delete_lst(info->pdata->isc_mgr, client);
	misc_deregister(&info->miscdev);
	return 0;
}

#ifdef CONFIG_PM
static int isc_dev_suspend(struct i2c_client *client, pm_message_t msg)
{
	struct isc_dev_info *info = i2c_get_clientdata(client);

	dev_info(info->dev, "Suspending\n");
	mutex_lock(&info->mutex);
	info->power_is_on = 0;
	mutex_unlock(&info->mutex);

	return 0;
}

static int isc_dev_resume(struct i2c_client *client)
{
	struct isc_dev_info *info = i2c_get_clientdata(client);

	dev_info(info->dev, "Resuming\n");
	mutex_lock(&info->mutex);
	info->power_is_on = 1;
	mutex_unlock(&info->mutex);

	return 0;
}

static void isc_dev_shutdown(struct i2c_client *client)
{
	struct isc_dev_info *info = i2c_get_clientdata(client);

	dev_info(info->dev, "Shutting down\n");
	mutex_lock(&info->mutex);
	info->power_is_on = 0;
	mutex_unlock(&info->mutex);
}
#endif

static const struct i2c_device_id isc_dev_id[] = {
	{ "isc-dev", 0 },
	{ },
};

static struct i2c_driver isc_dev_drv = {
	.driver = {
		.name = "isc-dev",
		.owner = THIS_MODULE,
	},
	.id_table = isc_dev_id,
	.probe = isc_dev_probe,
	.remove = isc_dev_remove,
#ifdef CONFIG_PM
	.shutdown = isc_dev_shutdown,
	.suspend  = isc_dev_suspend,
	.resume   = isc_dev_resume,
#endif
};

module_i2c_driver(isc_dev_drv);

MODULE_DESCRIPTION("ISC Generic I2C driver");
MODULE_AUTHOR("Charlie Huang <chahuang@nvidia.com>");
MODULE_LICENSE("GPL v2");
