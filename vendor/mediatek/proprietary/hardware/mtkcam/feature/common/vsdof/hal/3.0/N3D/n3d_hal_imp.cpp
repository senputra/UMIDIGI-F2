/*********************************************************************************************
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
#include <stdlib.h>

#include "n3d_hal_imp.h"         // For N3D_HAL class.
#include "../inc/stereo_dp_util.h"

#include <mtkcam/drv/IHalSensor.h>
#include <mtkcam/aaa/INvBufUtil.h>
#include <af_param.h>          // For AF_ROI_SEL_FD
#include <camera_custom_stereo.h>   // For CUST_STEREO_* definitions.
#include <math.h>

#include <vsdof/hal/rapidjson/writer.h>
#include <vsdof/hal/rapidjson/stringbuffer.h>
#include <vsdof/hal/rapidjson/document.h>     // rapidjson's DOM-style API
#include <vsdof/hal/rapidjson/prettywriter.h> // for stringify JSON
#include <vsdof/hal/rapidjson/filewritestream.h>
#include <vsdof/hal/rapidjson/writer.h>
#include <vsdof/hal/extradata_def.h>

#include <vsdof/hal/AffinityUtil.h>
#include <vsdof/hal/json_util.h>
#include <stereo_crop_util.h>
#include <mtkcam/feature/stereo/hal/stereo_fd_proxy.h>
#include <fefm_setting_provider.h>
#include <algorithm>

using namespace rapidjson;
using android::Mutex;           // For android::Mutex in stereo_hal.h.

/**************************************************************************
 *                      D E F I N E S / M A C R O S                       *
 **************************************************************************/
#define PROPERTY_ENABLE_VERIFY  STEREO_PROPERTY_PREFIX"enable_verify"
#define PROPERTY_ENABLE_CC      STEREO_PROPERTY_PREFIX"enable_cc"
#define PROPERTY_DUMP_NVRAM     STEREO_PROPERTY_PREFIX"dump_nvram"
#define PROPERTY_DUMP_OUTPUT    STEREO_PROPERTY_PREFIX"dump_n3d"
#define PROPERTY_DUMP_CAPTURE   STEREO_PROPERTY_PREFIX"dump_n3d_capture"
#define PROPERTY_DUMP_JSON      STEREO_PROPERTY_PREFIX"dump_json"
#define PROPERTY_DUMP_CAL       STEREO_PROPERTY_PREFIX"dump_cal"
#define PROPERTY_SYSTEM_CFG     STEREO_PROPERTY_PREFIX"system_cfg"

#define EXTERN_EEPROM_PATH      "/sdcard/EEPROM_STEREO"
#define EXTERN_LDC_PATH         "/sdcard/LensINFO"

const bool DUMP_INPUT_NVRAM  = true;
const bool DUMP_OUTPUT_NVRAM = !DUMP_INPUT_NVRAM;

/**************************************************************************
 *     E N U M / S T R U C T / T Y P E D E F    D E C L A R A T I O N     *
 **************************************************************************/

/**************************************************************************
 *                 E X T E R N A L    R E F E R E N C E S                 *
 **************************************************************************/

/**************************************************************************
 *                         G L O B A L    D A T A                         *
 **************************************************************************/

/**************************************************************************
 *       P R I V A T E    F U N C T I O N    D E C L A R A T I O N        *
 **************************************************************************/
Mutex N3D_HAL_IMP::__sLock;
Mutex N3D_HAL_IMP::__sLogLock;
Mutex N3D_HAL_IMP::__sRunLock;
NVRAM_CAMERA_GEOMETRY_STRUCT* N3D_HAL_IMP::__spVoidGeoData = NULL;
bool N3D_HAL_IMP::__useExternalCalibration = false;
N3D_HAL_KERNEL *N3D_HAL_IMP::__spPreviewKernel = NULL;
N3D_HAL_KERNEL *N3D_HAL_IMP::__spCaptureKernel = NULL;

/**************************************************************************
 *       Public Functions                                                 *
 **************************************************************************/
N3D_HAL *
N3D_HAL::createInstance(N3D_HAL_INIT_PARAM &n3dInitParam)
{
    return new N3D_HAL_IMP(n3dInitParam);
}

N3D_HAL_IMP::N3D_HAL_IMP(N3D_HAL_INIT_PARAM &n3dInitParam)
    : __LOG_ENABLED(StereoSettingProvider::isLogEnabled(LOG_PERPERTY))
    , __DISABLE_GPU(checkStereoProperty(PROPERTY_DISABLE_GPU) == 1)
    , __RUN_N3D(checkStereoProperty(PROPERTY_SKIP_N3D) != 1)
    , __DUMP_CAPTURE(checkStereoProperty(PROPERTY_DUMP_CAPTURE))
    , __DUMP_PREVIEW(checkStereoProperty(PROPERTY_DUMP_OUTPUT))
    , __DUMP_NVRAM(checkStereoProperty(PROPERTY_DUMP_NVRAM))
    , __eScenario(eSTEREO_SCENARIO_UNKNOWN)
    , __pAFTable{NULL, NULL}
    , __isAF{false, false}
    , __magicNumber{0, 0}
    , __requestNumber(0)
    , __n3dKernel(n3dInitParam)
    , __stereoExtraData(NULL)
    , __fastLogger(LOG_TAG, LOG_PERPERTY)
{
    __fastLogger.setSingleLineMode(SINGLE_LINE_LOG);

    __initN3DHAL(n3dInitParam);
}

N3D_HAL_IMP::~N3D_HAL_IMP()
{
    Mutex::Autolock lock(__sLock);    //To protect NVRAM access and staic instance

    __saveNVRAM();

    if(__spCaptureKernel == &__n3dKernel) {
        __spCaptureKernel = NULL;
    } else if(__spPreviewKernel == &__n3dKernel) {
        __spPreviewKernel = NULL;
    } else {
        MY_LOGE("Stereo drv does not match: this %p, preview %p, capture %p",
                &__n3dKernel, __spPreviewKernel, __spCaptureKernel);
    }

    if(__stereoExtraData) {
        delete [] __stereoExtraData;
        __stereoExtraData = NULL;
    }

    N3DDebugUtil::destroyInstance(__eScenario);
    __pN3DDebugUtil = NULL;
}

