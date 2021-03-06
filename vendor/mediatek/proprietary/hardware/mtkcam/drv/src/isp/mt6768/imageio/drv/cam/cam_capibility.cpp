/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "cam_capibitiliy"

#include "cam_capibility.h"

#include <mtkcam/drv/def/ICam_type.h>
#include <mtkcam/drv/def/ispio_port_index.h>
#include <mtkcam/drv/iopipe/CamIO/INormalPipe.h>
#include <mtkcam/def/ImageFormat.h>
#include "isp_drv_stddef.h"


#include <cutils/properties.h>  // For property_get().
#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#ifndef USING_MTK_LDVT   // Not using LDVT.
#define  DBG_LOG_TAG        ""
#else
#define  DBG_LOG_TAG        LOG_TAG
#endif


#ifndef USING_MTK_LDVT   // Not using LDVT.
#ifdef MTK_LOG_ENABLE
#undef MTK_LOG_ENABLE
#endif
#define MTK_LOG_ENABLE 1
    #include <cutils/log.h>

    #define CAM_CAP_DBG(fmt, arg...)    ALOGD(LOG_TAG"[%s](%5d)"     fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_INF(fmt, arg...)    ALOGD(LOG_TAG"[%s](%5d)"     fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_WRN(fmt, arg...)    ALOGW(LOG_TAG"[%s]WRN(%5d):" fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_ERR(fmt, arg...)    ALOGE(LOG_TAG"[%s]ERR(%5d):" fmt, __FUNCTION__, __LINE__, ##arg)

#else   // Using LDVT.
    #include "uvvf.h"

    #define CAM_CAP_DBG(fmt, arg...)    VV_MSG(LOG_TAG"[%s](%5d)"     fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_INF(fmt, arg...)    VV_MSG(LOG_TAG"[%s](%5d)"     fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_WRN(fmt, arg...)    VV_MSG(LOG_TAG"[%s]WRN(%5d):" fmt, __FUNCTION__, __LINE__, ##arg)
    #define CAM_CAP_ERR(fmt, arg...)    VV_MSG(LOG_TAG"[%s]ERR(%5d):" fmt, __FUNCTION__, __LINE__, ##arg)

#endif  // USING_MTK_LDVT

capibility::D_TWIN_CFG capibility::m_DTwin;

MBOOL capibility::GetCapibility(MUINT32 portId,NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd e_Op,
                                        NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo inputInfo,tCAM_rst &QueryRst,E_CAM_Query_OP inerOP)
{
    MBOOL ret = MTRUE;

    if (inerOP == E_CAM_UNKNOWNN) {
        MUINT32 valid_cmd_cap = (
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_BS_RATIO |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_QUERY_FMT |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_PIPELINE_BITDEPTH|
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_D_Twin |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_UNI_NUM |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_BURST_NUM|
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_SUPPORT_PATTERN|
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_DYNAMIC_PAK);

        MUINT32 valid_cmd_constraint = (
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_PIX |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_PIX |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_BYTE |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_START_X |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_PIX |
                    NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_BYTE);

        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_BS_RATIO){
            if( (QueryRst.ratio = this->GetRatio(portId)) == 0 )
                ret = MFALSE;
        }

        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_QUERY_FMT){
            if( this->GetFormat(portId, inputInfo.SecOn, QueryRst) == MFALSE )
                ret = MFALSE;
        }

        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_PIPELINE_BITDEPTH){
            QueryRst.pipelinebitdepth = this->GetPipelineBitdepth();
        }
        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_BURST_NUM){
            QueryRst.burstNum = this->GetSupportBurstNum();
        }

        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_SUPPORT_PATTERN){
            QueryRst.pattern = this->GetSupportPattern();
        }
        if(e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_D_Twin){
            //enable support dynamic twin
            QueryRst.D_TWIN = MTRUE;
        }
        if((e_Op & valid_cmd_cap) == NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_DYNAMIC_PAK){
            //donothing, just use default vaule
            //QueryRst.D_Pak;
        }
        if (e_Op & valid_cmd_constraint) {
            if (this->GetConstrainedSize(portId, e_Op, inputInfo, QueryRst) == MFALSE) {
                ret = MFALSE;
            }
        }

        if(e_Op & (~(valid_cmd_cap|valid_cmd_constraint))){
            ret = MFALSE;
            CAM_CAP_ERR("some query cmd(0x%x) is not supported. valid cmd(0x%x)\n",e_Op,(valid_cmd_cap|valid_cmd_constraint));
        }
    }
    else
        return this->GetCapibility_drv(portId,inerOP,QueryRst,inputInfo.pixelMode);

    return ret;
}

