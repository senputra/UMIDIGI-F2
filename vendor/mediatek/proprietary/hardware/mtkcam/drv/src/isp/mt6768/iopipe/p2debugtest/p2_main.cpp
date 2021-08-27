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

///////////////////////////////////////////////////////////////////////////////
// No Warranty
// Except as may be otherwise agreed to in writing, no warranties of any
// kind, whether express or implied, are given by MTK with respect to any MTK
// Deliverables or any use thereof, and MTK Deliverables are provided on an
// "AS IS" basis.  MTK hereby expressly disclaims all such warranties,
// including any implied warranties of merchantability, non-infringement and
// fitness for a particular purpose and any warranties arising out of course
// of performance, course of dealing or usage of trade.  Parties further
// acknowledge that Company may, either presently and/or in the future,
// instruct MTK to assist it in the development and the implementation, in
// accordance with Company's designs, of certain softwares relating to
// Company's product(s) (the "Services").  Except as may be otherwise agreed
// to in writing, no warranties of any kind, whether express or implied, are
// given by MTK with respect to the Services provided, and the Services are
// provided on an "AS IS" basis.  Company further acknowledges that the
// Services may contain errors, that testing is important and Company is
// solely responsible for fully testing the Services and/or derivatives
// thereof before they are used, sublicensed or distributed.  Should there be
// any third party action brought against MTK, arising out of or relating to
// the Services, Company agree to fully indemnify and hold MTK harmless.
// If the parties mutually agree to enter into or continue a business
// relationship or other arrangement, the terms and conditions set forth
// hereunder shall remain effective and, unless explicitly stated otherwise,
// shall prevail in the event of a conflict in the terms in any agreements
// entered into between the parties.
////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2008, MediaTek Inc.
// All rights reserved.
//
// Unauthorized use, practice, perform, copy, distribution, reproduction,
// or disclosure of this information in whole or in part is prohibited.


#define LOG_TAG "p2debugtest"

#include <vector>

#include <sys/time.h>
#include <sys/stat.h>
#include <sys/prctl.h>

#include <stdio.h>
#include <stdlib.h>
//
#include <errno.h>
#include <fcntl.h>

#include <mtkcam/def/common.h>

//
#include <mtkcam/drv/iopipe/PostProc/INormalStream.h>

#include <ispio_pipe_ports.h>
#include <imem_drv.h>
#include <isp_drv.h>

#include <mtkcam/utils/imgbuf/IImageBuffer.h>
#include <utils/StrongPointer.h>
#include <mtkcam/utils/std/common.h>
#include <mtkcam/utils/imgbuf/ImageBufferHeap.h>
//
//thread
#include <utils/threads.h>
#include <mtkcam/def/PriorityDefs.h>
//thread priority
#include <system/thread_defs.h>
#include <sys/resource.h>
#include <utils/ThreadDefs.h>
#include <pthread.h>
#include <semaphore.h>
#include "DpIspStream.h"

#include "isp_drv_dip_phy.h"
//
using namespace std;
using namespace android;
using namespace NSCam;
using namespace NSIoPipe;
using namespace NSPostProc;

/******************************************************************************
* save the buffer to the file
*******************************************************************************/
static bool
saveBufToFile(char const*const fname, MUINT8 *const buf, MUINT32 const size)
{
    int nw, cnt = 0;
    uint32_t written = 0;

    //LOG_INF("(name, buf, size) = (%s, %x, %d)", fname, buf, size);
    //LOG_INF("opening file [%s]\n", fname);
    int fd = ::open(fname, O_RDWR | O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf(": failed to create file [%s]: %s \n", fname, ::strerror(errno));
        return false;
    }

	printf("writing %d bytes to file [%s]\n", size, fname);

    //LOG_INF("writing %d bytes to file [%s]\n", size, fname);
    while (written < size) {
        nw = ::write(fd,
                     buf + written,
                     size - written);
        if (nw < 0) {
            printf(": failed to write to file [%s]: %s\n", fname, ::strerror(errno));
            break;
        }
        written += nw;
        cnt++;
    }
    //LOG_INF("done writing %d bytes to file [%s] in %d passes\n", size, fname, cnt);
    ::close(fd);
    return true;
}

/*******************************************************************************
* Driver Test Case
********************************************************************************/
enum EDrvTestCase
{
    //
    eDrvTestCase_P2A = 0,      //  normal, P2A path
    //
    eDrvTestCase_VFB_FB = 1,       //  FB, P2B path
    //
    eDrvTestCase_MFB_Blending = 2 ,          //  blending, P2A
    //
    eDrvTestCase_MFB_Mixing = 3,      //  mixing
    //
    eDrvTestCase_VSS = 4,                //  vss, P2A
    //
    eDrvTestCase_P2B_Bokeh = 5,     //  Boken, P2B
    //
    eDrvTestCase_FE = 6,            // including FE module
    //
    eDrvTestCaseo_FM = 7,            // including FM module
     //
    eDrvTestCase_Color_Effect = 8,            // specific color effect path
};


/*******************************************************************************
*  Main Function
*
*  p2debugtest 1 2 0 1
*  1st Argument: P2 Test
*  2nd Argument: Test Case Number
*  3rd Argument(testType): Defined by Test Cause
*  4th Argument(loopNum): Run Test Case Times
*
********************************************************************************/
int test_P2A(int type,int loopNum);
int test_MFB_Blending(int type,int loopNum);
int test_MFB_Mixing(int type,int loopNum);
int test_VSS(int type,int loopNum);
void VSS_Callback(QParams& rParams);
bool g_VSS_Callback = MFALSE;

int test_p2_main(int argc, char** argv)
{
    int ret = 0;
    if(argc<4)
    {
        printf("wrong paramerter number(%d)\n",argc);
        return 0;
    }


    printf("##############################\n");
    printf("\n");
    printf("##############################\n");

    int testNum = atoi(argv[1]);
    int testType = atoi(argv[2]);
    int loopNum = atoi(argv[3]);

    switch(testNum)
    {
        case eDrvTestCase_P2A:
        	ret=test_P2A(testType,loopNum);
        	break;
        case eDrvTestCase_MFB_Blending:
            ret=test_MFB_Blending(testType,loopNum);
            break;
        case eDrvTestCase_MFB_Mixing:
            ret=test_MFB_Mixing(testType,loopNum);
            break;
        case eDrvTestCase_VSS:
            ret=test_VSS(testType,loopNum);
            break;

        default:
        	break;
    }

    ret = 1;
    return ret;
}

#include "pic/imgi_5344_4016_yuy2.h"
#include "pic/tuningbuf.h"
#include "pic/tuningbuf_p2a.h"
#include "pic/tuningbuf_mixing.h"
#include "pic/srz5.h"