bool
N3D_HAL_IMP::__initN3DHAL(N3D_HAL_INIT_PARAM &n3dInitParam)
{
    __sensorSenarios[0] = StereoSettingProvider::getSensorScenarioMain1();
    __sensorSenarios[1] = StereoSettingProvider::getSensorScenarioMain2();

    __pN3DDebugUtil = (N3DDebugUtilImp *)N3DDebugUtil::getInstance(n3dInitParam.eScenario);

    switch(n3dInitParam.eScenario) {
        case eSTEREO_SCENARIO_CAPTURE:
            __algoInitInfo.scenario = STEREO_KERNEL_SCENARIO_IMAGE_CAPTURE;
            __spCaptureKernel = &__n3dKernel;
            __eScenario = eSTEREO_SCENARIO_CAPTURE;
            break;
        case eSTEREO_SCENARIO_PREVIEW:
        case eSTEREO_SCENARIO_RECORD:
        default:
            // __algoInitInfo.scenario = STEREO_KERNEL_SCENARIO_IMAGE_PREVIEW;
            __algoInitInfo.scenario = STEREO_KERNEL_SCENARIO_VIDEO_RECORD;
            __spPreviewKernel = &__n3dKernel;
            __eScenario = eSTEREO_SCENARIO_PREVIEW;
            break;
    }

    int32_t main1Idx, main2Idx;
    StereoSettingProvider::getStereoSensorIndex(main1Idx, main2Idx);

    //Make sure FEFM settings sync to N3D
    FEFMSettingProvider::getInstance()->init(main1Idx, main2Idx);
    if(!__initLensInfo(main1Idx, __pAFTable[0], __isAF[0])) {
        return false;
    }

    if(!__initLensInfo(main2Idx, __pAFTable[1], __isAF[1])) {
        return false;
    }

    __initAFWinTransform(n3dInitParam.eScenario);

    Pass2SizeInfo pass2SizeInfo;
    StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_2, __eScenario, pass2SizeInfo);
    __algoInitInfo.iio_main.inp_w = pass2SizeInfo.areaWDMA.size.w;
    __algoInitInfo.iio_main.inp_h = pass2SizeInfo.areaWDMA.size.h;

    __algoInitInfo.iio_main.src_w = pass2SizeInfo.areaWDMA.contentSize().w;
    __algoInitInfo.iio_main.src_h = pass2SizeInfo.areaWDMA.contentSize().h;

    StereoArea areaOutput;
    if(eSTEREO_SCENARIO_CAPTURE != __eScenario) {
        Pass2SizeInfo pass2SizeInfo;
        StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_P_2, __eScenario, pass2SizeInfo);
        __algoInitInfo.iio_auxi.src_w = pass2SizeInfo.areaWDMA.contentSize().w;
        __algoInitInfo.iio_auxi.src_h = pass2SizeInfo.areaWDMA.contentSize().h;
        __algoInitInfo.iio_auxi.inp_w = pass2SizeInfo.areaWDMA.size.w;
        __algoInitInfo.iio_auxi.inp_h = pass2SizeInfo.areaWDMA.size.h;

        areaOutput = StereoSizeProvider::getInstance()->getBufferSize(E_MV_Y, __eScenario);
        __algoInitInfo.iio_main.out_w = areaOutput.size.w;
        __algoInitInfo.iio_main.out_h = areaOutput.size.h;
    } else {
        Pass2SizeInfo pass2SizeInfo;
        StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_P_2, __eScenario, pass2SizeInfo);
        __algoInitInfo.iio_auxi.src_w = pass2SizeInfo.areaWDMA.contentSize().w;
        __algoInitInfo.iio_auxi.src_h = pass2SizeInfo.areaWDMA.contentSize().h;
        __algoInitInfo.iio_auxi.inp_w = pass2SizeInfo.areaWDMA.size.w;
        __algoInitInfo.iio_auxi.inp_h = pass2SizeInfo.areaWDMA.size.h;

        areaOutput = StereoSizeProvider::getInstance()->getBufferSize(E_MV_Y_LARGE, __eScenario);
        __algoInitInfo.iio_main.out_w = areaOutput.size.w;
        __algoInitInfo.iio_main.out_h = areaOutput.size.h;
    }

    //Not used
    __algoInitInfo.iio_auxi.out_w = __algoInitInfo.iio_main.out_w;
    __algoInitInfo.iio_auxi.out_h = __algoInitInfo.iio_main.out_h;

    if(E_N3D_WARP_WPE == N3D_WARP_HW) {
        MSize size = StereoSizeProvider::getInstance()->getBufferSize(E_WARP_MAP_M);
        __algoInitInfo.iio_main.wpe_w = size.w;
        __algoInitInfo.iio_main.wpe_h = size.h;
        size = StereoSizeProvider::getInstance()->getBufferSize(E_WARP_MAP_S);
        __algoInitInfo.iio_auxi.wpe_w = size.w;
        __algoInitInfo.iio_auxi.wpe_h = size.h;
    }

    // HWFE INPUT - the actual size for HWFE (after SRZ)
    __algoInitInfo.geo_info  = n3dInitParam.fefmRound;   //N3D_HAL_INIT_PARAM.fefmRound
    __algoInitInfo.geo_info |= 3<<2;
    __initN3DGeoInfo(__algoInitInfo.geo_img);              //FEFM setting

    // COLOR CORRECTION INPUT
    __initCCImgInfo(__algoInitInfo.pho_img);       //settings of main = auxi

    // Learning
    SensorFOV main1FOV, main2FOV;
    StereoSettingProvider::getStereoCameraFOV(main1FOV, main2FOV);
    __algoInitInfo.fov_main[0]     = main1FOV.fov_horizontal;
    __algoInitInfo.fov_main[1]     = main1FOV.fov_vertical;
    __algoInitInfo.fov_auxi[0]     = main2FOV.fov_horizontal;
    __algoInitInfo.fov_auxi[1]     = main2FOV.fov_vertical;

    __algoInitInfo.baseline     = StereoSettingProvider::getStereoBaseline();
    __loadNVRAM();  //Will update __useExternalCalibration, must called before __prepareSystemConfig
    __algoInitInfo.system_cfg   = __prepareSystemConfig();

    // Learning Coordinates RE-MAPPING
    __getStereoRemapInfo(__algoInitInfo.flow_main, __algoInitInfo.flow_auxi, __eScenario);

    ::memset(&__algoInitInfo.af_init_main, 0, sizeof(STEREO_KERNEL_AF_INIT_STRUCT));
    ::memset(&__algoInitInfo.af_init_auxi, 0, sizeof(STEREO_KERNEL_AF_INIT_STRUCT));

    __initAFInfo();

    __n3dKernel.initMain1Mask(StereoSizeProvider::getInstance()->getBufferSize(E_MV_Y, __eScenario));
    __n3dKernel.initN3D(__algoInitInfo, __spVoidGeoData, &(StereoSettingProvider::getLDCTable()[0]));

    return true;
}

bool
N3D_HAL_IMP::N3DHALWarpMain1(IImageBuffer *main1Input, IImageBuffer *main1Output, IImageBuffer *main1Mask)
{
    return (E_N3D_WARP_WPE == N3D_WARP_HW) || __n3dKernel.WarpMain1(main1Input, main1Output, main1Mask);
}

bool
N3D_HAL_IMP::N3DHALRun(N3D_HAL_PARAM &n3dParams, N3D_HAL_OUTPUT &n3dOutput)
{
    //Capture and preview instance cannot run simultaneously
    Mutex::Autolock lock(__sRunLock);

    if(eSTEREO_SCENARIO_CAPTURE == __eScenario) {
        MY_LOGW("Cannot run capture here");
        return false;
    }

    AutoProfileUtil profile(LOG_TAG, "N3DHALRun(Preview/VR)");

    __magicNumber[0] = n3dParams.magicNumber[0];
    __magicNumber[1] = n3dParams.magicNumber[1];
    __requestNumber  = n3dParams.requestNumber;
    __timestamp      = n3dParams.timestamp;
    __dumpHint       = n3dParams.dumpHint;
    MY_LOGD_IF(__LOG_ENABLED, "[Magic] %d, %d [Request] %d", __magicNumber[0], __magicNumber[1], __requestNumber);

    //Scenario may change due to EIS, re-init N3D if needed
    // if(!__isInit) {
    //     ENUM_STEREO_SCENARIO scenario = (n3dParams.eisData.isON) ? eSTEREO_SCENARIO_RECORD : eSTEREO_SCENARIO_PREVIEW;
    //     MUINT sensorScenarioMain1 = StereoSettingProvider::getSensorScenarioMain1();
    //     MUINT sensorScenarioMain2 = StereoSettingProvider::getSensorScenarioMain2();
    //     if(__sensorSenarios[0] != sensorScenarioMain1 ||
    //        __sensorSenarios[1] != sensorScenarioMain2 ||
    //        __eScenario != scenario)
    //     {
    //         __eScenario = scenario;
    //         __sensorSenarios[0] = sensorScenarioMain1;
    //         __sensorSenarios[1] = sensorScenarioMain2;

    //         Pass2SizeInfo pass2SizeInfo;
    //         StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_2, scenario, pass2SizeInfo);
    //         __algoInitInfo.iio_main.src_w = pass2SizeInfo.areaWDMA.size.w;
    //         __algoInitInfo.iio_main.src_h = pass2SizeInfo.areaWDMA.size.h;
    //         __algoInitInfo.iio_main.inp_w = __algoInitInfo.iio_main.src_w;
    //         __algoInitInfo.iio_main.inp_h = __algoInitInfo.iio_main.src_h;

    //         StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_P_2, scenario, pass2SizeInfo);
    //         __algoInitInfo.iio_auxi.src_w = pass2SizeInfo.areaWDMA.size.w;
    //         __algoInitInfo.iio_auxi.src_h = pass2SizeInfo.areaWDMA.size.h;
    //         __algoInitInfo.iio_auxi.inp_w = pass2SizeInfo.areaWDMA.size.w;
    //         __algoInitInfo.iio_auxi.inp_h = pass2SizeInfo.areaWDMA.size.h;

    //         MY_LOGI("Src size change: main1: %dx%d, main2: %dx%d, re-init N3D",
    //                 __algoInitInfo.iio_main.src_w, __algoInitInfo.iio_main.src_h,
    //                 __algoInitInfo.iio_auxi.src_w, __algoInitInfo.iio_auxi.src_h);

    //         // Learning Coordinates RE-MAPPING
    //         if(__eScenario != scenario) {
    //             __getStereoRemapInfo(__algoInitInfo.flow_main, __algoInitInfo.flow_auxi, __eScenario);
    //         }
    //     }

    //     __n3dKernel.initMain1Mask(StereoSizeProvider::getInstance()->getBufferSize(E_MV_Y, __eScenario));
    //     __n3dKernel.initN3D(__algoInitInfo, __spVoidGeoData, &(StereoSettingProvider::getLDCTable()[0]));
    //     __isInit = true;
    // }

    if(IS_DUMP_ENALED) {
        __dumpNVRAM(DUMP_INPUT_NVRAM);
        __dumpLDC();
        __n3dKernel.setDumpConfig(true, __dumpHint);
    } else {
        __n3dKernel.setDumpConfig(false);
    }

    //Not to learn even fefm buffers are given when not AF done frame
    __getRuntimeAFParams(__pAFTable[0], __magicNumber[0], __afInfoMain1);
    __getRuntimeAFParams(__pAFTable[1], __magicNumber[1], __afInfoMain2);

    if(n3dParams.hwfefmData.geoDataMain1[0] &&
       n3dParams.hwfefmData.geoDataMain2[0] &&
       n3dParams.hwfefmData.geoDataLeftToRight[0] &&
       n3dParams.hwfefmData.geoDataRightToLeft[0] &&
       __isAF[0])
    {
        bool needToLearn = false;
        if(!__isAF[1])
        {
            needToLearn = (!__wasAFStable[0] && __afInfoMain1.dac_v);
        }
        else
        {
            needToLearn = (__afInfoMain1.dac_v && __afInfoMain2.dac_v &&
                           !(__wasAFStable[0] && __wasAFStable[1]));
        }

        if(!needToLearn) {
            n3dParams.hwfefmData.geoDataMain1[0]       = NULL;
            n3dParams.hwfefmData.geoDataMain2[0]       = NULL;
            n3dParams.hwfefmData.geoDataLeftToRight[0] = NULL;
            n3dParams.hwfefmData.geoDataRightToLeft[0] = NULL;
        }
    }

    __wasAFStable[0] = __afInfoMain1.dac_v;
    __wasAFStable[1] = __afInfoMain2.dac_v;

    __n3dKernel.WarpMain2(n3dParams, &__afInfoMain1, &__afInfoMain2, n3dOutput);

    if(NULL != n3dParams.rectifyImgMain1 &&
       NULL != n3dOutput.rectifyImgMain1 &&
       NULL != n3dOutput.maskMain1)
    {
        __n3dKernel.WarpMain1(n3dParams.rectifyImgMain1, n3dOutput.rectifyImgMain1, n3dOutput.maskMain1);
    }

    if(IS_DUMP_ENALED) {
        __n3dKernel.dumpN3DInitConfig();    //Init may happen in WarpMain2
        __n3dKernel.dumpN3DRuntimeConfig();
        __dumpNVRAM(DUMP_OUTPUT_NVRAM);
    }

    return true;
}

