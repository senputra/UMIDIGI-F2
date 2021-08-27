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
    gc2385mipiraw_CCM_0000, gc2385mipiraw_CCM_0001, gc2385mipiraw_CCM_0002, gc2385mipiraw_CCM_0003, gc2385mipiraw_CCM_0004, gc2385mipiraw_CCM_0005, gc2385mipiraw_CCM_0006, gc2385mipiraw_CCM_0007, gc2385mipiraw_CCM_0008, gc2385mipiraw_CCM_0009,
    gc2385mipiraw_CCM_0010, gc2385mipiraw_CCM_0011, gc2385mipiraw_CCM_0012, gc2385mipiraw_CCM_0013, gc2385mipiraw_CCM_0014, gc2385mipiraw_CCM_0015, gc2385mipiraw_CCM_0016, gc2385mipiraw_CCM_0017, gc2385mipiraw_CCM_0018, gc2385mipiraw_CCM_0019,
    gc2385mipiraw_CCM_0020, gc2385mipiraw_CCM_0021, gc2385mipiraw_CCM_0022, gc2385mipiraw_CCM_0023, gc2385mipiraw_CCM_0024, gc2385mipiraw_CCM_0025, gc2385mipiraw_CCM_0026, gc2385mipiraw_CCM_0027, gc2385mipiraw_CCM_0028, gc2385mipiraw_CCM_0029,
    gc2385mipiraw_CCM_0030, gc2385mipiraw_CCM_0031, gc2385mipiraw_CCM_0032, gc2385mipiraw_CCM_0033, gc2385mipiraw_CCM_0034, gc2385mipiraw_CCM_0035, gc2385mipiraw_CCM_0036, gc2385mipiraw_CCM_0037, gc2385mipiraw_CCM_0038, gc2385mipiraw_CCM_0039,
    gc2385mipiraw_CCM_0040, gc2385mipiraw_CCM_0041, gc2385mipiraw_CCM_0042, gc2385mipiraw_CCM_0043, gc2385mipiraw_CCM_0044, gc2385mipiraw_CCM_0045, gc2385mipiraw_CCM_0046, gc2385mipiraw_CCM_0047, gc2385mipiraw_CCM_0048, gc2385mipiraw_CCM_0049,
    gc2385mipiraw_CCM_0050, gc2385mipiraw_CCM_0051, gc2385mipiraw_CCM_0052, gc2385mipiraw_CCM_0053, gc2385mipiraw_CCM_0054, gc2385mipiraw_CCM_0055, gc2385mipiraw_CCM_0056, gc2385mipiraw_CCM_0057, gc2385mipiraw_CCM_0058, gc2385mipiraw_CCM_0059,
    gc2385mipiraw_CCM_0060, gc2385mipiraw_CCM_0061, gc2385mipiraw_CCM_0062, gc2385mipiraw_CCM_0063, gc2385mipiraw_CCM_0064, gc2385mipiraw_CCM_0065, gc2385mipiraw_CCM_0066, gc2385mipiraw_CCM_0067, gc2385mipiraw_CCM_0068, gc2385mipiraw_CCM_0069,
    gc2385mipiraw_CCM_0070, gc2385mipiraw_CCM_0071, gc2385mipiraw_CCM_0072, gc2385mipiraw_CCM_0073, gc2385mipiraw_CCM_0074, gc2385mipiraw_CCM_0075, gc2385mipiraw_CCM_0076, gc2385mipiraw_CCM_0077, gc2385mipiraw_CCM_0078, gc2385mipiraw_CCM_0079,
    gc2385mipiraw_CCM_0080, gc2385mipiraw_CCM_0081, gc2385mipiraw_CCM_0082, gc2385mipiraw_CCM_0083, gc2385mipiraw_CCM_0084, gc2385mipiraw_CCM_0085, gc2385mipiraw_CCM_0086, gc2385mipiraw_CCM_0087, gc2385mipiraw_CCM_0088, gc2385mipiraw_CCM_0089,
    gc2385mipiraw_CCM_0090, gc2385mipiraw_CCM_0091, gc2385mipiraw_CCM_0092, gc2385mipiraw_CCM_0093, gc2385mipiraw_CCM_0094, gc2385mipiraw_CCM_0095, gc2385mipiraw_CCM_0096, gc2385mipiraw_CCM_0097, gc2385mipiraw_CCM_0098, gc2385mipiraw_CCM_0099,
    gc2385mipiraw_CCM_0100, gc2385mipiraw_CCM_0101, gc2385mipiraw_CCM_0102, gc2385mipiraw_CCM_0103, gc2385mipiraw_CCM_0104, gc2385mipiraw_CCM_0105, gc2385mipiraw_CCM_0106, gc2385mipiraw_CCM_0107, gc2385mipiraw_CCM_0108, gc2385mipiraw_CCM_0109,
    gc2385mipiraw_CCM_0110, gc2385mipiraw_CCM_0111, gc2385mipiraw_CCM_0112, gc2385mipiraw_CCM_0113, gc2385mipiraw_CCM_0114, gc2385mipiraw_CCM_0115, gc2385mipiraw_CCM_0116, gc2385mipiraw_CCM_0117, gc2385mipiraw_CCM_0118, gc2385mipiraw_CCM_0119,
    gc2385mipiraw_CCM_0120, gc2385mipiraw_CCM_0121, gc2385mipiraw_CCM_0122, gc2385mipiraw_CCM_0123, gc2385mipiraw_CCM_0124, gc2385mipiraw_CCM_0125, gc2385mipiraw_CCM_0126, gc2385mipiraw_CCM_0127, gc2385mipiraw_CCM_0128, gc2385mipiraw_CCM_0129,
    gc2385mipiraw_CCM_0130, gc2385mipiraw_CCM_0131, gc2385mipiraw_CCM_0132, gc2385mipiraw_CCM_0133, gc2385mipiraw_CCM_0134, gc2385mipiraw_CCM_0135, gc2385mipiraw_CCM_0136, gc2385mipiraw_CCM_0137, gc2385mipiraw_CCM_0138, gc2385mipiraw_CCM_0139,
    gc2385mipiraw_CCM_0140, gc2385mipiraw_CCM_0141, gc2385mipiraw_CCM_0142, gc2385mipiraw_CCM_0143, gc2385mipiraw_CCM_0144, gc2385mipiraw_CCM_0145, gc2385mipiraw_CCM_0146, gc2385mipiraw_CCM_0147, gc2385mipiraw_CCM_0148, gc2385mipiraw_CCM_0149,
    gc2385mipiraw_CCM_0150, gc2385mipiraw_CCM_0151, gc2385mipiraw_CCM_0152, gc2385mipiraw_CCM_0153, gc2385mipiraw_CCM_0154, gc2385mipiraw_CCM_0155, gc2385mipiraw_CCM_0156, gc2385mipiraw_CCM_0157, gc2385mipiraw_CCM_0158, gc2385mipiraw_CCM_0159,
    gc2385mipiraw_CCM_0160, gc2385mipiraw_CCM_0161, gc2385mipiraw_CCM_0162, gc2385mipiraw_CCM_0163, gc2385mipiraw_CCM_0164, gc2385mipiraw_CCM_0165, gc2385mipiraw_CCM_0166, gc2385mipiraw_CCM_0167, gc2385mipiraw_CCM_0168, gc2385mipiraw_CCM_0169,
    gc2385mipiraw_CCM_0170, gc2385mipiraw_CCM_0171, gc2385mipiraw_CCM_0172, gc2385mipiraw_CCM_0173, gc2385mipiraw_CCM_0174, gc2385mipiraw_CCM_0175, gc2385mipiraw_CCM_0176, gc2385mipiraw_CCM_0177, gc2385mipiraw_CCM_0178, gc2385mipiraw_CCM_0179,
    gc2385mipiraw_CCM_0180, gc2385mipiraw_CCM_0181, gc2385mipiraw_CCM_0182, gc2385mipiraw_CCM_0183, gc2385mipiraw_CCM_0184, gc2385mipiraw_CCM_0185, gc2385mipiraw_CCM_0186, gc2385mipiraw_CCM_0187, gc2385mipiraw_CCM_0188, gc2385mipiraw_CCM_0189,
    gc2385mipiraw_CCM_0190, gc2385mipiraw_CCM_0191, gc2385mipiraw_CCM_0192, gc2385mipiraw_CCM_0193, gc2385mipiraw_CCM_0194, gc2385mipiraw_CCM_0195, gc2385mipiraw_CCM_0196, gc2385mipiraw_CCM_0197, gc2385mipiraw_CCM_0198, gc2385mipiraw_CCM_0199,
    gc2385mipiraw_CCM_0200, gc2385mipiraw_CCM_0201, gc2385mipiraw_CCM_0202, gc2385mipiraw_CCM_0203, gc2385mipiraw_CCM_0204, gc2385mipiraw_CCM_0205, gc2385mipiraw_CCM_0206, gc2385mipiraw_CCM_0207, gc2385mipiraw_CCM_0208, gc2385mipiraw_CCM_0209,
    gc2385mipiraw_CCM_0210, gc2385mipiraw_CCM_0211, gc2385mipiraw_CCM_0212, gc2385mipiraw_CCM_0213, gc2385mipiraw_CCM_0214, gc2385mipiraw_CCM_0215, gc2385mipiraw_CCM_0216, gc2385mipiraw_CCM_0217, gc2385mipiraw_CCM_0218, gc2385mipiraw_CCM_0219,
    gc2385mipiraw_CCM_0220, gc2385mipiraw_CCM_0221, gc2385mipiraw_CCM_0222, gc2385mipiraw_CCM_0223, gc2385mipiraw_CCM_0224, gc2385mipiraw_CCM_0225, gc2385mipiraw_CCM_0226, gc2385mipiraw_CCM_0227, gc2385mipiraw_CCM_0228, gc2385mipiraw_CCM_0229,
    gc2385mipiraw_CCM_0230, gc2385mipiraw_CCM_0231, gc2385mipiraw_CCM_0232, gc2385mipiraw_CCM_0233, gc2385mipiraw_CCM_0234, gc2385mipiraw_CCM_0235, gc2385mipiraw_CCM_0236, gc2385mipiraw_CCM_0237, gc2385mipiraw_CCM_0238, gc2385mipiraw_CCM_0239,
},
.COLOR = {
    gc2385mipiraw_COLOR_0000, gc2385mipiraw_COLOR_0001, gc2385mipiraw_COLOR_0002, gc2385mipiraw_COLOR_0003, gc2385mipiraw_COLOR_0004, gc2385mipiraw_COLOR_0005, gc2385mipiraw_COLOR_0006, gc2385mipiraw_COLOR_0007, gc2385mipiraw_COLOR_0008, gc2385mipiraw_COLOR_0009,
    gc2385mipiraw_COLOR_0010, gc2385mipiraw_COLOR_0011, gc2385mipiraw_COLOR_0012, gc2385mipiraw_COLOR_0013, gc2385mipiraw_COLOR_0014, gc2385mipiraw_COLOR_0015, gc2385mipiraw_COLOR_0016, gc2385mipiraw_COLOR_0017, gc2385mipiraw_COLOR_0018, gc2385mipiraw_COLOR_0019,
    gc2385mipiraw_COLOR_0020, gc2385mipiraw_COLOR_0021, gc2385mipiraw_COLOR_0022, gc2385mipiraw_COLOR_0023, gc2385mipiraw_COLOR_0024, gc2385mipiraw_COLOR_0025, gc2385mipiraw_COLOR_0026, gc2385mipiraw_COLOR_0027, gc2385mipiraw_COLOR_0028, gc2385mipiraw_COLOR_0029,
    gc2385mipiraw_COLOR_0030, gc2385mipiraw_COLOR_0031, gc2385mipiraw_COLOR_0032, gc2385mipiraw_COLOR_0033, gc2385mipiraw_COLOR_0034, gc2385mipiraw_COLOR_0035, gc2385mipiraw_COLOR_0036, gc2385mipiraw_COLOR_0037, gc2385mipiraw_COLOR_0038, gc2385mipiraw_COLOR_0039,
    gc2385mipiraw_COLOR_0040, gc2385mipiraw_COLOR_0041, gc2385mipiraw_COLOR_0042, gc2385mipiraw_COLOR_0043, gc2385mipiraw_COLOR_0044, gc2385mipiraw_COLOR_0045, gc2385mipiraw_COLOR_0046, gc2385mipiraw_COLOR_0047, gc2385mipiraw_COLOR_0048, gc2385mipiraw_COLOR_0049,
    gc2385mipiraw_COLOR_0050, gc2385mipiraw_COLOR_0051, gc2385mipiraw_COLOR_0052, gc2385mipiraw_COLOR_0053, gc2385mipiraw_COLOR_0054, gc2385mipiraw_COLOR_0055, gc2385mipiraw_COLOR_0056, gc2385mipiraw_COLOR_0057, gc2385mipiraw_COLOR_0058, gc2385mipiraw_COLOR_0059,
    gc2385mipiraw_COLOR_0060, gc2385mipiraw_COLOR_0061, gc2385mipiraw_COLOR_0062, gc2385mipiraw_COLOR_0063, gc2385mipiraw_COLOR_0064, gc2385mipiraw_COLOR_0065, gc2385mipiraw_COLOR_0066, gc2385mipiraw_COLOR_0067, gc2385mipiraw_COLOR_0068, gc2385mipiraw_COLOR_0069,
    gc2385mipiraw_COLOR_0070, gc2385mipiraw_COLOR_0071, gc2385mipiraw_COLOR_0072, gc2385mipiraw_COLOR_0073, gc2385mipiraw_COLOR_0074, gc2385mipiraw_COLOR_0075, gc2385mipiraw_COLOR_0076, gc2385mipiraw_COLOR_0077, gc2385mipiraw_COLOR_0078, gc2385mipiraw_COLOR_0079,
    gc2385mipiraw_COLOR_0080, gc2385mipiraw_COLOR_0081, gc2385mipiraw_COLOR_0082, gc2385mipiraw_COLOR_0083, gc2385mipiraw_COLOR_0084, gc2385mipiraw_COLOR_0085, gc2385mipiraw_COLOR_0086, gc2385mipiraw_COLOR_0087, gc2385mipiraw_COLOR_0088, gc2385mipiraw_COLOR_0089,
    gc2385mipiraw_COLOR_0090, gc2385mipiraw_COLOR_0091, gc2385mipiraw_COLOR_0092, gc2385mipiraw_COLOR_0093, gc2385mipiraw_COLOR_0094, gc2385mipiraw_COLOR_0095, gc2385mipiraw_COLOR_0096, gc2385mipiraw_COLOR_0097, gc2385mipiraw_COLOR_0098, gc2385mipiraw_COLOR_0099,
    gc2385mipiraw_COLOR_0100, gc2385mipiraw_COLOR_0101, gc2385mipiraw_COLOR_0102, gc2385mipiraw_COLOR_0103, gc2385mipiraw_COLOR_0104, gc2385mipiraw_COLOR_0105, gc2385mipiraw_COLOR_0106, gc2385mipiraw_COLOR_0107, gc2385mipiraw_COLOR_0108, gc2385mipiraw_COLOR_0109,
    gc2385mipiraw_COLOR_0110, gc2385mipiraw_COLOR_0111, gc2385mipiraw_COLOR_0112, gc2385mipiraw_COLOR_0113, gc2385mipiraw_COLOR_0114, gc2385mipiraw_COLOR_0115, gc2385mipiraw_COLOR_0116, gc2385mipiraw_COLOR_0117, gc2385mipiraw_COLOR_0118, gc2385mipiraw_COLOR_0119,
    gc2385mipiraw_COLOR_0120, gc2385mipiraw_COLOR_0121, gc2385mipiraw_COLOR_0122, gc2385mipiraw_COLOR_0123, gc2385mipiraw_COLOR_0124, gc2385mipiraw_COLOR_0125, gc2385mipiraw_COLOR_0126, gc2385mipiraw_COLOR_0127, gc2385mipiraw_COLOR_0128, gc2385mipiraw_COLOR_0129,
    gc2385mipiraw_COLOR_0130, gc2385mipiraw_COLOR_0131, gc2385mipiraw_COLOR_0132, gc2385mipiraw_COLOR_0133, gc2385mipiraw_COLOR_0134, gc2385mipiraw_COLOR_0135, gc2385mipiraw_COLOR_0136, gc2385mipiraw_COLOR_0137, gc2385mipiraw_COLOR_0138, gc2385mipiraw_COLOR_0139,
    gc2385mipiraw_COLOR_0140, gc2385mipiraw_COLOR_0141, gc2385mipiraw_COLOR_0142, gc2385mipiraw_COLOR_0143, gc2385mipiraw_COLOR_0144, gc2385mipiraw_COLOR_0145, gc2385mipiraw_COLOR_0146, gc2385mipiraw_COLOR_0147, gc2385mipiraw_COLOR_0148, gc2385mipiraw_COLOR_0149,
    gc2385mipiraw_COLOR_0150, gc2385mipiraw_COLOR_0151, gc2385mipiraw_COLOR_0152, gc2385mipiraw_COLOR_0153, gc2385mipiraw_COLOR_0154, gc2385mipiraw_COLOR_0155, gc2385mipiraw_COLOR_0156, gc2385mipiraw_COLOR_0157, gc2385mipiraw_COLOR_0158, gc2385mipiraw_COLOR_0159,
    gc2385mipiraw_COLOR_0160, gc2385mipiraw_COLOR_0161, gc2385mipiraw_COLOR_0162, gc2385mipiraw_COLOR_0163, gc2385mipiraw_COLOR_0164, gc2385mipiraw_COLOR_0165, gc2385mipiraw_COLOR_0166, gc2385mipiraw_COLOR_0167, gc2385mipiraw_COLOR_0168, gc2385mipiraw_COLOR_0169,
    gc2385mipiraw_COLOR_0170, gc2385mipiraw_COLOR_0171, gc2385mipiraw_COLOR_0172, gc2385mipiraw_COLOR_0173, gc2385mipiraw_COLOR_0174, gc2385mipiraw_COLOR_0175, gc2385mipiraw_COLOR_0176, gc2385mipiraw_COLOR_0177, gc2385mipiraw_COLOR_0178, gc2385mipiraw_COLOR_0179,
    gc2385mipiraw_COLOR_0180, gc2385mipiraw_COLOR_0181, gc2385mipiraw_COLOR_0182, gc2385mipiraw_COLOR_0183, gc2385mipiraw_COLOR_0184, gc2385mipiraw_COLOR_0185, gc2385mipiraw_COLOR_0186, gc2385mipiraw_COLOR_0187, gc2385mipiraw_COLOR_0188, gc2385mipiraw_COLOR_0189,
    gc2385mipiraw_COLOR_0190, gc2385mipiraw_COLOR_0191, gc2385mipiraw_COLOR_0192, gc2385mipiraw_COLOR_0193, gc2385mipiraw_COLOR_0194, gc2385mipiraw_COLOR_0195, gc2385mipiraw_COLOR_0196, gc2385mipiraw_COLOR_0197, gc2385mipiraw_COLOR_0198, gc2385mipiraw_COLOR_0199,
    gc2385mipiraw_COLOR_0200, gc2385mipiraw_COLOR_0201, gc2385mipiraw_COLOR_0202, gc2385mipiraw_COLOR_0203, gc2385mipiraw_COLOR_0204, gc2385mipiraw_COLOR_0205, gc2385mipiraw_COLOR_0206, gc2385mipiraw_COLOR_0207, gc2385mipiraw_COLOR_0208, gc2385mipiraw_COLOR_0209,
    gc2385mipiraw_COLOR_0210, gc2385mipiraw_COLOR_0211, gc2385mipiraw_COLOR_0212, gc2385mipiraw_COLOR_0213, gc2385mipiraw_COLOR_0214, gc2385mipiraw_COLOR_0215, gc2385mipiraw_COLOR_0216, gc2385mipiraw_COLOR_0217, gc2385mipiraw_COLOR_0218, gc2385mipiraw_COLOR_0219,
    gc2385mipiraw_COLOR_0220, gc2385mipiraw_COLOR_0221, gc2385mipiraw_COLOR_0222, gc2385mipiraw_COLOR_0223, gc2385mipiraw_COLOR_0224, gc2385mipiraw_COLOR_0225, gc2385mipiraw_COLOR_0226, gc2385mipiraw_COLOR_0227, gc2385mipiraw_COLOR_0228, gc2385mipiraw_COLOR_0229,
    gc2385mipiraw_COLOR_0230, gc2385mipiraw_COLOR_0231, gc2385mipiraw_COLOR_0232, gc2385mipiraw_COLOR_0233, gc2385mipiraw_COLOR_0234, gc2385mipiraw_COLOR_0235, gc2385mipiraw_COLOR_0236, gc2385mipiraw_COLOR_0237, gc2385mipiraw_COLOR_0238, gc2385mipiraw_COLOR_0239,
    gc2385mipiraw_COLOR_0240, gc2385mipiraw_COLOR_0241, gc2385mipiraw_COLOR_0242, gc2385mipiraw_COLOR_0243, gc2385mipiraw_COLOR_0244, gc2385mipiraw_COLOR_0245, gc2385mipiraw_COLOR_0246, gc2385mipiraw_COLOR_0247, gc2385mipiraw_COLOR_0248, gc2385mipiraw_COLOR_0249,
    gc2385mipiraw_COLOR_0250, gc2385mipiraw_COLOR_0251, gc2385mipiraw_COLOR_0252, gc2385mipiraw_COLOR_0253, gc2385mipiraw_COLOR_0254, gc2385mipiraw_COLOR_0255, gc2385mipiraw_COLOR_0256, gc2385mipiraw_COLOR_0257, gc2385mipiraw_COLOR_0258, gc2385mipiraw_COLOR_0259,
    gc2385mipiraw_COLOR_0260, gc2385mipiraw_COLOR_0261, gc2385mipiraw_COLOR_0262, gc2385mipiraw_COLOR_0263, gc2385mipiraw_COLOR_0264, gc2385mipiraw_COLOR_0265, gc2385mipiraw_COLOR_0266, gc2385mipiraw_COLOR_0267, gc2385mipiraw_COLOR_0268, gc2385mipiraw_COLOR_0269,
    gc2385mipiraw_COLOR_0270, gc2385mipiraw_COLOR_0271, gc2385mipiraw_COLOR_0272, gc2385mipiraw_COLOR_0273, gc2385mipiraw_COLOR_0274, gc2385mipiraw_COLOR_0275, gc2385mipiraw_COLOR_0276, gc2385mipiraw_COLOR_0277, gc2385mipiraw_COLOR_0278, gc2385mipiraw_COLOR_0279,
    gc2385mipiraw_COLOR_0280, gc2385mipiraw_COLOR_0281, gc2385mipiraw_COLOR_0282, gc2385mipiraw_COLOR_0283, gc2385mipiraw_COLOR_0284, gc2385mipiraw_COLOR_0285, gc2385mipiraw_COLOR_0286, gc2385mipiraw_COLOR_0287, gc2385mipiraw_COLOR_0288, gc2385mipiraw_COLOR_0289,
    gc2385mipiraw_COLOR_0290, gc2385mipiraw_COLOR_0291, gc2385mipiraw_COLOR_0292, gc2385mipiraw_COLOR_0293, gc2385mipiraw_COLOR_0294, gc2385mipiraw_COLOR_0295, gc2385mipiraw_COLOR_0296, gc2385mipiraw_COLOR_0297, gc2385mipiraw_COLOR_0298, gc2385mipiraw_COLOR_0299,
    gc2385mipiraw_COLOR_0300, gc2385mipiraw_COLOR_0301, gc2385mipiraw_COLOR_0302, gc2385mipiraw_COLOR_0303, gc2385mipiraw_COLOR_0304, gc2385mipiraw_COLOR_0305, gc2385mipiraw_COLOR_0306, gc2385mipiraw_COLOR_0307, gc2385mipiraw_COLOR_0308, gc2385mipiraw_COLOR_0309,
    gc2385mipiraw_COLOR_0310, gc2385mipiraw_COLOR_0311, gc2385mipiraw_COLOR_0312, gc2385mipiraw_COLOR_0313, gc2385mipiraw_COLOR_0314, gc2385mipiraw_COLOR_0315, gc2385mipiraw_COLOR_0316, gc2385mipiraw_COLOR_0317, gc2385mipiraw_COLOR_0318, gc2385mipiraw_COLOR_0319,
    gc2385mipiraw_COLOR_0320, gc2385mipiraw_COLOR_0321, gc2385mipiraw_COLOR_0322, gc2385mipiraw_COLOR_0323, gc2385mipiraw_COLOR_0324, gc2385mipiraw_COLOR_0325, gc2385mipiraw_COLOR_0326, gc2385mipiraw_COLOR_0327, gc2385mipiraw_COLOR_0328, gc2385mipiraw_COLOR_0329,
    gc2385mipiraw_COLOR_0330, gc2385mipiraw_COLOR_0331, gc2385mipiraw_COLOR_0332, gc2385mipiraw_COLOR_0333, gc2385mipiraw_COLOR_0334, gc2385mipiraw_COLOR_0335, gc2385mipiraw_COLOR_0336, gc2385mipiraw_COLOR_0337, gc2385mipiraw_COLOR_0338, gc2385mipiraw_COLOR_0339,
    gc2385mipiraw_COLOR_0340, gc2385mipiraw_COLOR_0341, gc2385mipiraw_COLOR_0342, gc2385mipiraw_COLOR_0343, gc2385mipiraw_COLOR_0344, gc2385mipiraw_COLOR_0345, gc2385mipiraw_COLOR_0346, gc2385mipiraw_COLOR_0347, gc2385mipiraw_COLOR_0348, gc2385mipiraw_COLOR_0349,
    gc2385mipiraw_COLOR_0350, gc2385mipiraw_COLOR_0351, gc2385mipiraw_COLOR_0352, gc2385mipiraw_COLOR_0353, gc2385mipiraw_COLOR_0354, gc2385mipiraw_COLOR_0355, gc2385mipiraw_COLOR_0356, gc2385mipiraw_COLOR_0357, gc2385mipiraw_COLOR_0358, gc2385mipiraw_COLOR_0359,
    gc2385mipiraw_COLOR_0360, gc2385mipiraw_COLOR_0361, gc2385mipiraw_COLOR_0362, gc2385mipiraw_COLOR_0363, gc2385mipiraw_COLOR_0364, gc2385mipiraw_COLOR_0365, gc2385mipiraw_COLOR_0366, gc2385mipiraw_COLOR_0367, gc2385mipiraw_COLOR_0368, gc2385mipiraw_COLOR_0369,
    gc2385mipiraw_COLOR_0370, gc2385mipiraw_COLOR_0371, gc2385mipiraw_COLOR_0372, gc2385mipiraw_COLOR_0373, gc2385mipiraw_COLOR_0374, gc2385mipiraw_COLOR_0375, gc2385mipiraw_COLOR_0376, gc2385mipiraw_COLOR_0377, gc2385mipiraw_COLOR_0378, gc2385mipiraw_COLOR_0379,
    gc2385mipiraw_COLOR_0380, gc2385mipiraw_COLOR_0381, gc2385mipiraw_COLOR_0382, gc2385mipiraw_COLOR_0383, gc2385mipiraw_COLOR_0384, gc2385mipiraw_COLOR_0385, gc2385mipiraw_COLOR_0386, gc2385mipiraw_COLOR_0387, gc2385mipiraw_COLOR_0388, gc2385mipiraw_COLOR_0389,
    gc2385mipiraw_COLOR_0390, gc2385mipiraw_COLOR_0391, gc2385mipiraw_COLOR_0392, gc2385mipiraw_COLOR_0393, gc2385mipiraw_COLOR_0394, gc2385mipiraw_COLOR_0395, gc2385mipiraw_COLOR_0396, gc2385mipiraw_COLOR_0397, gc2385mipiraw_COLOR_0398, gc2385mipiraw_COLOR_0399,
    gc2385mipiraw_COLOR_0400, gc2385mipiraw_COLOR_0401, gc2385mipiraw_COLOR_0402, gc2385mipiraw_COLOR_0403, gc2385mipiraw_COLOR_0404, gc2385mipiraw_COLOR_0405, gc2385mipiraw_COLOR_0406, gc2385mipiraw_COLOR_0407, gc2385mipiraw_COLOR_0408, gc2385mipiraw_COLOR_0409,
    gc2385mipiraw_COLOR_0410, gc2385mipiraw_COLOR_0411, gc2385mipiraw_COLOR_0412, gc2385mipiraw_COLOR_0413, gc2385mipiraw_COLOR_0414, gc2385mipiraw_COLOR_0415, gc2385mipiraw_COLOR_0416, gc2385mipiraw_COLOR_0417, gc2385mipiraw_COLOR_0418, gc2385mipiraw_COLOR_0419,
    gc2385mipiraw_COLOR_0420, gc2385mipiraw_COLOR_0421, gc2385mipiraw_COLOR_0422, gc2385mipiraw_COLOR_0423, gc2385mipiraw_COLOR_0424, gc2385mipiraw_COLOR_0425, gc2385mipiraw_COLOR_0426, gc2385mipiraw_COLOR_0427, gc2385mipiraw_COLOR_0428, gc2385mipiraw_COLOR_0429,
    gc2385mipiraw_COLOR_0430, gc2385mipiraw_COLOR_0431, gc2385mipiraw_COLOR_0432, gc2385mipiraw_COLOR_0433, gc2385mipiraw_COLOR_0434, gc2385mipiraw_COLOR_0435, gc2385mipiraw_COLOR_0436, gc2385mipiraw_COLOR_0437, gc2385mipiraw_COLOR_0438, gc2385mipiraw_COLOR_0439,
    gc2385mipiraw_COLOR_0440, gc2385mipiraw_COLOR_0441, gc2385mipiraw_COLOR_0442, gc2385mipiraw_COLOR_0443, gc2385mipiraw_COLOR_0444, gc2385mipiraw_COLOR_0445, gc2385mipiraw_COLOR_0446, gc2385mipiraw_COLOR_0447, gc2385mipiraw_COLOR_0448, gc2385mipiraw_COLOR_0449,
    gc2385mipiraw_COLOR_0450, gc2385mipiraw_COLOR_0451, gc2385mipiraw_COLOR_0452, gc2385mipiraw_COLOR_0453, gc2385mipiraw_COLOR_0454, gc2385mipiraw_COLOR_0455, gc2385mipiraw_COLOR_0456, gc2385mipiraw_COLOR_0457, gc2385mipiraw_COLOR_0458, gc2385mipiraw_COLOR_0459,
    gc2385mipiraw_COLOR_0460, gc2385mipiraw_COLOR_0461, gc2385mipiraw_COLOR_0462, gc2385mipiraw_COLOR_0463, gc2385mipiraw_COLOR_0464, gc2385mipiraw_COLOR_0465, gc2385mipiraw_COLOR_0466, gc2385mipiraw_COLOR_0467, gc2385mipiraw_COLOR_0468, gc2385mipiraw_COLOR_0469,
    gc2385mipiraw_COLOR_0470, gc2385mipiraw_COLOR_0471, gc2385mipiraw_COLOR_0472, gc2385mipiraw_COLOR_0473, gc2385mipiraw_COLOR_0474, gc2385mipiraw_COLOR_0475, gc2385mipiraw_COLOR_0476, gc2385mipiraw_COLOR_0477, gc2385mipiraw_COLOR_0478, gc2385mipiraw_COLOR_0479,
    gc2385mipiraw_COLOR_0480, gc2385mipiraw_COLOR_0481, gc2385mipiraw_COLOR_0482, gc2385mipiraw_COLOR_0483, gc2385mipiraw_COLOR_0484, gc2385mipiraw_COLOR_0485, gc2385mipiraw_COLOR_0486, gc2385mipiraw_COLOR_0487, gc2385mipiraw_COLOR_0488, gc2385mipiraw_COLOR_0489,
    gc2385mipiraw_COLOR_0490, gc2385mipiraw_COLOR_0491, gc2385mipiraw_COLOR_0492, gc2385mipiraw_COLOR_0493, gc2385mipiraw_COLOR_0494, gc2385mipiraw_COLOR_0495, gc2385mipiraw_COLOR_0496, gc2385mipiraw_COLOR_0497, gc2385mipiraw_COLOR_0498, gc2385mipiraw_COLOR_0499,
    gc2385mipiraw_COLOR_0500, gc2385mipiraw_COLOR_0501, gc2385mipiraw_COLOR_0502, gc2385mipiraw_COLOR_0503, gc2385mipiraw_COLOR_0504, gc2385mipiraw_COLOR_0505, gc2385mipiraw_COLOR_0506, gc2385mipiraw_COLOR_0507, gc2385mipiraw_COLOR_0508, gc2385mipiraw_COLOR_0509,
    gc2385mipiraw_COLOR_0510, gc2385mipiraw_COLOR_0511, gc2385mipiraw_COLOR_0512, gc2385mipiraw_COLOR_0513, gc2385mipiraw_COLOR_0514, gc2385mipiraw_COLOR_0515, gc2385mipiraw_COLOR_0516, gc2385mipiraw_COLOR_0517, gc2385mipiraw_COLOR_0518, gc2385mipiraw_COLOR_0519,
    gc2385mipiraw_COLOR_0520, gc2385mipiraw_COLOR_0521, gc2385mipiraw_COLOR_0522, gc2385mipiraw_COLOR_0523, gc2385mipiraw_COLOR_0524, gc2385mipiraw_COLOR_0525, gc2385mipiraw_COLOR_0526, gc2385mipiraw_COLOR_0527, gc2385mipiraw_COLOR_0528, gc2385mipiraw_COLOR_0529,
    gc2385mipiraw_COLOR_0530, gc2385mipiraw_COLOR_0531, gc2385mipiraw_COLOR_0532, gc2385mipiraw_COLOR_0533, gc2385mipiraw_COLOR_0534, gc2385mipiraw_COLOR_0535, gc2385mipiraw_COLOR_0536, gc2385mipiraw_COLOR_0537, gc2385mipiraw_COLOR_0538, gc2385mipiraw_COLOR_0539,
    gc2385mipiraw_COLOR_0540, gc2385mipiraw_COLOR_0541, gc2385mipiraw_COLOR_0542, gc2385mipiraw_COLOR_0543, gc2385mipiraw_COLOR_0544, gc2385mipiraw_COLOR_0545, gc2385mipiraw_COLOR_0546, gc2385mipiraw_COLOR_0547, gc2385mipiraw_COLOR_0548, gc2385mipiraw_COLOR_0549,
    gc2385mipiraw_COLOR_0550, gc2385mipiraw_COLOR_0551, gc2385mipiraw_COLOR_0552, gc2385mipiraw_COLOR_0553, gc2385mipiraw_COLOR_0554, gc2385mipiraw_COLOR_0555, gc2385mipiraw_COLOR_0556, gc2385mipiraw_COLOR_0557, gc2385mipiraw_COLOR_0558, gc2385mipiraw_COLOR_0559,
    gc2385mipiraw_COLOR_0560, gc2385mipiraw_COLOR_0561, gc2385mipiraw_COLOR_0562, gc2385mipiraw_COLOR_0563, gc2385mipiraw_COLOR_0564, gc2385mipiraw_COLOR_0565, gc2385mipiraw_COLOR_0566, gc2385mipiraw_COLOR_0567, gc2385mipiraw_COLOR_0568, gc2385mipiraw_COLOR_0569,
    gc2385mipiraw_COLOR_0570, gc2385mipiraw_COLOR_0571, gc2385mipiraw_COLOR_0572, gc2385mipiraw_COLOR_0573, gc2385mipiraw_COLOR_0574, gc2385mipiraw_COLOR_0575, gc2385mipiraw_COLOR_0576, gc2385mipiraw_COLOR_0577, gc2385mipiraw_COLOR_0578, gc2385mipiraw_COLOR_0579,
    gc2385mipiraw_COLOR_0580, gc2385mipiraw_COLOR_0581, gc2385mipiraw_COLOR_0582, gc2385mipiraw_COLOR_0583, gc2385mipiraw_COLOR_0584, gc2385mipiraw_COLOR_0585, gc2385mipiraw_COLOR_0586, gc2385mipiraw_COLOR_0587, gc2385mipiraw_COLOR_0588, gc2385mipiraw_COLOR_0589,
    gc2385mipiraw_COLOR_0590, gc2385mipiraw_COLOR_0591, gc2385mipiraw_COLOR_0592, gc2385mipiraw_COLOR_0593, gc2385mipiraw_COLOR_0594, gc2385mipiraw_COLOR_0595, gc2385mipiraw_COLOR_0596, gc2385mipiraw_COLOR_0597, gc2385mipiraw_COLOR_0598, gc2385mipiraw_COLOR_0599,
    gc2385mipiraw_COLOR_0600, gc2385mipiraw_COLOR_0601, gc2385mipiraw_COLOR_0602, gc2385mipiraw_COLOR_0603, gc2385mipiraw_COLOR_0604, gc2385mipiraw_COLOR_0605, gc2385mipiraw_COLOR_0606, gc2385mipiraw_COLOR_0607, gc2385mipiraw_COLOR_0608, gc2385mipiraw_COLOR_0609,
    gc2385mipiraw_COLOR_0610, gc2385mipiraw_COLOR_0611, gc2385mipiraw_COLOR_0612, gc2385mipiraw_COLOR_0613, gc2385mipiraw_COLOR_0614, gc2385mipiraw_COLOR_0615, gc2385mipiraw_COLOR_0616, gc2385mipiraw_COLOR_0617, gc2385mipiraw_COLOR_0618, gc2385mipiraw_COLOR_0619,
    gc2385mipiraw_COLOR_0620, gc2385mipiraw_COLOR_0621, gc2385mipiraw_COLOR_0622, gc2385mipiraw_COLOR_0623, gc2385mipiraw_COLOR_0624, gc2385mipiraw_COLOR_0625, gc2385mipiraw_COLOR_0626, gc2385mipiraw_COLOR_0627, gc2385mipiraw_COLOR_0628, gc2385mipiraw_COLOR_0629,
    gc2385mipiraw_COLOR_0630, gc2385mipiraw_COLOR_0631, gc2385mipiraw_COLOR_0632, gc2385mipiraw_COLOR_0633, gc2385mipiraw_COLOR_0634, gc2385mipiraw_COLOR_0635, gc2385mipiraw_COLOR_0636, gc2385mipiraw_COLOR_0637, gc2385mipiraw_COLOR_0638, gc2385mipiraw_COLOR_0639,
    gc2385mipiraw_COLOR_0640, gc2385mipiraw_COLOR_0641, gc2385mipiraw_COLOR_0642, gc2385mipiraw_COLOR_0643, gc2385mipiraw_COLOR_0644, gc2385mipiraw_COLOR_0645, gc2385mipiraw_COLOR_0646, gc2385mipiraw_COLOR_0647, gc2385mipiraw_COLOR_0648, gc2385mipiraw_COLOR_0649,
    gc2385mipiraw_COLOR_0650, gc2385mipiraw_COLOR_0651, gc2385mipiraw_COLOR_0652, gc2385mipiraw_COLOR_0653, gc2385mipiraw_COLOR_0654, gc2385mipiraw_COLOR_0655, gc2385mipiraw_COLOR_0656, gc2385mipiraw_COLOR_0657, gc2385mipiraw_COLOR_0658, gc2385mipiraw_COLOR_0659,
    gc2385mipiraw_COLOR_0660, gc2385mipiraw_COLOR_0661, gc2385mipiraw_COLOR_0662, gc2385mipiraw_COLOR_0663, gc2385mipiraw_COLOR_0664, gc2385mipiraw_COLOR_0665, gc2385mipiraw_COLOR_0666, gc2385mipiraw_COLOR_0667, gc2385mipiraw_COLOR_0668, gc2385mipiraw_COLOR_0669,
    gc2385mipiraw_COLOR_0670, gc2385mipiraw_COLOR_0671, gc2385mipiraw_COLOR_0672, gc2385mipiraw_COLOR_0673, gc2385mipiraw_COLOR_0674, gc2385mipiraw_COLOR_0675, gc2385mipiraw_COLOR_0676, gc2385mipiraw_COLOR_0677, gc2385mipiraw_COLOR_0678, gc2385mipiraw_COLOR_0679,
    gc2385mipiraw_COLOR_0680, gc2385mipiraw_COLOR_0681, gc2385mipiraw_COLOR_0682, gc2385mipiraw_COLOR_0683, gc2385mipiraw_COLOR_0684, gc2385mipiraw_COLOR_0685, gc2385mipiraw_COLOR_0686, gc2385mipiraw_COLOR_0687, gc2385mipiraw_COLOR_0688, gc2385mipiraw_COLOR_0689,
    gc2385mipiraw_COLOR_0690, gc2385mipiraw_COLOR_0691, gc2385mipiraw_COLOR_0692, gc2385mipiraw_COLOR_0693, gc2385mipiraw_COLOR_0694, gc2385mipiraw_COLOR_0695, gc2385mipiraw_COLOR_0696, gc2385mipiraw_COLOR_0697, gc2385mipiraw_COLOR_0698, gc2385mipiraw_COLOR_0699,
    gc2385mipiraw_COLOR_0700, gc2385mipiraw_COLOR_0701, gc2385mipiraw_COLOR_0702, gc2385mipiraw_COLOR_0703, gc2385mipiraw_COLOR_0704, gc2385mipiraw_COLOR_0705, gc2385mipiraw_COLOR_0706, gc2385mipiraw_COLOR_0707, gc2385mipiraw_COLOR_0708, gc2385mipiraw_COLOR_0709,
    gc2385mipiraw_COLOR_0710, gc2385mipiraw_COLOR_0711, gc2385mipiraw_COLOR_0712, gc2385mipiraw_COLOR_0713, gc2385mipiraw_COLOR_0714, gc2385mipiraw_COLOR_0715, gc2385mipiraw_COLOR_0716, gc2385mipiraw_COLOR_0717, gc2385mipiraw_COLOR_0718, gc2385mipiraw_COLOR_0719,
    gc2385mipiraw_COLOR_0720, gc2385mipiraw_COLOR_0721, gc2385mipiraw_COLOR_0722, gc2385mipiraw_COLOR_0723, gc2385mipiraw_COLOR_0724, gc2385mipiraw_COLOR_0725, gc2385mipiraw_COLOR_0726, gc2385mipiraw_COLOR_0727, gc2385mipiraw_COLOR_0728, gc2385mipiraw_COLOR_0729,
    gc2385mipiraw_COLOR_0730, gc2385mipiraw_COLOR_0731, gc2385mipiraw_COLOR_0732, gc2385mipiraw_COLOR_0733, gc2385mipiraw_COLOR_0734, gc2385mipiraw_COLOR_0735, gc2385mipiraw_COLOR_0736, gc2385mipiraw_COLOR_0737, gc2385mipiraw_COLOR_0738, gc2385mipiraw_COLOR_0739,
    gc2385mipiraw_COLOR_0740, gc2385mipiraw_COLOR_0741, gc2385mipiraw_COLOR_0742, gc2385mipiraw_COLOR_0743, gc2385mipiraw_COLOR_0744, gc2385mipiraw_COLOR_0745, gc2385mipiraw_COLOR_0746, gc2385mipiraw_COLOR_0747, gc2385mipiraw_COLOR_0748, gc2385mipiraw_COLOR_0749,
    gc2385mipiraw_COLOR_0750, gc2385mipiraw_COLOR_0751, gc2385mipiraw_COLOR_0752, gc2385mipiraw_COLOR_0753, gc2385mipiraw_COLOR_0754, gc2385mipiraw_COLOR_0755, gc2385mipiraw_COLOR_0756, gc2385mipiraw_COLOR_0757, gc2385mipiraw_COLOR_0758, gc2385mipiraw_COLOR_0759,
    gc2385mipiraw_COLOR_0760, gc2385mipiraw_COLOR_0761, gc2385mipiraw_COLOR_0762, gc2385mipiraw_COLOR_0763, gc2385mipiraw_COLOR_0764, gc2385mipiraw_COLOR_0765, gc2385mipiraw_COLOR_0766, gc2385mipiraw_COLOR_0767, gc2385mipiraw_COLOR_0768, gc2385mipiraw_COLOR_0769,
    gc2385mipiraw_COLOR_0770, gc2385mipiraw_COLOR_0771, gc2385mipiraw_COLOR_0772, gc2385mipiraw_COLOR_0773, gc2385mipiraw_COLOR_0774, gc2385mipiraw_COLOR_0775, gc2385mipiraw_COLOR_0776, gc2385mipiraw_COLOR_0777, gc2385mipiraw_COLOR_0778, gc2385mipiraw_COLOR_0779,
    gc2385mipiraw_COLOR_0780, gc2385mipiraw_COLOR_0781, gc2385mipiraw_COLOR_0782, gc2385mipiraw_COLOR_0783, gc2385mipiraw_COLOR_0784, gc2385mipiraw_COLOR_0785, gc2385mipiraw_COLOR_0786, gc2385mipiraw_COLOR_0787, gc2385mipiraw_COLOR_0788, gc2385mipiraw_COLOR_0789,
    gc2385mipiraw_COLOR_0790, gc2385mipiraw_COLOR_0791, gc2385mipiraw_COLOR_0792, gc2385mipiraw_COLOR_0793, gc2385mipiraw_COLOR_0794, gc2385mipiraw_COLOR_0795, gc2385mipiraw_COLOR_0796, gc2385mipiraw_COLOR_0797, gc2385mipiraw_COLOR_0798, gc2385mipiraw_COLOR_0799,
    gc2385mipiraw_COLOR_0800, gc2385mipiraw_COLOR_0801, gc2385mipiraw_COLOR_0802, gc2385mipiraw_COLOR_0803, gc2385mipiraw_COLOR_0804, gc2385mipiraw_COLOR_0805, gc2385mipiraw_COLOR_0806, gc2385mipiraw_COLOR_0807, gc2385mipiraw_COLOR_0808, gc2385mipiraw_COLOR_0809,
    gc2385mipiraw_COLOR_0810, gc2385mipiraw_COLOR_0811, gc2385mipiraw_COLOR_0812, gc2385mipiraw_COLOR_0813, gc2385mipiraw_COLOR_0814, gc2385mipiraw_COLOR_0815, gc2385mipiraw_COLOR_0816, gc2385mipiraw_COLOR_0817, gc2385mipiraw_COLOR_0818, gc2385mipiraw_COLOR_0819,
    gc2385mipiraw_COLOR_0820, gc2385mipiraw_COLOR_0821, gc2385mipiraw_COLOR_0822, gc2385mipiraw_COLOR_0823, gc2385mipiraw_COLOR_0824, gc2385mipiraw_COLOR_0825, gc2385mipiraw_COLOR_0826, gc2385mipiraw_COLOR_0827, gc2385mipiraw_COLOR_0828, gc2385mipiraw_COLOR_0829,
    gc2385mipiraw_COLOR_0830, gc2385mipiraw_COLOR_0831, gc2385mipiraw_COLOR_0832, gc2385mipiraw_COLOR_0833, gc2385mipiraw_COLOR_0834, gc2385mipiraw_COLOR_0835, gc2385mipiraw_COLOR_0836, gc2385mipiraw_COLOR_0837, gc2385mipiraw_COLOR_0838, gc2385mipiraw_COLOR_0839,
    gc2385mipiraw_COLOR_0840, gc2385mipiraw_COLOR_0841, gc2385mipiraw_COLOR_0842, gc2385mipiraw_COLOR_0843, gc2385mipiraw_COLOR_0844, gc2385mipiraw_COLOR_0845, gc2385mipiraw_COLOR_0846, gc2385mipiraw_COLOR_0847, gc2385mipiraw_COLOR_0848, gc2385mipiraw_COLOR_0849,
    gc2385mipiraw_COLOR_0850, gc2385mipiraw_COLOR_0851, gc2385mipiraw_COLOR_0852, gc2385mipiraw_COLOR_0853, gc2385mipiraw_COLOR_0854, gc2385mipiraw_COLOR_0855, gc2385mipiraw_COLOR_0856, gc2385mipiraw_COLOR_0857, gc2385mipiraw_COLOR_0858, gc2385mipiraw_COLOR_0859,
    gc2385mipiraw_COLOR_0860, gc2385mipiraw_COLOR_0861, gc2385mipiraw_COLOR_0862, gc2385mipiraw_COLOR_0863, gc2385mipiraw_COLOR_0864, gc2385mipiraw_COLOR_0865, gc2385mipiraw_COLOR_0866, gc2385mipiraw_COLOR_0867, gc2385mipiraw_COLOR_0868, gc2385mipiraw_COLOR_0869,
    gc2385mipiraw_COLOR_0870, gc2385mipiraw_COLOR_0871, gc2385mipiraw_COLOR_0872, gc2385mipiraw_COLOR_0873, gc2385mipiraw_COLOR_0874, gc2385mipiraw_COLOR_0875, gc2385mipiraw_COLOR_0876, gc2385mipiraw_COLOR_0877, gc2385mipiraw_COLOR_0878, gc2385mipiraw_COLOR_0879,
    gc2385mipiraw_COLOR_0880, gc2385mipiraw_COLOR_0881, gc2385mipiraw_COLOR_0882, gc2385mipiraw_COLOR_0883, gc2385mipiraw_COLOR_0884, gc2385mipiraw_COLOR_0885, gc2385mipiraw_COLOR_0886, gc2385mipiraw_COLOR_0887, gc2385mipiraw_COLOR_0888, gc2385mipiraw_COLOR_0889,
    gc2385mipiraw_COLOR_0890, gc2385mipiraw_COLOR_0891, gc2385mipiraw_COLOR_0892, gc2385mipiraw_COLOR_0893, gc2385mipiraw_COLOR_0894, gc2385mipiraw_COLOR_0895, gc2385mipiraw_COLOR_0896, gc2385mipiraw_COLOR_0897, gc2385mipiraw_COLOR_0898, gc2385mipiraw_COLOR_0899,
    gc2385mipiraw_COLOR_0900, gc2385mipiraw_COLOR_0901, gc2385mipiraw_COLOR_0902, gc2385mipiraw_COLOR_0903, gc2385mipiraw_COLOR_0904, gc2385mipiraw_COLOR_0905, gc2385mipiraw_COLOR_0906, gc2385mipiraw_COLOR_0907, gc2385mipiraw_COLOR_0908, gc2385mipiraw_COLOR_0909,
    gc2385mipiraw_COLOR_0910, gc2385mipiraw_COLOR_0911, gc2385mipiraw_COLOR_0912, gc2385mipiraw_COLOR_0913, gc2385mipiraw_COLOR_0914, gc2385mipiraw_COLOR_0915, gc2385mipiraw_COLOR_0916, gc2385mipiraw_COLOR_0917, gc2385mipiraw_COLOR_0918, gc2385mipiraw_COLOR_0919,
    gc2385mipiraw_COLOR_0920, gc2385mipiraw_COLOR_0921, gc2385mipiraw_COLOR_0922, gc2385mipiraw_COLOR_0923, gc2385mipiraw_COLOR_0924, gc2385mipiraw_COLOR_0925, gc2385mipiraw_COLOR_0926, gc2385mipiraw_COLOR_0927, gc2385mipiraw_COLOR_0928, gc2385mipiraw_COLOR_0929,
    gc2385mipiraw_COLOR_0930, gc2385mipiraw_COLOR_0931, gc2385mipiraw_COLOR_0932, gc2385mipiraw_COLOR_0933, gc2385mipiraw_COLOR_0934, gc2385mipiraw_COLOR_0935, gc2385mipiraw_COLOR_0936, gc2385mipiraw_COLOR_0937, gc2385mipiraw_COLOR_0938, gc2385mipiraw_COLOR_0939,
    gc2385mipiraw_COLOR_0940, gc2385mipiraw_COLOR_0941, gc2385mipiraw_COLOR_0942, gc2385mipiraw_COLOR_0943, gc2385mipiraw_COLOR_0944, gc2385mipiraw_COLOR_0945, gc2385mipiraw_COLOR_0946, gc2385mipiraw_COLOR_0947, gc2385mipiraw_COLOR_0948, gc2385mipiraw_COLOR_0949,
    gc2385mipiraw_COLOR_0950, gc2385mipiraw_COLOR_0951, gc2385mipiraw_COLOR_0952, gc2385mipiraw_COLOR_0953, gc2385mipiraw_COLOR_0954, gc2385mipiraw_COLOR_0955, gc2385mipiraw_COLOR_0956, gc2385mipiraw_COLOR_0957, gc2385mipiraw_COLOR_0958, gc2385mipiraw_COLOR_0959,
},
.PCA = {
    gc2385mipiraw_PCA_0000,
},
.COLOR_PARAM = {
    gc2385mipiraw_COLOR_PARAM_0000, gc2385mipiraw_COLOR_PARAM_0001, gc2385mipiraw_COLOR_PARAM_0002, gc2385mipiraw_COLOR_PARAM_0003, gc2385mipiraw_COLOR_PARAM_0004, gc2385mipiraw_COLOR_PARAM_0005, gc2385mipiraw_COLOR_PARAM_0006, gc2385mipiraw_COLOR_PARAM_0007, gc2385mipiraw_COLOR_PARAM_0008, gc2385mipiraw_COLOR_PARAM_0009,
    gc2385mipiraw_COLOR_PARAM_0010, gc2385mipiraw_COLOR_PARAM_0011, gc2385mipiraw_COLOR_PARAM_0012, gc2385mipiraw_COLOR_PARAM_0013, gc2385mipiraw_COLOR_PARAM_0014, gc2385mipiraw_COLOR_PARAM_0015,
},
