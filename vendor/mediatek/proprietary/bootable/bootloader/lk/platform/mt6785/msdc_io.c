/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#include "msdc.h"
#include "msdc_io.h"
#include <platform/mt_gpio.h>
#include <platform/gpio_init.h>
#if defined(MMC_MSDC_DRV_CTP)
#include <common.h>
#include "api.h"    //For invocation cache_clean_invalidate()
#include "cache_api.h"  //For invocation cache_clean_invalidate()
#endif

#if defined(MMC_MSDC_DRV_LK)
#include <kernel/event.h>
#include <platform/mt_irq.h>
#endif

#if defined(MMC_MSDC_DRV_CTP)
#include "gpio.h"

#if defined(MSDC_USE_DCM)
#include "dcm.h"
#endif

#if !defined(FPGA_PLATFORM)
#include "pmic.h"
#include "clock_manager.h"
#endif
#endif


////////////////////////////////////////////////////////////////////////////////
//
// Section 1. Power Control -- Common for ASIC and FPGA
//
////////////////////////////////////////////////////////////////////////////////
//Note: MTKDRV_XXX are used by CTP
#if defined(MTKDRV_PMIC) && defined(MTKDRV_PMIC_WRAP) && defined(MTKDRV_I2C)
#include <upmu_hw.h>
#else
#define pmic_config_interface(RegNum, val, MASK, SHIFT)
#define pmic_read_interface(RegNum, val, MASK, SHIFT)
#endif

#if defined(FPGA_PLATFORM)
#define PWR_GPIO        (0x10000E84) //Select Power On/Off
#define PWR_GPIO_EO     (0x10000E88) //Select Output/Input Direction

#define PWR_MASK_CARD   (0x1 << 8)   //Vcc
#define PWR_MASK_VOL_18 (0x1 << 9)   //CLK/CMD/DAT for eMMC/SD +  Vccq for eMMC
#define PWR_MASK_VOL_33 (0x1 << 10)  //CLK/CMD/DAT for eMMC/SD +  Vccq for eMMC
#define PWR_MASK_L4     (0x1 << 11)
#define PWR_MSDC        (PWR_MASK_CARD | PWR_MASK_VOL_18 | PWR_MASK_VOL_33 | PWR_MASK_L4)

//#define FPGA_GPIO_DEBUG
static void msdc_clr_gpio(u32 bits)
{
	u32 l_val = 0;
	char *name;

	switch (bits) {
		case PWR_MASK_CARD:
			name = "card pwr";
			break;
		case PWR_MASK_VOL_18:
			name = "SD/eMMC bus pwer 1.8V";
			break;
		case PWR_MASK_VOL_33:
			name = "SD/eMMC bus pwer 3.3V";
			break;
		case PWR_MASK_L4:
			name = "L4";
			break;
		default:
			msdc_pr_err("[%s:%s]invalid value: 0x%x\n", __FILE__, __func__, bits);
			return;
	}

	MSDC_GET_FIELD(PWR_GPIO_EO, bits, l_val);
	//msdc_pr_info("====%s====%d\n", name, l_val);
	if (0 == l_val) {
		msdc_pr_info("check me! gpio for %s is input\n", name);
		MSDC_SET_FIELD(PWR_GPIO_EO, bits, 1);
	}
	/* check for set before */
	if (bits &  MSDC_READ32(PWR_GPIO)) {
		msdc_pr_info("clear %s\n", name);
		MSDC_SET_FIELD(PWR_GPIO, bits, 0);
		//l_val = MSDC_READ32(PWR_GPIO);
	}

#ifdef FPGA_GPIO_DEBUG
	{
		u32 val = 0;
		val = MSDC_READ32(PWR_GPIO);
		msdc_pr_err("[clr]PWR_GPIO[8-11]:0x%x\n", val);
		val = MSDC_READ32(PWR_GPIO_EO);
		msdc_pr_err("[clr]GPIO_DIR[8-11]	   :0x%x\n", val);
	}
#endif
}

static void msdc_set_gpio(u32 bits)
{
	u32 l_val = 0;
	char *name;

	switch (bits) {
		case PWR_MASK_CARD:
			name = "card pwr";
			break;
		case PWR_MASK_VOL_18:
			name = "SD/eMMC bus pwer 1.8V";
			break;
		case PWR_MASK_VOL_33:
			name = "SD/eMMC bus pwer 3.3V";
			break;
		case PWR_MASK_L4:
			name = "L4";
			break;
		default:
			msdc_pr_info("[%s]invalid parm: 0x%x\n", __func__, bits);
			return;
	}

	MSDC_GET_FIELD(PWR_GPIO_EO, bits, l_val);
	//msdc_pr_info("====%s====%d\n", name, l_val);
	if (0 == l_val) {
		msdc_pr_info("check me! gpio for %s is input\n", name);
		MSDC_SET_FIELD(PWR_GPIO_EO, bits, 1);
	}
	/* check for set before */
	if ((bits &  MSDC_READ32(PWR_GPIO))==0) {
		msdc_pr_info("Set %s\n", name);
		MSDC_SET_FIELD(PWR_GPIO, bits, 1);
		//l_val = MSDC_READ32(PWR_GPIO);
	}

#ifdef FPGA_GPIO_DEBUG
	{
		u32 val = 0;
		val = MSDC_READ32(PWR_GPIO);
		msdc_pr_err("[set]PWR_GPIO[8-11]:0x%x\n", val);
		val = MSDC_READ32(PWR_GPIO_EO);
		msdc_pr_err("[set]GPIO_DIR[8-11]	   :0x%x\n", val);
	}
#endif
}
#endif

