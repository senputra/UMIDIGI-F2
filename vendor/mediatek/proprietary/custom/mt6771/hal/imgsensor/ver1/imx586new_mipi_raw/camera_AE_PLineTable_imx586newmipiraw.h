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
#ifndef _CAMERA_AE_PLINETABLE_IMX586NEWMIPIRAW_H
#define _CAMERA_AE_PLINETABLE_IMX586NEWMIPIRAW_H

#include <custom/aaa/AEPlinetable.h>
static constexpr strEvPline sPreviewPLineTable_60Hz =
{
{
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.28  BV=9.67
    {103,1136,1024, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.15  BV=9.63 */
    {103,1184,1032, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56
    {114,1152,1048, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.20  BV=9.43
    {125,1136,1032, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.16  BV=9.34
    {125,1216,1024, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.25  BV=9.25
    {148,1136,1024, 0, 0, 0},  /* TV = 12.72(13 lines)  AV=1.53  SV=5.15  BV=9.10 */
    {148,1152,1048, 0, 0, 0},  /* TV = 12.72(13 lines)  AV=1.53  SV=5.20  BV=9.05 */
    {159,1152,1048, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.20  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.21  BV=8.84
    {193,1136,1024, 0, 0, 0},  //TV = 12.34(17 lines)  AV=1.53  SV=5.15  BV=8.72
    {193,1184,1032, 0, 0, 0},  //TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65
    {216,1136,1024, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.15  BV=8.56
    {227,1152,1032, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.18  BV=8.45
    {250,1136,1024, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.15  BV=8.35
    {261,1152,1032, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.18  BV=8.25
    {284,1136,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.16  BV=8.15
    {307,1136,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.15  BV=8.05
    {330,1136,1024, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.15  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.15  BV=7.85
    {375,1136,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.16  BV=7.75
    {398,1152,1024, 0, 0, 0},  //TV = 11.29(35 lines)  AV=1.53  SV=5.17  BV=7.66
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(38 lines)  AV=1.53  SV=5.15  BV=7.56
    {466,1136,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.15  BV=7.45
    {500,1136,1024, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.15  BV=7.35
    {534,1136,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.15  BV=7.25
    {568,1136,1032, 0, 0, 0},  //TV = 10.78(50 lines)  AV=1.53  SV=5.16  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(54 lines)  AV=1.53  SV=5.15  BV=7.05
    {659,1136,1024, 0, 0, 0},  //TV = 10.57(58 lines)  AV=1.53  SV=5.15  BV=6.95
    {704,1136,1024, 0, 0, 0},  //TV = 10.47(62 lines)  AV=1.53  SV=5.15  BV=6.85
    {749,1136,1032, 0, 0, 0},  //TV = 10.38(66 lines)  AV=1.53  SV=5.16  BV=6.75
    {806,1136,1024, 0, 0, 0},  //TV = 10.28(71 lines)  AV=1.53  SV=5.15  BV=6.66
    {863,1136,1024, 0, 0, 0},  //TV = 10.18(76 lines)  AV=1.53  SV=5.15  BV=6.56
    {931,1136,1024, 0, 0, 0},  //TV = 10.07(82 lines)  AV=1.53  SV=5.15  BV=6.45
    {999,1136,1024, 0, 0, 0},  //TV = 9.97(88 lines)  AV=1.53  SV=5.15  BV=6.35
    {1067,1136,1024, 0, 0, 0},  //TV = 9.87(94 lines)  AV=1.53  SV=5.15  BV=6.25
    {1146,1136,1024, 0, 0, 0},  //TV = 9.77(101 lines)  AV=1.53  SV=5.15  BV=6.15
    {1226,1136,1024, 0, 0, 0},  //TV = 9.67(108 lines)  AV=1.53  SV=5.15  BV=6.05
    {1317,1136,1024, 0, 0, 0},  //TV = 9.57(116 lines)  AV=1.53  SV=5.15  BV=5.95
    {1407,1136,1024, 0, 0, 0},  //TV = 9.47(124 lines)  AV=1.53  SV=5.15  BV=5.85
    {1521,1136,1024, 0, 0, 0},  //TV = 9.36(134 lines)  AV=1.53  SV=5.15  BV=5.74
    {1611,1136,1024, 0, 0, 0},  //TV = 9.28(142 lines)  AV=1.53  SV=5.15  BV=5.66
    {1748,1136,1024, 0, 0, 0},  //TV = 9.16(154 lines)  AV=1.53  SV=5.15  BV=5.54
    {1850,1136,1024, 0, 0, 0},  //TV = 9.08(163 lines)  AV=1.53  SV=5.15  BV=5.46
    {1997,1136,1024, 0, 0, 0},  //TV = 8.97(176 lines)  AV=1.53  SV=5.15  BV=5.35
    {2145,1136,1024, 0, 0, 0},  //TV = 8.86(189 lines)  AV=1.53  SV=5.15  BV=5.25
    {2292,1136,1024, 0, 0, 0},  //TV = 8.77(202 lines)  AV=1.53  SV=5.15  BV=5.15
    {2462,1136,1024, 0, 0, 0},  //TV = 8.67(217 lines)  AV=1.53  SV=5.15  BV=5.05
    {2644,1136,1024, 0, 0, 0},  //TV = 8.56(233 lines)  AV=1.53  SV=5.15  BV=4.94
    {2837,1136,1024, 0, 0, 0},  //TV = 8.46(250 lines)  AV=1.53  SV=5.15  BV=4.84
    {3030,1136,1024, 0, 0, 0},  //TV = 8.37(267 lines)  AV=1.53  SV=5.15  BV=4.75
    {3245,1136,1024, 0, 0, 0},  //TV = 8.27(286 lines)  AV=1.53  SV=5.15  BV=4.65
    {3495,1136,1024, 0, 0, 0},  //TV = 8.16(308 lines)  AV=1.53  SV=5.15  BV=4.54
    {3744,1136,1024, 0, 0, 0},  //TV = 8.06(330 lines)  AV=1.53  SV=5.15  BV=4.44
    {4005,1136,1024, 0, 0, 0},  //TV = 7.96(353 lines)  AV=1.53  SV=5.15  BV=4.35
    {4289,1136,1024, 0, 0, 0},  //TV = 7.87(378 lines)  AV=1.53  SV=5.15  BV=4.25
    {4595,1136,1024, 0, 0, 0},  //TV = 7.77(405 lines)  AV=1.53  SV=5.15  BV=4.15
    {4924,1136,1024, 0, 0, 0},  //TV = 7.67(434 lines)  AV=1.53  SV=5.15  BV=4.05
    {5299,1136,1024, 0, 0, 0},  //TV = 7.56(467 lines)  AV=1.53  SV=5.15  BV=3.94
    {5673,1136,1024, 0, 0, 0},  //TV = 7.46(500 lines)  AV=1.53  SV=5.15  BV=3.84
    {6081,1136,1024, 0, 0, 0},  //TV = 7.36(536 lines)  AV=1.53  SV=5.15  BV=3.74
    {6513,1136,1024, 0, 0, 0},  //TV = 7.26(574 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(615 lines)  AV=1.53  SV=5.15  BV=3.54
    {7466,1136,1024, 0, 0, 0},  //TV = 7.07(658 lines)  AV=1.53  SV=5.15  BV=3.45
    {7999,1136,1024, 0, 0, 0},  //TV = 6.97(705 lines)  AV=1.53  SV=5.15  BV=3.35
    {8328,1152,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.18  BV=3.26
    {8328,1248,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.29  BV=3.15
    {8328,1312,1048, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.39  BV=3.05
    {8328,1408,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.48  BV=2.96
    {8328,1536,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.58  BV=2.85
    {8328,1632,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.69  BV=2.74
    {8328,1760,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.79  BV=2.65
    {8328,1888,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.89  BV=2.55
    {8328,2016,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.99  BV=2.45
    {8328,2176,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.09  BV=2.35
    {16666,1152,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.18  BV=2.26
    {16666,1248,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.29  BV=2.15
    {16666,1312,1048, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.39  BV=2.05
    {16666,1408,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.48  BV=1.96
    {16666,1536,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.58  BV=1.85
    {16666,1632,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.68  BV=1.75
    {24994,1152,1048, 0, 0, 0},  //TV = 5.32(2203 lines)  AV=1.53  SV=5.20  BV=1.65
    {24994,1248,1032, 0, 0, 0},  //TV = 5.32(2203 lines)  AV=1.53  SV=5.30  BV=1.56
    {24994,1344,1032, 0, 0, 0},  //TV = 5.32(2203 lines)  AV=1.53  SV=5.40  BV=1.45
    {24994,1440,1032, 0, 0, 0},  //TV = 5.32(2203 lines)  AV=1.53  SV=5.50  BV=1.35
    {33332,1152,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.18  BV=1.26
    {33332,1248,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.29  BV=1.15
    {33332,1312,1048, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.39  BV=1.05
    {33332,1408,1040, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.48  BV=0.96
    {33332,1536,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.58  BV=0.85
    {33332,1632,1040, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.69  BV=0.74
    {33332,1760,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.79  BV=0.65
    {33332,1888,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.88  BV=0.56
    {33332,2016,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=5.99  BV=0.45
    {33332,2176,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.09  BV=0.35
    {33332,2304,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.18  BV=0.26
    {33332,2496,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.30  BV=0.14
    {33332,2656,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.39  BV=0.05
    {33332,2848,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33332,3072,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33332,3296,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33332,3520,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33332,3776,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33332,4064,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33332,4352,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33332,4672,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33332,4992,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33332,5376,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33332,5696,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33332,6144,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33332,6592,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33332,7040,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.78  BV=-1.34
    {33332,7616,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33332,8128,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33332,8704,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33332,9344,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33332,9984,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33332,10752,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33332,11520,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33332,12288,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33332,13056,1040, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.69  BV=-2.26
    {41671,11264,1032, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41671,12160,1024, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41671,13056,1024, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41671,13824,1032, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41671,14848,1032, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41671,15872,1032, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41671,16384,1072, 0, 0, 0},  //TV = 4.58(3673 lines)  AV=1.53  SV=9.07  BV=-2.95
    {49998,15104,1040, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=8.91  BV=-3.05
    {49998,16384,1024, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=9.00  BV=-3.15
    {49998,16384,1096, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=9.10  BV=-3.24
    {58336,16128,1024, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=8.98  BV=-3.35
    {58336,16384,1080, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.08  BV=-3.45
    {58336,16384,1160, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.18  BV=-3.55
    {58336,16384,1240, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.28  BV=-3.65
    {58336,16384,1336, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.38  BV=-3.75
    {58336,16384,1432, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.48  BV=-3.85
    {58336,16384,1536, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.58  BV=-3.95
    {58336,16384,1648, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.69  BV=-4.06
    {58336,16384,1768, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.79  BV=-4.16
    {58336,16384,1896, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.89  BV=-4.26
    {58336,16384,2032, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=9.99  BV=-4.36
    {58336,16384,2160, 0, 0, 0},  //TV = 4.10(5142 lines)  AV=1.53  SV=10.08  BV=-4.45
    {66664,16384,2032, 0, 0, 0},  //TV = 3.91(5876 lines)  AV=1.53  SV=9.99  BV=-4.55
    {75002,16384,1936, 0, 0, 0},  //TV = 3.74(6611 lines)  AV=1.53  SV=9.92  BV=-4.65
    {75002,16384,2072, 0, 0, 0},  //TV = 3.74(6611 lines)  AV=1.53  SV=10.02  BV=-4.75
    {83330,16384,2000, 0, 0, 0},  //TV = 3.59(7345 lines)  AV=1.53  SV=9.97  BV=-4.85
    {83330,16384,2144, 0, 0, 0},  //TV = 3.59(7345 lines)  AV=1.53  SV=10.07  BV=-4.95
    {91668,16384,2088, 0, 0, 0},  //TV = 3.45(8080 lines)  AV=1.53  SV=10.03  BV=-5.05
    {99995,16384,2056, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99995,16384,2208, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99995,16384,2368, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99995,16384,2536, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99995,16384,2720, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.41  BV=-5.56
    {99995,16384,2912, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99995,16384,3120, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99995,16384,3344, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99995,16384,3584, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99995,16384,3840, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99995,16384,4096, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.28  BV=9.67
    {103,1136,1024, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.15  BV=9.63 */
    {103,1184,1032, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56
    {114,1152,1048, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.20  BV=9.43
    {125,1136,1032, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.16  BV=9.34
    {125,1216,1024, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.25  BV=9.25
    {148,1136,1024, 0, 0, 0},  /* TV = 12.72(13 lines)  AV=1.53  SV=5.15  BV=9.10 */
    {148,1152,1048, 0, 0, 0},  /* TV = 12.72(13 lines)  AV=1.53  SV=5.20  BV=9.05 */
    {159,1152,1048, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.20  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.21  BV=8.84
    {193,1136,1024, 0, 0, 0},  //TV = 12.34(17 lines)  AV=1.53  SV=5.15  BV=8.72
    {193,1184,1032, 0, 0, 0},  //TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65
    {216,1136,1024, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.15  BV=8.56
    {227,1152,1032, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.18  BV=8.45
    {250,1136,1024, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.15  BV=8.35
    {261,1152,1032, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.18  BV=8.25
    {284,1136,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.16  BV=8.15
    {307,1136,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.15  BV=8.05
    {330,1136,1024, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.15  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.15  BV=7.85
    {375,1136,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.16  BV=7.75
    {398,1152,1024, 0, 0, 0},  //TV = 11.29(35 lines)  AV=1.53  SV=5.17  BV=7.66
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(38 lines)  AV=1.53  SV=5.15  BV=7.56
    {466,1136,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.15  BV=7.45
    {500,1136,1024, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.15  BV=7.35
    {534,1136,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.15  BV=7.25
    {568,1136,1032, 0, 0, 0},  //TV = 10.78(50 lines)  AV=1.53  SV=5.16  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(54 lines)  AV=1.53  SV=5.15  BV=7.05
    {659,1136,1024, 0, 0, 0},  //TV = 10.57(58 lines)  AV=1.53  SV=5.15  BV=6.95
    {704,1136,1024, 0, 0, 0},  //TV = 10.47(62 lines)  AV=1.53  SV=5.15  BV=6.85
    {749,1136,1032, 0, 0, 0},  //TV = 10.38(66 lines)  AV=1.53  SV=5.16  BV=6.75
    {806,1136,1024, 0, 0, 0},  //TV = 10.28(71 lines)  AV=1.53  SV=5.15  BV=6.66
    {863,1136,1024, 0, 0, 0},  //TV = 10.18(76 lines)  AV=1.53  SV=5.15  BV=6.56
    {931,1136,1024, 0, 0, 0},  //TV = 10.07(82 lines)  AV=1.53  SV=5.15  BV=6.45
    {999,1136,1024, 0, 0, 0},  //TV = 9.97(88 lines)  AV=1.53  SV=5.15  BV=6.35
    {1067,1136,1024, 0, 0, 0},  //TV = 9.87(94 lines)  AV=1.53  SV=5.15  BV=6.25
    {1146,1136,1024, 0, 0, 0},  //TV = 9.77(101 lines)  AV=1.53  SV=5.15  BV=6.15
    {1226,1136,1024, 0, 0, 0},  //TV = 9.67(108 lines)  AV=1.53  SV=5.15  BV=6.05
    {1317,1136,1024, 0, 0, 0},  //TV = 9.57(116 lines)  AV=1.53  SV=5.15  BV=5.95
    {1407,1136,1024, 0, 0, 0},  //TV = 9.47(124 lines)  AV=1.53  SV=5.15  BV=5.85
    {1521,1136,1024, 0, 0, 0},  //TV = 9.36(134 lines)  AV=1.53  SV=5.15  BV=5.74
    {1611,1136,1024, 0, 0, 0},  //TV = 9.28(142 lines)  AV=1.53  SV=5.15  BV=5.66
    {1748,1136,1024, 0, 0, 0},  //TV = 9.16(154 lines)  AV=1.53  SV=5.15  BV=5.54
    {1850,1136,1024, 0, 0, 0},  //TV = 9.08(163 lines)  AV=1.53  SV=5.15  BV=5.46
    {1997,1136,1024, 0, 0, 0},  //TV = 8.97(176 lines)  AV=1.53  SV=5.15  BV=5.35
    {2145,1136,1024, 0, 0, 0},  //TV = 8.86(189 lines)  AV=1.53  SV=5.15  BV=5.25
    {2292,1136,1024, 0, 0, 0},  //TV = 8.77(202 lines)  AV=1.53  SV=5.15  BV=5.15
    {2462,1136,1024, 0, 0, 0},  //TV = 8.67(217 lines)  AV=1.53  SV=5.15  BV=5.05
    {2644,1136,1024, 0, 0, 0},  //TV = 8.56(233 lines)  AV=1.53  SV=5.15  BV=4.94
    {2837,1136,1024, 0, 0, 0},  //TV = 8.46(250 lines)  AV=1.53  SV=5.15  BV=4.84
    {3030,1136,1024, 0, 0, 0},  //TV = 8.37(267 lines)  AV=1.53  SV=5.15  BV=4.75
    {3245,1136,1024, 0, 0, 0},  //TV = 8.27(286 lines)  AV=1.53  SV=5.15  BV=4.65
    {3495,1136,1024, 0, 0, 0},  //TV = 8.16(308 lines)  AV=1.53  SV=5.15  BV=4.54
    {3744,1136,1024, 0, 0, 0},  //TV = 8.06(330 lines)  AV=1.53  SV=5.15  BV=4.44
    {4005,1136,1024, 0, 0, 0},  //TV = 7.96(353 lines)  AV=1.53  SV=5.15  BV=4.35
    {4289,1136,1024, 0, 0, 0},  //TV = 7.87(378 lines)  AV=1.53  SV=5.15  BV=4.25
    {4595,1136,1024, 0, 0, 0},  //TV = 7.77(405 lines)  AV=1.53  SV=5.15  BV=4.15
    {4924,1136,1024, 0, 0, 0},  //TV = 7.67(434 lines)  AV=1.53  SV=5.15  BV=4.05
    {5299,1136,1024, 0, 0, 0},  //TV = 7.56(467 lines)  AV=1.53  SV=5.15  BV=3.94
    {5673,1136,1024, 0, 0, 0},  //TV = 7.46(500 lines)  AV=1.53  SV=5.15  BV=3.84
    {6081,1136,1024, 0, 0, 0},  //TV = 7.36(536 lines)  AV=1.53  SV=5.15  BV=3.74
    {6513,1136,1024, 0, 0, 0},  //TV = 7.26(574 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(615 lines)  AV=1.53  SV=5.15  BV=3.54
    {7466,1136,1024, 0, 0, 0},  //TV = 7.07(658 lines)  AV=1.53  SV=5.15  BV=3.45
    {7999,1136,1024, 0, 0, 0},  //TV = 6.97(705 lines)  AV=1.53  SV=5.15  BV=3.35
    {8566,1136,1024, 0, 0, 0},  //TV = 6.87(755 lines)  AV=1.53  SV=5.15  BV=3.25
    {9179,1136,1024, 0, 0, 0},  //TV = 6.77(809 lines)  AV=1.53  SV=5.15  BV=3.15
    {9837,1136,1024, 0, 0, 0},  //TV = 6.67(867 lines)  AV=1.53  SV=5.15  BV=3.05
    {9995,1184,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.22  BV=2.95
    {9995,1280,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.33  BV=2.84
    {9995,1344,1048, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.43  BV=2.75
    {9995,1472,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.52  BV=2.65
    {9995,1568,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.63  BV=2.55
    {9995,1696,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.73  BV=2.45
    {9995,1792,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.83  BV=2.35
    {9995,1920,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.93  BV=2.25
    {9995,2080,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.02  BV=2.15
    {9995,2208,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.12  BV=2.06
    {20002,1184,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.22  BV=1.95
    {20002,1280,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.32  BV=1.85
    {20002,1344,1048, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.43  BV=1.75
    {20002,1472,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.52  BV=1.65
    {20002,1568,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.63  BV=1.55
    {20002,1664,1040, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=5.72  BV=1.45
    {29997,1184,1048, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.24  BV=1.35
    {29997,1280,1040, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.34  BV=1.25
    {29997,1376,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.44  BV=1.15
    {29997,1472,1040, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.55  BV=1.04
    {29997,1600,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.64  BV=0.95
    {29997,1696,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.74  BV=0.85
    {29997,1824,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.84  BV=0.75
    {29997,1952,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=5.94  BV=0.65
    {29997,2080,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.03  BV=0.56
    {29997,2240,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.14  BV=0.45
    {29997,2400,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.24  BV=0.35
    {29997,2592,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.35  BV=0.24
    {29997,2784,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.44  BV=0.15
    {29997,2976,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.54  BV=0.05
    {29997,3168,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.64  BV=-0.05
    {29997,3392,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.74  BV=-0.15
    {29997,3680,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.85  BV=-0.26
    {29997,3936,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.94  BV=-0.35
    {29997,4160,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.03  BV=-0.44
    {29997,4480,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.14  BV=-0.55
    {29997,4800,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.24  BV=-0.65
    {29997,5184,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.34  BV=-0.75
    {29997,5568,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.44  BV=-0.85
    {29997,5952,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.54  BV=-0.95
    {29997,6336,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.64  BV=-1.05
    {29997,6848,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.74  BV=-1.15
    {29997,7296,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.83  BV=-1.24
    {29997,7808,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.93  BV=-1.34
    {29997,8320,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.03  BV=-1.44
    {29997,8960,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.14  BV=-1.55
    {29997,9600,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.24  BV=-1.65
    {29997,10368,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.34  BV=-1.75
    {29997,11136,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.44  BV=-1.85
    {29997,11904,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.54  BV=-1.95
    {29997,12800,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.64  BV=-2.05
    {29997,13568,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40003,11008,1024, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40003,11776,1024, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40003,12544,1032, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40003,13568,1024, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40003,14336,1040, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40003,15616,1024, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40003,16384,1040, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40003,16384,1112, 0, 0, 0},  //TV = 4.64(3526 lines)  AV=1.53  SV=9.12  BV=-2.94
    {49998,15104,1040, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=8.91  BV=-3.05
    {49998,16384,1024, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=9.00  BV=-3.15
    {49998,16384,1096, 0, 0, 0},  //TV = 4.32(4407 lines)  AV=1.53  SV=9.10  BV=-3.24
    {60004,15616,1032, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=8.94  BV=-3.35
    {60004,16384,1048, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.03  BV=-3.44
    {60004,16384,1128, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.14  BV=-3.55
    {60004,16384,1208, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.24  BV=-3.65
    {60004,16384,1304, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.35  BV=-3.76
    {60004,16384,1392, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.44  BV=-3.85
    {60004,16384,1496, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.55  BV=-3.96
    {60004,16384,1600, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.64  BV=-4.05
    {60004,16384,1720, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.75  BV=-4.16
    {60004,16384,1840, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.85  BV=-4.26
    {60004,16384,1976, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=9.95  BV=-4.36
    {60004,16384,2104, 0, 0, 0},  //TV = 4.06(5289 lines)  AV=1.53  SV=10.04  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6170 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6170 lines)  AV=1.53  SV=10.02  BV=-4.65
    {80005,16384,1944, 0, 0, 0},  //TV = 3.64(7052 lines)  AV=1.53  SV=9.92  BV=-4.75
    {80005,16384,2080, 0, 0, 0},  //TV = 3.64(7052 lines)  AV=1.53  SV=10.02  BV=-4.85
    {90000,16384,1984, 0, 0, 0},  //TV = 3.47(7933 lines)  AV=1.53  SV=9.95  BV=-4.95
    {90000,16384,2128, 0, 0, 0},  //TV = 3.47(7933 lines)  AV=1.53  SV=10.06  BV=-5.05
    {99995,16384,2056, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99995,16384,2208, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99995,16384,2368, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99995,16384,2536, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99995,16384,2720, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.41  BV=-5.56
    {99995,16384,2912, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99995,16384,3120, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99995,16384,3344, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99995,16384,3584, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99995,16384,3840, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99995,16384,4096, 0, 0, 0},  //TV = 3.32(8814 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    160, //u4TotalIndex
    20, //i4StrobeTrigerBV
    97, //i4MaxBV
    -62, //i4MinBV
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8335,1152,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.18  BV=3.26
    {8335,1248,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.29  BV=3.15
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.69  BV=2.74
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.88  BV=2.56
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {16668,1152,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.18  BV=2.26
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {25001,1152,1048, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.20  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {33334,1152,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.18  BV=1.26
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1440,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.49  BV=0.95
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.69  BV=0.74
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2848,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4064,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5376,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7040,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.78  BV=-1.34
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11520,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {50000,15104,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.00  BV=-3.15
    {50000,16384,1096, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.10  BV=-3.25
    {58333,16128,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.98  BV=-3.35
    {58333,16384,1080, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.08  BV=-3.45
    {58333,16384,1160, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.18  BV=-3.55
    {58333,16384,1240, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.28  BV=-3.65
    {58333,16384,1328, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.38  BV=-3.74
    {58333,16384,1424, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.48  BV=-3.85
    {58333,16384,1536, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.58  BV=-3.95
    {58333,16384,1648, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.69  BV=-4.06
    {58333,16384,1768, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.79  BV=-4.16
    {58333,16384,1896, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.89  BV=-4.26
    {58333,16384,2032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.99  BV=-4.36
    {58333,16384,2160, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.08  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {74999,16384,1936, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=9.92  BV=-4.65
    {74999,16384,2072, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.02  BV=-4.75
    {83332,16384,2000, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=9.97  BV=-4.85
    {83332,16384,2144, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.07  BV=-4.95
    {91666,16384,2088, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.03  BV=-5.05
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99999,16384,2208, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99999,16384,2368, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99999,16384,2536, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99999,16384,2712, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.41  BV=-5.55
    {99999,16384,2912, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99999,16384,3120, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99999,16384,3344, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99999,16384,3584, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99999,16384,3840, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99999,16384,4096, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8575,1136,1024, 0, 0, 0},  //TV = 6.87(854 lines)  AV=1.53  SV=5.15  BV=3.25
    {9187,1136,1024, 0, 0, 0},  //TV = 6.77(915 lines)  AV=1.53  SV=5.15  BV=3.15
    {9840,1136,1024, 0, 0, 0},  //TV = 6.67(980 lines)  AV=1.53  SV=5.15  BV=3.05
    {10000,1184,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.22  BV=2.95
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.34  BV=1.25
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1600,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2080,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.03  BV=0.56
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.35  BV=0.24
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30000,3392,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7808,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.93  BV=-1.34
    {30000,8320,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.03  BV=-1.44
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1112, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.12  BV=-2.94
    {50000,15104,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.00  BV=-3.15
    {50000,16384,1096, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.10  BV=-3.25
    {60000,15616,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.94  BV=-3.35
    {60000,16384,1048, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.03  BV=-3.44
    {60000,16384,1128, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.14  BV=-3.55
    {60000,16384,1208, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.24  BV=-3.65
    {60000,16384,1296, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.34  BV=-3.75
    {60000,16384,1392, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.44  BV=-3.85
    {60000,16384,1496, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.55  BV=-3.96
    {60000,16384,1600, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.64  BV=-4.05
    {60000,16384,1720, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.75  BV=-4.16
    {60000,16384,1840, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.85  BV=-4.26
    {60000,16384,1976, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.95  BV=-4.36
    {60000,16384,2104, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.04  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {79999,16384,1944, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=9.92  BV=-4.75
    {79999,16384,2080, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.02  BV=-4.85
    {89999,16384,1984, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=9.95  BV=-4.95
    {89999,16384,2128, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.06  BV=-5.05
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99999,16384,2208, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99999,16384,2368, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99999,16384,2536, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99999,16384,2712, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.41  BV=-5.55
    {99999,16384,2912, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99999,16384,3120, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99999,16384,3344, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99999,16384,3584, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99999,16384,3840, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99999,16384,4096, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    160, //u4TotalIndex
    20, //i4StrobeTrigerBV
    97, //i4MaxBV
    -62, //i4MinBV
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8335,1152,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.18  BV=3.26
    {8335,1248,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.29  BV=3.15
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.69  BV=2.74
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.88  BV=2.56
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {16668,1152,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.18  BV=2.26
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {25001,1152,1048, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.20  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {33293,1152,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.18  BV=1.26
    {33293,1248,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.29  BV=1.15
    {33293,1312,1048, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.39  BV=1.05
    {33293,1408,1040, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.48  BV=0.96
    {33293,1536,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.58  BV=0.85
    {33293,1632,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.68  BV=0.76
    {33293,1760,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.79  BV=0.65
    {33293,1888,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=5.89  BV=0.55
    {33293,2016,1040, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.00  BV=0.44
    {33293,2176,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.09  BV=0.35
    {33293,2304,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.18  BV=0.26
    {33293,2496,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.29  BV=0.15
    {33293,2688,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.39  BV=0.05
    {33293,2848,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33293,3072,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33293,3296,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33293,3552,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33293,3776,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.89  BV=-0.45
    {33293,4064,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33293,4352,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33293,4608,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.18  BV=-0.74
    {33293,4992,1032, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.30  BV=-0.86
    {33293,5376,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33293,5760,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33293,6144,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33293,6592,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33293,7040,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.78  BV=-1.34
    {33293,7552,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.88  BV=-1.44
    {33293,8128,1024, 0, 0, 0},  //TV = 4.91(3316 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33303,8704,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=8.09  BV=-1.65
    {41666,7424,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=7.86  BV=-1.74
    {41666,8000,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=7.97  BV=-1.85
    {41666,8576,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.07  BV=-1.95
    {41666,9088,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.16  BV=-2.04
    {41666,9856,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.27  BV=-2.15
    {41666,10496,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.36  BV=-2.24
    {41666,11264,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.46  BV=-2.34
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.17  BV=-3.05
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1416, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.47  BV=-3.35
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.55
    {41666,16384,1744, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.77  BV=-3.65
    {41666,16384,1872, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.87  BV=-3.75
    {41666,16384,2000, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.85
    {41666,16384,2144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.95
    {41666,16384,2304, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.17  BV=-4.05
    {41666,16384,2464, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.27  BV=-4.15
    {41666,16384,2640, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.37  BV=-4.25
    {41666,16384,2832, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.47  BV=-4.35
    {41666,16384,3032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.57  BV=-4.45
    {41666,16384,3256, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.67  BV=-4.55
    {41666,16384,3488, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.77  BV=-4.65
    {41666,16384,3736, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.87  BV=-4.75
    {41666,16384,4008, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.97  BV=-4.85
    {41666,16384,4296, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=11.07  BV=-4.95
    {50000,16384,3832, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.90  BV=-5.05
    {50000,16384,4112, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.01  BV=-5.15
    {50000,16384,4408, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.11  BV=-5.25
    {58333,16384,4048, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.98  BV=-5.35
    {58333,16384,4336, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=11.08  BV=-5.45
    {66636,16384,4072, 0, 0, 0},  //TV = 3.91(6637 lines)  AV=1.53  SV=10.99  BV=-5.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8575,1136,1024, 0, 0, 0},  //TV = 6.87(854 lines)  AV=1.53  SV=5.15  BV=3.25
    {9187,1136,1024, 0, 0, 0},  //TV = 6.77(915 lines)  AV=1.53  SV=5.15  BV=3.15
    {9840,1136,1024, 0, 0, 0},  //TV = 6.67(980 lines)  AV=1.53  SV=5.15  BV=3.05
    {10000,1184,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.22  BV=2.95
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.34  BV=1.25
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1600,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2080,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.03  BV=0.56
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.35  BV=0.24
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30000,3392,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7808,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.93  BV=-1.34
    {30000,8320,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.03  BV=-1.44
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {40000,7232,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.82  BV=-1.65
    {40000,7744,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.92  BV=-1.74
    {40000,8320,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.02  BV=-1.85
    {40000,8832,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.12  BV=-1.94
    {40000,9472,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.22  BV=-2.05
    {40000,10240,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.32  BV=-2.15
    {40000,10880,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.42  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14592,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.66
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1200, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.23  BV=-3.05
    {40000,16384,1288, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.33  BV=-3.16
    {40000,16384,1376, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.43  BV=-3.25
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {40000,16384,1816, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.65
    {40000,16384,1944, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.92  BV=-3.75
    {40000,16384,2088, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.85
    {40000,16384,2232, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.12  BV=-3.95
    {40000,16384,2400, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.23  BV=-4.05
    {40000,16384,2568, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.33  BV=-4.15
    {40000,16384,2752, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.43  BV=-4.25
    {40000,16384,2952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.53  BV=-4.35
    {40000,16384,3160, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.63  BV=-4.45
    {40000,16384,3392, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.73  BV=-4.55
    {40000,16384,3632, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.83  BV=-4.65
    {40000,16384,3896, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.93  BV=-4.75
    {40000,16384,4168, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.03  BV=-4.85
    {40000,16384,4472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.13  BV=-4.95
    {50000,16384,3832, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.90  BV=-5.05
    {50000,16384,4112, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.01  BV=-5.15
    {50000,16384,4408, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.11  BV=-5.25
    {60000,16384,3936, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.94  BV=-5.35
    {60000,16384,4216, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.04  BV=-5.45
    {69999,16384,3872, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.92  BV=-5.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    154, //u4TotalIndex
    20, //i4StrobeTrigerBV
    97, //i4MaxBV
    -56, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8263,1248,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.30  BV=3.15
    {8263,1344,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.39  BV=3.06
    {8263,1440,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.50  BV=2.95
    {8263,1536,1040, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.61  BV=2.84
    {8263,1632,1040, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.69  BV=2.76
    {8263,1760,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.79  BV=2.66
    {8263,1888,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.89  BV=2.56
    {8263,2048,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.00  BV=2.45
    {8263,2176,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.10  BV=2.35
    {8263,2336,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.20  BV=2.25
    {8263,2496,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.30  BV=2.15
    {8263,2688,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.39  BV=2.06
    {8263,2912,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.51  BV=1.94
    {8263,3104,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.60  BV=1.85
    {8263,3328,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.70  BV=1.75
    {8263,3552,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.79  BV=1.66
    {8263,3808,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.89  BV=1.56
    {8263,4096,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.00  BV=1.45
    {8263,4352,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.10  BV=1.35
    {8263,4672,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.20  BV=1.25
    {8263,4992,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.30  BV=1.15
    {8263,5376,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.39  BV=1.06
    {8263,5760,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.49  BV=0.96
    {8263,6208,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.60  BV=0.85
    {8263,6656,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.70  BV=0.75
    {8263,7104,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.81  BV=0.64
    {8263,7616,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.91  BV=0.54
    {8263,8192,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.00  BV=0.45
    {8263,8704,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.10  BV=0.35
    {8263,9344,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.20  BV=0.25
    {8263,9984,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.30  BV=0.15
    {8263,10752,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.39  BV=0.06
    {8263,11520,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.49  BV=-0.04
    {8263,12288,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.60  BV=-0.15
    {8263,13312,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.70  BV=-0.25
    {8263,14080,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.79  BV=-0.34
    {8263,15360,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.91  BV=-0.46
    {8263,16384,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.00  BV=-0.55
    {8263,16384,1104, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.11  BV=-0.66
    {8263,16384,1176, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.20  BV=-0.75
    {8263,16384,1264, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.30  BV=-0.85
    {8263,16384,1280, 0, 0, 0},  /* TV = 6.92(823 lines)  AV=1.53  SV=9.32  BV=-0.87 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8263,1248,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.30  BV=3.15
    {8263,1344,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.39  BV=3.06
    {8263,1440,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.50  BV=2.95
    {8263,1536,1040, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.61  BV=2.84
    {8263,1632,1040, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.69  BV=2.76
    {8263,1760,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.79  BV=2.66
    {8263,1888,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=5.89  BV=2.56
    {8263,2048,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.00  BV=2.45
    {8263,2176,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.10  BV=2.35
    {8263,2336,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.20  BV=2.25
    {8263,2496,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.30  BV=2.15
    {8263,2688,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.39  BV=2.06
    {8263,2912,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.51  BV=1.94
    {8263,3104,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.60  BV=1.85
    {8263,3328,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.70  BV=1.75
    {8263,3552,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.79  BV=1.66
    {8263,3808,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=6.89  BV=1.56
    {8263,4096,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.00  BV=1.45
    {8263,4352,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.10  BV=1.35
    {8263,4672,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.20  BV=1.25
    {8263,4992,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.30  BV=1.15
    {8263,5376,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.39  BV=1.06
    {8263,5760,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.49  BV=0.96
    {8263,6208,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.60  BV=0.85
    {8263,6656,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.70  BV=0.75
    {8263,7104,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.81  BV=0.64
    {8263,7616,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=7.91  BV=0.54
    {8263,8192,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.00  BV=0.45
    {8263,8704,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.10  BV=0.35
    {8263,9344,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.20  BV=0.25
    {8263,9984,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.30  BV=0.15
    {8263,10752,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.39  BV=0.06
    {8263,11520,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.49  BV=-0.04
    {8263,12288,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.60  BV=-0.15
    {8263,13312,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.70  BV=-0.25
    {8263,14080,1032, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.79  BV=-0.34
    {8263,15360,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=8.91  BV=-0.46
    {8263,16384,1024, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.00  BV=-0.55
    {8263,16384,1104, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.11  BV=-0.66
    {8263,16384,1176, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.20  BV=-0.75
    {8263,16384,1264, 0, 0, 0},  //TV = 6.92(823 lines)  AV=1.53  SV=9.30  BV=-0.85
    {8263,16384,1280, 0, 0, 0},  /* TV = 6.92(823 lines)  AV=1.53  SV=9.32  BV=-0.87 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -9, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {16668,1888,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.88  BV=1.56
    {16668,2016,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.99  BV=1.45
    {16668,2176,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.09  BV=1.35
    {16668,2304,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.18  BV=1.26
    {16668,2496,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.29  BV=1.15
    {16668,2656,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.39  BV=1.05
    {16668,2880,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.49  BV=0.95
    {16667,3072,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.60  BV=0.84
    {16667,3296,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.69  BV=0.75
    {16667,3520,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.79  BV=0.65
    {16667,3776,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.89  BV=0.54
    {25000,2688,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.40  BV=0.45
    {25000,2880,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.50  BV=0.35
    {25000,3104,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.60  BV=0.25
    {25000,3328,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.70  BV=0.15
    {25000,3552,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.81  BV=0.05
    {33303,2848,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33303,3072,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33303,3296,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33303,3520,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33303,3808,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.89  BV=-0.46
    {33303,4064,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33303,4352,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33303,4672,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33303,4992,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33303,5312,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33303,5696,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33303,6144,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.60  BV=-1.16
    {33303,6592,1032, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.70  BV=-1.26
    {33303,7104,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33303,7616,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33303,8128,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33303,8704,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33303,9344,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33303,9984,1024, 0, 0, 0},  //TV = 4.91(3317 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33303,10112,1032, 0, 0, 0},  /* TV = 4.91(3317 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {10000,2400,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.23  BV=1.95
    {10000,2560,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.32  BV=1.85
    {10000,2720,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.42  BV=1.75
    {10000,2944,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.52  BV=1.65
    {10000,3136,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.61  BV=1.56
    {10000,3392,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.73  BV=1.45
    {10000,3616,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.82  BV=1.35
    {10000,3904,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.93  BV=1.24
    {10000,4160,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.02  BV=1.15
    {10000,4416,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.12  BV=1.06
    {10000,4736,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.22  BV=0.95
    {20000,2560,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.32  BV=0.85
    {20000,2752,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.43  BV=0.75
    {20000,2944,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.52  BV=0.65
    {20000,3136,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.63  BV=0.55
    {20000,3392,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.73  BV=0.45
    {20000,3616,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.82  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2752,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3904,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7360,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.85  BV=-1.26
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10112,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.32  BV=-1.73
    {30000,10112,1032, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=8.32  BV=-1.73 */
    {30000,10112,1032, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=8.32  BV=-1.73 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8328,1248,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.29  BV=3.15
    {8328,1312,1048, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.39  BV=3.05
    {8328,1408,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.48  BV=2.96
    {8328,1536,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.60  BV=2.84
    {8328,1632,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.69  BV=2.74
    {8328,1760,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.79  BV=2.65
    {8328,1888,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.89  BV=2.55
    {8328,2016,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.99  BV=2.45
    {8328,2176,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.09  BV=2.35
    {8328,2336,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.19  BV=2.25
    {16666,1248,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.29  BV=2.15
    {16666,1312,1048, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.39  BV=2.05
    {16666,1408,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.48  BV=1.96
    {16666,1536,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.58  BV=1.85
    {16666,1632,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.69  BV=1.74
    {16666,1760,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.79  BV=1.65
    {16666,1888,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.88  BV=1.56
    {16666,2016,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.99  BV=1.45
    {16666,2176,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.09  BV=1.35
    {16666,2304,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.18  BV=1.26
    {16666,2496,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.29  BV=1.15
    {16666,2656,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.39  BV=1.05
    {16666,2848,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.49  BV=0.95
    {16666,3072,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.60  BV=0.84
    {16666,3296,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.69  BV=0.75
    {16666,3520,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.79  BV=0.65
    {16666,3776,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.89  BV=0.54
    {25005,2688,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.40  BV=0.45
    {25005,2880,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.50  BV=0.35
    {25005,3104,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.60  BV=0.25
    {25005,3328,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.70  BV=0.15
    {25005,3552,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.81  BV=0.05
    {33332,2848,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33332,3072,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33332,3296,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33332,3520,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33332,3776,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33332,4064,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33332,4352,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33332,4672,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33332,4992,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33332,5312,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33332,5696,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33332,6144,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33332,6592,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33332,7104,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33332,7552,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33332,8128,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33332,8704,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33332,9344,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33332,9984,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33332,10112,1032, 0, 0, 0},  /* TV = 4.91(2938 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8691,1184,1032, 0, 0, 0},  //TV = 6.85(766 lines)  AV=1.53  SV=5.22  BV=3.16
    {9371,1184,1032, 0, 0, 0},  //TV = 6.74(826 lines)  AV=1.53  SV=5.22  BV=3.05
    {9995,1184,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.23  BV=2.94
    {9995,1280,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.32  BV=2.85
    {9995,1344,1048, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.43  BV=2.75
    {9995,1472,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.52  BV=2.65
    {9995,1568,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.63  BV=2.55
    {9995,1696,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.73  BV=2.45
    {9995,1792,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.83  BV=2.35
    {9995,1920,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.93  BV=2.25
    {9995,2080,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.02  BV=2.15
    {9995,2208,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.12  BV=2.06
    {9995,2400,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.23  BV=1.95
    {9995,2560,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.32  BV=1.85
    {9995,2720,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.42  BV=1.76
    {9995,2944,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.52  BV=1.65
    {9995,3136,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.61  BV=1.56
    {9995,3392,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.73  BV=1.45
    {9995,3616,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.82  BV=1.36
    {9995,3904,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.93  BV=1.24
    {9995,4160,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.02  BV=1.15
    {9995,4416,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.12  BV=1.06
    {9995,4736,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.22  BV=0.95
    {20002,2560,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.32  BV=0.85
    {20002,2752,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.43  BV=0.75
    {20002,2944,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.52  BV=0.65
    {20002,3136,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.63  BV=0.55
    {20002,3392,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.73  BV=0.45
    {20002,3616,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.82  BV=0.35
    {29997,2592,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.34  BV=0.25
    {29997,2752,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.44  BV=0.15
    {29997,2976,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.54  BV=0.05
    {29997,3168,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.64  BV=-0.05
    {29997,3424,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.74  BV=-0.15
    {29997,3648,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.84  BV=-0.25
    {29997,3904,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.94  BV=-0.35
    {29997,4160,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.03  BV=-0.44
    {29997,4480,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.14  BV=-0.55
    {29997,4800,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.24  BV=-0.65
    {29997,5184,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.34  BV=-0.75
    {29997,5568,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.44  BV=-0.85
    {29997,5952,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.54  BV=-0.95
    {29997,6336,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.64  BV=-1.05
    {29997,6848,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.74  BV=-1.15
    {29997,7360,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.85  BV=-1.26
    {29997,7872,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.94  BV=-1.35
    {29997,8448,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.04  BV=-1.45
    {29997,8960,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.14  BV=-1.55
    {29997,9600,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.24  BV=-1.65
    {29997,10112,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8328,1248,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.29  BV=3.15
    {8328,1312,1048, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.39  BV=3.05
    {8328,1408,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.48  BV=2.96
    {8328,1536,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.60  BV=2.84
    {8328,1632,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.69  BV=2.74
    {8328,1760,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.79  BV=2.65
    {8328,1888,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.89  BV=2.55
    {8328,2016,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.99  BV=2.45
    {8328,2176,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.09  BV=2.35
    {8328,2336,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.19  BV=2.25
    {16666,1248,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.29  BV=2.15
    {16666,1312,1048, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.39  BV=2.05
    {16666,1408,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.48  BV=1.96
    {16666,1536,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.58  BV=1.85
    {16666,1632,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.69  BV=1.74
    {16666,1760,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.79  BV=1.65
    {16666,1888,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.88  BV=1.56
    {16666,2016,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.99  BV=1.45
    {16666,2176,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.09  BV=1.35
    {16666,2304,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.18  BV=1.26
    {16666,2496,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.29  BV=1.15
    {16666,2656,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.39  BV=1.05
    {16666,2848,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.49  BV=0.95
    {16666,3072,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.60  BV=0.84
    {16666,3296,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.69  BV=0.75
    {16666,3520,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.79  BV=0.65
    {16666,3776,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.89  BV=0.54
    {25005,2688,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.40  BV=0.45
    {25005,2880,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.50  BV=0.35
    {25005,3104,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.60  BV=0.25
    {25005,3328,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.70  BV=0.15
    {25005,3552,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.81  BV=0.05
    {33332,2848,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33332,3072,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33332,3296,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33332,3520,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33332,3776,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33332,4064,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33332,4352,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33332,4672,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33332,4992,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33332,5312,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33332,5696,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33332,6144,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33332,6592,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33332,7104,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33332,7552,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33332,8128,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33332,8704,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33332,9344,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33332,9984,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33332,10112,1032, 0, 0, 0},  /* TV = 4.91(2938 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8691,1184,1032, 0, 0, 0},  //TV = 6.85(766 lines)  AV=1.53  SV=5.22  BV=3.16
    {9371,1184,1032, 0, 0, 0},  //TV = 6.74(826 lines)  AV=1.53  SV=5.22  BV=3.05
    {9995,1184,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.23  BV=2.94
    {9995,1280,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.32  BV=2.85
    {9995,1344,1048, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.43  BV=2.75
    {9995,1472,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.52  BV=2.65
    {9995,1568,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.63  BV=2.55
    {9995,1696,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.73  BV=2.45
    {9995,1792,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.83  BV=2.35
    {9995,1920,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.93  BV=2.25
    {9995,2080,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.02  BV=2.15
    {9995,2208,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.12  BV=2.06
    {9995,2400,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.23  BV=1.95
    {9995,2560,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.32  BV=1.85
    {9995,2720,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.42  BV=1.76
    {9995,2944,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.52  BV=1.65
    {9995,3136,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.61  BV=1.56
    {9995,3392,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.73  BV=1.45
    {9995,3616,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.82  BV=1.36
    {9995,3904,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.93  BV=1.24
    {9995,4160,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.02  BV=1.15
    {9995,4416,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.12  BV=1.06
    {9995,4736,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.22  BV=0.95
    {20002,2560,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.32  BV=0.85
    {20002,2752,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.43  BV=0.75
    {20002,2944,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.52  BV=0.65
    {20002,3136,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.63  BV=0.55
    {20002,3392,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.73  BV=0.45
    {20002,3616,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.82  BV=0.35
    {29997,2592,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.34  BV=0.25
    {29997,2752,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.44  BV=0.15
    {29997,2976,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.54  BV=0.05
    {29997,3168,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.64  BV=-0.05
    {29997,3424,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.74  BV=-0.15
    {29997,3648,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.84  BV=-0.25
    {29997,3904,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.94  BV=-0.35
    {29997,4160,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.03  BV=-0.44
    {29997,4480,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.14  BV=-0.55
    {29997,4800,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.24  BV=-0.65
    {29997,5184,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.34  BV=-0.75
    {29997,5568,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.44  BV=-0.85
    {29997,5952,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.54  BV=-0.95
    {29997,6336,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.64  BV=-1.05
    {29997,6848,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.74  BV=-1.15
    {29997,7360,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.85  BV=-1.26
    {29997,7872,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.94  BV=-1.35
    {29997,8448,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.04  BV=-1.45
    {29997,8960,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.14  BV=-1.55
    {29997,9600,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.24  BV=-1.65
    {29997,10112,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {94,1248,1048, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.53  SV=5.32  BV=9.59
    {105,1184,1040, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.53  SV=5.23  BV=9.52
    {105,1248,1048, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.53  SV=5.32  BV=9.43
    {115,1216,1040, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.53  SV=5.27  BV=9.35
    {126,1184,1040, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.53  SV=5.23  BV=9.25
    {136,1216,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.53  SV=5.25  BV=9.13
    {146,1184,1048, 0, 0, 0},  //TV = 12.74(14 lines)  AV=1.53  SV=5.24  BV=9.03
    {157,1216,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.53  SV=5.25  BV=8.92
    {167,1216,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.53  SV=5.26  BV=8.82
    {178,1184,1040, 0, 0, 0},  /* TV = 12.46(17 lines)  AV=1.53  SV=5.23  BV=8.76 */
    {188,1216,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.53  SV=5.26  BV=8.65
    {199,1216,1040, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.53  SV=5.27  BV=8.56
    {219,1184,1040, 0, 0, 0},  //TV = 12.16(21 lines)  AV=1.53  SV=5.23  BV=8.46
    {230,1216,1040, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.53  SV=5.27  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(25 lines)  AV=1.53  SV=5.28  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.53  SV=5.22  BV=8.05
    {313,1184,1032, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.53  SV=5.22  BV=7.95
    {334,1184,1040, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.53  SV=5.23  BV=7.85
    {355,1184,1048, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.53  SV=5.24  BV=7.75
    {386,1184,1032, 0, 0, 0},  //TV = 11.34(37 lines)  AV=1.53  SV=5.22  BV=7.65
    {407,1184,1048, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.53  SV=5.24  BV=7.55
    {438,1184,1040, 0, 0, 0},  //TV = 11.16(42 lines)  AV=1.53  SV=5.23  BV=7.46
    {470,1184,1040, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.53  SV=5.23  BV=7.35
    {501,1184,1048, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.53  SV=5.22  BV=7.16
    {574,1184,1048, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.53  SV=5.24  BV=7.05
    {616,1184,1048, 0, 0, 0},  //TV = 10.66(59 lines)  AV=1.53  SV=5.24  BV=6.95
    {668,1184,1040, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.53  SV=5.23  BV=6.85
    {720,1184,1032, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.53  SV=5.22  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.53  SV=5.24  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(79 lines)  AV=1.53  SV=5.22  BV=6.56
    {876,1184,1040, 0, 0, 0},  //TV = 10.16(84 lines)  AV=1.53  SV=5.23  BV=6.46
    {939,1184,1040, 0, 0, 0},  //TV = 10.06(90 lines)  AV=1.53  SV=5.23  BV=6.36
    {1012,1184,1040, 0, 0, 0},  //TV = 9.95(97 lines)  AV=1.53  SV=5.23  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.53  SV=5.23  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.53  SV=5.23  BV=6.05
    {1251,1184,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.53  SV=5.22  BV=5.95
    {1345,1184,1032, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.53  SV=5.22  BV=5.85
    {1429,1184,1040, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.53  SV=5.22  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(158 lines)  AV=1.53  SV=5.22  BV=5.56
    {1773,1184,1032, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.53  SV=5.22  BV=5.45
    {1887,1184,1040, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.53  SV=5.23  BV=5.35
    {2033,1184,1040, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.53  SV=5.23  BV=5.24
    {2158,1184,1040, 0, 0, 0},  //TV = 8.86(207 lines)  AV=1.53  SV=5.23  BV=5.16
    {2335,1184,1032, 0, 0, 0},  //TV = 8.74(224 lines)  AV=1.53  SV=5.22  BV=5.05
    {2513,1184,1032, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.53  SV=5.22  BV=4.95
    {2690,1184,1032, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.53  SV=5.22  BV=4.85
    {2867,1184,1040, 0, 0, 0},  //TV = 8.45(275 lines)  AV=1.53  SV=5.23  BV=4.75
    {3076,1184,1032, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(316 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.53  SV=5.22  BV=4.45
    {3795,1184,1032, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.53  SV=5.22  BV=4.35
    {4066,1184,1032, 0, 0, 0},  //TV = 7.94(390 lines)  AV=1.53  SV=5.22  BV=4.25
    {4347,1184,1032, 0, 0, 0},  //TV = 7.85(417 lines)  AV=1.53  SV=5.22  BV=4.16
    {4660,1184,1032, 0, 0, 0},  //TV = 7.75(447 lines)  AV=1.53  SV=5.22  BV=4.06
    {5025,1184,1032, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.53  SV=5.22  BV=3.95
    {5379,1184,1032, 0, 0, 0},  //TV = 7.54(516 lines)  AV=1.53  SV=5.22  BV=3.85
    {5755,1184,1032, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.53  SV=5.22  BV=3.65
    {6599,1184,1032, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(726 lines)  AV=1.53  SV=5.22  BV=3.36
    {8110,1184,1032, 0, 0, 0},  //TV = 6.95(778 lines)  AV=1.53  SV=5.22  BV=3.26
    {8329,1248,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.29  BV=3.15
    {8329,1312,1048, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.39  BV=3.05
    {8329,1408,1040, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.48  BV=2.96
    {8329,1536,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.60  BV=2.84
    {8329,1632,1040, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.69  BV=2.74
    {8329,1760,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.79  BV=2.65
    {8329,1888,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.88  BV=2.56
    {8329,2016,1032, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=5.99  BV=2.45
    {8329,2176,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=6.09  BV=2.35
    {8329,2336,1024, 0, 0, 0},  //TV = 6.91(799 lines)  AV=1.53  SV=6.19  BV=2.25
    {16669,1248,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.29  BV=2.15
    {16669,1312,1048, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.39  BV=2.05
    {16669,1408,1040, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.48  BV=1.96
    {16669,1536,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.58  BV=1.85
    {16669,1632,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.68  BV=1.75
    {16669,1760,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.79  BV=1.65
    {16669,1888,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.88  BV=1.56
    {16669,2016,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=5.99  BV=1.45
    {16669,2176,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.09  BV=1.35
    {16669,2304,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.18  BV=1.26
    {16669,2496,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.29  BV=1.15
    {16669,2656,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.39  BV=1.05
    {16669,2848,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.49  BV=0.95
    {16668,3072,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.60  BV=0.84
    {16668,3296,1024, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.69  BV=0.75
    {16668,3520,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.79  BV=0.65
    {16668,3776,1032, 0, 0, 0},  //TV = 5.91(1599 lines)  AV=1.53  SV=6.89  BV=0.54
    {24997,2688,1032, 0, 0, 0},  //TV = 5.32(2398 lines)  AV=1.53  SV=6.40  BV=0.45
    {24997,2880,1032, 0, 0, 0},  //TV = 5.32(2398 lines)  AV=1.53  SV=6.50  BV=0.35
    {24997,3104,1024, 0, 0, 0},  //TV = 5.32(2398 lines)  AV=1.53  SV=6.60  BV=0.25
    {24997,3328,1024, 0, 0, 0},  //TV = 5.32(2398 lines)  AV=1.53  SV=6.70  BV=0.15
    {24997,3552,1032, 0, 0, 0},  //TV = 5.32(2398 lines)  AV=1.53  SV=6.81  BV=0.05
    {33336,2848,1032, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33336,3072,1032, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33336,3296,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33336,3520,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33336,3776,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33336,4064,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33336,4352,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33336,4672,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33336,4992,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33336,5312,1032, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33336,5696,1032, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33336,6144,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33336,6592,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33336,7104,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33336,7552,1032, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33336,8128,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33336,8704,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33336,9344,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33336,9984,1024, 0, 0, 0},  //TV = 4.91(3198 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33336,10112,1032, 0, 0, 0},  /* TV = 4.91(3198 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {94,1248,1048, 0, 0, 0},  //TV = 13.38(9 lines)  AV=1.53  SV=5.32  BV=9.59
    {105,1184,1040, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.53  SV=5.23  BV=9.52
    {105,1248,1048, 0, 0, 0},  //TV = 13.22(10 lines)  AV=1.53  SV=5.32  BV=9.43
    {115,1216,1040, 0, 0, 0},  //TV = 13.09(11 lines)  AV=1.53  SV=5.27  BV=9.35
    {126,1184,1040, 0, 0, 0},  //TV = 12.95(12 lines)  AV=1.53  SV=5.23  BV=9.25
    {136,1216,1024, 0, 0, 0},  //TV = 12.84(13 lines)  AV=1.53  SV=5.25  BV=9.13
    {146,1184,1048, 0, 0, 0},  //TV = 12.74(14 lines)  AV=1.53  SV=5.24  BV=9.03
    {157,1216,1024, 0, 0, 0},  //TV = 12.64(15 lines)  AV=1.53  SV=5.25  BV=8.92
    {167,1216,1032, 0, 0, 0},  //TV = 12.55(16 lines)  AV=1.53  SV=5.26  BV=8.82
    {178,1184,1040, 0, 0, 0},  /* TV = 12.46(17 lines)  AV=1.53  SV=5.23  BV=8.76 */
    {188,1216,1032, 0, 0, 0},  //TV = 12.38(18 lines)  AV=1.53  SV=5.26  BV=8.65
    {199,1216,1040, 0, 0, 0},  //TV = 12.29(19 lines)  AV=1.53  SV=5.27  BV=8.56
    {219,1184,1040, 0, 0, 0},  //TV = 12.16(21 lines)  AV=1.53  SV=5.23  BV=8.46
    {230,1216,1040, 0, 0, 0},  //TV = 12.09(22 lines)  AV=1.53  SV=5.27  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(24 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(25 lines)  AV=1.53  SV=5.28  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(28 lines)  AV=1.53  SV=5.22  BV=8.05
    {313,1184,1032, 0, 0, 0},  //TV = 11.64(30 lines)  AV=1.53  SV=5.22  BV=7.95
    {334,1184,1040, 0, 0, 0},  //TV = 11.55(32 lines)  AV=1.53  SV=5.23  BV=7.85
    {355,1184,1048, 0, 0, 0},  //TV = 11.46(34 lines)  AV=1.53  SV=5.24  BV=7.75
    {386,1184,1032, 0, 0, 0},  //TV = 11.34(37 lines)  AV=1.53  SV=5.22  BV=7.65
    {407,1184,1048, 0, 0, 0},  //TV = 11.26(39 lines)  AV=1.53  SV=5.24  BV=7.55
    {438,1184,1040, 0, 0, 0},  //TV = 11.16(42 lines)  AV=1.53  SV=5.23  BV=7.46
    {470,1184,1040, 0, 0, 0},  //TV = 11.06(45 lines)  AV=1.53  SV=5.23  BV=7.35
    {501,1184,1048, 0, 0, 0},  //TV = 10.96(48 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(52 lines)  AV=1.53  SV=5.22  BV=7.16
    {574,1184,1048, 0, 0, 0},  //TV = 10.77(55 lines)  AV=1.53  SV=5.24  BV=7.05
    {616,1184,1048, 0, 0, 0},  //TV = 10.66(59 lines)  AV=1.53  SV=5.24  BV=6.95
    {668,1184,1040, 0, 0, 0},  //TV = 10.55(64 lines)  AV=1.53  SV=5.23  BV=6.85
    {720,1184,1032, 0, 0, 0},  //TV = 10.44(69 lines)  AV=1.53  SV=5.22  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(73 lines)  AV=1.53  SV=5.24  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(79 lines)  AV=1.53  SV=5.22  BV=6.56
    {876,1184,1040, 0, 0, 0},  //TV = 10.16(84 lines)  AV=1.53  SV=5.23  BV=6.46
    {939,1184,1040, 0, 0, 0},  //TV = 10.06(90 lines)  AV=1.53  SV=5.23  BV=6.36
    {1012,1184,1040, 0, 0, 0},  //TV = 9.95(97 lines)  AV=1.53  SV=5.23  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(104 lines)  AV=1.53  SV=5.23  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(111 lines)  AV=1.53  SV=5.23  BV=6.05
    {1251,1184,1032, 0, 0, 0},  //TV = 9.64(120 lines)  AV=1.53  SV=5.22  BV=5.95
    {1345,1184,1032, 0, 0, 0},  //TV = 9.54(129 lines)  AV=1.53  SV=5.22  BV=5.85
    {1429,1184,1040, 0, 0, 0},  //TV = 9.45(137 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(148 lines)  AV=1.53  SV=5.22  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(158 lines)  AV=1.53  SV=5.22  BV=5.56
    {1773,1184,1032, 0, 0, 0},  //TV = 9.14(170 lines)  AV=1.53  SV=5.22  BV=5.45
    {1887,1184,1040, 0, 0, 0},  //TV = 9.05(181 lines)  AV=1.53  SV=5.23  BV=5.35
    {2033,1184,1040, 0, 0, 0},  //TV = 8.94(195 lines)  AV=1.53  SV=5.23  BV=5.24
    {2158,1184,1040, 0, 0, 0},  //TV = 8.86(207 lines)  AV=1.53  SV=5.23  BV=5.16
    {2335,1184,1032, 0, 0, 0},  //TV = 8.74(224 lines)  AV=1.53  SV=5.22  BV=5.05
    {2513,1184,1032, 0, 0, 0},  //TV = 8.64(241 lines)  AV=1.53  SV=5.22  BV=4.95
    {2690,1184,1032, 0, 0, 0},  //TV = 8.54(258 lines)  AV=1.53  SV=5.22  BV=4.85
    {2867,1184,1040, 0, 0, 0},  //TV = 8.45(275 lines)  AV=1.53  SV=5.23  BV=4.75
    {3076,1184,1032, 0, 0, 0},  //TV = 8.34(295 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(316 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(340 lines)  AV=1.53  SV=5.22  BV=4.45
    {3795,1184,1032, 0, 0, 0},  //TV = 8.04(364 lines)  AV=1.53  SV=5.22  BV=4.35
    {4066,1184,1032, 0, 0, 0},  //TV = 7.94(390 lines)  AV=1.53  SV=5.22  BV=4.25
    {4347,1184,1032, 0, 0, 0},  //TV = 7.85(417 lines)  AV=1.53  SV=5.22  BV=4.16
    {4660,1184,1032, 0, 0, 0},  //TV = 7.75(447 lines)  AV=1.53  SV=5.22  BV=4.06
    {5025,1184,1032, 0, 0, 0},  //TV = 7.64(482 lines)  AV=1.53  SV=5.22  BV=3.95
    {5379,1184,1032, 0, 0, 0},  //TV = 7.54(516 lines)  AV=1.53  SV=5.22  BV=3.85
    {5755,1184,1032, 0, 0, 0},  //TV = 7.44(552 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(591 lines)  AV=1.53  SV=5.22  BV=3.65
    {6599,1184,1032, 0, 0, 0},  //TV = 7.24(633 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(678 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(726 lines)  AV=1.53  SV=5.22  BV=3.36
    {8110,1184,1032, 0, 0, 0},  //TV = 6.95(778 lines)  AV=1.53  SV=5.22  BV=3.26
    {8694,1184,1032, 0, 0, 0},  //TV = 6.85(834 lines)  AV=1.53  SV=5.22  BV=3.16
    {9309,1184,1032, 0, 0, 0},  //TV = 6.75(893 lines)  AV=1.53  SV=5.22  BV=3.06
    {9976,1184,1032, 0, 0, 0},  //TV = 6.65(957 lines)  AV=1.53  SV=5.22  BV=2.96
    {9997,1280,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.32  BV=2.85
    {9997,1344,1048, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.43  BV=2.75
    {9997,1472,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.52  BV=2.65
    {9997,1568,1032, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.63  BV=2.55
    {9997,1696,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.73  BV=2.45
    {9997,1792,1040, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.83  BV=2.35
    {9997,1920,1040, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=5.93  BV=2.25
    {9997,2080,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.02  BV=2.15
    {9997,2208,1032, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.12  BV=2.06
    {9997,2400,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.23  BV=1.95
    {9997,2560,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.32  BV=1.85
    {9997,2720,1032, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.42  BV=1.75
    {9997,2944,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.52  BV=1.65
    {9997,3136,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.61  BV=1.56
    {9997,3392,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.73  BV=1.45
    {9997,3616,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.82  BV=1.36
    {9997,3904,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=6.93  BV=1.24
    {9997,4160,1024, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=7.02  BV=1.15
    {9997,4416,1032, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=7.12  BV=1.06
    {9997,4736,1032, 0, 0, 0},  //TV = 6.64(959 lines)  AV=1.53  SV=7.22  BV=0.95
    {20004,2560,1024, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.32  BV=0.85
    {20004,2752,1024, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.43  BV=0.75
    {20004,2944,1024, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.52  BV=0.65
    {20004,3136,1032, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.63  BV=0.55
    {20004,3392,1024, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.73  BV=0.45
    {20004,3616,1024, 0, 0, 0},  //TV = 5.64(1919 lines)  AV=1.53  SV=6.82  BV=0.35
    {30001,2592,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.34  BV=0.25
    {30001,2752,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.44  BV=0.15
    {30001,2976,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.54  BV=0.05
    {30001,3168,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30001,3424,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30001,3648,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30001,3904,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30001,4160,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30001,4480,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30001,4800,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30001,5184,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30001,5504,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30001,5952,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30001,6336,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30001,6848,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30001,7360,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.85  BV=-1.26
    {30001,7872,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30001,8448,1024, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30001,8960,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30001,9600,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30001,10112,1032, 0, 0, 0},  //TV = 5.06(2878 lines)  AV=1.53  SV=8.32  BV=-1.73
    {30001,10112,1032, 0, 0, 0},  /* TV = 5.06(2878 lines)  AV=1.53  SV=8.32  BV=-1.73 */
    {30001,10112,1032, 0, 0, 0},  /* TV = 5.06(2878 lines)  AV=1.53  SV=8.32  BV=-1.73 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8328,1248,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.29  BV=3.15
    {8328,1312,1048, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.39  BV=3.05
    {8328,1408,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.48  BV=2.96
    {8328,1536,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.60  BV=2.84
    {8328,1632,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.69  BV=2.74
    {8328,1760,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.79  BV=2.65
    {8328,1888,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.89  BV=2.55
    {8328,2016,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.99  BV=2.45
    {8328,2176,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.09  BV=2.35
    {8328,2336,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.19  BV=2.25
    {16666,1248,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.29  BV=2.15
    {16666,1312,1048, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.39  BV=2.05
    {16666,1408,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.48  BV=1.96
    {16666,1536,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.58  BV=1.85
    {16666,1632,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.69  BV=1.74
    {16666,1760,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.79  BV=1.65
    {16666,1888,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.88  BV=1.56
    {16666,2016,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.99  BV=1.45
    {16666,2176,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.09  BV=1.35
    {16666,2304,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.18  BV=1.26
    {16666,2496,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.29  BV=1.15
    {16666,2656,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.39  BV=1.05
    {16666,2848,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.49  BV=0.95
    {16666,3072,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.60  BV=0.84
    {16666,3296,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.69  BV=0.75
    {16666,3520,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.79  BV=0.65
    {16666,3776,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.89  BV=0.54
    {25005,2688,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.40  BV=0.45
    {25005,2880,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.50  BV=0.35
    {25005,3104,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.60  BV=0.25
    {25005,3328,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.70  BV=0.15
    {25005,3552,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.81  BV=0.05
    {33332,2848,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33332,3072,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33332,3296,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33332,3520,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33332,3776,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33332,4064,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33332,4352,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33332,4672,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33332,4992,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33332,5312,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33332,5696,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33332,6144,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33332,6592,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33332,7104,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33332,7552,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33332,8128,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33332,8704,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33332,9344,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33332,9984,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33332,10112,1032, 0, 0, 0},  /* TV = 4.91(2938 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8691,1184,1032, 0, 0, 0},  //TV = 6.85(766 lines)  AV=1.53  SV=5.22  BV=3.16
    {9371,1184,1032, 0, 0, 0},  //TV = 6.74(826 lines)  AV=1.53  SV=5.22  BV=3.05
    {9995,1184,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.23  BV=2.94
    {9995,1280,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.32  BV=2.85
    {9995,1344,1048, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.43  BV=2.75
    {9995,1472,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.52  BV=2.65
    {9995,1568,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.63  BV=2.55
    {9995,1696,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.73  BV=2.45
    {9995,1792,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.83  BV=2.35
    {9995,1920,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.93  BV=2.25
    {9995,2080,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.02  BV=2.15
    {9995,2208,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.12  BV=2.06
    {9995,2400,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.23  BV=1.95
    {9995,2560,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.32  BV=1.85
    {9995,2720,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.42  BV=1.76
    {9995,2944,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.52  BV=1.65
    {9995,3136,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.61  BV=1.56
    {9995,3392,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.73  BV=1.45
    {9995,3616,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.82  BV=1.36
    {9995,3904,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.93  BV=1.24
    {9995,4160,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.02  BV=1.15
    {9995,4416,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.12  BV=1.06
    {9995,4736,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.22  BV=0.95
    {20002,2560,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.32  BV=0.85
    {20002,2752,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.43  BV=0.75
    {20002,2944,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.52  BV=0.65
    {20002,3136,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.63  BV=0.55
    {20002,3392,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.73  BV=0.45
    {20002,3616,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.82  BV=0.35
    {29997,2592,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.34  BV=0.25
    {29997,2752,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.44  BV=0.15
    {29997,2976,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.54  BV=0.05
    {29997,3168,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.64  BV=-0.05
    {29997,3424,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.74  BV=-0.15
    {29997,3648,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.84  BV=-0.25
    {29997,3904,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.94  BV=-0.35
    {29997,4160,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.03  BV=-0.44
    {29997,4480,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.14  BV=-0.55
    {29997,4800,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.24  BV=-0.65
    {29997,5184,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.34  BV=-0.75
    {29997,5568,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.44  BV=-0.85
    {29997,5952,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.54  BV=-0.95
    {29997,6336,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.64  BV=-1.05
    {29997,6848,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.74  BV=-1.15
    {29997,7360,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.85  BV=-1.26
    {29997,7872,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.94  BV=-1.35
    {29997,8448,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.04  BV=-1.45
    {29997,8960,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.14  BV=-1.55
    {29997,9600,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.24  BV=-1.65
    {29997,10112,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8328,1248,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.29  BV=3.15
    {8328,1312,1048, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.39  BV=3.05
    {8328,1408,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.48  BV=2.96
    {8328,1536,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.60  BV=2.84
    {8328,1632,1040, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.69  BV=2.74
    {8328,1760,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.79  BV=2.65
    {8328,1888,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.89  BV=2.55
    {8328,2016,1032, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=5.99  BV=2.45
    {8328,2176,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.09  BV=2.35
    {8328,2336,1024, 0, 0, 0},  //TV = 6.91(734 lines)  AV=1.53  SV=6.19  BV=2.25
    {16666,1248,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.29  BV=2.15
    {16666,1312,1048, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.39  BV=2.05
    {16666,1408,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.48  BV=1.96
    {16666,1536,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.58  BV=1.85
    {16666,1632,1040, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.69  BV=1.74
    {16666,1760,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.79  BV=1.65
    {16666,1888,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.88  BV=1.56
    {16666,2016,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=5.99  BV=1.45
    {16666,2176,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.09  BV=1.35
    {16666,2304,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.18  BV=1.26
    {16666,2496,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.29  BV=1.15
    {16666,2656,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.39  BV=1.05
    {16666,2848,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.49  BV=0.95
    {16666,3072,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.60  BV=0.84
    {16666,3296,1024, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.69  BV=0.75
    {16666,3520,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.79  BV=0.65
    {16666,3776,1032, 0, 0, 0},  //TV = 5.91(1469 lines)  AV=1.53  SV=6.89  BV=0.54
    {25005,2688,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.40  BV=0.45
    {25005,2880,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.50  BV=0.35
    {25005,3104,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.60  BV=0.25
    {25005,3328,1024, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.70  BV=0.15
    {25005,3552,1032, 0, 0, 0},  //TV = 5.32(2204 lines)  AV=1.53  SV=6.81  BV=0.05
    {33332,2848,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33332,3072,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.60  BV=-0.16
    {33332,3296,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33332,3520,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.78  BV=-0.34
    {33332,3776,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33332,4064,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33332,4352,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33332,4672,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33332,4992,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33332,5312,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33332,5696,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33332,6144,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33332,6592,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33332,7104,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33332,7552,1032, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33332,8128,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33332,8704,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33332,9344,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33332,9984,1024, 0, 0, 0},  //TV = 4.91(2938 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33332,10112,1032, 0, 0, 0},  /* TV = 4.91(2938 lines)  AV=1.53  SV=8.32  BV=-1.88 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(8 lines)  AV=1.53  SV=5.36  BV=9.60
    {103,1184,1032, 0, 0, 0},  /* TV = 13.25(9 lines)  AV=1.53  SV=5.22  BV=9.56 */
    {103,1280,1040, 0, 0, 0},  //TV = 13.25(9 lines)  AV=1.53  SV=5.34  BV=9.43
    {114,1248,1024, 0, 0, 0},  //TV = 13.10(10 lines)  AV=1.53  SV=5.29  BV=9.34
    {125,1184,1048, 0, 0, 0},  //TV = 12.97(11 lines)  AV=1.53  SV=5.24  BV=9.25
    {137,1184,1048, 0, 0, 0},  /* TV = 12.83(12 lines)  AV=1.53  SV=5.24  BV=9.12 */
    {148,1184,1032, 0, 0, 0},  //TV = 12.72(13 lines)  AV=1.53  SV=5.22  BV=9.03
    {159,1184,1040, 0, 0, 0},  //TV = 12.62(14 lines)  AV=1.53  SV=5.23  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(15 lines)  AV=1.53  SV=5.23  BV=8.81
    {182,1216,1024, 0, 0, 0},  //TV = 12.42(16 lines)  AV=1.53  SV=5.25  BV=8.71
    {193,1184,1032, 0, 0, 0},  /* TV = 12.34(17 lines)  AV=1.53  SV=5.22  BV=8.65 */
    {205,1184,1040, 0, 0, 0},  //TV = 12.25(18 lines)  AV=1.53  SV=5.23  BV=8.55
    {216,1216,1032, 0, 0, 0},  //TV = 12.18(19 lines)  AV=1.53  SV=5.26  BV=8.45
    {227,1248,1024, 0, 0, 0},  //TV = 12.11(20 lines)  AV=1.53  SV=5.29  BV=8.35
    {250,1184,1048, 0, 0, 0},  //TV = 11.97(22 lines)  AV=1.53  SV=5.24  BV=8.25
    {261,1216,1048, 0, 0, 0},  //TV = 11.90(23 lines)  AV=1.53  SV=5.28  BV=8.15
    {284,1216,1032, 0, 0, 0},  //TV = 11.78(25 lines)  AV=1.53  SV=5.26  BV=8.05
    {307,1216,1024, 0, 0, 0},  //TV = 11.67(27 lines)  AV=1.53  SV=5.25  BV=7.95
    {330,1184,1048, 0, 0, 0},  //TV = 11.57(29 lines)  AV=1.53  SV=5.24  BV=7.85
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(31 lines)  AV=1.53  SV=5.25  BV=7.76
    {375,1216,1032, 0, 0, 0},  //TV = 11.38(33 lines)  AV=1.53  SV=5.26  BV=7.65
    {409,1184,1040, 0, 0, 0},  //TV = 11.26(36 lines)  AV=1.53  SV=5.23  BV=7.55
    {443,1184,1032, 0, 0, 0},  //TV = 11.14(39 lines)  AV=1.53  SV=5.22  BV=7.45
    {466,1216,1024, 0, 0, 0},  //TV = 11.07(41 lines)  AV=1.53  SV=5.25  BV=7.35
    {500,1184,1048, 0, 0, 0},  //TV = 10.97(44 lines)  AV=1.53  SV=5.24  BV=7.25
    {534,1216,1024, 0, 0, 0},  //TV = 10.87(47 lines)  AV=1.53  SV=5.25  BV=7.15
    {579,1184,1040, 0, 0, 0},  //TV = 10.75(51 lines)  AV=1.53  SV=5.23  BV=7.05
    {624,1184,1032, 0, 0, 0},  //TV = 10.65(55 lines)  AV=1.53  SV=5.22  BV=6.96
    {670,1184,1032, 0, 0, 0},  //TV = 10.54(59 lines)  AV=1.53  SV=5.22  BV=6.85
    {715,1184,1040, 0, 0, 0},  //TV = 10.45(63 lines)  AV=1.53  SV=5.23  BV=6.75
    {761,1184,1048, 0, 0, 0},  //TV = 10.36(67 lines)  AV=1.53  SV=5.24  BV=6.65
    {829,1184,1032, 0, 0, 0},  //TV = 10.24(73 lines)  AV=1.53  SV=5.22  BV=6.55
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(77 lines)  AV=1.53  SV=5.24  BV=6.45
    {942,1184,1040, 0, 0, 0},  //TV = 10.05(83 lines)  AV=1.53  SV=5.23  BV=6.35
    {1010,1184,1040, 0, 0, 0},  //TV = 9.95(89 lines)  AV=1.53  SV=5.23  BV=6.25
    {1090,1184,1032, 0, 0, 0},  //TV = 9.84(96 lines)  AV=1.53  SV=5.22  BV=6.15
    {1158,1184,1040, 0, 0, 0},  //TV = 9.75(102 lines)  AV=1.53  SV=5.23  BV=6.05
    {1248,1184,1032, 0, 0, 0},  //TV = 9.65(110 lines)  AV=1.53  SV=5.22  BV=5.96
    {1328,1184,1040, 0, 0, 0},  //TV = 9.56(117 lines)  AV=1.53  SV=5.23  BV=5.86
    {1430,1184,1040, 0, 0, 0},  //TV = 9.45(126 lines)  AV=1.53  SV=5.23  BV=5.75
    {1543,1184,1032, 0, 0, 0},  //TV = 9.34(136 lines)  AV=1.53  SV=5.22  BV=5.65
    {1646,1184,1032, 0, 0, 0},  //TV = 9.25(145 lines)  AV=1.53  SV=5.22  BV=5.56
    {1770,1184,1032, 0, 0, 0},  //TV = 9.14(156 lines)  AV=1.53  SV=5.22  BV=5.45
    {1895,1184,1032, 0, 0, 0},  //TV = 9.04(167 lines)  AV=1.53  SV=5.22  BV=5.35
    {2020,1184,1040, 0, 0, 0},  //TV = 8.95(178 lines)  AV=1.53  SV=5.23  BV=5.25
    {2179,1184,1032, 0, 0, 0},  //TV = 8.84(192 lines)  AV=1.53  SV=5.22  BV=5.15
    {2326,1184,1040, 0, 0, 0},  //TV = 8.75(205 lines)  AV=1.53  SV=5.23  BV=5.05
    {2496,1184,1032, 0, 0, 0},  //TV = 8.65(220 lines)  AV=1.53  SV=5.22  BV=4.96
    {2689,1184,1032, 0, 0, 0},  //TV = 8.54(237 lines)  AV=1.53  SV=5.22  BV=4.85
    {2848,1184,1040, 0, 0, 0},  //TV = 8.46(251 lines)  AV=1.53  SV=5.23  BV=4.76
    {3075,1184,1032, 0, 0, 0},  //TV = 8.35(271 lines)  AV=1.53  SV=5.22  BV=4.66
    {3291,1184,1032, 0, 0, 0},  //TV = 8.25(290 lines)  AV=1.53  SV=5.22  BV=4.56
    {3551,1184,1032, 0, 0, 0},  //TV = 8.14(313 lines)  AV=1.53  SV=5.22  BV=4.45
    {3801,1184,1032, 0, 0, 0},  //TV = 8.04(335 lines)  AV=1.53  SV=5.22  BV=4.35
    {4062,1184,1032, 0, 0, 0},  //TV = 7.94(358 lines)  AV=1.53  SV=5.22  BV=4.25
    {4346,1184,1032, 0, 0, 0},  //TV = 7.85(383 lines)  AV=1.53  SV=5.22  BV=4.16
    {4686,1184,1032, 0, 0, 0},  //TV = 7.74(413 lines)  AV=1.53  SV=5.22  BV=4.05
    {4992,1184,1032, 0, 0, 0},  //TV = 7.65(440 lines)  AV=1.53  SV=5.22  BV=3.96
    {5378,1184,1032, 0, 0, 0},  //TV = 7.54(474 lines)  AV=1.53  SV=5.22  BV=3.85
    {5752,1184,1032, 0, 0, 0},  //TV = 7.44(507 lines)  AV=1.53  SV=5.22  BV=3.75
    {6161,1184,1032, 0, 0, 0},  //TV = 7.34(543 lines)  AV=1.53  SV=5.22  BV=3.65
    {6603,1184,1032, 0, 0, 0},  //TV = 7.24(582 lines)  AV=1.53  SV=5.22  BV=3.55
    {7068,1184,1032, 0, 0, 0},  //TV = 7.14(623 lines)  AV=1.53  SV=5.22  BV=3.45
    {7568,1184,1032, 0, 0, 0},  //TV = 7.05(667 lines)  AV=1.53  SV=5.22  BV=3.36
    {8112,1184,1032, 0, 0, 0},  //TV = 6.95(715 lines)  AV=1.53  SV=5.22  BV=3.26
    {8691,1184,1032, 0, 0, 0},  //TV = 6.85(766 lines)  AV=1.53  SV=5.22  BV=3.16
    {9371,1184,1032, 0, 0, 0},  //TV = 6.74(826 lines)  AV=1.53  SV=5.22  BV=3.05
    {9995,1184,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.23  BV=2.94
    {9995,1280,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.32  BV=2.85
    {9995,1344,1048, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.43  BV=2.75
    {9995,1472,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.52  BV=2.65
    {9995,1568,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.63  BV=2.55
    {9995,1696,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.73  BV=2.45
    {9995,1792,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.83  BV=2.35
    {9995,1920,1040, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=5.93  BV=2.25
    {9995,2080,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.02  BV=2.15
    {9995,2208,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.12  BV=2.06
    {9995,2400,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.23  BV=1.95
    {9995,2560,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.32  BV=1.85
    {9995,2720,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.42  BV=1.76
    {9995,2944,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.52  BV=1.65
    {9995,3136,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.61  BV=1.56
    {9995,3392,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.73  BV=1.45
    {9995,3616,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.82  BV=1.36
    {9995,3904,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=6.93  BV=1.24
    {9995,4160,1024, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.02  BV=1.15
    {9995,4416,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.12  BV=1.06
    {9995,4736,1032, 0, 0, 0},  //TV = 6.64(881 lines)  AV=1.53  SV=7.22  BV=0.95
    {20002,2560,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.32  BV=0.85
    {20002,2752,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.43  BV=0.75
    {20002,2944,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.52  BV=0.65
    {20002,3136,1032, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.63  BV=0.55
    {20002,3392,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.73  BV=0.45
    {20002,3616,1024, 0, 0, 0},  //TV = 5.64(1763 lines)  AV=1.53  SV=6.82  BV=0.35
    {29997,2592,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.34  BV=0.25
    {29997,2752,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.44  BV=0.15
    {29997,2976,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.54  BV=0.05
    {29997,3168,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.64  BV=-0.05
    {29997,3424,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.74  BV=-0.15
    {29997,3648,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.84  BV=-0.25
    {29997,3904,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=6.94  BV=-0.35
    {29997,4160,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.03  BV=-0.44
    {29997,4480,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.14  BV=-0.55
    {29997,4800,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.24  BV=-0.65
    {29997,5184,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.34  BV=-0.75
    {29997,5568,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.44  BV=-0.85
    {29997,5952,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.54  BV=-0.95
    {29997,6336,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.64  BV=-1.05
    {29997,6848,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.74  BV=-1.15
    {29997,7360,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.85  BV=-1.26
    {29997,7872,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=7.94  BV=-1.35
    {29997,8448,1024, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.04  BV=-1.45
    {29997,8960,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.14  BV=-1.55
    {29997,9600,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.24  BV=-1.65
    {29997,10112,1032, 0, 0, 0},  //TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {29997,10112,1032, 0, 0, 0},  /* TV = 5.06(2644 lines)  AV=1.53  SV=8.32  BV=-1.72 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -19, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,12800,1040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {58333,11392,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.48  BV=-2.85
    {58333,12288,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.58  BV=-2.95
    {66666,11520,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.49  BV=-3.05
    {66666,12288,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.58  BV=-3.15
    {66666,13056,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.68  BV=-3.25
    {66666,14080,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.79  BV=-3.35
    {66666,15104,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.88  BV=-3.44
    {66666,16128,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.99  BV=-3.55
    {66666,16384,1088, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.09  BV=-3.65
    {66666,16384,1168, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.19  BV=-3.75
    {66666,16384,1248, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.29  BV=-3.85
    {66666,16384,1336, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.38  BV=-3.95
    {66666,16384,1432, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.48  BV=-4.05
    {66666,16384,1536, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.58  BV=-4.15
    {66666,16384,1648, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.69  BV=-4.25
    {66666,16384,1768, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.79  BV=-4.35
    {66666,16384,1896, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.89  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {66666,16384,2176, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.09  BV=-4.65
    {74999,16384,2080, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.02  BV=-4.75
    {74999,16384,2224, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.12  BV=-4.85
    {83332,16384,2144, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.07  BV=-4.95
    {83332,16384,2304, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.17  BV=-5.05
    {91666,16384,2240, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.13  BV=-5.15
    {99999,16384,2200, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.10  BV=-5.25
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {50000,13312,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.70  BV=-2.85
    {60000,11904,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.54  BV=-2.95
    {60000,12800,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.64  BV=-3.05
    {69999,11776,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.52  BV=-3.16
    {69999,12544,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.61  BV=-3.25
    {69999,13312,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.72  BV=-3.36
    {69999,14336,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.82  BV=-3.45
    {69999,15360,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.92  BV=-3.55
    {69999,16384,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.02  BV=-3.65
    {69999,16384,1112, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.12  BV=-3.75
    {69999,16384,1192, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.22  BV=-3.85
    {69999,16384,1272, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.31  BV=-3.95
    {69999,16384,1368, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.42  BV=-4.05
    {69999,16384,1464, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.52  BV=-4.15
    {69999,16384,1568, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.61  BV=-4.25
    {69999,16384,1680, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.71  BV=-4.35
    {69999,16384,1800, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.81  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {69999,16384,2224, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.12  BV=-4.75
    {79999,16384,2088, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.03  BV=-4.85
    {79999,16384,2240, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.13  BV=-4.95
    {89999,16384,2128, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.06  BV=-5.05
    {89999,16384,2288, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.16  BV=-5.15
    {99999,16384,2200, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.10  BV=-5.25
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -53, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {41667,1216,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.26  BV=0.86
    {41667,1312,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.36  BV=0.76
    {41667,1408,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.46  BV=0.66
    {50001,1248,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.30  BV=0.56
    {50001,1344,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.41  BV=0.44
    {58334,1216,1048, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=5.28  BV=0.35
    {58334,1312,1040, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=5.38  BV=0.25
    {66667,1248,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=5.30  BV=0.14
    {66667,1312,1048, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=5.39  BV=0.05
    {75000,1248,1048, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=5.32  BV=-0.05
    {83333,1216,1032, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=5.26  BV=-0.14
    {91667,1184,1032, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=5.22  BV=-0.24
    {91667,1280,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=5.32  BV=-0.34
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {40000,1280,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.32  BV=0.85
    {40000,1344,1048, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.43  BV=0.75
    {40000,1472,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.53  BV=0.64
    {50000,1248,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.30  BV=0.56
    {50000,1344,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.41  BV=0.44
    {60000,1184,1048, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=5.24  BV=0.35
    {60000,1280,1040, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=5.34  BV=0.25
    {60000,1376,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=5.44  BV=0.15
    {69999,1248,1048, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=5.32  BV=0.05
    {69999,1344,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=5.41  BV=-0.05
    {79999,1280,1032, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=5.33  BV=-0.16
    {89999,1216,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=5.25  BV=-0.24
    {89999,1280,1048, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=5.36  BV=-0.35
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -4, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {523,2016,1032, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=5.99  BV=6.44
    {553,2048,1032, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=6.01  BV=6.34
    {603,2016,1032, 0, 0, 0},  //TV = 10.70(60 lines)  AV=1.53  SV=5.99  BV=6.24
    {643,2016,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=5.99  BV=6.15
    {683,2016,1040, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=6.00  BV=6.05
    {733,2016,1040, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=6.00  BV=5.95
    {784,2048,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=6.00  BV=5.85
    {844,2016,1032, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=5.99  BV=5.75
    {904,2016,1040, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=6.00  BV=5.64
    {964,2016,1040, 0, 0, 0},  //TV = 10.02(96 lines)  AV=1.53  SV=6.00  BV=5.55
    {1035,2048,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=6.00  BV=5.45
    {1105,2048,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=6.00  BV=5.35
    {1195,2016,1032, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=5.99  BV=5.25
    {1276,2048,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=6.00  BV=5.15
    {1366,2016,1040, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=6.00  BV=5.05
    {1456,2048,1024, 0, 0, 0},  //TV = 9.42(145 lines)  AV=1.53  SV=6.00  BV=4.95
    {1567,2016,1040, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=6.00  BV=4.85
    {1687,2016,1040, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=6.00  BV=4.74
    {1808,2016,1032, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=5.99  BV=4.65
    {1928,2016,1040, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=6.00  BV=4.55
    {2079,2016,1040, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=6.00  BV=4.44
    {2219,2016,1040, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=6.00  BV=4.35
    {2390,2016,1040, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=6.00  BV=4.24
    {2551,2016,1040, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=6.00  BV=4.15
    {2731,2016,1040, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=6.00  BV=4.05
    {2922,2016,1040, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=6.00  BV=3.95
    {3133,2016,1040, 0, 0, 0},  //TV = 8.32(312 lines)  AV=1.53  SV=6.00  BV=3.85
    {3374,2016,1040, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=6.00  BV=3.74
    {3605,2016,1040, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=6.00  BV=3.65
    {3866,2016,1040, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=6.00  BV=3.55
    {4137,2016,1040, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=6.00  BV=3.45
    {4458,2016,1040, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=6.00  BV=3.34
    {4769,2016,1040, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=6.00  BV=3.24
    {5111,2016,1040, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=6.00  BV=3.14
    {5472,2016,1040, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=6.00  BV=3.05
    {5854,2016,1040, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=6.00  BV=2.95
    {6275,2016,1040, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=6.00  BV=2.85
    {6717,2016,1040, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=6.00  BV=2.75
    {7199,2016,1040, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=6.00  BV=2.65
    {7711,2016,1040, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=6.00  BV=2.55
    {8314,2016,1040, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=6.00  BV=2.44
    {8334,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8334,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {8334,2496,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.29  BV=2.15
    {8334,2656,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.39  BV=2.05
    {8334,2848,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.49  BV=1.95
    {16667,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16667,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16667,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {16667,1888,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.88  BV=1.56
    {16667,2016,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.99  BV=1.45
    {16667,2176,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.09  BV=1.35
    {16667,2304,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.18  BV=1.26
    {16667,2496,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.29  BV=1.15
    {25000,1792,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.81  BV=1.05
    {25000,1920,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.91  BV=0.95
    {25000,2048,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.00  BV=0.85
    {25000,2176,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.10  BV=0.75
    {25000,2336,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.20  BV=0.65
    {33333,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33333,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33333,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {41666,1856,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.87  BV=0.25
    {41666,1984,1040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.98  BV=0.14
    {41666,2112,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=6.06  BV=0.06
    {50000,1920,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.91  BV=-0.05
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.01  BV=-0.16
    {50000,2176,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.10  BV=-0.25
    {58333,2016,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=5.99  BV=-0.36
    {58333,2144,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=6.08  BV=-0.45
    {66666,2016,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=5.99  BV=-0.55
    {74999,1920,1032, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=5.92  BV=-0.65
    {74999,2080,1024, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=6.02  BV=-0.75
    {83332,1984,1032, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=5.97  BV=-0.85
    {91666,1952,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=5.93  BV=-0.95
    {91666,2080,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=6.02  BV=-1.04
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {523,2016,1032, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=5.99  BV=6.44
    {553,2048,1032, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=6.01  BV=6.34
    {603,2016,1032, 0, 0, 0},  //TV = 10.70(60 lines)  AV=1.53  SV=5.99  BV=6.24
    {643,2016,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=5.99  BV=6.15
    {683,2016,1040, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=6.00  BV=6.05
    {733,2016,1040, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=6.00  BV=5.95
    {784,2048,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=6.00  BV=5.85
    {844,2016,1032, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=5.99  BV=5.75
    {904,2016,1040, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=6.00  BV=5.64
    {964,2016,1040, 0, 0, 0},  //TV = 10.02(96 lines)  AV=1.53  SV=6.00  BV=5.55
    {1035,2048,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=6.00  BV=5.45
    {1105,2048,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=6.00  BV=5.35
    {1195,2016,1032, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=5.99  BV=5.25
    {1276,2048,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=6.00  BV=5.15
    {1366,2016,1040, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=6.00  BV=5.05
    {1456,2048,1024, 0, 0, 0},  //TV = 9.42(145 lines)  AV=1.53  SV=6.00  BV=4.95
    {1567,2016,1040, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=6.00  BV=4.85
    {1687,2016,1040, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=6.00  BV=4.74
    {1808,2016,1032, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=5.99  BV=4.65
    {1928,2016,1040, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=6.00  BV=4.55
    {2079,2016,1040, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=6.00  BV=4.44
    {2219,2016,1040, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=6.00  BV=4.35
    {2390,2016,1040, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=6.00  BV=4.24
    {2551,2016,1040, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=6.00  BV=4.15
    {2731,2016,1040, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=6.00  BV=4.05
    {2922,2016,1040, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=6.00  BV=3.95
    {3133,2016,1040, 0, 0, 0},  //TV = 8.32(312 lines)  AV=1.53  SV=6.00  BV=3.85
    {3374,2016,1040, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=6.00  BV=3.74
    {3605,2016,1040, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=6.00  BV=3.65
    {3866,2016,1040, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=6.00  BV=3.55
    {4137,2016,1040, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=6.00  BV=3.45
    {4458,2016,1040, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=6.00  BV=3.34
    {4769,2016,1040, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=6.00  BV=3.24
    {5111,2016,1040, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=6.00  BV=3.14
    {5472,2016,1040, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=6.00  BV=3.05
    {5854,2016,1040, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=6.00  BV=2.95
    {6275,2016,1040, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=6.00  BV=2.85
    {6717,2016,1040, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=6.00  BV=2.75
    {7199,2016,1040, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=6.00  BV=2.65
    {7711,2016,1040, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=6.00  BV=2.55
    {8314,2016,1040, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=6.00  BV=2.44
    {8906,2016,1040, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=6.00  BV=2.34
    {9538,2016,1040, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=6.00  BV=2.24
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {10000,2368,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.22  BV=1.95
    {10000,2560,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.32  BV=1.85
    {10000,2752,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.43  BV=1.75
    {10000,2944,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {20000,1792,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.82  BV=1.36
    {20000,1952,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.93  BV=1.24
    {20000,2080,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.02  BV=1.15
    {20000,2240,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.13  BV=1.05
    {20000,2400,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.23  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {40000,1792,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.82  BV=0.36
    {40000,1952,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.93  BV=0.24
    {40000,2080,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.02  BV=0.15
    {40000,2240,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.13  BV=0.05
    {50000,1920,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.91  BV=-0.05
    {50000,2048,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.01  BV=-0.16
    {50000,2176,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.10  BV=-0.25
    {60000,1952,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=5.94  BV=-0.35
    {60000,2112,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=6.04  BV=-0.45
    {69999,1920,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=5.92  BV=-0.55
    {69999,2048,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.02  BV=-0.65
    {79999,1920,1040, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=5.93  BV=-0.75
    {79999,2080,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=6.02  BV=-0.85
    {89999,1984,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=5.95  BV=-0.95
    {89999,2112,1032, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=6.06  BV=-1.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    108, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -11, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {523,4032,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=6.98  BV=5.45
    {553,4096,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=7.00  BV=5.35
    {593,4096,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=7.00  BV=5.25
    {643,4032,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=6.99  BV=5.15
    {683,4064,1024, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=6.99  BV=5.06
    {733,4064,1024, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=6.99  BV=4.96
    {784,4096,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=7.00  BV=4.85
    {844,4064,1024, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=6.99  BV=4.75
    {904,4064,1024, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=6.99  BV=4.65
    {974,4064,1024, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=6.99  BV=4.55
    {1035,4096,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=7.00  BV=4.45
    {1105,4096,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=7.00  BV=4.35
    {1195,4064,1024, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=6.99  BV=4.25
    {1276,4096,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=7.00  BV=4.15
    {1366,4064,1032, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=7.00  BV=4.05
    {1466,4096,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=7.00  BV=3.94
    {1567,4096,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=7.00  BV=3.85
    {1687,4064,1032, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=7.00  BV=3.74
    {1808,4064,1024, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=6.99  BV=3.65
    {1928,4064,1032, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=7.00  BV=3.55
    {2079,4064,1024, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=6.99  BV=3.45
    {2219,4064,1032, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=7.00  BV=3.35
    {2370,4096,1024, 0, 0, 0},  //TV = 8.72(236 lines)  AV=1.53  SV=7.00  BV=3.25
    {2551,4096,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=7.00  BV=3.15
    {2731,4064,1032, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=7.00  BV=3.05
    {2922,4096,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=7.00  BV=2.95
    {3133,4064,1032, 0, 0, 0},  //TV = 8.32(312 lines)  AV=1.53  SV=7.00  BV=2.85
    {3374,4064,1032, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=7.00  BV=2.74
    {3605,4064,1032, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=7.00  BV=2.65
    {3866,4064,1024, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=6.99  BV=2.56
    {4137,4064,1032, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=7.00  BV=2.45
    {4458,4064,1032, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=7.00  BV=2.34
    {4769,4064,1032, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=7.00  BV=2.24
    {5111,4064,1032, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=7.00  BV=2.14
    {5472,4064,1032, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=7.00  BV=2.04
    {5854,4064,1032, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=7.00  BV=1.95
    {6275,4064,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=7.00  BV=1.85
    {6717,4064,1032, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=7.00  BV=1.75
    {7199,4064,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=7.00  BV=1.65
    {7711,4064,1032, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=7.00  BV=1.55
    {8314,4064,1032, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=7.00  BV=1.44
    {8334,4352,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.09  BV=1.35
    {8334,4672,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.19  BV=1.25
    {8334,4992,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.29  BV=1.15
    {8334,5376,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.39  BV=1.05
    {8334,5760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.49  BV=0.95
    {16667,3072,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.58  BV=0.85
    {16667,3296,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.69  BV=0.75
    {16667,3520,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.78  BV=0.66
    {16667,3776,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.88  BV=0.56
    {16667,4064,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.99  BV=0.45
    {16667,4352,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.09  BV=0.35
    {16667,4608,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.18  BV=0.26
    {16667,4992,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.29  BV=0.15
    {25000,3552,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.79  BV=0.06
    {25000,3808,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.89  BV=-0.04
    {25000,4096,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.01  BV=-0.16
    {25000,4352,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.10  BV=-0.25
    {25000,4736,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.21  BV=-0.36
    {33333,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33333,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33333,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {41666,3744,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=6.87  BV=-0.75
    {41666,4000,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=6.97  BV=-0.85
    {41666,4288,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=7.07  BV=-0.95
    {50000,3840,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.91  BV=-1.05
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.01  BV=-1.16
    {50000,4416,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.11  BV=-1.26
    {58333,4032,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=6.99  BV=-1.36
    {58333,4288,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=7.08  BV=-1.45
    {66666,4064,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.99  BV=-1.55
    {74999,3872,1024, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=6.92  BV=-1.65
    {74999,4160,1024, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=7.02  BV=-1.75
    {83332,4000,1024, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=6.97  BV=-1.85
    {91666,3904,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=6.93  BV=-1.95
    {91666,4160,1032, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=7.03  BV=-2.06
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {523,4032,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=6.98  BV=5.45
    {553,4096,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=7.00  BV=5.35
    {593,4096,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=7.00  BV=5.25
    {643,4032,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=6.99  BV=5.15
    {683,4064,1024, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=6.99  BV=5.06
    {733,4064,1024, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=6.99  BV=4.96
    {784,4096,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=7.00  BV=4.85
    {844,4064,1024, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=6.99  BV=4.75
    {904,4064,1024, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=6.99  BV=4.65
    {974,4064,1024, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=6.99  BV=4.55
    {1035,4096,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=7.00  BV=4.45
    {1105,4096,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=7.00  BV=4.35
    {1195,4064,1024, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=6.99  BV=4.25
    {1276,4096,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=7.00  BV=4.15
    {1366,4064,1032, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=7.00  BV=4.05
    {1466,4096,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=7.00  BV=3.94
    {1567,4096,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=7.00  BV=3.85
    {1687,4064,1032, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=7.00  BV=3.74
    {1808,4064,1024, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=6.99  BV=3.65
    {1928,4064,1032, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=7.00  BV=3.55
    {2079,4064,1024, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=6.99  BV=3.45
    {2219,4064,1032, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=7.00  BV=3.35
    {2370,4096,1024, 0, 0, 0},  //TV = 8.72(236 lines)  AV=1.53  SV=7.00  BV=3.25
    {2551,4096,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=7.00  BV=3.15
    {2731,4064,1032, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=7.00  BV=3.05
    {2922,4096,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=7.00  BV=2.95
    {3133,4064,1032, 0, 0, 0},  //TV = 8.32(312 lines)  AV=1.53  SV=7.00  BV=2.85
    {3374,4064,1032, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=7.00  BV=2.74
    {3605,4064,1032, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=7.00  BV=2.65
    {3866,4064,1024, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=6.99  BV=2.56
    {4137,4064,1032, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=7.00  BV=2.45
    {4458,4064,1032, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=7.00  BV=2.34
    {4769,4064,1032, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=7.00  BV=2.24
    {5111,4064,1032, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=7.00  BV=2.14
    {5472,4064,1032, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=7.00  BV=2.04
    {5854,4064,1032, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=7.00  BV=1.95
    {6275,4064,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=7.00  BV=1.85
    {6717,4064,1032, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=7.00  BV=1.75
    {7199,4064,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=7.00  BV=1.65
    {7711,4064,1032, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=7.00  BV=1.55
    {8314,4064,1032, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=7.00  BV=1.44
    {8906,4064,1032, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=7.00  BV=1.34
    {9538,4064,1032, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=7.00  BV=1.24
    {10000,4160,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.02  BV=1.15
    {10000,4480,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.13  BV=1.05
    {10000,4800,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.23  BV=0.95
    {10000,5120,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.32  BV=0.85
    {10000,5504,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.43  BV=0.75
    {10000,5888,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.52  BV=0.65
    {20000,3136,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.63  BV=0.55
    {20000,3360,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.73  BV=0.45
    {20000,3616,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.82  BV=0.35
    {20000,3872,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.92  BV=0.26
    {20000,4160,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.02  BV=0.15
    {20000,4416,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.12  BV=0.06
    {20000,4736,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.22  BV=-0.05
    {30000,3392,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4224,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.04  BV=-0.45
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {40000,3616,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.83  BV=-0.66
    {40000,3904,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.93  BV=-0.76
    {40000,4160,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.02  BV=-0.85
    {40000,4480,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.13  BV=-0.95
    {50000,3840,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.91  BV=-1.05
    {50000,4096,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.01  BV=-1.16
    {50000,4416,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.11  BV=-1.26
    {60000,3936,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=6.94  BV=-1.35
    {60000,4224,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=7.04  BV=-1.45
    {69999,3872,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.92  BV=-1.55
    {69999,4160,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=7.02  BV=-1.65
    {79999,3904,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=6.93  BV=-1.76
    {79999,4160,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=7.02  BV=-1.85
    {89999,3968,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=6.95  BV=-1.95
    {89999,4224,1032, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=7.06  BV=-2.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    118, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -21, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {523,8064,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=7.98  BV=4.45
    {553,8192,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=8.00  BV=4.35
    {593,8192,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=8.00  BV=4.25
    {643,8064,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=7.99  BV=4.15
    {683,8128,1024, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=7.99  BV=4.06
    {733,8128,1024, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=7.99  BV=3.96
    {784,8192,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=8.00  BV=3.85
    {844,8128,1024, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=7.99  BV=3.75
    {904,8128,1024, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=7.99  BV=3.65
    {974,8128,1024, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=7.99  BV=3.55
    {1035,8192,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=8.00  BV=3.45
    {1105,8192,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=8.00  BV=3.35
    {1195,8128,1024, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=7.99  BV=3.25
    {1276,8192,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=8.00  BV=3.15
    {1366,8192,1024, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=8.00  BV=3.05
    {1466,8192,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=8.00  BV=2.94
    {1567,8192,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=8.00  BV=2.85
    {1687,8192,1024, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=8.00  BV=2.74
    {1808,8128,1024, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=7.99  BV=2.65
    {1928,8128,1032, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=8.00  BV=2.55
    {2079,8128,1024, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=7.99  BV=2.45
    {2219,8128,1032, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=8.00  BV=2.35
    {2390,8128,1032, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=8.00  BV=2.24
    {2551,8192,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=8.00  BV=2.15
    {2731,8192,1024, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=8.00  BV=2.05
    {2922,8192,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=8.00  BV=1.95
    {3153,8128,1024, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=7.99  BV=1.85
    {3374,8128,1024, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=7.99  BV=1.75
    {3605,8192,1024, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=8.00  BV=1.65
    {3866,8128,1024, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=7.99  BV=1.56
    {4137,8128,1024, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=7.99  BV=1.46
    {4458,8128,1024, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=7.99  BV=1.35
    {4769,8128,1032, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=8.00  BV=1.24
    {5111,8128,1024, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=7.99  BV=1.15
    {5472,8128,1024, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=7.99  BV=1.06
    {5854,8192,1024, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=8.00  BV=0.95
    {6275,8128,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=8.00  BV=0.85
    {6717,8128,1032, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=8.00  BV=0.75
    {7199,8128,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=8.00  BV=0.65
    {7711,8128,1032, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=8.00  BV=0.55
    {8314,8128,1032, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=8.00  BV=0.44
    {8334,8704,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=8.09  BV=0.35
    {8334,9344,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=8.19  BV=0.25
    {8334,9984,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=8.29  BV=0.15
    {8334,10752,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=8.39  BV=0.05
    {8334,11520,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=8.49  BV=-0.05
    {16667,6144,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.58  BV=-0.15
    {16667,6592,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.69  BV=-0.25
    {16667,7040,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.78  BV=-0.34
    {16667,7552,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.88  BV=-0.44
    {16667,8128,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.99  BV=-0.55
    {16667,8704,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.09  BV=-0.65
    {16667,9216,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.18  BV=-0.74
    {16667,9984,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.29  BV=-0.85
    {25000,7104,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.79  BV=-0.94
    {25000,7616,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.89  BV=-1.04
    {25000,8192,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.01  BV=-1.16
    {25000,8704,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.10  BV=-1.25
    {25000,9344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.20  BV=-1.35
    {33333,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33333,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33333,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {41666,7488,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=7.87  BV=-1.75
    {41666,8000,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=7.97  BV=-1.85
    {41666,8576,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.07  BV=-1.95
    {50000,7680,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.91  BV=-2.05
    {50000,8192,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.01  BV=-2.16
    {50000,8832,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.11  BV=-2.26
    {58333,8064,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=7.99  BV=-2.36
    {58333,8704,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.09  BV=-2.46
    {66666,8128,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=7.99  BV=-2.55
    {74999,7744,1024, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=7.92  BV=-2.65
    {74999,8320,1024, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=8.02  BV=-2.75
    {83332,8000,1024, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=7.97  BV=-2.85
    {91666,7808,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=7.93  BV=-2.95
    {91666,8320,1032, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=8.03  BV=-3.06
    {99999,8192,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.00  BV=-3.15
    {108332,8128,1024, 0, 0, 0},  //TV = 3.21(10790 lines)  AV=1.53  SV=7.99  BV=-3.25
    {116665,8064,1024, 0, 0, 0},  //TV = 3.10(11620 lines)  AV=1.53  SV=7.98  BV=-3.35
    {124998,8064,1032, 0, 0, 0},  //TV = 3.00(12450 lines)  AV=1.53  SV=7.99  BV=-3.46
    {133332,8128,1024, 0, 0, 0},  //TV = 2.91(13280 lines)  AV=1.53  SV=7.99  BV=-3.55
    {141665,8192,1024, 0, 0, 0},  //TV = 2.82(14110 lines)  AV=1.53  SV=8.00  BV=-3.65
    {149998,8320,1024, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=8.02  BV=-3.75
    {166664,8000,1024, 0, 0, 0},  //TV = 2.58(16600 lines)  AV=1.53  SV=7.97  BV=-3.85
    {174998,8192,1024, 0, 0, 0},  //TV = 2.51(17430 lines)  AV=1.53  SV=8.00  BV=-3.95
    {191664,8000,1024, 0, 0, 0},  //TV = 2.38(19090 lines)  AV=1.53  SV=7.97  BV=-4.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {523,8064,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=7.98  BV=4.45
    {553,8192,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=8.00  BV=4.35
    {593,8192,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=8.00  BV=4.25
    {643,8064,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=7.99  BV=4.15
    {683,8128,1024, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=7.99  BV=4.06
    {733,8128,1024, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=7.99  BV=3.96
    {784,8192,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=8.00  BV=3.85
    {844,8128,1024, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=7.99  BV=3.75
    {904,8128,1024, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=7.99  BV=3.65
    {974,8128,1024, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=7.99  BV=3.55
    {1035,8192,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=8.00  BV=3.45
    {1105,8192,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=8.00  BV=3.35
    {1195,8128,1024, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=7.99  BV=3.25
    {1276,8192,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=8.00  BV=3.15
    {1366,8192,1024, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=8.00  BV=3.05
    {1466,8192,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=8.00  BV=2.94
    {1567,8192,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=8.00  BV=2.85
    {1687,8192,1024, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=8.00  BV=2.74
    {1808,8128,1024, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=7.99  BV=2.65
    {1928,8128,1032, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=8.00  BV=2.55
    {2079,8128,1024, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=7.99  BV=2.45
    {2219,8128,1032, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=8.00  BV=2.35
    {2390,8128,1032, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=8.00  BV=2.24
    {2551,8192,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=8.00  BV=2.15
    {2731,8192,1024, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=8.00  BV=2.05
    {2922,8192,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=8.00  BV=1.95
    {3153,8128,1024, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=7.99  BV=1.85
    {3374,8128,1024, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=7.99  BV=1.75
    {3605,8192,1024, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=8.00  BV=1.65
    {3866,8128,1024, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=7.99  BV=1.56
    {4137,8128,1024, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=7.99  BV=1.46
    {4458,8128,1024, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=7.99  BV=1.35
    {4769,8128,1032, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=8.00  BV=1.24
    {5111,8128,1024, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=7.99  BV=1.15
    {5472,8128,1024, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=7.99  BV=1.06
    {5854,8192,1024, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=8.00  BV=0.95
    {6275,8128,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=8.00  BV=0.85
    {6717,8128,1032, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=8.00  BV=0.75
    {7199,8128,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=8.00  BV=0.65
    {7711,8128,1032, 0, 0, 0},  //TV = 7.02(768 lines)  AV=1.53  SV=8.00  BV=0.55
    {8314,8128,1032, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=8.00  BV=0.44
    {8906,8128,1032, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=8.00  BV=0.34
    {9538,8128,1032, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=8.00  BV=0.24
    {10000,8320,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.02  BV=0.15
    {10000,8960,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.13  BV=0.05
    {10000,9600,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.23  BV=-0.05
    {10000,10240,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.32  BV=-0.15
    {10000,11008,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.43  BV=-0.25
    {10000,11776,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=8.52  BV=-0.35
    {20000,6272,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.63  BV=-0.45
    {20000,6720,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.73  BV=-0.55
    {20000,7232,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.82  BV=-0.65
    {20000,7744,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.92  BV=-0.74
    {20000,8320,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.02  BV=-0.85
    {20000,8832,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.12  BV=-0.94
    {20000,9472,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.22  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {40000,7296,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.83  BV=-1.66
    {40000,7808,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=7.93  BV=-1.76
    {40000,8320,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.02  BV=-1.85
    {40000,8960,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.13  BV=-1.95
    {50000,7680,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=7.91  BV=-2.05
    {50000,8192,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.01  BV=-2.16
    {50000,8832,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.11  BV=-2.26
    {60000,7872,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=7.94  BV=-2.35
    {60000,8448,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.04  BV=-2.45
    {69999,7744,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=7.92  BV=-2.55
    {69999,8320,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.02  BV=-2.65
    {79999,7808,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=7.93  BV=-2.76
    {79999,8320,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=8.02  BV=-2.85
    {89999,7936,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=7.95  BV=-2.95
    {89999,8448,1032, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=8.06  BV=-3.05
    {99999,8192,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.00  BV=-3.15
    {109999,8000,1024, 0, 0, 0},  //TV = 3.18(10956 lines)  AV=1.53  SV=7.97  BV=-3.25
    {119999,7872,1024, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=7.94  BV=-3.35
    {119999,8448,1024, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=8.04  BV=-3.45
    {129998,8320,1024, 0, 0, 0},  //TV = 2.94(12948 lines)  AV=1.53  SV=8.02  BV=-3.55
    {139998,8320,1024, 0, 0, 0},  //TV = 2.84(13944 lines)  AV=1.53  SV=8.02  BV=-3.65
    {149998,8320,1024, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=8.02  BV=-3.75
    {159998,8320,1024, 0, 0, 0},  //TV = 2.64(15936 lines)  AV=1.53  SV=8.02  BV=-3.85
    {179998,7936,1024, 0, 0, 0},  //TV = 2.47(17928 lines)  AV=1.53  SV=7.95  BV=-3.95
    {189997,8064,1024, 0, 0, 0},  //TV = 2.40(18924 lines)  AV=1.53  SV=7.98  BV=-4.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    138, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -41, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {523,16128,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=8.98  BV=3.45
    {553,16384,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=9.00  BV=3.35
    {593,16384,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=9.00  BV=3.25
    {643,16128,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=8.99  BV=3.15
    {683,16128,1032, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=8.99  BV=3.06
    {733,16128,1032, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=8.99  BV=2.96
    {784,16384,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=9.00  BV=2.85
    {844,16128,1032, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=8.99  BV=2.75
    {904,16128,1032, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=8.99  BV=2.65
    {974,16128,1032, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=8.99  BV=2.55
    {1035,16384,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=9.00  BV=2.45
    {1105,16384,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=9.00  BV=2.35
    {1195,16128,1032, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=8.99  BV=2.25
    {1276,16384,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=9.00  BV=2.15
    {1366,16384,1024, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=9.00  BV=2.05
    {1466,16384,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=9.00  BV=1.94
    {1567,16384,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=9.00  BV=1.85
    {1687,16384,1024, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=9.00  BV=1.74
    {1808,16128,1032, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=8.99  BV=1.65
    {1928,16128,1040, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=9.00  BV=1.55
    {2079,16128,1032, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=8.99  BV=1.45
    {2219,16128,1040, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=9.00  BV=1.35
    {2370,16384,1024, 0, 0, 0},  //TV = 8.72(236 lines)  AV=1.53  SV=9.00  BV=1.25
    {2551,16384,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=9.00  BV=1.15
    {2731,16384,1024, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=9.00  BV=1.05
    {2922,16384,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=9.00  BV=0.95
    {3153,16128,1032, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=8.99  BV=0.85
    {3374,16128,1032, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=8.99  BV=0.75
    {3605,16384,1024, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=9.00  BV=0.65
    {3866,16128,1032, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=8.99  BV=0.56
    {4137,16128,1032, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=8.99  BV=0.46
    {4458,16128,1032, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=8.99  BV=0.35
    {4769,16128,1040, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=9.00  BV=0.24
    {5111,16128,1032, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=8.99  BV=0.15
    {5472,16128,1032, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=8.99  BV=0.06
    {5854,16384,1024, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=9.00  BV=-0.05
    {6275,16128,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=8.99  BV=-0.14
    {6717,16128,1040, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=9.00  BV=-0.25
    {7199,16128,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=8.99  BV=-0.34
    {7761,16128,1040, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=9.00  BV=-0.46
    {8314,16128,1040, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=9.00  BV=-0.56
    {8334,16384,1088, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=9.09  BV=-0.65
    {8334,16384,1168, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=9.19  BV=-0.75
    {8334,16384,1248, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=9.29  BV=-0.85
    {8334,16384,1344, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=9.39  BV=-0.95
    {8334,16384,1440, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=9.49  BV=-1.05
    {16667,12288,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.58  BV=-1.15
    {16667,13056,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.68  BV=-1.25
    {16667,14080,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.78  BV=-1.34
    {16667,15104,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.88  BV=-1.44
    {16667,16128,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=8.99  BV=-1.55
    {16667,16384,1088, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.09  BV=-1.65
    {16667,16384,1168, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.19  BV=-1.75
    {16667,16384,1248, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.29  BV=-1.85
    {25000,14080,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.80  BV=-1.95
    {25000,15104,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.89  BV=-2.04
    {25000,16384,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.00  BV=-2.15
    {25000,16384,1096, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.10  BV=-2.25
    {25000,16384,1184, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.21  BV=-2.36
    {33333,15104,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.89  BV=-2.46
    {33333,16128,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.99  BV=-2.55
    {33333,16384,1088, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=9.09  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {50000,15360,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.01  BV=-3.16
    {50000,16384,1104, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.11  BV=-3.26
    {58333,16128,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.99  BV=-3.36
    {58333,16384,1088, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.09  BV=-3.46
    {66666,16128,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.99  BV=-3.55
    {74999,15360,1032, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=8.92  BV=-3.65
    {74999,16384,1040, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=9.02  BV=-3.75
    {83332,15872,1032, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=8.97  BV=-3.85
    {91666,15616,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=8.93  BV=-3.95
    {91666,16384,1048, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=9.03  BV=-4.05
    {99999,16384,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=9.00  BV=-4.15
    {108332,16128,1032, 0, 0, 0},  //TV = 3.21(10790 lines)  AV=1.53  SV=8.99  BV=-4.25
    {116665,16128,1024, 0, 0, 0},  //TV = 3.10(11620 lines)  AV=1.53  SV=8.98  BV=-4.35
    {124998,16128,1024, 0, 0, 0},  //TV = 3.00(12450 lines)  AV=1.53  SV=8.98  BV=-4.45
    {133332,16128,1032, 0, 0, 0},  //TV = 2.91(13280 lines)  AV=1.53  SV=8.99  BV=-4.55
    {141665,16384,1024, 0, 0, 0},  //TV = 2.82(14110 lines)  AV=1.53  SV=9.00  BV=-4.65
    {149998,16384,1040, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=9.02  BV=-4.75
    {166664,15872,1032, 0, 0, 0},  //TV = 2.58(16600 lines)  AV=1.53  SV=8.97  BV=-4.85
    {174998,16384,1024, 0, 0, 0},  //TV = 2.51(17430 lines)  AV=1.53  SV=9.00  BV=-4.95
    {191664,15872,1032, 0, 0, 0},  //TV = 2.38(19090 lines)  AV=1.53  SV=8.97  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {523,16128,1024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=8.98  BV=3.45
    {553,16384,1024, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=9.00  BV=3.35
    {593,16384,1024, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=9.00  BV=3.25
    {643,16128,1032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=8.99  BV=3.15
    {683,16128,1032, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=8.99  BV=3.06
    {733,16128,1032, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=8.99  BV=2.96
    {784,16384,1024, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=9.00  BV=2.85
    {844,16128,1032, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=8.99  BV=2.75
    {904,16128,1032, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=8.99  BV=2.65
    {974,16128,1032, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=8.99  BV=2.55
    {1035,16384,1024, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=9.00  BV=2.45
    {1105,16384,1024, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=9.00  BV=2.35
    {1195,16128,1032, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=8.99  BV=2.25
    {1276,16384,1024, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=9.00  BV=2.15
    {1366,16384,1024, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=9.00  BV=2.05
    {1466,16384,1024, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=9.00  BV=1.94
    {1567,16384,1024, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=9.00  BV=1.85
    {1687,16384,1024, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=9.00  BV=1.74
    {1808,16128,1032, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=8.99  BV=1.65
    {1928,16128,1040, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=9.00  BV=1.55
    {2079,16128,1032, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=8.99  BV=1.45
    {2219,16128,1040, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=9.00  BV=1.35
    {2370,16384,1024, 0, 0, 0},  //TV = 8.72(236 lines)  AV=1.53  SV=9.00  BV=1.25
    {2551,16384,1024, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=9.00  BV=1.15
    {2731,16384,1024, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=9.00  BV=1.05
    {2922,16384,1024, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=9.00  BV=0.95
    {3153,16128,1032, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=8.99  BV=0.85
    {3374,16128,1032, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=8.99  BV=0.75
    {3605,16384,1024, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=9.00  BV=0.65
    {3866,16128,1032, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=8.99  BV=0.56
    {4137,16128,1032, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=8.99  BV=0.46
    {4458,16128,1032, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=8.99  BV=0.35
    {4769,16128,1040, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=9.00  BV=0.24
    {5111,16128,1032, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=8.99  BV=0.15
    {5472,16128,1032, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=8.99  BV=0.06
    {5854,16384,1024, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=9.00  BV=-0.05
    {6275,16128,1032, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=8.99  BV=-0.14
    {6717,16128,1040, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=9.00  BV=-0.25
    {7199,16128,1032, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=8.99  BV=-0.34
    {7761,16128,1040, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=9.00  BV=-0.46
    {8314,16128,1040, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=9.00  BV=-0.56
    {8906,16128,1040, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=9.00  BV=-0.66
    {9538,16128,1040, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=9.00  BV=-0.76
    {10000,16384,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.02  BV=-0.85
    {10000,16384,1120, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.13  BV=-0.95
    {10000,16384,1200, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.23  BV=-1.05
    {10000,16384,1280, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.32  BV=-1.15
    {10000,16384,1376, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.43  BV=-1.25
    {10000,16384,1472, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=9.52  BV=-1.35
    {20000,12544,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.63  BV=-1.45
    {20000,13312,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.72  BV=-1.55
    {20000,14336,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.82  BV=-1.64
    {20000,15360,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=8.92  BV=-1.74
    {20000,16384,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.02  BV=-1.85
    {20000,16384,1112, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.12  BV=-1.94
    {20000,16384,1192, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.22  BV=-2.04
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {30000,14592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.83  BV=-2.24
    {30000,15616,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.94  BV=-2.35
    {30000,16384,1056, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.04  BV=-2.45
    {30000,16384,1128, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.14  BV=-2.55
    {40000,14592,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.66
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1048, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.03  BV=-2.86
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {50000,15360,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.01  BV=-3.16
    {50000,16384,1104, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.11  BV=-3.26
    {60000,15616,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.94  BV=-3.35
    {60000,16384,1056, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.04  BV=-3.45
    {69999,15360,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.92  BV=-3.55
    {69999,16384,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.02  BV=-3.65
    {79999,15616,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=8.93  BV=-3.76
    {79999,16384,1040, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=9.02  BV=-3.85
    {89999,15872,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=8.95  BV=-3.95
    {89999,16384,1064, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=9.06  BV=-4.05
    {99999,16384,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=9.00  BV=-4.15
    {109999,15872,1032, 0, 0, 0},  //TV = 3.18(10956 lines)  AV=1.53  SV=8.97  BV=-4.25
    {119999,15616,1032, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=8.94  BV=-4.35
    {119999,16384,1056, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=9.04  BV=-4.45
    {129998,16384,1040, 0, 0, 0},  //TV = 2.94(12948 lines)  AV=1.53  SV=9.02  BV=-4.55
    {139998,16384,1040, 0, 0, 0},  //TV = 2.84(13944 lines)  AV=1.53  SV=9.02  BV=-4.65
    {149998,16384,1040, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=9.02  BV=-4.75
    {159998,16384,1040, 0, 0, 0},  //TV = 2.64(15936 lines)  AV=1.53  SV=9.02  BV=-4.85
    {179998,15872,1024, 0, 0, 0},  //TV = 2.47(17928 lines)  AV=1.53  SV=8.95  BV=-4.95
    {189997,16128,1024, 0, 0, 0},  //TV = 2.40(18924 lines)  AV=1.53  SV=8.98  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    148, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -51, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,12800,1040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {58333,11392,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.48  BV=-2.85
    {58333,12288,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.58  BV=-2.95
    {66666,11520,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.49  BV=-3.05
    {66666,12288,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.58  BV=-3.15
    {66666,13056,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.68  BV=-3.25
    {66666,14080,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.79  BV=-3.35
    {66666,15104,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.88  BV=-3.44
    {66666,16128,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.99  BV=-3.55
    {66666,16384,1088, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.09  BV=-3.65
    {66666,16384,1168, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.19  BV=-3.75
    {66666,16384,1248, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.29  BV=-3.85
    {66666,16384,1336, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.38  BV=-3.95
    {66666,16384,1432, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.48  BV=-4.05
    {66666,16384,1536, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.58  BV=-4.15
    {66666,16384,1648, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.69  BV=-4.25
    {66666,16384,1768, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.79  BV=-4.35
    {66666,16384,1896, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.89  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {66666,16384,2176, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.09  BV=-4.65
    {66666,16384,2328, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.18  BV=-4.75
    {66666,16384,2496, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.29  BV=-4.85
    {66666,16384,2680, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.39  BV=-4.95
    {66666,16384,2872, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {66666,16384,2880, 0, 0, 0},  /* TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {50000,13312,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.70  BV=-2.85
    {60000,11904,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.54  BV=-2.95
    {60000,12800,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.64  BV=-3.05
    {69999,11776,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.52  BV=-3.16
    {69999,12544,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.61  BV=-3.25
    {69999,13312,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.72  BV=-3.36
    {69999,14336,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.82  BV=-3.45
    {69999,15360,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.92  BV=-3.55
    {69999,16384,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.02  BV=-3.65
    {69999,16384,1112, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.12  BV=-3.75
    {69999,16384,1192, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.22  BV=-3.85
    {69999,16384,1272, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.31  BV=-3.95
    {69999,16384,1368, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.42  BV=-4.05
    {69999,16384,1464, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.52  BV=-4.15
    {69999,16384,1568, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.61  BV=-4.25
    {69999,16384,1680, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.71  BV=-4.35
    {69999,16384,1800, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.81  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {69999,16384,2224, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.12  BV=-4.75
    {69999,16384,2376, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.21  BV=-4.85
    {69999,16384,2552, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.32  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {69999,16384,2880, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.49  BV=-5.12
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    149, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -52, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,12800,1040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {58333,11392,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.48  BV=-2.85
    {58333,12288,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.58  BV=-2.95
    {66666,11520,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.49  BV=-3.05
    {66666,12288,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.58  BV=-3.15
    {66666,13056,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.68  BV=-3.25
    {66666,14080,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.79  BV=-3.35
    {66666,15104,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.88  BV=-3.44
    {66666,16128,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=8.99  BV=-3.55
    {66666,16384,1088, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.09  BV=-3.65
    {66666,16384,1168, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.19  BV=-3.75
    {66666,16384,1248, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.29  BV=-3.85
    {66666,16384,1336, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.38  BV=-3.95
    {66666,16384,1432, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.48  BV=-4.05
    {66666,16384,1536, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.58  BV=-4.15
    {66666,16384,1648, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.69  BV=-4.25
    {66666,16384,1768, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.79  BV=-4.35
    {66666,16384,1896, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.89  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {66666,16384,2176, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.09  BV=-4.65
    {66666,16384,2328, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.18  BV=-4.75
    {66666,16384,2496, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.29  BV=-4.85
    {66666,16384,2680, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.39  BV=-4.95
    {66666,16384,2872, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {74999,16384,2736, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.42  BV=-5.15
    {74999,16384,2936, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.52  BV=-5.25
    {83332,16384,2832, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.47  BV=-5.35
    {91666,16384,2760, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.43  BV=-5.45
    {91666,16384,2960, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.53  BV=-5.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {50000,11648,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.51  BV=-2.65
    {50000,12288,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.61  BV=-2.75
    {50000,13312,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.70  BV=-2.85
    {60000,11904,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.54  BV=-2.95
    {60000,12800,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.64  BV=-3.05
    {69999,11776,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.52  BV=-3.16
    {69999,12544,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.61  BV=-3.25
    {69999,13312,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.72  BV=-3.36
    {69999,14336,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.82  BV=-3.45
    {69999,15360,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=8.92  BV=-3.55
    {69999,16384,1040, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.02  BV=-3.65
    {69999,16384,1112, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.12  BV=-3.75
    {69999,16384,1192, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.22  BV=-3.85
    {69999,16384,1272, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.31  BV=-3.95
    {69999,16384,1368, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.42  BV=-4.05
    {69999,16384,1464, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.52  BV=-4.15
    {69999,16384,1568, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.61  BV=-4.25
    {69999,16384,1680, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.71  BV=-4.35
    {69999,16384,1800, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.81  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {69999,16384,2224, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.12  BV=-4.75
    {69999,16384,2376, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.21  BV=-4.85
    {69999,16384,2552, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.32  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {69999,16384,2936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.52  BV=-5.15
    {79999,16384,2752, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.43  BV=-5.25
    {79999,16384,2952, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.53  BV=-5.35
    {89999,16384,2808, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.46  BV=-5.45
    {89999,16384,3016, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.56  BV=-5.55
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    153, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -56, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.88  BV=2.56
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2304,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.18  BV=2.26
    {8335,2496,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.29  BV=2.15
    {8335,2656,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.39  BV=2.05
    {8335,2848,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.49  BV=1.95
    {8335,3072,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.58  BV=1.85
    {8335,3296,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.69  BV=1.75
    {8335,3520,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.78  BV=1.66
    {8335,3776,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.88  BV=1.56
    {8335,4064,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.99  BV=1.45
    {8335,4352,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.09  BV=1.35
    {8335,4672,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.19  BV=1.25
    {8334,4992,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.29  BV=1.15
    {8334,5312,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.39  BV=1.05
    {8334,5696,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=7.49  BV=0.95
    {16667,3072,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.58  BV=0.85
    {16667,3296,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.69  BV=0.75
    {16667,3520,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.78  BV=0.66
    {16667,3776,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.88  BV=0.56
    {16667,4032,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.99  BV=0.45
    {16667,4352,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.09  BV=0.35
    {16667,4672,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.19  BV=0.25
    {16667,4992,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=7.30  BV=0.14
    {25000,3584,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.81  BV=0.05
    {25000,3840,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.91  BV=-0.05
    {25000,4096,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.01  BV=-0.16
    {25000,4416,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.11  BV=-0.26
    {25000,4736,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.21  BV=-0.36
    {33333,3776,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.89  BV=-0.46
    {33333,4064,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33333,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33333,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33333,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33333,5376,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33333,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33333,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33333,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33333,7040,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.78  BV=-1.34
    {33333,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33333,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33333,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33333,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33333,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33333,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33333,11520,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {33333,14080,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.78  BV=-2.34
    {33333,15104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.88  BV=-2.44
    {33333,16128,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.99  BV=-2.55
    {33333,16128,1040, 0, 0, 0},  /* TV = 4.91(3320 lines)  AV=1.53  SV=9.00  BV=-2.56 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.22  BV=2.95
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1376,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1664,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.72  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {10000,2368,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.22  BV=1.95
    {10000,2560,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.32  BV=1.85
    {10000,2752,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.43  BV=1.75
    {10000,2944,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.52  BV=1.65
    {10000,3136,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.61  BV=1.56
    {10000,3392,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.73  BV=1.45
    {10000,3616,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.83  BV=1.34
    {10000,3872,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.93  BV=1.24
    {10000,4160,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.02  BV=1.15
    {10000,4416,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.12  BV=1.06
    {10000,4736,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.22  BV=0.95
    {10000,5120,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.32  BV=0.85
    {10000,5504,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.43  BV=0.75
    {10000,5888,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=7.52  BV=0.65
    {20000,3136,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.61  BV=0.56
    {20000,3392,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.73  BV=0.45
    {20000,3616,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.82  BV=0.35
    {20000,3904,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.93  BV=0.24
    {20000,4160,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.02  BV=0.15
    {20000,4480,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.13  BV=0.05
    {20000,4800,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.23  BV=-0.05
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4224,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.04  BV=-0.45
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7808,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.93  BV=-1.34
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {30000,14592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.83  BV=-2.24
    {30000,15616,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.94  BV=-2.35
    {30000,16128,1040, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=9.00  BV=-2.41 */
    {30000,16128,1040, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=9.00  BV=-2.41 */
    {30000,16128,1040, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=9.00  BV=-2.41 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -26, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33333,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {41666,1856,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.87  BV=0.25
    {41666,1984,1040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=5.98  BV=0.14
    {41666,2112,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=6.06  BV=0.06
    {50000,1888,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.91  BV=-0.05
    {50000,2048,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.00  BV=-0.15
    {50000,2176,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.10  BV=-0.25
    {58333,2016,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=5.98  BV=-0.35
    {58333,2144,1032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=6.08  BV=-0.45
    {66666,2016,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=5.99  BV=-0.55
    {66666,2176,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.09  BV=-0.65
    {66666,2336,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.19  BV=-0.75
    {66666,2496,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.29  BV=-0.85
    {66666,2656,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.39  BV=-0.95
    {66666,2880,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.49  BV=-1.05
    {66666,3072,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.58  BV=-1.15
    {66666,3296,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.69  BV=-1.25
    {66666,3552,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.79  BV=-1.36
    {66666,3776,1032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.89  BV=-1.46
    {66666,4064,1024, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=6.99  BV=-1.55
    {74999,3840,1032, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=6.92  BV=-1.65
    {74999,4096,1032, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=7.01  BV=-1.74
    {83332,4000,1024, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=6.97  BV=-1.85
    {83332,4288,1024, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=7.07  BV=-1.95
    {91666,4160,1024, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=7.02  BV=-2.04
    {99999,4096,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.01  BV=-2.16
    {99999,4352,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.10  BV=-2.25
    {99999,4672,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.20  BV=-2.35
    {99999,5056,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.30  BV=-2.45
    {99999,5376,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.39  BV=-2.54
    {99999,5824,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.51  BV=-2.65
    {99999,6208,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.60  BV=-2.75
    {99999,6656,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.70  BV=-2.85
    {99999,7168,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.81  BV=-2.95
    {99999,7616,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.91  BV=-3.05
    {99999,8192,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.00  BV=-3.15
    {99999,8704,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.10  BV=-3.25
    {99999,9344,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.20  BV=-3.35
    {99999,9984,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.30  BV=-3.44
    {99999,10752,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.39  BV=-3.54
    {99999,11648,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.51  BV=-3.65
    {99999,12160,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.58  BV=-3.73
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {40000,1792,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.82  BV=0.36
    {40000,1952,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=5.93  BV=0.24
    {40000,2080,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.02  BV=0.15
    {40000,2240,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=6.13  BV=0.05
    {50000,1888,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=5.91  BV=-0.05
    {50000,2048,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.00  BV=-0.15
    {50000,2176,1032, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=6.10  BV=-0.25
    {60000,1952,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=5.94  BV=-0.35
    {60000,2112,1024, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=6.04  BV=-0.45
    {69999,1920,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=5.92  BV=-0.55
    {69999,2080,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.02  BV=-0.65
    {69999,2208,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.12  BV=-0.75
    {69999,2368,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.21  BV=-0.84
    {69999,2560,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.32  BV=-0.95
    {69999,2720,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.42  BV=-1.05
    {69999,2912,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.52  BV=-1.15
    {69999,3136,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.61  BV=-1.25
    {69999,3360,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.71  BV=-1.35
    {69999,3616,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.82  BV=-1.45
    {69999,3872,1024, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=6.92  BV=-1.55
    {69999,4096,1032, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=7.01  BV=-1.64
    {79999,3872,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=6.92  BV=-1.74
    {79999,4160,1024, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=7.02  BV=-1.85
    {89999,3968,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=6.95  BV=-1.95
    {89999,4224,1024, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=7.04  BV=-2.04
    {99999,4096,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.01  BV=-2.16
    {99999,4352,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.10  BV=-2.25
    {99999,4672,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.20  BV=-2.35
    {99999,5056,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.30  BV=-2.45
    {99999,5376,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.39  BV=-2.54
    {99999,5824,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.51  BV=-2.65
    {99999,6208,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.60  BV=-2.75
    {99999,6656,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.70  BV=-2.85
    {99999,7168,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.81  BV=-2.95
    {99999,7616,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=7.91  BV=-3.05
    {99999,8192,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.00  BV=-3.15
    {99999,8704,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.10  BV=-3.25
    {99999,9344,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.20  BV=-3.35
    {99999,9984,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.30  BV=-3.44
    {99999,10752,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.39  BV=-3.54
    {99999,11648,1024, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.51  BV=-3.65
    {99999,12160,1032, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=8.58  BV=-3.73
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    135, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -38, //i4MinBV
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
    {199987,1696,1032, 0, 0, 0},  //TV = 2.32(19919 lines)  AV=1.53  SV=5.74  BV=-1.89
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {199997,1696,1032, 0, 0, 0},  //TV = 2.32(19920 lines)  AV=1.53  SV=5.74  BV=-1.89
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    -18, //i4MaxBV
    -19, //i4MinBV
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8335,1152,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.18  BV=3.26
    {8335,1248,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.29  BV=3.15
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.69  BV=2.74
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.88  BV=2.56
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {16668,1152,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.18  BV=2.26
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {25001,1152,1048, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.20  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {33334,1152,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.18  BV=1.26
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1440,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.49  BV=0.95
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.69  BV=0.74
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2848,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4064,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5376,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7040,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.78  BV=-1.34
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11520,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {50000,15104,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.00  BV=-3.15
    {50000,16384,1096, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.10  BV=-3.25
    {58333,16128,1024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=8.98  BV=-3.35
    {58333,16384,1080, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.08  BV=-3.45
    {58333,16384,1160, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.18  BV=-3.55
    {58333,16384,1240, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.28  BV=-3.65
    {58333,16384,1328, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.38  BV=-3.74
    {58333,16384,1424, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.48  BV=-3.85
    {58333,16384,1536, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.58  BV=-3.95
    {58333,16384,1648, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.69  BV=-4.06
    {58333,16384,1768, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.79  BV=-4.16
    {58333,16384,1896, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.89  BV=-4.26
    {58333,16384,2032, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.99  BV=-4.36
    {58333,16384,2160, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.08  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {74999,16384,1936, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=9.92  BV=-4.65
    {74999,16384,2072, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.02  BV=-4.75
    {83332,16384,2000, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=9.97  BV=-4.85
    {83332,16384,2144, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.07  BV=-4.95
    {91666,16384,2088, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.03  BV=-5.05
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99999,16384,2208, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99999,16384,2368, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99999,16384,2536, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99999,16384,2712, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.41  BV=-5.55
    {99999,16384,2912, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99999,16384,3120, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99999,16384,3344, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99999,16384,3584, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99999,16384,3840, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99999,16384,4096, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8575,1136,1024, 0, 0, 0},  //TV = 6.87(854 lines)  AV=1.53  SV=5.15  BV=3.25
    {9187,1136,1024, 0, 0, 0},  //TV = 6.77(915 lines)  AV=1.53  SV=5.15  BV=3.15
    {9840,1136,1024, 0, 0, 0},  //TV = 6.67(980 lines)  AV=1.53  SV=5.15  BV=3.05
    {10000,1184,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.22  BV=2.95
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.34  BV=1.25
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1600,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2080,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.03  BV=0.56
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.35  BV=0.24
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30000,3392,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7808,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.93  BV=-1.34
    {30000,8320,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.03  BV=-1.44
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1112, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.12  BV=-2.94
    {50000,15104,1040, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=8.91  BV=-3.05
    {50000,16384,1024, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.00  BV=-3.15
    {50000,16384,1096, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.10  BV=-3.25
    {60000,15616,1032, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=8.94  BV=-3.35
    {60000,16384,1048, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.03  BV=-3.44
    {60000,16384,1128, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.14  BV=-3.55
    {60000,16384,1208, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.24  BV=-3.65
    {60000,16384,1296, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.34  BV=-3.75
    {60000,16384,1392, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.44  BV=-3.85
    {60000,16384,1496, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.55  BV=-3.96
    {60000,16384,1600, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.64  BV=-4.05
    {60000,16384,1720, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.75  BV=-4.16
    {60000,16384,1840, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.85  BV=-4.26
    {60000,16384,1976, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.95  BV=-4.36
    {60000,16384,2104, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.04  BV=-4.45
    {69999,16384,1936, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.55
    {69999,16384,2072, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {79999,16384,1944, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=9.92  BV=-4.75
    {79999,16384,2080, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.02  BV=-4.85
    {89999,16384,1984, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=9.95  BV=-4.95
    {89999,16384,2128, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.06  BV=-5.05
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {99999,16384,2208, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.11  BV=-5.26
    {99999,16384,2368, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.21  BV=-5.36
    {99999,16384,2536, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.31  BV=-5.46
    {99999,16384,2712, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.41  BV=-5.55
    {99999,16384,2912, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.51  BV=-5.65
    {99999,16384,3120, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.61  BV=-5.75
    {99999,16384,3344, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.71  BV=-5.85
    {99999,16384,3584, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.81  BV=-5.95
    {99999,16384,3840, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.91  BV=-6.05
    {99999,16384,4096, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=11.00  BV=-6.15
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    160, //u4TotalIndex
    20, //i4StrobeTrigerBV
    97, //i4MaxBV
    -62, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {523,16384,2024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=9.98  BV=2.45
    {553,16384,2048, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=10.00  BV=2.35
    {593,16384,2048, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=10.00  BV=2.25
    {643,16384,2032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=9.99  BV=2.15
    {683,16384,2040, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=9.99  BV=2.05
    {733,16384,2040, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=9.99  BV=1.95
    {784,16384,2056, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=10.01  BV=1.84
    {844,16384,2040, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=9.99  BV=1.75
    {904,16384,2040, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=9.99  BV=1.65
    {974,16384,2032, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=9.99  BV=1.55
    {1035,16384,2056, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=10.01  BV=1.44
    {1105,16384,2048, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=10.00  BV=1.35
    {1195,16384,2040, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=9.99  BV=1.25
    {1276,16384,2048, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=10.00  BV=1.15
    {1366,16384,2048, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=10.00  BV=1.05
    {1466,16384,2048, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=10.00  BV=0.94
    {1567,16384,2048, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=10.00  BV=0.85
    {1687,16384,2048, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=10.00  BV=0.74
    {1808,16384,2040, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=9.99  BV=0.65
    {1928,16384,2048, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=10.00  BV=0.55
    {2079,16384,2040, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=9.99  BV=0.45
    {2219,16384,2048, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=10.00  BV=0.35
    {2390,16384,2040, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=9.99  BV=0.25
    {2551,16384,2048, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=10.00  BV=0.15
    {2731,16384,2048, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=10.00  BV=0.05
    {2922,16384,2048, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=10.00  BV=-0.05
    {3153,16384,2040, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=9.99  BV=-0.15
    {3374,16384,2040, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=9.99  BV=-0.25
    {3605,16384,2048, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=10.00  BV=-0.35
    {3866,16384,2040, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=9.99  BV=-0.45
    {4137,16384,2040, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=9.99  BV=-0.55
    {4458,16384,2040, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=9.99  BV=-0.65
    {4769,16384,2048, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=10.00  BV=-0.76
    {5111,16384,2040, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=9.99  BV=-0.85
    {5472,16384,2040, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=9.99  BV=-0.95
    {5854,16384,2048, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=10.00  BV=-1.05
    {6275,16384,2040, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=9.99  BV=-1.15
    {6717,16384,2048, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=10.00  BV=-1.25
    {7199,16384,2040, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=9.99  BV=-1.35
    {7761,16384,2048, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=10.00  BV=-1.46
    {8314,16384,2048, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=10.00  BV=-1.56
    {8334,16384,2184, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=10.09  BV=-1.65
    {8334,16384,2344, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=10.19  BV=-1.76
    {8334,16384,2504, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=10.29  BV=-1.85
    {8334,16384,2688, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=10.39  BV=-1.95
    {8334,16384,2880, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=10.49  BV=-2.05
    {16667,16384,1544, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.59  BV=-2.15
    {16667,16384,1648, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.69  BV=-2.25
    {16667,16384,1768, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.79  BV=-2.35
    {16667,16384,1896, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.89  BV=-2.45
    {16667,16384,2032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=9.99  BV=-2.55
    {16667,16384,2176, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.09  BV=-2.65
    {16667,16384,2336, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.19  BV=-2.75
    {16667,16384,2496, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.29  BV=-2.85
    {25000,16384,1784, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.80  BV=-2.95
    {25000,16384,1912, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.90  BV=-3.05
    {25000,16384,2048, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.00  BV=-3.15
    {25000,16384,2208, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.11  BV=-3.26
    {25000,16384,2368, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.21  BV=-3.36
    {33333,16384,1904, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=9.89  BV=-3.46
    {33333,16384,2040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=9.99  BV=-3.56
    {33333,16384,2184, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=10.09  BV=-3.65
    {41666,16384,1872, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.87  BV=-3.75
    {41666,16384,2008, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.86
    {41666,16384,2152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.96
    {50000,16384,1920, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.91  BV=-4.05
    {50000,16384,2064, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.01  BV=-4.16
    {50000,16384,2208, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.11  BV=-4.26
    {58333,16384,2024, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.98  BV=-4.35
    {58333,16384,2176, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.09  BV=-4.46
    {66666,16384,2040, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.56
    {74999,16384,1944, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=9.92  BV=-4.66
    {74999,16384,2080, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.02  BV=-4.75
    {83332,16384,2008, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=9.97  BV=-4.86
    {91666,16384,1952, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=9.93  BV=-4.95
    {91666,16384,2096, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.03  BV=-5.05
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {108332,16384,2040, 0, 0, 0},  //TV = 3.21(10790 lines)  AV=1.53  SV=9.99  BV=-5.26
    {116665,16384,2024, 0, 0, 0},  //TV = 3.10(11620 lines)  AV=1.53  SV=9.98  BV=-5.35
    {124998,16384,2024, 0, 0, 0},  //TV = 3.00(12450 lines)  AV=1.53  SV=9.98  BV=-5.45
    {133332,16384,2040, 0, 0, 0},  //TV = 2.91(13280 lines)  AV=1.53  SV=9.99  BV=-5.56
    {141665,16384,2056, 0, 0, 0},  //TV = 2.82(14110 lines)  AV=1.53  SV=10.01  BV=-5.66
    {149998,16384,2080, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=10.02  BV=-5.75
    {166664,16384,2008, 0, 0, 0},  //TV = 2.58(16600 lines)  AV=1.53  SV=9.97  BV=-5.86
    {174998,16384,2048, 0, 0, 0},  //TV = 2.51(17430 lines)  AV=1.53  SV=10.00  BV=-5.95
    {191664,16384,2000, 0, 0, 0},  //TV = 2.38(19090 lines)  AV=1.53  SV=9.97  BV=-6.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {523,16384,2024, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=9.98  BV=2.45
    {553,16384,2048, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=10.00  BV=2.35
    {593,16384,2048, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=10.00  BV=2.25
    {643,16384,2032, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=9.99  BV=2.15
    {683,16384,2040, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=9.99  BV=2.05
    {733,16384,2040, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=9.99  BV=1.95
    {784,16384,2056, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=10.01  BV=1.84
    {844,16384,2040, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=9.99  BV=1.75
    {904,16384,2040, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=9.99  BV=1.65
    {974,16384,2032, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=9.99  BV=1.55
    {1035,16384,2056, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=10.01  BV=1.44
    {1105,16384,2048, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=10.00  BV=1.35
    {1195,16384,2040, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=9.99  BV=1.25
    {1276,16384,2048, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=10.00  BV=1.15
    {1366,16384,2048, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=10.00  BV=1.05
    {1466,16384,2048, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=10.00  BV=0.94
    {1567,16384,2048, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=10.00  BV=0.85
    {1687,16384,2048, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=10.00  BV=0.74
    {1808,16384,2040, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=9.99  BV=0.65
    {1928,16384,2048, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=10.00  BV=0.55
    {2079,16384,2040, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=9.99  BV=0.45
    {2219,16384,2048, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=10.00  BV=0.35
    {2390,16384,2040, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=9.99  BV=0.25
    {2551,16384,2048, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=10.00  BV=0.15
    {2731,16384,2048, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=10.00  BV=0.05
    {2922,16384,2048, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=10.00  BV=-0.05
    {3153,16384,2040, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=9.99  BV=-0.15
    {3374,16384,2040, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=9.99  BV=-0.25
    {3605,16384,2048, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=10.00  BV=-0.35
    {3866,16384,2040, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=9.99  BV=-0.45
    {4137,16384,2040, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=9.99  BV=-0.55
    {4458,16384,2040, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=9.99  BV=-0.65
    {4769,16384,2048, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=10.00  BV=-0.76
    {5111,16384,2040, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=9.99  BV=-0.85
    {5472,16384,2040, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=9.99  BV=-0.95
    {5854,16384,2048, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=10.00  BV=-1.05
    {6275,16384,2040, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=9.99  BV=-1.15
    {6717,16384,2048, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=10.00  BV=-1.25
    {7199,16384,2040, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=9.99  BV=-1.35
    {7761,16384,2048, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=10.00  BV=-1.46
    {8314,16384,2048, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=10.00  BV=-1.56
    {8906,16384,2048, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=10.00  BV=-1.66
    {9538,16384,2048, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=10.00  BV=-1.76
    {10000,16384,2088, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.03  BV=-1.85
    {10000,16384,2240, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.13  BV=-1.95
    {10000,16384,2400, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.23  BV=-2.05
    {10000,16384,2568, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.33  BV=-2.15
    {10000,16384,2752, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.43  BV=-2.25
    {10000,16384,2952, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=10.53  BV=-2.35
    {20000,16384,1576, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.62  BV=-2.45
    {20000,16384,1688, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.72  BV=-2.55
    {20000,16384,1816, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.83  BV=-2.65
    {20000,16384,1944, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=9.92  BV=-2.75
    {20000,16384,2080, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.02  BV=-2.85
    {20000,16384,2232, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.12  BV=-2.95
    {20000,16384,2392, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.22  BV=-3.05
    {30000,16384,1704, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.73  BV=-3.14
    {30000,16384,1832, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.84  BV=-3.25
    {30000,16384,1976, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.95  BV=-3.36
    {30000,16384,2112, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.04  BV=-3.45
    {30000,16384,2264, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.14  BV=-3.55
    {40000,16384,1824, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.66
    {40000,16384,1952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.93  BV=-3.76
    {40000,16384,2096, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.86
    {40000,16384,2240, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.13  BV=-3.95
    {50000,16384,1920, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.91  BV=-4.05
    {50000,16384,2064, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.01  BV=-4.16
    {50000,16384,2208, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.11  BV=-4.26
    {60000,16384,1968, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.94  BV=-4.35
    {60000,16384,2112, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.04  BV=-4.45
    {69999,16384,1944, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=9.92  BV=-4.56
    {69999,16384,2080, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.02  BV=-4.65
    {79999,16384,1952, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=9.93  BV=-4.76
    {79999,16384,2088, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.03  BV=-4.85
    {89999,16384,1992, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=9.96  BV=-4.95
    {89999,16384,2136, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.06  BV=-5.06
    {99999,16384,2056, 0, 0, 0},  //TV = 3.32(9960 lines)  AV=1.53  SV=10.01  BV=-5.15
    {109999,16384,2008, 0, 0, 0},  //TV = 3.18(10956 lines)  AV=1.53  SV=9.97  BV=-5.26
    {119999,16384,1968, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=9.94  BV=-5.35
    {119999,16384,2112, 0, 0, 0},  //TV = 3.06(11952 lines)  AV=1.53  SV=10.04  BV=-5.45
    {129998,16384,2088, 0, 0, 0},  //TV = 2.94(12948 lines)  AV=1.53  SV=10.03  BV=-5.55
    {139998,16384,2080, 0, 0, 0},  //TV = 2.84(13944 lines)  AV=1.53  SV=10.02  BV=-5.65
    {149998,16384,2080, 0, 0, 0},  //TV = 2.74(14940 lines)  AV=1.53  SV=10.02  BV=-5.75
    {159998,16384,2088, 0, 0, 0},  //TV = 2.64(15936 lines)  AV=1.53  SV=10.03  BV=-5.85
    {179998,16384,1992, 0, 0, 0},  //TV = 2.47(17928 lines)  AV=1.53  SV=9.96  BV=-5.95
    {189997,16384,2024, 0, 0, 0},  //TV = 2.40(18924 lines)  AV=1.53  SV=9.98  BV=-6.06
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    158, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -61, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {492,16384,2160, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.08  BV=2.44
    {492,16384,2320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.18  BV=2.34
    {492,16384,2480, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.28  BV=2.24
    {492,16384,2664, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.38  BV=2.14
    {492,16384,2848, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.48  BV=2.04
    {492,16384,3056, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.58  BV=1.94
    {492,16384,3272, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.68  BV=1.84
    {492,16384,3512, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.78  BV=1.74
    {492,16384,3760, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.88  BV=1.64
    {492,16384,4032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.98  BV=1.54
    {523,16384,4056, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=10.99  BV=1.45
    {553,16384,4096, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=11.00  BV=1.35
    {593,16384,4096, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=11.00  BV=1.25
    {643,16384,4064, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=10.99  BV=1.15
    {683,16384,4088, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=11.00  BV=1.05
    {733,16384,4088, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=11.00  BV=0.95
    {784,16384,4104, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=11.00  BV=0.85
    {844,16384,4080, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=10.99  BV=0.75
    {904,16384,4088, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=11.00  BV=0.65
    {974,16384,4072, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=10.99  BV=0.54
    {1035,16384,4112, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=11.01  BV=0.44
    {1105,16384,4104, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=11.00  BV=0.35
    {1195,16384,4080, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=10.99  BV=0.25
    {1276,16384,4104, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=11.00  BV=0.14
    {1366,16384,4096, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=11.00  BV=0.05
    {1466,16384,4104, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=11.00  BV=-0.06
    {1567,16384,4096, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=11.00  BV=-0.15
    {1687,16384,4096, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=11.00  BV=-0.26
    {1808,16384,4080, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=10.99  BV=-0.35
    {1928,16384,4096, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=11.00  BV=-0.45
    {2079,16384,4088, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=11.00  BV=-0.56
    {2219,16384,4096, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=11.00  BV=-0.65
    {2390,16384,4088, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=11.00  BV=-0.76
    {2551,16384,4096, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=11.00  BV=-0.85
    {2731,16384,4096, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=11.00  BV=-0.95
    {2922,16384,4096, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=11.00  BV=-1.05
    {3153,16384,4088, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=11.00  BV=-1.16
    {3374,16384,4088, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=11.00  BV=-1.25
    {3605,16384,4096, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=11.00  BV=-1.35
    {3866,16384,4088, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=11.00  BV=-1.45
    {4137,16384,4088, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=11.00  BV=-1.55
    {4458,16384,4088, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=11.00  BV=-1.66
    {4769,16384,4096, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=11.00  BV=-1.76
    {5111,16384,4088, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=11.00  BV=-1.85
    {5472,16384,4088, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=11.00  BV=-1.95
    {5854,16384,4096, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=11.00  BV=-2.05
    {6275,16384,4088, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=11.00  BV=-2.15
    {6717,16384,4096, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=11.00  BV=-2.25
    {7199,16384,4088, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=11.00  BV=-2.35
    {7761,16384,4096, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=11.00  BV=-2.46
    {8314,16384,4088, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=11.00  BV=-2.56
    {8334,16384,4376, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=11.10  BV=-2.66
    {8334,16384,4680, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=11.19  BV=-2.75
    {8334,16384,5016, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=11.29  BV=-2.85
    {8334,16384,5376, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=11.39  BV=-2.95
    {8334,16384,5760, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=11.49  BV=-3.05
    {16667,16384,3088, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.59  BV=-3.15
    {16667,16384,3304, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.69  BV=-3.25
    {16667,16384,3544, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.79  BV=-3.35
    {16667,16384,3792, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.89  BV=-3.45
    {16667,16384,4064, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=10.99  BV=-3.55
    {16667,16384,4360, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.09  BV=-3.65
    {16667,16384,4672, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.19  BV=-3.75
    {16667,16384,5000, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.29  BV=-3.85
    {25000,16384,3568, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.80  BV=-3.95
    {25000,16384,3824, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.90  BV=-4.05
    {25000,16384,4104, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=11.00  BV=-4.15
    {25000,16384,4392, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=11.10  BV=-4.25
    {25000,16384,4744, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=11.21  BV=-4.36
    {33333,16384,3808, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=10.89  BV=-4.46
    {33333,16384,4088, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=11.00  BV=-4.56
    {33333,16384,4376, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=11.10  BV=-4.66
    {41666,16384,3752, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.87  BV=-4.76
    {41666,16384,4024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.97  BV=-4.86
    {41666,16384,4312, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=11.07  BV=-4.96
    {50000,16384,3848, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.91  BV=-5.06
    {50000,16384,4128, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.01  BV=-5.16
    {50000,16384,4416, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.11  BV=-5.26
    {58333,16384,4056, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.99  BV=-5.36
    {58333,16384,4352, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=11.09  BV=-5.46
    {66666,16384,4080, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.99  BV=-5.56
    {74999,16384,3888, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=10.92  BV=-5.66
    {74999,16384,4168, 0, 0, 0},  //TV = 3.74(7470 lines)  AV=1.53  SV=11.03  BV=-5.76
    {83332,16384,4016, 0, 0, 0},  //TV = 3.58(8300 lines)  AV=1.53  SV=10.97  BV=-5.86
    {91666,16384,3912, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=10.93  BV=-5.96
    {91666,16384,4192, 0, 0, 0},  //TV = 3.45(9130 lines)  AV=1.53  SV=11.03  BV=-6.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {492,16384,2160, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.08  BV=2.44
    {492,16384,2320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.18  BV=2.34
    {492,16384,2480, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.28  BV=2.24
    {492,16384,2664, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.38  BV=2.14
    {492,16384,2848, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.48  BV=2.04
    {492,16384,3056, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.58  BV=1.94
    {492,16384,3272, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.68  BV=1.84
    {492,16384,3512, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.78  BV=1.74
    {492,16384,3760, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.88  BV=1.64
    {492,16384,4032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.98  BV=1.54
    {523,16384,4056, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=10.99  BV=1.45
    {553,16384,4096, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=11.00  BV=1.35
    {593,16384,4096, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=11.00  BV=1.25
    {643,16384,4064, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=10.99  BV=1.15
    {683,16384,4088, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=11.00  BV=1.05
    {733,16384,4088, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=11.00  BV=0.95
    {784,16384,4104, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=11.00  BV=0.85
    {844,16384,4080, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=10.99  BV=0.75
    {904,16384,4088, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=11.00  BV=0.65
    {974,16384,4072, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=10.99  BV=0.54
    {1035,16384,4112, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=11.01  BV=0.44
    {1105,16384,4104, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=11.00  BV=0.35
    {1195,16384,4080, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=10.99  BV=0.25
    {1276,16384,4104, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=11.00  BV=0.14
    {1366,16384,4096, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=11.00  BV=0.05
    {1466,16384,4104, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=11.00  BV=-0.06
    {1567,16384,4096, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=11.00  BV=-0.15
    {1687,16384,4096, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=11.00  BV=-0.26
    {1808,16384,4080, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=10.99  BV=-0.35
    {1928,16384,4096, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=11.00  BV=-0.45
    {2079,16384,4088, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=11.00  BV=-0.56
    {2219,16384,4096, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=11.00  BV=-0.65
    {2390,16384,4088, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=11.00  BV=-0.76
    {2551,16384,4096, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=11.00  BV=-0.85
    {2731,16384,4096, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=11.00  BV=-0.95
    {2922,16384,4096, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=11.00  BV=-1.05
    {3153,16384,4088, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=11.00  BV=-1.16
    {3374,16384,4088, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=11.00  BV=-1.25
    {3605,16384,4096, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=11.00  BV=-1.35
    {3866,16384,4088, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=11.00  BV=-1.45
    {4137,16384,4088, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=11.00  BV=-1.55
    {4458,16384,4088, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=11.00  BV=-1.66
    {4769,16384,4096, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=11.00  BV=-1.76
    {5111,16384,4088, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=11.00  BV=-1.85
    {5472,16384,4088, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=11.00  BV=-1.95
    {5854,16384,4096, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=11.00  BV=-2.05
    {6275,16384,4088, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=11.00  BV=-2.15
    {6717,16384,4096, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=11.00  BV=-2.25
    {7199,16384,4088, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=11.00  BV=-2.35
    {7761,16384,4096, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=11.00  BV=-2.46
    {8314,16384,4088, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=11.00  BV=-2.56
    {8906,16384,4088, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=11.00  BV=-2.66
    {9538,16384,4096, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=11.00  BV=-2.76
    {10000,16384,4184, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.03  BV=-2.86
    {10000,16384,4480, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.13  BV=-2.95
    {10000,16384,4800, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.23  BV=-3.05
    {10000,16384,5144, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.33  BV=-3.15
    {10000,16384,5512, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.43  BV=-3.25
    {10000,16384,5904, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=11.53  BV=-3.35
    {20000,16384,3160, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.63  BV=-3.45
    {20000,16384,3384, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.72  BV=-3.55
    {20000,16384,3632, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.83  BV=-3.65
    {20000,16384,3888, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=10.92  BV=-3.75
    {20000,16384,4168, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.03  BV=-3.85
    {20000,16384,4464, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.12  BV=-3.95
    {20000,16384,4784, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.22  BV=-4.05
    {30000,16384,3416, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.74  BV=-4.15
    {30000,16384,3664, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.84  BV=-4.25
    {30000,16384,3952, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.95  BV=-4.36
    {30000,16384,4232, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=11.05  BV=-4.46
    {30000,16384,4536, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=11.15  BV=-4.56
    {40000,16384,3648, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.83  BV=-4.66
    {40000,16384,3912, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.93  BV=-4.76
    {40000,16384,4192, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.03  BV=-4.86
    {40000,16384,4488, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.13  BV=-4.96
    {50000,16384,3848, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.91  BV=-5.06
    {50000,16384,4128, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.01  BV=-5.16
    {50000,16384,4416, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.11  BV=-5.26
    {60000,16384,3944, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.95  BV=-5.36
    {60000,16384,4232, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.05  BV=-5.46
    {69999,16384,3888, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.92  BV=-5.56
    {69999,16384,4168, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=11.03  BV=-5.66
    {79999,16384,3904, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=10.93  BV=-5.76
    {79999,16384,4184, 0, 0, 0},  //TV = 3.64(7968 lines)  AV=1.53  SV=11.03  BV=-5.86
    {89999,16384,3984, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=10.96  BV=-5.95
    {89999,16384,4272, 0, 0, 0},  //TV = 3.47(8964 lines)  AV=1.53  SV=11.06  BV=-6.06
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    158, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -61, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {492,16384,2160, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.08  BV=2.44
    {492,16384,2320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.18  BV=2.34
    {492,16384,2480, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.28  BV=2.24
    {492,16384,2664, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.38  BV=2.14
    {492,16384,2848, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.48  BV=2.04
    {492,16384,3056, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.58  BV=1.94
    {492,16384,3272, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.68  BV=1.84
    {492,16384,3512, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.78  BV=1.74
    {492,16384,3760, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.88  BV=1.64
    {492,16384,4032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.98  BV=1.54
    {492,16384,4320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.08  BV=1.44
    {492,16384,4632, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.18  BV=1.34
    {492,16384,4960, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.28  BV=1.24
    {492,16384,5320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.38  BV=1.14
    {492,16384,5704, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.48  BV=1.04
    {492,16384,6112, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.58  BV=0.94
    {492,16384,6552, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.68  BV=0.84
    {492,16384,7016, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.78  BV=0.74
    {492,16384,7520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.88  BV=0.64
    {492,16384,8064, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.98  BV=0.54
    {523,16384,8112, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=11.99  BV=0.45
    {553,16384,8200, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=12.00  BV=0.35
    {593,16384,8200, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=12.00  BV=0.25
    {643,16384,8128, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=11.99  BV=0.15
    {683,16384,8176, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=12.00  BV=0.05
    {733,16384,8176, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=12.00  BV=-0.05
    {784,16384,8216, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=12.00  BV=-0.16
    {844,16384,8168, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=12.00  BV=-0.25
    {904,16384,8176, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=12.00  BV=-0.35
    {974,16384,8144, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=11.99  BV=-0.46
    {1035,16384,8216, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=12.00  BV=-0.56
    {1105,16384,8216, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=12.00  BV=-0.65
    {1195,16384,8160, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=11.99  BV=-0.75
    {1276,16384,8208, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=12.00  BV=-0.86
    {1366,16384,8192, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=12.00  BV=-0.95
    {1466,16384,8208, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=12.00  BV=-1.06
    {1567,16384,8200, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=12.00  BV=-1.15
    {1687,16384,8192, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=12.00  BV=-1.26
    {1808,16384,8168, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=12.00  BV=-1.35
    {1928,16384,8192, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=12.00  BV=-1.45
    {2079,16384,8176, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=12.00  BV=-1.56
    {2219,16384,8192, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=12.00  BV=-1.65
    {2390,16384,8184, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=12.00  BV=-1.76
    {2551,16384,8200, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=12.00  BV=-1.86
    {2731,16384,8192, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=12.00  BV=-1.95
    {2922,16384,8200, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=12.00  BV=-2.05
    {3153,16384,8184, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=12.00  BV=-2.16
    {3374,16384,8184, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=12.00  BV=-2.26
    {3605,16384,8192, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=12.00  BV=-2.35
    {3866,16384,8176, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=12.00  BV=-2.45
    {4137,16384,8184, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=12.00  BV=-2.55
    {4458,16384,8184, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=12.00  BV=-2.66
    {4769,16384,8192, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=12.00  BV=-2.76
    {5111,16384,8184, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=12.00  BV=-2.86
    {5472,16384,8184, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=12.00  BV=-2.95
    {5854,16384,8192, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=12.00  BV=-3.05
    {6275,16384,8184, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=12.00  BV=-3.15
    {6717,16384,8192, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=12.00  BV=-3.25
    {7199,16384,8184, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=12.00  BV=-3.35
    {7761,16384,8192, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=12.00  BV=-3.46
    {8314,16384,8184, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=12.00  BV=-3.56
    {8334,16384,8752, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=12.10  BV=-3.66
    {8334,16384,9368, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=12.19  BV=-3.76
    {8334,16384,10040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=12.29  BV=-3.86
    {8334,16384,10760, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=12.39  BV=-3.96
    {8334,16384,11528, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=12.49  BV=-4.06
    {16667,16384,6176, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.59  BV=-4.15
    {16667,16384,6616, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.69  BV=-4.25
    {16667,16384,7088, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.79  BV=-4.35
    {16667,16384,7592, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.89  BV=-4.45
    {16667,16384,8136, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=11.99  BV=-4.55
    {16667,16384,8720, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=12.09  BV=-4.65
    {16667,16384,9336, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=12.19  BV=-4.75
    {16667,16384,10008, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=12.29  BV=-4.85
    {25000,16384,7144, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=11.80  BV=-4.95
    {25000,16384,7656, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=11.90  BV=-5.05
    {25000,16384,8208, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=12.00  BV=-5.15
    {25000,16384,8792, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=12.10  BV=-5.25
    {25000,16384,9488, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=12.21  BV=-5.36
    {33333,16384,7624, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=11.90  BV=-5.46
    {33333,16384,8176, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=12.00  BV=-5.56
    {33333,16384,8760, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=12.10  BV=-5.66
    {41666,16384,7512, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=11.87  BV=-5.76
    {41666,16384,8048, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=11.97  BV=-5.86
    {41666,16384,8624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=12.07  BV=-5.96
    {50000,16384,7696, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.91  BV=-6.06
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {492,1216,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.27  BV=7.25
    {492,1312,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.37  BV=7.15
    {492,1408,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.47  BV=7.05
    {492,1504,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.58  BV=6.94
    {492,1600,1040, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.67  BV=6.85
    {492,1728,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.77  BV=6.75
    {492,1856,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.87  BV=6.65
    {492,1984,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.97  BV=6.55
    {492,2144,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.07  BV=6.45
    {492,2304,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.17  BV=6.35
    {492,2464,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.27  BV=6.25
    {492,2624,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.37  BV=6.15
    {492,2816,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.47  BV=6.05
    {492,3040,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.57  BV=5.95
    {492,3264,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.67  BV=5.85
    {492,3488,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.77  BV=5.75
    {492,3744,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.87  BV=5.65
    {492,4000,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=6.97  BV=5.55
    {492,4288,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.07  BV=5.45
    {492,4608,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.17  BV=5.35
    {492,4928,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.28  BV=5.24
    {492,5312,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.38  BV=5.15
    {492,5632,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.47  BV=5.05
    {492,6080,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.57  BV=4.95
    {492,6464,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.67  BV=4.85
    {492,6976,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.77  BV=4.75
    {492,7424,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.87  BV=4.65
    {492,8064,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=7.98  BV=4.54
    {492,8576,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.08  BV=4.44
    {492,9216,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.17  BV=4.35
    {492,9856,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.27  BV=4.25
    {492,10624,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.38  BV=4.15
    {492,11264,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.47  BV=4.05
    {492,12160,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.57  BV=3.95
    {492,13056,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.67  BV=3.85
    {492,13824,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.77  BV=3.75
    {492,14848,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.87  BV=3.65
    {492,15872,1032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=8.97  BV=3.55
    {492,16384,1072, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.07  BV=3.45
    {492,16384,1152, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.17  BV=3.35
    {492,16384,1232, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.27  BV=3.25
    {492,16384,1320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.37  BV=3.15
    {492,16384,1416, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.47  BV=3.05
    {492,16384,1520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.57  BV=2.95
    {492,16384,1624, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.67  BV=2.85
    {492,16384,1744, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.77  BV=2.75
    {492,16384,1872, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.87  BV=2.65
    {492,16384,2000, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=9.97  BV=2.55
    {492,16384,2160, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.08  BV=2.44
    {492,16384,2320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.18  BV=2.34
    {492,16384,2480, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.28  BV=2.24
    {492,16384,2664, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.38  BV=2.14
    {492,16384,2848, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.48  BV=2.04
    {492,16384,3056, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.58  BV=1.94
    {492,16384,3272, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.68  BV=1.84
    {492,16384,3512, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.78  BV=1.74
    {492,16384,3760, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.88  BV=1.64
    {492,16384,4032, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=10.98  BV=1.54
    {492,16384,4320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.08  BV=1.44
    {492,16384,4632, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.18  BV=1.34
    {492,16384,4960, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.28  BV=1.24
    {492,16384,5320, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.38  BV=1.14
    {492,16384,5704, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.48  BV=1.04
    {492,16384,6112, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.58  BV=0.94
    {492,16384,6552, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.68  BV=0.84
    {492,16384,7016, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.78  BV=0.74
    {492,16384,7520, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.88  BV=0.64
    {492,16384,8064, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=11.98  BV=0.54
    {523,16384,8112, 0, 0, 0},  //TV = 10.90(52 lines)  AV=1.53  SV=11.99  BV=0.45
    {553,16384,8200, 0, 0, 0},  //TV = 10.82(55 lines)  AV=1.53  SV=12.00  BV=0.35
    {593,16384,8200, 0, 0, 0},  //TV = 10.72(59 lines)  AV=1.53  SV=12.00  BV=0.25
    {643,16384,8128, 0, 0, 0},  //TV = 10.60(64 lines)  AV=1.53  SV=11.99  BV=0.15
    {683,16384,8176, 0, 0, 0},  //TV = 10.52(68 lines)  AV=1.53  SV=12.00  BV=0.05
    {733,16384,8176, 0, 0, 0},  //TV = 10.41(73 lines)  AV=1.53  SV=12.00  BV=-0.05
    {784,16384,8216, 0, 0, 0},  //TV = 10.32(78 lines)  AV=1.53  SV=12.00  BV=-0.16
    {844,16384,8168, 0, 0, 0},  //TV = 10.21(84 lines)  AV=1.53  SV=12.00  BV=-0.25
    {904,16384,8176, 0, 0, 0},  //TV = 10.11(90 lines)  AV=1.53  SV=12.00  BV=-0.35
    {974,16384,8144, 0, 0, 0},  //TV = 10.00(97 lines)  AV=1.53  SV=11.99  BV=-0.46
    {1035,16384,8216, 0, 0, 0},  //TV = 9.92(103 lines)  AV=1.53  SV=12.00  BV=-0.56
    {1105,16384,8216, 0, 0, 0},  //TV = 9.82(110 lines)  AV=1.53  SV=12.00  BV=-0.65
    {1195,16384,8160, 0, 0, 0},  //TV = 9.71(119 lines)  AV=1.53  SV=11.99  BV=-0.75
    {1276,16384,8208, 0, 0, 0},  //TV = 9.61(127 lines)  AV=1.53  SV=12.00  BV=-0.86
    {1366,16384,8192, 0, 0, 0},  //TV = 9.52(136 lines)  AV=1.53  SV=12.00  BV=-0.95
    {1466,16384,8208, 0, 0, 0},  //TV = 9.41(146 lines)  AV=1.53  SV=12.00  BV=-1.06
    {1567,16384,8200, 0, 0, 0},  //TV = 9.32(156 lines)  AV=1.53  SV=12.00  BV=-1.15
    {1687,16384,8192, 0, 0, 0},  //TV = 9.21(168 lines)  AV=1.53  SV=12.00  BV=-1.26
    {1808,16384,8168, 0, 0, 0},  //TV = 9.11(180 lines)  AV=1.53  SV=12.00  BV=-1.35
    {1928,16384,8192, 0, 0, 0},  //TV = 9.02(192 lines)  AV=1.53  SV=12.00  BV=-1.45
    {2079,16384,8176, 0, 0, 0},  //TV = 8.91(207 lines)  AV=1.53  SV=12.00  BV=-1.56
    {2219,16384,8192, 0, 0, 0},  //TV = 8.82(221 lines)  AV=1.53  SV=12.00  BV=-1.65
    {2390,16384,8184, 0, 0, 0},  //TV = 8.71(238 lines)  AV=1.53  SV=12.00  BV=-1.76
    {2551,16384,8200, 0, 0, 0},  //TV = 8.61(254 lines)  AV=1.53  SV=12.00  BV=-1.86
    {2731,16384,8192, 0, 0, 0},  //TV = 8.52(272 lines)  AV=1.53  SV=12.00  BV=-1.95
    {2922,16384,8200, 0, 0, 0},  //TV = 8.42(291 lines)  AV=1.53  SV=12.00  BV=-2.05
    {3153,16384,8184, 0, 0, 0},  //TV = 8.31(314 lines)  AV=1.53  SV=12.00  BV=-2.16
    {3374,16384,8184, 0, 0, 0},  //TV = 8.21(336 lines)  AV=1.53  SV=12.00  BV=-2.26
    {3605,16384,8192, 0, 0, 0},  //TV = 8.12(359 lines)  AV=1.53  SV=12.00  BV=-2.35
    {3866,16384,8176, 0, 0, 0},  //TV = 8.01(385 lines)  AV=1.53  SV=12.00  BV=-2.45
    {4137,16384,8184, 0, 0, 0},  //TV = 7.92(412 lines)  AV=1.53  SV=12.00  BV=-2.55
    {4458,16384,8184, 0, 0, 0},  //TV = 7.81(444 lines)  AV=1.53  SV=12.00  BV=-2.66
    {4769,16384,8192, 0, 0, 0},  //TV = 7.71(475 lines)  AV=1.53  SV=12.00  BV=-2.76
    {5111,16384,8184, 0, 0, 0},  //TV = 7.61(509 lines)  AV=1.53  SV=12.00  BV=-2.86
    {5472,16384,8184, 0, 0, 0},  //TV = 7.51(545 lines)  AV=1.53  SV=12.00  BV=-2.95
    {5854,16384,8192, 0, 0, 0},  //TV = 7.42(583 lines)  AV=1.53  SV=12.00  BV=-3.05
    {6275,16384,8184, 0, 0, 0},  //TV = 7.32(625 lines)  AV=1.53  SV=12.00  BV=-3.15
    {6717,16384,8192, 0, 0, 0},  //TV = 7.22(669 lines)  AV=1.53  SV=12.00  BV=-3.25
    {7199,16384,8184, 0, 0, 0},  //TV = 7.12(717 lines)  AV=1.53  SV=12.00  BV=-3.35
    {7761,16384,8192, 0, 0, 0},  //TV = 7.01(773 lines)  AV=1.53  SV=12.00  BV=-3.46
    {8314,16384,8184, 0, 0, 0},  //TV = 6.91(828 lines)  AV=1.53  SV=12.00  BV=-3.56
    {8906,16384,8184, 0, 0, 0},  //TV = 6.81(887 lines)  AV=1.53  SV=12.00  BV=-3.66
    {9538,16384,8192, 0, 0, 0},  //TV = 6.71(950 lines)  AV=1.53  SV=12.00  BV=-3.76
    {10000,16384,8368, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.03  BV=-3.86
    {10000,16384,8968, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.13  BV=-3.96
    {10000,16384,9608, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.23  BV=-4.06
    {10000,16384,10288, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.33  BV=-4.15
    {10000,16384,11024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.43  BV=-4.25
    {10000,16384,11816, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=12.53  BV=-4.35
    {20000,16384,6328, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.63  BV=-4.45
    {20000,16384,6776, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.73  BV=-4.55
    {20000,16384,7264, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.83  BV=-4.65
    {20000,16384,7784, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=11.93  BV=-4.75
    {20000,16384,8336, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=12.03  BV=-4.85
    {20000,16384,8936, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=12.13  BV=-4.95
    {20000,16384,9576, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=12.23  BV=-5.05
    {30000,16384,6840, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=11.74  BV=-5.15
    {30000,16384,7328, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=11.84  BV=-5.25
    {30000,16384,7912, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=11.95  BV=-5.36
    {30000,16384,8472, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=12.05  BV=-5.46
    {30000,16384,9080, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=12.15  BV=-5.56
    {40000,16384,7296, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.83  BV=-5.66
    {40000,16384,7824, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=11.93  BV=-5.76
    {40000,16384,8384, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=12.03  BV=-5.86
    {40000,16384,8984, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=12.13  BV=-5.96
    {50000,16384,7696, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=11.91  BV=-6.06
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    158, //u4TotalIndex
    20, //i4StrobeTrigerBV
    96, //i4MaxBV
    -61, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {16668,1888,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.88  BV=1.56
    {16668,2016,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.99  BV=1.45
    {16667,2176,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.09  BV=1.35
    {16667,2304,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.18  BV=1.26
    {16667,2496,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=6.29  BV=1.15
    {25000,1792,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.81  BV=1.05
    {25000,1920,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.91  BV=0.95
    {25000,2048,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.01  BV=0.84
    {25000,2176,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.10  BV=0.75
    {25000,2336,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.20  BV=0.65
    {25000,2528,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.30  BV=0.55
    {25000,2688,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.40  BV=0.45
    {25000,2880,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.50  BV=0.35
    {25000,3104,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.60  BV=0.25
    {25000,3328,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.70  BV=0.15
    {25000,3552,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.81  BV=0.05
    {25000,3808,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.91  BV=-0.05
    {25000,4096,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.01  BV=-0.16
    {25000,4352,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.10  BV=-0.25
    {25000,4672,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.20  BV=-0.35
    {25000,5056,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.30  BV=-0.45
    {25000,5376,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.40  BV=-0.55
    {25000,5760,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.50  BV=-0.65
    {25000,6208,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.60  BV=-0.75
    {25000,6656,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.70  BV=-0.85
    {25000,7104,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.79  BV=-0.94
    {25000,7680,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.91  BV=-1.05
    {25000,8192,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.01  BV=-1.16
    {25000,8832,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.11  BV=-1.26
    {25000,9344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.20  BV=-1.35
    {25000,10112,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.30  BV=-1.45
    {25000,10752,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.40  BV=-1.55
    {25000,11520,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.50  BV=-1.65
    {25000,12288,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.61  BV=-1.75
    {25000,13312,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.70  BV=-1.85
    {25000,14080,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.80  BV=-1.95
    {25000,15104,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=8.91  BV=-2.05
    {25000,16384,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.00  BV=-2.15
    {25000,16384,1096, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.10  BV=-2.25
    {25000,16384,1176, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.20  BV=-2.35
    {25000,16384,1264, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.30  BV=-2.45
    {25000,16384,1352, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.40  BV=-2.55
    {25000,16384,1448, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.50  BV=-2.65
    {25000,16384,1552, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.60  BV=-2.75
    {25000,16384,1664, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.70  BV=-2.85
    {25000,16384,1792, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.81  BV=-2.95
    {25000,16384,1920, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=9.91  BV=-3.05
    {25000,16384,2064, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.01  BV=-3.16
    {25000,16384,2208, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.11  BV=-3.26
    {25000,16384,2368, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.21  BV=-3.36
    {25000,16384,2536, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.31  BV=-3.46
    {25000,16384,2720, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.41  BV=-3.56
    {25000,16384,2880, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=10.49  BV=-3.64
    {25000,16384,2880, 0, 0, 0},  /* TV = 5.32(2490 lines)  AV=1.53  SV=10.49  BV=-3.64 */
    {25000,16384,2880, 0, 0, 0},  /* TV = 5.32(2490 lines)  AV=1.53  SV=10.49  BV=-3.64 */
    {25000,16384,2880, 0, 0, 0},  /* TV = 5.32(2490 lines)  AV=1.53  SV=10.49  BV=-3.64 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {10000,2400,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.23  BV=1.95
    {10000,2560,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.32  BV=1.85
    {10000,2720,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.42  BV=1.75
    {10000,2944,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.52  BV=1.65
    {10000,3136,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.61  BV=1.56
    {10000,3392,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.73  BV=1.45
    {20000,1792,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.82  BV=1.36
    {20000,1952,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.93  BV=1.24
    {20000,2080,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.02  BV=1.15
    {20000,2240,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.13  BV=1.05
    {20000,2400,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.23  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2080,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.03  BV=0.56
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.64  BV=-0.05
    {30000,3392,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3680,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.85  BV=-0.26
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5504,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.63  BV=-1.04
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7360,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.85  BV=-1.26
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12544,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {30000,14592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.83  BV=-2.24
    {30000,15616,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.93  BV=-2.34
    {30000,16384,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.03  BV=-2.44
    {30000,16384,1128, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.14  BV=-2.55
    {30000,16384,1208, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.24  BV=-2.65
    {30000,16384,1296, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.34  BV=-2.75
    {30000,16384,1392, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.44  BV=-2.85
    {30000,16384,1496, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.55  BV=-2.96
    {30000,16384,1600, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.64  BV=-3.05
    {30000,16384,1720, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.75  BV=-3.16
    {30000,16384,1840, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.85  BV=-3.26
    {30000,16384,1976, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.95  BV=-3.36
    {30000,16384,2112, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.04  BV=-3.45
    {30000,16384,2264, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.14  BV=-3.55
    {30000,16384,2432, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.25  BV=-3.66
    {30000,16384,2600, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.34  BV=-3.75
    {30000,16384,2792, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=10.45  BV=-3.86
    {30000,16384,2880, 0, 0, 0},  /* TV = 5.06(2988 lines)  AV=1.53  SV=10.49  BV=-3.90 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -39, //i4MinBV
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8335,1152,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.18  BV=3.26
    {8335,1248,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.29  BV=3.15
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.69  BV=2.74
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.88  BV=2.56
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {16668,1152,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.18  BV=2.26
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {25001,1152,1048, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.20  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {25001,1664,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.70  BV=1.15
    {25001,1792,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.81  BV=1.05
    {25001,1888,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.91  BV=0.95
    {25001,2048,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.00  BV=0.85
    {25001,2176,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.10  BV=0.75
    {25001,2336,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.20  BV=0.65
    {25001,2528,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.30  BV=0.55
    {25001,2688,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.40  BV=0.45
    {25001,2912,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.51  BV=0.35
    {25001,3104,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.60  BV=0.25
    {25001,3328,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.70  BV=0.15
    {25001,3552,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.79  BV=0.06
    {25001,3840,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=6.91  BV=-0.05
    {25001,4096,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.01  BV=-0.16
    {25001,4352,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.10  BV=-0.25
    {25001,4672,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.20  BV=-0.35
    {25001,5056,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.30  BV=-0.45
    {25000,5440,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.41  BV=-0.56
    {25000,5824,1024, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=7.51  BV=-0.65
    {33333,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33333,4992,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.30  BV=-0.86
    {33333,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33333,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33333,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33333,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33333,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33333,7552,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33333,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33333,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33333,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33333,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33333,10624,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33333,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {33333,14080,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.78  BV=-2.34
    {33333,15104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.88  BV=-2.44
    {33333,16128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.98  BV=-2.54
    {33333,16384,1088, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=9.09  BV=-2.65
    {33333,16384,1168, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=9.19  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.16  BV=-3.04
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1408, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.46  BV=-3.34
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1632, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.56
    {50000,16384,1456, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.51  BV=-3.65
    {50000,16384,1560, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.61  BV=-3.75
    {58333,16384,1432, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.48  BV=-3.85
    {58333,16384,1536, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=9.58  BV=-3.95
    {66666,16384,1440, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.49  BV=-4.05
    {66666,16384,1536, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.58  BV=-4.15
    {66666,16384,1648, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.69  BV=-4.25
    {66666,16384,1768, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.79  BV=-4.35
    {66666,16384,1896, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.89  BV=-4.45
    {66666,16384,2032, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=9.99  BV=-4.55
    {66666,16384,2176, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.09  BV=-4.65
    {66666,16384,2336, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.19  BV=-4.75
    {66666,16384,2504, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.29  BV=-4.85
    {66666,16384,2680, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.39  BV=-4.95
    {66666,16384,2872, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {66666,16384,3080, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.59  BV=-5.15
    {66666,16384,3296, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.69  BV=-5.25
    {66666,16384,3536, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.79  BV=-5.35
    {66666,16384,3792, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.89  BV=-5.45
    {66666,16384,4064, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.99  BV=-5.55
    {66666,16384,4352, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=11.09  BV=-5.65
    {66666,16384,4664, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=11.19  BV=-5.75
    {66666,16384,5000, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=11.29  BV=-5.85
    {66666,16384,5360, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=11.39  BV=-5.95
    {66666,16384,5632, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=11.46  BV=-6.02
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1216,1048, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.28  BV=9.67
    {101,1152,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.17  BV=9.63 */
    {101,1216,1024, 0, 0, 0},  //TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56
    {111,1184,1048, 0, 0, 0},  /* TV = 13.14(11 lines)  AV=1.53  SV=5.24  BV=9.43 */
    {121,1184,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.21  BV=9.33
    {131,1152,1032, 0, 0, 0},  //TV = 12.90(13 lines)  AV=1.53  SV=5.18  BV=9.25
    {141,1184,1024, 0, 0, 0},  /* TV = 12.79(14 lines)  AV=1.53  SV=5.21  BV=9.11 */
    {151,1152,1024, 0, 0, 0},  /* TV = 12.69(15 lines)  AV=1.53  SV=5.17  BV=9.05 */
    {161,1152,1032, 0, 0, 0},  //TV = 12.60(16 lines)  AV=1.53  SV=5.18  BV=8.95
    {171,1184,1024, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.21  BV=8.84
    {191,1136,1024, 0, 0, 0},  //TV = 12.35(19 lines)  AV=1.53  SV=5.15  BV=8.74
    {201,1136,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.16  BV=8.65
    {211,1152,1040, 0, 0, 0},  //TV = 12.21(21 lines)  AV=1.53  SV=5.19  BV=8.55
    {231,1136,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.16  BV=8.45
    {251,1136,1024, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.15  BV=8.34
    {262,1152,1024, 0, 0, 0},  //TV = 11.90(26 lines)  AV=1.53  SV=5.17  BV=8.26
    {282,1152,1024, 0, 0, 0},  //TV = 11.79(28 lines)  AV=1.53  SV=5.17  BV=8.15
    {302,1152,1024, 0, 0, 0},  //TV = 11.69(30 lines)  AV=1.53  SV=5.17  BV=8.05
    {322,1152,1032, 0, 0, 0},  //TV = 11.60(32 lines)  AV=1.53  SV=5.18  BV=7.95
    {352,1136,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.15  BV=7.85
    {372,1152,1024, 0, 0, 0},  //TV = 11.39(37 lines)  AV=1.53  SV=5.17  BV=7.75
    {402,1136,1032, 0, 0, 0},  //TV = 11.28(40 lines)  AV=1.53  SV=5.16  BV=7.65
    {432,1136,1024, 0, 0, 0},  //TV = 11.18(43 lines)  AV=1.53  SV=5.15  BV=7.56
    {462,1136,1032, 0, 0, 0},  //TV = 11.08(46 lines)  AV=1.53  SV=5.16  BV=7.45
    {492,1152,1024, 0, 0, 0},  //TV = 10.99(49 lines)  AV=1.53  SV=5.17  BV=7.35
    {533,1136,1024, 0, 0, 0},  //TV = 10.87(53 lines)  AV=1.53  SV=5.15  BV=7.25
    {573,1136,1024, 0, 0, 0},  //TV = 10.77(57 lines)  AV=1.53  SV=5.15  BV=7.15
    {613,1136,1024, 0, 0, 0},  //TV = 10.67(61 lines)  AV=1.53  SV=5.15  BV=7.05
    {653,1136,1032, 0, 0, 0},  //TV = 10.58(65 lines)  AV=1.53  SV=5.16  BV=6.95
    {703,1136,1024, 0, 0, 0},  //TV = 10.47(70 lines)  AV=1.53  SV=5.15  BV=6.86
    {753,1136,1024, 0, 0, 0},  //TV = 10.38(75 lines)  AV=1.53  SV=5.15  BV=6.76
    {814,1136,1024, 0, 0, 0},  //TV = 10.26(81 lines)  AV=1.53  SV=5.15  BV=6.64
    {864,1136,1024, 0, 0, 0},  //TV = 10.18(86 lines)  AV=1.53  SV=5.15  BV=6.56
    {934,1136,1024, 0, 0, 0},  //TV = 10.06(93 lines)  AV=1.53  SV=5.15  BV=6.45
    {994,1136,1024, 0, 0, 0},  //TV = 9.97(99 lines)  AV=1.53  SV=5.15  BV=6.36
    {1065,1136,1024, 0, 0, 0},  //TV = 9.87(106 lines)  AV=1.53  SV=5.15  BV=6.26
    {1155,1136,1024, 0, 0, 0},  //TV = 9.76(115 lines)  AV=1.53  SV=5.15  BV=6.14
    {1235,1136,1024, 0, 0, 0},  //TV = 9.66(123 lines)  AV=1.53  SV=5.15  BV=6.04
    {1326,1136,1024, 0, 0, 0},  //TV = 9.56(132 lines)  AV=1.53  SV=5.15  BV=5.94
    {1416,1136,1024, 0, 0, 0},  //TV = 9.46(141 lines)  AV=1.53  SV=5.15  BV=5.85
    {1506,1136,1024, 0, 0, 0},  //TV = 9.38(150 lines)  AV=1.53  SV=5.15  BV=5.76
    {1627,1136,1024, 0, 0, 0},  //TV = 9.26(162 lines)  AV=1.53  SV=5.15  BV=5.64
    {1747,1136,1024, 0, 0, 0},  //TV = 9.16(174 lines)  AV=1.53  SV=5.15  BV=5.54
    {1868,1136,1024, 0, 0, 0},  //TV = 9.06(186 lines)  AV=1.53  SV=5.15  BV=5.45
    {1998,1136,1024, 0, 0, 0},  //TV = 8.97(199 lines)  AV=1.53  SV=5.15  BV=5.35
    {2149,1136,1024, 0, 0, 0},  //TV = 8.86(214 lines)  AV=1.53  SV=5.15  BV=5.24
    {2300,1136,1024, 0, 0, 0},  //TV = 8.76(229 lines)  AV=1.53  SV=5.15  BV=5.15
    {2460,1136,1024, 0, 0, 0},  //TV = 8.67(245 lines)  AV=1.53  SV=5.15  BV=5.05
    {2651,1136,1024, 0, 0, 0},  //TV = 8.56(264 lines)  AV=1.53  SV=5.15  BV=4.94
    {2832,1136,1024, 0, 0, 0},  //TV = 8.46(282 lines)  AV=1.53  SV=5.15  BV=4.85
    {3033,1136,1024, 0, 0, 0},  //TV = 8.37(302 lines)  AV=1.53  SV=5.15  BV=4.75
    {3243,1136,1024, 0, 0, 0},  //TV = 8.27(323 lines)  AV=1.53  SV=5.15  BV=4.65
    {3494,1136,1024, 0, 0, 0},  //TV = 8.16(348 lines)  AV=1.53  SV=5.15  BV=4.54
    {3745,1136,1024, 0, 0, 0},  //TV = 8.06(373 lines)  AV=1.53  SV=5.15  BV=4.44
    {4006,1136,1024, 0, 0, 0},  //TV = 7.96(399 lines)  AV=1.53  SV=5.15  BV=4.34
    {4288,1136,1024, 0, 0, 0},  //TV = 7.87(427 lines)  AV=1.53  SV=5.15  BV=4.25
    {4599,1136,1024, 0, 0, 0},  //TV = 7.76(458 lines)  AV=1.53  SV=5.15  BV=4.15
    {4920,1136,1024, 0, 0, 0},  //TV = 7.67(490 lines)  AV=1.53  SV=5.15  BV=4.05
    {5271,1136,1024, 0, 0, 0},  //TV = 7.57(525 lines)  AV=1.53  SV=5.15  BV=3.95
    {5683,1136,1024, 0, 0, 0},  //TV = 7.46(566 lines)  AV=1.53  SV=5.15  BV=3.84
    {6085,1136,1024, 0, 0, 0},  //TV = 7.36(606 lines)  AV=1.53  SV=5.15  BV=3.74
    {6516,1136,1024, 0, 0, 0},  //TV = 7.26(649 lines)  AV=1.53  SV=5.15  BV=3.64
    {6978,1136,1024, 0, 0, 0},  //TV = 7.16(695 lines)  AV=1.53  SV=5.15  BV=3.54
    {7470,1136,1024, 0, 0, 0},  //TV = 7.06(744 lines)  AV=1.53  SV=5.15  BV=3.45
    {8002,1136,1024, 0, 0, 0},  //TV = 6.97(797 lines)  AV=1.53  SV=5.15  BV=3.35
    {8575,1136,1024, 0, 0, 0},  //TV = 6.87(854 lines)  AV=1.53  SV=5.15  BV=3.25
    {9187,1136,1024, 0, 0, 0},  //TV = 6.77(915 lines)  AV=1.53  SV=5.15  BV=3.15
    {9840,1136,1024, 0, 0, 0},  //TV = 6.67(980 lines)  AV=1.53  SV=5.15  BV=3.05
    {10000,1184,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.22  BV=2.95
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {20000,1792,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.82  BV=1.36
    {20000,1952,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.93  BV=1.24
    {20000,2080,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.02  BV=1.15
    {20000,2240,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.13  BV=1.05
    {20000,2400,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.23  BV=0.95
    {20000,2560,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.32  BV=0.85
    {20000,2720,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.42  BV=0.75
    {20000,2944,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.52  BV=0.65
    {20000,3136,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.63  BV=0.55
    {20000,3392,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.73  BV=0.45
    {20000,3616,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.83  BV=0.34
    {20000,3872,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=6.93  BV=0.24
    {20000,4160,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.02  BV=0.15
    {20000,4416,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.12  BV=0.06
    {20000,4800,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.23  BV=-0.05
    {20000,5120,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.33  BV=-0.16
    {20000,5504,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.43  BV=-0.25
    {20000,5888,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.52  BV=-0.35
    {20000,6272,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=7.63  BV=-0.45
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7360,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.85  BV=-1.26
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12544,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {30000,14592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.83  BV=-2.24
    {30000,15616,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.93  BV=-2.34
    {30000,16384,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.03  BV=-2.44
    {30000,16384,1136, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.15  BV=-2.56
    {30000,16384,1216, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=9.25  BV=-2.66
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1048, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.03  BV=-2.86
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1192, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.22  BV=-3.04
    {40000,16384,1280, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.32  BV=-3.15
    {40000,16384,1368, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.42  BV=-3.24
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {50000,16384,1456, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.51  BV=-3.65
    {50000,16384,1560, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.61  BV=-3.75
    {50000,16384,1672, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=9.71  BV=-3.85
    {60000,16384,1496, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.55  BV=-3.96
    {60000,16384,1600, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.64  BV=-4.05
    {60000,16384,1712, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.74  BV=-4.15
    {60000,16384,1832, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.84  BV=-4.25
    {60000,16384,1968, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=9.94  BV=-4.35
    {60000,16384,2104, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.04  BV=-4.45
    {60000,16384,2256, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.14  BV=-4.55
    {60000,16384,2416, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.24  BV=-4.65
    {60000,16384,2592, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.34  BV=-4.75
    {60000,16384,2776, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.44  BV=-4.85
    {60000,16384,2976, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.54  BV=-4.95
    {60000,16384,3192, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.64  BV=-5.05
    {60000,16384,3424, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.74  BV=-5.15
    {60000,16384,3664, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.84  BV=-5.25
    {60000,16384,3928, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.94  BV=-5.35
    {60000,16384,4208, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.04  BV=-5.45
    {60000,16384,4512, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.14  BV=-5.55
    {60000,16384,4840, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.24  BV=-5.65
    {60000,16384,5184, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.34  BV=-5.75
    {60000,16384,5560, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=11.44  BV=-5.85
    {60000,16384,5632, 0, 0, 0},  /* TV = 4.06(5976 lines)  AV=1.53  SV=11.46  BV=-5.87 */
    {60000,16384,5632, 0, 0, 0},  /* TV = 4.06(5976 lines)  AV=1.53  SV=11.46  BV=-5.87 */
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    159, //u4TotalIndex
    20, //i4StrobeTrigerBV
    97, //i4MaxBV
    -61, //i4MinBV
    90, //i4EffectiveMaxBV
    0, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene14PLineTable_60Hz,
    sAEScene14PLineTable_50Hz,
    NULL,
};
static constexpr strEvPline sAEScene15PLineTable_60Hz =
{
{
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.17  BV=-3.05
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1416, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.47  BV=-3.35
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.55
    {41666,16384,1744, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.77  BV=-3.65
    {41666,16384,1864, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.86  BV=-3.75
    {41666,16384,2000, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.85
    {41666,16384,2144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.95
    {41666,16384,2296, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.16  BV=-4.05
    {41666,16384,2464, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.27  BV=-4.15
    {41666,16384,2640, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.37  BV=-4.25
    {41666,16384,2832, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.47  BV=-4.35
    {41666,16384,3040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.57  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {58333,16384,2672, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.38  BV=-4.75
    {58333,16384,2864, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.48  BV=-4.85
    {58333,16384,3072, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.58  BV=-4.95
    {66666,16384,2880, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1200, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.23  BV=-3.05
    {40000,16384,1288, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.33  BV=-3.16
    {40000,16384,1376, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.43  BV=-3.25
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {40000,16384,1816, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.65
    {40000,16384,1944, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.92  BV=-3.75
    {40000,16384,2088, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.85
    {40000,16384,2232, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.12  BV=-3.95
    {40000,16384,2392, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.22  BV=-4.05
    {40000,16384,2568, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.33  BV=-4.15
    {40000,16384,2752, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.43  BV=-4.25
    {40000,16384,2952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.53  BV=-4.35
    {40000,16384,3168, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.63  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {50000,16384,3120, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.61  BV=-4.75
    {60000,16384,2784, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.44  BV=-4.85
    {60000,16384,2984, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.54  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -51, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.17  BV=-3.05
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1416, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.47  BV=-3.35
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.55
    {41666,16384,1744, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.77  BV=-3.65
    {41666,16384,1864, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.86  BV=-3.75
    {41666,16384,2000, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.85
    {41666,16384,2144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.95
    {41666,16384,2296, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.16  BV=-4.05
    {41666,16384,2464, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.27  BV=-4.15
    {41666,16384,2640, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.37  BV=-4.25
    {41666,16384,2832, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.47  BV=-4.35
    {41666,16384,3040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.57  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {58333,16384,2672, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.38  BV=-4.75
    {58333,16384,2864, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.48  BV=-4.85
    {58333,16384,3072, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.58  BV=-4.95
    {66666,16384,2880, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1200, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.23  BV=-3.05
    {40000,16384,1288, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.33  BV=-3.16
    {40000,16384,1376, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.43  BV=-3.25
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {40000,16384,1816, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.65
    {40000,16384,1944, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.92  BV=-3.75
    {40000,16384,2088, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.85
    {40000,16384,2232, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.12  BV=-3.95
    {40000,16384,2392, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.22  BV=-4.05
    {40000,16384,2568, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.33  BV=-4.15
    {40000,16384,2752, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.43  BV=-4.25
    {40000,16384,2952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.53  BV=-4.35
    {40000,16384,3168, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.63  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {50000,16384,3120, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.61  BV=-4.75
    {60000,16384,2784, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.44  BV=-4.85
    {60000,16384,2984, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.54  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -51, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.17  BV=-3.05
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1416, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.47  BV=-3.35
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.55
    {41666,16384,1744, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.77  BV=-3.65
    {41666,16384,1864, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.86  BV=-3.75
    {41666,16384,2000, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.85
    {41666,16384,2144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.95
    {41666,16384,2296, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.16  BV=-4.05
    {41666,16384,2464, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.27  BV=-4.15
    {41666,16384,2640, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.37  BV=-4.25
    {41666,16384,2832, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.47  BV=-4.35
    {41666,16384,3040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.57  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {58333,16384,2672, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.38  BV=-4.75
    {58333,16384,2864, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.48  BV=-4.85
    {58333,16384,3072, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.58  BV=-4.95
    {66666,16384,2880, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1200, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.23  BV=-3.05
    {40000,16384,1288, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.33  BV=-3.16
    {40000,16384,1376, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.43  BV=-3.25
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {40000,16384,1816, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.65
    {40000,16384,1944, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.92  BV=-3.75
    {40000,16384,2088, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.85
    {40000,16384,2232, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.12  BV=-3.95
    {40000,16384,2392, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.22  BV=-4.05
    {40000,16384,2568, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.33  BV=-4.15
    {40000,16384,2752, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.43  BV=-4.25
    {40000,16384,2952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.53  BV=-4.35
    {40000,16384,3168, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.63  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {50000,16384,3120, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.61  BV=-4.75
    {60000,16384,2784, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.44  BV=-4.85
    {60000,16384,2984, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.54  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -51, //i4MinBV
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8335,1248,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.30  BV=3.14
    {8335,1312,1048, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.39  BV=3.05
    {8335,1408,1040, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.48  BV=2.96
    {8335,1536,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.60  BV=2.84
    {8335,1632,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.68  BV=2.75
    {8335,1760,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.78  BV=2.66
    {8335,1888,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.89  BV=2.54
    {8335,2016,1032, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=5.99  BV=2.45
    {8335,2176,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.09  BV=2.35
    {8335,2336,1024, 0, 0, 0},  //TV = 6.91(830 lines)  AV=1.53  SV=6.19  BV=2.25
    {16668,1248,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.29  BV=2.15
    {16668,1312,1048, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.39  BV=2.05
    {16668,1408,1040, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.48  BV=1.96
    {16668,1536,1024, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.58  BV=1.85
    {16668,1632,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.68  BV=1.75
    {16668,1760,1032, 0, 0, 0},  //TV = 5.91(1660 lines)  AV=1.53  SV=5.79  BV=1.65
    {25001,1248,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.30  BV=1.56
    {25001,1344,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.40  BV=1.45
    {25001,1440,1032, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.50  BV=1.35
    {25001,1536,1040, 0, 0, 0},  //TV = 5.32(2490 lines)  AV=1.53  SV=5.61  BV=1.25
    {33334,1248,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.29  BV=1.15
    {33334,1312,1048, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.39  BV=1.05
    {33334,1408,1040, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.48  BV=0.96
    {33334,1536,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.58  BV=0.85
    {33334,1632,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.68  BV=0.75
    {33334,1760,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.79  BV=0.65
    {33334,1888,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.88  BV=0.56
    {33334,2016,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=5.99  BV=0.45
    {33334,2176,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.09  BV=0.35
    {33334,2304,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.18  BV=0.26
    {33334,2496,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.29  BV=0.15
    {33334,2656,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.39  BV=0.05
    {33334,2880,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.49  BV=-0.05
    {33334,3072,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.58  BV=-0.15
    {33334,3296,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.69  BV=-0.25
    {33334,3520,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.79  BV=-0.35
    {33334,3776,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.88  BV=-0.44
    {33334,4032,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=6.99  BV=-0.55
    {33334,4352,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.09  BV=-0.65
    {33334,4672,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.19  BV=-0.75
    {33334,4992,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.29  BV=-0.85
    {33334,5312,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.39  BV=-0.95
    {33334,5696,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.49  BV=-1.05
    {33334,6144,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.58  BV=-1.15
    {33334,6592,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.69  BV=-1.25
    {33334,7104,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.79  BV=-1.36
    {33334,7616,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.89  BV=-1.46
    {33334,8128,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=7.99  BV=-1.55
    {33334,8704,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.09  BV=-1.65
    {33334,9344,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.19  BV=-1.75
    {33334,9984,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.29  BV=-1.85
    {33334,10752,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.39  BV=-1.95
    {33334,11392,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.49  BV=-2.05
    {33333,12288,1024, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.58  BV=-2.15
    {33333,13056,1032, 0, 0, 0},  //TV = 4.91(3320 lines)  AV=1.53  SV=8.68  BV=-2.25
    {41666,11264,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.47  BV=-2.35
    {41666,12160,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.57  BV=-2.45
    {41666,13056,1024, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.67  BV=-2.56
    {41666,13824,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.77  BV=-2.65
    {41666,14848,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.87  BV=-2.75
    {41666,15872,1032, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=8.97  BV=-2.85
    {41666,16384,1072, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.07  BV=-2.95
    {41666,16384,1152, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.17  BV=-3.05
    {41666,16384,1232, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.27  BV=-3.15
    {41666,16384,1320, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.37  BV=-3.25
    {41666,16384,1416, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.47  BV=-3.35
    {41666,16384,1520, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.57  BV=-3.45
    {41666,16384,1624, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.67  BV=-3.55
    {41666,16384,1744, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.77  BV=-3.65
    {41666,16384,1864, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.86  BV=-3.75
    {41666,16384,2000, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=9.97  BV=-3.85
    {41666,16384,2144, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.07  BV=-3.95
    {41666,16384,2296, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.16  BV=-4.05
    {41666,16384,2464, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.27  BV=-4.15
    {41666,16384,2640, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.37  BV=-4.25
    {41666,16384,2832, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.47  BV=-4.35
    {41666,16384,3040, 0, 0, 0},  //TV = 4.58(4150 lines)  AV=1.53  SV=10.57  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {58333,16384,2672, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.38  BV=-4.75
    {58333,16384,2864, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.48  BV=-4.85
    {58333,16384,3072, 0, 0, 0},  //TV = 4.10(5810 lines)  AV=1.53  SV=10.58  BV=-4.95
    {66666,16384,2880, 0, 0, 0},  //TV = 3.91(6640 lines)  AV=1.53  SV=10.49  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    {91,1312,1024, 0, 0, 0},  //TV = 13.42(9 lines)  AV=1.53  SV=5.36  BV=9.60
    {101,1216,1024, 0, 0, 0},  /* TV = 13.27(10 lines)  AV=1.53  SV=5.25  BV=9.56 */
    {111,1184,1040, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.23  BV=9.44
    {111,1280,1024, 0, 0, 0},  //TV = 13.14(11 lines)  AV=1.53  SV=5.32  BV=9.35
    {121,1248,1024, 0, 0, 0},  //TV = 13.01(12 lines)  AV=1.53  SV=5.29  BV=9.26
    {131,1248,1040, 0, 0, 0},  /* TV = 12.90(13 lines)  AV=1.53  SV=5.31  BV=9.12 */
    {141,1248,1024, 0, 0, 0},  //TV = 12.79(14 lines)  AV=1.53  SV=5.29  BV=9.04
    {151,1248,1040, 0, 0, 0},  //TV = 12.69(15 lines)  AV=1.53  SV=5.31  BV=8.92
    {171,1184,1040, 0, 0, 0},  //TV = 12.51(17 lines)  AV=1.53  SV=5.23  BV=8.81
    {181,1216,1032, 0, 0, 0},  //TV = 12.43(18 lines)  AV=1.53  SV=5.26  BV=8.70
    {191,1184,1048, 0, 0, 0},  /* TV = 12.35(19 lines)  AV=1.53  SV=5.24  BV=8.64 */
    {201,1216,1032, 0, 0, 0},  //TV = 12.28(20 lines)  AV=1.53  SV=5.26  BV=8.55
    {221,1184,1032, 0, 0, 0},  //TV = 12.14(22 lines)  AV=1.53  SV=5.22  BV=8.45
    {231,1216,1032, 0, 0, 0},  //TV = 12.08(23 lines)  AV=1.53  SV=5.26  BV=8.35
    {251,1184,1048, 0, 0, 0},  //TV = 11.96(25 lines)  AV=1.53  SV=5.24  BV=8.25
    {272,1184,1032, 0, 0, 0},  //TV = 11.84(27 lines)  AV=1.53  SV=5.22  BV=8.15
    {292,1184,1032, 0, 0, 0},  //TV = 11.74(29 lines)  AV=1.53  SV=5.22  BV=8.05
    {312,1184,1032, 0, 0, 0},  //TV = 11.65(31 lines)  AV=1.53  SV=5.22  BV=7.96
    {332,1184,1040, 0, 0, 0},  //TV = 11.56(33 lines)  AV=1.53  SV=5.23  BV=7.86
    {352,1216,1024, 0, 0, 0},  //TV = 11.47(35 lines)  AV=1.53  SV=5.25  BV=7.76
    {382,1184,1040, 0, 0, 0},  //TV = 11.35(38 lines)  AV=1.53  SV=5.23  BV=7.65
    {412,1184,1032, 0, 0, 0},  //TV = 11.25(41 lines)  AV=1.53  SV=5.22  BV=7.56
    {442,1184,1040, 0, 0, 0},  //TV = 11.14(44 lines)  AV=1.53  SV=5.23  BV=7.44
    {472,1184,1040, 0, 0, 0},  //TV = 11.05(47 lines)  AV=1.53  SV=5.23  BV=7.35
    {502,1184,1048, 0, 0, 0},  //TV = 10.96(50 lines)  AV=1.53  SV=5.24  BV=7.25
    {543,1184,1032, 0, 0, 0},  //TV = 10.85(54 lines)  AV=1.53  SV=5.22  BV=7.16
    {583,1184,1032, 0, 0, 0},  //TV = 10.74(58 lines)  AV=1.53  SV=5.22  BV=7.05
    {623,1184,1040, 0, 0, 0},  //TV = 10.65(62 lines)  AV=1.53  SV=5.23  BV=6.95
    {663,1184,1048, 0, 0, 0},  //TV = 10.56(66 lines)  AV=1.53  SV=5.24  BV=6.85
    {713,1184,1040, 0, 0, 0},  //TV = 10.45(71 lines)  AV=1.53  SV=5.23  BV=6.75
    {764,1184,1040, 0, 0, 0},  //TV = 10.35(76 lines)  AV=1.53  SV=5.23  BV=6.65
    {824,1184,1032, 0, 0, 0},  //TV = 10.25(82 lines)  AV=1.53  SV=5.22  BV=6.56
    {874,1184,1048, 0, 0, 0},  //TV = 10.16(87 lines)  AV=1.53  SV=5.24  BV=6.45
    {944,1184,1040, 0, 0, 0},  //TV = 10.05(94 lines)  AV=1.53  SV=5.23  BV=6.35
    {1015,1184,1032, 0, 0, 0},  //TV = 9.94(101 lines)  AV=1.53  SV=5.22  BV=6.25
    {1085,1184,1040, 0, 0, 0},  //TV = 9.85(108 lines)  AV=1.53  SV=5.23  BV=6.15
    {1165,1184,1040, 0, 0, 0},  //TV = 9.75(116 lines)  AV=1.53  SV=5.23  BV=6.04
    {1245,1184,1040, 0, 0, 0},  //TV = 9.65(124 lines)  AV=1.53  SV=5.23  BV=5.95
    {1336,1184,1040, 0, 0, 0},  //TV = 9.55(133 lines)  AV=1.53  SV=5.23  BV=5.85
    {1426,1184,1040, 0, 0, 0},  //TV = 9.45(142 lines)  AV=1.53  SV=5.23  BV=5.75
    {1527,1184,1040, 0, 0, 0},  //TV = 9.36(152 lines)  AV=1.53  SV=5.23  BV=5.65
    {1647,1184,1032, 0, 0, 0},  //TV = 9.25(164 lines)  AV=1.53  SV=5.22  BV=5.56
    {1757,1184,1040, 0, 0, 0},  //TV = 9.15(175 lines)  AV=1.53  SV=5.23  BV=5.45
    {1888,1184,1040, 0, 0, 0},  //TV = 9.05(188 lines)  AV=1.53  SV=5.23  BV=5.35
    {2019,1184,1040, 0, 0, 0},  //TV = 8.95(201 lines)  AV=1.53  SV=5.23  BV=5.25
    {2159,1184,1040, 0, 0, 0},  //TV = 8.86(215 lines)  AV=1.53  SV=5.23  BV=5.15
    {2330,1184,1032, 0, 0, 0},  //TV = 8.75(232 lines)  AV=1.53  SV=5.22  BV=5.06
    {2510,1184,1032, 0, 0, 0},  //TV = 8.64(250 lines)  AV=1.53  SV=5.22  BV=4.95
    {2681,1184,1040, 0, 0, 0},  //TV = 8.54(267 lines)  AV=1.53  SV=5.23  BV=4.84
    {2872,1184,1032, 0, 0, 0},  //TV = 8.44(286 lines)  AV=1.53  SV=5.22  BV=4.75
    {3073,1184,1032, 0, 0, 0},  //TV = 8.35(306 lines)  AV=1.53  SV=5.22  BV=4.66
    {3294,1184,1032, 0, 0, 0},  //TV = 8.25(328 lines)  AV=1.53  SV=5.22  BV=4.56
    {3545,1184,1032, 0, 0, 0},  //TV = 8.14(353 lines)  AV=1.53  SV=5.22  BV=4.45
    {3796,1184,1032, 0, 0, 0},  //TV = 8.04(378 lines)  AV=1.53  SV=5.22  BV=4.35
    {4067,1184,1032, 0, 0, 0},  //TV = 7.94(405 lines)  AV=1.53  SV=5.22  BV=4.25
    {4348,1184,1032, 0, 0, 0},  //TV = 7.85(433 lines)  AV=1.53  SV=5.22  BV=4.16
    {4659,1184,1032, 0, 0, 0},  //TV = 7.75(464 lines)  AV=1.53  SV=5.22  BV=4.06
    {4990,1184,1032, 0, 0, 0},  //TV = 7.65(497 lines)  AV=1.53  SV=5.22  BV=3.96
    {5372,1184,1032, 0, 0, 0},  //TV = 7.54(535 lines)  AV=1.53  SV=5.22  BV=3.85
    {5753,1184,1032, 0, 0, 0},  //TV = 7.44(573 lines)  AV=1.53  SV=5.22  BV=3.75
    {6165,1184,1032, 0, 0, 0},  //TV = 7.34(614 lines)  AV=1.53  SV=5.22  BV=3.65
    {6607,1184,1032, 0, 0, 0},  //TV = 7.24(658 lines)  AV=1.53  SV=5.22  BV=3.55
    {7069,1184,1032, 0, 0, 0},  //TV = 7.14(704 lines)  AV=1.53  SV=5.22  BV=3.45
    {7571,1184,1032, 0, 0, 0},  //TV = 7.05(754 lines)  AV=1.53  SV=5.22  BV=3.36
    {8113,1184,1032, 0, 0, 0},  //TV = 6.95(808 lines)  AV=1.53  SV=5.22  BV=3.26
    {8695,1184,1032, 0, 0, 0},  //TV = 6.85(866 lines)  AV=1.53  SV=5.22  BV=3.16
    {9308,1184,1032, 0, 0, 0},  //TV = 6.75(927 lines)  AV=1.53  SV=5.22  BV=3.06
    {10000,1184,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.23  BV=2.94
    {10000,1280,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.32  BV=2.85
    {10000,1344,1048, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.43  BV=2.75
    {10000,1472,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.52  BV=2.65
    {10000,1568,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.63  BV=2.55
    {10000,1696,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.73  BV=2.45
    {10000,1792,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.83  BV=2.35
    {10000,1920,1040, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=5.93  BV=2.25
    {10000,2080,1024, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.02  BV=2.15
    {10000,2208,1032, 0, 0, 0},  //TV = 6.64(996 lines)  AV=1.53  SV=6.12  BV=2.06
    {20000,1184,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.22  BV=1.95
    {20000,1280,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.32  BV=1.85
    {20000,1344,1048, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.43  BV=1.75
    {20000,1472,1024, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.52  BV=1.65
    {20000,1568,1032, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.63  BV=1.55
    {20000,1664,1040, 0, 0, 0},  //TV = 5.64(1992 lines)  AV=1.53  SV=5.72  BV=1.45
    {30000,1184,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.24  BV=1.35
    {30000,1280,1048, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.36  BV=1.23
    {30000,1376,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.44  BV=1.15
    {30000,1472,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.55  BV=1.04
    {30000,1568,1040, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.64  BV=0.95
    {30000,1696,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.74  BV=0.85
    {30000,1824,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.84  BV=0.75
    {30000,1952,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=5.94  BV=0.65
    {30000,2112,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.04  BV=0.55
    {30000,2240,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.14  BV=0.45
    {30000,2400,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.24  BV=0.35
    {30000,2592,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.34  BV=0.25
    {30000,2784,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.44  BV=0.15
    {30000,2976,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.54  BV=0.05
    {30000,3168,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.63  BV=-0.04
    {30000,3424,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.74  BV=-0.15
    {30000,3648,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.84  BV=-0.25
    {30000,3936,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=6.94  BV=-0.35
    {30000,4160,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.03  BV=-0.44
    {30000,4480,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.14  BV=-0.55
    {30000,4800,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.24  BV=-0.65
    {30000,5184,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.34  BV=-0.75
    {30000,5568,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.44  BV=-0.85
    {30000,5952,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.54  BV=-0.95
    {30000,6336,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.64  BV=-1.05
    {30000,6848,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.74  BV=-1.15
    {30000,7296,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.83  BV=-1.24
    {30000,7872,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=7.94  BV=-1.35
    {30000,8448,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.04  BV=-1.45
    {30000,8960,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.14  BV=-1.55
    {30000,9600,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.24  BV=-1.65
    {30000,10368,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.34  BV=-1.75
    {30000,11136,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.44  BV=-1.85
    {30000,11904,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.54  BV=-1.95
    {30000,12800,1024, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.64  BV=-2.05
    {30000,13568,1032, 0, 0, 0},  //TV = 5.06(2988 lines)  AV=1.53  SV=8.74  BV=-2.15
    {40000,11008,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.43  BV=-2.25
    {40000,11776,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.52  BV=-2.35
    {40000,12544,1032, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.63  BV=-2.45
    {40000,13568,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.73  BV=-2.55
    {40000,14336,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.83  BV=-2.65
    {40000,15616,1024, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=8.93  BV=-2.76
    {40000,16384,1040, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.02  BV=-2.85
    {40000,16384,1120, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.13  BV=-2.95
    {40000,16384,1200, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.23  BV=-3.05
    {40000,16384,1288, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.33  BV=-3.16
    {40000,16384,1376, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.43  BV=-3.25
    {40000,16384,1472, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.52  BV=-3.35
    {40000,16384,1584, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.63  BV=-3.45
    {40000,16384,1696, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.73  BV=-3.55
    {40000,16384,1816, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.83  BV=-3.65
    {40000,16384,1944, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=9.92  BV=-3.75
    {40000,16384,2088, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.03  BV=-3.85
    {40000,16384,2232, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.12  BV=-3.95
    {40000,16384,2392, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.22  BV=-4.05
    {40000,16384,2568, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.33  BV=-4.15
    {40000,16384,2752, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.43  BV=-4.25
    {40000,16384,2952, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.53  BV=-4.35
    {40000,16384,3168, 0, 0, 0},  //TV = 4.64(3984 lines)  AV=1.53  SV=10.63  BV=-4.45
    {50000,16384,2712, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.41  BV=-4.55
    {50000,16384,2912, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.51  BV=-4.65
    {50000,16384,3120, 0, 0, 0},  //TV = 4.32(4980 lines)  AV=1.53  SV=10.61  BV=-4.75
    {60000,16384,2784, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.44  BV=-4.85
    {60000,16384,2984, 0, 0, 0},  //TV = 4.06(5976 lines)  AV=1.53  SV=10.54  BV=-4.95
    {69999,16384,2736, 0, 0, 0},  //TV = 3.84(6972 lines)  AV=1.53  SV=10.42  BV=-5.05
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
    {0, 0, 0, 0, 0, 0},  //reserved no used
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
    96, //i4MaxBV
    -51, //i4MinBV
    90, //i4EffectiveMaxBV
    -50, //i4EffectiveMinBV
    LIB3A_AE_ISO_SPEED_AUTO, //ISO
    sAEScene18PLineTable_60Hz,
    sAEScene18PLineTable_50Hz,
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
    g_AE_ReserveSceneTable,
},
};

static constexpr strAEPLineNumInfo g_strAEPreviewAutoPLineInfo =
{
    AETABLE_RPEVIEW_AUTO,
    90,
    -50,
    {
        {1,10000,30,1136,1136},
        {2,30,30,1136,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,16384},
        {5,24,17,16384,16384},
        {6,17,17,16384,32768},
        {7,17,10,32768,32768},
        {8,10,10,32768,65536},
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
        {1,10000,30,1136,1136},
        {2,30,30,1136,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,16384},
        {5,24,17,16384,16384},
        {6,17,17,16384,32768},
        {7,17,10,32768,32768},
        {8,10,10,32768,65536},
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
        {1,10000,30,1136,1136},
        {2,30,30,1136,8192},
        {3,30,24,8192,8192},
        {4,24,24,8192,65536},
        {5,24,15,65536,65536},
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
        {1,10000,30,1136,1136},
        {2,30,30,1136,12288},
        {3,30,24,12288,12288},
        {4,24,24,12288,16384},
        {5,24,17,16384,16384},
        {6,17,17,16384,32768},
        {7,17,10,32768,32768},
        {8,10,10,32768,65536},
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
    90,
    0,
    {
        {1,10000,40,1024,1024},
        {2,40,40,1024,5120},
        {3,40,30,5120,5120},
        {4,30,30,5120,17408},
        {5,30,24,17408,17408},
        {6,24,24,17408,24576},
        {7,24,16,24576,24576},
        {8,16,16,24576,90112},
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
        g_strAENoScenePLineInfo,
},
};

static constexpr strAEPLineGainList g_strAEGainList =
{
    209,
    {
        {1024,0},
        {1056,0},
        {1088,0},
        {1120,0},
        {1152,0},
        {1184,0},
        {1216,0},
        {1248,0},
        {1280,0},
        {1312,0},
        {1344,0},
        {1376,0},
        {1408,0},
        {1440,0},
        {1472,0},
        {1504,0},
        {1536,0},
        {1568,0},
        {1600,0},
        {1632,0},
        {1664,0},
        {1696,0},
        {1728,0},
        {1760,0},
        {1792,0},
        {1824,0},
        {1856,0},
        {1888,0},
        {1920,0},
        {1952,0},
        {1984,0},
        {2016,0},
        {2048,0},
        {2080,0},
        {2112,0},
        {2144,0},
        {2176,0},
        {2208,0},
        {2240,0},
        {2272,0},
        {2304,0},
        {2336,0},
        {2368,0},
        {2400,0},
        {2432,0},
        {2464,0},
        {2496,0},
        {2528,0},
        {2560,0},
        {2592,0},
        {2624,0},
        {2656,0},
        {2688,0},
        {2720,0},
        {2752,0},
        {2784,0},
        {2816,0},
        {2848,0},
        {2880,0},
        {2912,0},
        {2944,0},
        {2976,0},
        {3008,0},
        {3040,0},
        {3072,0},
        {3104,0},
        {3136,0},
        {3168,0},
        {3200,0},
        {3232,0},
        {3264,0},
        {3296,0},
        {3328,0},
        {3360,0},
        {3392,0},
        {3424,0},
        {3456,0},
        {3488,0},
        {3520,0},
        {3552,0},
        {3584,0},
        {3616,0},
        {3648,0},
        {3680,0},
        {3712,0},
        {3744,0},
        {3776,0},
        {3808,0},
        {3840,0},
        {3872,0},
        {3904,0},
        {3936,0},
        {3968,0},
        {4000,0},
        {4032,0},
        {4064,0},
        {4096,0},
        {4160,0},
        {4224,0},
        {4288,0},
        {4352,0},
        {4416,0},
        {4480,0},
        {4544,0},
        {4608,0},
        {4672,0},
        {4736,0},
        {4800,0},
        {4864,0},
        {4928,0},
        {4992,0},
        {5056,0},
        {5120,0},
        {5184,0},
        {5248,0},
        {5312,0},
        {5376,0},
        {5440,0},
        {5504,0},
        {5568,0},
        {5632,0},
        {5696,0},
        {5760,0},
        {5824,0},
        {5888,0},
        {5952,0},
        {6016,0},
        {6080,0},
        {6144,0},
        {6208,0},
        {6272,0},
        {6336,0},
        {6400,0},
        {6464,0},
        {6528,0},
        {6592,0},
        {6656,0},
        {6720,0},
        {6784,0},
        {6848,0},
        {6912,0},
        {6976,0},
        {7040,0},
        {7104,0},
        {7168,0},
        {7232,0},
        {7296,0},
        {7360,0},
        {7424,0},
        {7488,0},
        {7552,0},
        {7616,0},
        {7680,0},
        {7744,0},
        {7808,0},
        {7872,0},
        {7936,0},
        {8000,0},
        {8064,0},
        {8128,0},
        {8192,0},
        {8320,0},
        {8448,0},
        {8576,0},
        {8704,0},
        {8832,0},
        {8960,0},
        {9088,0},
        {9216,0},
        {9344,0},
        {9472,0},
        {9600,0},
        {9728,0},
        {9856,0},
        {9984,0},
        {10112,0},
        {10240,0},
        {10368,0},
        {10496,0},
        {10624,0},
        {10752,0},
        {10880,0},
        {11008,0},
        {11136,0},
        {11264,0},
        {11392,0},
        {11520,0},
        {11648,0},
        {11776,0},
        {11904,0},
        {12032,0},
        {12160,0},
        {12288,0},
        {12544,0},
        {12800,0},
        {13056,0},
        {13312,0},
        {13568,0},
        {13824,0},
        {14080,0},
        {14336,0},
        {14592,0},
        {14848,0},
        {15104,0},
        {15360,0},
        {15616,0},
        {15872,0},
        {16128,0},
        {16384,0},
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
MinGain,1136
MaxGain,16384
MiniISOGain,100
GainStepUnitInTotalRange,16
PreviewExposureLineUnit,11345
PreviewMaxFrameRate,30
VideoExposureLineUnit,10040
VideoMaxFrameRate,30
VideoToPreviewSensitivityRatio,1024
CaptureExposureLineUnit,10040
CaptureMaxFrameRate,30
CaptureToPreviewSensitivityRatio,1024
Video1ExposureLineUnit,10040
Video1MaxFrameRate,120
Video1ToPreviewSensitivityRatio,1024
Video2ExposureLineUnit,10040
Video2MaxFrameRate,60
Video2ToPreviewSensitivityRatio,1024
Custom1ExposureLineUnit,11345
Custom1MaxFrameRate,30
Custom1ToPreviewSensitivityRatio,1024
Custom2ExposureLineUnit,11345
Custom2MaxFrameRate,30
Custom2ToPreviewSensitivityRatio,1024
Custom3ExposureLineUnit,10424
Custom3MaxFrameRate,30
Custom3ToPreviewSensitivityRatio,1024
Custom4ExposureLineUnit,11345
Custom4MaxFrameRate,30
Custom4ToPreviewSensitivityRatio,1024
Custom5ExposureLineUnit,11345
Custom5MaxFrameRate,30
Custom5ToPreviewSensitivityRatio,1024
FocusLength,350
Fno,17

// Preview table -- Use preview sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_RPEVIEW_AUTO
90,-50
1,10000,30,1136,1136
2,30,30,1136,12288
3,30,24,12288,12288
4,24,24,12288,16384
5,24,17,16384,16384
6,17,17,16384,32768
7,17,10,32768,32768
8,10,10,32768,65536
AETABLE_END

// Capture table -- Use capture sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_CAPTURE_AUTO
90,-30
1,10000,30,1136,1136
2,30,30,1136,12288
3,30,24,12288,12288
4,24,24,12288,16384
5,24,17,16384,16384
6,17,17,16384,32768
7,17,10,32768,32768
8,10,10,32768,65536
AETABLE_END

// Video table -- Use video sensor setting
// Index MiniExp1/T MaxExp1/T MinGain MaxGain
AETABLE_VIDEO_AUTO
90,-30
1,10000,30,1136,1136
2,30,30,1136,8192
3,30,24,8192,8192
4,24,24,8192,65536
5,24,15,65536,65536
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
1,10000,30,1136,1136
2,30,30,1136,12288
3,30,24,12288,12288
4,24,24,12288,16384
5,24,17,16384,16384
6,17,17,16384,32768
7,17,10,32768,32768
8,10,10,32768,65536
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
90,0
1,10000,40,1024,1024
2,40,40,1024,5120
3,40,30,5120,5120
4,30,30,5120,17408
5,30,24,17408,17408
6,24,24,17408,24576
7,24,16,24576,24576
8,16,16,24576,90112
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
#endif
