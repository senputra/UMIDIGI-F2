/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2019. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#define LOG_TAG "TUI_OVL"

#include "ddp_log.h"
#include "ddp_dsi.h"
#include "ddp_reg.h"
#include "ddp_color_format.h"
#include "ddp_info.h"
#include "ddp_ovl.h"
#include "display_tui.h"

#define OVL_REG_BACK_MAX          (40)
#define OVL_LAYER_OFFSET        (0x20)
#define OVL_RDMA_DEBUG_OFFSET   (0x4)
#define DISP_OPT_SHADOW_MODE 1
#define DISP_OPT_OVL_EXT_LAYER 0

struct OVL_REG {
	unsigned long address;
	unsigned int value;
};

static enum DISP_MODULE_ENUM ovl_index_module[OVL_NUM] = {
	DISP_MODULE_OVL0, DISP_MODULE_OVL1, DISP_MODULE_OVL0_2L, DISP_MODULE_OVL1_2L
};

static unsigned int reg_back_cnt[OVL_NUM];
static struct OVL_REG reg_back[OVL_NUM][OVL_REG_BACK_MAX];
static unsigned int gOVLBackground = 0xFF000000;

static inline int is_module_ovl(enum DISP_MODULE_ENUM module)
{
	if (module == DISP_MODULE_OVL0 ||
	    module == DISP_MODULE_OVL1 ||
	    module == DISP_MODULE_OVL0_2L || module == DISP_MODULE_OVL1_2L ||
	    module == DISP_MODULE_OVL0_2L_VIRTUAL ||
	    module == DISP_MODULE_OVL1_2L_VIRTUAL)
		return 1;
	else
		return 0;
}

unsigned long ovl_base_addr(enum DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_OVL0:
		return DDP_REG_BASE_DISP_OVL0;
	case DISP_MODULE_OVL0_2L:
		return DDP_REG_BASE_DISP_OVL0_2L;
	case DISP_MODULE_OVL1_2L:
		return DDP_REG_BASE_DISP_OVL1_2L;
	default:
		DDPERR("invalid ovl module=%d, get ovl base fail\n", module);
		ASSERT(0);
		return DISP_MODULE_UNKNOWN;
	}
	return 0;
}

static inline unsigned long ovl_layer_num(enum DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_OVL0:
		return 4;
	case DISP_MODULE_OVL1:
		return 4;
	case DISP_MODULE_OVL0_2L:
		return 2;
	case DISP_MODULE_OVL1_2L:
		return 2;
	default:
		DDPERR("invalid ovl module=%d, get ovl layer number fail\n", module);
		ASSERT(0);
		return DISP_MODULE_UNKNOWN;
	}
	return 0;
}

unsigned long ovl_to_index(enum DISP_MODULE_ENUM module)
{
	int i;

	for (i = 0; i < OVL_NUM; i++) {
		if (ovl_index_module[i] == module)
			return i;
	}
	DDPERR("invalid ovl module=%d, get ovl index fail\n", module);
	ASSERT(0);
	return 0;
}

int ovl_roi(enum DISP_MODULE_ENUM module,
	    unsigned int bg_w, unsigned int bg_h, unsigned int bg_color, void *handle)
{
	unsigned long ovl_base = ovl_base_addr(module);

	if ((bg_w > OVL_MAX_WIDTH) || (bg_h > OVL_MAX_HEIGHT)) {
		DDPERR("ovl_roi,exceed OVL max size, w=%d, h=%d\n", bg_w, bg_h);
		ASSERT(0);
	}

	DISP_REG_SET(handle, ovl_base + DISP_REG_OVL_ROI_SIZE, bg_h << 16 | bg_w);

	DISP_REG_SET(handle, ovl_base + DISP_REG_OVL_ROI_BGCLR, bg_color);

	return 0;
}