#if defined(MMC_MSDC_DRV_CTP) && !defined(FPGA_PLATFORM)
u32 hwPowerOn(MSDC_POWER powerId, MSDC_POWER_VOLTAGE powerVolt)
{
	u32 ret;

	switch (powerId) {
		case MSDC_VEMC:
			if (powerVolt == VOL_3000) {
				pmic_config_interface(REG_VEMC_VOSEL, VEMC_VOSEL_3V, MASK_VEMC_VOSEL, SHIFT_VEMC_VOSEL);
				if (EMMC_VOL_ACTUAL != VOL_3000) {
					pmic_config_interface(REG_VEMC_VOSEL_CAL,
						VEMC_VOSEL_CAL_mV(EMMC_VOL_ACTUAL - VOL_3000),
						MASK_VEMC_VOSEL_CAL, SHIFT_VEMC_VOSEL_CAL);
				}
			} else if (powerVolt == VOL_3300) {
				pmic_config_interface(REG_VEMC_VOSEL, VEMC_VOSEL_3V3, MASK_VEMC_VOSEL, SHIFT_VEMC_VOSEL);
			} else {
				msdc_pr_err("Not support to Set VEMC_3V3 power to %d\n", powerVolt);
			}
			pmic_config_interface(REG_VEMC_EN, 1, MASK_VEMC_EN, SHIFT_VEMC_EN);
			break;

		case MSDC_VMC:
			if (powerVolt == VOL_3300 || powerVolt == VOL_3000)
				pmic_config_interface(REG_VMC_VOSEL, VMC_VOSEL_3V, MASK_VMC_VOSEL, SHIFT_VMC_VOSEL);
			else if (powerVolt == VOL_1800)
				pmic_config_interface(REG_VMC_VOSEL, VMC_VOSEL_1V8, MASK_VMC_VOSEL, SHIFT_VMC_VOSEL);
			else
				msdc_pr_err("Not support to Set VMC power to %d\n", powerVolt);

			pmic_config_interface(REG_VMC_EN, 1, MASK_VMC_EN, SHIFT_VMC_EN);
			break;

		case MSDC_VMCH:
			if (powerVolt == VOL_3000) {
				pmic_config_interface(REG_VMCH_VOSEL, VMCH_VOSEL_3V, MASK_VMCH_VOSEL, SHIFT_VMCH_VOSEL);
				if (SD_VOL_ACTUAL != VOL_3000) {
					pmic_config_interface(REG_VMCH_VOSEL_CAL,
						VMCH_VOSEL_CAL_mV(SD_VOL_ACTUAL - VOL_3000),
						MASK_VMCH_VOSEL_CAL, SHIFT_VMCH_VOSEL_CAL);
				}
			} else if (powerVolt == VOL_3300) {
				pmic_config_interface(REG_VMCH_VOSEL, VMCH_VOSEL_3V3, MASK_VMCH_VOSEL, SHIFT_VMCH_VOSEL);
			} else {
				msdc_pr_err("Not support to Set VMCH power to %d\n", powerVolt);
			}
			pmic_config_interface(REG_VMCH_EN, 1, MASK_VMCH_EN, SHIFT_VMCH_EN);
			break;

		default:
			msdc_pr_err("Not support to Set %d power on\n", powerId);
			break;
	}

	return 0;
}

u32 hwPowerDown(MSDC_POWER powerId)
{
	switch (powerId) {
		case MSDC_VEMC:
			pmic_config_interface(REG_VEMC_EN, 0, MASK_VEMC_EN, SHIFT_VEMC_EN);
			break;
		case MSDC_VMC:
			pmic_config_interface(REG_VMC_EN, 0, MASK_VMC_EN, SHIFT_VMC_EN);
			break;
		case MSDC_VMCH:
			pmic_config_interface(REG_VMCH_EN, 0, MASK_VMCH_EN, SHIFT_VMCH_EN);
			break;
		default:
			msdc_pr_err("Not support to Set %d power down\n", powerId);
			break;
	}
	return 0;
}

static u32 msdc_ldo_power(u32 on, MSDC_POWER powerId, MSDC_POWER_VOLTAGE powerVolt, u32 *status)
{
	if (on) { // want to power on
		if (*status == 0) {  // can power on
			msdc_pr_info("msdc LDO<%d> power on<%d>\n", powerId, powerVolt);
			hwPowerOn(powerId, powerVolt);
			*status = powerVolt;
		} else if (*status == powerVolt) {
			msdc_pr_info("msdc LDO<%d><%d> power on again!\n", powerId, powerVolt);
		} else { // for sd3.0 later
			msdc_pr_info("msdc LDO<%d> change<%d>	to <%d>\n", powerId, *status, powerVolt);
			hwPowerDown(powerId);
			hwPowerOn(powerId, powerVolt);
			*status = powerVolt;
		}
	} else {  // want to power off
		if (*status != 0) {  // has been powerred on
			msdc_pr_info("msdc LDO<%d> power off\n", powerId);
			hwPowerDown(powerId);
			*status = 0;
		} else {
			msdc_pr_info("LDO<%d>	not power on\n", powerId);
		}
	}

	return 0;
}
#endif /* defined(MMC_MSDC_DRV_CTP) && !defined(FPGA_PLATFORM) */

#if defined(FPGA_PLATFORM)
void msdc_card_power(struct mmc_host *host, u32 on)
{
	MSG(CFG, "[SD%d] Turn %s card power\n", host->id, on ? "on" : "off");
	switch (host->id) {
		case 0:
			if (on) {
				//On V6/V7 FPGA, card power need to be on/off
				//On HAPS FPGA, card power maybe always on.
				//Left this code for safety prevent from card power not always not.
				msdc_set_gpio(PWR_MASK_CARD);
			} else {
				msdc_clr_gpio(PWR_MASK_CARD);
			}
			mdelay(10);
			break;
		default:
			//No MSDC1 in FPGA
			break;
	}

	//add for fpga debug
	msdc_set_gpio(PWR_MASK_L4);
}

