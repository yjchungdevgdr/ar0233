/*
 * drivers/video/tegra/dc/sor_regs.h
 *
 * Copyright (c) 2011, NVIDIA Corporation.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DRIVER_VIDEO_TEGRA_DC_SOR_REGS_H__
#define __DRIVER_VIDEO_TEGRA_DC_SOR_REGS_H__


#define NV_SOR_CLK_CNTRL					(0x7)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_SHIFT			(0)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_MASK			(0x3)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_SINGLE_PCLK			(0)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_DIFF_PCLK			(1)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_SINGLE_DPCLK		(2)
#define NV_SOR_CLK_CNTRL_DP_CLK_SEL_DIFF_DPCLK			(3)
#define NV_SOR_CLK_CNTRL_DP_LINK_SPEED_SHIFT			(2)
#define NV_SOR_CLK_CNTRL_DP_LINK_SPEED_MASK			(0x1f << 2)
#define NV_SOR_CLK_CNTRL_DP_LINK_SPEED_G1_62			(6 << 2)
#define NV_SOR_CLK_CNTRL_DP_LINK_SPEED_G2_7			(10 << 2)
#define NV_SOR_CAP						(0x1e)
#define NV_SOR_CAP_DP_A_SHIFT					(24)
#define NV_SOR_CAP_DP_A_DEFAULT_MASK				(0x1 << 24)
#define NV_SOR_CAP_DP_A_FALSE					(0 << 24)
#define NV_SOR_CAP_DP_A_TRUE					(1 << 24)
#define NV_SOR_CAP_DP_B_SHIFT					(25)
#define NV_SOR_CAP_DP_B_DEFAULT_MASK				(0x1 << 24)
#define NV_SOR_CAP_DP_B_FALSE					(0 << 24)
#define NV_SOR_CAP_DP_B_TRUE					(1 << 24)
#define NV_SOR_PWR						(0x1f)
#define NV_SOR_PWR_SETTING_NEW_SHIFT				(31)
#define NV_SOR_PWR_SETTING_NEW_DEFAULT_MASK			(0x1 << 31)
#define NV_SOR_PWR_SETTING_NEW_PENDING				(1 << 31)
#define NV_SOR_PWR_SETTING_NEW_TRIGGER				(1 << 31)
#define NV_SOR_PWR_MODE_SHIFT					(28)
#define NV_SOR_PWR_MODE_DEFAULT_MASK				(0x1 << 28)
#define NV_SOR_PWR_MODE_NORMAL					(0 << 28)
#define NV_SOR_PWR_MODE_SAFE					(1 << 28)
#define NV_SOR_PWR_HALT_DELAY_SHIFT				(24)
#define NV_SOR_PWR_HALT_DELAY_DEFAULT_MASK			(0x1 << 24)
#define NV_SOR_PWR_HALT_DELAY_DONE				(0 << 24)
#define NV_SOR_PWR_HALT_DELAY_ACTIVE				(1 << 24)
#define NV_SOR_PWR_SAFE_START_SHIFT				(17)
#define NV_SOR_PWR_SAFE_START_DEFAULT_MASK			(0x1 << 17)
#define NV_SOR_PWR_SAFE_START_NORMAL				(0 << 17)
#define NV_SOR_PWR_SAFE_START_ALT				(1 << 17)
#define NV_SOR_PWR_SAFE_STATE_SHIFT				(16)
#define NV_SOR_PWR_SAFE_STATE_DEFAULT_MASK			(0x1 << 16)
#define NV_SOR_PWR_SAFE_STATE_PD				(0 << 16)
#define NV_SOR_PWR_SAFE_STATE_PU				(1 << 16)
#define NV_SOR_PWR_NORMAL_START_SHIFT				(1)
#define NV_SOR_PWR_NORMAL_START_DEFAULT_MASK			(0x1 << 1)
#define NV_SOR_PWR_NORMAL_START_NORMAL				(0 << 16)
#define NV_SOR_PWR_NORMAL_START_ALT				(1 << 16)
#define NV_SOR_PWR_NORMAL_STATE_SHIFT				(0)
#define NV_SOR_PWR_NORMAL_STATE_DEFAULT_MASK			(0x1)
#define NV_SOR_PWR_NORMAL_STATE_PD				(0)
#define NV_SOR_PWR_NORMAL_STATE_PU				(1)
#define NV_SOR_SEQ_CTL						(0x2c)
#define NV_SOR_SEQ_CTL_SWITCH_SHIFT				(30)
#define NV_SOR_SEQ_CTL_SWITCH_MASK				(0x1 << 30)
#define NV_SOR_SEQ_CTL_SWITCH_WAIT				(0 << 30)
#define NV_SOR_SEQ_CTL_SWITCH_FORCE				(1 << 30)
#define NV_SOR_SEQ_CTL_STATUS_SHIFT				(28)
#define NV_SOR_SEQ_CTL_STATUS_MASK				(0x1 << 28)
#define NV_SOR_SEQ_CTL_STATUS_STOPPED				(0 << 28)
#define NV_SOR_SEQ_CTL_STATUS_RUNNING				(1 << 28)
#define NV_SOR_SEQ_CTL_PC_SHIFT					(16)
#define NV_SOR_SEQ_CTL_PC_MASK					(0xf << 16)
#define NV_SOR_SEQ_CTL_PD_PC_ALT_SHIFT				(12)
#define NV_SOR_SEQ_CTL_PD_PC_ALT_MASK				(0xf << 12)
#define NV_SOR_SEQ_CTL_PD_PC_SHIFT				(8)
#define NV_SOR_SEQ_CTL_PD_PC_MASK				(0xf << 8)
#define NV_SOR_SEQ_CTL_PU_PC_ALT_SHIFT				(4)
#define NV_SOR_SEQ_CTL_PU_PC_ALT_MASK				(0xf << 4)
#define NV_SOR_SEQ_CTL_PU_PC_SHIFT				(0)
#define NV_SOR_SEQ_CTL_PU_PC_MASK				(0xf)
#define NV_SOR_LANE_SEQ_CTL					(0x2d)
#define NV_SOR_LANE_SEQ_CTL_SETTING_NEW_SHIFT			(31)
#define NV_SOR_LANE_SEQ_CTL_SETTING_MASK			(1 << 31)
#define NV_SOR_LANE_SEQ_CTL_SETTING_NEW_PENDING			(1 << 31)
#define NV_SOR_LANE_SEQ_CTL_SETTING_NEW_TRIGGER			(1 << 31)
#define NV_SOR_LANE_SEQ_CTL_SEQ_STATE_SHIFT			(28)
#define NV_SOR_LANE_SEQ_CTL_SEQ_STATE_IDLE			(0 << 28)
#define NV_SOR_LANE_SEQ_CTL_SEQ_STATE_BUSY			(1 << 28)
#define NV_SOR_LANE_SEQ_CTL_SEQUENCE_SHIFT			(20)
#define NV_SOR_LANE_SEQ_CTL_SEQUENCE_UP				(0 << 20)
#define NV_SOR_LANE_SEQ_CTL_SEQUENCE_DOWN			(1 << 20)
#define NV_SOR_LANE_SEQ_CTL_NEW_POWER_STATE_SHIFT		(16)
#define NV_SOR_LANE_SEQ_CTL_NEW_POWER_STATE_PU			(0 << 16)
#define NV_SOR_LANE_SEQ_CTL_NEW_POWER_STATE_PD			(1 << 16)
#define NV_SOR_LANE_SEQ_CTL_DELAY_SHIFT				(12)
#define NV_SOR_LANE_SEQ_CTL_DELAY_DEFAULT_MASK			(0xf << 12)
#define NV_SOR_LANE_SEQ_CTL_LANE9_STATE_SHIFT			(9)
#define NV_SOR_LANE_SEQ_CTL_LANE9_STATE_POWERUP			(0 << 9)
#define NV_SOR_LANE_SEQ_CTL_LANE9_STATE_POWERDOWN		(1 << 9)
#define NV_SOR_LANE_SEQ_CTL_LANE8_STATE_SHIFT			(8)
#define NV_SOR_LANE_SEQ_CTL_LANE8_STATE_POWERUP			(0 << 8)
#define NV_SOR_LANE_SEQ_CTL_LANE8_STATE_POWERDOWN		(1 << 8)
#define NV_SOR_LANE_SEQ_CTL_LANE7_STATE_SHIFT			(7)
#define NV_SOR_LANE_SEQ_CTL_LANE7_STATE_POWERUP			(0 << 7)
#define NV_SOR_LANE_SEQ_CTL_LANE7_STATE_POWERDOWN		(1 << 7)
#define NV_SOR_LANE_SEQ_CTL_LANE6_STATE_SHIFT			(6)
#define NV_SOR_LANE_SEQ_CTL_LANE6_STATE_POWERUP			(0 << 6)
#define NV_SOR_LANE_SEQ_CTL_LANE6_STATE_POWERDOWN		(1 << 6)
#define NV_SOR_LANE_SEQ_CTL_LANE5_STATE_SHIFT			(5)
#define NV_SOR_LANE_SEQ_CTL_LANE5_STATE_POWERUP			(0 << 5)
#define NV_SOR_LANE_SEQ_CTL_LANE5_STATE_POWERDOWN		(1 << 5)
#define NV_SOR_LANE_SEQ_CTL_LANE4_STATE_SHIFT			(4)
#define NV_SOR_LANE_SEQ_CTL_LANE4_STATE_POWERUP			(0 << 4)
#define NV_SOR_LANE_SEQ_CTL_LANE4_STATE_POWERDOWN		(1 << 4)
#define NV_SOR_LANE_SEQ_CTL_LANE3_STATE_SHIFT			(3)
#define NV_SOR_LANE_SEQ_CTL_LANE3_STATE_POWERUP			(0 << 3)
#define NV_SOR_LANE_SEQ_CTL_LANE3_STATE_POWERDOWN		(1 << 3)
#define NV_SOR_LANE_SEQ_CTL_LANE2_STATE_SHIFT			(2)
#define NV_SOR_LANE_SEQ_CTL_LANE2_STATE_POWERUP			(0 << 2)
#define NV_SOR_LANE_SEQ_CTL_LANE2_STATE_POWERDOWN		(1 << 2)
#define NV_SOR_LANE_SEQ_CTL_LANE1_STATE_SHIFT			(1)
#define NV_SOR_LANE_SEQ_CTL_LANE1_STATE_POWERUP			(0 << 1)
#define NV_SOR_LANE_SEQ_CTL_LANE1_STATE_POWERDOWN		(1 << 1)
#define NV_SOR_LANE_SEQ_CTL_LANE0_STATE_SHIFT			(0)
#define NV_SOR_LANE_SEQ_CTL_LANE0_STATE_POWERUP			(0)
#define NV_SOR_LANE_SEQ_CTL_LANE0_STATE_POWERDOWN		(1)
#define NV_SOR_PWM_DIV						(0x3e)
#define SOR_NV_PDISP_SOR_PWM_DIV_0_DIVIDE_DEFAULT_MASK		(0xffffff)
#define NV_SOR_PWM_CTL						(0x3f)
#define NV_SOR_PWM_CTL_SETTING_NEW_SHIFT			(31)
#define NV_SOR_PWM_CTL_SETTING_NEW_DONE				(0 << 31)
#define NV_SOR_PWM_CTL_SETTING_NEW_PENDING			(1 << 31)
#define NV_SOR_PWM_CTL_SETTING_NEW_TRIGGER			(1 << 31)
#define NV_SOR_PWM_CTL_CLKSEL_SHIFT				(30)
#define NV_SOR_PWM_CTL_CLKSEL_PCLK				(0 << 30)
#define NV_SOR_PWM_CTL_CLKSEL_XTAL				(1 << 30)
#define NV_SOR_PWM_CTL_DUTY_CYCLE_SHIFT				(0)
#define NV_SOR_PWM_CTL_DUTY_CYCLE_MASK				(0xffffff)
#define NV_SOR_DP_LINKCTL(i)					(0x5a + (i))
#define NV_SOR_DP_LINKCTL_FORCE_IDLEPTTRN_SHIFT			(31)
#define NV_SOR_DP_LINKCTL_FORCE_IDLEPTTRN_NO			(0 << 31)
#define NV_SOR_DP_LINKCTL_FORCE_IDLEPTTRN_YES			(1 << 31)
#define NV_SOR_DP_LINKCTL_COMPLIANCEPTTRN_SHIFT			(28)
#define NV_SOR_DP_LINKCTL_COMPLIANCEPTTRN_NOPATTERN		(0 << 28)
#define NV_SOR_DP_LINKCTL_COMPLIANCEPTTRN_COLORSQARE		(1 << 28)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_SHIFT			(26)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_MASK			(0x3 << 26)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_NOPATTERN		(0 << 26)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_D102			(1 << 26)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_SBLERRRATE		(2 << 26)
#define NV_SOR_DP_LINKCTL_LINKQUALPTTRN_PRBS7			(3 << 26)
#define NV_SOR_DP_LINKCTL_TRAININGPTTRN_SHIFT			(24)
#define NV_SOR_DP_LINKCTL_TRAININGPTTRN_MASK			(0x3 << 24)
#define NV_SOR_DP_LINKCTL_TRAININGPTTRN_NOPATTERN		(0 << 24)
#define NV_SOR_DP_LINKCTL_TRAININGPTTRN_TRAINING1		(1 << 24)
#define NV_SOR_DP_LINKCTL_TRAININGPTTRN_TRAINING2		(2 << 24)
#define NV_SOR_DP_LINKCTL_CHANNELCODING_SHIFT			(22)
#define NV_SOR_DP_LINKCTL_CHANNELCODING_DISABLE			(0 << 22)
#define NV_SOR_DP_LINKCTL_CHANNELCODING_ENABLE			(1 << 22)
#define NV_SOR_DP_LINKCTL_LANECOUNT_SHIFT			(16)
#define NV_SOR_DP_LINKCTL_LANECOUNT_MASK			(0x1f << 16)
#define NV_SOR_DP_LINKCTL_LANECOUNT_ZERO			(0 << 16)
#define NV_SOR_DP_LINKCTL_LANECOUNT_ONE				(1 << 16)
#define NV_SOR_DP_LINKCTL_LANECOUNT_TWO				(3 << 16)
#define NV_SOR_DP_LINKCTL_LANECOUNT_FOUR			(15 << 16)
#define NV_SOR_DP_LINKCTL_ENHANCEDFRAME_SHIFT			(14)
#define NV_SOR_DP_LINKCTL_ENHANCEDFRAME_DISABLE			(0 << 14)
#define NV_SOR_DP_LINKCTL_ENHANCEDFRAME_ENABLE			(1 << 14)
#define NV_SOR_DP_LINKCTL_SCRAMBLEREN_SHIFT			(12)
#define NV_SOR_DP_LINKCTL_SCRAMBLEREN_MASK			(0x3 << 12)
#define NV_SOR_DP_LINKCTL_SCRAMBLEREN_DISABLE			(0 << 12)
#define NV_SOR_DP_LINKCTL_SCRAMBLEREN_ENABLE_GALIOS		(1 << 12)
#define NV_SOR_DP_LINKCTL_SCRAMBLEREN_ENABLE_FIBONACCI		(2 << 12)
#define NV_SOR_DP_LINKCTL_SYNCMODE_SHIFT			(10)
#define NV_SOR_DP_LINKCTL_SYNCMODE_DISABLE			(0 << 10)
#define NV_SOR_DP_LINKCTL_SYNCMODE_ENABLE			(1 << 10)
#define NV_SOR_DP_LINKCTL_TUSIZE_SHIFT				(2)
#define NV_SOR_DP_LINKCTL_TUSIZE_MASK				(0x7f << 2)
#define NV_SOR_DP_LINKCTL_ENABLE_SHIFT				(0)
#define NV_SOR_DP_LINKCTL_ENABLE_NO				(0)
#define NV_SOR_DP_LINKCTL_ENABLE_YES				(1)
#define NV_SOR_DC(i)						(0x5c + (i))
#define NV_SOR_DC_LANE3_DP_LANE3_SHIFT				(24)
#define NV_SOR_DC_LANE3_DP_LANE3_MASK				(0xff << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P0_LEVEL0			(17 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P1_LEVEL0			(21 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P2_LEVEL0			(26 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P3_LEVEL0			(34 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P0_LEVEL1			(26 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P1_LEVEL1			(32 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P2_LEVEL1			(39 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P0_LEVEL2			(34 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P1_LEVEL2			(43 << 24)
#define NV_SOR_DC_LANE3_DP_LANE3_P0_LEVEL3			(51 << 24)
#define NV_SOR_DC_LANE2_DP_LANE0_SHIFT				(16)
#define NV_SOR_DC_LANE2_DP_LANE0_MASK				(0xff << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P0_LEVEL0			(17 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P1_LEVEL0			(21 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P2_LEVEL0			(26 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P3_LEVEL0			(34 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P0_LEVEL1			(26 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P1_LEVEL1			(32 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P2_LEVEL1			(39 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P0_LEVEL2			(34 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P1_LEVEL2			(43 << 16)
#define NV_SOR_DC_LANE2_DP_LANE0_P0_LEVEL3			(51 << 16)
#define NV_SOR_DC_LANE1_DP_LANE1_SHIFT				(8)
#define NV_SOR_DC_LANE1_DP_LANE1_MASK				(0xff << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P0_LEVEL0			(17 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P1_LEVEL0			(21 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P2_LEVEL0			(26 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P3_LEVEL0			(34 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P0_LEVEL1			(26 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P1_LEVEL1			(32 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P2_LEVEL1			(39 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P0_LEVEL2			(34 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P1_LEVEL2			(43 << 8)
#define NV_SOR_DC_LANE1_DP_LANE1_P0_LEVEL3			(51 << 8)
#define NV_SOR_DC_LANE0_DP_LANE2_SHIFT				(0)
#define NV_SOR_DC_LANE0_DP_LANE2_MASK				(0xff)
#define NV_SOR_DC_LANE0_DP_LANE2_P0_LEVEL0			(17)
#define NV_SOR_DC_LANE0_DP_LANE2_P1_LEVEL0			(21)
#define NV_SOR_DC_LANE0_DP_LANE2_P2_LEVEL0			(26)
#define NV_SOR_DC_LANE0_DP_LANE2_P3_LEVEL0			(34)
#define NV_SOR_DC_LANE0_DP_LANE2_P0_LEVEL1			(26)
#define NV_SOR_DC_LANE0_DP_LANE2_P1_LEVEL1			(32)
#define NV_SOR_DC_LANE0_DP_LANE2_P2_LEVEL1			(39)
#define NV_SOR_DC_LANE0_DP_LANE2_P0_LEVEL2			(34)
#define NV_SOR_DC_LANE0_DP_LANE2_P1_LEVEL2			(43)
#define NV_SOR_DC_LANE0_DP_LANE2_P0_LEVEL3			(51)
#define NV_SOR_LANE4_DRIVE_CURRENT(i)				(0x5e + (i))
#define NV_SOR_PR(i)						(0x60 + (i))
#define NV_SOR_PR_LANE3_DP_LANE3_SHIFT				(24)
#define NV_SOR_PR_LANE3_DP_LANE3_MASK				(0xff << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D0_LEVEL0			(0 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D1_LEVEL0			(0 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D2_LEVEL0			(0 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D3_LEVEL0			(0 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D0_LEVEL1			(4 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D1_LEVEL1			(6 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D2_LEVEL1			(17 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D0_LEVEL2			(8 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D1_LEVEL2			(13 << 24)
#define NV_SOR_PR_LANE3_DP_LANE3_D0_LEVEL3			(17 << 24)
#define NV_SOR_PR_LANE2_DP_LANE0_SHIFT				(16)
#define NV_SOR_PR_LANE2_DP_LANE0_MASK				(0xff << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D0_LEVEL0			(0 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D1_LEVEL0			(0 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D2_LEVEL0			(0 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D3_LEVEL0			(0 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D0_LEVEL1			(4 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D1_LEVEL1			(6 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D2_LEVEL1			(17 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D0_LEVEL2			(8 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D1_LEVEL2			(13 << 16)
#define NV_SOR_PR_LANE2_DP_LANE0_D0_LEVEL3			(17 << 16)
#define NV_SOR_PR_LANE1_DP_LANE1_SHIFT				(8)
#define NV_SOR_PR_LANE1_DP_LANE1_MASK				(0xff >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D0_LEVEL0			(0 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D1_LEVEL0			(0 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D2_LEVEL0			(0 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D3_LEVEL0			(0 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D0_LEVEL1			(4 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D1_LEVEL1			(6 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D2_LEVEL1			(17 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D0_LEVEL2			(8 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D1_LEVEL2			(13 >> 8)
#define NV_SOR_PR_LANE1_DP_LANE1_D0_LEVEL3			(17 >> 8)
#define NV_SOR_PR_LANE0_DP_LANE2_SHIFT				(0)
#define NV_SOR_PR_LANE0_DP_LANE2_MASK				(0xff)
#define NV_SOR_PR_LANE0_DP_LANE2_D0_LEVEL0			(0)
#define NV_SOR_PR_LANE0_DP_LANE2_D1_LEVEL0			(0)
#define NV_SOR_PR_LANE0_DP_LANE2_D2_LEVEL0			(0)
#define NV_SOR_PR_LANE0_DP_LANE2_D3_LEVEL0			(0)
#define NV_SOR_PR_LANE0_DP_LANE2_D0_LEVEL1			(4)
#define NV_SOR_PR_LANE0_DP_LANE2_D1_LEVEL1			(6)
#define NV_SOR_PR_LANE0_DP_LANE2_D2_LEVEL1			(17)
#define NV_SOR_PR_LANE0_DP_LANE2_D0_LEVEL2			(8)
#define NV_SOR_PR_LANE0_DP_LANE2_D1_LEVEL2			(13)
#define NV_SOR_PR_LANE0_DP_LANE2_D0_LEVEL3			(17)
#define NV_SOR_LANE4_PREEMPHASIS(i)				(0x62 + (i))
#define NV_SOR_DP_CONFIG(i)					(0x64 + (i))
#define NV_SOR_DP_CONFIG_RD_RESET_VAL_SHIFT			(31)
#define NV_SOR_DP_CONFIG_RD_RESET_VAL_POSITIVE			(0 << 31)
#define NV_SOR_DP_CONFIG_RD_RESET_VAL_NEGATIVE			(1 << 31)
#define NV_SOR_DP_CONFIG_IDLE_BEFORE_ATTACH_SHIFT		(28)
#define NV_SOR_DP_CONFIG_IDLE_BEFORE_ATTACH_DISABLE		(0 << 28)
#define NV_SOR_DP_CONFIG_IDLE_BEFORE_ATTACH_ENABLE		(1 << 28)
#define NV_SOR_DP_CONFIG_ACTIVESYM_CNTL_SHIFT			(26)
#define NV_SOR_DP_CONFIG_ACTIVESYM_CNTL_DISABLE			(0 << 26)
#define NV_SOR_DP_CONFIG_ACTIVESYM_CNTL_ENABLE			(1 << 26)
#define NV_SOR_DP_CONFIG_ACTIVESYM_POLARITY_SHIFT		(24)
#define NV_SOR_DP_CONFIG_ACTIVESYM_POLARITY_NEGATIVE		(0 << 24)
#define NV_SOR_DP_CONFIG_ACTIVESYM_POLARITY_POSITIVE		(1 << 24)
#define NV_SOR_DP_CONFIG_ACTIVESYM_FRAC_SHIFT			(16)
#define NV_SOR_DP_CONFIG_ACTIVESYM_FRAC_MASK			(0xf << 16)
#define NV_SOR_DP_CONFIG_ACTIVESYM_COUNT_SHIFT			(8)
#define NV_SOR_DP_CONFIG_ACTIVESYM_COUNT_MASK			(0x7f << 8)
#define NV_SOR_DP_CONFIG_WATERMARK_SHIFT			(0)
#define NV_SOR_DP_CONFIG_WATERMARK_MASK				(0x3f)
#define NV_SOR_DP_PADCTL(i)					(0x68 + (i))
#define NV_SOR_DP_PADCTL_SPARE_SHIFT				(25)
#define NV_SOR_DP_PADCTL_SPARE_DEFAULT_MASK			(0x7f << 25)
#define NV_SOR_DP_PADCTL_VCO_2X_SHIFT				(24)
#define NV_SOR_DP_PADCTL_VCO_2X_DISABLE				(0 << 24)
#define NV_SOR_DP_PADCTL_VCO_2X_ENABLE				(1 << 24)
#define NV_SOR_DP_PADCTL_PAD_CAL_PD_SHIFT			(23)
#define NV_SOR_DP_PADCTL_PAD_CAL_PD_POWERUP			(0 << 23)
#define NV_SOR_DP_PADCTL_PAD_CAL_PD_POWERDOWN			(1 << 23)
#define NV_SOR_DP_PADCTL_TX_PU_SHIFT				(22)
#define NV_SOR_DP_PADCTL_TX_PU_DISABLE				(0 << 22)
#define NV_SOR_DP_PADCTL_TX_PU_ENABLE				(1 << 22)
#define NV_SOR_DP_PADCTL_REG_CTRL_SHIFT				(20)
#define NV_SOR_DP_PADCTL_REG_CTRL_DEFAULT_MASK			(0x3 << 20)
#define NV_SOR_DP_PADCTL_VCMMODE_SHIFT				(16)
#define NV_SOR_DP_PADCTL_VCMMODE_DEFAULT_MASK			(0xf << 16)
#define NV_SOR_DP_PADCTL_VCMMODE_TRISTATE			(0 << 16)
#define NV_SOR_DP_PADCTL_VCMMODE_TEST_MUX			(1 << 16)
#define NV_SOR_DP_PADCTL_VCMMODE_WEAK_PULLDOWN			(2 << 16)
#define NV_SOR_DP_PADCTL_VCMMODE_STRONG_PULLDOWN		(4 << 16)
#define NV_SOR_DP_PADCTL_TX_PU_VALUE_SHIFT			(8)
#define NV_SOR_DP_PADCTL_TX_PU_VALUE_DEFAULT_MASK		(0xff << 8)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_3_DP_TXD_3_SHIFT	(7)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_3_DP_TXD_3_DISABLE	(0 << 7)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_3_DP_TXD_3_ENABLE	(1 << 7)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_2_DP_TXD_0_SHIFT	(6)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_2_DP_TXD_0_DISABLE	(0 << 6)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_2_DP_TXD_0_ENABLE	(1 << 6)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_1_DP_TXD_1_SHIFT	(5)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_1_DP_TXD_1_DISABLE	(0 << 5)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_1_DP_TXD_1_ENABLE	(1 << 5)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_0_DP_TXD_2_SHIFT	(4)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_0_DP_TXD_2_DISABLE	(0 << 4)
#define NV_SOR_DP_PADCTL_COMMONMODE_TXD_0_DP_TXD_2_ENABLE	(1 << 4)
#define NV_SOR_DP_PADCTL_PD_TXD_3_SHIFT				(3)
#define NV_SOR_DP_PADCTL_PD_TXD_3_YES				(0 << 3)
#define NV_SOR_DP_PADCTL_PD_TXD_3_NO				(1 << 3)
#define NV_SOR_DP_PADCTL_PD_TXD_0_SHIFT				(2)
#define NV_SOR_DP_PADCTL_PD_TXD_0_YES				(0 << 2)
#define NV_SOR_DP_PADCTL_PD_TXD_0_NO				(1 << 2)
#define NV_SOR_DP_PADCTL_PD_TXD_1_SHIFT				(1)
#define NV_SOR_DP_PADCTL_PD_TXD_1_YES				(0 << 1)
#define NV_SOR_DP_PADCTL_PD_TXD_1_NO				(1 << 1)
#define NV_SOR_DP_PADCTL_PD_TXD_2_SHIFT				(0)
#define NV_SOR_DP_PADCTL_PD_TXD_2_YES				(0)
#define NV_SOR_DP_PADCTL_PD_TXD_2_NO				(1)
#define NV_SOR_DP_SPARE(i)					(0x6c + (i))
#define NV_SOR_DP_SPARE_PANEL_SHIFT				(1)
#define NV_SOR_DP_SPARE_PANEL_EXTERNAL				(0 << 1)
#define NV_SOR_DP_SPARE_PANEL_INTERNAL				(1 << 1)
#define NV_SOR_DP_SPARE_SEQ_ENABLE_SHIFT			(0)
#define NV_SOR_DP_SPARE_SEQ_ENABLE_NO				(0)
#define NV_SOR_DP_SPARE_SEQ_ENABLE_YES				(1)
#define NV_SOR_DP_AUDIO_HBLANK_SYMBOLS				(0x6e)
#define NV_SOR_DP_AUDIO_HBLANK_SYMBOLS_MASK			(0x1ffff)
#define NV_SOR_DP_AUDIO_HBLANK_SYMBOLS_VALUE_SHIFT		(0)
#define NV_SOR_DP_AUDIO_VBLANK_SYMBOLS				(0x6f)
#define NV_SOR_DP_AUDIO_VBLANK_SYMBOLS_MASK			(0x1ffff)
#define NV_SOR_DP_AUDIO_VBLANK_SYMBOLS_SHIFT			(0)
#define NV_SOR_DP_GENERIC_INFOFRAME_HEADER			(0x70)
#define NV_SOR_DP_GENERIC_INFOFRAME_SUBPACK(i)			(0x71 + (i))

#endif