static int ovl_layer_config(enum DISP_MODULE_ENUM module,
		unsigned int layer,
		unsigned int is_engine_sec,
		const struct OVL_CONFIG_STRUCT * const cfg,
		const struct disp_rect * const ovl_partial_roi,
		const struct disp_rect * const layer_partial_roi,
		void *handle, int is_dual)
{
	unsigned int value = 0;
	unsigned int Bpp, input_swap, input_fmt;
	unsigned int rgb_swap = 0;
	int is_rgb;
	int color_matrix = 0x4;
	int rotate = 0;
	int is_ext_layer = cfg->ext_layer != -1;
	unsigned long ovl_base = ovl_base_addr(module);
	unsigned long ext_layer_offset = is_ext_layer ? (DISP_REG_OVL_EL0_CON - DISP_REG_OVL_L0_CON) : 0;
	unsigned long ext_layer_offset_clr = is_ext_layer ? (DISP_REG_OVL_EL0_CLEAR - DISP_REG_OVL_L0_CLR) : 0;
	unsigned long ext_layer_offset_addr = is_ext_layer ? (DISP_REG_OVL_EL0_ADDR - DISP_REG_OVL_L0_ADDR) : 0;
	unsigned long layer_offset = ovl_base + ext_layer_offset +
					(is_ext_layer?cfg->ext_layer:layer) * OVL_LAYER_OFFSET;
	unsigned long layer_offset_clr = ovl_base + ext_layer_offset_clr + (is_ext_layer?cfg->ext_layer:layer) * 4;
	unsigned long layer_offset_rdma_ctrl = ovl_base + layer * OVL_LAYER_OFFSET;
	unsigned long layer_offset_addr = ovl_base + ext_layer_offset_addr +
					(is_ext_layer?cfg->ext_layer*4:layer*OVL_LAYER_OFFSET);
	unsigned int offset = 0;
	enum UNIFIED_COLOR_FMT format = cfg->fmt;
	unsigned int src_x = cfg->src_x;
	unsigned int src_y = cfg->src_y;
	unsigned int dst_x = cfg->dst_x;
	unsigned int dst_y = cfg->dst_y;
	unsigned int dst_w = cfg->dst_w;
	unsigned int dst_h = cfg->dst_h;

	if (ovl_partial_roi != NULL) {
		dst_x = layer_partial_roi->x - ovl_partial_roi->x;
		dst_y = layer_partial_roi->y - ovl_partial_roi->y;
		dst_w = layer_partial_roi->width;
		dst_h = layer_partial_roi->height;
		src_x = cfg->src_x + layer_partial_roi->x - cfg->dst_x;
		src_y = cfg->src_y + layer_partial_roi->y - cfg->dst_y;

		DDPDBG("layer partial (%d,%d)(%d,%d,%d,%d) to (%d,%d)(%d,%d,%d,%d)\n",
				cfg->src_x, cfg->src_y, cfg->dst_x, cfg->dst_y, cfg->dst_w, cfg->dst_h,
				src_x, src_y, dst_x, dst_y, dst_w, dst_h);
	}

	if (dst_w > OVL_MAX_WIDTH)
		ASSERT(dst_w < OVL_MAX_WIDTH);
	if (dst_h > OVL_MAX_HEIGHT)
		ASSERT(dst_h < OVL_MAX_HEIGHT);

	if (!cfg->addr && cfg->source == OVL_LAYER_SOURCE_MEM) {
		DDPERR("source from memory, but addr is 0!\n");
		ASSERT(0);
		return -1;
	}

#ifdef CONFIG_MTK_LCM_PHYSICAL_ROTATION_HW
	if (is_dual || (module != DISP_MODULE_OVL1 && module != DISP_MODULE_OVL1_2L))
		rotate = 1;
#endif

	Bpp = UFMT_GET_Bpp(format);
	input_swap = UFMT_GET_BYTESWAP(format);
	input_fmt = UFMT_GET_FORMAT(format);
	is_rgb = UFMT_GET_RGB(format);

	if (format == UFMT_UYVY || format == UFMT_VYUY ||
	    format == UFMT_YUYV || format == UFMT_YVYU) {
		unsigned int regval = 0;

		if (src_x % 2) {
			src_x -= 1;	/* make src_x to even */
			dst_w += 1;
			regval |= REG_FLD_VAL(OVL_L_CLIP_FLD_LEFT, 1);
		}

		if ((src_x + dst_w) % 2) {
			dst_w += 1;	/* make right boundary even */
			regval |= REG_FLD_VAL(OVL_L_CLIP_FLD_RIGHT, 1);
		}
		DISP_REG_SET(handle, DISP_REG_OVL_L0_CLIP + layer_offset, regval);
	} else
		DISP_REG_SET(handle, DISP_REG_OVL_L0_CLIP + layer_offset, 0);

	switch (cfg->yuv_range) {
	case 0:
		color_matrix = 4;
		break;		/* BT601_full */
	case 1:
		color_matrix = 6;
		break;		/* BT601 */
	case 2:
		color_matrix = 7;
		break;		/* BT709 */
	default:
		DDPERR("un-recognized yuv_range=%d!\n", cfg->yuv_range);
		color_matrix = 4;
	}


	DISP_REG_SET(handle, DISP_REG_OVL_RDMA0_CTRL + layer_offset_rdma_ctrl, 0x1);

	value = (REG_FLD_VAL((L_CON_FLD_LSRC), (cfg->source)) |
		 REG_FLD_VAL((L_CON_FLD_CFMT), (input_fmt)) |
		 REG_FLD_VAL((L_CON_FLD_AEN), (cfg->aen)) |
		 REG_FLD_VAL((L_CON_FLD_APHA), (cfg->alpha)) |
		 REG_FLD_VAL((L_CON_FLD_SKEN), (cfg->keyEn)) |
		 REG_FLD_VAL((L_CON_FLD_BTSW), (input_swap)));

	if (!is_rgb)
		value = value | REG_FLD_VAL((L_CON_FLD_MTX), (color_matrix));

	if (rotate)
		value |= REG_FLD_VAL((L_CON_FLD_VIRTICAL_FLIP), (1)) | REG_FLD_VAL((L_CON_FLD_HORI_FLIP), (1));

	DISP_REG_SET(handle, DISP_REG_OVL_L0_CON + layer_offset, value);

	DISP_REG_SET(handle, DISP_REG_OVL_L0_CLR + layer_offset_clr, 0xff000000);

	DISP_REG_SET(handle, DISP_REG_OVL_L0_SRC_SIZE + layer_offset, dst_h << 16 | dst_w);

	if (rotate) {
		unsigned int bg_h, bg_w;

		bg_h = DISP_REG_GET(ovl_base + DISP_REG_OVL_ROI_SIZE);
		bg_w = bg_h & 0xFFFF;
		bg_h = bg_h >> 16;
		DISP_REG_SET(handle, DISP_REG_OVL_L0_OFFSET + layer_offset,
			     ((bg_h - dst_h - dst_y) << 16) | (bg_w - dst_w - dst_x));
		DISP_REG_SET(handle, DISP_REG_OVL_L0_ADDR + layer_offset_addr,
			     cfg->addr + cfg->src_pitch * (dst_h + src_y - 1) + (src_x + dst_w) * Bpp - 1);
		offset = (src_x + dst_w) * Bpp + (src_y + dst_h - 1) * cfg->src_pitch - 1;
	} else {
		DISP_REG_SET(handle, DISP_REG_OVL_L0_OFFSET + layer_offset, (dst_y << 16) | dst_x);
		DISP_REG_SET(handle, DISP_REG_OVL_L0_ADDR + layer_offset_addr,
			cfg->addr + src_x * Bpp + src_y * cfg->src_pitch);
		offset = src_x * Bpp + src_y * cfg->src_pitch;
	}

	if (!is_engine_sec) {
		DISP_REG_SET(handle, DISP_REG_OVL_L0_ADDR + layer_offset_addr, cfg->addr + offset);
	} else {
		/*Do nothing*/
	}
	DISP_REG_SET(handle, DISP_REG_OVL_L0_SRCKEY + layer_offset, cfg->key);

	value = (((cfg->sur_aen & 0x1) << 15) |
		 ((cfg->dst_alpha & 0x3) << 6) | ((cfg->dst_alpha & 0x3) << 4) |
		 ((cfg->src_alpha & 0x3) << 2) | (cfg->src_alpha & 0x3));

	value = (REG_FLD_VAL((L_PITCH_FLD_SUR_ALFA), (value)) |
		 REG_FLD_VAL((L_PITCH_FLD_SRC_PITCH), (cfg->src_pitch)));

	if (cfg->const_bld)
		value = value | REG_FLD_VAL((L_PITCH_FLD_CONST_BLD), (1));
	DISP_REG_SET(handle, DISP_REG_OVL_L0_PITCH + layer_offset, value);

	return 0;
}

static void ovl_store_regs(enum DISP_MODULE_ENUM module)
{
	int i = 0;
	unsigned long ovl_base = ovl_base_addr(module);
	int idx = ovl_to_index(module);
	static unsigned long regs[3];

	regs[0] = DISP_REG_OVL_ROI_SIZE + ovl_base;
	regs[1] = DISP_REG_OVL_ROI_BGCLR + ovl_base;
	regs[2] = DISP_REG_OVL_DATAPATH_CON + ovl_base;

	reg_back_cnt[idx] = sizeof(regs) / sizeof(unsigned long);
	ASSERT(reg_back_cnt[idx] <= OVL_REG_BACK_MAX);

	for (i = 0; i < reg_back_cnt[idx]; i++) {
		reg_back[idx][i].address = regs[i];
		reg_back[idx][i].value = DISP_REG_GET(regs[i]);
	}
	DDPMSG("store %d cnt registers on ovl %d\n", reg_back_cnt[idx], idx);

}

static void ovl_restore_regs(enum DISP_MODULE_ENUM module, void *handle)
{
	int idx = ovl_to_index(module);
	int i = reg_back_cnt[idx];

	while (i > 0) {
		i--;
		DISP_REG_SET(handle, reg_back[idx][i].address, reg_back[idx][i].value);
	}
	DDPMSG("restore %d cnt registers on ovl %d\n", reg_back_cnt[idx], idx);
	reg_back_cnt[idx] = 0;
}