MBOOL capibility::GetCapibility_drv(MUINT32 portId,E_CAM_Query_OP inerOP,tCAM_rst &QueryRst,NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode)
{
    MBOOL ret = MTRUE;portId;
    if(inerOP & (E_CAM_SRAM_DMX|E_CAM_SRAM_BMX|E_CAM_SRAM_AMX|E_CAM_SRAM_RMX|E_CAM_SRAM_PMX)){
        if(this->GetXMXSramSize(&QueryRst.xmx) == 0){
            CAM_CAP_ERR("xmx sram size error\n");
            ret = MFALSE;
        }
        if(this->GetXMXLineBuffer(&QueryRst.xmx) == 0){
            CAM_CAP_ERR("xmx linebuffer error\n");
            ret = MFALSE;
        }
    }


    if(inerOP & E_CAM_pipeline_size){
        QueryRst.pipeSize = this->GetPipeSize();
    }

    if(inerOP & E_CAM_BS_Max_size){
        QueryRst.bs_max_size = this->GetRRZSize();
    }

    if(inerOP & E_CAM_HEADER_size){
        QueryRst.HeaderSize = this->GetHeaderSize();
    }

    if (inerOP & E_CAM_pipeline_min_size) {
        this->GetPipelineMinSize(&QueryRst.pipelineMinSize, pixMode);
    }

    return ret;
}

MUINT32 capibility::GetFormat(MUINT32 portID, MBOOL SecOn, tCAM_rst &QueryRst)
{

    if(QueryRst.Queue_fmt.size()){
        CAM_CAP_ERR("current portID(0x%x) Queue_fmt need init\n",portID);
        return MFALSE;
    }

    if(SecOn == MTRUE){
        switch(portID){
            case NSImageio::NSIspio::EPortIndex_IMGO:
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER8);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER12);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10_MIPI);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER8_UNPAK);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10_UNPAK);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER12_UNPAK);
                break;
            case NSImageio::NSIspio::EPortIndex_RRZO:
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER8);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER10);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER12);
                break;
            default:
                CAM_CAP_ERR("current portID(0x%x) are not supported in query\n",portID);
                return MFALSE;
                break;
        }
    }
    else if(SecOn == MFALSE){
        switch(portID){
            case NSImageio::NSIspio::EPortIndex_IMGO:
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER8);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER12);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10_MIPI);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER8_UNPAK);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER10_UNPAK);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_BAYER12_UNPAK);
                break;
            case NSImageio::NSIspio::EPortIndex_RRZO:
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER8);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER10);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_FG_BAYER12);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_UFEO_BAYER8);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_UFEO_BAYER10);
                QueryRst.Queue_fmt.push_back(NSCam::eImgFmt_UFEO_BAYER12);
                break;
            default:
                CAM_CAP_ERR("current portID(0x%x) are not supported in query\n",portID);
                return MFALSE;
                break;
        }
    }
    return MTRUE;
}

MUINT32 capibility::GetRatio(MUINT32 portID)
{
    #define MAX_SCALING_DWON_RATIO  (25)        //unit:%

    switch(portID){
        case NSImageio::NSIspio::EPortIndex_RRZO:
            return MAX_SCALING_DWON_RATIO;
            break;
        default:
            CAM_CAP_ERR("curent portID(0x%x) are no scaler\n",portID);
            break;

    }
    return 100;
}