/*********************************************************************************/
int test_P2A(int type,int loopNum)
{

    int ret=0;
    printf("--- [test_P2A(%d)...enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr]\n", type);
    NSCam::NSIoPipe::NSPostProc::INormalStream* pStream;
    pStream= NSCam::NSIoPipe::NSPostProc::INormalStream::createInstance(0xFFFF);
    pStream->init("test_P2A");
    printf("--- [test_P2A(%d)...pStream init done]\n", type);
    IMemDrv* mpImemDrv=NULL;
    mpImemDrv=IMemDrv::createInstance();
    mpImemDrv->init();

/*
154398 04-19 08:51:38.596669 29121 30296 D PostProcPipe: [PrintPipePortInfo] vInPorts:FN(331),RN(331),TS(0x512ec35),UK(0x0),[0]:(0x2205),w(1280),h(720),stride(2400,0,0),type(0),idx(19),dir(0),Size(0x001a5e00,0x00000000,0x00000000),VA(0x99fb1000,0x0,0x0),PA(0x6c00000,0x0,0x0),
154399 04-19 08:51:38.596669 29121 30296 D PostProcPipe:                       vInPorts:FN(331),RN(331),TS(0x512ec35),UK(0x0),[1]:(0x32315659),w(1280),h(720),stride(1280,640,640),type(0),idx(22),dir(0),Size(0x000f0000,0x0003c000,0x0003c000),VA(0x9d49a000,0x9d58a000,0x9d5c6000),PA(0x2000000,0x20f0000,0x212c000)
154402 04-19 08:51:38.596765 29121 30296 D PostProcPipe: [PrintPipePortInfo] vOutPorts:FN(331),RN(331),TS(0x512ec35),UK(0x0),[0]:(0x32315659),w(1280),h(720),stride(1280,640,640),type(0),idx(38),dir(1),Size(0x000e1000,0x00038400,0x00038400),VA(0x9ac54000,0x9ad35000,0x9ad6d400),PA(0xfa00000,0xfae1000,0xfb19400),
154403 04-19 08:51:38.596765 29121 30296 D PostProcPipe:                       vOutPorts:FN(331),RN(331),TS(0x512ec35),UK(0x0),[1]:(0x32315659),w(1280),h(720),stride(1280,640,640),type(0),idx(32),dir(1),Size(0x000f0000,0x0003c000,0x0003c000),VA(0x9cda0000,0x9ce90000,0x9cecc000),PA(0xbd00000,0xbdf0000,0xbe2c000)
154407 04-19 08:51:38.596888 29121 30296 D PostProcPipe: [configPipe] [Imgi][crop_1](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(0,0,0,0)-[crop_2](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(1280,718,1280,720)-[crop_3](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(0,0,0,0),dupCqIdx(0),[vipi]ofst(0),rW/H(1280/720)
154408 04-19 08:51:38.596888 29121 30296 D PostProcPipe: ,                     isDipOnly(0), hwmodule(9/0), dipCQ/dup/burst(0/0/0), drvSc(0), isWtf(1),tdr_tpipe(0),en_yuv/yuv2/rgb/dma/fmt_sel/ctl_sel/misc (0x11e07df8/0xf0/0x1400d9/0x20e071/0x480409/0x16040/0x10), tcm(0xa/0x1fd8e1c3/0xe807b3c), last(1), CRZ_EN(0), img3o ofset(0,0),userName(StreamingFeature),PIX_ID(0),ImgBuf_PIX_ID(0)
154411 04-19 08:51:38.598612 29121 30298 D MdpMgr  : [_startMdp] +sceID(0),cqPa(0x9006000)-Va(0x9f722000),tpipVa(0x9af64000)-Pa(0x9610000),isWaitB(1),venc(0),        HMyo CQ info (0_1_0), ref(0_0_0) dpobj(0_0_0), (va: 0x9af64000),        srcFt(0x2205),W(1280),H(720),stride(2400,0),size(0x1a5e00-0x0-0x0),VA(0x    ffff),PA(0x 8900000),plane(1),Stmtype(1)
154412 04-19 08:51:38.598612 29121 30298 D MdpMgr  :         wdma_en(1),idx(0),cap(3),ft(1),rt(0),fp(0),(w,h,s)=(1280,720,1280),C(w,h,s)=(640,360,640),V(w,h,s)=(640,360,640),mdpidx(0),
154413 04-19 08:51:38.598612 29121 30298 D MdpMgr  :         wrot_en(0),idx(1),cap(0),ft(1),rt(0),fp(0),(w,h,s)=(1280,720,1280),C(w,h,s)=(1280,360,1280),V(w,h,s)=(0,0,0),mdpidx(0),
154414 04-19 08:51:38.598612 29121 30298 D MdpMgr  :         jpg_en(0),idx(2),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(1),
154415 04-19 08:51:38.598612 29121 30298 D MdpMgr  :         pipe_en(0),idx(3),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(2),
154416 04-19 08:51:38.598612 29121 30298 D MdpMgr  :         HMyo CQ(0_1_0),ref(0_0_0),(va:0x9af54000_0x9af64000,dstpa:0x9610000)
154417 04-19 08:51:38.598612 29121 30298 D MdpMgr  : flag(0_0x1->0x1),startStm(1195 us),WDPQ(0x       a),WRPQ(0x       0)
*/    

    QParams enqueParams;
    FrameParams frameParams;

    //frame tag
    frameParams.mStreamTag = NSCam::NSIoPipe::NSPostProc::ENormalStreamTag_Normal;

    //input image
    MUINT32 _imgi_w_=1280, _imgi_h_=720;
    IMEM_BUF_INFO buf_imgi;
    buf_imgi.size=0x001a5e00;
    mpImemDrv->allocVirtBuf(&buf_imgi);
    memcpy( (MUINT8*)(buf_imgi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgi.size);
    //imem buffer 2 image heap
    printf("--- [test_P2A(%d)...flag -1 ]\n", type);
    IImageBuffer* srcBuffer;
    MINT32 bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 bufStridesInBytes[3] = {2400, 0, 0};
    PortBufInfo_v1 portBufInfo = PortBufInfo_v1( buf_imgi.memID,buf_imgi.virtAddr,0,buf_imgi.bufSecu, buf_imgi.bufCohe);
    IImageBufferAllocator::ImgParam imgParam = IImageBufferAllocator::ImgParam((eImgFmt_FG_BAYER10),MSize(_imgi_w_, _imgi_h_), bufStridesInBytes, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap;
    pHeap = ImageBufferHeap::create( "test_P2A", imgParam,portBufInfo,true);
    srcBuffer = pHeap->createImageBuffer();
    srcBuffer->incStrong(srcBuffer);
    srcBuffer->lockBuf("test_P2A",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- [test_P2A(%d)...flag -8]\n", type);
    Input src;
    src.mPortID=PORT_IMGI;
    src.mBuffer=srcBuffer;
    src.mPortID.group=0;
    frameParams.mvIn.push_back(src);

    MUINT32 _vipi_w_=1280, _vipi_h_=720;
    IMEM_BUF_INFO buf_vipi;
    buf_vipi.size=0x000f0000+0x0003c000*2;
    mpImemDrv->allocVirtBuf(&buf_vipi);
    memcpy( (MUINT8*)(buf_vipi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_vipi.size);
    IImageBuffer* vipi_srcBuffer;
    MINT32 vipi_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 vipi_bufStridesInBytes[3] = {1280, 640, 640};
    PortBufInfo_v1 vipi_portBufInfo = PortBufInfo_v1( buf_vipi.memID,buf_vipi.virtAddr,0,buf_vipi.bufSecu, buf_vipi.bufCohe);
    IImageBufferAllocator::ImgParam vipi_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_YV12),MSize(_vipi_w_, _vipi_h_), vipi_bufStridesInBytes, vipi_bufBoundaryInBytes, 3);
    sp<ImageBufferHeap> vipi_pHeap;
    vipi_pHeap = ImageBufferHeap::create( "test_P2A", vipi_imgParam,vipi_portBufInfo,true);
    vipi_srcBuffer = vipi_pHeap->createImageBuffer();
    vipi_srcBuffer->incStrong(vipi_srcBuffer);
    vipi_srcBuffer->lockBuf("test_P2A",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    vipi_srcBuffer->setExtParam(MSize(_vipi_w_,_vipi_h_),0x0);
    Input vipi_src;
    vipi_src.mPortID=PORT_VIPI;
    vipi_src.mBuffer=vipi_srcBuffer;
    vipi_src.mPortID.group=0;
    frameParams.mvIn.push_back(vipi_src);

    printf("--- [test_P2A(%d)...push src done]\n", type);

    dip_x_reg_t tuningDat;
    memcpy( (MUINT8*)(&tuningDat.DIP_X_CTL_START), (MUINT8*)(p2a_tuning_buffer), sizeof(dip_x_reg_t));

    frameParams.mTuningData = (MVOID*)&tuningDat;

    //crop information
    MCrpRsInfo crop;
    crop.mFrameGroup=0;
    crop.mGroupID=1;
    MCrpRsInfo crop2;
    crop2.mFrameGroup=0;
    crop2.mGroupID=2;
    MCrpRsInfo crop3;
    crop3.mFrameGroup=0;
    crop3.mGroupID=3;
    crop.mCropRect.p_fractional.x=0;
    crop.mCropRect.p_fractional.y=0;
    crop.mCropRect.p_integral.x=0;
    crop.mCropRect.p_integral.y=0;
    crop.mCropRect.s.w=0;
    crop.mCropRect.s.h=0;
    crop.mResizeDst.w=0;
    crop.mResizeDst.h=0;
    crop2.mCropRect.p_fractional.x=0;
    crop2.mCropRect.p_fractional.y=0;
    crop2.mCropRect.p_integral.x=0;
    crop2.mCropRect.p_integral.y=0;
    crop2.mCropRect.s.w=1280;
    crop2.mCropRect.s.h=718;
    crop2.mResizeDst.w=1280;
    crop2.mResizeDst.h=720;
    crop3.mCropRect.p_fractional.x=0;
    crop3.mCropRect.p_fractional.y=0;
    crop3.mCropRect.p_integral.x=0;
    crop3.mCropRect.p_integral.y=0;
    crop3.mCropRect.s.w=0;
    crop3.mCropRect.s.h=0;
    crop3.mResizeDst.w=0;
    crop3.mResizeDst.h=0;
    frameParams.mvCropRsInfo.push_back(crop);
    frameParams.mvCropRsInfo.push_back(crop2);
    frameParams.mvCropRsInfo.push_back(crop3);
    printf("--- [test_P2A(%d)...push crop information done\n]", type);

    //output dma
    MUINT32 _wdmao_w_=1280, _wdmao_h_=720;
    IMEM_BUF_INFO buf_out1;
    buf_out1.size=0x000e1000+0x00038400*2;
    mpImemDrv->allocVirtBuf(&buf_out1);
    memset((MUINT8*)buf_out1.virtAddr, 0xffffffff, buf_out1.size);
    IImageBuffer* outBuffer=NULL;
    MUINT32 bufStridesInBytes_1[3] = {1280,640,640};
    PortBufInfo_v1 portBufInfo_1 = PortBufInfo_v1( buf_out1.memID,buf_out1.virtAddr,0,buf_out1.bufSecu, buf_out1.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_1 = IImageBufferAllocator::ImgParam((eImgFmt_YV12),
                                         MSize(_wdmao_w_,_wdmao_h_),  bufStridesInBytes_1, bufBoundaryInBytes, 3);
    sp<ImageBufferHeap> pHeap_1 = ImageBufferHeap::create( "test_P2A", imgParam_1,portBufInfo_1,true);
    outBuffer = pHeap_1->createImageBuffer();
    outBuffer->incStrong(outBuffer);
    outBuffer->lockBuf("test_P2A",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst;
    dst.mPortID=PORT_WDMAO;
    dst.mBuffer=outBuffer;
    dst.mPortID.group=0;
    frameParams.mvOut.push_back(dst);
	
	ExtraParam extraparam;
    PQParam pqparam;
    DpPqParam param;
    param.enable = 0xa;
    param.scenario = MEDIA_ISP_PREVIEW;
    extraparam.CmdIdx = EPIPE_MDP_PQPARAM_CMD;
    pqparam.WDMAPQParam = &param;
    pqparam.WROTPQParam = NULL;
    extraparam.moduleStruct = &pqparam;
    frameParams.mvExtraParam.push_back(extraparam);


    IMEM_BUF_INFO buf_out2;
    MUINT32 _img3o_w_=1280, _img3o_h_=720;
    buf_out2.size=0x000f0000+0x0003c000*2;
    mpImemDrv->allocVirtBuf(&buf_out2);
    memset((MUINT8*)buf_out2.virtAddr, 0xffffffff, buf_out2.size);
    IImageBuffer* outBuffer_2=NULL;
    MUINT32 bufStridesInBytes_2[3] = {1280,640,640};
    PortBufInfo_v1 portBufInfo_2 = PortBufInfo_v1( buf_out2.memID,buf_out2.virtAddr,0,buf_out2.bufSecu, buf_out2.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_2 = IImageBufferAllocator::ImgParam((eImgFmt_YV12),MSize(_img3o_w_,_img3o_h_),  bufStridesInBytes_2, bufBoundaryInBytes, 3);
    sp<ImageBufferHeap> pHeap_2 = ImageBufferHeap::create( "test_P2A", imgParam_2,portBufInfo_2,true);
    outBuffer_2 = pHeap_2->createImageBuffer();
    outBuffer_2->incStrong(outBuffer_2);
    outBuffer_2->lockBuf("test_P2A",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    outBuffer_2->setExtParam(MSize(_img3o_w_,_img3o_h_),0x0);
    Output dst_2;
    dst_2.mPortID=PORT_IMG3O;
    dst_2.mBuffer=outBuffer_2;
    dst_2.mPortID.group=0;
    frameParams.mvOut.push_back(dst_2);

    FrameParams frameParams2;

    //frame tag
    frameParams2.mStreamTag = NSCam::NSIoPipe::NSPostProc::ENormalStreamTag_Normal;
    frameParams2.mvIn.push_back(src);
    frameParams2.mvIn.push_back(vipi_src);
    frameParams2.mTuningData = (MVOID*)&tuningDat;

    frameParams2.mvCropRsInfo.push_back(crop);
    frameParams2.mvCropRsInfo.push_back(crop2);
    frameParams2.mvCropRsInfo.push_back(crop3);
    frameParams2.mvExtraParam.push_back(extraparam);
    frameParams2.mvOut.push_back(dst);
    frameParams2.mvOut.push_back(dst_2);


    enqueParams.mvFrameParams.push_back(frameParams);
    enqueParams.mvFrameParams.push_back(frameParams2);
    printf("--- [test_P2A(%d)...push dst done\n]", type);

    for(int i=0;i<loopNum;i++)
    {
        memset((MUINT8*)(frameParams.mvOut[0].mBuffer->getBufVA(0)), 0xffffffff, buf_out1.size);
        memset((MUINT8*)(frameParams.mvOut[1].mBuffer->getBufVA(0)), 0xffffffff, buf_out2.size);

        //buffer operation
        mpImemDrv->cacheFlushAll();
        printf("--- [test_P2A(%d_%d)...flush done\n]", type, i);

        //enque
        ret=pStream->enque(enqueParams);
        if(!ret)
        {
         printf("---ERRRRRRRRR [test_P2A(%d_%d)..enque fail\n]", type, i);
        }
        else
        {
         printf("---[test_P2A(%d_%d)..enque done\n]",type, i);
        }

        //temp use while to observe in CVD
        //printf("--- [basicP2A(%d)...enter while...........\n]", type);
        //while(1);


        //deque
        //wait a momet in fpga
        //usleep(5000000);
        QParams dequeParams;
        ret=pStream->deque(dequeParams);
        if(!ret)
        {
         printf("---ERRRRRRRRR [test_P2A(%d_%d)..deque fail\n]",type, i);
        }
        else
        {
         printf("---[test_P2A(%d_%d)..deque done\n]", type, i);
        }

        //dump image
        //char filename[256];
        //sprintf(filename, "/data/P2iopipe_basicP2A_process0x%x_type%d_package%d_img3o_%dx%d.yuv",(MUINT32) getpid (),type,i, _imgi_w_,_imgi_h_);
        //saveBufToFile(filename, reinterpret_cast<MUINT8*>(dequeParams.mvOut[0].mBuffer->getBufVA(0)), _wrot_w_ *_wrot_h_ * 2);

        //char filename2[256];
        //sprintf(filename2, "/data/P2iopipe_basicP2A_process0x%x_type%d_package%d_wroto_%dx%d.yuv",(MUINT32) getpid (), type,i, _wrot_h_,_wrot_h_);
        //saveBufToFile(filename2, reinterpret_cast<MUINT8*>(dequeParams.mvOut[1].mBuffer->getBufVA(0)), _wrot_h_ *_wrot_h_ * 2);

        printf("--- [test_P2A(%d_%d)...save file done\n]", type,i);
    }

    //free
    srcBuffer->unlockBuf("test_P2A");
    mpImemDrv->freeVirtBuf(&buf_imgi);
    vipi_srcBuffer->unlockBuf("test_P2A");
    mpImemDrv->freeVirtBuf(&buf_vipi);

    outBuffer->unlockBuf("test_P2A");
    mpImemDrv->freeVirtBuf(&buf_out1);
    outBuffer_2->unlockBuf("test_P2A");
    mpImemDrv->freeVirtBuf(&buf_out2);
    printf("--- [test_P2A(%d)...free memory done\n]", type);

    //
    pStream->uninit("test_P2A");
    pStream->destroyInstance();
    printf("--- [test_P2A(%d)...pStream uninit done\n]", type);

    mpImemDrv->uninit();
    mpImemDrv->destroyInstance();

    return ret;


}


/*********************************************************************************/
int test_MFB_Blending(int type,int loopNum)
{
    int ret=0;
#if 0
    printf("--- [testMFB_Blending(%d)...enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr]\n", type);
    NSCam::NSIoPipe::NSPostProc::INormalStream* pStream;
    pStream= NSCam::NSIoPipe::NSPostProc::INormalStream::createInstance(0xFFFF);
    pStream->init("testMFB_Blending");
    printf("--- [testMFB_Blending(%d)...pStream init done]\n", type);
    IMemDrv* mpImemDrv=NULL;
    mpImemDrv=IMemDrv::createInstance();
    mpImemDrv->init();

    QParams enqueParams;
    FrameParams frameParams;

/*

01-01 00:07:00.100914   504  3044 I PostProcPipe: [PrintPipePortInfo] vInPorts:[0]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(18),dir(0),Size(0x028ef400,0x00000000,0x00000000),VA(0xa6997000,0x00000000,0x00000000),PA(0x44400000,0x00000000,0x00000000),
01-01 00:07:00.100914   504  3044 I PostProcPipe:                       vInPorts:[1]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(19),dir(0),Size(0x028ef400,0x00000000,0x00000000),VA(0xb873e000,0x00000000,0x00000000),PA(0x31a00000,0x00000000,0x00000000),
01-01 00:07:00.100914   504  3044 I PostProcPipe:                       vInPorts:[2]:(0x2200),w(5344),h(4016),stride(5344,0,0),type(0),idx(20),dir(0),Size(0x01477a00,0x00000000,0x00000000),VA(0xb0c6f000,0x00000000,0x00000000),PA(0x37900000,0x00000000,0x00000000),
01-01 00:07:00.100914   504  3044 I PostProcPipe:                       vInPorts:[3]:(0x2200),w(167),h(126),stride(167,0,0),type(0),idx(25),dir(0),Size(0x00005232,0x00000000,0x00000000),VA(0xe511e000,0x00000000,0x00000000),PA(0x34300000,0x00000000,0x00000000)
01-01 00:07:00.101076   504  3044 I PostProcPipe: [PrintPipePortInfo] vOutPorts:[0]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(31),dir(1),Size(0x028ef400,0x00000000,0x00000000),VA(0xa40a7000,0x00000000,0x00000000),PA(0x46d00000,0x00000000,0x00000000),
01-01 00:07:00.101076   504  3044 I PostProcPipe:                       vOutPorts:[1]:(0x2200),w(5344),h(4016),stride(5344,0,0),type(0),idx(34),dir(1),Size(0x01477a00,0x00000000,0x00000000),VA(0xa2c2f000,0x00000000,0x00000000),PA(0x3f300000,0x00000000,0x00000000)
01-01 00:07:00.101143   504  3044 I PostProcPipe: [configPipe] SRZ4:in(167,125), crop(0_0x0/0_0x0, 167, 126),out(5344,4016)
01-01 00:07:00.101237   504  3044 I PostProcPipe: [configPipe] [Imgi][crop_1](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(5344,4016,5344,4016)-[crop_2](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(0,0,0,0)-[crop_3](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(0,0,0,0),dupCqIdx(1),[vipi]ofst(0),rW/H(0/0)
01-01 00:07:00.101237   504  3044 I PostProcPipe: ,             isDipOnly(0), hwmodule(8/0), dipCQ/dup/burst(2/1/0), drvSc(2), isWtf(1),tdr_tpipe(0),en_yuv/yuv2/rgb/dma/fmt_sel/ctl_sel/misc (0x20015/0x8/0x80/0x2487/0x6/0x10/0x20), tcm(0xa/0x2202e/0x400581), last(1), CRZ_EN(1)


*/

    //frame tag
    frameParams.mStreamTag = NSCam::NSIoPipe::NSPostProc::ENormalStreamTag_MFB_Bld;

    //input image
    MUINT32 _imgi_w_=5344, _imgi_h_=4016;
    IMEM_BUF_INFO buf_imgi;
    buf_imgi.size=_imgi_w_*_imgi_h_*2;
    mpImemDrv->allocVirtBuf(&buf_imgi);
    memcpy( (MUINT8*)(buf_imgi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgi.size);

    //imem buffer 2 image heap
    printf("--- [testMFB_Blending(%d)...flag -1 ]\n", type);
    IImageBuffer* srcBuffer;
    MINT32 bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 bufStridesInBytes[3] = {_imgi_w_*2, 0, 0};
    PortBufInfo_v1 portBufInfo = PortBufInfo_v1( buf_imgi.memID,buf_imgi.virtAddr,0,buf_imgi.bufSecu, buf_imgi.bufCohe);
    IImageBufferAllocator::ImgParam imgParam = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_imgi_w_, _imgi_h_), bufStridesInBytes, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap;
    pHeap = ImageBufferHeap::create( "testMFB_Blending", imgParam,portBufInfo,true);
    srcBuffer = pHeap->createImageBuffer();
    srcBuffer->incStrong(srcBuffer);
    srcBuffer->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- PORT_IMGI : [testMFB_Blending(%d)...flag -8]\n", type);

    Input src;
    src.mPortID=PORT_IMGI;
    src.mBuffer=srcBuffer;
    src.mPortID.group=0;
    frameParams.mvIn.push_back(src);
    printf("--- [testMFB_Blending(%d)...push src done]\n", type);

    MUINT32 _imgbi_w_=5344, _imgbi_h_=4016;
    IMEM_BUF_INFO buf_imgbi;
    buf_imgbi.size=_imgbi_w_*_imgbi_h_*2;
    mpImemDrv->allocVirtBuf(&buf_imgbi);
    memcpy( (MUINT8*)(buf_imgbi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgbi.size);
    //imem buffer 2 image heap
    printf("--- [testMFB_Blending(%d)...flag -1 ]\n", type);
    IImageBuffer* imgbi_srcBuffer;
    MINT32 imgbi_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 imgbi_bufStridesInBytes[3] = {_imgbi_w_*2, 0, 0};
    PortBufInfo_v1 imgbi_portBufInfo = PortBufInfo_v1( buf_imgbi.memID,buf_imgbi.virtAddr,0,buf_imgbi.bufSecu, buf_imgbi.bufCohe);
    IImageBufferAllocator::ImgParam imgbi_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_imgbi_w_, _imgbi_h_), imgbi_bufStridesInBytes, imgbi_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> imgbi_pHeap;
    imgbi_pHeap = ImageBufferHeap::create( "testMFB_Blending", imgbi_imgParam,imgbi_portBufInfo,true);
    imgbi_srcBuffer = imgbi_pHeap->createImageBuffer();
    imgbi_srcBuffer->incStrong(imgbi_srcBuffer);
    imgbi_srcBuffer->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- PORT_IMGBI : [testMFB_Blending(%d)...flag -8]\n", type);

    Input src_2;
    src_2.mPortID=PORT_IMGBI;
    src_2.mBuffer=imgbi_srcBuffer;
    src_2.mPortID.group=0;
    frameParams.mvIn.push_back(src_2);
    printf("--- [testMFB_Blending(%d)...push src_2 done]\n", type);


    IMEM_BUF_INFO buf_imgci;
    buf_imgci.size=_imgi_w_*_imgi_h_*1;
    mpImemDrv->allocVirtBuf(&buf_imgci);
    memcpy( (MUINT8*)(buf_imgci.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgci.size);
    IImageBuffer* imgci_srcBuffer;
    MINT32 imgci_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 imgci_bufStridesInBytes[3] = {_imgi_w_*1, 0, 0};
    PortBufInfo_v1 imgci_portBufInfo = PortBufInfo_v1( buf_imgci.memID,buf_imgci.virtAddr,0,buf_imgci.bufSecu, buf_imgci.bufCohe);
    IImageBufferAllocator::ImgParam imgci_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_BAYER8),MSize(_imgi_w_, _imgi_h_), imgci_bufStridesInBytes, imgci_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pimgciHeap;
    pimgciHeap = ImageBufferHeap::create( "testMFB_Blending", imgci_imgParam,imgci_portBufInfo,true);
    imgci_srcBuffer = pimgciHeap->createImageBuffer();
    imgci_srcBuffer->incStrong(imgci_srcBuffer);
    imgci_srcBuffer->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- PORT_IMGCI : [testMFB_Blending(%d)...flag -8]\n", type);

    Input src_3;
    src_3.mPortID=PORT_IMGCI;
    src_3.mBuffer=imgci_srcBuffer;
    src_3.mPortID.group=0;
    frameParams.mvIn.push_back(src_3);
    printf("--- [testMFB_Blending(%d)...push src_3 done]\n", type);


    IMEM_BUF_INFO buf_lcei;
    MUINT32 _lcei_w_=167, _lcei_h_=126;
    buf_lcei.size=_lcei_w_*_lcei_h_*1;
    mpImemDrv->allocVirtBuf(&buf_lcei);
    memcpy( (MUINT8*)(buf_lcei.virtAddr), (MUINT8*)(srz5_lcei), buf_lcei.size);
    IImageBuffer* lcei_srcBuffer;
    MINT32 lcei_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 lcei_bufStridesInBytes[3] = {_lcei_w_*1, 0, 0};
    PortBufInfo_v1 lcei_portBufInfo = PortBufInfo_v1( buf_lcei.memID,buf_lcei.virtAddr,0,buf_lcei.bufSecu, buf_lcei.bufCohe);
    IImageBufferAllocator::ImgParam lcei_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_BAYER8),MSize(_lcei_w_, _lcei_h_), lcei_bufStridesInBytes, lcei_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> plceiHeap;
    plceiHeap = ImageBufferHeap::create( "testMFB_Blending", lcei_imgParam,lcei_portBufInfo,true);
    lcei_srcBuffer = plceiHeap->createImageBuffer();
    lcei_srcBuffer->incStrong(lcei_srcBuffer);
    lcei_srcBuffer->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- PORT_LCEI : [testMFB_Blending(%d)...flag -8]\n", type);

    Input src_4;
    src_4.mPortID=PORT_LCEI;
    src_4.mBuffer=lcei_srcBuffer;
    src_4.mPortID.group=0;
    if (type == 0){
        frameParams.mvIn.push_back(src_4);
    }
    printf("--- [testMFB_Blending(%d)...push src_4 done]\n", type);


    /* SRZ5 setting */
    ModuleInfo srzModule;
    srzModule.moduleTag = EDipModule_SRZ5;
    srzModule.frameGroup = 0;
    _SRZ_SIZE_INFO_ Srz5SizeInfo;

    Srz5SizeInfo.out_w         = _imgi_w_;
    Srz5SizeInfo.out_h         = _imgi_h_;
    
    Srz5SizeInfo.crop_w        = 167;
    Srz5SizeInfo.crop_h        = 126;
    Srz5SizeInfo.in_w          = 167;
    Srz5SizeInfo.in_h          = 125;
    
    srzModule.moduleStruct = reinterpret_cast<MVOID*>(&Srz5SizeInfo);
    if (type == 0){
        frameParams.mvModuleData.push_back(srzModule);
    }


    dip_x_reg_t tuningDat;
    memcpy( (MUINT8*)(&tuningDat.DIP_X_CTL_START), (MUINT8*)(mfb_tuning_buffer), sizeof(dip_x_reg_t));

    if (type == 0){
        tuningDat.DIP_X_MFB_LL_CON10.Raw = 0x00000001;
    }

    frameParams.mTuningData = (MVOID*)&tuningDat;

   //crop information
    MCrpRsInfo crop;
    crop.mGroupID=1;
    MCrpRsInfo crop2;
    crop2.mGroupID=2;
    MCrpRsInfo crop3;
    crop3.mGroupID=3;
    crop.mCropRect.p_fractional.x=0;
    crop.mCropRect.p_fractional.y=0;
    crop.mCropRect.p_integral.x=0;
    crop.mCropRect.p_integral.y=0;
    crop.mCropRect.s.w=_imgi_w_;
    crop.mCropRect.s.h=_imgi_h_;
    crop.mResizeDst.w=_imgi_w_;
    crop.mResizeDst.h=_imgi_h_;
    crop2.mCropRect.p_fractional.x=0;
    crop2.mCropRect.p_fractional.y=0;
    crop2.mCropRect.p_integral.x=0;
    crop2.mCropRect.p_integral.y=0;
    crop2.mCropRect.s.w=_imgi_w_;
    crop2.mCropRect.s.h=_imgi_h_;
    crop2.mResizeDst.w=_imgi_w_;
    crop2.mResizeDst.h=_imgi_h_;
    crop3.mCropRect.p_fractional.x=0;
    crop3.mCropRect.p_fractional.y=0;
    crop3.mCropRect.p_integral.x=0;
    crop3.mCropRect.p_integral.y=0;
    crop3.mCropRect.s.w=_imgi_w_;
    crop3.mCropRect.s.h=_imgi_h_;
    crop3.mResizeDst.w=_imgi_w_;
    crop3.mResizeDst.h=_imgi_h_;
    frameParams.mvCropRsInfo.push_back(crop);
    frameParams.mvCropRsInfo.push_back(crop2);
    frameParams.mvCropRsInfo.push_back(crop3);
    printf("--- [testMFB_Blending(%d)...push crop information done\n]", type);

    //output dma

    IMEM_BUF_INFO buf_out1;
    MUINT32 _mfbo_w_= _imgi_w_;
    MUINT32 _mfbo_h_= _imgi_h_;
    buf_out1.size=_mfbo_w_*_mfbo_h_;
    mpImemDrv->allocVirtBuf(&buf_out1);
    memset((MUINT8*)buf_out1.virtAddr, 0xffffffff, buf_out1.size);
    IImageBuffer* outBuffer=NULL;
    MUINT32 bufStridesInBytes_1[3] = {_mfbo_w_,0,0};
    PortBufInfo_v1 portBufInfo_1 = PortBufInfo_v1( buf_out1.memID,buf_out1.virtAddr,0,buf_out1.bufSecu, buf_out1.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_1 = IImageBufferAllocator::ImgParam((eImgFmt_BAYER8),
                                            MSize(_mfbo_w_,_mfbo_h_),  bufStridesInBytes_1, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap_1 = ImageBufferHeap::create( "testMFB_Blending", imgParam_1,portBufInfo_1,true);
    outBuffer = pHeap_1->createImageBuffer();
    outBuffer->incStrong(outBuffer);
    outBuffer->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- [testMFB_Blending(%d)...mfbo done\n]", type);

    Output dst;
    dst.mPortID=PORT_MFBO;
    dst.mBuffer=outBuffer;
    dst.mPortID.group=0;
    frameParams.mvOut.push_back(dst);

    IMEM_BUF_INFO buf_out2;
    buf_out2.size=_imgi_w_*_imgi_h_*2;
    mpImemDrv->allocVirtBuf(&buf_out2);
    memset((MUINT8*)buf_out2.virtAddr, 0xffffffff, buf_out2.size);
    IImageBuffer* outBuffer_2=NULL;
    MUINT32 bufStridesInBytes_2[3] = {_imgi_w_*2,0,0};
    PortBufInfo_v1 portBufInfo_2 = PortBufInfo_v1( buf_out2.memID,buf_out2.virtAddr,0,buf_out2.bufSecu, buf_out2.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_2 = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_imgi_w_,_imgi_h_),  bufStridesInBytes_2, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap_2 = ImageBufferHeap::create( "testMFB_Blending", imgParam_2,portBufInfo_2,true);
    outBuffer_2 = pHeap_2->createImageBuffer();
    outBuffer_2->incStrong(outBuffer_2);
    outBuffer_2->lockBuf("testMFB_Blending",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst_2;
    dst_2.mPortID=PORT_IMG3O;
    dst_2.mBuffer=outBuffer_2;
    dst_2.mPortID.group=0;
    frameParams.mvOut.push_back(dst_2);	
    enqueParams.mvFrameParams.push_back(frameParams);
    printf("--- [testMFB_Blending(%d)...push dst done\n]", type);


    for(int i=0;i<loopNum;i++)
    {
        printf("-------------------------------!!!\n]");
        printf("--- start to test loop(%d_) ---!!!\n]", i+1);
        printf("-------------------------------!!!\n]");

        memset((MUINT8*)(frameParams.mvOut[0].mBuffer->getBufVA(0)), 0xffffffff, buf_out1.size);
        memset((MUINT8*)(frameParams.mvOut[1].mBuffer->getBufVA(0)), 0xffffffff, buf_out2.size);
        
        //buffer operation
        mpImemDrv->cacheFlushAll();
        printf("--- [testMFB_Blending(%d_)...flush done\n]", type);

        //enque
        ret=pStream->enque(enqueParams);
        if(!ret)
        {
            printf("---ERRRRRRRRR [testMFB_Blending(%d_)..enque fail\n]", type);
        }
        else
        {
            printf("---[testMFB_Blending(%d_)..enque done\n]",type);
        }

        QParams dequeParams;
        ret=pStream->deque(dequeParams);
        if(!ret)
        {
            printf("---ERRRRRRRRR [testMFB_Blending(%d_)..deque fail\n]",type);
        }
        else
        {
            printf("---[testMFB_Blending(%d_)..deque done\n]", type);
        }

    }

    //dump image
    char filename[256];
    sprintf(filename, "/data/P2iopipe_testMFB_Blending_process_type%d_package_img3o_%dx%d.yuv", type, _imgi_w_,_imgi_h_);
    saveBufToFile(filename, reinterpret_cast<MUINT8*>(buf_out2.virtAddr), _imgi_w_ *_imgi_h_ * 2);
    
    sprintf(filename, "/data/P2iopipe_testMFB_Blending_process_type%d_package_imgi_%dx%d.yuv", type, _imgi_w_,_imgi_h_);
    saveBufToFile(filename, reinterpret_cast<MUINT8*>(buf_imgi.virtAddr), _imgi_w_ *_imgi_h_ * 2);
    
    sprintf(filename, "/data/P2iopipe_testMFB_Blending_process_type%d_package_imgbi_%dx%d.yuv", type, _imgbi_w_,_imgbi_h_);
    saveBufToFile(filename, reinterpret_cast<MUINT8*>(buf_imgbi.virtAddr), _imgbi_w_ *_imgbi_h_ * 2);
    
    printf("--- [testMFB_Blending...save file done\n]");


    //free
    srcBuffer->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_imgi);

    imgbi_srcBuffer->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_imgbi);

    imgci_srcBuffer->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_imgci);

    lcei_srcBuffer->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_lcei);


    outBuffer->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_out1);

    outBuffer_2->unlockBuf("testMFB_Blending");
    mpImemDrv->freeVirtBuf(&buf_out2);

    printf("--- [testMFB_Blending(%d)...free memory done\n]", type);

    //
    pStream->uninit("testMFB_Blending");
    pStream->destroyInstance();
    printf("--- [testMFB_Blending(%d)...pStream uninit done\n]", type);

    mpImemDrv->uninit();
    mpImemDrv->destroyInstance();

#endif
    return ret;
}

/*********************************************************************************/
int test_MFB_Mixing(int type,int loopNum)
{

    int ret=0;
    printf("--- [test_MFB_Mixing(%d)...enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr]\n", type);
    NSCam::NSIoPipe::NSPostProc::INormalStream* pStream;
    pStream= NSCam::NSIoPipe::NSPostProc::INormalStream::createInstance(0xFFFF);
    pStream->init("test_MFB_Mixing");
    printf("--- [test_MFB_Mixing(%d)...pStream init done]\n", type);
    IMemDrv* mpImemDrv=NULL;
    mpImemDrv=IMemDrv::createInstance();
    mpImemDrv->init();

/*
    ALPS03777969

    02-10 15:53:08.719548   590 11143 D PostProcPipe: [PrintPipePortInfo] vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[0]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(19),dir(0),Size(0x028ef400,0x00000000,0x00000000),VA(0x8da54000,0x0,0x0),PA(0x41900000,0x0,0x0),
    02-10 15:53:08.719548   590 11143 D PostProcPipe:                       vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[1]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(22),dir(0),Size(0x028ef400,0x00000000,0x00000000),VA(0x86762000,0x0,0x0),PA(0x49000000,0x0,0x0),
    02-10 15:53:08.719548   590 11143 D PostProcPipe:                       vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[2]:(0x2200),w(5344),h(4016),stride(5344,0,0),type(0),idx(27),dir(0),Size(0x01477a00,0x00000000,0x00000000),VA(0x8ae6c000,0x0,0x0),PA(0x45700000,0x0,0x0)
    02-10 15:53:08.719641   590 11143 D PostProcPipe: [PrintPipePortInfo] vOutPorts:FN(0),RN(0),TS(0x0),UK(0x0),[0]:(0x14),w(5344),h(4016),stride(10688,0,0),type(0),idx(38),dir(1),Size(0x028ef400,0x00000000,0x00000000),VA(0x90344000,0x0,0x0),PA(0x3f000000,0x0,0x0),
    02-10 15:53:08.719641   590 11143 D PostProcPipe:                       vOutPorts:FN(0),RN(0),TS(0x0),UK(0x0),[1]:(0x14),w(160),h(128),stride(320,0,0),type(0),idx(37),dir(1),Size(0x0000a000,0x00000000,0x00000000),VA(0xf03b9000,0x0,0x0),PA(0x27800000,0x0,0x0)
    02-10 15:53:08.719765   590 11143 D PostProcPipe: [configPipe] [Imgi][crop_1](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(5344,4016,5344,4016)-[crop_2](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(5344,4016,5344,4016)-[crop_3](x,f_x,y,f_y)=(2051,0,1510,0),(w,h,tarW,tarH)=(1236,990,160,128),dupCqIdx(1),[vipi]ofst(0),rW/H(0/0)
    02-10 15:53:08.719765   590 11143 D PostProcPipe: ,                     isDipOnly(0), hwmodule(9/0), dipCQ/dup/burst(3/1/0), drvSc(3), isWtf(1),tdr_tpipe(0),en_yuv/yuv2/rgb/dma/fmt_sel/ctl_sel/misc (0xd21974/0x30/0x4ac88/0x300211/0x30000000/0x50/0x10), tcm(0xa/0x1e00242/0xc82f389), last(1), CRZ_EN(1), img3o ofset(0,0),userName(MfllCore/Mfb),PIX_ID(3)
02-10 15:53:08.724740   590 11144 D MdpMgr  : [_startMdp] +sceID(3),cqPa(0xbd6e000)-Va(0xdfbdd000),tpipVa(0xdda6b000)-Pa(0xc5d0000),isWaitB(1),venc(0),        HMyo CQ info (3_1_0), ref(3_1_0) dpobj(3_1_0), (va: 0xdda6b000),        srcFt(0x14),W(5344),H(4016),stride(10688,0),size(0x28ef400-0x0-0x0),VA(0x    ffff),PA(0x41900000),plane(1),Stmtype(1)
02-10 15:53:08.724740   590 11144 D MdpMgr  :         wdma_en(1),idx(0),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(5344,4016,10688),C(w,h,s)=(1920,540,1920),V(w,h,s)=(480,270,480),mdpidx(0),
02-10 15:53:08.724740   590 11144 D MdpMgr  :         wrot_en(1),idx(1),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(160,128,320),C(w,h,s)=(480,270,480),V(w,h,s)=(480,270,480),mdpidx(0),
02-10 15:53:08.724740   590 11144 D MdpMgr  :         jpg_en(0),idx(2),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(1),
02-10 15:53:08.724740   590 11144 D MdpMgr  :         pipe_en(0),idx(3),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(2),
02-10 15:53:08.724740   590 11144 D MdpMgr  :         HMyo CQ(3_1_0),ref(3_1_0),(va:0x0_0xdda6b000,dstpa:0xc5d0000)
02-10 15:53:08.724740   590 11144 D MdpMgr  : flag(0_0x0->0x0),startStm(2434 us),WDPQ(0x       0),WRPQ(0x       0)

*/    

    QParams enqueParams;
    FrameParams frameParams;

    //frame tag
    frameParams.mStreamTag = NSCam::NSIoPipe::NSPostProc::ENormalStreamTag_MFB_Mix;

    //input image
    MUINT32 _imgi_w_=5344, _imgi_h_=4016;
    IMEM_BUF_INFO buf_imgi;
    buf_imgi.size=(_imgi_w_* 2 *_imgi_h_);
    mpImemDrv->allocVirtBuf(&buf_imgi);
    memcpy( (MUINT8*)(buf_imgi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgi.size);
    //imem buffer 2 image heap
    printf("--- [test_MFB_Mixing(%d)...flag -1 ]\n", type);
    IImageBuffer* srcBuffer;
    MINT32 bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 bufStridesInBytes[3] = {_imgi_w_*2, 0, 0};
    PortBufInfo_v1 portBufInfo = PortBufInfo_v1( buf_imgi.memID,buf_imgi.virtAddr,0,buf_imgi.bufSecu, buf_imgi.bufCohe);
    IImageBufferAllocator::ImgParam imgParam = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_imgi_w_, _imgi_h_), bufStridesInBytes, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap;
    pHeap = ImageBufferHeap::create( "test_MFB_Mixing", imgParam,portBufInfo,true);
    srcBuffer = pHeap->createImageBuffer();
    srcBuffer->incStrong(srcBuffer);
    srcBuffer->lockBuf("test_MFB_Mixing",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- [test_MFB_Mixing(%d)...flag -8]\n", type);
    Input src;
    src.mPortID=PORT_IMGI;
    src.mBuffer=srcBuffer;
    src.mPortID.group=0;
    frameParams.mvIn.push_back(src);


    MUINT32 _dmgi_w_=5344, _dmgi_h_=4016;
    IMEM_BUF_INFO buf_dmgi;
    buf_dmgi.size=(_dmgi_w_*2*_dmgi_h_);
    mpImemDrv->allocVirtBuf(&buf_dmgi);
    memcpy( (MUINT8*)(buf_dmgi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_dmgi.size);
    IImageBuffer* dmgi_srcBuffer;
    MINT32 dmgi_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 dmgi_bufStridesInBytes[3] = {(_dmgi_w_), 0, 0};
    PortBufInfo_v1 dmgi_portBufInfo = PortBufInfo_v1( buf_dmgi.memID,buf_dmgi.virtAddr,0,buf_dmgi.bufSecu, buf_dmgi.bufCohe);
    IImageBufferAllocator::ImgParam dmgi_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_BAYER8),MSize(_dmgi_w_, _dmgi_h_), dmgi_bufStridesInBytes, dmgi_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> dmgi_pHeap;
    dmgi_pHeap = ImageBufferHeap::create( "test_MFB_Mixing", dmgi_imgParam,dmgi_portBufInfo,true);
    dmgi_srcBuffer = dmgi_pHeap->createImageBuffer();
    dmgi_srcBuffer->incStrong(dmgi_srcBuffer);
    dmgi_srcBuffer->lockBuf("test_MFB_Mixing",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Input dmgi_src;
    dmgi_src.mPortID=PORT_DMGI;
    dmgi_src.mBuffer=dmgi_srcBuffer;
    dmgi_src.mPortID.group=0;
    frameParams.mvIn.push_back(dmgi_src);


    MUINT32 _vipi_w_=5344, _vipi_h_=4016;
    IMEM_BUF_INFO buf_vipi;
    buf_vipi.size=_vipi_w_*2*_vipi_h_;
    mpImemDrv->allocVirtBuf(&buf_vipi);
    memcpy( (MUINT8*)(buf_vipi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_vipi.size);

    IImageBuffer* vipi_srcBuffer;
    MINT32 vipi_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 vipi_bufStridesInBytes[3] = {_vipi_w_*2, 0, 0};
    PortBufInfo_v1 vipi_portBufInfo = PortBufInfo_v1( buf_vipi.memID,buf_vipi.virtAddr,0,buf_vipi.bufSecu, buf_vipi.bufCohe);
    IImageBufferAllocator::ImgParam vipi_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_vipi_w_, _vipi_h_), vipi_bufStridesInBytes, vipi_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> vipi_pHeap;
    vipi_pHeap = ImageBufferHeap::create( "test_MFB_Mixing", vipi_imgParam,vipi_portBufInfo,true);
    vipi_srcBuffer = vipi_pHeap->createImageBuffer();
    vipi_srcBuffer->incStrong(vipi_srcBuffer);
    vipi_srcBuffer->lockBuf("test_MFB_Mixing",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    //vipi_srcBuffer->setExtParam(MSize(_vipi_w_,_vipi_h_),0x0);
    Input vipi_src;
    vipi_src.mPortID=PORT_VIPI;
    vipi_src.mBuffer=vipi_srcBuffer;
    vipi_src.mPortID.group=0;
    frameParams.mvIn.push_back(vipi_src);

    printf("--- [test_MFB_Mixing(%d)...push src done]\n", type);

    dip_x_reg_t tuningDat;
    memcpy( (MUINT8*)(&tuningDat.DIP_X_CTL_START), (MUINT8*)(mixing_tuning_buffer), sizeof(dip_x_reg_t));

    frameParams.mTuningData = (MVOID*)&tuningDat;

    //crop information
    MCrpRsInfo crop;
    crop.mFrameGroup=0;
    crop.mGroupID=1;
    MCrpRsInfo crop2;
    crop2.mFrameGroup=0;
    crop2.mGroupID=2;
    MCrpRsInfo crop3;
    crop3.mFrameGroup=0;
    crop3.mGroupID=3;
    crop.mCropRect.p_fractional.x=0;
    crop.mCropRect.p_fractional.y=0;
    crop.mCropRect.p_integral.x=0;
    crop.mCropRect.p_integral.y=0;
    crop.mCropRect.s.w=5344;
    crop.mCropRect.s.h=4016;
    crop.mResizeDst.w=5344;
    crop.mResizeDst.h=4016;
    crop2.mCropRect.p_fractional.x=0;
    crop2.mCropRect.p_fractional.y=0;
    crop2.mCropRect.p_integral.x=0;
    crop2.mCropRect.p_integral.y=0;
    crop2.mCropRect.s.w=5344;
    crop2.mCropRect.s.h=4016;
    crop2.mResizeDst.w=5344;
    crop2.mResizeDst.h=4016;
    crop3.mCropRect.p_fractional.x=0;
    crop3.mCropRect.p_fractional.y=0;
    crop3.mCropRect.p_integral.x=2051;
    crop3.mCropRect.p_integral.y=1510;
    crop3.mCropRect.s.w=1236;
    crop3.mCropRect.s.h=990;
    crop3.mResizeDst.w=160;
    crop3.mResizeDst.h=128;
    frameParams.mvCropRsInfo.push_back(crop);
    frameParams.mvCropRsInfo.push_back(crop2);
    frameParams.mvCropRsInfo.push_back(crop3);
    printf("--- [test_MFB_Mixing(%d)...push crop information done\n]", type);

    //output dma
    MUINT32 _wrot_w_=160, _wrot_h_=128;
    IMEM_BUF_INFO buf_out1;
    buf_out1.size=0x0000a000;
    mpImemDrv->allocVirtBuf(&buf_out1);
    memset((MUINT8*)buf_out1.virtAddr, 0xffffffff, buf_out1.size);
    IImageBuffer* outBuffer=NULL;
    MUINT32 bufStridesInBytes_1[3] = {_wrot_w_*2,0,0};
    PortBufInfo_v1 portBufInfo_1 = PortBufInfo_v1( buf_out1.memID,buf_out1.virtAddr,0,buf_out1.bufSecu, buf_out1.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_1 = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),
                                         MSize(_wrot_w_,_wrot_h_),  bufStridesInBytes_1, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap_1 = ImageBufferHeap::create( "test_MFB_Mixing", imgParam_1,portBufInfo_1,true);
    outBuffer = pHeap_1->createImageBuffer();
    outBuffer->incStrong(outBuffer);
    outBuffer->lockBuf("test_MFB_Mixing",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst;
    dst.mPortID=PORT_WROTO;
    dst.mBuffer=outBuffer;
    dst.mPortID.group=0;
    dst.mPortID.capbility=EPortCapbility_None;
    frameParams.mvOut.push_back(dst);


    IMEM_BUF_INFO buf_out2;
    MUINT32 _wdmao_w_=5344, _wdmao_h_=4016;
    buf_out2.size=0x028ef400;
    mpImemDrv->allocVirtBuf(&buf_out2);
    memset((MUINT8*)buf_out2.virtAddr, 0xffffffff, buf_out2.size);
    IImageBuffer* outBuffer_2=NULL;
    MUINT32 bufStridesInBytes_2[3] = {_wdmao_w_*2,0,0};
    PortBufInfo_v1 portBufInfo_2 = PortBufInfo_v1( buf_out2.memID,buf_out2.virtAddr,0,buf_out2.bufSecu, buf_out2.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_2 = IImageBufferAllocator::ImgParam((eImgFmt_YUY2),MSize(_wdmao_w_,_wdmao_h_),  bufStridesInBytes_2, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap_2 = ImageBufferHeap::create( "test_MFB_Mixing", imgParam_2,portBufInfo_2,true);
    outBuffer_2 = pHeap_2->createImageBuffer();
    outBuffer_2->incStrong(outBuffer_2);
    outBuffer_2->lockBuf("test_MFB_Mixing",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst_2;
    dst_2.mPortID=PORT_WDMAO;
    dst_2.mBuffer=outBuffer_2;
    dst_2.mPortID.group=0;
    dst_2.mPortID.capbility=EPortCapbility_None;
    frameParams.mvOut.push_back(dst_2);
    enqueParams.mvFrameParams.push_back(frameParams);
    printf("--- [test_MFB_Mixing(%d)...push dst done\n]", type);

    for(int i=0;i<loopNum;i++)
    {
        memset((MUINT8*)(frameParams.mvOut[0].mBuffer->getBufVA(0)), 0xffffffff, buf_out1.size);
        memset((MUINT8*)(frameParams.mvOut[1].mBuffer->getBufVA(0)), 0xffffffff, buf_out2.size);

        //buffer operation
        mpImemDrv->cacheFlushAll();
        printf("--- [test_MFB_Mixing(%d_%d)...flush done\n]", type, i);

        //enque
        ret=pStream->enque(enqueParams);
        if(!ret)
        {
         printf("---ERRRRRRRRR [test_MFB_Mixing(%d_%d)..enque fail\n]", type, i);
        }
        else
        {
         printf("---[test_MFB_Mixing(%d_%d)..enque done\n]",type, i);
        }

        //temp use while to observe in CVD
        //printf("--- [basicP2A(%d)...enter while...........\n]", type);
        //while(1);


        //deque
        //wait a momet in fpga
        //usleep(5000000);
        QParams dequeParams;
        ret=pStream->deque(dequeParams);
        if(!ret)
        {
         printf("---ERRRRRRRRR [test_MFB_Mixing(%d_%d)..deque fail\n]",type, i);
        }
        else
        {
         printf("---[test_MFB_Mixing(%d_%d)..deque done\n]", type, i);
        }

        //dump image
        //char filename[256];
        //sprintf(filename, "/data/P2iopipe_basicP2A_process0x%x_type%d_package%d_img3o_%dx%d.yuv",(MUINT32) getpid (),type,i, _imgi_w_,_imgi_h_);
        //saveBufToFile(filename, reinterpret_cast<MUINT8*>(dequeParams.mvOut[0].mBuffer->getBufVA(0)), _wrot_w_ *_wrot_h_ * 2);

        //char filename2[256];
        //sprintf(filename2, "/data/P2iopipe_basicP2A_process0x%x_type%d_package%d_wroto_%dx%d.yuv",(MUINT32) getpid (), type,i, _wrot_h_,_wrot_h_);
        //saveBufToFile(filename2, reinterpret_cast<MUINT8*>(dequeParams.mvOut[1].mBuffer->getBufVA(0)), _wrot_h_ *_wrot_h_ * 2);

        printf("--- [test_MFB_Mixing(%d_%d)...save file done\n]", type,i);
    }

    //free
    srcBuffer->unlockBuf("test_MFB_Mixing");
    mpImemDrv->freeVirtBuf(&buf_imgi);
    dmgi_srcBuffer->unlockBuf("test_MFB_Mixing");
    mpImemDrv->freeVirtBuf(&buf_dmgi);
    vipi_srcBuffer->unlockBuf("test_MFB_Mixing");
    mpImemDrv->freeVirtBuf(&buf_vipi);

    outBuffer->unlockBuf("test_MFB_Mixing");
    mpImemDrv->freeVirtBuf(&buf_out1);
    outBuffer_2->unlockBuf("test_MFB_Mixing");
    mpImemDrv->freeVirtBuf(&buf_out2);
    printf("--- [test_MFB_Mixing(%d)...free memory done\n]", type);

    //
    pStream->uninit("test_MFB_Mixing");
    pStream->destroyInstance();
    printf("--- [test_MFB_Mixing(%d)...pStream uninit done\n]", type);

    mpImemDrv->uninit();
    mpImemDrv->destroyInstance();

    return ret;


}


/*********************************************************************************/
int test_VSS(int type,int loopNum)
{
    int ret=0;
    printf("--- [test_Vss(%d)...enterrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr]\n", type);
    NSCam::NSIoPipe::NSPostProc::INormalStream* pStream;
    pStream= NSCam::NSIoPipe::NSPostProc::INormalStream::createInstance(0xFFFF);
    pStream->init("test_Vss");
    printf("--- [test_Vss(%d)...pStream init done]\n", type);
    IMemDrv* mpImemDrv=NULL;
    mpImemDrv=IMemDrv::createInstance();
    mpImemDrv->init();
/*
105628 01-01 21:49:10.224451   598 21498 D PostProcPipe: [PrintPipePortInfo] vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[0]:(0x2400),w(1536),h(16),stride(1536,0,0),type(0),idx(28),dir(0),Size(0x00006000,0x00000000,0x00000000),VA(0xf6b3f000,0x0,0x0),PA(0x4f00000,0x0,0x0),
105629 01-01 21:49:10.224451   598 21498 D PostProcPipe:                       vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[1]:(0x2401),w(334),h(250),stride(768,0,0),type(0),idx(26),dir(0),Size(0x00048000,0x00000000,0x00000000),VA(0xeff1d000,0x0,0x0),PA(0x7f00000,0x0,0x0),
105630 01-01 21:49:10.224451   598 21498 D PostProcPipe:                       vInPorts:FN(0),RN(0),TS(0x0),UK(0x0),[2]:(0x2201),w(5344),h(4016),stride(6680,0,0),type(0),idx(19),dir(0),Size(0x01995880,0x00000000,0x00000000),VA(0xc6754000,0x0,0x0),PA(0x21700000,0x0,0x0)
105635 01-01 21:49:10.224859   598 21498 D PostProcPipe: [PrintPipePortInfo] vOutPorts:FN(0),RN(0),TS(0x0),UK(0x0),[0]:(0x2009),w(5344),h(4016),stride(5344,2672,2672),type(0),idx(32),dir(1),Size(0x01477a00,0x00a3bd00,0x00a3bd00),VA(0xbe129000,0xbf5a0a00,0xbffdc700),PA(0x29000000,0x2a477a00,0x2aeb3700),
105636 01-01 21:49:10.224859   598 21498 D PostProcPipe:                       vOutPorts:FN(0),RN(0),TS(0x0),UK(0x0),[1]:(0x20203859),w(2672),h(2008),stride(2672,0,0),type(0),idx(37),dir(1),Size(0x0051de80,0x00000000,0x00000000),VA(0xc28e5000,0x0,0x0),PA(0x27200000,0x0,0x0),
105637 01-01 21:49:10.224859   598 21498 D PostProcPipe:                       vOutPorts:FN(0),RN(0),TS(0x0),UK(0x0),[2]:(0x11),w(1280),h(720),stride(1280,1280,0),type(0),idx(38),dir(1),Size(0x000e1000,0x00070800,0x00000000),VA(0xc2119000,0xe6b91000,0x0),PA(0xf400000,0xf500000,0x0)
105639 01-01 21:49:10.225029   598 21498 D PostProcPipe: [configPipe] [Imgi][crop_1](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(0,0,0,0)-[crop_2](x,f_x,y,f_y)=(2,0,505,0),(w,h,tarW,tarH)=(5340,3002,1280,720)-[crop_3](x,f_x,y,f_y)=(0,0,0,0),(w,h,tarW,tarH)=(5344,4016,2672,2008),dupCqIdx(0),[vipi]ofst(0),rW/H(0/0)
105640 01-01 21:49:10.225029   598 21498 D PostProcPipe: ,                     isDipOnly(0), hwmodule(9/0), dipCQ/dup/burst(11/0/0), drvSc(4), isWtf(0),tdr_tpipe(0),en_yuv/yuv2/rgb/dma/fmt_sel/ctl_sel/misc (0x10c01cf8/0xc0/0x14acfd/0x30e181/0x200009/0x6040/0x10), tcm(0xa/0x99f8e423/0x282eb0c), last(1), CRZ_EN(0), img3o ofset(0,0),userName(MfllCore/Mfb),PIX_ID(0),ImgBuf_PIX_ID(0)
105726 01-01 21:49:10.231819   598 21499 D MdpMgr  : [_startMdp] +sceID(4),cqPa(0x8928000)-Va(0xe650e000),tpipVa(0xe4abf000)-Pa(0x97c0000),isWaitB(0),venc(0),        HMyo CQ info (11_0_0), ref(11_0_0) dpobj(11_0_0), (va: 0xe4abf000),        srcFt(0x2201),W(5344),H(4016),stride(6680,0),size(0x1995880-0x0-0x0),VA(0x    ffff),PA(0x21700000),plane(1),Stmtype(1)
105727 01-01 21:49:10.231819   598 21499 D MdpMgr  :         wdma_en(1),idx(0),cap(0),ft(1),rt(0),fp(0),(w,h,s)=(1280,720,1280),C(w,h,s)=(1280,360,1280),V(w,h,s)=(640,360,640),mdpidx(0),
105728 01-01 21:49:10.231819   598 21499 D MdpMgr  :         wrot_en(1),idx(1),cap(0),ft(4),rt(0),fp(0),(w,h,s)=(2672,2008,2672),C(w,h,s)=(1280,360,1280),V(w,h,s)=(0,0,0),mdpidx(0),
105729 01-01 21:49:10.231819   598 21499 D MdpMgr  :         jpg_en(0),idx(2),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(1),
105730 01-01 21:49:10.231819   598 21499 D MdpMgr  :         pipe_en(0),idx(3),cap(0),ft(0),rt(0),fp(0),(w,h,s)=(0,0,0),C(w,h,s)=(0,0,0),V(w,h,s)=(0,0,0),mdpidx(2),
105731 01-01 21:49:10.231819   598 21499 D MdpMgr  :         HMyo CQ(11_0_0),ref(11_0_0),(va:0x0_0xe4abf000,dstpa:0x97c0000)
105732 01-01 21:49:10.231819   598 21499 D MdpMgr  : flag(0_0x0->0x0),startStm(5983 us),WDPQ(0x       0),WRPQ(0x       0)

*/

    QParams enqueParams;
    FrameParams frameParams;

    //frame tag
    frameParams.mStreamTag = NSCam::NSIoPipe::NSPostProc::ENormalStreamTag_Vss;

    //input image
    MUINT32 _imgi_w_=5344, _imgi_h_=4016;
    IMEM_BUF_INFO buf_imgi;
    buf_imgi.size=0x01995880;
    mpImemDrv->allocVirtBuf(&buf_imgi);
    memcpy( (MUINT8*)(buf_imgi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_imgi.size);
    //imem buffer 2 image heap
    printf("--- [test_Vss(%d)...flag -1 ]\n", type);
    IImageBuffer* srcBuffer;
    MINT32 bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 bufStridesInBytes[3] = {(6680) , 0, 0};
    PortBufInfo_v1 portBufInfo = PortBufInfo_v1( buf_imgi.memID,buf_imgi.virtAddr,0,buf_imgi.bufSecu, buf_imgi.bufCohe);
    IImageBufferAllocator::ImgParam imgParam = IImageBufferAllocator::ImgParam((eImgFmt_BAYER10),MSize(_imgi_w_, _imgi_h_), bufStridesInBytes, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap;
    pHeap = ImageBufferHeap::create( "test_Vss", imgParam,portBufInfo,true);
    srcBuffer = pHeap->createImageBuffer();
    srcBuffer->incStrong(srcBuffer);
    srcBuffer->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    printf("--- [test_Vss(%d)...flag -8]\n", type);
    Input src;
    src.mPortID=PORT_IMGI;
    src.mBuffer=srcBuffer;
    src.mPortID.group=0;
    frameParams.mvIn.push_back(src);

    MUINT32 _depi_w_=1536, _depi_h_=16;
    IMEM_BUF_INFO buf_depi;
    buf_depi.size=0x00006000;
    mpImemDrv->allocVirtBuf(&buf_depi);
    memcpy( (MUINT8*)(buf_depi.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_depi.size);
    IImageBuffer* depi_srcBuffer;
    MINT32 depi_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 depi_bufStridesInBytes[3] = {(1536), 0, 0};
    PortBufInfo_v1 depi_portBufInfo = PortBufInfo_v1( buf_depi.memID,buf_depi.virtAddr,0,buf_depi.bufSecu, buf_depi.bufCohe);
    IImageBufferAllocator::ImgParam depi_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_STA_BYTE),MSize(_depi_w_, _depi_h_), depi_bufStridesInBytes, depi_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> depi_pHeap;
    depi_pHeap = ImageBufferHeap::create( "test_Vss", depi_imgParam,depi_portBufInfo,true);
    depi_srcBuffer = depi_pHeap->createImageBuffer();
    depi_srcBuffer->incStrong(depi_srcBuffer);
    depi_srcBuffer->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Input depi_src;
    depi_src.mPortID=PORT_DEPI;
    depi_src.mBuffer=depi_srcBuffer;
    depi_src.mPortID.group=0;
    frameParams.mvIn.push_back(depi_src);
    
    MUINT32 _lcei_w_=334, _lcei_h_=250;
    IMEM_BUF_INFO buf_lcei;
    buf_lcei.size=0x00048000;
    mpImemDrv->allocVirtBuf(&buf_lcei);
    memcpy( (MUINT8*)(buf_lcei.virtAddr), (MUINT8*)(g_imgi_5344_4016_yuy2), buf_lcei.size);
    IImageBuffer* lcei_srcBuffer;
    MINT32 lcei_bufBoundaryInBytes[3] = {0, 0, 0};
    MUINT32 lcei_bufStridesInBytes[3] = {(768), 0, 0};
    PortBufInfo_v1 lcei_portBufInfo = PortBufInfo_v1( buf_lcei.memID,buf_lcei.virtAddr,0,buf_lcei.bufSecu, buf_lcei.bufCohe);
    IImageBufferAllocator::ImgParam lcei_imgParam = IImageBufferAllocator::ImgParam((eImgFmt_STA_2BYTE),MSize(_lcei_w_, _lcei_h_), lcei_bufStridesInBytes, lcei_bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> lcei_pHeap;
    lcei_pHeap = ImageBufferHeap::create( "test_Vss", lcei_imgParam,lcei_portBufInfo,true);
    lcei_srcBuffer = lcei_pHeap->createImageBuffer();
    lcei_srcBuffer->incStrong(lcei_srcBuffer);
    lcei_srcBuffer->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Input lcei_src;
    lcei_src.mPortID=PORT_LCEI;
    lcei_src.mBuffer=lcei_srcBuffer;
    lcei_src.mPortID.group=0;
    frameParams.mvIn.push_back(lcei_src);

    printf("--- [test_Vss(%d)...push src done]\n", type);

    dip_x_reg_t tuningDat;
    memcpy( (MUINT8*)(&tuningDat.DIP_X_CTL_START), (MUINT8*)(vss_tuning_buffer), sizeof(dip_x_reg_t));

    frameParams.mTuningData = (MVOID*)&tuningDat;

   //crop information
    MCrpRsInfo crop;
    crop.mFrameGroup=0;
    crop.mGroupID=1;
    MCrpRsInfo crop2;
    crop2.mFrameGroup=0;
    crop2.mGroupID=2;
    MCrpRsInfo crop3;
    crop3.mFrameGroup=0;
    crop3.mGroupID=3;
    crop.mCropRect.p_fractional.x=0;
    crop.mCropRect.p_fractional.y=0;
    crop.mCropRect.p_integral.x=0;
    crop.mCropRect.p_integral.y=0;
    crop.mCropRect.s.w=0;
    crop.mCropRect.s.h=0;
    crop.mResizeDst.w=0;
    crop.mResizeDst.h=0;
    crop2.mCropRect.p_fractional.x=0;
    crop2.mCropRect.p_fractional.y=0;
    crop2.mCropRect.p_integral.x=2;
    crop2.mCropRect.p_integral.y=505;
    crop2.mCropRect.s.w=5340;
    crop2.mCropRect.s.h=3002;
    crop2.mResizeDst.w=1280;
    crop2.mResizeDst.h=720;
    crop3.mCropRect.p_fractional.x=0;
    crop3.mCropRect.p_fractional.y=0;
    crop3.mCropRect.p_integral.x=0;
    crop3.mCropRect.p_integral.y=0;
    crop3.mCropRect.s.w=5344;
    crop3.mCropRect.s.h=4016;
    crop3.mResizeDst.w=2672;
    crop3.mResizeDst.h=2008;
    frameParams.mvCropRsInfo.push_back(crop);
    frameParams.mvCropRsInfo.push_back(crop2);
    frameParams.mvCropRsInfo.push_back(crop3);
    printf("--- [test_Vss(%d)...push crop information done\n]", type);

    //output dma
    MUINT32 _img3o_w_=5344, _img3o_h_=4016;
    IMEM_BUF_INFO buf_out0;
    buf_out0.size=0x01477a00+0x00a3bd00+0x00a3bd00;
    mpImemDrv->allocVirtBuf(&buf_out0);
    memset((MUINT8*)buf_out0.virtAddr, 0xffffffff, buf_out0.size);
    IImageBuffer* outBuffer=NULL;
    MUINT32 bufStridesInBytes_0[3] = {5344,2672,2672};
    PortBufInfo_v1 portBufInfo_0 = PortBufInfo_v1( buf_out0.memID,buf_out0.virtAddr,0,buf_out0.bufSecu, buf_out0.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_0 = IImageBufferAllocator::ImgParam((eImgFmt_I422),
                                         MSize(_img3o_w_,_img3o_h_),  bufStridesInBytes_0, bufBoundaryInBytes, 3);
    sp<ImageBufferHeap> pHeap_0 = ImageBufferHeap::create( "test_Vss", imgParam_0,portBufInfo_0,true);
    outBuffer = pHeap_0->createImageBuffer();
    outBuffer->incStrong(outBuffer);
    outBuffer->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst;
    dst.mPortID=PORT_IMG3O;
    dst.mBuffer=outBuffer;
    dst.mPortID.group=0;
    frameParams.mvOut.push_back(dst);
    
    MUINT32 _wrot_w_=2672, _wrot_h_=2008;
    IMEM_BUF_INFO buf_out1;
    buf_out1.size=0x0051de80;
    mpImemDrv->allocVirtBuf(&buf_out1);
    memset((MUINT8*)buf_out1.virtAddr, 0xffffffff, buf_out1.size);
    IImageBuffer* outBuffer_1=NULL;
    MUINT32 bufStridesInBytes_1[3] = {2672,0,0};
    PortBufInfo_v1 portBufInfo_1 = PortBufInfo_v1( buf_out1.memID,buf_out1.virtAddr,0,buf_out1.bufSecu, buf_out1.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_1 = IImageBufferAllocator::ImgParam((eImgFmt_Y8),
                                         MSize(_wrot_w_,_wrot_h_),  bufStridesInBytes_1, bufBoundaryInBytes, 1);
    sp<ImageBufferHeap> pHeap_1 = ImageBufferHeap::create( "test_Vss", imgParam_1,portBufInfo_1,true);
    outBuffer_1 = pHeap_1->createImageBuffer();
    outBuffer_1->incStrong(outBuffer_1);
    outBuffer_1->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst_1;
    dst_1.mPortID=PORT_WROTO;
    dst_1.mBuffer=outBuffer_1;
    dst_1.mPortID.group=0;
    frameParams.mvOut.push_back(dst_1);	

    MUINT32 _wdmao_w_=1280, _wdmao_h_=720;
    IMEM_BUF_INFO buf_out2;
    buf_out2.size=0x000e1000+0x00070800;
    mpImemDrv->allocVirtBuf(&buf_out2);
    memset((MUINT8*)buf_out2.virtAddr, 0xffffffff, buf_out2.size);
    IImageBuffer* outBuffer_2=NULL;
    MUINT32 bufStridesInBytes_2[3] = {1280,1280,0};
    PortBufInfo_v1 portBufInfo_2 = PortBufInfo_v1( buf_out2.memID,buf_out2.virtAddr,0,buf_out2.bufSecu, buf_out2.bufCohe);
    IImageBufferAllocator::ImgParam imgParam_2 = IImageBufferAllocator::ImgParam((eImgFmt_NV21),MSize(_wdmao_w_,_wdmao_h_),  bufStridesInBytes_2, bufBoundaryInBytes, 2);
    sp<ImageBufferHeap> pHeap_2 = ImageBufferHeap::create( "test_Vss", imgParam_2,portBufInfo_2,true);
    outBuffer_2 = pHeap_2->createImageBuffer();
    outBuffer_2->incStrong(outBuffer_2);
    outBuffer_2->lockBuf("test_Vss",eBUFFER_USAGE_HW_CAMERA_READWRITE | eBUFFER_USAGE_SW_READ_OFTEN);
    Output dst_2;
    dst_2.mPortID=PORT_WDMAO;
    dst_2.mBuffer=outBuffer_2;
    dst_2.mPortID.group=0;
    frameParams.mvOut.push_back(dst_2);	
    enqueParams.mvFrameParams.push_back(frameParams);
    printf("--- [test_Vss(%d)...push dst done\n]", type);

    g_VSS_Callback = MFALSE;
    enqueParams.mpfnCallback = VSS_Callback;

    for(int i=0;i<loopNum;i++)
    {
        memset((MUINT8*)(frameParams.mvOut[0].mBuffer->getBufVA(0)), 0xffffffff, buf_out0.size);
        memset((MUINT8*)(frameParams.mvOut[1].mBuffer->getBufVA(0)), 0xffffffff, buf_out1.size);
        memset((MUINT8*)(frameParams.mvOut[2].mBuffer->getBufVA(0)), 0xffffffff, buf_out2.size);

        //buffer operation
        mpImemDrv->cacheFlushAll();
        printf("--- [test_Vss(%d_%d)...flush done\n]", type, i);


        //enque
        ret=pStream->enque(enqueParams);
        if(!ret)
        {
            printf("---ERRRRRRRRR [test_Vss(%d_%d)..enque fail\n]", type, i);
        }
        else
        {
            printf("---[test_Vss(%d_%d)..enque done\n]",type, i);
        }

        //temp use while to observe in CVD
        //printf("--- [test_Vss(%d)...enter while...........\n]", type);
       //while(1);
        do{
            usleep(100000);
            if (MTRUE == g_VSS_Callback)
            {
                break;
            }
        }while(1);
        g_VSS_Callback = MFALSE;

        //deque
        //wait a momet in fpga
        //usleep(5000000);
 //       QParams dequeParams;
 //      ret=pStream->deque(dequeParams);
 //       if(!ret)
 //       {
 //           printf("---ERRRRRRRRR [test_Vss(%d_%d)..deque fail\n]",type, i);
 //       }
 //       else
 //       {
            printf("---[test_Vss(%d_%d)..deque done\n]", type, i);
 //       }


        //dump image
        //char filename[256];
        //sprintf(filename, "/data/P2iopipe_test_Vss_process0x%x_type%d_package%d_wdmao_%dx%d.yuv",(MUINT32) getpid (),type,i, _imgi_w_,_imgi_h_);
        //saveBufToFile(filename, reinterpret_cast<MUINT8*>(dequeParams.mvFrameParams[0].mvOut[0].mBuffer->getBufVA(0)), _imgi_w_ *_imgi_h_ * 2);
        //char filename2[256];
        //sprintf(filename2, "/data/P2iopipe_test_Vss_process0x%x_type%d_package%d_wroto_%dx%d.yuv",(MUINT32) getpid (),type,i, _imgi_w_,_imgi_h_);
        //saveBufToFile(filename2, reinterpret_cast<MUINT8*>(dequeParams.mvFrameParams[0].mvOut[1].mBuffer->getBufVA(0)), _imgi_w_ *_imgi_h_ * 2);
        printf("--- [test_Vss(%d_%d)...save file done\n]", type,i);
    }

    //free
    srcBuffer->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_imgi);
    depi_srcBuffer->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_depi);
    lcei_srcBuffer->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_lcei);
    outBuffer->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_out0);
    outBuffer_1->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_out1);
    outBuffer_2->unlockBuf("test_Vss");
    mpImemDrv->freeVirtBuf(&buf_out2);
    printf("--- [test_Vss(%d)...free memory done\n]", type);

    //
    pStream->uninit("test_Vss");
    pStream->destroyInstance();
    printf("--- [test_Vss(%d)...pStream uninit done\n]", type);
    mpImemDrv->uninit();
    mpImemDrv->destroyInstance();
    return ret;
}

void VSS_Callback(QParams& rParams)
{
    printf("--- [VSS callback func]\n");
		
    g_VSS_Callback = MTRUE;
}