int ovl_connect(enum DISP_MODULE_ENUM module, enum DISP_MODULE_ENUM prev,
		enum DISP_MODULE_ENUM next, int connect, void *handle)
{
	unsigned long ovl_base = ovl_base_addr(module);

	if (connect && is_module_ovl(prev))
		DISP_REG_SET_FIELD(handle, DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   ovl_base + DISP_REG_OVL_DATAPATH_CON, 1);
	else
		DISP_REG_SET_FIELD(handle, DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   ovl_base + DISP_REG_OVL_DATAPATH_CON, 0);
	return 0;
}

unsigned int ddp_ovl_get_cur_addr(bool rdma_mode, int layerid)
{
	/*just workaround, should remove this func */
	unsigned long ovl_base = ovl_base_addr(DISP_MODULE_OVL0);
	unsigned long rdma_base = rdma_base_addr(DISP_MODULE_RDMA0);

	if (rdma_mode)
		return DISP_REG_GET(rdma_base + DISP_REG_RDMA_MEM_START_ADDR);

	if (DISP_REG_GET(DISP_REG_OVL_RDMA0_CTRL + layerid * 0x20 + ovl_base) & 0x1)
		return DISP_REG_GET(DISP_REG_OVL_L0_ADDR + layerid * 0x20 + ovl_base);
	else
		return 0;
}

void ovl_get_address(enum DISP_MODULE_ENUM module, unsigned long *add)
{
	int i = 0;
	unsigned long ovl_base = ovl_base_addr(module);
	unsigned long layer_off = 0;
	unsigned int src_on = DISP_REG_GET(DISP_REG_OVL_SRC_CON + ovl_base);

	for (i = 0; i < 4; i++) {
		layer_off = i * OVL_LAYER_OFFSET + ovl_base;
		if (src_on & (0x1 << i))
			add[i] = DISP_REG_GET(layer_off + DISP_REG_OVL_L0_ADDR);
		else
			add[i] = 0;
	}
}

static int ovl_check_input_param(struct OVL_CONFIG_STRUCT *config)
{
	return 0;
}

/* use noinline to reduce stack size */
static void print_layer_config_args(int module, int local_layer, struct OVL_CONFIG_STRUCT *ovl_cfg,
												 struct disp_rect *roi)
{
	DDPDBG("%s, layer=%d(%d), source=%s, off(x=%d, y=%d), dst(%d, %d, %d, %d),pitch=%d,",
		ddp_get_module_name(module), local_layer, ovl_cfg->layer,
		(ovl_cfg->source == 0) ? "memory" : "dim", ovl_cfg->src_x, ovl_cfg->src_y,
		ovl_cfg->dst_x, ovl_cfg->dst_y, ovl_cfg->dst_w, ovl_cfg->dst_h, ovl_cfg->src_pitch);
	DDPDBG("fmt=%s, addr=0x%x, keyEn=%d, key=%d, aen=%d, alpha=%d,",
		unified_color_fmt_name(ovl_cfg->fmt), ovl_cfg->addr,
		ovl_cfg->keyEn, ovl_cfg->key, ovl_cfg->aen, ovl_cfg->alpha);
	DDPDBG("sur_aen=%d,sur_alpha=0x%x,yuv_range=%d,sec=%d,const_bld=%d\n",
		ovl_cfg->sur_aen, (ovl_cfg->dst_alpha << 2) | ovl_cfg->src_alpha,
		ovl_cfg->yuv_range, ovl_cfg->security, ovl_cfg->const_bld);
	if (roi)
		DDPDBG("dirty(%d,%d,%d,%d)\n", roi->x, roi->y, roi->height, roi->width);
}

/* for enabled layers: layout continuously for each OVL HW engine
 * for disabled layers: ignored
 */
static int ovl_layer_layout(enum DISP_MODULE_ENUM module, struct disp_ddp_path_config *pConfig)
{
	int local_layer, global_layer = 0;
	int ovl_idx = module;
	int phy_layer = -1, ext_layer = -1, ext_layer_idx = 0;
	struct OVL_CONFIG_STRUCT *ovl_cfg;

	/* 1. check if it has been prepared, just only prepare once for each frame */
#if 1
	for (global_layer = 0; global_layer < TOTAL_OVL_LAYER_NUM; global_layer++) {
		if (!(pConfig->ovl_layer_scanned & (1 << global_layer)))
			break;
	}
	if (global_layer >= TOTAL_OVL_LAYER_NUM)
		return 0;
#else
	if (pConfig->ovl_layer_scanned != 0)
		return 0;
#endif
	/* 2. prepare layer layout */
	for (local_layer = 0; local_layer < TOTAL_OVL_LAYER_NUM; local_layer++) {
		ovl_cfg = &pConfig->ovl_config[local_layer];
		ovl_cfg->ovl_index = -1;
	}

	for (local_layer = 0; local_layer <= ovl_layer_num(module); global_layer++) {

		if (global_layer >= TOTAL_OVL_LAYER_NUM)
			break;

		ovl_cfg = &pConfig->ovl_config[global_layer];

		/* Check if there has any extended layer on last phy layer */
		if (local_layer == ovl_layer_num(module)) {
			if (!DISP_OPT_OVL_EXT_LAYER || ovl_cfg->ext_sel_layer == -1)
				break;
		}

		ext_layer = -1;
		ovl_cfg->phy_layer = 0;
		ovl_cfg->ext_layer = -1;

		pConfig->ovl_layer_scanned |= (1 << global_layer);

		/* skip disabled layers, but need to decrease local_layer to make layout continuously
		 * all layers layout continuously by HRT Calc, so this is not necessary
		 */
		if (ovl_cfg->layer_en == 0) {
			local_layer++;
			continue;
		}

		if (DISP_OPT_OVL_EXT_LAYER) {
			if (ovl_cfg->ext_sel_layer != -1) {
				/* always layout from idx=0, so layer_idx here should be the same as ext_sel_layer
				 * TODO: remove this if we dispatch layer id not always start from idx=0
				 */
				if (phy_layer != ovl_cfg->ext_sel_layer) {
					DDPERR("L%d layout not match: cur=%d, in=%d\n",
							global_layer, phy_layer, ovl_cfg->ext_sel_layer);
					phy_layer++;
					ext_layer = -1;
				} else {
					ext_layer = ext_layer_idx++;
				}
			} else {
				/* all phy layers are layout continuously */
				phy_layer = local_layer;
				local_layer++;
			}
		} else {
			phy_layer = local_layer;
			local_layer++;
		}

		ovl_cfg->ovl_index = ovl_idx;
		ovl_cfg->phy_layer = phy_layer;
		ovl_cfg->ext_layer = ext_layer;
		DDPDBG("layout:L%d->ovl%d,phy:%d,ext:%d,ext_sel:%d\n",
				global_layer, ovl_idx, phy_layer, ext_layer,
				(ext_layer >= 0) ? phy_layer : ovl_cfg->ext_sel_layer);
	}

	return 1;
}