MUINT32 capibility::GetPipelineBitdepth()
{
    return (NSCam::NSIoPipe::NSCamIOPipe::CAM_Pipeline_12BITS);
}

MVOID capibility::GetPipelineMinSize(minSize* size, NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode)
{
    #define CAM_PIPELINE_MIN_WIDTH_SIZE  (120*4) //awb win_w is fixed in 120, 4 is for 1 block need 4 pixels.
    #define CAM_PIPELINE_MIN_HEIGHT_SIZE (90*2) //awb win_h is fixed in 90, 2 is for 1 block need 2 pixels.

    if (pixMode == NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE) { // 2 pixels for qbin_acc 1
        size->w = CAM_PIPELINE_MIN_WIDTH_SIZE*2;
        size->h = CAM_PIPELINE_MIN_HEIGHT_SIZE*2;
    } else {
        size->w = CAM_PIPELINE_MIN_WIDTH_SIZE;
        size->h = CAM_PIPELINE_MIN_HEIGHT_SIZE;
    }
}

MUINT32 capibility::GetPipeSize()
{
    #define CAM_BNR_MAX_LINE_BUFFER_IN_PIXEL (5056)

    return CAM_BNR_MAX_LINE_BUFFER_IN_PIXEL;
}

MUINT32 capibility::GetRRZSize()
{
    #undef CAM_RRZ_MAX_LINE_BUFFER_IN_PIXEL
    #define CAM_RRZ_MAX_LINE_BUFFER_IN_PIXEL (4736)

    return CAM_RRZ_MAX_LINE_BUFFER_IN_PIXEL;
}

MUINT32 capibility::GetXMXSramSize(tXmx* pXmx)
{
    #define DMX_SRAM    (3456/8)//(864)
    #define RMX_SRAM    (2368/8)//(576)
    #define BMX_SRAM    (1728/8)//(864)
    #define PMX_SRAM    (2112/4)//(384)
    #define AMX_SRAM    (1728/8)//SRAM_SIZE[15:0]


    pXmx->sram_dmx = DMX_SRAM;
    pXmx->sram_bmx = BMX_SRAM;
    pXmx->sram_amx = AMX_SRAM;
    pXmx->sram_rmx = RMX_SRAM;
    pXmx->sram_pmx = PMX_SRAM;


    return 1;
}

MUINT32 capibility::GetSupportBurstNum()
{
    /*
    return support burst number
    0x0 : not support       // ISP 3.0
    0x2 : support 2
    0x6 : support 2|4
    0xE : support 2|4|8
    0x1E: support 2|4|8|16  // ISP 4.0
    */
    return 0x1E;
}

MUINT32 capibility::GetSupportPattern()
{
    MUINT32 pattern;
    pattern = 0x1 << eCAM_NORMAL  |
              0x1 << eCAM_DUAL_PIX|
              0x1 << eCAM_QuadCode|
              0x1 << eCAM_4CELL   |
              0x1 << eCAM_MONO    |
              0x1 << eCAM_IVHDR   |
              0x1 << eCAM_4CELL_IVHDR   |
              0x1 << eCAM_DUAL_PIX_IVHDR|
              0x1 << eCAM_YUV;
    return pattern;
}

MUINT32 capibility::GetXMXLineBuffer(tXmx* pXmx)
{
    #define DUAL_RAW_WD     (3456)//(6804)
    #define DUAL_AMX_WD     (1728)
    #define DUAL_BMX_WD     (1728)
    #define DUAL_PMX_WD     (2118)


    pXmx->line_dmx = DUAL_RAW_WD;
    pXmx->line_bmx = DUAL_BMX_WD;
    pXmx->line_amx = DUAL_AMX_WD;
    pXmx->line_rmx = this->GetRRZSize();
    pXmx->line_pmx = DUAL_PMX_WD;

    return 1;
}