void msdc_host_power(struct mmc_host *host, u32 on, u32 level)
{
	MSG(CFG, "[SD%d] Turn %s host power\n", host->id, on ? "on" : "off");

	// GPO[3:2] = {LVL_PWR33, LVL_PWR18};
	msdc_clr_gpio(PWR_MASK_VOL_18);
	msdc_clr_gpio(PWR_MASK_VOL_33);

	switch (host->id) {
		case 0:
			if (on) {
				if (level == VOL_1800)
					msdc_set_gpio(PWR_MASK_VOL_18);
				else
					msdc_set_gpio(PWR_MASK_VOL_33);
			}
			mdelay(10);
			break;
		default:
			//No MSDC1 in FPGA
			break;
	}

	msdc_set_gpio(PWR_MASK_L4);
}
#else
void msdc_card_power(struct mmc_host *host, u32 on)
{
	//Only CTP support power on/off for verification purose.
	//Preload and LK need not touch power since it is default on
	MSG(CFG, "[SD%d] Turn %s card power\n", host->id, on ? "on" : "off");

#if defined(MMC_MSDC_DRV_CTP)
	switch (host->id) {
		case 0:
			if (msdc_cap[0].power_flash == 1) {
				msdc_cap[0].power_flash = VOL_3000;
			} else {
				msdc_ldo_power(on, MSDC_VEMC, VOL_3000, &msdc_cap[0].power_flash);
				mdelay(10);
			}
			break;
		case 1:
			if (msdc_cap[1].power_flash == 1) {
				msdc_cap[1].power_flash = VOL_3000;
			} else {
				msdc_ldo_power(on, MSDC_VMCH, VOL_3000, &msdc_cap[1].power_flash);
				mdelay(10);
			}
			mdelay(10);
			break;
		case 2:
			if (on && (host->cur_pwr < VOL_2000)) {
				//For MTK SDIO device initialized at 1.8V, use external source of 1.8V
				//So we just turn VMCH off
				on = 0;
			}
			msdc_ldo_power(on, MSDC_VMCH, VOL_3000, &msdc_cap[2].power_flash);
			mdelay(10);
			break;
		default:
			break;
	}
#endif
}

void msdc_host_power(struct mmc_host *host, u32 on, u32 level)
{
	//Only CTP support power on/off for verification purose.
	//Preload and LK need not touch power since it is default on
#if defined(MMC_MSDC_DRV_CTP)
	u32 card_on = on;
	if (host->id != 0) {
		host->cur_pwr = level;
	}
	msdc_set_tdsel_wrap(host);
	msdc_set_rdsel_wrap(host);
	msdc_set_driving(host, &msdc_cap[host->id], (level == VOL_1800));

	MSG(CFG, "[SD%d] Turn %s host power\n", host->id, on ? "on" : "off");

	switch (host->id) {
		case 0:
			//no need change;
			break;
		case 1:
			if (msdc_cap[1].power_io == 1) {
				msdc_cap[1].power_io = level;
			} else {
				msdc_ldo_power(on, MSDC_VMC, level, &msdc_cap[1].power_io);
				mdelay(10);
			}
			break;
		default:
			break;
	}
#endif
}

void msdc_dump_ldo_sts(struct mmc_host *host)
{
#if defined(MTK_MSDC_BRINGUP_DEBUG)
	u32 ldo_en = 0, ldo_vol = 0;

	pmic_read_interface(REG_VEMC_EN, &ldo_en, MASK_VEMC_EN,
	                    SHIFT_VEMC_EN);
	pmic_read_interface(REG_VEMC_VOSEL, &ldo_vol, MASK_VEMC_VOSEL,
	                    SHIFT_VEMC_VOSEL);
	msdc_pr_err(" VEMC_EN=0x%x, should:1b'1, "
	       "VEMC_VOL=0x%x, should:1b'0(3.0V),1b'1(3.3V)\n",
	       ldo_en, ldo_vol);
#endif
}
#endif

void msdc_power(struct mmc_host *host, u8 mode)
{
	if (mode == MMC_POWER_ON || mode == MMC_POWER_UP) {
		msdc_pin_config(host, MSDC_PIN_PULL_UP);
		msdc_host_power(host, 1, host->cur_pwr);
		msdc_card_power(host, 1);
		msdc_clock(host, 1);
	} else {
		msdc_clock(host, 0);
		msdc_host_power(host, 0, host->cur_pwr);
		msdc_card_power(host, 0);
		msdc_pin_config(host, MSDC_PIN_PULL_DOWN);
	}
}


/**************************************************************/
/* Section 2: Clock                    */
/**************************************************************/
#if !defined(FPGA_PLATFORM)
u32 hclks_msdc0[] = { MSDC0_SRC_0, MSDC0_SRC_1, MSDC0_SRC_2, MSDC0_SRC_3,
		      MSDC0_SRC_4, MSDC0_SRC_5};

/* msdc1/2 clock source reference value is 200M */
u32 hclks_msdc1[] = { MSDC1_SRC_0, MSDC1_SRC_1, MSDC1_SRC_2, MSDC1_SRC_3,
		      MSDC1_SRC_4};

u32 *hclks_msdc_all[] = {
	hclks_msdc0,
	hclks_msdc1,
};

void msdc_dump_clock_sts(struct mmc_host *host)
{
#if defined(MTK_MSDC_BRINGUP_DEBUG)
	msdc_pr_info("MSDC0 HCLK_MUX[0x1000_0070][17:16] = %d, pdn = %d, "
		"CLK_MUX[0x1000_0070][26:24] = %d, pdn = %d, "
		"CLK_CG[0x1000_1094] bit2 = %d, bit6 %d\n",
		/* mux at bits 17~16 */
		(MSDC_READ32(0x10000070) >> 16) & 3,
		/* pdn at bit 23 */
		(MSDC_READ32(0x10000070) >> 23) & 1,
		/* mux at bits 26~24 */
		(MSDC_READ32(0x10000070) >> 24) & 7,
		/* pdn at bit 31 */
		(MSDC_READ32(0x10000070) >> 31) & 1,
		/* cg at bit 2, 6 */
		(MSDC_READ32(0x10001094) >> 2) & 1,
		(MSDC_READ32(0x10001094) >> 6) & 1);
#endif
}
#endif