int ovl_config_l(enum DISP_MODULE_ENUM module, struct disp_ddp_path_config *pConfig, void *handle)
{
	int enabled_layers = 0;
	int has_sec_layer = 0;
	int layer_id;
	int enabled_ext_layers = 0, ext_sel_layers = 0;

	if (pConfig->dst_dirty)
		ovl_roi(module, pConfig->dst_w, pConfig->dst_h, gOVLBackground, handle);

	if (!pConfig->ovl_dirty)
		return 0;

	ovl_layer_layout(module, pConfig);

	for (layer_id = 0; layer_id < TOTAL_OVL_LAYER_NUM; layer_id++) {
		struct OVL_CONFIG_STRUCT *ovl_cfg = &pConfig->ovl_config[layer_id];
		int enable = ovl_cfg->layer_en;

		if (enable == 0)
			continue;
		if (ovl_check_input_param(ovl_cfg)) {
			DDPAEE("invalid layer parameters!\n");
			continue;
		}
		if (ovl_cfg->ovl_index != module)
			continue;

		print_layer_config_args(module, ovl_cfg->phy_layer, ovl_cfg, NULL);
		ovl_layer_config(module, ovl_cfg->phy_layer, has_sec_layer, ovl_cfg,
				NULL, NULL, handle, pConfig->is_dual);

		if (ovl_cfg->ext_layer != -1) {
			enabled_ext_layers |= enable << ovl_cfg->ext_layer;
			ext_sel_layers |= ovl_cfg->phy_layer << (16 + 4 * ovl_cfg->ext_layer);
		} else {
			enabled_layers |= enable << ovl_cfg->phy_layer;
		}
	}

	DDPDBG("ovl%d enabled_layers=0x%01x, enabled_ext_layers=0x%01x, ext_sel_layers=0x%04x\n",
		module, enabled_layers, enabled_ext_layers, ext_sel_layers>>16);
	DISP_REG_SET(handle, ovl_base_addr(module) + DISP_REG_OVL_SRC_CON, enabled_layers);
	/* ext layer control */
	DISP_REG_SET(handle, ovl_base_addr(module) + DISP_REG_OVL_DATAPATH_EXT_CON,
		enabled_ext_layers | ext_sel_layers);

	return 0;
}

unsigned int ovl_disable_irq_backup(enum DISP_MODULE_ENUM module, void *handle)
{
	unsigned long base_addr = ovl_base_addr(module);
	unsigned int old_val;

	old_val = DISP_REG_GET(base_addr + DISP_REG_OVL_INTEN);
	DISP_REG_SET(handle, base_addr + DISP_REG_OVL_INTEN, 0x0);
	DDPDBG("%s, irq_enable:old_val =%d\n", __func__, old_val);

    return old_val;
}

int ovl_irq_restore(enum DISP_MODULE_ENUM module, void *handle, unsigned int irq_val)
{
	unsigned long base_addr = ovl_base_addr(module);

	DISP_REG_SET(handle, base_addr + DISP_REG_OVL_INTEN, irq_val);
	return 0;
}

/***************** ovl debug info ************/

