/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#define LOG_TAG "ae_mgr"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif
#include <sys/stat.h>
#include <utils/threads.h>
#include <cutils/properties.h>
#include <mtkcam/def/common.h>
#include <aaa_types.h>
#include <aaa_error_code.h>
#include <mtkcam/utils/std/Log.h>
#include <mtkcam/utils/std/Trace.h>
#include <private/aaa_hal_private.h>
//#include <aaa_hal.h>
#include <camera_custom_nvram.h>
#include <awb_param.h>
#include <af_param.h>
#include <flash_param.h>
#include <ae_param.h>
//#include <CamDefs.h>
#include <faces.h>
#include <isp_tuning.h>
#include <isp_mgr.h>
#include <isp_tuning_mgr.h>
#include <ae_algo_if.h>
#include <aaa_trace.h>
//
#include <nvram_drv_mgr.h>
#include <ae_tuning_custom.h>
#include <aaa_sensor_mgr.h>
#include "camera_custom_hdr.h"
#include "camera_custom_ivhdr.h"
#include "camera_custom_mvhdr.h"
#include "camera_custom_zvhdr.h"
#include <kd_camera_feature.h>
#include <mtkcam/drv/IHalSensor.h>
#include "ae_mgr_if.h"
#include "ae_mgr.h"
#include <aaa_scheduler.h>
#include <aaa_common_custom.h>
#include "aaa_sensor_buf_mgr.h"
#include <time.h>
#include <android/sensor.h>                     // for g/gyro sensor listener
#include <mtkcam/utils/sys/SensorListener.h>    // for g/gyro sensor listener
#include <mtkcam/utils/std/TypeTraits.h>
#include <mtkcam/feature/hdrDetection/Defs.h>

static unsigned long long AEtimer;

#define ISP_GAIN_DELAY_OFFSET 2
#define EMLongestExp 500000
#define RealInitThrs 600000000 // 0.6s
// define log control
#define EN_3A_FLOW_LOG        1
#define EN_3A_SCHEDULE_LOG    2
// define AAO Separation size (test)
#define AAO_STT_BLOCK_NUMX 120
#define AAO_STT_BLOCK_NUMY 90
#define AAO_STT_HIST_BIN_NUM 128
#define AAO_SEP_AWB_SIZE (4*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
#define AAO_SEP_AE_SIZE (2*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
#define AAO_SEP_HIST_SIZE (4*4*AAO_STT_HIST_BIN_NUM)
#define AAO_SEP_OVEREXPCNT_SIZE (2*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
// define TG information
#define TG_INT_AE_RATIO 0.6
// define g/gyro info
#define SENSOR_ACCE_POLLING_MS  20
#define SENSOR_GYRO_POLLING_MS  20
#define SENSOR_ACCE_SCALE 100
#define SENSOR_GYRO_SCALE 100


#ifndef ABS
    #define ABS(x)                                                                  (((x) > 0) ? (x) : (-1*(x)))
#endif


using namespace NS3A;
using namespace NS3Av3;
using namespace NSIspTuning;
using namespace NSIspTuningv3;
using namespace NSCam;


#define AE_LOG(fmt, arg...) \
    do { \
        if (m_i4DgbLogE) { \
            CAM_LOGE(fmt, ##arg); \
        } else { \
            CAM_LOGD(fmt, ##arg); \
        } \
    }while(0)

#define AE_LOG_IF(cond, ...) \
    do { \
        if (m_i4DgbLogE) { \
            CAM_LOGE_IF(cond, __VA_ARGS__); \
        } else { \
            CAM_LOGD_IF(cond, __VA_ARGS__); \
        } \
    }while(0)


AeMgr* AeMgr::s_pAeMgr = MNULL;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <ESensorDev_T const eSensorDev>
class AeMgrDev : public AeMgr
{
public:
    static    AeMgr&    getInstance() {
        static AeMgrDev<eSensorDev> singleton;
        AeMgr::s_pAeMgr = &singleton;
        return singleton;
    }

    AeMgrDev() : AeMgr(eSensorDev) {}
    virtual ~AeMgrDev() {}
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// g/gyro sensor listener handler and data
#if 0
static MINT32  gAcceInfo[3];
static MUINT64 gAcceTS;
static MBOOL   gAcceValid = MFALSE;
static MUINT64 gPreAcceTS;

static MINT32  gGyroInfo[3];
static MUINT64 gGyroTS;
static MBOOL   gGyroValid = MFALSE;
static MUINT64 gPreGyroTS;

static SensorListener* gpSensorListener=NULL;
static Mutex gCommonLock;

void aeListenHandler( ASensorEvent event)
{
    switch( event.type)
    {
    case ASENSOR_TYPE_ACCELEROMETER:
    {
        gPreAcceTS = gAcceTS;
        gAcceInfo[0] = event.acceleration.x * SENSOR_ACCE_SCALE;
        gAcceInfo[1] = event.acceleration.y * SENSOR_ACCE_SCALE;
        gAcceInfo[2] = event.acceleration.z * SENSOR_ACCE_SCALE;
        gAcceTS = event.timestamp;
        /*CAM_LOGD("SensorEventAF Acc(%f,%f,%f,%lld)",
            event.acceleration.x,
            event.acceleration.y,
            event.acceleration.z,
            event.timestamp);*/
        break;
    }
    case ASENSOR_TYPE_GYROSCOPE:
    {
        gPreGyroTS = gGyroTS;
        gGyroInfo[0] = event.vector.x * SENSOR_GYRO_SCALE;
        gGyroInfo[1] = event.vector.y * SENSOR_GYRO_SCALE;
        gGyroInfo[2] = event.vector.z * SENSOR_GYRO_SCALE;
        gGyroTS = event.timestamp;
        /*CAM_LOGD("SensorEventAF Gyro(%f,%f,%f,%lld)",
            event.vector.x,
            event.vector.y,
            event.vector.z,
            event.timestamp);*/
        break;
    }
    case ASENSOR_TYPE_MAGNETIC_FIELD:
    case ASENSOR_TYPE_LIGHT:
    case ASENSOR_TYPE_PROXIMITY:
    default:
    {
        CAM_LOGD( "unknown type(%d)", event.type);
        break;
    }
    }
}
#endif
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AeMgr &AeMgr::getInstance(MINT32 const i4SensorDev)
{
    switch (i4SensorDev) {
        case ESensorDev_Main: //  Main Sensor
            return  AeMgrDev<ESensorDev_Main>::getInstance();
        case ESensorDev_MainSecond: //  Main Second Sensor
            return  AeMgrDev<ESensorDev_MainSecond>::getInstance();
        case ESensorDev_Sub: //  Sub Sensor
            return  AeMgrDev<ESensorDev_Sub>::getInstance();
        case ESensorDev_SubSecond: //  Sub Sensor
            return  AeMgrDev<ESensorDev_SubSecond>::getInstance();
        default:
            CAM_LOGD("i4SensorDev = %d", i4SensorDev);
            if (AeMgr::s_pAeMgr) {
                return  *AeMgr::s_pAeMgr;
            } else {
                return  AeMgrDev<ESensorDev_Main>::getInstance();
            }
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AeMgr::
AeMgr(ESensorDev_T eSensorDev)
    : m_eSensorDev(eSensorDev)
    , m_pIAeAlgo(NULL)
    , m_eSensorTG(ESensorTG_1)
    , m_eSensorMode(ESensorMode_Preview)
    , m_eISPProfile(EIspProfile_Preview)
    , m_eAENVRAMIdx(AE_NVRAM_IDX_NORMAL)
    , m_i4SensorIdx(0)
    , m_BVvalue(0)
    , m_i4DeltaBV(0)
    , m_AOECompBVvalue(0)
    , m_BVvalueWOStrobe(0)
    , m_i4EVvalue(0)
    , m_i4WaitVDNum(0)
    , m_i4RotateDegree(0)
    , m_i4TimeOutCnt(0)
    , m_i4ShutterDelayFrames(2)
    , m_i4SensorGainDelayFrames(2)
    , m_i4SensorGainDelayFramesWOShutter(1)
    , m_i4IspGainDelayFrames(0)
    , m_i4SensorCaptureDelayFrame(0)
    , m_i4TotalCaptureDelayFrame(3)
    , m_i4AEidxCurrent(0)
    , m_i4AEidxNext(0)
    , m_i2AEFaceDiffIndex(0)
    , m_u4PreExposureTime(0)
    , m_u4PreSensorGain(0)
    , m_u4PreIspGain(0)
    , m_u4SmoothIspGain(0)
    , m_u4AECondition(0)
    , m_u4DynamicFrameCnt(0)
    , m_u4AFSGG1Gain(16)
    , m_bOneShotAEBeforeLock(MFALSE)
    , m_bAESceneChanged(MFALSE)
    , m_bAELock(MFALSE)
    , m_bAPAELock(MFALSE)
    , m_bAFAELock(MFALSE)
    , m_bEnableAE(MFALSE)
    , m_bVideoDynamic(MTRUE)
    , m_bRealISOSpeed(MFALSE)
    , m_bAElimitor(MFALSE)
    , m_bAEStable(MFALSE)
    , m_bAEMonitorStable(MFALSE)
    , m_bAEReadyCapture(MFALSE)
    , m_bLockExposureSetting(MFALSE)
    , m_bStrobeOn(MFALSE)
    , m_bAEMgrDebugEnable(MFALSE)
    , m_bRestoreAE(MFALSE)
    , m_bAECaptureUpdate(MFALSE)
    , m_bOtherIPRestoreAE(MFALSE)
    , m_eAEScene(LIB3A_AE_SCENE_AUTO)
    , m_eAEMode(LIB3A_AE_MODE_ON)
    , m_ePreAEState(MTK_CONTROL_AE_STATE_INACTIVE)
    , m_eAEState(MTK_CONTROL_AE_STATE_INACTIVE)
    , m_fEVCompStep(1)
    , m_i4EVIndex(0)
    , m_eAEMeterMode(LIB3A_AE_METERING_MODE_CENTER_WEIGHT)
    , m_u4AEISOSpeed(0)
    , m_eAEFlickerMode(LIB3A_AE_FLICKER_MODE_50HZ)
    , m_i4AEMaxFps(LIB3A_AE_FRAMERATE_MODE_30FPS)
    , m_i4AEMinFps(LIB3A_AE_FRAMERATE_MODE_05FPS)
    , m_eAEAutoFlickerMode(LIB3A_AE_FLICKER_AUTO_MODE_50HZ)
    , m_i4AEAutoFlickerMode(0)
    , m_eCamMode(eAppMode_PhotoMode)
    , m_eAECamMode(LIB3A_AECAM_MODE_PHOTO)
    , m_eShotMode(eShotMode_NormalShot)
    , m_eAEEVcomp(LIB3A_AE_EV_COMP_00)
    , m_AEState(AE_INIT_STATE)
    , m_bIsAutoFlare(MTRUE)
    , m_bFrameUpdate(MFALSE)
    , m_bAdbAEEnable(MFALSE)
    , m_bAdbAELock(MFALSE)
    , m_bAdbAELog(MFALSE)
    , m_bAdbAEPreviewUpdate(MFALSE)
    , m_bAdbAEDisableSmooth(MFALSE)
    , m_i4AdbAEISPDisable(0)
    , m_u4AdbAEShutterTime(0)
    , m_u4AdbAESensorGain(0)
    , m_u4AdbAEISPGain(0)
    , m_u4AdbAAOdump(0)
    , m_u4AdbAEPerFrameCtrl(0)
    , m_u4IndexTestCnt(0)
    , m_i4ObjectTrackNum(0)
    , m_pIsAEActive(MNULL)
    , m_i4AECycleNum(0)
    , m_i4GammaIdx(0)
    , m_i4LESE_Ratio(1)
    , m_i4HdrSeg(3072)
    , m_i4HdrTurn(768)
    , m_i4HdrOnOff(toLiteral(HDRDetectionResult::NONE))
    , m_u4SWHDR_SE(0)
    , m_u4MaxShutter(100000)
    , m_u4MaxISO(800)
    , m_u4StableCnt(0)
    , m_pAEPlineTable(NULL)
    , m_pAEMapPlineTable(NULL)
    , m_p3ANVRAM(NULL)
    , m_eAETargetMode(AE_MODE_NORMAL)
    , m_u4PrevExposureTime(0)
    , m_u4PrevSensorGain(0)
    , m_u4PrevIspGain(0)
    , m_ePrevAECamMode(LIB3A_AECAM_MODE_PHOTO)
    , m_3ALogEnable(0)
    , m_i4DgbLogE(0)
    , m_bAEOneShotControl(MFALSE)
    , bUpdateSensorAWBGain(MFALSE)
    , bApplyAEPlineTableByCCT(MFALSE)
    , m_bSetShutterValue(MFALSE)
    , m_bSetGainValue(MFALSE)
    , m_bSetFrameRateValue(MFALSE)
    , m_u4UpdateShutterValue(0)
    , m_u4UpdateGainValue(0)
    , m_u4UpdateFrameRate_x10(LIB3A_AE_FRAMERATE_MODE_30FPS)
    , m_bTouchAEAreaChage(MFALSE)
    , m_bMultiCap(MFALSE)
    , m_bCShot(MFALSE)
    , m_bzcHDRshot(MFALSE)
    , m_bHDRshot(MFALSE)
    , m_bResetZHDRMode(MFALSE)
    , m_u4VsyncCnt(0)
    , m_bLockBlackLevel(MFALSE)
    , m_u4WOFDCnt (0)
    , m_bFDenable(MFALSE)
    , m_bFaceAEAreaChage(MFALSE)
    , m_u4AEScheduleCnt(0)
    , m_u4StableYValue(0)
    , m_pSensorGainThread(NULL)
    , m_bSGainThdFlg(MFALSE)
    , m_Lock()
    , m_u4AEExitStableCnt(0)
    , m_u4LEHDRshutter(0)
    , m_u4SEHDRshutter(0)
    , m_uEvQueueSize(MAX_AE_PRE_EVSETTING)
    , m_u4PreviousSensorgain(0)
    , m_u4PreviousISPgain(0)
    , m_bPerframeAEFlag(0)
    , m_bTgIntAEEn(MFALSE)
    , m_i4AETgValidBlockWidth(0)
    , m_i4AETgValidBlockHeight(0)
    , m_pPreviewTableCurrent(NULL)
    , m_pPreviewTableNew(NULL)
    , m_pCaptureTable(NULL)
    , m_pStrobeTable(NULL)
    , m_u4IndexMax(0)
    , m_u4IndexMin(0)
    , m_u4Index(0)
    , m_u4LCEGainStartIdx(0)
    , m_u4LCEGainEndIdx(0)
    , m_i4PreviewMaxBV(0)
    , m_i4VideoMaxBV(0)
    , m_i4Video1MaxBV(0)
    , m_i4Video2MaxBV(0)
    , m_i4ZSDMaxBV(0)
    , m_i4DeltaBVIdx(0)
    , m_i4DeltaSensitivityIdx(0)
    , m_bManualAEtable(0)
    , m_u4ManualAEtablePreviewidx(0)
    , m_u4ManualAEtableCaptureidx(0)
    , m_bStereoManualPline(MFALSE)
    , m_bEISAEPline(MFALSE)
    , m_u4EISExpRatio(100)
    , m_u4Hbinwidth(0)
    , m_u4Hbinheight(0)
    , m_pAAOTgSeparatedBuf(NULL)
    , m_bEnableHDRYConfig(1)
    , m_bEnableOverCntConfig(1)
    , m_bEnableTSFConfig(1)
    , m_bDisablePixelHistConfig(0)
    , m_u4AEOverExpCntThs(255)
    , m_u4AEOverExpCntShift(0)
    , m_u4BlockNumX(AAO_STT_BLOCK_NUMX)
    , m_u4BlockNumY(AAO_STT_BLOCK_NUMY)
    , m_u4AAOSepAWBsize(4*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
    , m_u4AAOSepAEsize(2*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
    , m_u4AAOSepHistsize(4*4*AAO_STT_HIST_BIN_NUM)
    , m_u4AAOSepOverCntsize(2*AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY)
    , m_u4AEYCoefR(5)
    , m_u4AEYCoefG(9)
    , m_u4AEYCoefB(2)
    , m_u4HwMagicNum(0)
    , m_u4VHDRratio(0)
    , m_bEnSWBuffMode(MFALSE)
    , m_i4SMSubSamples(1)
    , m_u4HFSMSkipFrame(0)
    , m_u4HDRcountforrevert(0)
    , m_bVHDRChangeFlag(MFALSE)
    , m_bIsFlareInManual(MFALSE)
    , m_bEnAutoTest(MFALSE)
    , m_u4ATCnt(0)
    , m_u4ATYval(0)
    , m_u4ATType(AE_AT_TYPE_NON)
{
    mEngFileName = new char[200];
    mEngFileName[0]=0;

    memset(&m_AeMgrCCTConfig, 0, sizeof(AE_CCT_CFG_T));
    memset(&m_eZoomWinInfo, 0, sizeof(EZOOM_WINDOW_T));
    memset(&m_eAEMeterArea, 0, sizeof(AEMeteringArea_T));
    memset(&m_eAEFDArea, 0, sizeof(AEMeteringArea_T));
    memset(&m_CurrentPreviewTable, 0, sizeof(strAETable));
    memset(&m_CurrentCaptureTable, 0, sizeof(strAETable));
    memset(&m_CurrentStrobetureTable, 0, sizeof(strAETable));
    memset(&mPreviewMode, 0, sizeof(AE_MODE_CFG_T));
    memset(&mPreviewModeBackup, 0, sizeof(AE_MODE_CFG_T));
    memset(&mCaptureMode, 0, sizeof(AE_MODE_CFG_T));
    memset(&m_strHDROutputInfo, 0, sizeof(Hal3A_HDROutputParam_T));
    memset(&m_strIVHDROutputSetting, 0, sizeof(IVHDRExpSettingOutputParam_T));
    memset(&m_backupMeterArea, 0, sizeof(CameraMeteringArea_T));
    memset(&m_rAEInitInput, 0, sizeof(AE_INITIAL_INPUT_T));
    memset(&m_rAEOutput, 0, sizeof(AE_OUTPUT_T));
    memset(&m_rAEStatCfg, 0, sizeof(AE_STAT_PARAM_T));
    memset(&m_rSensorResolution[0], 0, 2*sizeof(SENSOR_RES_INFO_T));
    memset(&m_rAEPLineLimitation, 0, sizeof(AE_PLINE_LIMITATION_T));
    memset(&m_rSensorVCInfo, 0, sizeof(SENSOR_VC_INFO_T));
    memset(&m_SensorQueueCtrl, 0, sizeof(AE_SENSOR_QUEUE_CTRL_T));
    memset(&m_rSensorCurrentInfo, 0, sizeof(AE_SENSOR_PARAM_T));
    memset(&m_strAECycleInfo,0, sizeof(strAECycleInfo));
    memset(&m_PreEvSettingQueue[0], 0, MAX_AE_PRE_EVSETTING*sizeof(strEvSetting));
    memset(&m_BackupEvSetting, 0, sizeof(strEvSetting));
    memset(&m_u4PreAEidxQueue[0], 0, MAX_AE_PRE_EVSETTING*sizeof(MUINT32));
    memset(&m_u4PreTgIntAEidxQueue[0], 0, MAX_AE_PRE_EVSETTING*sizeof(MUINT32));

    m_backupMeterArea.u4Count = 1;
    m_isAeMeterAreaEn=1;
    m_rAEPLineLimitation.u4IncreaseISO_x100 = 100;
    m_rAEPLineLimitation.u4IncreaseShutter_x100 = 100;
    AE_LOG( "[AeMgr]\n");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AeMgr::
~AeMgr()
{
    delete []mEngFileName;
    AE_LOG( "[~AeMgr]\n");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::PreviewAEInit(MINT32 i4SensorIdx, Param_T &rParam)
{
    MRESULT err;
    MINT32 i4SutterDelay, i4SensorGainDelay, i4IspGainDelay;

    // set sensor type
    m_i4SensorIdx = i4SensorIdx;

    // set sensor initial
    err = AAASensorMgr::getInstance().init(m_i4SensorIdx);
    if (FAILED(err)) {
        CAM_LOGE("AAASensorMgr::getInstance().init fail i4SensorDev:%d\n", m_i4SensorIdx);
        return err;
    }

    AAASensorMgr::getInstance().getSensorSyncinfo(m_eSensorDev, &i4SutterDelay, &i4SensorGainDelay, &i4IspGainDelay, &m_i4SensorCaptureDelayFrame);
    AAASensorMgr::getInstance().getSensorMaxFrameRate(m_eSensorDev, m_rSensorMaxFrmRate);

    if ((m_pSensorGainThread == NULL) && (i4SutterDelay != i4SensorGainDelay) && (m_u4AdbAEPerFrameCtrl == 0) ){
        m_bSGainThdFlg = MTRUE;
        i4SensorGainDelay = i4SutterDelay;
    }

    if(i4IspGainDelay >= m_i4SensorCaptureDelayFrame) {
        m_i4TotalCaptureDelayFrame = i4IspGainDelay + 1;
    } else {
        m_i4TotalCaptureDelayFrame = m_i4SensorCaptureDelayFrame;
    }

    AE_LOG( "[PreviewAEInit] Long capture delay frame :%d %d %d\n", m_i4TotalCaptureDelayFrame, m_i4SensorCaptureDelayFrame, i4IspGainDelay);

    if((i4SutterDelay <= 5) && (i4SensorGainDelay <= 5) && (i4IspGainDelay <= 5)) {
        m_i4ShutterDelayFrames = i4SutterDelay;
        m_i4SensorGainDelayFrames = i4SensorGainDelay;
        if(i4IspGainDelay >= 2) {
            m_i4IspGainDelayFrames = i4IspGainDelay - ISP_GAIN_DELAY_OFFSET; // for CQ0 2 delay frame
        } else {
            m_i4IspGainDelayFrames = 0;
        }

        AE_LOG( "[PreviewAEInit] SensorDelayInfo-> AeMgrDelayInfo (shutter/sensor gain/isp gain): %d/%d/%d -> %d/%d/%d  \n",
            i4SutterDelay, i4SensorGainDelay, i4IspGainDelay, m_i4ShutterDelayFrames, m_i4SensorGainDelayFrames, m_i4IspGainDelayFrames);
    } else {
        AE_LOG( "[PreviewAEInit] Delay info is incorrectly :%d %d %d\n", i4SutterDelay, i4SensorGainDelay, i4IspGainDelay);
        m_i4ShutterDelayFrames = 0;
        m_i4SensorGainDelayFrames = 0;
        m_i4IspGainDelayFrames = 0; // for CQ0 2 delay frame
    }

    // Get sensor resolution
    err = getSensorResolution();
    if (FAILED(err)) {
        CAM_LOGE("getSensorResolution() fail\n");
        return err;
    }

    // Get NVRAM data
    err = getNvramData(m_eSensorDev);
    if (FAILED(err)) {
        CAM_LOGE("getNvramData() fail\n");
        return err;
    }

    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
        err = AAASensorMgr::getInstance().getSensorVCinfo(m_eSensorDev, &m_rSensorVCInfo);
        if (FAILED(err)) {
            CAM_LOGE("getSensorVCinfo() fail\n");
            return err;
        }
    }

    // Init AE
    err = AEInit(rParam);
    if (FAILED(err)) {
        CAM_LOGE("AEInit() fail\n");
        return err;
    }

    m_i4SensorGainDelayFramesWOShutter = m_rAEInitInput.rAEPARAM.strAEParasetting.uAESensorGainDelayCycleWOShutter;
    // AE statistics and histogram config
    m_bEnableHDRYConfig = m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableHDRLSB;
    m_bEnableOverCntConfig = m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableAEOVERCNTconfig;
    m_bEnableTSFConfig = m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTSFSTATconfig;
    m_bDisablePixelHistConfig = ((m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePixelBaseHist==1)?MFALSE:MTRUE);
    m_u4AEOverExpCntThs = m_rAEInitInput.rAEPARAM.strAEParasetting.uOverExpoTHD;
    m_rAEInitInput.rAEPARAM.bPerFrameAESmooth = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth & AE_PERFRAME_EN;
    m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
    m_bTgIntAEEn      = m_rAEInitInput.rAEPARAM.bTgIntAEEn;
    m_u4AEYCoefR = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEYCoefR;
    m_u4AEYCoefG = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEYCoefG;
    m_u4AEYCoefB = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEYCoefB;
    AE_LOG( "[PreviewAEInit] m_eSensorDev:%d m_i4SensorIdx:%d AEconfig:%d/%d/%d/%d/%d/%d AE_PERFRAME_EN:%d m_bPerframeAEFlag:%d m_bTgIntAEEn:%d AEYCoefR/G/B:%d/%d/%d\n",
             m_eSensorDev, m_i4SensorIdx, m_u4BlockNumX, m_u4BlockNumY,
             m_bEnableHDRYConfig, m_bEnableOverCntConfig, m_bEnableTSFConfig, m_bDisablePixelHistConfig,
             AE_PERFRAME_EN, m_bPerframeAEFlag, m_bTgIntAEEn,
             m_u4AEYCoefR, m_u4AEYCoefG, m_u4AEYCoefB);

    if(m_pAAOTgSeparatedBuf== NULL) {
        m_pAAOTgSeparatedBuf = (MVOID *)malloc(m_u4AAOSepAEsize);
        if(m_pAAOTgSeparatedBuf == NULL) {
            CAM_LOGE("AAO-TG separated statistic memory is not enough - 0\n");
        } else {
            AE_LOG( "AAO-TG separated memory allocated success - 1\n");
        }
    } else {
        AE_LOG( "AAO-TG separated memory is allocated already - 1\n");
    }
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::cameraPreviewInit(MINT32 i4SensorIdx, Param_T &rParam)
{
    AE_LOG( "[%s()] m_eSensorDev: %d, i4SensorIdx = %d, m_eSensorMode = %d CamMode:%d\n", __FUNCTION__, m_eSensorDev, i4SensorIdx, m_eSensorMode, m_eAECamMode);

    m_bRealISOSpeed = 0;
    m_i4WaitVDNum = 0;
    m_bSetShutterValue = MFALSE;
    m_bSetGainValue = MFALSE;
    m_bSetFrameRateValue = MFALSE;
    m_u4AEScheduleCnt = 0;
    m_i4EVIndex = 0;
    m_eAEEVcomp = LIB3A_AE_EV_COMP_00;

    memset(&m_SensorQueueCtrl, 0, sizeof(AE_SENSOR_QUEUE_CTRL_T));

    switch(m_eCamMode) {
        case eAppMode_EngMode:        //  Engineer Mode
            m_bRealISOSpeed = 1;
            m_eAECamMode = LIB3A_AECAM_MODE_PHOTO;
            break;
        case eAppMode_ZsdMode:        //  ZSD Mode
            m_eAECamMode = LIB3A_AECAM_MODE_ZSD;
            break;
        case eAppMode_VideoMode:     //  Video Mode
            m_eAECamMode = LIB3A_AECAM_MODE_VIDEO; // for board support package test used.
            break;
        case eAppMode_StereoMode:        //  S3D Mode
            // TBD
            // m_eAECamMode = LIB3A_AECAM_MODE_S3D;
            // break;
        case eAppMode_PhotoMode:     //  Photo Mode
        case eAppMode_DefaultMode:   //  Default Mode
        case eAppMode_AtvMode:         //  ATV Mode
        case eAppMode_VtMode:           //  VT Mode
        case eAppMode_FactoryMode:
        default:
            m_eAECamMode = LIB3A_AECAM_MODE_PHOTO;
            break;
        }

    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.ae_mgr.enable", value, "0");
    m_bAdbAEEnable = atoi(value);

    m_u4IndexTestCnt = 0;
    property_get("vendor.debug.ae.perframeCtrl.enable", value, "0");
    m_u4AdbAEPerFrameCtrl = atoi(value);

    property_get("vendor.debug.ae_loge.enable", value, "0");
    m_i4DgbLogE = atoi(value);

    property_get("vendor.debug.aaa.pvlog.enable", value, "0");
    m_3ALogEnable = atoi(value);

    property_get("vendor.debug.ae_mgr.dumpaao", value, "0");
    m_u4AdbAAOdump = atoi(value);

    property_get("vendor.debug.ae.vhdr.ratio", value, "0");
    m_u4VHDRratio= atoi(value);

    // AE Auto Test
    property_get("vendor.debug.ae.autoTest.enable", value, "0");
    m_bEnAutoTest = atoi(value);

    PreviewAEInit(i4SensorIdx, rParam);
    m_AEState = AE_AUTO_FRAMERATE_STATE;



    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::Start()
{
    MRESULT err;
    AE_LOG( "[%s()] m_eSensorDev: %d, m_i4SensorIdx = %d, m_eSensorMode = %d CamMode:%d\n", __FUNCTION__, m_eSensorDev, m_i4SensorIdx, m_eSensorMode, m_eAECamMode);
    // Adb Manaul Pline Control
    MBOOL bAdbControlPline = FALSE;
    MUINT32 u4AdbPreviewPline = 0;
    MUINT32 u4AdbCapturePline = 0;
    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.ae_pline.manual", value, "0");
    bAdbControlPline = atoi(value);
    if (bAdbControlPline){
        m_bManualAEtable = MTRUE;
        property_get("vendor.debug.ae_pline.preview", value, "0");
        m_u4ManualAEtablePreviewidx = atoi(value);
        property_get("vendor.debug.ae_pline.capture", value, "0");
        m_u4ManualAEtableCaptureidx = atoi(value);
        AE_LOG( "[%s()] ADB assigns P-lineID manually: %d/%d \n", __FUNCTION__,m_u4ManualAEtablePreviewidx, m_u4ManualAEtableCaptureidx);
    }
    m_i4WaitVDNum = 0;
    m_bSetShutterValue = MFALSE;
    m_bSetGainValue = MFALSE;
    m_bSetFrameRateValue = MFALSE;
    m_u4AEScheduleCnt = 0;
    m_bRestoreAE = MFALSE;
    if (m_eAETargetMode == AE_MODE_ZVHDR_TARGET) {
        m_bResetZHDRMode = MTRUE;
    }

    memset(&m_SensorQueueCtrl, 0, sizeof(AE_SENSOR_QUEUE_CTRL_T));

    // Define m_eCamMode
    switch(m_eCamMode) {
        case eAppMode_EngMode:        //  Engineer Mode
            m_bRealISOSpeed = 1;
            m_eAECamMode = LIB3A_AECAM_MODE_PHOTO;
            break;
        case eAppMode_ZsdMode:        //  ZSD Mode
            m_eAECamMode = LIB3A_AECAM_MODE_ZSD;
            break;
        case eAppMode_VideoMode:     //  Video Mode
            m_eAECamMode = LIB3A_AECAM_MODE_VIDEO; // for board support package test used.
            break;
        case eAppMode_StereoMode:        //  S3D Mode
            // TBD
            // m_eAECamMode = LIB3A_AECAM_MODE_S3D;
            // break;
        case eAppMode_PhotoMode:     //  Photo Mode
        case eAppMode_DefaultMode:   //  Default Mode
        case eAppMode_AtvMode:         //  ATV Mode
        case eAppMode_VtMode:           //  VT Mode
        case eAppMode_FactoryMode:
        default:
            m_eAECamMode = LIB3A_AECAM_MODE_PHOTO;
            break;
        }

    if ((m_bSGainThdFlg == MTRUE)&&(m_pSensorGainThread == NULL)) {
        m_pSensorGainThread = ThreadSensorGain::createInstance(m_eSensorDev,m_i4SensorIdx);
    } else {
        AE_LOG( "[%s()] Sensor gain thread status Flg/Thread : %d/%d \n", __FUNCTION__,m_bSGainThdFlg,(m_pSensorGainThread == NULL));
    }
    // Sensor max framerate will be changed when changing sensor mode
    AAASensorMgr::getInstance().getSensorMaxFrameRate(m_eSensorDev, m_rSensorMaxFrmRate);

    // Get sensor resolution
    err = getSensorResolution();
    if (FAILED(err)) {
        CAM_LOGE("getSensorResolution() fail\n");
        return err;
    }

    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
        err = AAASensorMgr::getInstance().getSensorVCinfo(m_eSensorDev, &m_rSensorVCInfo);
        if (FAILED(err)) {
            CAM_LOGE("getSensorVCinfo() fail\n");
            return err;
        }
    }
// AEInit

    // Query TG info
    IHalSensorList* const pIHalSensorList = MAKE_HalSensorList();
    IHalSensor* pIHalSensor = pIHalSensorList->createSensor("ae_mgr", m_i4SensorIdx);
    SensorDynamicInfo rSensorDynamicInfo;

    switch(m_eSensorDev) {
        case ESensorDev_Main:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_MAIN, &rSensorDynamicInfo);
            break;
        case ESensorDev_Sub:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_SUB, &rSensorDynamicInfo);
            break;
        case ESensorDev_MainSecond:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_MAIN_2, &rSensorDynamicInfo);
            break;
        case ESensorDev_SubSecond:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_SUB_2, &rSensorDynamicInfo);
            break;
        default:    //  Shouldn't happen.
            CAM_LOGE("Invalid sensor device: %d", m_eSensorDev);
    }

    if(pIHalSensor) {
        pIHalSensor->destroyInstance("ae_mgr");
    }

    AE_LOG( "TG = %d, pixel mode = %d\n", rSensorDynamicInfo.TgInfo, rSensorDynamicInfo.pixelMode);

    switch(rSensorDynamicInfo.TgInfo){
        case CAM_TG_1:
            m_eSensorTG = ESensorTG_1;
            break;
        case CAM_TG_2:
            m_eSensorTG = ESensorTG_2;
            break;
        default:
            CAM_LOGE("rSensorDynamicInfo.TgInfo = %d", rSensorDynamicInfo.TgInfo);
            return MFALSE;
    }
#if 0
    // --- init g/gyro sensor listener ---  AFThreadStart()
    {
        Mutex::Autolock lock(gCommonLock);
        if(gpSensorListener==NULL)
        {
            gpSensorListener = SensorListener::createInstance();
            gpSensorListener->setListener(aeListenHandler);

            gAcceInfo[0] = gAcceInfo[1] = gAcceInfo[2] = 0;
            gAcceValid = gpSensorListener->enableSensor(SensorListener::SensorType_Acc, SENSOR_ACCE_POLLING_MS);
            if(!gAcceValid)
            {
                gpSensorListener->disableSensor(SensorListener::SensorType_Acc);
            }

            gGyroInfo[0] = gGyroInfo[1] = gGyroInfo[2] = 0;
            gGyroValid = gpSensorListener->enableSensor(SensorListener::SensorType_Gyro, SENSOR_GYRO_POLLING_MS);
            if(!gGyroValid)
            {
                gpSensorListener->disableSensor(SensorListener::SensorType_Gyro);
            }
        }
    }
#endif
// AEInit(rParam);

    m_i4SensorGainDelayFramesWOShutter = m_rAEInitInput.rAEPARAM.strAEParasetting.uAESensorGainDelayCycleWOShutter;

    AE_LOG( "[Start] m_eSensorDev:%d m_eSensorTG:%d m_i4SensorIdx:%d m_eISPProfile:%d \n", m_eSensorDev, m_eSensorTG, m_i4SensorIdx, m_eISPProfile);
    // AE statistics and histogram config
    //m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight);
    m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight, m_i4AETgValidBlockWidth, m_i4AETgValidBlockHeight);
    err = ISP_MGR_AE_STAT_CONFIG_T::getInstance(m_eSensorDev).config(m_rAEStatCfg);
    err = ISP_MGR_AE_STAT_CONFIG_T::getInstance(m_eSensorDev).setAEconfigParam(m_u4BlockNumX,m_u4BlockNumY,
                                     m_bEnableHDRYConfig, m_bEnableOverCntConfig, m_bEnableTSFConfig,
                                     m_bDisablePixelHistConfig, m_u4AEOverExpCntThs, m_u4AEOverExpCntShift);
    err = ISP_MGR_AE_STAT_CONFIG_T::getInstance(m_eSensorDev).setAEYCoefParam(m_u4AEYCoefR, m_u4AEYCoefG, m_u4AEYCoefB);
    if (FAILED(err)) {
        CAM_LOGE("AE state hist config() fail\n");
        return err;
    }
    // Update AE info to Algorithm
    m_pIAeAlgo->setAERealISOSpeed(m_bRealISOSpeed);
    m_pIAeAlgo->getEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
    setAEScene(m_eAEScene);
    setIsoSpeed(m_u4AEISOSpeed);
    setAEMinMaxFrameRatePlineIdx(m_i4AEMinFps ,m_i4AEMaxFps);
    m_pIAeAlgo->updateAEPlineInfo(m_pPreviewTableCurrent,m_pCaptureTable);
    m_pIAeAlgo->setEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
    m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
    updateAEidxtoExpsetting();
    m_bAEStable = MFALSE;
    m_bAEMonitorStable = m_bAEStable;
    mPreviewMode = m_rAEOutput.rPreviewMode;
    updateAECycleInfo();
    m_i4AEAutoFlickerMode = (MINT32)(m_eAEAutoFlickerMode);
    if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET) || m_bVHDRChangeFlag) {
        if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
            m_rAEInitInput.i4AEMaxBlockWidth = m_rSensorVCInfo.u2VCStatWidth;
            m_rAEInitInput.i4AEMaxBlockHeight = m_rSensorVCInfo.u2VCStatHeight;
        }else{
            m_rAEInitInput.i4AEMaxBlockWidth = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumX;
            m_rAEInitInput.i4AEMaxBlockHeight = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumY;
        }
        m_rAEInitInput.u4AEISOSpeed = m_u4AEISOSpeed;
        m_rAEInitInput.eAETargetMode = m_eAETargetMode;

        strAEOutput rAEOutput;
        MBOOL bEnablePreIndex = m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex;
        m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex = MTRUE;
        m_pIAeAlgo->initAE(&m_rAEInitInput, &rAEOutput, &m_rAEStatCfg);
        resetZVHDRFlag();
        copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
        if ((m_eAETargetMode!=AE_MODE_IVHDR_TARGET)&&(m_eAETargetMode!=AE_MODE_MVHDR_TARGET)&&(m_eAETargetMode!=AE_MODE_ZVHDR_TARGET))
            UpdateSensorISPParams(AE_INIT_STATE);
        else
            UpdateSensorISPParams(AE_TWO_SHUTTER_INIT_STATE);
        m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex = bEnablePreIndex;
        m_bVHDRChangeFlag= MFALSE;

    } else {
        UpdateSensorISPParams(AE_INIT_STATE);
    }
    m_AEState = AE_AUTO_FRAMERATE_STATE;

    for (int i = 0 ; i < m_uEvQueueSize; i++) {
        m_u4PreAEidxQueue[i] = m_u4Index;
        m_u4PreTgIntAEidxQueue[i]= m_u4Index;
    }

    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::camcorderPreviewInit(MINT32 i4SensorIdx, Param_T &rParam)
{
    MRESULT err;

    AE_LOG( "[%s()] m_eSensorDev: %d, i4SensorIdx = %d, m_eSensorMode = %d CamMode:%d\n", __FUNCTION__, m_eSensorDev, i4SensorIdx, m_eSensorMode, m_eAECamMode);

    // the same with preview initial
    m_eAECamMode = LIB3A_AECAM_MODE_VIDEO; // for board support package test used.
    PreviewAEInit(i4SensorIdx, rParam);

    m_AEState = AE_MANUAL_FRAMERATE_STATE;

    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// for come back to preview/video condition use
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::cameraPreviewReinit()
{
    MRESULT err;
    strAEInput rAEInput;
    strAEOutput rAEOutput;

    m_i4WaitVDNum = 0;

    if(m_eCamMode == eAppMode_EngMode) {  //  Engineer Mode
        m_bRealISOSpeed = 1;
        m_eAECamMode = LIB3A_AECAM_MODE_PHOTO;
    } else if(m_eCamMode == eAppMode_ZsdMode) {  //  ZSD Mode
        m_eAECamMode = LIB3A_AECAM_MODE_ZSD;
        m_bRealISOSpeed = 0;
    }

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->setAERealISOSpeed(m_bRealISOSpeed);
        m_pIAeAlgo->setAECamMode(m_eAECamMode);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    AE_LOG( "[cameraPreviewReinit] Original m_eAECamMode:%d Real ISO:%d Exp mode: %d, Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                m_eAECamMode, m_bRealISOSpeed, m_rAEOutput.rPreviewMode.u4ExposureMode, m_rAEOutput.rPreviewMode.u4Eposuretime,
                m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain, m_rAEOutput.rPreviewMode.u2FrameRate,
                m_rAEOutput.rPreviewMode.i2FlareGain, m_rAEOutput.rPreviewMode.i2FlareOffset, m_rAEOutput.rPreviewMode.u4RealISO);

    if(m_bEnableAE) {
        if(m_eAECamMode != LIB3A_AECAM_MODE_VIDEO) {
            rAEInput.eAeState = AE_STATE_INIT;
            rAEInput.pAESatisticBuffer = NULL;
            if(m_pIAeAlgo != NULL) {
                m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
            } else {
                AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
            }
            AE_LOG( "[cameraPreviewReinit] init m_eAECamMode:%d Real ISO:%d Exp mode: %d, Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                m_eAECamMode, m_bRealISOSpeed, m_rAEOutput.rPreviewMode.u4ExposureMode, rAEOutput.EvSetting.u4Eposuretime,
                rAEOutput.EvSetting.u4AfeGain, rAEOutput.EvSetting.u4IspGain, rAEOutput.u2FrameRate,
                rAEOutput.i2FlareGain, rAEOutput.i2FlareOffset, rAEOutput.u4ISO);
        }

        rAEInput.eAeState = AE_STATE_AELOCK;
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
            m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }

        AE_LOG( "[cameraPreviewReinit] Lock Real ISO:%d Exp mode: %d, Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                m_bRealISOSpeed, m_rAEOutput.rPreviewMode.u4ExposureMode, rAEOutput.EvSetting.u4Eposuretime,
                rAEOutput.EvSetting.u4AfeGain, rAEOutput.EvSetting.u4IspGain, rAEOutput.u2FrameRate,
                rAEOutput.i2FlareGain, rAEOutput.i2FlareOffset, rAEOutput.u4ISO);

        copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);

        AE_LOG( "[cameraPreviewReinit] Exp mode: %d, Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                    m_rAEOutput.rPreviewMode.u4ExposureMode, m_rAEOutput.rPreviewMode.u4Eposuretime,
                    m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain, m_rAEOutput.rPreviewMode.u2FrameRate,
                    m_rAEOutput.rPreviewMode.i2FlareGain, m_rAEOutput.rPreviewMode.i2FlareOffset, m_rAEOutput.rPreviewMode.u4RealISO);
    } else {
        AE_LOG( "[cameraPreviewReinit] AE disable\n");
    }

    UpdateSensorISPParams(AE_REINIT_STATE);

    m_AEState = AE_AUTO_FRAMERATE_STATE;

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::uninit()
{
    MRESULT err;

    err = AAASensorMgr::getInstance().uninit();
    if (FAILED(err)) {
        CAM_LOGE("AAASensorMgr::getInstance().uninit fail\n");
        return err;
    }
    m_bSGainThdFlg = MFALSE;
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->destroyInstance();
        m_pIAeAlgo = NULL;
    }
    if(m_pAAOTgSeparatedBuf != NULL) {
        free(m_pAAOTgSeparatedBuf);
        m_pAAOTgSeparatedBuf = NULL;
        AE_LOG( "[AeMgr::uninit] m_pAAOTgSeparatedBuf\n");
    }
    #if 0
    // --- uninit g/gyro sensor listener --- uninit()
    {
        Mutex::Autolock lock(gCommonLock);
        if(gpSensorListener!=NULL)
        {
            if(gAcceValid)
            {
                gpSensorListener->disableSensor(SensorListener::SensorType_Acc);
            }

            if(gGyroValid)
            {
                gpSensorListener->disableSensor(SensorListener::SensorType_Gyro);
            }

            gpSensorListener->destroyInstance();
            gpSensorListener = NULL;
        }
    }
    #endif
    // Save uninit AEtime
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    AEtimer = (unsigned long long)time.tv_sec*1000000000 + (unsigned long long)time.tv_nsec;
    AE_LOG( "[AeMgr::uninit] AETimer %lld/%lld/%lld \n",AEtimer, (unsigned long long)time.tv_sec, (unsigned long long)time.tv_nsec);
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::Stop()
{
    if (m_pSensorGainThread){
        m_pSensorGainThread->destroyInstance();
        m_pSensorGainThread = NULL;
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void AeMgr::setAeMeterAreaEn(int en)
{
  AE_LOG( "setAeMeterAreaEn en=%d, m_isAeMeterAreaEn=%d",en, m_isAeMeterAreaEn);
  m_isAeMeterAreaEn=en;
  setAEMeteringArea(&m_backupMeterArea);

}
MRESULT AeMgr::setAEMeteringArea(CameraMeteringArea_T const *sNewAEMeteringArea)
{

    if(CUST_ENABLE_TOUCH_AE() == MFALSE) {
        AE_LOG( "[%s()] i4SensorDev:%d line:%d The set face AE is disable:%d ", __FUNCTION__, m_eSensorDev, __LINE__, CUST_ENABLE_TOUCH_AE());
        return S_AE_OK;
    }

    AE_LOG_IF(m_3ALogEnable,"setAEMeteringArea m_isAeMeterAreaEn=%d",m_isAeMeterAreaEn);


    CameraMeteringArea_T meterArea;
    memcpy(&m_backupMeterArea, sNewAEMeteringArea, sizeof(CameraMeteringArea_T));
    memcpy(&meterArea, sNewAEMeteringArea, sizeof(CameraMeteringArea_T));




    if(m_isAeMeterAreaEn==0)
    {
      memset(&meterArea, 0, sizeof(CameraMeteringArea_T));
      meterArea.u4Count = 1;
    }


    MUINT32 i;
    MBOOL bAreaChage = MFALSE;
    MUINT32 u4AreaCnt;
    CameraMeteringArea_T *sAEMeteringArea = &meterArea;

    if (sAEMeteringArea->u4Count <= 0) {
//        AE_LOG( "No AE Metering area cnt: %d\n", sAEMeteringArea->u4Count);
        return S_AE_OK;
    } else if (sAEMeteringArea->u4Count > MAX_METERING_AREAS) {
        CAM_LOGE("The AE Metering area cnt error: %d\n", sAEMeteringArea->u4Count);
        return E_AE_UNSUPPORT_MODE;
    }

    u4AreaCnt = sAEMeteringArea->u4Count;

    for(i=0; i<u4AreaCnt; i++) {

        AE_LOG_IF(m_3ALogEnable,"[%s():New] AE meter area Idx:%d Left:%d Right:%d Top:%d Bottom:%d Weight:%d\n",__FUNCTION__, i, sAEMeteringArea->rAreas[i].i4Left, sAEMeteringArea->rAreas[i].i4Right, sAEMeteringArea->rAreas[i].i4Top, sAEMeteringArea->rAreas[i].i4Bottom, sAEMeteringArea->rAreas[i].i4Weight);
        if (sAEMeteringArea->rAreas[i].i4Weight != 0){
             // Mapping AE region from Hbin size to [-1000,1000]
             sAEMeteringArea->rAreas[i].i4Left = sAEMeteringArea->rAreas[i].i4Left*2000/m_u4Hbinwidth - 1000;
             sAEMeteringArea->rAreas[i].i4Right = sAEMeteringArea->rAreas[i].i4Right*2000/m_u4Hbinwidth - 1000;
             sAEMeteringArea->rAreas[i].i4Top = sAEMeteringArea->rAreas[i].i4Top*2000/m_u4Hbinheight - 1000;
             sAEMeteringArea->rAreas[i].i4Bottom = sAEMeteringArea->rAreas[i].i4Bottom*2000/m_u4Hbinheight - 1000;
             // check if out-of-boundary
             if (sAEMeteringArea->rAreas[i].i4Left   < -1000)  {sAEMeteringArea->rAreas[i].i4Left   = -1000;}
             if (sAEMeteringArea->rAreas[i].i4Right  < -1000)  {sAEMeteringArea->rAreas[i].i4Right  = -1000;}
             if (sAEMeteringArea->rAreas[i].i4Top    < -1000)  {sAEMeteringArea->rAreas[i].i4Top    = -1000;}
             if (sAEMeteringArea->rAreas[i].i4Bottom < -1000)  {sAEMeteringArea->rAreas[i].i4Bottom = -1000;}
             if (sAEMeteringArea->rAreas[i].i4Left   > 1000)  {sAEMeteringArea->rAreas[i].i4Left   = 1000;}
             if (sAEMeteringArea->rAreas[i].i4Right  > 1000)  {sAEMeteringArea->rAreas[i].i4Right  = 1000;}
             if (sAEMeteringArea->rAreas[i].i4Top    > 1000)  {sAEMeteringArea->rAreas[i].i4Top    = 1000;}
             if (sAEMeteringArea->rAreas[i].i4Bottom > 1000)  {sAEMeteringArea->rAreas[i].i4Bottom = 1000;}

             if((sAEMeteringArea->rAreas[i].i4Left != m_eAEMeterArea.rAreas[i].i4Left) || (sAEMeteringArea->rAreas[i].i4Right != m_eAEMeterArea.rAreas[i].i4Right) ||
                 (sAEMeteringArea->rAreas[i].i4Top != m_eAEMeterArea.rAreas[i].i4Top) || (sAEMeteringArea->rAreas[i].i4Bottom != m_eAEMeterArea.rAreas[i].i4Bottom)) {
                 AE_LOG( "[%s():Modified] AE meter area Idx:%d Left:%d Right:%d Top:%d Bottom:%d Weight:%d\n",__FUNCTION__, i, sAEMeteringArea->rAreas[i].i4Left, sAEMeteringArea->rAreas[i].i4Right, sAEMeteringArea->rAreas[i].i4Top, sAEMeteringArea->rAreas[i].i4Bottom, sAEMeteringArea->rAreas[i].i4Weight);
                 AE_LOG( "[%s():Previous] AE meter area Idx:%d Left:%d Right:%d Top:%d Bottom:%d Weight:%d\n",__FUNCTION__, i, m_eAEMeterArea.rAreas[i].i4Left, m_eAEMeterArea.rAreas[i].i4Right, m_eAEMeterArea.rAreas[i].i4Top, m_eAEMeterArea.rAreas[i].i4Bottom, m_eAEMeterArea.rAreas[i].i4Weight);
                 m_eAEMeterArea.rAreas[i].i4Left = sAEMeteringArea->rAreas[i].i4Left;
                 m_eAEMeterArea.rAreas[i].i4Right = sAEMeteringArea->rAreas[i].i4Right;
                 m_eAEMeterArea.rAreas[i].i4Top = sAEMeteringArea->rAreas[i].i4Top;
                 m_eAEMeterArea.rAreas[i].i4Bottom = sAEMeteringArea->rAreas[i].i4Bottom;
                 m_eAEMeterArea.rAreas[i].i4Weight = sAEMeteringArea->rAreas[i].i4Weight;
                 bAreaChage = MTRUE;
             }
        }

    }
    if(bAreaChage == MTRUE) {
        m_bTouchAEAreaChage = MTRUE;
        m_eAEMeterArea.u4Count = u4AreaCnt;
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setAEMeteringArea(&m_eAEMeterArea);
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d TouchAEAreaChage:%d\n", __FUNCTION__, m_eSensorDev, __LINE__, m_bTouchAEAreaChage);
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setFDenable(MBOOL bFDenable)
{
    if (bFDenable != m_bFDenable){
        AE_LOG( "[%s()] FDenable is from %d -> %d\n", __FUNCTION__, m_bFDenable, bFDenable);
        m_bFDenable = bFDenable;
        m_bFaceAEAreaChage = MTRUE;
        m_u4WOFDCnt = 0 ;
    }
    return S_AE_OK;
}


MRESULT AeMgr::setFDInfo(MVOID* a_sFaces)
{
    MtkCameraFaceMetadata *pFaces = (MtkCameraFaceMetadata *)a_sFaces;
    MINT8 ifaceIdx = 0;

    if(CUST_ENABLE_FACE_AE() == MTRUE) {
        if(pFaces == NULL) {
            AE_LOG( "[%s()] FD window is NULL pointer 1\n", __FUNCTION__);
                return S_AF_OK;
        }

        if((pFaces->faces) == NULL) {
            AE_LOG( "[%s()] FD window is NULL pointer 2\n", __FUNCTION__);
            return S_AF_OK;
        }
        //First time with face to without face
        if (m_eAEFDArea.u4Count &&(pFaces->number_of_faces == 0)){
            m_bFaceAEAreaChage = MTRUE;
            m_u4WOFDCnt = 0 ;
            AE_LOG( "[%s()] First frame without face Count %d ->%d \n", __FUNCTION__,m_eAEFDArea.u4Count,pFaces->number_of_faces);
        }
        // Clear m_eAEFDArea content
        memset(&m_eAEFDArea, 0, sizeof(AEMeteringArea_T));

        if(m_bFDenable == MTRUE){
            // Define FD area number

            if(pFaces->number_of_faces > MAX_AE_METER_AREAS) {
                m_eAEFDArea.u4Count = MAX_AE_METER_AREAS;
            } else {
                m_eAEFDArea.u4Count = pFaces->number_of_faces;
            }

            for(ifaceIdx=0; ifaceIdx < m_eAEFDArea.u4Count; ifaceIdx++) {

                m_eAEFDArea.rAreas[ifaceIdx].i4Left = pFaces->faces[ifaceIdx].rect[0];
                m_eAEFDArea.rAreas[ifaceIdx].i4Right = pFaces->faces[ifaceIdx].rect[2];
                m_eAEFDArea.rAreas[ifaceIdx].i4Top = pFaces->faces[ifaceIdx].rect[1];
                m_eAEFDArea.rAreas[ifaceIdx].i4Bottom = pFaces->faces[ifaceIdx].rect[3];
                m_eAEFDArea.rAreas[ifaceIdx].i4Weight = 1;
                // new FD info +
                m_eAEFDArea.rAreas[ifaceIdx].i4Id = pFaces->faces[ifaceIdx].id;
                m_eAEFDArea.rAreas[ifaceIdx].i4Type = pFaces->faces_type[ifaceIdx];
                m_eAEFDArea.rAreas[ifaceIdx].i4Motion[0] = pFaces->motion[ifaceIdx][0];
                m_eAEFDArea.rAreas[ifaceIdx].i4Motion[1] = pFaces->motion[ifaceIdx][1];
                // landmark cv
                m_eAEFDArea.rAreas[ifaceIdx].i4LandmarkCV = pFaces->fa_cv[ifaceIdx];
                if (pFaces->fa_cv[ifaceIdx] > 0) {
                    // left eye
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][0] = pFaces->leyex0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][1] = pFaces->leyey0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][2] = pFaces->leyex1[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][3] = pFaces->leyey1[ifaceIdx];
                    // right eye
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][0] = pFaces->reyex0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][1] = pFaces->reyey0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][2] = pFaces->reyex1[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][3] = pFaces->reyey1[ifaceIdx];
                    // mouth
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][0] = pFaces->mouthx0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][1] = pFaces->mouthy0[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][2] = pFaces->mouthx1[ifaceIdx];
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][3] = pFaces->mouthy1[ifaceIdx];
                }
                // FD Area Info
                m_eAEFDArea.rAreas[ifaceIdx].i4Left   = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Left*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                m_eAEFDArea.rAreas[ifaceIdx].i4Right  = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Right*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                m_eAEFDArea.rAreas[ifaceIdx].i4Top    = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Top*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                m_eAEFDArea.rAreas[ifaceIdx].i4Bottom = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Bottom*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);

                if(pFaces->fa_cv[ifaceIdx] > 0)
                {
                    // left eye
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][0] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][0]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][1] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][1]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][2] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][2]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][3] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[0][3]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                    // right eye
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][0] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][0]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][1] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][1]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][2] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][2]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][3] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[1][3]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                    // mouth
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][0] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][0]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][1] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][1]*2000/(m_eZoomWinInfo.u4XWidth+2*m_eZoomWinInfo.u4XOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][2] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][2]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                    m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][3] = -1000 + m_eAEFDArea.rAreas[ifaceIdx].i4Landmark[2][3]*2000/(m_eZoomWinInfo.u4YHeight+2*m_eZoomWinInfo.u4YOffset);
                }

                AE_LOG( "[%s():Modified] AE FD meter area Idx:%d Left:%d Right:%d Top:%d Bottom:%d InitWidth:%d InitHeight:%d\n",__FUNCTION__, ifaceIdx,
                            m_eAEFDArea.rAreas[ifaceIdx].i4Left, m_eAEFDArea.rAreas[ifaceIdx].i4Right,
                            m_eAEFDArea.rAreas[ifaceIdx].i4Top, m_eAEFDArea.rAreas[ifaceIdx].i4Bottom ,m_eZoomWinInfo.u4XWidth,m_eZoomWinInfo.u4YHeight );
                AE_LOG( "[%s():Previous] AE FD meter area Idx:%d Left:%d Right:%d Top:%d Bottom:%d \n",__FUNCTION__, ifaceIdx,
                          pFaces->faces[ifaceIdx].rect[0], pFaces->faces[ifaceIdx].rect[2],
                          pFaces->faces[ifaceIdx].rect[1] , pFaces->faces[ifaceIdx].rect[3] );

                m_bFaceAEAreaChage = MTRUE;
                m_u4WOFDCnt = 0 ;
            }

            AE_LOG_IF(m_3ALogEnable,"[%s()] i4SensorDev:%d line:%d Face Number:%d FaceAEChange:%d", __FUNCTION__, m_eSensorDev, __LINE__, m_eAEFDArea.u4Count, m_bFaceAEAreaChage);
        }
    } else {
        AE_LOG( "[%s()] i4SensorDev:%d line:%d The set face AE is disable:%d ", __FUNCTION__, m_eSensorDev, __LINE__, CUST_ENABLE_FACE_AE());
    }

    return S_AF_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setOTInfo(MVOID* a_sOT)
{
    MtkCameraFaceMetadata *pOTWindow = (MtkCameraFaceMetadata *)a_sOT;
    MBOOL bEnableObjectTracking;

    if( m_i4ObjectTrackNum != pOTWindow->number_of_faces) {
        AE_LOG( "[setOTInfo] Object tracking:%d %d\n", pOTWindow->number_of_faces, m_i4ObjectTrackNum);
        m_i4ObjectTrackNum = pOTWindow->number_of_faces;
        if(pOTWindow->number_of_faces > 0) { // Object tracking enable
            bEnableObjectTracking = MTRUE;
        } else {
            bEnableObjectTracking = MFALSE;
        }

        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setAEObjectTracking(bEnableObjectTracking);
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
        } else {
            AE_LOG( "The AE algo class is NULL (2)\n");
        }
    }
    return S_AF_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEEVCompIndex(MINT32 i4NewEVIndex, MFLOAT fStep)
{
MINT32 i4EVValue, i4EVStep;

    if (m_i4EVIndex != i4NewEVIndex) {
        m_i4EVIndex = i4NewEVIndex;
        m_fEVCompStep = fStep;
        i4EVStep = (MINT32) (100 * m_fEVCompStep);
        i4EVValue = i4NewEVIndex * i4EVStep;

        if(i4EVValue < -390) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n40; }
        else if(i4EVValue < -380) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n39; }
        else if(i4EVValue < -370) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n38; }
        else if(i4EVValue < -360) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n37; }
        else if(i4EVValue < -350) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n36; }
        else if(i4EVValue < -340) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n35; }
        else if(i4EVValue < -330) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n34; }
        else if(i4EVValue < -320) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n33; }
        else if(i4EVValue < -310) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n32; }
        else if(i4EVValue < -300) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n31; }
        else if(i4EVValue < -290) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n30; }
        else if(i4EVValue < -280) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n29; }
        else if(i4EVValue < -270) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n28; }
        else if(i4EVValue < -260) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n27; }
        else if(i4EVValue < -250) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n26; }
        else if(i4EVValue < -240) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n25; }
        else if(i4EVValue < -230) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n24; }
        else if(i4EVValue < -220) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n23; }
        else if(i4EVValue < -210) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n22; }
        else if(i4EVValue < -200) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n21; }
        else if(i4EVValue < -190) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n20; }
        else if(i4EVValue < -180) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n19; }
        else if(i4EVValue < -170) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n18; }
        else if(i4EVValue < -160) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n17; }
        else if(i4EVValue < -150) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n16; }
        else if(i4EVValue < -140) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n15; }
        else if(i4EVValue < -130) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n14; }
        else if(i4EVValue < -120) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n13; }
        else if(i4EVValue < -110) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n12; }
        else if(i4EVValue < -100) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n11; }
        else if(i4EVValue < -90) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_n10; }
        else if(i4EVValue < -80) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n09; }
        else if(i4EVValue < -70) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n08; }
        else if(i4EVValue < -60) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_n07; }
        else if(i4EVValue < -50) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n06; }
        else if(i4EVValue < -40) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_n05; }
        else if(i4EVValue < -30) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n04; }
        else if(i4EVValue < -20) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n03; }
        else if(i4EVValue < -10) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n02; }
        else if(i4EVValue <   0) { m_eAEEVcomp = LIB3A_AE_EV_COMP_n01;   }
        else if(i4EVValue == 0) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_00;   }
        else if(i4EVValue < 20) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_01;   }
        else if(i4EVValue < 30) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_02;   }
        else if(i4EVValue < 40) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_03;   }
        else if(i4EVValue < 50) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_04;   }
        else if(i4EVValue < 60) {     m_eAEEVcomp = LIB3A_AE_EV_COMP_05;  }
        else if(i4EVValue < 70) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_06;   }
        else if(i4EVValue < 80) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_07;   }
        else if(i4EVValue < 90) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_08;   }
        else if(i4EVValue < 100) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_09;   }
        else if(i4EVValue < 110) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_10;   }
        else if(i4EVValue < 120) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_11;   }
        else if(i4EVValue < 130) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_12;   }
        else if(i4EVValue < 140) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_13;   }
        else if(i4EVValue < 150) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_14;   }
        else if(i4EVValue < 160) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_15;   }
        else if(i4EVValue < 170) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_16;   }
        else if(i4EVValue < 180) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_17;   }
        else if(i4EVValue < 190) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_18;   }
        else if(i4EVValue < 200) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_19;   }
        else if(i4EVValue < 210) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_20;   }
        else if(i4EVValue < 220) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_21;   }
        else if(i4EVValue < 230) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_22;   }
        else if(i4EVValue < 240) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_23;   }
        else if(i4EVValue < 250) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_24;   }
        else if(i4EVValue < 260) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_25;   }
        else if(i4EVValue < 270) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_26;   }
        else if(i4EVValue < 280) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_27;   }
        else if(i4EVValue < 290) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_28;   }
        else if(i4EVValue < 300) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_29;   }
        else if(i4EVValue < 310) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_30;   }
        else if(i4EVValue < 320) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_31;   }
        else if(i4EVValue < 330) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_32;   }
        else if(i4EVValue < 340) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_33;   }
        else if(i4EVValue < 350) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_34;   }
        else if(i4EVValue < 360) {   m_eAEEVcomp = LIB3A_AE_EV_COMP_35;   }
        else if(i4EVValue < 370) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_36;   }
        else if(i4EVValue < 380) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_37;   }
        else if(i4EVValue < 390) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_38;   }
        else if(i4EVValue < 400) {    m_eAEEVcomp = LIB3A_AE_EV_COMP_39;   }
        else { m_eAEEVcomp = LIB3A_AE_EV_COMP_40;  }

        AE_LOG( "[setAEEVCompIndex] m_i4EVIndex: %d EVComp:%d fEVCompStep:%f PreAEState:%d m_bAELock:%d\n", m_i4EVIndex, m_eAEEVcomp, m_fEVCompStep, m_ePreAEState, m_bAELock);
        if(m_pIAeAlgo != NULL) {
            // AE Auto Test
            if(m_bEnAutoTest) {
                m_u4ATCnt = AE_AT_MAX_CNT_NUM;
                m_u4ATYval = m_pIAeAlgo->getBrightnessAverageValue();
                m_u4ATType = AE_AT_TYPE_EVCOMP;
                AE_LOG( "AE Auto Test [AE_AT_TYPE_EVCOMP]: m_u4ATYval(%d) thresh(%d) m_u4ATType(%d)\n", m_u4ATYval, AEAutoTestThreshTable[m_u4ATType], m_u4ATType);
            }

            m_pIAeAlgo->setEVCompensate(m_eAEEVcomp);
            if (m_bAEMonitorStable == MTRUE){
                m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
            }
            m_strAECycleInfo.m_i4FrameCnt = 1;
            m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
            if(m_bAELock) {
                m_i4WaitVDNum = (m_i4IspGainDelayFrames+ISP_GAIN_DELAY_OFFSET+1);
            }
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    }

    return S_AE_OK;
}

/*******************************************************************************
*
********************************************************************************/
MINT32 AeMgr::getEVCompensateIndex()
{
MINT32 iEVIndex;

    switch(m_eAEEVcomp){
        case LIB3A_AE_EV_COMP_03: { iEVIndex = 3;   break; }
        case LIB3A_AE_EV_COMP_05: { iEVIndex = 5;   break; }
        case LIB3A_AE_EV_COMP_07: { iEVIndex = 7;   break; }
        case LIB3A_AE_EV_COMP_10: { iEVIndex = 10;  break; }
        case LIB3A_AE_EV_COMP_13: { iEVIndex = 13;  break; }
        case LIB3A_AE_EV_COMP_15: { iEVIndex = 15;  break; }
        case LIB3A_AE_EV_COMP_17: { iEVIndex = 17;  break; }
        case LIB3A_AE_EV_COMP_20: { iEVIndex = 20;  break; }
        case LIB3A_AE_EV_COMP_25: { iEVIndex = 25;  break; }
        case LIB3A_AE_EV_COMP_30: { iEVIndex = 30;  break; }
        case LIB3A_AE_EV_COMP_35: { iEVIndex = 35;  break; }
        case LIB3A_AE_EV_COMP_40: { iEVIndex = 40;  break; }
        case LIB3A_AE_EV_COMP_n03: { iEVIndex = -3;   break; }
        case LIB3A_AE_EV_COMP_n05: { iEVIndex = -5;   break; }
        case LIB3A_AE_EV_COMP_n07: { iEVIndex = -7;   break; }
        case LIB3A_AE_EV_COMP_n10: { iEVIndex = -10;  break; }
        case LIB3A_AE_EV_COMP_n13: { iEVIndex = -13;  break; }
        case LIB3A_AE_EV_COMP_n15: { iEVIndex = -15;  break; }
        case LIB3A_AE_EV_COMP_n17: { iEVIndex = -17;  break; }
        case LIB3A_AE_EV_COMP_n20: { iEVIndex = -20;  break; }
        case LIB3A_AE_EV_COMP_n25: { iEVIndex = -25;  break; }
        case LIB3A_AE_EV_COMP_n30: { iEVIndex = -30;  break; }
        case LIB3A_AE_EV_COMP_n35: { iEVIndex = -35;  break; }
        case LIB3A_AE_EV_COMP_n40: { iEVIndex = -40;  break; }
        default:
        case LIB3A_AE_EV_COMP_00:
            iEVIndex = 0;
            break;
    }
    return iEVIndex;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEMeteringMode(MUINT32 u4NewAEMeteringMode)
{
    AE_METERING_T eNewAEMeteringMode = static_cast<AE_METERING_T>(u4NewAEMeteringMode);
    LIB3A_AE_METERING_MODE_T eAEMeteringMode;

    if ((eNewAEMeteringMode < AE_METERING_BEGIN) || (eNewAEMeteringMode >= NUM_OF_AE_METER)) {
        CAM_LOGE("Unsupport AE Metering Mode: %d\n", eNewAEMeteringMode);
        return E_AE_UNSUPPORT_MODE;
    }

    switch(eNewAEMeteringMode) {
        case AE_METERING_MODE_SOPT:
            eAEMeteringMode = LIB3A_AE_METERING_MODE_SOPT;
            break;
        case AE_METERING_MODE_AVERAGE:
            eAEMeteringMode = LIB3A_AE_METERING_MODE_AVERAGE;
            break;
        case AE_METERING_MODE_CENTER_WEIGHT:
            eAEMeteringMode = LIB3A_AE_METERING_MODE_CENTER_WEIGHT;
            break;
        default:
            AE_LOG( "The AE metering mode enum value is incorrectly:%d\n", eNewAEMeteringMode);
            eAEMeteringMode = LIB3A_AE_METERING_MODE_CENTER_WEIGHT;
            break;
    }

    if (m_eAEMeterMode != eAEMeteringMode) {
        m_eAEMeterMode = eAEMeteringMode;
        AE_LOG( "[setAEMeteringMode] m_eAEMeterMode: %d\n", m_eAEMeterMode);
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setAEMeteringMode(m_eAEMeterMode);
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAEMeterMode() const
{
    return static_cast<MINT32>(m_eAEMeterMode);
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEMinMaxFrameRate(MINT32 i4NewAEMinFps, MINT32 i4NewAEMaxFps)
{
    MINT32 i4NewMinFPS, i4NewMaxFPS, i4SensorMaxFPS;

    i4NewMinFPS = i4NewAEMinFps / 100;
    i4NewMaxFPS = i4NewAEMaxFps / 100;
    i4SensorMaxFPS = m_rSensorMaxFrmRate[m_eSensorMode];

    if (i4NewMaxFPS > i4SensorMaxFPS)
    {
        AE_LOG( "[%s] Clipping: i4NewMaxFPS(%d), i4SensorMaxFPS(%d)", __FUNCTION__, i4NewMaxFPS, i4SensorMaxFPS);
        i4NewMaxFPS = i4SensorMaxFPS;
    }

    if ((i4NewMinFPS < LIB3A_AE_FRAMERATE_MODE_05FPS) || (i4NewMaxFPS > LIB3A_AE_FRAMERATE_MODE_MAX)) {
        AE_LOG( "[setAEMinMaxFrameRate] Unsupport AE frame rate range value: %d %d\n", i4NewMinFPS, i4NewMaxFPS);
        return S_AE_OK;
    } else if(i4NewMinFPS > i4NewMaxFPS) {
        AE_LOG( "[setAEMinMaxFrameRate] Unsupport AE frame rate: %d %d\n", i4NewMinFPS, i4NewMaxFPS);
        i4NewMinFPS = i4NewMaxFPS;
    }

    if ((m_i4AEMinFps != i4NewMinFPS) || (m_i4AEMaxFps != i4NewMaxFPS)) {
        m_i4AEMinFps = i4NewMinFPS;
        m_i4AEMaxFps = i4NewMaxFPS;
        AE_LOG( "[setAEMinMaxFrameRate] m_i4AEMinFps: %d m_i4AEMaxFps:%d\n", m_i4AEMinFps, m_i4AEMaxFps);
        if(m_pIAeAlgo != NULL) {
            //New AE-Pline
            m_pIAeAlgo->getEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
            searchPreviewIndexLimit();
            m_pIAeAlgo->setEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
            m_pIAeAlgo->setAEMinMaxFrameRate(m_i4AEMinFps, m_i4AEMaxFps);
            m_pIAeAlgo->setAECamMode(m_eAECamMode);
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
            m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
            m_i4WaitVDNum = (m_i4IspGainDelayFrames+ISP_GAIN_DELAY_OFFSET+1);
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    }

    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEShotMode(MUINT32 u4NewAEShotMode)
{
    EShotMode eNewAEShotMode = static_cast<EShotMode>(u4NewAEShotMode);

    if (m_eShotMode != eNewAEShotMode) {
        m_eShotMode = eNewAEShotMode;
        m_bAElimitor = MFALSE;
        AE_LOG( "[setAEShotMode] m_eAppShotMode:%d AE limitor:%d\n", m_eShotMode, m_bAElimitor);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEHDRMode(MUINT32 u4NewAEHDRMode)
{
    AE_NVRAM_IDX_T eNewAEHDRMode = static_cast<AE_NVRAM_IDX_T>(u4NewAEHDRMode);

    if (m_eAENVRAMIdx != eNewAEHDRMode) {
        AE_LOG( "[setAEHDRMode] m_eAENVRAMIdx: %d -> %d\n", m_eAENVRAMIdx, eNewAEHDRMode);
        m_eAENVRAMIdx = eNewAEHDRMode;
        m_rAEInitInput.rAENVRAM = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx];
        switch(m_eSensorDev) {
        case ESensorDev_Main:
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_Main>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_Main>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_Main>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_Main>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }
            break;
        case ESensorDev_Sub:
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_Sub>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_Sub>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_Sub>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_Sub>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }
            break;
        case ESensorDev_MainSecond:
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_MainSecond>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_MainSecond>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_MainSecond>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_MainSecond>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }
            break;
        case ESensorDev_SubSecond:
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_SubSecond>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_SubSecond>();
                m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strHDRPlineMapping.sAESceneMapping[0]));
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_SubSecond>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_SubSecond>();
                m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
            }
            break;
        default:    //  Shouldn't happen.
            MY_ERR("Invalid sensor device: %d", m_eSensorDev);
    }
        m_pIAeAlgo->updateAEParam(&m_rAEInitInput);
        updateAEScenarioPline(m_eSensorMode);

        m_rAEInitInput.rAEPARAM.bPerFrameAESmooth = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth & AE_PERFRAME_EN;
        m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth = m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth & AE_PERFRAME_EN;

        if ((m_eAENVRAMIdx!=AE_NVRAM_IDX_NORMAL)&&(m_eAENVRAMIdx!=AE_NVRAM_IDX_VT)){
            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth;
        }else{
            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
        }

        m_bTgIntAEEn      = m_rAEInitInput.rAEPARAM.bTgIntAEEn;

        // auto HDR: m_i4HdrOnOff reset
        m_i4HdrOnOff = toLiteral(HDRDetectionResult::NONE);
        if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO) {
            m_i4HdrOnOff = toLiteral(HDRDetectionResult::NORMAL);
            AE_LOG("[%s] turn on auto HDR\n", __FUNCTION__);
        }
        AE_LOG_IF(m_3ALogEnable,"[%s] m_i4HdrOnOff:%d\n", __FUNCTION__, m_i4HdrOnOff);
    }

    if(m_eAETargetMode == AE_MODE_ZVHDR_TARGET && m_bResetZHDRMode) {
        if((m_eSensorMode == ESensorMode_Video) && (m_eISPProfile == EIspProfile_Preview)) {
            AE_LOG( "[%s()] ZHDR SensorMode:%d Change AE Pline table to Preview\n", __FUNCTION__, m_eSensorMode);
            updateAEScenarioPline(ESensorMode_Preview);
        }
        m_bResetZHDRMode = MFALSE;
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAEHDROnOff()
{
    AE_LOG_IF(m_3ALogEnable,"[%s] m_i4HdrOnOff:%d\n", __FUNCTION__, m_i4HdrOnOff);
    return m_i4HdrOnOff;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAELimiterMode(MBOOL bAELimter)
{
    m_bAElimitor = bAELimter;
    AE_LOG( "[setAELimiterMode] ShotMode:%d AE limitor:%d\n", m_eShotMode, m_bAElimitor);
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->setAElimitorEnable(m_bAElimitor);
        if (m_bAEMonitorStable == MTRUE){
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
    }

        } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEMode(MUINT32 u4NewAEMode)
{
    MUINT32 eNewAEMode = u4NewAEMode;
    LIB3A_AE_MODE_T eAEMode;
    if ((MINT32)eNewAEMode != (MINT32)m_eAEMode){
        AE_LOG( "[%s()] m_eAEMode %d -> %d AEState:%d %d\n", __FUNCTION__, m_eAEMode, eNewAEMode, m_eAEState, m_ePreAEState);

        switch(eNewAEMode) {
            case MTK_CONTROL_AE_MODE_OFF:
                m_eAEMode = LIB3A_AE_MODE_OFF;
                m_eAEState = MTK_CONTROL_AE_STATE_INACTIVE;
                break;
            case MTK_CONTROL_AE_MODE_ON:
                m_eAEMode = LIB3A_AE_MODE_ON;
                break;
            case MTK_CONTROL_AE_MODE_ON_AUTO_FLASH:
                m_eAEMode = LIB3A_AE_MODE_ON_AUTO_FLASH;
                break;
            case MTK_CONTROL_AE_MODE_ON_ALWAYS_FLASH:
                m_eAEMode = LIB3A_AE_MODE_ON_ALWAYS_FLASH;
                break;
            case MTK_CONTROL_AE_MODE_ON_AUTO_FLASH_REDEYE:
                m_eAEMode = LIB3A_AE_MODE_ON_AUTO_FLASH_REDEYE;
                break;
            default:
                break;
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAEMode() const
{
    return static_cast<MINT32>(m_eAEMode);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAEState() const
{
    return static_cast<MINT32>(m_eAEState);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::setSensorMode(MINT32 i4NewSensorMode , MUINT32 width, MUINT32 height)
{
    ESensorMode_T eNewSensorMode;
    MUINT32 u4BlocksizeX;
    MUINT32 u4BlocksizeY;
    AE_LOG( "[%s()] m_eSensorDev: %d i4NewSensorMode: %d\n", __FUNCTION__, m_eSensorDev, i4NewSensorMode);

    switch (i4NewSensorMode) {
        case SENSOR_SCENARIO_ID_NORMAL_PREVIEW:
            eNewSensorMode = ESensorMode_Preview;
            break;
        case SENSOR_SCENARIO_ID_NORMAL_CAPTURE:
            eNewSensorMode = ESensorMode_Capture;
            break;
        case SENSOR_SCENARIO_ID_NORMAL_VIDEO:
            eNewSensorMode = ESensorMode_Video;
            break;
        case SENSOR_SCENARIO_ID_SLIM_VIDEO1:
            eNewSensorMode = ESensorMode_SlimVideo1;
            break;
        case SENSOR_SCENARIO_ID_SLIM_VIDEO2:
            eNewSensorMode = ESensorMode_SlimVideo2;
            break;
        case SENSOR_SCENARIO_ID_CUSTOM1:
            eNewSensorMode = ESensorMode_Custom1;
            break;
        case SENSOR_SCENARIO_ID_CUSTOM2:
            eNewSensorMode = ESensorMode_Custom2;
            break;
        case SENSOR_SCENARIO_ID_CUSTOM3:
            eNewSensorMode = ESensorMode_Custom3;
            break;
        case SENSOR_SCENARIO_ID_CUSTOM4:
            eNewSensorMode = ESensorMode_Custom4;
            break;
        case SENSOR_SCENARIO_ID_CUSTOM5:
            eNewSensorMode = ESensorMode_Custom5;
            break;
        default:
            CAM_LOGE("E_AE_UNSUPPORT_SENSOR_MODE: %d\n", i4NewSensorMode);
            return MFALSE;
    }

    // Window size
    u4BlocksizeX = ((width / m_u4BlockNumX)/2)*2;
    u4BlocksizeY = ((height / m_u4BlockNumY)/2)*2;
    m_u4AEOverExpCntShift = (((u4BlocksizeX/4)*(u4BlocksizeY/2)>255)?MTRUE:MFALSE);
    AE_LOG( "[%s()] m_eSensorMode/Hbinwidth/Hbinheight: %d/%d/%d -> %d/%d/%d , u4BlocksizeX/Y/Shift = %d/%d/%d \n", __FUNCTION__, m_eSensorMode,m_u4Hbinwidth,m_u4Hbinheight,
           eNewSensorMode, width, height, u4BlocksizeX , u4BlocksizeY, m_u4AEOverExpCntShift);
    m_u4Hbinwidth = width;
    m_u4Hbinheight = height;

    // TG interrupt AAO information
    MINT32 i4PitchY  = height / m_u4BlockNumY;
    MINT32 i4OriginY = (height - (i4PitchY * m_u4BlockNumY)) / 2;
    MINT32 i4AETgValidBlockWidth  = m_rAEInitInput.i4AEMaxBlockWidth;
    MINT32 i4AETgValidBlockHeight = (height * TG_INT_AE_RATIO - i4OriginY) / i4PitchY;
    AE_LOG( "[%s()] i4AETgValidBlockWidth/Height: %d/%d -> %d/%d , u4BlockNumX/Y/i4PitchY/i4OriginY = %d/%d/%d/%d \n", __FUNCTION__,
           m_i4AETgValidBlockWidth, m_i4AETgValidBlockHeight, i4AETgValidBlockWidth, i4AETgValidBlockHeight,
           m_u4BlockNumX, m_u4BlockNumY, i4PitchY, i4OriginY);
    m_i4AETgValidBlockWidth  = i4AETgValidBlockWidth;
    m_i4AETgValidBlockHeight = i4AETgValidBlockHeight;

    if((m_bAEReadyCapture == MTRUE) && (m_bAECaptureUpdate == MFALSE)) {
        ModifyCaptureParamsBySensorMode(eNewSensorMode, m_eSensorMode);
    }

    if (m_eSensorMode != eNewSensorMode) {
        if (m_pAEMapPlineTable != NULL){
            switchSensorModeMaxBVSensitivityDiff(eNewSensorMode, m_eSensorMode, m_i4DeltaSensitivityIdx, m_i4DeltaBVIdx);
        }
        m_eSensorMode = eNewSensorMode;
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setAESensorMode(m_eSensorMode);
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    }

    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::updateAEScenarioMode(EIspProfile_T eIspProfile)
{
    if (m_eISPProfile != eIspProfile){
        AE_LOG( "[%s()] eIspProfile: %d -> %d \n", __FUNCTION__, m_eISPProfile, eIspProfile);
        m_eISPProfile = eIspProfile ;
        if((m_eSensorMode == ESensorMode_Preview)&&(eIspProfile == EIspProfile_Video)) {
            AE_LOG( "[%s()] SensorMode:%d Change AE Pline table to Video\n", __FUNCTION__, m_eSensorMode);
            // AE Auto Test
            if(m_bEnAutoTest) {
                m_u4ATCnt = AE_AT_MAX_CNT_NUM;
                m_u4ATYval = m_pIAeAlgo->getBrightnessAverageValue();
                m_u4ATType = AE_AT_TYPE_Pre2Video;
                AE_LOG( "AE Auto Test [AE_AT_TYPE_Pre2Video]: m_u4ATYval(%d) thresh(%d) m_u4ATType(%d)\n", m_u4ATYval, AEAutoTestThreshTable[m_u4ATType], m_u4ATType);
            }
            updateAEScenarioPline(ESensorMode_Video);
        }
        else if((m_eSensorMode == ESensorMode_Video)&&(eIspProfile == EIspProfile_Preview)) {
            AE_LOG( "[%s()] SensorMode:%d Change AE Pline table to Preview\n", __FUNCTION__, m_eSensorMode);
            updateAEScenarioPline(ESensorMode_Preview);
        }else {
            m_pIAeAlgo->getEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
            setAEScene(m_eAEScene);
            setIsoSpeed(m_u4AEISOSpeed);
            setAEMinMaxFrameRatePlineIdx(m_i4AEMinFps ,m_i4AEMaxFps);
            m_pIAeAlgo->updateAEPlineInfo(m_pPreviewTableCurrent,m_pCaptureTable);
            m_pIAeAlgo->setEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
            m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
            AE_LOG( "[%s()] SensorMode:%d IspProfile:%d Change AE Pline table to Normal \n", __FUNCTION__, m_eSensorMode, eIspProfile);
        }
        // Reschedule if needed
        if (m_bAEMonitorStable == MTRUE){
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
        }
    }
    return MTRUE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateAEScenarioPline(MINT32 i4SensorMode)
{
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->setAESensorMode(i4SensorMode);
        m_pIAeAlgo->setIsoSpeed(m_u4AEISOSpeed);

        if (m_pAEMapPlineTable != NULL){
            switchSensorModeMaxBVSensitivityDiff(i4SensorMode, m_eSensorMode, m_i4DeltaSensitivityIdx, m_i4DeltaBVIdx);
        }

        m_pIAeAlgo->getEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);

        MRESULT mr;
        eAETableID ePreviewPLineTableID, eCapturePLineTableID;
        if(m_pAEPlineTable != NULL && m_pAEMapPlineTable != NULL) {   // protect the AE Pline table don't ready
            mr = getAEPLineMappingID(m_eAEScene, i4SensorMode, &ePreviewPLineTableID, &eCapturePLineTableID);
                if(FAILED(mr)) {
                    MY_ERR("[updateAEScenarioMode]Get capture table ERROR :%d PLineID:%d %d\n", m_eAEScene, ePreviewPLineTableID, eCapturePLineTableID);
                }

            mr = setAETable(ePreviewPLineTableID, eCapturePLineTableID);
            if(FAILED(mr)) {
                MY_ERR("[updateAEScenarioMode]Capture table ERROR :%d PLineID:%d %d\n", m_eAEScene, ePreviewPLineTableID, eCapturePLineTableID);
            }
        } else {
            AE_LOG( "[updateAEScenarioMode] setAEScene:%d, AE Pline table is NULL \n",m_eAEScene);
        }

        m_pPreviewTableCurrent = m_pPreviewTableNew;
        searchPreviewIndexLimit();
        //switchSensorModeMaxBVSensitivityDiff(MINT32 i4newSensorMode,MINT32 i4oldSensorMode,MINT32 & i4SenstivityDeltaIdx,MINT32 & i4BVDeltaIdx)
        m_pIAeAlgo->updateAEPlineInfo(m_pPreviewTableCurrent,m_pCaptureTable);
        m_pIAeAlgo->setEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
        m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);

    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getSensorMode() const
{
    return static_cast<MINT32>(m_eSensorMode);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAELock()
{
    AE_LOG( "[AeMgr::setAELock] m_bAELock: %d m_bAPAELock:%d m_bAFAELock:%d AEState:%d %d\n", m_bAELock, m_bAPAELock, m_bAFAELock, m_eAEState, m_ePreAEState);
    if((m_bAPAELock == MFALSE) && (m_bAFAELock == MFALSE)) {    // AE unlock
        m_bAELock = MFALSE;
        m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
        if (m_bAEMonitorStable == MTRUE){
            m_bAEMonitorStable = MFALSE;
            m_u4AEScheduleCnt = 0;
        }
    } else {    // AE lock
        m_bAELock = MTRUE;
        m_bOneShotAEBeforeLock = MTRUE;
    }

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->lockAE(m_bAELock);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }
    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAPAELock(MBOOL bAPAELock)
{
    if (m_bAPAELock != bAPAELock) {
        AE_LOG( "[AeMgr::setAPAELock] m_bAPAELock: %d -> %d\n", m_bAPAELock, bAPAELock);
        m_bAPAELock = bAPAELock;
        setAELock();
        if(m_bAPAELock == MFALSE) {    // AE unlock
            m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
        } else {    // AE lock
            m_ePreAEState = m_eAEState;
            m_eAEState = MTK_CONTROL_AE_STATE_LOCKED;
        }
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAFAELock(MBOOL bAFAELock)
{
    if (m_bAFAELock != bAFAELock) {
        AE_LOG( "[AeMgr::setAFAELock] m_bAFAELock: %d -> %d\n", m_bAFAELock, bAFAELock);
        m_bAFAELock = bAFAELock;
        setAELock();

        if (bAFAELock == MFALSE){
            if (m_strAECycleInfo.m_i4FrameCnt>=1){
                m_strAECycleInfo.m_i4FrameCnt = 6;
                MY_LOG("[AeMgr::SetAFAELock] AE reschedule \n");
            }
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setZoomWinInfo(MUINT32 u4XOffset, MUINT32 u4YOffset, MUINT32 u4Width, MUINT32 u4Height)
{

    if((u4XOffset >= 0)&&(u4XOffset <= 8192)&&(u4YOffset >= 0)&&(u4YOffset <= 8192)
        &&(u4Width > 0)&&(u4Width <= 16384)&&(u4Height > 0)&&(u4Height <= 16384)){
        if((m_eZoomWinInfo.u4XOffset != u4XOffset) || (m_eZoomWinInfo.u4XWidth != u4Width) ||
           (m_eZoomWinInfo.u4YOffset != u4YOffset) || (m_eZoomWinInfo.u4YHeight != u4Height)) {
            AE_LOG( "[AeMgr::setZoomWinInfo] New WinX:%d %d New WinY:%d %d Old WinX:%d %d Old WinY:%d %d\n", u4XOffset, u4Width, u4YOffset, u4Height,
                   m_eZoomWinInfo.u4XOffset, m_eZoomWinInfo.u4XWidth,
                   m_eZoomWinInfo.u4YOffset, m_eZoomWinInfo.u4YHeight);
            m_eZoomWinInfo.bZoomChange = MTRUE;
            m_eZoomWinInfo.u4XOffset = u4XOffset;
            m_eZoomWinInfo.u4XWidth = u4Width;
            m_eZoomWinInfo.u4YOffset = u4YOffset;
            m_eZoomWinInfo.u4YHeight = u4Height;
            if (m_bAEMonitorStable == MTRUE){
                m_bAEMonitorStable = MFALSE;
                m_u4AEScheduleCnt = 0;
            }
        }
    } else {
        AE_LOG( "[AeMgr::setZoomWinInfo] Wrong zoom window size %d/%d/%d/%d \n", u4XOffset, u4Width, u4YOffset, u4Height);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MUINT32 AeMgr::getAEMaxMeterAreaNum()
{
    return MAX_METERING_AREAS;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::enableAE()
{
    m_bEnableAE = MTRUE;

    AE_LOG( "enableAE()\n");
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::disableAE()
{
    m_bEnableAE = MFALSE;

    AE_LOG( "disableAE()\n");
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doPvAE(MINT32 i4FrameCount, MVOID *pAEStatBuf, MINT32 i4ActiveAEItem, MUINT32 u4AAOUpdate, MBOOL bAAASchedule)
{
strAEInput rAEInput;
strAEOutput rAEOutput;
AE_INFO_T rAEInfo2ISP;
MUINT32 u4DFpsThres = 0;
int bRestore=0;
MVOID *pAEStatisticBuf;
MUINT8 *pAEStaticBuf;
BufInfo_T rBufInfo;
mVHDRInputParam_T rInput;
mVHDROutputParam_T rOutput;
MBOOL bCalculateAE = MFALSE;
MBOOL bApplyAE = MFALSE;
MINT32 i4ActiveItem = 0;
MBOOL bAAOUpdate=0;
MBOOL bIsHDRflow =((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET));
    memset(&rAEOutput, 0, sizeof(strAEOutput));
    memset(&rAEInput , 0, sizeof(strAEInput ));

    if (m_u4HwMagicNum != u4AAOUpdate){
        m_u4HwMagicNum = u4AAOUpdate;
        bAAOUpdate = MTRUE;
    }
    m_bAEReadyCapture = MFALSE;  // reset capture flag
    m_bAECaptureUpdate = MFALSE;
    m_i4TimeOutCnt = MFALSE;  // reset timeout counter
    m_bFrameUpdate = MTRUE;
    m_strAECycleInfo.m_u4HwMagicNum = m_u4HwMagicNum;

    if(m_bAdbAEEnable == MTRUE) {
        char value[PROPERTY_VALUE_MAX] = {'\0'};
        property_get("vendor.debug.ae_mgr.lock", value, "0");
        m_bAdbAELock = atoi(value);
        property_get("vendor.debug.ae_mgr.log", value, "0");
        m_bAdbAELog = atoi(value);
        property_get("vendor.debug.ae_mgr.disableISP", value, "0");
        m_i4AdbAEISPDisable = atoi(value);    // 0 : No disable, 1 : Disable ISP gain to shutter, 2 : Disable ISP gain to sensor gain
        property_get("vendor.debug.ae_mgr.preview.update", value, "0");
        m_bAdbAEPreviewUpdate = atoi(value);
        property_get("vendor.debug.ae_mgr.disable.smooth", value, "0");
        m_bAdbAEDisableSmooth = atoi(value);
    }
    // Get mVHDR mode buffer address
    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
        // Dequeue AE DMA buffer
        // IAEBufMgr::getInstance().dequeueHwBuf(m_eSensorDev, rBufInfo);
        rInput.u4SensorID = 0; //TBD
        rInput.u4OBValue = 0;
        rInput.u4ISPGain = m_strIVHDROutputSetting.u4LEISPGain; //m_rAEOutput.rPreviewMode.u4IspGain;
        rInput.u2StatWidth = m_rSensorVCInfo.u2VCStatWidth;
        rInput.u2StatHight = m_rSensorVCInfo.u2VCStatHeight;
        if(m_rSensorVCInfo.u2VCModeSelect == 0) {
            rInput.u2ShutterRatio = m_rSensorVCInfo.u2VCShutterRatio;
        } else {
            if(m_strIVHDROutputSetting.u4SEExpTimeInUS != 0) {
                rInput.u2ShutterRatio = (m_strIVHDROutputSetting.u4LEExpTimeInUS + (m_strIVHDROutputSetting.u4SEExpTimeInUS >> 1)) / m_strIVHDROutputSetting.u4SEExpTimeInUS;
            } else {
                rInput.u2ShutterRatio = m_rSensorVCInfo.u2VCShutterRatio;
                AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d u4SEExpTimeInUS:%d\n", __FUNCTION__, m_eSensorDev, m_strIVHDROutputSetting.u4SEExpTimeInUS);
            }
        }
        rInput.u2ShutterRatio = m_rSensorVCInfo.u2VCShutterRatio;
        rInput.pDataPointer = reinterpret_cast<MVOID *>(pAEStatBuf);
        decodemVHDRStatistic(rInput, rOutput);
        bUpdateSensorAWBGain = rOutput.bUpdateSensorAWB;
        pAEStatisticBuf = reinterpret_cast<MVOID *>(rOutput.pDataPointer);
    } else {
        pAEStatisticBuf = pAEStatBuf;
    }

    if(m_pIAeAlgo != NULL) {
        if(pAEStatisticBuf != NULL) {
            Mutex::Autolock lock(m_Lock);
            // Set FDarea to algorithm
               if(m_bFaceAEAreaChage == MTRUE) {   // Face AE window change
                       AAA_TRACE_G(setAEFDArea);
                       AAA_TRACE_NL(setAEFDArea);
                   m_pIAeAlgo->setAEFDArea(&m_eAEFDArea);
                   AAA_TRACE_END_NL;
                   AAA_TRACE_END_G;
                  if (m_u4WOFDCnt > m_rAEInitInput.rAEPARAM.pFaceSmooth->u4FD_Lost_MaxCnt*3){
                   m_bFaceAEAreaChage = MFALSE;
                  }
                  m_u4WOFDCnt ++;
               }

            AaaTimer localTimer("AESatistic", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
            AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
            AAA_TRACE_G(setAESatisticBufferAddr);
            AAA_TRACE_NL(setAESatisticBufferAddr);
            m_pIAeAlgo->setAESatisticBufferAddr(pAEStatisticBuf, rCurrentIspAWBGain);
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
            localTimer.End();

            if((m_bIsAutoFlare == MTRUE) && (m_bRestoreAE == MFALSE)){
                if ((bAAASchedule == MTRUE) && ((i4ActiveAEItem & E_AE_AE_CALC) != E_AE_AE_CALC)){
                    //m_rAEOutput.rPreviewMode.i2FlareOffset = m_rAEOutput.rPreviewMode.i2FlareOffset;
                    AE_LOG( "[%s()] Flare for APPLY action \n",__FUNCTION__);
                }else{
                    MINT16 i2FlareOffset;
                    MINT16 i2FlareGain;
                    AaaTimer localTimer("DoPreFlare", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                    AAA_TRACE_G(DoPreFlare);
                    AAA_TRACE_NL(DoPreFlare);
                    m_pIAeAlgo->DoPreFlare(pAEStatisticBuf);
                    AAA_TRACE_END_NL;
                    AAA_TRACE_END_G;

                    AAA_TRACE_G(getPreviewFlare);
                    AAA_TRACE_NL(getPreviewFlare);
                    m_pIAeAlgo->getPreviewFlare(&i2FlareOffset,&i2FlareGain);
                    AAA_TRACE_END_NL;
                    AAA_TRACE_END_G;
                    m_rAEOutput.rPreviewMode.i2FlareOffset = i2FlareOffset;
                    AE_LOG_IF(bAAASchedule,"[%s()] Flare for CALC action %d/%d , %d/%d \n",__FUNCTION__, bAAASchedule, ((i4ActiveAEItem & E_AE_AE_CALC) != E_AE_AE_CALC), i4ActiveAEItem, E_AE_AE_CALC);
                }
                UpdateFlare2ISP();
                localTimer.End();
            }
        } else {
            AE_LOG( "[%s()] The AAO buffer pointer is NULL  i4SensorDev = %d line:%d u4AAOUpdate:%d i4ActiveAEItem:%d\n", __FUNCTION__, m_eSensorDev, __LINE__, u4AAOUpdate, i4ActiveAEItem);
        }
        // monitor AE state
        AAA_TRACE_G(getBrightnessCenterValue);
        AAA_TRACE_NL(getBrightnessCenterValue);
        monitorAndReschedule(bAAASchedule, m_pIAeAlgo->getBrightnessCenterWeightedValue(), m_u4StableYValue, &bCalculateAE, &bApplyAE);
        AAA_TRACE_END_NL;
        AAA_TRACE_END_G;

        // AE Auto Test
        if(m_bEnAutoTest) {
        if(m_u4ATType != AE_AT_TYPE_NON && m_u4ATType != AE_AT_TYPE_Pre2Cap) {
            AAA_TRACE_G(getBrightnessAvgValue);
            AAA_TRACE_NL(getBrightnessAvgValue);
            MUINT32 u4AvgYcur = m_pIAeAlgo->getBrightnessAverageValue();
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
            AE_LOG( "AE Auto Test - u4AvgYcur(%d) m_u4ATType(%d)\n", u4AvgYcur, m_u4ATType);
            switch(m_u4ATType) {
                case AE_AT_TYPE_ISO:
                    if ((u4AvgYcur<(m_u4ATYval-m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100))||(u4AvgYcur>(m_u4ATYval+m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100)))
                        AE_LOG( "AE Auto Test - ISO failed\n");
                    break;
                case AE_AT_TYPE_SCENE:
                    if ((u4AvgYcur<(m_u4ATYval-m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100))||(u4AvgYcur>(m_u4ATYval+m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100)))
                        AE_LOG( "AE Auto Test - Scene mode failed\n");
                    break;
                case AE_AT_TYPE_Pre2Video:
                    if ((u4AvgYcur<(m_u4ATYval-m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100))||(u4AvgYcur>(m_u4ATYval+m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100)))
                        AE_LOG( "AE Auto Test - Pre/Video failed\n");
                    break;
                case AE_AT_TYPE_EVCOMP:
                    if(m_u4ATCnt < (AE_AT_MAX_CNT_NUM-3)) {
                    if ((u4AvgYcur>(m_u4ATYval-m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100))&&(u4AvgYcur<(m_u4ATYval+m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100)))
                        AE_LOG( "AE Auto Test - EV comp failed\n");
                    }
                    break;
                default:
                    break;
            }
            m_u4ATCnt --;
            if(m_u4ATCnt <= 0) {
                m_u4ATCnt = 0;
                m_u4ATYval = 0;
                m_u4ATType = AE_AT_TYPE_NON;
                AE_LOG( "AE Auto Test - Reset type\n");
            }
        }
        }

        // When perframe and AE schedule is TRUE
        if((m_bPerframeAEFlag == MTRUE) && (bAAASchedule == MFALSE)&& (m_bEnSWBuffMode == MFALSE)) {
            if (bIsHDRflow){
                if (m_eAETargetMode == AE_MODE_MVHDR_TARGET){
                    m_bPerframeAEFlag = MFALSE;
                    AE_LOG("[%s()] This is non-Perframe HDR AE flow , mVHDR/HDRFlag:%d/%d \n",__FUNCTION__,(m_eAETargetMode == AE_MODE_MVHDR_TARGET),m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth );
                } else if (m_bTouchAEAreaChage == MTRUE){
                    if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth){
                        bCalculateAE  = MTRUE ;
                        bApplyAE = MTRUE ;
                    }else{
                m_bPerframeAEFlag = MFALSE;
                    }
                    AE_LOG("[%s()] This is Touch HDR AE flow, bPerframe:%d \n",__FUNCTION__,m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth);
                } else {
                    bCalculateAE  = MTRUE ;
                    bApplyAE = MTRUE ;
                    AE_LOG("[%s()] This is Perframe HDR AE flow \n",__FUNCTION__);
                }
            } else {
                if(m_bTouchAEAreaChage == MTRUE){
                    if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth){
                        bCalculateAE  = MTRUE ;
                        bApplyAE = MTRUE ;
                    }else{
                    m_bPerframeAEFlag = MFALSE;
                    }
                    AE_LOG( "[%s()] This is Touch AE flow, bPerframe:%d \n",__FUNCTION__,m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth);
                } else if (m_bAElimitor == MTRUE){
                    m_bPerframeAEFlag = MFALSE;
                    AE_LOG( "[%s()] This is Limiter AE flow \n",__FUNCTION__);
                } else {
                    bCalculateAE  = MTRUE ;
                    bApplyAE = MTRUE ;
                    AE_LOG_IF(m_3ALogEnable, "[%s()] This is Perframe AE flow \n",__FUNCTION__);
                }
            }
        } else {
            AE_LOG_IF(m_bPerframeAEFlag,"[%s()] Neither perframeAE and AEschedule (%d/%d) i4SensorDev = %d \n", __FUNCTION__,m_bPerframeAEFlag ,bAAASchedule , m_eSensorDev);
        }
        // AE schedule
        if(bAAASchedule == MFALSE) {
           i4ActiveItem = 0;
        } else {
           i4ActiveItem = i4ActiveAEItem;
           bCalculateAE  = MFALSE ;
           bApplyAE = MFALSE ;
           AAA_TRACE_G(getBrightnessCenterValue);
           AAA_TRACE_NL(getBrightnessCenterValue);
           AE_LOG( "[%s()] i4SensorDev = %d, schedule Calc/Apply = %d/%d , MagicNum = %d/%d , AAOUpdate = %d , CwvY = %d \n", __FUNCTION__,
            m_eSensorDev ,((i4ActiveItem & E_AE_AE_CALC)==E_AE_AE_CALC),((i4ActiveItem & E_AE_AE_APPLY)==E_AE_AE_APPLY),m_u4HwMagicNum,u4AAOUpdate,bAAOUpdate , m_pIAeAlgo->getBrightnessCenterWeightedValue());
           AAA_TRACE_END_NL;
             AAA_TRACE_END_G;
        }
        // per-frame control test
        if(m_u4AdbAEPerFrameCtrl) {
            AaaTimer localTimer("startSensorPerFrameControl", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
            startSensorPerFrameControl(m_u4AdbAEPerFrameCtrl);
            localTimer.End();
            m_bSetShutterValue = 0;
            m_bSetGainValue = 0;
            return S_AE_OK;
        }
    }else{
        AE_LOG( "[%s():1] The AE algo class is NULL  i4SensorDev = %d \n", __FUNCTION__, m_eSensorDev);
    }

    // Log out AE schedule
    AAA_TRACE_G(getBrightnessAvgValue);
    AAA_TRACE_NL(getBrightnessAvgValue);
    AE_LOG_IF(m_3ALogEnable,"[%s()][AEScheduler] AECalc:%d AEApply:%d AEFlare:%d VDnum:%d AvgY:%d\n", __FUNCTION__,
                            bCalculateAE     ,
                            bApplyAE    ,
                            1      ,
                            m_i4WaitVDNum                  ,
                            m_pIAeAlgo->getBrightnessAverageValue());
    AAA_TRACE_END_NL;
    AAA_TRACE_END_G;

    if(m_eAEMode == LIB3A_AE_MODE_OFF) {
        if (bAAASchedule == MFALSE)
            UpdateSensorISPParams(AE_SENSOR_PER_FRAME_STATE);
        else if(i4ActiveItem & E_AE_AE_APPLY)
            UpdateSensorISPParams(AE_SENSOR_PER_FRAME_STATE);
    } else if(m_bEnableAE) {
        if ((i4ActiveItem & E_AE_AE_CALC) || (bCalculateAE == MTRUE)) {
            if(m_bAELock || m_bAdbAELock) {
                if(m_bOneShotAEBeforeLock == MTRUE) {
                    rAEInput.eAeState = AE_STATE_AELOCK;
                    m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
                    m_bOneShotAEBeforeLock = MFALSE;
                } else {
                    rAEInput.eAeState = AE_STATE_AELOCK;
                    m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
                }
            }  else if(m_bAEOneShotControl == MTRUE) {
                rAEInput.eAeState = AE_STATE_ONE_SHOT;
                AE_LOG( "[%s()] AE_STATE_ONE_SHOT", __FUNCTION__);
            } else if(m_bTouchAEAreaChage == MTRUE) {
                if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth&&m_bPerframeAEFlag&&(!bAAASchedule))
                    rAEInput.eAeState = AE_STATE_TOUCH_PERFRAME;
                else
                rAEInput.eAeState = AE_STATE_ONE_SHOT;
                AE_LOG("[%s()] Enable per-frame AE for touch:%d\n", __FUNCTION__,m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth);
            } else if ((bAAASchedule == MTRUE)||(bIsHDRflow)||(m_bEnSWBuffMode == MTRUE)){
                if ((m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_bPerframeAEFlag == MFALSE)){
                rAEInput.eAeState = AE_STATE_SLOW_MOTION;
                AE_LOG( "[%s()] Stereo or VHDR or Slow Motion flow\n", __FUNCTION__);
                } else {
                    rAEInput.eAeState = AE_STATE_NORMAL_PREVIEW;
                }
            } else if (m_bAElimitor == MTRUE) {
                rAEInput.eAeState = AE_STATE_PANORAMA_MODE;
                AE_LOG( "[%s()] PANORAMA \n", __FUNCTION__);
            } else {
                rAEInput.eAeState = AE_STATE_NORMAL_PREVIEW;
            }

            if(m_eZoomWinInfo.bZoomChange == MTRUE) {
                if(m_pIAeAlgo != NULL) {
                    //m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight);
                    m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight, m_i4AETgValidBlockWidth, m_i4AETgValidBlockHeight);
                } else {
                    AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                }
                m_eZoomWinInfo.bZoomChange = MFALSE;
                // Update AE histogram window config
                ISP_MGR_AE_STAT_CONFIG_T::getInstance(m_eSensorDev).config(m_rAEStatCfg);
                AE_LOG( "[%s()] AE config change (Skip AeAlgo once)\n", __FUNCTION__);
            } else {
                rAEInput.pAESatisticBuffer = pAEStatisticBuf;
                rAEInput.eAeTargetMode = m_eAETargetMode;
                // Prepare perframe AE info to algorithm
                if (m_bPerframeAEFlag){
                    rAEInput.CycleInfo = m_strAECycleInfo;
                    for (int i=0; i< m_uEvQueueSize; i++) {
                        rAEInput.PreEvSetting[i] = m_PreEvSettingQueue[i];
                        rAEInput.u4PreAEidx[i] = m_u4PreAEidxQueue[i];
                        rAEInput.u4PreTgIntAEidx[i] = m_u4PreTgIntAEidxQueue[i];
                    }
                    AE_LOG_IF(m_3ALogEnable, "[%s():PassToAlgo] rAEInput.PreEvSetting[N-1]:%d/%d/%d rAEInput.PreEvSetting[N-2]:%d/%d/%d rAEInput.PreEvSetting[N-3]:%d/%d/%d FrameCnt(%d)\n", __FUNCTION__,
                            rAEInput.PreEvSetting[0].u4Eposuretime,
                            rAEInput.PreEvSetting[0].u4AfeGain    ,
                            rAEInput.PreEvSetting[0].u4IspGain    ,
                            rAEInput.PreEvSetting[1].u4Eposuretime,
                            rAEInput.PreEvSetting[1].u4AfeGain    ,
                            rAEInput.PreEvSetting[1].u4IspGain    ,
                            rAEInput.PreEvSetting[2].u4Eposuretime,
                            rAEInput.PreEvSetting[2].u4AfeGain    ,
                            rAEInput.PreEvSetting[2].u4IspGain    ,
                            rAEInput.CycleInfo.m_i4FrameCnt);
                    if(m_bTgIntAEEn && m_bPerframeAEFlag)
                    AE_LOG( "[%s():PassToAlgo-TG] u4PreAEidx[N-1]/[N-2]/[N-3]::%d/%d/%d u4PreTgIntAEidx[N-1]/[N-2]/[N-3]::%d/%d/%d FrameTgCnt(%d) HwMagicNum(%d)\n", __FUNCTION__,
                            rAEInput.u4PreAEidx[0], rAEInput.u4PreAEidx[1], rAEInput.u4PreAEidx[2],
                            rAEInput.u4PreTgIntAEidx[0], rAEInput.u4PreTgIntAEidx[1], rAEInput.u4PreTgIntAEidx[2],
                            rAEInput.CycleInfo.m_i4FrameTgCnt, rAEInput.CycleInfo.m_u4HwMagicNum);
                }
                if(m_pIAeAlgo != NULL) {
                    if(m_bRestoreAE == MFALSE) {
                        if ((m_bHDRshot == MFALSE)&&(m_u4HDRcountforrevert<1)){
                            if (m_u4HFSMSkipFrame == 0){
                                AaaTimer localTimer("handleAE", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                                AAA_TRACE_G(handleAE);
                                AAA_TRACE_NL(handleAE);
                                m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
                                AAA_TRACE_END_NL;
                                AAA_TRACE_END_G;
                                if((rAEInput.CycleInfo.m_i4FrameCnt != m_strAECycleInfo.m_i4FrameCnt)&&(m_bPerframeAEFlag))
                                {
                                  if(rAEInput.CycleInfo.m_i4FrameCnt>0)
                                     m_strAECycleInfo.m_i4FrameCnt = rAEInput.CycleInfo.m_i4FrameCnt;
                                  else
                                     AE_LOG("Wrong frameCnt:%d %d\n",m_strAECycleInfo.m_i4FrameCnt,rAEInput.CycleInfo.m_i4FrameCnt);
                                }
                                localTimer.End();
                                // Modify Evsetting (for current command setting)
                                copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
                            } else {
                                mPreviewMode = mPreviewModeBackup;
                                m_u4HFSMSkipFrame--;
                                AE_LOG( "[%s()] m_u4HFSMSkipFrame:%d , Backup:%d/%d/%d \n", __FUNCTION__,
                                        m_u4HFSMSkipFrame,
                                        mPreviewMode.u4Eposuretime,
                                        mPreviewMode.u4AfeGain,
                                        mPreviewMode.u4IspGain);
                                rAEOutput.bAEStable = MFALSE;
                            }
                        } else {
                            // m_rAEOutput.rPreviewMode = m_rAEOutput.rCaptureMode[0];
                            rAEOutput.bAEStable = MFALSE;
                            if (m_bHDRshot == MFALSE)
                                m_u4HDRcountforrevert--;
                            AE_LOG( "[IsHDRshot()] HDRshot/HDRcount = %d/%d",m_bHDRshot,m_u4HDRcountforrevert);
                        }
                        mPreviewMode = m_rAEOutput.rPreviewMode;
                        m_i4WaitVDNum = 0; // reset the delay frame
                        if((rAEInput.eAeState != AE_STATE_AELOCK)) {
                            m_bAEStable = rAEOutput.bAEStable;
                            m_bAEMonitorStable = m_bAEStable;

                            if(m_bTgIntAEEn && m_bPerframeAEFlag) { // update m_u4PreAEidxQueue[]
                                for (int i = m_uEvQueueSize - 2 ; i >= 0; i--){
                                    m_u4PreAEidxQueue[i+1]= m_u4PreAEidxQueue[i];
                                }
                                m_u4PreAEidxQueue[0] = m_i4AEidxNext;
                            }
                        }
                    } else {
                        if( (m_bPerframeAEFlag == MTRUE) && (rAEInput.CycleInfo.m_i4FrameCnt<(m_i4IspGainDelayFrames+2))){
                            m_bRestoreAE = MTRUE;
                        } else {
                            m_bRestoreAE = MFALSE;
                        }
                        bRestore=1;
                        AE_LOG( "Restore AE, skip AE one time\n");
                    }
                } else {
                    AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                }


                if(m_bAEStable == MTRUE) {
                    if(m_bAPAELock == MFALSE) {
                        if(m_bAFAELock == MTRUE){
                            m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
                        } else {
                            m_eAEState = MTK_CONTROL_AE_STATE_CONVERGED;
                        }
                    } else {
                        m_eAEState = MTK_CONTROL_AE_STATE_LOCKED;
                    }
                    if (m_bAFAELock == MFALSE){
                        AAA_TRACE_G(getBrightnessCenterValue);
                        AAA_TRACE_NL(getBrightnessCenterValue);
                        m_u4StableYValue = m_pIAeAlgo->getBrightnessCenterWeightedValue();
                        AAA_TRACE_END_NL;
                        AAA_TRACE_END_G;
                    }
                    if(m_bTouchAEAreaChage == MTRUE) {
                        m_bTouchAEAreaChage = MFALSE;
                        if (!m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth)
                            m_bPerframeAEFlag = MFALSE;
                        AE_LOG( "[%s()] Disable one shot for AE stable\n", __FUNCTION__);
                    }
                } else {
                    if (m_bAPAELock == MTRUE)
                        m_eAEState = MTK_CONTROL_AE_STATE_LOCKED;
                    else
                        m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
                }
                if(m_bLockExposureSetting == MTRUE) {
                    AE_LOG( "[doPvAE] Lock sensor setting:%d\n", m_bLockExposureSetting);
                    return S_AE_OK;
                }
                if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)){   // apply AE
                    if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)) {
                        UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
                        if ((m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth)&&((m_eAETargetMode == AE_MODE_ZVHDR_TARGET)||(m_eAETargetMode == AE_MODE_IVHDR_TARGET))){
                            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth;
                            updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                            m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                        }
                    } else {
                        if(bRestore == 0) {
                            UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
                            // Save to Evsetting Queue (for algorithm)
                            updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                            m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                        } else {
                            UpdateSensorISPParams(AE_AF_RESTORE_STATE);
                            m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                        }
                    }
                }
            }
        } else if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)) {   // apply AE
            if(m_pIAeAlgo != NULL) {
                AAA_TRACE_G(getBrightnessAvgValue);
                AAA_TRACE_NL(getBrightnessAvgValue);
                AE_LOG( "[%s()] i4SensorDev:%d AE Wait Vd frame:%d Enable:%d avgY:%d\n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum, m_bEnableAE, m_pIAeAlgo->getBrightnessAverageValue());
                AAA_TRACE_END_NL;
                AAA_TRACE_END_G;
                // continue update for preview or AF state
                if(bIsHDRflow) {
                    UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
                } else {
                    m_bPerframeAEFlag = MFALSE;
                    UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                    m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
                    // Save to Evsetting Queue (for algorithm)
                    updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                    m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;

                }
            }
        } else {
            AE_LOG_IF(m_3ALogEnable,"[%s()] i4SensorDev:%d AE idle command:%d\n", __FUNCTION__, m_eSensorDev, i4ActiveItem);
        }
    }else {
        AE_LOG( "[%s()] i4SensorDev:%d AE don't enable Enable:%d\n", __FUNCTION__, m_eSensorDev, m_bEnableAE);
    }

    if(m_bAdbAELog == MTRUE) {   // enable adb log
        MUINT8 uYvalue[AE_BLOCK_NO][AE_BLOCK_NO];

        AE_LOG( "[%s()] i4SensorDev:%d Shutter:%d Sensor Gain:%d ISP Gain:%d\n", __FUNCTION__, m_eSensorDev, m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain);

        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->getAEBlockYvalues(&uYvalue[0][0], AE_BLOCK_NO*AE_BLOCK_NO);
            AE_LOG( "i4SensorDev:%d block0:%d %d %d %d %d\n", m_eSensorDev, uYvalue[0][0], uYvalue[0][1], uYvalue[0][2], uYvalue[0][3], uYvalue[0][4]);
            AE_LOG( "i4SensorDev:%d block1:%d %d %d %d %d\n", m_eSensorDev, uYvalue[1][0], uYvalue[1][1], uYvalue[1][2], uYvalue[1][3], uYvalue[1][4]);
            AE_LOG( "i4SensorDev:%d block2:%d %d %d %d %d\n", m_eSensorDev, uYvalue[2][0], uYvalue[2][1], uYvalue[2][2], uYvalue[2][3], uYvalue[2][4]);
            AE_LOG( "i4SensorDev:%d block3:%d %d %d %d %d\n", m_eSensorDev, uYvalue[3][0], uYvalue[3][1], uYvalue[3][2], uYvalue[3][3], uYvalue[3][4]);
            AE_LOG( "i4SensorDev:%d block4:%d %d %d %d %d\n", m_eSensorDev, uYvalue[4][0], uYvalue[4][1], uYvalue[4][2], uYvalue[4][3], uYvalue[4][4]);

        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    }

    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
        // Enqueue AE DMA buffer
        IAEBufMgr::getInstance().enqueueHwBuf(m_eSensorDev, rBufInfo);

        // Update AE DMA base address for next frame
        IAEBufMgr::getInstance().updateDMABaseAddr(m_eSensorDev);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doPvAE_TG_INT(MVOID *pAEStatBuf)
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;
    MBOOL bRestore = MFALSE;
    MBOOL bValid   = MFALSE;

    if(m_strAECycleInfo.m_i4FrameCnt <= 0) {
        AE_LOG( "[%s()] waiting for sensor stability, skip calculation\n", __FUNCTION__);
        return S_AE_OK;
    }

    memset(&rAEOutput, 0, sizeof(strAEOutput));
    if (m_bTgIntAEEn && m_bPerframeAEFlag) {
        if(m_bEnableAE && (m_eAEMode!= LIB3A_AE_MODE_OFF)) {
            // Control eAeState to Algorithm
            if(m_bAELock || m_bAdbAELock) {
                if(m_bOneShotAEBeforeLock == MTRUE) {
                    rAEInput.eAeState = AE_STATE_AELOCK;
                    m_bOneShotAEBeforeLock = MFALSE;
                } else {
                    rAEInput.eAeState = AE_STATE_AELOCK;
                }
                AE_LOG( "[%s()] AE_STATE_AELOCK", __FUNCTION__);
            }  else if(m_bAEOneShotControl == MTRUE) {
                rAEInput.eAeState = AE_STATE_ONE_SHOT;
                AE_LOG( "[%s()] AE_STATE_ONE_SHOT", __FUNCTION__);
            } else if(m_bTouchAEAreaChage == MTRUE) {
                rAEInput.eAeState = AE_STATE_ONE_SHOT;
                AE_LOG( "[%s()] Enable one shot for touch AE enable:%d\n", __FUNCTION__, m_bTouchAEAreaChage);
            } else if ((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)||(m_bEnSWBuffMode == MTRUE)){
                rAEInput.eAeState = AE_STATE_SLOW_MOTION;
                AE_LOG( "[%s()] Stereo or VHDR or Slow Motion flow\n", __FUNCTION__);
            } else if (m_bAElimitor == MTRUE) {
                rAEInput.eAeState = AE_STATE_PANORAMA_MODE;
                AE_LOG( "[%s()] PANORAMA \n", __FUNCTION__);
            } else {
                rAEInput.eAeState = AE_STATE_NORMAL_PREVIEW;
            }

            // not normal preview, skip calculation
            if(rAEInput.eAeState != AE_STATE_NORMAL_PREVIEW) {
                AE_LOG( "[%s()] not normal preview, skip calculation\n", __FUNCTION__);
                return S_AE_OK;
            }

            AaaTimer localTimer("AAOTgSeparation", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
            aaoTgSeparation(pAEStatBuf, m_u4BlockNumX, m_u4BlockNumY, m_pAAOTgSeparatedBuf);
            localTimer.End();

            rAEInput.pAESatisticBuffer = m_pAAOTgSeparatedBuf;
            rAEInput.eAeTargetMode = m_eAETargetMode;

            rAEInput.CycleInfo = m_strAECycleInfo;
            for (int i=0; i< m_uEvQueueSize; i++){
                rAEInput.PreEvSetting[i] = m_PreEvSettingQueue[i];
                rAEInput.u4PreAEidx[i] = m_u4PreAEidxQueue[i];
                rAEInput.u4PreTgIntAEidx[i] = m_u4PreTgIntAEidxQueue[i];
            }

            // Call half-based AeAlgo
            if(m_pIAeAlgo != NULL) {
                if(m_bRestoreAE == MFALSE) {

                    bValid = m_pIAeAlgo->handleInterAE(&rAEInput, &rAEOutput);
                    if(bValid == MTRUE) {
                        AE_LOG_IF(m_3ALogEnable,"[%s():PassToAlgo] PreEvSetting[N-1]:%d/%d/%d PreEvSetting[N-2]:%d/%d/%d PreEvSetting[N-3]:%d/%d/%d FrameCnt(%d)\n", __FUNCTION__,
                                rAEInput.PreEvSetting[0].u4Eposuretime, rAEInput.PreEvSetting[0].u4AfeGain, rAEInput.PreEvSetting[0].u4IspGain,
                                rAEInput.PreEvSetting[1].u4Eposuretime, rAEInput.PreEvSetting[1].u4AfeGain, rAEInput.PreEvSetting[1].u4IspGain,
                                rAEInput.PreEvSetting[2].u4Eposuretime, rAEInput.PreEvSetting[2].u4AfeGain, rAEInput.PreEvSetting[2].u4IspGain,
                                rAEInput.CycleInfo.m_i4FrameCnt);
                        AE_LOG_IF(m_3ALogEnable,"[%s():PassToAlgo-TG] u4PreAEidx[N-1]/[N-2]/[N-3]::%d/%d/%d u4PreTgIntAEidx[N-1]/[N-2]/[N-3]::%d/%d/%d FrameTgCnt(%d) HwMagicNum(%d)\n", __FUNCTION__,
                                rAEInput.u4PreAEidx[0], rAEInput.u4PreAEidx[1], rAEInput.u4PreAEidx[2],
                                rAEInput.u4PreTgIntAEidx[0], rAEInput.u4PreTgIntAEidx[1], rAEInput.u4PreTgIntAEidx[2],
                                rAEInput.CycleInfo.m_i4FrameTgCnt, rAEInput.CycleInfo.m_u4HwMagicNum);
                        copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
                        // update m_u4PreTgIntAEidxQueue[]
                        for (int i = m_uEvQueueSize - 2 ; i >= 0; i--) {
                            m_u4PreTgIntAEidxQueue[i+1]= m_u4PreTgIntAEidxQueue[i];
                        }
                        m_u4PreTgIntAEidxQueue[0] = m_i4AEidxNext;
                    }
                } else{
                    bRestore = MTRUE;
                    AE_LOG( "[%s()] Restore AE, skip AE one time\n", __FUNCTION__);
                }
            } else {
                AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
            }

            // Send exposure settings
            if(bRestore == MFALSE) {
                if(bValid == MTRUE) {
                    // Sensor shutter & sensor gain
                    AaaTimer localTimer("SetShutterGain", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                    AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4Eposuretime);
                    AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4AfeGain);
                    localTimer.End();
                    // Isp gain
                    //IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, m_rAEOutput.rPreviewMode.u4IspGain>>1);
                    updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, m_rAEOutput.rPreviewMode.u4IspGain);

                    AE_LOG( "[%s] i4SensorDev:%d , Output %d/%d/%d \n", __FUNCTION__, m_eSensorDev,
                        m_rAEOutput.rPreviewMode.u4Eposuretime,
                        m_rAEOutput.rPreviewMode.u4AfeGain,
                        m_rAEOutput.rPreviewMode.u4IspGain);

                    if (m_strAECycleInfo.m_i4FrameCnt > 10) {
                        updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                    }
                }
                m_strAECycleInfo.m_i4FrameTgCnt ++;
            }
            else {
                AE_LOG( "[%s()] Restore AE, skip AE send command one time\n", __FUNCTION__);
            }

        }else {
            AE_LOG( "[%s()] i4SensorDev:%d AE don't enable Enable:%d\n", __FUNCTION__, m_eSensorDev, m_bEnableAE);
        }

        char value[PROPERTY_VALUE_MAX] = {'\0'};
        property_get("vendor.aao_tg_int.dump.enable", value, "0");
        MBOOL bEnable = atoi(value);

        if (bEnable) {
            char fileName[64];
            sprintf(fileName, "/sdcard/aao_tg_int/aao_%d.raw", m_strAECycleInfo.m_i4FrameTgCnt);
            FILE *fp = fopen(fileName, "w");
            if (NULL == fp)
            {
                CAM_LOGE("[%s()] fail to open file to save img: %s", __FUNCTION__, fileName);
                MINT32 err = mkdir("/sdcard/aao_tg_int", S_IRWXU | S_IRWXG | S_IRWXO);
                AE_LOG( "[%s()] err = %d", __FUNCTION__, err);
                return MFALSE;
            }
            AE_LOG( "[%s()] Dump AAO - fileName: %s, pAEStatBuf:[0x%x], AAO_STT_BLOCK_NUMX: %d, AAO_STT_BLOCK_NUMY: %d \n", __FUNCTION__, fileName, pAEStatBuf, AAO_STT_BLOCK_NUMX, AAO_STT_BLOCK_NUMY);
            fwrite(reinterpret_cast<void *>(pAEStatBuf), 1, AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY*8.5+4*AAO_STT_HIST_BIN_NUM*3, fp);
            fclose(fp);
        }

        if (bEnable) {
            char fileName[64];
            sprintf(fileName, "/sdcard/aao_tg_int/aao_y_%d.raw", m_strAECycleInfo.m_i4FrameTgCnt);
            FILE *fp = fopen(fileName, "w");
            if (NULL == fp)
            {
                CAM_LOGE("[%s()] fail to open file to save img: %s", __FUNCTION__, fileName);
                MINT32 err = mkdir("/sdcard/aao_tg_int", S_IRWXU | S_IRWXG | S_IRWXO);
                AE_LOG( "[%s()] err = %d", __FUNCTION__, err);
                return MFALSE;
            }
            fwrite(reinterpret_cast<void *>(m_pAAOTgSeparatedBuf), 1, AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY*2, fp);
            fclose(fp);
        }

    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doAFAEAAO(MVOID *pAEStatBuf, MUINT32 u4AAOUpdate)
{
MBOOL bAAOUpdate=0;
MVOID *pAEStatisticBuf;

    if (m_u4HwMagicNum != u4AAOUpdate){
            m_u4HwMagicNum = u4AAOUpdate;
            bAAOUpdate = MTRUE;
    }

    if(m_bEnableAE && (m_bAdbAELock == MFALSE)) {
        if((m_pIAeAlgo != NULL)&& (pAEStatBuf != NULL)) {
            pAEStatisticBuf = pAEStatBuf;
            AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
            AAA_TRACE_G(setAESatisticBufferAddr);
            AAA_TRACE_NL(setAESatisticBufferAddr);
            m_pIAeAlgo->setAESatisticBufferAddr(pAEStatisticBuf, rCurrentIspAWBGain);
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
        } else {
            AE_LOG( "[%s()] The AE algo class or AAO is NULL, i4SensorDev = %d \n", __FUNCTION__, m_eSensorDev);
        }
        if(m_pIAeAlgo != NULL) {
            AAA_TRACE_G(getBrightnessAvgValue);
            AAA_TRACE_NL(getBrightnessAvgValue);
        AE_LOG( "[monitorAndReschedule():doAFAEAAO] Cnt:%d Magic:%d Stable:%d AEMonitorStable:%d VdCnt:%d ISPdelay:%d FaceArea:%d FaceWOCnt:%d TouchArea:%d u4CwvYcur:%d u4CwvYpre:%d u4AvgYcur:%d\n",
                  m_u4AEScheduleCnt, m_u4HwMagicNum, m_bAEStable, m_bAEMonitorStable, m_i4WaitVDNum, m_i4IspGainDelayFrames,
                  m_bFaceAEAreaChage, m_u4WOFDCnt, m_bTouchAEAreaChage, m_pIAeAlgo->getBrightnessAverageValue(), m_u4StableYValue, m_pIAeAlgo->getBrightnessAverageValue());
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doAFAE(MINT32 i4FrameCount, MVOID *pAEStatBuf, MINT32 i4ActiveAEItem, MUINT32 u4AAOUpdate, MBOOL bAAASchedule)
{
strAEInput rAEInput;
strAEOutput rAEOutput;
AE_INFO_T rAEInfo2ISP;
MBOOL bCalculateAE = MFALSE;
MBOOL bApplyAE = MFALSE;
MINT32 i4ActiveItem;
MVOID *pAEStatisticBuf = NULL;
MBOOL bAAOUpdate=0;
MBOOL bIsHDRFlow= ((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET));

    memset(&rAEOutput, 0, sizeof(strAEOutput));
    AE_LOG( "[doAFAE]:%d %d frameCnt:%d ActiveAE:%d eAETargetMode:%d bTouchAEAreaChage:%d\n", m_i4TimeOutCnt, m_i4WaitVDNum, i4FrameCount, i4ActiveAEItem, m_eAETargetMode, m_bTouchAEAreaChage);
    if (m_u4HwMagicNum != u4AAOUpdate){
        m_u4HwMagicNum = u4AAOUpdate;
        bAAOUpdate = MTRUE;
    }
    if(m_i4TimeOutCnt > 18) {
        AE_LOG( "[doAFAE] Time out happen\n");
        if(m_bLockExposureSetting == MTRUE) {
            AE_LOG( "[doAFAE] Lock sensor setting:%d\n", m_bLockExposureSetting);
            return S_AE_OK;
        }
        //if (i4ActiveAEItem & E_AE_AE_APPLY) {   // apply AE
            m_rAEOutput.rAFMode = mPreviewMode;
            UpdateSensorISPParams(AE_AF_STATE);
        //}
        return S_AE_OK;
    } else {
        m_i4TimeOutCnt++;
    }

    if(m_bEnableAE && (m_bAdbAELock == MFALSE)) {
        if((m_pIAeAlgo != NULL)&& (pAEStatBuf != NULL)) {
            pAEStatisticBuf = pAEStatBuf;
            AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
            AAA_TRACE_G(setAESatisticBufferAddr);
            AAA_TRACE_NL(setAESatisticBufferAddr);
            m_pIAeAlgo->setAESatisticBufferAddr(pAEStatisticBuf, rCurrentIspAWBGain);
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d u4AAOUpdate:%d i4ActiveAEItem:%d\n", __FUNCTION__, m_eSensorDev, __LINE__, u4AAOUpdate, i4ActiveAEItem);
        }

        // monitor AE state
        AAA_TRACE_G(getBrightnessCenterValue);
        AAA_TRACE_NL(getBrightnessCenterValue);
        monitorAndReschedule(bAAASchedule, m_pIAeAlgo->getBrightnessCenterWeightedValue(), m_u4StableYValue, &bCalculateAE, &bApplyAE);
        AAA_TRACE_END_NL;
        AAA_TRACE_END_G;
        if(bAAASchedule == MFALSE) {
            i4ActiveItem = 0;
            if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth&&m_bPerframeAEFlag&&(!m_bAEReadyCapture)){
                bCalculateAE  = MTRUE ;
                bApplyAE = MTRUE ;
            }
        } else {
            i4ActiveItem = i4ActiveAEItem;
            AE_LOG( "[%s()] i4SensorDev = %d, schedule Calc/Apply = %d/%d , MagicNum = %d/%d \n", __FUNCTION__,
                m_eSensorDev ,((i4ActiveItem & E_AE_AE_CALC)==E_AE_AE_CALC),((i4ActiveItem & E_AE_AE_APPLY)==E_AE_AE_APPLY),m_u4HwMagicNum,u4AAOUpdate);
        }
        m_bAEStable = MFALSE;
        m_bAEMonitorStable = m_bAEStable;
        m_bTouchAEAreaChage = MFALSE;
        AAA_TRACE_G(getBrightnessAvgValue);
        AAA_TRACE_NL(getBrightnessAvgValue);
        AE_LOG_IF(m_bPerframeAEFlag,"[%s()][AEScheduler] AECalc:%d AEApply:%d AEFlare:%d VDnum:%d AvgY:%d\n", __FUNCTION__,
                            bCalculateAE     ,
                            bApplyAE    ,
                            1      ,
                            m_i4WaitVDNum                  ,
                            m_pIAeAlgo->getBrightnessAverageValue());
        AAA_TRACE_END_NL;
        AAA_TRACE_END_G;
        if ((i4ActiveItem & E_AE_AE_CALC)  || (bCalculateAE == MTRUE)) {
            if (bIsHDRFlow){
                m_bAEStable = MTRUE;
                m_bAEMonitorStable = m_bAEStable;
            } else {
                    if (m_bPerframeAEFlag){
                        rAEInput.CycleInfo = m_strAECycleInfo;
                        for (MINT32 i=0; i< m_uEvQueueSize; i++){
                            rAEInput.PreEvSetting[i] = m_PreEvSettingQueue[i];
                        }
                        AE_LOG("[%s():PassToAlgo] rAEInput.PreEvSetting[N-1]:%d/%d/%d rAEInput.PreEvSetting[N-2]:%d/%d/%d rAEInput.PreEvSetting[N-3]:%d/%d/%d rAEInput.CycleInfo.m_i4FrameCnt:%d\n", __FUNCTION__,
                            rAEInput.PreEvSetting[0].u4Eposuretime,
                            rAEInput.PreEvSetting[0].u4AfeGain    ,
                            rAEInput.PreEvSetting[0].u4IspGain    ,
                            rAEInput.PreEvSetting[1].u4Eposuretime,
                            rAEInput.PreEvSetting[1].u4AfeGain    ,
                            rAEInput.PreEvSetting[1].u4IspGain    ,
                            rAEInput.PreEvSetting[2].u4Eposuretime,
                            rAEInput.PreEvSetting[2].u4AfeGain    ,
                            rAEInput.PreEvSetting[2].u4IspGain    ,
                            rAEInput.CycleInfo.m_i4FrameCnt       );
                    }
                if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth && m_bPerframeAEFlag && (!bAAASchedule) &&(!m_bAEReadyCapture)){
                    rAEInput.eAeState = AE_STATE_TOUCH_PERFRAME;
                    AE_LOG("[doAFAE] AE_STATE_TOUCH_PERFRAME :%d\n",m_bPerframeAEFlag);
                }else{
                    rAEInput.eAeState = AE_STATE_ONE_SHOT;
                    AE_LOG( "[doAFAE] AE_STATE_ONE_SHOT\n");
                }
                rAEInput.pAESatisticBuffer = pAEStatisticBuf;
                rAEInput.eAeTargetMode = m_eAETargetMode;
                if(m_pIAeAlgo != NULL) {
                    AAA_TRACE_G(handleAE);
                    AAA_TRACE_NL(handleAE);
                    m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
                    AAA_TRACE_END_NL;
                    AAA_TRACE_END_G;
                } else {
                    AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                }
                if((rAEInput.CycleInfo.m_i4FrameCnt != m_strAECycleInfo.m_i4FrameCnt)&&(m_bPerframeAEFlag))
                {
                   if(rAEInput.CycleInfo.m_i4FrameCnt>0)
                       m_strAECycleInfo.m_i4FrameCnt = rAEInput.CycleInfo.m_i4FrameCnt;
                   else
                       AE_LOG("Wrong frameCnt:%d %d\n",m_strAECycleInfo.m_i4FrameCnt,rAEInput.CycleInfo.m_i4FrameCnt);
                }
                copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
                AE_LOG_IF(m_3ALogEnable,"[%s():AeAlgo output] Exp/Afe/Isp = %d/%d/%d",__FUNCTION__,m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                mPreviewMode = m_rAEOutput.rPreviewMode;
                m_i4WaitVDNum = 0; // reset the delay frame

                // AE is stable, change to AF state
                if(rAEOutput.bAEStable == MTRUE) {
                    rAEInput.eAeState = AE_STATE_AFASSIST;
                    if(m_pIAeAlgo != NULL) {
                        AAA_TRACE_G(handleAE);
                        AAA_TRACE_G(handleAE);
                        m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
                        AAA_TRACE_END_NL;
                        AAA_TRACE_END_G;
                    } else {
                        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                    }
                    copyAEInfo2mgr(&m_rAEOutput.rAFMode, &rAEOutput);
                    m_AEState = AE_AF_STATE;
                }

                if(m_bLockExposureSetting == MTRUE) {
                    AE_LOG( "[doCapAE] Lock sensor setting:%d\n", m_bLockExposureSetting);
                    return S_AE_OK;
                }
                // Using preview state to do AE before AE stable
                if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)) {   // apply AE
                    // continue update for preview or AF state
                    if(bIsHDRFlow) {
                        UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
                        if ((m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth)&&((m_eAETargetMode == AE_MODE_ZVHDR_TARGET)||(m_eAETargetMode == AE_MODE_IVHDR_TARGET))){
                            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth;
                            updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                            m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                        }
                    } else if(m_AEState == AE_AF_STATE) {
                        UpdateSensorISPParams(AE_AF_STATE);
                        updatePreEvSettingQueue(m_rAEOutput.rAFMode.u4Eposuretime,m_rAEOutput.rAFMode.u4AfeGain,m_rAEOutput.rAFMode.u4IspGain);
                        m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                    } else {
                        if (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTouchSmooth && (!bAAASchedule))
                            m_bPerframeAEFlag = MTRUE;
                        else
                            m_bPerframeAEFlag = MFALSE;
                        UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                        // Save to Evsetting Queue (for algorithm)
                        updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                        m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                        m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
                    }
                }
            }
        } else if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)) {   // apply AE
            if(m_pIAeAlgo != NULL) {
                AAA_TRACE_G(getBrightnessAvgValue);
                AAA_TRACE_NL(getBrightnessAvgValue);
                AE_LOG( "[%s()] i4SensorDev:%d AE Wait Vd frame:%d Enable:%d avgY:%d State:%d\n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum, m_bEnableAE, m_pIAeAlgo->getBrightnessAverageValue(), m_AEState);
                AAA_TRACE_END_NL;
                AAA_TRACE_END_G;
            }
            // continue update for preview or AF state
            if(bIsHDRFlow) {
                UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
            } else if(m_AEState == AE_AF_STATE) {
                UpdateSensorISPParams(AE_AF_STATE);
                updatePreEvSettingQueue(m_rAEOutput.rAFMode.u4Eposuretime,m_rAEOutput.rAFMode.u4AfeGain,m_rAEOutput.rAFMode.u4IspGain);
                m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
            } else {
                m_bPerframeAEFlag = MFALSE;
                UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                // Save to Evsetting Queue (for algorithm)
                updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime,m_rAEOutput.rPreviewMode.u4AfeGain,m_rAEOutput.rPreviewMode.u4IspGain);
                m_strAECycleInfo.m_i4FrameCnt = m_strAECycleInfo.m_i4FrameCnt + 1 ;
                m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
            }
        }
    } else {
        m_bAEStable = MTRUE;
        m_bAEMonitorStable = m_bAEStable;
        AE_LOG( "[%s()] i4SensorDev:%d AE don't enable Enable:%d\n", __FUNCTION__, m_eSensorDev, m_bEnableAE);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doPreCapAE(MINT32 i4FrameCount, MBOOL bIsStrobeFired, MVOID *pAEStatBuf, MINT32 i4ActiveAEItem, MUINT32 u4AAOUpdate, MBOOL bAAASchedule)
{
strAEInput rAEInput;
strAEOutput rAEOutput;
AE_INFO_T rAEInfo2ISP;
MVOID *pAEStatisticBuf;
BufInfo_T rBufInfo;
mVHDRInputParam_T rInput;
mVHDROutputParam_T rOutput;
MBOOL bCalculateAE = MFALSE;
MBOOL bApplyAE = MFALSE;
MINT32 i4ActiveItem;

    m_bTgIntAEEn = MFALSE;
    memset(&rAEOutput, 0, sizeof(strAEOutput));
    if (m_bEnableAE && (m_bAdbAELock == MFALSE))
    {
        if((m_bAEReadyCapture == MFALSE)||(m_bCShot == MTRUE)) {
            AE_LOG( "[%s()] i4SensorDev:%d Ready:%d isStrobe:%d TimeOut:%d\n", __FUNCTION__, m_eSensorDev, m_bAEReadyCapture, bIsStrobeFired, m_i4TimeOutCnt);
            if(((m_i4TimeOutCnt > 18)&&(m_bStrobeOn == MFALSE)&&(m_bCShot == MFALSE))||((m_i4TimeOutCnt > 35)&&((m_bCShot == MTRUE)||(m_bStrobeOn == MTRUE)))){
                AE_LOG( "[%s()] Time out happen\n", __FUNCTION__);
                if(m_bLockExposureSetting == MTRUE) {
                    AE_LOG( "[%s()] Lock sensor setting:%d\n", __FUNCTION__, m_bLockExposureSetting);
                    return S_AE_OK;
                }
                m_rAEOutput.rAFMode = m_rAEOutput.rPreviewMode;
                UpdateSensorISPParams(AE_AF_STATE);
                return S_AE_OK;
            } else {
                m_i4TimeOutCnt++;
            }

            //    AE_LOG( "%s() : AEMode:%d AEState:%d i4ActiveAEItem:%d u4AAOUpdate:%d\n", __FUNCTION__, m_eAEMode, m_eAEState, i4ActiveAEItem, u4AAOUpdate);
            if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
                // Dequeue AE DMA buffer
                // IAEBufMgr::getInstance().dequeueHwBuf(m_eSensorDev, rBufInfo);
                rInput.u4SensorID = 0; //TBD
                rInput.u4OBValue = 0;
                rInput.u4ISPGain = m_rAEOutput.rPreviewMode.u4IspGain;
                rInput.u2StatWidth = m_rSensorVCInfo.u2VCStatWidth;
                rInput.u2StatHight = m_rSensorVCInfo.u2VCStatHeight;
                rInput.u2ShutterRatio = m_rSensorVCInfo.u2VCShutterRatio;
                rInput.pDataPointer = reinterpret_cast<MVOID *>(pAEStatBuf);
                decodemVHDRStatistic(rInput, rOutput);
                bUpdateSensorAWBGain = rOutput.bUpdateSensorAWB;
                pAEStatisticBuf = reinterpret_cast<MVOID *>(rOutput.pDataPointer);
            } else {
                pAEStatisticBuf = pAEStatBuf;
            }

            if((m_bAEStable == MFALSE)||(m_bCShot == MTRUE)) {
                if((m_pIAeAlgo != NULL) && (pAEStatBuf != NULL) && ((u4AAOUpdate == 1) || (i4ActiveAEItem & E_AE_FLARE) || (i4ActiveAEItem & E_AE_AE_CALC))) {
                  AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
                  AAA_TRACE_G(setAESatisticBufferAddr);
                  AAA_TRACE_NL(setAESatisticBufferAddr);
                    m_pIAeAlgo->setAESatisticBufferAddr(pAEStatisticBuf, rCurrentIspAWBGain);
                    AAA_TRACE_END_NL;
                    AAA_TRACE_END_G;
                } else {
                    AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d u4AAOUpdate:%d i4ActiveAEItem:%d\n", __FUNCTION__, m_eSensorDev, __LINE__, u4AAOUpdate, i4ActiveAEItem);
                }

                // monitor AE state
                AAA_TRACE_G(getBrightnessCenterValue);
                AAA_TRACE_NL(getBrightnessCenterValue);
                monitorAndReschedule(bAAASchedule, m_pIAeAlgo->getBrightnessCenterWeightedValue(), m_u4StableYValue, &bCalculateAE, &bApplyAE);
                AAA_TRACE_END_NL;
                AAA_TRACE_END_G;
                if(bAAASchedule == MFALSE) {
                    i4ActiveItem = 0;
                } else {
                    i4ActiveItem = i4ActiveAEItem;
                }


                AAA_TRACE_G(getBrightnessAvgValue);
                AAA_TRACE_NL(getBrightnessAvgValue);
                AE_LOG_IF(m_bPerframeAEFlag,"[%s()][AEScheduler] AECalc:%d AEApply:%d AEFlare:%d VDnum:%d AvgY:%d\n", __FUNCTION__,
                            bCalculateAE     ,
                            bApplyAE    ,
                            1      ,
                            m_i4WaitVDNum                  ,
                            m_pIAeAlgo->getBrightnessAverageValue());
                AAA_TRACE_END_NL;
                AAA_TRACE_END_G;

                if ((i4ActiveItem & E_AE_AE_CALC) ||(bCalculateAE == MTRUE)){
                    AE_LOG( "[%s()] AE_STATE_ONE_SHOT\n", __FUNCTION__);
                    rAEInput.eAeState = AE_STATE_ONE_SHOT;
                    rAEInput.pAESatisticBuffer = pAEStatisticBuf;
                    rAEInput.eAeTargetMode = m_eAETargetMode;
                    if(m_pIAeAlgo != NULL) {
                        AAA_TRACE_G(handleAE);
                        AAA_TRACE_NL(handleAE);
                        m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
                        AAA_TRACE_END_NL;
                        AAA_TRACE_END_G;
                    } else {
                        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                    }
                    copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
                    m_i4WaitVDNum = 0; // reset the delay frame
                    mPreviewMode = m_rAEOutput.rPreviewMode;
                    if (m_bCShot == MTRUE){
                        m_bAEStable = rAEOutput.bAEStable;
                    }
                    if(m_bLockExposureSetting == MTRUE) {
                         m_bAEStable = MTRUE;
                         m_bAEMonitorStable = m_bAEStable;
                        AE_LOG( "[%s()] Lock sensor setting:%d\n", __FUNCTION__, m_bLockExposureSetting);
                        return S_AE_OK;
                    }
                    // AE is stable, update capture info
                    if(rAEOutput.bAEStable == MTRUE) {
                        UpdateSensorISPParams(AE_PRE_CAPTURE_STATE);
                        //doBackAEInfo();   // do back up AE for Precapture AF state.
                    } else if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)) {
                        // Using preview state to do AE before AE stable
                        if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)){
                            UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
                        } else {
                            m_bPerframeAEFlag = MFALSE;
                            UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
                        }
                    }
                } else if ((i4ActiveItem & E_AE_AE_APPLY) || (bApplyAE == MTRUE)) {   // apply AE
                    AE_LOG( "[%s()] i4SensorDev:%d AE Wait Vd frame:%d Enable:%d State:%d\n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum, m_bEnableAE, m_AEState);
                    // continue update for preview or AF state
                    if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)){
                            UpdateSensorISPParams(AE_TWO_SHUTTER_FRAME_STATE);
                    } else {
                            m_bPerframeAEFlag = MFALSE;
                            UpdateSensorISPParams(AE_AUTO_FRAMERATE_STATE);
                            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
                    }
               }
            } else {
                AE_LOG( "[%s()] AE stable already\n", __FUNCTION__);
                UpdateSensorISPParams(AE_PRE_CAPTURE_STATE);
                //doBackAEInfo();   // do back up AE for Precapture AF state.
            }

            if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
             // Enqueue AE DMA buffer
                IAEBufMgr::getInstance().enqueueHwBuf(m_eSensorDev, rBufInfo);

             // Update AE DMA base address for next frame
                IAEBufMgr::getInstance().updateDMABaseAddr(m_eSensorDev);
            }

            // AE Auto Test
            if(m_bEnAutoTest) {
                AAA_TRACE_G(getBrightnessAvgValue);
                AAA_TRACE_NL(getBrightnessAvgValue);
                m_u4ATYval = m_pIAeAlgo->getBrightnessAverageValue();
                AAA_TRACE_END_NL;
                AAA_TRACE_END_G;
                m_u4ATType = AE_AT_TYPE_Pre2Cap;
                AE_LOG( "AE Auto Test [AE_AT_TYPE_Pre2Cap]: m_u4ATYval(%d) thresh(%d) m_u4ATType(%d)\n", m_u4ATYval, AEAutoTestThreshTable[m_u4ATType], m_u4ATType);
            }

        } else {
            m_bAEStable = MTRUE;
            m_bAEMonitorStable = m_bAEStable;
            AE_LOG( "[%s()] i4SensorDev:%d Do Nothing Ready:%d isStrobe:%d\n", __FUNCTION__, m_eSensorDev, m_bAEReadyCapture, bIsStrobeFired);
        }
    } else {
        m_bAEStable = MTRUE;
        m_bAEMonitorStable = m_bAEStable;
        AE_LOG( "[%s()] AE don't enable Enable:%d\n", __FUNCTION__, m_bEnableAE);
    }

    m_eAEState = MTK_CONTROL_AE_STATE_PRECAPTURE;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAEState2Converge()
{
    AE_LOG( "[%s] Chage to converge state, Old state:%d\n", __FUNCTION__, m_eAEState);
    m_eAEState = MTK_CONTROL_AE_STATE_CONVERGED;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doCapAE()
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;
    memset(&rAEOutput, 0, sizeof(strAEOutput));

#if 0
    if(m_bLockExposureSetting == MTRUE) {
        AE_LOG( "[doCapAE] Lock sensor setting:%d\n", m_bLockExposureSetting);
        return S_AE_OK;
    }
#endif

    AE_LOG( "[%s()] i4SensorDev:%d CamMode:%d TargetMode:%d\n", __FUNCTION__, m_eSensorDev, m_eCamMode, m_eAETargetMode);

    if((m_bIsAutoFlare == FALSE) && (m_eSensorMode == ESensorMode_Capture)) {
            rAEInput.eAeState = AE_STATE_POST_CAPTURE;
            rAEInput.pAESatisticBuffer = NULL;
            AAA_TRACE_G(handleAE);
            AAA_TRACE_NL(handleAE);
            m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
            mCaptureMode.i2FlareOffset=rAEOutput.i2FlareOffset;
            mCaptureMode.i2FlareGain=rAEOutput.i2FlareGain;
            AE_LOG( "[%s()] i4SensorDev:%d Update flare offset :%d Flare Gain::%d\n", __FUNCTION__, m_eSensorDev, mCaptureMode.i2FlareOffset, mCaptureMode.i2FlareGain);
    }

    if ( (m_bStrobeOn == MFALSE) && (m_bRealISOSpeed == MTRUE) && (m_u4AEISOSpeed != (MUINT32) LIB3A_AE_ISO_SPEED_AUTO) ){
        updateEMISOCaptureParams(mCaptureMode);
    }
    if(((m_eCamMode == eAppMode_EngMode)||(m_bzcHDRshot == MTRUE)) && ((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET))) {   // engineer mode and target mode
        UpdateSensorISPParams(AE_TWO_SHUTTER_INIT_STATE);
    } else {
        if(m_bAdbAEPreviewUpdate) {
              mCaptureMode.u4Eposuretime = m_u4AdbAEShutterTime;
              mCaptureMode.u4AfeGain = m_u4AdbAESensorGain;
              mCaptureMode.u4IspGain = m_u4AdbAEISPGain;
        }
        UpdateSensorISPParams(AE_CAPTURE_STATE);
    }

    m_SensorQueueCtrl.uOutputIndex = m_SensorQueueCtrl.uInputIndex;

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
static int g_defaultFrameRate;
static int g_rExp;
static int g_rAfe;
static int g_rIsp;

static int g_rExpOn2;
static int g_rAfeOn2;
static int g_rIspOn2;

static int g_rIspAFLampOff;
static int g_rFrm;
static AE_MODE_CFG_T g_lastAFInfo;

int mapAFLampOffIsp2(int rollFrmTime, int exp, int afe, int isp, int expOn, int afeOn, int ispOn, int* expOn2=0, int* afeOn2=0, int* ispOn2=0)
{
  CAM_LOGD("AFLampExp, expOn: %d %d %d %d %d %d",exp, afe, isp, expOn, afeOn, ispOn);
  double rDif;
  rDif = (double)exp*afe*isp/expOn/afeOn/ispOn;

  double ispIncRat;
  if(rDif<1.2)
    ispIncRat=1.1;
  else if(rDif<1.5)
    ispIncRat=1.15;
  else if(rDif<2)
    ispIncRat=1.18;
  else
    ispIncRat=1.22;


  int rollFrameTime;

  int exp2;
  int afe2;
  int isp2;

  if(expOn2!=0)
    *expOn2 = expOn;
  if(afeOn2!=0)
    *afeOn2 = afeOn;

  double r;
  r = (rDif*exp)/ (rDif*(exp-rollFrmTime/2)+rollFrmTime/2);

  r = r*1.03;

  CAM_LOGD("AFLampExpp ispIncRat=%lf r=%lf", ispIncRat, r);

  r=1;

  return ispOn*r;
}

int mapAFLampOffIsp(int exp, int afe, int isp, int expOn, int afeOn, int ispOn)
{
  CAM_LOGD("AFLampExp, expOn: %d %d %d %d %d %d",exp, afe, isp, expOn, afeOn, ispOn);
  double rDif;
  rDif = (double)exp*afe*isp/expOn/afeOn/ispOn;

  double ispIncRat;
  if(rDif<1.2)
    ispIncRat=1.1;
  else if(rDif<1.5)
    ispIncRat=1.15;
  else if(rDif<2)
    ispIncRat=1.18;
  else
    ispIncRat=1.22;

  return ispOn*ispIncRat;
}

MRESULT AeMgr::doBackAEInfo()
{
strAEInput rAEInput;
strAEOutput rAEOutput;

    if(m_bEnableAE) {
        AE_LOG( "[%s()] i4SensorDev:%d\n", __FUNCTION__, m_eSensorDev);

        rAEInput.eAeState = AE_STATE_BACKUP_PREVIEW;
        rAEInput.pAESatisticBuffer = NULL;
        if(m_pIAeAlgo != NULL) {
            AAA_TRACE_G(handleAE);
            AAA_TRACE_NL(handleAE);
            m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
            AAA_TRACE_END_NL;
            AAA_TRACE_END_G;
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
    } else {
        AE_LOG( "[%s()] i4SensorDev:%d AE don't enable Enable:%d\n", __FUNCTION__, m_eSensorDev, m_bEnableAE);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void AeMgr::setExp(int exp)
{
    AE_LOG( "setExp(%d)",exp);
  AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, exp);
}
void AeMgr::setAfe(int afe)
{
    AE_LOG( "setAfe(%d)",afe);
  AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, afe);
}

void AeMgr::setIsp(int isp)
{
    AE_LOG( "setIsp(%d)",isp);
    AE_INFO_T rAEInfo2ISP;
    MUINT32 u4PreviewBaseGain=1024;
    MUINT32 u4PreviewBaseISO=100;

    if(m_pIAeAlgo != NULL) {
        AAA_TRACE_G(getAEInfoForISP);
        AAA_TRACE_NL(getAEInfoForISP);
        m_pIAeAlgo->getAEInfoForISP(rAEInfo2ISP);
        AAA_TRACE_END_NL;
        AAA_TRACE_END_G;
    }
    rAEInfo2ISP.i4GammaIdx = m_i4GammaIdx;
    rAEInfo2ISP.i4LESE_Ratio = m_i4LESE_Ratio;
    rAEInfo2ISP.u4SWHDR_SE = m_u4SWHDR_SE;
    rAEInfo2ISP.i4HdrSeg = m_i4HdrSeg;
    rAEInfo2ISP.i4HdrTurn = m_i4HdrTurn;
    rAEInfo2ISP.u4MaxISO = m_u4MaxISO*m_rAEPLineLimitation.u4IncreaseISO_x100/100;
    rAEInfo2ISP.u4AEStableCnt = m_u4StableCnt;
    rAEInfo2ISP.u4Eposuretime = m_rAEOutput.rPreviewMode.u4Eposuretime;
    rAEInfo2ISP.u4AfeGain = m_rAEOutput.rPreviewMode.u4AfeGain;
    rAEInfo2ISP.u4IspGain = isp;
    rAEInfo2ISP.u4RealISOValue = 100*((rAEInfo2ISP.u4AfeGain*isp)>>10)/1024;
    rAEInfo2ISP.u4EVRatio = m_rAEInitInput.rAEPARAM.pEVValueArray[m_eAEEVcomp];
    rAEInfo2ISP.bAEStable = m_bAEStable;
    rAEInfo2ISP.bAELock = m_bAELock;
    rAEInfo2ISP.bAELimiter = m_bAElimitor;
    rAEInfo2ISP.u4EISExpRatio = m_u4EISExpRatio;

    IspTuningMgr::getInstance().setAEInfo((ESensorDev_T)m_eSensorDev, rAEInfo2ISP);
    IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, isp>>1);
}

void AeMgr::setPfPara(int exp, int afe, int isp)
{
    AE_LOG( "setPfPara(%d/%d/%d)",exp, afe, isp);
    AE_INFO_T rAEInfo2ISP;
    if(m_pIAeAlgo != NULL) {
        AAA_TRACE_G(getAEInfoForISP);
        AAA_TRACE_NL(getAEInfoForISP);
        m_pIAeAlgo->getAEInfoForISP(rAEInfo2ISP);
        AAA_TRACE_END_NL;
        AAA_TRACE_END_G;
    }
    rAEInfo2ISP.i4GammaIdx = m_i4GammaIdx;
    rAEInfo2ISP.i4LESE_Ratio = m_i4LESE_Ratio;
    rAEInfo2ISP.u4SWHDR_SE = m_u4SWHDR_SE;
    rAEInfo2ISP.i4HdrSeg = m_i4HdrSeg;
    rAEInfo2ISP.i4HdrTurn = m_i4HdrTurn;
    rAEInfo2ISP.u4MaxISO = m_u4MaxISO*m_rAEPLineLimitation.u4IncreaseISO_x100/100;
    rAEInfo2ISP.u4AEStableCnt = m_u4StableCnt;
    rAEInfo2ISP.u4Eposuretime = exp;
    rAEInfo2ISP.u4AfeGain = afe;
    rAEInfo2ISP.u4IspGain = isp;
    rAEInfo2ISP.u4RealISOValue = 100*((rAEInfo2ISP.u4AfeGain*isp)>>10)/1024;
    rAEInfo2ISP.u4EVRatio = m_rAEInitInput.rAEPARAM.pEVValueArray[m_eAEEVcomp];
    rAEInfo2ISP.bAEStable = m_bAEStable;
    rAEInfo2ISP.bAELock = m_bAELock;
    rAEInfo2ISP.bAELimiter = m_bAElimitor;
    rAEInfo2ISP.u4EISExpRatio = m_u4EISExpRatio;

    IspTuningMgr::getInstance().setAEInfo((ESensorDev_T)m_eSensorDev, rAEInfo2ISP);
    IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, isp>>1);
}

void AeMgr::setRestore(int frm)
{
    AE_LOG( "[setRestore] Frame =%d DelayFrm = %d %d %d\n", frm, m_i4ShutterDelayFrames, m_i4SensorGainDelayFrames, m_i4IspGainDelayFrames);
    int expSetFrm;
    int afeSetFrm;
    int ispSetFrm;
    int minFrmDelay=0;
    minFrmDelay = m_i4ShutterDelayFrames;
    if(minFrmDelay>m_i4SensorGainDelayFrames)
      minFrmDelay=m_i4SensorGainDelayFrames;
    if(minFrmDelay>m_i4IspGainDelayFrames)
      minFrmDelay=m_i4IspGainDelayFrames;
    expSetFrm = m_i4ShutterDelayFrames-minFrmDelay;
    afeSetFrm = m_i4SensorGainDelayFrames-minFrmDelay;
    ispSetFrm = m_i4IspGainDelayFrames-minFrmDelay;


    AE_LOG( "[setRestore] exp,afe,isp setFrame %d %d %d\n", expSetFrm, afeSetFrm, ispSetFrm );
    // Set Exposure time
    if(frm==expSetFrm) //on exp
    {
      AE_LOG( "setExp frm0");
      setExp(g_rExp);
    }
    // Set Afe gain
    if(frm==afeSetFrm) //on afe
    {
      AE_LOG( "setAfe frm0");
      if (!m_pSensorGainThread){  // 0/0/2 sensor
          setAfe(g_rAfe);
      } else {                    // 0/1/2 sensor
          ThreadSensorGain::Cmd_T rCmd(0, 0, g_rAfe, m_eSensorTG);
          m_pSensorGainThread->postCmd(&rCmd);
      }
    }
    // Set ISP gain
    if(frm==ispSetFrm) //on isp
    {
      AE_LOG( "setIsp frm0");
      setIsp(g_rIsp);
    }
    // for Perframe control
    updatePreEvSettingQueue(g_rExp,g_rAfe,g_rIsp);
    updatePreEvSettingQueue(g_rExp,g_rAfe,g_rIsp);
    updatePreEvSettingQueue(g_rExp,g_rAfe,g_rIsp);
    m_strAECycleInfo.m_i4FrameCnt = 0;
    m_strAECycleInfo.m_i4FrameTgCnt = 0;
    m_strAECycleInfo.m_u4HwMagicNum = 0;

}


MRESULT AeMgr::doRestoreAEInfo(MBOOL bRestorePrvOnly)
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;

    if(m_bEnableAE) {
        AE_LOG( "[%s()] i4SensorDev:%d bRestorePrvOnly:%d\n", __FUNCTION__, m_eSensorDev, bRestorePrvOnly);
        rAEInput.eAeState = AE_STATE_RESTORE_PREVIEW;
        rAEInput.pAESatisticBuffer = NULL;
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
            m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
        copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
        AE_LOG( "[getPreviewParams3] Preview Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                   m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain,
                   m_rAEOutput.rPreviewMode.u4IspGain, m_rAEOutput.rPreviewMode.u2FrameRate, m_rAEOutput.rPreviewMode.i2FlareGain, m_rAEOutput.rPreviewMode.i2FlareOffset, m_rAEOutput.rPreviewMode.u4RealISO);

        g_rExp = m_rAEOutput.rPreviewMode.u4Eposuretime;
        g_rAfe = m_rAEOutput.rPreviewMode.u4AfeGain;
        g_rIsp = m_rAEOutput.rPreviewMode.u4IspGain;

        mPreviewMode = m_rAEOutput.rPreviewMode;

        m_u4PreExposureTime = m_rAEOutput.rPreviewMode.u4Eposuretime;
        m_u4PreSensorGain = m_rAEOutput.rPreviewMode.u4AfeGain;
        m_u4UpdateShutterValue = m_rAEOutput.rPreviewMode.u4Eposuretime;
        m_u4UpdateGainValue = m_rAEOutput.rPreviewMode.u4AfeGain;

        if(bRestorePrvOnly == MFALSE) {
            prepareCapParams();

            int rollFrmTime;
            if(m_eAECamMode == LIB3A_AECAM_MODE_ZSD)
                rollFrmTime = 66000;
            else
                rollFrmTime = 33000;

            g_rIspAFLampOff = mapAFLampOffIsp2(rollFrmTime, g_rExp, g_rAfe, g_rIsp,
                                         m_rAEOutput.rAFMode.u4Eposuretime, m_rAEOutput.rAFMode.u4AfeGain, m_rAEOutput.rAFMode.u4IspGain);
        }

        //m_i4WaitVDNum = m_i4IspGainDelayFrames + 2;
        m_bAEMonitorStable = MFALSE;  // AE monitor - Calculate apply
        m_u4AEScheduleCnt = 0; // AE monitor - Calculate apply
        m_bRestoreAE = MTRUE; // restore AE
    }else {
        AE_LOG( "[%s()] i4SensorDev:%d AE don't enable Enable:%d\n", __FUNCTION__, m_eSensorDev, m_bEnableAE);
    }
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::doCapFlare(MVOID *pAEStatBuf, MBOOL bIsStrobe)
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;
    AE_MODE_CFG_T a_rCaptureInfo;
    MVOID* pAEStatisticBuf;

    if(!m_bTgIntAEEn)
        m_bTgIntAEEn = m_rAEInitInput.rAEPARAM.bTgIntAEEn;
    if((m_bIsAutoFlare == FALSE) || (m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET)){
        AE_LOG( "[%s()] i4SensorDev:%d Using predict flare:m_bIsAutoFlare:%d m_eAETargetMode:%d\n", __FUNCTION__, m_eSensorDev, m_bIsAutoFlare, m_eAETargetMode);
        return S_AE_OK;
    }

    if((m_pIAeAlgo != NULL)&&(pAEStatBuf != NULL)) {
        pAEStatisticBuf = pAEStatBuf;
        AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
        m_pIAeAlgo->setAESatisticBufferAddr(pAEStatisticBuf, rCurrentIspAWBGain);
        m_pIAeAlgo->CalculateCaptureFlare(pAEStatisticBuf,bIsStrobe);

        rAEInput.eAeState = AE_STATE_POST_CAPTURE;
        rAEInput.pAESatisticBuffer = NULL;
        m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
        mCaptureMode.i2FlareOffset=rAEOutput.i2FlareOffset;
        mCaptureMode.i2FlareGain=rAEOutput.i2FlareGain;

        // AE Auto Test
        if(m_bEnAutoTest) {
        if(m_u4ATType == AE_AT_TYPE_Pre2Cap) {
            MUINT32 u4AvgYcur = m_pIAeAlgo->getBrightnessAverageValue();
            AE_LOG( "AE Auto Test - u4AvgYcur(%d) m_u4ATType(%d)\n", u4AvgYcur, m_u4ATType);
            if ((u4AvgYcur<(m_u4ATYval-m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100))||(u4AvgYcur>(m_u4ATYval+m_u4ATYval*AEAutoTestThreshTable[m_u4ATType]/100)))
                AE_LOG( "AE Auto Test - Pre/Cap failed\n");
            m_u4ATCnt = 0;
            m_u4ATYval = 0;
            m_u4ATType = AE_AT_TYPE_NON;
            AE_LOG( "AE Auto Test - Reset type\n");
        }
        }
    }

    if(m_bStrobeOn == TRUE) {
        if(m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableStrobeThres == MFALSE) {
            mCaptureMode.i2FlareOffset = m_rAEInitInput.rAENVRAM.rCCTConfig.u4StrobeFlareOffset;
            mCaptureMode.i2FlareGain = (MINT16)(FLARE_SCALE_UNIT * FLARE_OFFSET_DOMAIN / (FLARE_OFFSET_DOMAIN  - m_rAEInitInput.rAENVRAM.rCCTConfig.u4StrobeFlareOffset));
        }
    } else if(m_eSensorMode == ESensorMode_Video) {
        if(m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableVideoThres == MFALSE) {
            mCaptureMode.i2FlareOffset = m_rAEInitInput.rAENVRAM.rCCTConfig.u4VideoFlareOffset;
            mCaptureMode.i2FlareGain = (MINT16)(FLARE_SCALE_UNIT * FLARE_OFFSET_DOMAIN / (FLARE_OFFSET_DOMAIN  - m_rAEInitInput.rAENVRAM.rCCTConfig.u4VideoFlareOffset));
        }
    } else {
        if(m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableCaptureThres == MFALSE) {
            mCaptureMode.i2FlareOffset = m_rAEInitInput.rAENVRAM.rCCTConfig.u4CaptureFlareOffset;
            mCaptureMode.i2FlareGain = (MINT16)(FLARE_SCALE_UNIT * FLARE_OFFSET_DOMAIN / (FLARE_OFFSET_DOMAIN  - m_rAEInitInput.rAENVRAM.rCCTConfig.u4CaptureFlareOffset));
        }
    }
    AE_LOG( "[%s()] i4SensorDev:%d i2FlareOffset:%d i2FlareGain:%d Sensor Mode:%d Strobe:%d Enable:%d %d %d avgY:%d\n", __FUNCTION__, m_eSensorDev,
                   mCaptureMode.i2FlareOffset, mCaptureMode.i2FlareGain, m_eSensorMode, m_bStrobeOn, m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableCaptureThres,
                   m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableVideoThres, m_rAEInitInput.rAENVRAM.rCCTConfig.bEnableStrobeThres, m_pIAeAlgo->getBrightnessAverageValue());

    UpdateSensorISPParams(AE_POST_CAPTURE_STATE);

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getLVvalue(MBOOL isStrobeOn)
{
    if(isStrobeOn == MTRUE) {
        return (m_BVvalue + 50);
    } else {
        return (m_BVvalueWOStrobe + 50);
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAOECompLVvalue(MBOOL isStrobeOn)
{

    if(isStrobeOn == MTRUE) {
        return (m_BVvalue + 50);
    } else {
        return (m_AOECompBVvalue + 50);
    }
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getCaptureLVvalue()
{
    MINT32 i4LVValue_10x = 0;

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->CalculateCaptureLV(&i4LVValue_10x);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    return (i4LVValue_10x);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getDebugInfo(AE_DEBUG_INFO_T &rAEDebugInfo, AE_PLINE_DEBUG_INFO_T &rAEPlineDebugInfo)
{
MINT32 u4AEPlineInfoSize, u4AEPlineMappingSize, u4AFTableSize, u4GainTableSize;
AE_EASYTUNING_PLINE_INFO_T rEasytuningTable;
MINT32 i4LVValue_10x = 0;

    if(m_pIAeAlgo != NULL) {
        AE_LOG_IF(m_3ALogEnable,"[%s()] i4SensorDev:%d\n", __FUNCTION__, m_eSensorDev);
        rAEPlineDebugInfo.u4Size = sizeof(AE_PLINE_DEBUG_INFO_T);
        rAEPlineDebugInfo.u4IsTrue = MTRUE;
        m_pIAeAlgo->CalculateCaptureLV(&i4LVValue_10x);
        m_pIAeAlgo->getDebugInfo(rAEDebugInfo);
        u4AEPlineInfoSize = sizeof(m_pAEPlineTable->AEPlineInfo);
        u4AEPlineMappingSize = sizeof(strAESceneMapping);
        u4AFTableSize = sizeof(m_rAEInitInput.rAEPARAM.strAFPLine);
        u4GainTableSize = sizeof(m_pAEPlineTable->AEGainList);
        AE_LOG_IF(m_3ALogEnable,"[getDebugInfo] TotalSize:%d AEPlineInfoSize:%d Mapping:%d AFTable:%d u4GainTableSize:%d\n", rAEPlineDebugInfo.u4Size, u4AEPlineInfoSize, u4AEPlineMappingSize, u4AFTableSize, u4GainTableSize);
        memcpy(&(rEasytuningTable.AEPLineInfomation), &(m_pAEPlineTable->AEPlineInfo), u4AEPlineInfoSize);
        memcpy(&(rEasytuningTable.AEPLineMapping), &(m_pAEPlineTable->sAEScenePLineMapping), u4AEPlineMappingSize);
        memcpy(&(rEasytuningTable.normalAFPlineInfo), &(m_rAEInitInput.rAEPARAM.strAFPLine), u4AFTableSize);
        memcpy(&(rEasytuningTable.ZSDAFPlineInfo), &(m_rAEInitInput.rAEPARAM.strAFZSDPLine), u4AFTableSize);
        memcpy(&(rEasytuningTable.AEPLineGainList), &(m_pAEPlineTable->AEGainList), u4GainTableSize);
        if(sizeof(rAEPlineDebugInfo.PlineInfo) >= sizeof(rEasytuningTable)) {
            memcpy(&rAEPlineDebugInfo.PlineInfo[0], &rEasytuningTable, sizeof(rEasytuningTable));
        } else {
            memcpy(&rAEPlineDebugInfo.PlineInfo[0], &rEasytuningTable, sizeof(rAEPlineDebugInfo.PlineInfo));
        }
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    if(strlen(mEngFileName)!=0) {
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->SaveAeCoreInfo(mEngFileName);
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::getAENvramData(AE_NVRAM_T &rAENVRAM)
{
    AE_LOG( "[%s()] i4SensorDev:%d\n", __FUNCTION__, m_eSensorDev);
    if(m_p3ANVRAM == NULL) {
        CAM_LOGE("Nvram 3A pointer NULL\n");
    } else {
        rAENVRAM = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx];
    }

    return MTRUE;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::copyAEInfo2mgr(AE_MODE_CFG_T *sAEOutputInfo, strAEOutput *sAEInfo)
{
MUINT32 u4Shutter;
MUINT32 u4SensorGain;
MUINT32 u4ISPGain;
MUINT32 u4FinalGain;
MUINT32 u4PreviewBaseGain=1024;
MUINT32 u4PreviewBaseISO=100;
MUINT32 u4ISOValue;
AE_EXP_GAIN_MODIFY_T rSensorInputData, rSensorOutputData;

    sAEOutputInfo->u4CWValue = (MUINT16)sAEInfo->u4CWValue; // for N3D sync

    if(((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET)) && ( m_eCamMode == eAppMode_EngMode || m_bAEReadyCapture == MFALSE)){
        if(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)
            updatePreviewParamsByzVHDR(sAEInfo);
        else
            updatePreviewParamsByiVHDR(sAEInfo);

        sAEOutputInfo->u4Eposuretime = m_strIVHDROutputSetting.u4LEExpTimeInUS;
        sAEOutputInfo->u4AfeGain = m_strIVHDROutputSetting.u4LESensorGain;
        sAEOutputInfo->u4IspGain = m_strIVHDROutputSetting.u4LEISPGain;
        m_i4LESE_Ratio = m_strIVHDROutputSetting.u4LE_SERatio_x100;   // for HDR LE/SE ratio
        m_u4EISExpRatio = 100*m_strIVHDROutputSetting.u4LEExpTimeInUS/m_strIVHDROutputSetting.u4SEExpTimeInUS;
    } else {
        char value[PROPERTY_VALUE_MAX] = {'\0'};
        property_get("vendor.debug.ae_mgr.bufctrl", value, "0");
        // m_bEnSWBuffMode = atoi(value);
        u4Shutter = sAEInfo->EvSetting.u4Eposuretime;
        u4SensorGain = sAEInfo->EvSetting.u4AfeGain;
        u4ISPGain = sAEInfo->EvSetting.u4IspGain;

        if(m_bAdbAEPreviewUpdate) {
            char value[PROPERTY_VALUE_MAX] = {'\0'};

            property_get("vendor.debug.ae_mgr.shutter", value, "0");
            m_u4AdbAEShutterTime = atoi(value);
            property_get("vendor.debug.ae_mgr.sensorgain", value, "0");
            m_u4AdbAESensorGain = atoi(value);
            property_get("vendor.debug.ae_mgr.ispgain", value, "0");
            m_u4AdbAEISPGain = atoi(value);
            u4Shutter = m_u4AdbAEShutterTime;
            u4SensorGain = m_u4AdbAESensorGain;
            u4ISPGain = m_u4AdbAEISPGain;
            AE_LOG( "[%s()] i4SensorDev:%d Apply New Shutter:%d Sensor Gain:%d ISP Gain:%d m_bAdbAEPreviewUpdate:%d\n", __FUNCTION__, m_eSensorDev, m_u4AdbAEShutterTime, m_u4AdbAESensorGain, m_u4AdbAEISPGain, m_bAdbAEPreviewUpdate);
        }
        // Copy Sensor information to output structure
        if(m_i4AdbAEISPDisable) {
            AE_LOG( "[%s()] i4SensorDev:%d Old Shutter:%d Sensor Gain:%d ISP Gain:%d m_i4AdbAEISPDisable:%d\n", __FUNCTION__, m_eSensorDev, u4Shutter, u4SensorGain, u4ISPGain, m_i4AdbAEISPDisable);
            if(m_i4AdbAEISPDisable == 1) {  // Disable ISP gain to shutter
                sAEOutputInfo->u4Eposuretime = (u4Shutter*u4ISPGain) >> 10;
                sAEOutputInfo->u4AfeGain = u4SensorGain;
            } else {   // Disable ISP gain to sensor gain
                sAEOutputInfo->u4Eposuretime = u4Shutter;
                sAEOutputInfo->u4AfeGain = (u4SensorGain*u4ISPGain) >> 10;
            }
            sAEOutputInfo->u4IspGain = 1024;
            AE_LOG( "[%s()] i4SensorDev:%d Modify Shutter:%d Sensor Gain:%d ISP Gain:%d\n", __FUNCTION__, m_eSensorDev, u4Shutter, u4SensorGain, u4ISPGain);
        } else {
            sAEOutputInfo->u4Eposuretime = u4Shutter;
            sAEOutputInfo->u4AfeGain = u4SensorGain;
            sAEOutputInfo->u4IspGain = u4ISPGain;
        }
        m_i4LESE_Ratio = m_strIVHDROutputSetting.u4LE_SERatio_x100;   // No used for normal
    }

    // for 3DNR, no used for capture mode
    if((m_rAEPLineLimitation.bEnable == MTRUE) && (m_bAEReadyCapture == MFALSE)){
        if(m_rAEPLineLimitation.bEquivalent == MTRUE) {
            if(m_rAEPLineLimitation.u4IncreaseISO_x100 > 100) {
                //if(sAEOutputInfo->u4Eposuretime > (100*m_u4MaxShutter / m_rAEPLineLimitation.u4IncreaseISO_x100)) {
                    rSensorInputData.u4SensorExpTime = 100*m_u4MaxShutter / m_rAEPLineLimitation.u4IncreaseISO_x100;
                    rSensorInputData.u4SensorGain = sAEOutputInfo->u4Eposuretime * sAEOutputInfo->u4AfeGain / rSensorInputData.u4SensorExpTime;
                    rSensorInputData.u4IspGain = sAEOutputInfo->u4IspGain;
                    if(m_pIAeAlgo != NULL) {
                        m_pIAeAlgo->switchSensorExposureGain(MFALSE, rSensorInputData, rSensorOutputData);   // send to 3A to calculate the exposure time and gain
                    } else {
                        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                    }
                    AE_LOG( "[%s()] i4SensorDev:%d New Shutter:%d %d New Sesnor Gain:%d %d ISP Gain:%d %d\n", __FUNCTION__, m_eSensorDev,
                               rSensorOutputData.u4SensorExpTime, sAEOutputInfo->u4Eposuretime, rSensorOutputData.u4SensorGain,  sAEOutputInfo->u4AfeGain, rSensorOutputData.u4IspGain, sAEOutputInfo->u4IspGain);
                    sAEOutputInfo->u4Eposuretime = rSensorOutputData.u4SensorExpTime;
                    sAEOutputInfo->u4AfeGain = rSensorOutputData.u4SensorGain;
                    sAEOutputInfo->u4IspGain = rSensorOutputData.u4IspGain;
                //}
            } else if(m_rAEPLineLimitation.u4IncreaseISO_x100 < 100) {
                if(m_p3ANVRAM != NULL) {
                    u4PreviewBaseISO=m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
                } else {
                    AE_LOG( "[%s()] m_i4SensorDev:%d NVRAM data is NULL\n", __FUNCTION__, m_eSensorDev);
                }
                u4FinalGain = (sAEOutputInfo->u4AfeGain*sAEOutputInfo->u4IspGain)>>10 ;
                u4ISOValue = u4PreviewBaseISO*u4FinalGain/u4PreviewBaseGain;
                AE_LOG( "[%s()] u4ISOValue:%d m_u4MaxISO:%d Ratio:%d\n", __FUNCTION__, u4ISOValue, m_u4MaxISO, m_rAEPLineLimitation.u4IncreaseISO_x100);

                if(u4ISOValue > (m_u4MaxISO * m_rAEPLineLimitation.u4IncreaseISO_x100 / 100)) {
                    rSensorInputData.u4SensorGain = sAEOutputInfo->u4AfeGain * m_rAEPLineLimitation.u4IncreaseISO_x100 / 100;
                    rSensorInputData.u4SensorExpTime = sAEOutputInfo->u4Eposuretime * sAEOutputInfo->u4AfeGain / rSensorInputData.u4SensorGain;
                    rSensorInputData.u4IspGain = sAEOutputInfo->u4IspGain;
                    if(m_pIAeAlgo != NULL) {
                        m_pIAeAlgo->switchSensorExposureGain(MFALSE, rSensorInputData, rSensorOutputData);   // send to 3A to calculate the exposure time and gain
                    } else {
                        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
                    }
                    AE_LOG( "[%s()] i4SensorDev:%d New Shutter:%d %d New Sesnor Gain:%d %d ISP Gain:%d %d Ratio:%d\n", __FUNCTION__, m_eSensorDev,
                               rSensorOutputData.u4SensorExpTime, sAEOutputInfo->u4Eposuretime, rSensorOutputData.u4SensorGain,  sAEOutputInfo->u4AfeGain, rSensorOutputData.u4IspGain, sAEOutputInfo->u4IspGain, m_rAEPLineLimitation.u4IncreaseISO_x100);
                    sAEOutputInfo->u4Eposuretime = rSensorOutputData.u4SensorExpTime;
                    sAEOutputInfo->u4AfeGain = rSensorOutputData.u4SensorGain;
                    sAEOutputInfo->u4IspGain = rSensorOutputData.u4IspGain;
                }
            }
        } else {
            AE_LOG( "[%s()] i4SensorDev:%d No rquivalent, Please use AE Pline table:%d ISO:%d Shutter:%d\n", __FUNCTION__, m_eSensorDev, m_rAEPLineLimitation.bEnable, m_rAEPLineLimitation.u4IncreaseISO_x100, m_rAEPLineLimitation.u4IncreaseShutter_x100);
        }
    }

    if(sAEOutputInfo->u4IspGain < 1024) {
        AE_LOG( "[%s()] i4SensorDev:%d ISP gain too small:%d\n", __FUNCTION__, m_eSensorDev, sAEOutputInfo->u4IspGain);
        sAEOutputInfo->u4IspGain = 1024;
    }
    sAEOutputInfo->u2FrameRate = sAEInfo->u2FrameRate;
    sAEOutputInfo->u4RealISO = sAEInfo->u4ISO;

//    if(m_bIsAutoFlare == TRUE) {
        sAEOutputInfo->i2FlareOffset = sAEInfo->i2FlareOffset;
        sAEOutputInfo->i2FlareGain = sAEInfo->i2FlareGain;
//    } else {     // flare disable, don't update.
//        AE_LOG( "[%s()] i4SensorDev:%d i2FlareOffset:%d i2FlareGain:%d\n", __FUNCTION__, m_eSensorDev, sAEOutputInfo->i2FlareOffset, sAEOutputInfo->i2FlareGain);
//    }

    m_BVvalue = sAEInfo->Bv;
    m_AOECompBVvalue = sAEInfo->AoeCompBv;

    if(m_bStrobeOn == MFALSE) {
        m_BVvalueWOStrobe = sAEInfo->Bv;
    }

    m_i4EVvalue = sAEInfo->i4EV;
    m_i4DeltaBV = sAEInfo->i4DeltaBV;
    m_u4AECondition = sAEInfo->u4AECondition;
    m_i4AEidxCurrent = sAEInfo->i4AEidxCurrent;
    m_i4AEidxNext = sAEInfo->i4AEidxNext;
    m_i2AEFaceDiffIndex = sAEInfo->i2FaceDiffIndex;
    m_i4GammaIdx = sAEInfo->i4gammaidx;

    m_u4SWHDR_SE = ABS(sAEInfo->i4cHdrSEDeltaEV);      //for HDR SE ,  -x EV , compare with converge AE
    m_i4HdrSeg = sAEInfo->HdrEvSetting.i4RMGk;
    m_i4HdrTurn = sAEInfo->HdrEvSetting.i4RMGt;

    return S_3A_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getSensorResolution()
{
    MRESULT err = S_AE_OK;

    if ((m_eSensorDev == ESensorDev_Main) || (m_eSensorDev == ESensorDev_Sub)) {
        err = AAASensorMgr::getInstance().getSensorWidthHeight(m_eSensorDev, &m_rSensorResolution[0]);
    } else if((m_eSensorDev == ESensorDev_MainSecond) ||(m_eSensorDev == ESensorDev_SubSecond)){
        err = AAASensorMgr::getInstance().getSensorWidthHeight(m_eSensorDev, &m_rSensorResolution[1]);
    } else {
        CAM_LOGE("Error sensor device\n");
    }

    if (FAILED(err)) {
        CAM_LOGE("AAASensorMgr::getInstance().getSensorWidthHeight fail\n");
        return err;
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <nvbuf_util.h>
MRESULT AeMgr::getNvramData(MINT32 i4SensorDev, MBOOL isForce)
{
    AE_LOG( "[%s()] i4SensorDev:%d\n", __FUNCTION__, i4SensorDev);

    int err;
    err = NvBufUtil::getInstance().getBufAndRead(CAMERA_NVRAM_DATA_3A, i4SensorDev, (void*&)m_p3ANVRAM, isForce);
    if(err!=0)
        CAM_LOGE("Nvram 3A pointer NULL err=%d\n",err);

    strAEPLineTable sAEPlineTable;
    if(isForce == MTRUE) // fix me plz
        sAEPlineTable = ((AE_PLINETABLE_T*)m_pAEPlineTable)->AEPlineTable;

    err = NvBufUtil::getInstance().getBufAndRead(CAMERA_DATA_AE_PLINETABLE, i4SensorDev, (void*&)m_pAEPlineTable, isForce);
    if(err!=0)
        CAM_LOGE("Nvram AE Pline table pointer NULL err=%d\n",err);

    if(isForce == MTRUE) // fix me plz
    {
        for(int i = 0; i < MAX_PLINE_TABLE; i++)
        {
            ((AE_PLINETABLE_T*)m_pAEPlineTable)->AEPlineTable.sPlineTable[i].pCurrentTable = sAEPlineTable.sPlineTable[i].pCurrentTable;
        }
    }
    /*
    if (FAILED(NvramDrvMgr::getInstance().init(i4SensorDev))) {
         CAM_LOGE("NvramDrvMgr init fail\n");
         return E_AE_NVRAM_DATA;
    }

    NvramDrvMgr::getInstance().getRefBuf(m_p3ANVRAM);
    if(m_p3ANVRAM == NULL) {
         CAM_LOGE("Nvram 3A pointer NULL\n");
    }

    NvramDrvMgr::getInstance().getRefBuf(m_pAEPlineTable);
    if(m_pAEPlineTable == NULL) {
         CAM_LOGE("Nvram AE Pline table pointer NULL\n");
    }*/

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::AEInit(Param_T &rParam)
{
    strAEOutput rAEOutput;
    MINT32 i, j;
    unsigned long long u8initAEtimer;
    MBOOL brealAEinit = MFALSE;
    MBOOL bEnablePreIndex = MFALSE;

    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    u8initAEtimer = (unsigned long long)time.tv_sec*1000000000 + (unsigned long long)time.tv_nsec;
    brealAEinit=(u8initAEtimer>AEtimer+RealInitThrs)?MTRUE:MFALSE;
    AE_LOG( "[%s()] i4SensorDev:%d , AEtimer(uninit/init):%lld/%lld/%lld , bRealAEInit:%d \n", __FUNCTION__, m_eSensorDev, AEtimer, u8initAEtimer, u8initAEtimer-AEtimer, brealAEinit);

    if(m_p3ANVRAM != NULL) {
        m_rAEInitInput.rAENVRAM = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx];
    } else {
         CAM_LOGE("Nvram 3A pointer is NULL\n");
    }

    // Query TG info
    IHalSensorList* const pIHalSensorList = MAKE_HalSensorList();
    IHalSensor* pIHalSensor = pIHalSensorList->createSensor("ae_mgr", m_i4SensorIdx);
    SensorDynamicInfo rSensorDynamicInfo;

    switch(m_eSensorDev) {
        case ESensorDev_Main:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_MAIN, &rSensorDynamicInfo);
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_Main>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_Main>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_Main>();
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_Main>();
            }
            m_pIsAEActive = getAEActiveCycle<ESensorDev_Main>();
            m_bEnableAE = isAEEnabled<ESensorDev_Main>();
            m_i4AECycleNum = getAECycleNum<ESensorDev_Main>();
            m_rAEInitInput.eSensorDev = AE_SENSOR_MAIN;
            break;
        case ESensorDev_Sub:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_SUB, &rSensorDynamicInfo);
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_Sub>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_Sub>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_Sub>();
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_Sub>();
            }
            m_pIsAEActive = getAEActiveCycle<ESensorDev_Sub>();
            m_bEnableAE = isAEEnabled<ESensorDev_Sub>();
            m_i4AECycleNum = getAECycleNum<ESensorDev_Sub>();
            m_rAEInitInput.eSensorDev = AE_SENSOR_SUB;
            break;
        case ESensorDev_MainSecond:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_MAIN_2, &rSensorDynamicInfo);
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_MainSecond>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_MainSecond>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_MainSecond>();
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_MainSecond>();
            }
            m_pIsAEActive = getAEActiveCycle<ESensorDev_MainSecond>();
            m_bEnableAE = isAEEnabled<ESensorDev_MainSecond>();
            m_i4AECycleNum = getAECycleNum<ESensorDev_MainSecond>();
            m_rAEInitInput.eSensorDev = AE_SENSOR_MAIN2;
            break;
        case ESensorDev_SubSecond:
            pIHalSensor->querySensorDynamicInfo(NSCam::SENSOR_DEV_SUB_2, &rSensorDynamicInfo);
            // HDR params switch
            if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_ON){
                m_rAEInitInput.rAEPARAM = getHDRAEParam<ESensorDev_SubSecond>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_HDR_AUTO){
                m_rAEInitInput.rAEPARAM = getAUTOHDRAEParam<ESensorDev_SubSecond>();
            }else if (m_eAENVRAMIdx==AE_NVRAM_IDX_VT){
                m_rAEInitInput.rAEPARAM = getVTAEParam<ESensorDev_SubSecond>();
            }else{
                m_rAEInitInput.rAEPARAM = getAEParam<ESensorDev_SubSecond>();
            }
            m_pIsAEActive = getAEActiveCycle<ESensorDev_SubSecond>();
            m_bEnableAE = isAEEnabled<ESensorDev_SubSecond>();
            m_i4AECycleNum = getAECycleNum<ESensorDev_SubSecond>();
            m_rAEInitInput.eSensorDev = AE_SENSOR_SUB2;
            break;
        default:    //  Shouldn't happen.
            CAM_LOGE("Invalid sensor device: %d", m_eSensorDev);
    }

    if(pIHalSensor) {
        pIHalSensor->destroyInstance("ae_mgr");
    }

    AE_LOG( "TG = %d, pixel mode = %d\n", rSensorDynamicInfo.TgInfo, rSensorDynamicInfo.pixelMode);

    switch(rSensorDynamicInfo.TgInfo){
        case CAM_TG_1:
            m_eSensorTG = ESensorTG_1;
            break;
        case CAM_TG_2:
            m_eSensorTG = ESensorTG_2;
            break;
    }

    if(bApplyAEPlineTableByCCT == MTRUE) {   // update by CCT
        CAM_LOGE("AE Pline table update by CCT\n");
    } else if(m_pAEPlineTable != NULL) {
        m_rAEInitInput.rAEPlineTable = m_pAEPlineTable;

        // sensor table mapping
        for(j=0; j < MAX_PLINE_MAP_TABLE; j++) {
            for(i = 0; i < LIB3A_SENSOR_MODE_MAX; i++) {
                m_rAEInitInput.rAEPlineMapTable[j].eAEScene = m_pAEPlineTable->sAEScenePLineMapping.sAESceneMapping[j].eAEScene;
                m_rAEInitInput.rAEPlineMapTable[j].ePLineID[i] = m_pAEPlineTable->sAEScenePLineMapping.sAESceneMapping[j].ePLineID[i];
            }
            /*AE_LOG( "[%s()] %d Scene:%d Table:%d %d %d %d %d %d %d %d %d %d %d\n", __FUNCTION__, j, m_rAEInitInput.rAEPlineMapTable[j].eAEScene,
              m_rAEInitInput.rAEPlineMapTable[j].ePLineID[0], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[1], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[2],
              m_rAEInitInput.rAEPlineMapTable[j].ePLineID[3], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[4], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[5],
              m_rAEInitInput.rAEPlineMapTable[j].ePLineID[6], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[7], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[8],
              m_rAEInitInput.rAEPlineMapTable[j].ePLineID[9], m_rAEInitInput.rAEPlineMapTable[j].ePLineID[10]);*/
        }
    } else {
         CAM_LOGE("Nvram AE Pline table pointer is NULL\n");
    }

    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {
        m_rAEInitInput.i4AEMaxBlockWidth = m_rSensorVCInfo.u2VCStatWidth;
        m_rAEInitInput.i4AEMaxBlockHeight = m_rSensorVCInfo.u2VCStatHeight;
    } else {
        m_rAEInitInput.i4AEMaxBlockWidth = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumX;
        m_rAEInitInput.i4AEMaxBlockHeight = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumY;
    }
    // AAO buffer size for AEalgo
    m_u4BlockNumX = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumX;
    m_u4BlockNumY = m_rAEInitInput.rAEPARAM.strAEParasetting.u4AEWinodwNumY;
    m_u4AAOSepAWBsize  = 4*m_u4BlockNumX*m_u4BlockNumY;
    m_u4AAOSepAEsize   = sizeof(MUINT16)*m_u4BlockNumX*m_u4BlockNumY;
    m_u4AAOSepHistsize = sizeof(MUINT32)*4*AAO_STT_HIST_BIN_NUM;
    m_u4AAOSepOverCntsize = sizeof(MUINT16)*m_u4BlockNumX*m_u4BlockNumY;
    m_rAEInitInput.u4MGRSepAWBsize = m_u4AAOSepAWBsize;
    m_rAEInitInput.u4MGRSepAEsize = m_u4AAOSepAEsize;
    m_rAEInitInput.u4MGRSepHistsize = m_u4AAOSepHistsize;
    m_rAEInitInput.u4MGRSepOverCntsize = m_u4AAOSepOverCntsize;
    AE_LOG( "[AEInit] AAO separation size(To AeAlgo):%d/%d/%d/%d \n",
             m_u4AAOSepAWBsize, m_u4AAOSepAEsize, m_u4AAOSepHistsize, m_u4AAOSepOverCntsize);
    // ezoom info default
    m_eZoomWinInfo.u4XOffset = 0;
    m_eZoomWinInfo.u4YOffset = 0;
    m_eZoomWinInfo.u4XWidth = 2000;
    m_eZoomWinInfo.u4YHeight = 1000;
    m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
    m_rAEInitInput.rEZoomWin = m_eZoomWinInfo;
    m_rAEInitInput.eAEMeteringMode = m_eAEMeterMode;
    m_rAEInitInput.eAEScene = m_eAEScene;
    m_rAEInitInput.eAECamMode = m_eAECamMode;
    m_rAEInitInput.eAEFlickerMode = m_eAEFlickerMode;
    m_rAEInitInput.eAEAutoFlickerMode = m_eAEAutoFlickerMode;
    m_rAEInitInput.eAEEVcomp = m_eAEEVcomp;
    m_rAEInitInput.u4AEISOSpeed = m_u4AEISOSpeed;
    m_rAEInitInput.i4AEMaxFps = m_i4AEMaxFps;
    m_rAEInitInput.i4AEMinFps = m_i4AEMinFps;
    m_rAEInitInput.i4SensorMode = m_eSensorMode;
    m_rAEInitInput.eAETargetMode = m_eAETargetMode;
    m_rAEInitInput.i4AAOLineByte = (int)(m_u4BlockNumX*(5
                                                        +0.5*m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableHDRLSB
                                                        +1  *m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableAEOVERCNTconfig
                                                        +2  *m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableTSFSTATconfig) +0.5);
    AE_LOG( "[%s()] i4SensorDev:%d SensorIdx:%d AE max block width:%d heigh:%d AE meter:%d CamMode:%d AEScene:%d Flicker :%d %d EVcomp:%d ISO:%d %d MinFps:%d MaxFps:%d Limiter:%d AAOLineByte:%d\n", __FUNCTION__,
        m_eSensorDev, m_i4SensorIdx, m_rAEInitInput.i4AEMaxBlockWidth, m_rAEInitInput.i4AEMaxBlockHeight, m_eAEMeterMode,
        m_eAECamMode, m_eAEScene, m_eAEFlickerMode, m_eAEAutoFlickerMode, m_eAEEVcomp, m_u4AEISOSpeed, m_bRealISOSpeed,
        m_i4AEMinFps, m_i4AEMaxFps, m_bAElimitor, m_rAEInitInput.i4AAOLineByte);
#if USE_OPEN_SOURCE_AE
    m_pIAeAlgo = NS3A::IAeAlgo::createInstance<NS3A::EAAAOpt_OpenSource>(m_eSensorDev);
#else
    m_pIAeAlgo = NS3A::IAeAlgo::createInstance<NS3A::EAAAOpt_MTK>(m_eSensorDev);
#endif
    if (!m_pIAeAlgo) {
        CAM_LOGE("AeAlgo::createInstance() fail \n");
        return E_AE_ALGO_INIT_ERR;
    }
    if (!brealAEinit){
        bEnablePreIndex = m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex;
        m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex = MTRUE;
    }
    m_pIAeAlgo->lockAE(m_bAELock);
    m_pIAeAlgo->setAERealISOSpeed(m_bRealISOSpeed);
    m_pIAeAlgo->setAEVideoDynamicEnable(m_bVideoDynamic);
//    m_pIAeAlgo->setAELowLightTargetValue(m_rAEInitInput.rAENVRAM.rCCTConfig.u4AETarget, m_rAEInitInput.rAENVRAM.rCCTConfig.u4InDoorEV - 50, m_rAEInitInput.rAENVRAM.rCCTConfig.u4InDoorEV);   // set AE lowlight target 47 and low light threshold LV5
    m_pIAeAlgo->getEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
    setAEScene(m_eAEScene);
    setIsoSpeed(m_u4AEISOSpeed);
    setAEMinMaxFrameRatePlineIdx(m_i4AEMinFps ,m_i4AEMaxFps);
    //switchSensorModeMaxBVSensitivityDiff(MINT32 i4newSensorMode,MINT32 i4oldSensorMode,MINT32 & i4SenstivityDeltaIdx,MINT32 & i4BVDeltaIdx)
    m_pIAeAlgo->updateAEPlineInfo(m_pPreviewTableCurrent,m_pCaptureTable);
    m_pIAeAlgo->setEVIdxInfo(m_u4IndexMax ,m_u4IndexMin ,m_u4Index);
    m_pIAeAlgo->setSensorModeMaxBVdiff(m_i4DeltaSensitivityIdx,m_i4DeltaBVIdx);
    m_pIAeAlgo->initAE(&m_rAEInitInput, &rAEOutput, &m_rAEStatCfg);
    copyAEInfo2mgr(&m_rAEOutput.rPreviewMode, &rAEOutput);
    m_pIAeAlgo->setAElimitorEnable(m_bAElimitor);  // update limiter
    m_pIAeAlgo->setAEObjectTracking(MFALSE);;
    m_pIAeAlgo->setAEFDArea(&m_eAEFDArea);
    m_pIAeAlgo->getAEMaxISO(m_u4MaxShutter, m_u4MaxISO);
    //m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight);
    m_pIAeAlgo->modifyHistogramWinConfig(m_eZoomWinInfo, &m_rAEStatCfg, m_u4Hbinwidth, m_u4Hbinheight, m_i4AETgValidBlockWidth, m_i4AETgValidBlockHeight);


    if (!brealAEinit){
        m_rAEInitInput.rAEPARAM.strAEParasetting.bEnablePreIndex = bEnablePreIndex;
    }
    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.debug.ae_mgr.enable", value, "0");
    m_bAEMgrDebugEnable = atoi(value);

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::prepareCapParams()
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;

    AE_LOG( "[%s()] i4SensorDev:%d m_eShotMode:%d\n", __FUNCTION__, m_eSensorDev, m_eShotMode);
    rAEInput.eAeState = AE_STATE_CAPTURE;
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorIdx = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }
    m_bAEReadyCapture = MTRUE;  // capture ready flag
    m_i4TimeOutCnt = MFALSE;
    m_bCShot = MFALSE;
    copyAEInfo2mgr(&m_rAEOutput.rCaptureMode[0], &rAEOutput);
    copyAEInfo2mgr(&m_rAEOutput.rCaptureMode[1], &rAEOutput);
    copyAEInfo2mgr(&m_rAEOutput.rCaptureMode[2], &rAEOutput);
    mCaptureMode = m_rAEOutput.rCaptureMode[0];

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAECapPlineTable(MINT32 *i4CapIndex, strAETable &a_AEPlineTable)
{
    strAETable strAEPlineTable;
    strAEInput rAEInput;
    strAEOutput rAEOutput;

    AE_LOG( "[%s()] i4SensorDev:%d m_eShotMode:%d\n", __FUNCTION__, m_eSensorDev, m_eShotMode);
    rAEInput.eAeState = AE_STATE_CAPTURE;
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorIdx = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getCapPlineTable(i4CapIndex, strAEPlineTable);
        a_AEPlineTable =  strAEPlineTable;
        AE_LOG( "[%s()] i4SensorDev:%d i4CapIndex:%d CapId:%d\n", __FUNCTION__, m_eSensorDev, *i4CapIndex, strAEPlineTable.eID);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getSensorDeviceInfo(AE_DEVICES_INFO_T &a_rDeviceInfo)
{
    if(m_p3ANVRAM != NULL) {
        a_rDeviceInfo = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo;
    } else {
        AE_LOG( "[%s()] i4SensorDev:%d NVRAM Data is NULL\n", __FUNCTION__, m_eSensorDev);
    }
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MRESULT AeMgr::getAEConfigParams(MBOOL &bHDRen, MBOOL &bOverCnten, MBOOL &bTSFen)
{
    bHDRen = m_bEnableHDRYConfig;
    bOverCnten = m_bEnableOverCntConfig;
    bTSFen = m_bEnableTSFConfig;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsDoAEInPreAF()
{
    AE_LOG( "[%s()] i4SensorDev:%d DoAEbeforeAF:%d\n", __FUNCTION__, m_eSensorDev, m_rAEInitInput.rAEPARAM.strAEParasetting.bPreAFLockAE);
    return m_rAEInitInput.rAEPARAM.strAEParasetting.bPreAFLockAE;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsAEStable()
{
    if (m_bAEMgrDebugEnable) {
        AE_LOG( "[%s()] i4SensorDev:%d m_bAEStable:%d\n", __FUNCTION__, m_eSensorDev, m_bAEStable);
    }
    return m_bAEStable;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsAELock()
{
    if (m_bAEMgrDebugEnable) {
        AE_LOG( "[%s()] i4SensorDev:%d m_bAELock/m_bAPAELock/m_bAFAELock:%d/%d/%d\n", __FUNCTION__, m_eSensorDev, m_bAELock, m_bAPAELock, m_bAFAELock);
    }
    return m_bAELock;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsAPAELock()
{
    if (m_bAEMgrDebugEnable) {
        AE_LOG( "[%s()] i4SensorDev:%d m_bAELock/m_bAPAELock/m_bAFAELock:%d/%d/%d\n", __FUNCTION__, m_eSensorDev, m_bAELock, m_bAPAELock, m_bAFAELock);
    }
    return m_bAPAELock;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getBVvalue()
{
    return (m_BVvalue);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getDeltaBV()
{
    return (m_i4DeltaBV);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsStrobeBVTrigger()
{
    MBOOL bStrobeBVTrigger;
    MINT32 i4Bv = 0;
    strAETable strCurrentPreviewTable;
    strAETable strCurrentCaptureTable;
    strAETable strCurrentStrobeTable;
    strAFPlineInfo strobeAEPlineInfo;

    memset(&strCurrentCaptureTable, 0, sizeof(strAETable));
    getCurrentPlineTable(strCurrentPreviewTable, strCurrentCaptureTable, strCurrentStrobeTable, strobeAEPlineInfo);

    if(m_rAEInitInput.rAEPARAM.strAEParasetting.bEV0TriggerStrobe == MTRUE) {         // The strobe trigger by the EV 0 index
        i4Bv = m_BVvalueWOStrobe;
    } else {
        if(m_rAEInitInput.rAEPARAM.pEVValueArray[m_eAEEVcomp]) {
            if(m_pIAeAlgo != NULL) {
                i4Bv = m_BVvalueWOStrobe + m_pIAeAlgo->getSenstivityDeltaIndex(1024 *1024/ m_rAEInitInput.rAEPARAM.pEVValueArray[m_eAEEVcomp]);
            } else {
                i4Bv = m_BVvalueWOStrobe;
                AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
            }
        }
    }

    bStrobeBVTrigger = (i4Bv < strCurrentCaptureTable.i4StrobeTrigerBV)?MTRUE:MFALSE;

    AE_LOG_IF(m_3ALogEnable,"[%s()] i4SensorDev:%d bStrobeBVTrigger:%d BV:%d %d\n", __FUNCTION__, m_eSensorDev, bStrobeBVTrigger, i4Bv, strCurrentCaptureTable.i4StrobeTrigerBV);

    return bStrobeBVTrigger;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setStrobeMode(MBOOL bIsStrobeOn)
{
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->setStrobeMode(bIsStrobeOn);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }
    m_bStrobeOn = bIsStrobeOn;
    // Update flare again
    if(m_bStrobeOn == MTRUE) {   // capture on, get capture parameters for flare again.
//        prepareCapParams();
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getPreviewParams(AE_MODE_CFG_T &a_rPreviewInfo)
{
    a_rPreviewInfo = m_rAEOutput.rPreviewMode;
    AE_LOG_IF(m_3ALogEnable,"[getPreviewParams] SensorDev=%d, Preview Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n", m_eSensorDev, a_rPreviewInfo.u4Eposuretime, a_rPreviewInfo.u4AfeGain,
                   a_rPreviewInfo.u4IspGain, a_rPreviewInfo.u2FrameRate, a_rPreviewInfo.i2FlareGain, a_rPreviewInfo.i2FlareOffset, a_rPreviewInfo.u4RealISO);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updatePreviewParams(AE_MODE_CFG_T &a_rPreviewInfo, MINT32 i4AEidxNext)
{
    mPreviewMode = a_rPreviewInfo;
    m_rAEOutput.rAFMode = mPreviewMode;
    m_rAEOutput.rPreviewMode = mPreviewMode;
    m_i4WaitVDNum = 0; // reset the delay frame

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->updateAEIndex(i4AEidxNext);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    AE_LOG( "[%s()] m_i4SensorDev:%d i4AEidxNext:%d Exp. mode = %d Preview Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
        __FUNCTION__, m_eSensorDev, i4AEidxNext, mPreviewMode.u4ExposureMode, mPreviewMode.u4Eposuretime,
        mPreviewMode.u4AfeGain, mPreviewMode.u4IspGain, mPreviewMode.u2FrameRate, mPreviewMode.i2FlareGain, mPreviewMode.i2FlareOffset, mPreviewMode.u4RealISO);

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getExposureInfo(ExpSettingParam_T &strHDRInputSetting)
{
    MUINT8 i;
    MUINT32 rAEHistogram[AE_HISTOGRAM_BIN] = {0}, rFlareHistogram[128] = {0};
    HDR_CHDR_INFO_T rSWHdrInfo;
    strAETable strCurrentCaptureTable;
    MUINT32 u4NewSensitivityRatio = 1024, u4OldSensitivityRatio = 1024, u4SensitivityRatio = 1024;
    MUINT32 u4BinningIndex = 0;
    MUINT32 u4PreviewBaseGain=1024;
    MUINT32 u4PreviewBaseISO=100;
    MUINT32 u4FinalGain;

    strHDRInputSetting.u4MaxSensorAnalogGain = m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MaxGain;
    strHDRInputSetting.u4MaxAEExpTimeInUS = 500000; // 0.5sec
    strHDRInputSetting.u4MinAEExpTimeInUS = 500;  // 500us
    if(m_rAEInitInput.rAENVRAM.rDevicesInfo.u4CapExpUnit < 10000) {
        strHDRInputSetting.u4ShutterLineTime = 1000*m_rAEInitInput.rAENVRAM.rDevicesInfo.u4CapExpUnit;
    } else {
        strHDRInputSetting.u4ShutterLineTime = m_rAEInitInput.rAENVRAM.rDevicesInfo.u4CapExpUnit;
    }

    strHDRInputSetting.u4MaxAESensorGain = 8*m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MaxGain;
    strHDRInputSetting.u4MinAESensorGain = m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MinGain;

    u4OldSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video2PreRatio;
    u4NewSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Cap2PreRatio;

    if(u4OldSensitivityRatio != 0) {
        u4SensitivityRatio = 1024 *u4NewSensitivityRatio  / u4OldSensitivityRatio;
    } else {
        u4SensitivityRatio = 1024;
        AE_LOG( "[%s] i4SensorDev:%d u4OldSensitivityRatio is zero\n", __FUNCTION__, m_eSensorDev);
    }

    if(u4SensitivityRatio <= 300) {
        u4BinningIndex = 20;
    } else if(u4SensitivityRatio <= 450) {
        u4BinningIndex = 15;
    } else if(u4SensitivityRatio <= 768) {
        u4BinningIndex = 10;
    } else {
        u4BinningIndex = 0;
    }

    //getOnePlineTable(AETABLE_CAPTURE_AUTO, strCurrentCaptureTable);
    if (m_bEISAEPline){
        eAETableID eAISTableID = AETABLE_SCENE_INDEX14;
        MBOOL bNewPLineTableID = MFALSE;
        // Search for eID
        for(i=0;i<(MUINT32)MAX_PLINE_TABLE;i++) {
            if(m_pAEPlineTable->AEPlineTable.sPlineTable[i].eID == eAISTableID){
                AE_LOG( "[getExposureInfo] i/ePreviewPLineTableID/TotalIdx: %d/%d/%d \n", i, eAISTableID, m_pAEPlineTable->AEPlineTable.sPlineTable[i].u4TotalIndex);
                bNewPLineTableID = MTRUE;
                if (m_pAEPlineTable->AEPlineTable.sPlineTable[i].u4TotalIndex == 0){
                    AE_LOG( "[getExposureInfo] The Preview AE table total index is zero : %d ->%d\n", eAISTableID, m_pPreviewTableCurrent->eID);
                    eAISTableID = m_pPreviewTableCurrent->eID;
                }
            }
            AE_LOG_IF(m_3ALogEnable,"[getExposureInfo] i/TotalIdx: %d/%d \n", i, m_pAEPlineTable->AEPlineTable.sPlineTable[i].u4TotalIndex);
        }
        // Check AE Pline if not existed
        if (!bNewPLineTableID){
            eAISTableID = m_pPreviewTableCurrent->eID;
            AE_LOG( "[getExposureInfo] The Preview AE table enum value is not supported: %d ->%d\n", bNewPLineTableID, m_pPreviewTableCurrent->eID);
        }
        getOnePlineTable(eAISTableID, strCurrentCaptureTable);
    }else{
        getOnePlineTable(m_pCaptureTable->eID, strCurrentCaptureTable);
    }
    if((m_i4AEidxNext + u4BinningIndex) < strCurrentCaptureTable.u4TotalIndex) {
        m_rAEOutput.rCaptureMode[0].u4Eposuretime = strCurrentCaptureTable.pCurrentTable->sPlineTable[m_i4AEidxNext + u4BinningIndex].u4Eposuretime;
        m_rAEOutput.rCaptureMode[0].u4AfeGain = strCurrentCaptureTable.pCurrentTable->sPlineTable[m_i4AEidxNext + u4BinningIndex].u4AfeGain;
        m_rAEOutput.rCaptureMode[0].u4IspGain = strCurrentCaptureTable.pCurrentTable->sPlineTable[m_i4AEidxNext + u4BinningIndex].u4IspGain;
        u4FinalGain = (m_rAEOutput.rCaptureMode[0].u4AfeGain*m_rAEOutput.rCaptureMode[0].u4IspGain)>>10;
        m_rAEOutput.rCaptureMode[0].u4RealISO = u4PreviewBaseISO*u4FinalGain/u4PreviewBaseGain;
        AE_LOG( "[%s()] m_i4SensorDev:%d Modify Capture Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d Index:%d Binning:%d\n", __FUNCTION__, m_eSensorDev,
              m_rAEOutput.rCaptureMode[0].u4Eposuretime, m_rAEOutput.rCaptureMode[0].u4AfeGain, m_rAEOutput.rCaptureMode[0].u4IspGain, m_rAEOutput.rCaptureMode[0].u2FrameRate,
              m_rAEOutput.rCaptureMode[0].i2FlareGain, m_rAEOutput.rCaptureMode[0].i2FlareOffset, m_rAEOutput.rCaptureMode[0].u4RealISO, m_i4AEidxNext, u4BinningIndex);
    }

    strHDRInputSetting.u4ExpTimeInUS0EV = m_rAEOutput.rCaptureMode[0].u4Eposuretime;
    strHDRInputSetting.u4SensorGain0EV = (m_rAEOutput.rCaptureMode[0].u4AfeGain)*(m_rAEOutput.rCaptureMode[0].u4IspGain) >>10;
    strHDRInputSetting.u4ISOValue = m_rAEOutput.rCaptureMode[0].u4RealISO;
    strHDRInputSetting.u1FlareOffset0EV = m_rAEOutput.rCaptureMode[0].i2FlareOffset;

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAEHistogram(2, rAEHistogram);   // Y histogram output
        m_pIAeAlgo->getAEHistogram(0, rFlareHistogram);   // Y histogram output
        m_pIAeAlgo->getAESWHdrInfo(rSWHdrInfo);

        if((m_eAETargetMode == AE_MODE_IVHDR_TARGET)||(m_eAETargetMode == AE_MODE_ZVHDR_TARGET)) {
            strHDRInputSetting.u4AOEMode = 1;
            strHDRInputSetting.i4GainBase0EV = rSWHdrInfo.i4GainBase;
            strHDRInputSetting.i4LE_LowAvg = rSWHdrInfo.i4LEInfo;
            strHDRInputSetting.i4SEDeltaEVx100 = rSWHdrInfo.i4SEInfo;
        }
        else if((m_eAETargetMode == AE_MODE_MVHDR_TARGET)) {
            mVHDR_SWHDR_InputParam_T rInput;
            mVHDR_SWHDR_OutputParam_T rOutput;

            if(m_rSensorVCInfo.u2VCModeSelect == 0)
                rInput.i4Ratio = m_rSensorVCInfo.u2VCShutterRatio;
            else
                rInput.i4Ratio = (m_strIVHDROutputSetting.u4LEExpTimeInUS + (m_strIVHDROutputSetting.u4SEExpTimeInUS >> 1)) / m_strIVHDROutputSetting.u4SEExpTimeInUS;
            rInput.LEMax = rSWHdrInfo.i4LEInfo;
            rInput.SEMax = rSWHdrInfo.i4SEInfo;

            getMVHDR_AEInfo(rInput, rOutput);

            AE_LOG( "[%s] Ratio:%d, LEMax:%d, SEMax:%d, SEDeltaEV:%d\n", __FUNCTION__, rInput.i4Ratio, rInput.LEMax, rInput.SEMax, rOutput.i4SEDeltaEVx100);

            strHDRInputSetting.u4AOEMode = 1;
            strHDRInputSetting.i4GainBase0EV = rSWHdrInfo.i4GainBase;
            strHDRInputSetting.i4LE_LowAvg = 0;
            strHDRInputSetting.i4SEDeltaEVx100 = rOutput.i4SEDeltaEVx100;
        }
        else {
            strHDRInputSetting.u4AOEMode = 0;
            strHDRInputSetting.i4GainBase0EV = 0;
            strHDRInputSetting.i4LE_LowAvg = 0;
            strHDRInputSetting.i4SEDeltaEVx100 = 0;
        }

        AE_LOG( "[%s()] u4AOEMode = %d, i4GainBase0EV = %d, i4LE_LowAvg = %d, i4SEDeltaEVx100 = %d\n", __FUNCTION__,
                                                                                            strHDRInputSetting.u4AOEMode, strHDRInputSetting.i4GainBase0EV,
                                                                                            strHDRInputSetting.i4LE_LowAvg,  strHDRInputSetting.i4SEDeltaEVx100);

    } else {
        AE_LOG( "The AE algo class is NULL (26)\n");
    }

    strHDRInputSetting.bDetectFace = (m_eAEFDArea.u4Count > 0)? 1:0;

    for (i = 0; i < AE_HISTOGRAM_BIN; i++) {
        strHDRInputSetting.u4Histogram[i] = rAEHistogram[i];
        strHDRInputSetting.u4FlareHistogram[i] = rFlareHistogram[i];
    }

    AE_LOG( "[%s()] Input MaxSensorAnalogGain:%d MaxExpTime:%d MinExpTime:%d LineTime:%d MaxSensorGain:%d ExpTime:%d SensorGain:%d FlareOffset:%d DetectFace:%d %d\n", __FUNCTION__,
        strHDRInputSetting.u4MaxSensorAnalogGain, strHDRInputSetting.u4MaxAEExpTimeInUS, strHDRInputSetting.u4MinAEExpTimeInUS, strHDRInputSetting.u4ShutterLineTime,
        strHDRInputSetting.u4MaxAESensorGain, strHDRInputSetting.u4ExpTimeInUS0EV, strHDRInputSetting.u4SensorGain0EV, strHDRInputSetting.u1FlareOffset0EV, strHDRInputSetting.bDetectFace, m_eAEFDArea.u4Count);

    for (i = 0; i < AE_HISTOGRAM_BIN; i+=8) {
        AE_LOG( "[%s()] Input Histogram%d~%d:%d %d %d %d %d %d %d %d\n", __FUNCTION__, i, i+7, strHDRInputSetting.u4Histogram[i],
           strHDRInputSetting.u4Histogram[i+1], strHDRInputSetting.u4Histogram[i+2], strHDRInputSetting.u4Histogram[i+3], strHDRInputSetting.u4Histogram[i+4],
           strHDRInputSetting.u4Histogram[i+5], strHDRInputSetting.u4Histogram[i+6], strHDRInputSetting.u4Histogram[i+7]);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getCaptureParams(AE_MODE_CFG_T &a_rCaptureInfo)
{
    strAEOutput rAEOutput;

    a_rCaptureInfo = m_rAEOutput.rCaptureMode[0];

    AE_LOG( "[%s()] m_i4SensorDev:%d Capture Exp. mode:%d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n", __FUNCTION__, m_eSensorDev, a_rCaptureInfo.u4ExposureMode, a_rCaptureInfo.u4Eposuretime, a_rCaptureInfo.u4AfeGain,
                   a_rCaptureInfo.u4IspGain, a_rCaptureInfo.u2FrameRate, a_rCaptureInfo.i2FlareGain, a_rCaptureInfo.i2FlareOffset, a_rCaptureInfo.u4RealISO);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateCaptureParams(AE_MODE_CFG_T &a_rCaptureInfo)
{
    MUINT32 u4FinalGain;
    MUINT32 u4PreviewBaseGain=1024;
    MUINT32 u4PreviewBaseISO=100;
    AE_EXP_GAIN_MODIFY_T  rSensorInputData, rSensorOutputData;

    if(m_p3ANVRAM != NULL) {
        u4PreviewBaseISO=m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
    } else {
        AE_LOG( "[%s()] m_i4SensorDev:%d NVRAM data is NULL\n", __FUNCTION__, m_eSensorDev);
    }
    mCaptureMode = a_rCaptureInfo;
    u4FinalGain = (mCaptureMode.u4AfeGain*mCaptureMode.u4IspGain)>>10;
    mCaptureMode.u4RealISO = u4PreviewBaseISO*u4FinalGain/u4PreviewBaseGain;
    AE_LOG( "[%s()] m_i4SensorDev:%d Exp. mode = %d Capture Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
        __FUNCTION__, m_eSensorDev, mCaptureMode.u4ExposureMode, mCaptureMode.u4Eposuretime,
        mCaptureMode.u4AfeGain, mCaptureMode.u4IspGain, mCaptureMode.u2FrameRate, mCaptureMode.i2FlareGain, mCaptureMode.i2FlareOffset, mCaptureMode.u4RealISO);

    if(m_bEnableAE) {
        rSensorInputData.u4SensorExpTime = mCaptureMode.u4Eposuretime;
        rSensorInputData.u4SensorGain = mCaptureMode.u4AfeGain;
        rSensorInputData.u4IspGain = mCaptureMode.u4IspGain;
        if(!m_bStrobeOn){
            AE_LOG( "[%s()] m_bStrobeOn == 0\n", __FUNCTION__);
            if(m_pIAeAlgo != NULL) {
                m_pIAeAlgo->switchSensorExposureGain(MTRUE, rSensorInputData, rSensorOutputData);   // send to 3A to calculate the exposure time and gain
            } else {
                AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
            }
            mCaptureMode.u4Eposuretime = rSensorOutputData.u4SensorExpTime;
            mCaptureMode.u4AfeGain = rSensorOutputData.u4SensorGain;
            mCaptureMode.u4IspGain = rSensorOutputData.u4IspGain;
        }
        u4FinalGain = (mCaptureMode.u4AfeGain*mCaptureMode.u4IspGain)>>10;
        mCaptureMode.u4RealISO = u4PreviewBaseISO*u4FinalGain/u4PreviewBaseGain;
        AE_LOG( "[%s()] m_i4SensorDev:%d Modify Exp. mode = %d Capture Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
        __FUNCTION__, m_eSensorDev, mCaptureMode.u4ExposureMode, mCaptureMode.u4Eposuretime,
        mCaptureMode.u4AfeGain, mCaptureMode.u4IspGain, mCaptureMode.u2FrameRate, mCaptureMode.i2FlareGain, mCaptureMode.i2FlareOffset, mCaptureMode.u4RealISO);
    }

    m_rAEOutput.rCaptureMode[0] = mCaptureMode;
    m_bAECaptureUpdate = MTRUE;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setSensorDirectly(CaptureParam_T &a_rCaptureInfo, MBOOL bDirectlySetting)
{
    AE_MODE_CFG_T rCaptureInfo;

    AE_LOG( "[%s()] m_i4SensorDev:%d Mode:%d Shutter:%d Sensor Gain:%d ISP Gain:%d ISO:%d Flare Offset:%d %d\n", __FUNCTION__, m_eSensorDev, a_rCaptureInfo.u4ExposureMode, a_rCaptureInfo.u4Eposuretime,
    a_rCaptureInfo.u4AfeGain, a_rCaptureInfo.u4IspGain, a_rCaptureInfo.u4RealISO,   a_rCaptureInfo.u4FlareGain, a_rCaptureInfo.u4FlareOffset);

    rCaptureInfo.u4ExposureMode = a_rCaptureInfo.u4ExposureMode;
    rCaptureInfo.u4Eposuretime = a_rCaptureInfo.u4Eposuretime;
    rCaptureInfo.u4AfeGain = a_rCaptureInfo.u4AfeGain;
    rCaptureInfo.u4IspGain = a_rCaptureInfo.u4IspGain;
    rCaptureInfo.u4RealISO = a_rCaptureInfo.u4RealISO;
    rCaptureInfo.i2FlareGain = (MINT16)a_rCaptureInfo.u4FlareGain;
    rCaptureInfo.i2FlareOffset = (MINT16)a_rCaptureInfo.u4FlareOffset;

    updateCaptureParams(rCaptureInfo);

    if(bDirectlySetting) {
        if((m_eCamMode == eAppMode_EngMode) && ((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET))) {   // engineer mode and target mode
            UpdateSensorISPParams(AE_TWO_SHUTTER_INIT_STATE);
        } else {
            UpdateSensorISPParams(AE_CAPTURE_STATE);
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAEMeteringYvalue(AEMeterArea_T rWinSize, MUINT8 *uYvalue)
{
    Mutex::Autolock lock(m_Lock);
    MUINT8 iValue = 0;
    AEMeterArea_T sAEMeteringArea = rWinSize;
    // Mapping AE region from Hbin size to [-1000,1000]
    sAEMeteringArea.i4Left   = sAEMeteringArea.i4Left*2000/m_u4Hbinwidth - 1000;
    sAEMeteringArea.i4Right  = sAEMeteringArea.i4Right*2000/m_u4Hbinwidth - 1000;
    sAEMeteringArea.i4Top    = sAEMeteringArea.i4Top*2000/m_u4Hbinheight - 1000;
    sAEMeteringArea.i4Bottom = sAEMeteringArea.i4Bottom*2000/m_u4Hbinheight - 1000;
    // Bounding check
    if (sAEMeteringArea.i4Left   < -1000)  {sAEMeteringArea.i4Left   = -1000;}
    if (sAEMeteringArea.i4Right  < -1000)  {sAEMeteringArea.i4Right  = -1000;}
    if (sAEMeteringArea.i4Top    < -1000)  {sAEMeteringArea.i4Top    = -1000;}
    if (sAEMeteringArea.i4Bottom < -1000)  {sAEMeteringArea.i4Bottom = -1000;}

    if (sAEMeteringArea.i4Left   > 1000)  {sAEMeteringArea.i4Left   = 1000;}
    if (sAEMeteringArea.i4Right  > 1000)  {sAEMeteringArea.i4Right  = 1000;}
    if (sAEMeteringArea.i4Top    > 1000)  {sAEMeteringArea.i4Top    = 1000;}
    if (sAEMeteringArea.i4Bottom > 1000)  {sAEMeteringArea.i4Bottom = 1000;}
    AE_LOG_IF(m_3ALogEnable,"[%s()] AE meter area Left:%d Right:%d Top:%d Bottom:%d \n",__FUNCTION__,
        sAEMeteringArea.i4Left, sAEMeteringArea.i4Right, sAEMeteringArea.i4Top, sAEMeteringArea.i4Bottom);

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAEMeteringAreaValue(sAEMeteringArea, &iValue);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    *uYvalue = iValue;

//    AE_LOG( "[getMeteringYvalue] AE meter area Left:%d Right:%d Top:%d Bottom:%d Y:%d %d\n", sAEMeteringArea.i4Left, sAEMeteringArea.i4Right, sAEMeteringArea.i4Top, sAEMeteringArea.i4Bottom, iValue, *uYvalue);
    return S_AE_OK;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAEMeteringBlockAreaValue(AEMeterArea_T rWinSize, MUINT8 *uYvalue, MUINT16 *u2YCnt)
{
    Mutex::Autolock lock(m_Lock);
    AEMeterArea_T sAEMeteringArea = rWinSize;
    // Mapping AE region from Hbin size to [-1000,1000]
    sAEMeteringArea.i4Left   = sAEMeteringArea.i4Left*2000/m_u4Hbinwidth - 1000;
    sAEMeteringArea.i4Right  = sAEMeteringArea.i4Right*2000/m_u4Hbinwidth - 1000;
    sAEMeteringArea.i4Top    = sAEMeteringArea.i4Top*2000/m_u4Hbinheight - 1000;
    sAEMeteringArea.i4Bottom = sAEMeteringArea.i4Bottom*2000/m_u4Hbinheight - 1000;
    // Bounding check
    if (sAEMeteringArea.i4Left   < -1000)  {sAEMeteringArea.i4Left   = -1000;}
    if (sAEMeteringArea.i4Right  < -1000)  {sAEMeteringArea.i4Right  = -1000;}
    if (sAEMeteringArea.i4Top    < -1000)  {sAEMeteringArea.i4Top    = -1000;}
    if (sAEMeteringArea.i4Bottom < -1000)  {sAEMeteringArea.i4Bottom = -1000;}

    if (sAEMeteringArea.i4Left   > 1000)  {sAEMeteringArea.i4Left   = 1000;}
    if (sAEMeteringArea.i4Right  > 1000)  {sAEMeteringArea.i4Right  = 1000;}
    if (sAEMeteringArea.i4Top    > 1000)  {sAEMeteringArea.i4Top    = 1000;}
    if (sAEMeteringArea.i4Bottom > 1000)  {sAEMeteringArea.i4Bottom = 1000;}
    AE_LOG_IF(m_3ALogEnable,"[%s()] AE meter area Left:%d Right:%d Top:%d Bottom:%d\n",__FUNCTION__,
    sAEMeteringArea.i4Left, sAEMeteringArea.i4Right, sAEMeteringArea.i4Top, sAEMeteringArea.i4Bottom);

    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAEMeteringBlockAreaValue(sAEMeteringArea, uYvalue, u2YCnt);
    } else {
        AE_LOG( "The AE algo class is NULL (25)\n");
    }

//    AE_LOG( "[getMeteringYvalue] AE meter area Left:%d Right:%d Top:%d Bottom:%d Y:%d %d\n", sAEMeteringArea.i4Left, sAEMeteringArea.i4Right, sAEMeteringArea.i4Top, sAEMeteringArea.i4Bottom, iValue, *uYvalue);
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAEBlockYvalues(MUINT8 *pYvalues, MUINT8 size)
{
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAEBlockYvalues(pYvalues, size);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getRTParams(FrameOutputParam_T &a_strFrameInfo)
{
    strAEInput rAEInput;
    strAEOutput rAEOutput;
    MUINT32 u4FinalGain;
    MUINT32 u4PreviewBaseGain=1024;
    MUINT32 u4PreviewBaseISO=100;

    a_strFrameInfo.u4AEIndex = m_i4AEidxNext;
    a_strFrameInfo.u4PreviewShutterSpeed_us = m_rAEOutput.rPreviewMode.u4Eposuretime;
    a_strFrameInfo.u4PreviewSensorGain_x1024 = m_rAEOutput.rPreviewMode.u4AfeGain;
    a_strFrameInfo.u4PreviewISPGain_x1024 = m_rAEOutput.rPreviewMode.u4IspGain;
    u4FinalGain = (a_strFrameInfo.u4PreviewSensorGain_x1024*a_strFrameInfo.u4PreviewISPGain_x1024)>>10;
    if(m_p3ANVRAM != NULL) {
        a_strFrameInfo.u4RealISOValue = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain*u4FinalGain/u4PreviewBaseGain;
    } else {
        a_strFrameInfo.u4RealISOValue = u4PreviewBaseISO*u4FinalGain/u4PreviewBaseGain;
    }

    if(m_eCamMode == eAppMode_EngMode){
        rAEInput.eAeState = AE_STATE_CAPTURE;
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->handleAE(&rAEInput, &rAEOutput);
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }
        // VHDR or non-VHDR condition
        if ((m_eAETargetMode==AE_MODE_IVHDR_TARGET)||(m_eAETargetMode==AE_MODE_ZVHDR_TARGET)||(m_eAETargetMode==AE_MODE_MVHDR_TARGET)){
            a_strFrameInfo.u4CapShutterSpeed_us = m_strIVHDROutputSetting.u4LEExpTimeInUS;
            a_strFrameInfo.u4CapSensorGain_x1024 = m_strIVHDROutputSetting.u4LESensorGain;
            a_strFrameInfo.u4CapISPGain_x1024 = m_strIVHDROutputSetting.u4LEISPGain;
        }else{
            copyAEInfo2mgr(&m_rAEOutput.rCaptureMode[0], &rAEOutput);
            a_strFrameInfo.u4CapShutterSpeed_us = m_rAEOutput.rCaptureMode[0].u4Eposuretime;
            a_strFrameInfo.u4CapSensorGain_x1024 = m_rAEOutput.rCaptureMode[0].u4AfeGain;
            a_strFrameInfo.u4CapISPGain_x1024 = m_rAEOutput.rCaptureMode[0].u4IspGain;
        }
    } else {
        a_strFrameInfo.u4CapShutterSpeed_us = m_rAEOutput.rPreviewMode.u4Eposuretime;
        a_strFrameInfo.u4CapSensorGain_x1024 = m_rAEOutput.rPreviewMode.u4AfeGain;
        a_strFrameInfo.u4CapISPGain_x1024 = m_rAEOutput.rPreviewMode.u4IspGain;
    }
    a_strFrameInfo.u4FRameRate_x10 = m_rAEOutput.rPreviewMode.u2FrameRate;
    a_strFrameInfo.i4BrightValue_x10 = m_BVvalue;
    a_strFrameInfo.i4ExposureValue_x10 = m_i4EVvalue;
    a_strFrameInfo.i4LightValue_x10 = (m_BVvalue + 50);
    a_strFrameInfo.i2FlareOffset = m_rAEOutput.rPreviewMode.i2FlareOffset;
    a_strFrameInfo.i2FlareGain = m_rAEOutput.rPreviewMode.i2FlareGain;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::getAECondition(MUINT32 i4AECondition)
{
    if(i4AECondition & m_u4AECondition) {
        return MTRUE;
    } else {
        return MFALSE;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getLCEPlineInfo(LCEInfo_T &a_rLCEInfo)
{
MUINT32 u4LCEStartIdx = 0, u4LCEEndIdx = 0;


    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAELCEIndexInfo(&u4LCEStartIdx, &u4LCEEndIdx);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    a_rLCEInfo.i4AEidxCur = m_i4AEidxCurrent;
    a_rLCEInfo.i4AEidxNext = m_i4AEidxNext;
    a_rLCEInfo.i4NormalAEidx = (MINT32) u4LCEStartIdx;
    a_rLCEInfo.i4LowlightAEidx = (MINT32) u4LCEEndIdx;

    if (m_bAEMgrDebugEnable) {
        AE_LOG( "[%s()] m_i4SensorDev:%d i4AEidxCur:%d i4AEidxNext:%d i4NormalAEidx:%d i4LowlightAEidx:%d\n", __FUNCTION__, m_eSensorDev, a_rLCEInfo.i4AEidxCur, a_rLCEInfo.i4AEidxNext, a_rLCEInfo.i4NormalAEidx, a_rLCEInfo.i4LowlightAEidx);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAERotateDegree(MINT32 i4RotateDegree)
{
    if(m_i4RotateDegree == i4RotateDegree) {  // the same degree
        return S_AE_OK;
    }

    AE_LOG( "[%s()] m_i4SensorDev:%d old:%d\n", __FUNCTION__, m_eSensorDev, m_i4RotateDegree);
    m_i4RotateDegree = i4RotateDegree;

    if(m_pIAeAlgo != NULL) {
        if((i4RotateDegree == 90) || (i4RotateDegree == 270)){
            m_pIAeAlgo->setAERotateWeighting(MTRUE);
        } else {
            m_pIAeAlgo->setAERotateWeighting(MFALSE);
        }
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::UpdateSensorISPParams(AE_STATE_T eNewAEState)
{
    MRESULT err;
    AE_INFO_T rAEInfo2ISP;
    MUINT32 u4IndexRatio;
    MUINT32 u4Index = 0;
    MUINT32 u4ISOValue = 100;
    MUINT32 u4FinalGain;
    MUINT32 u4PreviewBaseGain=1024;
    MUINT32 u4PreviewBaseISO=100;
    MBOOL bCaptureState = MFALSE;
    MUINT16 u2FrameRate;
    MUINT32 u4ISPGain = 1024;
    MUINT32 u4MinIsoGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
    MUINT32 u4MaxGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MaxGain;

    m_AEState = eNewAEState;

    switch(eNewAEState)
    {
        case AE_INIT_STATE:
        case AE_REINIT_STATE:
            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameAESmooth;
            // sensor initial and send shutter / gain default value
            AE_LOG( "[%s()] i4SensorDev:%d Exp Mode: %d Shutter:%d Sensor Gain:%d Isp Gain:%d Flare:%d %d Frame Rate:%d\n",
             __FUNCTION__, m_eSensorDev, m_rAEOutput.rPreviewMode.u4ExposureMode, m_rAEOutput.rPreviewMode.u4Eposuretime,
             m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain, m_rAEOutput.rPreviewMode.i2FlareGain, m_rAEOutput.rPreviewMode.i2FlareOffset, m_rAEOutput.rPreviewMode.u2FrameRate);

            (m_rAEOutput.rPreviewMode.u4ExposureMode == eAE_EXPO_TIME) ? (err = AAASensorMgr::getInstance().setPreviewParams((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain))
                                                           : (err = AAASensorMgr::getInstance().setPreviewLineBaseParams((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain));

            if (FAILED(err)) {
                CAM_LOGE("AAASensorMgr::getInstance().setPreviewParams fail\n");
                return err;
            }
            m_u4PrevExposureTime = m_u4PreExposureTime = m_rAEOutput.rPreviewMode.u4Eposuretime;
            m_u4PrevSensorGain = m_u4PreSensorGain = m_rAEOutput.rPreviewMode.u4AfeGain;
            m_u4PrevIspGain = m_u4PreIspGain = m_rAEOutput.rPreviewMode.u4IspGain;

            m_bAEStable = MFALSE;
            updateAEInfo2ISP(AE_INIT_STATE, 0x00);
            m_u4StableCnt = 0 ;
            m_i4WaitVDNum = 0;
            m_eAEState = MTK_CONTROL_AE_STATE_SEARCHING;
            // updateEvsettingqueue
            for (int i=0; i< m_uEvQueueSize ; i++){
                updatePreEvSettingQueue(m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain );
            }
            //
            m_u4PreviousSensorgain = m_rAEOutput.rPreviewMode.u4AfeGain;
            m_u4PreviousISPgain = m_rAEOutput.rPreviewMode.u4IspGain;
            break;
        case AE_AUTO_FRAMERATE_STATE:
        case AE_MANUAL_FRAMERATE_STATE:
                if(m_bAEStable == MFALSE) {
                    m_u4StableCnt = 0;
                } else {
                    if(m_u4StableCnt < 0xFFFF) {
                        m_u4StableCnt++;
                    }
                }

            AE_LOG( "[%s:s] i4SensorDev:%d VDNum %d, Prev %d/%d/%d, Output %d/%d/%d Smooth:%d m_eAEState:%d\n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum,
                    m_u4PreExposureTime,
                    m_u4PreSensorGain,
                    m_u4PreIspGain,
                    mPreviewMode.u4Eposuretime,
                    mPreviewMode.u4AfeGain,
                    mPreviewMode.u4IspGain,
                    m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableAESmoothGain, m_eAEState);
            if (m_bEnSWBuffMode){
                updatePreviewParamsByHFSM(&mPreviewMode);
            }
            if ((m_u4PrevExposureTime == 0) || (m_u4PrevSensorGain == 0) || (m_u4PrevIspGain == 0)) {
                m_u4PrevExposureTime = mPreviewMode.u4Eposuretime;
                m_u4PrevSensorGain = mPreviewMode.u4AfeGain;
                m_u4PrevIspGain = mPreviewMode.u4IspGain;
            }
if(m_bPerframeAEFlag && (!m_bEnSWBuffMode)){

            // Frame rate control
            if((m_i4AEMinFps == m_i4AEMaxFps) || (m_i4AEMaxFps <= LIB3A_AE_FRAMERATE_MODE_30FPS)) {    // frame rate control
                        m_bSetFrameRateValue = MTRUE;
                        m_u4UpdateFrameRate_x10 = m_i4AEMaxFps;
            }
            // Raise shutter command flag for I2C
            if (m_i4ShutterDelayFrames == 0){
                    m_bSetShutterValue = MTRUE;
                    m_u4UpdateShutterValue = m_rAEOutput.rPreviewMode.u4Eposuretime;
            }
            if ((m_i4SensorGainDelayFrames == m_i4ShutterDelayFrames)||m_rAEInitInput.rAEPARAM.bPerFrameAESmooth) {
                    m_bSetGainValue = MTRUE;
                    m_u4UpdateGainValue = m_rAEOutput.rPreviewMode.u4AfeGain;
            }
            if (m_i4SensorGainDelayFrames == m_i4ShutterDelayFrames + 1){
                    m_bSetGainValue = MTRUE;
                    m_u4UpdateGainValue = m_u4PreviousSensorgain;
            }
            // Send ISP gain command
            if ((m_i4IspGainDelayFrames == m_i4ShutterDelayFrames)||m_rAEInitInput.rAEPARAM.bPerFrameAESmooth) {
                    updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, m_rAEOutput.rPreviewMode.u4IspGain);
                    AE_LOG_IF(m_3ALogEnable,"[%s()] Isp gain value(current) = %d\n", __FUNCTION__, m_rAEOutput.rPreviewMode.u4IspGain);
            } else if (m_i4IspGainDelayFrames == m_i4ShutterDelayFrames + 1){
                    updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, m_u4PreviousISPgain);
                    AE_LOG( "[%s()] Isp gain value(previous) = %d\n", __FUNCTION__, m_u4PreviousISPgain);
            } else {
                    AE_LOG( "Perframe update AE warning : ISPGain delay should be more than 1.\n");
            }
            // Prepare Isp Gain for command sending
            if ((m_i4IspGainDelayFrames - m_i4ShutterDelayFrames) == 1){
                 m_u4PreviousISPgain = mPreviewMode.u4IspGain;
            }
            // Prepare Afe Gain for command sending
            if ((m_i4SensorGainDelayFrames - m_i4ShutterDelayFrames) == 1){
                 m_u4PreviousSensorgain = mPreviewMode.u4AfeGain;
            }
            // reset condition
            m_u4PrevExposureTime = m_u4PreExposureTime = m_rAEOutput.rPreviewMode.u4Eposuretime;
            m_u4PrevSensorGain   = m_u4PreSensorGain   = m_rAEOutput.rPreviewMode.u4AfeGain;
            m_u4PrevIspGain      = m_u4PreIspGain      = m_rAEOutput.rPreviewMode.u4IspGain;

}else{
#if 1 // edwin version
            if(m_i4WaitVDNum <= (m_i4IspGainDelayFrames+ISP_GAIN_DELAY_OFFSET)) {   // restart
                m_u4PreExposureTime = m_u4PrevExposureTime;
                m_u4PreSensorGain = m_u4PrevSensorGain;
                m_u4PreIspGain = m_u4PrevIspGain;

                m_bSetFrameRateValue = MTRUE;
                m_u4UpdateFrameRate_x10 = m_i4AEMaxFps;

                if(m_i4WaitVDNum == m_i4ShutterDelayFrames) {
                    m_bSetShutterValue = MTRUE;
                    m_u4UpdateShutterValue = mPreviewMode.u4Eposuretime;
                    m_u4PrevExposureTime = mPreviewMode.u4Eposuretime;
                }
                if(m_i4WaitVDNum == m_i4SensorGainDelayFrames) {
                    m_bSetGainValue = MTRUE;
                    m_u4UpdateGainValue = mPreviewMode.u4AfeGain;
                    m_u4PrevSensorGain = mPreviewMode.u4AfeGain;
                }

#if 0 //enable smooth
                if((m_bAdbAEDisableSmooth == MFALSE) && (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableAESmoothGain == MTRUE)){
                    if((m_i4WaitVDNum < m_i4IspGainDelayFrames) && (m_ePrevAECamMode == m_eAECamMode) && (m_bOtherIPRestoreAE == MFALSE) && (m_bEnableAE == MTRUE)) {
                        MUINT32 w1;
                        UINT32 CurTotalGain;

#ifndef min
#define min(a,b)  ((a) < (b) ? (a) : (b))
#endif
#ifndef max
#define max(a,b)  ((a) > (b) ? (a) : (b))
#endif

                        w1 = 12;
                        CurTotalGain = (mPreviewMode.u4Eposuretime * mPreviewMode.u4AfeGain) /
                            m_u4PreExposureTime *
                            mPreviewMode.u4IspGain /
                            m_u4PreSensorGain;

                        m_u4SmoothIspGain = ((32-w1)*m_u4PrevIspGain + w1*CurTotalGain)>>5;
                        m_u4SmoothIspGain = max(min(m_u4SmoothIspGain, 10*1024), 1024);
                    if(m_u4SmoothIspGain != mPreviewMode.u4IspGain) {
                        IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, m_u4SmoothIspGain>>1);
                        updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, m_u4SmoothIspGain);
//                AE_LOG( "[%s] total/prev/smooth/output %d/%d/%d/%d", __FUNCTION__,
//                        CurTotalGain,
//                        m_u4PreIspGain,
//                        m_u4SmoothIspGain,
//                        m_rAEOutput.rPreviewMode.u4IspGain);
                      }
                    } else {    // reset condition
                        m_u4PreExposureTime =mPreviewMode.u4Eposuretime;
                        m_u4PreSensorGain = mPreviewMode.u4AfeGain;
                        m_u4PrevIspGain = m_u4PreIspGain = mPreviewMode.u4IspGain;

                        if (m_i4WaitVDNum > m_i4IspGainDelayFrames && m_bAEStable == TRUE) { // a complete cycle
                            m_ePrevAECamMode = m_eAECamMode;
                            m_bOtherIPRestoreAE = MFALSE;
                        }
                    }
                }
#endif
                AE_LOG( "[%s:e] i4SensorDev:%d VDNum %d, Delay %d/%d/%d, Prev %d/%d/%d, Output %d/%d/%d State:%d FrameRate:%d/%d Flare:%d/%d \n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum,
                    m_i4ShutterDelayFrames,
                    m_i4SensorGainDelayFrames,
                    m_i4IspGainDelayFrames,
                    m_u4PreExposureTime,
                    m_u4PreSensorGain,
                    m_u4PreIspGain,
                    mPreviewMode.u4Eposuretime,
                    mPreviewMode.u4AfeGain,
                    mPreviewMode.u4IspGain,
                    m_AEState, m_i4AEMinFps, m_i4AEMaxFps,
                    mPreviewMode.i2FlareOffset, mPreviewMode.i2FlareGain);

                if(m_i4WaitVDNum == m_i4IspGainDelayFrames) {
                    m_AEState = eNewAEState;
                    updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, 0x00);
                    m_u4PrevIspGain = mPreviewMode.u4IspGain;
                }
            }else {
                //AE_LOG( "[%s] i4SensorDev:%d m_i4WaitVDNum:%d \n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum);
            }
            m_i4WaitVDNum++;

            u2FrameRate = m_rAEOutput.rPreviewMode.u2FrameRate;

            if(u2FrameRate > m_i4AEMaxFps) {
                AE_LOG_IF(m_3ALogEnable,"[updateAEInfo2ISP] Frame rate too large:%d %d\n", u2FrameRate, m_i4AEMaxFps);
                u2FrameRate = m_i4AEMaxFps;
            }

            if(u2FrameRate != 0) {
                m_rSensorCurrentInfo.u8FrameDuration = 10000000000L / u2FrameRate;
            } else {
                m_rSensorCurrentInfo.u8FrameDuration = 33000000L;
                AE_LOG( "No Frame rate value, using default frame rate value (33ms)\n");
            }
#endif
}
            break;
        case AE_AF_STATE:
            // if the AF setting is the same with preview, skip the re-setting
            if((mPreviewMode.u4Eposuretime != m_rAEOutput.rAFMode.u4Eposuretime) || (mPreviewMode.u4AfeGain != m_rAEOutput.rAFMode.u4AfeGain) ||
                (mPreviewMode.u4IspGain != m_rAEOutput.rAFMode.u4IspGain)) {
                if(m_i4WaitVDNum == m_i4ShutterDelayFrames) {
                    m_bSetShutterValue = MTRUE;
                    m_u4UpdateShutterValue = m_rAEOutput.rAFMode.u4Eposuretime;
                }
                if(m_i4WaitVDNum == m_i4SensorGainDelayFrames) {
                    m_bSetGainValue = MTRUE;
                    m_u4UpdateGainValue = m_rAEOutput.rAFMode.u4AfeGain;
                }
                if(m_i4WaitVDNum >= m_i4IspGainDelayFrames) {
                    updateAEInfo2ISP(AE_AF_STATE, 0x00);
                    m_u4PrevExposureTime = 0;
                    m_u4PrevSensorGain = 0;
                    m_u4PrevIspGain = 0;
                    AE_LOG( "[doAFAE] ISP Gain:%d\n", m_rAEOutput.rAFMode.u4IspGain);
                    m_bAEStable = MTRUE;
                    m_bAEMonitorStable = m_bAEStable;
                    prepareCapParams();
                }
                //m_i4WaitVDNum ++;
                AE_LOG( "[doAFAE] Shutter:%d Sensor Gain:%d\n", m_rAEOutput.rAFMode.u4Eposuretime, m_rAEOutput.rAFMode.u4AfeGain);
            }else {
                 m_bAEStable = MTRUE;
                 m_u4AEScheduleCnt = 0; // for AE monitor
                 m_i4WaitVDNum = m_i4IspGainDelayFrames+ISP_GAIN_DELAY_OFFSET+1;
                 prepareCapParams();
                 AE_LOG( "[doAFAE] AE Stable\n");
            }
            m_i4WaitVDNum++;
            AE_LOG( "[doAFAE] AF SensorDev:%d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d m_i4WaitVDNum:%d\n", m_eSensorDev, m_rAEOutput.rAFMode.u4Eposuretime,
                 m_rAEOutput.rAFMode.u4AfeGain, m_rAEOutput.rAFMode.u4IspGain, m_rAEOutput.rAFMode.u2FrameRate,
                 m_rAEOutput.rAFMode.i2FlareGain, m_rAEOutput.rAFMode.i2FlareOffset, m_rAEOutput.rAFMode.u4RealISO, m_i4WaitVDNum);
            AE_LOG( "[doAFAE] Capture i4SensorDev:%d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n", m_eSensorDev, m_rAEOutput.rCaptureMode[0].u4Eposuretime,
                 m_rAEOutput.rCaptureMode[0].u4AfeGain, m_rAEOutput.rCaptureMode[0].u4IspGain, m_rAEOutput.rCaptureMode[0].u2FrameRate,
                 m_rAEOutput.rCaptureMode[0].i2FlareGain, m_rAEOutput.rCaptureMode[0].i2FlareOffset, m_rAEOutput.rCaptureMode[0].u4RealISO);
            break;
        case AE_PRE_CAPTURE_STATE:
            m_bAEStable = MTRUE;
            m_bAEMonitorStable = m_bAEStable;
            prepareCapParams();
            AE_LOG( "[doPreCapAE] State:%d SensorDev:%d Exp mode:%d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                    eNewAEState, m_eSensorDev, m_rAEOutput.rPreviewMode.u4ExposureMode, m_rAEOutput.rPreviewMode.u4Eposuretime,
                    m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain, m_rAEOutput.rPreviewMode.u2FrameRate,
                    m_rAEOutput.rPreviewMode.i2FlareGain, m_rAEOutput.rPreviewMode.i2FlareOffset, m_rAEOutput.rPreviewMode.u4RealISO);
            AE_LOG( "[doPreCapAE] AF Exp mode:%d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                 m_rAEOutput.rAFMode.u4ExposureMode, m_rAEOutput.rAFMode.u4Eposuretime,
                 m_rAEOutput.rAFMode.u4AfeGain, m_rAEOutput.rAFMode.u4IspGain, m_rAEOutput.rAFMode.u2FrameRate,
                 m_rAEOutput.rAFMode.i2FlareGain, m_rAEOutput.rAFMode.i2FlareOffset, m_rAEOutput.rAFMode.u4RealISO);
            AE_LOG( "[doPreCapAE] Capture Exp mode: %d Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n",
                 m_rAEOutput.rCaptureMode[0].u4ExposureMode, m_rAEOutput.rCaptureMode[0].u4Eposuretime,
                 m_rAEOutput.rCaptureMode[0].u4AfeGain, m_rAEOutput.rCaptureMode[0].u4IspGain, m_rAEOutput.rCaptureMode[0].u2FrameRate,
                 m_rAEOutput.rCaptureMode[0].i2FlareGain, m_rAEOutput.rCaptureMode[0].i2FlareOffset, m_rAEOutput.rCaptureMode[0].u4RealISO);
            break;
        case AE_CAPTURE_STATE:
            if( 0 && (m_bEnableAE == MTRUE) && (m_bMultiCap == MFALSE) &&  (mCaptureMode.u4Eposuretime > m_rAEInitInput.rAEPARAM.strAEParasetting.u4LongCaptureThres) && (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableLongCaptureCtrl == MTRUE)) {
                (mCaptureMode.u4ExposureMode == eAE_EXPO_TIME) ? (AAASensorMgr::getInstance().setCaptureParams((ESensorDev_T)m_eSensorDev, 30000, mCaptureMode.u4AfeGain))
                                               : (AAASensorMgr::getInstance().setCaptureLineBaseParams((ESensorDev_T)m_eSensorDev, mCaptureMode.u4Eposuretime, mCaptureMode.u4AfeGain));
                m_u4VsyncCnt = m_i4TotalCaptureDelayFrame;
                AE_LOG( "[%s()] Enable long time capture performance %d Shutter:%d Cnt:%d\n", __FUNCTION__, m_bMultiCap, mCaptureMode.u4Eposuretime, m_u4VsyncCnt);
            } else {
                //(mCaptureMode.u4ExposureMode == eAE_EXPO_TIME) ? (AAASensorMgr::getInstance().setCaptureParams((ESensorDev_T)m_eSensorDev, mCaptureMode.u4Eposuretime, mCaptureMode.u4AfeGain))
                //                               : (AAASensorMgr::getInstance().setCaptureLineBaseParams((ESensorDev_T)m_eSensorDev, mCaptureMode.u4Eposuretime, mCaptureMode.u4AfeGain));
                if (mCaptureMode.u4ExposureMode == eAE_EXPO_TIME){
                    AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, mCaptureMode.u4Eposuretime);
                    if (!m_pSensorGainThread){ // 0/0/2 sensor
                        AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, mCaptureMode.u4AfeGain);
                    } else { // 0/1/2 sensor
                        ThreadSensorGain::Cmd_T rCmd(0, 0, mCaptureMode.u4AfeGain, m_eSensorTG);
                        m_pSensorGainThread->postCmd(&rCmd);
                    }
                } else {
                    AAASensorMgr::getInstance().setCaptureLineBaseParams((ESensorDev_T)m_eSensorDev, mCaptureMode.u4Eposuretime, mCaptureMode.u4AfeGain);
                }
                m_u4VsyncCnt = m_i4SensorCaptureDelayFrame;
                AE_LOG( "[doCapAE] SensorDev:%d Exp. Mode = %d Capture Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n", m_eSensorDev, mCaptureMode.u4ExposureMode, mCaptureMode.u4Eposuretime,
                mCaptureMode.u4AfeGain, mCaptureMode.u4IspGain, mCaptureMode.u2FrameRate, mCaptureMode.i2FlareGain, mCaptureMode.i2FlareOffset, mCaptureMode.u4RealISO);
            }

            // Update to isp tuning
            updateAEInfo2ISP(AE_CAPTURE_STATE, 0x00);
            break;
        case AE_POST_CAPTURE_STATE:
            AE_LOG( "[PostCapAE] SensorDev:%d Capture Shutter:%d Sensor gain:%d Isp gain:%d frame rate:%d flare:%d %d ISO:%d\n", m_eSensorDev, mCaptureMode.u4Eposuretime,
                mCaptureMode.u4AfeGain, mCaptureMode.u4IspGain, mCaptureMode.u2FrameRate, mCaptureMode.i2FlareGain, mCaptureMode.i2FlareOffset, mCaptureMode.u4RealISO);

            updateAEInfo2ISP(AE_POST_CAPTURE_STATE, 0x00);
            break;
        case AE_SENSOR_PER_FRAME_CAPTURE_STATE:
//            bCaptureState = MTRUE;
        case AE_SENSOR_PER_FRAME_STATE:
            {
                if(m_SensorQueueCtrl.uOutputIndex >= AE_SENSOR_MAX_QUEUE) {
                     m_SensorQueueCtrl.uOutputIndex = 0;
                }

                if(m_SensorQueueCtrl.uInputIndex != m_SensorQueueCtrl.uOutputIndex) {
                    // frame rate control
                    // m_bSetFrameRateValue = MTRUE;
                    m_u4UpdateFrameRate_x10 = 10000000 / m_SensorQueueCtrl.rSensorParamQueue[m_SensorQueueCtrl.uOutputIndex].u4FrameDuration;

                    if(m_u4UpdateFrameRate_x10 > m_i4AEMaxFps) {
                        AE_LOG( "[AE_SENSOR_PER_FRAME_STATE] Frame rate too large:%d %d\n", m_u4UpdateFrameRate_x10, m_i4AEMaxFps);
                        m_u4UpdateFrameRate_x10 = m_i4AEMaxFps;
                    }

                    m_bSetShutterValue = MTRUE;
                    if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                        m_bSetGainValue = MTRUE;
                    }

                    m_u4UpdateShutterValue = m_SensorQueueCtrl.rSensorParamQueue[m_SensorQueueCtrl.uOutputIndex].u4ExposureTime;
                    u4ISOValue = m_SensorQueueCtrl.rSensorParamQueue[m_SensorQueueCtrl.uOutputIndex].u4Sensitivity;
                    u4ISPGain = 1024;
                    if(m_p3ANVRAM != NULL) {
                        m_u4UpdateGainValue = (u4ISOValue * 1024) / u4MinIsoGain;
                        if (m_u4UpdateGainValue > u4MaxGain) {
                            u4ISPGain = 1024 * m_u4UpdateGainValue / u4MaxGain;
                            m_u4UpdateGainValue = u4MaxGain;
                        }
                    } else {
                        AE_LOG( "[%s] NVRAM is NULL\n", __FUNCTION__);
                        m_u4UpdateGainValue = 1024;
                    }
                    // VHDR exposure setting manually
                    if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET)) {
                        m_u4LEHDRshutter = m_u4UpdateShutterValue;
                        if ((m_u4VHDRratio == 0)||(m_u4VHDRratio == 9999))
                            m_u4SEHDRshutter = m_u4UpdateShutterValue;
                        else
                            m_u4SEHDRshutter = m_u4UpdateShutterValue*1000/m_u4VHDRratio;
                        AE_LOG( "[AE_SENSOR_PER_FRAME_STATE] VHDR manual setting: LE/SE/afe/ISP : %d/%d/%d/%d \n", m_u4LEHDRshutter, m_u4SEHDRshutter, m_u4UpdateGainValue, u4ISPGain);
                    }
                    updateAEInfo2ISP(AE_SENSOR_PER_FRAME_STATE, u4ISPGain);
                    m_SensorQueueCtrl.uOutputIndex++;
                } else {
                    AE_LOG( "[%s] VDNum %d, No data input %d %d\n", __FUNCTION__, m_i4WaitVDNum, m_SensorQueueCtrl.uInputIndex, m_SensorQueueCtrl.uOutputIndex);
                }
                // For SensorDelayFrame = 1 ; ignore
                if(m_i4ShutterDelayFrames < m_i4SensorGainDelayFrames) {
                    if((m_SensorQueueCtrl.uOutputIndex-1) >= (m_i4SensorGainDelayFrames - m_i4ShutterDelayFrames)) {
                        u4Index = (m_SensorQueueCtrl.uOutputIndex-1) - m_i4SensorGainDelayFrames + m_i4ShutterDelayFrames;
                        } else {
                        u4Index = AE_SENSOR_MAX_QUEUE + (m_SensorQueueCtrl.uOutputIndex-1) - m_i4SensorGainDelayFrames + m_i4ShutterDelayFrames;
                        }

                        if(u4Index >= AE_SENSOR_MAX_QUEUE) {
                        AE_LOG( "[%s] u4Index incorrectly:%d delay:%d %d %d\n", __FUNCTION__, u4Index, m_SensorQueueCtrl.uOutputIndex-1, m_i4SensorGainDelayFrames, m_i4ShutterDelayFrames);
                        u4Index = AE_SENSOR_MAX_QUEUE-1;
                        }

                        if (m_SensorQueueCtrl.rSensorParamQueue[u4Index].u4Sensitivity != 0x00) {
                            u4ISOValue = m_SensorQueueCtrl.rSensorParamQueue[u4Index].u4Sensitivity;
                        } else {
                            u4FinalGain = (mPreviewMode.u4AfeGain*mPreviewMode.u4IspGain)>>10;
                            u4ISOValue = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain*u4FinalGain/u4PreviewBaseGain;
                        }

                    if(m_p3ANVRAM != NULL) {
                        m_u4UpdateGainValue = (u4ISOValue * 1024) / u4MinIsoGain;
                        if (m_u4UpdateGainValue > u4MaxGain) {
                            m_u4UpdateGainValue = u4MaxGain;
                        }
                    } else {
                        AE_LOG( "[%s] NVRAM is NULL\n", __FUNCTION__);
                        m_u4UpdateGainValue = 1024;
                    }
                    m_bSetGainValue = MTRUE;
                 }
             }
             break;
        case AE_TWO_SHUTTER_INIT_STATE:
            //AAASensorMgr::getInstance().set2ShutterParams((ESensorDev_T)m_eSensorDev, m_strIVHDROutputSetting.u4LEExpTimeInUS, m_strIVHDROutputSetting.u4SEExpTimeInUS, m_strIVHDROutputSetting.u4LESensorGain);
            AAASensorMgr::getInstance().set2ShutterControl((ESensorDev_T)m_eSensorDev, m_strIVHDROutputSetting.u4LEExpTimeInUS, m_strIVHDROutputSetting.u4SEExpTimeInUS);
            AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_strIVHDROutputSetting.u4LESensorGain);
            if(bUpdateSensorAWBGain) {
                strSensorAWBGain rSensorAWBGain;
                AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
                rSensorAWBGain.u4R = rCurrentIspAWBGain.i4R;
                rSensorAWBGain.u4GR = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4GB = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4B = rCurrentIspAWBGain.i4B;

                AAASensorMgr::getInstance().setSensorAWBGain((ESensorDev_T)m_eSensorDev, &rSensorAWBGain);
            }
            m_bPerframeAEFlag = m_rAEInitInput.rAEPARAM.bPerFrameHDRAESmooth;
            m_u4StableCnt = 0 ;
            updateAEInfo2ISP(AE_TWO_SHUTTER_INIT_STATE, 0x00);

            AE_LOG( "[%s] i4SensorDev:%d Delay %d/%d/%d, iVHDR Output %d/%d/%d/%d Flare gain:%d offset:%d State:%d FrameRate:%d %d %d\n", __FUNCTION__, m_eSensorDev,
                m_i4ShutterDelayFrames,
                m_i4SensorGainDelayFrames,
                m_i4IspGainDelayFrames,
                m_strIVHDROutputSetting.u4LEExpTimeInUS,
                m_strIVHDROutputSetting.u4SEExpTimeInUS,
                m_strIVHDROutputSetting.u4LESensorGain,
                m_strIVHDROutputSetting.u4LEISPGain,
                m_rAEOutput.rPreviewMode.i2FlareGain,
                m_rAEOutput.rPreviewMode.i2FlareOffset,
                m_AEState, m_rAEOutput.rPreviewMode.u2FrameRate, m_i4AEMinFps, m_i4AEMaxFps);
            break;
        case AE_TWO_SHUTTER_FRAME_STATE:

            if((m_i4AEMinFps == m_i4AEMaxFps) || (m_i4AEMaxFps <= LIB3A_AE_FRAMERATE_MODE_30FPS)) {      // frame rate control
                m_bSetFrameRateValue = MTRUE;
                m_u4UpdateFrameRate_x10 = m_i4AEMaxFps;
            }

            if(m_i4WaitVDNum == m_i4ShutterDelayFrames) {
                m_u4SEHDRshutter = m_strIVHDROutputSetting.u4SEExpTimeInUS;
                m_u4LEHDRshutter = m_strIVHDROutputSetting.u4LEExpTimeInUS;
                m_bSetShutterValue = MTRUE;
            }

            if(m_i4WaitVDNum == m_i4SensorGainDelayFrames) {
                m_u4UpdateGainValue = m_strIVHDROutputSetting.u4LESensorGain;
                m_bSetGainValue = MTRUE;
            }

            /*if(bUpdateSensorAWBGain) {
                strSensorAWBGain rSensorAWBGain;
                AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
                rSensorAWBGain.u4R = rCurrentIspAWBGain.i4R;
                rSensorAWBGain.u4GR = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4GB = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4B = rCurrentIspAWBGain.i4B;
                AAASensorMgr::getInstance().setSensorAWBGain((ESensorDev_T)m_eSensorDev, &rSensorAWBGain);
            }*/


            if(m_i4WaitVDNum == m_i4IspGainDelayFrames) {   // restart
                m_u4StableCnt = 0 ;
                if(m_bAEStable == MFALSE) {
                    m_u4StableCnt = 0 ;
                } else {
                    if(m_u4StableCnt < 0xFFFF) {
                        m_u4StableCnt++;
                    }
                }
                updateAEInfo2ISP(AE_TWO_SHUTTER_FRAME_STATE, 0x00);
            }
            AE_LOG( "[%s] i4SensorDev:%d VDNum %d, Delay %d/%d/%d, iVHDR Output %d/%d/%d/%d Flare gain:%d offset:%d State:%d FrameRate:%d %d %d\n", __FUNCTION__, m_eSensorDev, m_i4WaitVDNum,
                m_i4ShutterDelayFrames,
                m_i4SensorGainDelayFrames,
                m_i4IspGainDelayFrames,
                m_strIVHDROutputSetting.u4LEExpTimeInUS,
                m_strIVHDROutputSetting.u4SEExpTimeInUS,
                m_strIVHDROutputSetting.u4LESensorGain,
                m_strIVHDROutputSetting.u4LEISPGain,
                m_rAEOutput.rPreviewMode.i2FlareGain,
                m_rAEOutput.rPreviewMode.i2FlareOffset,
                m_AEState, m_rAEOutput.rPreviewMode.u2FrameRate, m_i4AEMinFps, m_i4AEMaxFps);
            m_i4WaitVDNum++;
            break;
        case AE_AF_RESTORE_STATE:
        default:
            break;
    }
    return S_AE_OK;
}

MRESULT AeMgr::UpdateFlare2ISP()
{
    if (m_eAEMode == LIB3A_AE_MODE_OFF){
        if(m_SensorQueueCtrl.uOutputIndex >= AE_SENSOR_MAX_QUEUE) {
             m_SensorQueueCtrl.uOutputIndex = 0;
        }
        MUINT32 u4MinIsoGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
        MUINT32 u4MaxGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MaxGain;
        MUINT32 u4ISPGain = 1024;
        MUINT32 u4ISOValue = m_SensorQueueCtrl.rSensorParamQueue[m_SensorQueueCtrl.uOutputIndex].u4Sensitivity;
        if(m_p3ANVRAM != NULL) {
            m_u4UpdateGainValue = (u4ISOValue * 1024) / u4MinIsoGain;
            if (m_u4UpdateGainValue > u4MaxGain) {
                u4ISPGain = 1024 * m_u4UpdateGainValue / u4MaxGain;
                m_u4UpdateGainValue = u4MaxGain;
            }
        } else {
            MY_LOG("[%s] NVRAM is NULL\n", __FUNCTION__);
            m_u4UpdateGainValue = 1024;
        }
        updateAEInfo2ISP(AE_SENSOR_PER_FRAME_STATE, u4ISPGain);
    }else{
        updateAEInfo2ISP(AE_AUTO_FRAMERATE_STATE, 0x00);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT16 AeMgr::getAEFaceDiffIndex()
{
 return m_i2AEFaceDiffIndex;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateSensorDelayInfo(MINT32* i4SutterDelay, MINT32* i4SensorGainDelay, MINT32* i4IspGainDelay)
{
    m_i4ShutterDelayFrames = *i4IspGainDelay - *i4SutterDelay;
    m_i4SensorGainDelayFrames = *i4IspGainDelay - *i4SensorGainDelay;
    if(*i4IspGainDelay > 2) {
        m_i4IspGainDelayFrames = *i4IspGainDelay - ISP_GAIN_DELAY_OFFSET; // for CQ0 1 delay frame
    } else {
        m_i4IspGainDelayFrames = 0; // for CQ0 1 delay frame
    }

    AE_LOG( "[%s] i4SensorDev:%d m_i4ShutterDelayFrames:%d m_i4SensorGainDelayFrames:%d Isp gain:%d %d %d %d\n", __FUNCTION__, m_eSensorDev,
        m_i4ShutterDelayFrames, m_i4SensorGainDelayFrames, m_i4IspGainDelayFrames, *i4SutterDelay, *i4SensorGainDelay, *i4IspGainDelay);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getBrightnessValue(MBOOL * bFrameUpdate, MINT32* i4Yvalue)
{
MUINT8 uYvalue[5][5];

    if(m_bFrameUpdate == MTRUE) {
        if(m_pIAeAlgo != NULL) {
            m_pIAeAlgo->getAEBlockYvalues(&uYvalue[0][0], AE_BLOCK_NO*AE_BLOCK_NO);
            * i4Yvalue = uYvalue[2][2];
        } else {
            AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
        }

        *bFrameUpdate = m_bFrameUpdate;
        m_bFrameUpdate = MFALSE;
    } else {
        * i4Yvalue = 0;
        *bFrameUpdate = MFALSE;
    }

    AE_LOG( "[%s] i4SensorDev:%d Yvalue:%d FrameUpdate:%d\n", __FUNCTION__, m_eSensorDev, * i4Yvalue, *bFrameUpdate);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::SetAETargetMode(eAETargetMODE eAETargetMode)
{
    if(m_eAETargetMode != eAETargetMode) {
       AE_LOG( "[%s] i4SensorDev:%d TargetMode:%d %d\n", __FUNCTION__, m_eSensorDev, m_eAETargetMode, eAETargetMode);
       m_eAETargetMode = eAETargetMode;
       if (m_eAETargetMode == AE_MODE_NORMAL){
           m_strIVHDROutputSetting.u4LE_SERatio_x100 = 100;
           m_u4EISExpRatio = 100;
       }
       m_bVHDRChangeFlag = MTRUE;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setEMVHDRratio(MUINT32 u4ratio)
{
    if(m_u4VHDRratio != u4ratio) {
       AE_LOG( "[%s] i4SensorDev:%d m_u4VHDRratio:%d -> %d\n", __FUNCTION__, m_eSensorDev, m_u4VHDRratio, u4ratio);
       m_u4VHDRratio = u4ratio;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updatePreviewParamsByiVHDR(strAEOutput *sAEInfo)
{
    IVHDRExpSettingInputParam_T strIVHDRInputSetting;
    IVHDRExpSettingOutputParam_T strIVHDROutputSetting;
    mVHDR_TRANSFER_Param_T strInputTransferParam;
    AE_EXP_GAIN_MODIFY_T  rSensorInputData, rSensorOutputData;

    if((m_eAEFlickerMode == LIB3A_AE_FLICKER_MODE_60HZ) || ((m_eAEFlickerMode == LIB3A_AE_FLICKER_MODE_AUTO) && (m_eAEAutoFlickerMode == LIB3A_AE_FLICKER_AUTO_MODE_60HZ))) {
        strIVHDRInputSetting.bIs60HZ = MTRUE;
        strInputTransferParam.bIs60HZ = MTRUE;
    } else {
        strIVHDRInputSetting.bIs60HZ = MFALSE;
        strInputTransferParam.bIs60HZ = MFALSE;
    }

    strIVHDRInputSetting.u4ShutterTime = sAEInfo->EvSetting.u4Eposuretime;
    strIVHDRInputSetting.u4SensorGain = sAEInfo->EvSetting.u4AfeGain; //(sAEInfo->EvSetting.u4AfeGain*sAEInfo->EvSetting.u4IspGain + 512) >> 10;
    strIVHDRInputSetting.u4IspGain = sAEInfo->EvSetting.u4IspGain; //(sAEInfo->EvSetting.u4AfeGain*sAEInfo->EvSetting.u4IspGain + 512) >> 10;

    if(m_p3ANVRAM != NULL) {
        strIVHDRInputSetting.u41xGainISO = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
        strIVHDRInputSetting.u4SaturationGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MinGain;
    } else {
        strIVHDRInputSetting.u41xGainISO = 100;
        strIVHDRInputSetting.u4SaturationGain = 1216;
        AE_LOG( "[updatePreviewParamsByiVHDR] NVRAM data is NULL\n");
    }

    if((m_bRealISOSpeed == MTRUE)&&(m_u4AEISOSpeed != 0)){ //Eng mode
           strIVHDROutputSetting.u4SEExpTimeInUS =  sAEInfo->EvSetting.u4Eposuretime ;
           strIVHDROutputSetting.u4LEExpTimeInUS =  sAEInfo->EvSetting.u4Eposuretime ;
           strIVHDROutputSetting.u4SESensorGain  =  sAEInfo->EvSetting.u4AfeGain ;
           strIVHDROutputSetting.u4LESensorGain  =  sAEInfo->EvSetting.u4AfeGain ;
           strIVHDROutputSetting.u4SEISPGain     =  sAEInfo->EvSetting.u4IspGain ;
           strIVHDROutputSetting.u4LEISPGain     =  sAEInfo->EvSetting.u4IspGain ;
    } else {
           getIVHDRExpSetting(strIVHDRInputSetting, strIVHDROutputSetting);
           strIVHDROutputSetting.u4LE_SERatio_x100 = strIVHDROutputSetting.u4LEExpTimeInUS *100 / strIVHDROutputSetting.u4SEExpTimeInUS;
    }

    AE_LOG( "[%s] i4SensorDev:%d iVHDR 60Hz:%d Shutter:%d Gain:%d %d %d 1xGainISO:%d SatGain:%d Workaround:%d SE:%d %d %d LE:%d %d %d Ratio:%d\n", __FUNCTION__, m_eSensorDev,
                    strIVHDRInputSetting.bIs60HZ,
                    strIVHDRInputSetting.u4ShutterTime,
                    strIVHDRInputSetting.u4SensorGain,
                    sAEInfo->EvSetting.u4AfeGain,
                    sAEInfo->EvSetting.u4IspGain,
                    strIVHDRInputSetting.u41xGainISO,
                    strIVHDRInputSetting.u4SaturationGain,
                    strIVHDROutputSetting.bEnableWorkaround,
                    strIVHDROutputSetting.u4SEExpTimeInUS,
                    strIVHDROutputSetting.u4SESensorGain,
                    strIVHDROutputSetting.u4SEISPGain,
                    strIVHDROutputSetting.u4LEExpTimeInUS,
                    strIVHDROutputSetting.u4LESensorGain,
                    strIVHDROutputSetting.u4LEISPGain,
                    strIVHDROutputSetting.u4LE_SERatio_x100);

    if(m_eAETargetMode == AE_MODE_MVHDR_TARGET) {   // mVHDR mode used
        strInputTransferParam.bSEInput = isSESetting();
        strInputTransferParam.u2SelectMode = m_rSensorVCInfo.u2VCModeSelect;
        strInputTransferParam.i4LV = sAEInfo->Bv + 50;
        getmVHDRExpSetting(strInputTransferParam, strIVHDROutputSetting);
        strIVHDROutputSetting.u4LE_SERatio_x100 = strIVHDROutputSetting.u4LEExpTimeInUS *100 / strIVHDROutputSetting.u4SEExpTimeInUS;
        AE_LOG( "[%s] i4SensorDev:%d mVHDR SE:%d %d %d LE:%d %d %d Ratio:%d\n", __FUNCTION__, m_eSensorDev,
                    strIVHDROutputSetting.u4SEExpTimeInUS,
                    strIVHDROutputSetting.u4SESensorGain,
                    strIVHDROutputSetting.u4SEISPGain,
                    strIVHDROutputSetting.u4LEExpTimeInUS,
                    strIVHDROutputSetting.u4LESensorGain,
                    strIVHDROutputSetting.u4LEISPGain,
                    strIVHDROutputSetting.u4LE_SERatio_x100);
    }

    // LE time
    rSensorInputData.u4SensorExpTime = strIVHDROutputSetting.u4LEExpTimeInUS*101/100;
    rSensorInputData.u4SensorGain = strIVHDROutputSetting.u4LESensorGain*100/101;
    rSensorInputData.u4IspGain = strIVHDROutputSetting.u4LEISPGain;

    if(m_bRealISOSpeed == MTRUE){ //Eng mode

           rSensorOutputData.u4SensorExpTime =  strIVHDROutputSetting.u4LEExpTimeInUS ;
           rSensorOutputData.u4SensorGain  =  strIVHDROutputSetting.u4LESensorGain ;
           rSensorOutputData.u4IspGain     =  strIVHDROutputSetting.u4LEISPGain ;

    } else {
           if(m_pIAeAlgo != NULL) {
               m_pIAeAlgo->switchSensorExposureGain(MFALSE, rSensorInputData, rSensorOutputData);   // send to 3A to calculate the exposure time and gain
           } else {
               AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
           }
           // check if gain is less than min saturation gain
           if (rSensorOutputData.u4IspGain < 1024){
               rSensorOutputData.u4SensorExpTime = rSensorInputData.u4SensorExpTime;
               rSensorOutputData.u4SensorGain = rSensorInputData.u4SensorGain;
               rSensorOutputData.u4IspGain = rSensorInputData.u4IspGain;
               AE_LOG( "[updatePreviewParamsByzVHDR] Isp gain from switchSensorExposureGain should be larger than 1x , revert before setting \n");
           }
    }
    m_strIVHDROutputSetting.u4LEExpTimeInUS = rSensorOutputData.u4SensorExpTime;
    m_strIVHDROutputSetting.u4LESensorGain = rSensorOutputData.u4SensorGain;
    m_strIVHDROutputSetting.u4LEISPGain = rSensorOutputData.u4IspGain;

    // SE time
    m_strIVHDROutputSetting.u4SEExpTimeInUS =  strIVHDROutputSetting.u4SEExpTimeInUS*strIVHDROutputSetting.u4SESensorGain / m_strIVHDROutputSetting.u4LESensorGain * strIVHDROutputSetting.u4SEISPGain / m_strIVHDROutputSetting.u4LEISPGain;
    if(m_strIVHDROutputSetting.u4SEExpTimeInUS > m_strIVHDROutputSetting.u4LEExpTimeInUS) {
        m_strIVHDROutputSetting.u4SEExpTimeInUS = m_strIVHDROutputSetting.u4LEExpTimeInUS;
    }
    m_strIVHDROutputSetting.u4SESensorGain = m_strIVHDROutputSetting.u4LESensorGain;
    m_strIVHDROutputSetting.u4SEISPGain = m_strIVHDROutputSetting.u4LEISPGain;

    m_strIVHDROutputSetting.u4LE_SERatio_x100 = 100*m_strIVHDROutputSetting.u4LEExpTimeInUS / m_strIVHDROutputSetting.u4SEExpTimeInUS;
    m_strIVHDROutputSetting.bEnableWorkaround = strIVHDROutputSetting.bEnableWorkaround;

    if(m_strIVHDROutputSetting.bEnableWorkaround == MTRUE) {
        m_u4AFSGG1Gain = 16*m_strIVHDROutputSetting.u4SEISPGain/1024;
    } else {
        m_u4AFSGG1Gain = 16;
    }

    if(m_strIVHDROutputSetting.u4LE_SERatio_x100 > 800) {
        AE_LOG( "[%s] i4SensorDev:%d Ratio:%d\n", __FUNCTION__, m_eSensorDev, m_strIVHDROutputSetting.u4LE_SERatio_x100);
        m_strIVHDROutputSetting.u4LE_SERatio_x100 = 800;
    }

    m_rSensorVCInfo.u2VCShutterRatio = m_strIVHDROutputSetting.u4LE_SERatio_x100 * 101 / 10000;

    AE_LOG( "[%s] i4SensorDev:%d iVHDR workound:%d New SE:%d %d %d LE:%d %d %d Ratio:%d SGG1Gain:%d u2VCShutterRatio:%d\n", __FUNCTION__, m_eSensorDev,
                    m_strIVHDROutputSetting.bEnableWorkaround,
                    m_strIVHDROutputSetting.u4SEExpTimeInUS,
                    m_strIVHDROutputSetting.u4SESensorGain,
                    m_strIVHDROutputSetting.u4SEISPGain,
                    m_strIVHDROutputSetting.u4LEExpTimeInUS,
                    m_strIVHDROutputSetting.u4LESensorGain,
                    m_strIVHDROutputSetting.u4LEISPGain,
                    m_strIVHDROutputSetting.u4LE_SERatio_x100,
                    m_u4AFSGG1Gain,
                    m_rSensorVCInfo.u2VCShutterRatio);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updatePreviewParamsByzVHDR(strAEOutput *sAEInfo)
{
    ZVHDRExpSettingInputParam_T strZVHDRInputSetting;
    ZVHDRExpSettingOutputParam_T strZVHDROutputSetting;
    memset(&strZVHDROutputSetting, 0, sizeof(ZVHDRExpSettingOutputParam_T));
    rVHDRExpSettingInfo_T rZVHDROutputInfo;
    MINT32 i4TotalGain = (sAEInfo->EvSetting.u4AfeGain * sAEInfo->EvSetting.u4IspGain + 512) >> 10;

    AE_EXP_GAIN_MODIFY_T  rSensorInputData, rSensorOutputData;
    memset(&rSensorOutputData, 0, sizeof(AE_EXP_GAIN_MODIFY_T));

    if((m_eAEFlickerMode == LIB3A_AE_FLICKER_MODE_60HZ) || ((m_eAEFlickerMode == LIB3A_AE_FLICKER_MODE_AUTO) && (m_eAEAutoFlickerMode == LIB3A_AE_FLICKER_AUTO_MODE_60HZ))) {
        strZVHDRInputSetting.bIs60HZ = MTRUE;
    } else {
        strZVHDRInputSetting.bIs60HZ = MFALSE;
    }

    strZVHDRInputSetting.u4ShutterTime = sAEInfo->EvSetting.u4Eposuretime;
    strZVHDRInputSetting.u4SensorGain = sAEInfo->EvSetting.u4AfeGain;
    strZVHDRInputSetting.u4ISPGain = sAEInfo->EvSetting.u4IspGain;
    strZVHDRInputSetting.i4LV = sAEInfo->Bv + 50;
    strZVHDRInputSetting.bAEStable = sAEInfo->bAEStable;
    strZVHDRInputSetting.rAutoFlicker =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoFlicker;
    strZVHDRInputSetting.rAutoSmooth =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoSmooth;
    strZVHDRInputSetting.rGGyroSensor =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoBright.rGGyroSensor;
    strZVHDRInputSetting.HdrEvSetting = sAEInfo->HdrEvSetting;
    /*strZVHDRInputSetting.rGGyroInfo.i4Acce[0] = gAcceInfo[0];
    strZVHDRInputSetting.rGGyroInfo.i4Acce[1] = gAcceInfo[1];
    strZVHDRInputSetting.rGGyroInfo.i4Acce[2] = gAcceInfo[2];
    strZVHDRInputSetting.rGGyroInfo.i4Gyro[0] = gGyroInfo[0];
    strZVHDRInputSetting.rGGyroInfo.i4Gyro[1] = gGyroInfo[1];
    strZVHDRInputSetting.rGGyroInfo.i4Gyro[2] = gGyroInfo[2];*/

    if(m_p3ANVRAM != NULL) {
        strZVHDRInputSetting.u41xGainISO = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
        strZVHDRInputSetting.u4SaturationGain = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MinGain;
    } else {
        strZVHDRInputSetting.u41xGainISO = 100;
        strZVHDRInputSetting.u4SaturationGain = 1216;
        AE_LOG( "[updatePreviewParamsByzVHDR] NVRAM data is NULL\n");
    }

    AE_LOG( "[updatePreviewParamsByzVHDR] AE mgr i4HdrRatio = %d \n",sAEInfo->HdrEvSetting.i4HdrRatio[0]);

    if((m_bRealISOSpeed == MTRUE) && (m_u4VHDRratio!=0) && (m_u4VHDRratio!=9999)){ //EM VHDR ratio
           strZVHDROutputSetting.u4LEExpTimeInUS  = sAEInfo->EvSetting.u4Eposuretime ;
           strZVHDROutputSetting.u4SEExpTimeInUS =  sAEInfo->EvSetting.u4Eposuretime *1000 / m_u4VHDRratio ;
           strZVHDROutputSetting.u4LESensorGain  =  sAEInfo->EvSetting.u4AfeGain ;
           strZVHDROutputSetting.u4SESensorGain  =  sAEInfo->EvSetting.u4AfeGain ;
           strZVHDROutputSetting.u4LEISPGain     =  sAEInfo->EvSetting.u4IspGain ;
           strZVHDROutputSetting.u4SEISPGain     =  sAEInfo->EvSetting.u4IspGain ;
           strZVHDROutputSetting.u4LE_SERatio_x100 = m_u4VHDRratio / 1000 *100;
           strZVHDROutputSetting.bEnableWorkaround = MFALSE;
           strZVHDRInputSetting.bAEStable = sAEInfo->bAEStable;
           strZVHDRInputSetting.rAutoFlicker =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoFlicker;
           strZVHDRInputSetting.rAutoSmooth =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoSmooth;
           strZVHDRInputSetting.rGGyroSensor =  m_rAEInitInput.rAEPARAM.pHdrAECFG->rHdrAutoEnhance.rAutoBright.rGGyroSensor;
           strZVHDRInputSetting.HdrEvSetting = sAEInfo->HdrEvSetting;
           /*strZVHDRInputSetting.rGGyroInfo.i4Acce[0] = gAcceInfo[0];
           strZVHDRInputSetting.rGGyroInfo.i4Acce[1] = gAcceInfo[1];
           strZVHDRInputSetting.rGGyroInfo.i4Acce[2] = gAcceInfo[2];
           strZVHDRInputSetting.rGGyroInfo.i4Gyro[0] = gGyroInfo[0];
           strZVHDRInputSetting.rGGyroInfo.i4Gyro[1] = gGyroInfo[1];
           strZVHDRInputSetting.rGGyroInfo.i4Gyro[2] = gGyroInfo[2];*/
           AE_LOG( "[updatePreviewParamsByzVHDR] Manual Ratio = %d \n",m_u4VHDRratio);
    } else {

        AE_LOG( "[%s] HDR gyro info AcceInfo:(%d,%d,%d) GyroInfo:(%d,%d,%d)\n",__FUNCTION__,
                 strZVHDRInputSetting.rGGyroInfo.i4Acce[0], strZVHDRInputSetting.rGGyroInfo.i4Acce[1], strZVHDRInputSetting.rGGyroInfo.i4Acce[2],
                 strZVHDRInputSetting.rGGyroInfo.i4Gyro[0], strZVHDRInputSetting.rGGyroInfo.i4Gyro[1], strZVHDRInputSetting.rGGyroInfo.i4Gyro[2]);
        getZVHDRExpSetting(strZVHDRInputSetting, strZVHDROutputSetting);
        if(m_i4HdrOnOff != toLiteral(HDRDetectionResult::NONE)) {
            m_i4HdrOnOff = (strZVHDROutputSetting.HdrEvSetting.i4HdrOnOff == 1) ?
            toLiteral(HDRDetectionResult::HDR) :
            toLiteral(HDRDetectionResult::NORMAL);
        }
        AE_LOG_IF(m_3ALogEnable,"[%s] m_i4HdrOnOff:%d\n", __FUNCTION__, m_i4HdrOnOff);

    }
    strZVHDROutputSetting.u4SESensorGain = strZVHDROutputSetting.u4LESensorGain;
    strZVHDROutputSetting.u4SEISPGain = strZVHDROutputSetting.u4LEISPGain;
    AE_LOG( "[%s] i4SensorDev:%d zVHDR 60Hz:%d Shutter:%d Gain:%d %d %d 1xGainISO:%d SatGain:%d Workaround:%d SE:%d %d %d LE:%d %d %d Ratio:%d\n", __FUNCTION__, m_eSensorDev,
                    strZVHDRInputSetting.bIs60HZ,
                    strZVHDRInputSetting.u4ShutterTime,
                    i4TotalGain,
                    sAEInfo->EvSetting.u4AfeGain,
                    sAEInfo->EvSetting.u4IspGain,
                    strZVHDRInputSetting.u41xGainISO,
                    strZVHDRInputSetting.u4SaturationGain,
                    strZVHDROutputSetting.bEnableWorkaround,
                    strZVHDROutputSetting.u4SEExpTimeInUS,
                    strZVHDROutputSetting.u4SESensorGain,
                    strZVHDROutputSetting.u4SEISPGain,
                    strZVHDROutputSetting.u4LEExpTimeInUS,
                    strZVHDROutputSetting.u4LESensorGain,
                    strZVHDROutputSetting.u4LEISPGain,
                    strZVHDROutputSetting.u4LE_SERatio_x100);

    // LE time
    rSensorInputData.u4SensorExpTime = strZVHDROutputSetting.u4LEExpTimeInUS;
    rSensorInputData.u4SensorGain = strZVHDROutputSetting.u4LESensorGain;
    rSensorInputData.u4IspGain = strZVHDROutputSetting.u4LEISPGain;

    // Match with AE pline
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->switchSensorExposureGain(MFALSE, rSensorInputData, rSensorOutputData);   // send to 3A to calculate the exposure time and gain
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    // check if gain is less than min saturation gain
    if (rSensorOutputData.u4IspGain < 1024){
        rSensorOutputData.u4SensorExpTime = rSensorInputData.u4SensorExpTime;
        rSensorOutputData.u4SensorGain = rSensorInputData.u4SensorGain;
        rSensorOutputData.u4IspGain = rSensorInputData.u4IspGain;
        AE_LOG( "[updatePreviewParamsByzVHDR] Isp gain from switchSensorExposureGain should be larger than 1x , revert before setting \n");
    }


    m_strIVHDROutputSetting.u4LEExpTimeInUS = rSensorOutputData.u4SensorExpTime;
    m_strIVHDROutputSetting.u4LESensorGain = rSensorOutputData.u4SensorGain;
    m_strIVHDROutputSetting.u4LEISPGain = rSensorOutputData.u4IspGain;

    // SE time
    m_strIVHDROutputSetting.u4SEExpTimeInUS =  strZVHDROutputSetting.u4SEExpTimeInUS*strZVHDROutputSetting.u4SESensorGain / m_strIVHDROutputSetting.u4LESensorGain * strZVHDROutputSetting.u4SEISPGain / m_strIVHDROutputSetting.u4LEISPGain;
    if(m_strIVHDROutputSetting.u4SEExpTimeInUS > m_strIVHDROutputSetting.u4LEExpTimeInUS) {
        m_strIVHDROutputSetting.u4SEExpTimeInUS = m_strIVHDROutputSetting.u4LEExpTimeInUS;
    }
    m_strIVHDROutputSetting.u4SESensorGain = m_strIVHDROutputSetting.u4LESensorGain;
    m_strIVHDROutputSetting.u4SEISPGain = m_strIVHDROutputSetting.u4LEISPGain;

    m_strIVHDROutputSetting.u4LE_SERatio_x100 = 100*m_strIVHDROutputSetting.u4LEExpTimeInUS / m_strIVHDROutputSetting.u4SEExpTimeInUS;
    m_strIVHDROutputSetting.bEnableWorkaround = strZVHDROutputSetting.bEnableWorkaround;

    if(m_strIVHDROutputSetting.bEnableWorkaround == MTRUE) {
        m_u4AFSGG1Gain = 16*m_strIVHDROutputSetting.u4SEISPGain/1024;
    } else {
        m_u4AFSGG1Gain = 16;
    }

    if(m_strIVHDROutputSetting.u4LE_SERatio_x100 > 800) {
        AE_LOG( "[%s] i4SensorDev:%d Ratio:%d\n", __FUNCTION__, m_eSensorDev, m_strIVHDROutputSetting.u4LE_SERatio_x100);
        m_strIVHDROutputSetting.u4LE_SERatio_x100 = 800;
    }

    sAEInfo->HdrEvSetting = strZVHDROutputSetting.HdrEvSetting;

    AE_LOG( "[%s] i4RMGk = %d, i4RMGt = %d\n", __FUNCTION__, sAEInfo->HdrEvSetting.i4RMGk, sAEInfo->HdrEvSetting.i4RMGt);
    if(m_pIAeAlgo != NULL) {

        /*
        *   HDR information update
        */
        rZVHDROutputInfo.bEnableWorkaround = m_strIVHDROutputSetting.bEnableWorkaround;
        rZVHDROutputInfo.u4LEExpTimeInUS = m_strIVHDROutputSetting.u4LEExpTimeInUS;
        rZVHDROutputInfo.u4LEISPGain = m_strIVHDROutputSetting.u4LEISPGain;
        rZVHDROutputInfo.u4LESensorGain = m_strIVHDROutputSetting.u4LESensorGain;
        rZVHDROutputInfo.u4LE_SERatio_x100 = m_strIVHDROutputSetting.u4LE_SERatio_x100;
        rZVHDROutputInfo.u4SEExpTimeInUS = m_strIVHDROutputSetting.u4SEExpTimeInUS;
        rZVHDROutputInfo.u4SEISPGain = m_strIVHDROutputSetting.u4SEISPGain;
        rZVHDROutputInfo.u4SESensorGain = m_strIVHDROutputSetting.u4SESensorGain;
        rZVHDROutputInfo.HdrEvSetting =  strZVHDROutputSetting.HdrEvSetting;
        m_pIAeAlgo->setHdrAEInfo(rZVHDROutputInfo);
    }

    AE_LOG( "[%s] i4SensorDev:%d zVHDR workound:%d New SE:%d %d %d LE:%d %d %d Ratio:%d SGG1Gain:%d\n", __FUNCTION__, m_eSensorDev,
                    m_strIVHDROutputSetting.bEnableWorkaround,
                    m_strIVHDROutputSetting.u4SEExpTimeInUS,
                    m_strIVHDROutputSetting.u4SESensorGain,
                    m_strIVHDROutputSetting.u4SEISPGain,
                    m_strIVHDROutputSetting.u4LEExpTimeInUS,
                    m_strIVHDROutputSetting.u4LESensorGain,
                    m_strIVHDROutputSetting.u4LEISPGain,
                    m_strIVHDROutputSetting.u4LE_SERatio_x100,
                    m_u4AFSGG1Gain);
    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAESensorActiveCycle(MINT32* i4ActiveCycle)
{
    * i4ActiveCycle = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET + 1;
    AE_LOG_IF(m_3ALogEnable,"[%s] i4SensorDev:%d Cycle:%d\n", __FUNCTION__, m_eSensorDev, *i4ActiveCycle);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setVideoDynamicFrameRate(MBOOL bVdoDynamicFps)
{
    if(m_bVideoDynamic != bVdoDynamicFps) {
       AE_LOG( "[%s] i4SensorDev:%d TargetMode:%d %d\n", __FUNCTION__, m_eSensorDev, m_bVideoDynamic, bVdoDynamicFps);
       m_bVideoDynamic = bVdoDynamicFps;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::modifyAEPlineTableLimitation(MBOOL bEnable, MBOOL bEquivalent, MUINT32 u4IncreaseISO_x100, MUINT32 u4IncreaseShutter_x100)
{
    if((m_rAEPLineLimitation.bEnable != bEnable) || (m_rAEPLineLimitation.bEquivalent != bEquivalent) || (m_rAEPLineLimitation.u4IncreaseISO_x100 != u4IncreaseISO_x100) || (m_rAEPLineLimitation.u4IncreaseShutter_x100 != u4IncreaseShutter_x100)) {
        AE_LOG( "[%s] i4SensorDev:%d Enable:%d %d Equivalent:%d %d IncreaseISO:%d %d IncreaseShutter: %d %d\n", __FUNCTION__, m_eSensorDev,
                      m_rAEPLineLimitation.bEnable, bEnable,
                      m_rAEPLineLimitation.bEquivalent, bEquivalent,
                      m_rAEPLineLimitation.u4IncreaseISO_x100, u4IncreaseISO_x100,
                      m_rAEPLineLimitation.u4IncreaseShutter_x100, u4IncreaseShutter_x100);
        m_rAEPLineLimitation.bEnable = bEnable;
        m_rAEPLineLimitation.bEquivalent = bEquivalent;
        m_rAEPLineLimitation.u4IncreaseISO_x100 = u4IncreaseISO_x100;
        m_rAEPLineLimitation.u4IncreaseShutter_x100 = u4IncreaseShutter_x100;
    }
    return S_AE_OK;
}

/*******************************************************************************
*
********************************************************************************/
MRESULT AeMgr::ModifyCaptureParamsBySensorMode(MINT32 i4newSensorMode, MINT32 i4oldSensorMode)
{
    MINT32 err;
    MUINT32 u4AFEGain = 0, u4IspGain = 1024, u4BinningRatio = 1;
    MUINT32 u4NewSensitivityRatio = 1024, u4OldSensitivityRatio = 1024, u4SensitivityRatio = 1024;
    strAEInput rAEInput;
    strAEOutput rAEOutput;
    MBOOL bStrobeOn;

    if(m_p3ANVRAM == NULL) {
        AE_LOG( "[%s] i4SensorDev:%d Nvram 3A pointer is NULL\n", __FUNCTION__, m_eSensorDev);
        return S_AE_OK;
    }

    // Update new sensor mode senstivity ratio
    switch(i4newSensorMode) {
        case ESensorMode_Capture:
            u4NewSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Cap2PreRatio;
            break;
        case ESensorMode_Video:
            u4NewSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video2PreRatio;
            break;
        case ESensorMode_SlimVideo1:
            u4NewSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video12PreRatio;
            break;
        case ESensorMode_SlimVideo2:
            u4NewSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video22PreRatio;
            break;
        case ESensorMode_Preview:
        default:
            u4NewSensitivityRatio = 1024;
            break;
    }

    // Update old sensor mode senstivity ratio
    switch(i4oldSensorMode) {
        case ESensorMode_Capture:
            u4OldSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Cap2PreRatio;
            break;
        case ESensorMode_Video:
            u4OldSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video2PreRatio;
            break;
        case ESensorMode_SlimVideo1:
            u4OldSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video12PreRatio;
            break;
        case ESensorMode_SlimVideo2:
            u4OldSensitivityRatio = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4Video22PreRatio;
            break;
        case ESensorMode_Preview:
        default:
            u4OldSensitivityRatio = 1024;
            break;
    }

    if(u4OldSensitivityRatio != 0) {
        u4SensitivityRatio = 1024 *u4NewSensitivityRatio  / u4OldSensitivityRatio;
    } else {
        u4SensitivityRatio = 1024;
        AE_LOG( "[%s] i4SensorDev:%d u4OldSensitivityRatio is zero\n", __FUNCTION__, m_eSensorDev);
    }

    if(u4SensitivityRatio <= 300) {
        u4BinningRatio = 4;
    } else if(u4SensitivityRatio <= 450) {
        u4BinningRatio = 3;
    } else if(u4SensitivityRatio <= 768) {
        u4BinningRatio = 2;
    } else {
        u4BinningRatio = 1;
    }

    if(i4newSensorMode != ESensorMode_Capture) {
        mCaptureMode.u4Eposuretime = mCaptureMode.u4Eposuretime/u4BinningRatio;
        mCaptureMode.i2FlareOffset = m_rAEOutput.rPreviewMode.i2FlareOffset;
        mCaptureMode.i2FlareGain = m_rAEOutput.rPreviewMode.i2FlareGain;
        AE_LOG( "[%s] i4SensorDev:%d New Capture Shutter:%d Binning:%d Flare:%d %d\n", __FUNCTION__, m_eSensorDev, mCaptureMode.u4Eposuretime, u4BinningRatio,
                                mCaptureMode.i2FlareOffset, mCaptureMode.i2FlareGain);
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getAESGG1Gain(MUINT32 *pSGG1Gain)
{
    *pSGG1Gain = m_u4AFSGG1Gain;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::switchCapureDiffEVState(MINT8 iDiffEV, strAEOutput &aeoutput)
{
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->switchCapureDiffEVState(&aeoutput, iDiffEV);
        AE_LOG( "[%s()] i4SensorDev:%d iDiffEV:%d\n", __FUNCTION__, m_eSensorDev, iDiffEV);
    } else {
        AE_LOG( "[%s()] The AE algo class is NULL  i4SensorDev = %d line:%d", __FUNCTION__, m_eSensorDev, __LINE__);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::enableAEOneShotControl(MBOOL bAEControl)
{
    if(m_bAEOneShotControl != bAEControl) {
        AE_LOG( "[%s] i4SensorDev:%d One Shot control old:%d new:%d\n", __FUNCTION__, m_eSensorDev, m_bAEOneShotControl, bAEControl);
       m_bAEOneShotControl = bAEControl;
    }
    return S_AE_OK;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::startSensorPerFrameControl(MUINT32 uTestidx)
{
    if(m_u4IndexTestCnt < 300) {

        switch(uTestidx) {
                case 1: // Shutter delay frames [Exp:10ms <-> 20ms, 1x ]
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                    } else {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000*2;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                    }
                    break;
                case 2: // Gain delay frames [Gain:2x <-> 4x , 10ms ]
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                    } else {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024*4;
                    }
                    break;
                case 3: // Delay frames IT [20ms/2x <-> 10ms/4x ]
                    if( m_u4IndexTestCnt%20 < 10 ) { // 0-9 20ms/1x
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 20000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //0-9 1x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                        } else if(m_u4IndexTestCnt%20 == 0){ // 0 2x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*4;
                        } else{                              // 1-9 1x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                        }
                    } else {                        //10-19 10ms/2x
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //10-19 2x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*4;
                        } else if(m_u4IndexTestCnt%20 == 10){ // 10 1x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                        } else{                              // 11-19 2x
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*4;
                        }
                    }
                    break;
                case 4: // Perframe shutter command [10ms<->20ms,1x]
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000*(m_u4IndexTestCnt%2 + 1);
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                    break;
                case 5: // Perframe gain command [2x<->4x,10ms]
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2*(m_u4IndexTestCnt%2 + 1);
                    break;
                case 6: // Perframe command IT [10ms/6x<->30ms/2x]
                    if(m_u4IndexTestCnt%2 == 0) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*6;
                        } else {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                        }
                    } else if(m_u4IndexTestCnt%2 == 1) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000*3;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                             m_rAEOutput.rPreviewMode.u4AfeGain = 1024*2;
                        } else {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*6;
                        }
                    }
                    break;
                case 7: // Perframe framerate command [10ms/5x <-> 50ms/1x]
                    if(m_u4IndexTestCnt%2 == 0) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*5;
                        } else {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                        }
                    } else if(m_u4IndexTestCnt%2 == 1) {
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000*5;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                        } else {
                            m_rAEOutput.rPreviewMode.u4AfeGain = 1024*5;
                        }
                    }
                    break;
                case 8: // Shutter Linearity
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 5000*((m_u4IndexTestCnt%160)/10 + 1);
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
                    break;
                case 9: // Gain Linearity
                        m_rAEOutput.rPreviewMode.u4Eposuretime = 10000;
                        m_rAEOutput.rPreviewMode.u4AfeGain = 1024*((m_u4IndexTestCnt%160)/10 + 1);
                    break;
                case 11:
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*2;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    } else {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*1;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    }
                    break;
                case 12:
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*1;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    } else {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*1;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                    }
                    break;
                case 13: // Delay frames IT [30ms/10ms/2x <-> 30ms/30ms/6x ]
                    if( m_u4IndexTestCnt%20 < 10 ) { // 0-9 20ms/1x
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 20000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //0-9 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else if(m_u4IndexTestCnt%20 == 0){ // 0 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        } else{                              // 1-9 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        }
                    } else {                        //10-19 10ms/2x
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //10-19 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        } else if(m_u4IndexTestCnt%20 == 10){ // 10 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else{                              // 11-19 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        }
                    }
                    break;
                case 14: // Perframe shutter command [10ms<->20ms,1x]
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*(m_u4IndexTestCnt%2 + 1);
                        m_strIVHDROutputSetting.u4SESensorGain = 1024;
                    break;
                case 15: // Perframe gain command [2x<->4x,10ms]
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*2*(m_u4IndexTestCnt%2 + 1);
                    break;
                case 16: // Perframe command IT [10ms/6x<->30ms/2x]
                    if(m_u4IndexTestCnt%2 == 0) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*6;
                        } else {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        }
                    } else if(m_u4IndexTestCnt%2 == 1) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*3;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*6;
                        }
                    }
                    break;
                case 21:
                    m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*4;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    } else {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*2;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    }
                    break;
                case 22:
                    m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                    if( m_u4IndexTestCnt%20 < 10 ) {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*2;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*1;
                    } else {
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*2;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                    }
                    break;
                case 23: // Delay frames IT [30ms/10ms/2x <-> 30ms/30ms/6x ]
                    if( m_u4IndexTestCnt%20 < 10 ) { // 0-9 20ms/1x
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 40000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //0-9 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else if(m_u4IndexTestCnt%20 == 0){ // 0 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        } else{                              // 1-9 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        }
                    } else {                        //10-19 10ms/2x
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 20000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) { //10-19 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        } else if(m_u4IndexTestCnt%20 == 10){ // 10 1x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else{                              // 11-19 2x
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        }
                    }
                    break;
                case 24: // Perframe shutter command [10ms<->20ms,1x]
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 10000*(m_u4IndexTestCnt%2 + 1);
                        m_strIVHDROutputSetting.u4SESensorGain = 1024;
                    break;
                case 25: // Perframe gain command [2x<->4x,10ms]
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 20000;
                        m_strIVHDROutputSetting.u4SESensorGain = 1024*2*(m_u4IndexTestCnt%2 + 1);
                    break;
                case 26: // Perframe command IT [10ms/6x<->30ms/2x]
                    if(m_u4IndexTestCnt%2 == 0) {
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 20000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        } else {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        }
                    } else if(m_u4IndexTestCnt%2 == 1) {
                        m_strIVHDROutputSetting.u4SEExpTimeInUS = 10000;
                        m_strIVHDROutputSetting.u4LEExpTimeInUS = 40000;
                        if(m_i4ShutterDelayFrames == m_i4SensorGainDelayFrames) {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*2;
                        } else {
                            m_strIVHDROutputSetting.u4SESensorGain = 1024*4;
                        }
                    }
                    break;
                default:
                    AE_LOG( "[startSensorPerFrameControl] Test item:%d isn't supported \n", uTestidx);
                    break;
            }

        m_rAEOutput.rPreviewMode.u4IspGain = 1024;
        m_strIVHDROutputSetting.u4SEISPGain = 1024;
        if ((uTestidx>10)&&(uTestidx<20)) {
            m_strIVHDROutputSetting.u4SEExpTimeInUS = m_strIVHDROutputSetting.u4LEExpTimeInUS;
            m_strIVHDROutputSetting.u4LE_SERatio_x100 = 100*m_strIVHDROutputSetting.u4LEExpTimeInUS/m_strIVHDROutputSetting.u4SEExpTimeInUS;
        }
        m_u4IndexTestCnt++;
    } else {
        m_rAEOutput.rPreviewMode.u4Eposuretime = 1000;
        m_rAEOutput.rPreviewMode.u4AfeGain = 1024;
        m_rAEOutput.rPreviewMode.u4IspGain = 1024;
    }
    if (uTestidx < 10){
        AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4Eposuretime);
        AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_rAEOutput.rPreviewMode.u4AfeGain);
        IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, m_rAEOutput.rPreviewMode.u4IspGain>>1);
        AE_LOG("[%s()] testid:%d u4Index:%03d avgY:%03d Shutter:%d AfeGain:%d ISPGain:%d\n", __FUNCTION__ ,uTestidx , m_u4IndexTestCnt-1, m_pIAeAlgo->getBrightnessAverageValue(), m_rAEOutput.rPreviewMode.u4Eposuretime, m_rAEOutput.rPreviewMode.u4AfeGain, m_rAEOutput.rPreviewMode.u4IspGain);
    }else{
        AAASensorMgr::getInstance().set2ShutterControl((ESensorDev_T)m_eSensorDev, m_strIVHDROutputSetting.u4LEExpTimeInUS, m_strIVHDROutputSetting.u4SEExpTimeInUS);
        AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_strIVHDROutputSetting.u4SESensorGain);
        IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, m_strIVHDROutputSetting.u4SEISPGain>>1);
        updateAEInfo2ISP(AE_TWO_SHUTTER_FRAME_STATE, 0x00);
        m_i4LESE_Ratio = m_strIVHDROutputSetting.u4LE_SERatio_x100;
        AE_LOG("[%s()] testid:%d u4Index:%03d avgY:%03d LE/SE:%d/%d Afe:%d ISP:%d LSEratio:%d \n", __FUNCTION__ ,uTestidx ,
            m_u4IndexTestCnt-1, m_pIAeAlgo->getBrightnessAverageValue(),
            m_strIVHDROutputSetting.u4LEExpTimeInUS, m_strIVHDROutputSetting.u4SEExpTimeInUS,
            m_strIVHDROutputSetting.u4SESensorGain, m_strIVHDROutputSetting.u4SEISPGain, m_i4LESE_Ratio);
    }



    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::IsNeedUpdateSensor()
{
    return (m_bSetShutterValue | m_bSetGainValue | m_bSetFrameRateValue);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateSensorbyI2CBufferMode()
{
    MINT32 err = S_AE_OK;

    if((m_bSetShutterValue)&&(m_u4UpdateShutterValue != m_u4PreExposureTime)) {    // update shutter value

        AaaTimer localTimer("SetSensorShutterBufferMode", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
        err = AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, m_u4UpdateShutterValue);
        localTimer.End();
        AE_LOG( "[%s()]  Exp = %d -> %d \n", __FUNCTION__,m_u4PreExposureTime, m_u4UpdateShutterValue);
        if (FAILED(err)) {
            CAM_LOGE("AAASensorMgr::getInstance().setSensorExpTimeBufferMode fail\n");
        }

        m_bSetShutterValue = MFALSE;
        return S_AE_OK;
    }

    if((m_bSetGainValue)&&(m_u4UpdateGainValue!= m_u4PreSensorGain)) {    // update sensor gain value

        AaaTimer localTimer("SetSensorGainBufferMode", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
        err = AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_u4UpdateGainValue);
        localTimer.End();
        AE_LOG( "[%s()]  Afe = %d -> %d \n", __FUNCTION__,m_u4PreSensorGain, m_u4UpdateGainValue);
        if (FAILED(err)) {
        CAM_LOGE("AAASensorMgr::getInstance().setSensorGainBufferMode fail\n");
        }


        m_bSetGainValue = MFALSE;
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateSensorbyI2C()
{
    MINT32 err = S_AE_OK;

    if(m_u4AdbAEPerFrameCtrl) {
        AaaTimer localTimer("startSensorPerFrameControl", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
        startSensorPerFrameControl(m_u4AdbAEPerFrameCtrl);
        localTimer.End();
        return S_AE_OK;
    }
    if(m_bSetFrameRateValue) {     // update frame rate
        m_bSetFrameRateValue = MFALSE;
        AaaTimer localTimer("SetFrameRater", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
        err = AAASensorMgr::getInstance().setPreviewMaxFrameRate((ESensorDev_T)m_eSensorDev, m_u4UpdateFrameRate_x10, m_eSensorMode);
        localTimer.End();
        if (FAILED(err)) {
            CAM_LOGE("AAASensorMgr::getInstance().setPreviewMaxFrameRate fail\n");
        }
    }

    if((m_eAETargetMode == AE_MODE_IVHDR_TARGET) || (m_eAETargetMode == AE_MODE_MVHDR_TARGET)|| (m_eAETargetMode == AE_MODE_ZVHDR_TARGET)) {   // mVHDR/iVHDR sensor control
        if(m_bSetShutterValue) {    // update shutter value
            // 0/0/2 and 0/1/2 sensor both use it
            AAASensorMgr::getInstance().set2ShutterControl((ESensorDev_T)m_eSensorDev, m_u4LEHDRshutter, m_u4SEHDRshutter);
            m_bSetShutterValue = MFALSE;

            // Update AWB gain to sensor
            if(bUpdateSensorAWBGain) {
                strSensorAWBGain rSensorAWBGain;
                AWB_GAIN_T rCurrentIspAWBGain = ISP_MGR_PGN_T::getInstance(m_eSensorDev).getIspAWBGain();
                rSensorAWBGain.u4R = rCurrentIspAWBGain.i4R;
                rSensorAWBGain.u4GR = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4GB = rCurrentIspAWBGain.i4G;
                rSensorAWBGain.u4B = rCurrentIspAWBGain.i4B;

                AAASensorMgr::getInstance().setSensorAWBGain((ESensorDev_T)m_eSensorDev, &rSensorAWBGain);
            }

        }
        if(m_bSetGainValue) {    // update sensor gain value
            if (!m_pSensorGainThread){  // 0/0/2 sensor
                err = AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_u4UpdateGainValue);
            } else {                    // 0/1/2 sensor
                ThreadSensorGain::Cmd_T rCmd(0, 0, m_u4UpdateGainValue, m_eSensorTG);
                m_pSensorGainThread->postCmd(&rCmd);
            }
            m_bSetGainValue = MFALSE;
            if (FAILED(err)) {
                CAM_LOGE("AAASensorMgr::getInstance().setSensorGain fail\n");
            }
        }

    } else {   // normal control
        if(m_bSetShutterValue) {    // update shutter value
            if (m_rAEInitInput.rAEPARAM.bPerFrameAESmooth&&(!m_bStereoManualPline)){
                if ((m_u4UpdateShutterValue != m_PreEvSettingQueue[0].u4Eposuretime)||
                    (m_u4UpdateShutterValue != m_PreEvSettingQueue[1].u4Eposuretime)||
                    (m_u4UpdateShutterValue != m_PreEvSettingQueue[2].u4Eposuretime)||(m_strAECycleInfo.m_i4FrameCnt<10)){
                    AaaTimer localTimer("SetSensorShutter", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                    err = AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, m_u4UpdateShutterValue);
                    AE_LOG_IF(m_3ALogEnable,"[%s()] Exposure time value = %d\n", __FUNCTION__, m_u4UpdateShutterValue);
                    localTimer.End();
                    if (FAILED(err)) {
                        CAM_LOGE("AAASensorMgr::getInstance().setSensorExpTime fail\n");
                    }
                } else {
                    AE_LOG_IF(m_3ALogEnable,"[%s()] Exposure time value is repeat (skip send command)= %d\n", __FUNCTION__, m_u4UpdateShutterValue);
                }
            } else {
                AaaTimer localTimer("SetSensorShutter", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                err = AAASensorMgr::getInstance().setSensorExpTime((ESensorDev_T)m_eSensorDev, m_u4UpdateShutterValue);
                localTimer.End();
                if (FAILED(err)) {
                    CAM_LOGE("AAASensorMgr::getInstance().setSensorExpTime fail\n");
                }
            }
            m_bSetShutterValue = MFALSE;
        }
        if(m_bSetGainValue) {    // update sensor gain value
            if (m_rAEInitInput.rAEPARAM.bPerFrameAESmooth&&(!m_bStereoManualPline)){
                if ((m_u4UpdateGainValue != m_PreEvSettingQueue[0].u4AfeGain)||
                    (m_u4UpdateGainValue != m_PreEvSettingQueue[1].u4AfeGain)||
                    (m_u4UpdateGainValue != m_PreEvSettingQueue[2].u4AfeGain)||(m_strAECycleInfo.m_i4FrameCnt<10)){
                    AaaTimer localTimer("SetSensorGain", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));

                    if (m_pSensorGainThread){
                        ThreadSensorGain::Cmd_T rCmd(0, 0, m_u4UpdateGainValue, m_eSensorTG);
                        m_pSensorGainThread->postCmd(&rCmd);
                    } else {
                        err = AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_u4UpdateGainValue);
                        //err = AAASensorMgr::getInstance().setSensorIso((ESensorDev_T)m_eSensorDev, m_eSensorMode, m_rAEOutput.rPreviewMode.u4RealISO);
                    }
                    AE_LOG_IF(m_3ALogEnable,"[%s()] Sensor gain value = %d\n", __FUNCTION__, m_u4UpdateGainValue);
                    localTimer.End();
                    if (FAILED(err)) {
                        CAM_LOGE("AAASensorMgr::getInstance().setSensorGain fail\n");
                    }
                } else {
                    AE_LOG_IF(m_3ALogEnable,"[%s()] Sensor gain value is repeat (skip send command)= %d\n", __FUNCTION__, m_u4UpdateGainValue);
                }
            } else {
                if (m_pSensorGainThread){
                    ThreadSensorGain::Cmd_T rCmd(0, 0, m_u4UpdateGainValue, m_eSensorTG);
                    m_pSensorGainThread->postCmd(&rCmd);
                } else {
                    AaaTimer localTimer("SetSensorGain", m_eSensorDev, (m_3ALogEnable & EN_3A_SCHEDULE_LOG));
                    err = AAASensorMgr::getInstance().setSensorGain((ESensorDev_T)m_eSensorDev, m_u4UpdateGainValue);
                    localTimer.End();
                    if (FAILED(err)) {
                    CAM_LOGE("AAASensorMgr::getInstance().setSensorGain fail\n");
                    }
                }
            }
            m_bSetGainValue = MFALSE;
        }
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateAEInfo2ISP(AE_STATE_T eNewAEState, MUINT32 u4ISPGain)
{
AE_INFO_T rAEInfo2ISP;
MUINT32 u4FinalGain;
MUINT32 u4PreviewBaseGain=1024;
MUINT32 u4PreviewBaseISO=100;
MINT16 i2FlareGain;
MUINT16 u2FrameRate = 300;

    // Update to isp tuning
    if(m_pIAeAlgo != NULL) {
        m_pIAeAlgo->getAEInfoForISP(rAEInfo2ISP, LIB3A_SENSOR_MODE_PRVIEW);
    } else {
        AE_LOG( "The AE algo class is NULL (updateAEInfo2ISP)\n");
    }

    rAEInfo2ISP.i4GammaIdx = m_i4GammaIdx;
    rAEInfo2ISP.i4LESE_Ratio = m_i4LESE_Ratio;
    rAEInfo2ISP.i4HdrSeg = m_i4HdrSeg;
    rAEInfo2ISP.i4HdrTurn = m_i4HdrTurn;
    rAEInfo2ISP.u4SWHDR_SE = m_u4SWHDR_SE;
    rAEInfo2ISP.u4MaxISO = m_u4MaxISO*m_rAEPLineLimitation.u4IncreaseISO_x100/100;
    rAEInfo2ISP.u4AEStableCnt = m_u4StableCnt;
    rAEInfo2ISP.u4EVRatio = m_rAEInitInput.rAEPARAM.pEVValueArray[m_eAEEVcomp];
    rAEInfo2ISP.bAEStable = m_bAEStable;
    rAEInfo2ISP.bAELock = m_bAPAELock;
    rAEInfo2ISP.bAELimiter = m_bAElimitor;
    rAEInfo2ISP.u4EISExpRatio = m_u4EISExpRatio;

    switch(eNewAEState) {
        case AE_INIT_STATE:
        case AE_REINIT_STATE:
        case AE_AUTO_FRAMERATE_STATE:
        case AE_MANUAL_FRAMERATE_STATE:
            rAEInfo2ISP.u4Eposuretime = m_rAEOutput.rPreviewMode.u4Eposuretime;
            rAEInfo2ISP.u4AfeGain = m_rAEOutput.rPreviewMode.u4AfeGain;
            rAEInfo2ISP.i2FlareOffset  =m_rAEOutput.rPreviewMode.i2FlareOffset;

            if(u4ISPGain != 0x00) {
                rAEInfo2ISP.u4IspGain = u4ISPGain;
                AE_LOG_IF(m_3ALogEnable,"[updateAEInfo2ISP] Smooth ISP Gain:%d\n", rAEInfo2ISP.u4IspGain);
            } else {
                rAEInfo2ISP.u4IspGain = m_rAEOutput.rPreviewMode.u4IspGain;
            }

            if(m_p3ANVRAM != NULL) {
                u4PreviewBaseISO=m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
            } else {
                AE_LOG( "[updateAEInfo2ISP] NVRAM data is NULL\n");
            }

            u4FinalGain = (rAEInfo2ISP.u4AfeGain*rAEInfo2ISP.u4IspGain)>>10;
            rAEInfo2ISP.u4RealISOValue = (u4PreviewBaseISO*u4FinalGain+(u4PreviewBaseGain-1))/u4PreviewBaseGain;
            u2FrameRate = m_rAEOutput.rPreviewMode.u2FrameRate;
            break;
        case AE_AF_STATE:
            rAEInfo2ISP.u4Eposuretime = m_rAEOutput.rAFMode.u4Eposuretime;
            rAEInfo2ISP.u4AfeGain = m_rAEOutput.rAFMode.u4AfeGain;
            rAEInfo2ISP.u4IspGain = m_rAEOutput.rAFMode.u4IspGain;
            rAEInfo2ISP.i2FlareOffset  =m_rAEOutput.rAFMode.i2FlareOffset;
            rAEInfo2ISP.u4RealISOValue = m_rAEOutput.rAFMode.u4RealISO;
            u2FrameRate = m_rAEOutput.rAFMode.u2FrameRate;
            break;
        case AE_CAPTURE_STATE:
        case AE_POST_CAPTURE_STATE:
            if(m_pIAeAlgo != NULL) {
                m_pIAeAlgo->getAEInfoForISP(rAEInfo2ISP, LIB3A_SENSOR_MODE_CAPTURE);
            } else {
                AE_LOG( "The AE algo class is NULL (updateAEInfo2ISP)\n");
            }

            if(m_p3ANVRAM != NULL) {
                u4PreviewBaseISO=m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
            } else {
                AE_LOG( "[updateAEInfo2ISP] NVRAM data is NULL\n");
            }

            rAEInfo2ISP.u4Eposuretime = mCaptureMode.u4Eposuretime;
            rAEInfo2ISP.i2FlareOffset  =mCaptureMode.i2FlareOffset;
            rAEInfo2ISP.u4AfeGain = mCaptureMode.u4AfeGain;
            rAEInfo2ISP.u4IspGain = mCaptureMode.u4IspGain;
            u4FinalGain = (rAEInfo2ISP.u4AfeGain*rAEInfo2ISP.u4IspGain)>>10;
            rAEInfo2ISP.u4RealISOValue = (u4PreviewBaseISO*u4FinalGain+(u4PreviewBaseGain-1))/u4PreviewBaseGain;
            u2FrameRate = mCaptureMode.u2FrameRate;
            break;
        case AE_SENSOR_PER_FRAME_STATE :
            rAEInfo2ISP.u4Eposuretime = m_u4UpdateShutterValue;
            rAEInfo2ISP.u4AfeGain = m_u4UpdateGainValue;
            rAEInfo2ISP.i2FlareOffset  = 0;
            if (m_bIsFlareInManual) {
                rAEInfo2ISP.i2FlareOffset  = m_rAEOutput.rPreviewMode.i2FlareOffset;
            }

            if(u4ISPGain != 0x00) {
                rAEInfo2ISP.u4IspGain = u4ISPGain;
                AE_LOG( "[updateAEInfo2ISP] Smooth ISP Gain:%d avgY:%d\n", rAEInfo2ISP.u4IspGain, m_pIAeAlgo->getBrightnessAverageValue());
            } else {
                rAEInfo2ISP.u4IspGain = 1024;
                AE_LOG( "[updateAEInfo2ISP] No Smooth ISP Gain:%d avgY:%d\n", rAEInfo2ISP.u4IspGain, m_pIAeAlgo->getBrightnessAverageValue());
            }

            if(m_p3ANVRAM != NULL) {
                u4PreviewBaseISO = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
            } else {
                AE_LOG( "[updateAEInfo2ISP] NVRAM data is NULL\n");
            }

            u4FinalGain = (rAEInfo2ISP.u4AfeGain*rAEInfo2ISP.u4IspGain)>>10;
            rAEInfo2ISP.u4RealISOValue = (u4PreviewBaseISO*u4FinalGain+(u4PreviewBaseGain-1))/u4PreviewBaseGain;
            u2FrameRate = m_u4UpdateFrameRate_x10;
            break;
        case AE_TWO_SHUTTER_INIT_STATE :
            rAEInfo2ISP.i2FlareOffset  =m_rAEOutput.rPreviewMode.i2FlareOffset;
            rAEInfo2ISP.u4Eposuretime = m_strIVHDROutputSetting.u4SEExpTimeInUS;
            rAEInfo2ISP.u4AfeGain = m_strIVHDROutputSetting.u4SESensorGain;
            rAEInfo2ISP.u4IspGain = m_strIVHDROutputSetting.u4SEISPGain;
            rAEInfo2ISP.i4LESE_Ratio = m_strIVHDROutputSetting.u4LE_SERatio_x100;
            rAEInfo2ISP.u4SWHDR_SE = m_u4SWHDR_SE;
            rAEInfo2ISP.i4HdrSeg = m_i4HdrSeg;
            rAEInfo2ISP.i4HdrTurn = m_i4HdrTurn;

            if(u4ISPGain != 0x00) {
                rAEInfo2ISP.u4IspGain = u4ISPGain;
                AE_LOG( "[updateAEInfo2ISP] Smooth ISP Gain:%d avgY:%d\n", rAEInfo2ISP.u4IspGain, m_pIAeAlgo->getBrightnessAverageValue());
            }

            if(m_p3ANVRAM != NULL) {
                u4PreviewBaseISO = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
            } else {
                AE_LOG( "[updateAEInfo2ISP] NVRAM data is NULL\n");
            }

            u4FinalGain = (rAEInfo2ISP.u4AfeGain*rAEInfo2ISP.u4IspGain)>>10;
            rAEInfo2ISP.u4RealISOValue = (u4PreviewBaseISO*u4FinalGain+(u4PreviewBaseGain-1))/u4PreviewBaseGain;
            u2FrameRate = m_u4UpdateFrameRate_x10;
            break;
        case AE_TWO_SHUTTER_FRAME_STATE :
            rAEInfo2ISP.i2FlareOffset  =m_rAEOutput.rPreviewMode.i2FlareOffset;
            rAEInfo2ISP.u4Eposuretime = m_strIVHDROutputSetting.u4SEExpTimeInUS;
            rAEInfo2ISP.u4AfeGain = m_strIVHDROutputSetting.u4SESensorGain;
            rAEInfo2ISP.u4IspGain = m_strIVHDROutputSetting.u4SEISPGain;
            rAEInfo2ISP.i4LESE_Ratio = m_strIVHDROutputSetting.u4LE_SERatio_x100;
            rAEInfo2ISP.u4SWHDR_SE = m_u4SWHDR_SE;
            rAEInfo2ISP.i4HdrSeg = m_i4HdrSeg;
            rAEInfo2ISP.i4HdrTurn = m_i4HdrTurn;

            if(u4ISPGain != 0x00) {
                rAEInfo2ISP.u4IspGain = u4ISPGain;
                AE_LOG( "[updateAEInfo2ISP] Smooth ISP Gain:%d avgY:%d\n", rAEInfo2ISP.u4IspGain, m_pIAeAlgo->getBrightnessAverageValue());
            }

            if(m_p3ANVRAM != NULL) {
                u4PreviewBaseISO = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx].rDevicesInfo.u4MiniISOGain;
            } else {
                AE_LOG( "[updateAEInfo2ISP] NVRAM data is NULL\n");
            }

            u4FinalGain = (rAEInfo2ISP.u4AfeGain*rAEInfo2ISP.u4IspGain)>>10;
            rAEInfo2ISP.u4RealISOValue = (u4PreviewBaseISO*u4FinalGain+(u4PreviewBaseGain-1))/u4PreviewBaseGain;
            u2FrameRate = m_u4UpdateFrameRate_x10;
            break;
        case AE_PRE_CAPTURE_STATE:
        case AE_AF_RESTORE_STATE:
        case AE_SENSOR_PER_FRAME_CAPTURE_STATE:
            AE_LOG( "[updateAEInfo2ISP] Nothing to do State:%d\n", eNewAEState);
            return S_AE_OK;
    }

    if(u2FrameRate > m_i4AEMaxFps) {
        AE_LOG_IF(m_3ALogEnable,"[updateAEInfo2ISP] Frame rate too large:%d %d\n", u2FrameRate, m_i4AEMaxFps);
        u2FrameRate = m_i4AEMaxFps;
    }

    if(u2FrameRate != 0) {
        m_rSensorCurrentInfo.u8FrameDuration = 10005000000L / u2FrameRate;
    } else {
        m_rSensorCurrentInfo.u8FrameDuration = 33000000L;
        AE_LOG( "No Frame rate value, using default frame rate value (33ms)\n");
    }

    m_rSensorCurrentInfo.u8ExposureTime = (MUINT64)rAEInfo2ISP.u4Eposuretime * 1000L;
    m_rSensorCurrentInfo.u4Sensitivity = rAEInfo2ISP.u4RealISOValue;
    i2FlareGain = FLARE_SCALE_UNIT * FLARE_OFFSET_DOMAIN / (FLARE_OFFSET_DOMAIN - rAEInfo2ISP.i2FlareOffset);
    m_i4AEAutoFlickerMode = (MINT32)(m_eAEAutoFlickerMode);
    if (eNewAEState == AE_POST_CAPTURE_STATE){
        i2FlareGain = FLARE_SCALE_UNIT * FLARE_OFFSET_DOMAIN / (FLARE_OFFSET_DOMAIN - m_rAEOutput.rPreviewMode.i2FlareOffset);
        IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, g_rIsp>>1);
        IspTuningMgr::getInstance().setIspFlareGainOffset((ESensorDev_T)m_eSensorDev, i2FlareGain, (-1*m_rAEOutput.rPreviewMode.i2FlareOffset));
        AE_LOG( "[updateAEInfo2ISP] AE_POST_CAPTURE_STATE - ISP / FlareOffset : %d/ %d\n", g_rIsp, m_rAEOutput.rPreviewMode.i2FlareOffset);
    }else{
        IspTuningMgr::getInstance().setISPAEGain((ESensorDev_T)m_eSensorDev, MFALSE, rAEInfo2ISP.u4IspGain>>1);
        IspTuningMgr::getInstance().setIspFlareGainOffset((ESensorDev_T)m_eSensorDev, i2FlareGain, (-1*rAEInfo2ISP.i2FlareOffset));
    }
    IspTuningMgr::getInstance().setAEInfo((ESensorDev_T)m_eSensorDev, rAEInfo2ISP);
    AE_LOG( "[updateAEInfo2ISP] State:%d Shutter:%d Gain:%d %d %d Flare offset:%d %d FrameDuration:%lld \n", eNewAEState, rAEInfo2ISP.u4Eposuretime, rAEInfo2ISP.u4AfeGain,
        rAEInfo2ISP.u4IspGain, rAEInfo2ISP.u4RealISOValue, rAEInfo2ISP.i2FlareOffset, i2FlareGain, m_rSensorCurrentInfo.u8FrameDuration);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::get3ACaptureDelayFrame()
{
MINT32 i4CaptureDelayFrame = m_i4SensorCaptureDelayFrame;
//MINT8 idx;
    getAESensorActiveCycle(&i4CaptureDelayFrame);


    if((m_bEnableAE == MTRUE) && (mCaptureMode.u4Eposuretime > m_rAEInitInput.rAEPARAM.strAEParasetting.u4LongCaptureThres) && (m_bMultiCap == MFALSE) && (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableLongCaptureCtrl == MTRUE)) {


        AAASensorMgr::getInstance().getSensorModeDelay(m_eSensorMode, &i4CaptureDelayFrame);

        if (i4CaptureDelayFrame < (m_i4IspGainDelayFrames+3)){

        i4CaptureDelayFrame = m_i4TotalCaptureDelayFrame;

        } else {

        m_i4TotalCaptureDelayFrame = i4CaptureDelayFrame;
        m_u4VsyncCnt = m_i4TotalCaptureDelayFrame;

        }
    }

    AE_LOG( "[%s()] i4SensorDev:%d i4CaptureDelayFrame:%d %d %d Shutter:%d MultiCap:%d Thres:%d Enable:%d\n", __FUNCTION__, m_eSensorDev, i4CaptureDelayFrame, m_i4SensorCaptureDelayFrame,
      m_i4TotalCaptureDelayFrame, mCaptureMode.u4Eposuretime, m_bMultiCap, m_rAEInitInput.rAEPARAM.strAEParasetting.u4LongCaptureThres, m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableLongCaptureCtrl);
    return i4CaptureDelayFrame;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


MINT32 AeMgr::getAEAutoFlickerState()
{
    return m_i4AEAutoFlickerMode;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::IsMultiCapture(MBOOL bMultiCap)
{
    AE_LOG( "[%s()] i4SensorDev:%d bMultiCap:%d\n", __FUNCTION__, m_eSensorDev, bMultiCap);
    m_bMultiCap = bMultiCap;
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::IsAEContinueShot(MBOOL bCShot)
{
    AE_LOG( "[%s()] i4SensorDev:%d bCShot:%d\n", __FUNCTION__, m_eSensorDev, bCShot);
    m_bCShot = bCShot;
    if(m_bCShot == MTRUE){
        m_bAEMonitorStable = MFALSE;
        m_u4AEScheduleCnt = 0;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::IsEISRecording(MBOOL bEISRecording)
{

   if ((bEISRecording == MTRUE) && (m_bManualAEtable == MFALSE)){
        m_bManualAEtable = MTRUE;
        m_u4ManualAEtablePreviewidx = AE_PLINE_EISRECORD ;//g_AE_SceneTable9
        m_u4ManualAEtableCaptureidx = AE_PLINE_EISRECORD ;//g_AE_SceneTable9
   } else if ((bEISRecording == MFALSE) && (m_bManualAEtable == MTRUE)){
        m_bManualAEtable = MFALSE;
        m_u4ManualAEtablePreviewidx = 0 ;
        m_u4ManualAEtableCaptureidx = 1 ;
   } else {

   }
   AE_LOG( "[%s()] i4SensorDev:%d manualAETable: %d/%d/%d/%d \n", __FUNCTION__, m_eSensorDev, bEISRecording, m_bManualAEtable ,m_u4ManualAEtablePreviewidx, m_u4ManualAEtableCaptureidx);
   return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setzCHDRShot(MBOOL bHDRShot)
{
   if ((bHDRShot == 1) || (bHDRShot!=m_bzcHDRshot)){
        AE_LOG( "[%s()] i4SensorDev:%d bZCHDRShot:%d->%d\n", __FUNCTION__, m_eSensorDev, m_bzcHDRshot ,bHDRShot);
        m_bzcHDRshot = bHDRShot;
        m_bAEMonitorStable = MFALSE;
        m_u4AEScheduleCnt = 0;
   }
   return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::IsHDRShot(MBOOL bHDRShot)
{
   if ((bHDRShot == 1) || (bHDRShot!=m_bHDRshot)){
        AE_LOG( "[%s()] i4SensorDev:%d bHDRShot:%d->%d\n", __FUNCTION__, m_eSensorDev, m_bHDRshot ,bHDRShot);
        m_bHDRshot = bHDRShot;
        m_bAEMonitorStable = MFALSE;
        m_u4AEScheduleCnt = 0;
        if (m_rAEInitInput.rAEPARAM.bPerFrameAESmooth)
            m_u4HDRcountforrevert = 3;
        else
            m_u4HDRcountforrevert = 1;
   }
   return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updateCaptureShutterValue()
{
    if((m_bEnableAE == MTRUE) && (m_bMultiCap == MFALSE) && (mCaptureMode.u4Eposuretime > m_rAEInitInput.rAEPARAM.strAEParasetting.u4LongCaptureThres) && (m_rAEInitInput.rAEPARAM.strAEParasetting.bEnableLongCaptureCtrl == MTRUE)) {
        m_u4VsyncCnt--;
        if(m_u4VsyncCnt == (m_i4TotalCaptureDelayFrame-1)) {
            setExp(mCaptureMode.u4Eposuretime);
        } else if((m_u4VsyncCnt == 1) && (m_bCShot == MFALSE)) {   // if m_bQuick2Preview is TRUE mean the capture is continue shot
            setExp(30000);
        }
    }
    AE_LOG( "[%s()] i4SensorDev:%d m_u4VsyncCnt:%d m_bMultiCap:%d m_bCShot:%d\n", __FUNCTION__, m_eSensorDev, m_u4VsyncCnt, m_bMultiCap, m_bCShot);
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::prepareCapParam() //for optimized capture flow
{
    AE_LOG( "[%s()] AE stable already\n", __FUNCTION__);
    UpdateSensorISPParams(AE_PRE_CAPTURE_STATE);
    doBackAEInfo();   // do back up AE for Precapture AF state.
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::monitorAndReschedule( MBOOL bAAASchedule, MUINT32 u4AvgYcur, MUINT32 u4AvgYStable, MBOOL *bAECalc, MBOOL *bAEApply )
{
    MBOOL bStatChange;
    MBOOL bReschedule;
    MBOOL bAEExit = MFALSE;
    MBOOL bAESkip = MFALSE;
    MINT32 i4framePerAECycle = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET + 1;
    MUINT16 u2AEStatThrs = m_rAEInitInput.rAEPARAM.strAEParasetting.u2AEStatThrs;
    MUINT8 AEScheduleFrame;
    MUINT8 NumCycleAESkipAfterExit = m_rAEInitInput.rAEPARAM.strAEParasetting.uCycleNumAESkipAfterExit;

    //  AE_LOG( "[%s()] u2AEStatThrs:%d NumCycleAESkipAfterExit:%d\n", __FUNCTION__ , u2AEStatThrs, NumCycleAESkipAfterExit);
    getAESensorActiveCycle(&i4framePerAECycle);

    if(bAAASchedule){
        m_u4AEScheduleCnt = 0;
        *bAECalc  = MFALSE;
        *bAEApply = MFALSE;
        return 0;
    }

    // Detect AE statistic change
    bStatChange = AEStatisticChange(u4AvgYcur, u4AvgYStable, u2AEStatThrs);
    // Reset and Follow Schedule
    bReschedule = (m_bAEMonitorStable && (bStatChange || (m_bFaceAEAreaChage &&(m_u4WOFDCnt>m_rAEInitInput.rAEPARAM.pFaceSmooth->u4FD_Lost_MaxCnt)) || m_bTouchAEAreaChage));


    //AE Exit condition

    if (m_bAEMonitorStable){

        if( (bReschedule)&&(m_i4WaitVDNum > (i4framePerAECycle-1) ) ){       // (touchAE||Face||statchange) when stable
            m_u4AEScheduleCnt = 0;
        }else if ((bReschedule)&&(m_i4WaitVDNum <= (i4framePerAECycle-1) ) ){ // (touchAE||Face||statchange) when stable
            m_u4AEScheduleCnt = m_i4WaitVDNum;
        }else{                                                                      // without (touchAE||Face||statchange) when stable
            bAEExit = MTRUE;
        }
    }

    //Skip after AEexit
    if (bAEExit == MTRUE){
        (m_u4AEExitStableCnt < i4framePerAECycle*NumCycleAESkipAfterExit)?(bAESkip = MFALSE):(bAESkip = MTRUE);
         m_u4AEExitStableCnt++;
    } else {
         m_u4AEExitStableCnt = 0;
    }

    // Set AECalc & AEApply
    AEScheduleFrame = (m_u4AEScheduleCnt) % (i4framePerAECycle);

    if(bAESkip == MTRUE) {
        *bAECalc  = MFALSE;
        *bAEApply = MFALSE;
        m_i4WaitVDNum = 0;
    } else if ((AEScheduleFrame == 0)) {
        *bAECalc = MTRUE;
        *bAEApply = MTRUE;
    } else {
        *bAECalc = MFALSE;
        *bAEApply = MTRUE;
    }

    AE_LOG( "[%s()] Calc:%d Apply:%d Cnt:%d Frame:%d Magic:%d ReSchedule:%d Exit:%d Skip:%d bStatChange:%d bAAASchedule:%d framePerAECycle:%d Stable:%d AEMonitorStable:%d VdCnt:%d ISPdelay:%d FaceArea:%d FaceWOCnt:%d TouchArea:%d u4CwvYcur:%d u4CwvYpre:%d u4AvgYcur:%d\n",
              __FUNCTION__, *bAECalc, *bAEApply, m_u4AEScheduleCnt,AEScheduleFrame,m_u4HwMagicNum, bReschedule, bAEExit, bAESkip, bStatChange, bAAASchedule, i4framePerAECycle,
              m_bAEStable, m_bAEMonitorStable, m_i4WaitVDNum, m_i4IspGainDelayFrames, m_bFaceAEAreaChage, m_u4WOFDCnt, m_bTouchAEAreaChage,u4AvgYcur, u4AvgYStable, m_pIAeAlgo->getBrightnessAverageValue());

    // Update next AE Schedule Count
    m_u4AEScheduleCnt ++;
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::AEStatisticChange( MUINT32 u4AvgYcur, MUINT32 u4AvgYpre, MUINT32 u4thres)
{
    MBOOL bStatChange=0;

    if ((u4AvgYcur<(u4AvgYpre-u4AvgYpre*u4thres/100))||(u4AvgYcur>(u4AvgYpre+u4AvgYpre*u4thres/100))){
        bStatChange = 1;
//        if(m_bAEStable) {
            //AE_LOG( "[%s()] u4AvgYcur:%d u4AvgYpre:%d u4thres:%d\n", __FUNCTION__ , u4AvgYcur, u4AvgYpre, u4thres);
//        }
    }

    return bStatChange;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MINT32 AeMgr::getAAOLineByteSize() const
{
    return static_cast<MINT32>(m_u4BlockNumX*(5+0.5*m_bEnableHDRYConfig+1*m_bEnableOverCntConfig+2*m_bEnableTSFConfig)+0.5);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::aaoSeparation(void* aao, int w, int h, void* awb, void* ae,  void* hist, void* overexpcnt,void* lsc)
{
    CAM_TRACE_FMT_BEGIN("AESep");

  int i;
  int j;
  MUINT8* pawb=(MUINT8*)awb;
  MUINT8* p=(MUINT8*)aao;
  MBOOL bEnable = m_u4AdbAAOdump;
  // Original AAO dump
  if (bEnable) {
        char fileName[64];
        static int framecnt = 0;
        sprintf(fileName, "/sdcard/aaodump/aao_%d.raw", framecnt);
        FILE *fp = fopen(fileName, "w");
        if (NULL == fp)
        {
            CAM_LOGE("fail to open file to save img: %s", fileName);
            MINT32 err = mkdir("/sdcard/aaodump", S_IRWXU | S_IRWXG | S_IRWXO);
            AE_LOG( "err = %d", err);
            return MFALSE;
        }
        AE_LOG_IF(bEnable ,"%s\n", fileName);
        fwrite(reinterpret_cast<void *>(aao), 1, AAO_STT_BLOCK_NUMX*AAO_STT_BLOCK_NUMY*8.5+4*AAO_STT_HIST_BIN_NUM*3, fp);
        framecnt++;
        fclose(fp);
  }

  int lineByte;
  lineByte = (int)(w*(5+0.5*m_bEnableHDRYConfig+1*m_bEnableOverCntConfig+2*m_bEnableTSFConfig)+0.5);

    // Fill awb
  if(awb!=0)
  {
    for(j=0;j<h;j++)
    {
      memcpy(pawb, p, w*4);
      p+=lineByte;
      pawb+=w*4;
    }
  }


    // Fill ae
    if (ae!=0)
    {
        MUINT16* pae=(MUINT16* )ae;
        p=(MUINT8*)aao;
        int aaoNoAWBSz;
        aaoNoAWBSz = (int)(w*4);
        if(m_bEnableHDRYConfig){
            for(j=0;j<h;j++)
            {

                for(int k=0;k<(w/2);k++){
                    MUINT16 LSBbit30 = (*(p+aaoNoAWBSz+w+k))& 0xF;
                    MUINT16 LSBbit74 = (*(p+aaoNoAWBSz+w+k))>>4;
                    MUINT16 MSBfor30 = (*(p+aaoNoAWBSz+2*k));
                    MUINT16 MSBfor74 = (*(p+aaoNoAWBSz+2*k+1));
                    *(pae+2*k)  = (MSBfor30<<4)+LSBbit30;
                    *(pae+2*k+1)= (MSBfor74<<4)+LSBbit74;
                }
                p += lineByte;
                pae+=w;
            }
        }else{
            for(j=0;j<h;j++)
            {
                for(int k=0;k<(w/2);k++){
                    MUINT16 u2FirstByte = (*(p+aaoNoAWBSz+2*k));
                    MUINT16 u2SecondByte = (*(p+aaoNoAWBSz+2*k+1));
                    *(pae+2*k)  = u2FirstByte;
                    *(pae+2*k+1)= u2SecondByte;
                }
                p += lineByte;
                pae+=w;
            }
        }
    }
    //Lsc
  if (lsc!=0)
    {
        MUINT16* plsc=(MUINT16* )lsc;
        p=(MUINT8*)aao;
        int aaoNoLSCsz=(int)(w*(5+0.5*m_bEnableHDRYConfig+1*m_bEnableOverCntConfig));
        if (m_bEnableTSFConfig){
            for(j=0;j<h;j++)
            {

                for(int k=0;k<w*2;k++){
                    MUINT16 LSBbit30 = (*(p+aaoNoLSCsz+k))& 0xF;
                    MUINT16 LSBbit74 = (*(p+aaoNoLSCsz+k))>>4;
                    MUINT16 MSBfor30 = (*(p+2*k));
                    MUINT16 MSBfor74 = (*(p+2*k+1));
                    *(plsc+2*k)  = (MSBfor30<<4)+LSBbit30;
                    if (k%2 ==0){
                        *(plsc+2*k+1)= (MSBfor74<<4)+LSBbit74;
                    } else {
                        *(plsc+2*k+1)= MSBfor74;
                    }
                }
                p += lineByte;
                plsc+=w*4;
             }
         }else{
             for(j=0;j<h;j++)
             {
                for(int k=0;k<w*2;k++){
                    *(plsc+2*k)  = 0;
                    *(plsc+2*k+1)= 0;
                }
                p += lineByte;
                plsc+=w*4;
             }
         }
    }
    // Fill hist
  if(hist!=0)
  {
    int* pHist=(int* )hist;
    p=(MUINT8*)aao;
    int aaoNoHistSz;
    aaoNoHistSz = lineByte*h;
    p+=aaoNoHistSz;
    if (!m_bDisablePixelHistConfig){
        for(j=0;j<4;j++)
        {
          for(i=0;i<128;i++)
          {
            int v;
            int b1;
            int b2;
            int b3;
            b1 = *p;
            b2 = *(p+1);
            b3 = *(p+2);
            v = b1+(b2<<8)+(b3<<16);
            p+=3;
            *pHist=v;
            pHist++;
          }
        }
    }else{
        for(j=0;j<4;j++)
        {
          for(i=0;i<128;i++)
          {
            int v;
            int b1;
            int b2;
            b1 = *p;
            b2 = *(p+1);
            v = b1+(b2<<8);
            p+=2;
            *pHist=v;
            pHist++;
          }
        }

    }
  }
    // Fill overexpcnt
  if(overexpcnt!=0)
  {
        MUINT16* poverexpcnt = (MUINT16* )overexpcnt;
        p=(MUINT8*)aao;
        int aaoNoAWBAESz;
        aaoNoAWBAESz = (int)(w*(5+0.5*m_bEnableHDRYConfig)+0.5);
        if(m_bEnableOverCntConfig){
            for (j=0;j<h;j++){

                for (int k=0; k<w; k++){
                     *(poverexpcnt+k)=*(p+aaoNoAWBAESz+k);
                     if (m_u4AEOverExpCntShift){
                        *(poverexpcnt+k)= (*(poverexpcnt+k))*2;
                     }
                }
                p += lineByte;
                poverexpcnt+=w;
            }
        }else{
            for (j=0;j<h;j++){

                for (int k=0; k<w; k++){
                     *(poverexpcnt+k)= 0;
                }
                p += lineByte;
                poverexpcnt+=w;
            }

        }
  }
  CAM_TRACE_FMT_END();
    return 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::aaoTgSeparation(void* aao, int w, int h, void* ae)
{
    CAM_TRACE_FMT_BEGIN("AETgSep");

    int i;
    int j;
    MUINT8* p=(MUINT8*)aao;

    int lineByte;
    lineByte = (int)(w*(5+0.5*m_bEnableHDRYConfig+1*m_bEnableOverCntConfig+2*m_bEnableTSFConfig)+0.5);

    // Fill ae
    if (ae!=0)
    {
        MUINT16* pae=(MUINT16* )ae;
        p=(MUINT8*)aao;
        int aaoNoAWBSz;
        aaoNoAWBSz = (int)(w*4);
        if(m_bEnableHDRYConfig){
            for(j=0;j<h;j++)
            {
                if(j>=m_i4AETgValidBlockHeight) break; // stop if reach TG-interrupt height

                for(int k=0;k<(w/2);k++){
                    MUINT16 LSBbit30 = (*(p+aaoNoAWBSz+w+k))& 0xF;
                    MUINT16 LSBbit74 = (*(p+aaoNoAWBSz+w+k))>>4;
                    MUINT16 MSBfor30 = (*(p+aaoNoAWBSz+2*k));
                    MUINT16 MSBfor74 = (*(p+aaoNoAWBSz+2*k+1));
                    *(pae+2*k)  = (MSBfor30<<4)+LSBbit30;
                    *(pae+2*k+1)= (MSBfor74<<4)+LSBbit74;
                }
                p += lineByte;
                pae+=w;
            }
        }else{
            for(j=0;j<h;j++)
            {
                if(j>=m_i4AETgValidBlockHeight) break; // stop if reach TG-interrupt height

                for(int k=0;k<(w/2);k++){
                    MUINT16 u2FirstByte = (*(p+aaoNoAWBSz+2*k));
                    MUINT16 u2SecondByte = (*(p+aaoNoAWBSz+2*k+1));
                    *(pae+2*k)  = u2FirstByte;
                    *(pae+2*k+1)= u2SecondByte;
                }
                p += lineByte;
                pae+=w;
            }
        }
    }

    CAM_TRACE_FMT_END();
    return 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::isLVChangeTooMuch()
{
    if(ABS((DOUBLE)m_pIAeAlgo->getBrightnessCenterWeightedValue() - (DOUBLE)m_u4StableYValue)/((DOUBLE)m_u4StableYValue) > 0.3){
        AE_LOG( "[%s()] CWVYcur:%d CWVYStable:%d Change/Thres percentage:%d/%d \n", __FUNCTION__ , m_pIAeAlgo->getBrightnessCenterWeightedValue(), m_u4StableYValue, 100*ABS((MINT32)m_pIAeAlgo->getBrightnessCenterWeightedValue() - (MINT32)m_u4StableYValue)/((MINT32)m_u4StableYValue), 30);
        return MTRUE;
    }
    return MFALSE;
}

MBOOL AeMgr::SaveAEMgrInfo(const char * fname)
{
    strcpy(mEngFileName, fname);
    return MTRUE;
}

MRESULT AeMgr::updateEMISOCaptureParams(AE_MODE_CFG_T &inputparam){

    MUINT32 u4OriExposure = inputparam.u4Eposuretime;
    MUINT32 u4OriAfeGain  = inputparam.u4AfeGain;
    MUINT32 u4OriIspGain  = inputparam.u4IspGain;
    inputparam.u4AfeGain     = m_u4AEISOSpeed*1024/100;
    if (inputparam.u4AfeGain <= m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MaxGain){
        inputparam.u4IspGain = 1024;
    } else {
        inputparam.u4IspGain = inputparam.u4AfeGain*1024/m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MaxGain;
        inputparam.u4AfeGain = m_rAEInitInput.rAENVRAM.rDevicesInfo.u4MaxGain;
    }
    inputparam.u4Eposuretime = u4OriExposure*u4OriAfeGain/inputparam.u4AfeGain*u4OriIspGain/inputparam.u4IspGain;
    inputparam.u4Eposuretime = (inputparam.u4Eposuretime > EMLongestExp)? EMLongestExp : inputparam.u4Eposuretime;
    if (inputparam.u4Eposuretime < m_pPreviewTableCurrent->pCurrentTable->sPlineTable[0].u4Eposuretime){
        AE_LOG( "[updateEMISOCaptureParams] Calculated/PlineMin %d/%d \n",inputparam.u4Eposuretime, m_pPreviewTableCurrent->pCurrentTable->sPlineTable[0].u4Eposuretime);
        inputparam.u4Eposuretime = m_pPreviewTableCurrent->pCurrentTable->sPlineTable[0].u4Eposuretime;
    }
    AE_LOG( "[%s():EM-ISO] m_u4AEISOSpeed:%d Exp/Afe/Isp:%d/%d/%d -> Exp/Afe/Isp:%d/%d/%d \n", __FUNCTION__,m_u4AEISOSpeed, u4OriExposure,u4OriAfeGain,u4OriIspGain ,inputparam.u4Eposuretime, inputparam.u4AfeGain, inputparam.u4IspGain);
    return S_AE_OK;

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL AeMgr::setTGInfo(MINT32 const i4TGInfo)
{
    AE_LOG( "[%s()] i4TGInfo: %d \n", __FUNCTION__, i4TGInfo);

    switch (i4TGInfo)
    {
    case CAM_TG_1:
        m_eSensorTG = ESensorTG_1;
        break;
    case CAM_TG_2:
        m_eSensorTG = ESensorTG_2;
        break;
    default:
        CAM_LOGE("i4TGInfo = %d", i4TGInfo);
        return MFALSE;
    }

    return MTRUE;
}

MRESULT AeMgr::updateAECycleInfo()
{
    m_strAECycleInfo.m_i4CycleVDNum = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET + 1;
    m_strAECycleInfo.m_i4ShutterDelayFrames = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET - m_i4ShutterDelayFrames;
    m_strAECycleInfo.m_i4GainDelayFrames = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET - m_i4SensorGainDelayFrames;
    m_strAECycleInfo.m_i4IspGainDelayFrames = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET;
    m_strAECycleInfo.m_i4FrameCnt = 0;
    m_strAECycleInfo.m_i4FrameTgCnt = 0;
    m_strAECycleInfo.m_u4HwMagicNum = 0;

    AE_LOG( "[%s()] m_i4CycleVDNum:%d m_i4ShutterDelayFrames:%d m_i4GainDelayFrames:%d m_i4IspGainDelayFrames:%d m_i4FrameCnt:%d\n", __FUNCTION__,
           m_strAECycleInfo.m_i4CycleVDNum,
           m_strAECycleInfo.m_i4ShutterDelayFrames,
           m_strAECycleInfo.m_i4GainDelayFrames,
           m_strAECycleInfo.m_i4IspGainDelayFrames,
           m_strAECycleInfo.m_i4FrameCnt);

    return S_AE_OK;
}

MRESULT AeMgr::updatePreEvSettingQueue(MUINT32 newExpsuretime, MUINT32 newAfegain, MUINT32 newIspGain)
{
    m_BackupEvSetting = m_PreEvSettingQueue[2];
    for (int i = m_uEvQueueSize - 2 ; i>-1; i--){
        m_PreEvSettingQueue[i+1]= m_PreEvSettingQueue[i];
    }

    m_PreEvSettingQueue[0].u4Eposuretime = newExpsuretime ;
    m_PreEvSettingQueue[0].u4AfeGain     = newAfegain    ;
    m_PreEvSettingQueue[0].u4IspGain     = newIspGain    ;
    m_PreEvSettingQueue[0].uFlag         = 1           ;

    AE_LOG_IF(m_3ALogEnable,"[%s()] m_PreEvSettingQueue[N-1]:%d/%d/%d m_PreEvSettingQueue[N-2]:%d/%d/%d m_PreEvSettingQueue[N-3]:%d/%d/%d FrameCnt(%d) FrameTgCnt(%d) HwMagicNum(%d)\n", __FUNCTION__,
        m_PreEvSettingQueue[0].u4Eposuretime,
        m_PreEvSettingQueue[0].u4AfeGain    ,
        m_PreEvSettingQueue[0].u4IspGain    ,
        m_PreEvSettingQueue[1].u4Eposuretime,
        m_PreEvSettingQueue[1].u4AfeGain    ,
        m_PreEvSettingQueue[1].u4IspGain    ,
        m_PreEvSettingQueue[2].u4Eposuretime,
        m_PreEvSettingQueue[2].u4AfeGain    ,
        m_PreEvSettingQueue[2].u4IspGain    ,
        m_strAECycleInfo.m_i4FrameCnt       ,
        m_strAECycleInfo.m_i4FrameTgCnt     ,
        m_strAECycleInfo.m_u4HwMagicNum);

    return S_AE_OK;
}

MRESULT AeMgr::revertPreEvSettingQueue()
{
    AE_LOG( "[%s():s] m_PreEvSettingQueue[N-1]:%d/%d/%d m_PreEvSettingQueue[N-2]:%d/%d/%d m_PreEvSettingQueue[N-3]:%d/%d/%d \n", __FUNCTION__,
        m_PreEvSettingQueue[0].u4Eposuretime,
        m_PreEvSettingQueue[0].u4AfeGain    ,
        m_PreEvSettingQueue[0].u4IspGain    ,
        m_PreEvSettingQueue[1].u4Eposuretime,
        m_PreEvSettingQueue[1].u4AfeGain    ,
        m_PreEvSettingQueue[1].u4IspGain    ,
        m_PreEvSettingQueue[2].u4Eposuretime,
        m_PreEvSettingQueue[2].u4AfeGain    ,
        m_PreEvSettingQueue[2].u4IspGain );

    for (int i = m_uEvQueueSize - 2 ; i<m_uEvQueueSize ; i++){
        m_PreEvSettingQueue[i-1]= m_PreEvSettingQueue[i];
    }
    m_PreEvSettingQueue[2] = m_BackupEvSetting;

    AE_LOG( "[%s():e] m_PreEvSettingQueue[N-1]:%d/%d/%d m_PreEvSettingQueue[N-2]:%d/%d/%d m_PreEvSettingQueue[N-3]:%d/%d/%d \n", __FUNCTION__,
        m_PreEvSettingQueue[0].u4Eposuretime,
        m_PreEvSettingQueue[0].u4AfeGain    ,
        m_PreEvSettingQueue[0].u4IspGain    ,
        m_PreEvSettingQueue[1].u4Eposuretime,
        m_PreEvSettingQueue[1].u4AfeGain    ,
        m_PreEvSettingQueue[1].u4IspGain    ,
        m_PreEvSettingQueue[2].u4Eposuretime,
        m_PreEvSettingQueue[2].u4AfeGain    ,
        m_PreEvSettingQueue[2].u4IspGain );

    return S_AE_OK;
}

/*******************************************************************************
*
********************************************************************************/
MINT32 AeMgr::getNVRAMParam(MVOID *a_pAENVRAM, MUINT32 *a_pOutLen)
{
    AE_LOG( "[getNVRAMParam]\n");

    AE_NVRAM_T *pAENVRAM = reinterpret_cast<AE_NVRAM_T*>(a_pAENVRAM);

    getNvramData(m_eSensorDev);

    if(pAENVRAM != NULL) {
        *pAENVRAM = m_p3ANVRAM->rAENVRAM[m_eAENVRAMIdx];
    } else {
        AE_LOG( "NVRAM is NULL\n");
    }

    *a_pOutLen = sizeof(AE_NVRAM_T);

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::setAESMBuffermode(MBOOL bSMBuffmode, MINT32 i4subframeCnt)
{
    if (m_bEnSWBuffMode != bSMBuffmode){
        AE_LOG( "[%s()] Slow Motion AE Buffer Mode Enable %d -> %d , Sample = %d \n", __FUNCTION__,m_bEnSWBuffMode, bSMBuffmode, i4subframeCnt);
        m_bEnSWBuffMode = bSMBuffmode;
        m_i4SMSubSamples = i4subframeCnt;
        //AAASensorMgr::getInstance().enableSensorI2CBuffMode((MINT32)m_eSensorDev, m_bEnSWBuffMode);
        if ((m_i4SMSubSamples == 8) && (m_bManualAEtable == MFALSE)){
             m_bManualAEtable = MTRUE;
             m_u4ManualAEtablePreviewidx = AE_PLINE_SM240FPS; // g_AE_SceneTable10
             m_u4ManualAEtableCaptureidx = AE_PLINE_SM240FPS ; // g_AE_SceneTable10
        } else if ((m_i4SMSubSamples != 8) && (m_bManualAEtable == MTRUE)){
             m_bManualAEtable = MFALSE;
             m_u4ManualAEtablePreviewidx = 0 ;
             m_u4ManualAEtableCaptureidx = 1 ;
        } else {

        }
       AE_LOG( "[%s()] i4SensorDev:%d manualAETable: %d/%d/%d/%d \n", __FUNCTION__, m_eSensorDev, m_i4SMSubSamples, m_bManualAEtable ,m_u4ManualAEtablePreviewidx, m_u4ManualAEtableCaptureidx);
    }

    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::updatePreviewParamsByHFSM(AE_MODE_CFG_T *sAEInfo)
{
    MUINT32 u4exp,u4afe,u4isp;
    MUINT32 u4exppre,u4afepre,u4isppre;
    u4exp = sAEInfo->u4Eposuretime;
    u4afe = sAEInfo->u4AfeGain;
    u4isp = sAEInfo->u4IspGain;
    u4exppre = m_u4PreExposureTime;
    u4afepre = m_u4PreSensorGain;
    u4isppre = m_u4PreIspGain;
    float deltaratio = 0.0;

    // Both Exp and Afe should be modified
    if ((u4exp != u4exppre)&&(u4afe != u4afepre)){
        MUINT64 u8totalexpgain;
        MUINT64 u8totalexpgainpre;
        deltaratio = ((float)u4exp)/u4exppre*u4afe/u4afepre*u4isp/u4isppre;
        AE_LOG( "[%s():s]  %d/%d/%d -> %d/%d/%d ,Delta:%f \n", __FUNCTION__,u4exppre, u4afepre, u4isppre, u4exp, u4afe, u4isp,
            deltaratio);
        u8totalexpgain = (MUINT64)u4exp*u4afe*u4isp;
        u8totalexpgainpre = (MUINT64)u4exppre*u4afepre*u4isppre;
        if (u8totalexpgainpre <= u8totalexpgain){
            u4exp = sAEInfo->u4Eposuretime ;
            u4afe = m_u4PreSensorGain ;
            u4isp = sAEInfo->u4AfeGain*sAEInfo->u4IspGain/m_u4PreSensorGain;
            if ((u4isp < 1024)||(u4isp > 8192)){
                if (u4isp < 1024){
                    u4isp = 1024;
        } else {
                    u4isp = 8192;
                }
                u4exp = m_u4PreExposureTime;
                u4afe = sAEInfo->u4AfeGain;
                m_u4HFSMSkipFrame = 1;
                mPreviewModeBackup = *sAEInfo;
                AE_LOG_IF(m_3ALogEnable,"[%s()Pre<Cur] m_u4HFSMSkipFrame:%d , Backup:%d/%d/%d \n", __FUNCTION__,
                    m_u4HFSMSkipFrame,
                    mPreviewModeBackup.u4Eposuretime,
                    mPreviewModeBackup.u4AfeGain,
                    mPreviewModeBackup.u4IspGain);
            }
        } else {
            u4exp = sAEInfo->u4Eposuretime;
            u4afe = m_u4PreSensorGain ;
            u4isp = sAEInfo->u4AfeGain*sAEInfo->u4IspGain/m_u4PreSensorGain;
            if ((u4isp < 1024)||(u4isp > 8192)){
                if (u4isp < 1024){
                    u4isp = 1024;
                } else {
                    u4isp = 8192;
                }
            }
            m_u4HFSMSkipFrame = 1;
            mPreviewModeBackup = *sAEInfo;
            AE_LOG_IF(m_3ALogEnable,"[%s()Pre>Cur] m_u4HFSMSkipFrame:%d , Backup:%d/%d/%d \n", __FUNCTION__,
                    m_u4HFSMSkipFrame,
                    mPreviewModeBackup.u4Eposuretime,
                    mPreviewModeBackup.u4AfeGain,
                    mPreviewModeBackup.u4IspGain);
        }
        deltaratio = ((float)u4exp)/u4exppre*u4afe/u4afepre*u4isp/u4isppre;
        AE_LOG( "[%s():e]  %d/%d/%d -> %d/%d/%d , Delta:%f\n", __FUNCTION__,u4exppre, u4afepre, u4isppre, u4exp, u4afe, u4isp, deltaratio);
        sAEInfo->u4Eposuretime = u4exp;
        sAEInfo->u4AfeGain = u4afe;
        sAEInfo->u4IspGain = u4isp;
    }
    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::enableAISManualPline(MBOOL bAISPline)
{
    if(m_bEISAEPline != bAISPline) {
        AE_LOG( "[%s] i4SensorDev:%d enableEISAEPline old:%d new:%d\n", __FUNCTION__, m_eSensorDev, m_bEISAEPline, bAISPline);
        m_bEISAEPline = bAISPline;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::enableFlareInManualControl(MBOOL bIsFlareInManual)
{
    if(m_bIsFlareInManual != bIsFlareInManual) {
        AE_LOG( "[%s] i4SensorDev:%d bIsFlareInManual old:%d new:%d\n", __FUNCTION__, m_eSensorDev, m_bIsFlareInManual, bIsFlareInManual);
        m_bIsFlareInManual = bIsFlareInManual;
    }
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::enableAEStereoManualPline(MBOOL bstereomode)
{
    if (m_bStereoManualPline != bstereomode){
        AE_LOG( "[%s()] Stereo %d -> %d , m_eSensorMode = %d\n", __FUNCTION__, m_bStereoManualPline, bstereomode, m_eSensorMode);

        if ((bstereomode == MTRUE) && (m_bStereoManualPline == MFALSE)){
            m_pAEMapPlineTable = (AE_PLINEMAPPINGTABLE_T *)(&(m_rAEInitInput.rAEPARAM.strStereoPlineMapping.sAESceneMapping[0]));
        } else if ((bstereomode == MFALSE) && (m_bStereoManualPline == MTRUE)){
            m_pAEMapPlineTable = &(m_rAEInitInput.rAEPlineMapTable[0]);
        } else {

        }

       m_bStereoManualPline = bstereomode;
       for (MINT32 i = 0; i<30 ; i++){
               AE_LOG( "[%s()] i4SensorDev:%d  eID/ePlinetable = %d - %d/%d/%d/%d/%d/%d/%d/%d/%d/%d/%d \n", __FUNCTION__, m_eSensorDev, (MINT32)m_pAEMapPlineTable[i].eAEScene,
               (MINT32)m_pAEMapPlineTable[i].ePLineID[0],(MINT32)m_pAEMapPlineTable[i].ePLineID[1],(MINT32)m_pAEMapPlineTable[i].ePLineID[2],
               (MINT32)m_pAEMapPlineTable[i].ePLineID[3],(MINT32)m_pAEMapPlineTable[i].ePLineID[4],(MINT32)m_pAEMapPlineTable[i].ePLineID[5],
               (MINT32)m_pAEMapPlineTable[i].ePLineID[6],(MINT32)m_pAEMapPlineTable[i].ePLineID[7],(MINT32)m_pAEMapPlineTable[i].ePLineID[8],
               (MINT32)m_pAEMapPlineTable[i].ePLineID[9],(MINT32)m_pAEMapPlineTable[i].ePLineID[10]);
       }
    }

    return S_AE_OK;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

MRESULT AeMgr::getAEdelayInfo(MINT32* i4ExpDelay, MINT32* i4AEGainDelay, MINT32* i4IspGainDelay)
{
    MRESULT err;
    *i4ExpDelay = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET - m_i4ShutterDelayFrames;
    *i4AEGainDelay = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET - m_i4SensorGainDelayFrames;
    *i4IspGainDelay = m_i4IspGainDelayFrames + ISP_GAIN_DELAY_OFFSET;
    if(m_bSGainThdFlg)
        *i4AEGainDelay = *i4AEGainDelay-1;
    AE_LOG( "[%s()] Exp/Afe/Isp delay frame = %d/%d/%d , AfeGainFlg = %d\n", __FUNCTION__, *i4ExpDelay, *i4AEGainDelay, *i4IspGainDelay, m_bSGainThdFlg);
    return S_AE_OK;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MRESULT AeMgr::getTgIntAEInfo(MBOOL &bTgIntAEEn, MFLOAT &fTgIntAERatio)
{
    bTgIntAEEn = m_bTgIntAEEn & m_bPerframeAEFlag;
    fTgIntAERatio = TG_INT_AE_RATIO;
    AE_LOG( "[%s()] m_bTgIntAEEn:%d, m_bPerframeAEFlag:%d, TG_INT_AE_RATIO:%f\n", __FUNCTION__, m_bTgIntAEEn, m_bPerframeAEFlag, fTgIntAERatio);
    return S_AE_OK;
}

