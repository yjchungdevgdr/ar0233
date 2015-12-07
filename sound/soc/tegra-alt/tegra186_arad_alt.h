/*
 * tegra186_arad_alt.h - Definitions for Tegra186 ARAD driver
 *
 * Copyright (c) 2015-2016, NVIDIA CORPORATION.  All rights reserved.
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

#ifndef __TEGRA186_ARAD_ALT_H__
#define __TEGRA186_ARAD_ALT_H__

#define TEGRA186_ARAD_LANE_STRIDE				0x38
#define TEGRA186_ARAD_LANE_START				0x40
#define TEGRA186_ARAD_LANE_MAX					6
#define TEGRA186_ARAD_LANE_LIMIT		(TEGRA186_ARAD_LANE_START + (TEGRA186_ARAD_LANE_MAX * TEGRA186_ARAD_LANE_STRIDE))

#define TEGRA186_ARAD_LANE_ENABLE			0x0
#define TEGRA186_ARAD_LANE_STATUS			0x4
#define TEGRA186_ARAD_LANE_SOFT_RESET		0x8
#define TEGRA186_ARAD_LANE_INT_STATUS		0xc
#define TEGRA186_ARAD_LANE_INT_MASK			0x10
#define TEGRA186_ARAD_LANE_INT_SET			0x14
#define TEGRA186_ARAD_LANE_INT_CLEAR			0x18
#define TEGRA186_ARAD_LANE_INT_RATIO_CHANGE_MASK	(0x3f<<16)
#define TEGRA186_ARAD_LANE_INT_LOCK_CHANGE_MASK		0x3f
#define TEGRA186_ARAD_LANE_INT_RATIO_CHANGE_SHIFT	16
#define TEGRA186_ARAD_LANE_INT_LOCK_CHANGE_SHIFT	0

#define TEGRA186_ARAD_GLOBAL_SOFT_RESET		0x1c
#define TEGRA186_ARAD_CG					0x20
#define TEGRA186_ARAD_STATUS				0x24
#define TEGRA186_ARAD_SEND_RATIO			0x28
#define TEGRA186_ARAD_CYA_GLOBAL			0x2c
#define TEGRA186_ARAD_TX_CIF_CTRL			0x178

#define TEGRA186_ARAD_LANE1_NUMERATOR_MUX_SEL				0x40
#define TEGRA186_ARAD_LANE1_NUMERATOR_PRESCALAR				0x44
#define TEGRA186_ARAD_LANE1_DENOMINATOR_MUX_SEL				0x48
#define TEGRA186_ARAD_LANE1_DENOMINATOR_PRESCALAR			0x4c
#define TEGRA186_ARAD_LANE1_RATIO_INTEGER_PART				0x50
#define TEGRA186_ARAD_LANE1_RATIO_FRACTIONAL_PART			0x54
#define TEGRA186_ARAD_LANE1_PERIOD_COUNT			0x58
#define TEGRA186_ARAD_LANE1_SERVO_LOOP_CONFIG				0x5c
#define TEGRA186_ARAD_LANE1_LOCK_UNLOCK_DETECTOR_CONFIG		0x60
#define TEGRA186_ARAD_LANE1_ERROR_LOCK_THRESHOLD			0x64
#define TEGRA186_ARAD_LANE1_ERROR_UNLOCK_THRESHOLD			0x68
#define TEGRA186_ARAD_LANE1_RATIO_CALCULATOR_CONFIG			0x6c
#define TEGRA186_ARAD_LANE1_CYA					0x70

#define TEGRA186_ARAD_LANE2_NUMERATOR_MUX_SEL				0x78
#define TEGRA186_ARAD_LANE2_DENOMINATOR_MUX_SEL				0x80
#define TEGRA186_ARAD_LANE3_NUMERATOR_MUX_SEL				0xb0
#define TEGRA186_ARAD_LANE3_DENOMINATOR_MUX_SEL				0xb8
#define TEGRA186_ARAD_LANE4_NUMERATOR_MUX_SEL				0xe8
#define TEGRA186_ARAD_LANE4_DENOMINATOR_MUX_SEL				0xf0
#define TEGRA186_ARAD_LANE5_NUMERATOR_MUX_SEL				0x120
#define TEGRA186_ARAD_LANE5_DENOMINATOR_MUX_SEL				0x128
#define TEGRA186_ARAD_LANE6_NUMERATOR_MUX_SEL				0x158
#define TEGRA186_ARAD_LANE6_DENOMINATOR_MUX_SEL				0x160

#define TEGRA186_ARAD_LANE2_RATIO_INTEGER_PART				0x88
#define TEGRA186_ARAD_LANE2_RATIO_FRACTIONAL_PART			0x8c
#define TEGRA186_ARAD_LANE3_RATIO_INTEGER_PART				0xc0
#define TEGRA186_ARAD_LANE3_RATIO_FRACTIONAL_PART			0xc4
#define TEGRA186_ARAD_LANE4_RATIO_INTEGER_PART				0xf8
#define TEGRA186_ARAD_LANE4_RATIO_FRACTIONAL_PART			0xfc
#define TEGRA186_ARAD_LANE5_RATIO_INTEGER_PART				0x130
#define TEGRA186_ARAD_LANE5_RATIO_FRACTIONAL_PART			0x134
#define TEGRA186_ARAD_LANE6_RATIO_INTEGER_PART				0x168
#define TEGRA186_ARAD_LANE6_RATIO_FRACTIONAL_PART			0x16c

#define TEGRA186_ARAD_LANE_ENABLE_SHIFT		0
#define TEGRA186_ARAD_LANE_ENABLE_MASK		(0x3f << TEGRA186_ARAD_LANE_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE1_ENABLE_SHIFT	0
#define TEGRA186_ARAD_LANE1_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE1_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE2_ENABLE_SHIFT	1
#define TEGRA186_ARAD_LANE2_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE2_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE3_ENABLE_SHIFT	2
#define TEGRA186_ARAD_LANE3_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE3_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE4_ENABLE_SHIFT	3
#define TEGRA186_ARAD_LANE4_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE4_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE5_ENABLE_SHIFT	4
#define TEGRA186_ARAD_LANE5_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE5_ENABLE_SHIFT)
#define TEGRA186_ARAD_LANE6_ENABLE_SHIFT	5
#define TEGRA186_ARAD_LANE6_ENABLE_MASK		(0x1 << TEGRA186_ARAD_LANE6_ENABLE_SHIFT)

#define TEGRA186_ARAD_LANE_LOCK_STATUS_SHIFT		16
#define TEGRA186_ARAD_LANE_ENABLED_STATUS_SHIFT		0

#define TEGRA186_ARAD_LANE_RATIO_INTEGER_PART_MASK		0xFFFFFFFF
#define TEGRA186_ARAD_LANE_RATIO_FRAC_PART_MASK			0xFFFFFFFF

struct tegra186_arad_soc_data {
	void (*set_audio_cif)(struct regmap *map,
			unsigned int reg,
			struct tegra210_xbar_cif_conf *conf);
};

struct tegra186_arad {
	struct regmap *regmap;
	const struct tegra186_arad_soc_data *soc_data;
#if defined CONFIG_SND_SOC_TEGRA186_ARAD_WAR
	unsigned int int_status;
	spinlock_t status_lock;
#endif
};
void tegra186_arad_send_ratio(void);

#endif