void msdc_clock(struct mmc_host *host, int on)
{
	//Only CTP need enable/disable clock
	//Preloader will turn on clock with predefined clock source and module need not to touch clock setting.
	//LK will use preloader's setting and need not to touch clock setting.
#if !defined(FPGA_PLATFORM)
#if defined(MMC_MSDC_DRV_CTP)
	MSG(CFG, "[SD%d] Turn %s %s clock \n", host->id, on ? "on" : "off", "host");

	if (on) {
		if (host->id == 0) {
			MSDC_SET_BIT32(MSDC0_CLOCK_UNGATE_REG, MSDC0_CLOCK_CG);
			MSDC_SET_BIT32(MSDC0_CLOCK_UNGATE_REG, MSDC0_CLOCK_SRC_CG);
		} else if (host->id == 1) {
			MSDC_SET_BIT32(MSDC1_CLOCK_UNGATE_REG, MSDC1_CLOCK_CG);
			MSDC_SET_BIT32(MSDC1_CLOCK_UNGATE_REG, MSDC1_CLOCK_SRC_CG);
		}
	} else {
		if (host->id == 0) {
			MSDC_SET_BIT32(MSDC0_CLOCK_GATE_REG, MSDC0_CLOCK_CG);
			MSDC_SET_BIT32(MSDC0_CLOCK_GATE_REG, MSDC0_CLOCK_SRC_CG);
		} else if (host->id == 1) {
			MSDC_SET_BIT32(MSDC1_CLOCK_GATE_REG, MSDC1_CLOCK_CG);
			MSDC_SET_BIT32(MSDC1_CLOCK_GATE_REG, MSDC1_CLOCK_SRC_CG);
		}
	}
#endif

	msdc_dump_clock_sts(host);

#endif
}

/* perloader will pre-set msdc pll and the mux channel of msdc pll */
/* note: pll will not changed */
void msdc_config_clksrc(struct mmc_host *host, int clksrc)
{
#if !defined(FPGA_PLATFORM)
	#if defined(MMC_MSDC_DRV_PRELOADER) || defined(MMC_MSDC_DRV_LK)
	host->pll_mux_clk = MSDC0_CLKSRC_DEFAULT;
	host->src_clk = msdc_get_hclk(host->id, MSDC0_CLKSRC_DEFAULT);
	#endif

	#if defined(MMC_MSDC_DRV_CTP)
	if (host->card && mmc_card_hs400(host->card)) {
		/* if card is in hs400 mode, force clk source to be 400MHz */
		clksrc = MSDC0_CLKSRC_400MHZ;
	}
	host->pll_mux_clk = clksrc;
	host->src_clk = msdc_get_hclk(host->id, clksrc);

	/* The following section shall be confirmed by clock owner during porting */
	if (host->id == 0) {
		MSDC_SET_FIELD((TOPCKGEN_BASE + 0x080), 0x7 << 8, host->pll_mux_clk);
	} else if (host->id == 1) {
		MSDC_SET_FIELD((TOPCKGEN_BASE + 0x080), 0x7 << 16, host->pll_mux_clk);
	}
	/* Beware!, may hang if update others */
	MSDC_WRITE32(TOPCKGEN_BASE + 0x04, 0x07FFFFFF);
	#endif
#else
	host->src_clk = msdc_get_hclk(host->id, clksrc);
#endif

}