void ovl_dump_reg(enum DISP_MODULE_ENUM module)
{
	if (0) {
		unsigned long module_base = ovl_base_addr(module);

		DDPDUMP("== START: DISP %s REGS ==\n", ddp_get_module_name(module));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x0, INREG32(module_base + 0x0),
			0x4, INREG32(module_base + 0x4),
			0x8, INREG32(module_base + 0x8),
			0xC, INREG32(module_base + 0xC));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x10, INREG32(module_base + 0x10),
			0x14, INREG32(module_base + 0x14),
			0x20, INREG32(module_base + 0x20),
			0x24, INREG32(module_base + 0x24));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x28, INREG32(module_base + 0x28),
			0x2C, INREG32(module_base + 0x2C),
			0x30, INREG32(module_base + 0x30),
			0x34, INREG32(module_base + 0x34));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x38, INREG32(module_base + 0x38),
			0x3C, INREG32(module_base + 0x3C),
			0xF40, INREG32(module_base + 0xF40),
			0x44, INREG32(module_base + 0x44));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x48, INREG32(module_base + 0x48),
			0x4C, INREG32(module_base + 0x4C),
			0x50, INREG32(module_base + 0x50),
			0x54, INREG32(module_base + 0x54));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x58, INREG32(module_base + 0x58),
			0x5C, INREG32(module_base + 0x5C),
			0xF60, INREG32(module_base + 0xF60),
			0x64, INREG32(module_base + 0x64));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x68, INREG32(module_base + 0x68),
			0x6C, INREG32(module_base + 0x6C),
			0x70, INREG32(module_base + 0x70),
			0x74, INREG32(module_base + 0x74));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x78, INREG32(module_base + 0x78),
			0x7C, INREG32(module_base + 0x7C),
			0xF80, INREG32(module_base + 0xF80),
			0x84, INREG32(module_base + 0x84));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x88, INREG32(module_base + 0x88),
			0x8C, INREG32(module_base + 0x8C),
			0x90, INREG32(module_base + 0x90),
			0x94, INREG32(module_base + 0x94));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x98, INREG32(module_base + 0x98),
			0x9C, INREG32(module_base + 0x9C),
			0xFa0, INREG32(module_base + 0xFa0),
			0xa4, INREG32(module_base + 0xa4));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0xa8, INREG32(module_base + 0xa8),
			0xAC, INREG32(module_base + 0xAC),
			0xc0, INREG32(module_base + 0xc0),
			0xc8, INREG32(module_base + 0xc8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0xcc, INREG32(module_base + 0xcc),
			0xd0, INREG32(module_base + 0xd0),
			0xe0, INREG32(module_base + 0xe0),
			0xe8, INREG32(module_base + 0xe8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0xec, INREG32(module_base + 0xec),
			0xf0, INREG32(module_base + 0xf0),
			0x100, INREG32(module_base + 0x100),
			0x108, INREG32(module_base + 0x108));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x10c, INREG32(module_base + 0x10c),
			0x110, INREG32(module_base + 0x110),
			0x120, INREG32(module_base + 0x120),
			0x128, INREG32(module_base + 0x128));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x12c, INREG32(module_base + 0x12c),
			0x130, INREG32(module_base + 0x130),
			0x134, INREG32(module_base + 0x134),
			0x138, INREG32(module_base + 0x138));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x13c, INREG32(module_base + 0x13c),
			0x140, INREG32(module_base + 0x140),
			0x144, INREG32(module_base + 0x144),
			0x148, INREG32(module_base + 0x148));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x14c, INREG32(module_base + 0x14c),
			0x150, INREG32(module_base + 0x150),
			0x154, INREG32(module_base + 0x154),
			0x158, INREG32(module_base + 0x158));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x15c, INREG32(module_base + 0x15c),
			0x160, INREG32(module_base + 0x160),
			0x164, INREG32(module_base + 0x164),
			0x168, INREG32(module_base + 0x168));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x16c, INREG32(module_base + 0x16c),
			0x170, INREG32(module_base + 0x170),
			0x174, INREG32(module_base + 0x174),
			0x178, INREG32(module_base + 0x178));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x17c, INREG32(module_base + 0x17c),
			0x180, INREG32(module_base + 0x180),
			0x184, INREG32(module_base + 0x184),
			0x188, INREG32(module_base + 0x188));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x18c, INREG32(module_base + 0x18c),
			0x190, INREG32(module_base + 0x190),
			0x194, INREG32(module_base + 0x194),
			0x198, INREG32(module_base + 0x198));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x19c, INREG32(module_base + 0x19c),
			0x1a0, INREG32(module_base + 0x1a0),
			0x1a4, INREG32(module_base + 0x1a4),
			0x1a8, INREG32(module_base + 0x1a8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x1ac, INREG32(module_base + 0x1ac),
			0x1b0, INREG32(module_base + 0x1b0),
			0x1b4, INREG32(module_base + 0x1b4),
			0x1b8, INREG32(module_base + 0x1b8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x1bc, INREG32(module_base + 0x1bc),
			0x1c0, INREG32(module_base + 0x1c0),
			0x1c4, INREG32(module_base + 0x1c4),
			0x1c8, INREG32(module_base + 0x1c8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x1cc, INREG32(module_base + 0x1cc),
			0x1d0, INREG32(module_base + 0x1d0),
			0x1d4, INREG32(module_base + 0x1d4),
			0x1e0, INREG32(module_base + 0x1e0));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x1e4, INREG32(module_base + 0x1e4),
			0x1e8, INREG32(module_base + 0x1e8),
			0x1ec, INREG32(module_base + 0x1ec),
			0x1F0, INREG32(module_base + 0x1F0));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x1F4, INREG32(module_base + 0x1F4),
			0x1F8, INREG32(module_base + 0x1F8),
			0x1FC, INREG32(module_base + 0x1FC),
			0x200, INREG32(module_base + 0x200));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x208, INREG32(module_base + 0x208),
			0x20C, INREG32(module_base + 0x20C),
			0x210, INREG32(module_base + 0x210),
			0x214, INREG32(module_base + 0x214));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x218, INREG32(module_base + 0x218),
			0x21C, INREG32(module_base + 0x21C),
			0x230, INREG32(module_base + 0x230),
			0x234, INREG32(module_base + 0x234));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x238, INREG32(module_base + 0x238),
			0x240, INREG32(module_base + 0x240),
			0x244, INREG32(module_base + 0x244),
			0x24c, INREG32(module_base + 0x24c));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x250, INREG32(module_base + 0x250),
			0x254, INREG32(module_base + 0x254),
			0x258, INREG32(module_base + 0x258),
			0x25c, INREG32(module_base + 0x25c));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x260, INREG32(module_base + 0x260),
			0x264, INREG32(module_base + 0x264),
			0x268, INREG32(module_base + 0x268),
			0x26C, INREG32(module_base + 0x26C));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x270, INREG32(module_base + 0x270),
			0x280, INREG32(module_base + 0x280),
			0x284, INREG32(module_base + 0x284),
			0x288, INREG32(module_base + 0x288));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x28C, INREG32(module_base + 0x28C),
			0x290, INREG32(module_base + 0x290),
			0x29C, INREG32(module_base + 0x29C),
			0x2A0, INREG32(module_base + 0x2A0));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x2A4, INREG32(module_base + 0x2A4),
			0x2B0, INREG32(module_base + 0x2B0),
			0x2B4, INREG32(module_base + 0x2B4),
			0x2B8, INREG32(module_base + 0x2B8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x2BC, INREG32(module_base + 0x2BC),
			0x2C0, INREG32(module_base + 0x2C0),
			0x2C4, INREG32(module_base + 0x2C4),
			0x2C8, INREG32(module_base + 0x2C8));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x324, INREG32(module_base + 0x324),
			0x330, INREG32(module_base + 0x330),
			0x334, INREG32(module_base + 0x334),
			0x338, INREG32(module_base + 0x338));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x33C, INREG32(module_base + 0x33C),
			0xFB0, INREG32(module_base + 0xFB0),
			0x344, INREG32(module_base + 0x344),
			0x348, INREG32(module_base + 0x348));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x34C, INREG32(module_base + 0x34C),
			0x350, INREG32(module_base + 0x350),
			0x354, INREG32(module_base + 0x354),
			0x358, INREG32(module_base + 0x358));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x35C, INREG32(module_base + 0x35C),
			0xFB4, INREG32(module_base + 0xFB4),
			0x364, INREG32(module_base + 0x364),
			0x368, INREG32(module_base + 0x368));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x36C, INREG32(module_base + 0x36C),
			0x370, INREG32(module_base + 0x370),
			0x374, INREG32(module_base + 0x374),
			0x378, INREG32(module_base + 0x378));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x37C, INREG32(module_base + 0x37C),
			0xFB8, INREG32(module_base + 0xFB8),
			0x384, INREG32(module_base + 0x384),
			0x388, INREG32(module_base + 0x388));
		DDPDUMP("OVL0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
			0x38C, INREG32(module_base + 0x38C),
			0x390, INREG32(module_base + 0x390),
			0x394, INREG32(module_base + 0x394),
			0x398, INREG32(module_base + 0x398));
		DDPDUMP("OVL0: 0x%04x=0x%08x\n",
			0xFC0, INREG32(module_base + 0xFC0));
		DDPDUMP("-- END: DISP %s REGS --\n", ddp_get_module_name(module));
	} else {
		unsigned long offset = ovl_base_addr(module);
		unsigned int src_on = DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset);

		DDPDUMP("== DISP %s REGS ==\n", ddp_get_module_name(module));
		DDPDUMP("0x000: 0x%08x 0x%08x 0x%08x 0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_STA + offset),
			DISP_REG_GET(DISP_REG_OVL_INTEN + offset),
			DISP_REG_GET(DISP_REG_OVL_INTSTA + offset), DISP_REG_GET(DISP_REG_OVL_EN + offset));
		DDPDUMP("0x010: 0x%08x 0x%08x, 0x020: 0x%08x 0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_TRIG + offset),
			DISP_REG_GET(DISP_REG_OVL_RST + offset),
			DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset),
			DISP_REG_GET(DISP_REG_OVL_DATAPATH_CON + offset));
		DDPDUMP("0x028: 0x%08x 0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_ROI_BGCLR + offset),
			DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset));

		if (src_on & 0x1) {
			DDPDUMP("0x030: 0x%08x 0x%08x 0x%08x 0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L0_CON + offset),
				DISP_REG_GET(DISP_REG_OVL_L0_SRCKEY + offset),
				DISP_REG_GET(DISP_REG_OVL_L0_SRC_SIZE + offset),
				DISP_REG_GET(DISP_REG_OVL_L0_OFFSET + offset));

			DDPDUMP("0xf40=0x%08x,0x044=0x%08x,0x0c0=0x%08x,0x0c8=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L0_ADDR + offset),
				DISP_REG_GET(DISP_REG_OVL_L0_PITCH + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA0_CTRL + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA0_MEM_GMC_SETTING + offset));

			DDPDUMP("0x0d0=0x%08x,0x1e0=0x%08x,0x24c=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_RDMA0_FIFO_CTRL + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA0_MEM_GMC_S2 + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA0_DBG + offset));
		}
		if (src_on & 0x2) {
			DDPDUMP("0x050: 0x%08x 0x%08x 0x%08x 0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L1_CON + offset),
				DISP_REG_GET(DISP_REG_OVL_L1_SRCKEY + offset),
				DISP_REG_GET(DISP_REG_OVL_L1_SRC_SIZE + offset),
				DISP_REG_GET(DISP_REG_OVL_L1_OFFSET + offset));

			DDPDUMP("0xf60=0x%08x,0x064=0x%08x,0x0e0=0x%08x,0x0e8=0x%08x,0x0f0=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L1_ADDR + offset),
				DISP_REG_GET(DISP_REG_OVL_L1_PITCH + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA1_CTRL + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA1_MEM_GMC_SETTING + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA1_FIFO_CTRL + offset));

			DDPDUMP("0x1e4=0x%08x,0x250=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_RDMA1_MEM_GMC_S2 + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA1_DBG + offset));
		}
		if (src_on & 0x4) {
			DDPDUMP("0x070: 0x%08x 0x%08x 0x%08x 0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L2_CON + offset),
				DISP_REG_GET(DISP_REG_OVL_L2_SRCKEY + offset),
				DISP_REG_GET(DISP_REG_OVL_L2_SRC_SIZE + offset),
				DISP_REG_GET(DISP_REG_OVL_L2_OFFSET + offset));

			DDPDUMP("0xf80=0x%08x,0x084=0x%08x,0x100=0x%08x,0x108=0x%08x,0x110=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L2_ADDR + offset),
				DISP_REG_GET(DISP_REG_OVL_L2_PITCH + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA2_CTRL + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA2_MEM_GMC_SETTING + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA2_FIFO_CTRL + offset));

			DDPDUMP("0x1e8=0x%08x,0x254=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_RDMA2_MEM_GMC_S2 + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA2_DBG + offset));
		}
		if (src_on & 0x8) {
			DDPDUMP("0x090: 0x%08x 0x%08x 0x%08x 0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L3_CON + offset),
				DISP_REG_GET(DISP_REG_OVL_L3_SRCKEY + offset),
				DISP_REG_GET(DISP_REG_OVL_L3_SRC_SIZE + offset),
				DISP_REG_GET(DISP_REG_OVL_L3_OFFSET + offset));

			DDPDUMP("0xfa0=0x%08x,0x0a4=0x%08x,0x120=0x%08x,0x128=0x%08x,0x130=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_L3_ADDR + offset),
				DISP_REG_GET(DISP_REG_OVL_L3_PITCH + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA3_CTRL + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA3_MEM_GMC_SETTING + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA3_FIFO_CTRL + offset));

			DDPDUMP("0x1ec=0x%08x,0x258=0x%08x\n",
				DISP_REG_GET(DISP_REG_OVL_RDMA3_MEM_GMC_S2 + offset),
				DISP_REG_GET(DISP_REG_OVL_RDMA3_DBG + offset));
		}
		DDPDUMP("0x1d4=0x%08x,0x1f8=0x%08x,0x1fc=0x%08x,0x200=0x%08x,0x20c=0x%08x\n"
			"0x210: 0x%08x 0x%08x 0x%08x 0x%08x\n"
			"0x230: 0x%08x 0x%08x, 0x240: 0x%08x 0x%08x, 0x2a0: 0x%08x 0x%08x\n",
			DISP_REG_GET(DISP_REG_OVL_DEBUG_MON_SEL + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA_GREQ_NUM + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA_GREQ_URG_NUM + offset),
			DISP_REG_GET(DISP_REG_OVL_DUMMY_REG + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMA_ULTRA_SRC + offset),

			DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(0) + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(1) + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(2) + offset),
			DISP_REG_GET(DISP_REG_OVL_RDMAn_BUF_LOW(3) + offset),

			DISP_REG_GET(DISP_REG_OVL_SMI_DBG + offset),
			DISP_REG_GET(DISP_REG_OVL_GREQ_LAYER_CNT + offset),
			DISP_REG_GET(DISP_REG_OVL_FLOW_CTRL_DBG + offset),
			DISP_REG_GET(DISP_REG_OVL_ADDCON_DBG + offset),
			DISP_REG_GET(DISP_REG_OVL_FUNC_DCM0 + offset),
			DISP_REG_GET(DISP_REG_OVL_FUNC_DCM1 + offset));
	}
}

