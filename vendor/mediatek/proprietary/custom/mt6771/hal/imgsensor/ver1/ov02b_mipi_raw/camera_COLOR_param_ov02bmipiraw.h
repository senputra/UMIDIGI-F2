/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2019. All rights reserved.
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
.COMM =
{
    .COLOR =
    {
        .COLOR_Method =
        {
            1,
        }
    },
    .CCM =
    {
        .dynamic_CCM=
        {
            {.set={
                0x1ECE034E, 0x00001FE4, 0x02BD1FBE, 0x00001F85, 0x1F000008, 0x000002F8
            }},
            {.set={
                0x1E8D03C2, 0x00001FB1, 0x02C41F87, 0x00001FB5, 0x1EC9000B, 0x0000032C
            }},
            {.set={
                0x1DF00417, 0x00001FDE, 0x02B01F7A, 0x00001FD6, 0x1ECE0012, 0x00000320
            }},
            {.set={
                0x1F4302FD, 0x00001FC0, 0x02761F9E, 0x00001FEC, 0x1E331FF4, 0x000003D9
            }}
        },

        .dynamic_CCM_AWBGain=
        {
            {
              1342,
              512,
              647
            },
            {
              978,
              512,
              915
            },
            {
              1114,
              512,
              1021
            },
            {
              681,
              512,
              1207
            }
        }
    }
},
.CCM = {
    ov02bmipiraw_CCM_0000, ov02bmipiraw_CCM_0001, ov02bmipiraw_CCM_0002, ov02bmipiraw_CCM_0003, ov02bmipiraw_CCM_0004, ov02bmipiraw_CCM_0005, ov02bmipiraw_CCM_0006, ov02bmipiraw_CCM_0007, ov02bmipiraw_CCM_0008, ov02bmipiraw_CCM_0009,
    ov02bmipiraw_CCM_0010, ov02bmipiraw_CCM_0011, ov02bmipiraw_CCM_0012, ov02bmipiraw_CCM_0013, ov02bmipiraw_CCM_0014, ov02bmipiraw_CCM_0015, ov02bmipiraw_CCM_0016, ov02bmipiraw_CCM_0017, ov02bmipiraw_CCM_0018, ov02bmipiraw_CCM_0019,
    ov02bmipiraw_CCM_0020, ov02bmipiraw_CCM_0021, ov02bmipiraw_CCM_0022, ov02bmipiraw_CCM_0023, ov02bmipiraw_CCM_0024, ov02bmipiraw_CCM_0025, ov02bmipiraw_CCM_0026, ov02bmipiraw_CCM_0027, ov02bmipiraw_CCM_0028, ov02bmipiraw_CCM_0029,
    ov02bmipiraw_CCM_0030, ov02bmipiraw_CCM_0031, ov02bmipiraw_CCM_0032, ov02bmipiraw_CCM_0033, ov02bmipiraw_CCM_0034, ov02bmipiraw_CCM_0035, ov02bmipiraw_CCM_0036, ov02bmipiraw_CCM_0037, ov02bmipiraw_CCM_0038, ov02bmipiraw_CCM_0039,
    ov02bmipiraw_CCM_0040, ov02bmipiraw_CCM_0041, ov02bmipiraw_CCM_0042, ov02bmipiraw_CCM_0043, ov02bmipiraw_CCM_0044, ov02bmipiraw_CCM_0045, ov02bmipiraw_CCM_0046, ov02bmipiraw_CCM_0047, ov02bmipiraw_CCM_0048, ov02bmipiraw_CCM_0049,
    ov02bmipiraw_CCM_0050, ov02bmipiraw_CCM_0051, ov02bmipiraw_CCM_0052, ov02bmipiraw_CCM_0053, ov02bmipiraw_CCM_0054, ov02bmipiraw_CCM_0055, ov02bmipiraw_CCM_0056, ov02bmipiraw_CCM_0057, ov02bmipiraw_CCM_0058, ov02bmipiraw_CCM_0059,
    ov02bmipiraw_CCM_0060, ov02bmipiraw_CCM_0061, ov02bmipiraw_CCM_0062, ov02bmipiraw_CCM_0063, ov02bmipiraw_CCM_0064, ov02bmipiraw_CCM_0065, ov02bmipiraw_CCM_0066, ov02bmipiraw_CCM_0067, ov02bmipiraw_CCM_0068, ov02bmipiraw_CCM_0069,
    ov02bmipiraw_CCM_0070, ov02bmipiraw_CCM_0071, ov02bmipiraw_CCM_0072, ov02bmipiraw_CCM_0073, ov02bmipiraw_CCM_0074, ov02bmipiraw_CCM_0075, ov02bmipiraw_CCM_0076, ov02bmipiraw_CCM_0077, ov02bmipiraw_CCM_0078, ov02bmipiraw_CCM_0079,
    ov02bmipiraw_CCM_0080, ov02bmipiraw_CCM_0081, ov02bmipiraw_CCM_0082, ov02bmipiraw_CCM_0083, ov02bmipiraw_CCM_0084, ov02bmipiraw_CCM_0085, ov02bmipiraw_CCM_0086, ov02bmipiraw_CCM_0087, ov02bmipiraw_CCM_0088, ov02bmipiraw_CCM_0089,
    ov02bmipiraw_CCM_0090, ov02bmipiraw_CCM_0091, ov02bmipiraw_CCM_0092, ov02bmipiraw_CCM_0093, ov02bmipiraw_CCM_0094, ov02bmipiraw_CCM_0095, ov02bmipiraw_CCM_0096, ov02bmipiraw_CCM_0097, ov02bmipiraw_CCM_0098, ov02bmipiraw_CCM_0099,
    ov02bmipiraw_CCM_0100, ov02bmipiraw_CCM_0101, ov02bmipiraw_CCM_0102, ov02bmipiraw_CCM_0103, ov02bmipiraw_CCM_0104, ov02bmipiraw_CCM_0105, ov02bmipiraw_CCM_0106, ov02bmipiraw_CCM_0107, ov02bmipiraw_CCM_0108, ov02bmipiraw_CCM_0109,
    ov02bmipiraw_CCM_0110, ov02bmipiraw_CCM_0111, ov02bmipiraw_CCM_0112, ov02bmipiraw_CCM_0113, ov02bmipiraw_CCM_0114, ov02bmipiraw_CCM_0115, ov02bmipiraw_CCM_0116, ov02bmipiraw_CCM_0117, ov02bmipiraw_CCM_0118, ov02bmipiraw_CCM_0119,
    ov02bmipiraw_CCM_0120, ov02bmipiraw_CCM_0121, ov02bmipiraw_CCM_0122, ov02bmipiraw_CCM_0123, ov02bmipiraw_CCM_0124, ov02bmipiraw_CCM_0125, ov02bmipiraw_CCM_0126, ov02bmipiraw_CCM_0127, ov02bmipiraw_CCM_0128, ov02bmipiraw_CCM_0129,
    ov02bmipiraw_CCM_0130, ov02bmipiraw_CCM_0131, ov02bmipiraw_CCM_0132, ov02bmipiraw_CCM_0133, ov02bmipiraw_CCM_0134, ov02bmipiraw_CCM_0135, ov02bmipiraw_CCM_0136, ov02bmipiraw_CCM_0137, ov02bmipiraw_CCM_0138, ov02bmipiraw_CCM_0139,
    ov02bmipiraw_CCM_0140, ov02bmipiraw_CCM_0141, ov02bmipiraw_CCM_0142, ov02bmipiraw_CCM_0143, ov02bmipiraw_CCM_0144, ov02bmipiraw_CCM_0145, ov02bmipiraw_CCM_0146, ov02bmipiraw_CCM_0147, ov02bmipiraw_CCM_0148, ov02bmipiraw_CCM_0149,
    ov02bmipiraw_CCM_0150, ov02bmipiraw_CCM_0151, ov02bmipiraw_CCM_0152, ov02bmipiraw_CCM_0153, ov02bmipiraw_CCM_0154, ov02bmipiraw_CCM_0155, ov02bmipiraw_CCM_0156, ov02bmipiraw_CCM_0157, ov02bmipiraw_CCM_0158, ov02bmipiraw_CCM_0159,
    ov02bmipiraw_CCM_0160, ov02bmipiraw_CCM_0161, ov02bmipiraw_CCM_0162, ov02bmipiraw_CCM_0163, ov02bmipiraw_CCM_0164, ov02bmipiraw_CCM_0165, ov02bmipiraw_CCM_0166, ov02bmipiraw_CCM_0167, ov02bmipiraw_CCM_0168, ov02bmipiraw_CCM_0169,
    ov02bmipiraw_CCM_0170, ov02bmipiraw_CCM_0171, ov02bmipiraw_CCM_0172, ov02bmipiraw_CCM_0173, ov02bmipiraw_CCM_0174, ov02bmipiraw_CCM_0175, ov02bmipiraw_CCM_0176, ov02bmipiraw_CCM_0177, ov02bmipiraw_CCM_0178, ov02bmipiraw_CCM_0179,
    ov02bmipiraw_CCM_0180, ov02bmipiraw_CCM_0181, ov02bmipiraw_CCM_0182, ov02bmipiraw_CCM_0183, ov02bmipiraw_CCM_0184, ov02bmipiraw_CCM_0185, ov02bmipiraw_CCM_0186, ov02bmipiraw_CCM_0187, ov02bmipiraw_CCM_0188, ov02bmipiraw_CCM_0189,
    ov02bmipiraw_CCM_0190, ov02bmipiraw_CCM_0191, ov02bmipiraw_CCM_0192, ov02bmipiraw_CCM_0193, ov02bmipiraw_CCM_0194, ov02bmipiraw_CCM_0195, ov02bmipiraw_CCM_0196, ov02bmipiraw_CCM_0197, ov02bmipiraw_CCM_0198, ov02bmipiraw_CCM_0199,
    ov02bmipiraw_CCM_0200, ov02bmipiraw_CCM_0201, ov02bmipiraw_CCM_0202, ov02bmipiraw_CCM_0203, ov02bmipiraw_CCM_0204, ov02bmipiraw_CCM_0205, ov02bmipiraw_CCM_0206, ov02bmipiraw_CCM_0207, ov02bmipiraw_CCM_0208, ov02bmipiraw_CCM_0209,
    ov02bmipiraw_CCM_0210, ov02bmipiraw_CCM_0211, ov02bmipiraw_CCM_0212, ov02bmipiraw_CCM_0213, ov02bmipiraw_CCM_0214, ov02bmipiraw_CCM_0215, ov02bmipiraw_CCM_0216, ov02bmipiraw_CCM_0217, ov02bmipiraw_CCM_0218, ov02bmipiraw_CCM_0219,
    ov02bmipiraw_CCM_0220, ov02bmipiraw_CCM_0221, ov02bmipiraw_CCM_0222, ov02bmipiraw_CCM_0223, ov02bmipiraw_CCM_0224, ov02bmipiraw_CCM_0225, ov02bmipiraw_CCM_0226, ov02bmipiraw_CCM_0227, ov02bmipiraw_CCM_0228, ov02bmipiraw_CCM_0229,
    ov02bmipiraw_CCM_0230, ov02bmipiraw_CCM_0231, ov02bmipiraw_CCM_0232, ov02bmipiraw_CCM_0233, ov02bmipiraw_CCM_0234, ov02bmipiraw_CCM_0235, ov02bmipiraw_CCM_0236, ov02bmipiraw_CCM_0237, ov02bmipiraw_CCM_0238, ov02bmipiraw_CCM_0239,
},
.COLOR = {
    ov02bmipiraw_COLOR_0000, ov02bmipiraw_COLOR_0001, ov02bmipiraw_COLOR_0002, ov02bmipiraw_COLOR_0003, ov02bmipiraw_COLOR_0004, ov02bmipiraw_COLOR_0005, ov02bmipiraw_COLOR_0006, ov02bmipiraw_COLOR_0007, ov02bmipiraw_COLOR_0008, ov02bmipiraw_COLOR_0009,
    ov02bmipiraw_COLOR_0010, ov02bmipiraw_COLOR_0011, ov02bmipiraw_COLOR_0012, ov02bmipiraw_COLOR_0013, ov02bmipiraw_COLOR_0014, ov02bmipiraw_COLOR_0015, ov02bmipiraw_COLOR_0016, ov02bmipiraw_COLOR_0017, ov02bmipiraw_COLOR_0018, ov02bmipiraw_COLOR_0019,
    ov02bmipiraw_COLOR_0020, ov02bmipiraw_COLOR_0021, ov02bmipiraw_COLOR_0022, ov02bmipiraw_COLOR_0023, ov02bmipiraw_COLOR_0024, ov02bmipiraw_COLOR_0025, ov02bmipiraw_COLOR_0026, ov02bmipiraw_COLOR_0027, ov02bmipiraw_COLOR_0028, ov02bmipiraw_COLOR_0029,
    ov02bmipiraw_COLOR_0030, ov02bmipiraw_COLOR_0031, ov02bmipiraw_COLOR_0032, ov02bmipiraw_COLOR_0033, ov02bmipiraw_COLOR_0034, ov02bmipiraw_COLOR_0035, ov02bmipiraw_COLOR_0036, ov02bmipiraw_COLOR_0037, ov02bmipiraw_COLOR_0038, ov02bmipiraw_COLOR_0039,
    ov02bmipiraw_COLOR_0040, ov02bmipiraw_COLOR_0041, ov02bmipiraw_COLOR_0042, ov02bmipiraw_COLOR_0043, ov02bmipiraw_COLOR_0044, ov02bmipiraw_COLOR_0045, ov02bmipiraw_COLOR_0046, ov02bmipiraw_COLOR_0047, ov02bmipiraw_COLOR_0048, ov02bmipiraw_COLOR_0049,
    ov02bmipiraw_COLOR_0050, ov02bmipiraw_COLOR_0051, ov02bmipiraw_COLOR_0052, ov02bmipiraw_COLOR_0053, ov02bmipiraw_COLOR_0054, ov02bmipiraw_COLOR_0055, ov02bmipiraw_COLOR_0056, ov02bmipiraw_COLOR_0057, ov02bmipiraw_COLOR_0058, ov02bmipiraw_COLOR_0059,
    ov02bmipiraw_COLOR_0060, ov02bmipiraw_COLOR_0061, ov02bmipiraw_COLOR_0062, ov02bmipiraw_COLOR_0063, ov02bmipiraw_COLOR_0064, ov02bmipiraw_COLOR_0065, ov02bmipiraw_COLOR_0066, ov02bmipiraw_COLOR_0067, ov02bmipiraw_COLOR_0068, ov02bmipiraw_COLOR_0069,
    ov02bmipiraw_COLOR_0070, ov02bmipiraw_COLOR_0071, ov02bmipiraw_COLOR_0072, ov02bmipiraw_COLOR_0073, ov02bmipiraw_COLOR_0074, ov02bmipiraw_COLOR_0075, ov02bmipiraw_COLOR_0076, ov02bmipiraw_COLOR_0077, ov02bmipiraw_COLOR_0078, ov02bmipiraw_COLOR_0079,
    ov02bmipiraw_COLOR_0080, ov02bmipiraw_COLOR_0081, ov02bmipiraw_COLOR_0082, ov02bmipiraw_COLOR_0083, ov02bmipiraw_COLOR_0084, ov02bmipiraw_COLOR_0085, ov02bmipiraw_COLOR_0086, ov02bmipiraw_COLOR_0087, ov02bmipiraw_COLOR_0088, ov02bmipiraw_COLOR_0089,
    ov02bmipiraw_COLOR_0090, ov02bmipiraw_COLOR_0091, ov02bmipiraw_COLOR_0092, ov02bmipiraw_COLOR_0093, ov02bmipiraw_COLOR_0094, ov02bmipiraw_COLOR_0095, ov02bmipiraw_COLOR_0096, ov02bmipiraw_COLOR_0097, ov02bmipiraw_COLOR_0098, ov02bmipiraw_COLOR_0099,
    ov02bmipiraw_COLOR_0100, ov02bmipiraw_COLOR_0101, ov02bmipiraw_COLOR_0102, ov02bmipiraw_COLOR_0103, ov02bmipiraw_COLOR_0104, ov02bmipiraw_COLOR_0105, ov02bmipiraw_COLOR_0106, ov02bmipiraw_COLOR_0107, ov02bmipiraw_COLOR_0108, ov02bmipiraw_COLOR_0109,
    ov02bmipiraw_COLOR_0110, ov02bmipiraw_COLOR_0111, ov02bmipiraw_COLOR_0112, ov02bmipiraw_COLOR_0113, ov02bmipiraw_COLOR_0114, ov02bmipiraw_COLOR_0115, ov02bmipiraw_COLOR_0116, ov02bmipiraw_COLOR_0117, ov02bmipiraw_COLOR_0118, ov02bmipiraw_COLOR_0119,
    ov02bmipiraw_COLOR_0120, ov02bmipiraw_COLOR_0121, ov02bmipiraw_COLOR_0122, ov02bmipiraw_COLOR_0123, ov02bmipiraw_COLOR_0124, ov02bmipiraw_COLOR_0125, ov02bmipiraw_COLOR_0126, ov02bmipiraw_COLOR_0127, ov02bmipiraw_COLOR_0128, ov02bmipiraw_COLOR_0129,
    ov02bmipiraw_COLOR_0130, ov02bmipiraw_COLOR_0131, ov02bmipiraw_COLOR_0132, ov02bmipiraw_COLOR_0133, ov02bmipiraw_COLOR_0134, ov02bmipiraw_COLOR_0135, ov02bmipiraw_COLOR_0136, ov02bmipiraw_COLOR_0137, ov02bmipiraw_COLOR_0138, ov02bmipiraw_COLOR_0139,
    ov02bmipiraw_COLOR_0140, ov02bmipiraw_COLOR_0141, ov02bmipiraw_COLOR_0142, ov02bmipiraw_COLOR_0143, ov02bmipiraw_COLOR_0144, ov02bmipiraw_COLOR_0145, ov02bmipiraw_COLOR_0146, ov02bmipiraw_COLOR_0147, ov02bmipiraw_COLOR_0148, ov02bmipiraw_COLOR_0149,
    ov02bmipiraw_COLOR_0150, ov02bmipiraw_COLOR_0151, ov02bmipiraw_COLOR_0152, ov02bmipiraw_COLOR_0153, ov02bmipiraw_COLOR_0154, ov02bmipiraw_COLOR_0155, ov02bmipiraw_COLOR_0156, ov02bmipiraw_COLOR_0157, ov02bmipiraw_COLOR_0158, ov02bmipiraw_COLOR_0159,
    ov02bmipiraw_COLOR_0160, ov02bmipiraw_COLOR_0161, ov02bmipiraw_COLOR_0162, ov02bmipiraw_COLOR_0163, ov02bmipiraw_COLOR_0164, ov02bmipiraw_COLOR_0165, ov02bmipiraw_COLOR_0166, ov02bmipiraw_COLOR_0167, ov02bmipiraw_COLOR_0168, ov02bmipiraw_COLOR_0169,
    ov02bmipiraw_COLOR_0170, ov02bmipiraw_COLOR_0171, ov02bmipiraw_COLOR_0172, ov02bmipiraw_COLOR_0173, ov02bmipiraw_COLOR_0174, ov02bmipiraw_COLOR_0175, ov02bmipiraw_COLOR_0176, ov02bmipiraw_COLOR_0177, ov02bmipiraw_COLOR_0178, ov02bmipiraw_COLOR_0179,
    ov02bmipiraw_COLOR_0180, ov02bmipiraw_COLOR_0181, ov02bmipiraw_COLOR_0182, ov02bmipiraw_COLOR_0183, ov02bmipiraw_COLOR_0184, ov02bmipiraw_COLOR_0185, ov02bmipiraw_COLOR_0186, ov02bmipiraw_COLOR_0187, ov02bmipiraw_COLOR_0188, ov02bmipiraw_COLOR_0189,
    ov02bmipiraw_COLOR_0190, ov02bmipiraw_COLOR_0191, ov02bmipiraw_COLOR_0192, ov02bmipiraw_COLOR_0193, ov02bmipiraw_COLOR_0194, ov02bmipiraw_COLOR_0195, ov02bmipiraw_COLOR_0196, ov02bmipiraw_COLOR_0197, ov02bmipiraw_COLOR_0198, ov02bmipiraw_COLOR_0199,
    ov02bmipiraw_COLOR_0200, ov02bmipiraw_COLOR_0201, ov02bmipiraw_COLOR_0202, ov02bmipiraw_COLOR_0203, ov02bmipiraw_COLOR_0204, ov02bmipiraw_COLOR_0205, ov02bmipiraw_COLOR_0206, ov02bmipiraw_COLOR_0207, ov02bmipiraw_COLOR_0208, ov02bmipiraw_COLOR_0209,
    ov02bmipiraw_COLOR_0210, ov02bmipiraw_COLOR_0211, ov02bmipiraw_COLOR_0212, ov02bmipiraw_COLOR_0213, ov02bmipiraw_COLOR_0214, ov02bmipiraw_COLOR_0215, ov02bmipiraw_COLOR_0216, ov02bmipiraw_COLOR_0217, ov02bmipiraw_COLOR_0218, ov02bmipiraw_COLOR_0219,
    ov02bmipiraw_COLOR_0220, ov02bmipiraw_COLOR_0221, ov02bmipiraw_COLOR_0222, ov02bmipiraw_COLOR_0223, ov02bmipiraw_COLOR_0224, ov02bmipiraw_COLOR_0225, ov02bmipiraw_COLOR_0226, ov02bmipiraw_COLOR_0227, ov02bmipiraw_COLOR_0228, ov02bmipiraw_COLOR_0229,
    ov02bmipiraw_COLOR_0230, ov02bmipiraw_COLOR_0231, ov02bmipiraw_COLOR_0232, ov02bmipiraw_COLOR_0233, ov02bmipiraw_COLOR_0234, ov02bmipiraw_COLOR_0235, ov02bmipiraw_COLOR_0236, ov02bmipiraw_COLOR_0237, ov02bmipiraw_COLOR_0238, ov02bmipiraw_COLOR_0239,
    ov02bmipiraw_COLOR_0240, ov02bmipiraw_COLOR_0241, ov02bmipiraw_COLOR_0242, ov02bmipiraw_COLOR_0243, ov02bmipiraw_COLOR_0244, ov02bmipiraw_COLOR_0245, ov02bmipiraw_COLOR_0246, ov02bmipiraw_COLOR_0247, ov02bmipiraw_COLOR_0248, ov02bmipiraw_COLOR_0249,
    ov02bmipiraw_COLOR_0250, ov02bmipiraw_COLOR_0251, ov02bmipiraw_COLOR_0252, ov02bmipiraw_COLOR_0253, ov02bmipiraw_COLOR_0254, ov02bmipiraw_COLOR_0255, ov02bmipiraw_COLOR_0256, ov02bmipiraw_COLOR_0257, ov02bmipiraw_COLOR_0258, ov02bmipiraw_COLOR_0259,
    ov02bmipiraw_COLOR_0260, ov02bmipiraw_COLOR_0261, ov02bmipiraw_COLOR_0262, ov02bmipiraw_COLOR_0263, ov02bmipiraw_COLOR_0264, ov02bmipiraw_COLOR_0265, ov02bmipiraw_COLOR_0266, ov02bmipiraw_COLOR_0267, ov02bmipiraw_COLOR_0268, ov02bmipiraw_COLOR_0269,
    ov02bmipiraw_COLOR_0270, ov02bmipiraw_COLOR_0271, ov02bmipiraw_COLOR_0272, ov02bmipiraw_COLOR_0273, ov02bmipiraw_COLOR_0274, ov02bmipiraw_COLOR_0275, ov02bmipiraw_COLOR_0276, ov02bmipiraw_COLOR_0277, ov02bmipiraw_COLOR_0278, ov02bmipiraw_COLOR_0279,
    ov02bmipiraw_COLOR_0280, ov02bmipiraw_COLOR_0281, ov02bmipiraw_COLOR_0282, ov02bmipiraw_COLOR_0283, ov02bmipiraw_COLOR_0284, ov02bmipiraw_COLOR_0285, ov02bmipiraw_COLOR_0286, ov02bmipiraw_COLOR_0287, ov02bmipiraw_COLOR_0288, ov02bmipiraw_COLOR_0289,
    ov02bmipiraw_COLOR_0290, ov02bmipiraw_COLOR_0291, ov02bmipiraw_COLOR_0292, ov02bmipiraw_COLOR_0293, ov02bmipiraw_COLOR_0294, ov02bmipiraw_COLOR_0295, ov02bmipiraw_COLOR_0296, ov02bmipiraw_COLOR_0297, ov02bmipiraw_COLOR_0298, ov02bmipiraw_COLOR_0299,
    ov02bmipiraw_COLOR_0300, ov02bmipiraw_COLOR_0301, ov02bmipiraw_COLOR_0302, ov02bmipiraw_COLOR_0303, ov02bmipiraw_COLOR_0304, ov02bmipiraw_COLOR_0305, ov02bmipiraw_COLOR_0306, ov02bmipiraw_COLOR_0307, ov02bmipiraw_COLOR_0308, ov02bmipiraw_COLOR_0309,
    ov02bmipiraw_COLOR_0310, ov02bmipiraw_COLOR_0311, ov02bmipiraw_COLOR_0312, ov02bmipiraw_COLOR_0313, ov02bmipiraw_COLOR_0314, ov02bmipiraw_COLOR_0315, ov02bmipiraw_COLOR_0316, ov02bmipiraw_COLOR_0317, ov02bmipiraw_COLOR_0318, ov02bmipiraw_COLOR_0319,
    ov02bmipiraw_COLOR_0320, ov02bmipiraw_COLOR_0321, ov02bmipiraw_COLOR_0322, ov02bmipiraw_COLOR_0323, ov02bmipiraw_COLOR_0324, ov02bmipiraw_COLOR_0325, ov02bmipiraw_COLOR_0326, ov02bmipiraw_COLOR_0327, ov02bmipiraw_COLOR_0328, ov02bmipiraw_COLOR_0329,
    ov02bmipiraw_COLOR_0330, ov02bmipiraw_COLOR_0331, ov02bmipiraw_COLOR_0332, ov02bmipiraw_COLOR_0333, ov02bmipiraw_COLOR_0334, ov02bmipiraw_COLOR_0335, ov02bmipiraw_COLOR_0336, ov02bmipiraw_COLOR_0337, ov02bmipiraw_COLOR_0338, ov02bmipiraw_COLOR_0339,
    ov02bmipiraw_COLOR_0340, ov02bmipiraw_COLOR_0341, ov02bmipiraw_COLOR_0342, ov02bmipiraw_COLOR_0343, ov02bmipiraw_COLOR_0344, ov02bmipiraw_COLOR_0345, ov02bmipiraw_COLOR_0346, ov02bmipiraw_COLOR_0347, ov02bmipiraw_COLOR_0348, ov02bmipiraw_COLOR_0349,
    ov02bmipiraw_COLOR_0350, ov02bmipiraw_COLOR_0351, ov02bmipiraw_COLOR_0352, ov02bmipiraw_COLOR_0353, ov02bmipiraw_COLOR_0354, ov02bmipiraw_COLOR_0355, ov02bmipiraw_COLOR_0356, ov02bmipiraw_COLOR_0357, ov02bmipiraw_COLOR_0358, ov02bmipiraw_COLOR_0359,
    ov02bmipiraw_COLOR_0360, ov02bmipiraw_COLOR_0361, ov02bmipiraw_COLOR_0362, ov02bmipiraw_COLOR_0363, ov02bmipiraw_COLOR_0364, ov02bmipiraw_COLOR_0365, ov02bmipiraw_COLOR_0366, ov02bmipiraw_COLOR_0367, ov02bmipiraw_COLOR_0368, ov02bmipiraw_COLOR_0369,
    ov02bmipiraw_COLOR_0370, ov02bmipiraw_COLOR_0371, ov02bmipiraw_COLOR_0372, ov02bmipiraw_COLOR_0373, ov02bmipiraw_COLOR_0374, ov02bmipiraw_COLOR_0375, ov02bmipiraw_COLOR_0376, ov02bmipiraw_COLOR_0377, ov02bmipiraw_COLOR_0378, ov02bmipiraw_COLOR_0379,
    ov02bmipiraw_COLOR_0380, ov02bmipiraw_COLOR_0381, ov02bmipiraw_COLOR_0382, ov02bmipiraw_COLOR_0383, ov02bmipiraw_COLOR_0384, ov02bmipiraw_COLOR_0385, ov02bmipiraw_COLOR_0386, ov02bmipiraw_COLOR_0387, ov02bmipiraw_COLOR_0388, ov02bmipiraw_COLOR_0389,
    ov02bmipiraw_COLOR_0390, ov02bmipiraw_COLOR_0391, ov02bmipiraw_COLOR_0392, ov02bmipiraw_COLOR_0393, ov02bmipiraw_COLOR_0394, ov02bmipiraw_COLOR_0395, ov02bmipiraw_COLOR_0396, ov02bmipiraw_COLOR_0397, ov02bmipiraw_COLOR_0398, ov02bmipiraw_COLOR_0399,
    ov02bmipiraw_COLOR_0400, ov02bmipiraw_COLOR_0401, ov02bmipiraw_COLOR_0402, ov02bmipiraw_COLOR_0403, ov02bmipiraw_COLOR_0404, ov02bmipiraw_COLOR_0405, ov02bmipiraw_COLOR_0406, ov02bmipiraw_COLOR_0407, ov02bmipiraw_COLOR_0408, ov02bmipiraw_COLOR_0409,
    ov02bmipiraw_COLOR_0410, ov02bmipiraw_COLOR_0411, ov02bmipiraw_COLOR_0412, ov02bmipiraw_COLOR_0413, ov02bmipiraw_COLOR_0414, ov02bmipiraw_COLOR_0415, ov02bmipiraw_COLOR_0416, ov02bmipiraw_COLOR_0417, ov02bmipiraw_COLOR_0418, ov02bmipiraw_COLOR_0419,
    ov02bmipiraw_COLOR_0420, ov02bmipiraw_COLOR_0421, ov02bmipiraw_COLOR_0422, ov02bmipiraw_COLOR_0423, ov02bmipiraw_COLOR_0424, ov02bmipiraw_COLOR_0425, ov02bmipiraw_COLOR_0426, ov02bmipiraw_COLOR_0427, ov02bmipiraw_COLOR_0428, ov02bmipiraw_COLOR_0429,
    ov02bmipiraw_COLOR_0430, ov02bmipiraw_COLOR_0431, ov02bmipiraw_COLOR_0432, ov02bmipiraw_COLOR_0433, ov02bmipiraw_COLOR_0434, ov02bmipiraw_COLOR_0435, ov02bmipiraw_COLOR_0436, ov02bmipiraw_COLOR_0437, ov02bmipiraw_COLOR_0438, ov02bmipiraw_COLOR_0439,
    ov02bmipiraw_COLOR_0440, ov02bmipiraw_COLOR_0441, ov02bmipiraw_COLOR_0442, ov02bmipiraw_COLOR_0443, ov02bmipiraw_COLOR_0444, ov02bmipiraw_COLOR_0445, ov02bmipiraw_COLOR_0446, ov02bmipiraw_COLOR_0447, ov02bmipiraw_COLOR_0448, ov02bmipiraw_COLOR_0449,
    ov02bmipiraw_COLOR_0450, ov02bmipiraw_COLOR_0451, ov02bmipiraw_COLOR_0452, ov02bmipiraw_COLOR_0453, ov02bmipiraw_COLOR_0454, ov02bmipiraw_COLOR_0455, ov02bmipiraw_COLOR_0456, ov02bmipiraw_COLOR_0457, ov02bmipiraw_COLOR_0458, ov02bmipiraw_COLOR_0459,
    ov02bmipiraw_COLOR_0460, ov02bmipiraw_COLOR_0461, ov02bmipiraw_COLOR_0462, ov02bmipiraw_COLOR_0463, ov02bmipiraw_COLOR_0464, ov02bmipiraw_COLOR_0465, ov02bmipiraw_COLOR_0466, ov02bmipiraw_COLOR_0467, ov02bmipiraw_COLOR_0468, ov02bmipiraw_COLOR_0469,
    ov02bmipiraw_COLOR_0470, ov02bmipiraw_COLOR_0471, ov02bmipiraw_COLOR_0472, ov02bmipiraw_COLOR_0473, ov02bmipiraw_COLOR_0474, ov02bmipiraw_COLOR_0475, ov02bmipiraw_COLOR_0476, ov02bmipiraw_COLOR_0477, ov02bmipiraw_COLOR_0478, ov02bmipiraw_COLOR_0479,
    ov02bmipiraw_COLOR_0480, ov02bmipiraw_COLOR_0481, ov02bmipiraw_COLOR_0482, ov02bmipiraw_COLOR_0483, ov02bmipiraw_COLOR_0484, ov02bmipiraw_COLOR_0485, ov02bmipiraw_COLOR_0486, ov02bmipiraw_COLOR_0487, ov02bmipiraw_COLOR_0488, ov02bmipiraw_COLOR_0489,
    ov02bmipiraw_COLOR_0490, ov02bmipiraw_COLOR_0491, ov02bmipiraw_COLOR_0492, ov02bmipiraw_COLOR_0493, ov02bmipiraw_COLOR_0494, ov02bmipiraw_COLOR_0495, ov02bmipiraw_COLOR_0496, ov02bmipiraw_COLOR_0497, ov02bmipiraw_COLOR_0498, ov02bmipiraw_COLOR_0499,
    ov02bmipiraw_COLOR_0500, ov02bmipiraw_COLOR_0501, ov02bmipiraw_COLOR_0502, ov02bmipiraw_COLOR_0503, ov02bmipiraw_COLOR_0504, ov02bmipiraw_COLOR_0505, ov02bmipiraw_COLOR_0506, ov02bmipiraw_COLOR_0507, ov02bmipiraw_COLOR_0508, ov02bmipiraw_COLOR_0509,
    ov02bmipiraw_COLOR_0510, ov02bmipiraw_COLOR_0511, ov02bmipiraw_COLOR_0512, ov02bmipiraw_COLOR_0513, ov02bmipiraw_COLOR_0514, ov02bmipiraw_COLOR_0515, ov02bmipiraw_COLOR_0516, ov02bmipiraw_COLOR_0517, ov02bmipiraw_COLOR_0518, ov02bmipiraw_COLOR_0519,
    ov02bmipiraw_COLOR_0520, ov02bmipiraw_COLOR_0521, ov02bmipiraw_COLOR_0522, ov02bmipiraw_COLOR_0523, ov02bmipiraw_COLOR_0524, ov02bmipiraw_COLOR_0525, ov02bmipiraw_COLOR_0526, ov02bmipiraw_COLOR_0527, ov02bmipiraw_COLOR_0528, ov02bmipiraw_COLOR_0529,
    ov02bmipiraw_COLOR_0530, ov02bmipiraw_COLOR_0531, ov02bmipiraw_COLOR_0532, ov02bmipiraw_COLOR_0533, ov02bmipiraw_COLOR_0534, ov02bmipiraw_COLOR_0535, ov02bmipiraw_COLOR_0536, ov02bmipiraw_COLOR_0537, ov02bmipiraw_COLOR_0538, ov02bmipiraw_COLOR_0539,
    ov02bmipiraw_COLOR_0540, ov02bmipiraw_COLOR_0541, ov02bmipiraw_COLOR_0542, ov02bmipiraw_COLOR_0543, ov02bmipiraw_COLOR_0544, ov02bmipiraw_COLOR_0545, ov02bmipiraw_COLOR_0546, ov02bmipiraw_COLOR_0547, ov02bmipiraw_COLOR_0548, ov02bmipiraw_COLOR_0549,
    ov02bmipiraw_COLOR_0550, ov02bmipiraw_COLOR_0551, ov02bmipiraw_COLOR_0552, ov02bmipiraw_COLOR_0553, ov02bmipiraw_COLOR_0554, ov02bmipiraw_COLOR_0555, ov02bmipiraw_COLOR_0556, ov02bmipiraw_COLOR_0557, ov02bmipiraw_COLOR_0558, ov02bmipiraw_COLOR_0559,
    ov02bmipiraw_COLOR_0560, ov02bmipiraw_COLOR_0561, ov02bmipiraw_COLOR_0562, ov02bmipiraw_COLOR_0563, ov02bmipiraw_COLOR_0564, ov02bmipiraw_COLOR_0565, ov02bmipiraw_COLOR_0566, ov02bmipiraw_COLOR_0567, ov02bmipiraw_COLOR_0568, ov02bmipiraw_COLOR_0569,
    ov02bmipiraw_COLOR_0570, ov02bmipiraw_COLOR_0571, ov02bmipiraw_COLOR_0572, ov02bmipiraw_COLOR_0573, ov02bmipiraw_COLOR_0574, ov02bmipiraw_COLOR_0575, ov02bmipiraw_COLOR_0576, ov02bmipiraw_COLOR_0577, ov02bmipiraw_COLOR_0578, ov02bmipiraw_COLOR_0579,
    ov02bmipiraw_COLOR_0580, ov02bmipiraw_COLOR_0581, ov02bmipiraw_COLOR_0582, ov02bmipiraw_COLOR_0583, ov02bmipiraw_COLOR_0584, ov02bmipiraw_COLOR_0585, ov02bmipiraw_COLOR_0586, ov02bmipiraw_COLOR_0587, ov02bmipiraw_COLOR_0588, ov02bmipiraw_COLOR_0589,
    ov02bmipiraw_COLOR_0590, ov02bmipiraw_COLOR_0591, ov02bmipiraw_COLOR_0592, ov02bmipiraw_COLOR_0593, ov02bmipiraw_COLOR_0594, ov02bmipiraw_COLOR_0595, ov02bmipiraw_COLOR_0596, ov02bmipiraw_COLOR_0597, ov02bmipiraw_COLOR_0598, ov02bmipiraw_COLOR_0599,
    ov02bmipiraw_COLOR_0600, ov02bmipiraw_COLOR_0601, ov02bmipiraw_COLOR_0602, ov02bmipiraw_COLOR_0603, ov02bmipiraw_COLOR_0604, ov02bmipiraw_COLOR_0605, ov02bmipiraw_COLOR_0606, ov02bmipiraw_COLOR_0607, ov02bmipiraw_COLOR_0608, ov02bmipiraw_COLOR_0609,
    ov02bmipiraw_COLOR_0610, ov02bmipiraw_COLOR_0611, ov02bmipiraw_COLOR_0612, ov02bmipiraw_COLOR_0613, ov02bmipiraw_COLOR_0614, ov02bmipiraw_COLOR_0615, ov02bmipiraw_COLOR_0616, ov02bmipiraw_COLOR_0617, ov02bmipiraw_COLOR_0618, ov02bmipiraw_COLOR_0619,
    ov02bmipiraw_COLOR_0620, ov02bmipiraw_COLOR_0621, ov02bmipiraw_COLOR_0622, ov02bmipiraw_COLOR_0623, ov02bmipiraw_COLOR_0624, ov02bmipiraw_COLOR_0625, ov02bmipiraw_COLOR_0626, ov02bmipiraw_COLOR_0627, ov02bmipiraw_COLOR_0628, ov02bmipiraw_COLOR_0629,
    ov02bmipiraw_COLOR_0630, ov02bmipiraw_COLOR_0631, ov02bmipiraw_COLOR_0632, ov02bmipiraw_COLOR_0633, ov02bmipiraw_COLOR_0634, ov02bmipiraw_COLOR_0635, ov02bmipiraw_COLOR_0636, ov02bmipiraw_COLOR_0637, ov02bmipiraw_COLOR_0638, ov02bmipiraw_COLOR_0639,
    ov02bmipiraw_COLOR_0640, ov02bmipiraw_COLOR_0641, ov02bmipiraw_COLOR_0642, ov02bmipiraw_COLOR_0643, ov02bmipiraw_COLOR_0644, ov02bmipiraw_COLOR_0645, ov02bmipiraw_COLOR_0646, ov02bmipiraw_COLOR_0647, ov02bmipiraw_COLOR_0648, ov02bmipiraw_COLOR_0649,
    ov02bmipiraw_COLOR_0650, ov02bmipiraw_COLOR_0651, ov02bmipiraw_COLOR_0652, ov02bmipiraw_COLOR_0653, ov02bmipiraw_COLOR_0654, ov02bmipiraw_COLOR_0655, ov02bmipiraw_COLOR_0656, ov02bmipiraw_COLOR_0657, ov02bmipiraw_COLOR_0658, ov02bmipiraw_COLOR_0659,
    ov02bmipiraw_COLOR_0660, ov02bmipiraw_COLOR_0661, ov02bmipiraw_COLOR_0662, ov02bmipiraw_COLOR_0663, ov02bmipiraw_COLOR_0664, ov02bmipiraw_COLOR_0665, ov02bmipiraw_COLOR_0666, ov02bmipiraw_COLOR_0667, ov02bmipiraw_COLOR_0668, ov02bmipiraw_COLOR_0669,
    ov02bmipiraw_COLOR_0670, ov02bmipiraw_COLOR_0671, ov02bmipiraw_COLOR_0672, ov02bmipiraw_COLOR_0673, ov02bmipiraw_COLOR_0674, ov02bmipiraw_COLOR_0675, ov02bmipiraw_COLOR_0676, ov02bmipiraw_COLOR_0677, ov02bmipiraw_COLOR_0678, ov02bmipiraw_COLOR_0679,
    ov02bmipiraw_COLOR_0680, ov02bmipiraw_COLOR_0681, ov02bmipiraw_COLOR_0682, ov02bmipiraw_COLOR_0683, ov02bmipiraw_COLOR_0684, ov02bmipiraw_COLOR_0685, ov02bmipiraw_COLOR_0686, ov02bmipiraw_COLOR_0687, ov02bmipiraw_COLOR_0688, ov02bmipiraw_COLOR_0689,
    ov02bmipiraw_COLOR_0690, ov02bmipiraw_COLOR_0691, ov02bmipiraw_COLOR_0692, ov02bmipiraw_COLOR_0693, ov02bmipiraw_COLOR_0694, ov02bmipiraw_COLOR_0695, ov02bmipiraw_COLOR_0696, ov02bmipiraw_COLOR_0697, ov02bmipiraw_COLOR_0698, ov02bmipiraw_COLOR_0699,
    ov02bmipiraw_COLOR_0700, ov02bmipiraw_COLOR_0701, ov02bmipiraw_COLOR_0702, ov02bmipiraw_COLOR_0703, ov02bmipiraw_COLOR_0704, ov02bmipiraw_COLOR_0705, ov02bmipiraw_COLOR_0706, ov02bmipiraw_COLOR_0707, ov02bmipiraw_COLOR_0708, ov02bmipiraw_COLOR_0709,
    ov02bmipiraw_COLOR_0710, ov02bmipiraw_COLOR_0711, ov02bmipiraw_COLOR_0712, ov02bmipiraw_COLOR_0713, ov02bmipiraw_COLOR_0714, ov02bmipiraw_COLOR_0715, ov02bmipiraw_COLOR_0716, ov02bmipiraw_COLOR_0717, ov02bmipiraw_COLOR_0718, ov02bmipiraw_COLOR_0719,
    ov02bmipiraw_COLOR_0720, ov02bmipiraw_COLOR_0721, ov02bmipiraw_COLOR_0722, ov02bmipiraw_COLOR_0723, ov02bmipiraw_COLOR_0724, ov02bmipiraw_COLOR_0725, ov02bmipiraw_COLOR_0726, ov02bmipiraw_COLOR_0727, ov02bmipiraw_COLOR_0728, ov02bmipiraw_COLOR_0729,
    ov02bmipiraw_COLOR_0730, ov02bmipiraw_COLOR_0731, ov02bmipiraw_COLOR_0732, ov02bmipiraw_COLOR_0733, ov02bmipiraw_COLOR_0734, ov02bmipiraw_COLOR_0735, ov02bmipiraw_COLOR_0736, ov02bmipiraw_COLOR_0737, ov02bmipiraw_COLOR_0738, ov02bmipiraw_COLOR_0739,
    ov02bmipiraw_COLOR_0740, ov02bmipiraw_COLOR_0741, ov02bmipiraw_COLOR_0742, ov02bmipiraw_COLOR_0743, ov02bmipiraw_COLOR_0744, ov02bmipiraw_COLOR_0745, ov02bmipiraw_COLOR_0746, ov02bmipiraw_COLOR_0747, ov02bmipiraw_COLOR_0748, ov02bmipiraw_COLOR_0749,
    ov02bmipiraw_COLOR_0750, ov02bmipiraw_COLOR_0751, ov02bmipiraw_COLOR_0752, ov02bmipiraw_COLOR_0753, ov02bmipiraw_COLOR_0754, ov02bmipiraw_COLOR_0755, ov02bmipiraw_COLOR_0756, ov02bmipiraw_COLOR_0757, ov02bmipiraw_COLOR_0758, ov02bmipiraw_COLOR_0759,
    ov02bmipiraw_COLOR_0760, ov02bmipiraw_COLOR_0761, ov02bmipiraw_COLOR_0762, ov02bmipiraw_COLOR_0763, ov02bmipiraw_COLOR_0764, ov02bmipiraw_COLOR_0765, ov02bmipiraw_COLOR_0766, ov02bmipiraw_COLOR_0767, ov02bmipiraw_COLOR_0768, ov02bmipiraw_COLOR_0769,
    ov02bmipiraw_COLOR_0770, ov02bmipiraw_COLOR_0771, ov02bmipiraw_COLOR_0772, ov02bmipiraw_COLOR_0773, ov02bmipiraw_COLOR_0774, ov02bmipiraw_COLOR_0775, ov02bmipiraw_COLOR_0776, ov02bmipiraw_COLOR_0777, ov02bmipiraw_COLOR_0778, ov02bmipiraw_COLOR_0779,
    ov02bmipiraw_COLOR_0780, ov02bmipiraw_COLOR_0781, ov02bmipiraw_COLOR_0782, ov02bmipiraw_COLOR_0783, ov02bmipiraw_COLOR_0784, ov02bmipiraw_COLOR_0785, ov02bmipiraw_COLOR_0786, ov02bmipiraw_COLOR_0787, ov02bmipiraw_COLOR_0788, ov02bmipiraw_COLOR_0789,
    ov02bmipiraw_COLOR_0790, ov02bmipiraw_COLOR_0791, ov02bmipiraw_COLOR_0792, ov02bmipiraw_COLOR_0793, ov02bmipiraw_COLOR_0794, ov02bmipiraw_COLOR_0795, ov02bmipiraw_COLOR_0796, ov02bmipiraw_COLOR_0797, ov02bmipiraw_COLOR_0798, ov02bmipiraw_COLOR_0799,
    ov02bmipiraw_COLOR_0800, ov02bmipiraw_COLOR_0801, ov02bmipiraw_COLOR_0802, ov02bmipiraw_COLOR_0803, ov02bmipiraw_COLOR_0804, ov02bmipiraw_COLOR_0805, ov02bmipiraw_COLOR_0806, ov02bmipiraw_COLOR_0807, ov02bmipiraw_COLOR_0808, ov02bmipiraw_COLOR_0809,
    ov02bmipiraw_COLOR_0810, ov02bmipiraw_COLOR_0811, ov02bmipiraw_COLOR_0812, ov02bmipiraw_COLOR_0813, ov02bmipiraw_COLOR_0814, ov02bmipiraw_COLOR_0815, ov02bmipiraw_COLOR_0816, ov02bmipiraw_COLOR_0817, ov02bmipiraw_COLOR_0818, ov02bmipiraw_COLOR_0819,
    ov02bmipiraw_COLOR_0820, ov02bmipiraw_COLOR_0821, ov02bmipiraw_COLOR_0822, ov02bmipiraw_COLOR_0823, ov02bmipiraw_COLOR_0824, ov02bmipiraw_COLOR_0825, ov02bmipiraw_COLOR_0826, ov02bmipiraw_COLOR_0827, ov02bmipiraw_COLOR_0828, ov02bmipiraw_COLOR_0829,
    ov02bmipiraw_COLOR_0830, ov02bmipiraw_COLOR_0831, ov02bmipiraw_COLOR_0832, ov02bmipiraw_COLOR_0833, ov02bmipiraw_COLOR_0834, ov02bmipiraw_COLOR_0835, ov02bmipiraw_COLOR_0836, ov02bmipiraw_COLOR_0837, ov02bmipiraw_COLOR_0838, ov02bmipiraw_COLOR_0839,
    ov02bmipiraw_COLOR_0840, ov02bmipiraw_COLOR_0841, ov02bmipiraw_COLOR_0842, ov02bmipiraw_COLOR_0843, ov02bmipiraw_COLOR_0844, ov02bmipiraw_COLOR_0845, ov02bmipiraw_COLOR_0846, ov02bmipiraw_COLOR_0847, ov02bmipiraw_COLOR_0848, ov02bmipiraw_COLOR_0849,
    ov02bmipiraw_COLOR_0850, ov02bmipiraw_COLOR_0851, ov02bmipiraw_COLOR_0852, ov02bmipiraw_COLOR_0853, ov02bmipiraw_COLOR_0854, ov02bmipiraw_COLOR_0855, ov02bmipiraw_COLOR_0856, ov02bmipiraw_COLOR_0857, ov02bmipiraw_COLOR_0858, ov02bmipiraw_COLOR_0859,
    ov02bmipiraw_COLOR_0860, ov02bmipiraw_COLOR_0861, ov02bmipiraw_COLOR_0862, ov02bmipiraw_COLOR_0863, ov02bmipiraw_COLOR_0864, ov02bmipiraw_COLOR_0865, ov02bmipiraw_COLOR_0866, ov02bmipiraw_COLOR_0867, ov02bmipiraw_COLOR_0868, ov02bmipiraw_COLOR_0869,
    ov02bmipiraw_COLOR_0870, ov02bmipiraw_COLOR_0871, ov02bmipiraw_COLOR_0872, ov02bmipiraw_COLOR_0873, ov02bmipiraw_COLOR_0874, ov02bmipiraw_COLOR_0875, ov02bmipiraw_COLOR_0876, ov02bmipiraw_COLOR_0877, ov02bmipiraw_COLOR_0878, ov02bmipiraw_COLOR_0879,
    ov02bmipiraw_COLOR_0880, ov02bmipiraw_COLOR_0881, ov02bmipiraw_COLOR_0882, ov02bmipiraw_COLOR_0883, ov02bmipiraw_COLOR_0884, ov02bmipiraw_COLOR_0885, ov02bmipiraw_COLOR_0886, ov02bmipiraw_COLOR_0887, ov02bmipiraw_COLOR_0888, ov02bmipiraw_COLOR_0889,
    ov02bmipiraw_COLOR_0890, ov02bmipiraw_COLOR_0891, ov02bmipiraw_COLOR_0892, ov02bmipiraw_COLOR_0893, ov02bmipiraw_COLOR_0894, ov02bmipiraw_COLOR_0895, ov02bmipiraw_COLOR_0896, ov02bmipiraw_COLOR_0897, ov02bmipiraw_COLOR_0898, ov02bmipiraw_COLOR_0899,
    ov02bmipiraw_COLOR_0900, ov02bmipiraw_COLOR_0901, ov02bmipiraw_COLOR_0902, ov02bmipiraw_COLOR_0903, ov02bmipiraw_COLOR_0904, ov02bmipiraw_COLOR_0905, ov02bmipiraw_COLOR_0906, ov02bmipiraw_COLOR_0907, ov02bmipiraw_COLOR_0908, ov02bmipiraw_COLOR_0909,
    ov02bmipiraw_COLOR_0910, ov02bmipiraw_COLOR_0911, ov02bmipiraw_COLOR_0912, ov02bmipiraw_COLOR_0913, ov02bmipiraw_COLOR_0914, ov02bmipiraw_COLOR_0915, ov02bmipiraw_COLOR_0916, ov02bmipiraw_COLOR_0917, ov02bmipiraw_COLOR_0918, ov02bmipiraw_COLOR_0919,
    ov02bmipiraw_COLOR_0920, ov02bmipiraw_COLOR_0921, ov02bmipiraw_COLOR_0922, ov02bmipiraw_COLOR_0923, ov02bmipiraw_COLOR_0924, ov02bmipiraw_COLOR_0925, ov02bmipiraw_COLOR_0926, ov02bmipiraw_COLOR_0927, ov02bmipiraw_COLOR_0928, ov02bmipiraw_COLOR_0929,
    ov02bmipiraw_COLOR_0930, ov02bmipiraw_COLOR_0931, ov02bmipiraw_COLOR_0932, ov02bmipiraw_COLOR_0933, ov02bmipiraw_COLOR_0934, ov02bmipiraw_COLOR_0935, ov02bmipiraw_COLOR_0936, ov02bmipiraw_COLOR_0937, ov02bmipiraw_COLOR_0938, ov02bmipiraw_COLOR_0939,
    ov02bmipiraw_COLOR_0940, ov02bmipiraw_COLOR_0941, ov02bmipiraw_COLOR_0942, ov02bmipiraw_COLOR_0943, ov02bmipiraw_COLOR_0944, ov02bmipiraw_COLOR_0945, ov02bmipiraw_COLOR_0946, ov02bmipiraw_COLOR_0947, ov02bmipiraw_COLOR_0948, ov02bmipiraw_COLOR_0949,
    ov02bmipiraw_COLOR_0950, ov02bmipiraw_COLOR_0951, ov02bmipiraw_COLOR_0952, ov02bmipiraw_COLOR_0953, ov02bmipiraw_COLOR_0954, ov02bmipiraw_COLOR_0955, ov02bmipiraw_COLOR_0956, ov02bmipiraw_COLOR_0957, ov02bmipiraw_COLOR_0958, ov02bmipiraw_COLOR_0959,
},
.PCA = {
    ov02bmipiraw_PCA_0000,
},
.COLOR_PARAM = {
    ov02bmipiraw_COLOR_PARAM_0000, ov02bmipiraw_COLOR_PARAM_0001, ov02bmipiraw_COLOR_PARAM_0002, ov02bmipiraw_COLOR_PARAM_0003, ov02bmipiraw_COLOR_PARAM_0004, ov02bmipiraw_COLOR_PARAM_0005, ov02bmipiraw_COLOR_PARAM_0006, ov02bmipiraw_COLOR_PARAM_0007, ov02bmipiraw_COLOR_PARAM_0008, ov02bmipiraw_COLOR_PARAM_0009,
    ov02bmipiraw_COLOR_PARAM_0010, ov02bmipiraw_COLOR_PARAM_0011, ov02bmipiraw_COLOR_PARAM_0012, ov02bmipiraw_COLOR_PARAM_0013, ov02bmipiraw_COLOR_PARAM_0014, ov02bmipiraw_COLOR_PARAM_0015,
},
