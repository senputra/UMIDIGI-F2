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
#include "s5k3p3sxmipiraw_Face_Capture.h"

const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0006 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0007 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0008 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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

const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0009 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0010 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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
const ISP_NVRAM_MULTI_CCM_STRUCT s5k3p3sxmipiraw_CCM_0011 = {
        .CCM_CT_valid_NUM = 5,
    .CCM_Coef = {1, 2, 2},
    .CCM_Reg=
    {
			{.set={//CT_00
				0x1FF60250, 0x00001FBA, 0x025D1F04, 0x0000009F, 0x1C8E1F4E, 0x00000624
			}},
			{.set={//CT_01
				0x1F760299, 0x00001FF1, 0x02571F50, 0x00000059, 0x1DA01FD3, 0x0000048D
			}},
			{.set={//CT_02
				0x1F2A02EF, 0x00001FE7, 0x027E1F7B, 0x00000007, 0x1E43004F, 0x0000036E
			}},
			{.set={//CT_03
				0x1E840390, 0x00001FEC, 0x02731F73, 0x0000001A, 0x1E84003B, 0x00000341
			}},
			{.set={//CT_04
				0x1ED1034F, 0x00001FE0, 0x02C51FA4, 0x00001F97, 0x1EBC002B, 0x00000319
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
            503,  // i4R
            512,  // i4G
            1586  // i4B
        },
        {//CT_01
            630,  // i4R
            512,  // i4G
            1318  // i4B
        },
        {//CT_02
            941,  // i4R
            512,  // i4G
            1124  // i4B
        },
        {//CT_03
            1056,  // i4R
            512,  // i4G
            1168  // i4B
        },
        {//CT_04
            1191,  // i4R
            512,  // i4G
            710  // i4B
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