static void ovl_printf_status(unsigned int status)
{
	DDPDUMP("- OVL_FLOW_CONTROL_DEBUG -\n");
	DDPDUMP("addcon_idle:%d,blend_idle:%d,out_valid:%d,out_ready:%d,out_idle:%d\n",
		(status >> 10) & (0x1),
		(status >> 11) & (0x1),
		(status >> 12) & (0x1), (status >> 13) & (0x1), (status >> 15) & (0x1));
	DDPDUMP("rdma3_idle:%d,rdma2_idle:%d,rdma1_idle:%d, rdma0_idle:%d,rst:%d\n",
		(status >> 16) & (0x1),
		(status >> 17) & (0x1),
		(status >> 18) & (0x1), (status >> 19) & (0x1), (status >> 20) & (0x1));
	DDPDUMP("trig:%d,frame_hwrst_done:%d,frame_swrst_done:%d,frame_underrun:%d,frame_done:%d\n",
		(status >> 21) & (0x1),
		(status >> 23) & (0x1),
		(status >> 24) & (0x1), (status >> 25) & (0x1), (status >> 26) & (0x1));
	DDPDUMP("ovl_running:%d,ovl_start:%d,ovl_clr:%d,reg_update:%d,ovl_upd_reg:%d\n",
		(status >> 27) & (0x1),
		(status >> 28) & (0x1),
		(status >> 29) & (0x1), (status >> 30) & (0x1), (status >> 31) & (0x1));

	DDPDUMP("ovl_fms_state:\n");
	switch (status & 0x3ff) {
	case 0x1:
		DDPDUMP("idle\n");
		break;
	case 0x2:
		DDPDUMP("wait_SOF\n");
		break;
	case 0x4:
		DDPDUMP("prepare\n");
		break;
	case 0x8:
		DDPDUMP("reg_update\n");
		break;
	case 0x10:
		DDPDUMP("eng_clr(internal reset)\n");
		break;
	case 0x20:
		DDPDUMP("eng_act(processing)\n");
		break;
	case 0x40:
		DDPDUMP("h_wait_w_rst\n");
		break;
	case 0x80:
		DDPDUMP("s_wait_w_rst\n");
		break;
	case 0x100:
		DDPDUMP("h_w_rst\n");
		break;
	case 0x200:
		DDPDUMP("s_w_rst\n");
		break;
	default:
		DDPDUMP("ovl_fsm_unknown\n");
		break;
	}
}