/**************************************************************/
/* Section 3: GPIO and Pad                    */
/**************************************************************/
#if !defined(FPGA_PLATFORM)
void msdc_dump_padctl_by_id(u32 id)
{
#if defined(MTK_MSDC_BRINGUP_DEBUG)
	if (id == 0) {
		msdc_pr_err("MSDC0 MODE20[%x] = 0x%X\tshould: 0x1???????\n",
			MSDC0_GPIO_MODE20, MSDC_READ32(MSDC0_GPIO_MODE20));
		msdc_pr_err("MSDC0 MODE21[%x] = 0x%X\tshould: 0x11111111\n",
			MSDC0_GPIO_MODE21, MSDC_READ32(MSDC0_GPIO_MODE21));
		msdc_pr_err("MSDC0 MODE22[%x] = 0x%X\tshould: 0x?????111\n",
			MSDC0_GPIO_MODE22, MSDC_READ32(MSDC0_GPIO_MODE22));
		msdc_pr_err("MSDC0 IES   [%x] = 0x%X\tshould: 0x?????FFF\n",
			MSDC0_GPIO_IES_ADDR, MSDC_READ32(MSDC0_GPIO_IES_ADDR));
		msdc_pr_err("MSDC0 SMT   [%x] = 0x%X\tshould: 0x???????F\n",
			MSDC0_GPIO_SMT_ADDR, MSDC_READ32(MSDC0_GPIO_SMT_ADDR));
		msdc_pr_err("MSDC0 TDSEL0[%x] = 0x%X\tshould: 0x????0000\n",
			MSDC0_GPIO_TDSEL0_ADDR,
			MSDC_READ32(MSDC0_GPIO_TDSEL0_ADDR));
		msdc_pr_err("MSDC0 RDSEL0[%x] = 0x%X\tshould: 0x00000000\n",
			MSDC0_GPIO_RDSEL0_ADDR,
			MSDC_READ32(MSDC0_GPIO_RDSEL0_ADDR));
		msdc_pr_err("MSDC0 DRV0  [%x] = 0x%X\tshould: 0x?????249\n",
			MSDC0_GPIO_DRV0_ADDR,
			MSDC_READ32(MSDC0_GPIO_DRV0_ADDR));
		msdc_pr_err("PUPD/R1/R0: dat/cmd:0/0/1, clk/dst: 1/1/0\n");
		msdc_pr_err("MSDC0 PUPD0 [%x] = 0x%X\tshould: 0x?????401\n",
			MSDC0_GPIO_PUPD0_ADDR,
			MSDC_READ32(MSDC0_GPIO_PUPD0_ADDR));
		msdc_pr_err("MSDC0 R0 [%x] = 0x%X\tshould: 0x?????3FE\n",
			MSDC0_GPIO_R0_ADDR,
			MSDC_READ32(MSDC0_GPIO_R0_ADDR));
		msdc_pr_err("MSDC0 R1 [%x] = 0x%X\tshould: 0x?????401\n",
			MSDC0_GPIO_R1_ADDR,
			MSDC_READ32(MSDC0_GPIO_R1_ADDR));
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		msdc_pr_err("MSDC1 MODE16 [%x] = 0x%X\tshould: 0x11??????\n",
			MSDC1_GPIO_MODE16, MSDC_READ32(MSDC1_GPIO_MODE16));
		msdc_pr_err("MSDC1 MODE17 [%x] = 0x%X\tshould: 0x????1111\n",
			MSDC1_GPIO_MODE17, MSDC_READ32(MSDC1_GPIO_MODE17));
		msdc_pr_err("MSDC1 IES    [%x] = 0x%X\tshould: 0x??????FC\n",
			MSDC1_GPIO_IES_ADDR, MSDC_READ32(MSDC1_GPIO_IES_ADDR));
		msdc_pr_err("MSDC1 SMT    [%x] = 0x%X\tshould: 0x??????1C\n",
			MSDC1_GPIO_SMT_ADDR, MSDC_READ32(MSDC1_GPIO_SMT_ADDR));
		msdc_pr_err("MSDC1 TDSEL0 [%x] = 0x%X\tshould: 0x????000?\n",
			MSDC1_GPIO_TDSEL0_ADDR,
			MSDC_READ32(MSDC1_GPIO_TDSEL0_ADDR));
		msdc_pr_err("should 1.8v: sleep: TBD, awake: TBD\n");
		msdc_pr_err("MSDC1 RDSEL0 [%x] = 0x%X\tshould: 0x???0000?\n",
			MSDC1_GPIO_RDSEL0_ADDR,
			MSDC_READ32(MSDC1_GPIO_RDSEL0_ADDR));
		msdc_pr_err("1.8V: TBD, 2.9v: TBD\n");
		msdc_pr_err("MSDC1 DRV0   [%x] = 0x%X\tshould: 0x?????92?\n",
			MSDC1_GPIO_DRV0_ADDR,
			MSDC_READ32(MSDC1_GPIO_DRV0_ADDR));
		msdc_pr_err("MSDC1 PUPD0  [%x] = 0x%X\tshould: 0x??????01\n",
			MSDC1_GPIO_PUPD0_ADDR,
			MSDC_READ32(MSDC1_GPIO_PUPD0_ADDR));
		msdc_pr_err("MSDC1 R0  [%x] = 0x%X\tshould: 0x??????00\n",
			MSDC1_GPIO_R0_ADDR,
			MSDC_READ32(MSDC1_GPIO_R0_ADDR));
		msdc_pr_err("MSDC1 R1  [%x] = 0x%X\tshould: 0x??????3F\n",
			MSDC1_GPIO_R1_ADDR,
			MSDC_READ32(MSDC1_GPIO_R1_ADDR));
#endif
	}
#endif
}

void msdc_set_pin_mode(struct mmc_host *host)
{
	if (host->id == 0) {
		MSDC_SET_FIELD(MSDC0_GPIO_MODE20, 0xF0000000, 0x1);
		MSDC_SET_FIELD(MSDC0_GPIO_MODE21, 0xFFFFFFFF, 0x11111111);
		MSDC_SET_FIELD(MSDC0_GPIO_MODE22, 0x00000FFF, 0x111);
#if (MSDC_MAX_NUM > 1)
	} else if (host->id == 1) {
		MSDC_SET_FIELD(MSDC1_GPIO_MODE16, 0xFF000000, 0x11);
		MSDC_SET_FIELD(MSDC1_GPIO_MODE17, 0x0000FFFF, 0x1111);
#endif
	}
}

void msdc_set_ies_by_id(u32 id, int set_ies)
{
	if (id == 0) {
		MSDC_SET_FIELD(MSDC0_GPIO_IES_ADDR, MSDC0_IES_ALL_MASK,
			(set_ies ? 0xFFF : 0));
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_SET_FIELD(MSDC1_GPIO_IES_ADDR, MSDC1_IES_ALL_MASK,
			(set_ies ? 0x3F : 0));
#endif
	}
}

void msdc_set_smt_by_id(u32 id, int set_smt)
{
	if (id == 0) {
		MSDC_SET_FIELD(MSDC0_GPIO_SMT_ADDR, MSDC0_SMT_ALL_MASK,
			(set_smt ? 0xF : 0));
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_SET_FIELD(MSDC1_GPIO_SMT_ADDR, MSDC1_SMT_ALL_MASK,
			(set_smt ? 0x7 : 0));
#endif
	}
}

