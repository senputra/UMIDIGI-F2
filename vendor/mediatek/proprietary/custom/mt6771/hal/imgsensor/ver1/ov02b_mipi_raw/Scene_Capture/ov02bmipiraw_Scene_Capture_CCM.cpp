/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2020. All rights reserved.
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
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include "camera_custom_nvram.h"
#include "ov02bmipiraw_Scene_Capture.h"

const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0000 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0001 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0002 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0003 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0004 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
const ISP_NVRAM_MULTI_CCM_STRUCT ov02bmipiraw_CCM_0005 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1FBA020D, 0x00000039, 0x02D91F4D, 0x00001FDA, 0x1CAB1F46, 0x0000060F
        }},
        {.set={//CT_01
            0x1F6A0333, 0x00001F63, 0x030B1F6E, 0x00001F87, 0x1D741FA9, 0x000004E3
        }},
        {.set={//CT_02
            0x1E8403A5, 0x00001FD7, 0x02C41F80, 0x00001FBC, 0x1DA40006, 0x00000456
        }},
        {.set={//CT_03
            0x1E2103EC, 0x00001FF3, 0x02CF1F65, 0x00001FCC, 0x1E621FE7, 0x000003B7
        }},
        {.set={//CT_04
            0x1EA50373, 0x00001FE8, 0x02FD1FB2, 0x00001F51, 0x1E821FFB, 0x00000383
        }},
        {.set={//CT_05
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_06
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_07
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_08
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }},
        {.set={//CT_09
            0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
        }}
    },
    .AWBGain=
    {
        {//CT_00
            436,  // i4R
            512,  // i4G
            1285  // i4B
        },
        {//CT_01
            544,  // i4R
            512,  // i4G
            1128  // i4B
        },
        {//CT_02
            764,  // i4R
            512,  // i4G
            985  // i4B
        },
        {//CT_03
            852,  // i4R
            512,  // i4G
            992  // i4B
        },
        {//CT_04
            1025,  // i4R
            512,  // i4G
            689  // i4B
        },
        {//CT_05
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_06
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_07
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_08
            512,  // i4R
            512,  // i4G
            512  // i4B
        },
        {//CT_09
            512,  // i4R
            512,  // i4G
            512  // i4B
        }
    },

};
