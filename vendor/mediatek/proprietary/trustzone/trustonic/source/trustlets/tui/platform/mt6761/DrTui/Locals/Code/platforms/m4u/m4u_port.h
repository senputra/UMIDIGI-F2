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
#ifndef __M4U_PORT_H__
#define __M4U_PORT_H__

/* ==================================== */
/* about portid */
/* ==================================== */

enum M4U_PORT_ID {
	/*larb0 */
	M4U_PORT_DISP_OVL0,
	M4U_PORT_DISP_2L_OVL0_LARB0,
	M4U_PORT_DISP_RDMA0,
	M4U_PORT_DISP_WDMA0,
	M4U_PORT_MDP_RDMA0,
	M4U_PORT_MDP_WDMA0,
	M4U_PORT_MDP_WROT0,
	M4U_PORT_DISP_FAKE0,
	/*larb1 */
	M4U_PORT_VENC_RCPU,
	M4U_PORT_VENC_REC,
	M4U_PORT_VENC_BSDMA,
	M4U_PORT_VENC_SV_COMV,
	M4U_PORT_VENC_RD_COMV,
	M4U_PORT_JPGENC_RDMA,
	M4U_PORT_JPGENC_BSDMA,
	M4U_PORT_VENC_CUR_LUMA,
	M4U_PORT_VENC_CUR_CHROMA,
	M4U_PORT_VENC_REF_LUMA,
	M4U_PORT_VENC_REF_CHROMA,
	/*larb2 */
	M4U_PORT_CAM_IMGO,
	M4U_PORT_CAM_RRZO,
	M4U_PORT_CAM_AAO,
	M4U_PORT_CAM_LCSO,
	M4U_PORT_CAM_ESFKO,
	M4U_PORT_CAM_IMGO_S,
	M4U_PORT_CAM_IMGO_S2,
	M4U_PORT_CAM_LSCI,
	M4U_PORT_CAM_LSCI_D,
	M4U_PORT_CAM_AFO,
	M4U_PORT_CAM_AFO_D,
	M4U_PORT_CAM_BPCI,
	M4U_PORT_CAM_BPCI_D,
	M4U_PORT_CAM_UFDI,
	M4U_PORT_CAM_IMGI,
	M4U_PORT_CAM_IMG2O,
	M4U_PORT_CAM_IMG3O,
	M4U_PORT_CAM_VIPI,
	M4U_PORT_CAM_VIP2I,
	M4U_PORT_CAM_VIP3I,
	M4U_PORT_CAM_ICEI,
	M4U_PORT_CAM_FD_RP,
	M4U_PORT_CAM_FD_WR,
	M4U_PORT_CAM_FD_RB,

	M4U_PORT_UNKNOWN
};
#define M4U_PORT_NR M4U_PORT_UNKNOWN

#endif