void msdc_set_tdsel_by_id(u32 id, u32 flag, u32 value)
{
	u32 cust_val;

	if (id == 0) {
		if (flag == MSDC_TDRDSEL_CUST)
			cust_val = value;
		else
			cust_val = 0;
		MSDC_SET_FIELD(MSDC0_GPIO_TDSEL0_ADDR, MSDC0_TDSEL0_CMD_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_TDSEL0_ADDR, MSDC0_TDSEL0_DAT_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_TDSEL0_ADDR, MSDC0_TDSEL0_CLK_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_TDSEL0_ADDR, MSDC0_TDSEL0_DSL_MASK,
			cust_val);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		if (flag == MSDC_TDRDSEL_CUST)
			cust_val = value;
		else
			cust_val = 0;
		MSDC_SET_FIELD(MSDC1_GPIO_TDSEL0_ADDR, MSDC1_TDSEL0_DAT_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC1_GPIO_TDSEL0_ADDR, MSDC1_TDSEL0_CMD_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC1_GPIO_TDSEL0_ADDR, MSDC1_TDSEL0_CLK_MASK,
			cust_val);
#endif
	}
}

void msdc_set_rdsel_by_id(u32 id, u32 flag, u32 value)
{
	u32 cust_val;

	if (id == 0) {
		if (flag == MSDC_TDRDSEL_CUST)
			cust_val = value;
		else
			cust_val = 0;
		MSDC_SET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_CMD_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_DAT_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_CLK_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_DSL_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_RSTB_MASK,
			cust_val);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		if (flag == MSDC_TDRDSEL_CUST)
			cust_val = value;
		else
			cust_val = 0;
		MSDC_SET_FIELD(MSDC1_GPIO_RDSEL0_ADDR, MSDC1_RDSEL0_CMD_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC1_GPIO_RDSEL0_ADDR, MSDC1_RDSEL0_DAT_MASK,
			cust_val);
		MSDC_SET_FIELD(MSDC1_GPIO_RDSEL0_ADDR, MSDC1_RDSEL0_CLK_MASK,
			cust_val);
#endif
	}
}

void msdc_get_tdsel_by_id(u32 id, u32 *value)
{
	if (id == 0) {
		MSDC_GET_FIELD(MSDC0_GPIO_TDSEL0_ADDR, MSDC0_TDSEL0_CMD_MASK,
			*value);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_GET_FIELD(MSDC1_GPIO_TDSEL0_ADDR, MSDC1_TDSEL0_CMD_MASK,
			*value);
#endif
	}
}

void msdc_get_rdsel_by_id(u32 id, u32 *value)
{
	if (id == 0) {
		MSDC_GET_FIELD(MSDC0_GPIO_RDSEL0_ADDR, MSDC0_RDSEL0_CMD_MASK,
			*value);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_GET_FIELD(MSDC1_GPIO_RDSEL0_ADDR, MSDC1_RDSEL0_CMD_MASK,
			*value);
#endif
	}
}

void msdc_set_sr_by_id(u32 id, int clk, int cmd, int dat, int rst, int ds)
{
	/*SR not supported*/
	return;
}

void msdc_set_driving_by_id(u32 id, struct msdc_cust *msdc_cap, bool sd_18)
{
	if (id == 0) {
		MSDC_SET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_DSL_MASK,
			msdc_cap->ds_drv);
		MSDC_SET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_DAT_MASK,
			msdc_cap->dat_drv);
		MSDC_SET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_CMD_MASK,
			msdc_cap->cmd_drv);
		MSDC_SET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_CLK_MASK,
			msdc_cap->clk_drv);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_SET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_CMD_MASK,
			msdc_cap->cmd_drv);
		MSDC_SET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_CLK_MASK,
			msdc_cap->clk_drv);
		MSDC_SET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_DAT_MASK,
			msdc_cap->dat_drv);
#endif
	}
}

#if defined(MMC_MSDC_DRV_CTP)
void msdc_get_driving_by_id(u32 id, struct msdc_cust *msdc_cap, bool sd_18)
{
	if (id == 0) {
		MSDC_GET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_DSL_MASK,
			msdc_cap->ds_drv);
		MSDC_GET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_DAT_MASK,
			msdc_cap->rst_drv);
		MSDC_GET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_CMD_MASK,
			msdc_cap->cmd_drv);
		MSDC_GET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_CLK_MASK,
			msdc_cap->clk_drv);
		MSDC_GET_FIELD(MSDC0_GPIO_DRV0_ADDR, MSDC0_DRV0_DAT_MASK,
			msdc_cap->dat_drv);
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		MSDC_GET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_CMD_MASK,
			msdc_cap->cmd_drv);
		MSDC_GET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_CLK_MASK,
			msdc_cap->clk_drv);
		MSDC_GET_FIELD(MSDC1_GPIO_DRV0_ADDR, MSDC1_DRV0_DAT_MASK,
			msdc_cap->dat_drv);
#endif
	}
}
#endif

/* msdc pin config
 * MSDC0
 * PUPD/R1/R0
 * 0/0/0: High-Z
 * 0/0/1: Pull-up with 10Kohm
 * 0/1/0: Pull-up with 50Kohm
 * 0/1/1: Pull-up with 10Kohm//50Kohm
 * 1/0/0: High-Z
 * 1/0/1: Pull-down with 10Kohm
 * 1/1/0: Pull-down with 50Kohm
 * 1/1/1: Pull-down with 10Kohm//50Kohm
 */