bool
N3D_HAL_IMP::N3DHALRun(N3D_HAL_PARAM_CAPTURE &n3dParams, N3D_HAL_OUTPUT_CAPTURE &n3dOutput)
{
    //Capture and preview instance cannot run simultaneously
    Mutex::Autolock lock(__sRunLock);

    // CPUMask cpuMask(CPUCoreL, 4);
    // AutoCPUAffinity affinity(cpuMask);

    AutoProfileUtil profile(LOG_TAG, "N3DHALRun(Capture)");
    __magicNumber[0] = n3dParams.magicNumber[0];
    __magicNumber[1] = n3dParams.magicNumber[1];
    __requestNumber  = n3dParams.requestNumber;
    __timestamp      = n3dParams.timestamp;
    MY_LOGD_IF(__LOG_ENABLED, "[Magic] %d, %d [Request] %d", __magicNumber[0], __magicNumber[1], __requestNumber);

    __syncInternalNVRAM(__spPreviewKernel, __spCaptureKernel);   //nvram: preview->capture

    if(IS_DUMP_ENALED) {
        __dumpNVRAM(DUMP_INPUT_NVRAM);
        __n3dKernel.setDumpConfig(true, __dumpHint);
    } else {
        __n3dKernel.setDumpConfig(false);
    }

    bool isSuccess = __n3dKernel.WarpMain2(n3dParams,
                                           __getRuntimeAFParams(__pAFTable[0], __magicNumber[0], __afInfoMain1),
                                           __getRuntimeAFParams(__pAFTable[1], __magicNumber[1], __afInfoMain2),
                                           n3dOutput, __algoResult);

    __n3dKernel.WarpMain1(n3dParams.rectifyImgMain1, n3dOutput.rectifyImgMain1, n3dOutput.maskMain1);

    //Denoise will learn in capture
    if( StereoSettingProvider::isDeNoise() )
    {
        __syncInternalNVRAM(__spCaptureKernel, __spPreviewKernel);   //nvram: capture->preview
    }

    if(IS_DUMP_ENALED) {
        __n3dKernel.dumpN3DInitConfig();    //Init may happen in WarpMain2
        __n3dKernel.dumpN3DRuntimeConfig();
        __dumpNVRAM(DUMP_OUTPUT_NVRAM);
    }

    __prepareStereoExtraData();

    return isSuccess;
}

char *
N3D_HAL_IMP::getStereoExtraData()
{
    //Only support capture
    if(eSTEREO_SCENARIO_CAPTURE != __eScenario) {
        return NULL;
    }

    if(NULL == __stereoExtraData) {
        __prepareStereoExtraData();
    }

    return __stereoExtraData;
}
/**************************************************************************
 *       Private Functions                                                *
 **************************************************************************/
bool
N3D_HAL_IMP::__getFEOInputInfo(ENUM_PASS2_ROUND pass2Round,
                              ENUM_STEREO_SCENARIO eScenario,
                              STEREO_KERNEL_IMG_INFO_STRUCT &imgInfo)
{
    imgInfo.depth    = 1;    //pixel depth, YUV:1, RGB: 3, RGBA: 4
    imgInfo.format   = 0;    //YUV:0, RGB: 1

    Pass2SizeInfo pass2Info;
    StereoSizeProvider::getInstance()->getPass2SizeInfo(pass2Round, eScenario, pass2Info);

    imgInfo.width        = pass2Info.areaFEO.size.w;
    imgInfo.height       = pass2Info.areaFEO.size.h;
    imgInfo.stride       = imgInfo.width;
    imgInfo.act_width    = pass2Info.areaFEO.size.w - pass2Info.areaFEO.padding.w;
    imgInfo.act_height   = pass2Info.areaFEO.size.h - pass2Info.areaFEO.padding.h;

    if(pass2Round <= PASS2A_3) {
        imgInfo.offset_x = 0;
        imgInfo.offset_y = 0;
    } else {
        imgInfo.offset_x = (imgInfo.width - imgInfo.act_width)>>1;
        imgInfo.offset_y = (imgInfo.height - imgInfo.act_height)>>1;
    }

    return true;
}

bool
N3D_HAL_IMP::__initN3DGeoInfo(STEREO_KERNEL_GEO_INFO_STRUCT geo_img[])
{
    ::memset(geo_img, 0, MAX_GEO_LEVEL * sizeof(STEREO_KERNEL_GEO_INFO_STRUCT));
//    if(MAX_GEO_LEVEL > 0) {
//        geo_img[0].size = StereoSettingProvider::fefmBlockSize(1);    //16
//        __getFEOInputInfo(PASS2A,        __eScenario,    geo_img[0].img_main);
//        __getFEOInputInfo(PASS2A_P,      __eScenario,    geo_img[0].img_auxi);
//    }

//    if(MAX_GEO_LEVEL > 1) {
        geo_img[0].size = StereoSettingProvider::fefmBlockSize(1);    //16
        __getFEOInputInfo(PASS2A_2,      __eScenario,    geo_img[0].img_main);
        __getFEOInputInfo(PASS2A_P_2,    __eScenario,    geo_img[0].img_auxi);
//    }

//    if(MAX_GEO_LEVEL > 2) {
        geo_img[1].size = StereoSettingProvider::fefmBlockSize(2);    //8
        __getFEOInputInfo(PASS2A_3,      __eScenario,    geo_img[1].img_main);
        __getFEOInputInfo(PASS2A_P_3,    __eScenario,    geo_img[1].img_auxi);
//    }

    return true;
}

