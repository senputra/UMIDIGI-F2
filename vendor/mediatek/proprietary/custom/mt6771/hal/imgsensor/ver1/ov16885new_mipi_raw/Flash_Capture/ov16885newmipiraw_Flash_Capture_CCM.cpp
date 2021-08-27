/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2017. All rights reserved.
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
#include "ov16885newmipiraw_Flash_Capture.h"

const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0030 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1FC60201, 0x00000039, 0x02221F97, 0x00000047, 0x1E021FA2, 0x0000045C
        }},
        {.set={//CT_01
            0x1FDF0266, 0x00001FBB, 0x02821F98, 0x00001FE6, 0x1DA91F7D, 0x000004DA
        }},
        {.set={//CT_02
            0x1FA80273, 0x00001FE5, 0x028B1F97, 0x00001FDE, 0x1EBC0007, 0x0000033D
        }},
        {.set={//CT_03
            0x1F82028D, 0x00001FF1, 0x025F1FB2, 0x00001FEF, 0x1F160008, 0x000002E2
        }},
        {.set={//CT_04
            0x1EF50301, 0x0000000A, 0x023F1FB3, 0x0000000E, 0x1F1E0013, 0x000002CF
        }},
        {.set={//CT_05
            0x1F790274, 0x00000013, 0x025C1FE5, 0x00001FBF, 0x1F2C0017, 0x000002BD
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

    .AWBGain =
    {
        {//CT_00
            445,  // i4R
            512,  // i4G
            1560  // i4B
        },
        {//CT_01
            540,  // i4R
            512,  // i4G
            1347  // i4B
        },
        {//CT_02
            633,  // i4R
            512,  // i4G
            1411  // i4B
        },
        {//CT_03
            829,  // i4R
            512,  // i4G
            1099  // i4B
        },
        {//CT_04
            907,  // i4R
            512,  // i4G
            1190  // i4B
        },
        {//CT_05
            1043,    // i4R
            512,    // i4G
            755     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0031 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1F200216, 0x000000CA, 0x02B31FAF, 0x00001F9E, 0x1C4E1F9C, 0x00000616
        }},
        {.set={//CT_01
            0x1FDF0266, 0x00001FBB, 0x02821F98, 0x00001FE6, 0x1DA91F7D, 0x000004DA
        }},
        {.set={//CT_02
            0x1FD3027B, 0x00001FB2, 0x02671F8E, 0x0000000B, 0x1DFF1FBF, 0x00000442
        }},
        {.set={//CT_03
            0x1F82028D, 0x00001FF1, 0x025F1FB2, 0x00001FEF, 0x1F160008, 0x000002E2
        }},
        {.set={//CT_04
            0x1EF50301, 0x0000000A, 0x023F1FB3, 0x0000000E, 0x1F1E0013, 0x000002CF
        }},
        {.set={//CT_05
            0x1F790274, 0x00000013, 0x025C1FE5, 0x00001FBF, 0x1F2C0017, 0x000002BD
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

    .AWBGain =
    {
        {//CT_00
            355,  // i4R
            512,  // i4G
            1526  // i4B
        },
        {//CT_01
            433,  // i4R
            512,  // i4G
            1344  // i4B
        },
        {//CT_02
            633,  // i4R
            512,  // i4G
            1411  // i4B
        },
        {//CT_03
            829,  // i4R
            512,  // i4G
            1099  // i4B
        },
        {//CT_04
            907,  // i4R
            512,  // i4G
            1190  // i4B
        },
        {//CT_05
            1043,    // i4R
            512,    // i4G
            755     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0032 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x00590212, 0x00001F95, 0x02381F7D, 0x0000004B, 0x1D8C1F61, 0x00000513
        }},
        {.set={//CT_01
            0x1FD3027B, 0x00001FB2, 0x02671F8E, 0x0000000B, 0x1DFF1FBF, 0x00000442
        }},
        {.set={//CT_02
            0x1F8102C9, 0x00001FB6, 0x028F1F8D, 0x00001FE4, 0x1E050003, 0x000003F8
        }},
        {.set={//CT_03
            0x1F4B02E3, 0x00001FD2, 0x02891F9F, 0x00001FD8, 0x1E910001, 0x0000036E
        }},
        {.set={//CT_04
            0x1EC40346, 0x00001FF6, 0x025F1F91, 0x00000010, 0x1EAA1FFD, 0x00000359
        }},
        {.set={//CT_05
            0x1F7802B3, 0x00001FD5, 0x02AA1FCB, 0x00001F8B, 0x1EE20008, 0x00000316
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

    .AWBGain =
    {
        {//CT_00
            445,  // i4R
            512,  // i4G
            1560  // i4B
        },
        {//CT_01
            540,  // i4R
            512,  // i4G
            1347  // i4B
        },
        {//CT_02
            609,  // i4R
            512,  // i4G
            1589  // i4B
        },
        {//CT_03
            808,  // i4R
            512,  // i4G
            1256  // i4B
        },
        {//CT_04
            869,  // i4R
            512,  // i4G
            1323  // i4B
        },
        {//CT_05
            928,    // i4R
            512,    // i4G
            837     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0033 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x00590212, 0x00001F95, 0x02381F7D, 0x0000004B, 0x1D8C1F61, 0x00000513
        }},
        {.set={//CT_01
            0x00590212, 0x00001F95, 0x02381F7D, 0x0000004B, 0x1D8C1F61, 0x00000513
        }},
        {.set={//CT_02
            0x1F5602EF, 0x00001FBB, 0x02891F9A, 0x00001FDD, 0x1E41000A, 0x000003B5
        }},
        {.set={//CT_03
            0x1F82028D, 0x00001FF1, 0x025F1FB2, 0x00001FEF, 0x1F160008, 0x000002E2
        }},
        {.set={//CT_04
            0x1EF1033E, 0x00001FD1, 0x023A1FB5, 0x00000011, 0x1EBA0023, 0x00000323
        }},
        {.set={//CT_05
            0x1F5402AE, 0x00001FFE, 0x02981FC9, 0x00001F9F, 0x1EFA0007, 0x000002FF
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

    .AWBGain =
    {
        {//CT_00
            470,  // i4R
            512,  // i4G
            1648  // i4B
        },
        {//CT_01
            572,  // i4R
            512,  // i4G
            1444  // i4B
        },
        {//CT_02
            674,  // i4R
            512,  // i4G
            1554  // i4B
        },
        {//CT_03
            829,  // i4R
            512,  // i4G
            1099  // i4B
        },
        {//CT_04
            966,  // i4R
            512,  // i4G
            1338  // i4B
        },
        {//CT_05
            1097,    // i4R
            512,    // i4G
            829     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0034 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x004B0201, 0x00001FB4, 0x02261F91, 0x00000049, 0x1DA41F79, 0x000004E3
        }},
        {.set={//CT_01
            0x00550203, 0x00001FA8, 0x02621F7F, 0x0000001F, 0x1DD91F76, 0x000004B1
        }},
        {.set={//CT_02
            0x1F780279, 0x0000000F, 0x02591FA5, 0x00000002, 0x1EAD000A, 0x00000349
        }},
        {.set={//CT_03
            0x1F82028D, 0x00001FF1, 0x025F1FB2, 0x00001FEF, 0x1F160008, 0x000002E2
        }},
        {.set={//CT_04
            0x1EF50301, 0x0000000A, 0x023F1FB3, 0x0000000E, 0x1F1E0013, 0x000002CF
        }},
        {.set={//CT_05
            0x1F790274, 0x00000013, 0x025C1FE5, 0x00001FBF, 0x1F2C0017, 0x000002BD
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

    .AWBGain =
    {
        {//CT_00
            453,  // i4R
            512,  // i4G
            1624  // i4B
        },
        {//CT_01
            554,  // i4R
            512,  // i4G
            1416  // i4B
        },
        {//CT_02
            640,  // i4R
            512,  // i4G
            1444  // i4B
        },
        {//CT_03
            829,  // i4R
            512,  // i4G
            1099  // i4B
        },
        {//CT_04
            907,  // i4R
            512,  // i4G
            1190  // i4B
        },
        {//CT_05
            1043,    // i4R
            512,    // i4G
            755     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
const ISP_NVRAM_MULTI_CCM_STRUCT ov16885newmipiraw_CCM_0035 = {

    .CCM_CT_valid_NUM = 6,

    .CCM_Coef = {1, 2, 2},

    .CCM_Reg =
    {
        {.set={//CT_00
            0x1FC60201, 0x00000039, 0x02221F97, 0x00000047, 0x1E021FA2, 0x0000045C
        }},
        {.set={//CT_01
            0x1FC3023F, 0x00001FFE, 0x023A1FA3, 0x00000023, 0x1E621FDE, 0x000003C0
        }},
        {.set={//CT_02
            0x1FA80273, 0x00001FE5, 0x028B1F97, 0x00001FDE, 0x1EBC0007, 0x0000033D
        }},
        {.set={//CT_03
            0x1F82028D, 0x00001FF1, 0x025F1FB2, 0x00001FEF, 0x1F160008, 0x000002E2
        }},
        {.set={//CT_04
            0x1EF50301, 0x0000000A, 0x023F1FB3, 0x0000000E, 0x1F1E0013, 0x000002CF
        }},
        {.set={//CT_05
            0x1F790274, 0x00000013, 0x025C1FE5, 0x00001FBF, 0x1F2C0017, 0x000002BD
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

    .AWBGain =
    {
        {//CT_00
            445,  // i4R
            512,  // i4G
            1560  // i4B
        },
        {//CT_01
            540,  // i4R
            512,  // i4G
            1347  // i4B
        },
        {//CT_02
            633,  // i4R
            512,  // i4G
            1411  // i4B
        },
        {//CT_03
            829,  // i4R
            512,  // i4G
            1099  // i4B
        },
        {//CT_04
            907,  // i4R
            512,  // i4G
            1190  // i4B
        },
        {//CT_05
            1043,    // i4R
            512,    // i4G
            755     // i4B
        },
        {//CT_06
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_07
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_08
            512,    // i4R
            512,    // i4G
            512     // i4B
        },
        {//CT_09
            512,    // i4R
            512,    // i4G
            512     // i4B
        }
    }
};