static void ovl_print_ovl_rdma_status(unsigned int status)
{
	DDPDUMP("wram_rst_cs:0x%x,layer_greq:0x%x,out_data:0x%x,",
		status & 0x7, (status >> 3) & 0x1, (status >> 4) & 0xffffff);
	DDPDUMP("out_ready:0x%x,out_valid:0x%x,smi_busy:0x%x,smi_greq:0x%x\n",
		(status >> 28) & 0x1, (status >> 29) & 0x1, (status >> 30) & 0x1,
		(status >> 31) & 0x1);
}

static void ovl_dump_layer_info(int layer, unsigned long layer_offset)
{
	enum UNIFIED_COLOR_FMT fmt;

	fmt = display_fmt_reg_to_unified_fmt(DISP_REG_GET_FIELD
					   (L_CON_FLD_CFMT, DISP_REG_OVL_L0_CON + layer_offset),
					   DISP_REG_GET_FIELD(L_CON_FLD_BTSW,
							      DISP_REG_OVL_L0_CON + layer_offset),
						DISP_REG_GET_FIELD(L_CON_FLD_RGB_SWAP,
							      DISP_REG_OVL_L0_CON + layer_offset));

	DDPDUMP("layer%d: w=%d,h=%d,off(x=%d,y=%d),pitch=%d,addr=0x%x,fmt=%s,source=%s,aen=%d,alpha=%d\n",
	     layer, DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_SRC_SIZE) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_SRC_SIZE) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_OFFSET) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_OFFSET) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_PITCH) & 0xffff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_L0_ADDR), unified_color_fmt_name(fmt),
	     (DISP_REG_GET_FIELD(L_CON_FLD_LSRC, DISP_REG_OVL_L0_CON + layer_offset) ==
	      0) ? "memory" : "constant_color", DISP_REG_GET_FIELD(L_CON_FLD_AEN,
								   DISP_REG_OVL_L0_CON +
								   layer_offset),
	     DISP_REG_GET_FIELD(L_CON_FLD_APHA, DISP_REG_OVL_L0_CON + layer_offset)
	    );
}

static void ovl_dump_ext_layer_info(int layer, unsigned long layer_offset)
{
	unsigned long layer_addr_offset;
	enum UNIFIED_COLOR_FMT fmt;

	layer_addr_offset = layer_offset - layer * OVL_LAYER_OFFSET + layer * 4;
	fmt = display_fmt_reg_to_unified_fmt(DISP_REG_GET_FIELD
					   (L_CON_FLD_CFMT, DISP_REG_OVL_EL0_CON + layer_offset),
					   DISP_REG_GET_FIELD(L_CON_FLD_BTSW,
							      DISP_REG_OVL_EL0_CON + layer_offset),
						DISP_REG_GET_FIELD(L_CON_FLD_RGB_SWAP,
							      DISP_REG_OVL_EL0_CON + layer_offset));

	DDPDUMP("ext layer%d: w=%d,h=%d,off(x=%d,y=%d),pitch=%d,addr=0x%x,fmt=%s,source=%s,aen=%d,alpha=%d\n",
	     layer, DISP_REG_GET(layer_offset + DISP_REG_OVL_EL0_SRC_SIZE) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_EL0_SRC_SIZE) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_EL0_OFFSET) & 0xfff,
	     (DISP_REG_GET(layer_offset + DISP_REG_OVL_EL0_OFFSET) >> 16) & 0xfff,
	     DISP_REG_GET(layer_offset + DISP_REG_OVL_EL0_PITCH) & 0xffff,
	     DISP_REG_GET(layer_addr_offset + DISP_REG_OVL_EL0_ADDR), unified_color_fmt_name(fmt),
	     (DISP_REG_GET_FIELD(L_CON_FLD_LSRC, DISP_REG_OVL_EL0_CON + layer_offset) ==
	      0) ? "memory" : "constant_color", DISP_REG_GET_FIELD(L_CON_FLD_AEN,
								   DISP_REG_OVL_EL0_CON +
								   layer_offset),
	     DISP_REG_GET_FIELD(L_CON_FLD_APHA, DISP_REG_OVL_EL0_CON + layer_offset)
	    );
}

void ovl_dump_golden_setting(enum DISP_MODULE_ENUM module)
{
	unsigned long ovl_base = ovl_base_addr(module);
	int i, layer_num;
	unsigned int read_wrk_state;

	layer_num = ovl_layer_num(module);

	read_wrk_state = DISP_REG_GET_FIELD(EN_FLD_RD_WRK_REG,
			ovl_base + DISP_REG_OVL_EN);
	DISP_REG_SET_FIELD(NULL, EN_FLD_RD_WRK_REG, ovl_base + DISP_REG_OVL_EN, 1);

	DDPDUMP("DUMP %s golden_setting\n", ddp_get_module_name(module));

	DDPDUMP("DATAPATH_CON\n");
	DDPDUMP("[0]:%u, [3]:%u [24]:%u\n",
			DISP_REG_GET_FIELD(DATAPATH_CON_FLD_LAYER_SMI_ID_EN,
				ovl_base + DISP_REG_OVL_DATAPATH_CON),
			DISP_REG_GET_FIELD(DATAPATH_CON_FLD_OUTPUT_NO_RND,
				ovl_base + DISP_REG_OVL_DATAPATH_CON),
			DISP_REG_GET_FIELD(DATAPATH_CON_FLD_GCLAST_EN,
				ovl_base + DISP_REG_OVL_DATAPATH_CON));

	for (i = 0; i < layer_num; i++) {
		unsigned long layer_offset = i * OVL_LAYER_OFFSET + ovl_base;

		DDPDUMP("RDMA%d_MEM_GMC_SETTING1\n", i);
		DDPDUMP("[9:0]:%x [25:16]:%x [28]:%x [31]:%x\n",
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC_ULTRA_THRESHOLD,
					layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC_PRE_ULTRA_THRESHOLD,
					layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC_ULTRA_THRESHOLD_HIGH_OFS,
					layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC_PRE_ULTRA_THRESHOLD_HIGH_OFS,
					layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING));
	}

	for (i = 0; i < layer_num; i++) {
		unsigned long layer_offset = i * OVL_LAYER_OFFSET + ovl_base;

		DDPDUMP("RDMA%d_FIFO_CTRL\n", i);
		DDPDUMP("[9:0]:%u [25:16]:%u\n",
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_FIFO_THRD,
					layer_offset + DISP_REG_OVL_RDMA0_FIFO_CTRL),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_FIFO_SIZE,
					layer_offset + DISP_REG_OVL_RDMA0_FIFO_CTRL));
	}

	for (i = 0; i < layer_num; i++) {
		DDPDUMP("RDMA%d_MEM_GMC_SETTING2\n", i);
		DDPDUMP("[11:0]:%u [27:16]:%u [28]:%u [29]:%u [30]:%u\n",
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC2_ISSUE_REQ_THRES,
					ovl_base + DISP_REG_OVL_RDMA0_MEM_GMC_S2 + i * 4),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC2_ISSUE_REQ_THRES_URG,
					ovl_base + DISP_REG_OVL_RDMA0_MEM_GMC_S2 + i * 4),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC2_REQ_THRES_PREULTRA,
					ovl_base + DISP_REG_OVL_RDMA0_MEM_GMC_S2 + i * 4),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC2_REQ_THRES_ULTRA,
					ovl_base + DISP_REG_OVL_RDMA0_MEM_GMC_S2 + i * 4),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_MEM_GMC2_FORCE_REQ_THRES,
					ovl_base + DISP_REG_OVL_RDMA0_MEM_GMC_S2 + i * 4));
	}

	DDPDUMP("RDMA_GREQ_NUM\n");
	DDPDUMP("[3:0]%u [7:4]%u [11:8]%u [15:12]%u [23:16]%x [26:24]%u [27]%u [28]%u [29]%u [30]%u [31]%u\n",
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER0_GREQ_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER1_GREQ_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER2_GREQ_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER3_GREQ_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_OSTD_GREQ_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_GREQ_DIS_CNT,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_STOP_EN,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_GRP_END_STOP,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_GRP_BRK_STOP,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_IOBUF_FLUSH_PREULTRA,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_IOBUF_FLUSH_ULTRA,
					ovl_base + DISP_REG_OVL_RDMA_GREQ_NUM));
	DDPDUMP("RDMA_GREQ_URG_NUM\n");
	DDPDUMP("[3:0]:%u [7:4]:%u [11:8]:%u [15:12]:%u [25:16]:%u [28]:%u [29]:%u [31:30]:%u\n",
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER0_GREQ_URG_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER1_GREQ_URG_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER2_GREQ_URG_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_LAYER3_GREQ_URG_NUM,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_ARG_GREQ_URG_TH,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_ARG_URG_BIAS,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_NUM_SHT_VAL,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_GREQ_NUM_SHT,
				ovl_base + DISP_REG_OVL_RDMA_GREQ_URG_NUM));
	DDPDUMP("RDMA_ULTRA_SRC\n");
	DDPDUMP("[1:0]%u [3:2]%u [5:4]%u [7:6]%u [9:8]%u [11:10]%u [13:12]%u [15:14]%u\n",
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_PREULTRA_BUF_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_PREULTRA_SMI_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_PREULTRA_ROI_END_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_PREULTRA_RDMA_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_ULTRA_BUF_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_ULTRA_SMI_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_ULTRA_ROI_END_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC),
			DISP_REG_GET_FIELD(FLD_OVL_RDMA_ULTRA_RDMA_SRC,
				ovl_base + DISP_REG_OVL_RDMA_ULTRA_SRC));

	for (i = 0; i < layer_num; i++) {
		DDPDUMP("RDMA%d_BUF_LOW\n", i);
		DDPDUMP("[9:0]:%u [21:12]:%u\n",
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_BUF_LOW_ULTRA_TH,
					ovl_base + DISP_REG_OVL_RDMAn_BUF_LOW(i)),
				DISP_REG_GET_FIELD(FLD_OVL_RDMA_BUF_LOW_PREULTRA_TH,
					ovl_base + DISP_REG_OVL_RDMAn_BUF_LOW(i)));

	}

	DISP_REG_SET_FIELD(NULL, EN_FLD_RD_WRK_REG, ovl_base + DISP_REG_OVL_EN, read_wrk_state);
}