bool
N3D_HAL_IMP::__initCCImgInfo(STEREO_KERNEL_IMG_INFO_STRUCT &ccImgInfo)
{
    Pass2SizeInfo pass2Info;
    StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_3, __eScenario, pass2Info);
    MSize szCCImg = pass2Info.areaIMG2O;
    ccImgInfo.width         = szCCImg.w;
    ccImgInfo.height        = szCCImg.h;
    ccImgInfo.depth         = 1;            //pixel depth, YUV:1, RGB: 3, RGBA: 4
    ccImgInfo.stride        = szCCImg.w;
    ccImgInfo.format        = 4;//0;            //YUV:0, RGB: 1

    StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_P_3, __eScenario, pass2Info);
    szCCImg = pass2Info.areaIMG2O;
    ccImgInfo.act_width     = szCCImg.w;
    ccImgInfo.act_height    = szCCImg.h;
    ccImgInfo.offset_x      = 0;
    ccImgInfo.offset_y      = 0;

    return true;
}

void
N3D_HAL_IMP::__initAFWinTransform(ENUM_STEREO_SCENARIO scenario)
{
    MINT32 err = 0;
    int main1SensorIndex, main2SensorIndex;
    StereoSettingProvider::getStereoSensorIndex(main1SensorIndex, main2SensorIndex);

    int main1SensorDevIndex, main2SensorDevIndex;
    StereoSettingProvider::getStereoSensorDevIndex(main1SensorDevIndex, main2SensorDevIndex);

    IHalSensorList* sensorList = MAKE_HalSensorList();
    IHalSensor* pIHalSensor = NULL;

    if(NULL == sensorList) {
        MY_LOGE("Cannot get sensor list");
    } else {
        //========= Get main1 size =========
        IHalSensor* pIHalSensor = sensorList->createSensor(LOG_TAG, main1SensorIndex);
        if(NULL == pIHalSensor) {
            MY_LOGE("Cannot get hal sensor of main1");
            err = 1;
        } else {
            SensorCropWinInfo sensorCropInfo;
            ::memset(&sensorCropInfo, 0, sizeof(SensorCropWinInfo));
            int sensorScenario = StereoSettingProvider::getSensorScenarioMain1();
            err = pIHalSensor->sendCommand(main1SensorDevIndex, SENSOR_CMD_GET_SENSOR_CROP_WIN_INFO,
                                           (MUINTPTR)&sensorScenario, (MUINTPTR)&sensorCropInfo, 0);

            if(err) {
                MY_LOGE("Cannot get sensor crop info for scenario %d", scenario);
            } else {
                //For image refocus
                int m, n;
                imageRatioMToN(StereoSettingProvider::imageRatio(), m, n);
                const float HEIGHT_RATIO = n/(float)m / (3.0f/4.0f);
                __afOffsetX = sensorCropInfo.x2_tg_offset;
                __afOffsetY = sensorCropInfo.y2_tg_offset + sensorCropInfo.w2_tg_size * (1.0f-HEIGHT_RATIO)/2.0f;
                __afScaleW = 2000.0f / sensorCropInfo.w2_tg_size;
                __afScaleH = 2000.0f / sensorCropInfo.h2_tg_size * HEIGHT_RATIO;

                MY_LOGD_IF(__LOG_ENABLED,
                           "AF Transform: scenario: %d, offset(%d, %d), scale(%f, %f)",
                           scenario, __afOffsetX, __afOffsetY, __afScaleW, __afScaleH);
            }

            pIHalSensor->destroyInstance(LOG_TAG);
        }
    }
}

void
N3D_HAL_IMP::__transferAFWin(const AF_WIN_COORDINATE_STRUCT &in, AF_WIN_COORDINATE_STRUCT &out)
{

    if(eSTEREO_SCENARIO_CAPTURE == __eScenario) {
        //For image refocus
        //ROI correction
        int x_correction = 0;
        if(in.af_win_start_x < __afOffsetX) {
            x_correction = __afOffsetX - in.af_win_start_x;
        }

        int y_correction = 0;
        if(in.af_win_start_y < __afOffsetY) {
            y_correction = __afOffsetY - in.af_win_start_y;
        }

        int correction = MAX(x_correction, y_correction);

        //ROI correction should not change the center point
        out.af_win_start_x = (in.af_win_start_x - __afOffsetX + correction) * __afScaleW - 1000.0f;
        out.af_win_start_y = (in.af_win_start_y - __afOffsetY + correction) * __afScaleH - 1000.0f;
        out.af_win_end_x   = (in.af_win_end_x   - __afOffsetX - correction) * __afScaleW - 1000.0f;
        out.af_win_end_y   = (in.af_win_end_y   - __afOffsetY - correction) * __afScaleH - 1000.0f;

        //Check boundary and adjust
        int offset = out.af_win_start_x - (-1000);
        if(offset < 0) {
            out.af_win_start_x = -1000;
            out.af_win_end_x += offset;
        }

        offset = out.af_win_start_y - (-1000);
        if(offset < 0) {
            out.af_win_start_y = -1000;
            out.af_win_end_y += offset;
        }

        offset = out.af_win_end_x - 1000;
        if(offset > 0) {
            out.af_win_end_x = 1000;
            out.af_win_start_x += offset;
        }

        offset = out.af_win_end_y - 1000;
        if(offset > 0) {
            out.af_win_end_y = 1000;
            out.af_win_start_y += offset;
        }
    } else {
        //For Depth AF
        out.af_win_start_x = in.af_win_start_x - __afOffsetX;
        out.af_win_start_y = in.af_win_start_y - __afOffsetY;
        out.af_win_end_x   = in.af_win_end_x   - __afOffsetX;
        out.af_win_end_y   = in.af_win_end_y   - __afOffsetY;

        if(eSTEREO_SCENARIO_RECORD == __eScenario) {
            out.af_win_start_x *= __afScaleW;
            out.af_win_start_y *= __afScaleH;
            out.af_win_end_x   *= __afScaleW;
            out.af_win_end_y   *= __afScaleH;
        }
    }

    // Verify input AF window to protect camera from NE
    if (in.af_win_start_x == 0 && in.af_win_start_y == 0 && in.af_win_end_x == 0 && in.af_win_end_y == 0 ) {
        out.af_win_start_x = 0;
        out.af_win_start_y = 0;
        out.af_win_end_x   = 0;
        out.af_win_end_y   = 0;
        MY_LOGW("Invalid AF ROI, force output window to be (%d %d %d %d)", out.af_win_start_x, out.af_win_start_y, out.af_win_end_x, out.af_win_end_y);
    }

    MY_LOGD_IF(__LOG_ENABLED,
               "AF ROI: %d %d %d %d -> %d %d %d %d",
               in.af_win_start_x, in.af_win_start_y, in.af_win_end_x, in.af_win_end_y,
               out.af_win_start_x, out.af_win_start_y, out.af_win_end_x, out.af_win_end_y);
}

STEREO_KERNEL_AF_INFO_STRUCT *
N3D_HAL_IMP::__getRuntimeAFParams(DAF_TBL_STRUCT *afTable, MUINT32 magicNuimber, STEREO_KERNEL_AF_INFO_STRUCT &result)
{
    if(NULL == afTable) {
        return NULL;
    }

    const int AF_INDEX = magicNuimber % DAF_TBL_QLEN;
    DAF_VEC_STRUCT *afVec = &afTable->daf_vec[AF_INDEX];
    result.dac_i    = (afVec->posture_dac > 0) ? afVec->posture_dac : afVec->af_dac_pos;
    result.dac_v    = afVec->is_af_stable;
    result.dac_c    = afVec->af_confidence;
    result.dac_w[0] = afVec->af_win_start_x;
    result.dac_w[1] = afVec->af_win_start_y;
    result.dac_w[2] = afVec->af_win_end_x;
    result.dac_w[3] = afVec->af_win_end_y;
    afTable->is_daf_run |= E_DAF_RUN_STEREO;  //Backup plan, should be set when init

    return &result;
}

