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
#include "imx586mipiraw_N3D_Preview.h"

const AE_NVRAM_T imx586mipiraw_AE_0005 = {
        .rDevicesInfo = 
    {
        1136,  // u4MinGain
        16384,  // u4MaxGain
        100,  // u4MiniISOGain
        16,  // u4GainStepUnit
        11345,  // u4PreExpUnit
        30,  // u4PreMaxFrameRate
        10040,  // u4VideoExpUnit
        30,  // u4VideoMaxFrameRate
        1024,  // u4Video2PreRatio
        10040,  // u4CapExpUnit
        30,  // u4CapMaxFrameRate
        1024,  // u4Cap2PreRatio
        10040,  // u4Video1ExpUnit
        120,  // u4Video1MaxFrameRate
        1024,  // u4Video12PreRatio
        10040,  // u4Video2ExpUnit
        60,  // u4Video2MaxFrameRate
        1024,  // u4Video22PreRatio
        11345,  // u4Custom1ExpUnit
        30,  // u4Custom1MaxFrameRate
        1024,  // u4Custom12PreRatio
        11345,  // u4Custom2ExpUnit
        30,  // u4Custom2MaxFrameRate
        1024,  // u4Custom22PreRatio
        10424,  // u4Custom3ExpUnit
        30,  // u4Custom3MaxFrameRate
        1024,  // u4Custom32PreRatio
        11345,  // u4Custom4ExpUnit
        30,  // u4Custom4MaxFrameRate
        1024,  // u4Custom42PreRatio
        11345,  // u4Custom5ExpUnit
        30,  // u4Custom5MaxFrameRate
        1024,  // u4Custom52PreRatio
        17,  // u4LensFno
        350  // u4FocusLength_100x
    },
    .rHistConfig =
    {
        4,  // u4HistHighThres
        40,  // u4HistLowThres
        2,  // u4MostBrightRatio
        1,  // u4MostDarkRatio
        160,  // u4CentralHighBound
        20,  // u4CentralLowBound
        // u4OverExpThres
        {
            240, 230, 220, 210, 200
        },
        // u4HistStretchThres
        {
            62, 70, 82, 108, 141
        },
        // u4BlackLightThres
        {
            18, 22, 26, 30, 34
        }
    },
    .rCCTConfig =
    {
        1,  // bEnableBlackLight
        1,  // bEnableHistStretch
        1,  // bEnableAntiOverExposure
        1,  // bEnableTimeLPF
        1,  // bEnableCaptureThres
        1,  // bEnableVideoThres
        1,  // bEnableVideo1Thres
        1,  // bEnableVideo2Thres
        1,  // bEnableCustom1Thres
        1,  // bEnableCustom2Thres
        1,  // bEnableCustom3Thres
        1,  // bEnableCustom4Thres
        1,  // bEnableCustom5Thres
        1,  // bEnableStrobeThres
        47,  // u4AETarget
        47,  // u4StrobeAETarget
        70,  // u4InitIndex
        4,  // u4BackLightWeight
        32,  // u4HistStretchWeight
        4,  // u4AntiOverExpWeight
        2,  // u4BlackLightStrengthIndex
        2,  // u4HistStretchStrengthIndex
        2,  // u4AntiOverExpStrengthIndex
        2,  // u4TimeLPFStrengthIndex
        // u4LPFConvergeLevel
        {
            1, 3, 5, 7, 8
        },
        90,  // u4InDoorEV
        -20,  // i4BVOffset
        64,  // u4PreviewFlareOffset
        64,  // u4CaptureFlareOffset
        10,  // u4CaptureFlareThres
        64,  // u4VideoFlareOffset
        10,  // u4VideoFlareThres
        64,  // u4CustomFlareOffset
        10,  // u4CustomFlareThres
        64,  // u4StrobeFlareOffset
        3,  // u4StrobeFlareThres
        98,  // u4PrvMaxFlareThres
        0,  // u4PrvMinFlareThres
        160,  // u4VideoMaxFlareThres
        0,  // u4VideoMinFlareThres
        18,  // u4FlatnessThres
        75,  // u4FlatnessStrength
        // rMeteringSpec
        {
            // rHS_Spec
            {
                1,  // bEnableHistStretch
                1024,  // u4HistStretchWeight
                60,  // u4Pcent
                160,  // u4Thd
                75,  // u4FlatThd
                120,  // u4FlatBrightPcent
                120,  // u4FlatDarkPcent
                // sFlatRatio
                {
                    1000,  // u4X1
                    1024,  // u4Y1
                    2400,  // u4X2
                    0  // u4Y2
                },
                0,  // bEnableGreyTextEnhance
                1800,  // u4GreyTextFlatStart
                // sGreyTextRatio
                {
                    10,  // u4X1
                    1024,  // u4Y1
                    80,  // u4X2
                    0  // u4Y2
                }
            },
            // rAOE_Spec
            {
                1,  // bEnableAntiOverExposure
                1024,  // u4AntiOverExpWeight
                10,  // u4Pcent
                220,  // u4Thd
                1,  // bEnableCOEP
                1,  // u4COEPcent
                106,  // u4COEThd
                0,  // u4BVCompRatio
                // sCOEYRatio
                {
                    23,  // u4X1
                    1024,  // u4Y1
                    47,  // u4X2
                    0  // u4Y2
                },
                // sCOEDiffRatio
                {
                    1500,  // u4X1
                    0,  // u4Y1
                    2100,  // u4X2
                    1024  // u4Y2
                }
            },
            // rABL_Spec
            {
                1,  // bEnableBlackLight
                1024,  // u4BackLightWeight
                500,  // u4Pcent
                22,  // u4Thd
                255,  // u4CenterHighBnd
                180,  // u4TargetStrength
                // sFgBgEVRatio
                {
                    2100,  // u4X1
                    0,  // u4Y1
                    4000,  // u4X2
                    1024  // u4Y2
                },
                // sBVRatio
                {
                    3800,  // u4X1
                    0,  // u4Y1
                    5000,  // u4X2
                    1024  // u4Y2
                }
            },
            // rNS_Spec
            {
                1,  // bEnableNightScene
                10,  // u4Pcent
                150,  // u4Thd
                55,  // u4FlatThd
                180,  // u4BrightTonePcent
                55,  // u4BrightToneThd
                500,  // u4LowBndPcent
                5,  // u4LowBndThd
                26,  // u4LowBndThdLimit
                50,  // u4FlatBrightPcent
                300,  // u4FlatDarkPcent
                // sFlatRatio
                {
                    1200,  // u4X1
                    1024,  // u4Y1
                    2800,  // u4X2
                    0  // u4Y2
                },
                // sBVRatio
                {
                    -500,  // u4X1
                    1024,  // u4Y1
                    3000,  // u4X2
                    0  // u4Y2
                },
                1,  // bEnableNightSkySuppresion
                // sSkyBVRatio
                {
                    -4000,  // u4X1
                    1024,  // u4Y1
                    -2000,  // u4X2
                    0  // u4Y2
                }
            },
            // rTOUCHFD_Spec
            {
                40,  // uMeteringYLowBound
                50,  // uMeteringYHighBound
                40,  // uFaceYLowBound
                50,  // uFaceYHighBound
                3,  // uFaceCentralWeight
                120,  // u4MeteringStableMax
                80  // u4MeteringStableMin
            }
        },
        // rFlareSpec
        {
            // uPrvFlareWeightArr
            {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1
            },
            // uVideoFlareWeightArr
            {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1
            },
            96,  // u4FlareStdThrHigh
            48,  // u4FlareStdThrLow
            0,  // u4PrvCapFlareDiff
            2,  // u4FlareMaxStepGap_Fast
            0,  // u4FlareMaxStepGap_Slow
            1800,  // u4FlarMaxStepGapLimitBV
            2  // u4FlareAEStableCount
        },
        // rAEMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            190,  // u4Bright2TargetEnd
            10,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            85,  // u4B2TStart
            70,  // u4D2TEnd
            85  // u4D2TStart
        },
        // rAEVideoMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAEVideo1MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAEVideo2MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAECustom1MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAECustom2MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAECustom3MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAECustom4MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAECustom5MovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            150,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            90,  // u4B2TEnd
            40,  // u4B2TStart
            30,  // u4D2TEnd
            90  // u4D2TStart
        },
        // rAEFaceMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            190,  // u4Bright2TargetEnd
            10,  // u4Dark2TargetStart
            60,  // u4B2TEnd
            60,  // u4B2TStart
            60,  // u4D2TEnd
            60  // u4D2TStart
        },
        // rAETrackingMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            190,  // u4Bright2TargetEnd
            10,  // u4Dark2TargetStart
            80,  // u4B2TEnd
            30,  // u4B2TStart
            20,  // u4D2TEnd
            60  // u4D2TStart
        },
        // rAEAOENVRAMParam
        {
            1,  // i4AOEStrengthIdx
            130,  // u4BVCompRatio
            // rAEAOEAlgParam
            {
                {
                    28,  // u4Y_Target
                    25,  // u4AOE_OE_percent
                    210,  // u4AOE_OEBound
                    10,  // u4AOE_DarkBound
                    950,  // u4AOE_LowlightPrecent
                    1,  // u4AOE_LowlightBound
                    145,  // u4AOESceneLV_L
                    180,  // u4AOESceneLV_H
                    40  // u4AOE_SWHdrLE_Bound
                },
                {
                    28,  // u4Y_Target
                    25,  // u4AOE_OE_percent
                    210,  // u4AOE_OEBound
                    15,  // u4AOE_DarkBound
                    950,  // u4AOE_LowlightPrecent
                    3,  // u4AOE_LowlightBound
                    145,  // u4AOESceneLV_L
                    180,  // u4AOESceneLV_H
                    40  // u4AOE_SWHdrLE_Bound
                },
                {
                    28,  // u4Y_Target
                    25,  // u4AOE_OE_percent
                    210,  // u4AOE_OEBound
                    25,  // u4AOE_DarkBound
                    950,  // u4AOE_LowlightPrecent
                    8,  // u4AOE_LowlightBound
                    145,  // u4AOESceneLV_L
                    180,  // u4AOESceneLV_H
                    40  // u4AOE_SWHdrLE_Bound
                }
            }
        }
    },
    .rHDRAEConfig =
    {
        3072,  // i4RMGSeg
        768,  // i4RMGTurn
        35,  // i4HDRTarget_L
        40,  // i4HDRTarget_H
        100,  // i4HDRTargetLV_L
        120,  // i4HDRTargetLV_H
        20,  // i4OverExpoRatio
        212,  // i4OverExpoTarget
        120,  // i4OverExpoLV_L
        180,  // i4OverExpoLV_H
        4,  // i4UnderExpoContrastThr
        // i4UnderExpoTargetTbl
        {
            3, 3, 3, 3, 3, 2, 1, 1, 1, 1,
            1
        },
        950,  // i4UnderExpoRatio
        1000,  // i4AvgExpoRatio
        8,  // i4AvgExpoTarget
        768,  // i4HDRAESpeed
        2,  // i4HDRConvergeThr
        40,  // i4SWHdrLEThr
        20,  // i4SWHdrSERatio
        180,  // i4SWHdrSETarget
        1024  // i4SWHdrBaseGain
    },
    .rAeParam =
    {
        // strAEParasetting
        {
            0,  // bEnableSaturationCheck
            1,  // bEnablePreIndex
            1,  // bEnableRotateWeighting
            1,  // bEV0TriggerStrobe
            0,  // bLockCamPreMeteringWin
            0,  // bLockVideoPreMeteringWin
            1,  // bLockVideoRecMeteringWin
            1,  // bSkipAEinBirghtRange
            1,  // bPreAFLockAE
            1,  // bStrobeFlarebyCapture
            1,  // bEnableFaceAE
            1,  // bEnableMeterAE
            1,  // bFlarMaxStepGapLimitEnable
            1,  // bEnableAESmoothGain
            1,  // bEnableLongCaptureCtrl
            0,  // bEnableTouchSmoothRatio
            1,  // bEnableTouchSmooth
            1,  // bEnablePixelBaseHist
            1,  // bEnableHDRSTATconfig
            1,  // bEnableAEOVERCNTconfig
            1,  // bEnableTSFSTATconfig
            1,  // bEnableHDRLSB
            1,  // bEnableFlareFastConverge
            1,  // bEnableRAFastConverge
            1,  // bEnableFaceFastConverge
            256,  // u4BackLightStrength
            256,  // u4OverExpStrength
            256,  // u4HistStretchStrength
            0,  // u4SmoothLevel
            4,  // u4TimeLPFLevel
            120,  // u4AEWinodwNumX
            90,  // u4AEWinodwNumY
            5,  // uBlockNumX
            5,  // uBlockNumY
            12,  // uTgBlockNumX
            9,  // uTgBlockNumY
            20,  // uSatBlockCheckLow
            50,  // uSatBlockCheckHigh
            50,  // uSatBlockAdjustFactor
            80,  // uMeteringYLowSkipRatio
            120,  // uMeteringYHighSkipRatio
            10,  // u4MinYLowBound
            256,  // u4MaxYHighBound
            512,  // u4MeterWeight
            1,  // u4MinCWRecommend
            250,  // u4MaxCWRecommend
            -50,  // iMiniBVValue
            2,  // uAEShutterDelayCycle
            2,  // uAESensorGainDelayCycleWShutter
            1,  // uAESensorGainDelayCycleWOShutter
            0,  // uAEIspGainDelayCycle
            5,  // u4AEYCoefR
            9,  // u4AEYCoefG
            2,  // u4AEYCoefB
            200000,  // u4LongCaptureThres
            1,  // u4CenterFaceExtraWeighting
            7,  // u2AEStatThrs
            1,  // uCycleNumAESkipAfterExit
            254,  // uOverExpoTHD
            11,  // u4HSSmoothTHD
            3,  // u4FinerEvIndexBase
            0  // bNewConstraintForMeteringEnable
        },
        // Weighting
        {
            {
                AE_WEIGHTING_CENTRALWEIGHT,  // eID
                // W
                {
                    {
                        6, 19, 28, 19, 6
                    },
                    {
                        19, 60, 88, 60, 19
                    },
                    {
                        28, 88, 160, 88, 28
                    },
                    {
                        19, 60, 88, 60, 19
                    },
                    {
                        6, 19, 28, 19, 6
                    }
                }
            },
            {
                AE_WEIGHTING_SPOT,  // eID
                // W
                {
                    {
                        0, 0, 0, 0, 0
                    },
                    {
                        0, 0, 0, 0, 0
                    },
                    {
                        0, 0, 1, 0, 0
                    },
                    {
                        0, 0, 0, 0, 0
                    },
                    {
                        0, 0, 0, 0, 0
                    }
                }
            },
            {
                AE_WEIGHTING_AVERAGE,  // eID
                // W
                {
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    }
                }
            },
            {
                AE_WEIGHTING_AVERAGE,  // eID
                // W
                {
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    },
                    {
                        1, 1, 1, 1, 1
                    }
                }
            }
        },
        // strAFPLine
        {
            0,  // bAFPlineEnable
            // i2FrameRate
            {
                {
                    73, 30
                },
                {
                    65, 25
                },
                {
                    55, 19
                },
                {
                    45, 17
                },
                {
                    0, 17
                }
            }
        },
        // strAFZSDPLine
        {
            0,  // bAFPlineEnable
            // i2FrameRate
            {
                {
                    73, 15
                },
                {
                    65, 15
                },
                {
                    55, 15
                },
                {
                    45, 15
                },
                {
                    0, 10
                }
            }
        },
        // strStrobePLine
        {
            1,  // bAFPlineEnable
            // i2FrameRate
            {
                {
                    73, 30
                },
                {
                    65, 25
                },
                {
                    55, 19
                },
                {
                    45, 17
                },
                {
                    0, 17
                }
            }
        },
        // strStrobeZSDPLine
        {
            1,  // bAFPlineEnable
            // i2FrameRate
            {
                {
                    73, 15
                },
                {
                    65, 15
                },
                {
                    55, 15
                },
                {
                    45, 15
                },
                {
                    0, 10
                }
            }
        },
        // EVValueArray
        {
            // EVValue
            {
                1024, 1097, 1176, 1261, 1351, 1448, 1552, 1663, 1783, 1911,
                2048, 2195, 2353, 2521, 2702, 2896, 3104, 3327, 3566, 3822,
                4096, 4390, 4705, 5043, 5405, 5793, 6208, 6654, 7132, 7643,
                8192, 8780, 9410, 10086, 10809, 11585, 12417, 13308, 14263, 15287,
                16384, 955, 891, 832, 776, 724, 676, 630, 588, 549,
                512, 478, 446, 416, 388, 362, 338, 315, 294, 274,
                256, 239, 223, 208, 194, 181, 169, 158, 147, 137,
                128, 119, 111, 104, 97, 91, 84, 79, 74, 69,
                64
            }
        },
        // AEMovingTable
        {
            // table
            {
                {
                    -20,  // Diff_EV
                    17,  // Ration
                    24  // move_index
                },
                {
                    -20,  // Diff_EV
                    25,  // Ration
                    19  // move_index
                },
                {
                    -15,  // Diff_EV
                    33,  // Ration
                    15  // move_index
                },
                {
                    -15,  // Diff_EV
                    40,  // Ration
                    12  // move_index
                },
                {
                    -10,  // Diff_EV
                    50,  // Ration
                    9  // move_index
                },
                {
                    -8,  // Diff_EV
                    57,  // Ration
                    7  // move_index
                },
                {
                    -5,  // Diff_EV
                    71,  // Ration
                    4  // move_index
                },
                {
                    -4,  // Diff_EV
                    75,  // Ration
                    3  // move_index
                },
                {
                    -3,  // Diff_EV
                    81,  // Ration
                    2  // move_index
                },
                {
                    -1,  // Diff_EV
                    90,  // Ration
                    1  // move_index
                },
                {
                    0,  // Diff_EV
                    100,  // Ration
                    0  // move_index
                },
                {
                    1,  // Diff_EV
                    110,  // Ration
                    0  // move_index
                },
                {
                    2,  // Diff_EV
                    114,  // Ration
                    -1  // move_index
                },
                {
                    3,  // Diff_EV
                    123,  // Ration
                    -1  // move_index
                },
                {
                    4,  // Diff_EV
                    131,  // Ration
                    -2  // move_index
                },
                {
                    5,  // Diff_EV
                    141,  // Ration
                    -3  // move_index
                },
                {
                    7,  // Diff_EV
                    162,  // Ration
                    -4  // move_index
                },
                {
                    9,  // Diff_EV
                    186,  // Ration
                    -6  // move_index
                },
                {
                    10,  // Diff_EV
                    200,  // Ration
                    -8  // move_index
                },
                {
                    13,  // Diff_EV
                    246,  // Ration
                    -9  // move_index
                },
                {
                    16,  // Diff_EV
                    303,  // Ration
                    -12  // move_index
                },
                {
                    20,  // Diff_EV
                    400,  // Ration
                    -15  // move_index
                },
                {
                    25,  // Diff_EV
                    566,  // Ration
                    -19  // move_index
                },
                {
                    30,  // Diff_EV
                    800,  // Ration
                    -22  // move_index
                }
            }
        },
        // AEVideoMovingTable
        {
            // table
            {
                {
                    -20,  // Diff_EV
                    17,  // Ration
                    20  // move_index
                },
                {
                    -20,  // Diff_EV
                    25,  // Ration
                    15  // move_index
                },
                {
                    -15,  // Diff_EV
                    33,  // Ration
                    10  // move_index
                },
                {
                    -15,  // Diff_EV
                    40,  // Ration
                    6  // move_index
                },
                {
                    -10,  // Diff_EV
                    50,  // Ration
                    4  // move_index
                },
                {
                    -8,  // Diff_EV
                    57,  // Ration
                    3  // move_index
                },
                {
                    -5,  // Diff_EV
                    71,  // Ration
                    2  // move_index
                },
                {
                    -4,  // Diff_EV
                    75,  // Ration
                    1  // move_index
                },
                {
                    -3,  // Diff_EV
                    81,  // Ration
                    1  // move_index
                },
                {
                    -1,  // Diff_EV
                    90,  // Ration
                    1  // move_index
                },
                {
                    0,  // Diff_EV
                    100,  // Ration
                    0  // move_index
                },
                {
                    1,  // Diff_EV
                    110,  // Ration
                    0  // move_index
                },
                {
                    2,  // Diff_EV
                    114,  // Ration
                    -1  // move_index
                },
                {
                    3,  // Diff_EV
                    123,  // Ration
                    -1  // move_index
                },
                {
                    4,  // Diff_EV
                    131,  // Ration
                    -1  // move_index
                },
                {
                    5,  // Diff_EV
                    141,  // Ration
                    -2  // move_index
                },
                {
                    7,  // Diff_EV
                    162,  // Ration
                    -2  // move_index
                },
                {
                    9,  // Diff_EV
                    186,  // Ration
                    -3  // move_index
                },
                {
                    10,  // Diff_EV
                    200,  // Ration
                    -4  // move_index
                },
                {
                    13,  // Diff_EV
                    246,  // Ration
                    -4  // move_index
                },
                {
                    16,  // Diff_EV
                    303,  // Ration
                    -6  // move_index
                },
                {
                    20,  // Diff_EV
                    400,  // Ration
                    -7  // move_index
                },
                {
                    25,  // Diff_EV
                    566,  // Ration
                    -9  // move_index
                },
                {
                    30,  // Diff_EV
                    800,  // Ration
                    -11  // move_index
                }
            }
        },
        // AEFaceMovingTable
        {
            // table
            {
                {
                    -20,  // Diff_EV
                    17,  // Ration
                    20  // move_index
                },
                {
                    -20,  // Diff_EV
                    25,  // Ration
                    15  // move_index
                },
                {
                    -15,  // Diff_EV
                    33,  // Ration
                    10  // move_index
                },
                {
                    -15,  // Diff_EV
                    40,  // Ration
                    6  // move_index
                },
                {
                    -10,  // Diff_EV
                    50,  // Ration
                    4  // move_index
                },
                {
                    -8,  // Diff_EV
                    57,  // Ration
                    3  // move_index
                },
                {
                    -5,  // Diff_EV
                    71,  // Ration
                    2  // move_index
                },
                {
                    -4,  // Diff_EV
                    75,  // Ration
                    1  // move_index
                },
                {
                    -3,  // Diff_EV
                    81,  // Ration
                    1  // move_index
                },
                {
                    -1,  // Diff_EV
                    90,  // Ration
                    1  // move_index
                },
                {
                    0,  // Diff_EV
                    100,  // Ration
                    0  // move_index
                },
                {
                    1,  // Diff_EV
                    110,  // Ration
                    0  // move_index
                },
                {
                    2,  // Diff_EV
                    114,  // Ration
                    -1  // move_index
                },
                {
                    3,  // Diff_EV
                    123,  // Ration
                    -1  // move_index
                },
                {
                    4,  // Diff_EV
                    131,  // Ration
                    -1  // move_index
                },
                {
                    5,  // Diff_EV
                    141,  // Ration
                    -2  // move_index
                },
                {
                    7,  // Diff_EV
                    162,  // Ration
                    -2  // move_index
                },
                {
                    9,  // Diff_EV
                    186,  // Ration
                    -3  // move_index
                },
                {
                    10,  // Diff_EV
                    200,  // Ration
                    -4  // move_index
                },
                {
                    13,  // Diff_EV
                    246,  // Ration
                    -4  // move_index
                },
                {
                    16,  // Diff_EV
                    303,  // Ration
                    -6  // move_index
                },
                {
                    20,  // Diff_EV
                    400,  // Ration
                    -7  // move_index
                },
                {
                    25,  // Diff_EV
                    566,  // Ration
                    -9  // move_index
                },
                {
                    30,  // Diff_EV
                    800,  // Ration
                    -11  // move_index
                }
            }
        },
        // AETrackingMovingTable
        {
            // table
            {
                {
                    -20,  // Diff_EV
                    17,  // Ration
                    20  // move_index
                },
                {
                    -20,  // Diff_EV
                    25,  // Ration
                    15  // move_index
                },
                {
                    -15,  // Diff_EV
                    33,  // Ration
                    10  // move_index
                },
                {
                    -15,  // Diff_EV
                    40,  // Ration
                    6  // move_index
                },
                {
                    -10,  // Diff_EV
                    50,  // Ration
                    4  // move_index
                },
                {
                    -8,  // Diff_EV
                    57,  // Ration
                    3  // move_index
                },
                {
                    -5,  // Diff_EV
                    71,  // Ration
                    2  // move_index
                },
                {
                    -4,  // Diff_EV
                    75,  // Ration
                    1  // move_index
                },
                {
                    -3,  // Diff_EV
                    81,  // Ration
                    1  // move_index
                },
                {
                    -1,  // Diff_EV
                    90,  // Ration
                    1  // move_index
                },
                {
                    0,  // Diff_EV
                    100,  // Ration
                    0  // move_index
                },
                {
                    1,  // Diff_EV
                    110,  // Ration
                    0  // move_index
                },
                {
                    2,  // Diff_EV
                    114,  // Ration
                    -1  // move_index
                },
                {
                    3,  // Diff_EV
                    123,  // Ration
                    -1  // move_index
                },
                {
                    4,  // Diff_EV
                    131,  // Ration
                    -1  // move_index
                },
                {
                    5,  // Diff_EV
                    141,  // Ration
                    -2  // move_index
                },
                {
                    7,  // Diff_EV
                    162,  // Ration
                    -2  // move_index
                },
                {
                    9,  // Diff_EV
                    186,  // Ration
                    -3  // move_index
                },
                {
                    10,  // Diff_EV
                    200,  // Ration
                    -4  // move_index
                },
                {
                    13,  // Diff_EV
                    246,  // Ration
                    -4  // move_index
                },
                {
                    16,  // Diff_EV
                    303,  // Ration
                    -6  // move_index
                },
                {
                    20,  // Diff_EV
                    400,  // Ration
                    -7  // move_index
                },
                {
                    25,  // Diff_EV
                    566,  // Ration
                    -9  // move_index
                },
                {
                    30,  // Diff_EV
                    800,  // Ration
                    -11  // move_index
                }
            }
        },
        // strAELimiterData
        {
            2,  // iLEVEL1_GAIN
            10,  // iLEVEL2_GAIN
            18,  // iLEVEL3_GAIN
            28,  // iLEVEL4_GAIN
            40,  // iLEVEL5_GAIN
            50,  // iLEVEL6_GAIN
            0,  // iLEVEL1_TARGET_DIFFERENCE
            4,  // iLEVEL2_TARGET_DIFFERENCE
            7,  // iLEVEL3_TARGET_DIFFERENCE
            7,  // iLEVEL4_TARGET_DIFFERENCE
            7,  // iLEVEL5_TARGET_DIFFERENCE
            7,  // iLEVEL6_TARGET_DIFFERENCE
            2,  // iLEVEL1_GAINH
            -2,  // iLEVEL1_GAINL
            6,  // iLEVEL2_GAINH
            -7,  // iLEVEL2_GAINL
            8,  // iLEVEL3_GAINH
            -9,  // iLEVEL3_GAINL
            10,  // iLEVEL4_GAINH
            -12,  // iLEVEL4_GAINL
            12,  // iLEVEL5_GAINH
            -16,  // iLEVEL5_GAINL
            15,  // iLEVEL6_GAINH
            -20,  // iLEVEL6_GAINL
            1  // iGAIN_DIFFERENCE_LIMITER
        },
        // strVdoDFps
        {
            1,  // isEnableDFps
            50,  // EVThresNormal
            50  // EVThresNight
        },
        // AEBlockWINCFG
        {
            0,  // uHist0StartBlockXRatio
            100,  // uHist0EndBlockXRatio
            0,  // uHist0StartBlockYRatio
            100,  // uHist0EndBlockYRatio
            3,  // uHist0OutputMode
            0,  // uHist0BinMode
            0,  // uHist1StartBlockXRatio
            100,  // uHist1EndBlockXRatio
            0,  // uHist1StartBlockYRatio
            100,  // uHist1EndBlockYRatio
            3,  // uHist1OutputMode
            0,  // uHist1BinMode
            0,  // uHist2StartBlockXRatio
            100,  // uHist2EndBlockXRatio
            0,  // uHist2StartBlockYRatio
            100,  // uHist2EndBlockYRatio
            4,  // uHist2OutputMode
            0,  // uHist2BinMode
            25,  // uHist3StartBlockXRatio
            75,  // uHist3EndBlockXRatio
            25,  // uHist3StartBlockYRatio
            75,  // uHist3EndBlockYRatio
            4,  // uHist3OutputMode
            0,  // uHist3BinMode
            25,  // uHist4StartBlockXRatio
            75,  // uHist4EndBlockXRatio
            25,  // uHist4StartBlockYRatio
            75,  // uHist4EndBlockYRatio
            4,  // uHist4OutputMode
            1,  // uHist4BinMode
            25,  // uHist5StartBlockXRatio
            75,  // uHist5EndBlockXRatio
            25,  // uHist5StartBlockYRatio
            75,  // uHist5EndBlockYRatio
            4,  // uHist5OutputMode
            1  // uHist5BinMode
        },
        // AEPixelWINCFG
        {
            0,  // uHist0StartBlockXRatio
            100,  // uHist0EndBlockXRatio
            0,  // uHist0StartBlockYRatio
            100,  // uHist0EndBlockYRatio
            0,  // uHist0OutputMode
            1,  // uHist0BinMode
            0,  // uHist1StartBlockXRatio
            100,  // uHist1EndBlockXRatio
            0,  // uHist1StartBlockYRatio
            100,  // uHist1EndBlockYRatio
            1,  // uHist1OutputMode
            1,  // uHist1BinMode
            0,  // uHist2StartBlockXRatio
            100,  // uHist2EndBlockXRatio
            0,  // uHist2StartBlockYRatio
            100,  // uHist2EndBlockYRatio
            2,  // uHist2OutputMode
            1,  // uHist2BinMode
            25,  // uHist3StartBlockXRatio
            75,  // uHist3EndBlockXRatio
            25,  // uHist3StartBlockYRatio
            75,  // uHist3EndBlockYRatio
            4,  // uHist3OutputMode
            1,  // uHist3BinMode
            25,  // uHist4StartBlockXRatio
            75,  // uHist4EndBlockXRatio
            25,  // uHist4StartBlockYRatio
            75,  // uHist4EndBlockYRatio
            4,  // uHist4OutputMode
            1,  // uHist4BinMode
            25,  // uHist5StartBlockXRatio
            75,  // uHist5EndBlockXRatio
            25,  // uHist5StartBlockYRatio
            75,  // uHist5EndBlockYRatio
            4,  // uHist5OutputMode
            1  // uHist5BinMode
        },
        // PSPixelWINCFG
        {
            0,  // uHistStartBlockXRatio
            100,  // uHistEndBlockXRatio
            0,  // uHistStartBlockYRatio
            100  // uHistEndBlockYRatio
        },
        0,  // bOldAESmooth
        1,  // bEnableSubPreIndex
        0,  // u4VideoLPFWeight
        // FaceLocSizecheck
        {
            1,  // bFaceLocSizeCheck
            // u4Size_X
            {
                15, 3
            },
            // u4Size_Y
            {
                768, 196
            },
            // u4Loc_X
            {
                200, 600
            },
            // u4Loc_Y
            {
                1024, 1024
            },
            1,  // bFaceOECheck
            // u4OE_X
            {
                10240, 20480
            },
            // u4OE_Y
            {
                1024, 768
            },
            // i4OE_BV_X
            {
                3500, 6000
            },
            // u4OE_BV_Y
            {
                1024, 1024
            },
            // u4FCY_DX
            {
                10, 30
            },
            // u4FCY_INDOOR_DX
            {
                10, 30
            },
            // u4FCY_BX
            {
                130, 100
            },
            // u4FCY_Y
            {
                1024, 0
            },
            1  // bLandmarkSize
        },
        // PerframeCFG
        {
            200,  // i4DeltaEVDiff
            80,  // u4WoAccRatio
            80,  // u4BoAccRatio
            240,  // u4PredY_H
            4,  // u4PredY_L
            254,  // u4AccY_Max
            510,  // u4AccCWV_Max
            1,  // u4AccY_Min
            1  // bRecycleEnable
        },
        1,  // bPerFrameAESmooth
        0,  // bPerFrameHDRAESmooth
        0,  // bTgIntAEEn
        1,  // bSpeedupEscOverExp
        0,  // bSpeedupEscUnderExp
        // AETgTuningParam
        {
            252,  // OverExpoThr
            70,  // OverExpoRatio
            200,  // OverExpoResetAccEVTh
            // OverExpoSTD_Th
            {
                80, 300, 500
            },
            // OverExpoSTD_Ratio
            {
                100, 85, 60, 40
            },
            // OverExpoAccDeltaEV_Th
            {
                30, 40, 50
            },
            // OverExpoAccDeltaEV_DeltaEV
            {
                -30, -24, -20, -10
            },
            200,  // OverExpoCountSTD_Th
            165,  // OverExpoLowBound
            24,  // OverExpLightAcc1
            20,  // OverExpLightAcc2
            18,  // OverExpLightAcc3
            16,  // OverExpLightAcc4
            7,  // UnderExpoThr
            80,  // UnderExpoRatio
            20,  // UnderExpoResetAccEVTh
            // UnderExpoSTD_Th
            {
                80, 250, 500
            },
            // UnderExpoSTD_Ratio
            {
                100, 85, 60, 35
            },
            // UnderExpoAccDeltaEV_Th
            {
                30, 40, 50
            },
            // UnderExpoAccDeltaEV_DeltaEV
            {
                20, 15, 10, 10
            },
            20  // UnderExpoCountSTD_Th
        },
        // TgEVCompJumpRatioOverExp
        {
            // EVValue
            {
                100, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 100, 100, 100, 100, 100, 110, 110, 110, 110,
                120, 120, 120, 130, 130, 140, 140, 140, 150, 150,
                170, 170, 170, 170, 170, 170, 170, 170, 170, 170,
                200, 200, 200, 200, 200, 200, 200, 200, 200, 200,
                200
            }
        },
        // TgEVCompJumpRatioUnderExp
        {
            // EVValue
            {
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0
            }
        },
        // pTgWeightTbl
        {
            {
                55, 55, 69, 83, 83, 83, 83, 83, 83, 69,
                55, 55
            },
            {
                69, 69, 86, 104, 104, 113, 143, 104, 104, 86,
                69, 69
            },
            {
                83, 83, 104, 125, 125, 143, 143, 125, 125, 104,
                83, 83
            },
            {
                83, 83, 123, 134, 134, 143, 143, 134, 134, 123,
                83, 83
            },
            {
                83, 83, 143, 143, 143, 143, 143, 143, 143, 143,
                83, 83
            },
            {
                83, 83, 123, 134, 134, 143, 143, 134, 134, 123,
                83, 83
            },
            {
                83, 83, 104, 125, 125, 143, 143, 125, 125, 104,
                83, 83
            },
            {
                69, 69, 86, 104, 104, 113, 143, 104, 104, 86,
                69, 69
            },
            {
                55, 55, 69, 83, 83, 83, 83, 83, 83, 69,
                55, 55
            }
        },
        // AEStableThd
        {
            0,  // u4InStableThd
            1,  // u4OutStableThd
            1,  // bEnableAEModeStableTHD
            1,  // u4VideoInStableThd
            1,  // u4VideoOutStableThd
            1,  // u4FaceInStableThd
            3,  // u4FaceOutStableThd
            15,  // u4FaceOutB2TStableThd
            15,  // u4FaceOutD2TStableThd
            0,  // u4TouchInStableThd
            3,  // u4TouchOutStableThd
            0,  // bEnableFaceAeLock
            0  // bEnableZeroStableThd
        },
        // BVAccRatio
        {
            1,  // u4BVAccEnable
            90,  // i4DeltaBVRatio
            220,  // u4B2T_Target
            // pAEBVAccRatio
            {
                100,  // u4SpeedUpRatio
                100,  // u4GlobalRatio
                255,  // u4Bright2TargetEnd
                20,  // u4Dark2TargetStart
                200,  // u4B2TEnd
                100,  // u4B2TStart
                40,  // u4D2TEnd
                90  // u4D2TStart
            }
        },
        // PSOConverge
        {
            1,  // u4PsoAccEnable
            100,  // i4PsoEscRatioWO
            50,  // i4PsoEscRatioNonLinear
            4000,  // ConvergeDeltaPosBound
            -4000  // ConvergeDeltaNegBound
        },
        // NonCWRAcc
        {
            0,  // bNonCWRAccEnable
            255,  // u4HS_FHY_HBound
            160,  // u4CWV_HBound
            160,  // u4HS_TargetHBound
            58  // u4HS_ACCTarget
        },
        // FaceSmooth
        {
            10,  // u4MinFDYLowBound
            360,  // u4MaxFDYHighBound
            0,  // i4FaceBVLowBound
            4000,  // i4FaceBVHighBound
            235,  // u4TmpFDY_HBound
            1,  // u4TmpFDY_LBound
            20,  // u4FD_Lost_MaxCnt
            100,  // u4FD_Scale_Ratio
            35,  // u4FaceNSLowBound
            5,  // u4FD_Lock_MaxCnt
            0,  // u4FD_TemporalSmooth
            70,  // u4FD_FaceTopCropRat
            100,  // u4FD_FaceBottomCropRat
            100,  // u4FD_FaceLeftCropRat
            100,  // u4FD_FaceRightCropRat
            5,  // u4FD_InToOutThdMaxCnt
            220,  // u4FD_OTLockUpperBnd
            0,  // u4FD_OTLockLowerBnd
            2,  // u4FD_ContinueTrustCnt
            0,  // u4FD_PerframeAntiOverFlag
            0,  // u4FD_SideFaceLock
            1,  // u4FD_LimitStableThdLowBnd
            0,  // u4FD_LimitStableThdLowBndNum
            1,  // u4FD_ReConvergeWhenFaceChange
            15,  // u4FD_FaceMotionLockRat
            3,  // u4FD_ImpulseLockCnt
            25,  // u4FD_ImpulseUpperThd
            18,  // u4FD_ImpulseLowerThd
            2,  // u4FD_ROPTrustCnt
            30,  // u4FD_ReCovergeWhenSizeChangeRat
            120,  // u4FD_ReCovergeWhenPosChangeDist
            3000,  // u4FD_ReCovergeWhenRealBVx1000DiffLarge
            1,  // u4FD_ReCovergeWhenAFDone
            1,  // u4FD_OTFaceLock
            0,  // bCnnFaceEnable
            0,  // bReConvergeWhenCNNFaceBack
            4,  // i4PortraitTolerance
            400,  // i4FD_CNN_Lock_MaxCnt
            0,  // bEVCompExceptionEnable
            10000,  // u4EVCompTouchMeteringStableMax
            1,  // u4EVCompTouchMeteringStableMin
            20,  // u4EVCompTouchOutStableThd
            15,  // u4EVCompTouchInStableThd
            0,  // bFaceAccLockEnable
            100,  // u4FaceAccLockThd
            0,  // u4FaceAccLock_MaxCnt
            0,  // bFaceGyroDiffLockEnable
            100,  // u4FaceGyroDiffLockThd
            0  // u4FaceGyroDiffLock_MaxCnt
        },
        // FaceWeight
        {
            1,  // bEnableMultiFaceWeight
            FACE_PRIOR_TIME,  // Prior
            // u4FaceWeight
            {
                1, 0, 0, 0, 0, 0, 0, 0, 0
            }
        },
        // AETempSmooth
        {
            0,  // bEnableAEHsTS
            0,  // bEnableAEAblTS
            0,  // bEnableAEAoeTS
            0,  // bEnableAENsTS
            1,  // bEnableAEFaceTS
            1,  // bEnableAEVideoTS
            0,  // bEnableAEMainTargetTS
            0  // bEnableAEHsV4p0TargetTS
        },
        // FaceLandmark
        {
            1,  // bLandmarkCtrlFlag
            0,  // u4LandmarkCV_Thd
            3,  // u4LandmarkWeight
            100,  // i4LandmarkExtRatW
            100,  // i4LandmarkExtRatH
            90,  // i4LandmarkTrustRopDegree
            5,  // i4RoundXYPercent
            3,  // i4RoundSZPercent
            9,  // i4THOverlap
            3,  // i4BUFLEN
            8,  // i4SMOOTH_LEVEL
            0,  // i4MOMENTUM
            60  // u4LandmarkWeightPercent
        },
        // AOERefBV
        {
            1,  // bEnable
            4,  // u4TblLength
            // i4BV
            {
                -2000, 0, 3000, 5500, 0, 0, 0, 0
            },
            // u4THD
            {
                150, 170, 180, 180, 0, 0, 0, 0
            }
        },
        // NsCdfRatio
        {
            1,  // bEnable
            700,  // u4Pcent
            // i4NS_CDFRatio_X
            {
                -1400, -500
            },
            // u4NS_CDFRatio_Y
            {
                1024, 0
            }
        },
        // AETouchMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            190,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            80,  // u4B2TEnd
            60,  // u4B2TStart
            40,  // u4D2TEnd
            80  // u4D2TStart
        },
        // HSFlatSkyEnhance
        {
            1,  // bEnableFlatSkyEnhance
            2,  // uSkyDetInThd
            5,  // uSkyDetOutThd
            160,  // u4FlatSkyTHD
            1500,  // u4FlatSkyEVD
            // u4BVRatio_X
            {
                8000, 11000
            },
            // u4BVRatio_Y
            {
                0, 1024
            }
        },
        // ABLabsDiff
        {
            1,  // bEnableABLabsDiff
            // u4EVDiffRatio_X
            {
                2500, 5000
            },
            // u4EVDiffRatio_Y
            {
                0, 1024
            },
            // u4BVRatio_X
            {
                9000, 11000
            },
            // u4BVRatio_Y
            {
                0, 1024
            }
        },
        // HSMultiStep
        {
            1,  // bEnableMultiStepHS
            4,  // u4TblLength
            // u4MS_EVDiff
            {
                1100, 2600, 4500, 6000, 0, 0, 0, 0
            },
            // u4MS_OutdoorTHD
            {
                65, 150, 165, 180, 0, 0, 0, 0
            },
            // u4MS_IndoorTHD
            {
                65, 140, 150, 165, 0, 0, 0, 0
            },
            // i4MS_BVRatio
            {
                4500, 8000
            }
        },
        // HistStableCFG
        {
            0,  // bEnableStablebyHist
            250,  // u4HistEVDiff
            242,  // u4OverexpoTHD
            13,  // u4UnderexpoTHD
            140  // u4HistStableTHD
        },
        // OverExpoAOECFG
        {
            1,  // bEnableOverExpoAOE
            1,  // bEnableHistOverExpoCnt
            20,  // u4OElevel
            1,  // u4OERatio_LowBnd
            20,  // u4OERatio_HighBnd
            // i4OE_BVRatio_X
            {
                4500, 6000
            },
            // u4OE_BVRatio_Y
            {
                0, 1024
            },
            // u4OEWeight
            {
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                },
                {
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1
                }
            }
        },
        1,  // bAEv4p0MeterEnable
        // MainTargetCFG
        {
            1,  // bEnableAEMainTarget
            1024,  // u4MainTargetWeight
            // u4MainTargetWeightTbl
            {
                {
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0
                },
                {
                    0, 43, 50, 57, 65, 68, 71, 74, 71, 68,
                    65, 57, 50, 43, 0
                },
                {
                    0, 50, 58, 67, 76, 79, 83, 86, 83, 79,
                    76, 67, 58, 50, 0
                },
                {
                    0, 57, 67, 77, 87, 91, 95, 99, 95, 91,
                    87, 77, 67, 57, 0
                },
                {
                    0, 65, 76, 87, 98, 102, 107, 112, 107, 102,
                    98, 87, 76, 65, 0
                },
                {
                    0, 68, 79, 91, 102, 107, 112, 117, 112, 107,
                    102, 91, 79, 68, 0
                },
                {
                    0, 71, 83, 95, 107, 112, 117, 122, 117, 112,
                    107, 95, 83, 71, 0
                },
                {
                    0, 74, 86, 99, 112, 117, 122, 128, 122, 117,
                    112, 99, 86, 74, 0
                },
                {
                    0, 71, 83, 95, 107, 112, 117, 122, 117, 112,
                    107, 95, 83, 71, 0
                },
                {
                    0, 68, 79, 91, 102, 107, 112, 117, 112, 107,
                    102, 91, 79, 68, 0
                },
                {
                    0, 65, 76, 87, 98, 102, 107, 112, 107, 102,
                    98, 87, 76, 65, 0
                },
                {
                    0, 57, 67, 77, 87, 91, 95, 99, 95, 91,
                    87, 77, 67, 57, 0
                },
                {
                    0, 50, 58, 67, 76, 79, 83, 86, 83, 79,
                    76, 67, 58, 50, 0
                },
                {
                    0, 43, 50, 57, 65, 68, 71, 74, 71, 68,
                    65, 57, 50, 43, 0
                },
                {
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0
                }
            },
            // TargetBVRatioTbl
            {
                0,  // u4X1
                52,  // u4Y1
                9000,  // u4X2
                72  // u4Y2
            },
            0,  // bEnableColorWTRatio
            // ColorWTRatioTbl
            {
                130,  // u4X1
                1024,  // u4Y1
                300,  // u4X2
                768  // u4Y2
            },
            100,  // uColorSupRatioR
            100,  // uColorSupRatioG
            0,  // uColorSupRatioB
            // ColorSupBVRatioTbl
            {
                5000,  // u4X1
                0,  // u4Y1
                6500,  // u4X2
                1024  // u4Y2
            }
        },
        // HSv4p0CFG
        {
            1,  // bEnableHSv4p0
            1024,  // u4HSv4p0Weight
            5,  // u4BVSize
            5,  // u4EVDSize
            // i4HS_BVRatio
            {
                -500, 1000, 3500, 9000, 11000, 0, 0, 0
            },
            // u4HS_PcntRatio
            {
                50, 50, 25, 20, 20, 0, 0, 0
            },
            // u4HS_EVDRatio
            {
                500, 1100, 2500, 3200, 6000, 0, 0, 0
            },
            // u4HSTHDRatioTbl
            {
                {
                    120, 130, 160, 190, 200, 0, 0, 0
                },
                {
                    120, 130, 190, 200, 220, 0, 0, 0
                },
                {
                    130, 160, 230, 235, 240, 0, 0, 0
                },
                {
                    130, 160, 240, 240, 250, 0, 0, 0
                },
                {
                    140, 160, 245, 250, 255, 0, 0, 0
                },
                {
                    0, 0, 0, 0, 0, 0, 0, 0
                },
                {
                    0, 0, 0, 0, 0, 0, 0, 0
                },
                {
                    0, 0, 0, 0, 0, 0, 0, 0
                }
            },
            1,  // bEnableDynWTRatio
            // DynWTRatioTbl
            {
                0,  // u4X1
                0,  // u4Y1
                30,  // u4X2
                384  // u4Y2
            },
            0,  // bEnableHsGreenSupress
            120,  // u4HsGreenGRRatio
            130,  // u4HsGreenGBRatio
            70,  // u4HsSupRatio
            // u4HS_GCountRatio_X
            {
                256, 512
            },
            // u4HS_GCountRatio_Y
            {
                0, 1024
            }
        },
        // NSBVCFG
        {
            1,  // bEnableNSBVCFG
            3,  // u4TblLength
            // i4BV
            {
                -4500, -3000, 1000, 0, 0, 0, 0, 0
            },
            // u4BTTHD
            {
                55, 80, 90, 0, 0, 0, 0, 0
            },
            // u4NSTHD
            {
                140, 160, 170, 0, 0, 0, 0, 0
            }
        },
        // AEACCMovingRatio
        {
            100,  // u4SpeedUpRatio
            100,  // u4GlobalRatio
            255,  // u4Bright2TargetEnd
            20,  // u4Dark2TargetStart
            100,  // u4B2TEnd
            100,  // u4B2TStart
            100,  // u4D2TEnd
            100  // u4D2TStart
        },
        // HdrAECFG
        {
            eMainHDR_OFF,  // eHdrParamID
            // rHdrDetector
            {
                1,  // bHdrDetectorEnable
                4500,  // i4HdrConfidenceThr
                // rHdrHistInfo
                {
                    1,  // bHistDetectEnable
                    // rHdrDetectDarkWtWin
                    {
                        6,  // i4HdrHistP0
                        12,  // i4HdrHistP1
                        100,  // i4HdrHistW0
                        0  // i4HdrHistW1
                    },
                    // rHdrDetectBrightWtWin
                    {
                        180,  // i4HdrHistP0
                        220,  // i4HdrHistP1
                        0,  // i4HdrHistW0
                        300  // i4HdrHistW1
                    },
                    // rHdrEnhanceBrightWtWin
                    {
                        220,  // i4HdrHistP0
                        245,  // i4HdrHistP1
                        0,  // i4HdrHistW0
                        300  // i4HdrHistW1
                    },
                    // rHdrFDBrightWtWin
                    {
                        220,  // i4HdrHistP0
                        245,  // i4HdrHistP1
                        0,  // i4HdrHistW0
                        300  // i4HdrHistW1
                    },
                    60,  // i4HdrContrastPercentH
                    450,  // i4HdrContrastPercentL
                    50,  // i4HdrNightEVDiffPercentH
                    300,  // i4HdrNightEVDiffPercentL
                    500,  // i4HdrNightDarkPercent
                    // rHdrNightEVDiffProb
                    {
                        4800,  // u4X1
                        0,  // u4Y1
                        6500,  // u4X2
                        1024  // u4Y2
                    },
                    // rHdrNightHistProb
                    {
                        2,  // u4X1
                        1024,  // u4Y1
                        10,  // u4X2
                        0  // u4Y2
                    },
                    // rHdrNightLVProb
                    {
                        50,  // u4X1
                        1024,  // u4Y1
                        100,  // u4X2
                        0  // u4Y2
                    }
                },
                // rHdrGeometryInfo
                {
                    // rGeometryCOEProp
                    {
                        1,  // bGeometryCOEEnable
                        1024,  // i4COEWeight
                        // rHdrCOEOuterRatio
                        {
                            23,  // u4X1
                            1024,  // u4Y1
                            47,  // u4X2
                            0  // u4Y2
                        },
                        // rHdrCOEDiffRatio
                        {
                            1900,  // u4X1
                            0,  // u4Y1
                            2400,  // u4X2
                            1024  // u4Y2
                        }
                    },
                    // rGeometryABLProp
                    {
                        1,  // bGeometryABLEnable
                        1024,  // i4ABLWeight
                        // rCenterBrightDiffRatio
                        {
                            3150,  // u4X1
                            0,  // u4Y1
                            5000,  // u4X2
                            1024  // u4Y2
                        },
                        // rCenterDarkDiffRatio
                        {
                            3150,  // u4X1
                            0,  // u4Y1
                            5000,  // u4X2
                            1024  // u4Y2
                        }
                    }
                },
                // rHdrLVInfo
                {
                    1,  // bLVDetectEnable
                    // i4LVProbTbl
                    {
                        0, 0, 0, 0, 0, 0, 0, 0, 33, 66,
                        100, 100, 100, 66, 33, 0, 0, 0, 0
                    }
                }
            },
            // rHdrAutoEnhance
            {
                1,  // bAutoEnhanceEnable
                4095,  // i4RMGk
                40,  // i4RMGtRatio
                // rRMGt
                {
                    160,  // u4X1
                    512,  // u4Y1
                    220,  // u4X2
                    384  // u4Y2
                },
                2,  // i4SupportHdrNum
                1024,  // i4AutoEnhanceProb
                1024,  // i4HdrWeight
                // rAutoBright
                {
                    // i4LVRatio50
                    {
                        200, 200, 200, 200, 200, 200, 200, 200, 200, 200,
                        200, 200, 200, 200, 200, 200, 200, 200, 200
                    },
                    // i4LVRatio60
                    {
                        200, 200, 200, 200, 200, 200, 200, 200, 200, 200,
                        200, 200, 200, 200, 200, 200, 200, 200, 200
                    },
                    // rContrastRatio
                    {
                        3500,  // u4X1
                        100,  // u4Y1
                        4500,  // u4X2
                        200  // u4Y2
                    },
                    // rBrightRatio
                    {
                        600,  // u4X1
                        400,  // u4Y1
                        1100,  // u4X2
                        400  // u4Y2
                    },
                    // rNightProbRatio
                    {
                        0,  // u4X1
                        200,  // u4Y1
                        512,  // u4X2
                        100  // u4Y2
                    },
                    // rGGyroSensor
                    {
                        // rAcceProb
                        {
                            1100,  // u4X1
                            0,  // u4Y1
                            1500,  // u4X2
                            1024  // u4Y2
                        },
                        // rGyroProb
                        {
                            50,  // u4X1
                            0,  // u4Y1
                            200,  // u4X2
                            1024  // u4Y2
                        },
                        // rMotionRatio
                        {
                            512,  // u4X1
                            400,  // u4Y1
                            960,  // u4X2
                            100  // u4Y2
                        },
                        512,  // i4MotionOnThr
                        2  // i4MotionOnCntThr
                    }
                },
                // rAutoFlicker
                {
                    // i4Flkr1LVThr
                    {
                        130, 130
                    },
                    800,  // i4MinRatioAntiFlk
                    // i4MaxExp
                    {
                        70007, 66670
                    },
                    // i4MinExp
                    {
                        400, 400
                    },
                    // rIsoThr
                    {
                        12288,  // u4X1
                        400,  // u4Y1
                        14336,  // u4X2
                        100  // u4Y2
                    }
                },
                // rAutoSmooth
                {
                    1,  // bHdrWaitAEStable
                    6,  // i4HdrInfoCounterThr
                    1,  // bRatioSmoothEnable
                    0,  // i4AutoWeightMode
                    4,  // i4AutoWeightSmooth
                    4,  // i4AutoWeightStableThr
                    0,  // i4RMGtStableMode
                    4,  // i4RMGtStableThr
                    0,  // i4HdrRatioStableMode
                    4,  // i4HdrRatioStableThr
                    // i4RatioSmoothThr
                    {
                        1, 1
                    },
                    // i4RoughRatioUnit
                    {
                        30, 60
                    },
                    // i4FinerRatioUnit
                    {
                        15, 60
                    },
                    // i4RMGtUnit
                    {
                        128, 384
                    }
                },
                // rAutoTuning
                {
                    10,  // i4RmmExpoDiffThr
                    24  // i4LscRatio
                },
                100  // i4FlashRatio
            },
            // rHdrAETarget
            {
                47,  // i4DefTarget
                0,  // i4DefWeight
                // rAutoEVWeight
                {
                    4000,  // u4X1
                    256,  // u4Y1
                    5000,  // u4X2
                    512  // u4Y2
                },
                // rAutoBrightWeight
                {
                    4000,  // u4X1
                    256,  // u4Y1
                    5000,  // u4X2
                    768  // u4Y2
                },
                // rAutoABLWeight
                {
                    0,  // u4X1
                    1024,  // u4Y1
                    512,  // u4X2
                    1024  // u4Y2
                },
                // rAutoLVWeightL
                {
                    30,  // u4X1
                    768,  // u4Y1
                    40,  // u4X2
                    1024  // u4Y2
                },
                // rAutoLVWeightH
                {
                    100,  // u4X1
                    256,  // u4Y1
                    130,  // u4X2
                    512  // u4Y2
                },
                // rAutoNightWeight
                {
                    1024,  // u4X1
                    512,  // u4Y1
                    2048,  // u4X2
                    256  // u4Y2
                },
                // rHdrAoeTarget
                {
                    25,  // i4AoePercent
                    // i4AoeLV
                    {
                        50, 100, 150
                    },
                    // i4AoeTarget
                    {
                        220, 220, 220
                    }
                },
                // rHdrNightTarget
                {
                    150,  // i4NightPercent
                    // rNightTarget
                    {
                        0,  // u4X1
                        80,  // u4Y1
                        1024,  // u4X2
                        60  // u4Y2
                    }
                },
                // rTargetLimitL
                {
                    60,  // i4LVLimit
                    // rTargetMinLimit
                    {
                        4000,  // u4X1
                        10,  // u4Y1
                        6000,  // u4X2
                        10  // u4Y2
                    },
                    // rTargetMaxLimit
                    {
                        4000,  // u4X1
                        50,  // u4Y1
                        6000,  // u4X2
                        50  // u4Y2
                    }
                },
                // rTargetLimitM
                {
                    80,  // i4LVLimit
                    // rTargetMinLimit
                    {
                        4000,  // u4X1
                        15,  // u4Y1
                        6000,  // u4X2
                        20  // u4Y2
                    },
                    // rTargetMaxLimit
                    {
                        4000,  // u4X1
                        50,  // u4Y1
                        6000,  // u4X2
                        50  // u4Y2
                    }
                },
                // rTargetLimitH
                {
                    120,  // i4LVLimit
                    // rTargetMinLimit
                    {
                        4000,  // u4X1
                        25,  // u4Y1
                        6000,  // u4X2
                        40  // u4Y2
                    },
                    // rTargetMaxLimit
                    {
                        4000,  // u4X1
                        47,  // u4Y1
                        6000,  // u4X2
                        90  // u4Y2
                    }
                }
            },
            // rHdrMiscProp
            {
                // rFaceAEProp
                {
                    // rFaceEVProb
                    {
                        3800,  // u4X1
                        128,  // u4Y1
                        5000,  // u4X2
                        1024  // u4Y2
                    },
                    // rFaceHdrProb
                    {
                        2000,  // u4X1
                        1024,  // u4Y1
                        3200,  // u4X2
                        128  // u4Y2
                    }
                }
            },
            // rHdrcHdr
            {
                40,  // i4LEThr
                20,  // i4SERatio
                180,  // i4SETarget
                1024  // i4BaseGain
            }
        }
        ,{ // strStereoPlineMapping
            { // sAESceneMapping
            {LIB3A_AE_SCENE_AUTO, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_NIGHT, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_ACTION, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_BEACH, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_CANDLELIGHT, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_FIREWORKS, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_LANDSCAPE, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_PORTRAIT, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_NIGHT_PORTRAIT, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_PARTY, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_SNOW, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_SPORTS, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_STEADYPHOTO, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_SUNSET, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_THEATRE, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_ISO_ANTI_SHAKE, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX12}},
            {LIB3A_AE_SCENE_ISO100, {AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX15, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX15}},
            {LIB3A_AE_SCENE_ISO200, {AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO200, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO200}},
            {LIB3A_AE_SCENE_ISO400, {AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO400, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO400}},
            {LIB3A_AE_SCENE_ISO800, {AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO800, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO800}},
            {LIB3A_AE_SCENE_ISO1600, {AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO1600, AETABLE_SCENE_INDEX13, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_SCENE_INDEX11, AETABLE_CAPTURE_ISO1600}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            {LIB3A_AE_SCENE_UNSUPPORTED, {AETABLE_RPEVIEW_AUTO, AETABLE_CAPTURE_AUTO, AETABLE_VIDEO_AUTO, AETABLE_VIDEO1_AUTO, AETABLE_VIDEO2_AUTO, AETABLE_CUSTOM1_AUTO, AETABLE_CUSTOM2_AUTO, AETABLE_CUSTOM3_AUTO, AETABLE_CUSTOM4_AUTO, AETABLE_CUSTOM5_AUTO, AETABLE_CAPTURE_AUTO}},
            }
        },
        { // strHDRPlineMapping
            { // sAESceneMapping
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
            }
        },
        { // strDynamicFlareCFG
            8,  // u4FlareSmallDeltaIdxStep
            4,  // u4CWVChangeStep
            2,  // u4AllStableStep
            0,  // bOutdoorFlareEnable
            64,  // u4OutdoorMaxFlareThres
            // i4BVRatio
            {
                2000, 3500
            }
        }
    },

};