void msdc_pin_config_by_id(u32 id, u32 mode)
{
	if (id == 0) {
		/* 1. don't pull CLK high;
		 * 2. Don't toggle RST to prevent from entering boot mode
		 */
		if (mode == MSDC_PIN_PULL_NONE) {
			/* Switch MSDC0_* to no ohm PU */
			MSDC_SET_FIELD(MSDC0_GPIO_PUPD0_ADDR, MSDC0_PUPD_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC0_GPIO_R0_ADDR, MSDC0_R0_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC0_GPIO_R1_ADDR, MSDC0_R1_ALL_MASK, 0x0);
		} else if (mode == MSDC_PIN_PULL_DOWN) {
			/* Switch MSDC0_* to 50K ohm PD */
			MSDC_SET_FIELD(MSDC0_GPIO_PUPD0_ADDR, MSDC0_PUPD_ALL_MASK, 0x7FF);
			MSDC_SET_FIELD(MSDC0_GPIO_R0_ADDR, MSDC0_R0_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC0_GPIO_R1_ADDR, MSDC0_R1_ALL_MASK, 0x7FF);
		} else if (mode == MSDC_PIN_PULL_UP) {
			/* Switch MSDC0_CLK to 50K ohm PD,
			 * MSDC0_CMD/MSDC0_DAT* to 10K ohm PU,
			 * MSDC0_DSL to 50K ohm PD
			 */
			MSDC_SET_FIELD(MSDC0_GPIO_PUPD0_ADDR, MSDC0_PUPD_ALL_MASK, 0x401);
			MSDC_SET_FIELD(MSDC0_GPIO_R0_ADDR, MSDC0_R0_ALL_MASK, 0x3FE);
			MSDC_SET_FIELD(MSDC0_GPIO_R1_ADDR, MSDC0_R1_ALL_MASK, 0x401);
		}
#if (MSDC_MAX_NUM > 1)
	} else if (id == 1) {
		if (mode == MSDC_PIN_PULL_NONE) {
			/* Switch MSDC1_* to no ohm PU */
			MSDC_SET_FIELD(MSDC1_GPIO_PUPD0_ADDR, MSDC1_PUPD_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC1_GPIO_R0_ADDR, MSDC1_R0_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC1_GPIO_R1_ADDR, MSDC1_R1_ALL_MASK, 0x0);
		} else if (mode == MSDC_PIN_PULL_DOWN) {
			/* Switch MSDC1_* to 50K ohm PD */
			MSDC_SET_FIELD(MSDC1_GPIO_PUPD0_ADDR, MSDC1_PUPD_ALL_MASK, 0x3F);
			MSDC_SET_FIELD(MSDC1_GPIO_R0_ADDR, MSDC1_R0_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC1_GPIO_R1_ADDR, MSDC1_R1_ALL_MASK, 0x3F);
		} else if (mode == MSDC_PIN_PULL_UP) {
			/* Switch MSDC1_CLK to 50K ohm PD,
			* MSDC1_CMD/MSDC1_DAT* to 50K ohm PU
			*/
			MSDC_SET_FIELD(MSDC1_GPIO_PUPD0_ADDR, MSDC1_PUPD_ALL_MASK, 0x1);
			MSDC_SET_FIELD(MSDC1_GPIO_R0_ADDR, MSDC1_R0_ALL_MASK, 0x0);
			MSDC_SET_FIELD(MSDC1_GPIO_R1_ADDR, MSDC1_R1_ALL_MASK, 0x3F);
		}
#endif
	}
}

/**************************************************************/
/* Section 4: MISC                                            */
/**************************************************************/
/* make sure the pad is msdc mode */
#if !defined(FPGA_PLATFORM)
void msdc_set_tdsel_wrap(struct mmc_host *host)
{
	if (host->cur_pwr == VOL_1800)
		msdc_set_tdsel_by_id(host->id, MSDC_TDRDSEL_1V8, 0);
	else
		msdc_set_tdsel_by_id(host->id, MSDC_TDRDSEL_3V, 0);
}

void msdc_set_rdsel_wrap(struct mmc_host *host)
{
	if (host->cur_pwr == VOL_1800)
		msdc_set_rdsel_by_id(host->id, MSDC_TDRDSEL_1V8, 0);
	else
		msdc_set_rdsel_by_id(host->id, MSDC_TDRDSEL_3V, 0);
}

void msdc_gpio_and_pad_init(struct mmc_host *host)
{
	/* set smt enable */
	msdc_set_smt(host, 1);

	/* set pull enable */
	msdc_pin_config(host, MSDC_PIN_PULL_UP);

	/* set gpio to msdc mode */
	msdc_set_pin_mode(host);

	/* set driving */
	msdc_set_driving(host, &msdc_cap[host->id], (host->cur_pwr == VOL_1800));

	/* set tdsel and rdsel */
	msdc_set_tdsel_wrap(host);
	msdc_set_rdsel_wrap(host);

	msdc_dump_padctl_by_id(host->id);
}
#endif
#endif

#define MSDC0_SDC_ADV_CFG0 (MSDC0_BASE + 0x64)
#define MSDC1_SDC_ADV_CFG0 (MSDC1_BASE + 0x64)
#define MSDC_SPM_REQ_EN    (7U << 22) /* bit 22:24 msdc spm req enable bits */
/* Enable msdc HW SPM resource request, otherwise SPM always see msdc res req siganl busy */
void msdc_spm_hw_res_req_en(void)
{
	MSDC_SET_FIELD(MSDC0_SDC_ADV_CFG0, MSDC_SPM_REQ_EN, 0x7);
	MSDC_SET_FIELD(MSDC1_SDC_ADV_CFG0, MSDC_SPM_REQ_EN, 0x7);
}

/*For UFS/EMMC comba: if use ufs, emmc gpio need to set NC for low power */
void msdc_gpio_set_nc()
{
	/*167 is the first msdc0 gpio*/
	int i, last_msdc_gpio = 167+11;
	gpio_pin msdc_gpio = {
		.mode = 0,
		.dir = 0,
		.dataout = 0,
		.pullen = 1,
		.pull = 0,
		.smt =0
	};
	for (i = 167; i <= last_msdc_gpio; i++)
	{	/* set GPIOx_MODE*/
		mt_set_gpio_mode(0x80000000 + i , msdc_gpio.mode);

		/* set GPIOx_DIR*/
		mt_set_gpio_dir(0x80000000 + i, msdc_gpio.dir);

		/* set GPIOx_PULL*/
		mt_set_gpio_pull_select(0x80000000 + i, msdc_gpio.pull);

		/* set GPIOx_PULLEN*/
		mt_set_gpio_pull_enable(0x80000000 + i , msdc_gpio.pullen);

		/* set GPIOx_DATAOUT*/
		mt_set_gpio_out(0x80000000 + i, msdc_gpio.dataout);

		/* set GPIO0_SMT */
		mt_set_gpio_smt(0x80000000 + i, msdc_gpio.smt);
	}
}