bool
N3D_HAL_IMP::__initLensInfo(const int32_t SENSOR_INDEX, DAF_TBL_STRUCT *&pAFTable, bool &isAF)
{
    const int DEFAULT_DAC = 0;
    isAF = false;

    IHal3A *pHal3A = MAKE_Hal3A(SENSOR_INDEX, LOG_TAG);
    if(NULL == pHal3A) {
        MY_LOGE("Cannot get 3A HAL of sensor %d", SENSOR_INDEX);
        return false;
    } else {
        isAF = StereoSettingProvider::isSensorAF(SENSOR_INDEX);
        if(!isAF) {
            MY_LOGD_IF(__LOG_ENABLED, "[FF] Use default min dac of sensor %d: %d", SENSOR_INDEX, DEFAULT_DAC);
        } else {
            pHal3A->send3ACtrl(NS3Av3::E3ACtrl_GetAFDAFTable, (MUINTPTR)&pAFTable, 0);
            if(NULL == pAFTable) {
                MY_LOGE("[AF] Cannot get AF table of sensor %d", SENSOR_INDEX);
                pHal3A->destroyInstance(LOG_TAG);
                return false;
            }

            if (0 == pAFTable->af_dac_min) {
                MY_LOGD("[AF] Cannot get af_dac_min of sensor %d yet", SENSOR_INDEX);
            } else {
                pAFTable->is_daf_run |= E_DAF_RUN_STEREO;
                MY_LOGD_IF(__LOG_ENABLED, "[AF] Min dac of sensor %d: %d", SENSOR_INDEX, pAFTable->af_dac_min);
            }
        }

        pHal3A->destroyInstance(LOG_TAG);
    }

    return true;
}

bool
N3D_HAL_IMP::__getStereoRemapInfo(STEREO_KERNEL_FLOW_INFO_STRUCT &infoMain1,
                                 STEREO_KERNEL_FLOW_INFO_STRUCT &infoMain2,
                                 ENUM_STEREO_SCENARIO eScenario)
{
    int sensorIndex[2];
    StereoSettingProvider::getStereoSensorIndex(sensorIndex[0], sensorIndex[1]);

    int sensorDevIndex[2];
    StereoSettingProvider::getStereoSensorDevIndex(sensorDevIndex[0], sensorDevIndex[1]);

    STEREO_KERNEL_FLOW_INFO_STRUCT *kernelRemapInfos[2] { &infoMain1, &infoMain2 };
    ENUM_STEREO_SENSOR sensorEnums[2] { eSTEREO_SENSOR_MAIN1, eSTEREO_SENSOR_MAIN2 };

    IHalSensorList* sensorList = MAKE_HalSensorList();
    IHalSensor* pIHalSensor = NULL;
    SensorCropWinInfo rSensorCropInfo;

    if(NULL == sensorList) {
        MY_LOGE("Cannot get sensor list");
    } else {
        MUINT32 junkStride;
        MSize   szMain1RRZO;
        MRect   tgCropRect;
        MINT32  err = 0;
        //========= Get main1 size =========
        for(int sensor = 0 ; sensor < 2; sensor++) {
            IHalSensor* pIHalSensor = sensorList->createSensor(LOG_TAG, sensorIndex[sensor]);
            if(NULL == pIHalSensor) {
                MY_LOGE("Cannot get hal sensor of sensor %d", sensorIndex[sensor]);
                err = 1;
            } else {
                ::memset(&rSensorCropInfo, 0, sizeof(SensorCropWinInfo));
                err = pIHalSensor->sendCommand(sensorDevIndex[sensor], SENSOR_CMD_GET_SENSOR_CROP_WIN_INFO,
                                               (MUINTPTR)&__sensorSenarios[sensor], (MUINTPTR)&rSensorCropInfo, 0);
            }

            if(!err) {
                StereoSizeProvider::getInstance()->getPass1Size( sensorEnums[sensor],
                                                                 eImgFmt_FG_BAYER10,
                                                                 EPortIndex_RRZO,
                                                                 eScenario,
                                                                 //below are outputs
                                                                 tgCropRect,
                                                                 szMain1RRZO,
                                                                 junkStride);

                STEREO_KERNEL_FLOW_INFO_STRUCT *kernelInfo = kernelRemapInfos[sensor];

                kernelInfo->pixel_array_width  = rSensorCropInfo.full_w;
                kernelInfo->pixel_array_height = rSensorCropInfo.full_h ;
                kernelInfo->sensor_offset_x0   = rSensorCropInfo.x0_offset ;
                kernelInfo->sensor_offset_y0   = rSensorCropInfo.y0_offset ;
                kernelInfo->sensor_size_w0     = rSensorCropInfo.w0_size ;
                kernelInfo->sensor_size_h0     = rSensorCropInfo.h0_size ;
                kernelInfo->sensor_scale_w     = rSensorCropInfo.scale_w ;
                kernelInfo->sensor_scale_h     = rSensorCropInfo.scale_h ;
                kernelInfo->sensor_offset_x1   = rSensorCropInfo.x1_offset ;
                kernelInfo->sensor_offset_y1   = rSensorCropInfo.y1_offset ;
                kernelInfo->tg_offset_x        = rSensorCropInfo.x2_tg_offset ;
                kernelInfo->tg_offset_y        = rSensorCropInfo.y2_tg_offset ;
                kernelInfo->sensor_size_w1     = rSensorCropInfo.w1_size ;
                kernelInfo->sensor_size_h1     = rSensorCropInfo.h1_size ;
                kernelInfo->tg_size_w          = rSensorCropInfo.w2_tg_size ;
                kernelInfo->tg_size_h          = rSensorCropInfo.h2_tg_size ;
                kernelInfo->mdp_rotate         = (StereoSettingProvider::getModuleRotation() != 0) ;

                //Pre-crop main1 FOV if difference of FOV is not good enough
                if(0 == sensor)
                {
                    if(eSTEREO_SCENARIO_CAPTURE == eScenario) {
                        Pass2SizeInfo pass2SizeInfo;
                        StereoSizeProvider::getInstance()->getPass2SizeInfo(PASS2A_CROP, eScenario, pass2SizeInfo);
                        StereoArea cropArea = pass2SizeInfo.areaWDMA;
                        kernelInfo->rrz_usage_width  = cropArea.contentSize().w;
                        kernelInfo->rrz_usage_height = cropArea.contentSize().h;

                        kernelInfo->rrz_offset_x = cropArea.startPt.x;
                        kernelInfo->rrz_offset_y = cropArea.startPt.y;
                    } else {
                        kernelInfo->rrz_usage_width  = tgCropRect.s.w;
                        kernelInfo->rrz_usage_height = tgCropRect.s.h;
                        kernelInfo->rrz_offset_x     = tgCropRect.p.x;
                        kernelInfo->rrz_offset_y     = tgCropRect.p.y;
                    }
                } else {    //Only for RRZO
                    kernelInfo->rrz_usage_width  = tgCropRect.s.w;
                    kernelInfo->rrz_usage_height = tgCropRect.s.h;

                    kernelInfo->rrz_offset_x     = tgCropRect.p.x;
                    kernelInfo->rrz_offset_y     = tgCropRect.p.y;
                }

                kernelInfo->rrz_out_width  = szMain1RRZO.w;
                kernelInfo->rrz_out_height = szMain1RRZO.h;
            }

            if(pIHalSensor) {
                pIHalSensor->destroyInstance(LOG_TAG);
            }
        }
    }

    return true;
}

bool
N3D_HAL_IMP::__initAFInfo()
{
    //Get calibration data
    ENUM_STEREO_SENSOR sensor;
    STEREO_KERNEL_AF_INIT_STRUCT *afInitInfo[2] = {&__algoInitInfo.af_init_main, &__algoInitInfo.af_init_auxi};

    int32_t sensorIdx[2];
    StereoSettingProvider::getStereoSensorIndex(sensorIdx[0], sensorIdx[1]);
    int32_t sensorDevIdx[2];
    StereoSettingProvider::getStereoSensorDevIndex(sensorDevIdx[0], sensorDevIdx[1]);

    NVRAM_LENS_PARA_STRUCT *pLensNVRam = NULL;
    NVRAM_LENS_DATA_PARA_STRUCT lensData;
    //Using ZSD by default
    MUINT32 u4AFNVRAMIdx = AFNVRAMMapping[2];   //TODO: query instead of hard coded
    size_t tableSize = 0;

    CamCalDrvBase *pCamCalDrvObj = CamCalDrvBase::createInstance();
    CAM_CAL_DATA_STRUCT camCalData;
    MUINT32 result = 0;
    int dac_str = 0;

    for(int i = 0; i < 2; ++i) {
        if(__isAF[i]) {
            result = pCamCalDrvObj->GetCamCalCalData(sensorDevIdx[i], CAMERA_CAM_CAL_DATA_3A_GAIN, (void *)&camCalData);
            afInitInfo[i]->dac_inf = camCalData.Single2A.S2aAf[0];
            afInitInfo[i]->dac_mcr = camCalData.Single2A.S2aAf[1];
            dac_str = afInitInfo[i]->dac_inf - (afInitInfo[i]->dac_mcr - afInitInfo[i]->dac_inf)*0.2f;
            if(dac_str < 0) {
                dac_str = 0;
            }
            afInitInfo[i]->dac_str = dac_str;

            sensor = (0 == i) ? eSTEREO_SENSOR_MAIN1 : eSTEREO_SENSOR_MAIN2;
            StereoSettingProvider::getCalibrationDistance(sensor, afInitInfo[i]->dist_mcr, afInitInfo[i]->dist_inf);
        } else {
            ::memset(afInitInfo[i], 0, sizeof(STEREO_KERNEL_AF_INIT_STRUCT));
        }
    }

    pCamCalDrvObj->destroyInstance();

    return true;
}