MUINT32 capibility::GetHeaderSize()
{
    return CAM_IMAGE_HEADER * 4;
}


#define _query_p2_stride_constraint( stride){\
    stride = (stride + 0x3) & (~0x3);\
}

#define query_rrzo_constraint(xsize,pixMode,imgFmt){\
    switch(pixMode){\
        case NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE:\
        case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:\
            xsize = (xsize + 0xf) & (~0xf);\
            break;\
        case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:\
            xsize = (xsize + 0x7) & (~0x7);\
            break;\
        case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:\
            if(imgFmt == NSCam::eImgFmt_FG_BAYER10)\
                xsize = (xsize + 0x3) & (~0x3);\
            else\
                xsize = (xsize + 0x7) & (~0x7);\
            break;\
        default:\
            xsize = (xsize + 0xf) & (~0xf);\
        break;\
    }\
}


static MUINT32 _query_fg_constraint(MUINT32 size)
{
    return (size&0x3)? 0 : 1;
}

static MUINT32 _query_fg_align_size(MUINT32 size)
{
    return ((size + 0x3) & ~0x3);
}

static MUINT32  _queryBitPerPix(MUINT32 const imgFmt)
{
    MUINT32 pixDepth;

    switch (imgFmt) {
        case NSCam::eImgFmt_BAYER8:          //= 0x0001,   //Bayer format, 8-bit
        case NSCam::eImgFmt_Y8:              //weighting table
        case NSCam::eImgFmt_FG_BAYER8:
            pixDepth = 8;
            break;
        case NSCam::eImgFmt_BAYER10:         //= 0x0002,   //Bayer format, 10-bit
        case NSCam::eImgFmt_FG_BAYER10:
            pixDepth = 10;
            break;
        case NSCam::eImgFmt_UFEO_BAYER10:
            pixDepth = 10;
            break;
        case NSCam::eImgFmt_BAYER12:         //= 0x0004,   //Bayer format, 12-bit
        case NSCam::eImgFmt_FG_BAYER12:
            pixDepth = 12;
            break;
        case NSCam::eImgFmt_UFEO_BAYER12:
            pixDepth = 12;
            break;

        case NSCam::eImgFmt_BAYER14:         //= 0x0008,   //Bayer format, 14-bit
            pixDepth = 16;//?
            break;
        case NSCam::eImgFmt_UFO_BAYER10:
            pixDepth = 10;
            break;
        case NSCam::eImgFmt_YUY2:            //= 0x0100,   //422 format, 1 plane (YUYV)
        case NSCam::eImgFmt_UYVY:            //= 0x0200,   //422 format, 1 plane (UYVY)
        case NSCam::eImgFmt_YVYU:            //= 0x080000,   //422 format, 1 plane (YVYU)
        case NSCam::eImgFmt_VYUY:            //= 0x100000,   //422 format, 1 plane (VYUY)
            pixDepth = 16;
            break;
        case NSCam::eImgFmt_NV16:  //user would set format_nv16 to all of 2 planes if multi-plane(img3o~img3bo)
        case NSCam::eImgFmt_NV12:
        case NSCam::eImgFmt_YV12:  //user would set format_yv12 to all of 3 planes if multi-plane(img3o~img3co)
        case NSCam::eImgFmt_I420:
            pixDepth = 8;   //temp use pixDepth 8
            break;
        case NSCam::eImgFmt_RGB565:
        case NSCam::eImgFmt_STA_2BYTE:
            pixDepth = 16;
            break;
        case NSCam::eImgFmt_RGB888:
            pixDepth = 24;
            break;
        case NSCam::eImgFmt_JPEG:
            pixDepth = 8;
            break;
        case NSCam::eImgFmt_STA_BYTE:
        case NSCam::eImgFmt_UFO_FG:
            pixDepth = 1;
            break;
        default:
            CAM_CAP_ERR("eImgFmt:[%d]NOT Support",imgFmt);
            return -1;
    }
    if( imgFmt == NSCam::eImgFmt_FG_BAYER8 ||
        imgFmt == NSCam::eImgFmt_FG_BAYER10 ||
        imgFmt == NSCam::eImgFmt_FG_BAYER12 ||
        imgFmt == NSCam::eImgFmt_UFO_BAYER10)
    {
        pixDepth = (pixDepth*3)/2;
    }
    return pixDepth;
}


