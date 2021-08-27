/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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
#ifndef _CAMERA_AE_PLINETABLE_S5K3P3SX4CELLMIPIRAW_H
#define _CAMERA_AE_PLINETABLE_S5K3P3SX4CELLMIPIRAW_H

#include <custom/aaa/AEPlinetable.h>
static constexpr strEvPline sPreviewPLineTable_60Hz =
{
{
    {89,1280,1040, 0, 0, 0},  //TV = 13.46(7 lines)  AV=2.00  SV=5.34  BV=10.11
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.25  BV=10.03
    {101,1280,1024, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.32  BV=9.95
    {114,1248,1024, 0, 0, 0},  /* TV = 13.10(9 lines)  AV=2.00  SV=5.29  BV=9.81 */
    {127,1184,1032, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.22  BV=9.72
    {139,1160,1024, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.18  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.26  BV=9.55
    {152,1216,1024, 0, 0, 0},  //TV = 12.68(12 lines)  AV=2.00  SV=5.25  BV=9.44
    {164,1216,1024, 0, 0, 0},  //TV = 12.57(13 lines)  AV=2.00  SV=5.25  BV=9.33
    {177,1216,1024, 0, 0, 0},  //TV = 12.46(14 lines)  AV=2.00  SV=5.25  BV=9.22
    {190,1216,1024, 0, 0, 0},  //TV = 12.36(15 lines)  AV=2.00  SV=5.25  BV=9.11
    {202,1184,1032, 0, 0, 0},  /* TV = 12.27(16 lines)  AV=2.00  SV=5.22  BV=9.05 */
    {215,1184,1040, 0, 0, 0},  //TV = 12.18(17 lines)  AV=2.00  SV=5.23  BV=8.95
    {227,1216,1024, 0, 0, 0},  //TV = 12.11(18 lines)  AV=2.00  SV=5.25  BV=8.86
    {253,1160,1032, 0, 0, 0},  //TV = 11.95(20 lines)  AV=2.00  SV=5.19  BV=8.76
    {265,1184,1040, 0, 0, 0},  //TV = 11.88(21 lines)  AV=2.00  SV=5.23  BV=8.65
    {290,1184,1024, 0, 0, 0},  //TV = 11.75(23 lines)  AV=2.00  SV=5.21  BV=8.54
    {316,1160,1024, 0, 0, 0},  //TV = 11.63(25 lines)  AV=2.00  SV=5.18  BV=8.45
    {328,1184,1032, 0, 0, 0},  //TV = 11.57(26 lines)  AV=2.00  SV=5.22  BV=8.35
    {354,1184,1024, 0, 0, 0},  //TV = 11.46(28 lines)  AV=2.00  SV=5.21  BV=8.25
    {379,1184,1024, 0, 0, 0},  //TV = 11.37(30 lines)  AV=2.00  SV=5.21  BV=8.16
    {417,1160,1024, 0, 0, 0},  //TV = 11.23(33 lines)  AV=2.00  SV=5.18  BV=8.05
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(35 lines)  AV=2.00  SV=5.19  BV=7.95
    {480,1160,1024, 0, 0, 0},  //TV = 11.02(38 lines)  AV=2.00  SV=5.18  BV=7.84
    {505,1184,1024, 0, 0, 0},  //TV = 10.95(40 lines)  AV=2.00  SV=5.21  BV=7.74
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(43 lines)  AV=2.00  SV=5.19  BV=7.66
    {580,1184,1024, 0, 0, 0},  //TV = 10.75(46 lines)  AV=2.00  SV=5.21  BV=7.54
    {631,1160,1024, 0, 0, 0},  //TV = 10.63(50 lines)  AV=2.00  SV=5.18  BV=7.45
    {669,1160,1032, 0, 0, 0},  //TV = 10.55(53 lines)  AV=2.00  SV=5.19  BV=7.35
    {719,1160,1032, 0, 0, 0},  //TV = 10.44(57 lines)  AV=2.00  SV=5.19  BV=7.25
    {770,1160,1032, 0, 0, 0},  //TV = 10.34(61 lines)  AV=2.00  SV=5.19  BV=7.15
    {833,1160,1024, 0, 0, 0},  //TV = 10.23(66 lines)  AV=2.00  SV=5.18  BV=7.05
    {883,1160,1032, 0, 0, 0},  //TV = 10.15(70 lines)  AV=2.00  SV=5.19  BV=6.95
    {959,1160,1024, 0, 0, 0},  //TV = 10.03(76 lines)  AV=2.00  SV=5.18  BV=6.85
    {1022,1160,1024, 0, 0, 0},  //TV = 9.93(81 lines)  AV=2.00  SV=5.18  BV=6.75
    {1097,1160,1024, 0, 0, 0},  //TV = 9.83(87 lines)  AV=2.00  SV=5.18  BV=6.65
    {1173,1160,1024, 0, 0, 0},  //TV = 9.74(93 lines)  AV=2.00  SV=5.18  BV=6.56
    {1261,1160,1024, 0, 0, 0},  //TV = 9.63(100 lines)  AV=2.00  SV=5.18  BV=6.45
    {1362,1160,1024, 0, 0, 0},  //TV = 9.52(108 lines)  AV=2.00  SV=5.18  BV=6.34
    {1450,1160,1024, 0, 0, 0},  //TV = 9.43(115 lines)  AV=2.00  SV=5.18  BV=6.25
    {1564,1160,1024, 0, 0, 0},  //TV = 9.32(124 lines)  AV=2.00  SV=5.18  BV=6.14
    {1665,1160,1024, 0, 0, 0},  //TV = 9.23(132 lines)  AV=2.00  SV=5.18  BV=6.05
    {1778,1160,1024, 0, 0, 0},  //TV = 9.14(141 lines)  AV=2.00  SV=5.18  BV=5.96
    {1917,1160,1024, 0, 0, 0},  //TV = 9.03(152 lines)  AV=2.00  SV=5.18  BV=5.85
    {2056,1160,1024, 0, 0, 0},  //TV = 8.93(163 lines)  AV=2.00  SV=5.18  BV=5.75
    {2207,1160,1024, 0, 0, 0},  //TV = 8.82(175 lines)  AV=2.00  SV=5.18  BV=5.64
    {2358,1160,1024, 0, 0, 0},  //TV = 8.73(187 lines)  AV=2.00  SV=5.18  BV=5.55
    {2522,1160,1024, 0, 0, 0},  //TV = 8.63(200 lines)  AV=2.00  SV=5.18  BV=5.45
    {2724,1160,1024, 0, 0, 0},  //TV = 8.52(216 lines)  AV=2.00  SV=5.18  BV=5.34
    {2913,1160,1024, 0, 0, 0},  //TV = 8.42(231 lines)  AV=2.00  SV=5.18  BV=5.24
    {3089,1160,1024, 0, 0, 0},  //TV = 8.34(245 lines)  AV=2.00  SV=5.18  BV=5.16
    {3354,1160,1024, 0, 0, 0},  //TV = 8.22(266 lines)  AV=2.00  SV=5.18  BV=5.04
    {3594,1160,1024, 0, 0, 0},  //TV = 8.12(285 lines)  AV=2.00  SV=5.18  BV=4.94
    {3846,1160,1024, 0, 0, 0},  //TV = 8.02(305 lines)  AV=2.00  SV=5.18  BV=4.84
    {4123,1160,1024, 0, 0, 0},  //TV = 7.92(327 lines)  AV=2.00  SV=5.18  BV=4.74
    {4413,1160,1024, 0, 0, 0},  //TV = 7.82(350 lines)  AV=2.00  SV=5.18  BV=4.64
    {4716,1160,1024, 0, 0, 0},  //TV = 7.73(374 lines)  AV=2.00  SV=5.18  BV=4.55
    {5056,1160,1024, 0, 0, 0},  //TV = 7.63(401 lines)  AV=2.00  SV=5.18  BV=4.45
    {5447,1160,1024, 0, 0, 0},  //TV = 7.52(432 lines)  AV=2.00  SV=5.18  BV=4.34
    {5800,1160,1024, 0, 0, 0},  //TV = 7.43(460 lines)  AV=2.00  SV=5.18  BV=4.25
    {6254,1160,1024, 0, 0, 0},  //TV = 7.32(496 lines)  AV=2.00  SV=5.18  BV=4.14
    {6695,1160,1024, 0, 0, 0},  //TV = 7.22(531 lines)  AV=2.00  SV=5.18  BV=4.04
    {7174,1160,1024, 0, 0, 0},  //TV = 7.12(569 lines)  AV=2.00  SV=5.18  BV=3.94
    {7679,1160,1024, 0, 0, 0},  //TV = 7.02(609 lines)  AV=2.00  SV=5.18  BV=3.84
    {8221,1160,1024, 0, 0, 0},  //TV = 6.93(652 lines)  AV=2.00  SV=5.18  BV=3.75
    {8335,1216,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.25  BV=3.66
    {8335,1312,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.36  BV=3.55
    {8335,1408,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.46  BV=3.45
    {8335,1504,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.57  BV=3.34
    {8335,1600,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.66  BV=3.25
    {8335,1728,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.77  BV=3.14
    {8335,1856,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.86  BV=3.05
    {8335,1984,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.97  BV=2.94
    {8335,2144,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=6.07  BV=2.84
    {8335,2272,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=6.16  BV=2.75
    {16669,1216,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.25  BV=2.66
    {16669,1312,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.36  BV=2.55
    {16669,1408,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.46  BV=2.45
    {16669,1504,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.55  BV=2.35
    {16669,1600,1032, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.66  BV=2.25
    {16669,1728,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.75  BV=2.15
    {25003,1216,1040, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=5.27  BV=2.05
    {25003,1312,1032, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=5.37  BV=1.95
    {25003,1408,1032, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=5.47  BV=1.85
    {25003,1504,1040, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=5.58  BV=1.74
    {33336,1216,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.25  BV=1.66
    {33336,1312,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.36  BV=1.55
    {33336,1408,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.46  BV=1.45
    {33336,1504,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.55  BV=1.35
    {33336,1600,1032, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.66  BV=1.25
    {33336,1728,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.75  BV=1.15
    {33336,1856,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.86  BV=1.05
    {33336,1984,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=5.95  BV=0.95
    {33336,2144,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.07  BV=0.84
    {33336,2272,1032, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.16  BV=0.75
    {33336,2432,1032, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.26  BV=0.65
    {33336,2624,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.36  BV=0.55
    {33336,2816,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.46  BV=0.45
    {33336,3008,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.55  BV=0.35
    {33336,3232,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.66  BV=0.25
    {33336,3456,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.75  BV=0.15
    {33336,3712,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.86  BV=0.05
    {33336,4000,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=6.97  BV=-0.06
    {33336,4256,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33336,4576,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33336,4896,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33336,5248,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33336,5600,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.45  BV=-0.54
    {33336,6048,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.56  BV=-0.66
    {33336,6464,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33336,6944,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33336,7424,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33336,7968,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33336,8512,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33336,9152,1024, 0, 0, 0},  //TV = 4.91(2644 lines)  AV=2.00  SV=8.16  BV=-1.25
    {41670,7840,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=7.94  BV=-1.35
    {41670,8416,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.04  BV=-1.45
    {41670,8992,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.13  BV=-1.55
    {41670,9664,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.24  BV=-1.65
    {41670,10336,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.34  BV=-1.75
    {41670,11072,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.43  BV=-1.85
    {41670,11872,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41670,12800,1024, 0, 0, 0},  //TV = 4.58(3305 lines)  AV=2.00  SV=8.64  BV=-2.06
    {50004,11424,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.48  BV=-2.16
    {50004,12256,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.58  BV=-2.26
    {50004,13120,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.68  BV=-2.36
    {58338,12064,1024, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=8.56  BV=-2.46
    {58338,12896,1024, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=8.65  BV=-2.56
    {58338,13824,1024, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=8.75  BV=-2.66
    {58338,14816,1024, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=8.85  BV=-2.76
    {58338,15872,1024, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=8.95  BV=-2.85
    {58338,16384,1056, 0, 0, 0},  //TV = 4.10(4627 lines)  AV=2.00  SV=9.04  BV=-2.94
    {66659,15904,1024, 0, 0, 0},  //TV = 3.91(5287 lines)  AV=2.00  SV=8.96  BV=-3.05
    {66659,16384,1064, 0, 0, 0},  //TV = 3.91(5287 lines)  AV=2.00  SV=9.06  BV=-3.15
    {74993,16256,1024, 0, 0, 0},  //TV = 3.74(5948 lines)  AV=2.00  SV=8.99  BV=-3.25
    {83327,15680,1024, 0, 0, 0},  //TV = 3.59(6609 lines)  AV=2.00  SV=8.94  BV=-3.35
    {83327,16384,1048, 0, 0, 0},  //TV = 3.59(6609 lines)  AV=2.00  SV=9.03  BV=-3.45
    {91661,16352,1024, 0, 0, 0},  //TV = 3.45(7270 lines)  AV=2.00  SV=9.00  BV=-3.55
    {99995,16064,1024, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=8.97  BV=-3.65
    {99995,16384,1080, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.08  BV=-3.75
    {99995,16384,1152, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.17  BV=-3.85
    {99995,16384,1240, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.28  BV=-3.95
    {99995,16384,1328, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.38  BV=-4.05
    {99995,16384,1424, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.48  BV=-4.15
    {99995,16384,1528, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.58  BV=-4.26
    {99995,16384,1632, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.67  BV=-4.35
    {99995,16384,1752, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.77  BV=-4.45
    {99995,16384,1880, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.88  BV=-4.55
    {99995,16384,2016, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.98  BV=-4.66
    {99995,16384,2160, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.08  BV=-4.75
    {99995,16384,2312, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.17  BV=-4.85
    {99995,16384,2480, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.28  BV=-4.95
    {99995,16384,2656, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.38  BV=-5.05
    {99995,16384,2848, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.48  BV=-5.15
    {99995,16384,3048, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.57  BV=-5.25
    {99995,16384,3200, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.64  BV=-5.32
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sPreviewPLineTable_50Hz =
{
{
    {89,1280,1040, 0, 0, 0},  //TV = 13.46(7 lines)  AV=2.00  SV=5.34  BV=10.11
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.25  BV=10.03
    {101,1280,1024, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.32  BV=9.95
    {114,1248,1024, 0, 0, 0},  /* TV = 13.10(9 lines)  AV=2.00  SV=5.29  BV=9.81 */
    {127,1184,1032, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.22  BV=9.72
    {139,1160,1024, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.18  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.26  BV=9.55
    {152,1216,1024, 0, 0, 0},  //TV = 12.68(12 lines)  AV=2.00  SV=5.25  BV=9.44
    {164,1216,1024, 0, 0, 0},  //TV = 12.57(13 lines)  AV=2.00  SV=5.25  BV=9.33
    {177,1216,1024, 0, 0, 0},  //TV = 12.46(14 lines)  AV=2.00  SV=5.25  BV=9.22
    {190,1216,1024, 0, 0, 0},  //TV = 12.36(15 lines)  AV=2.00  SV=5.25  BV=9.11
    {202,1184,1032, 0, 0, 0},  /* TV = 12.27(16 lines)  AV=2.00  SV=5.22  BV=9.05 */
    {215,1184,1040, 0, 0, 0},  //TV = 12.18(17 lines)  AV=2.00  SV=5.23  BV=8.95
    {227,1216,1024, 0, 0, 0},  //TV = 12.11(18 lines)  AV=2.00  SV=5.25  BV=8.86
    {253,1160,1032, 0, 0, 0},  //TV = 11.95(20 lines)  AV=2.00  SV=5.19  BV=8.76
    {265,1184,1040, 0, 0, 0},  //TV = 11.88(21 lines)  AV=2.00  SV=5.23  BV=8.65
    {290,1184,1024, 0, 0, 0},  //TV = 11.75(23 lines)  AV=2.00  SV=5.21  BV=8.54
    {316,1160,1024, 0, 0, 0},  //TV = 11.63(25 lines)  AV=2.00  SV=5.18  BV=8.45
    {328,1184,1032, 0, 0, 0},  //TV = 11.57(26 lines)  AV=2.00  SV=5.22  BV=8.35
    {354,1184,1024, 0, 0, 0},  //TV = 11.46(28 lines)  AV=2.00  SV=5.21  BV=8.25
    {379,1184,1024, 0, 0, 0},  //TV = 11.37(30 lines)  AV=2.00  SV=5.21  BV=8.16
    {417,1160,1024, 0, 0, 0},  //TV = 11.23(33 lines)  AV=2.00  SV=5.18  BV=8.05
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(35 lines)  AV=2.00  SV=5.19  BV=7.95
    {480,1160,1024, 0, 0, 0},  //TV = 11.02(38 lines)  AV=2.00  SV=5.18  BV=7.84
    {505,1184,1024, 0, 0, 0},  //TV = 10.95(40 lines)  AV=2.00  SV=5.21  BV=7.74
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(43 lines)  AV=2.00  SV=5.19  BV=7.66
    {580,1184,1024, 0, 0, 0},  //TV = 10.75(46 lines)  AV=2.00  SV=5.21  BV=7.54
    {631,1160,1024, 0, 0, 0},  //TV = 10.63(50 lines)  AV=2.00  SV=5.18  BV=7.45
    {669,1160,1032, 0, 0, 0},  //TV = 10.55(53 lines)  AV=2.00  SV=5.19  BV=7.35
    {719,1160,1032, 0, 0, 0},  //TV = 10.44(57 lines)  AV=2.00  SV=5.19  BV=7.25
    {770,1160,1032, 0, 0, 0},  //TV = 10.34(61 lines)  AV=2.00  SV=5.19  BV=7.15
    {833,1160,1024, 0, 0, 0},  //TV = 10.23(66 lines)  AV=2.00  SV=5.18  BV=7.05
    {883,1160,1032, 0, 0, 0},  //TV = 10.15(70 lines)  AV=2.00  SV=5.19  BV=6.95
    {959,1160,1024, 0, 0, 0},  //TV = 10.03(76 lines)  AV=2.00  SV=5.18  BV=6.85
    {1022,1160,1024, 0, 0, 0},  //TV = 9.93(81 lines)  AV=2.00  SV=5.18  BV=6.75
    {1097,1160,1024, 0, 0, 0},  //TV = 9.83(87 lines)  AV=2.00  SV=5.18  BV=6.65
    {1173,1160,1024, 0, 0, 0},  //TV = 9.74(93 lines)  AV=2.00  SV=5.18  BV=6.56
    {1261,1160,1024, 0, 0, 0},  //TV = 9.63(100 lines)  AV=2.00  SV=5.18  BV=6.45
    {1362,1160,1024, 0, 0, 0},  //TV = 9.52(108 lines)  AV=2.00  SV=5.18  BV=6.34
    {1450,1160,1024, 0, 0, 0},  //TV = 9.43(115 lines)  AV=2.00  SV=5.18  BV=6.25
    {1564,1160,1024, 0, 0, 0},  //TV = 9.32(124 lines)  AV=2.00  SV=5.18  BV=6.14
    {1665,1160,1024, 0, 0, 0},  //TV = 9.23(132 lines)  AV=2.00  SV=5.18  BV=6.05
    {1778,1160,1024, 0, 0, 0},  //TV = 9.14(141 lines)  AV=2.00  SV=5.18  BV=5.96
    {1917,1160,1024, 0, 0, 0},  //TV = 9.03(152 lines)  AV=2.00  SV=5.18  BV=5.85
    {2056,1160,1024, 0, 0, 0},  //TV = 8.93(163 lines)  AV=2.00  SV=5.18  BV=5.75
    {2207,1160,1024, 0, 0, 0},  //TV = 8.82(175 lines)  AV=2.00  SV=5.18  BV=5.64
    {2358,1160,1024, 0, 0, 0},  //TV = 8.73(187 lines)  AV=2.00  SV=5.18  BV=5.55
    {2522,1160,1024, 0, 0, 0},  //TV = 8.63(200 lines)  AV=2.00  SV=5.18  BV=5.45
    {2724,1160,1024, 0, 0, 0},  //TV = 8.52(216 lines)  AV=2.00  SV=5.18  BV=5.34
    {2913,1160,1024, 0, 0, 0},  //TV = 8.42(231 lines)  AV=2.00  SV=5.18  BV=5.24
    {3089,1160,1024, 0, 0, 0},  //TV = 8.34(245 lines)  AV=2.00  SV=5.18  BV=5.16
    {3354,1160,1024, 0, 0, 0},  //TV = 8.22(266 lines)  AV=2.00  SV=5.18  BV=5.04
    {3594,1160,1024, 0, 0, 0},  //TV = 8.12(285 lines)  AV=2.00  SV=5.18  BV=4.94
    {3846,1160,1024, 0, 0, 0},  //TV = 8.02(305 lines)  AV=2.00  SV=5.18  BV=4.84
    {4123,1160,1024, 0, 0, 0},  //TV = 7.92(327 lines)  AV=2.00  SV=5.18  BV=4.74
    {4413,1160,1024, 0, 0, 0},  //TV = 7.82(350 lines)  AV=2.00  SV=5.18  BV=4.64
    {4716,1160,1024, 0, 0, 0},  //TV = 7.73(374 lines)  AV=2.00  SV=5.18  BV=4.55
    {5056,1160,1024, 0, 0, 0},  //TV = 7.63(401 lines)  AV=2.00  SV=5.18  BV=4.45
    {5447,1160,1024, 0, 0, 0},  //TV = 7.52(432 lines)  AV=2.00  SV=5.18  BV=4.34
    {5800,1160,1024, 0, 0, 0},  //TV = 7.43(460 lines)  AV=2.00  SV=5.18  BV=4.25
    {6254,1160,1024, 0, 0, 0},  //TV = 7.32(496 lines)  AV=2.00  SV=5.18  BV=4.14
    {6695,1160,1024, 0, 0, 0},  //TV = 7.22(531 lines)  AV=2.00  SV=5.18  BV=4.04
    {7174,1160,1024, 0, 0, 0},  //TV = 7.12(569 lines)  AV=2.00  SV=5.18  BV=3.94
    {7679,1160,1024, 0, 0, 0},  //TV = 7.02(609 lines)  AV=2.00  SV=5.18  BV=3.84
    {8221,1160,1024, 0, 0, 0},  //TV = 6.93(652 lines)  AV=2.00  SV=5.18  BV=3.75
    {8813,1160,1024, 0, 0, 0},  //TV = 6.83(699 lines)  AV=2.00  SV=5.18  BV=3.65
    {9431,1160,1024, 0, 0, 0},  //TV = 6.73(748 lines)  AV=2.00  SV=5.18  BV=3.55
    {9999,1160,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.19  BV=3.45
    {9999,1248,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.29  BV=3.36
    {9999,1344,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.39  BV=3.25
    {9999,1440,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.50  BV=3.14
    {9999,1536,1040, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.61  BV=3.04
    {9999,1664,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.70  BV=2.94
    {9999,1760,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.79  BV=2.85
    {9999,1888,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.89  BV=2.75
    {9999,2016,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.99  BV=2.66
    {9999,2176,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.10  BV=2.55
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=5.70  BV=1.94
    {29995,1184,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.21  BV=1.85
    {29995,1248,1040, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.31  BV=1.75
    {29995,1344,1032, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.40  BV=1.66
    {29995,1440,1040, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.51  BV=1.54
    {29995,1568,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.61  BV=1.44
    {29995,1664,1032, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.71  BV=1.35
    {29995,1792,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.81  BV=1.25
    {29995,1920,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=5.91  BV=1.15
    {29995,2048,1032, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.01  BV=1.05
    {29995,2208,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.11  BV=0.95
    {29995,2368,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.21  BV=0.85
    {29995,2528,1032, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.32  BV=0.74
    {29995,2720,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.41  BV=0.65
    {29995,2912,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.51  BV=0.55
    {29995,3136,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.61  BV=0.44
    {29995,3360,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.71  BV=0.34
    {29995,3584,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.81  BV=0.25
    {29995,3840,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.91  BV=0.15
    {29995,4128,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.01  BV=0.05
    {29995,4416,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.11  BV=-0.05
    {29995,4736,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29995,5088,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29995,5440,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29995,5824,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29995,6240,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29995,6720,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.71  BV=-0.66
    {29995,7200,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.81  BV=-0.75
    {29995,7712,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.91  BV=-0.85
    {29995,8256,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.01  BV=-0.95
    {29995,8864,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29995,9472,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.21  BV=-1.15
    {40006,7616,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=7.89  BV=-1.25
    {40006,8160,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=7.99  BV=-1.35
    {40006,8768,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.10  BV=-1.45
    {40006,9376,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.19  BV=-1.55
    {40006,10048,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.29  BV=-1.65
    {40006,10784,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.40  BV=-1.75
    {40006,11552,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.50  BV=-1.85
    {40006,12352,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.59  BV=-1.95
    {40006,13312,1024, 0, 0, 0},  //TV = 4.64(3173 lines)  AV=2.00  SV=8.70  BV=-2.06
    {50004,11424,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.48  BV=-2.16
    {50004,12256,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.58  BV=-2.26
    {50004,13120,1024, 0, 0, 0},  //TV = 4.32(3966 lines)  AV=2.00  SV=8.68  BV=-2.36
    {60002,11712,1024, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60002,12544,1024, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=8.61  BV=-2.56
    {60002,13440,1024, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=8.71  BV=-2.66
    {60002,14400,1024, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=8.81  BV=-2.75
    {60002,15424,1024, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=8.91  BV=-2.85
    {60002,16384,1032, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=9.01  BV=-2.95
    {60002,16384,1104, 0, 0, 0},  //TV = 4.06(4759 lines)  AV=2.00  SV=9.11  BV=-3.05
    {70000,16256,1024, 0, 0, 0},  //TV = 3.84(5552 lines)  AV=2.00  SV=8.99  BV=-3.15
    {70000,16384,1088, 0, 0, 0},  //TV = 3.84(5552 lines)  AV=2.00  SV=9.09  BV=-3.25
    {79998,16320,1024, 0, 0, 0},  //TV = 3.64(6345 lines)  AV=2.00  SV=8.99  BV=-3.35
    {89996,15552,1024, 0, 0, 0},  //TV = 3.47(7138 lines)  AV=2.00  SV=8.92  BV=-3.45
    {89996,16384,1040, 0, 0, 0},  //TV = 3.47(7138 lines)  AV=2.00  SV=9.02  BV=-3.55
    {99995,16064,1024, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=8.97  BV=-3.65
    {99995,16384,1080, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.08  BV=-3.75
    {99995,16384,1152, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.17  BV=-3.85
    {99995,16384,1240, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.28  BV=-3.95
    {99995,16384,1328, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.38  BV=-4.05
    {99995,16384,1424, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.48  BV=-4.15
    {99995,16384,1528, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.58  BV=-4.26
    {99995,16384,1632, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.67  BV=-4.35
    {99995,16384,1752, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.77  BV=-4.45
    {99995,16384,1880, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.88  BV=-4.55
    {99995,16384,2016, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=9.98  BV=-4.66
    {99995,16384,2160, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.08  BV=-4.75
    {99995,16384,2312, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.17  BV=-4.85
    {99995,16384,2480, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.28  BV=-4.95
    {99995,16384,2656, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.38  BV=-5.05
    {99995,16384,2848, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.48  BV=-5.15
    {99995,16384,3048, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.57  BV=-5.25
    {99995,16384,3200, 0, 0, 0},  //TV = 3.32(7931 lines)  AV=2.00  SV=10.64  BV=-5.32
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_PreviewAutoTable =
{
    AETABLE_RPEVIEW_AUTO, //eAETableID
    156, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -54, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sPreviewPLineTable_60Hz,
    sPreviewPLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCapturePLineTable_60Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8330,1216,1040, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.27  BV=3.64
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.95  BV=0.95
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.16  BV=0.75
    {33329,2432,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.26  BV=0.65
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,4000,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.97  BV=-0.06
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5600,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.45  BV=-0.54
    {33329,6048,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.56  BV=-0.66
    {33329,6496,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.67  BV=-0.76
    {33329,6944,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33329,8544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33329,9152,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.25
    {41668,7840,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.94  BV=-1.35
    {41668,8416,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.04  BV=-1.45
    {41668,8992,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.13  BV=-1.55
    {41668,9664,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.24  BV=-1.65
    {41668,10336,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.34  BV=-1.75
    {41668,11072,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.43  BV=-1.85
    {41668,11872,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {49997,11424,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.16
    {49997,12256,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13120,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.36
    {58327,12064,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.56  BV=-2.46
    {58327,12896,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.65  BV=-2.55
    {58327,13824,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.75  BV=-2.66
    {58327,14816,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.85  BV=-2.76
    {58327,15872,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.95  BV=-2.85
    {58327,16384,1056, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.04  BV=-2.94
    {66666,15936,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.96  BV=-3.05
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {74996,16288,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=8.99  BV=-3.25
    {83335,15712,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=8.94  BV=-3.35
    {83335,16384,1048, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=9.03  BV=-3.45
    {91665,16384,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=9.00  BV=-3.55
    {99994,16096,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.97  BV=-3.65
    {99994,16384,1072, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.07  BV=-3.74
    {99994,16384,1160, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.18  BV=-3.86
    {99994,16384,1240, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.28  BV=-3.95
    {99994,16384,1328, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.38  BV=-4.05
    {99994,16384,1424, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.48  BV=-4.15
    {99994,16384,1528, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.58  BV=-4.26
    {99994,16384,1640, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.68  BV=-4.36
    {99994,16384,1752, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.77  BV=-4.45
    {99994,16384,1880, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.88  BV=-4.55
    {99994,16384,2016, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.98  BV=-4.66
    {99994,16384,2160, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.08  BV=-4.75
    {99994,16384,2312, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.17  BV=-4.85
    {99994,16384,2480, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.28  BV=-4.95
    {99994,16384,2656, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.38  BV=-5.05
    {99994,16384,2848, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.48  BV=-5.15
    {99994,16384,3056, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.58  BV=-5.26
    {99994,16384,3200, 0, 0, 0},  /* TV = 3.32(10876 lines)  AV=2.00  SV=10.64  BV=-5.32 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCapturePLineTable_50Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8808,1160,1024, 0, 0, 0},  //TV = 6.83(958 lines)  AV=2.00  SV=5.18  BV=3.65
    {9443,1160,1024, 0, 0, 0},  //TV = 6.73(1027 lines)  AV=2.00  SV=5.18  BV=3.55
    {10004,1160,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.19  BV=3.45
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {30001,1184,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.21  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.52  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.81  BV=1.25
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.32  BV=0.74
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3360,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.71  BV=0.34
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5824,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.51  BV=-0.45
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.66
    {30001,7200,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8256,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.15
    {40004,7616,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.89  BV=-1.25
    {40004,8160,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.99  BV=-1.35
    {40004,8768,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.10  BV=-1.45
    {40004,9376,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.19  BV=-1.55
    {40004,10048,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.29  BV=-1.65
    {40004,10784,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.75
    {40004,11552,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.85
    {40004,12352,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.59  BV=-1.95
    {40004,13344,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {49997,11424,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.16
    {49997,12256,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13120,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.36
    {60001,11712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60001,12544,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.56
    {60001,13440,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.71  BV=-2.66
    {60001,14400,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.81  BV=-2.75
    {60001,15424,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.91  BV=-2.85
    {60001,16384,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.01  BV=-2.95
    {70004,15168,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.89  BV=-3.05
    {70004,16256,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.15
    {79997,15264,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=8.90  BV=-3.25
    {79997,16352,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=9.00  BV=-3.35
    {90001,15584,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=8.93  BV=-3.45
    {90001,16384,1040, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=9.02  BV=-3.55
    {100004,16096,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.97  BV=-3.65
    {100004,16384,1072, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.07  BV=-3.74
    {100004,16384,1160, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.18  BV=-3.86
    {100004,16384,1240, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.28  BV=-3.95
    {100004,16384,1328, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.38  BV=-4.05
    {100004,16384,1424, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.48  BV=-4.15
    {100004,16384,1528, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.58  BV=-4.26
    {100004,16384,1640, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.68  BV=-4.36
    {100004,16384,1752, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.77  BV=-4.45
    {100004,16384,1880, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.88  BV=-4.55
    {100004,16384,2016, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.98  BV=-4.66
    {100004,16384,2160, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.08  BV=-4.75
    {100004,16384,2312, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.17  BV=-4.85
    {100004,16384,2480, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.28  BV=-4.95
    {100004,16384,2656, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.38  BV=-5.05
    {100004,16384,2848, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.48  BV=-5.15
    {100004,16384,3056, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.58  BV=-5.26
    {100004,16384,3200, 0, 0, 0},  /* TV = 3.32(10877 lines)  AV=2.00  SV=10.64  BV=-5.32 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureAutoTable =
{
    AETABLE_CAPTURE_AUTO, //eAETableID
    156, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -54, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCapturePLineTable_60Hz,
    sCapturePLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sVideoPLineTable_60Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8330,1216,1040, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.27  BV=3.64
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33302,1216,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.26  BV=1.65
    {33302,1312,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.37  BV=1.54
    {33302,1408,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.46  BV=1.45
    {33302,1504,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.55  BV=1.35
    {33302,1600,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.66  BV=1.25
    {33302,1728,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.75  BV=1.15
    {33302,1856,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.86  BV=1.05
    {33302,1984,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=5.95  BV=0.95
    {33302,2112,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.06  BV=0.85
    {33302,2272,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.16  BV=0.75
    {33302,2432,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.26  BV=0.65
    {33302,2624,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.36  BV=0.55
    {33302,2816,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.46  BV=0.45
    {33302,3008,1032, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.57  BV=0.34
    {33302,3232,1024, 0, 0, 0},  //TV = 4.91(3622 lines)  AV=2.00  SV=6.66  BV=0.25
    {41668,2784,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.44  BV=0.14
    {41668,2976,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.54  BV=0.05
    {41668,3200,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.64  BV=-0.06
    {41668,3424,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.74  BV=-0.16
    {41668,3648,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.83  BV=-0.25
    {41668,3904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.93  BV=-0.35
    {41668,4192,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.03  BV=-0.45
    {41668,4512,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.14  BV=-0.55
    {41668,4832,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.24  BV=-0.65
    {41668,5184,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.34  BV=-0.75
    {41668,5536,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.43  BV=-0.85
    {41668,5952,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.54  BV=-0.95
    {41668,6368,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.64  BV=-1.05
    {41668,6816,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.73  BV=-1.15
    {41668,7296,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.83  BV=-1.25
    {41668,7872,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.94  BV=-1.36
    {41668,8416,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.04  BV=-1.45
    {41668,9024,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.14  BV=-1.55
    {41668,9664,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.24  BV=-1.65
    {41668,10368,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.34  BV=-1.75
    {41668,11104,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.85
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12736,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.05
    {41668,13664,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.74  BV=-2.15
    {41668,14624,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.84  BV=-2.25
    {41668,15680,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.94  BV=-2.35
    {41668,16384,1048, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.03  BV=-2.45
    {49997,15040,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.88  BV=-2.55
    {49997,16096,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.97  BV=-2.65
    {49997,16384,1072, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.07  BV=-2.74
    {58327,15872,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.95  BV=-2.85
    {58327,16384,1056, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.04  BV=-2.94
    {58327,16384,1136, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.15  BV=-3.05
    {58327,16384,1216, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.25  BV=-3.15
    {58327,16384,1304, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.35  BV=-3.25
    {58327,16384,1392, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.44  BV=-3.34
    {58327,16384,1496, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.55  BV=-3.45
    {58327,16384,1600, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.64  BV=-3.54
    {58327,16384,1720, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.75  BV=-3.65
    {58327,16384,1840, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.85  BV=-3.75
    {58327,16384,1984, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.95  BV=-3.85
    {58327,16384,2128, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.06  BV=-3.96
    {58327,16384,2280, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.15  BV=-4.06
    {58327,16384,2448, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.26  BV=-4.16
    {58327,16384,2624, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.36  BV=-4.26
    {58327,16384,2808, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.46  BV=-4.36
    {58327,16384,3008, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.55  BV=-4.45
    {58327,16384,3200, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.64  BV=-4.54
    {58327,16384,3200, 0, 0, 0},  /* TV = 4.10(6344 lines)  AV=2.00  SV=10.64  BV=-4.54 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sVideoPLineTable_50Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8808,1160,1024, 0, 0, 0},  //TV = 6.83(958 lines)  AV=2.00  SV=5.18  BV=3.65
    {9443,1160,1024, 0, 0, 0},  //TV = 6.73(1027 lines)  AV=2.00  SV=5.18  BV=3.55
    {10004,1160,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.19  BV=3.45
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {30001,1184,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.21  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.52  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.81  BV=1.25
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.32  BV=0.74
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3360,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.71  BV=0.34
    {40004,2688,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.39  BV=0.25
    {40004,2880,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.49  BV=0.15
    {40004,3104,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.60  BV=0.04
    {40004,3328,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.70  BV=-0.06
    {40004,3552,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.79  BV=-0.15
    {40004,3808,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.89  BV=-0.25
    {40004,4064,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.99  BV=-0.34
    {40004,4352,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.09  BV=-0.44
    {40004,4704,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.20  BV=-0.56
    {40004,5024,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.29  BV=-0.65
    {40004,5408,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.40  BV=-0.76
    {40004,5760,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.49  BV=-0.85
    {40004,6176,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.59  BV=-0.95
    {40004,6624,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.69  BV=-1.05
    {40004,7104,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.79  BV=-1.15
    {40004,7616,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.89  BV=-1.25
    {40004,8192,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.00  BV=-1.36
    {40004,8768,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.10  BV=-1.45
    {40004,9408,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.20  BV=-1.56
    {40004,10080,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.30  BV=-1.66
    {40004,10784,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.75
    {40004,11552,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.85
    {40004,12384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.95
    {40004,13280,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.05
    {40004,14240,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.80  BV=-2.15
    {40004,15232,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.89  BV=-2.25
    {40004,16320,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.99  BV=-2.35
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {49997,15040,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.88  BV=-2.55
    {49997,16096,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.97  BV=-2.65
    {49997,16384,1072, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.07  BV=-2.74
    {60001,15424,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.91  BV=-2.85
    {60001,16384,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.01  BV=-2.95
    {60001,16384,1104, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.11  BV=-3.05
    {60001,16384,1184, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.21  BV=-3.15
    {60001,16384,1264, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.30  BV=-3.24
    {60001,16384,1360, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.41  BV=-3.35
    {60001,16384,1456, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.51  BV=-3.45
    {60001,16384,1560, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.61  BV=-3.55
    {60001,16384,1672, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.71  BV=-3.65
    {60001,16384,1792, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.81  BV=-3.75
    {60001,16384,1928, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.91  BV=-3.85
    {60001,16384,2072, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.02  BV=-3.96
    {60001,16384,2216, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.11  BV=-4.05
    {60001,16384,2376, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.21  BV=-4.16
    {60001,16384,2552, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.32  BV=-4.26
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2928, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.52  BV=-4.46
    {60001,16384,3136, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.61  BV=-4.56
    {60001,16384,3200, 0, 0, 0},  /* TV = 4.06(6526 lines)  AV=2.00  SV=10.64  BV=-4.58 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_VideoAutoTable =
{
    AETABLE_VIDEO_AUTO, //eAETableID
    149, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -46, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideoPLineTable_60Hz,
    sVideoPLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sVideo1PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8257,1216,1040, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.27  BV=3.65
    {8257,1312,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.37  BV=3.55
    {8257,1408,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.47  BV=3.45
    {8257,1504,1040, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.58  BV=3.34
    {8257,1632,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.67  BV=3.25
    {8257,1728,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.77  BV=3.15
    {8257,1856,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.87  BV=3.05
    {8257,2016,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.98  BV=2.94
    {8257,2144,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.07  BV=2.85
    {8257,2304,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.17  BV=2.75
    {8257,2464,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.27  BV=2.65
    {8257,2656,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.38  BV=2.55
    {8257,2816,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.47  BV=2.45
    {8257,3040,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.57  BV=2.35
    {8257,3264,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.67  BV=2.25
    {8257,3488,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.77  BV=2.15
    {8257,3744,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.87  BV=2.05
    {8257,4000,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.97  BV=1.95
    {8257,4320,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.08  BV=1.84
    {8257,4608,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.17  BV=1.75
    {8257,4960,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.28  BV=1.64
    {8257,5312,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.38  BV=1.55
    {8257,5664,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.47  BV=1.45
    {8257,6080,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.57  BV=1.35
    {8257,6496,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.67  BV=1.25
    {8257,7008,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.77  BV=1.15
    {8257,7520,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.88  BV=1.04
    {8257,8064,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.98  BV=0.94
    {8257,8640,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.08  BV=0.84
    {8257,9248,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.17  BV=0.75
    {8257,9888,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.27  BV=0.65
    {8257,10592,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.37  BV=0.55
    {8257,11360,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.47  BV=0.45
    {8257,12160,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.57  BV=0.35
    {8257,13056,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.67  BV=0.25
    {8257,13984,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.77  BV=0.15
    {8257,14976,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.87  BV=0.05
    {8257,16032,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.97  BV=-0.05
    {8257,16384,1072, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.07  BV=-0.15
    {8257,16384,1160, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.18  BV=-0.26
    {8257,16384,1240, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.28  BV=-0.36
    {8257,16384,1280, 0, 0, 0},  /* TV = 6.92(898 lines)  AV=2.00  SV=9.32  BV=-0.40 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sVideo1PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8257,1216,1040, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.27  BV=3.65
    {8257,1312,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.37  BV=3.55
    {8257,1408,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.47  BV=3.45
    {8257,1504,1040, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.58  BV=3.34
    {8257,1632,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.67  BV=3.25
    {8257,1728,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.77  BV=3.15
    {8257,1856,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.87  BV=3.05
    {8257,2016,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=5.98  BV=2.94
    {8257,2144,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.07  BV=2.85
    {8257,2304,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.17  BV=2.75
    {8257,2464,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.27  BV=2.65
    {8257,2656,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.38  BV=2.55
    {8257,2816,1032, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.47  BV=2.45
    {8257,3040,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.57  BV=2.35
    {8257,3264,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.67  BV=2.25
    {8257,3488,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.77  BV=2.15
    {8257,3744,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.87  BV=2.05
    {8257,4000,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=6.97  BV=1.95
    {8257,4320,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.08  BV=1.84
    {8257,4608,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.17  BV=1.75
    {8257,4960,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.28  BV=1.64
    {8257,5312,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.38  BV=1.55
    {8257,5664,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.47  BV=1.45
    {8257,6080,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.57  BV=1.35
    {8257,6496,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.67  BV=1.25
    {8257,7008,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.77  BV=1.15
    {8257,7520,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.88  BV=1.04
    {8257,8064,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=7.98  BV=0.94
    {8257,8640,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.08  BV=0.84
    {8257,9248,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.17  BV=0.75
    {8257,9888,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.27  BV=0.65
    {8257,10592,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.37  BV=0.55
    {8257,11360,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.47  BV=0.45
    {8257,12160,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.57  BV=0.35
    {8257,13056,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.67  BV=0.25
    {8257,13984,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.77  BV=0.15
    {8257,14976,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.87  BV=0.05
    {8257,16032,1024, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=8.97  BV=-0.05
    {8257,16384,1072, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.07  BV=-0.15
    {8257,16384,1160, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.18  BV=-0.26
    {8257,16384,1240, 0, 0, 0},  //TV = 6.92(898 lines)  AV=2.00  SV=9.28  BV=-0.36
    {8257,16384,1280, 0, 0, 0},  /* TV = 6.92(898 lines)  AV=2.00  SV=9.32  BV=-0.40 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Video1AutoTable =
{
    AETABLE_VIDEO1_AUTO, //eAETableID
    107, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -4, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideo1PLineTable_60Hz,
    sVideo1PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sVideo2PLineTable_60Hz =
{
{
    {89,1344,1024, 0, 0, 0},  //TV = 13.46(7 lines)  AV=2.00  SV=5.39  BV=10.06
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(8 lines)  AV=2.00  SV=5.25  BV=10.03 */
    {101,1280,1032, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.33  BV=9.94
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(9 lines)  AV=2.00  SV=5.29  BV=9.81
    {127,1184,1032, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.22  BV=9.72
    {127,1248,1040, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.31  BV=9.64
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.26  BV=9.55
    {152,1216,1024, 0, 0, 0},  //TV = 12.68(12 lines)  AV=2.00  SV=5.25  BV=9.44
    {164,1216,1024, 0, 0, 0},  //TV = 12.57(13 lines)  AV=2.00  SV=5.25  BV=9.33
    {177,1216,1024, 0, 0, 0},  //TV = 12.46(14 lines)  AV=2.00  SV=5.25  BV=9.22
    {190,1216,1024, 0, 0, 0},  //TV = 12.36(15 lines)  AV=2.00  SV=5.25  BV=9.11
    {190,1248,1040, 0, 0, 0},  /* TV = 12.36(15 lines)  AV=2.00  SV=5.31  BV=9.05 */
    {215,1184,1040, 0, 0, 0},  //TV = 12.18(17 lines)  AV=2.00  SV=5.23  BV=8.95
    {227,1216,1024, 0, 0, 0},  //TV = 12.11(18 lines)  AV=2.00  SV=5.25  BV=8.86
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(19 lines)  AV=2.00  SV=5.27  BV=8.75
    {265,1184,1040, 0, 0, 0},  //TV = 11.88(21 lines)  AV=2.00  SV=5.23  BV=8.65
    {278,1216,1032, 0, 0, 0},  //TV = 11.81(22 lines)  AV=2.00  SV=5.26  BV=8.55
    {303,1184,1040, 0, 0, 0},  //TV = 11.69(24 lines)  AV=2.00  SV=5.23  BV=8.46
    {328,1184,1032, 0, 0, 0},  //TV = 11.57(26 lines)  AV=2.00  SV=5.22  BV=8.35
    {341,1216,1040, 0, 0, 0},  //TV = 11.52(27 lines)  AV=2.00  SV=5.27  BV=8.25
    {366,1216,1032, 0, 0, 0},  //TV = 11.42(29 lines)  AV=2.00  SV=5.26  BV=8.16
    {404,1184,1032, 0, 0, 0},  //TV = 11.27(32 lines)  AV=2.00  SV=5.22  BV=8.05
    {429,1184,1040, 0, 0, 0},  //TV = 11.19(34 lines)  AV=2.00  SV=5.23  BV=7.95
    {454,1216,1024, 0, 0, 0},  //TV = 11.11(36 lines)  AV=2.00  SV=5.25  BV=7.86
    {492,1216,1024, 0, 0, 0},  //TV = 10.99(39 lines)  AV=2.00  SV=5.25  BV=7.74
    {530,1184,1040, 0, 0, 0},  //TV = 10.88(42 lines)  AV=2.00  SV=5.23  BV=7.65
    {568,1184,1040, 0, 0, 0},  //TV = 10.78(45 lines)  AV=2.00  SV=5.23  BV=7.55
    {606,1184,1040, 0, 0, 0},  //TV = 10.69(48 lines)  AV=2.00  SV=5.23  BV=7.46
    {656,1184,1032, 0, 0, 0},  //TV = 10.57(52 lines)  AV=2.00  SV=5.22  BV=7.35
    {694,1216,1024, 0, 0, 0},  //TV = 10.49(55 lines)  AV=2.00  SV=5.25  BV=7.24
    {744,1216,1024, 0, 0, 0},  //TV = 10.39(59 lines)  AV=2.00  SV=5.25  BV=7.14
    {795,1216,1024, 0, 0, 0},  //TV = 10.30(63 lines)  AV=2.00  SV=5.25  BV=7.05
    {858,1184,1040, 0, 0, 0},  //TV = 10.19(68 lines)  AV=2.00  SV=5.23  BV=6.95
    {921,1184,1040, 0, 0, 0},  //TV = 10.08(73 lines)  AV=2.00  SV=5.23  BV=6.85
    {997,1184,1032, 0, 0, 0},  //TV = 9.97(79 lines)  AV=2.00  SV=5.22  BV=6.75
    {1060,1184,1040, 0, 0, 0},  //TV = 9.88(84 lines)  AV=2.00  SV=5.23  BV=6.65
    {1135,1184,1040, 0, 0, 0},  //TV = 9.78(90 lines)  AV=2.00  SV=5.23  BV=6.55
    {1223,1184,1040, 0, 0, 0},  //TV = 9.68(97 lines)  AV=2.00  SV=5.23  BV=6.44
    {1299,1184,1040, 0, 0, 0},  //TV = 9.59(103 lines)  AV=2.00  SV=5.23  BV=6.36
    {1400,1184,1040, 0, 0, 0},  //TV = 9.48(111 lines)  AV=2.00  SV=5.23  BV=6.25
    {1513,1184,1032, 0, 0, 0},  //TV = 9.37(120 lines)  AV=2.00  SV=5.22  BV=6.15
    {1614,1184,1032, 0, 0, 0},  //TV = 9.28(128 lines)  AV=2.00  SV=5.22  BV=6.05
    {1715,1184,1040, 0, 0, 0},  //TV = 9.19(136 lines)  AV=2.00  SV=5.23  BV=5.96
    {1854,1184,1032, 0, 0, 0},  //TV = 9.08(147 lines)  AV=2.00  SV=5.22  BV=5.85
    {1980,1184,1040, 0, 0, 0},  //TV = 8.98(157 lines)  AV=2.00  SV=5.23  BV=5.75
    {2131,1184,1040, 0, 0, 0},  //TV = 8.87(169 lines)  AV=2.00  SV=5.23  BV=5.64
    {2283,1184,1032, 0, 0, 0},  //TV = 8.77(181 lines)  AV=2.00  SV=5.22  BV=5.55
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(194 lines)  AV=2.00  SV=5.22  BV=5.45
    {2636,1184,1032, 0, 0, 0},  //TV = 8.57(209 lines)  AV=2.00  SV=5.22  BV=5.35
    {2812,1184,1032, 0, 0, 0},  //TV = 8.47(223 lines)  AV=2.00  SV=5.22  BV=5.25
    {3014,1184,1032, 0, 0, 0},  //TV = 8.37(239 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(256 lines)  AV=2.00  SV=5.22  BV=5.05
    {3455,1184,1032, 0, 0, 0},  //TV = 8.18(274 lines)  AV=2.00  SV=5.22  BV=4.96
    {3720,1184,1032, 0, 0, 0},  //TV = 8.07(295 lines)  AV=2.00  SV=5.22  BV=4.85
    {3985,1184,1032, 0, 0, 0},  //TV = 7.97(316 lines)  AV=2.00  SV=5.22  BV=4.75
    {4262,1184,1032, 0, 0, 0},  //TV = 7.87(338 lines)  AV=2.00  SV=5.22  BV=4.65
    {4565,1184,1032, 0, 0, 0},  //TV = 7.78(362 lines)  AV=2.00  SV=5.22  BV=4.55
    {4918,1184,1032, 0, 0, 0},  //TV = 7.67(390 lines)  AV=2.00  SV=5.22  BV=4.45
    {5233,1184,1032, 0, 0, 0},  //TV = 7.58(415 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(447 lines)  AV=2.00  SV=5.22  BV=4.25
    {6040,1184,1032, 0, 0, 0},  //TV = 7.37(479 lines)  AV=2.00  SV=5.22  BV=4.15
    {6468,1184,1032, 0, 0, 0},  //TV = 7.27(513 lines)  AV=2.00  SV=5.22  BV=4.05
    {6922,1184,1032, 0, 0, 0},  //TV = 7.17(549 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(588 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(630 lines)  AV=2.00  SV=5.22  BV=3.76
    {8335,1216,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.25  BV=3.66
    {8335,1312,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.36  BV=3.55
    {8335,1408,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.46  BV=3.45
    {8335,1504,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.57  BV=3.34
    {8335,1600,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.66  BV=3.25
    {8335,1728,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.77  BV=3.14
    {8335,1856,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.86  BV=3.05
    {8335,1984,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=5.97  BV=2.94
    {8335,2144,1024, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=6.07  BV=2.84
    {8335,2272,1032, 0, 0, 0},  //TV = 6.91(661 lines)  AV=2.00  SV=6.16  BV=2.75
    {16669,1216,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.25  BV=2.66
    {16669,1312,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.36  BV=2.55
    {16669,1408,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.46  BV=2.45
    {16669,1504,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.55  BV=2.35
    {16669,1600,1032, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.66  BV=2.25
    {16669,1728,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.75  BV=2.15
    {16669,1856,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.86  BV=2.05
    {16669,1984,1032, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=5.97  BV=1.94
    {16669,2112,1032, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.06  BV=1.85
    {16669,2272,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.15  BV=1.76
    {16669,2432,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.25  BV=1.66
    {16669,2624,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.36  BV=1.55
    {16669,2816,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.46  BV=1.45
    {16669,3008,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.55  BV=1.35
    {16668,3232,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.66  BV=1.25
    {16668,3456,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.75  BV=1.15
    {16668,3712,1024, 0, 0, 0},  //TV = 5.91(1322 lines)  AV=2.00  SV=6.86  BV=1.05
    {25002,2656,1024, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=6.38  BV=0.95
    {25002,2848,1024, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=6.48  BV=0.85
    {25002,3040,1024, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=6.57  BV=0.75
    {25002,3264,1024, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=6.67  BV=0.65
    {25002,3488,1024, 0, 0, 0},  //TV = 5.32(1983 lines)  AV=2.00  SV=6.77  BV=0.55
    {33299,2816,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.46  BV=0.45
    {33299,3008,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.55  BV=0.35
    {33299,3232,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.66  BV=0.25
    {33299,3456,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.75  BV=0.15
    {33299,3712,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.86  BV=0.05
    {33299,3968,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33299,4288,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33299,4576,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33299,4896,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33299,5248,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33299,5632,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33299,6016,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33299,6496,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.67  BV=-0.76
    {33299,6976,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.77  BV=-0.86
    {33299,7456,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33299,8000,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=7.97  BV=-1.06
    {33299,8544,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33299,9152,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33299,9824,1024, 0, 0, 0},  //TV = 4.91(2641 lines)  AV=2.00  SV=8.26  BV=-1.35
    {33299,10240,1024, 0, 0, 0},  /* TV = 4.91(2641 lines)  AV=2.00  SV=8.32  BV=-1.41 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sVideo2PLineTable_50Hz =
{
{
    {89,1344,1024, 0, 0, 0},  //TV = 13.46(7 lines)  AV=2.00  SV=5.39  BV=10.06
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(8 lines)  AV=2.00  SV=5.25  BV=10.03 */
    {101,1280,1032, 0, 0, 0},  //TV = 13.27(8 lines)  AV=2.00  SV=5.33  BV=9.94
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(9 lines)  AV=2.00  SV=5.29  BV=9.81
    {127,1184,1032, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.22  BV=9.72
    {127,1248,1040, 0, 0, 0},  //TV = 12.94(10 lines)  AV=2.00  SV=5.31  BV=9.64
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(11 lines)  AV=2.00  SV=5.26  BV=9.55
    {152,1216,1024, 0, 0, 0},  //TV = 12.68(12 lines)  AV=2.00  SV=5.25  BV=9.44
    {164,1216,1024, 0, 0, 0},  //TV = 12.57(13 lines)  AV=2.00  SV=5.25  BV=9.33
    {177,1216,1024, 0, 0, 0},  //TV = 12.46(14 lines)  AV=2.00  SV=5.25  BV=9.22
    {190,1216,1024, 0, 0, 0},  //TV = 12.36(15 lines)  AV=2.00  SV=5.25  BV=9.11
    {190,1248,1040, 0, 0, 0},  /* TV = 12.36(15 lines)  AV=2.00  SV=5.31  BV=9.05 */
    {215,1184,1040, 0, 0, 0},  //TV = 12.18(17 lines)  AV=2.00  SV=5.23  BV=8.95
    {227,1216,1024, 0, 0, 0},  //TV = 12.11(18 lines)  AV=2.00  SV=5.25  BV=8.86
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(19 lines)  AV=2.00  SV=5.27  BV=8.75
    {265,1184,1040, 0, 0, 0},  //TV = 11.88(21 lines)  AV=2.00  SV=5.23  BV=8.65
    {278,1216,1032, 0, 0, 0},  //TV = 11.81(22 lines)  AV=2.00  SV=5.26  BV=8.55
    {303,1184,1040, 0, 0, 0},  //TV = 11.69(24 lines)  AV=2.00  SV=5.23  BV=8.46
    {328,1184,1032, 0, 0, 0},  //TV = 11.57(26 lines)  AV=2.00  SV=5.22  BV=8.35
    {341,1216,1040, 0, 0, 0},  //TV = 11.52(27 lines)  AV=2.00  SV=5.27  BV=8.25
    {366,1216,1032, 0, 0, 0},  //TV = 11.42(29 lines)  AV=2.00  SV=5.26  BV=8.16
    {404,1184,1032, 0, 0, 0},  //TV = 11.27(32 lines)  AV=2.00  SV=5.22  BV=8.05
    {429,1184,1040, 0, 0, 0},  //TV = 11.19(34 lines)  AV=2.00  SV=5.23  BV=7.95
    {454,1216,1024, 0, 0, 0},  //TV = 11.11(36 lines)  AV=2.00  SV=5.25  BV=7.86
    {492,1216,1024, 0, 0, 0},  //TV = 10.99(39 lines)  AV=2.00  SV=5.25  BV=7.74
    {530,1184,1040, 0, 0, 0},  //TV = 10.88(42 lines)  AV=2.00  SV=5.23  BV=7.65
    {568,1184,1040, 0, 0, 0},  //TV = 10.78(45 lines)  AV=2.00  SV=5.23  BV=7.55
    {606,1184,1040, 0, 0, 0},  //TV = 10.69(48 lines)  AV=2.00  SV=5.23  BV=7.46
    {656,1184,1032, 0, 0, 0},  //TV = 10.57(52 lines)  AV=2.00  SV=5.22  BV=7.35
    {694,1216,1024, 0, 0, 0},  //TV = 10.49(55 lines)  AV=2.00  SV=5.25  BV=7.24
    {744,1216,1024, 0, 0, 0},  //TV = 10.39(59 lines)  AV=2.00  SV=5.25  BV=7.14
    {795,1216,1024, 0, 0, 0},  //TV = 10.30(63 lines)  AV=2.00  SV=5.25  BV=7.05
    {858,1184,1040, 0, 0, 0},  //TV = 10.19(68 lines)  AV=2.00  SV=5.23  BV=6.95
    {921,1184,1040, 0, 0, 0},  //TV = 10.08(73 lines)  AV=2.00  SV=5.23  BV=6.85
    {997,1184,1032, 0, 0, 0},  //TV = 9.97(79 lines)  AV=2.00  SV=5.22  BV=6.75
    {1060,1184,1040, 0, 0, 0},  //TV = 9.88(84 lines)  AV=2.00  SV=5.23  BV=6.65
    {1135,1184,1040, 0, 0, 0},  //TV = 9.78(90 lines)  AV=2.00  SV=5.23  BV=6.55
    {1223,1184,1040, 0, 0, 0},  //TV = 9.68(97 lines)  AV=2.00  SV=5.23  BV=6.44
    {1299,1184,1040, 0, 0, 0},  //TV = 9.59(103 lines)  AV=2.00  SV=5.23  BV=6.36
    {1400,1184,1040, 0, 0, 0},  //TV = 9.48(111 lines)  AV=2.00  SV=5.23  BV=6.25
    {1513,1184,1032, 0, 0, 0},  //TV = 9.37(120 lines)  AV=2.00  SV=5.22  BV=6.15
    {1614,1184,1032, 0, 0, 0},  //TV = 9.28(128 lines)  AV=2.00  SV=5.22  BV=6.05
    {1715,1184,1040, 0, 0, 0},  //TV = 9.19(136 lines)  AV=2.00  SV=5.23  BV=5.96
    {1854,1184,1032, 0, 0, 0},  //TV = 9.08(147 lines)  AV=2.00  SV=5.22  BV=5.85
    {1980,1184,1040, 0, 0, 0},  //TV = 8.98(157 lines)  AV=2.00  SV=5.23  BV=5.75
    {2131,1184,1040, 0, 0, 0},  //TV = 8.87(169 lines)  AV=2.00  SV=5.23  BV=5.64
    {2283,1184,1032, 0, 0, 0},  //TV = 8.77(181 lines)  AV=2.00  SV=5.22  BV=5.55
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(194 lines)  AV=2.00  SV=5.22  BV=5.45
    {2636,1184,1032, 0, 0, 0},  //TV = 8.57(209 lines)  AV=2.00  SV=5.22  BV=5.35
    {2812,1184,1032, 0, 0, 0},  //TV = 8.47(223 lines)  AV=2.00  SV=5.22  BV=5.25
    {3014,1184,1032, 0, 0, 0},  //TV = 8.37(239 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(256 lines)  AV=2.00  SV=5.22  BV=5.05
    {3455,1184,1032, 0, 0, 0},  //TV = 8.18(274 lines)  AV=2.00  SV=5.22  BV=4.96
    {3720,1184,1032, 0, 0, 0},  //TV = 8.07(295 lines)  AV=2.00  SV=5.22  BV=4.85
    {3985,1184,1032, 0, 0, 0},  //TV = 7.97(316 lines)  AV=2.00  SV=5.22  BV=4.75
    {4262,1184,1032, 0, 0, 0},  //TV = 7.87(338 lines)  AV=2.00  SV=5.22  BV=4.65
    {4565,1184,1032, 0, 0, 0},  //TV = 7.78(362 lines)  AV=2.00  SV=5.22  BV=4.55
    {4918,1184,1032, 0, 0, 0},  //TV = 7.67(390 lines)  AV=2.00  SV=5.22  BV=4.45
    {5233,1184,1032, 0, 0, 0},  //TV = 7.58(415 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(447 lines)  AV=2.00  SV=5.22  BV=4.25
    {6040,1184,1032, 0, 0, 0},  //TV = 7.37(479 lines)  AV=2.00  SV=5.22  BV=4.15
    {6468,1184,1032, 0, 0, 0},  //TV = 7.27(513 lines)  AV=2.00  SV=5.22  BV=4.05
    {6922,1184,1032, 0, 0, 0},  //TV = 7.17(549 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(588 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(630 lines)  AV=2.00  SV=5.22  BV=3.76
    {8511,1184,1032, 0, 0, 0},  //TV = 6.88(675 lines)  AV=2.00  SV=5.22  BV=3.66
    {9116,1184,1032, 0, 0, 0},  //TV = 6.78(723 lines)  AV=2.00  SV=5.22  BV=3.56
    {9772,1184,1032, 0, 0, 0},  //TV = 6.68(775 lines)  AV=2.00  SV=5.22  BV=3.46
    {9999,1248,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.29  BV=3.36
    {9999,1344,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.39  BV=3.25
    {9999,1440,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.49  BV=3.15
    {9999,1536,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.60  BV=3.05
    {9999,1664,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.70  BV=2.94
    {9999,1760,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.79  BV=2.85
    {9999,1888,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=5.89  BV=2.75
    {9999,2048,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.00  BV=2.64
    {9999,2176,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.09  BV=2.56
    {9999,2336,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.19  BV=2.45
    {9999,2496,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.30  BV=2.35
    {9999,2688,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.39  BV=2.25
    {9999,2880,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.49  BV=2.15
    {9999,3072,1032, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.60  BV=2.05
    {9999,3328,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.70  BV=1.94
    {9999,3552,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.79  BV=1.85
    {9999,3808,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.89  BV=1.75
    {9999,4064,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=6.99  BV=1.66
    {9999,4384,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=7.10  BV=1.55
    {9999,4672,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=7.19  BV=1.45
    {9999,5024,1024, 0, 0, 0},  //TV = 6.64(793 lines)  AV=2.00  SV=7.29  BV=1.35
    {19997,2688,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.39  BV=1.25
    {19997,2880,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.49  BV=1.15
    {19997,3104,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.60  BV=1.04
    {19997,3328,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.70  BV=0.94
    {19997,3552,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.79  BV=0.85
    {19997,3808,1024, 0, 0, 0},  //TV = 5.64(1586 lines)  AV=2.00  SV=6.89  BV=0.75
    {29995,2720,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.41  BV=0.65
    {29995,2912,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.51  BV=0.55
    {29995,3136,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.61  BV=0.44
    {29995,3360,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.71  BV=0.34
    {29995,3584,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.81  BV=0.25
    {29995,3840,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=6.91  BV=0.15
    {29995,4128,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.01  BV=0.05
    {29995,4448,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29995,4736,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29995,5088,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29995,5440,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29995,5824,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29995,6240,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29995,6688,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29995,7200,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.81  BV=-0.75
    {29995,7744,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29995,8288,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29995,8864,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29995,9504,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29995,10176,1024, 0, 0, 0},  //TV = 5.06(2379 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29995,10240,1024, 0, 0, 0},  /* TV = 5.06(2379 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29995,10240,1024, 0, 0, 0},  /* TV = 5.06(2379 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Video2AutoTable =
{
    AETABLE_VIDEO2_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideo2PLineTable_60Hz,
    sVideo2PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCustom1PLineTable_60Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8324,1216,1040, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.27  BV=3.64
    {8324,1312,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.37  BV=3.54
    {8324,1408,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.46  BV=3.45
    {8324,1504,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.55  BV=3.35
    {8324,1600,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.66  BV=3.25
    {8324,1728,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.77  BV=3.14
    {8324,1856,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.87  BV=3.04
    {8324,1984,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.97  BV=2.94
    {8324,2144,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.07  BV=2.84
    {8324,2272,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.16  BV=2.75
    {16667,1216,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.25  BV=2.66
    {16667,1312,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.36  BV=2.55
    {16667,1408,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.46  BV=2.45
    {16667,1504,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.55  BV=2.35
    {16667,1600,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.66  BV=2.25
    {16667,1728,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.75  BV=2.15
    {16667,1856,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.86  BV=2.05
    {16667,1984,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.97  BV=1.94
    {16667,2112,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.06  BV=1.85
    {16667,2272,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.15  BV=1.76
    {16667,2432,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.25  BV=1.66
    {16667,2624,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.36  BV=1.55
    {16667,2816,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.46  BV=1.45
    {16667,3008,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.55  BV=1.35
    {16667,3232,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.66  BV=1.25
    {16667,3456,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.75  BV=1.15
    {16667,3712,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.86  BV=1.05
    {24990,2656,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.38  BV=0.95
    {24990,2848,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.48  BV=0.85
    {24990,3040,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.57  BV=0.75
    {24990,3264,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.67  BV=0.65
    {24990,3488,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.77  BV=0.55
    {33333,2816,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.46  BV=0.45
    {33333,3008,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.55  BV=0.35
    {33333,3232,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.66  BV=0.25
    {33333,3456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.75  BV=0.15
    {33333,3712,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.86  BV=0.05
    {33333,3968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33333,4288,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33333,4576,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33333,4896,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33333,5248,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33333,5632,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33333,6016,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33333,6464,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33333,6944,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33333,7456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33333,7968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33333,8544,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33333,9152,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33333,9824,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33333,10240,1024, 0, 0, 0},  /* TV = 4.91(1686 lines)  AV=2.00  SV=8.32  BV=-1.42 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCustom1PLineTable_50Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8502,1184,1032, 0, 0, 0},  //TV = 6.88(430 lines)  AV=2.00  SV=5.22  BV=3.66
    {9114,1184,1032, 0, 0, 0},  //TV = 6.78(461 lines)  AV=2.00  SV=5.22  BV=3.56
    {9767,1184,1032, 0, 0, 0},  //TV = 6.68(494 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.29  BV=1.35
    {20008,2688,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.39  BV=1.25
    {20008,2880,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.49  BV=1.15
    {20008,3104,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.60  BV=1.04
    {20008,3328,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.70  BV=0.94
    {20008,3552,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.79  BV=0.85
    {20008,3808,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.89  BV=0.75
    {29992,2720,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.41  BV=0.65
    {29992,2912,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.51  BV=0.55
    {29992,3136,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.61  BV=0.44
    {29992,3360,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.71  BV=0.35
    {29992,3584,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.81  BV=0.25
    {29992,3840,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.91  BV=0.15
    {29992,4128,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.01  BV=0.05
    {29992,4448,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29992,4736,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29992,5088,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29992,5440,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29992,5824,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29992,6240,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29992,6688,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29992,7232,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.82  BV=-0.76
    {29992,7744,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29992,8288,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29992,8864,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29992,9504,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29992,10176,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Custom1AutoTable =
{
    AETABLE_CUSTOM1_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom1PLineTable_60Hz,
    sCustom1PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCustom2PLineTable_60Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8324,1216,1040, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.27  BV=3.64
    {8324,1312,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.37  BV=3.54
    {8324,1408,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.46  BV=3.45
    {8324,1504,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.55  BV=3.35
    {8324,1600,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.66  BV=3.25
    {8324,1728,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.77  BV=3.14
    {8324,1856,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.87  BV=3.04
    {8324,1984,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.97  BV=2.94
    {8324,2144,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.07  BV=2.84
    {8324,2272,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.16  BV=2.75
    {16667,1216,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.25  BV=2.66
    {16667,1312,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.36  BV=2.55
    {16667,1408,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.46  BV=2.45
    {16667,1504,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.55  BV=2.35
    {16667,1600,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.66  BV=2.25
    {16667,1728,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.75  BV=2.15
    {16667,1856,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.86  BV=2.05
    {16667,1984,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.97  BV=1.94
    {16667,2112,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.06  BV=1.85
    {16667,2272,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.15  BV=1.76
    {16667,2432,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.25  BV=1.66
    {16667,2624,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.36  BV=1.55
    {16667,2816,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.46  BV=1.45
    {16667,3008,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.55  BV=1.35
    {16667,3232,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.66  BV=1.25
    {16667,3456,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.75  BV=1.15
    {16667,3712,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.86  BV=1.05
    {24990,2656,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.38  BV=0.95
    {24990,2848,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.48  BV=0.85
    {24990,3040,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.57  BV=0.75
    {24990,3264,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.67  BV=0.65
    {24990,3488,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.77  BV=0.55
    {33333,2816,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.46  BV=0.45
    {33333,3008,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.55  BV=0.35
    {33333,3232,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.66  BV=0.25
    {33333,3456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.75  BV=0.15
    {33333,3712,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.86  BV=0.05
    {33333,3968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33333,4288,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33333,4576,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33333,4896,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33333,5248,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33333,5632,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33333,6016,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33333,6464,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33333,6944,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33333,7456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33333,7968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33333,8544,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33333,9152,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33333,9824,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33333,10240,1024, 0, 0, 0},  /* TV = 4.91(1686 lines)  AV=2.00  SV=8.32  BV=-1.42 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCustom2PLineTable_50Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8502,1184,1032, 0, 0, 0},  //TV = 6.88(430 lines)  AV=2.00  SV=5.22  BV=3.66
    {9114,1184,1032, 0, 0, 0},  //TV = 6.78(461 lines)  AV=2.00  SV=5.22  BV=3.56
    {9767,1184,1032, 0, 0, 0},  //TV = 6.68(494 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.29  BV=1.35
    {20008,2688,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.39  BV=1.25
    {20008,2880,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.49  BV=1.15
    {20008,3104,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.60  BV=1.04
    {20008,3328,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.70  BV=0.94
    {20008,3552,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.79  BV=0.85
    {20008,3808,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.89  BV=0.75
    {29992,2720,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.41  BV=0.65
    {29992,2912,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.51  BV=0.55
    {29992,3136,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.61  BV=0.44
    {29992,3360,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.71  BV=0.35
    {29992,3584,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.81  BV=0.25
    {29992,3840,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.91  BV=0.15
    {29992,4128,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.01  BV=0.05
    {29992,4448,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29992,4736,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29992,5088,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29992,5440,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29992,5824,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29992,6240,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29992,6688,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29992,7232,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.82  BV=-0.76
    {29992,7744,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29992,8288,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29992,8864,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29992,9504,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29992,10176,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Custom2AutoTable =
{
    AETABLE_CUSTOM2_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom2PLineTable_60Hz,
    sCustom2PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCustom3PLineTable_60Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8324,1216,1040, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.27  BV=3.64
    {8324,1312,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.37  BV=3.54
    {8324,1408,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.46  BV=3.45
    {8324,1504,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.55  BV=3.35
    {8324,1600,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.66  BV=3.25
    {8324,1728,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.77  BV=3.14
    {8324,1856,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.87  BV=3.04
    {8324,1984,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.97  BV=2.94
    {8324,2144,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.07  BV=2.84
    {8324,2272,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.16  BV=2.75
    {16667,1216,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.25  BV=2.66
    {16667,1312,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.36  BV=2.55
    {16667,1408,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.46  BV=2.45
    {16667,1504,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.55  BV=2.35
    {16667,1600,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.66  BV=2.25
    {16667,1728,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.75  BV=2.15
    {16667,1856,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.86  BV=2.05
    {16667,1984,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.97  BV=1.94
    {16667,2112,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.06  BV=1.85
    {16667,2272,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.15  BV=1.76
    {16667,2432,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.25  BV=1.66
    {16667,2624,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.36  BV=1.55
    {16667,2816,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.46  BV=1.45
    {16667,3008,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.55  BV=1.35
    {16667,3232,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.66  BV=1.25
    {16667,3456,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.75  BV=1.15
    {16667,3712,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.86  BV=1.05
    {24990,2656,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.38  BV=0.95
    {24990,2848,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.48  BV=0.85
    {24990,3040,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.57  BV=0.75
    {24990,3264,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.67  BV=0.65
    {24990,3488,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.77  BV=0.55
    {33333,2816,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.46  BV=0.45
    {33333,3008,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.55  BV=0.35
    {33333,3232,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.66  BV=0.25
    {33333,3456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.75  BV=0.15
    {33333,3712,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.86  BV=0.05
    {33333,3968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33333,4288,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33333,4576,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33333,4896,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33333,5248,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33333,5632,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33333,6016,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33333,6464,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33333,6944,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33333,7456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33333,7968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33333,8544,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33333,9152,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33333,9824,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33333,10240,1024, 0, 0, 0},  /* TV = 4.91(1686 lines)  AV=2.00  SV=8.32  BV=-1.42 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCustom3PLineTable_50Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8502,1184,1032, 0, 0, 0},  //TV = 6.88(430 lines)  AV=2.00  SV=5.22  BV=3.66
    {9114,1184,1032, 0, 0, 0},  //TV = 6.78(461 lines)  AV=2.00  SV=5.22  BV=3.56
    {9767,1184,1032, 0, 0, 0},  //TV = 6.68(494 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.29  BV=1.35
    {20008,2688,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.39  BV=1.25
    {20008,2880,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.49  BV=1.15
    {20008,3104,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.60  BV=1.04
    {20008,3328,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.70  BV=0.94
    {20008,3552,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.79  BV=0.85
    {20008,3808,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.89  BV=0.75
    {29992,2720,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.41  BV=0.65
    {29992,2912,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.51  BV=0.55
    {29992,3136,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.61  BV=0.44
    {29992,3360,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.71  BV=0.35
    {29992,3584,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.81  BV=0.25
    {29992,3840,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.91  BV=0.15
    {29992,4128,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.01  BV=0.05
    {29992,4448,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29992,4736,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29992,5088,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29992,5440,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29992,5824,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29992,6240,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29992,6688,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29992,7232,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.82  BV=-0.76
    {29992,7744,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29992,8288,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29992,8864,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29992,9504,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29992,10176,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Custom3AutoTable =
{
    AETABLE_CUSTOM3_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom3PLineTable_60Hz,
    sCustom3PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCustom4PLineTable_60Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8324,1216,1040, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.27  BV=3.64
    {8324,1312,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.37  BV=3.54
    {8324,1408,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.46  BV=3.45
    {8324,1504,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.55  BV=3.35
    {8324,1600,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.66  BV=3.25
    {8324,1728,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.77  BV=3.14
    {8324,1856,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.87  BV=3.04
    {8324,1984,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.97  BV=2.94
    {8324,2144,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.07  BV=2.84
    {8324,2272,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.16  BV=2.75
    {16667,1216,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.25  BV=2.66
    {16667,1312,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.36  BV=2.55
    {16667,1408,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.46  BV=2.45
    {16667,1504,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.55  BV=2.35
    {16667,1600,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.66  BV=2.25
    {16667,1728,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.75  BV=2.15
    {16667,1856,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.86  BV=2.05
    {16667,1984,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.97  BV=1.94
    {16667,2112,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.06  BV=1.85
    {16667,2272,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.15  BV=1.76
    {16667,2432,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.25  BV=1.66
    {16667,2624,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.36  BV=1.55
    {16667,2816,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.46  BV=1.45
    {16667,3008,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.55  BV=1.35
    {16667,3232,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.66  BV=1.25
    {16667,3456,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.75  BV=1.15
    {16667,3712,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.86  BV=1.05
    {24990,2656,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.38  BV=0.95
    {24990,2848,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.48  BV=0.85
    {24990,3040,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.57  BV=0.75
    {24990,3264,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.67  BV=0.65
    {24990,3488,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.77  BV=0.55
    {33333,2816,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.46  BV=0.45
    {33333,3008,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.55  BV=0.35
    {33333,3232,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.66  BV=0.25
    {33333,3456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.75  BV=0.15
    {33333,3712,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.86  BV=0.05
    {33333,3968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33333,4288,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33333,4576,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33333,4896,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33333,5248,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33333,5632,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33333,6016,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33333,6464,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33333,6944,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33333,7456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33333,7968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33333,8544,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33333,9152,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33333,9824,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33333,10240,1024, 0, 0, 0},  /* TV = 4.91(1686 lines)  AV=2.00  SV=8.32  BV=-1.42 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCustom4PLineTable_50Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8502,1184,1032, 0, 0, 0},  //TV = 6.88(430 lines)  AV=2.00  SV=5.22  BV=3.66
    {9114,1184,1032, 0, 0, 0},  //TV = 6.78(461 lines)  AV=2.00  SV=5.22  BV=3.56
    {9767,1184,1032, 0, 0, 0},  //TV = 6.68(494 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.29  BV=1.35
    {20008,2688,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.39  BV=1.25
    {20008,2880,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.49  BV=1.15
    {20008,3104,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.60  BV=1.04
    {20008,3328,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.70  BV=0.94
    {20008,3552,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.79  BV=0.85
    {20008,3808,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.89  BV=0.75
    {29992,2720,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.41  BV=0.65
    {29992,2912,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.51  BV=0.55
    {29992,3136,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.61  BV=0.44
    {29992,3360,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.71  BV=0.35
    {29992,3584,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.81  BV=0.25
    {29992,3840,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.91  BV=0.15
    {29992,4128,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.01  BV=0.05
    {29992,4448,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29992,4736,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29992,5088,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29992,5440,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29992,5824,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29992,6240,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29992,6688,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29992,7232,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.82  BV=-0.76
    {29992,7744,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29992,8288,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29992,8864,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29992,9504,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29992,10176,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Custom4AutoTable =
{
    AETABLE_CUSTOM4_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom4PLineTable_60Hz,
    sCustom4PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCustom5PLineTable_60Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8324,1216,1040, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.27  BV=3.64
    {8324,1312,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.37  BV=3.54
    {8324,1408,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.46  BV=3.45
    {8324,1504,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.55  BV=3.35
    {8324,1600,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.66  BV=3.25
    {8324,1728,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.77  BV=3.14
    {8324,1856,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.87  BV=3.04
    {8324,1984,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=5.97  BV=2.94
    {8324,2144,1024, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.07  BV=2.84
    {8324,2272,1032, 0, 0, 0},  //TV = 6.91(421 lines)  AV=2.00  SV=6.16  BV=2.75
    {16667,1216,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.25  BV=2.66
    {16667,1312,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.36  BV=2.55
    {16667,1408,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.46  BV=2.45
    {16667,1504,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.55  BV=2.35
    {16667,1600,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.66  BV=2.25
    {16667,1728,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.75  BV=2.15
    {16667,1856,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.86  BV=2.05
    {16667,1984,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=5.97  BV=1.94
    {16667,2112,1032, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.06  BV=1.85
    {16667,2272,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.15  BV=1.76
    {16667,2432,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.25  BV=1.66
    {16667,2624,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.36  BV=1.55
    {16667,2816,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.46  BV=1.45
    {16667,3008,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.55  BV=1.35
    {16667,3232,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.66  BV=1.25
    {16667,3456,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.75  BV=1.15
    {16667,3712,1024, 0, 0, 0},  //TV = 5.91(843 lines)  AV=2.00  SV=6.86  BV=1.05
    {24990,2656,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.38  BV=0.95
    {24990,2848,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.48  BV=0.85
    {24990,3040,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.57  BV=0.75
    {24990,3264,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.67  BV=0.65
    {24990,3488,1024, 0, 0, 0},  //TV = 5.32(1264 lines)  AV=2.00  SV=6.77  BV=0.55
    {33333,2816,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.46  BV=0.45
    {33333,3008,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.55  BV=0.35
    {33333,3232,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.66  BV=0.25
    {33333,3456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.75  BV=0.15
    {33333,3712,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.86  BV=0.05
    {33333,3968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33333,4288,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.07  BV=-0.16
    {33333,4576,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33333,4896,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33333,5248,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33333,5632,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33333,6016,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33333,6464,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33333,6944,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33333,7456,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.86  BV=-0.96
    {33333,7968,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33333,8544,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33333,9152,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33333,9824,1024, 0, 0, 0},  //TV = 4.91(1686 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33333,10240,1024, 0, 0, 0},  /* TV = 4.91(1686 lines)  AV=2.00  SV=8.32  BV=-1.42 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCustom5PLineTable_50Hz =
{
{
    {99,1216,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.25  BV=10.05
    {99,1248,1024, 0, 0, 0},  /* TV = 13.30(5 lines)  AV=2.00  SV=5.29  BV=10.02 */
    {99,1312,1024, 0, 0, 0},  //TV = 13.30(5 lines)  AV=2.00  SV=5.36  BV=9.94
    {119,1184,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.22  BV=9.82
    {119,1280,1024, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.32  BV=9.71
    {119,1344,1032, 0, 0, 0},  //TV = 13.04(6 lines)  AV=2.00  SV=5.40  BV=9.63
    {139,1216,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.26  BV=9.55
    {139,1312,1032, 0, 0, 0},  //TV = 12.81(7 lines)  AV=2.00  SV=5.37  BV=9.44
    {159,1248,1024, 0, 0, 0},  //TV = 12.62(8 lines)  AV=2.00  SV=5.29  BV=9.33
    {178,1184,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.23  BV=9.22
    {178,1280,1040, 0, 0, 0},  //TV = 12.46(9 lines)  AV=2.00  SV=5.34  BV=9.11
    {198,1216,1024, 0, 0, 0},  /* TV = 12.30(10 lines)  AV=2.00  SV=5.25  BV=9.05 */
    {198,1312,1024, 0, 0, 0},  //TV = 12.30(10 lines)  AV=2.00  SV=5.36  BV=8.94
    {218,1280,1024, 0, 0, 0},  //TV = 12.16(11 lines)  AV=2.00  SV=5.32  BV=8.84
    {238,1248,1024, 0, 0, 0},  //TV = 12.04(12 lines)  AV=2.00  SV=5.29  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(13 lines)  AV=2.00  SV=5.27  BV=8.65
    {277,1216,1040, 0, 0, 0},  //TV = 11.82(14 lines)  AV=2.00  SV=5.27  BV=8.55
    {297,1216,1040, 0, 0, 0},  //TV = 11.72(15 lines)  AV=2.00  SV=5.27  BV=8.45
    {317,1216,1040, 0, 0, 0},  //TV = 11.62(16 lines)  AV=2.00  SV=5.27  BV=8.35
    {337,1248,1024, 0, 0, 0},  //TV = 11.53(17 lines)  AV=2.00  SV=5.29  BV=8.25
    {376,1184,1032, 0, 0, 0},  //TV = 11.38(19 lines)  AV=2.00  SV=5.22  BV=8.16
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(20 lines)  AV=2.00  SV=5.25  BV=8.05
    {416,1248,1024, 0, 0, 0},  //TV = 11.23(21 lines)  AV=2.00  SV=5.29  BV=7.95
    {455,1216,1024, 0, 0, 0},  //TV = 11.10(23 lines)  AV=2.00  SV=5.25  BV=7.85
    {495,1184,1040, 0, 0, 0},  //TV = 10.98(25 lines)  AV=2.00  SV=5.23  BV=7.75
    {515,1216,1040, 0, 0, 0},  //TV = 10.92(26 lines)  AV=2.00  SV=5.27  BV=7.65
    {554,1216,1040, 0, 0, 0},  //TV = 10.82(28 lines)  AV=2.00  SV=5.27  BV=7.55
    {594,1216,1040, 0, 0, 0},  //TV = 10.72(30 lines)  AV=2.00  SV=5.27  BV=7.45
    {633,1216,1040, 0, 0, 0},  //TV = 10.63(32 lines)  AV=2.00  SV=5.27  BV=7.36
    {692,1216,1024, 0, 0, 0},  //TV = 10.50(35 lines)  AV=2.00  SV=5.25  BV=7.25
    {732,1216,1032, 0, 0, 0},  //TV = 10.42(37 lines)  AV=2.00  SV=5.26  BV=7.16
    {791,1216,1024, 0, 0, 0},  //TV = 10.30(40 lines)  AV=2.00  SV=5.25  BV=7.06
    {870,1184,1032, 0, 0, 0},  //TV = 10.17(44 lines)  AV=2.00  SV=5.22  BV=6.95
    {930,1184,1032, 0, 0, 0},  //TV = 10.07(47 lines)  AV=2.00  SV=5.22  BV=6.85
    {989,1184,1040, 0, 0, 0},  //TV = 9.98(50 lines)  AV=2.00  SV=5.23  BV=6.75
    {1068,1184,1040, 0, 0, 0},  //TV = 9.87(54 lines)  AV=2.00  SV=5.23  BV=6.64
    {1127,1216,1024, 0, 0, 0},  //TV = 9.79(57 lines)  AV=2.00  SV=5.25  BV=6.55
    {1206,1216,1024, 0, 0, 0},  //TV = 9.70(61 lines)  AV=2.00  SV=5.25  BV=6.45
    {1305,1184,1040, 0, 0, 0},  //TV = 9.58(66 lines)  AV=2.00  SV=5.23  BV=6.35
    {1384,1216,1024, 0, 0, 0},  //TV = 9.50(70 lines)  AV=2.00  SV=5.25  BV=6.25
    {1503,1184,1032, 0, 0, 0},  //TV = 9.38(76 lines)  AV=2.00  SV=5.22  BV=6.16
    {1602,1184,1040, 0, 0, 0},  //TV = 9.29(81 lines)  AV=2.00  SV=5.23  BV=6.05
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(87 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(93 lines)  AV=2.00  SV=5.23  BV=5.86
    {1977,1184,1040, 0, 0, 0},  //TV = 8.98(100 lines)  AV=2.00  SV=5.23  BV=5.75
    {2116,1184,1040, 0, 0, 0},  //TV = 8.88(107 lines)  AV=2.00  SV=5.23  BV=5.65
    {2274,1184,1040, 0, 0, 0},  //TV = 8.78(115 lines)  AV=2.00  SV=5.23  BV=5.55
    {2432,1184,1040, 0, 0, 0},  //TV = 8.68(123 lines)  AV=2.00  SV=5.23  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(133 lines)  AV=2.00  SV=5.22  BV=5.35
    {2788,1184,1040, 0, 0, 0},  //TV = 8.49(141 lines)  AV=2.00  SV=5.23  BV=5.25
    {2986,1184,1040, 0, 0, 0},  //TV = 8.39(151 lines)  AV=2.00  SV=5.23  BV=5.16
    {3223,1184,1032, 0, 0, 0},  //TV = 8.28(163 lines)  AV=2.00  SV=5.22  BV=5.06
    {3440,1184,1040, 0, 0, 0},  //TV = 8.18(174 lines)  AV=2.00  SV=5.23  BV=4.95
    {3717,1184,1032, 0, 0, 0},  //TV = 8.07(188 lines)  AV=2.00  SV=5.22  BV=4.85
    {3974,1184,1032, 0, 0, 0},  //TV = 7.98(201 lines)  AV=2.00  SV=5.22  BV=4.75
    {4251,1184,1040, 0, 0, 0},  //TV = 7.88(215 lines)  AV=2.00  SV=5.23  BV=4.65
    {4567,1184,1032, 0, 0, 0},  //TV = 7.77(231 lines)  AV=2.00  SV=5.22  BV=4.55
    {4884,1184,1032, 0, 0, 0},  //TV = 7.68(247 lines)  AV=2.00  SV=5.22  BV=4.46
    {5259,1184,1032, 0, 0, 0},  //TV = 7.57(266 lines)  AV=2.00  SV=5.22  BV=4.35
    {5635,1184,1032, 0, 0, 0},  //TV = 7.47(285 lines)  AV=2.00  SV=5.22  BV=4.25
    {6030,1184,1032, 0, 0, 0},  //TV = 7.37(305 lines)  AV=2.00  SV=5.22  BV=4.15
    {6465,1184,1032, 0, 0, 0},  //TV = 7.27(327 lines)  AV=2.00  SV=5.22  BV=4.05
    {6920,1184,1032, 0, 0, 0},  //TV = 7.18(350 lines)  AV=2.00  SV=5.22  BV=3.95
    {7414,1184,1032, 0, 0, 0},  //TV = 7.08(375 lines)  AV=2.00  SV=5.22  BV=3.85
    {7948,1184,1032, 0, 0, 0},  //TV = 6.98(402 lines)  AV=2.00  SV=5.22  BV=3.75
    {8502,1184,1032, 0, 0, 0},  //TV = 6.88(430 lines)  AV=2.00  SV=5.22  BV=3.66
    {9114,1184,1032, 0, 0, 0},  //TV = 6.78(461 lines)  AV=2.00  SV=5.22  BV=3.56
    {9767,1184,1032, 0, 0, 0},  //TV = 6.68(494 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(506 lines)  AV=2.00  SV=7.29  BV=1.35
    {20008,2688,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.39  BV=1.25
    {20008,2880,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.49  BV=1.15
    {20008,3104,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.60  BV=1.04
    {20008,3328,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.70  BV=0.94
    {20008,3552,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.79  BV=0.85
    {20008,3808,1024, 0, 0, 0},  //TV = 5.64(1012 lines)  AV=2.00  SV=6.89  BV=0.75
    {29992,2720,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.41  BV=0.65
    {29992,2912,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.51  BV=0.55
    {29992,3136,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.61  BV=0.44
    {29992,3360,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.71  BV=0.35
    {29992,3584,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.81  BV=0.25
    {29992,3840,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=6.91  BV=0.15
    {29992,4128,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.01  BV=0.05
    {29992,4448,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.12  BV=-0.06
    {29992,4736,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.21  BV=-0.15
    {29992,5088,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.31  BV=-0.25
    {29992,5440,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.41  BV=-0.35
    {29992,5824,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.51  BV=-0.45
    {29992,6240,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.61  BV=-0.55
    {29992,6688,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.71  BV=-0.65
    {29992,7232,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.82  BV=-0.76
    {29992,7744,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=7.92  BV=-0.86
    {29992,8288,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.02  BV=-0.96
    {29992,8864,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.11  BV=-1.05
    {29992,9504,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.21  BV=-1.16
    {29992,10176,1024, 0, 0, 0},  //TV = 5.06(1517 lines)  AV=2.00  SV=8.31  BV=-1.25
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {29992,10240,1024, 0, 0, 0},  /* TV = 5.06(1517 lines)  AV=2.00  SV=8.32  BV=-1.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_Custom5AutoTable =
{
    AETABLE_CUSTOM5_AUTO, //eAETableID
    117, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCustom5PLineTable_60Hz,
    sCustom5PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sVideoNightPLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12768,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {58327,12032,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.55  BV=-2.45
    {58327,12896,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.65  BV=-2.55
    {66666,12096,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.56  BV=-2.66
    {66666,12960,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.66  BV=-2.75
    {66666,13888,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.76  BV=-2.85
    {66666,14880,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.86  BV=-2.95
    {66666,15968,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.96  BV=-3.06
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {66666,16384,1144, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.16  BV=-3.25
    {66666,16384,1224, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.26  BV=-3.35
    {66666,16384,1312, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.36  BV=-3.45
    {66666,16384,1408, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.46  BV=-3.55
    {66666,16384,1504, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.55  BV=-3.65
    {66666,16384,1616, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.66  BV=-3.75
    {66666,16384,1728, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.75  BV=-3.85
    {66666,16384,1856, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.86  BV=-3.95
    {66666,16384,1992, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.96  BV=-4.05
    {66666,16384,2128, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.06  BV=-4.15
    {66666,16384,2288, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.16  BV=-4.25
    {74996,16384,2184, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=10.09  BV=-4.36
    {83335,16384,2104, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.04  BV=-4.45
    {83335,16384,2256, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.14  BV=-4.55
    {91665,16384,2200, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=10.10  BV=-4.66
    {99994,16384,2160, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.08  BV=-4.75
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sVideoNightPLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {60001,11712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60001,12544,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.56
    {70004,11520,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.49  BV=-2.66
    {70004,12352,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.59  BV=-2.76
    {70004,13248,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.69  BV=-2.86
    {70004,14176,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.79  BV=-2.95
    {70004,15200,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.89  BV=-3.06
    {70004,16288,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.16
    {70004,16384,1088, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.09  BV=-3.25
    {70004,16384,1168, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.19  BV=-3.35
    {70004,16384,1248, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.29  BV=-3.45
    {70004,16384,1336, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.38  BV=-3.55
    {70004,16384,1432, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.48  BV=-3.65
    {70004,16384,1536, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.58  BV=-3.75
    {70004,16384,1648, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.69  BV=-3.85
    {70004,16384,1768, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.79  BV=-3.95
    {70004,16384,1896, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.89  BV=-4.05
    {70004,16384,2032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.99  BV=-4.15
    {70004,16384,2184, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.09  BV=-4.26
    {70004,16384,2336, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.19  BV=-4.35
    {79997,16384,2192, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=10.10  BV=-4.45
    {90001,16384,2088, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.03  BV=-4.55
    {90001,16384,2240, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.13  BV=-4.66
    {100004,16384,2160, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.08  BV=-4.75
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_VideoNightTable =
{
    AETABLE_VIDEO_NIGHT, //eAETableID
    150, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -48, //i4MinBV
    90, //i4EffectiveMaxBV
    -10, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sVideoNightPLineTable_60Hz,
    sVideoNightPLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureISO100PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {41669,1184,1040, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.23  BV=1.35
    {41669,1280,1032, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.33  BV=1.25
    {41669,1376,1040, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.45  BV=1.14
    {49997,1216,1040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.27  BV=1.05
    {49997,1312,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.37  BV=0.95
    {58327,1216,1032, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.26  BV=0.84
    {58327,1312,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.36  BV=0.74
    {66667,1216,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.25  BV=0.66
    {66667,1312,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.36  BV=0.55
    {74996,1248,1032, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=5.30  BV=0.44
    {83326,1184,1040, 0, 0, 0},  //TV = 3.59(9063 lines)  AV=2.00  SV=5.23  BV=0.35
    {83326,1280,1032, 0, 0, 0},  //TV = 3.59(9063 lines)  AV=2.00  SV=5.33  BV=0.25
    {91665,1248,1032, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=5.30  BV=0.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureISO100PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {40004,1248,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.29  BV=1.36
    {40004,1344,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.39  BV=1.25
    {40004,1440,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.49  BV=1.15
    {49997,1216,1040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.27  BV=1.05
    {49997,1312,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.37  BV=0.95
    {49997,1408,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.47  BV=0.85
    {60001,1248,1040, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.31  BV=0.75
    {60001,1344,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.40  BV=0.66
    {70004,1248,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.29  BV=0.55
    {70004,1344,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.39  BV=0.44
    {79997,1248,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=5.29  BV=0.36
    {90001,1184,1040, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=5.23  BV=0.24
    {90001,1280,1032, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=5.33  BV=0.14
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureISO100Table =
{
    AETABLE_CAPTURE_ISO100, //eAETableID
    101, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    1, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_100, //ISO
    sCaptureISO100PLineTable_60Hz,
    sCaptureISO100PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureISO200PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {506,2048,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=6.00  BV=6.95
    {543,2048,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=6.00  BV=6.85
    {580,2048,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=6.00  BV=6.75
    {626,2048,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=6.00  BV=6.64
    {662,2048,1032, 0, 0, 0},  //TV = 10.56(72 lines)  AV=2.00  SV=6.01  BV=6.55
    {718,2016,1032, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=5.99  BV=6.46
    {764,2048,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=6.00  BV=6.35
    {819,2048,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=6.00  BV=6.25
    {883,2048,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=6.00  BV=6.15
    {947,2016,1032, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=5.99  BV=6.06
    {1012,2048,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=6.00  BV=5.95
    {1085,2048,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=6.00  BV=5.85
    {1168,2048,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=6.00  BV=5.74
    {1251,2016,1032, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=5.99  BV=5.65
    {1343,2016,1032, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=5.99  BV=5.55
    {1444,2016,1032, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=5.99  BV=5.45
    {1536,2048,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=6.00  BV=5.35
    {1646,2048,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=6.00  BV=5.25
    {1766,2048,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=6.00  BV=5.15
    {1885,2048,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=6.00  BV=5.05
    {2032,2048,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=6.00  BV=4.94
    {2170,2048,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=6.00  BV=4.85
    {2327,2048,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=6.00  BV=4.75
    {2501,2048,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=6.00  BV=4.64
    {2676,2048,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=6.00  BV=4.55
    {2869,2048,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=6.00  BV=4.45
    {3071,2048,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=6.00  BV=4.35
    {3301,2048,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=6.00  BV=4.24
    {3540,2048,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=6.00  BV=4.14
    {3788,2048,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=6.00  BV=4.04
    {4055,2048,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=6.00  BV=3.95
    {4340,2048,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=6.00  BV=3.85
    {4671,2048,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=6.00  BV=3.74
    {5002,2048,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=6.00  BV=3.64
    {5361,2048,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=6.00  BV=3.54
    {5738,2048,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=6.00  BV=3.45
    {6142,2048,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=6.00  BV=3.35
    {6583,2048,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=6.00  BV=3.25
    {7052,2048,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=6.00  BV=3.15
    {7549,2048,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=6.00  BV=3.05
    {8091,2048,1024, 0, 0, 0},  //TV = 6.95(880 lines)  AV=2.00  SV=6.00  BV=2.95
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {8330,2464,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.27  BV=2.64
    {8330,2624,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.36  BV=2.55
    {8330,2816,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.46  BV=2.45
    {8330,3008,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.55  BV=2.35
    {16669,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16669,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {16669,1856,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.86  BV=2.05
    {16669,1984,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.95  BV=1.95
    {16669,2112,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.06  BV=1.85
    {16669,2272,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.15  BV=1.76
    {16669,2432,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.25  BV=1.66
    {24999,1728,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.77  BV=1.56
    {24999,1856,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.87  BV=1.45
    {24999,2016,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.98  BV=1.34
    {24999,2144,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.08  BV=1.24
    {24999,2304,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.17  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.95  BV=0.95
    {33329,2144,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.07  BV=0.84
    {33329,2272,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.16  BV=0.75
    {41668,1952,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.93  BV=0.65
    {41668,2112,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.04  BV=0.54
    {49997,1888,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.88  BV=0.44
    {49997,2016,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.98  BV=0.34
    {49997,2144,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.08  BV=0.24
    {58327,1984,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.95  BV=0.15
    {58327,2112,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=6.04  BV=0.06
    {66666,1984,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.97  BV=-0.06
    {66666,2144,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.07  BV=-0.16
    {74996,2016,1032, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=5.99  BV=-0.25
    {83335,1952,1032, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=5.94  BV=-0.36
    {83335,2112,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=6.04  BV=-0.46
    {91665,2048,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=6.00  BV=-0.55
    {99994,2016,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=5.98  BV=-0.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureISO200PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {506,2048,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=6.00  BV=6.95
    {543,2048,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=6.00  BV=6.85
    {580,2048,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=6.00  BV=6.75
    {626,2048,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=6.00  BV=6.64
    {662,2048,1032, 0, 0, 0},  //TV = 10.56(72 lines)  AV=2.00  SV=6.01  BV=6.55
    {718,2016,1032, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=5.99  BV=6.46
    {764,2048,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=6.00  BV=6.35
    {819,2048,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=6.00  BV=6.25
    {883,2048,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=6.00  BV=6.15
    {947,2016,1032, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=5.99  BV=6.06
    {1012,2048,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=6.00  BV=5.95
    {1085,2048,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=6.00  BV=5.85
    {1168,2048,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=6.00  BV=5.74
    {1251,2016,1032, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=5.99  BV=5.65
    {1343,2016,1032, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=5.99  BV=5.55
    {1444,2016,1032, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=5.99  BV=5.45
    {1536,2048,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=6.00  BV=5.35
    {1646,2048,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=6.00  BV=5.25
    {1766,2048,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=6.00  BV=5.15
    {1885,2048,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=6.00  BV=5.05
    {2032,2048,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=6.00  BV=4.94
    {2170,2048,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=6.00  BV=4.85
    {2327,2048,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=6.00  BV=4.75
    {2501,2048,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=6.00  BV=4.64
    {2676,2048,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=6.00  BV=4.55
    {2869,2048,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=6.00  BV=4.45
    {3071,2048,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=6.00  BV=4.35
    {3301,2048,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=6.00  BV=4.24
    {3540,2048,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=6.00  BV=4.14
    {3788,2048,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=6.00  BV=4.04
    {4055,2048,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=6.00  BV=3.95
    {4340,2048,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=6.00  BV=3.85
    {4671,2048,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=6.00  BV=3.74
    {5002,2048,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=6.00  BV=3.64
    {5361,2048,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=6.00  BV=3.54
    {5738,2048,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=6.00  BV=3.45
    {6142,2048,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=6.00  BV=3.35
    {6583,2048,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=6.00  BV=3.25
    {7052,2048,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=6.00  BV=3.15
    {7549,2048,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=6.00  BV=3.05
    {8091,2048,1024, 0, 0, 0},  //TV = 6.95(880 lines)  AV=2.00  SV=6.00  BV=2.95
    {8726,2048,1024, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=6.00  BV=2.84
    {9342,2048,1024, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=6.00  BV=2.74
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {19997,1888,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.89  BV=1.75
    {19997,2016,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.99  BV=1.66
    {19997,2176,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.09  BV=1.56
    {19997,2336,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.19  BV=1.45
    {19997,2496,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.29  BV=1.36
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.92  BV=1.14
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {40004,1888,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.89  BV=0.75
    {40004,2016,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.99  BV=0.66
    {40004,2176,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.10  BV=0.55
    {49997,1888,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.88  BV=0.44
    {49997,2016,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.98  BV=0.34
    {49997,2144,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.08  BV=0.24
    {60001,1920,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.92  BV=0.14
    {60001,2048,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.01  BV=0.05
    {70004,1888,1032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.89  BV=-0.06
    {70004,2016,1032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.99  BV=-0.15
    {70004,2176,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.09  BV=-0.25
    {79997,2016,1032, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=5.99  BV=-0.34
    {90001,1920,1032, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=5.92  BV=-0.44
    {90001,2080,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=6.02  BV=-0.55
    {100004,2016,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=5.98  BV=-0.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureISO200Table =
{
    AETABLE_CAPTURE_ISO200, //eAETableID
    109, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -7, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_200, //ISO
    sCaptureISO200PLineTable_60Hz,
    sCaptureISO200PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureISO400PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {506,4096,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=7.00  BV=5.95
    {543,4064,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=6.99  BV=5.86
    {580,4096,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=7.00  BV=5.75
    {626,4096,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=7.00  BV=5.64
    {672,4064,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=6.99  BV=5.55
    {718,4096,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=7.00  BV=5.44
    {764,4096,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=7.00  BV=5.35
    {819,4096,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=7.00  BV=5.25
    {883,4096,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=7.00  BV=5.15
    {947,4064,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=6.99  BV=5.06
    {1021,4064,1024, 0, 0, 0},  //TV = 9.94(111 lines)  AV=2.00  SV=6.99  BV=4.95
    {1085,4096,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=7.00  BV=4.85
    {1168,4096,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=7.00  BV=4.74
    {1251,4064,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=6.99  BV=4.65
    {1343,4064,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=6.99  BV=4.55
    {1444,4064,1024, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=6.99  BV=4.45
    {1536,4096,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=7.00  BV=4.35
    {1646,4064,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=6.99  BV=4.26
    {1766,4096,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=7.00  BV=4.15
    {1885,4096,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=7.00  BV=4.05
    {2032,4096,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=7.00  BV=3.94
    {2170,4096,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=7.00  BV=3.85
    {2327,4096,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=7.00  BV=3.75
    {2501,4096,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=7.00  BV=3.64
    {2676,4096,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=7.00  BV=3.55
    {2869,4064,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=6.99  BV=3.46
    {3071,4064,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=6.99  BV=3.36
    {3301,4096,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=7.00  BV=3.24
    {3540,4064,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=6.99  BV=3.15
    {3788,4064,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=6.99  BV=3.06
    {4055,4064,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=6.99  BV=2.96
    {4368,4096,1024, 0, 0, 0},  //TV = 7.84(475 lines)  AV=2.00  SV=7.00  BV=2.84
    {4671,4096,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=7.00  BV=2.74
    {5002,4096,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=7.00  BV=2.64
    {5361,4096,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=7.00  BV=2.54
    {5738,4096,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=7.00  BV=2.45
    {6142,4096,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=7.00  BV=2.35
    {6583,4096,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=7.00  BV=2.25
    {7052,4096,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=7.00  BV=2.15
    {7549,4096,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=7.00  BV=2.05
    {8091,4096,1024, 0, 0, 0},  //TV = 6.95(880 lines)  AV=2.00  SV=7.00  BV=1.95
    {8330,4288,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.07  BV=1.84
    {8330,4576,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.16  BV=1.75
    {8330,4896,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.26  BV=1.65
    {8330,5248,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.36  BV=1.55
    {8330,5632,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.46  BV=1.45
    {8330,6048,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.56  BV=1.35
    {16669,3232,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.66  BV=1.25
    {16669,3456,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.75  BV=1.15
    {16669,3712,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.86  BV=1.05
    {16669,3968,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.95  BV=0.95
    {16669,4256,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.06  BV=0.85
    {16669,4576,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.16  BV=0.75
    {16669,4896,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.26  BV=0.65
    {24999,3488,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.77  BV=0.55
    {24999,3744,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.87  BV=0.45
    {24999,4000,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.97  BV=0.36
    {24999,4288,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.07  BV=0.26
    {24999,4608,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.17  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {41668,3936,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.94  BV=-0.36
    {41668,4224,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.04  BV=-0.46
    {49997,3776,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.88  BV=-0.56
    {49997,4032,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.98  BV=-0.66
    {49997,4320,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.08  BV=-0.75
    {58327,3968,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=6.95  BV=-0.85
    {58327,4224,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=7.04  BV=-0.94
    {66666,3968,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.95  BV=-1.05
    {66666,4288,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.07  BV=-1.16
    {74996,4064,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=6.99  BV=-1.25
    {83335,3936,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=6.94  BV=-1.36
    {83335,4224,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=7.04  BV=-1.46
    {91665,4096,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=7.00  BV=-1.55
    {99994,4032,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=6.98  BV=-1.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureISO400PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {506,4096,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=7.00  BV=5.95
    {543,4064,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=6.99  BV=5.86
    {580,4096,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=7.00  BV=5.75
    {626,4096,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=7.00  BV=5.64
    {672,4064,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=6.99  BV=5.55
    {718,4096,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=7.00  BV=5.44
    {764,4096,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=7.00  BV=5.35
    {819,4096,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=7.00  BV=5.25
    {883,4096,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=7.00  BV=5.15
    {947,4064,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=6.99  BV=5.06
    {1021,4064,1024, 0, 0, 0},  //TV = 9.94(111 lines)  AV=2.00  SV=6.99  BV=4.95
    {1085,4096,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=7.00  BV=4.85
    {1168,4096,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=7.00  BV=4.74
    {1251,4064,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=6.99  BV=4.65
    {1343,4064,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=6.99  BV=4.55
    {1444,4064,1024, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=6.99  BV=4.45
    {1536,4096,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=7.00  BV=4.35
    {1646,4064,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=6.99  BV=4.26
    {1766,4096,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=7.00  BV=4.15
    {1885,4096,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=7.00  BV=4.05
    {2032,4096,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=7.00  BV=3.94
    {2170,4096,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=7.00  BV=3.85
    {2327,4096,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=7.00  BV=3.75
    {2501,4096,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=7.00  BV=3.64
    {2676,4096,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=7.00  BV=3.55
    {2869,4064,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=6.99  BV=3.46
    {3071,4064,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=6.99  BV=3.36
    {3301,4096,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=7.00  BV=3.24
    {3540,4064,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=6.99  BV=3.15
    {3788,4064,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=6.99  BV=3.06
    {4055,4064,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=6.99  BV=2.96
    {4368,4096,1024, 0, 0, 0},  //TV = 7.84(475 lines)  AV=2.00  SV=7.00  BV=2.84
    {4671,4096,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=7.00  BV=2.74
    {5002,4096,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=7.00  BV=2.64
    {5361,4096,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=7.00  BV=2.54
    {5738,4096,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=7.00  BV=2.45
    {6142,4096,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=7.00  BV=2.35
    {6583,4096,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=7.00  BV=2.25
    {7052,4096,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=7.00  BV=2.15
    {7549,4096,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=7.00  BV=2.05
    {8091,4096,1024, 0, 0, 0},  //TV = 6.95(880 lines)  AV=2.00  SV=7.00  BV=1.95
    {8726,4096,1024, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=7.00  BV=1.84
    {9342,4096,1024, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=7.00  BV=1.74
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4704,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.20  BV=1.44
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.29  BV=1.35
    {10004,5376,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.39  BV=1.25
    {10004,5760,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.49  BV=1.15
    {19997,3104,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.60  BV=1.04
    {19997,3296,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.69  BV=0.96
    {19997,3552,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.79  BV=0.85
    {19997,3808,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.89  BV=0.75
    {19997,4064,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.99  BV=0.66
    {19997,4352,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.09  BV=0.56
    {19997,4672,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.19  BV=0.45
    {19997,5024,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.29  BV=0.35
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4448,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.12  BV=-0.06
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {40004,3808,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.89  BV=-0.25
    {40004,4064,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.99  BV=-0.34
    {40004,4384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.10  BV=-0.45
    {49997,3776,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.88  BV=-0.56
    {49997,4032,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.98  BV=-0.66
    {49997,4320,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.08  BV=-0.75
    {60001,3872,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.92  BV=-0.86
    {60001,4128,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.01  BV=-0.95
    {70004,3808,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.89  BV=-1.06
    {70004,4064,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.99  BV=-1.15
    {70004,4352,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=7.09  BV=-1.25
    {79997,4096,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=7.00  BV=-1.36
    {90001,3904,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=6.93  BV=-1.46
    {90001,4192,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=7.03  BV=-1.56
    {100004,4032,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=6.98  BV=-1.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureISO400Table =
{
    AETABLE_CAPTURE_ISO400, //eAETableID
    119, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -17, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_400, //ISO
    sCaptureISO400PLineTable_60Hz,
    sCaptureISO400PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureISO800PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {506,8192,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=8.00  BV=4.95
    {543,8160,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=7.99  BV=4.85
    {580,8224,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=8.01  BV=4.75
    {626,8192,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=8.00  BV=4.64
    {672,8160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=7.99  BV=4.54
    {718,8192,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=8.00  BV=4.44
    {764,8224,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=8.01  BV=4.35
    {819,8224,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=8.01  BV=4.25
    {883,8192,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=8.00  BV=4.15
    {947,8160,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=7.99  BV=4.05
    {1012,8160,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=7.99  BV=3.95
    {1085,8192,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=8.00  BV=3.85
    {1168,8160,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=7.99  BV=3.75
    {1251,8160,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=7.99  BV=3.65
    {1343,8160,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=7.99  BV=3.55
    {1444,8160,1024, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=7.99  BV=3.44
    {1536,8192,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=8.00  BV=3.35
    {1646,8160,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=7.99  BV=3.25
    {1766,8192,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=8.00  BV=3.15
    {1885,8192,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=8.00  BV=3.05
    {2032,8192,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=8.00  BV=2.94
    {2170,8192,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=8.00  BV=2.85
    {2327,8160,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=7.99  BV=2.75
    {2501,8192,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=8.00  BV=2.64
    {2676,8192,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=8.00  BV=2.55
    {2869,8160,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=7.99  BV=2.45
    {3071,8160,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=7.99  BV=2.35
    {3301,8192,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=8.00  BV=2.24
    {3540,8160,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=7.99  BV=2.15
    {3788,8160,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=7.99  BV=2.05
    {4055,8160,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=7.99  BV=1.95
    {4340,8160,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=7.99  BV=1.85
    {4671,8192,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=8.00  BV=1.74
    {5002,8192,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=8.00  BV=1.64
    {5361,8160,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=7.99  BV=1.55
    {5738,8192,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=8.00  BV=1.45
    {6142,8192,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=8.00  BV=1.35
    {6583,8192,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=8.00  BV=1.25
    {7052,8192,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=8.00  BV=1.15
    {7549,8192,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=8.00  BV=1.05
    {8146,8192,1024, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=8.00  BV=0.94
    {8330,8576,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.07  BV=0.84
    {8330,9184,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.16  BV=0.74
    {8330,9824,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.26  BV=0.65
    {8330,10528,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.36  BV=0.55
    {8330,11296,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.46  BV=0.44
    {8330,12096,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=8.56  BV=0.35
    {16669,6464,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.66  BV=0.25
    {16669,6944,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.76  BV=0.15
    {16669,7424,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.86  BV=0.05
    {16669,7968,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.96  BV=-0.05
    {16669,8544,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.06  BV=-0.15
    {16669,9152,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.16  BV=-0.25
    {16669,9792,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.26  BV=-0.35
    {24999,7008,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.77  BV=-0.45
    {24999,7488,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.87  BV=-0.55
    {24999,8032,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.97  BV=-0.65
    {24999,8608,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.07  BV=-0.75
    {24999,9216,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.17  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8512,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33329,9120,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.15  BV=-1.25
    {41668,7808,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.93  BV=-1.35
    {41668,8448,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.04  BV=-1.46
    {49997,7520,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.88  BV=-1.55
    {49997,8064,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.98  BV=-1.66
    {49997,8640,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.08  BV=-1.75
    {58327,7936,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=7.95  BV=-1.85
    {58327,8512,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.06  BV=-1.96
    {66666,8000,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.97  BV=-2.06
    {66666,8576,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.07  BV=-2.16
    {74996,8160,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=7.99  BV=-2.26
    {83335,7872,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=7.94  BV=-2.36
    {83335,8416,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=8.04  BV=-2.45
    {91665,8224,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=8.01  BV=-2.56
    {99994,8064,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.98  BV=-2.66
    {108333,7968,1024, 0, 0, 0},  //TV = 3.21(11783 lines)  AV=2.00  SV=7.96  BV=-2.75
    {116663,7936,1024, 0, 0, 0},  //TV = 3.10(12689 lines)  AV=2.00  SV=7.95  BV=-2.85
    {124993,7936,1024, 0, 0, 0},  //TV = 3.00(13595 lines)  AV=2.00  SV=7.95  BV=-2.95
    {133332,7968,1024, 0, 0, 0},  //TV = 2.91(14502 lines)  AV=2.00  SV=7.96  BV=-3.05
    {141662,8064,1024, 0, 0, 0},  //TV = 2.82(15408 lines)  AV=2.00  SV=7.98  BV=-3.16
    {149991,8160,1024, 0, 0, 0},  //TV = 2.74(16314 lines)  AV=2.00  SV=7.99  BV=-3.26
    {158330,8288,1024, 0, 0, 0},  //TV = 2.66(17221 lines)  AV=2.00  SV=8.02  BV=-3.36
    {174990,8032,1024, 0, 0, 0},  //TV = 2.51(19033 lines)  AV=2.00  SV=7.97  BV=-3.46
    {183329,8224,1024, 0, 0, 0},  //TV = 2.45(19940 lines)  AV=2.00  SV=8.01  BV=-3.56
    {199988,8064,1024, 0, 0, 0},  //TV = 2.32(21752 lines)  AV=2.00  SV=7.98  BV=-3.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureISO800PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {506,8192,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=8.00  BV=4.95
    {543,8160,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=7.99  BV=4.85
    {580,8224,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=8.01  BV=4.75
    {626,8192,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=8.00  BV=4.64
    {672,8160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=7.99  BV=4.54
    {718,8192,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=8.00  BV=4.44
    {764,8224,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=8.01  BV=4.35
    {819,8224,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=8.01  BV=4.25
    {883,8192,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=8.00  BV=4.15
    {947,8160,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=7.99  BV=4.05
    {1012,8160,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=7.99  BV=3.95
    {1085,8192,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=8.00  BV=3.85
    {1168,8160,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=7.99  BV=3.75
    {1251,8160,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=7.99  BV=3.65
    {1343,8160,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=7.99  BV=3.55
    {1444,8160,1024, 0, 0, 0},  //TV = 9.44(157 lines)  AV=2.00  SV=7.99  BV=3.44
    {1536,8192,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=8.00  BV=3.35
    {1646,8160,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=7.99  BV=3.25
    {1766,8192,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=8.00  BV=3.15
    {1885,8192,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=8.00  BV=3.05
    {2032,8192,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=8.00  BV=2.94
    {2170,8192,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=8.00  BV=2.85
    {2327,8160,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=7.99  BV=2.75
    {2501,8192,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=8.00  BV=2.64
    {2676,8192,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=8.00  BV=2.55
    {2869,8160,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=7.99  BV=2.45
    {3071,8160,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=7.99  BV=2.35
    {3301,8192,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=8.00  BV=2.24
    {3540,8160,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=7.99  BV=2.15
    {3788,8160,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=7.99  BV=2.05
    {4055,8160,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=7.99  BV=1.95
    {4340,8160,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=7.99  BV=1.85
    {4671,8192,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=8.00  BV=1.74
    {5002,8192,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=8.00  BV=1.64
    {5361,8160,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=7.99  BV=1.55
    {5738,8192,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=8.00  BV=1.45
    {6142,8192,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=8.00  BV=1.35
    {6583,8192,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=8.00  BV=1.25
    {7052,8192,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=8.00  BV=1.15
    {7549,8192,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=8.00  BV=1.05
    {8146,8192,1024, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=8.00  BV=0.94
    {8726,8192,1024, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=8.00  BV=0.84
    {9342,8192,1024, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=8.00  BV=0.74
    {10004,8192,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.00  BV=0.64
    {10004,8768,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.10  BV=0.55
    {10004,9408,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.20  BV=0.44
    {10004,10080,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.30  BV=0.34
    {10004,10784,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.40  BV=0.25
    {10004,11552,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=8.50  BV=0.15
    {19997,6176,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.59  BV=0.05
    {19997,6624,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.69  BV=-0.05
    {19997,7104,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.79  BV=-0.15
    {19997,7616,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.89  BV=-0.25
    {19997,8160,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.99  BV=-0.35
    {19997,8736,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.09  BV=-0.45
    {19997,9376,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.19  BV=-0.55
    {19997,10048,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.29  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8832,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.15
    {40004,7648,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.90  BV=-1.26
    {40004,8192,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.00  BV=-1.36
    {40004,8800,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.10  BV=-1.46
    {49997,7520,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.88  BV=-1.55
    {49997,8064,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=7.98  BV=-1.66
    {49997,8640,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.08  BV=-1.75
    {60001,7712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.91  BV=-1.85
    {60001,8288,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.02  BV=-1.96
    {70004,7616,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=7.89  BV=-2.06
    {70004,8160,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=7.99  BV=-2.16
    {70004,8736,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.09  BV=-2.26
    {79997,8192,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=8.00  BV=-2.36
    {90001,7808,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=7.93  BV=-2.46
    {90001,8352,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=8.03  BV=-2.55
    {100004,8064,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.98  BV=-2.66
    {109998,7872,1024, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=7.94  BV=-2.76
    {109998,8416,1024, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=8.04  BV=-2.85
    {120001,8288,1024, 0, 0, 0},  //TV = 3.06(13052 lines)  AV=2.00  SV=8.02  BV=-2.96
    {130004,8192,1024, 0, 0, 0},  //TV = 2.94(14140 lines)  AV=2.00  SV=8.00  BV=-3.06
    {139998,8160,1024, 0, 0, 0},  //TV = 2.84(15227 lines)  AV=2.00  SV=7.99  BV=-3.16
    {150001,8160,1024, 0, 0, 0},  //TV = 2.74(16315 lines)  AV=2.00  SV=7.99  BV=-3.26
    {160004,8192,1024, 0, 0, 0},  //TV = 2.64(17403 lines)  AV=2.00  SV=8.00  BV=-3.36
    {169998,8256,1024, 0, 0, 0},  //TV = 2.56(18490 lines)  AV=2.00  SV=8.01  BV=-3.45
    {180001,8352,1024, 0, 0, 0},  //TV = 2.47(19578 lines)  AV=2.00  SV=8.03  BV=-3.55
    {199998,8064,1024, 0, 0, 0},  //TV = 2.32(21753 lines)  AV=2.00  SV=7.98  BV=-3.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureISO800Table =
{
    AETABLE_CAPTURE_ISO800, //eAETableID
    139, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -37, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_800, //ISO
    sCaptureISO800PLineTable_60Hz,
    sCaptureISO800PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureISO1600PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {506,16384,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=9.00  BV=3.95
    {543,16352,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=9.00  BV=3.85
    {580,16384,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=9.00  BV=3.75
    {626,16384,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=9.00  BV=3.64
    {672,16320,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=8.99  BV=3.54
    {718,16384,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=9.00  BV=3.44
    {764,16384,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=9.00  BV=3.35
    {819,16384,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=9.00  BV=3.25
    {883,16384,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=9.00  BV=3.15
    {947,16352,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=9.00  BV=3.05
    {1012,16352,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=9.00  BV=2.95
    {1085,16384,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=9.00  BV=2.85
    {1168,16352,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=9.00  BV=2.74
    {1251,16320,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=8.99  BV=2.65
    {1343,16320,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=8.99  BV=2.55
    {1435,16320,1024, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=8.99  BV=2.45
    {1536,16384,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=9.00  BV=2.35
    {1646,16352,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=9.00  BV=2.25
    {1766,16384,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=9.00  BV=2.15
    {1885,16384,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=9.00  BV=2.05
    {2032,16384,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=9.00  BV=1.94
    {2170,16384,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=9.00  BV=1.85
    {2327,16352,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=9.00  BV=1.75
    {2501,16384,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=9.00  BV=1.64
    {2676,16384,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=9.00  BV=1.55
    {2869,16352,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=9.00  BV=1.45
    {3071,16352,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=9.00  BV=1.35
    {3301,16384,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=9.00  BV=1.24
    {3540,16352,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=9.00  BV=1.14
    {3788,16352,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=9.00  BV=1.05
    {4055,16352,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=9.00  BV=0.95
    {4340,16352,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=9.00  BV=0.85
    {4671,16384,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=9.00  BV=0.74
    {5002,16384,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=9.00  BV=0.64
    {5361,16352,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=9.00  BV=0.55
    {5738,16384,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=9.00  BV=0.45
    {6142,16384,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=9.00  BV=0.35
    {6583,16352,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=9.00  BV=0.25
    {7052,16352,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=9.00  BV=0.15
    {7549,16384,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=9.00  BV=0.05
    {8146,16352,1024, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=9.00  BV=-0.06
    {8330,16384,1072, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.07  BV=-0.16
    {8330,16384,1144, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.16  BV=-0.25
    {8330,16384,1224, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.26  BV=-0.35
    {8330,16384,1312, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.36  BV=-0.45
    {8330,16384,1408, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.46  BV=-0.55
    {8330,16384,1512, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=9.56  BV=-0.65
    {16669,12960,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.66  BV=-0.76
    {16669,13888,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.76  BV=-0.85
    {16669,14880,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.86  BV=-0.95
    {16669,15936,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=8.96  BV=-1.05
    {16669,16384,1064, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.06  BV=-1.15
    {16669,16384,1144, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.16  BV=-1.25
    {16669,16384,1224, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.26  BV=-1.35
    {24999,13984,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.77  BV=-1.45
    {24999,15008,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.87  BV=-1.55
    {24999,16064,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.97  BV=-1.65
    {24999,16384,1072, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.07  BV=-1.74
    {24999,16384,1152, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.17  BV=-1.85
    {33329,14848,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.86  BV=-1.95
    {33329,15904,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.96  BV=-2.05
    {33329,16384,1064, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.06  BV=-2.15
    {33329,16384,1136, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.15  BV=-2.24
    {41668,15648,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.93  BV=-2.35
    {41668,16384,1056, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.04  BV=-2.46
    {49997,15072,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.88  BV=-2.56
    {49997,16160,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.98  BV=-2.66
    {49997,16384,1080, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.08  BV=-2.75
    {58327,15904,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.96  BV=-2.86
    {58327,16384,1064, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.06  BV=-2.96
    {66666,16000,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.97  BV=-3.06
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {74996,16320,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=8.99  BV=-3.26
    {83335,15744,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=8.94  BV=-3.36
    {83335,16384,1048, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=9.03  BV=-3.45
    {91665,16384,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=9.00  BV=-3.55
    {99994,16160,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.98  BV=-3.66
    {108333,15968,1024, 0, 0, 0},  //TV = 3.21(11783 lines)  AV=2.00  SV=8.96  BV=-3.76
    {116663,15904,1024, 0, 0, 0},  //TV = 3.10(12689 lines)  AV=2.00  SV=8.96  BV=-3.86
    {124993,15904,1024, 0, 0, 0},  //TV = 3.00(13595 lines)  AV=2.00  SV=8.96  BV=-3.96
    {133332,15968,1024, 0, 0, 0},  //TV = 2.91(14502 lines)  AV=2.00  SV=8.96  BV=-4.06
    {141662,16128,1024, 0, 0, 0},  //TV = 2.82(15408 lines)  AV=2.00  SV=8.98  BV=-4.16
    {149991,16320,1024, 0, 0, 0},  //TV = 2.74(16314 lines)  AV=2.00  SV=8.99  BV=-4.26
    {158330,16384,1032, 0, 0, 0},  //TV = 2.66(17221 lines)  AV=2.00  SV=9.01  BV=-4.35
    {174990,16064,1024, 0, 0, 0},  //TV = 2.51(19033 lines)  AV=2.00  SV=8.97  BV=-4.46
    {183329,16384,1024, 0, 0, 0},  //TV = 2.45(19940 lines)  AV=2.00  SV=9.00  BV=-4.55
    {199988,16128,1024, 0, 0, 0},  //TV = 2.32(21752 lines)  AV=2.00  SV=8.98  BV=-4.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureISO1600PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {506,16384,1024, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=9.00  BV=3.95
    {543,16352,1024, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=9.00  BV=3.85
    {580,16384,1024, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=9.00  BV=3.75
    {626,16384,1024, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=9.00  BV=3.64
    {672,16320,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=8.99  BV=3.54
    {718,16384,1024, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=9.00  BV=3.44
    {764,16384,1024, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=9.00  BV=3.35
    {819,16384,1024, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=9.00  BV=3.25
    {883,16384,1024, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=9.00  BV=3.15
    {947,16352,1024, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=9.00  BV=3.05
    {1012,16352,1024, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=9.00  BV=2.95
    {1085,16384,1024, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=9.00  BV=2.85
    {1168,16352,1024, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=9.00  BV=2.74
    {1251,16320,1024, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=8.99  BV=2.65
    {1343,16320,1024, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=8.99  BV=2.55
    {1435,16320,1024, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=8.99  BV=2.45
    {1536,16384,1024, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=9.00  BV=2.35
    {1646,16352,1024, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=9.00  BV=2.25
    {1766,16384,1024, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=9.00  BV=2.15
    {1885,16384,1024, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=9.00  BV=2.05
    {2032,16384,1024, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=9.00  BV=1.94
    {2170,16384,1024, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=9.00  BV=1.85
    {2327,16352,1024, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=9.00  BV=1.75
    {2501,16384,1024, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=9.00  BV=1.64
    {2676,16384,1024, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=9.00  BV=1.55
    {2869,16352,1024, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=9.00  BV=1.45
    {3071,16352,1024, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=9.00  BV=1.35
    {3301,16384,1024, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=9.00  BV=1.24
    {3540,16352,1024, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=9.00  BV=1.14
    {3788,16352,1024, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=9.00  BV=1.05
    {4055,16352,1024, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=9.00  BV=0.95
    {4340,16352,1024, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=9.00  BV=0.85
    {4671,16384,1024, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=9.00  BV=0.74
    {5002,16384,1024, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=9.00  BV=0.64
    {5361,16352,1024, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=9.00  BV=0.55
    {5738,16384,1024, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=9.00  BV=0.45
    {6142,16384,1024, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=9.00  BV=0.35
    {6583,16352,1024, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=9.00  BV=0.25
    {7052,16352,1024, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=9.00  BV=0.15
    {7549,16384,1024, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=9.00  BV=0.05
    {8146,16352,1024, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=9.00  BV=-0.06
    {8726,16352,1024, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=9.00  BV=-0.16
    {9342,16384,1024, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=9.00  BV=-0.26
    {10004,16384,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.00  BV=-0.36
    {10004,16384,1096, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.10  BV=-0.45
    {10004,16384,1176, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.20  BV=-0.56
    {10004,16384,1256, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.29  BV=-0.65
    {10004,16384,1344, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.39  BV=-0.75
    {10004,16384,1440, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=9.49  BV=-0.85
    {19997,12384,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.60  BV=-0.95
    {19997,13280,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.70  BV=-1.05
    {19997,14240,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.80  BV=-1.15
    {19997,15232,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.89  BV=-1.25
    {19997,16320,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=8.99  BV=-1.35
    {19997,16384,1088, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.09  BV=-1.44
    {19997,16384,1168, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.19  BV=-1.55
    {19997,16384,1256, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.29  BV=-1.65
    {30001,14336,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.81  BV=-1.75
    {30001,15392,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.91  BV=-1.85
    {30001,16384,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.00  BV=-1.94
    {30001,16384,1104, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.11  BV=-2.05
    {30001,16384,1192, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.22  BV=-2.16
    {40004,15200,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.89  BV=-2.25
    {40004,16384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.00  BV=-2.36
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {49997,15072,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.88  BV=-2.56
    {49997,16160,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.98  BV=-2.66
    {49997,16384,1080, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.08  BV=-2.75
    {60001,15456,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.92  BV=-2.86
    {60001,16384,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.01  BV=-2.95
    {70004,15232,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.89  BV=-3.06
    {70004,16320,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.16
    {70004,16384,1088, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.09  BV=-3.25
    {79997,16384,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=9.00  BV=-3.36
    {90001,15616,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=8.93  BV=-3.46
    {90001,16384,1040, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=9.02  BV=-3.55
    {100004,16160,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.98  BV=-3.66
    {109998,15744,1024, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=8.94  BV=-3.76
    {109998,16384,1048, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=9.03  BV=-3.85
    {120001,16384,1032, 0, 0, 0},  //TV = 3.06(13052 lines)  AV=2.00  SV=9.01  BV=-3.95
    {130004,16384,1024, 0, 0, 0},  //TV = 2.94(14140 lines)  AV=2.00  SV=9.00  BV=-4.06
    {139998,16320,1024, 0, 0, 0},  //TV = 2.84(15227 lines)  AV=2.00  SV=8.99  BV=-4.16
    {150001,16320,1024, 0, 0, 0},  //TV = 2.74(16315 lines)  AV=2.00  SV=8.99  BV=-4.26
    {160004,16384,1024, 0, 0, 0},  //TV = 2.64(17403 lines)  AV=2.00  SV=9.00  BV=-4.36
    {169998,16384,1032, 0, 0, 0},  //TV = 2.56(18490 lines)  AV=2.00  SV=9.01  BV=-4.45
    {180001,16384,1040, 0, 0, 0},  //TV = 2.47(19578 lines)  AV=2.00  SV=9.02  BV=-4.55
    {199998,16128,1024, 0, 0, 0},  //TV = 2.32(21753 lines)  AV=2.00  SV=8.98  BV=-4.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_CaptureISO1600Table =
{
    AETABLE_CAPTURE_ISO1600, //eAETableID
    149, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -47, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_1600, //ISO
    sCaptureISO1600PLineTable_60Hz,
    sCaptureISO1600PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sCaptureStrobePLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12768,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {58327,12032,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.55  BV=-2.45
    {58327,12896,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.65  BV=-2.55
    {66666,12096,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.56  BV=-2.66
    {66666,12960,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.66  BV=-2.75
    {66666,13888,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.76  BV=-2.85
    {66666,14880,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.86  BV=-2.95
    {66666,15968,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.96  BV=-3.06
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {66666,16384,1144, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.16  BV=-3.25
    {66666,16384,1224, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.26  BV=-3.35
    {66666,16384,1312, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.36  BV=-3.45
    {66666,16384,1408, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.46  BV=-3.55
    {66666,16384,1504, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.55  BV=-3.65
    {66666,16384,1616, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.66  BV=-3.75
    {66666,16384,1728, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.75  BV=-3.85
    {66666,16384,1856, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.86  BV=-3.95
    {66666,16384,1992, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.96  BV=-4.05
    {66666,16384,2128, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.06  BV=-4.15
    {66666,16384,2280, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.15  BV=-4.25
    {66666,16384,2448, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.26  BV=-4.35
    {66666,16384,2624, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.36  BV=-4.45
    {66666,16384,2808, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {66666,16384,2880, 0, 0, 0},  /* TV = 3.91(7251 lines)  AV=2.00  SV=10.49  BV=-4.58 */
    {66666,16384,2880, 0, 0, 0},  /* TV = 3.91(7251 lines)  AV=2.00  SV=10.49  BV=-4.58 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sCaptureStrobePLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {60001,11712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60001,12544,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.56
    {70004,11520,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.49  BV=-2.66
    {70004,12352,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.59  BV=-2.76
    {70004,13248,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.69  BV=-2.86
    {70004,14176,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.79  BV=-2.95
    {70004,15200,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.89  BV=-3.06
    {70004,16288,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.16
    {70004,16384,1088, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.09  BV=-3.25
    {70004,16384,1168, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.19  BV=-3.35
    {70004,16384,1248, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.29  BV=-3.45
    {70004,16384,1336, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.38  BV=-3.55
    {70004,16384,1432, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.48  BV=-3.65
    {70004,16384,1536, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.58  BV=-3.75
    {70004,16384,1648, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.69  BV=-3.85
    {70004,16384,1768, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.79  BV=-3.95
    {70004,16384,1896, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.89  BV=-4.05
    {70004,16384,2032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.99  BV=-4.15
    {70004,16384,2176, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.09  BV=-4.25
    {70004,16384,2328, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.18  BV=-4.35
    {70004,16384,2496, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.29  BV=-4.45
    {70004,16384,2680, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.55
    {70004,16384,2872, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.49  BV=-4.65
    {70004,16384,2880, 0, 0, 0},  /* TV = 3.84(7614 lines)  AV=2.00  SV=10.49  BV=-4.66 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_StrobeTable =
{
    AETABLE_STROBE, //eAETableID
    150, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -47, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sCaptureStrobePLineTable_60Hz,
    sCaptureStrobePLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene1PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12768,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {58327,12032,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.55  BV=-2.45
    {58327,12896,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.65  BV=-2.55
    {66666,12096,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.56  BV=-2.66
    {66666,12960,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.66  BV=-2.75
    {66666,13888,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.76  BV=-2.85
    {66666,14880,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.86  BV=-2.95
    {66666,15968,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.96  BV=-3.06
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {66666,16384,1144, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.16  BV=-3.25
    {66666,16384,1224, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.26  BV=-3.35
    {66666,16384,1312, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.36  BV=-3.45
    {66666,16384,1408, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.46  BV=-3.55
    {66666,16384,1504, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.55  BV=-3.65
    {66666,16384,1616, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.66  BV=-3.75
    {66666,16384,1728, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.75  BV=-3.85
    {66666,16384,1856, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.86  BV=-3.95
    {66666,16384,1992, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.96  BV=-4.05
    {66666,16384,2128, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.06  BV=-4.15
    {66666,16384,2280, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.15  BV=-4.25
    {66666,16384,2448, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.26  BV=-4.35
    {66666,16384,2624, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.36  BV=-4.45
    {66666,16384,2808, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {66666,16384,3016, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.56  BV=-4.65
    {74996,16384,2880, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=10.49  BV=-4.75
    {83335,16384,2776, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.44  BV=-4.85
    {83335,16384,2976, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.54  BV=-4.95
    {91665,16384,2896, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=10.50  BV=-5.05
    {99994,16384,2848, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.48  BV=-5.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene1PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {49997,11392,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.15
    {49997,12224,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13088,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.35
    {60001,11712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60001,12544,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.56
    {70004,11520,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.49  BV=-2.66
    {70004,12352,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.59  BV=-2.76
    {70004,13248,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.69  BV=-2.86
    {70004,14176,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.79  BV=-2.95
    {70004,15200,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.89  BV=-3.06
    {70004,16288,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.16
    {70004,16384,1088, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.09  BV=-3.25
    {70004,16384,1168, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.19  BV=-3.35
    {70004,16384,1248, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.29  BV=-3.45
    {70004,16384,1336, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.38  BV=-3.55
    {70004,16384,1432, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.48  BV=-3.65
    {70004,16384,1536, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.58  BV=-3.75
    {70004,16384,1648, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.69  BV=-3.85
    {70004,16384,1768, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.79  BV=-3.95
    {70004,16384,1896, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.89  BV=-4.05
    {70004,16384,2032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.99  BV=-4.15
    {70004,16384,2176, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.09  BV=-4.25
    {70004,16384,2328, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.18  BV=-4.35
    {70004,16384,2496, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.29  BV=-4.45
    {70004,16384,2680, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.55
    {70004,16384,2872, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.49  BV=-4.65
    {70004,16384,3080, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.59  BV=-4.75
    {79997,16384,2888, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=10.50  BV=-4.85
    {90001,16384,2752, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.43  BV=-4.95
    {90001,16384,2952, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.53  BV=-5.05
    {100004,16384,2848, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.48  BV=-5.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable1 =
{
    AETABLE_SCENE_INDEX1, //eAETableID
    154, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -52, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene1PLineTable_60Hz,
    sAEScene1PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene2PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.75  BV=3.15
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.95  BV=2.95
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.15  BV=2.76
    {8330,2464,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.27  BV=2.64
    {8330,2624,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.36  BV=2.55
    {8330,2816,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.46  BV=2.45
    {8330,3008,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.55  BV=2.35
    {8330,3232,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.66  BV=2.25
    {8330,3456,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.75  BV=2.15
    {8330,3712,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.86  BV=2.05
    {8330,4000,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.97  BV=1.94
    {8330,4256,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.06  BV=1.85
    {8330,4576,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.16  BV=1.75
    {8330,4896,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.26  BV=1.65
    {8330,5248,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.36  BV=1.55
    {8330,5632,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.46  BV=1.45
    {8330,6048,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=7.56  BV=1.35
    {16669,3232,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.66  BV=1.25
    {16669,3456,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.75  BV=1.15
    {16669,3712,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.86  BV=1.05
    {16669,3968,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.95  BV=0.95
    {16669,4256,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.06  BV=0.85
    {16669,4544,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.15  BV=0.76
    {16669,4896,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=7.26  BV=0.65
    {24999,3520,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.78  BV=0.54
    {24999,3744,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.87  BV=0.45
    {24999,4032,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.98  BV=0.34
    {24999,4320,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.08  BV=0.25
    {24999,4608,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.17  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4928,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.27  BV=-0.36
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6048,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.56  BV=-0.66
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11296,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.56
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12960,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.66  BV=-1.75
    {33329,13888,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.76  BV=-1.85
    {33329,14880,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.86  BV=-1.95
    {33329,15936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.96  BV=-2.05
    {33329,16384,1024, 0, 0, 0},  /* TV = 4.91(3625 lines)  AV=2.00  SV=9.00  BV=-2.09 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene2PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.50  BV=3.14
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2016,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.99  BV=2.65
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.29  BV=2.36
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.69  BV=1.96
    {10004,3552,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.79  BV=1.85
    {10004,3808,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.89  BV=1.75
    {10004,4096,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.00  BV=1.64
    {10004,4384,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.10  BV=1.55
    {10004,4672,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.19  BV=1.45
    {10004,5024,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.29  BV=1.35
    {10004,5376,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.39  BV=1.25
    {10004,5760,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=7.49  BV=1.15
    {19997,3072,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.60  BV=1.05
    {19997,3296,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.69  BV=0.96
    {19997,3552,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.79  BV=0.85
    {19997,3808,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.89  BV=0.75
    {19997,4064,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.99  BV=0.66
    {19997,4352,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.09  BV=0.56
    {19997,4672,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.19  BV=0.45
    {19997,5024,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=7.29  BV=0.35
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3872,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.92  BV=0.14
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4448,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.12  BV=-0.06
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.42  BV=-0.36
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6272,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.56
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8896,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.12  BV=-1.06
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {30001,14400,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.81  BV=-1.75
    {30001,15424,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.91  BV=-1.85
    {30001,16384,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.00  BV=-1.94
    {30001,16384,1024, 0, 0, 0},  /* TV = 5.06(3263 lines)  AV=2.00  SV=9.00  BV=-1.94 */
    {30001,16384,1024, 0, 0, 0},  /* TV = 5.06(3263 lines)  AV=2.00  SV=9.00  BV=-1.94 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable2 =
{
    AETABLE_SCENE_INDEX2, //eAETableID
    124, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -21, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene2PLineTable_60Hz,
    sAEScene2PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene3PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {41668,1952,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.93  BV=0.65
    {41668,2080,1032, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.03  BV=0.55
    {41668,2240,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=6.13  BV=0.46
    {49997,2016,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.98  BV=0.34
    {49997,2144,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.08  BV=0.24
    {58327,1984,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.95  BV=0.15
    {58327,2112,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=6.04  BV=0.06
    {66666,1984,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.95  BV=-0.05
    {66666,2112,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.06  BV=-0.15
    {66666,2272,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.16  BV=-0.25
    {66666,2432,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.26  BV=-0.35
    {66666,2624,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.36  BV=-0.45
    {66666,2816,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.46  BV=-0.55
    {66666,3008,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.55  BV=-0.65
    {66666,3232,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.66  BV=-0.75
    {66666,3456,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.75  BV=-0.85
    {66666,3712,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.86  BV=-0.95
    {66666,4000,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.97  BV=-1.06
    {66666,4256,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.06  BV=-1.15
    {74996,4064,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=6.99  BV=-1.25
    {83335,3904,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=6.93  BV=-1.35
    {83335,4192,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=7.03  BV=-1.45
    {91665,4096,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=7.00  BV=-1.55
    {99994,4000,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=6.97  BV=-1.64
    {99994,4320,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.08  BV=-1.75
    {99994,4608,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.17  BV=-1.85
    {99994,4960,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.28  BV=-1.95
    {99994,5312,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.38  BV=-2.05
    {99994,5696,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.48  BV=-2.15
    {99994,6112,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.58  BV=-2.26
    {99994,6560,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.68  BV=-2.36
    {99994,7008,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.77  BV=-2.45
    {99994,7520,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.88  BV=-2.55
    {99994,8064,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=7.98  BV=-2.66
    {99994,8608,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.07  BV=-2.75
    {99994,9248,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.17  BV=-2.85
    {99994,9888,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.27  BV=-2.95
    {99994,10592,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.37  BV=-3.05
    {99994,11360,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.47  BV=-3.15
    {99994,12160,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.57  BV=-3.25
    {99994,12288,1024, 0, 0, 0},  /* TV = 3.32(10876 lines)  AV=2.00  SV=8.58  BV=-3.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene3PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {40004,1888,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.89  BV=0.75
    {40004,2016,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.99  BV=0.66
    {40004,2176,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=6.09  BV=0.56
    {49997,1856,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.87  BV=0.45
    {49997,2016,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.98  BV=0.34
    {49997,2144,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=6.08  BV=0.24
    {60001,1920,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.91  BV=0.15
    {60001,2048,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.01  BV=0.05
    {70004,1888,1032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.89  BV=-0.06
    {70004,2016,1032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=5.99  BV=-0.15
    {70004,2176,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.09  BV=-0.25
    {70004,2336,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.19  BV=-0.35
    {70004,2496,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.29  BV=-0.45
    {70004,2656,1032, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.39  BV=-0.55
    {70004,2880,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.49  BV=-0.66
    {70004,3072,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.58  BV=-0.75
    {70004,3296,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.69  BV=-0.85
    {70004,3520,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.78  BV=-0.94
    {70004,3808,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.89  BV=-1.06
    {70004,4064,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=6.99  BV=-1.15
    {70004,4352,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=7.09  BV=-1.25
    {79997,4064,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=6.99  BV=-1.34
    {90001,3872,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=6.92  BV=-1.44
    {90001,4160,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=7.02  BV=-1.55
    {100004,4000,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=6.97  BV=-1.64
    {100004,4320,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.08  BV=-1.75
    {100004,4608,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.17  BV=-1.85
    {100004,4960,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.28  BV=-1.95
    {100004,5280,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.37  BV=-2.04
    {100004,5696,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.48  BV=-2.15
    {100004,6112,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.58  BV=-2.26
    {100004,6560,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.68  BV=-2.36
    {100004,7008,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.77  BV=-2.45
    {100004,7520,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.88  BV=-2.55
    {100004,8064,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=7.98  BV=-2.66
    {100004,8608,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.07  BV=-2.75
    {100004,9248,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.17  BV=-2.85
    {100004,9888,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.27  BV=-2.95
    {100004,10592,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.37  BV=-3.05
    {100004,11360,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.47  BV=-3.15
    {100004,12256,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.58  BV=-3.26
    {100004,12288,1024, 0, 0, 0},  /* TV = 3.32(10877 lines)  AV=2.00  SV=8.58  BV=-3.26 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable3 =
{
    AETABLE_SCENE_INDEX3, //eAETableID
    136, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -33, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene3PLineTable_60Hz,
    sAEScene3PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene4PLineTable_60Hz =
{
{
    {199988,1696,1032, 0, 0, 0},  //TV = 2.32(21752 lines)  AV=2.00  SV=5.74  BV=-1.42
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene4PLineTable_50Hz =
{
{
    {199998,1696,1032, 0, 0, 0},  //TV = 2.32(21753 lines)  AV=2.00  SV=5.74  BV=-1.42
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable4 =
{
    AETABLE_SCENE_INDEX4, //eAETableID
    1, //u4TotalIndex
    20, //i4StrobeTrigerBV
    -14, //i4MaxBV
    -15, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene4PLineTable_60Hz,
    sAEScene4PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene5PLineTable_60Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8330,1216,1040, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.27  BV=3.64
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.95  BV=0.95
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.16  BV=0.75
    {33329,2432,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.26  BV=0.65
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,4000,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.97  BV=-0.06
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5600,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.45  BV=-0.54
    {33329,6048,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.56  BV=-0.66
    {33329,6496,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.67  BV=-0.76
    {33329,6944,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33329,8544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33329,9152,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.25
    {41668,7840,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=7.94  BV=-1.35
    {41668,8416,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.04  BV=-1.45
    {41668,8992,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.13  BV=-1.55
    {41668,9664,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.24  BV=-1.65
    {41668,10336,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.34  BV=-1.75
    {41668,11072,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.43  BV=-1.85
    {41668,11872,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {49997,11424,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.16
    {49997,12256,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13120,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.36
    {58327,12064,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.56  BV=-2.46
    {58327,12896,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.65  BV=-2.55
    {58327,13824,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.75  BV=-2.66
    {58327,14816,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.85  BV=-2.76
    {58327,15872,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=8.95  BV=-2.85
    {58327,16384,1056, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.04  BV=-2.94
    {66666,15904,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.96  BV=-3.05
    {66666,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {74996,16256,1024, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=8.99  BV=-3.25
    {83335,15680,1024, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=8.94  BV=-3.35
    {83335,16384,1048, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=9.03  BV=-3.45
    {91665,16352,1024, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=9.00  BV=-3.55
    {99994,16064,1024, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=8.97  BV=-3.65
    {99994,16384,1080, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.08  BV=-3.75
    {99994,16384,1152, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.17  BV=-3.85
    {99994,16384,1240, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.28  BV=-3.95
    {99994,16384,1328, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.38  BV=-4.05
    {99994,16384,1424, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.48  BV=-4.15
    {99994,16384,1528, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.58  BV=-4.26
    {99994,16384,1632, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.67  BV=-4.35
    {99994,16384,1752, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.77  BV=-4.45
    {99994,16384,1880, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.88  BV=-4.55
    {99994,16384,2016, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.98  BV=-4.66
    {99994,16384,2160, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.08  BV=-4.75
    {99994,16384,2312, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.17  BV=-4.85
    {99994,16384,2480, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.28  BV=-4.95
    {99994,16384,2656, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.38  BV=-5.05
    {99994,16384,2848, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.48  BV=-5.15
    {99994,16384,3048, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.57  BV=-5.25
    {99994,16384,3200, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.64  BV=-5.32
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene5PLineTable_50Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8808,1160,1024, 0, 0, 0},  //TV = 6.83(958 lines)  AV=2.00  SV=5.18  BV=3.65
    {9443,1160,1024, 0, 0, 0},  //TV = 6.73(1027 lines)  AV=2.00  SV=5.18  BV=3.55
    {10004,1160,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.19  BV=3.45
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {30001,1184,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.21  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.52  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.81  BV=1.25
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.32  BV=0.74
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3360,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.71  BV=0.34
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5824,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.51  BV=-0.45
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.66
    {30001,7200,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8256,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.15
    {40004,7616,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.89  BV=-1.25
    {40004,8160,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=7.99  BV=-1.35
    {40004,8768,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.10  BV=-1.45
    {40004,9376,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.19  BV=-1.55
    {40004,10048,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.29  BV=-1.65
    {40004,10784,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.75
    {40004,11552,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.85
    {40004,12352,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.59  BV=-1.95
    {40004,13344,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {49997,11424,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.48  BV=-2.16
    {49997,12256,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.58  BV=-2.26
    {49997,13120,1024, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=8.68  BV=-2.36
    {60001,11712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.52  BV=-2.46
    {60001,12544,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.56
    {60001,13440,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.71  BV=-2.66
    {60001,14400,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.81  BV=-2.75
    {60001,15424,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.91  BV=-2.85
    {60001,16384,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.01  BV=-2.95
    {60001,16384,1104, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.11  BV=-3.05
    {70004,16256,1024, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=8.99  BV=-3.15
    {70004,16384,1088, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.09  BV=-3.25
    {79997,16320,1024, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=8.99  BV=-3.35
    {90001,15552,1024, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=8.92  BV=-3.45
    {90001,16384,1040, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=9.02  BV=-3.55
    {100004,16064,1024, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=8.97  BV=-3.65
    {100004,16384,1080, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.08  BV=-3.75
    {100004,16384,1152, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.17  BV=-3.85
    {100004,16384,1240, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.28  BV=-3.95
    {100004,16384,1328, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.38  BV=-4.05
    {100004,16384,1424, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.48  BV=-4.15
    {100004,16384,1528, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.58  BV=-4.26
    {100004,16384,1632, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.67  BV=-4.35
    {100004,16384,1752, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.77  BV=-4.45
    {100004,16384,1880, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.88  BV=-4.55
    {100004,16384,2008, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.97  BV=-4.65
    {100004,16384,2160, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.08  BV=-4.75
    {100004,16384,2312, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.17  BV=-4.85
    {100004,16384,2480, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.28  BV=-4.95
    {100004,16384,2656, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.38  BV=-5.05
    {100004,16384,2848, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.48  BV=-5.15
    {100004,16384,3048, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.57  BV=-5.25
    {100004,16384,3200, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.64  BV=-5.32
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable5 =
{
    AETABLE_SCENE_INDEX5, //eAETableID
    156, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -54, //i4MinBV
    90, //i4EffectiveMaxBV
    -30, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene5PLineTable_60Hz,
    sAEScene5PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene6PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {506,16384,2048, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=10.00  BV=2.95
    {543,16384,2040, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=9.99  BV=2.85
    {580,16384,2048, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=10.00  BV=2.75
    {626,16384,2048, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=10.00  BV=2.64
    {672,16384,2040, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=9.99  BV=2.54
    {718,16384,2048, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=10.00  BV=2.44
    {764,16384,2056, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=10.01  BV=2.35
    {819,16384,2048, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=10.00  BV=2.25
    {883,16384,2048, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=10.00  BV=2.15
    {947,16384,2040, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=9.99  BV=2.05
    {1012,16384,2040, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=9.99  BV=1.95
    {1085,16384,2048, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=10.00  BV=1.85
    {1168,16384,2040, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=9.99  BV=1.75
    {1251,16384,2040, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=9.99  BV=1.65
    {1343,16384,2040, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=9.99  BV=1.55
    {1435,16384,2040, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=9.99  BV=1.45
    {1536,16384,2048, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=10.00  BV=1.35
    {1646,16384,2040, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=9.99  BV=1.25
    {1766,16384,2048, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=10.00  BV=1.15
    {1885,16384,2048, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=10.00  BV=1.05
    {2032,16384,2048, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=10.00  BV=0.94
    {2170,16384,2048, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=10.00  BV=0.85
    {2327,16384,2040, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=9.99  BV=0.75
    {2501,16384,2048, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=10.00  BV=0.64
    {2676,16384,2048, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=10.00  BV=0.55
    {2869,16384,2040, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=9.99  BV=0.45
    {3071,16384,2040, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=9.99  BV=0.35
    {3301,16384,2048, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=10.00  BV=0.24
    {3540,16384,2040, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=9.99  BV=0.15
    {3788,16384,2040, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=9.99  BV=0.05
    {4055,16384,2040, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=9.99  BV=-0.05
    {4340,16384,2040, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=9.99  BV=-0.15
    {4671,16384,2048, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=10.00  BV=-0.26
    {5002,16384,2048, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=10.00  BV=-0.36
    {5361,16384,2040, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=9.99  BV=-0.45
    {5738,16384,2048, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=10.00  BV=-0.55
    {6142,16384,2048, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=10.00  BV=-0.65
    {6583,16384,2040, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=9.99  BV=-0.75
    {7052,16384,2040, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=9.99  BV=-0.85
    {7549,16384,2048, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=10.00  BV=-0.95
    {8146,16384,2040, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=9.99  BV=-1.05
    {8330,16384,2144, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.07  BV=-1.16
    {8330,16384,2296, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.16  BV=-1.26
    {8330,16384,2456, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.26  BV=-1.35
    {8330,16384,2632, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.36  BV=-1.45
    {8330,16384,2824, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.46  BV=-1.56
    {8330,16384,3024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=10.56  BV=-1.65
    {16669,16384,1616, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.66  BV=-1.75
    {16669,16384,1736, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.76  BV=-1.85
    {16669,16384,1856, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.86  BV=-1.95
    {16669,16384,1992, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=9.96  BV=-2.05
    {16669,16384,2128, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.06  BV=-2.15
    {16669,16384,2280, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.15  BV=-2.25
    {16669,16384,2448, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.26  BV=-2.35
    {24999,16384,1744, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.77  BV=-2.45
    {24999,16384,1872, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.87  BV=-2.55
    {24999,16384,2008, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.97  BV=-2.65
    {24999,16384,2152, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.07  BV=-2.75
    {24999,16384,2304, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.17  BV=-2.85
    {33329,16384,1856, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.86  BV=-2.95
    {33329,16384,1984, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.95  BV=-3.05
    {33329,16384,2128, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.06  BV=-3.15
    {33329,16384,2296, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.16  BV=-3.26
    {41668,16384,1968, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.94  BV=-3.36
    {41668,16384,2112, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.04  BV=-3.46
    {49997,16384,1880, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.88  BV=-3.55
    {49997,16384,2016, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.98  BV=-3.66
    {49997,16384,2160, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.08  BV=-3.75
    {58327,16384,1984, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=9.95  BV=-3.85
    {58327,16384,2128, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.06  BV=-3.96
    {66666,16384,2000, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.97  BV=-4.06
    {66666,16384,2136, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.06  BV=-4.15
    {74996,16384,2040, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=9.99  BV=-4.26
    {83335,16384,1968, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=9.94  BV=-4.36
    {83335,16384,2104, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.04  BV=-4.45
    {91665,16384,2056, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=10.01  BV=-4.56
    {99994,16384,2016, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=9.98  BV=-4.66
    {108333,16384,1992, 0, 0, 0},  //TV = 3.21(11783 lines)  AV=2.00  SV=9.96  BV=-4.75
    {116663,16384,1984, 0, 0, 0},  //TV = 3.10(12689 lines)  AV=2.00  SV=9.95  BV=-4.85
    {124993,16384,1984, 0, 0, 0},  //TV = 3.00(13595 lines)  AV=2.00  SV=9.95  BV=-4.95
    {133332,16384,1992, 0, 0, 0},  //TV = 2.91(14502 lines)  AV=2.00  SV=9.96  BV=-5.05
    {141662,16384,2016, 0, 0, 0},  //TV = 2.82(15408 lines)  AV=2.00  SV=9.98  BV=-5.16
    {149991,16384,2040, 0, 0, 0},  //TV = 2.74(16314 lines)  AV=2.00  SV=9.99  BV=-5.26
    {158330,16384,2072, 0, 0, 0},  //TV = 2.66(17221 lines)  AV=2.00  SV=10.02  BV=-5.36
    {174990,16384,2008, 0, 0, 0},  //TV = 2.51(19033 lines)  AV=2.00  SV=9.97  BV=-5.46
    {183329,16384,2048, 0, 0, 0},  //TV = 2.45(19940 lines)  AV=2.00  SV=10.00  BV=-5.55
    {199988,16384,2016, 0, 0, 0},  //TV = 2.32(21752 lines)  AV=2.00  SV=9.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene6PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {506,16384,2048, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=10.00  BV=2.95
    {543,16384,2040, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=9.99  BV=2.85
    {580,16384,2048, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=10.00  BV=2.75
    {626,16384,2048, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=10.00  BV=2.64
    {672,16384,2040, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=9.99  BV=2.54
    {718,16384,2048, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=10.00  BV=2.44
    {764,16384,2056, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=10.01  BV=2.35
    {819,16384,2048, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=10.00  BV=2.25
    {883,16384,2048, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=10.00  BV=2.15
    {947,16384,2040, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=9.99  BV=2.05
    {1012,16384,2040, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=9.99  BV=1.95
    {1085,16384,2048, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=10.00  BV=1.85
    {1168,16384,2040, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=9.99  BV=1.75
    {1251,16384,2040, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=9.99  BV=1.65
    {1343,16384,2040, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=9.99  BV=1.55
    {1435,16384,2040, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=9.99  BV=1.45
    {1536,16384,2048, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=10.00  BV=1.35
    {1646,16384,2040, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=9.99  BV=1.25
    {1766,16384,2048, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=10.00  BV=1.15
    {1885,16384,2048, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=10.00  BV=1.05
    {2032,16384,2048, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=10.00  BV=0.94
    {2170,16384,2048, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=10.00  BV=0.85
    {2327,16384,2040, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=9.99  BV=0.75
    {2501,16384,2048, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=10.00  BV=0.64
    {2676,16384,2048, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=10.00  BV=0.55
    {2869,16384,2040, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=9.99  BV=0.45
    {3071,16384,2040, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=9.99  BV=0.35
    {3301,16384,2048, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=10.00  BV=0.24
    {3540,16384,2040, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=9.99  BV=0.15
    {3788,16384,2040, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=9.99  BV=0.05
    {4055,16384,2040, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=9.99  BV=-0.05
    {4340,16384,2040, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=9.99  BV=-0.15
    {4671,16384,2048, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=10.00  BV=-0.26
    {5002,16384,2048, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=10.00  BV=-0.36
    {5361,16384,2040, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=9.99  BV=-0.45
    {5738,16384,2048, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=10.00  BV=-0.55
    {6142,16384,2048, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=10.00  BV=-0.65
    {6583,16384,2040, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=9.99  BV=-0.75
    {7052,16384,2040, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=9.99  BV=-0.85
    {7549,16384,2048, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=10.00  BV=-0.95
    {8146,16384,2040, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=9.99  BV=-1.05
    {8726,16384,2040, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=9.99  BV=-1.15
    {9342,16384,2048, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=10.00  BV=-1.26
    {10004,16384,2048, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.00  BV=-1.36
    {10004,16384,2192, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.10  BV=-1.45
    {10004,16384,2352, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.20  BV=-1.56
    {10004,16384,2520, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.30  BV=-1.66
    {10004,16384,2696, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.40  BV=-1.75
    {10004,16384,2888, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=10.50  BV=-1.85
    {19997,16384,1544, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.59  BV=-1.95
    {19997,16384,1656, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.69  BV=-2.05
    {19997,16384,1776, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.79  BV=-2.15
    {19997,16384,1904, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.89  BV=-2.25
    {19997,16384,2040, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=9.99  BV=-2.35
    {19997,16384,2184, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.09  BV=-2.45
    {19997,16384,2344, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.19  BV=-2.55
    {19997,16384,2512, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.29  BV=-2.65
    {30001,16384,1792, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.81  BV=-2.75
    {30001,16384,1920, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.91  BV=-2.85
    {30001,16384,2056, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.01  BV=-2.95
    {30001,16384,2208, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.11  BV=-3.05
    {30001,16384,2360, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.20  BV=-3.15
    {40004,16384,1912, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.90  BV=-3.26
    {40004,16384,2048, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.00  BV=-3.36
    {40004,16384,2200, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.10  BV=-3.46
    {49997,16384,1880, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.88  BV=-3.55
    {49997,16384,2016, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=9.98  BV=-3.66
    {49997,16384,2160, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.08  BV=-3.75
    {60001,16384,1928, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.91  BV=-3.85
    {60001,16384,2072, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.02  BV=-3.96
    {70004,16384,1904, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.89  BV=-4.06
    {70004,16384,2040, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=9.99  BV=-4.16
    {70004,16384,2184, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.09  BV=-4.26
    {79997,16384,2048, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=10.00  BV=-4.36
    {90001,16384,1952, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=9.93  BV=-4.46
    {90001,16384,2088, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.03  BV=-4.55
    {100004,16384,2016, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=9.98  BV=-4.66
    {109998,16384,1968, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=9.94  BV=-4.76
    {109998,16384,2104, 0, 0, 0},  //TV = 3.18(11964 lines)  AV=2.00  SV=10.04  BV=-4.85
    {120001,16384,2072, 0, 0, 0},  //TV = 3.06(13052 lines)  AV=2.00  SV=10.02  BV=-4.96
    {130004,16384,2048, 0, 0, 0},  //TV = 2.94(14140 lines)  AV=2.00  SV=10.00  BV=-5.06
    {139998,16384,2040, 0, 0, 0},  //TV = 2.84(15227 lines)  AV=2.00  SV=9.99  BV=-5.16
    {150001,16384,2040, 0, 0, 0},  //TV = 2.74(16315 lines)  AV=2.00  SV=9.99  BV=-5.26
    {160004,16384,2048, 0, 0, 0},  //TV = 2.64(17403 lines)  AV=2.00  SV=10.00  BV=-5.36
    {169998,16384,2064, 0, 0, 0},  //TV = 2.56(18490 lines)  AV=2.00  SV=10.01  BV=-5.45
    {180001,16384,2088, 0, 0, 0},  //TV = 2.47(19578 lines)  AV=2.00  SV=10.03  BV=-5.55
    {199998,16384,2016, 0, 0, 0},  //TV = 2.32(21753 lines)  AV=2.00  SV=9.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable6 =
{
    AETABLE_SCENE_INDEX6, //eAETableID
    159, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -57, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene6PLineTable_60Hz,
    sAEScene6PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene7PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {497,16384,2080, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.02  BV=2.95
    {497,16384,2232, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.12  BV=2.85
    {497,16384,2392, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.22  BV=2.75
    {497,16384,2560, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.32  BV=2.65
    {497,16384,2744, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.42  BV=2.55
    {497,16384,2944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.52  BV=2.45
    {497,16384,3152, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.62  BV=2.35
    {497,16384,3400, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.73  BV=2.24
    {497,16384,3648, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.83  BV=2.14
    {497,16384,3912, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.93  BV=2.04
    {506,16384,4096, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=11.00  BV=1.95
    {543,16384,4088, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=11.00  BV=1.85
    {580,16384,4104, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=11.00  BV=1.75
    {626,16384,4096, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=11.00  BV=1.64
    {672,16384,4080, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=10.99  BV=1.54
    {718,16384,4096, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=11.00  BV=1.44
    {764,16384,4112, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=11.01  BV=1.35
    {819,16384,4104, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=11.00  BV=1.25
    {883,16384,4104, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=11.00  BV=1.14
    {947,16384,4080, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=10.99  BV=1.05
    {1012,16384,4088, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=11.00  BV=0.95
    {1085,16384,4104, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=11.00  BV=0.85
    {1168,16384,4088, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=11.00  BV=0.74
    {1251,16384,4080, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=10.99  BV=0.65
    {1343,16384,4080, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=10.99  BV=0.55
    {1435,16384,4080, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=10.99  BV=0.45
    {1536,16384,4104, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=11.00  BV=0.34
    {1646,16384,4088, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=11.00  BV=0.25
    {1766,16384,4096, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=11.00  BV=0.15
    {1885,16384,4104, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=11.00  BV=0.05
    {2032,16384,4096, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=11.00  BV=-0.06
    {2170,16384,4096, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=11.00  BV=-0.15
    {2327,16384,4088, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=11.00  BV=-0.25
    {2501,16384,4096, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=11.00  BV=-0.36
    {2676,16384,4096, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=11.00  BV=-0.45
    {2869,16384,4088, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=11.00  BV=-0.55
    {3071,16384,4088, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=11.00  BV=-0.65
    {3301,16384,4096, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=11.00  BV=-0.76
    {3540,16384,4088, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=11.00  BV=-0.86
    {3788,16384,4088, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=11.00  BV=-0.95
    {4055,16384,4088, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=11.00  BV=-1.05
    {4340,16384,4088, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=11.00  BV=-1.15
    {4671,16384,4096, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=11.00  BV=-1.26
    {5002,16384,4096, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=11.00  BV=-1.36
    {5361,16384,4088, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=11.00  BV=-1.45
    {5738,16384,4096, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=11.00  BV=-1.55
    {6142,16384,4096, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=11.00  BV=-1.65
    {6583,16384,4088, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=11.00  BV=-1.75
    {7052,16384,4088, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=11.00  BV=-1.85
    {7549,16384,4096, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=11.00  BV=-1.95
    {8146,16384,4088, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=11.00  BV=-2.06
    {8330,16384,4288, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.07  BV=-2.16
    {8330,16384,4592, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.16  BV=-2.26
    {8330,16384,4920, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.26  BV=-2.36
    {8330,16384,5272, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.36  BV=-2.46
    {8330,16384,5648, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.46  BV=-2.56
    {8330,16384,6048, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=11.56  BV=-2.65
    {16669,16384,3240, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.66  BV=-2.76
    {16669,16384,3472, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.76  BV=-2.85
    {16669,16384,3720, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.86  BV=-2.95
    {16669,16384,3984, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=10.96  BV=-3.05
    {16669,16384,4264, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.06  BV=-3.15
    {16669,16384,4568, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.16  BV=-3.25
    {16669,16384,4896, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.26  BV=-3.35
    {24999,16384,3496, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.77  BV=-3.45
    {24999,16384,3752, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.87  BV=-3.55
    {24999,16384,4016, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.97  BV=-3.65
    {24999,16384,4304, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=11.07  BV=-3.75
    {24999,16384,4616, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=11.17  BV=-3.85
    {33329,16384,3704, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.85  BV=-3.95
    {33329,16384,3976, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.96  BV=-4.05
    {33329,16384,4256, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=11.06  BV=-4.15
    {33329,16384,4560, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=11.15  BV=-4.25
    {41668,16384,3936, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.94  BV=-4.36
    {41668,16384,4224, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=11.04  BV=-4.46
    {49997,16384,3768, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.88  BV=-4.56
    {49997,16384,4040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.98  BV=-4.66
    {49997,16384,4328, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.08  BV=-4.76
    {58327,16384,3976, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.96  BV=-4.86
    {58327,16384,4264, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=11.06  BV=-4.96
    {66666,16384,3992, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.96  BV=-5.06
    {66666,16384,4280, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=11.06  BV=-5.16
    {74996,16384,4080, 0, 0, 0},  //TV = 3.74(8157 lines)  AV=2.00  SV=10.99  BV=-5.26
    {83335,16384,3936, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=10.94  BV=-5.36
    {83335,16384,4216, 0, 0, 0},  //TV = 3.58(9064 lines)  AV=2.00  SV=11.04  BV=-5.46
    {91665,16384,4112, 0, 0, 0},  //TV = 3.45(9970 lines)  AV=2.00  SV=11.01  BV=-5.56
    {99994,16384,4040, 0, 0, 0},  //TV = 3.32(10876 lines)  AV=2.00  SV=10.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene7PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {497,16384,2080, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.02  BV=2.95
    {497,16384,2232, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.12  BV=2.85
    {497,16384,2392, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.22  BV=2.75
    {497,16384,2560, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.32  BV=2.65
    {497,16384,2744, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.42  BV=2.55
    {497,16384,2944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.52  BV=2.45
    {497,16384,3152, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.62  BV=2.35
    {497,16384,3400, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.73  BV=2.24
    {497,16384,3648, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.83  BV=2.14
    {497,16384,3912, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.93  BV=2.04
    {506,16384,4096, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=11.00  BV=1.95
    {543,16384,4088, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=11.00  BV=1.85
    {580,16384,4104, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=11.00  BV=1.75
    {626,16384,4096, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=11.00  BV=1.64
    {672,16384,4080, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=10.99  BV=1.54
    {718,16384,4096, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=11.00  BV=1.44
    {764,16384,4112, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=11.01  BV=1.35
    {819,16384,4104, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=11.00  BV=1.25
    {883,16384,4104, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=11.00  BV=1.14
    {947,16384,4080, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=10.99  BV=1.05
    {1012,16384,4088, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=11.00  BV=0.95
    {1085,16384,4104, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=11.00  BV=0.85
    {1168,16384,4088, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=11.00  BV=0.74
    {1251,16384,4080, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=10.99  BV=0.65
    {1343,16384,4080, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=10.99  BV=0.55
    {1435,16384,4080, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=10.99  BV=0.45
    {1536,16384,4104, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=11.00  BV=0.34
    {1646,16384,4088, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=11.00  BV=0.25
    {1766,16384,4096, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=11.00  BV=0.15
    {1885,16384,4104, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=11.00  BV=0.05
    {2032,16384,4096, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=11.00  BV=-0.06
    {2170,16384,4096, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=11.00  BV=-0.15
    {2327,16384,4088, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=11.00  BV=-0.25
    {2501,16384,4096, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=11.00  BV=-0.36
    {2676,16384,4096, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=11.00  BV=-0.45
    {2869,16384,4088, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=11.00  BV=-0.55
    {3071,16384,4088, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=11.00  BV=-0.65
    {3301,16384,4096, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=11.00  BV=-0.76
    {3540,16384,4088, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=11.00  BV=-0.86
    {3788,16384,4088, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=11.00  BV=-0.95
    {4055,16384,4088, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=11.00  BV=-1.05
    {4340,16384,4088, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=11.00  BV=-1.15
    {4671,16384,4096, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=11.00  BV=-1.26
    {5002,16384,4096, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=11.00  BV=-1.36
    {5361,16384,4088, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=11.00  BV=-1.45
    {5738,16384,4096, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=11.00  BV=-1.55
    {6142,16384,4096, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=11.00  BV=-1.65
    {6583,16384,4088, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=11.00  BV=-1.75
    {7052,16384,4088, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=11.00  BV=-1.85
    {7549,16384,4096, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=11.00  BV=-1.95
    {8146,16384,4088, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=11.00  BV=-2.06
    {8726,16384,4088, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=11.00  BV=-2.16
    {9342,16384,4096, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=11.00  BV=-2.26
    {10004,16384,4096, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.00  BV=-2.36
    {10004,16384,4384, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.10  BV=-2.45
    {10004,16384,4704, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.20  BV=-2.56
    {10004,16384,5040, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.30  BV=-2.66
    {10004,16384,5392, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.40  BV=-2.75
    {10004,16384,5784, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=11.50  BV=-2.85
    {19997,16384,3096, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.60  BV=-2.95
    {19997,16384,3320, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.70  BV=-3.05
    {19997,16384,3560, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.80  BV=-3.15
    {19997,16384,3808, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.89  BV=-3.25
    {19997,16384,4080, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=10.99  BV=-3.35
    {19997,16384,4376, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.10  BV=-3.45
    {19997,16384,4688, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.19  BV=-3.55
    {19997,16384,5024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.29  BV=-3.65
    {30001,16384,3584, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.81  BV=-3.75
    {30001,16384,3848, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.91  BV=-3.85
    {30001,16384,4120, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=11.01  BV=-3.95
    {30001,16384,4416, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=11.11  BV=-4.05
    {30001,16384,4728, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=11.21  BV=-4.15
    {40004,16384,3824, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.90  BV=-4.26
    {40004,16384,4104, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=11.00  BV=-4.36
    {40004,16384,4400, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=11.10  BV=-4.46
    {49997,16384,3768, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.88  BV=-4.56
    {49997,16384,4040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.98  BV=-4.66
    {49997,16384,4328, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.08  BV=-4.76
    {60001,16384,3864, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.92  BV=-4.86
    {60001,16384,4144, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=11.02  BV=-4.96
    {70004,16384,3808, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.89  BV=-5.06
    {70004,16384,4080, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.99  BV=-5.16
    {70004,16384,4368, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=11.09  BV=-5.26
    {79997,16384,4096, 0, 0, 0},  //TV = 3.64(8701 lines)  AV=2.00  SV=11.00  BV=-5.36
    {90001,16384,3904, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=10.93  BV=-5.46
    {90001,16384,4184, 0, 0, 0},  //TV = 3.47(9789 lines)  AV=2.00  SV=11.03  BV=-5.56
    {100004,16384,4040, 0, 0, 0},  //TV = 3.32(10877 lines)  AV=2.00  SV=10.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable7 =
{
    AETABLE_SCENE_INDEX7, //eAETableID
    159, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -57, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene7PLineTable_60Hz,
    sAEScene7PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene8PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {497,16384,2080, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.02  BV=2.95
    {497,16384,2232, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.12  BV=2.85
    {497,16384,2392, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.22  BV=2.75
    {497,16384,2560, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.32  BV=2.65
    {497,16384,2744, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.42  BV=2.55
    {497,16384,2944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.52  BV=2.45
    {497,16384,3152, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.62  BV=2.35
    {497,16384,3400, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.73  BV=2.24
    {497,16384,3648, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.83  BV=2.14
    {497,16384,3912, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.93  BV=2.04
    {497,16384,4192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.03  BV=1.94
    {497,16384,4488, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.13  BV=1.84
    {497,16384,4816, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.23  BV=1.74
    {497,16384,5160, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.33  BV=1.64
    {497,16384,5528, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.43  BV=1.54
    {497,16384,5928, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.53  BV=1.44
    {497,16384,6352, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.63  BV=1.34
    {497,16384,6808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.73  BV=1.24
    {497,16384,7296, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.83  BV=1.14
    {497,16384,7816, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.93  BV=1.04
    {506,16384,8192, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=12.00  BV=0.95
    {543,16384,8176, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=12.00  BV=0.85
    {580,16384,8216, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=12.00  BV=0.75
    {626,16384,8192, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=12.00  BV=0.64
    {672,16384,8160, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=11.99  BV=0.54
    {718,16384,8192, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=12.00  BV=0.44
    {764,16384,8224, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=12.01  BV=0.35
    {819,16384,8216, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=12.00  BV=0.25
    {883,16384,8208, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=12.00  BV=0.14
    {947,16384,8168, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=12.00  BV=0.05
    {1012,16384,8184, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=12.00  BV=-0.05
    {1085,16384,8208, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=12.00  BV=-0.15
    {1168,16384,8184, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=12.00  BV=-0.26
    {1251,16384,8160, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=11.99  BV=-0.35
    {1343,16384,8168, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=12.00  BV=-0.46
    {1435,16384,8160, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=11.99  BV=-0.55
    {1536,16384,8208, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=12.00  BV=-0.66
    {1646,16384,8176, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=12.00  BV=-0.75
    {1766,16384,8200, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=12.00  BV=-0.86
    {1885,16384,8208, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=12.00  BV=-0.95
    {2032,16384,8192, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=12.00  BV=-1.06
    {2170,16384,8200, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=12.00  BV=-1.15
    {2327,16384,8184, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=12.00  BV=-1.25
    {2501,16384,8200, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=12.00  BV=-1.36
    {2676,16384,8200, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=12.00  BV=-1.46
    {2869,16384,8176, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=12.00  BV=-1.55
    {3071,16384,8176, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=12.00  BV=-1.65
    {3301,16384,8192, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=12.00  BV=-1.76
    {3540,16384,8176, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=12.00  BV=-1.86
    {3788,16384,8176, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=12.00  BV=-1.95
    {4055,16384,8176, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=12.00  BV=-2.05
    {4340,16384,8176, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=12.00  BV=-2.15
    {4671,16384,8192, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=12.00  BV=-2.26
    {5002,16384,8192, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=12.00  BV=-2.36
    {5361,16384,8184, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=12.00  BV=-2.46
    {5738,16384,8192, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=12.00  BV=-2.55
    {6142,16384,8192, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=12.00  BV=-2.65
    {6583,16384,8184, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=12.00  BV=-2.75
    {7052,16384,8184, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=12.00  BV=-2.85
    {7549,16384,8192, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=12.00  BV=-2.95
    {8146,16384,8184, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=12.00  BV=-3.06
    {8330,16384,8576, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.07  BV=-3.16
    {8330,16384,9184, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.16  BV=-3.26
    {8330,16384,9840, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.26  BV=-3.36
    {8330,16384,10544, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.36  BV=-3.46
    {8330,16384,11296, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.46  BV=-3.56
    {8330,16384,12104, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=12.56  BV=-3.66
    {16669,16384,6480, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.66  BV=-3.76
    {16669,16384,6936, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.76  BV=-3.85
    {16669,16384,7432, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.86  BV=-3.95
    {16669,16384,7968, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=11.96  BV=-4.05
    {16669,16384,8536, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=12.06  BV=-4.15
    {16669,16384,9144, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=12.16  BV=-4.25
    {16669,16384,9800, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=12.26  BV=-4.35
    {24999,16384,7000, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=11.77  BV=-4.45
    {24999,16384,7504, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=11.87  BV=-4.55
    {24999,16384,8040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=11.97  BV=-4.65
    {24999,16384,8616, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=12.07  BV=-4.75
    {24999,16384,9232, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=12.17  BV=-4.85
    {33329,16384,7416, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=11.86  BV=-4.95
    {33329,16384,7952, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=11.96  BV=-5.05
    {33329,16384,8520, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=12.06  BV=-5.15
    {33329,16384,9128, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=12.16  BV=-5.25
    {41668,16384,7880, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=11.94  BV=-5.36
    {41668,16384,8448, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=12.04  BV=-5.46
    {49997,16384,7544, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.88  BV=-5.56
    {49997,16384,8080, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene8PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {497,1280,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.32  BV=7.65
    {497,1376,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.43  BV=7.55
    {497,1472,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.52  BV=7.45
    {497,1568,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.63  BV=7.35
    {497,1696,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.73  BV=7.25
    {497,1824,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.83  BV=7.14
    {497,1920,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.92  BV=7.06
    {497,2080,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.02  BV=6.95
    {497,2240,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.13  BV=6.85
    {497,2400,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.23  BV=6.75
    {497,2560,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.33  BV=6.64
    {497,2752,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.43  BV=6.55
    {497,2944,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.52  BV=6.45
    {497,3136,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.61  BV=6.36
    {497,3360,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.71  BV=6.26
    {497,3616,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.82  BV=6.15
    {497,3904,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=6.93  BV=6.04
    {497,4160,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.02  BV=5.95
    {497,4448,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.12  BV=5.86
    {497,4800,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.23  BV=5.75
    {497,5152,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.33  BV=5.64
    {497,5504,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.43  BV=5.55
    {497,5888,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.52  BV=5.45
    {497,6336,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.63  BV=5.35
    {497,6784,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.73  BV=5.25
    {497,7264,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.83  BV=5.15
    {497,7776,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=7.92  BV=5.05
    {497,8320,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.02  BV=4.95
    {497,8960,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.13  BV=4.85
    {497,9632,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.23  BV=4.74
    {497,10304,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.33  BV=4.64
    {497,11040,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.43  BV=4.54
    {497,11840,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.53  BV=4.44
    {497,12672,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.63  BV=4.35
    {497,13568,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.73  BV=4.25
    {497,14528,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.83  BV=4.15
    {497,15584,1024, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=8.93  BV=4.05
    {497,16384,1040, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.02  BV=3.95
    {497,16384,1112, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.12  BV=3.86
    {497,16384,1192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.22  BV=3.76
    {497,16384,1280, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.32  BV=3.65
    {497,16384,1376, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.43  BV=3.55
    {497,16384,1472, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.52  BV=3.45
    {497,16384,1576, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.62  BV=3.35
    {497,16384,1688, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.72  BV=3.25
    {497,16384,1808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.82  BV=3.15
    {497,16384,1944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=9.92  BV=3.05
    {497,16384,2080, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.02  BV=2.95
    {497,16384,2232, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.12  BV=2.85
    {497,16384,2392, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.22  BV=2.75
    {497,16384,2560, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.32  BV=2.65
    {497,16384,2744, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.42  BV=2.55
    {497,16384,2944, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.52  BV=2.45
    {497,16384,3152, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.62  BV=2.35
    {497,16384,3400, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.73  BV=2.24
    {497,16384,3648, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.83  BV=2.14
    {497,16384,3912, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=10.93  BV=2.04
    {497,16384,4192, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.03  BV=1.94
    {497,16384,4488, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.13  BV=1.84
    {497,16384,4816, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.23  BV=1.74
    {497,16384,5160, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.33  BV=1.64
    {497,16384,5528, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.43  BV=1.54
    {497,16384,5928, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.53  BV=1.44
    {497,16384,6352, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.63  BV=1.34
    {497,16384,6808, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.73  BV=1.24
    {497,16384,7296, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.83  BV=1.14
    {497,16384,7816, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=11.93  BV=1.04
    {506,16384,8192, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=12.00  BV=0.95
    {543,16384,8176, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=12.00  BV=0.85
    {580,16384,8216, 0, 0, 0},  //TV = 10.75(63 lines)  AV=2.00  SV=12.00  BV=0.75
    {626,16384,8192, 0, 0, 0},  //TV = 10.64(68 lines)  AV=2.00  SV=12.00  BV=0.64
    {672,16384,8160, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=11.99  BV=0.54
    {718,16384,8192, 0, 0, 0},  //TV = 10.44(78 lines)  AV=2.00  SV=12.00  BV=0.44
    {764,16384,8224, 0, 0, 0},  //TV = 10.35(83 lines)  AV=2.00  SV=12.01  BV=0.35
    {819,16384,8216, 0, 0, 0},  //TV = 10.25(89 lines)  AV=2.00  SV=12.00  BV=0.25
    {883,16384,8208, 0, 0, 0},  //TV = 10.15(96 lines)  AV=2.00  SV=12.00  BV=0.14
    {947,16384,8168, 0, 0, 0},  //TV = 10.04(103 lines)  AV=2.00  SV=12.00  BV=0.05
    {1012,16384,8184, 0, 0, 0},  //TV = 9.95(110 lines)  AV=2.00  SV=12.00  BV=-0.05
    {1085,16384,8208, 0, 0, 0},  //TV = 9.85(118 lines)  AV=2.00  SV=12.00  BV=-0.15
    {1168,16384,8184, 0, 0, 0},  //TV = 9.74(127 lines)  AV=2.00  SV=12.00  BV=-0.26
    {1251,16384,8160, 0, 0, 0},  //TV = 9.64(136 lines)  AV=2.00  SV=11.99  BV=-0.35
    {1343,16384,8168, 0, 0, 0},  //TV = 9.54(146 lines)  AV=2.00  SV=12.00  BV=-0.46
    {1435,16384,8160, 0, 0, 0},  //TV = 9.44(156 lines)  AV=2.00  SV=11.99  BV=-0.55
    {1536,16384,8208, 0, 0, 0},  //TV = 9.35(167 lines)  AV=2.00  SV=12.00  BV=-0.66
    {1646,16384,8176, 0, 0, 0},  //TV = 9.25(179 lines)  AV=2.00  SV=12.00  BV=-0.75
    {1766,16384,8200, 0, 0, 0},  //TV = 9.15(192 lines)  AV=2.00  SV=12.00  BV=-0.86
    {1885,16384,8208, 0, 0, 0},  //TV = 9.05(205 lines)  AV=2.00  SV=12.00  BV=-0.95
    {2032,16384,8192, 0, 0, 0},  //TV = 8.94(221 lines)  AV=2.00  SV=12.00  BV=-1.06
    {2170,16384,8200, 0, 0, 0},  //TV = 8.85(236 lines)  AV=2.00  SV=12.00  BV=-1.15
    {2327,16384,8184, 0, 0, 0},  //TV = 8.75(253 lines)  AV=2.00  SV=12.00  BV=-1.25
    {2501,16384,8200, 0, 0, 0},  //TV = 8.64(272 lines)  AV=2.00  SV=12.00  BV=-1.36
    {2676,16384,8200, 0, 0, 0},  //TV = 8.55(291 lines)  AV=2.00  SV=12.00  BV=-1.46
    {2869,16384,8176, 0, 0, 0},  //TV = 8.45(312 lines)  AV=2.00  SV=12.00  BV=-1.55
    {3071,16384,8176, 0, 0, 0},  //TV = 8.35(334 lines)  AV=2.00  SV=12.00  BV=-1.65
    {3301,16384,8192, 0, 0, 0},  //TV = 8.24(359 lines)  AV=2.00  SV=12.00  BV=-1.76
    {3540,16384,8176, 0, 0, 0},  //TV = 8.14(385 lines)  AV=2.00  SV=12.00  BV=-1.86
    {3788,16384,8176, 0, 0, 0},  //TV = 8.04(412 lines)  AV=2.00  SV=12.00  BV=-1.95
    {4055,16384,8176, 0, 0, 0},  //TV = 7.95(441 lines)  AV=2.00  SV=12.00  BV=-2.05
    {4340,16384,8176, 0, 0, 0},  //TV = 7.85(472 lines)  AV=2.00  SV=12.00  BV=-2.15
    {4671,16384,8192, 0, 0, 0},  //TV = 7.74(508 lines)  AV=2.00  SV=12.00  BV=-2.26
    {5002,16384,8192, 0, 0, 0},  //TV = 7.64(544 lines)  AV=2.00  SV=12.00  BV=-2.36
    {5361,16384,8184, 0, 0, 0},  //TV = 7.54(583 lines)  AV=2.00  SV=12.00  BV=-2.46
    {5738,16384,8192, 0, 0, 0},  //TV = 7.45(624 lines)  AV=2.00  SV=12.00  BV=-2.55
    {6142,16384,8192, 0, 0, 0},  //TV = 7.35(668 lines)  AV=2.00  SV=12.00  BV=-2.65
    {6583,16384,8184, 0, 0, 0},  //TV = 7.25(716 lines)  AV=2.00  SV=12.00  BV=-2.75
    {7052,16384,8184, 0, 0, 0},  //TV = 7.15(767 lines)  AV=2.00  SV=12.00  BV=-2.85
    {7549,16384,8192, 0, 0, 0},  //TV = 7.05(821 lines)  AV=2.00  SV=12.00  BV=-2.95
    {8146,16384,8184, 0, 0, 0},  //TV = 6.94(886 lines)  AV=2.00  SV=12.00  BV=-3.06
    {8726,16384,8184, 0, 0, 0},  //TV = 6.84(949 lines)  AV=2.00  SV=12.00  BV=-3.16
    {9342,16384,8192, 0, 0, 0},  //TV = 6.74(1016 lines)  AV=2.00  SV=12.00  BV=-3.26
    {10004,16384,8192, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.00  BV=-3.36
    {10004,16384,8776, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.10  BV=-3.46
    {10004,16384,9408, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.20  BV=-3.56
    {10004,16384,10072, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.30  BV=-3.65
    {10004,16384,10792, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.40  BV=-3.75
    {10004,16384,11568, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=12.50  BV=-3.85
    {19997,16384,6200, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.60  BV=-3.95
    {19997,16384,6640, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.70  BV=-4.05
    {19997,16384,7112, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.80  BV=-4.15
    {19997,16384,7624, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=11.90  BV=-4.25
    {19997,16384,8168, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=12.00  BV=-4.35
    {19997,16384,8752, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=12.10  BV=-4.45
    {19997,16384,9376, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=12.19  BV=-4.55
    {19997,16384,10048, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=12.29  BV=-4.65
    {30001,16384,7176, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=11.81  BV=-4.75
    {30001,16384,7688, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=11.91  BV=-4.85
    {30001,16384,8240, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=12.01  BV=-4.95
    {30001,16384,8832, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=12.11  BV=-5.05
    {30001,16384,9464, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=12.21  BV=-5.15
    {40004,16384,7608, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=11.89  BV=-5.25
    {40004,16384,8208, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=12.00  BV=-5.36
    {40004,16384,8800, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=12.10  BV=-5.46
    {49997,16384,7544, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.88  BV=-5.56
    {49997,16384,8080, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=11.98  BV=-5.66
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable8 =
{
    AETABLE_SCENE_INDEX8, //eAETableID
    159, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -57, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene8PLineTable_60Hz,
    sAEScene8PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene9PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {16670,1856,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.86  BV=2.05
    {16670,1984,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.97  BV=1.94
    {16669,2112,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.06  BV=1.85
    {16669,2272,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.15  BV=1.76
    {16669,2432,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=6.25  BV=1.66
    {24999,1728,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.77  BV=1.56
    {24999,1888,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.88  BV=1.44
    {24999,2016,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.98  BV=1.34
    {24999,2144,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.07  BV=1.26
    {24999,2304,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.17  BV=1.15
    {24999,2464,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.28  BV=1.04
    {24999,2656,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.38  BV=0.95
    {24999,2848,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.48  BV=0.85
    {24999,3040,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.57  BV=0.75
    {24999,3264,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.67  BV=0.65
    {24999,3488,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.77  BV=0.55
    {24999,3744,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.87  BV=0.45
    {24999,4000,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=6.97  BV=0.36
    {24999,4320,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.08  BV=0.25
    {24999,4640,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.18  BV=0.14
    {24999,4960,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.28  BV=0.05
    {24999,5312,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.38  BV=-0.05
    {24999,5696,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.48  BV=-0.15
    {24999,6080,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.57  BV=-0.25
    {24999,6528,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.67  BV=-0.35
    {24999,6976,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.77  BV=-0.45
    {24999,7488,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.87  BV=-0.55
    {24999,8064,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=7.98  BV=-0.66
    {24999,8640,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.08  BV=-0.75
    {24999,9280,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.18  BV=-0.86
    {24999,9920,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.28  BV=-0.95
    {24999,10624,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.38  BV=-1.05
    {24999,11392,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.48  BV=-1.15
    {24999,12224,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.58  BV=-1.26
    {24999,13088,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.68  BV=-1.35
    {24999,14016,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.77  BV=-1.45
    {24999,15008,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.87  BV=-1.55
    {24999,16096,1024, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=8.97  BV=-1.65
    {24999,16384,1072, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.07  BV=-1.74
    {24999,16384,1152, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.17  BV=-1.85
    {24999,16384,1232, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.27  BV=-1.94
    {24999,16384,1320, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.37  BV=-2.04
    {24999,16384,1416, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.47  BV=-2.15
    {24999,16384,1520, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.57  BV=-2.25
    {24999,16384,1632, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.67  BV=-2.35
    {24999,16384,1744, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.77  BV=-2.45
    {24999,16384,1872, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.87  BV=-2.55
    {24999,16384,2008, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=9.97  BV=-2.65
    {24999,16384,2152, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.07  BV=-2.75
    {24999,16384,2320, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.18  BV=-2.86
    {24999,16384,2488, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.28  BV=-2.96
    {24999,16384,2664, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.38  BV=-3.06
    {24999,16384,2856, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=10.48  BV=-3.16
    {24999,16384,2880, 0, 0, 0},  /* TV = 5.32(2719 lines)  AV=2.00  SV=10.49  BV=-3.17 */
    {24999,16384,2880, 0, 0, 0},  /* TV = 5.32(2719 lines)  AV=2.00  SV=10.49  BV=-3.17 */
    {24999,16384,2880, 0, 0, 0},  /* TV = 5.32(2719 lines)  AV=2.00  SV=10.49  BV=-3.17 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene9PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {10004,2496,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.30  BV=2.35
    {10004,2688,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.39  BV=2.25
    {10004,2880,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.49  BV=2.15
    {10004,3072,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.60  BV=2.05
    {10004,3296,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.69  BV=1.96
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {19997,1888,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.89  BV=1.75
    {19997,2016,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.99  BV=1.66
    {19997,2176,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.09  BV=1.56
    {19997,2336,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.19  BV=1.45
    {19997,2496,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=6.29  BV=1.36
    {30001,1792,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.81  BV=1.25
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2560,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.32  BV=0.74
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3872,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.92  BV=0.14
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5824,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.51  BV=-0.45
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7200,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8256,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10176,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.31  BV=-1.25
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.51  BV=-1.45
    {30001,12512,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.55
    {30001,13408,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.65
    {30001,14368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.81  BV=-1.75
    {30001,15392,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.91  BV=-1.85
    {30001,16384,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.01  BV=-1.95
    {30001,16384,1104, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.11  BV=-2.05
    {30001,16384,1184, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.21  BV=-2.15
    {30001,16384,1264, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.30  BV=-2.24
    {30001,16384,1360, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.41  BV=-2.35
    {30001,16384,1456, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.51  BV=-2.45
    {30001,16384,1560, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.61  BV=-2.55
    {30001,16384,1672, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.71  BV=-2.65
    {30001,16384,1792, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.81  BV=-2.75
    {30001,16384,1936, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.92  BV=-2.86
    {30001,16384,2072, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.02  BV=-2.96
    {30001,16384,2216, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.11  BV=-3.05
    {30001,16384,2376, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.21  BV=-3.16
    {30001,16384,2552, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.32  BV=-3.26
    {30001,16384,2736, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.42  BV=-3.36
    {30001,16384,2880, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.49  BV=-3.43
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable9 =
{
    AETABLE_SCENE_INDEX9, //eAETableID
    137, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -35, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene9PLineTable_60Hz,
    sAEScene9PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene14PLineTable_60Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8330,1216,1040, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.27  BV=3.64
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.26  BV=1.65
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {41669,1184,1040, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.23  BV=1.35
    {41669,1280,1032, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.33  BV=1.25
    {41669,1376,1032, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=5.44  BV=1.15
    {49997,1216,1040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.27  BV=1.05
    {49997,1312,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.37  BV=0.95
    {58327,1216,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.25  BV=0.85
    {58327,1312,1024, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=5.36  BV=0.74
    {66667,1216,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.25  BV=0.66
    {66667,1312,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.36  BV=0.55
    {66667,1408,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.46  BV=0.45
    {66667,1504,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.55  BV=0.35
    {66667,1600,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.66  BV=0.25
    {66667,1728,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.75  BV=0.15
    {66667,1856,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.86  BV=0.05
    {66667,1984,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=5.95  BV=-0.05
    {66667,2144,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.07  BV=-0.16
    {66667,2272,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.16  BV=-0.25
    {66667,2432,1032, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.26  BV=-0.35
    {66667,2624,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.36  BV=-0.45
    {66667,2816,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.46  BV=-0.55
    {66667,3008,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.55  BV=-0.65
    {66667,3232,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.66  BV=-0.75
    {66667,3456,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.75  BV=-0.85
    {66667,3712,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.86  BV=-0.95
    {66667,4000,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=6.97  BV=-1.06
    {66667,4256,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.06  BV=-1.15
    {66667,4576,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.16  BV=-1.25
    {66667,4896,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.26  BV=-1.35
    {66667,5248,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.36  BV=-1.45
    {66667,5600,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.45  BV=-1.54
    {66667,6048,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.56  BV=-1.66
    {66667,6464,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.66  BV=-1.75
    {66667,6944,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.76  BV=-1.85
    {66667,7424,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.86  BV=-1.95
    {66667,7968,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=7.96  BV=-2.05
    {66667,8544,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.06  BV=-2.15
    {66667,9152,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.16  BV=-2.25
    {66667,9792,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.26  BV=-2.35
    {66667,10496,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.36  BV=-2.45
    {66667,11232,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.46  BV=-2.55
    {66667,12032,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.55  BV=-2.65
    {66667,12896,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.65  BV=-2.75
    {66667,13920,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.76  BV=-2.86
    {66667,14912,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.86  BV=-2.96
    {66667,16000,1024, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=8.97  BV=-3.06
    {66667,16384,1064, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.06  BV=-3.15
    {66667,16384,1144, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.16  BV=-3.25
    {66667,16384,1224, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.26  BV=-3.35
    {66667,16384,1312, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.36  BV=-3.45
    {66667,16384,1408, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.46  BV=-3.55
    {66667,16384,1512, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.56  BV=-3.66
    {66667,16384,1616, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.66  BV=-3.75
    {66667,16384,1736, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.76  BV=-3.85
    {66667,16384,1856, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.86  BV=-3.95
    {66667,16384,1992, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=9.96  BV=-4.05
    {66667,16384,2136, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.06  BV=-4.15
    {66667,16384,2288, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.16  BV=-4.25
    {66667,16384,2448, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.26  BV=-4.35
    {66667,16384,2624, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.36  BV=-4.45
    {66667,16384,2816, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {66667,16384,2880, 0, 0, 0},  /* TV = 3.91(7251 lines)  AV=2.00  SV=10.49  BV=-4.58 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene14PLineTable_50Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8808,1160,1024, 0, 0, 0},  //TV = 6.83(958 lines)  AV=2.00  SV=5.18  BV=3.65
    {9443,1160,1024, 0, 0, 0},  //TV = 6.73(1027 lines)  AV=2.00  SV=5.18  BV=3.55
    {10004,1160,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.19  BV=3.45
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {30001,1184,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.21  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.41  BV=1.64
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {40004,1160,1032, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.19  BV=1.45
    {40004,1248,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.29  BV=1.36
    {40004,1344,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.39  BV=1.25
    {40004,1440,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=5.49  BV=1.15
    {49997,1216,1040, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.27  BV=1.05
    {49997,1312,1032, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=5.37  BV=0.95
    {60001,1184,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.21  BV=0.85
    {60001,1248,1040, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.31  BV=0.75
    {60001,1344,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.40  BV=0.66
    {60001,1472,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.52  BV=0.54
    {60001,1568,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.61  BV=0.44
    {60001,1664,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.71  BV=0.35
    {60001,1792,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.81  BV=0.25
    {60001,1920,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=5.91  BV=0.15
    {60001,2048,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.01  BV=0.05
    {60001,2208,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.11  BV=-0.05
    {60001,2368,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.21  BV=-0.15
    {60001,2528,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.32  BV=-0.26
    {60001,2720,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.41  BV=-0.35
    {60001,2912,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.51  BV=-0.45
    {60001,3136,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.61  BV=-0.56
    {60001,3360,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.71  BV=-0.66
    {60001,3584,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.81  BV=-0.75
    {60001,3840,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=6.91  BV=-0.85
    {60001,4128,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.01  BV=-0.95
    {60001,4416,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.11  BV=-1.05
    {60001,4736,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.21  BV=-1.15
    {60001,5088,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.31  BV=-1.25
    {60001,5440,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.41  BV=-1.35
    {60001,5824,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.51  BV=-1.45
    {60001,6240,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.61  BV=-1.55
    {60001,6720,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.71  BV=-1.66
    {60001,7200,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.81  BV=-1.75
    {60001,7712,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=7.91  BV=-1.85
    {60001,8256,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.01  BV=-1.95
    {60001,8864,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.11  BV=-2.05
    {60001,9472,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.21  BV=-2.15
    {60001,10144,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.31  BV=-2.25
    {60001,10880,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.41  BV=-2.35
    {60001,11648,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.51  BV=-2.45
    {60001,12480,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.61  BV=-2.55
    {60001,13376,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.71  BV=-2.65
    {60001,14336,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.81  BV=-2.75
    {60001,15488,1024, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=8.92  BV=-2.86
    {60001,16384,1032, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.01  BV=-2.95
    {60001,16384,1104, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.11  BV=-3.05
    {60001,16384,1184, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.21  BV=-3.15
    {60001,16384,1272, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.31  BV=-3.25
    {60001,16384,1360, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.41  BV=-3.35
    {60001,16384,1464, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.52  BV=-3.46
    {60001,16384,1568, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.61  BV=-3.56
    {60001,16384,1680, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.71  BV=-3.66
    {60001,16384,1800, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.81  BV=-3.75
    {60001,16384,1928, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=9.91  BV=-3.85
    {60001,16384,2064, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.01  BV=-3.95
    {60001,16384,2216, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.11  BV=-4.05
    {60001,16384,2368, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.21  BV=-4.15
    {60001,16384,2544, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.31  BV=-4.25
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2880, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.49  BV=-4.43
    {60001,16384,2880, 0, 0, 0},  /* TV = 4.06(6526 lines)  AV=2.00  SV=10.49  BV=-4.43 */
    {60001,16384,2880, 0, 0, 0},  /* TV = 4.06(6526 lines)  AV=2.00  SV=10.49  BV=-4.43 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable14 =
{
    AETABLE_SCENE_INDEX14, //eAETableID
    149, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -46, //i4MinBV
    0, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene14PLineTable_60Hz,
    sAEScene14PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene15PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {41668,13696,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.74  BV=-2.16
    {41668,14688,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.84  BV=-2.26
    {41668,15744,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.94  BV=-2.36
    {41668,16384,1048, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.03  BV=-2.45
    {41668,16384,1128, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.14  BV=-2.55
    {41668,16384,1208, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.24  BV=-2.65
    {41668,16384,1296, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.34  BV=-2.75
    {41668,16384,1384, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.43  BV=-2.85
    {41668,16384,1488, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.54  BV=-2.95
    {41668,16384,1592, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.64  BV=-3.05
    {41668,16384,1704, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.73  BV=-3.15
    {41668,16384,1832, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.84  BV=-3.25
    {41668,16384,1960, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.94  BV=-3.35
    {41668,16384,2104, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.04  BV=-3.45
    {41668,16384,2256, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.14  BV=-3.55
    {41668,16384,2416, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.24  BV=-3.65
    {41668,16384,2584, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.34  BV=-3.75
    {41668,16384,2776, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.44  BV=-3.85
    {41668,16384,2976, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.54  BV=-3.95
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {58327,16384,2808, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.46  BV=-4.36
    {58327,16384,3008, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.55  BV=-4.45
    {66666,16384,2816, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene15PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {40004,14272,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.80  BV=-2.16
    {40004,15296,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.90  BV=-2.26
    {40004,16384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.00  BV=-2.36
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {40004,16384,1176, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.20  BV=-2.56
    {40004,16384,1256, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.29  BV=-2.65
    {40004,16384,1344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.39  BV=-2.75
    {40004,16384,1448, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.50  BV=-2.86
    {40004,16384,1544, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.59  BV=-2.95
    {40004,16384,1656, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.69  BV=-3.05
    {40004,16384,1776, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.79  BV=-3.15
    {40004,16384,1904, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.89  BV=-3.25
    {40004,16384,2040, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.99  BV=-3.35
    {40004,16384,2192, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.10  BV=-3.45
    {40004,16384,2344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.19  BV=-3.55
    {40004,16384,2512, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.29  BV=-3.65
    {40004,16384,2696, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.40  BV=-3.75
    {40004,16384,2888, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.50  BV=-3.85
    {40004,16384,3104, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.60  BV=-3.96
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2920, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.51  BV=-4.45
    {70004,16384,2688, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.56
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable15 =
{
    AETABLE_SCENE_INDEX15, //eAETableID
    148, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -46, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene15PLineTable_60Hz,
    sAEScene15PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene16PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {41668,13696,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.74  BV=-2.16
    {41668,14688,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.84  BV=-2.26
    {41668,15744,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.94  BV=-2.36
    {41668,16384,1048, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.03  BV=-2.45
    {41668,16384,1128, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.14  BV=-2.55
    {41668,16384,1208, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.24  BV=-2.65
    {41668,16384,1296, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.34  BV=-2.75
    {41668,16384,1384, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.43  BV=-2.85
    {41668,16384,1488, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.54  BV=-2.95
    {41668,16384,1592, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.64  BV=-3.05
    {41668,16384,1704, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.73  BV=-3.15
    {41668,16384,1832, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.84  BV=-3.25
    {41668,16384,1960, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.94  BV=-3.35
    {41668,16384,2104, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.04  BV=-3.45
    {41668,16384,2256, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.14  BV=-3.55
    {41668,16384,2416, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.24  BV=-3.65
    {41668,16384,2584, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.34  BV=-3.75
    {41668,16384,2776, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.44  BV=-3.85
    {41668,16384,2976, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.54  BV=-3.95
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {58327,16384,2808, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.46  BV=-4.36
    {58327,16384,3008, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.55  BV=-4.45
    {66666,16384,2816, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene16PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {40004,14272,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.80  BV=-2.16
    {40004,15296,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.90  BV=-2.26
    {40004,16384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.00  BV=-2.36
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {40004,16384,1176, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.20  BV=-2.56
    {40004,16384,1256, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.29  BV=-2.65
    {40004,16384,1344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.39  BV=-2.75
    {40004,16384,1448, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.50  BV=-2.86
    {40004,16384,1544, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.59  BV=-2.95
    {40004,16384,1656, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.69  BV=-3.05
    {40004,16384,1776, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.79  BV=-3.15
    {40004,16384,1904, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.89  BV=-3.25
    {40004,16384,2040, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.99  BV=-3.35
    {40004,16384,2192, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.10  BV=-3.45
    {40004,16384,2344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.19  BV=-3.55
    {40004,16384,2512, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.29  BV=-3.65
    {40004,16384,2696, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.40  BV=-3.75
    {40004,16384,2888, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.50  BV=-3.85
    {40004,16384,3104, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.60  BV=-3.96
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2920, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.51  BV=-4.45
    {70004,16384,2688, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.56
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable16 =
{
    AETABLE_SCENE_INDEX16, //eAETableID
    148, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -46, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene16PLineTable_60Hz,
    sAEScene16PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene17PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {41668,13696,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.74  BV=-2.16
    {41668,14688,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.84  BV=-2.26
    {41668,15744,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.94  BV=-2.36
    {41668,16384,1048, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.03  BV=-2.45
    {41668,16384,1128, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.14  BV=-2.55
    {41668,16384,1208, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.24  BV=-2.65
    {41668,16384,1296, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.34  BV=-2.75
    {41668,16384,1384, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.43  BV=-2.85
    {41668,16384,1488, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.54  BV=-2.95
    {41668,16384,1592, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.64  BV=-3.05
    {41668,16384,1704, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.73  BV=-3.15
    {41668,16384,1832, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.84  BV=-3.25
    {41668,16384,1960, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.94  BV=-3.35
    {41668,16384,2104, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.04  BV=-3.45
    {41668,16384,2256, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.14  BV=-3.55
    {41668,16384,2416, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.24  BV=-3.65
    {41668,16384,2584, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.34  BV=-3.75
    {41668,16384,2776, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.44  BV=-3.85
    {41668,16384,2976, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.54  BV=-3.95
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {58327,16384,2808, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.46  BV=-4.36
    {58327,16384,3008, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.55  BV=-4.45
    {66666,16384,2816, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene17PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {40004,14272,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.80  BV=-2.16
    {40004,15296,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.90  BV=-2.26
    {40004,16384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.00  BV=-2.36
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {40004,16384,1176, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.20  BV=-2.56
    {40004,16384,1256, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.29  BV=-2.65
    {40004,16384,1344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.39  BV=-2.75
    {40004,16384,1448, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.50  BV=-2.86
    {40004,16384,1544, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.59  BV=-2.95
    {40004,16384,1656, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.69  BV=-3.05
    {40004,16384,1776, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.79  BV=-3.15
    {40004,16384,1904, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.89  BV=-3.25
    {40004,16384,2040, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.99  BV=-3.35
    {40004,16384,2192, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.10  BV=-3.45
    {40004,16384,2344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.19  BV=-3.55
    {40004,16384,2512, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.29  BV=-3.65
    {40004,16384,2696, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.40  BV=-3.75
    {40004,16384,2888, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.50  BV=-3.85
    {40004,16384,3104, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.60  BV=-3.96
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2920, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.51  BV=-4.45
    {70004,16384,2688, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.56
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable17 =
{
    AETABLE_SCENE_INDEX17, //eAETableID
    148, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -46, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene17PLineTable_60Hz,
    sAEScene17PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene18PLineTable_60Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8330,1216,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.26  BV=3.65
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.97  BV=0.94
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.15  BV=0.76
    {33329,2432,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.25  BV=0.66
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,3968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.95  BV=-0.05
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.15  BV=-0.24
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5632,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.46  BV=-0.55
    {33329,6016,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.55  BV=-0.65
    {33329,6464,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.66  BV=-0.75
    {33329,6912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.75  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7936,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.95  BV=-1.05
    {33329,8576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.07  BV=-1.16
    {33329,9184,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.26
    {33329,9824,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.36
    {33329,10528,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11264,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12096,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.56  BV=-1.66
    {33329,12992,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.67  BV=-1.76
    {41668,11136,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.44  BV=-1.86
    {41668,11904,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.54  BV=-1.95
    {41668,12800,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.64  BV=-2.06
    {41668,13696,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.74  BV=-2.16
    {41668,14688,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.84  BV=-2.26
    {41668,15744,1024, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=8.94  BV=-2.36
    {41668,16384,1048, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.03  BV=-2.45
    {41668,16384,1128, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.14  BV=-2.55
    {41668,16384,1208, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.24  BV=-2.65
    {41668,16384,1296, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.34  BV=-2.75
    {41668,16384,1384, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.43  BV=-2.85
    {41668,16384,1488, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.54  BV=-2.95
    {41668,16384,1592, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.64  BV=-3.05
    {41668,16384,1704, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.73  BV=-3.15
    {41668,16384,1832, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.84  BV=-3.25
    {41668,16384,1960, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=9.94  BV=-3.35
    {41668,16384,2104, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.04  BV=-3.45
    {41668,16384,2256, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.14  BV=-3.55
    {41668,16384,2416, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.24  BV=-3.65
    {41668,16384,2584, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.34  BV=-3.75
    {41668,16384,2776, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.44  BV=-3.85
    {41668,16384,2976, 0, 0, 0},  //TV = 4.58(4532 lines)  AV=2.00  SV=10.54  BV=-3.95
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {58327,16384,2808, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.46  BV=-4.36
    {58327,16384,3008, 0, 0, 0},  //TV = 4.10(6344 lines)  AV=2.00  SV=10.55  BV=-4.45
    {66666,16384,2816, 0, 0, 0},  //TV = 3.91(7251 lines)  AV=2.00  SV=10.46  BV=-4.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene18PLineTable_50Hz =
{
{
    {92,1280,1040, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.34  BV=10.06
    {102,1184,1040, 0, 0, 0},  /* TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03 */
    {102,1280,1024, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.32  BV=9.94
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.32  BV=9.82
    {120,1248,1040, 0, 0, 0},  //TV = 13.02(13 lines)  AV=2.00  SV=5.31  BV=9.72
    {129,1248,1024, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.29  BV=9.63
    {138,1216,1040, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.27  BV=9.55
    {148,1248,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.29  BV=9.44
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {175,1216,1024, 0, 0, 0},  //TV = 12.48(19 lines)  AV=2.00  SV=5.25  BV=9.23
    {184,1248,1024, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.29  BV=9.12
    {194,1248,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.29  BV=9.05
    {212,1216,1024, 0, 0, 0},  //TV = 12.20(23 lines)  AV=2.00  SV=5.25  BV=8.96
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {240,1216,1040, 0, 0, 0},  //TV = 12.02(26 lines)  AV=2.00  SV=5.27  BV=8.75
    {258,1216,1040, 0, 0, 0},  //TV = 11.92(28 lines)  AV=2.00  SV=5.27  BV=8.65
    {276,1216,1040, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.27  BV=8.55
    {304,1184,1040, 0, 0, 0},  //TV = 11.68(33 lines)  AV=2.00  SV=5.23  BV=8.45
    {322,1216,1024, 0, 0, 0},  //TV = 11.60(35 lines)  AV=2.00  SV=5.25  BV=8.35
    {350,1184,1040, 0, 0, 0},  //TV = 11.48(38 lines)  AV=2.00  SV=5.23  BV=8.25
    {377,1184,1032, 0, 0, 0},  //TV = 11.37(41 lines)  AV=2.00  SV=5.22  BV=8.15
    {396,1216,1024, 0, 0, 0},  //TV = 11.30(43 lines)  AV=2.00  SV=5.25  BV=8.05
    {423,1216,1024, 0, 0, 0},  //TV = 11.21(46 lines)  AV=2.00  SV=5.25  BV=7.96
    {460,1184,1040, 0, 0, 0},  //TV = 11.09(50 lines)  AV=2.00  SV=5.23  BV=7.85
    {497,1184,1032, 0, 0, 0},  //TV = 10.97(54 lines)  AV=2.00  SV=5.22  BV=7.75
    {525,1216,1024, 0, 0, 0},  //TV = 10.90(57 lines)  AV=2.00  SV=5.25  BV=7.65
    {571,1184,1040, 0, 0, 0},  //TV = 10.77(62 lines)  AV=2.00  SV=5.23  BV=7.54
    {607,1184,1040, 0, 0, 0},  //TV = 10.69(66 lines)  AV=2.00  SV=5.23  BV=7.45
    {653,1184,1040, 0, 0, 0},  //TV = 10.58(71 lines)  AV=2.00  SV=5.23  BV=7.35
    {699,1184,1040, 0, 0, 0},  //TV = 10.48(76 lines)  AV=2.00  SV=5.23  BV=7.25
    {754,1184,1032, 0, 0, 0},  //TV = 10.37(82 lines)  AV=2.00  SV=5.22  BV=7.15
    {800,1184,1040, 0, 0, 0},  //TV = 10.29(87 lines)  AV=2.00  SV=5.23  BV=7.06
    {865,1184,1032, 0, 0, 0},  //TV = 10.18(94 lines)  AV=2.00  SV=5.22  BV=6.95
    {920,1184,1040, 0, 0, 0},  //TV = 10.09(100 lines)  AV=2.00  SV=5.23  BV=6.85
    {993,1184,1040, 0, 0, 0},  //TV = 9.98(108 lines)  AV=2.00  SV=5.23  BV=6.74
    {1058,1184,1040, 0, 0, 0},  //TV = 9.88(115 lines)  AV=2.00  SV=5.23  BV=6.65
    {1131,1184,1040, 0, 0, 0},  //TV = 9.79(123 lines)  AV=2.00  SV=5.23  BV=6.56
    {1214,1184,1040, 0, 0, 0},  //TV = 9.69(132 lines)  AV=2.00  SV=5.23  BV=6.45
    {1315,1184,1032, 0, 0, 0},  //TV = 9.57(143 lines)  AV=2.00  SV=5.22  BV=6.35
    {1407,1184,1032, 0, 0, 0},  //TV = 9.47(153 lines)  AV=2.00  SV=5.22  BV=6.25
    {1499,1184,1040, 0, 0, 0},  //TV = 9.38(163 lines)  AV=2.00  SV=5.23  BV=6.15
    {1600,1184,1040, 0, 0, 0},  //TV = 9.29(174 lines)  AV=2.00  SV=5.23  BV=6.06
    {1720,1184,1040, 0, 0, 0},  //TV = 9.18(187 lines)  AV=2.00  SV=5.23  BV=5.95
    {1839,1184,1040, 0, 0, 0},  //TV = 9.09(200 lines)  AV=2.00  SV=5.23  BV=5.86
    {1986,1184,1032, 0, 0, 0},  //TV = 8.98(216 lines)  AV=2.00  SV=5.22  BV=5.76
    {2134,1184,1032, 0, 0, 0},  //TV = 8.87(232 lines)  AV=2.00  SV=5.22  BV=5.65
    {2281,1184,1032, 0, 0, 0},  //TV = 8.78(248 lines)  AV=2.00  SV=5.22  BV=5.56
    {2446,1184,1032, 0, 0, 0},  //TV = 8.68(266 lines)  AV=2.00  SV=5.22  BV=5.45
    {2630,1184,1032, 0, 0, 0},  //TV = 8.57(286 lines)  AV=2.00  SV=5.22  BV=5.35
    {2814,1184,1032, 0, 0, 0},  //TV = 8.47(306 lines)  AV=2.00  SV=5.22  BV=5.25
    {3016,1184,1032, 0, 0, 0},  //TV = 8.37(328 lines)  AV=2.00  SV=5.22  BV=5.15
    {3228,1184,1032, 0, 0, 0},  //TV = 8.28(351 lines)  AV=2.00  SV=5.22  BV=5.05
    {3476,1184,1032, 0, 0, 0},  //TV = 8.17(378 lines)  AV=2.00  SV=5.22  BV=4.95
    {3724,1184,1032, 0, 0, 0},  //TV = 8.07(405 lines)  AV=2.00  SV=5.22  BV=4.85
    {3982,1184,1032, 0, 0, 0},  //TV = 7.97(433 lines)  AV=2.00  SV=5.22  BV=4.75
    {4267,1184,1032, 0, 0, 0},  //TV = 7.87(464 lines)  AV=2.00  SV=5.22  BV=4.65
    {4561,1184,1032, 0, 0, 0},  //TV = 7.78(496 lines)  AV=2.00  SV=5.22  BV=4.56
    {4883,1184,1032, 0, 0, 0},  //TV = 7.68(531 lines)  AV=2.00  SV=5.22  BV=4.46
    {5232,1184,1032, 0, 0, 0},  //TV = 7.58(569 lines)  AV=2.00  SV=5.22  BV=4.36
    {5636,1184,1032, 0, 0, 0},  //TV = 7.47(613 lines)  AV=2.00  SV=5.22  BV=4.25
    {6041,1184,1032, 0, 0, 0},  //TV = 7.37(657 lines)  AV=2.00  SV=5.22  BV=4.15
    {6473,1184,1032, 0, 0, 0},  //TV = 7.27(704 lines)  AV=2.00  SV=5.22  BV=4.05
    {6924,1184,1032, 0, 0, 0},  //TV = 7.17(753 lines)  AV=2.00  SV=5.22  BV=3.95
    {7420,1184,1032, 0, 0, 0},  //TV = 7.07(807 lines)  AV=2.00  SV=5.22  BV=3.85
    {7944,1184,1032, 0, 0, 0},  //TV = 6.98(864 lines)  AV=2.00  SV=5.22  BV=3.76
    {8514,1184,1032, 0, 0, 0},  //TV = 6.88(926 lines)  AV=2.00  SV=5.22  BV=3.66
    {9121,1184,1032, 0, 0, 0},  //TV = 6.78(992 lines)  AV=2.00  SV=5.22  BV=3.56
    {9774,1184,1032, 0, 0, 0},  //TV = 6.68(1063 lines)  AV=2.00  SV=5.22  BV=3.46
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.09  BV=2.56
    {10004,2336,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {19997,1760,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.79  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1440,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.51  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.82  BV=1.24
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.30  BV=0.76
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3328,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.70  BV=0.36
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5856,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.52  BV=-0.46
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6688,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.65
    {30001,7168,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7680,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8224,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9504,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.16
    {30001,10208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.32  BV=-1.26
    {30001,10912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.52  BV=-1.46
    {30001,12544,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.56
    {30001,13440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.66
    {40004,10816,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.40  BV=-1.76
    {40004,11584,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.50  BV=-1.86
    {40004,12416,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.60  BV=-1.96
    {40004,13312,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.70  BV=-2.06
    {40004,14272,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.80  BV=-2.16
    {40004,15296,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=8.90  BV=-2.26
    {40004,16384,1024, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.00  BV=-2.36
    {40004,16384,1096, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.10  BV=-2.45
    {40004,16384,1176, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.20  BV=-2.56
    {40004,16384,1256, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.29  BV=-2.65
    {40004,16384,1344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.39  BV=-2.75
    {40004,16384,1448, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.50  BV=-2.86
    {40004,16384,1544, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.59  BV=-2.95
    {40004,16384,1656, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.69  BV=-3.05
    {40004,16384,1776, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.79  BV=-3.15
    {40004,16384,1904, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.89  BV=-3.25
    {40004,16384,2040, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=9.99  BV=-3.35
    {40004,16384,2192, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.10  BV=-3.45
    {40004,16384,2344, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.19  BV=-3.55
    {40004,16384,2512, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.29  BV=-3.65
    {40004,16384,2696, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.40  BV=-3.75
    {40004,16384,2888, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.50  BV=-3.85
    {40004,16384,3104, 0, 0, 0},  //TV = 4.64(4351 lines)  AV=2.00  SV=10.60  BV=-3.96
    {49997,16384,2656, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.38  BV=-4.05
    {49997,16384,2848, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.48  BV=-4.15
    {49997,16384,3056, 0, 0, 0},  //TV = 4.32(5438 lines)  AV=2.00  SV=10.58  BV=-4.26
    {60001,16384,2728, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.41  BV=-4.35
    {60001,16384,2920, 0, 0, 0},  //TV = 4.06(6526 lines)  AV=2.00  SV=10.51  BV=-4.45
    {70004,16384,2688, 0, 0, 0},  //TV = 3.84(7614 lines)  AV=2.00  SV=10.39  BV=-4.56
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable18 =
{
    AETABLE_SCENE_INDEX18, //eAETableID
    148, //u4TotalIndex
    20, //i4StrobeTrigerBV
    101, //i4MaxBV
    -46, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene18PLineTable_60Hz,
    sAEScene18PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene22PLineTable_60Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8330,1216,1040, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.27  BV=3.64
    {8330,1312,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.36  BV=3.55
    {8330,1408,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.46  BV=3.45
    {8330,1504,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.55  BV=3.35
    {8330,1600,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.66  BV=3.25
    {8330,1728,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.77  BV=3.14
    {8330,1856,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.86  BV=3.05
    {8330,1984,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=5.97  BV=2.94
    {8330,2144,1024, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.07  BV=2.84
    {8330,2272,1032, 0, 0, 0},  //TV = 6.91(906 lines)  AV=2.00  SV=6.16  BV=2.75
    {16670,1216,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.25  BV=2.66
    {16670,1312,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.36  BV=2.55
    {16670,1408,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.46  BV=2.45
    {16670,1504,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.55  BV=2.35
    {16670,1600,1032, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.66  BV=2.25
    {16670,1728,1024, 0, 0, 0},  //TV = 5.91(1813 lines)  AV=2.00  SV=5.75  BV=2.15
    {24999,1216,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.27  BV=2.05
    {24999,1312,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.37  BV=1.95
    {24999,1408,1032, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.47  BV=1.85
    {24999,1504,1040, 0, 0, 0},  //TV = 5.32(2719 lines)  AV=2.00  SV=5.58  BV=1.75
    {33329,1216,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.25  BV=1.66
    {33329,1312,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.36  BV=1.55
    {33329,1408,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.46  BV=1.45
    {33329,1504,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.55  BV=1.35
    {33329,1600,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.66  BV=1.25
    {33329,1728,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.75  BV=1.15
    {33329,1856,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.86  BV=1.05
    {33329,1984,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=5.95  BV=0.95
    {33329,2112,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.06  BV=0.85
    {33329,2272,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.16  BV=0.75
    {33329,2432,1032, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.26  BV=0.65
    {33329,2624,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.36  BV=0.55
    {33329,2816,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.46  BV=0.45
    {33329,3008,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.55  BV=0.35
    {33329,3232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.66  BV=0.25
    {33329,3456,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.75  BV=0.15
    {33329,3712,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.86  BV=0.05
    {33329,4000,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=6.97  BV=-0.06
    {33329,4256,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.06  BV=-0.15
    {33329,4576,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.16  BV=-0.25
    {33329,4896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.26  BV=-0.35
    {33329,5248,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.36  BV=-0.45
    {33329,5600,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.45  BV=-0.54
    {33329,6048,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.56  BV=-0.66
    {33329,6496,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.67  BV=-0.76
    {33329,6944,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.76  BV=-0.85
    {33329,7424,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.86  BV=-0.95
    {33329,7968,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=7.96  BV=-1.05
    {33329,8544,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.06  BV=-1.15
    {33329,9152,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.16  BV=-1.25
    {33329,9792,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.26  BV=-1.35
    {33329,10496,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.36  BV=-1.45
    {33329,11232,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.46  BV=-1.55
    {33329,12032,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.55  BV=-1.65
    {33329,12896,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.65  BV=-1.75
    {33329,13920,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.76  BV=-1.86
    {33329,14912,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.86  BV=-1.96
    {33329,16000,1024, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=8.97  BV=-2.06
    {33329,16384,1064, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.06  BV=-2.15
    {33329,16384,1144, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.16  BV=-2.25
    {33329,16384,1224, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.26  BV=-2.35
    {33329,16384,1312, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.36  BV=-2.45
    {33329,16384,1408, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.46  BV=-2.55
    {33329,16384,1512, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.56  BV=-2.66
    {33329,16384,1616, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.66  BV=-2.75
    {33329,16384,1736, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.76  BV=-2.85
    {33329,16384,1856, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.86  BV=-2.95
    {33329,16384,1992, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=9.96  BV=-3.05
    {33329,16384,2136, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.06  BV=-3.15
    {33329,16384,2288, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.16  BV=-3.25
    {33329,16384,2448, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.26  BV=-3.35
    {33329,16384,2624, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.36  BV=-3.45
    {33329,16384,2816, 0, 0, 0},  //TV = 4.91(3625 lines)  AV=2.00  SV=10.46  BV=-3.55
    {33329,16384,2880, 0, 0, 0},  /* TV = 4.91(3625 lines)  AV=2.00  SV=10.49  BV=-3.58 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strEvPline sAEScene22PLineTable_50Hz =
{
{
    {92,1248,1032, 0, 0, 0},  //TV = 13.41(10 lines)  AV=2.00  SV=5.30  BV=10.11
    {102,1184,1040, 0, 0, 0},  //TV = 13.26(11 lines)  AV=2.00  SV=5.23  BV=10.03
    {111,1160,1024, 0, 0, 0},  //TV = 13.14(12 lines)  AV=2.00  SV=5.18  BV=9.96
    {120,1184,1024, 0, 0, 0},  /* TV = 13.02(13 lines)  AV=2.00  SV=5.21  BV=9.82 */
    {129,1160,1032, 0, 0, 0},  //TV = 12.92(14 lines)  AV=2.00  SV=5.19  BV=9.73
    {138,1160,1024, 0, 0, 0},  //TV = 12.82(15 lines)  AV=2.00  SV=5.18  BV=9.64
    {148,1160,1024, 0, 0, 0},  //TV = 12.72(16 lines)  AV=2.00  SV=5.18  BV=9.54
    {157,1184,1024, 0, 0, 0},  //TV = 12.64(17 lines)  AV=2.00  SV=5.21  BV=9.43
    {166,1184,1032, 0, 0, 0},  //TV = 12.56(18 lines)  AV=2.00  SV=5.22  BV=9.34
    {184,1160,1032, 0, 0, 0},  //TV = 12.41(20 lines)  AV=2.00  SV=5.19  BV=9.22
    {194,1184,1024, 0, 0, 0},  //TV = 12.33(21 lines)  AV=2.00  SV=5.21  BV=9.12
    {203,1184,1024, 0, 0, 0},  /* TV = 12.27(22 lines)  AV=2.00  SV=5.21  BV=9.06 */
    {221,1160,1032, 0, 0, 0},  //TV = 12.14(24 lines)  AV=2.00  SV=5.19  BV=8.95
    {230,1184,1040, 0, 0, 0},  //TV = 12.09(25 lines)  AV=2.00  SV=5.23  BV=8.85
    {249,1184,1032, 0, 0, 0},  //TV = 11.97(27 lines)  AV=2.00  SV=5.22  BV=8.75
    {276,1160,1024, 0, 0, 0},  //TV = 11.82(30 lines)  AV=2.00  SV=5.18  BV=8.64
    {295,1160,1024, 0, 0, 0},  //TV = 11.73(32 lines)  AV=2.00  SV=5.18  BV=8.55
    {313,1160,1032, 0, 0, 0},  //TV = 11.64(34 lines)  AV=2.00  SV=5.19  BV=8.45
    {331,1184,1024, 0, 0, 0},  //TV = 11.56(36 lines)  AV=2.00  SV=5.21  BV=8.35
    {359,1160,1032, 0, 0, 0},  //TV = 11.44(39 lines)  AV=2.00  SV=5.19  BV=8.25
    {387,1160,1024, 0, 0, 0},  //TV = 11.34(42 lines)  AV=2.00  SV=5.18  BV=8.16
    {414,1160,1024, 0, 0, 0},  //TV = 11.24(45 lines)  AV=2.00  SV=5.18  BV=8.06
    {442,1160,1032, 0, 0, 0},  //TV = 11.14(48 lines)  AV=2.00  SV=5.19  BV=7.95
    {479,1160,1024, 0, 0, 0},  //TV = 11.03(52 lines)  AV=2.00  SV=5.18  BV=7.85
    {506,1160,1032, 0, 0, 0},  //TV = 10.95(55 lines)  AV=2.00  SV=5.19  BV=7.76
    {543,1160,1032, 0, 0, 0},  //TV = 10.85(59 lines)  AV=2.00  SV=5.19  BV=7.66
    {589,1160,1024, 0, 0, 0},  //TV = 10.73(64 lines)  AV=2.00  SV=5.18  BV=7.55
    {635,1160,1024, 0, 0, 0},  //TV = 10.62(69 lines)  AV=2.00  SV=5.18  BV=7.44
    {672,1160,1024, 0, 0, 0},  //TV = 10.54(73 lines)  AV=2.00  SV=5.18  BV=7.36
    {727,1160,1024, 0, 0, 0},  //TV = 10.43(79 lines)  AV=2.00  SV=5.18  BV=7.25
    {773,1160,1024, 0, 0, 0},  //TV = 10.34(84 lines)  AV=2.00  SV=5.18  BV=7.16
    {828,1160,1024, 0, 0, 0},  //TV = 10.24(90 lines)  AV=2.00  SV=5.18  BV=7.06
    {892,1160,1024, 0, 0, 0},  //TV = 10.13(97 lines)  AV=2.00  SV=5.18  BV=6.95
    {957,1160,1024, 0, 0, 0},  //TV = 10.03(104 lines)  AV=2.00  SV=5.18  BV=6.85
    {1030,1160,1024, 0, 0, 0},  //TV = 9.92(112 lines)  AV=2.00  SV=5.18  BV=6.74
    {1095,1160,1024, 0, 0, 0},  //TV = 9.83(119 lines)  AV=2.00  SV=5.18  BV=6.65
    {1187,1160,1024, 0, 0, 0},  //TV = 9.72(129 lines)  AV=2.00  SV=5.18  BV=6.54
    {1260,1160,1024, 0, 0, 0},  //TV = 9.63(137 lines)  AV=2.00  SV=5.18  BV=6.45
    {1361,1160,1024, 0, 0, 0},  //TV = 9.52(148 lines)  AV=2.00  SV=5.18  BV=6.34
    {1453,1160,1024, 0, 0, 0},  //TV = 9.43(158 lines)  AV=2.00  SV=5.18  BV=6.25
    {1554,1160,1024, 0, 0, 0},  //TV = 9.33(169 lines)  AV=2.00  SV=5.18  BV=6.15
    {1655,1160,1024, 0, 0, 0},  //TV = 9.24(180 lines)  AV=2.00  SV=5.18  BV=6.06
    {1793,1160,1024, 0, 0, 0},  //TV = 9.12(195 lines)  AV=2.00  SV=5.18  BV=5.94
    {1922,1160,1024, 0, 0, 0},  //TV = 9.02(209 lines)  AV=2.00  SV=5.18  BV=5.84
    {2051,1160,1024, 0, 0, 0},  //TV = 8.93(223 lines)  AV=2.00  SV=5.18  BV=5.75
    {2198,1160,1024, 0, 0, 0},  //TV = 8.83(239 lines)  AV=2.00  SV=5.18  BV=5.65
    {2363,1160,1024, 0, 0, 0},  //TV = 8.73(257 lines)  AV=2.00  SV=5.18  BV=5.55
    {2529,1160,1024, 0, 0, 0},  //TV = 8.63(275 lines)  AV=2.00  SV=5.18  BV=5.45
    {2722,1160,1024, 0, 0, 0},  //TV = 8.52(296 lines)  AV=2.00  SV=5.18  BV=5.34
    {2915,1160,1024, 0, 0, 0},  //TV = 8.42(317 lines)  AV=2.00  SV=5.18  BV=5.24
    {3117,1160,1024, 0, 0, 0},  //TV = 8.33(339 lines)  AV=2.00  SV=5.18  BV=5.15
    {3338,1160,1024, 0, 0, 0},  //TV = 8.23(363 lines)  AV=2.00  SV=5.18  BV=5.05
    {3595,1160,1024, 0, 0, 0},  //TV = 8.12(391 lines)  AV=2.00  SV=5.18  BV=4.94
    {3853,1160,1024, 0, 0, 0},  //TV = 8.02(419 lines)  AV=2.00  SV=5.18  BV=4.84
    {4119,1160,1024, 0, 0, 0},  //TV = 7.92(448 lines)  AV=2.00  SV=5.18  BV=4.74
    {4414,1160,1024, 0, 0, 0},  //TV = 7.82(480 lines)  AV=2.00  SV=5.18  BV=4.64
    {4726,1160,1024, 0, 0, 0},  //TV = 7.73(514 lines)  AV=2.00  SV=5.18  BV=4.55
    {5057,1160,1024, 0, 0, 0},  //TV = 7.63(550 lines)  AV=2.00  SV=5.18  BV=4.45
    {5416,1160,1024, 0, 0, 0},  //TV = 7.53(589 lines)  AV=2.00  SV=5.18  BV=4.35
    {5839,1160,1024, 0, 0, 0},  //TV = 7.42(635 lines)  AV=2.00  SV=5.18  BV=4.24
    {6252,1160,1024, 0, 0, 0},  //TV = 7.32(680 lines)  AV=2.00  SV=5.18  BV=4.14
    {6694,1160,1024, 0, 0, 0},  //TV = 7.22(728 lines)  AV=2.00  SV=5.18  BV=4.04
    {7172,1160,1024, 0, 0, 0},  //TV = 7.12(780 lines)  AV=2.00  SV=5.18  BV=3.94
    {7677,1160,1024, 0, 0, 0},  //TV = 7.03(835 lines)  AV=2.00  SV=5.18  BV=3.85
    {8229,1160,1024, 0, 0, 0},  //TV = 6.93(895 lines)  AV=2.00  SV=5.18  BV=3.75
    {8808,1160,1024, 0, 0, 0},  //TV = 6.83(958 lines)  AV=2.00  SV=5.18  BV=3.65
    {9443,1160,1024, 0, 0, 0},  //TV = 6.73(1027 lines)  AV=2.00  SV=5.18  BV=3.55
    {10004,1160,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.19  BV=3.45
    {10004,1248,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.29  BV=3.36
    {10004,1344,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.39  BV=3.25
    {10004,1440,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.49  BV=3.15
    {10004,1536,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.60  BV=3.05
    {10004,1632,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.68  BV=2.96
    {10004,1760,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.79  BV=2.85
    {10004,1888,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=5.89  BV=2.75
    {10004,2048,1024, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.00  BV=2.64
    {10004,2176,1032, 0, 0, 0},  //TV = 6.64(1088 lines)  AV=2.00  SV=6.10  BV=2.54
    {19997,1160,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.19  BV=2.45
    {19997,1248,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.29  BV=2.36
    {19997,1344,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.39  BV=2.25
    {19997,1440,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.49  BV=2.15
    {19997,1536,1032, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.60  BV=2.05
    {19997,1664,1024, 0, 0, 0},  //TV = 5.64(2175 lines)  AV=2.00  SV=5.70  BV=1.94
    {30001,1184,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.21  BV=1.85
    {30001,1248,1040, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.31  BV=1.75
    {30001,1344,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.40  BV=1.66
    {30001,1472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.52  BV=1.54
    {30001,1568,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.61  BV=1.44
    {30001,1664,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.71  BV=1.35
    {30001,1792,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.81  BV=1.25
    {30001,1920,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=5.91  BV=1.15
    {30001,2048,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.01  BV=1.05
    {30001,2208,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.11  BV=0.95
    {30001,2368,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.21  BV=0.85
    {30001,2528,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.32  BV=0.74
    {30001,2720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.41  BV=0.65
    {30001,2912,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.51  BV=0.55
    {30001,3136,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.61  BV=0.44
    {30001,3360,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.71  BV=0.34
    {30001,3584,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.81  BV=0.25
    {30001,3840,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=6.91  BV=0.15
    {30001,4128,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.01  BV=0.05
    {30001,4416,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.11  BV=-0.05
    {30001,4736,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.21  BV=-0.15
    {30001,5088,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.31  BV=-0.25
    {30001,5440,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.41  BV=-0.35
    {30001,5824,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.51  BV=-0.45
    {30001,6240,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.61  BV=-0.55
    {30001,6720,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.71  BV=-0.66
    {30001,7200,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.81  BV=-0.75
    {30001,7712,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=7.91  BV=-0.85
    {30001,8256,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.01  BV=-0.95
    {30001,8864,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.11  BV=-1.05
    {30001,9472,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.21  BV=-1.15
    {30001,10144,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.31  BV=-1.25
    {30001,10880,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.41  BV=-1.35
    {30001,11648,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.51  BV=-1.45
    {30001,12480,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.61  BV=-1.55
    {30001,13376,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.71  BV=-1.65
    {30001,14336,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.81  BV=-1.75
    {30001,15488,1024, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=8.92  BV=-1.86
    {30001,16384,1032, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.01  BV=-1.95
    {30001,16384,1104, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.11  BV=-2.05
    {30001,16384,1184, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.21  BV=-2.15
    {30001,16384,1272, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.31  BV=-2.25
    {30001,16384,1360, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.41  BV=-2.35
    {30001,16384,1464, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.52  BV=-2.46
    {30001,16384,1568, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.61  BV=-2.56
    {30001,16384,1680, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.71  BV=-2.66
    {30001,16384,1800, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.81  BV=-2.75
    {30001,16384,1928, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=9.91  BV=-2.85
    {30001,16384,2064, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.01  BV=-2.95
    {30001,16384,2216, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.11  BV=-3.05
    {30001,16384,2368, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.21  BV=-3.15
    {30001,16384,2544, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.31  BV=-3.25
    {30001,16384,2728, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.41  BV=-3.35
    {30001,16384,2880, 0, 0, 0},  //TV = 5.06(3263 lines)  AV=2.00  SV=10.49  BV=-3.43
    {30001,16384,2880, 0, 0, 0},  /* TV = 5.06(3263 lines)  AV=2.00  SV=10.49  BV=-3.43 */
    {30001,16384,2880, 0, 0, 0},  /* TV = 5.06(3263 lines)  AV=2.00  SV=10.49  BV=-3.43 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};

static constexpr strAETable g_AE_SceneTable22 =
{
    AETABLE_SCENE_INDEX22, //eAETableID
    139, //u4TotalIndex
    20, //i4StrobeTrigerBV
    102, //i4MaxBV
    -36, //i4MinBV
    0, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene22PLineTable_60Hz,
    sAEScene22PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAESceneReservePLineTable =
{
{
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
},
};
static constexpr strAETable g_AE_ReserveSceneTable =
{
	AETABLE_SCENE_MAX,    //eAETableID
	0,    //u4TotalIndex
	20,    //u4StrobeTrigerBV
	0,    //i4MaxBV
	0,    //i4MinBV
	90,    //i4EffectiveMaxBV
	0,      //i4EffectiveMinBV
	LIB3A_AE_ISO_SPEED_AUTO, //ISO SPEED
	sAESceneReservePLineTable,
	sAESceneReservePLineTable,
	NULL,
};

static constexpr strAESceneMapping g_AEScenePLineMapping = 
{
{
    {LIB3A_AE_SCENE_AUTO, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX5}},
    {LIB3A_AE_SCENE_NIGHT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_ACTION, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_BEACH, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_CANDLELIGHT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_FIREWORKS, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX4, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX4}},
    {LIB3A_AE_SCENE_LANDSCAPE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_PORTRAIT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_NIGHT_PORTRAIT, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_PARTY, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_SNOW, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_SPORTS, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_STEADYPHOTO, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_SUNSET, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3}},
    {LIB3A_AE_SCENE_THEATRE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1}},
    {LIB3A_AE_SCENE_ISO_ANTI_SHAKE, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2}},
    {LIB3A_AE_SCENE_ISO100, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO100, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO100}},
    {LIB3A_AE_SCENE_ISO200, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO200, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO200}},
    {LIB3A_AE_SCENE_ISO400, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO400, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO400}},
    {LIB3A_AE_SCENE_ISO800, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO800, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO800}},
    {LIB3A_AE_SCENE_ISO1600, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO1600, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_SCENE_INDEX6, AETABLE_SCENE_INDEX7, AETABLE_SCENE_INDEX8, AETABLE_SCENE_INDEX9, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO1600}},
    {LIB3A_AE_SCENE_ISO3200, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX6, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX6}},
    {LIB3A_AE_SCENE_ISO6400, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX7, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX7}},
    {LIB3A_AE_SCENE_ISO12800, {AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX8, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX8}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
    {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
},
};

static constexpr strAEPLineTable g_strAEPlineTable =
{
{
// PLINE Table
    g_AE_PreviewAutoTable,
    g_AE_CaptureAutoTable,
    g_AE_VideoAutoTable,
    g_AE_Video1AutoTable,
    g_AE_Video2AutoTable,
    g_AE_Custom1AutoTable,
    g_AE_Custom2AutoTable,
    g_AE_Custom3AutoTable,
    g_AE_Custom4AutoTable,
    g_AE_Custom5AutoTable,
    g_AE_VideoNightTable,
    g_AE_CaptureISO100Table,
    g_AE_CaptureISO200Table,
    g_AE_CaptureISO400Table,
    g_AE_CaptureISO800Table,
    g_AE_CaptureISO1600Table,
    g_AE_StrobeTable,
    g_AE_SceneTable1,
    g_AE_SceneTable2,
    g_AE_SceneTable3,
    g_AE_SceneTable4,
    g_AE_SceneTable5,
    g_AE_SceneTable6,
    g_AE_SceneTable7,
    g_AE_SceneTable8,
    g_AE_SceneTable9,
    g_AE_SceneTable14,
    g_AE_SceneTable15,
    g_AE_SceneTable16,
    g_AE_SceneTable17,
    g_AE_SceneTable18,
    g_AE_SceneTable22,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
    g_AE_ReserveSceneTable,
},
};

static constexpr strAEPLineNumInfo g_strAEPreviewAutoPLineInfo =
{
    AETABLE_RPEVIEW_AUTO,
    90,
    -50,
    {
        {1,10000,30,1160,1160},
        {2,30,30,1160,8192},
        {3,30,24,8192,8192},
        {4,24,24,8192,12288},
        {5,24,17,12288,12288},
        {6,17,17,12288,16384},
        {7,17,10,16384,16384},
        {8,10,10,16384,51200},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureAutoPLineInfo =
{
    AETABLE_CAPTURE_AUTO,
    90,
    -30,
    {
        {1,10000,30,1160,1160},
        {2,30,30,1160,8192},
        {3,30,24,8192,8192},
        {4,24,24,8192,12288},
        {5,24,17,12288,12288},
        {6,17,17,12288,16184},
        {7,17,10,16184,16184},
        {8,10,10,16184,51200},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEVideoAutoPLineInfo =
{
    AETABLE_VIDEO_AUTO,
    90,
    -30,
    {
        {1,10000,30,1160,1160},
        {2,30,30,1160,3072},
        {3,30,24,3072,3072},
        {4,24,24,3072,16384},
        {5,24,17,16384,16384},
        {6,17,17,16384,51200},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEVideo1AutoPLineInfo =
{
    AETABLE_VIDEO1_AUTO,
    90,
    0,
    {
        {1,10000,121,1195,1195},
        {2,121,121,1195,20480},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEVideo2AutoPLineInfo =
{
    AETABLE_VIDEO2_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECustom1AutoPLineInfo =
{
    AETABLE_CUSTOM1_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECustom2AutoPLineInfo =
{
    AETABLE_CUSTOM2_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECustom3AutoPLineInfo =
{
    AETABLE_CUSTOM3_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECustom4AutoPLineInfo =
{
    AETABLE_CUSTOM4_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECustom5AutoPLineInfo =
{
    AETABLE_CUSTOM5_AUTO,
    90,
    -30,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,3072},
        {3,60,30,3072,3072},
        {4,30,30,3072,10240},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEVideoNightPLineInfo =
{
    AETABLE_VIDEO_NIGHT,
    90,
    -10,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,15,12288,12288},
        {4,15,15,12288,35200},
        {5,15,10,35200,35200},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureISO100PLineInfo =
{
    AETABLE_CAPTURE_ISO100,
    90,
    0,
    {
        {1,10000,10,1195,1195},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureISO200PLineInfo =
{
    AETABLE_CAPTURE_ISO200,
    90,
    -30,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,2048},
        {3,2000,10,2048,2048},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureISO400PLineInfo =
{
    AETABLE_CAPTURE_ISO400,
    90,
    -30,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,4096},
        {3,2000,10,4096,4096},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureISO800PLineInfo =
{
    AETABLE_CAPTURE_ISO800,
    90,
    0,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,8192},
        {3,2000,5,8192,8192},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAECaptureISO1600PLineInfo =
{
    AETABLE_CAPTURE_ISO1600,
    90,
    0,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,16384},
        {3,2000,5,16384,16384},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEStrobePLineInfo =
{
    AETABLE_STROBE,
    90,
    -30,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,15,12288,12288},
        {4,15,15,12288,46080},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene1PLineInfo =
{
    AETABLE_SCENE_INDEX1,
    90,
    -50,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,15,12288,12288},
        {4,15,15,12288,46080},
        {5,15,10,46080,46080},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene2PLineInfo =
{
    AETABLE_SCENE_INDEX2,
    90,
    -30,
    {
        {1,10000,100,1195,1195},
        {2,100,100,1195,4096},
        {3,100,30,4096,4096},
        {4,30,30,4096,16384},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene3PLineInfo =
{
    AETABLE_SCENE_INDEX3,
    90,
    -30,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,2048},
        {3,30,15,2048,2048},
        {4,15,15,2048,4096},
        {5,15,10,4096,4096},
        {6,10,10,4096,12288},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene4PLineInfo =
{
    AETABLE_SCENE_INDEX4,
    90,
    -30,
    {
        {1,5,5,1706,1706},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene5PLineInfo =
{
    AETABLE_SCENE_INDEX5,
    90,
    -30,
    {
        {1,10000,30,1160,1160},
        {2,30,30,1160,8192},
        {3,30,24,8192,8192},
        {4,24,24,8192,12288},
        {5,24,17,12288,12288},
        {6,17,17,12288,16384},
        {7,17,10,16384,16384},
        {8,10,10,16384,51200},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene6PLineInfo =
{
    AETABLE_SCENE_INDEX6,
    90,
    0,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,32768},
        {3,2000,5,32768,32768},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene7PLineInfo =
{
    AETABLE_SCENE_INDEX7,
    90,
    0,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,65536},
        {3,2000,10,65536,65536},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene8PLineInfo =
{
    AETABLE_SCENE_INDEX8,
    90,
    0,
    {
        {1,10000,2000,1195,1195},
        {2,2000,2000,1195,131072},
        {3,2000,20,131072,131072},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene9PLineInfo =
{
    AETABLE_SCENE_INDEX9,
    90,
    0,
    {
        {1,10000,60,1195,1195},
        {2,60,60,1195,2048},
        {3,60,40,2048,2048},
        {4,40,40,2048,46080},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene14PLineInfo =
{
    AETABLE_SCENE_INDEX14,
    0,
    0,
    {
        {1,10000,15,1144,1144},
        {2,15,15,1144,46080},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene15PLineInfo =
{
    AETABLE_SCENE_INDEX15,
    90,
    -50,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,46080},
        {5,24,15,46080,46080},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene16PLineInfo =
{
    AETABLE_SCENE_INDEX16,
    90,
    -50,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,46080},
        {5,24,15,46080,46080},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene17PLineInfo =
{
    AETABLE_SCENE_INDEX17,
    90,
    -50,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,46080},
        {5,24,15,46080,46080},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene18PLineInfo =
{
    AETABLE_SCENE_INDEX18,
    90,
    -50,
    {
        {1,10000,30,1195,1195},
        {2,30,30,1195,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,46080},
        {5,24,15,46080,46080},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAEScene22PLineInfo =
{
    AETABLE_SCENE_INDEX22,
    0,
    0,
    {
        {1,10000,30,1144,1144},
        {2,30,30,1144,46080},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};

static constexpr strAEPLineNumInfo g_strAENoScenePLineInfo =
{
    AETABLE_SCENE_MAX,
    90,
    0,
    {
        {1,0,0,0,0},
        {2,0,0,0,0},
        {3,0,0,0,0},
        {4,0,0,0,0},
        {5,0,0,0,0},
        {6,0,0,0,0},
        {7,0,0,0,0},
        {8,0,0,0,0},
        {9,0,0,0,0},
        {10,0,0,0,0},
        {11,0,0,0,0},
        {12,0,0,0,0},
        {13,0,0,0,0},
        {14,0,0,0,0},
        {15,0,0,0,0},
    }
};
static constexpr strAEPLineInfomation g_strAEPlineInfo =
{
    MTRUE,   // FALSE mean the sampling
    {
    // PLINE Info
        g_strAEPreviewAutoPLineInfo,
        g_strAECaptureAutoPLineInfo,
        g_strAEVideoAutoPLineInfo,
        g_strAEVideo1AutoPLineInfo,
        g_strAEVideo2AutoPLineInfo,
        g_strAECustom1AutoPLineInfo,
        g_strAECustom2AutoPLineInfo,
        g_strAECustom3AutoPLineInfo,
        g_strAECustom4AutoPLineInfo,
        g_strAECustom5AutoPLineInfo,
        g_strAEVideoNightPLineInfo,
        g_strAECaptureISO100PLineInfo,
        g_strAECaptureISO200PLineInfo,
        g_strAECaptureISO400PLineInfo,
        g_strAECaptureISO800PLineInfo,
        g_strAECaptureISO1600PLineInfo,
        g_strAEStrobePLineInfo,
        g_strAEScene1PLineInfo,
        g_strAEScene2PLineInfo,
        g_strAEScene3PLineInfo,
        g_strAEScene4PLineInfo,
        g_strAEScene5PLineInfo,
        g_strAEScene6PLineInfo,
        g_strAEScene7PLineInfo,
        g_strAEScene8PLineInfo,
        g_strAEScene9PLineInfo,
        g_strAEScene14PLineInfo,
        g_strAEScene15PLineInfo,
        g_strAEScene16PLineInfo,
        g_strAEScene17PLineInfo,
        g_strAEScene18PLineInfo,
        g_strAEScene22PLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
        g_strAENoScenePLineInfo,
},
};

static constexpr strAEPLineGainList g_strAEGainList =
{
    0,
    {
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
        {0,100},
    }
};

static constexpr AE_PLINETABLE_T g_PlineTableMapping =
{
    g_AEScenePLineMapping,
    g_strAEPlineTable,
    g_strAEPlineInfo,
    g_strAEGainList
};
#endif

#if 0 //Save the P-line info to file for debug
MinGain,1160
MaxGain,16384
MiniISOGain,100
GainStepUnitInTotalRange,32
PreviewExposureLineUnit,12608
PreviewMaxFrameRate,30
VideoExposureLineUnit,9194
VideoMaxFrameRate,30
VideoToPreviewSensitivityRatio,1024
CaptureExposureLineUnit,9194
CaptureMaxFrameRate,30
CaptureToPreviewSensitivityRatio,1024
Video1ExposureLineUnit,9194
Video1MaxFrameRate,120
Video1ToPreviewSensitivityRatio,1024
Video2ExposureLineUnit,12608
Video2MaxFrameRate,100
Video2ToPreviewSensitivityRatio,1024
Custom1ExposureLineUnit,19770
Custom1MaxFrameRate,30
Custom1ToPreviewSensitivityRatio,1024
Custom2ExposureLineUnit,19770
Custom2MaxFrameRate,30
Custom2ToPreviewSensitivityRatio,1024
Custom3ExposureLineUnit,19770
Custom3MaxFrameRate,30
Custom3ToPreviewSensitivityRatio,1024
Custom4ExposureLineUnit,19770
Custom4MaxFrameRate,30
Custom4ToPreviewSensitivityRatio,1024
Custom5ExposureLineUnit,19770
Custom5MaxFrameRate,30
Custom5ToPreviewSensitivityRatio,1024
FocusLength,350
Fno,20

// Preview table -- Use preview sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_RPEVIEW_AUTO
90,-50
1,10000,30,1160,1160
2,30,30,1160,8192
3,30,24,8192,8192
4,24,24,8192,12288
5,24,17,12288,12288
6,17,17,12288,16384
7,17,10,16384,16384
8,10,10,16384,51200
AETABLE_END

// Capture table -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_AUTO
90,-30
1,10000,30,1160,1160
2,30,30,1160,8192
3,30,24,8192,8192
4,24,24,8192,12288
5,24,17,12288,12288
6,17,17,12288,16184
7,17,10,16184,16184
8,10,10,16184,51200
AETABLE_END

// Video table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_AUTO
90,-30
1,10000,30,1160,1160
2,30,30,1160,3072
3,30,24,3072,3072
4,24,24,3072,16384
5,24,17,16384,16384
6,17,17,16384,51200
AETABLE_END

// Video1 table -- Use video1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO1_AUTO
90,0
1,10000,121,1195,1195
2,121,121,1195,20480
AETABLE_END

// Video2 table -- Use video2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO2_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom1 table -- Use custom1 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM1_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom2 table -- Use custom2 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM2_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom3 table -- Use custom3 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM3_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom4 table -- Use custom4 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM4_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Custom5 table -- Use custom5 sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CUSTOM5_AUTO
90,-30
1,10000,60,1195,1195
2,60,60,1195,3072
3,60,30,3072,3072
4,30,30,3072,10240
AETABLE_END

// Video Night table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_NIGHT
90,-10
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,35200
5,15,10,35200,35200
AETABLE_END

// Capture ISO100 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO100
90,0
1,10000,10,1195,1195
AETABLE_END

// Capture ISO200 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO200
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,2048
3,2000,10,2048,2048
AETABLE_END

// Capture ISO400 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO400
90,-30
1,10000,2000,1195,1195
2,2000,2000,1195,4096
3,2000,10,4096,4096
AETABLE_END

// Capture ISO800 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO800
90,0
1,10000,2000,1195,1195
2,2000,2000,1195,8192
3,2000,5,8192,8192
AETABLE_END

// Capture ISO1600 -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_ISO1600
90,0
1,10000,2000,1195,1195
2,2000,2000,1195,16384
3,2000,5,16384,16384
AETABLE_END

// Strobe -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_STROBE
90,-30
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,46080
AETABLE_END

// Table1 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX1
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,15,12288,12288
4,15,15,12288,46080
5,15,10,46080,46080
AETABLE_END

// Table2 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX2
90,-30
1,10000,100,1195,1195
2,100,100,1195,4096
3,100,30,4096,4096
4,30,30,4096,16384
AETABLE_END

// Table3 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX3
90,-30
1,10000,30,1195,1195
2,30,30,1195,2048
3,30,15,2048,2048
4,15,15,2048,4096
5,15,10,4096,4096
6,10,10,4096,12288
AETABLE_END

// Table4 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX4
90,-30
1,5,5,1706,1706
AETABLE_END

// Table5 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX5
90,-30
1,10000,30,1160,1160
2,30,30,1160,8192
3,30,24,8192,8192
4,24,24,8192,12288
5,24,17,12288,12288
6,17,17,12288,16384
7,17,10,16384,16384
8,10,10,16384,51200
AETABLE_END

// Table6 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX6
90,0
1,10000,2000,1195,1195
2,2000,2000,1195,32768
3,2000,5,32768,32768
AETABLE_END

// Table7 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX7
90,0
1,10000,2000,1195,1195
2,2000,2000,1195,65536
3,2000,10,65536,65536
AETABLE_END

// Table8 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX8
90,0
1,10000,2000,1195,1195
2,2000,2000,1195,131072
3,2000,20,131072,131072
AETABLE_END

// Table9 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX9
90,0
1,10000,60,1195,1195
2,60,60,1195,2048
3,60,40,2048,2048
4,40,40,2048,46080
AETABLE_END

// Table14 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX14
0,0
1,10000,15,1144,1144
2,15,15,1144,46080
AETABLE_END

// Table15 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX15
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,24,12288,12288
4,24,24,12288,46080
5,24,15,46080,46080
AETABLE_END

// Table16 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX16
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,24,12288,12288
4,24,24,12288,46080
5,24,15,46080,46080
AETABLE_END

// Table17 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX17
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,24,12288,12288
4,24,24,12288,46080
5,24,15,46080,46080
AETABLE_END

// Table18 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX18
90,-50
1,10000,30,1195,1195
2,30,30,1195,12288
3,30,24,12288,12288
4,24,24,12288,46080
5,24,15,46080,46080
AETABLE_END

// Table22 PLine -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_SCENE_INDEX22
0,0
1,10000,30,1144,1144
2,30,30,1144,46080
AETABLE_END

LIB3A_AE_SCENE_AUTO, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX5
LIB3A_AE_SCENE_NIGHT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
LIB3A_AE_SCENE_ACTION, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
LIB3A_AE_SCENE_BEACH, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
LIB3A_AE_SCENE_CANDLELIGHT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
LIB3A_AE_SCENE_FIREWORKS, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX4, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX4
LIB3A_AE_SCENE_LANDSCAPE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
LIB3A_AE_SCENE_PORTRAIT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
LIB3A_AE_SCENE_NIGHT_PORTRAIT, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_NIGHT, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
LIB3A_AE_SCENE_PARTY, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
LIB3A_AE_SCENE_SNOW, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
LIB3A_AE_SCENE_SPORTS, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
LIB3A_AE_SCENE_STEADYPHOTO, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
LIB3A_AE_SCENE_SUNSET, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX3, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX3
LIB3A_AE_SCENE_THEATRE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX1, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX1
LIB3A_AE_SCENE_ISO_ANTI_SHAKE, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX2, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX2
LIB3A_AE_SCENE_ISO100, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO100, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO100
LIB3A_AE_SCENE_ISO200, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO200, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO200
LIB3A_AE_SCENE_ISO400, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO400, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO400
LIB3A_AE_SCENE_ISO800, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO800, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO800
LIB3A_AE_SCENE_ISO1600, AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_ISO1600, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_SCENE_INDEX6, AETABLE_SCENE_INDEX7, AETABLE_SCENE_INDEX8, AETABLE_SCENE_INDEX9, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_ISO1600
LIB3A_AE_SCENE_ISO3200, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX6, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX6
LIB3A_AE_SCENE_ISO6400, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX7, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX7
LIB3A_AE_SCENE_ISO12800, AETABLE_RPEVIEW_AUTO, AETABLE_SCENE_INDEX8, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX8
LIB3A_AE_SCENE_FIX_15FPS, AETABLE_SCENE_INDEX14, AETABLE_SCENE_INDEX14, AETABLE_SCENE_INDEX14, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX14
LIB3A_AE_SCENE_FIX_30FPS, AETABLE_SCENE_INDEX22, AETABLE_SCENE_INDEX22, AETABLE_SCENE_INDEX22, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_SCENE_INDEX22
#endif