MUINT32
N3D_HAL_IMP::__prepareSystemConfig()
{
    MUINT32 config = 0x450003;   //0 01 00 0 10 10 00 00 00 0 00 0 0 0 0 1 1

    if( __DISABLE_GPU )
    {
        config &= ~(1);  //disable GPU
    }

    if( checkStereoProperty(PROPERTY_ENABLE_CC, 0) == 1 ) {
        config &= ~(1<<3);
    }

    config |= ((StereoSettingProvider::LDCEnabled()||__useExternalCalibration)<<4);

    if(StereoSettingProvider::getSensorRelativePosition()) {
        config |= (1<<6);
    }

    if( eRotate_90  == StereoSettingProvider::getModuleRotation() ||
        eRotate_270 == StereoSettingProvider::getModuleRotation() )
    {
        config  |= (1<<7);
    }

    config |= (__isAF[0] << 9);
    config |= (__isAF[1] << 10);

    if(!StereoSettingProvider::isBayerPlusMono()) {
        // config |= (1 << 12);    //auxi Y only
    }

    if(E_N3D_WARP_WPE == N3D_WARP_HW) {
        config &= ~(1);     //disable GPU
        config &= ~(1<<1);  //disable learning
        config &= ~(1<<9);  //Main FF
        config &= ~(1<<10); //Auxi FF
        config |= (3<<13);  //wpe on
        config |= (3<<15);  //wpe on
        config &= ~(3<<22); //ldc off
    }

    config |= __useExternalCalibration<<31;
    config |= (!__useExternalCalibration)<<30;  //For mtk internal phone

    config = checkStereoProperty(PROPERTY_SYSTEM_CFG, config);

    return config;
}

bool
N3D_HAL_IMP::__saveNVRAM()
{
    if(NULL == __spVoidGeoData) {
        return false;
    }

    if(StereoSettingProvider::isDeNoise()) {
        //For denoise, only save nvram of capture instance
        if(eSTEREO_SCENARIO_CAPTURE != __eScenario) {
            return false;
        }
    } else {
        //For VSDoF, only save nvram of preview instance
        if(eSTEREO_SCENARIO_CAPTURE == __eScenario) {
            return false;
        }
    }

    AutoProfileUtil profile(LOG_TAG, "Save NARAM");

    MBOOL bResult = MTRUE;
    if(__RUN_N3D) {
        __n3dKernel.updateNVRAM(__spVoidGeoData);

        int32_t main1DevIdx, main2DevIdx;
        StereoSettingProvider::getStereoSensorDevIndex(main1DevIdx, main2DevIdx);
        auto pNvBufUtil = MAKE_NvBufUtil();
        MINT32 err = (!pNvBufUtil) ? -1 : pNvBufUtil->write(CAMERA_NVRAM_DATA_GEOMETRY, main1DevIdx);
        if(err) {
            MY_LOGE("Write to NVRAM fail. pNvBufUtil:%p", pNvBufUtil);
            bResult = MFALSE;
        }
    }

    __spVoidGeoData = NULL;

    return bResult;
}

bool
N3D_HAL_IMP::__loadNVRAM()
{
    Mutex::Autolock lock(__sLock);

    AutoProfileUtil profile(LOG_TAG, "Load NVRAM");

    MINT32 err = 0;
    if(NULL == __spVoidGeoData) {
        int32_t main1DevIdx, main2DevIdx;
        StereoSettingProvider::getStereoSensorDevIndex(main1DevIdx, main2DevIdx);
        auto pNvBufUtil = MAKE_NvBufUtil();
        err = (!pNvBufUtil) ? -1 : pNvBufUtil->getBufAndRead(CAMERA_NVRAM_DATA_GEOMETRY, main1DevIdx, (void*&)__spVoidGeoData);
        if(err ||
           NULL == __spVoidGeoData)
        {
            MY_LOGE("Read NVRAM fail, data: %p pNvBufUtil:%p", __spVoidGeoData, pNvBufUtil);
            return false;
        }

        //Reset NVRAM if needed
        if(1 == checkStereoProperty("vendor.STEREO.reset_nvram")) {
            MY_LOGD("Reset NVRAM");
            ::memset(__spVoidGeoData, 0, sizeof(NVRAM_CAMERA_GEOMETRY_STRUCT));
        }

        //Save calibration data into nvram
        MUINT32 calibrationOffset = __n3dKernel.getCalibrationOffsetInNVRAM();
        void *calibrationAddr = &(__spVoidGeoData->StereoNvramData.StereoData[calibrationOffset]);
        struct stat st;
        if(stat(EXTERN_EEPROM_PATH, &st) ||         //extern eeprom file not exist
           st.st_size != CAM_CAL_Stereo_Data_SIZE)  //exterm eeprom file size does not match
        {
            __useExternalCalibration = __loadExternalCalibrationData((float *)calibrationAddr);
            if(!__useExternalCalibration) {
                //1. Get calibration data
                CAM_CAL_DATA_STRUCT calibrationData;
                CamCalDrvBase *pCamCalDrvObj = CamCalDrvBase::createInstance();
                err = pCamCalDrvObj->GetCamCalCalData(main1DevIdx,
                                                      CAMERA_CAM_CAL_DATA_STEREO_DATA,
                                                      (void *)&calibrationData);

                bool isValid = false;
                //2. Save to Stereo Kernel
                if(!err) {
                    //check if calibration is valid
                    for(auto &c : calibrationData.Stereo_Data.Data) {
                        if(c != 0xFF) {
                            isValid = true;
                            break;
                        }
                    }

                    if(isValid) {
                        ::memcpy(calibrationAddr, calibrationData.Stereo_Data.Data, CAM_CAL_Stereo_Data_SIZE);
                    } else {
                        MY_LOGW("Invlid stereo calibration data");
                    }
                } else {
                    MY_LOGW("Fail to read stereo calibration from EEPROM(err %d)", err);
                }
                pCamCalDrvObj->destroyInstance();

                if(!isValid) {
                    size_t size = StereoSettingProvider::getCalibrationData(calibrationAddr);
                    if(size > 0) {
                        MY_LOGD("Use offline stereo calibration data, size %zu", size);
                        isValid = true;
                    }
                }

                if(isValid) {
                    //Check calibration version
                    int calDist = *(((int*)calibrationAddr)+1);
                    if(calDist <= 5000) {
                        __useExternalCalibration = true;
                    }

                    if(checkStereoProperty(PROPERTY_DUMP_CAL)) {
                        FILE *eepromFile = fopen(EXTERN_EEPROM_PATH, "wb+");
                        if(eepromFile) {
                            fwrite(calibrationAddr, 1, CAM_CAL_Stereo_Data_SIZE, eepromFile);
                            fclose(eepromFile);
                            eepromFile = NULL;
                        } else {
                            MY_LOGE("Cannot open %s", EXTERN_EEPROM_PATH);
                        }
                    }
                } else {
                    MY_LOGE("No stereo calibration data");
                }
            }
        } else {
            MY_LOGD("Read extern EEPROM of stereo");
            FILE *eepromFile = fopen(EXTERN_EEPROM_PATH, "r");
            if(eepromFile) {
                char eepromData[CAM_CAL_Stereo_Data_SIZE];
                fread(eepromData, CAM_CAL_Stereo_Data_SIZE, 1, eepromFile);
                ::memcpy(calibrationAddr, eepromData, CAM_CAL_Stereo_Data_SIZE) ;
                fclose(eepromFile);
                eepromFile = NULL;
            } else {
                MY_LOGE("Cannot open %s", EXTERN_EEPROM_PATH);
            }
        }
    }

    return true;
}

