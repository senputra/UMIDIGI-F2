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

#ifndef __DSI_DRV_H__
#define __DSI_DRV_H__

#include "lcm_drv.h"
#include "ddp_hal.h"
#include "cmdq_sec_record.h"
#include "ddp_path.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t UINT8;
typedef uint32_t UINT32;
typedef uint16_t UINT16;
typedef int32_t INT32;

#if 0

/* --------------------------------------------------------------------------- */

#define DSI_CHECK_RET(expr)             \
	do {                                \
		DSI_STATUS ret = (expr);        \
		ASSERT(DSI_STATUS_OK == ret);   \
	} while (0)

/* --------------------------------------------------------------------------- */

#define		DSI_DCS_SHORT_PACKET_ID_0			0x05
#define		DSI_DCS_SHORT_PACKET_ID_1			0x15
#define		DSI_DCS_LONG_PACKET_ID				0x39
#define		DSI_DCS_READ_PACKET_ID				0x06

#define		DSI_GERNERIC_SHORT_PACKET_ID_1		0x13
#define		DSI_GERNERIC_SHORT_PACKET_ID_2		0x23
#define		DSI_GERNERIC_LONG_PACKET_ID			0x29
#define		DSI_GERNERIC_READ_LONG_PACKET_ID	0x14
#endif

#define		DSI_WMEM_CONTI						(0x3C)
#define		DSI_RMEM_CONTI						(0x3E)

#if 0
/* ESD recovery method for video mode LCM */
#define		METHOD_NONCONTINUOUS_CLK			(0x1)
#define		METHOD_BUS_TURN_AROUND				(0x2)

/* State of DSI engine */
#define		DSI_VDO_VSA_VS_STATE				(0x008)
#define		DSI_VDO_VSA_HS_STATE				(0x010)
#define		DSI_VDO_VSA_VE_STATE				(0x020)
#define		DSI_VDO_VBP_STATE					(0x040)
#define		DSI_VDO_VACT_STATE					(0x080)
#define		DSI_VDO_VFP_STATE					(0x100)
#endif
/* --------------------------------------------------------------------------- */

	typedef enum {
		DSI_STATUS_OK = 0,
		DSI_STATUS_ERROR,
	} DSI_STATUS;

	typedef enum {
		SHORT_PACKET_RW = 0,
		FB_WRITE = 1,
		LONG_PACKET_W = 2,
		FB_READ = 3,
	} DSI_INS_TYPE;


	typedef enum {
		DISABLE_BTA = 0,
		ENABLE_BTA = 1,
	} DSI_CMDQ_BTA;


	typedef enum {
		LOW_POWER = 0,
		HIGH_SPEED = 1,
	} DSI_CMDQ_HS;


	typedef enum {
		CL_8BITS = 0,
		CL_16BITS = 1,
	} DSI_CMDQ_CL;


	typedef enum {
		DISABLE_TE = 0,
		ENABLE_TE = 1,
	} DSI_CMDQ_TE;


	typedef enum {
		DISABLE_RPT = 0,
		ENABLE_RPT = 1,
	} DSI_CMDQ_RPT;

	typedef struct {
		unsigned type:2;
		unsigned BTA:1;
		unsigned HS:1;
		unsigned CL:1;
		unsigned TE:1;
		unsigned Rsv:1;
		unsigned RPT:1;
	} DSI_CMDQ_CONFG, *PDSI_CMDQ_CONFIG;


	typedef struct {
		unsigned CONFG:8;
		unsigned Data_ID:8;
		unsigned Data0:8;
		unsigned Data1:8;
	} DSI_T0_INS, *PDSI_T0_INS;

	typedef struct {
		unsigned CONFG:8;
		unsigned Data_ID:8;
		unsigned mem_start0:8;
		unsigned mem_start1:8;
	} DSI_T1_INS, *PDSI_T1_INS;

	typedef struct {
		unsigned CONFG:8;
		unsigned Data_ID:8;
		unsigned WC16:16;
		unsigned int *pdata;
	} DSI_T2_INS, *PDSI_T2_INS;

	typedef struct {
		unsigned CONFG:8;
		unsigned Data_ID:8;
		unsigned mem_start0:8;
		unsigned mem_start1:8;
	} DSI_T3_INS, *PDSI_T3_INS;

	typedef struct {
		UINT8 TXDIV0;
		UINT8 TXDIV1;
		UINT32 SDM_PCW;
		UINT8 SSC_PH_INIT;
		UINT16 SSC_PRD;
		UINT16 SSC_DELTA1;
		UINT16 SSC_DELTA;
	} DSI_PLL_CONFIG;

	typedef enum {
		DSI_INTERFACE_0 = 0,
		DSI_INTERFACE_1,
		DSI_INTERFACE_DUAL,
		DSI_INTERFACE_NUM,
	} DSI_INTERFACE_ID;

	typedef enum {
		DSI_VFP = 0,
		DSI_VSA,
		DSI_VBP,
		DSI_VACT,
		DSI_HFP,
		DSI_HSA,
		DSI_HBP,
		DSI_BLLP,
		DSI_PORCH_NUM,
	} DSI_PORCH_TYPE;

	/*void*get_dsi_params_handle(UINT32 dsi_idx);*/

	int ddp_dsi_trigger(DISP_MODULE_ENUM module, cmdqRecHandle cmdq);

	int ddp_dsi_init(void);

	void dsi_analysis(DISP_MODULE_ENUM module);

	void DSI_WaitForNotBusy(DISP_MODULE_ENUM module, cmdqRecHandle cmdq);

	/*DISP_MODULE_ENUM ddp_dsi_get_module();*/
	DDP_MODE ddp_dsi_get_mode(DISP_MODULE_ENUM module);
	int ddp_dsi_is_busy(DISP_MODULE_ENUM module);

	/*void DSI_manual_enter_HS(cmdqRecHandle cmdq);*/
	/*void DSI_sw_clk_trail_cmdq(int module_idx,cmdqRecHandle cmdq);*/
	/*CLK_MODE ddp_dsi_get_clk_lane_mode(void);*/
	const char *_dsi_vdo_mode_parse_state(unsigned int state);

#ifdef __cplusplus
}
#endif
#endif				/* __DPI_DRV_H__ */