static MUINT32 _queryCropStart(MUINT32 portId,NSCam::EImageFormat imgFmt,MUINT32 input, tCAM_rst &QueryRst,
                                        NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE e_PixMode)
{
    switch(portId){
    case NSImageio::NSIspio::EPortIndex_IMGO:
        switch(imgFmt){
        case NSCam::eImgFmt_BAYER10:
            switch(e_PixMode){
            case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:
                //if bus size 16bit, the inputer must be 8 alignment,
                QueryRst.crop_x = (input >> 3) << 3;
                break;
            case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:
                //if bus size 16bit, the inputer must be 16 alignment,
                QueryRst.crop_x = (input >> 4) << 4;
                break;
            default:
            case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:
                //if bus size 16bit, the inputer must be 32 alignment,
                QueryRst.crop_x = (input >> 5) << 5;
                break;
            }
            break;
        case NSCam::eImgFmt_BAYER12:
            switch(e_PixMode){
            case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:
                //if bus size 16bit, the inputer must be 4 alignment,
                QueryRst.crop_x = (input >> 2) << 2;
                break;
            case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:
                //if bus size 16bit, the inputer must be 8 alignment,
                QueryRst.crop_x = (input >> 3) << 3;
                break;
            default:
            case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:
                //if bus size 16bit, the inputer must be 16 alignment,
                QueryRst.crop_x = (input >> 4) << 4;
                break;
            }
            break;
        case NSCam::eImgFmt_BAYER8:
        case NSCam::eImgFmt_FG_BAYER8:
        case NSCam::eImgFmt_FG_BAYER10:
        case NSCam::eImgFmt_FG_BAYER12:
        case NSCam::eImgFmt_UFEO_BAYER10:
        case NSCam::eImgFmt_UFEO_BAYER12:
            switch(e_PixMode){
            case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:
                //if bus size 16bit, the inputer must be 2 alignment,
                QueryRst.crop_x = (input >> 1) << 1;
                break;
            case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:
                //if bus size 16bit, the inputer must be 4 alignment,
                QueryRst.crop_x = (input >> 2) << 2;
                break;
            default:
            case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:
                //if bus size 16bit, the inputer must be 8 alignment,
                QueryRst.crop_x = (input >> 3) << 3;
                break;
            }
            break;
        case NSCam::eImgFmt_BAYER8_UNPAK:
        case NSCam::eImgFmt_BAYER10_UNPAK:
        case NSCam::eImgFmt_BAYER12_UNPAK:
        case NSCam::eImgFmt_BAYER14_UNPAK:
            QueryRst.crop_x = 0;
            break;
        default:
            QueryRst.crop_x = 0;
            CAM_CAP_ERR("NOT SUPPORT imgFmt(%d)",imgFmt);
            return 0;
            break;
        }
        break;
    case NSImageio::NSIspio::EPortIndex_RRZO://rrz support only rrz_in crop, not dma crop
        input -= (input&0x1);
        QueryRst.crop_x = input;
        break;
    default:
        CAM_CAP_ERR("NOT SUPPORT port(%d)",portId);
        break;
    }

    return 1;
}


static MUINT32 _query_p2_constraint(MUINT32 size)
{
    return (size&0x1) ? 0 : 1;
}

