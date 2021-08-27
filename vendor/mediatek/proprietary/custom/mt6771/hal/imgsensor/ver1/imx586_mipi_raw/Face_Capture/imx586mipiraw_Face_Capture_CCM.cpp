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
#include "imx586mipiraw_Face_Capture.h"

const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0006 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0007 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0008 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0009 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0010 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT imx586mipiraw_CCM_0011 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
        {.set={//CT_00
            0x1F8502B7, 0x00001FC4, 0x024B1F5B, 0x0000005A, 0x1D091F96, 0x00000561
        }},
        {.set={//CT_01
            0x1F4402EA, 0x00001FD2, 0x029D1F5C, 0x00000007, 0x1E041FE6, 0x00000416
        }},
        {.set={//CT_02
            0x1ED7038A, 0x00001F9F, 0x02D31F7A, 0x00001FB3, 0x1EB10015, 0x0000033A
        }},
        {.set={//CT_03
            0x1E310400, 0x00001FCF, 0x02AD1F72, 0x00001FE1, 0x1EDC001E, 0x00000306
        }},
        {.set={//CT_04
            0x1E960380, 0x00001FEA, 0x02A11FB7, 0x00001FA8, 0x1EF50022, 0x000002E9
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
            468,  // i4R
            512,  // i4G
            1853  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1512  // i4B
        },
        {//CT_02
            810,  // i4R
            512,  // i4G
            1293  // i4B
        },
        {//CT_03
            896,  // i4R
            512,  // i4G
            1219  // i4B
        },
        {//CT_04
            1041,  // i4R
            512,  // i4G
            791  // i4B
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
