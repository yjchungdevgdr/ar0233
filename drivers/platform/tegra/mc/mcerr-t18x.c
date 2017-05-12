/*
 * Tegra 18x SoC-specific mcerr code.
 *
 * Copyright (c) 2015, NVIDIA Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#define pr_fmt(fmt) "mc-err: " fmt

#include <linux/bitops.h>
#include <linux/of.h>
#include <linux/platform/tegra/mcerr.h>
#include <dt-bindings/memory/tegra-swgroup.h>
#include <linux/interrupt.h>

/*** Auto generated by `mcp.pl'. Do not modify! ***/

static struct mc_client mc_clients[] = {
	client("ptc", "csr_ptcr", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csr_afir", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("hda", "csr_hdar", INVALID),
	client("hc", "csr_host1xdmar", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvenc", "csr_nvencsrd", INVALID),
	dummy_client,
	dummy_client,
	client("sata", "csr_satar", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("mpcore", "csr_mpcorer", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvenc", "csw_nvencswr", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("afi", "csw_afiw", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("hda", "csw_hdaw", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("mpcore", "csw_mpcorew", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	client("sata", "csw_sataw", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("isp2", "csr_ispra", INVALID),
	dummy_client,
	client("isp2", "csw_ispwa", INVALID),
	client("isp2", "csw_ispwb", INVALID),
	dummy_client,
	dummy_client,
	client("xusb_host", "csr_xusb_hostr", INVALID),
	client("xusb_host", "csw_xusb_hostw", INVALID),
	client("xusb_dev", "csr_xusb_devr", INVALID),
	client("xusb_dev", "csw_xusb_devw", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("tsec", "csr_tsecsrd", INVALID),
	client("tsec", "csw_tsecswr", INVALID),
	dummy_client,
	dummy_client,
	client("gpu", "csr_gpusrd", INVALID),
	client("gpu", "csw_gpuswr", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("sdmmc1a", "csr_sdmmcra", INVALID),
	client("sdmmc2a", "csr_sdmmcraa", INVALID),
	client("sdmmc3a", "csr_sdmmcr", INVALID),
	client("sdmmc4a", "csr_sdmmcrab", INVALID),
	client("sdmmc1a", "csw_sdmmcwa", INVALID),
	client("sdmmc2a", "csw_sdmmcwaa", INVALID),
	client("sdmmc3a", "csw_sdmmcw", INVALID),
	client("sdmmc4a", "csw_sdmmcwab", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vic", "csr_vicsrd", INVALID),
	client("vic", "csw_vicswr", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("vi", "csw_viw", INVALID),
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	dummy_client,
	client("nvdec", "csr_nvdecsrd", INVALID),
	client("nvdec", "csw_nvdecswr", INVALID),
	client("ape", "csr_aper", INVALID),
	client("ape", "csw_apew", INVALID),
	dummy_client,
	dummy_client,
	client("nvjpg", "csr_nvjpgsrd", INVALID),
	client("nvjpg", "csw_nvjpgswr", INVALID),
	client("se", "csr_sesrd", INVALID),
	client("se", "csw_seswr", INVALID),
	dummy_client,
	dummy_client,
	client("etr", "csr_etrr", INVALID),
	client("etr", "csw_etrw", INVALID),
	client("tsecb", "csr_tsecsrdb", INVALID),
	client("tsecb", "csw_tsecswrb", INVALID),
	client("gpu", "csr_gpusrd2", INVALID),
	client("gpu", "csw_gpuswr2", INVALID),
	dummy_client,
	dummy_client,
	client("axis", "csr_axisr", INVALID),
	client("axis", "csw_axisw", INVALID),
	client("eqos", "csr_eqosr", INVALID),
	client("eqos", "csw_eqosw", INVALID),
	client("ufshc", "csr_ufshcr", INVALID),
	client("ufshc", "csw_ufshcw", INVALID),
	client("nvdisplay", "csr_nvdisplayr", INVALID),
	client("bpmp", "csr_bpmpr", INVALID),
	client("bpmp", "csw_bpmpw", INVALID),
	client("bpmp", "csr_bpmpdmar", INVALID),
	client("bpmp", "csw_bpmpdmaw", INVALID),
	client("aon", "csr_aonr", INVALID),
	client("aon", "csw_aonw", INVALID),
	client("aon", "csr_aondmar", INVALID),
	client("aon", "csw_aondmaw", INVALID),
	client("sce", "csr_scer", INVALID),
	client("sce", "csw_scew", INVALID),
	client("sce", "csr_scedmar", INVALID),
	client("sce", "csw_scedmaw", INVALID),
	client("ape", "csr_apedmar", INVALID),
	client("ape", "csw_apedmaw", INVALID),
	client("nvdisplay", "csr_nvdisplayr1", INVALID),
	client("vic", "csr_vicsrd1", INVALID),
	client("nvdec", "csr_nvdecsrd1", INVALID),
};
static int mc_client_last = ARRAY_SIZE(mc_clients) - 1;
/*** Done. ***/

static const char *t186_intr_info[] = {
	NULL,		/* Bit 0 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 4 */
	NULL,
	"decerr-emem",
	NULL,
	"secerr",	/* Bit 8 */
	"arb-emem",
	NULL,
	NULL,
	"decerr-vpr",	/* Bit 12 */
	"decerr-sec",
	NULL,
	NULL,
	"decerr-mts",	/* Bit 16 */
	"decerr-gsc",
	"scrub-ecc",
	"wcam-err",
	NULL,		/* Bit 20 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 24 */
	NULL,
	NULL,
	NULL,
	NULL,		/* Bit 28 */
	NULL,
	NULL,
	NULL,
};

#define MC_INT_DECERR_MTS			(1<<16)
#define MC_INT_WCAM_ERR				(1<<19)

/* hub common int status */
#define MC_HUBC_INT_SCRUB_ECC_WR_ACK		(1 << 0)

/* reported in MC_INTSTATUS_0 */
static const struct mc_error hub_mc_errors[] = {
	MC_ERR(MC_INT_DECERR_EMEM,
	       "EMEM address decode error",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_SECURITY_VIOLATION,
	       "non secure access to secure region",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_DECERR_VPR,
	       "MC request violates VPR requirements",
	       E_VPR, MC_ERR_VPR_STATUS, MC_ERR_VPR_ADR),
	MC_ERR(MC_INT_SECERR_SEC,
	       "MC request violated SEC carveout requirements",
	       0, MC_ERR_SEC_STATUS, MC_ERR_SEC_ADR),
	MC_ERR(MC_INT_DECERR_MTS,
	       "MTS carveout access violation",
	       0, MC_ERR_MTS_STATUS, MC_ERR_MTS_ADR),
	MC_ERR(MC_INT_DECERR_GENERALIZED_CARVEOUT,
	       "GSC access violation", 0,
	       MC_ERR_GENERALIZED_CARVEOUT_STATUS,
	       MC_ERR_GENERALIZED_CARVEOUT_ADR),

	/* combination interrupts */
	MC_ERR(MC_INT_DECERR_EMEM | MC_INT_SECURITY_VIOLATION,
	       "non secure access to secure region",
	       0, MC_ERR_STATUS, MC_ERR_ADR),
	MC_ERR(MC_INT_DECERR_GENERALIZED_CARVEOUT | MC_INT_DECERR_EMEM,
	       "EMEM GSC access violation", 0,
	       MC_ERR_GENERALIZED_CARVEOUT_STATUS,
	       MC_ERR_GENERALIZED_CARVEOUT_ADR),

	/* NULL terminate. */
	MC_ERR(0, NULL, 0, 0, 0),
};

/* reported in MC_CH_INTSTATUS_0 */
static const struct mc_error ch_mc_errors[] = {
	MC_ERR(MC_INT_WCAM_ERR, "WCAM error", E_TWO_STATUS,
	       MC_WCAM_IRQ_P0_STATUS0,
	       MC_WCAM_IRQ_P1_STATUS0),

	/* NULL terminate. */
	MC_ERR(0, NULL, 0, 0, 0),
};

/* reported in MC_HUBC_INTSTATUS_0 */
static const struct mc_error hubc_mc_errors[] = {
	MC_ERR(MC_HUBC_INT_SCRUB_ECC_WR_ACK,
	       "ECC scrub complete", E_NO_STATUS, 0, 0),

	/* NULL terminate. */
	MC_ERR(0, NULL, 0, 0, 0),
};

enum {
	INTSTATUS_CH0 = 0,
	INTSTATUS_CH1 = 1,
	INTSTATUS_CH2 = 2,
	INTSTATUS_CH3 = 3,
	INTSTATUS_HUB0 = 16,
	INTSTATUS_HUB1 = 17,
	INTSTATUS_HUBC = 24,
};

#define MC_INTSTATUS_CLEAR 0x00033340
#define MC_CH_INTSTATUS_CLEAR 0x00080200
#define MC_HUBC_INTSTATUS_CLEAR 0x00000001
#define MC_GLOBAL_INTSTATUS_CLEAR 0x0103000F

static void clear_interrupt(unsigned int irq)
{
	mc_writel(MC_INTSTATUS_CLEAR, MC_INTSTATUS);
	mc_writel(MC_CH_INTSTATUS_CLEAR, MC_CH_INTSTATUS);
	mc_writel(MC_HUBC_INTSTATUS_CLEAR, MC_HUBC_INTSTATUS);
	mc_writel(MC_GLOBAL_INTSTATUS_CLEAR, MC_GLOBAL_INTSTATUS);
}

static void log_fault(int src_chan, const struct mc_error *fault)
{
	phys_addr_t addr;
	struct mc_client *client;
	u32 status, write, secure, client_id;


	if (fault->flags & E_VPR)
		mcerr_pr("vpr base=%x:%x, size=%x, ctrl=%x, override:(%x, %x, %x, %x)\n",
			 mc_readl(MC_VIDEO_PROTECT_BOM_ADR_HI),
			 mc_readl(MC_VIDEO_PROTECT_BOM),
			 mc_readl(MC_VIDEO_PROTECT_SIZE_MB),
			 mc_readl(MC_VIDEO_PROTECT_REG_CTRL),
			 mc_readl(MC_VIDEO_PROTECT_VPR_OVERRIDE),
			 mc_readl(MC_VIDEO_PROTECT_VPR_OVERRIDE1),
			 mc_readl(MC_VIDEO_PROTECT_GPU_OVERRIDE_0),
			 mc_readl(MC_VIDEO_PROTECT_GPU_OVERRIDE_1));

	if (fault->flags & E_NO_STATUS) {
		mcerr_pr("MC fault - no status: %s\n", fault->msg);
		return;
	}

	status = __mc_readl(src_chan, fault->stat_reg);
	addr = __mc_readl(src_chan, fault->addr_reg);

	if (fault->flags & E_TWO_STATUS) {
		mcerr_pr("MC fault - %s\n", fault->msg);
		mcerr_pr("status: 0x%08x status2: 0x%08llx\n",
			status, addr);
		return;
	}

	secure = !!(status & MC_ERR_STATUS_SECURE);
	write = !!(status & MC_ERR_STATUS_WRITE);
	client_id = status & 0xff;
	client = &mc_clients[client_id <= mc_client_last
			     ? client_id : mc_client_last];

	/*
	 * LPAE: make sure we get the extra 2 physical address bits available
	 * and pass them down to the printing function.
	 */
	addr |= (((phys_addr_t)(status & MC_ERR_STATUS_ADR_HI)) << 12);

	mcerr_pr("(%d) %s: %s\n", client->swgid, client->name, fault->msg);
	mcerr_pr("  status = 0x%08x; addr = 0x%08llx\n", status,
		 (long long unsigned int)addr);
	mcerr_pr("  secure: %s, access-type: %s\n",
		secure ? "yes" : "no", write ? "write" : "read");
}

static void log_mcerr_fault(unsigned int irq)
{
	int faults_handled = 0;
	const struct mc_error *err;
	int mc_channel = MC_BROADCAST_CHANNEL;
	u32 int_status, ch_int_status, hubc_int_status;
	u32 g_intstatus = mc_readl(MC_GLOBAL_INTSTATUS);

	/*
	 * If multiple interrupts come in just handle the first one we see. The
	 * HW only keeps track of 1 interrupt's data and we don't know which
	 * particular fault is actually being kept...
	 */
	if (g_intstatus & (BIT(INTSTATUS_CH0)) ||
	    g_intstatus & (BIT(INTSTATUS_HUB0))) {
		mc_channel = 0;
	} else if (g_intstatus & (BIT(INTSTATUS_CH1)) ||
		   g_intstatus & (BIT(INTSTATUS_HUB1))) {
		mc_channel = 1;
	} else if (g_intstatus & (BIT(INTSTATUS_CH2))) {
		mc_channel = 2;
	} else if (g_intstatus & (BIT(INTSTATUS_CH3))) {
		mc_channel = 3;
	} else if (g_intstatus & (BIT(INTSTATUS_HUBC))) {
		mc_channel = MC_BROADCAST_CHANNEL;
	} else {
		trace_printk("mcerr: unknown source (intstatus = 0x%08x)\n",
			     g_intstatus);
		return;
	}

	int_status = __mc_readl(mc_channel, MC_INTSTATUS);
	ch_int_status = __mc_readl(mc_channel, MC_CH_INTSTATUS);
	hubc_int_status = __mc_readl(mc_channel, MC_HUBC_INTSTATUS);

	for (err = hub_mc_errors; err->sig && err->msg; err++) {
		if ((int_status & mc_int_mask) != err->sig)
			continue;
		log_fault(mc_channel, err);
		__mc_writel(mc_channel, int_status, MC_INTSTATUS);
		faults_handled++;
		break;
	}

	for (err = ch_mc_errors; err->sig && err->msg; err++) {
		if ((ch_int_status) != err->sig)
			continue;
		log_fault(mc_channel, err);
		__mc_writel(mc_channel, ch_int_status, MC_CH_INTSTATUS);
		faults_handled++;
		break;
	}

	for (err = hubc_mc_errors; err->sig && err->msg; err++) {
		if ((hubc_int_status) != err->sig)
			continue;
		log_fault(mc_channel, err);
		__mc_writel(mc_channel, hubc_int_status, MC_HUBC_INTSTATUS);
		faults_handled++;
		break;
	}

	if (!faults_handled)
		pr_err("unknown mcerr fault, int_status=0x%08x, "
			"ch_int_status=0x%08x, hubc_int_status=0x%08x\n",
			int_status, ch_int_status, hubc_int_status);
}

static struct mcerr_ops mcerr_ops = {
	.nr_clients = ARRAY_SIZE(mc_clients),
	.intr_descriptions = t186_intr_info,
	.clear_interrupt = clear_interrupt,
	.log_mcerr_fault = log_mcerr_fault,
	.mc_clients = mc_clients,
};

static struct mcerr_ops *t18x_mcerr_of_setup(struct device_node *np)
{
	pr_info("mcerr ops are set to t18x\n");
	return &mcerr_ops;
}

MCERR_OF_DECLARE(mcerr_of, "nvidia,tegra-t18x-mc", t18x_mcerr_of_setup);