static MUINT32 _query_pix_mode_constraint(MUINT32 size, MUINT32 pixMode){
    /*
    1 pix mode => 2n
    2 pix mode => 4n
    but current flow , user have no pix mode information, so fix 4n for safety
    */
    MUINT32 divisor = 0x3;
    switch(pixMode){
        case NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE:
        case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:
            divisor = 0x7;
            break;
        case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:
            divisor = 0x3;
            break;
        case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:
            divisor = 0x1;
            break;
        default:
            CAM_CAP_ERR("pix mode error(%d)",pixMode);
            break;
    }
    if(size & divisor)
        return 0;
    else
        return 1;
}
static MUINT32 _query_pix_mode_align_size(MUINT32 size, MUINT32 pixMode)
{
    MUINT32 divisor = 0x7, align_size = size;

    switch (pixMode) {
        case NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE:
        case NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE:
            divisor = 0x7;
            break;
        case NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE:
            divisor = 0x3;
            break;
        case NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE:
            divisor = 0x1;
            break;
        default:
            CAM_CAP_ERR("pix mode error(%d)", pixMode);
            break;
    }

    align_size = ((align_size + divisor) & ~divisor);

    return align_size;
}

static MBOOL _queryXsize_imgo(NSCam::EImageFormat imgFmt, MUINT32& xsize, MUINT32& outWidth,
                                        NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode, MBOOL bCrop)
{
    outWidth += (outWidth&0x1);

    switch(imgFmt){
    case NSCam::eImgFmt_BAYER8:
    case NSCam::eImgFmt_JPEG:
        xsize = outWidth;

        //expand stride, instead of shrink width
        if (!(_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if (_query_p2_constraint(aligned)) {
                CAM_CAP_ERR("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_UFO_BAYER10:
    case NSCam::eImgFmt_BAYER10_MIPI:
    case NSCam::eImgFmt_BAYER10:
        if (bCrop == MFALSE) {//do nothing
        }
        else {
            //width need 4 alignment to make sure xsize is 8-alignment
            if (outWidth & 0x2) {
                CAM_CAP_WRN("WARNING: constraint: 4 align for outWidth(%d)\n", outWidth);
                outWidth -= 2;
            }
        }
        xsize = (outWidth*10 + 7) / 8;
        xsize += (xsize & 0x1);

        //expand stride, instead of shrink width
        if (!((_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize)))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if (_query_p2_constraint(aligned)) {
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_BAYER12:
        //no need to patch under cropping , because outWidth must be at leaset 2-alignment
        xsize = (outWidth*12 + 7) / 8;
        xsize += (xsize & 0x1);

        //expand stride, instead of shrink width
        if (!((_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize)))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if (_query_p2_constraint(aligned)) {
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_BAYER14:
	//no need to patch under cropping , because outWidth must be at leaset 2-alignment
        xsize = (outWidth*14 + 7) / 8;
        xsize += (xsize & 0x1);
        //expand stride, instead of shrink width
        if (!((_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize)))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);
            if (_query_p2_constraint(aligned)) {
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_BAYER8_UNPAK:
    case NSCam::eImgFmt_BAYER10_UNPAK:
    case NSCam::eImgFmt_BAYER12_UNPAK:
        xsize = outWidth * 2; //fixed 16 bit
        xsize += (xsize & 0x1);

        if (!((_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize)))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if( _query_p2_constraint(xsize))
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_YUY2:
    case NSCam::eImgFmt_UYVY:
    case NSCam::eImgFmt_YVYU:
    case NSCam::eImgFmt_VYUY:
        xsize = outWidth * 2;
        //expand stride, instead of shrink width
        if (!((_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize)))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if (_query_p2_constraint(aligned)) {
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_RGB888:
    case NSCam::eImgFmt_RGB565:
        xsize = outWidth * 2;
        //expand stride, instead of shrink width
        if (!(_query_pix_mode_constraint(xsize, pixMode) && _query_p2_constraint(xsize))) {
            MUINT32 aligned = _query_pix_mode_align_size(xsize, pixMode);

            if (_query_p2_constraint(aligned)) {
                CAM_CAP_DBG("constraint: align xsize(%d/%d)\n", xsize, aligned);
            }
            else {
                CAM_CAP_ERR("constraint: cannot pass p2 constraint(%d)\n", xsize);
            }
            xsize = aligned;
        }
        CAM_CAP_ERR("NOT SUPPORT imgFmt(%d)",imgFmt);
        break;
    case NSCam::eImgFmt_BLOB:
        xsize = outWidth;
        break;
    default:
        xsize = outWidth = 0;
        CAM_CAP_ERR("NOT SUPPORT imgFmt(%d)",imgFmt);
        return MFALSE;
        break;
    }
    return MTRUE;
}

static MBOOL _queryXsize_rrzo(NSCam::EImageFormat imgFmt, MUINT32& xsize, MUINT32& outWidth,
                                        NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode)
{
    outWidth += (outWidth&0x1);

    if ((outWidth > CAM_RRZ_MAX_LINE_BUFFER_IN_PIXEL) && (pixMode == NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE)) {
        CAM_CAP_ERR("rrzo output over 2304, support no 1 pix mode, 2 pix mode will be enabled\n");
        CAM_CAP_ERR("Warning: plz re-check imgo limitation in 2 pix mode if imgo is needed\n");
    }

    switch(imgFmt){
    case NSCam::eImgFmt_FG_BAYER8:
        xsize = outWidth*3>>1;
        query_rrzo_constraint(xsize,pixMode,imgFmt);

        //expand stride, instead of shrink width
        if (!_query_fg_constraint(xsize)) {
            MUINT32 aligned = _query_fg_align_size(xsize);

            CAM_CAP_INF("constraint: align fg xsize(%d/%d)\n", xsize, aligned);
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_FG_BAYER10:
        xsize = outWidth*3>>1;
        xsize = (xsize*10 + 7) / 8;
        query_rrzo_constraint(xsize,pixMode,imgFmt);

        //expand stride, instead of shrink width
        if (!_query_fg_constraint(xsize)) {
            MUINT32 aligned = _query_fg_align_size(xsize);

            CAM_CAP_INF("constraint: align fg xsize(%d/%d)\n", xsize, aligned);
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_FG_BAYER12:
        xsize = outWidth*3>>1;
        xsize = (xsize*12 + 7) / 8;
        query_rrzo_constraint(xsize,pixMode,imgFmt);

        //expand stride, instead of shrink width
        if (!_query_fg_constraint(xsize)) {
            MUINT32 aligned = _query_fg_align_size(xsize);

            CAM_CAP_INF("constraint: align fg xsize(%d/%d)\n", xsize, aligned);
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_UFEO_BAYER10:
        xsize = outWidth*3>>1;
        xsize = (xsize*10 + 7) / 8;
        query_rrzo_constraint(xsize,pixMode,imgFmt);

        //expand stride, instead of shrink width
        if (!_query_fg_constraint(xsize)) {
            MUINT32 aligned = _query_fg_align_size(xsize);

            CAM_CAP_INF("constraint: align fg xsize(%d/%d)\n", xsize, aligned);
            xsize = aligned;
        }
        break;
    case NSCam::eImgFmt_UFEO_BAYER12:
        xsize = outWidth*3>>1;
        xsize = (xsize*12 + 7) / 8;
        query_rrzo_constraint(xsize,pixMode,imgFmt);

        //expand stride, instead of shrink width
        if (!_query_fg_constraint(xsize)) {
            MUINT32 aligned = _query_fg_align_size(xsize);

            CAM_CAP_INF("constraint: align fg xsize(%d/%d)\n", xsize, aligned);
            xsize = aligned;
        }
        break;
    default:
        xsize = outWidth = 0;
        CAM_CAP_ERR("rrzo NOT SUPPORT imgFmt(%d)",imgFmt);
        return MFALSE;
        break;
    }
    return MTRUE;
}

static MBOOL _queryXsize_ufeo(NSCam::EImageFormat imgFmt,MUINT32& xsize, MUINT32& outWidth)
{
    outWidth += (outWidth&0x1);

    switch(imgFmt){
    case NSCam::eImgFmt_UFEO_BAYER10:
    case NSCam::eImgFmt_UFEO_BAYER12:
        xsize = (((outWidth+63)/64)+7)/8*8;
        break;
    default:
        xsize = outWidth = 0;
        CAM_CAP_ERR("ufeo NOT SUPPORT imgFmt(%d)",imgFmt);
        return MFALSE;
        break;
    }
    return MTRUE;
}


MUINT32 capibility::GetConstrainedSize(MUINT32 portId, NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd e_Op,
                                                    NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo inputInfo, tCAM_rst &QueryRst)
{
    MUINT32 xsize, outWidth = inputInfo.width;
    MBOOL   _bCrop = MFALSE;

    switch(portId){
    case NSImageio::NSIspio::EPortIndex_IMGO:
    case NSImageio::NSIspio::EPortIndex_CAMSV_IMGO:

        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_PIX|NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_BYTE)) {
            _bCrop = MTRUE;
        }
        else {
            _bCrop = MFALSE;
        }

        if (_queryXsize_imgo(inputInfo.format, xsize, outWidth, inputInfo.pixelMode, _bCrop) == MFALSE) {
            return MFALSE;
        }

        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_PIX|NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_PIX)) {
            QueryRst.x_pix = outWidth;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_PIX) {
            QueryRst.stride_pix = xsize / _queryBitPerPix(inputInfo.format);
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_BYTE) {
            QueryRst.stride_byte = xsize;
            _query_p2_stride_constraint(QueryRst.stride_byte);
        }
        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE|NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_BYTE)) {
            QueryRst.xsize_byte = xsize;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_START_X) {
            if (_queryCropStart(portId, inputInfo.format, inputInfo.width, QueryRst, inputInfo.pixelMode) == 0) {
                CAM_CAP_ERR("unsupported format:0x%x\n",inputInfo.format);
            }
        }
        break;
    case NSImageio::NSIspio::EPortIndex_UFEO:
        if (_queryXsize_ufeo(inputInfo.format,xsize,outWidth) == MFALSE) {
            return MFALSE;
        }

        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_PIX)) {
            QueryRst.x_pix = outWidth;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_BYTE) {
            QueryRst.stride_byte = xsize;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE) {
            QueryRst.xsize_byte = xsize;
        }
        break;
    case NSImageio::NSIspio::EPortIndex_RRZO:
        if (_queryXsize_rrzo(inputInfo.format, xsize, outWidth, inputInfo.pixelMode) == MFALSE) {
            return MFALSE;
        }

        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_PIX|NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_PIX)) {
            QueryRst.x_pix = outWidth;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_PIX) {
            QueryRst.stride_pix = outWidth / _queryBitPerPix(inputInfo.format);
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_BYTE) {
            QueryRst.stride_byte = xsize;
        }
        if (e_Op & (NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE|NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_BYTE)) {
            QueryRst.xsize_byte = xsize;
        }
        if (e_Op & NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_START_X){
            if (_queryCropStart(portId, inputInfo.format, inputInfo.width, QueryRst, inputInfo.pixelMode) == 0) {
                CAM_CAP_ERR("unsupported format:0x%x\n",inputInfo.format);
            }
        }
        break;
    default:
        CAM_CAP_ERR("current portID(0x%x) r not supported in query\n",portId);
        QueryRst.x_pix = QueryRst.stride_pix = QueryRst.stride_byte = 0;
        return MFALSE;
        break;
    }

    return MTRUE;
}

MBOOL capibility::D_TWIN_CFG::SetDTwin(MBOOL ON)
{
    this->m_DTwin = ON;
    if(m_DTwin)
        CAM_CAP_INF("enable Dynamic twin!!!!\n");
    return MTRUE;
}

MBOOL capibility::D_TWIN_CFG::GetDTwin(void)
{
    return this->m_DTwin;
}