void ovl_dump_analysis(enum DISP_MODULE_ENUM module)
{
	int i = 0;
	unsigned long layer_offset = 0;
	unsigned long rdma_offset = 0;
	unsigned long offset = ovl_base_addr(module);
	unsigned int src_con = DISP_REG_GET(DISP_REG_OVL_SRC_CON + offset);
	unsigned int ext_con = DISP_REG_GET(DISP_REG_OVL_DATAPATH_EXT_CON + offset);

	DDPDUMP("== DISP %s ANALYSIS ==\n", ddp_get_module_name(module));
	DDPDUMP("ovl_en=%d,layer_enable(%d,%d,%d,%d),bg(w=%d, h=%d)\n",
		DISP_REG_GET(DISP_REG_OVL_EN + offset) & 0x1,
		src_con & 0x1, (src_con >> 1) & 0x1, (src_con >> 2) & 0x1, (src_con >> 3) & 0x1,
		DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset) & 0xfff,
		(DISP_REG_GET(DISP_REG_OVL_ROI_SIZE + offset) >> 16) & 0xfff);
	DDPDUMP("ext layer: layer_enable(%d,%d,%d), attach_layer(%d,%d,%d)\n",
		ext_con & 0x1, (ext_con >> 1) & 0x1, (ext_con >> 2) & 0x1,
		(ext_con >> 16) & 0xf, (ext_con >> 20) & 0xf, (ext_con >> 24) & 0xf);
	DDPDUMP("cur_pos(x=%d,y=%d),layer_hit(%d,%d,%d,%d),bg_mode=%s,sta=0x%x\n",
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_ROI_X, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_ROI_Y, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L0_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L1_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L2_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(ADDCON_DBG_FLD_L3_WIN_HIT, DISP_REG_OVL_ADDCON_DBG + offset),
		DISP_REG_GET_FIELD(DATAPATH_CON_FLD_BGCLR_IN_SEL,
				   DISP_REG_OVL_DATAPATH_CON + offset) ? "directlink" : "const",
		DISP_REG_GET(DISP_REG_OVL_STA + offset)
	    );
	for (i = 0; i < 4; i++) {
		unsigned int rdma_ctrl;

		layer_offset = i * OVL_LAYER_OFFSET + offset;
		rdma_offset = i * OVL_RDMA_DEBUG_OFFSET + offset;
		if (src_con & (0x1 << i))
			ovl_dump_layer_info(i, layer_offset);
		else
			DDPDUMP("layer%d: disabled\n", i);
		rdma_ctrl = DISP_REG_GET(layer_offset + DISP_REG_OVL_RDMA0_CTRL);
		DDPDUMP("ovl rdma%d status:(en=%d, fifo_used %d, GMC=0x%x)\n", i,
			REG_FLD_VAL_GET(RDMA0_CTRL_FLD_RDMA_EN, rdma_ctrl),
			REG_FLD_VAL_GET(RDMA0_CTRL_FLD_RMDA_FIFO_USED_SZ, rdma_ctrl),
			DISP_REG_GET(layer_offset + DISP_REG_OVL_RDMA0_MEM_GMC_SETTING));
		ovl_print_ovl_rdma_status(DISP_REG_GET(DISP_REG_OVL_RDMA0_DBG + rdma_offset));
	}
	/* ext layer detail info */
	for (i = 0; i < 3; i++) {
		layer_offset = i * OVL_LAYER_OFFSET + offset;
		rdma_offset = i * OVL_RDMA_DEBUG_OFFSET + offset;
		if (ext_con & (0x1 << i))
			ovl_dump_ext_layer_info(i, layer_offset);
		else
			DDPDUMP("ext layer%d: disabled\n", i);
	}
	ovl_printf_status(DISP_REG_GET(DISP_REG_OVL_FLOW_CTRL_DBG + offset));

	ovl_dump_golden_setting(module);
}


int ovl_dump(enum DISP_MODULE_ENUM module, int level)
{
	ovl_dump_analysis(module);
	ovl_dump_reg(module);

	return 0;
}
