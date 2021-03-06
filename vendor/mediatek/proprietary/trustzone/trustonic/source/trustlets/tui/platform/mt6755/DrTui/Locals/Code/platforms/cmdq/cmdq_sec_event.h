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

/* MDP start frame */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RDMA0_SOF, 0)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RSZ0_SOF, 1)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RSZ1_SOF, 2)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_TDSHP_SOF, 3)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_WDMA_SOF, 4)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_WROT_SOF, 5)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_COLOR_SOF, 6)

/* Display start frame */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_OVL0_SOF, 7)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_OVL1_SOF, 8)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA0_SOF, 9)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA1_SOF, 10)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_WDMA0_SOF, 11)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_COLOR_SOF, 12)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_CCORR_SOF, 13)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_AAL_SOF, 14)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_GAMMA_SOF, 15)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_DITHER_SOF, 16)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_WDMA1_SOF, 17)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_PWM0_SOF, 18)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_2L_OVL0_SOF, 19)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_2L_OVL1_SOF, 20)

DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_UFOE_SOF, (-3))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L0_SOF, (-4))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L1_SOF, (-5))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L2_SOF, (-6))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L3_SOF, (-7))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L0_SOF, (-8))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L1_SOF, (-9))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L2_SOF, (-10))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L3_SOF, (-11))

/* MDP frame done */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RDMA0_EOF, 21)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RSZ0_EOF, 22)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_RSZ1_EOF, 23)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_TDSHP_EOF, 24)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_WDMA_EOF, 25)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_WROT_WRITE_EOF, 26)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_WROT_READ_EOF, 27)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MDP_COLOR_EOF, 28)

/* Display frame done */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_OVL0_EOF, 29)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_OVL1_EOF, 30)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA0_EOF, 31)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA1_EOF, 32)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_WDMA0_EOF, 33)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_COLOR_EOF, 34)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_CCORR_EOF, 35)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_AAL_EOF, 36)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_GAMMA_EOF, 37)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_DITHER_EOF, 38)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_DPI0_EOF, 39)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_WDMA1_EOF, 40)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_DSI0_EOF, 41)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_2L_OVL0_EOF, 42)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_2L_OVL1_EOF, 43)

DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_UFOE_EOF, (-12))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L0_EOF, (-13))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L1_EOF, (-14))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L2_EOF, (-15))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA0_L3_EOF, (-16))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L0_EOF, (-17))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L1_EOF, (-18))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L2_EOF, (-19))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_UFOD_RAMA1_L3_EOF, (-20))

DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA2_SOF, (-21))
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA2_EOF, (-22))

/* Mutex frame done */
/* DISPSYS */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX0_STREAM_EOF, 44)
/* DISPSYS */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX1_STREAM_EOF, 45)
/* DISPSYS */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX2_STREAM_EOF, 46)
/* DISPSYS */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX3_STREAM_EOF, 47)
/* DISPSYS, please refer to disp_hal.h */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX4_STREAM_EOF, 48)
/* DpFramework */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX5_STREAM_EOF, 49)
/* DpFramework */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX6_STREAM_EOF, 50)
/* DpFramework */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX7_STREAM_EOF, 51)
/* DpFramework */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX8_STREAM_EOF, 52)
/* DpFramework via CMDQ_IOCTL_LOCK_MUTEX */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_MUTEX9_STREAM_EOF, 53)

/* Display underrun */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA0_UNDERRUN, 54)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DISP_RDMA1_UNDERRUN, 55)

/* Display TE */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_DSI_TE, 56)

/* ISP frame done */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_PASS2_2_EOF, 129)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_PASS2_1_EOF, 130)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_PASS2_0_EOF, 131)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_PASS1_1_EOF, 132)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_PASS1_0_EOF, 133)

/* ISP engine events */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_CAMSV_2_PASS1_DONE, 134)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_CAMSV_1_PASS1_DONE, 135)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_SENINF_CAM1_2_3_FULL, 136)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_ISP_SENINF_CAM0_FULL, 137)

/* VENC frame done */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_VENC_EOF, 257)

/* JPEG frame done */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_JPEG_ENC_EOF, 258)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_JPEG_DEC_EOF, 259)

/* VENC engine events */
DECLARE_CMDQ_EVENT(CMDQ_EVENT_VENC_MB_DONE, 260)
DECLARE_CMDQ_EVENT(CMDQ_EVENT_VENC_128BYTE_CNT_DONE, 261)

/* Keep this at the end of HW events */
DECLARE_CMDQ_EVENT(CMDQ_MAX_HW_EVENT_COUNT, 400)

/* SW Sync Tokens (Pre-defined) */
/* Config thread notify trigger thread */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_CONFIG_DIRTY, 401)
/* Trigger thread notify config thread */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_STREAM_EOF, 402)
/* Block Trigger thread until the ESD check finishes. */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_ESD_EOF, 403)
/* check CABC setup finish */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_CABC_EOF, 404)
/* Block Trigger thread until the path freeze finishes */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_FREEZE_EOF, 405)
/* Pass-2 notifies VENC frame is ready to be encoded */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_VENC_INPUT_READY, 406)
/* VENC notifies Pass-2 encode done so next frame may start */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_VENC_EOF, 407)

/* Notify normal CMDQ there are some secure task done */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_SECURE_THR_EOF, 408)

/* SW Sync Tokens (User-defined) */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_USER_0, 410)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_USER_1, 411)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_POLL_MONITOR, 412)

/* Event for CMDQ to block executing command when append command
* Plz sync CMDQ_SYNC_TOKEN_APPEND_THR(id) in cmdq_core source file. */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR0, 432)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR1, 433)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR2, 434)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR3, 435)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR4, 436)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR5, 437)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR6, 438)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR7, 439)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR8, 440)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR9, 441)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR10, 442)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR11, 443)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR12, 444)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR13, 445)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR14, 446)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_APPEND_THR15, 447)


/* GPR access tokens (for HW register backup) */
/* There are 15 32-bit GPR, 3 GPR form a set (64-bit for address, 32-bit for value) */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_GPR_SET_0, 450)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_GPR_SET_1, 451)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_GPR_SET_2, 452)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_GPR_SET_3, 453)
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_GPR_SET_4, 454)

/* Resource lock event to control resource in GCE thread */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_RESOURCE_WROT0, 460)

/* event id is 9 bit */
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_MAX, (0x1FF))
DECLARE_CMDQ_EVENT(CMDQ_SYNC_TOKEN_INVALID, (-1))
