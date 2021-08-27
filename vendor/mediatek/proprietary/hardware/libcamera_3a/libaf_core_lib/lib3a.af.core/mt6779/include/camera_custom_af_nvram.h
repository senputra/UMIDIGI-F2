/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#ifndef _FROMALGO_CAMERA_CUSTOM_AF_NVRAM_H_
#define _FROMALGO_CAMERA_CUSTOM_AF_NVRAM_H_

#include <stddef.h>

#define NVRAM_CUSTOM_REVISION   8242003

//____AF NVRAM____

#define AF_TABLE_NUM (30)
#define ISO_MAX_NUM   (8)
#define GMEAN_MAX_NUM (6)

#define JUMP_NUM        (5)
#define STEPSIZE_NUM    (15)
#define PRERUN_NUM      (2)
#define FPS_THRES_NUM   (2)


typedef struct
{
    MINT32 i4InfPos;
    MINT32 i4MacroPos;

} FOCUS_RANGE_T;

#define PD_CALI_DATA_SIZE   (2048)
#define PD_CONF_IDX_SIZE    (5)

typedef struct
{
    MINT32  i4FocusPDSizeX;
    MINT32  i4FocusPDSizeY;
    MINT32  i4ConfIdx1[PD_CONF_IDX_SIZE];
    MINT32  i4ConfIdx2[PD_CONF_IDX_SIZE];
    MINT32  i4ConfTbl[PD_CONF_IDX_SIZE+1][PD_CONF_IDX_SIZE+1];
    MINT32  i4SaturateLevel;
    MINT32  i4SaturateThr;
    MINT32  i4ConfThr;
    MINT32  i4Reserved[20];
    MINT32  i4V5Config[64];
} PD_ALGO_TUNING_T;

typedef struct
{
    MUINT8  uData[PD_CALI_DATA_SIZE];
    MINT32  i4Size;
} PD_CALIBRATION_DATA_T;

typedef struct
{
    PD_CALIBRATION_DATA_T rCaliData; //this field is only for function parseCaliData(), pd calibration data in nvram is located at NVRAM_AF_PARA_STRUCT
    PD_ALGO_TUNING_T rTuningData;
} PD_NVRAM_T;

typedef struct
{
    MINT32  i4Offset;
    MINT32  i4NormalNum;
    MINT32  i4MacroNum;
    MINT32  i4InfIdxOffset;
    MINT32  i4MacroIdxOffset;
    MINT32  i4Pos[AF_TABLE_NUM];

} NVRAM_AF_TABLE_T;


typedef struct
{
    MINT32 i4ISONum;
    MINT32 i4ISO[ISO_MAX_NUM];

    MINT32 i4GMR[7][ISO_MAX_NUM];

    MINT32 i4HW_TH_PL_H[ISO_MAX_NUM];
    MINT32 i4HW_TH_PL_V[ISO_MAX_NUM];

    MINT32 i4HW_TH_LC_H[ISO_MAX_NUM];
    MINT32 i4HW_TH_FD_H[ISO_MAX_NUM];

    MINT32 i4HW_TH_PRV_H[ISO_MAX_NUM];
    MINT32 i4HW_TH_PRV_V[ISO_MAX_NUM];

} NVRAM_AF_THRES_T;


typedef struct
{
    NVRAM_AF_TABLE_T sTABLE;
    MINT32 i4THRES_MAIN;
    MINT32 i4THRES_SUB;
    MINT32 i4AFC_FAIL_CNT;
    MINT32 i4FAIL_POS;

    MINT32 i4INIT_WAIT;
    MINT32 i4FRAME_WAIT[JUMP_NUM];
    MINT32 i4DONE_WAIT;
} NVRAM_AF_COEF;

typedef struct
{
    // --- AF SW coef ---
    NVRAM_AF_COEF sAF_Coef;
    NVRAM_AF_TABLE_T sHBAF_table;

    // --- AF HW thres ---
    NVRAM_AF_THRES_T sAF_TH;

    // --- common use ----
    MINT32 i4Common[64];

    // --- AF Seek ---
    MINT32 i4AFSeek[64];

    // --- SceneMonitor ---
    MINT32 i4SceneMonitor[64];

    // --- Easytuning ---
    MINT32 i4EasyTuning[64];

    // --- AFv2.5 ---
    MINT32 i4Coefs[64];

    // --- AFv3.0 ---
    MINT32 i4SceneMonitor2[64];

    // --- Point Light AF ---
    MINT32 i4PLAFCoefs[128];

    // --- Hybrid AF ---
    MINT32 i4HybridAFCoefs[128];

    // --- PDAF ---
    MINT32 i4PDAFCoefs[64];

    // --- Laser AF ---
    MINT32 i4LDAFCoefs[64];

    // --- Face AF ---
    MINT32 i4FaceAFCoefs[64];

    // ---
    MINT32 i4TempErr[64];
    // ---
    MINT32 i4ZoEffect[64];
    // ---
    MINT32 i4DualAFCoefs[128];

    // --- Laser Calibration Data ---
    MINT32 i4LaserCali[64];

    // --- Reserved ---
    MINT32 i4Revs[64];
} AF_NVRAM_T;

#endif // _FROMALGO_CAMERA_CUSTOM_AF_NVRAM_H_
