/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
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
*/

#include <debug.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <platform.h>
#include <platform/mt_typedefs.h>

#include "lcm_define.h"
#include "lcm_drv.h"
#include "lcm_util.h"

#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <lk_builtin_dtb.h>

int lcm_util_get_i2c_lcd_bias(int *id, int *addr)
{
	int offset;
	unsigned int *data = NULL;
	int len = 0;

	offset = fdt_node_offset_by_compatible(get_lk_overlayed_dtb(), -1, "mediatek,i2c_lcd_bias");
	if (offset < 0) {
		dprintf(0, "get fdt i2c_lcd_bias node fail\n");
		return -1;
	}
	data = (unsigned int*)fdt_getprop(get_lk_overlayed_dtb(), offset, "reg", &len);
	if (!data || !len) {
		dprintf(0, "get i2c_lcd_bias reg fail\n");
		return -1;
	}
	*addr = fdt32_to_cpu(*(unsigned int *)data);
	offset = fdt_parent_offset(get_lk_overlayed_dtb(), offset);
	data = (unsigned int*)fdt_getprop(get_lk_overlayed_dtb(), offset, "id", &len);
	if (!data || !len) {
		dprintf(0, "get i2c_lcd_bias id fail\n");
		return -1;
	}
	*id = fdt32_to_cpu(*(unsigned int *)data);
	return 0;
}

int lcm_util_get_pin(char *pin_name)
{
	int offset, idx, phandle;
	unsigned int *data = NULL;
	int len = 0;
	char pinctrl_name[128] = {'\0'};

	offset = fdt_node_offset_by_compatible(get_lk_overlayed_dtb(), -1, "mediatek,mtkfb");
	if (offset < 0) {
		dprintf(INFO, "get fdt mtkfb node fail\n");
		return -1;
	}
	idx = fdt_stringlist_search(get_lk_overlayed_dtb(), offset, "pinctrl-names", pin_name);
	if (idx < 0) {
		dprintf(INFO, "get idx fail. pinctrl_name:%s\n", pinctrl_name);
		return -1;
	}
	snprintf(pinctrl_name, (sizeof(pinctrl_name) - 1), "pinctrl-%d", idx);
	data = (unsigned int*)fdt_getprop(get_lk_overlayed_dtb(), offset, pinctrl_name, &len);
	if (!data || !len) {
		dprintf(INFO, "get lcm pinctrl fail. pinctrl_name:%s\n", pinctrl_name);
		return -1;
	}
	phandle = fdt32_to_cpu(*(unsigned int *)data);

	offset = fdt_node_offset_by_phandle(get_lk_overlayed_dtb(), phandle);
	if (offset < 0) {
		dprintf(INFO, "get lcm pinctrl fail. phandle:0x%x\n", phandle);
		return -1;
	}
	offset = fdt_subnode_offset(get_lk_overlayed_dtb(), offset, "pins_cmd_dat");
	if (offset < 0) {
		dprintf(INFO, "get pins_cmd_dat node fail\n");
		return -1;
	}
	data = (unsigned int*)fdt_getprop(get_lk_overlayed_dtb(), offset, "pinmux", &len);
	if (!data || !len) {
		dprintf(INFO, "get pinmux fail\n");
		return -1;
	}

	/* Pin define format: 0~7->pin status, 8~15->pin id */
	return fdt32_to_cpu(*(unsigned int *)data) >> 8;
}
#else
int lcm_util_get_i2c_lcd_bias(int *id, int *addr)
{
	return -1;
}
int lcm_util_get_pin(char *pin_name)
{
	return -1;
}
#endif

#if defined(MTK_LCM_DEVICE_TREE_SUPPORT)
static LCM_STATUS _lcm_util_check_data(char type, const LCM_DATA_T1 *t1)
{
	switch (type) {
		case LCM_UTIL_RESET:
			switch (t1->data) {
				case LCM_UTIL_RESET_LOW:
				case LCM_UTIL_RESET_HIGH:
					break;

				default:
					return LCM_STATUS_ERROR;
			}
			break;

		case LCM_UTIL_MDELAY:
		case LCM_UTIL_UDELAY:
			// no limitation
			break;

		default:
			return LCM_STATUS_ERROR;
	}


	return LCM_STATUS_OK;
}