/**************************************************************/
/* Section 5: Hard-code timing                                */
/**************************************************************/
#if defined(SLT) || defined(MMC_MSDC_DRV_CTP)
/* copy from autok.c */
#define AUTOK_CKGEN_VALUE                       (0)
#define AUTOK_CMD_LATCH_EN_HS400_PORT0_VALUE    (3)
#define AUTOK_CRC_LATCH_EN_HS400_PORT0_VALUE    (3)
#define AUTOK_CMD_LATCH_EN_DDR208_PORT3_VALUE   (3)
#define AUTOK_CRC_LATCH_EN_DDR208_PORT3_VALUE   (3)
#define AUTOK_CMD_LATCH_EN_HS200_PORT0_VALUE    (2)
#define AUTOK_CRC_LATCH_EN_HS200_PORT0_VALUE    (2)
#define AUTOK_CMD_LATCH_EN_SDR104_PORT1_VALUE   (2)
#define AUTOK_CRC_LATCH_EN_SDR104_PORT1_VALUE   (2)
#define AUTOK_CMD_LATCH_EN_HS_VALUE             (1)
#define AUTOK_CRC_LATCH_EN_HS_VALUE             (1)

void msdc_apply_timing(unsigned int id)
{
	struct mmc_host *host;
	msdc_priv_t *priv;
	int mode;
	u32 base;
	u32 base_top;

	u32 hz, div;

	host = mmc_get_host(id);
	priv = host->priv;
	base = host->base;
	base_top = host->base_top;

	hz = host->cur_bus_clk;

	MSDC_SET_FIELD(host->base + 0x208, (0x1 << 9), 0);
	MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, mode);
	MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKDIV, div);

	if ((id == 0) && (mode == 3)) {
		/*eMMC HS400*/
		msdc_pr_err("[SD%d] %s %d: HS400\n", id,  __func__, __LINE__);

		MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, 0);    /* MSDC_IOCON[MSDC_IOCON_RSPL] 0x4 bit1 */
		MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_R_D_SMPL, 0);     /* MSDC_IOCON[MSDC_IOCON_R_D_SMPL] 0x4 bit2 */
		MSDC_SET_FIELD(MSDC_PATCH_BIT1 , MSDC_PB1_STOP_DLY_SEL, 3);    /* MSDC_PB1_STOP_DLY_SEL 0xb4[11:8] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT2 , MSDC_PB2_CRCSTSENSEL, 0); /* 0xb8[31:29] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT2 , MSDC_PB2_RESPSTENSEL, 0); /* 0xb8[18:16] */
		MSDC_SET_FIELD(EMMC50_CFG0, MSDC_EMMC50_CFG_CRC_STS_EDGE, 0); /* 0x208 bit3 */
		/*top reg*/
		MSDC_WRITE32(EMMC_TOP_CONTROL, 0xa080);  /* EMMC_TOP_CONTROL 0x0 */
		MSDC_WRITE32(EMMC_TOP_CMD, 0xac0);  /* EMMC_TOP_CMD 0x4 */
		MSDC_WRITE32(TOP_EMMC50_PAD_CTL0, 0x0);  /* TOP_EMMC50_PAD_CTL0 0x8 */
		MSDC_WRITE32(TOP_EMMC50_PAD_DS_TUNE, 0x12c14);  /* TOP_EMMC50_PAD_DS_TUNE 0xc */
	} else if ((id == 0) && (div == 0)) {
		/*eMMC HS200*/
		msdc_pr_err("[SD%d] %s %d: HS200\n", id,  __func__, __LINE__);

		MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, 0);    /*MSDC_IOCON[MSDC_IOCON_RSPL] 0x4 bit1 */
		MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_R_D_SMPL, 0);     /* MSDC_IOCON[MSDC_IOCON_R_D_SMPL] 0x4 bit2 */
		MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_PB0_INT_DAT_LATCH_CK_SEL, 0);      /* PATCH_BIT0[MSDC_PB0_INT_DAT_LATCH_CK_SEL] 0xb0[9:7] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_PB0_RD_DAT_SEL, 0); /* 0xb0 bit3 */
		MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_PB1_STOP_DLY_SEL, 3);    /* MSDC_PB1_STOP_DLY_SEL 0xb4[11:8] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT2, MSDC_PB2_CRCSTSENSEL, 0); /* 0xb8[31:29] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT2, MSDC_PB2_RESPSTENSEL, 0); /* 0xb8[18:16] */
		MSDC_SET_FIELD(MSDC_PATCH_BIT2, MSDC_PB2_CFGCRCSTSEDGE, 0);      /* MSDC_PB2_CFGCRCSTSEDGE, write crc stage edge */ /* 0xb8 bit25 */
		/*top reg*/
		MSDC_WRITE32(EMMC_TOP_CONTROL, 0xaa80);  /* EMMC_TOP_CONTROL 0x0 */
		MSDC_WRITE32(EMMC_TOP_CMD, 0xac0);  /* EMMC_TOP_CMD 0x4 */
		MSDC_WRITE32(TOP_EMMC50_PAD_CTL0, 0x0);  /* TOP_EMMC50_PAD_CTL0 0x8 */
		MSDC_WRITE32(TOP_EMMC50_PAD_DS_TUNE, 0x0);  /* TOP_EMMC50_PAD_DS_TUNE 0xc */
	}
}
#endif