bool
N3D_HAL_IMP::__syncInternalNVRAM(N3D_HAL_KERNEL *pSrcStereoKernel, N3D_HAL_KERNEL *pDstStereoKernel)
{
    if(!__RUN_N3D) {
        return true;
    }

    MINT32 err = 0; // 0: no error. other value: error.
    //Step 1: get nvram data from pSrcStereoKernel
    if(pSrcStereoKernel) {
        pSrcStereoKernel->updateNVRAM(__spVoidGeoData);
    } else {
        MY_LOGW("No source stereo drv");
        err = 1;
    }

    //Step 2: save nvram data to pDstStereoKernel
    if(!err) {
        if(pDstStereoKernel) {
            err = !pDstStereoKernel->setNVRAM(__spVoidGeoData);
        } else {
            MY_LOGW("No dst stereo drv");
        }
    }

    return true;
}

const char *
N3D_HAL_IMP::__prepareStereoExtraData()
{
    AutoProfileUtil profile(LOG_TAG, "Thread: Main2 mask-2: Encode extra data");

    if(__stereoExtraData) {
        delete [] __stereoExtraData;
        __stereoExtraData = NULL;
    }

#if (1 == STEREO_DENOISE_SUPPORTED)
    if( StereoSettingProvider::isDeNoise() &&
        DENOISE_MODE == E_DENOISE_MODE_NORMAL &&
        checkStereoProperty(PROPERTY_ENABLE_VERIFY) <= 0)
    {
        __stereoExtraData = new char[3];
        ::strcpy(__stereoExtraData, "{}");
        return __stereoExtraData;
    }
#endif

    Document document(kObjectType);
    Document::AllocatorType& allocator = document.GetAllocator();

//    "JPS_size": {
//        "width": 4352,
//        "height": 1152
//    },
    Value JPS_size(kObjectType);
    JPS_size.AddMember(EXTRA_DATA_WIDTH, 0, allocator);
    JPS_size.AddMember(EXTRA_DATA_HEIGHT, 0, allocator);
    document.AddMember(EXTRA_DATA_JPS_SIZE, JPS_size, allocator);

//    "output_image_size" : {
//        "width": 2176,
//        "height": 1152
//    },
    Value output_image_size(kObjectType);
    output_image_size.AddMember(EXTRA_DATA_WIDTH, 0, allocator);
    output_image_size.AddMember(EXTRA_DATA_HEIGHT, 0, allocator);
    document.AddMember(EXTRA_DATA_OUTPUT_IMAGE_SIZE, output_image_size, allocator);

//    "main_cam_align_shift" : {
//        "x": 30,
//        "y": 10
//    },
    Value main_cam_align_shift(kObjectType);
    main_cam_align_shift.AddMember(EXTRA_DATA_X, ((MFLOAT *)__algoResult.out_p[STEREO_KERNEL_OUTPUT_DEPTH])[0], allocator);
    main_cam_align_shift.AddMember(EXTRA_DATA_Y, ((MFLOAT *)__algoResult.out_p[STEREO_KERNEL_OUTPUT_DEPTH])[1], allocator);
    document.AddMember(EXTRA_DATA_MAIN_CAM_ALIGN_SHIFT, main_cam_align_shift, allocator);

//    "capture_orientation": {
//        "orientations_values": ["0: none", "1: flip_horizontal", "2: flip_vertical", "4: 90", "3: 180", "7: 270"],
//        "orientation": 0
//    },
    int cap_ori = 0;
    switch(__captureOrientation){
        case 90:
            cap_ori = 4;
            break;
        case 180:
            cap_ori = 3;
            break;
        case 270:
            cap_ori = 7;
            break;
        case 0:
        default:
            cap_ori = 0;
            break;
    }

    Value capture_orientation(kObjectType);
    Value orientations_values(kArrayType);
    orientations_values.PushBack(Value("0: none").Move(), allocator);
    // orientations_values.PushBack(Value("1: flip_horizontal").Move(), allocator);
    // orientations_values.PushBack(Value("2: flip_vertical").Move(), allocator);
    orientations_values.PushBack(Value("4: 90 degrees CW").Move(), allocator);
    orientations_values.PushBack(Value("3: 180 degrees CW").Move(), allocator);
    orientations_values.PushBack(Value("7: 270 degrees CW").Move(), allocator);
    capture_orientation.AddMember(EXTRA_DATA_ORIENTATIONS_VALUES, orientations_values, allocator);
    capture_orientation.AddMember(EXTRA_DATA_ORIENTATION, Value(cap_ori).Move(), allocator);
    document.AddMember(EXTRA_DATA_CAPTURE_ORIENTATION, capture_orientation, allocator);

//    "depthmap_orientation": {
//        "depthmap_orientation_values": ["0: none", "90: 90 degrees CW", "180: 180 degrees CW", "270: 270 degrees CW"],
//        "orientation": 0
//    },
    Value depthmap_orientation(kObjectType);
    Value depthmap_orientation_values(kArrayType);
    depthmap_orientation_values.PushBack(Value("0: none").Move(), allocator);
    depthmap_orientation_values.PushBack(Value("90: 90 degrees CW").Move(), allocator);
    depthmap_orientation_values.PushBack(Value("180: 180 degrees CW").Move(), allocator);
    depthmap_orientation_values.PushBack(Value("270: 270 degrees CW").Move(), allocator);
    depthmap_orientation.AddMember(EXTRA_DATA_DEPTHMAP_ORIENTATION_VALUES, depthmap_orientation_values, allocator);
    // int depthOrientationValue = __captureOrientation-StereoSettingProvider::getModuleRotation();
    // if(depthOrientationValue < 0) {
    //     depthOrientationValue += 360;
    // }
    depthmap_orientation.AddMember(EXTRA_DATA_ORIENTATION, 0, allocator);
    document.AddMember(EXTRA_DATA_DEPTHMAP_ORIENTATION, depthmap_orientation, allocator);

//    "depth_buffer_size": {
//        "width": 480,
//        "height": 270
//    },
    Value depth_buffer_size(kObjectType);
    MSize szDepthMap = StereoSizeProvider::getInstance()->getBufferSize(E_DEPTH_MAP, __eScenario);
    if( 90 == __captureOrientation ||
       270 == __captureOrientation)
    {
        szDepthMap = MSize(szDepthMap.h, szDepthMap.w);
    }
    depth_buffer_size.AddMember(EXTRA_DATA_WIDTH, szDepthMap.w, allocator);
    depth_buffer_size.AddMember(EXTRA_DATA_HEIGHT, szDepthMap.h, allocator);
    document.AddMember(EXTRA_DATA_DEPTH_BUFFER_SIZE, depth_buffer_size, allocator);

//    "input_image_size": {
//        "width": 1920,
//        "height": 1088
//    },
    MSize viewSize = szDepthMap * 4;
    Value input_image_size(kObjectType);
    input_image_size.AddMember(EXTRA_DATA_WIDTH, viewSize.w, allocator);
    input_image_size.AddMember(EXTRA_DATA_HEIGHT, viewSize.h, allocator);
    document.AddMember(EXTRA_DATA_INPUT_IMAGE_SIZE, input_image_size, allocator);

//    "sensor_relative_position": {
//        "relative_position_values": ["0: main-minor", "1: minor-main"],
//        "relative_position": 0
//    },
    Value sensor_relative_position(kObjectType);
    Value relative_position_values(kArrayType);
    relative_position_values.PushBack(Value("0: main-minor").Move(), allocator);
    relative_position_values.PushBack(Value("1: minor-main").Move(), allocator);
    sensor_relative_position.AddMember(EXTRA_DATA_RELATIVE_POSITION_VALUES, relative_position_values, allocator);
    sensor_relative_position.AddMember(EXTRA_DATA_RELATIVE_POSITION, Value((int)StereoSettingProvider::getSensorRelativePosition()).Move(), allocator);
    document.AddMember(EXTRA_DATA_SENSOR_RELATIVE_POSITION, sensor_relative_position, allocator);

//    "focus_roi": {
//        "top": 0,
//        "left": 10,
//        "bottom": 10,
//        "right": 30
//    },
    const int AF_INDEX = __magicNumber[0] % DAF_TBL_QLEN;
    AF_WIN_COORDINATE_STRUCT apAFWin(0, 0, 0, 0);
    if(__isAF[0] &&
       NULL != __pAFTable[0])
    {
        DAF_VEC_STRUCT *afVec = &__pAFTable[0]->daf_vec[AF_INDEX];
        AF_WIN_COORDINATE_STRUCT afWin(afVec->af_win_start_x, afVec->af_win_start_y,
                                       afVec->af_win_end_x, afVec->af_win_end_y);
        __transferAFWin(afWin, apAFWin);
    } else {   //FF
        if(StereoFDProxy::isFocusedOnFace()) {
            MtkCameraFace face = StereoFDProxy::getFocusedFace();
            apAFWin.af_win_start_x = face.rect[2];
            apAFWin.af_win_start_y = face.rect[1];
            apAFWin.af_win_end_x   = face.rect[0];
            apAFWin.af_win_end_y   = face.rect[3];
        } else {
            apAFWin.af_win_start_x = __touchPt.x;
            apAFWin.af_win_start_y = __touchPt.y;
            apAFWin.af_win_end_x   = __touchPt.x;
            apAFWin.af_win_end_y   = __touchPt.y;
        }
    }

    if(0 != __captureOrientation) {
        MPoint ptTopLeft = MPoint(apAFWin.af_win_start_x, apAFWin.af_win_start_y);
        MPoint ptBottomRight = MPoint(apAFWin.af_win_end_x, apAFWin.af_win_end_y);

        MY_LOGD_IF(__LOG_ENABLED, "AF ROI Before Rotate (%d, %d) (%d, %d)",
                   ptTopLeft.x, ptTopLeft.y, ptBottomRight.x, ptBottomRight.y);

        const MSize ROI_DOMAIN(2000, 2000);     //-1000~1000
        const MPoint ORIGIN_OFFSET(1000, 1000);
        MRect roi = StereoHAL::rotateRect( MRect( ptTopLeft+ORIGIN_OFFSET, ptBottomRight+ORIGIN_OFFSET ),
                                           ROI_DOMAIN,
                                           static_cast<ENUM_ROTATION>(__captureOrientation) );
        ptTopLeft = roi.leftTop() - ORIGIN_OFFSET;
        ptBottomRight = roi.rightBottom() - ORIGIN_OFFSET;

        MY_LOGD_IF(__LOG_ENABLED, "AF ROI After Rotate (%d, %d) (%d, %d), rotate %d",
                   ptTopLeft.x, ptTopLeft.y, ptBottomRight.x, ptBottomRight.y,
                   __captureOrientation);

        apAFWin.af_win_start_x = ptTopLeft.x;
        apAFWin.af_win_start_y = ptTopLeft.y;
        apAFWin.af_win_end_x   = ptBottomRight.x;
        apAFWin.af_win_end_y   = ptBottomRight.y;
    }

    Value focus_roi(kObjectType);
    focus_roi.AddMember(EXTRA_DATA_TOP,      Value( apAFWin.af_win_start_y ).Move(), allocator);
    focus_roi.AddMember(EXTRA_DATA_LEFT,     Value( apAFWin.af_win_start_x ).Move(), allocator);
    focus_roi.AddMember(EXTRA_DATA_BOTTOM,   Value( apAFWin.af_win_end_y   ).Move(), allocator);
    focus_roi.AddMember(EXTRA_DATA_RIGHT,    Value( apAFWin.af_win_end_x   ).Move(), allocator);
    document.AddMember(EXTRA_DATA_FOCUS_ROI, focus_roi, allocator);

//    "focus_info": {
//        "is_face": 0,
//        "face_ratio": 0.07,
//        "dac_cur": 200,
//        "dac_min": 100,
//        "dac_max": 300,
//        "focus_type": 3
//    }
    Value focus_info(kObjectType);
    if(__isAF[0] &&
       NULL != __pAFTable[0])
    {
        DAF_VEC_STRUCT *afVec = &__pAFTable[0]->daf_vec[AF_INDEX];
        focus_info.AddMember(EXTRA_DATA_IS_FACE, Value( AF_ROI_SEL_FD == afVec->af_roi_sel ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_FACE_RATIO, Value( (apAFWin.af_win_end_x-apAFWin.af_win_start_x+1)/2000.0f ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_DAC_CUR, Value( (afVec->posture_dac > 0) ? afVec->posture_dac : afVec->af_dac_pos ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_DAC_MIN, Value( __pAFTable[0]->af_dac_min ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_DAC_MAX, Value( __pAFTable[0]->af_dac_max ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_FOCUS_TYPE, Value( afVec->af_roi_sel ).Move(), allocator);
    } else {    //FF
        if(StereoFDProxy::isFocusedOnFace()) {
            focus_info.AddMember(EXTRA_DATA_IS_FACE, Value( 1 ).Move(), allocator);
            MRect rect = StereoFDProxy::getFocusedFaceRect();
            focus_info.AddMember(EXTRA_DATA_FACE_RATIO, Value( rect.s.w/2000.0f ).Move(), allocator);
            focus_info.AddMember(EXTRA_DATA_FOCUS_TYPE, Value( AF_ROI_SEL_FD ).Move(), allocator);
        } else {
            focus_info.AddMember(EXTRA_DATA_FOCUS_TYPE, Value( AF_ROI_SEL_AP ).Move(), allocator);
        }
        focus_info.AddMember(EXTRA_DATA_DAC_CUR, Value( 0 ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_DAC_MIN, Value( 0 ).Move(), allocator);
        focus_info.AddMember(EXTRA_DATA_DAC_MAX, Value( 0 ).Move(), allocator);
    }
    document.AddMember(EXTRA_DATA_FOCUS_INFO, focus_info, allocator);

//    "GFocus": {
//        "BlurAtInfinity": 0.014506519,
//        "FocalDistance": 25.612852,
//        "FocalPointX": 0.5,
//        "FocalPointY": 0.5
//    },
    Value GFocus(kObjectType);
    GFocus.AddMember(EXTRA_DATA_BLURATINFINITY, 0.014506519, allocator);
    GFocus.AddMember(EXTRA_DATA_FOCALDISTANCE, 25.612852, allocator);
    GFocus.AddMember(EXTRA_DATA_FOCALPOINTX, 0.5, allocator);
    GFocus.AddMember(EXTRA_DATA_FOCALPOINTY, 0.5, allocator);
    document.AddMember(EXTRA_DATA_GFOCUS, GFocus, allocator);

//    "GImage" : {
//        "Mime": "image/jpeg"
//    },
    Value GImage(kObjectType);
    GImage.AddMember(EXTRA_DATA_MIME, "image/jpeg", allocator);
    document.AddMember(EXTRA_DATA_GIMAGE, GImage, allocator);

//    "GDepth": {
//        "Format": "RangeInverse",
//        "Near": 15.12828254699707,
//        "Far": 97.0217514038086,
//        "Mime": "image/png"
//    },
    Value GDepth(kObjectType);
    GDepth.AddMember(EXTRA_DATA_FORMAT, "RangeInverse", allocator);
    GDepth.AddMember(EXTRA_DATA_NEAR, 15.12828254699707, allocator);
    GDepth.AddMember(EXTRA_DATA_FAR, 97.0217514038086, allocator);
    GDepth.AddMember(EXTRA_DATA_MIME, "image/png", allocator);
    document.AddMember(EXTRA_DATA_GDEPTH, GDepth, allocator);

    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    document.Accept(writer);    // Accept() traverses the DOM and generates Handler events.

    const char *stereoExtraData = sb.GetString();
    if(stereoExtraData) {
        const int STR_LEN = strlen(stereoExtraData);
        if(STR_LEN > 0) {
            __stereoExtraData = new char[STR_LEN+1];
            strcpy(__stereoExtraData, stereoExtraData);
        }
    }

    if(checkStereoProperty(PROPERTY_DUMP_JSON) == 1) {
        char fileName[PATH_MAX+1];
        const char *folder = StereoSettingProvider::getDumpFolder(eSTEREO_SCENARIO_CAPTURE == __eScenario, __timestamp, __requestNumber).c_str();
        sprintf(fileName, "%s/N3D_ExtraData.json", folder);
        FILE *fp = fopen(fileName, "wb");
        if(fp) {
            char writeBuffer[65536];
            FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
            PrettyWriter<FileWriteStream> prettyWriter(os);
            document.Accept(prettyWriter);

            fflush(fp);
            fclose(fp);
        }
    }

    return __stereoExtraData;
}