static LCM_STATUS _lcm_util_check_write_cmd_v1(const LCM_DATA_T5 *t5)
{
	if (t5 == NULL) {
		return LCM_STATUS_ERROR;
	}

	if (t5->size == 0) {
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


static LCM_STATUS _lcm_util_check_write_cmd_v2(const LCM_DATA_T3 *t3)
{
	if (t3 == NULL) {
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


static LCM_STATUS _lcm_util_check_write_cmd_v23(const LCM_DATA_T3 *t3)
{
	if (t3 == NULL)
		return LCM_STATUS_ERROR;

	return LCM_STATUS_OK;
}


static LCM_STATUS _lcm_util_check_read_cmd_v2(const LCM_DATA_T4 *t4)
{
	if (t4 == NULL) {
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


LCM_STATUS lcm_util_set_data(const LCM_UTIL_FUNCS *lcm_util, char type, LCM_DATA_T1 *t1)
{
	// check parameter is valid
	if (LCM_STATUS_OK == _lcm_util_check_data(type, t1)) {
		switch (type) {
			case LCM_UTIL_RESET:
				lcm_util->set_reset_pin((unsigned int)t1->data);
				break;

			case LCM_UTIL_MDELAY:
				lcm_util->mdelay((unsigned int)t1->data);
				break;

			case LCM_UTIL_UDELAY:
				lcm_util->udelay((unsigned int)t1->data);
				break;

			default:
				dprintf(0, "[LCM][ERROR] %s: %d \n", __func__, (unsigned int)type);
				return LCM_STATUS_ERROR;
		}
	} else {
		dprintf(0, "[LCM][ERROR] %s: 0x%x, 0x%x \n", __func__, (unsigned int)type, (unsigned int)t1->data);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


LCM_STATUS lcm_util_set_write_cmd_v1(const LCM_UTIL_FUNCS *lcm_util, LCM_DATA_T5 *t5, unsigned char force_update)
{
	unsigned int i;
	unsigned int cmd[32];

	// check parameter is valid
	if (LCM_STATUS_OK == _lcm_util_check_write_cmd_v1(t5)) {
		memset(cmd, 0x0, sizeof(unsigned int) * 32);
		for (i=0; i<t5->size; i++) {
			cmd[i] = (t5->cmd[i*4+3] << 24) | (t5->cmd[i*4+2] << 16) | (t5->cmd[i*4+1] << 8) | (t5->cmd[i*4]);
		}
		lcm_util->dsi_set_cmdq(cmd, (unsigned int)t5->size, force_update);
	} else {
		dprintf(0, "[LCM][ERROR] %s: 0x%p, %d, %d \n", __func__, t5->cmd, (unsigned int)t5->size, force_update);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


LCM_STATUS lcm_util_set_write_cmd_v2(const LCM_UTIL_FUNCS *lcm_util, LCM_DATA_T3 *t3, unsigned char force_update)
{
	// check parameter is valid
	if (LCM_STATUS_OK == _lcm_util_check_write_cmd_v2(t3)) {
		lcm_util->dsi_set_cmdq_V2((unsigned char)t3->cmd, (unsigned char)t3->size, (unsigned char*)t3->data, force_update);
	} else {
		dprintf(0, "[LCM][ERROR] %s: 0x%x, %d, 0x%p, %d \n", __func__, (unsigned int)t3->cmd, (unsigned int)t3->size, t3->data, force_update);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


LCM_STATUS lcm_util_set_write_cmd_v23(const LCM_UTIL_FUNCS *lcm_util, void *handle, LCM_DATA_T3 *t3,
				     unsigned char force_update)
{
	/* check parameter is valid */
	if (LCM_STATUS_OK == _lcm_util_check_write_cmd_v23(t3))
		lcm_util->dsi_set_cmdq_V23(handle, (unsigned char)t3->cmd, (unsigned char)t3->size,
					  (unsigned char *)t3->data, force_update);
	else {
		pr_debug("[LCM][ERROR] %s/%d: 0x%x, %d, 0x%p\n", __func__, __LINE__, t3->cmd,
		       t3->size, t3->data);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}


LCM_STATUS lcm_util_set_read_cmd_v2(const LCM_UTIL_FUNCS *lcm_util, LCM_DATA_T4 *t4, unsigned int *compare)
{
	if (compare == NULL) {
		dprintf(0, "[LCM][ERROR] %s: NULL parameter \n", __func__);
		return LCM_STATUS_ERROR;
	}

	*compare = 0;

	// check parameter is valid
	if (LCM_STATUS_OK == _lcm_util_check_read_cmd_v2(t4)) {
		unsigned char buffer[4];

		lcm_util->dsi_dcs_read_lcm_reg_v2((unsigned char)t4->cmd, buffer, 4);

		if (buffer[t4->location] == (unsigned char)t4->data) {
			*compare = 1;
		}
	} else {
		dprintf(0, "[LCM][ERROR] %s: 0x%x, %d, 0x%x \n", __func__, (unsigned int)t4->cmd, (unsigned int)t4->location, (unsigned int)t4->data);
		return LCM_STATUS_ERROR;
	}

	return LCM_STATUS_OK;
}
#endif

