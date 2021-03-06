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
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "FdvtDrv"

#include <utils/Errors.h>
#include <utils/Mutex.h>    // For android::Mutex.
#include <cutils/log.h>
#include <cutils/properties.h>  // For property_get().
#include <fcntl.h>
#include <sys/mman.h>
#include <linux/mman-proprietary.h>
#include <cutils/atomic.h>

#include "camera_fdvt.h"
#include <mtkcam/def/common.h>
#include <mtkcam/drv/def/fdvtcommon.h>
#include <fdvt_drv.h>
#include <pic/all_header.h>
#include <fd_dram_size.h>
#include <fd_dram_info.h>
#include <attr_dram_info.h>
#include <pose_dram_info.h>
#include <fdvtunittest.h>
#include <imem_drv.h>

#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#define  DBG_LOG_TAG        LOG_TAG
#include "log.h"                        // Note: DBG_LOG_TAG/LEVEL will be used in header file, so header must be included after definition.
#include <cutils/properties.h>
DECLARE_DBG_LOG_VARIABLE(fdvt_drv);


// Clear previous define, use our own define.
#undef LOG_VRB
#undef LOG_DBG
#undef LOG_INF
#undef LOG_WRN
#undef LOG_ERR
#undef LOG_AST
#define LOG_VRB(fmt, arg...)        BASE_LOG_VRB(fmt, ##arg);
#define LOG_DBG(fmt, arg...)        do { if (g_isFDVTLogEnable) { BASE_LOG_INF(fmt, ##arg); } } while(0)
#define LOG_INF(fmt, arg...)        BASE_LOG_INF(fmt, ##arg);
#define LOG_WRN(fmt, arg...)        BASE_LOG_WRN(fmt, ##arg);
#define LOG_ERR(fmt, arg...)        BASE_LOG_ERR(fmt, ##arg);
#define LOG_AST(cond, fmt, arg...)  BASE_LOG_AST(cond, fmt, ##arg);

#define FD_Unit_Test 0
#define ATTR_Unit_Test 0
#define POSE_Unit_Test 0

#define FD_MEMSET(p,v,size)         do { if(g_isFDVTSecure==0) {memset(p, v, size); } } while(0)
MBOOL g_isFDVTSecure = MFALSE;
MUINT32 g_FDVTSecMemType = 1; // 0: normal, 1: protected, 2: secure
MBOOL g_isReleased = MTRUE;

MBOOL g_isFDVTLogEnable = MFALSE;
FdDrv_Para *g_FdDrv_Para = (FdDrv_Para *)malloc(sizeof(FdDrv_Para));
FdDrv_Attr_Para *g_FdDrv_Attr_Para = (FdDrv_Attr_Para *)malloc(sizeof(FdDrv_Attr_Para));
FdDrv_Pose_Para *g_FdDrv_Pose_Para = (FdDrv_Pose_Para *)malloc(sizeof(FdDrv_Pose_Para));
FdDrv_FD_DMA_Para *g_FdDrv_Fd_DMA_Para = (FdDrv_FD_DMA_Para *)malloc(sizeof(FdDrv_FD_DMA_Para));
#if 1
DipIMemDrv *g_FdvtImemDrv = NULL;
IMEM_BUF_INFO Fdvt_Imem_Buf_Info;
//Input Buffer Pointer
IMEM_BUF_INFO Imem_RS_ConfigData;
IMEM_BUF_INFO Imem_FD_ConfigData;
IMEM_BUF_INFO Imem_YUV2RGB_ConfigData;
//HW Output Buffer Pointer
IMEM_BUF_INFO Imem_YUV2RGB_Outout_hw;
IMEM_BUF_INFO Imem_RS_Output_hw;
IMEM_BUF_INFO Imem_FD_DMA_hw;
IMEM_BUF_INFO Imem_FD_DMA_Result_hw;

MUINT8   *g_FdvtImem_pLogVir=NULL;
MINT32   g_FdvtImem_MemID;
MUINT32  g_FdvtImem_Size;
MUINT32  Fdvt_Imem_AllocNum = 0;
#endif

//DRAM Buffer Size
unsigned int fdvt_fdmode_rs_config_size, fdvt_fdmode_fd_config_size, fdvt_fdmode_yuv2rgb_config_size;
unsigned int fdvt_attrmode_rs_config_size, fdvt_attrmode_fd_config_size, fdvt_attrmode_yuv2rgb_config_size;
unsigned int fdvt_posemode_rs_config_size, fdvt_posemode_fd_config_size, fdvt_posemode_yuv2rgb_config_size;

//HW Output Buffer Size
unsigned int fdvt_frame_R_size, fdvt_frame_G_size, fdvt_frame_B_size;
unsigned int fdvt_rs_pyramid0_out_size, fdvt_rs_pyramid1_out_size, fdvt_rs_pyramid2_out_size;
unsigned int fdvt_fd_DMA_MAX_size, fdvt_fd_DMA_Result_MAX_size;


#if FD_Unit_Test
//FD PART
unsigned int *fdvt_frame_R_golden, *fdvt_frame_G_golden, *fdvt_frame_B_golden;
unsigned int *fdvt_frame_R_pyramid0_golden, *fdvt_frame_G_pyramid0_golden, *fdvt_frame_B_pyramid0_golden;
unsigned int *fdvt_frame_R_pyramid1_golden, *fdvt_frame_G_pyramid1_golden, *fdvt_frame_B_pyramid1_golden;
unsigned int *fdvt_frame_R_pyramid2_golden, *fdvt_frame_G_pyramid2_golden, *fdvt_frame_B_pyramid2_golden;

unsigned int *fdvt_fd_out_loop00_0_golden, *fdvt_fd_out_loop00_2_golden;
unsigned int *fdvt_fd_out_loop01_0_golden, *fdvt_fd_out_loop01_2_golden;
unsigned int *fdvt_fd_out_loop02_0_golden;
unsigned int *fdvt_fd_out_loop03_0_golden, *fdvt_fd_out_loop03_1_golden, *fdvt_fd_out_loop03_2_golden, *fdvt_fd_out_loop03_3_golden;
unsigned int *fdvt_fd_out_loop04_0_golden, *fdvt_fd_out_loop04_1_golden, *fdvt_fd_out_loop04_2_golden, *fdvt_fd_out_loop04_3_golden;
unsigned int *fdvt_fd_out_loop05_0_golden, *fdvt_fd_out_loop05_2_golden;
unsigned int *fdvt_fd_out_loop06_0_golden, *fdvt_fd_out_loop06_1_golden;
unsigned int *fdvt_fd_out_loop07_0_golden, *fdvt_fd_out_loop07_2_golden;
unsigned int *fdvt_fd_out_loop08_0_golden, *fdvt_fd_out_loop08_1_golden;
unsigned int *fdvt_fd_out_loop09_0_golden;
unsigned int *fdvt_fd_out_loop10_0_golden;
unsigned int *fdvt_fd_out_loop11_0_golden;
unsigned int *fdvt_fd_out_loop12_0_golden;
unsigned int *fdvt_fd_out_loop13_0_golden;
unsigned int *fdvt_fd_out_loop14_0_golden;
unsigned int *fdvt_fd_out_loop15_0_golden, *fdvt_fd_out_loop15_1_golden;
unsigned int *fdvt_fd_out_loop16_0_golden, *fdvt_fd_out_loop16_1_golden, *fdvt_fd_out_loop16_2_golden, *fdvt_fd_out_loop16_3_golden;
unsigned int *fdvt_fd_out_loop17_0_golden, *fdvt_fd_out_loop17_1_golden;
unsigned int *fdvt_fd_out_loop18_0_golden, *fdvt_fd_out_loop18_1_golden;
unsigned int *fdvt_fd_out_loop19_0_golden;

unsigned int *fdvt_fd_out_loop20_0_golden, *fdvt_fd_out_loop20_2_golden;
unsigned int *fdvt_fd_out_loop21_0_golden, *fdvt_fd_out_loop21_2_golden;
unsigned int *fdvt_fd_out_loop22_0_golden;
unsigned int *fdvt_fd_out_loop23_0_golden, *fdvt_fd_out_loop23_1_golden, *fdvt_fd_out_loop23_2_golden, *fdvt_fd_out_loop23_3_golden;
unsigned int *fdvt_fd_out_loop24_0_golden, *fdvt_fd_out_loop24_1_golden, *fdvt_fd_out_loop24_2_golden, *fdvt_fd_out_loop24_3_golden;
unsigned int *fdvt_fd_out_loop25_0_golden, *fdvt_fd_out_loop25_2_golden;
unsigned int *fdvt_fd_out_loop26_0_golden, *fdvt_fd_out_loop26_1_golden;
unsigned int *fdvt_fd_out_loop27_0_golden, *fdvt_fd_out_loop27_2_golden;
unsigned int *fdvt_fd_out_loop28_0_golden, *fdvt_fd_out_loop28_1_golden;
unsigned int *fdvt_fd_out_loop29_0_golden;
unsigned int *fdvt_fd_out_loop30_0_golden;
unsigned int *fdvt_fd_out_loop31_0_golden;
unsigned int *fdvt_fd_out_loop32_0_golden;
unsigned int *fdvt_fd_out_loop33_0_golden;
unsigned int *fdvt_fd_out_loop34_0_golden;
unsigned int *fdvt_fd_out_loop35_0_golden, *fdvt_fd_out_loop35_1_golden;
unsigned int *fdvt_fd_out_loop36_0_golden, *fdvt_fd_out_loop36_1_golden, *fdvt_fd_out_loop36_2_golden, *fdvt_fd_out_loop36_3_golden;
unsigned int *fdvt_fd_out_loop37_0_golden, *fdvt_fd_out_loop37_1_golden;
unsigned int *fdvt_fd_out_loop38_0_golden, *fdvt_fd_out_loop38_1_golden;
unsigned int *fdvt_fd_out_loop39_0_golden;

unsigned int *fdvt_fd_out_loop40_0_golden, *fdvt_fd_out_loop40_2_golden;
unsigned int *fdvt_fd_out_loop41_0_golden, *fdvt_fd_out_loop41_2_golden;
unsigned int *fdvt_fd_out_loop42_0_golden;
unsigned int *fdvt_fd_out_loop43_0_golden, *fdvt_fd_out_loop43_1_golden, *fdvt_fd_out_loop43_2_golden, *fdvt_fd_out_loop43_3_golden;
unsigned int *fdvt_fd_out_loop44_0_golden, *fdvt_fd_out_loop44_1_golden, *fdvt_fd_out_loop44_2_golden, *fdvt_fd_out_loop44_3_golden;
unsigned int *fdvt_fd_out_loop45_0_golden, *fdvt_fd_out_loop45_2_golden;
unsigned int *fdvt_fd_out_loop46_0_golden, *fdvt_fd_out_loop46_1_golden;
unsigned int *fdvt_fd_out_loop47_0_golden, *fdvt_fd_out_loop47_2_golden;
unsigned int *fdvt_fd_out_loop48_0_golden, *fdvt_fd_out_loop48_1_golden;
unsigned int *fdvt_fd_out_loop49_0_golden;
unsigned int *fdvt_fd_out_loop50_0_golden;
unsigned int *fdvt_fd_out_loop51_0_golden;
unsigned int *fdvt_fd_out_loop52_0_golden;
unsigned int *fdvt_fd_out_loop53_0_golden;
unsigned int *fdvt_fd_out_loop54_0_golden;
unsigned int *fdvt_fd_out_loop55_0_golden, *fdvt_fd_out_loop55_1_golden;
unsigned int *fdvt_fd_out_loop56_0_golden, *fdvt_fd_out_loop56_1_golden, *fdvt_fd_out_loop56_2_golden, *fdvt_fd_out_loop56_3_golden;
unsigned int *fdvt_fd_out_loop57_0_golden, *fdvt_fd_out_loop57_1_golden, *fdvt_fd_out_loop57_2_golden, *fdvt_fd_out_loop57_3_golden;
unsigned int *fdvt_fd_out_loop58_0_golden, *fdvt_fd_out_loop58_1_golden;
unsigned int *fdvt_fd_out_loop59_0_golden, *fdvt_fd_out_loop59_1_golden;
unsigned int *fdvt_fd_out_loop60_0_golden, *fdvt_fd_out_loop60_1_golden;
unsigned int *fdvt_fd_out_loop61_0_golden;
unsigned int *fdvt_fd_out_loop62_0_golden, *fdvt_fd_out_loop62_1_golden;
unsigned int *fdvt_fd_out_loop63_0_golden, *fdvt_fd_out_loop63_1_golden;
unsigned int *fdvt_fd_out_loop64_0_golden;
unsigned int *fdvt_fd_out_loop65_0_golden;
#endif
#if ATTR_Unit_Test
// ATTR PART
unsigned int *attr_frame_R_golden, *attr_frame_G_golden, *attr_frame_B_golden;
unsigned int *attr_frame_R_pyramid0_golden, *attr_frame_G_pyramid0_golden, *attr_frame_B_pyramid0_golden;

unsigned int *attr_fd_out_loop00_0_golden, *attr_fd_out_loop00_2_golden;
unsigned int *attr_fd_out_loop01_0_golden, *attr_fd_out_loop01_2_golden;
unsigned int *attr_fd_out_loop02_0_golden;
unsigned int *attr_fd_out_loop03_0_golden, *attr_fd_out_loop03_1_golden, *attr_fd_out_loop03_2_golden, *attr_fd_out_loop03_3_golden;
unsigned int *attr_fd_out_loop04_0_golden, *attr_fd_out_loop04_1_golden, *attr_fd_out_loop04_2_golden, *attr_fd_out_loop04_3_golden;
unsigned int *attr_fd_out_loop05_0_golden, *attr_fd_out_loop05_2_golden;
unsigned int *attr_fd_out_loop06_0_golden, *attr_fd_out_loop06_1_golden;
unsigned int *attr_fd_out_loop07_0_golden, *attr_fd_out_loop07_2_golden;
unsigned int *attr_fd_out_loop08_0_golden, *attr_fd_out_loop08_1_golden;
unsigned int *attr_fd_out_loop09_0_golden;
unsigned int *attr_fd_out_loop10_0_golden;
unsigned int *attr_fd_out_loop11_0_golden;
unsigned int *attr_fd_out_loop12_0_golden;
unsigned int *attr_fd_out_loop13_0_golden;
unsigned int *attr_fd_out_loop14_0_golden;
unsigned int *attr_fd_out_loop15_0_golden, *attr_fd_out_loop15_1_golden;
unsigned int *attr_fd_out_loop16_0_golden;
unsigned int *attr_fd_out_loop17_0_golden;
#endif
#if POSE_Unit_Test
// POSE PART
unsigned int *pose_frame_R_golden, *pose_frame_G_golden, *pose_frame_B_golden;
unsigned int *pose_frame_R_pyramid0_golden, *pose_frame_G_pyramid0_golden, *pose_frame_B_pyramid0_golden;

unsigned int *pose_fd_out_loop00_0_golden, *pose_fd_out_loop00_2_golden;
unsigned int *pose_fd_out_loop01_0_golden, *pose_fd_out_loop01_2_golden;
unsigned int *pose_fd_out_loop02_0_golden;
unsigned int *pose_fd_out_loop03_0_golden, *pose_fd_out_loop03_1_golden, *pose_fd_out_loop03_2_golden, *pose_fd_out_loop03_3_golden;
unsigned int *pose_fd_out_loop04_0_golden, *pose_fd_out_loop04_1_golden, *pose_fd_out_loop04_2_golden, *pose_fd_out_loop04_3_golden;
unsigned int *pose_fd_out_loop05_0_golden, *pose_fd_out_loop05_2_golden;
unsigned int *pose_fd_out_loop06_0_golden, *pose_fd_out_loop06_1_golden;
unsigned int *pose_fd_out_loop07_0_golden, *pose_fd_out_loop07_2_golden;
unsigned int *pose_fd_out_loop08_0_golden, *pose_fd_out_loop08_1_golden;
unsigned int *pose_fd_out_loop09_0_golden;
unsigned int *pose_fd_out_loop10_0_golden;
unsigned int *pose_fd_out_loop11_0_golden;
unsigned int *pose_fd_out_loop12_0_golden;
unsigned int *pose_fd_out_loop13_0_golden;
unsigned int *pose_fd_out_loop14_0_golden;
unsigned int *pose_fd_out_loop15_0_golden, *pose_fd_out_loop15_1_golden;
unsigned int *pose_fd_out_loop16_0_golden;
unsigned int *pose_fd_out_loop17_0_golden;
#endif

MINT32 FDVT_Imem_alloc(MUINT32 size,MINT32 *memId,MUINT8 **vAddr,MUINTPTR *pAddr,bool isSecure);
MINT32 FDVT_Imem_free(MUINT8 *vAddr, MUINTPTR phyAddr,MUINT32 size,MINT32 memId,bool isSecure);

class FdvtDbgTimer
{
protected:
    char const*const    mpszName;
    mutable MINT32      mIdx;
    MINT32 const        mi4StartUs;
    mutable MINT32      mi4LastUs;

public:
    FdvtDbgTimer(char const*const pszTitle)
        : mpszName(pszTitle)
        , mIdx(0)
        , mi4StartUs(getUs())
        , mi4LastUs(getUs())
    {
    }

    inline MINT32 getUs() const
    {
        struct timeval tv;
        ::gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
    }

    inline MBOOL ProfilingPrint(char const*const pszInfo = "") const
    {
        MINT32 const i4EndUs = getUs();
        if  (0==mIdx)
        {
            LOG_INF("[%s] %s:(%d-th) ===> [start-->now: %.06f ms]", mpszName, pszInfo, mIdx++, (float)(i4EndUs-mi4StartUs)/1000);
        }
        else
        {
            LOG_INF("[%s] %s:(%d-th) ===> [start-->now: %.06f ms] [last-->now: %.06f ms]", mpszName, pszInfo, mIdx++, (float)(i4EndUs-mi4StartUs)/1000, (float)(i4EndUs-mi4LastUs)/1000);
        }
        mi4LastUs = i4EndUs;

        //sleep(4); //wait 1 sec for AE stable

        return  MTRUE;
    }
};

MINT32              FdvtDrvImp::m_Fd = -1;
volatile MINT32     FdvtDrvImp::m_UserCnt = 0;
FDVT_DRV_RW_MODE     FdvtDrvImp::m_regRWMode = FDVT_DRV_R_ONLY;
MUINT32*            FdvtDrvImp::m_pFdvtHwRegAddr = NULL;
android::Mutex      FdvtDrvImp::m_FdvtInitMutex;

char                FdvtDrvImp::m_UserName[MAX_USER_NUMBER][32] =
{
    {"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},
    {"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},
    {"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},
    {"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},{"\0"},
};

FdvtDrvImp::FdvtDrvImp()
{
    DBG_LOG_CONFIG(drv, fdvt_drv);
    LOG_VRB("getpid[0x%08x],gettid[0x%08x]", getpid() ,gettid());
    m_pFdvtHwRegAddr = NULL;
}

template<>
EngineDrv<FDVTConfig>* EngineDrv<FDVTConfig>::createInstance()
{
    return FdvtDrvImp::getInstance();
}

static FdvtDrvImp singleton;

EngineDrv<FDVTConfig>* FdvtDrvImp::getInstance()
{
    singleton.ctl_tbl = fdvt_ctl;

    LOG_DBG("singleton[0x%p].",static_cast<void *>(&singleton));

    return &singleton;
}

void FDVT_getSizeOfData(MUINT16 MAX_SRC_IMG_WIDTH, MUINT16 MAX_SRC_IMG_HEIGHT)
{
    MUINT8 i = 0, j = 0;
    g_FdDrv_Para->MAX_SRC_Input_Width = MAX_SRC_IMG_WIDTH;
    g_FdDrv_Para->MAX_SRC_Input_Height = MAX_SRC_IMG_HEIGHT;
    fdvt_fd_DMA_MAX_size = 0;
    fdvt_fd_DMA_Result_MAX_size = 0;

    //FDMODE Dram Buffer Size
    fdvt_fdmode_rs_config_size = fdvt_fdmode_rs_confi_size;
    fdvt_fdmode_fd_config_size = fdvt_fdmode_fd_confi_size;
    fdvt_fdmode_yuv2rgb_config_size = fdvt_fdmode_yuv2rgb_confi_size;

    //ATTRMODE Dram Buffer Size
    fdvt_attrmode_rs_config_size = fdvt_attrmode_rs_confi_size;
    fdvt_attrmode_fd_config_size = fdvt_attrmode_fd_confi_size;
    fdvt_attrmode_yuv2rgb_config_size = fdvt_attrmode_yuv2rgb_confi_size;

    //POSEMODE Dram Buffer Size
    fdvt_posemode_rs_config_size = fdvt_posemode_rs_confi_size;
    fdvt_posemode_fd_config_size = fdvt_posemode_fd_confi_size;
    fdvt_posemode_yuv2rgb_config_size = fdvt_posemode_yuv2rgb_confi_size;

    //HW Output Buffer Size
    fdvt_frame_R_size = (unsigned int)(MAX_SRC_IMG_WIDTH * MAX_SRC_IMG_HEIGHT);
    fdvt_frame_G_size = (unsigned int)(MAX_SRC_IMG_WIDTH * MAX_SRC_IMG_HEIGHT);
    fdvt_frame_B_size = (unsigned int)(MAX_SRC_IMG_WIDTH * MAX_SRC_IMG_HEIGHT);

    fdvt_rs_pyramid0_out_size = (unsigned int)(400 * 400);
    fdvt_rs_pyramid1_out_size = (unsigned int)(200 * 200);
    fdvt_rs_pyramid2_out_size = (unsigned int)(104 * 100);

    //FDMODE Dram Buffer Size
    for(i=0; i < fdvt_fd_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(output_WDMA_WRA_buffer_en[i][j] == 1)
			    fdvt_fd_DMA_MAX_size += output_WDMA_WRA_buffer_size[i][j];
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(kernel_RDMA_RA_buffer_en[i][j] == 1)
			    fdvt_fd_DMA_MAX_size += kernel_RDMA_RA_buffer_size[i][j];
	    }
    }
    fdvt_fd_DMA_Result_MAX_size += output_WDMA_WRA_buffer_size[19][0];
    fdvt_fd_DMA_Result_MAX_size += output_WDMA_WRA_buffer_size[39][0];
    fdvt_fd_DMA_Result_MAX_size += output_WDMA_WRA_buffer_size[65][0];

    //ATTRMODE Dram Buffer Size
    for(i=0; i < fdvt_attr_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(attr_output_WDMA_WRA_buffer_en[i][j] == 1)
	    	{
			    if((i == fdvt_race_output_regression || i == fdvt_gender_output_regression) && (j == 0))
				    fdvt_fd_DMA_MAX_size += attr_output_WDMA_WRA_buffer_size[i][j]*MAX_ENQUE_FRAME_NUM;
			    else
				    fdvt_fd_DMA_MAX_size += attr_output_WDMA_WRA_buffer_size[i][j];
	    	}
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(attr_kernel_RDMA_RA_buffer_en[i][j] == 1)
			    fdvt_fd_DMA_MAX_size += attr_kernel_RDMA_RA_buffer_size[i][j];
	    }
    }
    fdvt_fd_DMA_Result_MAX_size += attr_output_WDMA_WRA_buffer_size[16][0]*MAX_ENQUE_FRAME_NUM;
    fdvt_fd_DMA_Result_MAX_size += attr_output_WDMA_WRA_buffer_size[17][0]*MAX_ENQUE_FRAME_NUM;

    //POSEMODE Dram Buffer Size
    for(i=0; i < fdvt_pose_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(pose_output_WDMA_WRA_buffer_en[i][j] == 1)
	    	{
			    if((i == fdvt_rip_output_regression || i == fdvt_rop_output_regression) && (j == 0))
				    fdvt_fd_DMA_MAX_size += pose_output_WDMA_WRA_buffer_size[i][j]*MAX_ENQUE_FRAME_NUM;
			    else
				    fdvt_fd_DMA_MAX_size += pose_output_WDMA_WRA_buffer_size[i][j];
	    	}
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(pose_kernel_RDMA_RA_buffer_en[i][j] == 1)
			    fdvt_fd_DMA_MAX_size += pose_kernel_RDMA_RA_buffer_size[i][j];
	    }
    }
    fdvt_fd_DMA_Result_MAX_size += pose_output_WDMA_WRA_buffer_size[16][0]*MAX_ENQUE_FRAME_NUM;
    fdvt_fd_DMA_Result_MAX_size += pose_output_WDMA_WRA_buffer_size[17][0]*MAX_ENQUE_FRAME_NUM;

}

void FDVT_allocateDramBuffer()
{
	MUINT8 i = 0;
    //RS DRAM
    g_FdvtImem_Size = fdvt_fdmode_rs_config_size + fdvt_attrmode_rs_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_rs_config_size*MAX_ENQUE_FRAME_NUM;
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_RS_ConfigData.phyAddr, g_isFDVTSecure);
    Imem_RS_ConfigData.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_RS_ConfigData.memID=g_FdvtImem_MemID;
    Imem_RS_ConfigData.size=g_FdvtImem_Size;
    //FD MODE
    g_FdDrv_Para->FDMODE_RS_Config_PA = (MUINT32*)Imem_RS_ConfigData.phyAddr;
    g_FdDrv_Para->FDMODE_RS_Config_VA = (MUINT64*)Imem_RS_ConfigData.virtAddr;
    FD_MEMSET(g_FdDrv_Para->FDMODE_RS_Config_VA, 0, fdvt_fdmode_rs_config_size);
    //ATTR MODE
    g_FdDrv_Para->ATTRMODE_RS_Config_PA[0] = g_FdDrv_Para->FDMODE_RS_Config_PA + fdvt_fdmode_rs_config_size/4;
    g_FdDrv_Para->ATTRMODE_RS_Config_VA[0] = g_FdDrv_Para->FDMODE_RS_Config_VA + fdvt_fdmode_rs_config_size/8;
    FD_MEMSET(g_FdDrv_Para->ATTRMODE_RS_Config_VA[0], 0, fdvt_attrmode_rs_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->ATTRMODE_RS_Config_PA[i] = g_FdDrv_Para->ATTRMODE_RS_Config_PA[i-1] + fdvt_attrmode_rs_config_size/4;
	    g_FdDrv_Para->ATTRMODE_RS_Config_VA[i] = g_FdDrv_Para->ATTRMODE_RS_Config_VA[i-1] + fdvt_attrmode_rs_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->ATTRMODE_RS_Config_VA[i], 0, fdvt_attrmode_rs_config_size);
    }
    //POSE MODE
    g_FdDrv_Para->POSEMODE_RS_Config_PA[0] = g_FdDrv_Para->ATTRMODE_RS_Config_PA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_rs_config_size/4;
    g_FdDrv_Para->POSEMODE_RS_Config_VA[0] = g_FdDrv_Para->ATTRMODE_RS_Config_VA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_rs_config_size/8;
    FD_MEMSET(g_FdDrv_Para->POSEMODE_RS_Config_VA[0], 0, fdvt_posemode_rs_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->POSEMODE_RS_Config_PA[i] = g_FdDrv_Para->POSEMODE_RS_Config_PA[i-1] + fdvt_posemode_rs_config_size/4;
	    g_FdDrv_Para->POSEMODE_RS_Config_VA[i] = g_FdDrv_Para->POSEMODE_RS_Config_VA[i-1] + fdvt_posemode_rs_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->POSEMODE_RS_Config_VA[i], 0, fdvt_posemode_rs_config_size);
    }
    //FD DRAM
    g_FdvtImem_Size = fdvt_fdmode_fd_config_size + fdvt_attrmode_fd_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_fd_config_size*MAX_ENQUE_FRAME_NUM;
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_FD_ConfigData.phyAddr, g_isFDVTSecure);
    Imem_FD_ConfigData.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_FD_ConfigData.memID=g_FdvtImem_MemID;
    Imem_FD_ConfigData.size=g_FdvtImem_Size;
    //FD MODE
    g_FdDrv_Para->FDMODE_FD_Config_PA = (MUINT32*)Imem_FD_ConfigData.phyAddr;
    g_FdDrv_Para->FDMODE_FD_Config_VA = (MUINT64*)Imem_FD_ConfigData.virtAddr;
    FD_MEMSET(g_FdDrv_Para->FDMODE_FD_Config_VA, 0, fdvt_fdmode_fd_config_size);
    //ATTR MODE
    g_FdDrv_Para->ATTRMODE_FD_Config_PA[0] = g_FdDrv_Para->FDMODE_FD_Config_PA + fdvt_fdmode_fd_config_size/4;
    g_FdDrv_Para->ATTRMODE_FD_Config_VA[0] = g_FdDrv_Para->FDMODE_FD_Config_VA + fdvt_fdmode_fd_config_size/8;
    FD_MEMSET(g_FdDrv_Para->ATTRMODE_FD_Config_VA[0], 0, fdvt_attrmode_fd_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->ATTRMODE_FD_Config_PA[i] = g_FdDrv_Para->ATTRMODE_FD_Config_PA[i-1] + fdvt_attrmode_fd_config_size/4;
	    g_FdDrv_Para->ATTRMODE_FD_Config_VA[i] = g_FdDrv_Para->ATTRMODE_FD_Config_VA[i-1] + fdvt_attrmode_fd_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->ATTRMODE_FD_Config_VA[i], 0, fdvt_attrmode_fd_config_size);
    }
    //POSE MODE
    g_FdDrv_Para->POSEMODE_FD_Config_PA[0] = g_FdDrv_Para->ATTRMODE_FD_Config_PA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_fd_config_size/4;
    g_FdDrv_Para->POSEMODE_FD_Config_VA[0] = g_FdDrv_Para->ATTRMODE_FD_Config_VA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_fd_config_size/8;
    FD_MEMSET(g_FdDrv_Para->POSEMODE_FD_Config_VA[0], 0, fdvt_posemode_fd_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->POSEMODE_FD_Config_PA[i] = g_FdDrv_Para->POSEMODE_FD_Config_PA[i-1] + fdvt_posemode_fd_config_size/4;
	    g_FdDrv_Para->POSEMODE_FD_Config_VA[i] = g_FdDrv_Para->POSEMODE_FD_Config_VA[i-1] + fdvt_posemode_fd_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->POSEMODE_FD_Config_VA[i], 0, fdvt_posemode_fd_config_size);
    }
    //YUV2RGB DRAM
    g_FdvtImem_Size = fdvt_fdmode_yuv2rgb_config_size + fdvt_attrmode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM+ fdvt_posemode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM;
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_YUV2RGB_ConfigData.phyAddr, g_isFDVTSecure);
    Imem_YUV2RGB_ConfigData.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_YUV2RGB_ConfigData.memID=g_FdvtImem_MemID;
    Imem_YUV2RGB_ConfigData.size=g_FdvtImem_Size;
    //FD MODE
    g_FdDrv_Para->FDMODE_YUV2RGB_Config_PA = (MUINT32*)Imem_YUV2RGB_ConfigData.phyAddr;
    g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA = (MUINT64*)Imem_YUV2RGB_ConfigData.virtAddr;
    FD_MEMSET(g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, 0, fdvt_fdmode_yuv2rgb_config_size);
    //ATTR MODE
    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[0] = g_FdDrv_Para->FDMODE_YUV2RGB_Config_PA + fdvt_fdmode_yuv2rgb_config_size/4;
    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[0] = g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA + fdvt_fdmode_yuv2rgb_config_size/8;
    FD_MEMSET(g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[0], 0, fdvt_attrmode_yuv2rgb_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[i] = g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[i-1] + fdvt_attrmode_yuv2rgb_config_size/4;
	    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i] = g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i-1] + fdvt_attrmode_yuv2rgb_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i], 0, fdvt_attrmode_yuv2rgb_config_size);
    }
    //POSE MODE
    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_PA[0] = g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_yuv2rgb_config_size/4;
    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[0] = g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[MAX_ENQUE_FRAME_NUM-1] + fdvt_attrmode_yuv2rgb_config_size/8;
    FD_MEMSET(g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[0], 0, fdvt_posemode_yuv2rgb_config_size);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_PA[i] = g_FdDrv_Para->POSEMODE_YUV2RGB_Config_PA[i-1] + fdvt_posemode_yuv2rgb_config_size/4;
	    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i] = g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i-1] + fdvt_posemode_yuv2rgb_config_size/8;
	    FD_MEMSET(g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i], 0, fdvt_posemode_yuv2rgb_config_size);
    }
}

void FDVT_allocateOutputBuffer()
{
    g_FdvtImem_Size = (fdvt_frame_R_size+fdvt_frame_G_size+fdvt_frame_B_size);
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_YUV2RGB_Outout_hw.phyAddr, g_isFDVTSecure);
    Imem_YUV2RGB_Outout_hw.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_YUV2RGB_Outout_hw.memID=g_FdvtImem_MemID;
    Imem_YUV2RGB_Outout_hw.size=g_FdvtImem_Size;
    g_FdDrv_Para->YUV2RGB_R_Result_PA = (MUINT32*)Imem_YUV2RGB_Outout_hw.phyAddr;
    g_FdDrv_Para->YUV2RGB_R_Result_VA = (MUINT64*)Imem_YUV2RGB_Outout_hw.virtAddr;
    g_FdDrv_Para->YUV2RGB_G_Result_PA = g_FdDrv_Para->YUV2RGB_R_Result_PA + fdvt_frame_R_size/4;
    g_FdDrv_Para->YUV2RGB_G_Result_VA = g_FdDrv_Para->YUV2RGB_R_Result_VA + fdvt_frame_R_size/8;
    g_FdDrv_Para->YUV2RGB_B_Result_PA = g_FdDrv_Para->YUV2RGB_G_Result_PA + fdvt_frame_G_size/4;
    g_FdDrv_Para->YUV2RGB_B_Result_VA = g_FdDrv_Para->YUV2RGB_G_Result_VA + fdvt_frame_G_size/8;

    g_FdvtImem_Size = (fdvt_rs_pyramid0_out_size*3 + fdvt_rs_pyramid1_out_size*3 + fdvt_rs_pyramid2_out_size*3);
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_RS_Output_hw.phyAddr, g_isFDVTSecure);
    Imem_RS_Output_hw.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_RS_Output_hw.memID=g_FdvtImem_MemID;
    Imem_RS_Output_hw.size=g_FdvtImem_Size;
    g_FdDrv_Para->RS_Pyramid0_R_Result_PA = (MUINT32*)Imem_RS_Output_hw.phyAddr;
    g_FdDrv_Para->RS_Pyramid0_R_Result_VA = (MUINT64*)Imem_RS_Output_hw.virtAddr;
    g_FdDrv_Para->RS_Pyramid0_G_Result_PA = g_FdDrv_Para->RS_Pyramid0_R_Result_PA + fdvt_rs_pyramid0_out_size/4;
    g_FdDrv_Para->RS_Pyramid0_G_Result_VA = g_FdDrv_Para->RS_Pyramid0_R_Result_VA + fdvt_rs_pyramid0_out_size/8;
    g_FdDrv_Para->RS_Pyramid0_B_Result_PA = g_FdDrv_Para->RS_Pyramid0_G_Result_PA + fdvt_rs_pyramid0_out_size/4;
    g_FdDrv_Para->RS_Pyramid0_B_Result_VA = g_FdDrv_Para->RS_Pyramid0_G_Result_VA + fdvt_rs_pyramid0_out_size/8;
    g_FdDrv_Para->RS_Pyramid1_R_Result_PA = g_FdDrv_Para->RS_Pyramid0_B_Result_PA + fdvt_rs_pyramid0_out_size/4;
    g_FdDrv_Para->RS_Pyramid1_R_Result_VA = g_FdDrv_Para->RS_Pyramid0_B_Result_VA + fdvt_rs_pyramid0_out_size/8;
    g_FdDrv_Para->RS_Pyramid1_G_Result_PA = g_FdDrv_Para->RS_Pyramid1_R_Result_PA + fdvt_rs_pyramid1_out_size/4;
    g_FdDrv_Para->RS_Pyramid1_G_Result_VA = g_FdDrv_Para->RS_Pyramid1_R_Result_VA + fdvt_rs_pyramid1_out_size/8;
    g_FdDrv_Para->RS_Pyramid1_B_Result_PA = g_FdDrv_Para->RS_Pyramid1_G_Result_PA + fdvt_rs_pyramid1_out_size/4;
    g_FdDrv_Para->RS_Pyramid1_B_Result_VA = g_FdDrv_Para->RS_Pyramid1_G_Result_VA + fdvt_rs_pyramid1_out_size/8;
    g_FdDrv_Para->RS_Pyramid2_R_Result_PA = g_FdDrv_Para->RS_Pyramid1_B_Result_PA + fdvt_rs_pyramid1_out_size/4;
    g_FdDrv_Para->RS_Pyramid2_R_Result_VA = g_FdDrv_Para->RS_Pyramid1_B_Result_VA + fdvt_rs_pyramid1_out_size/8;
    g_FdDrv_Para->RS_Pyramid2_G_Result_PA = g_FdDrv_Para->RS_Pyramid2_R_Result_PA + fdvt_rs_pyramid2_out_size/4;
    g_FdDrv_Para->RS_Pyramid2_G_Result_VA = g_FdDrv_Para->RS_Pyramid2_R_Result_VA + fdvt_rs_pyramid2_out_size/8;
    g_FdDrv_Para->RS_Pyramid2_B_Result_PA = g_FdDrv_Para->RS_Pyramid2_G_Result_PA + fdvt_rs_pyramid2_out_size/4;
    g_FdDrv_Para->RS_Pyramid2_B_Result_VA = g_FdDrv_Para->RS_Pyramid2_G_Result_VA + fdvt_rs_pyramid2_out_size/8;

	if (1)
	{
#if FD_Unit_Test
		// FD part
		fdvt_frame_R_golden = (unsigned int *)&fdvt_rgb_img_r_frame01[0];
		fdvt_frame_G_golden = (unsigned int *)&fdvt_rgb_img_g_frame01[0];
		fdvt_frame_B_golden = (unsigned int *)&fdvt_rgb_img_b_frame01[0];

		fdvt_frame_R_pyramid0_golden = (unsigned int *)&fdvt_rs_out_frame01_scale00_r[0];
		fdvt_frame_G_pyramid0_golden = (unsigned int *)&fdvt_rs_out_frame01_scale00_g[0];
		fdvt_frame_B_pyramid0_golden = (unsigned int *)&fdvt_rs_out_frame01_scale00_b[0];
		fdvt_frame_R_pyramid1_golden = (unsigned int *)&fdvt_rs_out_frame01_scale01_r[0];
		fdvt_frame_G_pyramid1_golden = (unsigned int *)&fdvt_rs_out_frame01_scale01_g[0];
		fdvt_frame_B_pyramid1_golden = (unsigned int *)&fdvt_rs_out_frame01_scale01_b[0];
		fdvt_frame_R_pyramid2_golden = (unsigned int *)&fdvt_rs_out_frame01_scale02_r[0];
		fdvt_frame_G_pyramid2_golden = (unsigned int *)&fdvt_rs_out_frame01_scale02_g[0];
		fdvt_frame_B_pyramid2_golden = (unsigned int *)&fdvt_rs_out_frame01_scale02_b[0];

		fdvt_fd_out_loop00_0_golden = (unsigned int *)&fdvt_fd_out_loop00_0[0];
		fdvt_fd_out_loop00_2_golden = (unsigned int *)&fdvt_fd_out_loop00_2[0];
		fdvt_fd_out_loop01_0_golden = (unsigned int *)&fdvt_fd_out_loop01_0[0];
		fdvt_fd_out_loop01_2_golden = (unsigned int *)&fdvt_fd_out_loop01_2[0];
		fdvt_fd_out_loop02_0_golden = (unsigned int *)&fdvt_fd_out_loop02_0[0];
		fdvt_fd_out_loop03_0_golden = (unsigned int *)&fdvt_fd_out_loop03_0[0];
		fdvt_fd_out_loop03_1_golden = (unsigned int *)&fdvt_fd_out_loop03_1[0];
		fdvt_fd_out_loop03_2_golden = (unsigned int *)&fdvt_fd_out_loop03_2[0];
		fdvt_fd_out_loop03_3_golden = (unsigned int *)&fdvt_fd_out_loop03_3[0];
		fdvt_fd_out_loop04_0_golden = (unsigned int *)&fdvt_fd_out_loop04_0[0];
		fdvt_fd_out_loop04_1_golden = (unsigned int *)&fdvt_fd_out_loop04_1[0];
		fdvt_fd_out_loop04_2_golden = (unsigned int *)&fdvt_fd_out_loop04_2[0];
		fdvt_fd_out_loop04_3_golden = (unsigned int *)&fdvt_fd_out_loop04_3[0];
		fdvt_fd_out_loop05_0_golden = (unsigned int *)&fdvt_fd_out_loop05_0[0];
		fdvt_fd_out_loop05_2_golden = (unsigned int *)&fdvt_fd_out_loop05_2[0];
		fdvt_fd_out_loop06_0_golden = (unsigned int *)&fdvt_fd_out_loop06_0[0];
		fdvt_fd_out_loop06_1_golden = (unsigned int *)&fdvt_fd_out_loop06_1[0];
		fdvt_fd_out_loop07_0_golden = (unsigned int *)&fdvt_fd_out_loop07_0[0];
		fdvt_fd_out_loop07_2_golden = (unsigned int *)&fdvt_fd_out_loop07_2[0];
		fdvt_fd_out_loop08_0_golden = (unsigned int *)&fdvt_fd_out_loop08_0[0];
		fdvt_fd_out_loop08_1_golden = (unsigned int *)&fdvt_fd_out_loop08_1[0];
		fdvt_fd_out_loop09_0_golden = (unsigned int *)&fdvt_fd_out_loop09_0[0];
		fdvt_fd_out_loop10_0_golden = (unsigned int *)&fdvt_fd_out_loop10_0[0];
		fdvt_fd_out_loop11_0_golden = (unsigned int *)&fdvt_fd_out_loop11_0[0];
		fdvt_fd_out_loop12_0_golden = (unsigned int *)&fdvt_fd_out_loop12_0[0];
		fdvt_fd_out_loop13_0_golden = (unsigned int *)&fdvt_fd_out_loop13_0[0];
		fdvt_fd_out_loop14_0_golden = (unsigned int *)&fdvt_fd_out_loop14_0[0];
		fdvt_fd_out_loop15_0_golden = (unsigned int *)&fdvt_fd_out_loop15_0[0];
		fdvt_fd_out_loop15_1_golden = (unsigned int *)&fdvt_fd_out_loop15_1[0];
		fdvt_fd_out_loop16_0_golden = (unsigned int *)&fdvt_fd_out_loop16_0[0];
		fdvt_fd_out_loop16_1_golden = (unsigned int *)&fdvt_fd_out_loop16_1[0];
		fdvt_fd_out_loop16_2_golden = (unsigned int *)&fdvt_fd_out_loop16_2[0];
		fdvt_fd_out_loop16_3_golden = (unsigned int *)&fdvt_fd_out_loop16_3[0];
		fdvt_fd_out_loop17_0_golden = (unsigned int *)&fdvt_fd_out_loop17_0[0];
		fdvt_fd_out_loop17_1_golden = (unsigned int *)&fdvt_fd_out_loop17_1[0];
		fdvt_fd_out_loop18_0_golden = (unsigned int *)&fdvt_fd_out_loop18_0[0];
		fdvt_fd_out_loop18_1_golden = (unsigned int *)&fdvt_fd_out_loop18_1[0];
		fdvt_fd_out_loop19_0_golden = (unsigned int *)&fdvt_fd_out_loop19_0[0];

		fdvt_fd_out_loop20_0_golden = (unsigned int *)&fdvt_fd_out_loop20_0[0];
		fdvt_fd_out_loop20_2_golden = (unsigned int *)&fdvt_fd_out_loop20_2[0];
		fdvt_fd_out_loop21_0_golden = (unsigned int *)&fdvt_fd_out_loop21_0[0];
		fdvt_fd_out_loop21_2_golden = (unsigned int *)&fdvt_fd_out_loop21_2[0];
		fdvt_fd_out_loop22_0_golden = (unsigned int *)&fdvt_fd_out_loop22_0[0];
		fdvt_fd_out_loop23_0_golden = (unsigned int *)&fdvt_fd_out_loop23_0[0];
		fdvt_fd_out_loop23_1_golden = (unsigned int *)&fdvt_fd_out_loop23_1[0];
		fdvt_fd_out_loop23_2_golden = (unsigned int *)&fdvt_fd_out_loop23_2[0];
		fdvt_fd_out_loop23_3_golden = (unsigned int *)&fdvt_fd_out_loop23_3[0];
		fdvt_fd_out_loop24_0_golden = (unsigned int *)&fdvt_fd_out_loop24_0[0];
		fdvt_fd_out_loop24_1_golden = (unsigned int *)&fdvt_fd_out_loop24_1[0];
		fdvt_fd_out_loop24_2_golden = (unsigned int *)&fdvt_fd_out_loop24_2[0];
		fdvt_fd_out_loop24_3_golden = (unsigned int *)&fdvt_fd_out_loop24_3[0];
		fdvt_fd_out_loop25_0_golden = (unsigned int *)&fdvt_fd_out_loop25_0[0];
		fdvt_fd_out_loop25_2_golden = (unsigned int *)&fdvt_fd_out_loop25_2[0];
		fdvt_fd_out_loop26_0_golden = (unsigned int *)&fdvt_fd_out_loop26_0[0];
		fdvt_fd_out_loop26_1_golden = (unsigned int *)&fdvt_fd_out_loop26_1[0];
		fdvt_fd_out_loop27_0_golden = (unsigned int *)&fdvt_fd_out_loop27_0[0];
		fdvt_fd_out_loop27_2_golden = (unsigned int *)&fdvt_fd_out_loop27_2[0];
		fdvt_fd_out_loop28_0_golden = (unsigned int *)&fdvt_fd_out_loop28_0[0];
		fdvt_fd_out_loop28_1_golden = (unsigned int *)&fdvt_fd_out_loop28_1[0];
		fdvt_fd_out_loop29_0_golden = (unsigned int *)&fdvt_fd_out_loop29_0[0];
		fdvt_fd_out_loop30_0_golden = (unsigned int *)&fdvt_fd_out_loop30_0[0];
		fdvt_fd_out_loop31_0_golden = (unsigned int *)&fdvt_fd_out_loop31_0[0];
		fdvt_fd_out_loop32_0_golden = (unsigned int *)&fdvt_fd_out_loop32_0[0];
		fdvt_fd_out_loop33_0_golden = (unsigned int *)&fdvt_fd_out_loop33_0[0];
		fdvt_fd_out_loop34_0_golden = (unsigned int *)&fdvt_fd_out_loop34_0[0];
		fdvt_fd_out_loop35_0_golden = (unsigned int *)&fdvt_fd_out_loop35_0[0];
		fdvt_fd_out_loop35_1_golden = (unsigned int *)&fdvt_fd_out_loop35_1[0];
		fdvt_fd_out_loop36_0_golden = (unsigned int *)&fdvt_fd_out_loop36_0[0];
		fdvt_fd_out_loop36_1_golden = (unsigned int *)&fdvt_fd_out_loop36_1[0];
		fdvt_fd_out_loop36_2_golden = (unsigned int *)&fdvt_fd_out_loop36_2[0];
		fdvt_fd_out_loop36_3_golden = (unsigned int *)&fdvt_fd_out_loop36_3[0];
		fdvt_fd_out_loop37_0_golden = (unsigned int *)&fdvt_fd_out_loop37_0[0];
		fdvt_fd_out_loop37_1_golden = (unsigned int *)&fdvt_fd_out_loop37_1[0];
		fdvt_fd_out_loop38_0_golden = (unsigned int *)&fdvt_fd_out_loop38_0[0];
		fdvt_fd_out_loop38_1_golden = (unsigned int *)&fdvt_fd_out_loop38_1[0];
		fdvt_fd_out_loop39_0_golden = (unsigned int *)&fdvt_fd_out_loop39_0[0];

		fdvt_fd_out_loop40_0_golden = (unsigned int *)&fdvt_fd_out_loop40_0[0];
		fdvt_fd_out_loop40_2_golden = (unsigned int *)&fdvt_fd_out_loop40_2[0];
		fdvt_fd_out_loop41_0_golden = (unsigned int *)&fdvt_fd_out_loop41_0[0];
		fdvt_fd_out_loop41_2_golden = (unsigned int *)&fdvt_fd_out_loop41_2[0];
		fdvt_fd_out_loop42_0_golden = (unsigned int *)&fdvt_fd_out_loop42_0[0];
		fdvt_fd_out_loop43_0_golden = (unsigned int *)&fdvt_fd_out_loop43_0[0];
		fdvt_fd_out_loop43_1_golden = (unsigned int *)&fdvt_fd_out_loop43_1[0];
		fdvt_fd_out_loop43_2_golden = (unsigned int *)&fdvt_fd_out_loop43_2[0];
		fdvt_fd_out_loop43_3_golden = (unsigned int *)&fdvt_fd_out_loop43_3[0];
		fdvt_fd_out_loop44_0_golden = (unsigned int *)&fdvt_fd_out_loop44_0[0];
		fdvt_fd_out_loop44_1_golden = (unsigned int *)&fdvt_fd_out_loop44_1[0];
		fdvt_fd_out_loop44_2_golden = (unsigned int *)&fdvt_fd_out_loop44_2[0];
		fdvt_fd_out_loop44_3_golden = (unsigned int *)&fdvt_fd_out_loop44_3[0];
		fdvt_fd_out_loop45_0_golden = (unsigned int *)&fdvt_fd_out_loop45_0[0];
		fdvt_fd_out_loop45_2_golden = (unsigned int *)&fdvt_fd_out_loop45_2[0];
		fdvt_fd_out_loop46_0_golden = (unsigned int *)&fdvt_fd_out_loop46_0[0];
		fdvt_fd_out_loop46_1_golden = (unsigned int *)&fdvt_fd_out_loop46_1[0];
		fdvt_fd_out_loop47_0_golden = (unsigned int *)&fdvt_fd_out_loop47_0[0];
		fdvt_fd_out_loop47_2_golden = (unsigned int *)&fdvt_fd_out_loop47_2[0];
		fdvt_fd_out_loop48_0_golden = (unsigned int *)&fdvt_fd_out_loop48_0[0];
		fdvt_fd_out_loop48_1_golden = (unsigned int *)&fdvt_fd_out_loop48_1[0];
		fdvt_fd_out_loop49_0_golden = (unsigned int *)&fdvt_fd_out_loop49_0[0];
		fdvt_fd_out_loop50_0_golden = (unsigned int *)&fdvt_fd_out_loop50_0[0];
		fdvt_fd_out_loop51_0_golden = (unsigned int *)&fdvt_fd_out_loop51_0[0];
		fdvt_fd_out_loop52_0_golden = (unsigned int *)&fdvt_fd_out_loop52_0[0];
		fdvt_fd_out_loop53_0_golden = (unsigned int *)&fdvt_fd_out_loop53_0[0];
		fdvt_fd_out_loop54_0_golden = (unsigned int *)&fdvt_fd_out_loop54_0[0];
		fdvt_fd_out_loop55_0_golden = (unsigned int *)&fdvt_fd_out_loop55_0[0];
		fdvt_fd_out_loop55_1_golden = (unsigned int *)&fdvt_fd_out_loop55_1[0];
		fdvt_fd_out_loop56_0_golden = (unsigned int *)&fdvt_fd_out_loop56_0[0];
		fdvt_fd_out_loop56_1_golden = (unsigned int *)&fdvt_fd_out_loop56_1[0];
		fdvt_fd_out_loop56_2_golden = (unsigned int *)&fdvt_fd_out_loop56_2[0];
		fdvt_fd_out_loop56_3_golden = (unsigned int *)&fdvt_fd_out_loop56_3[0];
		fdvt_fd_out_loop57_0_golden = (unsigned int *)&fdvt_fd_out_loop57_0[0];
		fdvt_fd_out_loop57_1_golden = (unsigned int *)&fdvt_fd_out_loop57_1[0];
		fdvt_fd_out_loop57_2_golden = (unsigned int *)&fdvt_fd_out_loop57_2[0];
		fdvt_fd_out_loop57_3_golden = (unsigned int *)&fdvt_fd_out_loop57_3[0];
		fdvt_fd_out_loop58_0_golden = (unsigned int *)&fdvt_fd_out_loop58_0[0];
		fdvt_fd_out_loop58_1_golden = (unsigned int *)&fdvt_fd_out_loop58_1[0];
		fdvt_fd_out_loop59_0_golden = (unsigned int *)&fdvt_fd_out_loop59_0[0];
		fdvt_fd_out_loop59_1_golden = (unsigned int *)&fdvt_fd_out_loop59_1[0];
		fdvt_fd_out_loop60_0_golden = (unsigned int *)&fdvt_fd_out_loop60_0[0];
		fdvt_fd_out_loop60_1_golden = (unsigned int *)&fdvt_fd_out_loop60_1[0];
		fdvt_fd_out_loop61_0_golden = (unsigned int *)&fdvt_fd_out_loop61_0[0];
		fdvt_fd_out_loop62_0_golden = (unsigned int *)&fdvt_fd_out_loop62_0[0];
		fdvt_fd_out_loop62_1_golden = (unsigned int *)&fdvt_fd_out_loop62_1[0];
		fdvt_fd_out_loop63_0_golden = (unsigned int *)&fdvt_fd_out_loop63_0[0];
		fdvt_fd_out_loop63_1_golden = (unsigned int *)&fdvt_fd_out_loop63_1[0];
		fdvt_fd_out_loop64_0_golden = (unsigned int *)&fdvt_fd_out_loop64_0[0];
		fdvt_fd_out_loop65_0_golden = (unsigned int *)&fdvt_fd_out_loop65_0[0];
#endif
#if ATTR_Unit_Test
		// ATTR PART
		attr_frame_R_golden = (unsigned int *)&attr_rgb_img_r_frame01[0];
		attr_frame_G_golden = (unsigned int *)&attr_rgb_img_g_frame01[0];
		attr_frame_B_golden = (unsigned int *)&attr_rgb_img_b_frame01[0];

		attr_frame_R_pyramid0_golden = (unsigned int *)&attr_rs_out_frame01_scale00_r[0];
		attr_frame_G_pyramid0_golden = (unsigned int *)&attr_rs_out_frame01_scale00_g[0];
		attr_frame_B_pyramid0_golden = (unsigned int *)&attr_rs_out_frame01_scale00_b[0];

		attr_fd_out_loop00_0_golden = (unsigned int *)&attr_fd_out_loop00_0[0];
		attr_fd_out_loop00_2_golden = (unsigned int *)&attr_fd_out_loop00_2[0];
		attr_fd_out_loop01_0_golden = (unsigned int *)&attr_fd_out_loop01_0[0];
		attr_fd_out_loop01_2_golden = (unsigned int *)&attr_fd_out_loop01_2[0];
		attr_fd_out_loop02_0_golden = (unsigned int *)&attr_fd_out_loop02_0[0];
		attr_fd_out_loop03_0_golden = (unsigned int *)&attr_fd_out_loop03_0[0];
		attr_fd_out_loop03_1_golden = (unsigned int *)&attr_fd_out_loop03_1[0];
		attr_fd_out_loop03_2_golden = (unsigned int *)&attr_fd_out_loop03_2[0];
		attr_fd_out_loop03_3_golden = (unsigned int *)&attr_fd_out_loop03_3[0];
		attr_fd_out_loop04_0_golden = (unsigned int *)&attr_fd_out_loop04_0[0];
		attr_fd_out_loop04_1_golden = (unsigned int *)&attr_fd_out_loop04_1[0];
		attr_fd_out_loop04_2_golden = (unsigned int *)&attr_fd_out_loop04_2[0];
		attr_fd_out_loop04_3_golden = (unsigned int *)&attr_fd_out_loop04_3[0];
		attr_fd_out_loop05_0_golden = (unsigned int *)&attr_fd_out_loop05_0[0];
		attr_fd_out_loop05_2_golden = (unsigned int *)&attr_fd_out_loop05_2[0];
		attr_fd_out_loop06_0_golden = (unsigned int *)&attr_fd_out_loop06_0[0];
		attr_fd_out_loop06_1_golden = (unsigned int *)&attr_fd_out_loop06_1[0];
		attr_fd_out_loop07_0_golden = (unsigned int *)&attr_fd_out_loop07_0[0];
		attr_fd_out_loop07_2_golden = (unsigned int *)&attr_fd_out_loop07_2[0];
		attr_fd_out_loop08_0_golden = (unsigned int *)&attr_fd_out_loop08_0[0];
		attr_fd_out_loop08_1_golden = (unsigned int *)&attr_fd_out_loop08_1[0];
		attr_fd_out_loop09_0_golden = (unsigned int *)&attr_fd_out_loop09_0[0];
		attr_fd_out_loop10_0_golden = (unsigned int *)&attr_fd_out_loop10_0[0];
		attr_fd_out_loop11_0_golden = (unsigned int *)&attr_fd_out_loop11_0[0];
		attr_fd_out_loop12_0_golden = (unsigned int *)&attr_fd_out_loop12_0[0];
		attr_fd_out_loop13_0_golden = (unsigned int *)&attr_fd_out_loop13_0[0];
		attr_fd_out_loop14_0_golden = (unsigned int *)&attr_fd_out_loop14_0[0];
		attr_fd_out_loop15_0_golden = (unsigned int *)&attr_fd_out_loop15_0[0];
		attr_fd_out_loop15_1_golden = (unsigned int *)&attr_fd_out_loop15_1[0];
		attr_fd_out_loop16_0_golden = (unsigned int *)&attr_fd_out_loop16_0[0];
		attr_fd_out_loop17_0_golden = (unsigned int *)&attr_fd_out_loop17_0[0];
#endif
#if POSE_Unit_Test
		// POSE PART
		pose_frame_R_golden = (unsigned int *)&pose_rgb_img_r_frame01[0];
		pose_frame_G_golden = (unsigned int *)&pose_rgb_img_g_frame01[0];
		pose_frame_B_golden = (unsigned int *)&pose_rgb_img_b_frame01[0];

		pose_frame_R_pyramid0_golden = (unsigned int *)&pose_rs_out_frame01_scale00_r[0];
		pose_frame_G_pyramid0_golden = (unsigned int *)&pose_rs_out_frame01_scale00_g[0];
		pose_frame_B_pyramid0_golden = (unsigned int *)&pose_rs_out_frame01_scale00_b[0];

		pose_fd_out_loop00_0_golden = (unsigned int *)&pose_fd_out_loop00_0[0];
		pose_fd_out_loop00_2_golden = (unsigned int *)&pose_fd_out_loop00_2[0];
		pose_fd_out_loop01_0_golden = (unsigned int *)&pose_fd_out_loop01_0[0];
		pose_fd_out_loop01_2_golden = (unsigned int *)&pose_fd_out_loop01_2[0];
		pose_fd_out_loop02_0_golden = (unsigned int *)&pose_fd_out_loop02_0[0];
		pose_fd_out_loop03_0_golden = (unsigned int *)&pose_fd_out_loop03_0[0];
		pose_fd_out_loop03_1_golden = (unsigned int *)&pose_fd_out_loop03_1[0];
		pose_fd_out_loop03_2_golden = (unsigned int *)&pose_fd_out_loop03_2[0];
		pose_fd_out_loop03_3_golden = (unsigned int *)&pose_fd_out_loop03_3[0];
		pose_fd_out_loop04_0_golden = (unsigned int *)&pose_fd_out_loop04_0[0];
		pose_fd_out_loop04_1_golden = (unsigned int *)&pose_fd_out_loop04_1[0];
		pose_fd_out_loop04_2_golden = (unsigned int *)&pose_fd_out_loop04_2[0];
		pose_fd_out_loop04_3_golden = (unsigned int *)&pose_fd_out_loop04_3[0];
		pose_fd_out_loop05_0_golden = (unsigned int *)&pose_fd_out_loop05_0[0];
		pose_fd_out_loop05_2_golden = (unsigned int *)&pose_fd_out_loop05_2[0];
		pose_fd_out_loop06_0_golden = (unsigned int *)&pose_fd_out_loop06_0[0];
		pose_fd_out_loop06_1_golden = (unsigned int *)&pose_fd_out_loop06_1[0];
		pose_fd_out_loop07_0_golden = (unsigned int *)&pose_fd_out_loop07_0[0];
		pose_fd_out_loop07_2_golden = (unsigned int *)&pose_fd_out_loop07_2[0];
		pose_fd_out_loop08_0_golden = (unsigned int *)&pose_fd_out_loop08_0[0];
		pose_fd_out_loop08_1_golden = (unsigned int *)&pose_fd_out_loop08_1[0];
		pose_fd_out_loop09_0_golden = (unsigned int *)&pose_fd_out_loop09_0[0];
		pose_fd_out_loop10_0_golden = (unsigned int *)&pose_fd_out_loop10_0[0];
		pose_fd_out_loop11_0_golden = (unsigned int *)&pose_fd_out_loop11_0[0];
		pose_fd_out_loop12_0_golden = (unsigned int *)&pose_fd_out_loop12_0[0];
		pose_fd_out_loop13_0_golden = (unsigned int *)&pose_fd_out_loop13_0[0];
		pose_fd_out_loop14_0_golden = (unsigned int *)&pose_fd_out_loop14_0[0];
		pose_fd_out_loop15_0_golden = (unsigned int *)&pose_fd_out_loop15_0[0];
		pose_fd_out_loop15_1_golden = (unsigned int *)&pose_fd_out_loop15_1[0];
		pose_fd_out_loop16_0_golden = (unsigned int *)&pose_fd_out_loop16_0[0];
		pose_fd_out_loop17_0_golden = (unsigned int *)&pose_fd_out_loop17_0[0];
#endif
	}
}

void FDVT_allocateFDDMABuffer()
{
    MUINT64 *currentVA = NULL, *nextVA = NULL;
    MUINT32 *currentPA = NULL, *nextPA = NULL;
    MUINT64 *currentResultVA = NULL;
    MUINT32 *currentResultPA = NULL;
    MUINT8 i=0, j=0;
    MBOOL first_alloc_WDMA_WRA_buffer = MFALSE;

    g_FdvtImem_Size = fdvt_fd_DMA_MAX_size;
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_FD_DMA_hw.phyAddr, g_isFDVTSecure);
    Imem_FD_DMA_hw.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_FD_DMA_hw.memID=g_FdvtImem_MemID;
    Imem_FD_DMA_hw.size=g_FdvtImem_Size;

    g_FdvtImem_Size = fdvt_fd_DMA_Result_MAX_size;
    FDVT_Imem_alloc(g_FdvtImem_Size, &g_FdvtImem_MemID, &g_FdvtImem_pLogVir, &Imem_FD_DMA_Result_hw.phyAddr, 0);
    Imem_FD_DMA_Result_hw.virtAddr=(MUINTPTR)g_FdvtImem_pLogVir;
    Imem_FD_DMA_Result_hw.memID=g_FdvtImem_MemID;
    Imem_FD_DMA_Result_hw.size=g_FdvtImem_Size;
    currentResultPA = (MUINT32*)Imem_FD_DMA_Result_hw.phyAddr;
    currentResultVA = (MUINT64*)Imem_FD_DMA_Result_hw.virtAddr;

    // FD mode
    for(i=0; i < fdvt_fd_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(output_WDMA_WRA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;

	    	    if(!first_alloc_WDMA_WRA_buffer)
	    	    {
				    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] = (MUINT32*)Imem_FD_DMA_hw.phyAddr;
				    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] = (MUINT64*)Imem_FD_DMA_hw.virtAddr;
				    first_alloc_WDMA_WRA_buffer = MTRUE;
                    nextPA = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] + output_WDMA_WRA_buffer_size[i][j]/4;
                    nextVA = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] + output_WDMA_WRA_buffer_size[i][j]/8;
	    	    }
	    	    else
	    	    {
                    //if ((i == 19) || (i == 39) || (i == 65) && (j == 0))
                    //{
                    //    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] = currentResultPA;
                    //    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] = currentResultVA;
                    //    currentResultPA = currentResultPA + output_WDMA_WRA_buffer_size[i][j]/4;
                    //    currentResultVA = currentResultVA + output_WDMA_WRA_buffer_size[i][j]/8;
                    //    nextPA = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] + output_WDMA_WRA_buffer_size[i][j]/4;
                    //    nextVA = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] + output_WDMA_WRA_buffer_size[i][j]/8;
                    //}
                    //else
                    //{
				        g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] = currentPA;
				        g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] = currentVA;
                        nextPA = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] + output_WDMA_WRA_buffer_size[i][j]/4;
                        nextVA = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] + output_WDMA_WRA_buffer_size[i][j]/8;
                    //}
	    	    }
	    	}
	    }
    }

    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[19][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[19][0] = currentResultVA;
    currentResultPA = currentResultPA + output_WDMA_WRA_buffer_size[19][0]/4;
    currentResultVA = currentResultVA + output_WDMA_WRA_buffer_size[19][0]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[39][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[39][0] = currentResultVA;
    currentResultPA = currentResultPA + output_WDMA_WRA_buffer_size[39][0]/4;
    currentResultVA = currentResultVA + output_WDMA_WRA_buffer_size[39][0]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[65][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[65][0] = currentResultVA;
    currentResultPA = currentResultPA + output_WDMA_WRA_buffer_size[65][0]/4;
    currentResultVA = currentResultVA + output_WDMA_WRA_buffer_size[65][0]/8;

    // special config
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][0] + output_WDMA_WRA_buffer_size[16][0]/4 + output_WDMA_WRA_buffer_size[16][2]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][0] + output_WDMA_WRA_buffer_size[16][0]/8 + output_WDMA_WRA_buffer_size[16][2]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][0] + out_xsize_plus_1[16]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][0] + out_xsize_plus_1[16]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[16][1] + out_xsize_plus_1[16]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][1] + out_xsize_plus_1[16]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[17][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[17][0] + out_xsize_plus_1[17]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[17][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[17][0] + out_xsize_plus_1[17]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[18][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[18][0] + out_xsize_plus_1[18]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[18][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[18][0] + out_xsize_plus_1[18]/8;

    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][0] + output_WDMA_WRA_buffer_size[36][0]/4 + output_WDMA_WRA_buffer_size[36][2]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][0] + output_WDMA_WRA_buffer_size[36][0]/8 + output_WDMA_WRA_buffer_size[36][2]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][0] + 1*out_xsize_plus_1[36]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][0] + 1*out_xsize_plus_1[36]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[36][1] + 1*out_xsize_plus_1[36]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][1] + 1*out_xsize_plus_1[36]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[37][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[37][0] + 1*out_xsize_plus_1[37]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[37][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[37][0] + 1*out_xsize_plus_1[37]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[38][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[38][0] + 1*out_xsize_plus_1[38]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[38][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[38][0] + 1*out_xsize_plus_1[38]/8;

    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][0] + output_WDMA_WRA_buffer_size[56][0]/4 + output_WDMA_WRA_buffer_size[56][2]/4 + output_WDMA_WRA_buffer_size[57][0]/4 + output_WDMA_WRA_buffer_size[57][2]/4 + output_WDMA_WRA_buffer_size[58][0]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0] + output_WDMA_WRA_buffer_size[56][0]/8 + output_WDMA_WRA_buffer_size[56][2]/8 + output_WDMA_WRA_buffer_size[57][0]/8 + output_WDMA_WRA_buffer_size[57][2]/8 + output_WDMA_WRA_buffer_size[58][0]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][0] + 1*out_xsize_plus_1[56]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0] + 1*out_xsize_plus_1[56]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][1] + 1*out_xsize_plus_1[56]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1] + 1*out_xsize_plus_1[56]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[57][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][0] + 2*out_xsize_plus_1[57]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0] + 2*out_xsize_plus_1[57]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[57][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][1] + 2*out_xsize_plus_1[57]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1] + 2*out_xsize_plus_1[57]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[57][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][0] + 3*out_xsize_plus_1[57]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][2] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0] + 3*out_xsize_plus_1[57]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[57][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][1] + 3*out_xsize_plus_1[57]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][3] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1] + 3*out_xsize_plus_1[57]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[58][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][0] + 4*out_xsize_plus_1[58]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[58][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0] + 4*out_xsize_plus_1[58]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[58][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[56][1] + 4*out_xsize_plus_1[58]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[58][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1] + 4*out_xsize_plus_1[58]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[59][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[59][0] + 1*out_xsize_plus_1[59]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][0] + 1*out_xsize_plus_1[59]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[60][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[59][0] + 2*out_xsize_plus_1[60]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[60][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][0] + 2*out_xsize_plus_1[60]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[60][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[59][0] + 3*out_xsize_plus_1[60]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[60][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][0] + 3*out_xsize_plus_1[60]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[61][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[59][0] + 4*out_xsize_plus_1[61]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[61][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][0] + 4*out_xsize_plus_1[61]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[62][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[62][0] + 1*out_xsize_plus_1[62]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][0] + 1*out_xsize_plus_1[62]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[63][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[62][0] + 2*out_xsize_plus_1[63]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[63][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][0] + 2*out_xsize_plus_1[63]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[63][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[62][0] + 3*out_xsize_plus_1[63]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[63][1] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][0] + 3*out_xsize_plus_1[63]/8;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[64][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[62][0] + 4*out_xsize_plus_1[64]/4;
    g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[64][0] = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][0] + 4*out_xsize_plus_1[64]/8;

    for(i=0; i < fdvt_fd_loop_num; i++)
    {
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(kernel_RDMA_RA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;
	    	    g_FdDrv_Fd_DMA_Para->fd_kernel_PA[i][j] = currentPA;
	    	    g_FdDrv_Fd_DMA_Para->fd_kernel_VA[i][j] = currentVA;
	    	    nextPA = g_FdDrv_Fd_DMA_Para->fd_kernel_PA[i][j] + kernel_RDMA_RA_buffer_size[i][j]/4;
	    	    nextVA = g_FdDrv_Fd_DMA_Para->fd_kernel_VA[i][j] + kernel_RDMA_RA_buffer_size[i][j]/8;
	    	}
	    }
    }

    // attribute mode
    for(i=0; i < fdvt_attr_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(attr_output_WDMA_WRA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;

	    	    if((i == fdvt_race_output_regression || i == fdvt_gender_output_regression) && (j == 0))
	    	    {
                    g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] = currentPA;
                    g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[i][j] = currentVA;
                    //currentResultPA = currentResultPA + attr_output_WDMA_WRA_buffer_size[i][j]*10/4;
                    //currentResultVA = currentResultVA + attr_output_WDMA_WRA_buffer_size[i][j]*10/8;
	    	        nextPA = g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] + (attr_output_WDMA_WRA_buffer_size[i][j]*10)/4;
	    	        nextVA = g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[i][j] + (attr_output_WDMA_WRA_buffer_size[i][j]*10)/8;
	    	    }
	    	    else
	    	    {
                    g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] = currentPA;
                    g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[i][j] = currentVA;
	    	        nextPA = g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] + attr_output_WDMA_WRA_buffer_size[i][j]/4;
	    	        nextVA = g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[i][j] + attr_output_WDMA_WRA_buffer_size[i][j]/8;
	    	    }
	    	}
	    }
    }

    g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[16][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[16][0] = currentResultVA;
    currentResultPA = currentResultPA + attr_output_WDMA_WRA_buffer_size[16][0]*10/4;
    currentResultVA = currentResultVA + attr_output_WDMA_WRA_buffer_size[16][0]*10/8;
    g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[17][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[17][0] = currentResultVA;
    currentResultPA = currentResultPA + attr_output_WDMA_WRA_buffer_size[17][0]*10/4;
    currentResultVA = currentResultVA + attr_output_WDMA_WRA_buffer_size[17][0]*10/8;

    //[loop 16/17] race/gender result : need to prepare 10 buffers to store 10 times result
    g_FdDrv_Fd_DMA_Para->race_out_hw_PA[0] = g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[fdvt_race_output_regression][0];
    g_FdDrv_Fd_DMA_Para->race_out_hw_VA[0] = g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[fdvt_race_output_regression][0];
    FD_MEMSET(g_FdDrv_Fd_DMA_Para->race_out_hw_VA[0], 0, attr_output_WDMA_WRA_buffer_size[fdvt_race_output_regression][0]);
    g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[0] = g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[fdvt_gender_output_regression][0];
    g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[0] = g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[fdvt_gender_output_regression][0];
    FD_MEMSET(g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[0], 0, attr_output_WDMA_WRA_buffer_size[fdvt_gender_output_regression][0]);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Fd_DMA_Para->race_out_hw_PA[i] = g_FdDrv_Fd_DMA_Para->race_out_hw_PA[i-1] + attr_output_WDMA_WRA_buffer_size[fdvt_race_output_regression][0]/4;
	    g_FdDrv_Fd_DMA_Para->race_out_hw_VA[i] = g_FdDrv_Fd_DMA_Para->race_out_hw_VA[i-1] + attr_output_WDMA_WRA_buffer_size[fdvt_race_output_regression][0]/8;
	    FD_MEMSET(g_FdDrv_Fd_DMA_Para->race_out_hw_VA[i], 0, attr_output_WDMA_WRA_buffer_size[fdvt_race_output_regression][0]);
	    g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[i] = g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[i-1] + attr_output_WDMA_WRA_buffer_size[fdvt_gender_output_regression][0]/4;
	    g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[i] = g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[i-1] + attr_output_WDMA_WRA_buffer_size[fdvt_gender_output_regression][0]/8;
	    FD_MEMSET(g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[i], 0, attr_output_WDMA_WRA_buffer_size[fdvt_gender_output_regression][0]);
    }

    for(i=0; i < fdvt_attr_loop_num; i++)
    {
	    for(int j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(attr_kernel_RDMA_RA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;
	    	    g_FdDrv_Fd_DMA_Para->attr_kernel_PA[i][j] = currentPA;
	    	    g_FdDrv_Fd_DMA_Para->attr_kernel_VA[i][j] = currentVA;
	    	    nextPA = g_FdDrv_Fd_DMA_Para->attr_kernel_PA[i][j] + attr_kernel_RDMA_RA_buffer_size[i][j]/4;
	    	    nextVA = g_FdDrv_Fd_DMA_Para->attr_kernel_VA[i][j] + attr_kernel_RDMA_RA_buffer_size[i][j]/8;
	    	}
	    }
    }

    // pose mode
    for(i=0; i < fdvt_pose_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	    	if(pose_output_WDMA_WRA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;

	    	    if((i == fdvt_rip_output_regression || i == fdvt_rop_output_regression) && (j == 0))
	    	    {
                    g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] = currentPA;
                    g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[i][j] = currentVA;
                    //currentResultPA = currentResultPA + pose_output_WDMA_WRA_buffer_size[i][j]*10/4;
                    //currentResultVA = currentResultVA + pose_output_WDMA_WRA_buffer_size[i][j]*10/8;
	    	        nextPA = g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] + (pose_output_WDMA_WRA_buffer_size[i][j]*10)/4;
	    	        nextVA = g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[i][j] + (pose_output_WDMA_WRA_buffer_size[i][j]*10)/8;
	    	    }
	    	    else
	    	    {
                    g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] = currentPA;
                    g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[i][j] = currentVA;
	    	        nextPA = g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] + pose_output_WDMA_WRA_buffer_size[i][j]/4;
	    	        nextVA = g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[i][j] + pose_output_WDMA_WRA_buffer_size[i][j]/8;
	    	    }
	    	}
	    }
    }

    g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[16][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[16][0] = currentResultVA;
    currentResultPA = currentResultPA + pose_output_WDMA_WRA_buffer_size[16][0]*10/4;
    currentResultVA = currentResultVA + pose_output_WDMA_WRA_buffer_size[16][0]*10/8;
    g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[17][0] = currentResultPA;
    g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[17][0] = currentResultVA;
    currentResultPA = currentResultPA + pose_output_WDMA_WRA_buffer_size[17][0]*10/4;
    currentResultVA = currentResultVA + pose_output_WDMA_WRA_buffer_size[17][0]*10/8;

    //[loop 16/17] race/gender result : need to prepare 10 buffers to store 10 times result
    g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[0] = g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[fdvt_rip_output_regression][0];
    g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[0] = g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[fdvt_rip_output_regression][0];
    FD_MEMSET(g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[0], 0, pose_output_WDMA_WRA_buffer_size[fdvt_rip_output_regression][0]);
    g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[0] = g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[fdvt_rop_output_regression][0];
    g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[0] = g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[fdvt_rop_output_regression][0];
    FD_MEMSET(g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[0], 0, pose_output_WDMA_WRA_buffer_size[fdvt_rop_output_regression][0]);
    for(i=1; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[i] = g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[i-1] + pose_output_WDMA_WRA_buffer_size[fdvt_rip_output_regression][0]/4;
	    g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[i] = g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[i-1] + pose_output_WDMA_WRA_buffer_size[fdvt_rip_output_regression][0]/8;
	    FD_MEMSET(g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[i], 0, pose_output_WDMA_WRA_buffer_size[fdvt_rip_output_regression][0]);
	    g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[i] = g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[i-1] + pose_output_WDMA_WRA_buffer_size[fdvt_rop_output_regression][0]/4;
	    g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[i] = g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[i-1] + pose_output_WDMA_WRA_buffer_size[fdvt_rop_output_regression][0]/8;
	    FD_MEMSET(g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[i], 0, pose_output_WDMA_WRA_buffer_size[fdvt_rop_output_regression][0]);
    }

    for(i=0; i < fdvt_pose_loop_num; i++)
    {
	    for(int j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	    	if(pose_kernel_RDMA_RA_buffer_en[i][j] == 1)
	    	{
	    	    currentPA = nextPA;
	    	    currentVA = nextVA;
	    	    g_FdDrv_Fd_DMA_Para->pose_kernel_PA[i][j] = currentPA;
	    	    g_FdDrv_Fd_DMA_Para->pose_kernel_VA[i][j] = currentVA;
	    	    nextPA = g_FdDrv_Fd_DMA_Para->pose_kernel_PA[i][j] + pose_kernel_RDMA_RA_buffer_size[i][j]/4;
	    	    nextVA = g_FdDrv_Fd_DMA_Para->pose_kernel_VA[i][j] + pose_kernel_RDMA_RA_buffer_size[i][j]/8;
	    	}
	    }
    }
}

void FDVT_logBufInfo()
{
	MUINT8 i = 0;
	LOG_INF("fdmode_fdvt_yuv2rgb_config:  0x%x, fdmode_fdvt_yuv2rgb_config_size: %d", g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, fdvt_fdmode_yuv2rgb_config_size);
	LOG_INF("fdmode_fdvt_rs_config:       0x%x, fdmode_fdvt_rs_config_size:      %d", g_FdDrv_Para->FDMODE_RS_Config_VA, fdvt_fdmode_rs_config_size);
	LOG_INF("fdmode_fdvt_fd_config:       0x%x, fdmode_fdvt_fd_config_size:      %d", g_FdDrv_Para->FDMODE_FD_Config_VA, fdvt_fdmode_fd_config_size);

	for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
	{
	    LOG_INF("attrmode_fdvt_yuv2rgb_config[%d]:  0x%x, attrmode_fdvt_yuv2rgb_config_size: %d", i, g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i], fdvt_attrmode_yuv2rgb_config_size);
	    LOG_INF("attrmode_fdvt_rs_config[%d]:       0x%x, attrmode_fdvt_rs_config_size:      %d", i, g_FdDrv_Para->ATTRMODE_RS_Config_VA[i], fdvt_attrmode_rs_config_size);
	    LOG_INF("attrmode_fdvt_fd_config[%d]:       0x%x, attrmode_fdvt_fd_config_size:      %d", i, g_FdDrv_Para->ATTRMODE_FD_Config_VA[i], fdvt_attrmode_fd_config_size);
	}

	for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
	{
	    LOG_INF("posemode_fdvt_yuv2rgb_config[%d]:  0x%x, posemode_fdvt_yuv2rgb_config_size: %d", i, g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i], fdvt_posemode_yuv2rgb_config_size);
	    LOG_INF("posemode_fdvt_rs_config[%d]:       0x%x, posemode_fdvt_rs_config_size:      %d", i, g_FdDrv_Para->POSEMODE_RS_Config_VA[i], fdvt_posemode_rs_config_size);
	    LOG_INF("posemode_fdvt_fd_config[%d]:       0x%x, posemode_fdvt_fd_config_size:      %d", i, g_FdDrv_Para->POSEMODE_FD_Config_VA[i], fdvt_posemode_fd_config_size);
	}

	LOG_INF("fdvt_frame_R: 0x%x, fdvt_frame_R_size: %d", g_FdDrv_Para->YUV2RGB_R_Result_VA, fdvt_frame_R_size);
	LOG_INF("fdvt_frame_G: 0x%x, fdvt_frame_G_size: %d", g_FdDrv_Para->YUV2RGB_G_Result_VA, fdvt_frame_G_size);
	LOG_INF("fdvt_frame_B: 0x%x, fdvt_frame_B_size: %d", g_FdDrv_Para->YUV2RGB_B_Result_VA, fdvt_frame_B_size);
	LOG_INF("fdvt_frame_R_pyramid0: 0x%x, fdvt_frame_R_pyramid0_size: %d", g_FdDrv_Para->RS_Pyramid0_R_Result_VA, fdvt_rs_pyramid0_out_size);
	LOG_INF("fdvt_frame_G_pyramid0: 0x%x, fdvt_frame_G_pyramid0_size: %d", g_FdDrv_Para->RS_Pyramid0_G_Result_VA, fdvt_rs_pyramid0_out_size);
	LOG_INF("fdvt_frame_B_pyramid0: 0x%x, fdvt_frame_B_pyramid0_size: %d", g_FdDrv_Para->RS_Pyramid0_B_Result_VA, fdvt_rs_pyramid0_out_size);
	LOG_INF("fdvt_frame_R_pyramid1: 0x%x, fdvt_frame_R_pyramid1_size: %d", g_FdDrv_Para->RS_Pyramid1_R_Result_VA, fdvt_rs_pyramid1_out_size);
	LOG_INF("fdvt_frame_G_pyramid1: 0x%x, fdvt_frame_G_pyramid1_size: %d", g_FdDrv_Para->RS_Pyramid1_G_Result_VA, fdvt_rs_pyramid1_out_size);
	LOG_INF("fdvt_frame_B_pyramid1: 0x%x, fdvt_frame_B_pyramid1_size: %d", g_FdDrv_Para->RS_Pyramid1_B_Result_VA, fdvt_rs_pyramid1_out_size);
	LOG_INF("fdvt_frame_R_pyramid2: 0x%x, fdvt_frame_R_pyramid2_size: %d", g_FdDrv_Para->RS_Pyramid2_R_Result_VA, fdvt_rs_pyramid1_out_size);
	LOG_INF("fdvt_frame_G_pyramid2: 0x%x, fdvt_frame_G_pyramid2_size: %d", g_FdDrv_Para->RS_Pyramid2_G_Result_VA, fdvt_rs_pyramid1_out_size);
	LOG_INF("fdvt_frame_B_pyramid2: 0x%x, fdvt_frame_B_pyramid2_size: %d", g_FdDrv_Para->RS_Pyramid2_B_Result_VA, fdvt_rs_pyramid1_out_size);

	LOG_INF("YUV2RGB_R_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff));
	LOG_INF("YUV2RGB_G_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff));
	LOG_INF("YUV2RGB_B_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid0_R_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid0_G_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid0_B_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid1_R_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_R_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid1_G_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_G_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid1_B_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_B_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid2_R_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_R_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid2_G_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_G_Result_PA & 0x00000000ffffffff));
	LOG_INF("RS_Pyramid2_B_Result_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_B_Result_PA & 0x00000000ffffffff));

	LOG_INF("fd_out_hw_19_0_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[19][0] & 0x00000000ffffffff));
	LOG_INF("fd_out_hw_39_0_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[39][0] & 0x00000000ffffffff));
	LOG_INF("fd_out_hw_65_0_PA: 0x%x", (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[65][0] & 0x00000000ffffffff));

	for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
	{
	    LOG_INF("[race]attr_out_hw_16_0_PA[%d]:  0x%x", i, (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->race_out_hw_PA[i] & 0x00000000ffffffff));
	    LOG_INF("[gender]attr_out_hw_17_0_PA[%d]:  0x%x", i, (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[i] & 0x00000000ffffffff));
	}

	for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
	{
	    LOG_INF("[rip]pose_out_hw_16_0_PA[%d]:  0x%x", i, (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[i] & 0x00000000ffffffff));
	    LOG_INF("[rop]pose_out_hw_17_0_PA[%d]:  0x%x", i, (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[i] & 0x00000000ffffffff));
	}
}

void FDVT_FreeMem_DramBuffer()
{
    FDVT_Imem_free((MUINT8 *)Imem_RS_ConfigData.virtAddr, Imem_RS_ConfigData.phyAddr, Imem_RS_ConfigData.size, Imem_RS_ConfigData.memID,g_isFDVTSecure);
    FDVT_Imem_free((MUINT8 *)Imem_FD_ConfigData.virtAddr, Imem_FD_ConfigData.phyAddr, Imem_FD_ConfigData.size, Imem_FD_ConfigData.memID,g_isFDVTSecure);
    FDVT_Imem_free((MUINT8 *)Imem_YUV2RGB_ConfigData.virtAddr, Imem_YUV2RGB_ConfigData.phyAddr, Imem_YUV2RGB_ConfigData.size, Imem_YUV2RGB_ConfigData.memID,g_isFDVTSecure);
}

void FDVT_FreeMem_OutputBuffer()
{
    FDVT_Imem_free((MUINT8 *)Imem_YUV2RGB_Outout_hw.virtAddr, Imem_YUV2RGB_Outout_hw.phyAddr, Imem_YUV2RGB_Outout_hw.size, Imem_YUV2RGB_Outout_hw.memID, g_isFDVTSecure);
    FDVT_Imem_free((MUINT8 *)Imem_RS_Output_hw.virtAddr, Imem_RS_Output_hw.phyAddr, Imem_RS_Output_hw.size, Imem_RS_Output_hw.memID, g_isFDVTSecure);
}

void FDVT_FreeMem_FDDMABuffer()
{
    FDVT_Imem_free((MUINT8 *)Imem_FD_DMA_hw.virtAddr, Imem_FD_DMA_hw.phyAddr, Imem_FD_DMA_hw.size, Imem_FD_DMA_hw.memID, g_isFDVTSecure);
    FDVT_Imem_free((MUINT8 *)Imem_FD_DMA_Result_hw.virtAddr, Imem_FD_DMA_Result_hw.phyAddr, Imem_FD_DMA_Result_hw.size, Imem_FD_DMA_Result_hw.memID, 0);
}

void FDVT_copyInputDataToBuffer()
{
        MUINT8 i = 0;

        // FDMODE
        memcpy((MUINT8*)g_FdDrv_Para->FDMODE_RS_Config_VA, (MUINT8*)(fdvt_FD_rs_config), sizeof(fdvt_FD_rs_config));
        memcpy((MUINT8*)g_FdDrv_Para->FDMODE_FD_Config_VA, (MUINT8*)(fdvt_FD_fd_config), sizeof(fdvt_FD_fd_config));
        memcpy((MUINT8*)g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, (MUINT8*)(fdvt_FD_yuv2rgb_config), sizeof(fdvt_FD_yuv2rgb_config));

        // Copy kernel channel data
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[0][0], 0, kernel_RDMA_RA_buffer_size[0][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[0][0], (MUINT8*)(fdvt_kernel_bias_loop00_0_frame01), sizeof(fdvt_kernel_bias_loop00_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[0][1], 0, kernel_RDMA_RA_buffer_size[0][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[0][1], (MUINT8*)(fdvt_kernel_bias_loop00_1_frame01), sizeof(fdvt_kernel_bias_loop00_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[1][0], 0, kernel_RDMA_RA_buffer_size[1][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[1][0], (MUINT8*)(fdvt_kernel_bias_loop01_0_frame01), sizeof(fdvt_kernel_bias_loop01_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[1][1], 0, kernel_RDMA_RA_buffer_size[1][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[1][1], (MUINT8*)(fdvt_kernel_bias_loop01_1_frame01), sizeof(fdvt_kernel_bias_loop01_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[2][0], 0, kernel_RDMA_RA_buffer_size[2][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[2][0], (MUINT8*)(fdvt_kernel_bias_loop02_0_frame01), sizeof(fdvt_kernel_bias_loop02_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[2][1], 0, kernel_RDMA_RA_buffer_size[2][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[2][1], (MUINT8*)(fdvt_kernel_bias_loop02_1_frame01), sizeof(fdvt_kernel_bias_loop02_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[3][0], 0, kernel_RDMA_RA_buffer_size[3][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[3][0], (MUINT8*)(fdvt_kernel_bias_loop03_0_frame01), sizeof(fdvt_kernel_bias_loop03_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[3][1], 0, kernel_RDMA_RA_buffer_size[3][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[3][1], (MUINT8*)(fdvt_kernel_bias_loop03_1_frame01), sizeof(fdvt_kernel_bias_loop03_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[4][0], 0, kernel_RDMA_RA_buffer_size[4][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[4][0], (MUINT8*)(fdvt_kernel_bias_loop04_0_frame01), sizeof(fdvt_kernel_bias_loop04_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[4][1], 0, kernel_RDMA_RA_buffer_size[4][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[4][1], (MUINT8*)(fdvt_kernel_bias_loop04_1_frame01), sizeof(fdvt_kernel_bias_loop04_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[5][0], 0, kernel_RDMA_RA_buffer_size[5][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[5][0], (MUINT8*)(fdvt_kernel_bias_loop05_0_frame01), sizeof(fdvt_kernel_bias_loop05_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[5][1], 0, kernel_RDMA_RA_buffer_size[5][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[5][1], (MUINT8*)(fdvt_kernel_bias_loop05_1_frame01), sizeof(fdvt_kernel_bias_loop05_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[6][0], 0, kernel_RDMA_RA_buffer_size[6][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[6][0], (MUINT8*)(fdvt_kernel_bias_loop06_0_frame01), sizeof(fdvt_kernel_bias_loop06_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[6][1], 0, kernel_RDMA_RA_buffer_size[6][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[6][1], (MUINT8*)(fdvt_kernel_bias_loop06_1_frame01), sizeof(fdvt_kernel_bias_loop06_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[7][0], 0, kernel_RDMA_RA_buffer_size[7][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[7][0], (MUINT8*)(fdvt_kernel_bias_loop07_0_frame01), sizeof(fdvt_kernel_bias_loop07_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[7][1], 0, kernel_RDMA_RA_buffer_size[7][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[7][1], (MUINT8*)(fdvt_kernel_bias_loop07_1_frame01), sizeof(fdvt_kernel_bias_loop07_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[8][0], 0, kernel_RDMA_RA_buffer_size[8][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[8][0], (MUINT8*)(fdvt_kernel_bias_loop08_0_frame01), sizeof(fdvt_kernel_bias_loop08_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[8][1], 0, kernel_RDMA_RA_buffer_size[8][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[8][1], (MUINT8*)(fdvt_kernel_bias_loop08_1_frame01), sizeof(fdvt_kernel_bias_loop08_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[9][0], 0, kernel_RDMA_RA_buffer_size[9][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[9][0], (MUINT8*)(fdvt_kernel_bias_loop09_0_frame01), sizeof(fdvt_kernel_bias_loop09_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[9][1], 0, kernel_RDMA_RA_buffer_size[9][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[9][1], (MUINT8*)(fdvt_kernel_bias_loop09_1_frame01), sizeof(fdvt_kernel_bias_loop09_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[10][0], 0, kernel_RDMA_RA_buffer_size[10][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[10][0], (MUINT8*)(fdvt_kernel_bias_loop10_0_frame01), sizeof(fdvt_kernel_bias_loop10_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[10][1], 0, kernel_RDMA_RA_buffer_size[10][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[10][1], (MUINT8*)(fdvt_kernel_bias_loop10_1_frame01), sizeof(fdvt_kernel_bias_loop10_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[11][0], 0, kernel_RDMA_RA_buffer_size[11][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[11][0], (MUINT8*)(fdvt_kernel_bias_loop11_0_frame01), sizeof(fdvt_kernel_bias_loop11_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[11][1], 0, kernel_RDMA_RA_buffer_size[11][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[11][1], (MUINT8*)(fdvt_kernel_bias_loop11_1_frame01), sizeof(fdvt_kernel_bias_loop11_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[12][0], 0, kernel_RDMA_RA_buffer_size[12][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[12][0], (MUINT8*)(fdvt_kernel_bias_loop12_0_frame01), sizeof(fdvt_kernel_bias_loop12_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[12][1], 0, kernel_RDMA_RA_buffer_size[12][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[12][1], (MUINT8*)(fdvt_kernel_bias_loop12_1_frame01), sizeof(fdvt_kernel_bias_loop12_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[13][0], 0, kernel_RDMA_RA_buffer_size[13][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[13][0], (MUINT8*)(fdvt_kernel_bias_loop13_0_frame01), sizeof(fdvt_kernel_bias_loop13_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[13][1], 0, kernel_RDMA_RA_buffer_size[13][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[13][1], (MUINT8*)(fdvt_kernel_bias_loop13_1_frame01), sizeof(fdvt_kernel_bias_loop13_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[14][0], 0, kernel_RDMA_RA_buffer_size[14][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[14][0], (MUINT8*)(fdvt_kernel_bias_loop14_0_frame01), sizeof(fdvt_kernel_bias_loop14_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[14][1], 0, kernel_RDMA_RA_buffer_size[14][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[14][1], (MUINT8*)(fdvt_kernel_bias_loop14_1_frame01), sizeof(fdvt_kernel_bias_loop14_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[15][0], 0, kernel_RDMA_RA_buffer_size[15][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[15][0], (MUINT8*)(fdvt_kernel_bias_loop15_0_frame01), sizeof(fdvt_kernel_bias_loop15_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[15][1], 0, kernel_RDMA_RA_buffer_size[15][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[15][1], (MUINT8*)(fdvt_kernel_bias_loop15_1_frame01), sizeof(fdvt_kernel_bias_loop15_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[16][0], 0, kernel_RDMA_RA_buffer_size[16][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[16][0], (MUINT8*)(fdvt_kernel_bias_loop16_0_frame01), sizeof(fdvt_kernel_bias_loop16_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[16][1], 0, kernel_RDMA_RA_buffer_size[16][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[16][1], (MUINT8*)(fdvt_kernel_bias_loop16_1_frame01), sizeof(fdvt_kernel_bias_loop16_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[17][0], 0, kernel_RDMA_RA_buffer_size[17][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[17][0], (MUINT8*)(fdvt_kernel_bias_loop17_0_frame01), sizeof(fdvt_kernel_bias_loop17_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[17][1], 0, kernel_RDMA_RA_buffer_size[17][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[17][1], (MUINT8*)(fdvt_kernel_bias_loop17_1_frame01), sizeof(fdvt_kernel_bias_loop17_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[18][0], 0, kernel_RDMA_RA_buffer_size[18][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[18][0], (MUINT8*)(fdvt_kernel_bias_loop18_0_frame01), sizeof(fdvt_kernel_bias_loop18_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[18][1], 0, kernel_RDMA_RA_buffer_size[18][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[18][1], (MUINT8*)(fdvt_kernel_bias_loop18_1_frame01), sizeof(fdvt_kernel_bias_loop18_1_frame01));

        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[20][0], 0, kernel_RDMA_RA_buffer_size[20][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[20][0], (MUINT8*)(fdvt_kernel_bias_loop20_0_frame01), sizeof(fdvt_kernel_bias_loop20_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[20][1], 0, kernel_RDMA_RA_buffer_size[20][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[20][1], (MUINT8*)(fdvt_kernel_bias_loop20_1_frame01), sizeof(fdvt_kernel_bias_loop20_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[21][0], 0, kernel_RDMA_RA_buffer_size[21][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[21][0], (MUINT8*)(fdvt_kernel_bias_loop21_0_frame01), sizeof(fdvt_kernel_bias_loop21_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[21][1], 0, kernel_RDMA_RA_buffer_size[21][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[21][1], (MUINT8*)(fdvt_kernel_bias_loop21_1_frame01), sizeof(fdvt_kernel_bias_loop21_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[22][0], 0, kernel_RDMA_RA_buffer_size[22][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[22][0], (MUINT8*)(fdvt_kernel_bias_loop22_0_frame01), sizeof(fdvt_kernel_bias_loop22_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[22][1], 0, kernel_RDMA_RA_buffer_size[22][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[22][1], (MUINT8*)(fdvt_kernel_bias_loop22_1_frame01), sizeof(fdvt_kernel_bias_loop22_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[23][0], 0, kernel_RDMA_RA_buffer_size[23][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[23][0], (MUINT8*)(fdvt_kernel_bias_loop23_0_frame01), sizeof(fdvt_kernel_bias_loop23_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[23][1], 0, kernel_RDMA_RA_buffer_size[23][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[23][1], (MUINT8*)(fdvt_kernel_bias_loop23_1_frame01), sizeof(fdvt_kernel_bias_loop23_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[24][0], 0, kernel_RDMA_RA_buffer_size[24][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[24][0], (MUINT8*)(fdvt_kernel_bias_loop24_0_frame01), sizeof(fdvt_kernel_bias_loop24_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[24][1], 0, kernel_RDMA_RA_buffer_size[24][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[24][1], (MUINT8*)(fdvt_kernel_bias_loop24_1_frame01), sizeof(fdvt_kernel_bias_loop24_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[25][0], 0, kernel_RDMA_RA_buffer_size[25][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[25][0], (MUINT8*)(fdvt_kernel_bias_loop25_0_frame01), sizeof(fdvt_kernel_bias_loop25_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[25][1], 0, kernel_RDMA_RA_buffer_size[25][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[25][1], (MUINT8*)(fdvt_kernel_bias_loop25_1_frame01), sizeof(fdvt_kernel_bias_loop25_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[26][0], 0, kernel_RDMA_RA_buffer_size[26][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[26][0], (MUINT8*)(fdvt_kernel_bias_loop26_0_frame01), sizeof(fdvt_kernel_bias_loop26_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[26][1], 0, kernel_RDMA_RA_buffer_size[26][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[26][1], (MUINT8*)(fdvt_kernel_bias_loop26_1_frame01), sizeof(fdvt_kernel_bias_loop26_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[27][0], 0, kernel_RDMA_RA_buffer_size[27][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[27][0], (MUINT8*)(fdvt_kernel_bias_loop27_0_frame01), sizeof(fdvt_kernel_bias_loop27_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[27][1], 0, kernel_RDMA_RA_buffer_size[27][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[27][1], (MUINT8*)(fdvt_kernel_bias_loop27_1_frame01), sizeof(fdvt_kernel_bias_loop27_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[28][0], 0, kernel_RDMA_RA_buffer_size[28][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[28][0], (MUINT8*)(fdvt_kernel_bias_loop28_0_frame01), sizeof(fdvt_kernel_bias_loop28_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[28][1], 0, kernel_RDMA_RA_buffer_size[28][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[28][1], (MUINT8*)(fdvt_kernel_bias_loop28_1_frame01), sizeof(fdvt_kernel_bias_loop28_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[29][0], 0, kernel_RDMA_RA_buffer_size[29][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[29][0], (MUINT8*)(fdvt_kernel_bias_loop29_0_frame01), sizeof(fdvt_kernel_bias_loop29_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[29][1], 0, kernel_RDMA_RA_buffer_size[29][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[29][1], (MUINT8*)(fdvt_kernel_bias_loop29_1_frame01), sizeof(fdvt_kernel_bias_loop29_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[30][0], 0, kernel_RDMA_RA_buffer_size[30][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[30][0], (MUINT8*)(fdvt_kernel_bias_loop30_0_frame01), sizeof(fdvt_kernel_bias_loop30_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[30][1], 0, kernel_RDMA_RA_buffer_size[30][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[30][1], (MUINT8*)(fdvt_kernel_bias_loop30_1_frame01), sizeof(fdvt_kernel_bias_loop30_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[31][0], 0, kernel_RDMA_RA_buffer_size[31][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[31][0], (MUINT8*)(fdvt_kernel_bias_loop31_0_frame01), sizeof(fdvt_kernel_bias_loop31_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[31][1], 0, kernel_RDMA_RA_buffer_size[31][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[31][1], (MUINT8*)(fdvt_kernel_bias_loop31_1_frame01), sizeof(fdvt_kernel_bias_loop31_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[32][0], 0, kernel_RDMA_RA_buffer_size[32][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[32][0], (MUINT8*)(fdvt_kernel_bias_loop32_0_frame01), sizeof(fdvt_kernel_bias_loop32_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[32][1], 0, kernel_RDMA_RA_buffer_size[32][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[32][1], (MUINT8*)(fdvt_kernel_bias_loop32_1_frame01), sizeof(fdvt_kernel_bias_loop32_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[33][0], 0, kernel_RDMA_RA_buffer_size[33][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[33][0], (MUINT8*)(fdvt_kernel_bias_loop33_0_frame01), sizeof(fdvt_kernel_bias_loop33_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[33][1], 0, kernel_RDMA_RA_buffer_size[33][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[33][1], (MUINT8*)(fdvt_kernel_bias_loop33_1_frame01), sizeof(fdvt_kernel_bias_loop33_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[34][0], 0, kernel_RDMA_RA_buffer_size[34][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[34][0], (MUINT8*)(fdvt_kernel_bias_loop34_0_frame01), sizeof(fdvt_kernel_bias_loop34_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[34][1], 0, kernel_RDMA_RA_buffer_size[34][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[34][1], (MUINT8*)(fdvt_kernel_bias_loop34_1_frame01), sizeof(fdvt_kernel_bias_loop34_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[35][0], 0, kernel_RDMA_RA_buffer_size[35][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[35][0], (MUINT8*)(fdvt_kernel_bias_loop35_0_frame01), sizeof(fdvt_kernel_bias_loop35_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[35][1], 0, kernel_RDMA_RA_buffer_size[35][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[35][1], (MUINT8*)(fdvt_kernel_bias_loop35_1_frame01), sizeof(fdvt_kernel_bias_loop35_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[36][0], 0, kernel_RDMA_RA_buffer_size[36][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[36][0], (MUINT8*)(fdvt_kernel_bias_loop36_0_frame01), sizeof(fdvt_kernel_bias_loop36_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[36][1], 0, kernel_RDMA_RA_buffer_size[36][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[36][1], (MUINT8*)(fdvt_kernel_bias_loop36_1_frame01), sizeof(fdvt_kernel_bias_loop36_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[37][0], 0, kernel_RDMA_RA_buffer_size[37][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[37][0], (MUINT8*)(fdvt_kernel_bias_loop37_0_frame01), sizeof(fdvt_kernel_bias_loop37_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[37][1], 0, kernel_RDMA_RA_buffer_size[37][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[37][1], (MUINT8*)(fdvt_kernel_bias_loop37_1_frame01), sizeof(fdvt_kernel_bias_loop37_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[38][0], 0, kernel_RDMA_RA_buffer_size[38][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[38][0], (MUINT8*)(fdvt_kernel_bias_loop38_0_frame01), sizeof(fdvt_kernel_bias_loop38_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[38][1], 0, kernel_RDMA_RA_buffer_size[38][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[38][1], (MUINT8*)(fdvt_kernel_bias_loop38_1_frame01), sizeof(fdvt_kernel_bias_loop38_1_frame01));

        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[40][0], 0, kernel_RDMA_RA_buffer_size[40][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[40][0], (MUINT8*)(fdvt_kernel_bias_loop40_0_frame01), sizeof(fdvt_kernel_bias_loop40_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[40][1], 0, kernel_RDMA_RA_buffer_size[40][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[40][1], (MUINT8*)(fdvt_kernel_bias_loop40_1_frame01), sizeof(fdvt_kernel_bias_loop40_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[41][0], 0, kernel_RDMA_RA_buffer_size[41][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[41][0], (MUINT8*)(fdvt_kernel_bias_loop41_0_frame01), sizeof(fdvt_kernel_bias_loop41_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[41][1], 0, kernel_RDMA_RA_buffer_size[41][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[41][1], (MUINT8*)(fdvt_kernel_bias_loop41_1_frame01), sizeof(fdvt_kernel_bias_loop41_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[42][0], 0, kernel_RDMA_RA_buffer_size[42][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[42][0], (MUINT8*)(fdvt_kernel_bias_loop42_0_frame01), sizeof(fdvt_kernel_bias_loop42_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[42][1], 0, kernel_RDMA_RA_buffer_size[42][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[42][1], (MUINT8*)(fdvt_kernel_bias_loop42_1_frame01), sizeof(fdvt_kernel_bias_loop42_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[43][0], 0, kernel_RDMA_RA_buffer_size[43][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[43][0], (MUINT8*)(fdvt_kernel_bias_loop43_0_frame01), sizeof(fdvt_kernel_bias_loop43_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[43][1], 0, kernel_RDMA_RA_buffer_size[43][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[43][1], (MUINT8*)(fdvt_kernel_bias_loop43_1_frame01), sizeof(fdvt_kernel_bias_loop43_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[44][0], 0, kernel_RDMA_RA_buffer_size[44][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[44][0], (MUINT8*)(fdvt_kernel_bias_loop44_0_frame01), sizeof(fdvt_kernel_bias_loop44_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[44][1], 0, kernel_RDMA_RA_buffer_size[44][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[44][1], (MUINT8*)(fdvt_kernel_bias_loop44_1_frame01), sizeof(fdvt_kernel_bias_loop44_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[45][0], 0, kernel_RDMA_RA_buffer_size[45][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[45][0], (MUINT8*)(fdvt_kernel_bias_loop45_0_frame01), sizeof(fdvt_kernel_bias_loop45_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[45][1], 0, kernel_RDMA_RA_buffer_size[45][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[45][1], (MUINT8*)(fdvt_kernel_bias_loop45_1_frame01), sizeof(fdvt_kernel_bias_loop45_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[46][0], 0, kernel_RDMA_RA_buffer_size[46][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[46][0], (MUINT8*)(fdvt_kernel_bias_loop46_0_frame01), sizeof(fdvt_kernel_bias_loop46_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[46][1], 0, kernel_RDMA_RA_buffer_size[46][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[46][1], (MUINT8*)(fdvt_kernel_bias_loop46_1_frame01), sizeof(fdvt_kernel_bias_loop46_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[47][0], 0, kernel_RDMA_RA_buffer_size[47][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[47][0], (MUINT8*)(fdvt_kernel_bias_loop47_0_frame01), sizeof(fdvt_kernel_bias_loop47_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[47][1], 0, kernel_RDMA_RA_buffer_size[47][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[47][1], (MUINT8*)(fdvt_kernel_bias_loop47_1_frame01), sizeof(fdvt_kernel_bias_loop47_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[48][0], 0, kernel_RDMA_RA_buffer_size[48][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[48][0], (MUINT8*)(fdvt_kernel_bias_loop48_0_frame01), sizeof(fdvt_kernel_bias_loop48_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[48][1], 0, kernel_RDMA_RA_buffer_size[48][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[48][1], (MUINT8*)(fdvt_kernel_bias_loop48_1_frame01), sizeof(fdvt_kernel_bias_loop48_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[49][0], 0, kernel_RDMA_RA_buffer_size[49][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[49][0], (MUINT8*)(fdvt_kernel_bias_loop49_0_frame01), sizeof(fdvt_kernel_bias_loop49_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[49][1], 0, kernel_RDMA_RA_buffer_size[49][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[49][1], (MUINT8*)(fdvt_kernel_bias_loop49_1_frame01), sizeof(fdvt_kernel_bias_loop49_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[50][0], 0, kernel_RDMA_RA_buffer_size[50][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[50][0], (MUINT8*)(fdvt_kernel_bias_loop50_0_frame01), sizeof(fdvt_kernel_bias_loop50_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[50][1], 0, kernel_RDMA_RA_buffer_size[50][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[50][1], (MUINT8*)(fdvt_kernel_bias_loop50_1_frame01), sizeof(fdvt_kernel_bias_loop50_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[51][0], 0, kernel_RDMA_RA_buffer_size[51][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[51][0], (MUINT8*)(fdvt_kernel_bias_loop51_0_frame01), sizeof(fdvt_kernel_bias_loop51_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[51][1], 0, kernel_RDMA_RA_buffer_size[51][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[51][1], (MUINT8*)(fdvt_kernel_bias_loop51_1_frame01), sizeof(fdvt_kernel_bias_loop51_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[52][0], 0, kernel_RDMA_RA_buffer_size[52][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[52][0], (MUINT8*)(fdvt_kernel_bias_loop52_0_frame01), sizeof(fdvt_kernel_bias_loop52_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[52][1], 0, kernel_RDMA_RA_buffer_size[52][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[52][1], (MUINT8*)(fdvt_kernel_bias_loop52_1_frame01), sizeof(fdvt_kernel_bias_loop52_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[53][0], 0, kernel_RDMA_RA_buffer_size[53][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[53][0], (MUINT8*)(fdvt_kernel_bias_loop53_0_frame01), sizeof(fdvt_kernel_bias_loop53_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[53][1], 0, kernel_RDMA_RA_buffer_size[53][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[53][1], (MUINT8*)(fdvt_kernel_bias_loop53_1_frame01), sizeof(fdvt_kernel_bias_loop53_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[54][0], 0, kernel_RDMA_RA_buffer_size[54][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[54][0], (MUINT8*)(fdvt_kernel_bias_loop54_0_frame01), sizeof(fdvt_kernel_bias_loop54_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[54][1], 0, kernel_RDMA_RA_buffer_size[54][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[54][1], (MUINT8*)(fdvt_kernel_bias_loop54_1_frame01), sizeof(fdvt_kernel_bias_loop54_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[55][0], 0, kernel_RDMA_RA_buffer_size[55][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[55][0], (MUINT8*)(fdvt_kernel_bias_loop55_0_frame01), sizeof(fdvt_kernel_bias_loop55_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[55][1], 0, kernel_RDMA_RA_buffer_size[55][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[55][1], (MUINT8*)(fdvt_kernel_bias_loop55_1_frame01), sizeof(fdvt_kernel_bias_loop55_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[56][0], 0, kernel_RDMA_RA_buffer_size[56][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[56][0], (MUINT8*)(fdvt_kernel_bias_loop56_0_frame01), sizeof(fdvt_kernel_bias_loop56_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[56][1], 0, kernel_RDMA_RA_buffer_size[56][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[56][1], (MUINT8*)(fdvt_kernel_bias_loop56_1_frame01), sizeof(fdvt_kernel_bias_loop56_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[57][0], 0, kernel_RDMA_RA_buffer_size[57][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[57][0], (MUINT8*)(fdvt_kernel_bias_loop57_0_frame01), sizeof(fdvt_kernel_bias_loop57_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[57][1], 0, kernel_RDMA_RA_buffer_size[57][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[57][1], (MUINT8*)(fdvt_kernel_bias_loop57_1_frame01), sizeof(fdvt_kernel_bias_loop57_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[58][0], 0, kernel_RDMA_RA_buffer_size[58][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[58][0], (MUINT8*)(fdvt_kernel_bias_loop58_0_frame01), sizeof(fdvt_kernel_bias_loop58_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[58][1], 0, kernel_RDMA_RA_buffer_size[58][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[58][1], (MUINT8*)(fdvt_kernel_bias_loop58_1_frame01), sizeof(fdvt_kernel_bias_loop58_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[59][0], 0, kernel_RDMA_RA_buffer_size[59][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[59][0], (MUINT8*)(fdvt_kernel_bias_loop59_0_frame01), sizeof(fdvt_kernel_bias_loop59_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[59][1], 0, kernel_RDMA_RA_buffer_size[59][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[59][1], (MUINT8*)(fdvt_kernel_bias_loop59_1_frame01), sizeof(fdvt_kernel_bias_loop59_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[60][0], 0, kernel_RDMA_RA_buffer_size[60][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[60][0], (MUINT8*)(fdvt_kernel_bias_loop60_0_frame01), sizeof(fdvt_kernel_bias_loop60_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[60][1], 0, kernel_RDMA_RA_buffer_size[60][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[60][1], (MUINT8*)(fdvt_kernel_bias_loop60_1_frame01), sizeof(fdvt_kernel_bias_loop60_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[61][0], 0, kernel_RDMA_RA_buffer_size[61][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[61][0], (MUINT8*)(fdvt_kernel_bias_loop61_0_frame01), sizeof(fdvt_kernel_bias_loop61_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[61][1], 0, kernel_RDMA_RA_buffer_size[61][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[61][1], (MUINT8*)(fdvt_kernel_bias_loop61_1_frame01), sizeof(fdvt_kernel_bias_loop61_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[62][0], 0, kernel_RDMA_RA_buffer_size[62][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[62][0], (MUINT8*)(fdvt_kernel_bias_loop62_0_frame01), sizeof(fdvt_kernel_bias_loop62_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[62][1], 0, kernel_RDMA_RA_buffer_size[62][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[62][1], (MUINT8*)(fdvt_kernel_bias_loop62_1_frame01), sizeof(fdvt_kernel_bias_loop62_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[63][0], 0, kernel_RDMA_RA_buffer_size[63][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[63][0], (MUINT8*)(fdvt_kernel_bias_loop63_0_frame01), sizeof(fdvt_kernel_bias_loop63_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[63][1], 0, kernel_RDMA_RA_buffer_size[63][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[63][1], (MUINT8*)(fdvt_kernel_bias_loop63_1_frame01), sizeof(fdvt_kernel_bias_loop63_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[64][0], 0, kernel_RDMA_RA_buffer_size[64][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[64][0], (MUINT8*)(fdvt_kernel_bias_loop64_0_frame01), sizeof(fdvt_kernel_bias_loop64_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->fd_kernel_VA[64][1], 0, kernel_RDMA_RA_buffer_size[64][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->fd_kernel_VA[64][1], (MUINT8*)(fdvt_kernel_bias_loop64_1_frame01), sizeof(fdvt_kernel_bias_loop64_1_frame01));

        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_R_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_G_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_B_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_R_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_G_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_B_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn0_loop_num][0], 0, fdvt_fd_result_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn1_loop_num][0], 0, fdvt_fd_result_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn2_loop_num][0], 0, fdvt_fd_result_size);

        // ATTRIBUTE MODE
        for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
        {
	        memcpy((MUINT8*)g_FdDrv_Para->ATTRMODE_RS_Config_VA[i], (MUINT8*)(fdvt_ATTR_rs_config), sizeof(fdvt_ATTR_rs_config));
	        memcpy((MUINT8*)g_FdDrv_Para->ATTRMODE_FD_Config_VA[i], (MUINT8*)(fdvt_ATTR_fd_config), sizeof(fdvt_ATTR_fd_config));
	        memcpy((MUINT8*)g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i], (MUINT8*)(fdvt_ATTR_yuv2rgb_config), sizeof(fdvt_ATTR_yuv2rgb_config));
        }
        // Copy kernel channel data
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[0][0], 0, attr_kernel_RDMA_RA_buffer_size[0][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[0][0], (MUINT8*)(attr_kernel_bias_loop00_0_frame01), sizeof(attr_kernel_bias_loop00_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[0][1], 0, attr_kernel_RDMA_RA_buffer_size[0][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[0][1], (MUINT8*)(attr_kernel_bias_loop00_1_frame01), sizeof(attr_kernel_bias_loop00_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[1][0], 0, attr_kernel_RDMA_RA_buffer_size[1][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[1][0], (MUINT8*)(attr_kernel_bias_loop01_0_frame01), sizeof(attr_kernel_bias_loop01_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[1][1], 0, attr_kernel_RDMA_RA_buffer_size[1][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[1][1], (MUINT8*)(attr_kernel_bias_loop01_1_frame01), sizeof(attr_kernel_bias_loop01_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[2][0], 0, attr_kernel_RDMA_RA_buffer_size[2][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[2][0], (MUINT8*)(attr_kernel_bias_loop02_0_frame01), sizeof(attr_kernel_bias_loop02_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[2][1], 0, attr_kernel_RDMA_RA_buffer_size[2][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[2][1], (MUINT8*)(attr_kernel_bias_loop02_1_frame01), sizeof(attr_kernel_bias_loop02_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[3][0], 0, attr_kernel_RDMA_RA_buffer_size[3][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[3][0], (MUINT8*)(attr_kernel_bias_loop03_0_frame01), sizeof(attr_kernel_bias_loop03_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[3][1], 0, attr_kernel_RDMA_RA_buffer_size[3][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[3][1], (MUINT8*)(attr_kernel_bias_loop03_1_frame01), sizeof(attr_kernel_bias_loop03_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[4][0], 0, attr_kernel_RDMA_RA_buffer_size[4][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[4][0], (MUINT8*)(attr_kernel_bias_loop04_0_frame01), sizeof(attr_kernel_bias_loop04_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[4][1], 0, attr_kernel_RDMA_RA_buffer_size[4][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[4][1], (MUINT8*)(attr_kernel_bias_loop04_1_frame01), sizeof(attr_kernel_bias_loop04_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[5][0], 0, attr_kernel_RDMA_RA_buffer_size[5][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[5][0], (MUINT8*)(attr_kernel_bias_loop05_0_frame01), sizeof(attr_kernel_bias_loop05_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[5][1], 0, attr_kernel_RDMA_RA_buffer_size[5][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[5][1], (MUINT8*)(attr_kernel_bias_loop05_1_frame01), sizeof(attr_kernel_bias_loop05_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[6][0], 0, attr_kernel_RDMA_RA_buffer_size[6][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[6][0], (MUINT8*)(attr_kernel_bias_loop06_0_frame01), sizeof(attr_kernel_bias_loop06_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[6][1], 0, attr_kernel_RDMA_RA_buffer_size[6][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[6][1], (MUINT8*)(attr_kernel_bias_loop06_1_frame01), sizeof(attr_kernel_bias_loop06_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[7][0], 0, attr_kernel_RDMA_RA_buffer_size[7][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[7][0], (MUINT8*)(attr_kernel_bias_loop07_0_frame01), sizeof(attr_kernel_bias_loop07_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[7][1], 0, attr_kernel_RDMA_RA_buffer_size[7][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[7][1], (MUINT8*)(attr_kernel_bias_loop07_1_frame01), sizeof(attr_kernel_bias_loop07_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[8][0], 0, attr_kernel_RDMA_RA_buffer_size[8][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[8][0], (MUINT8*)(attr_kernel_bias_loop08_0_frame01), sizeof(attr_kernel_bias_loop08_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[8][1], 0, attr_kernel_RDMA_RA_buffer_size[8][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[8][1], (MUINT8*)(attr_kernel_bias_loop08_1_frame01), sizeof(attr_kernel_bias_loop08_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[9][0], 0, attr_kernel_RDMA_RA_buffer_size[9][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[9][0], (MUINT8*)(attr_kernel_bias_loop09_0_frame01), sizeof(attr_kernel_bias_loop09_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[9][1], 0, attr_kernel_RDMA_RA_buffer_size[9][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[9][1], (MUINT8*)(attr_kernel_bias_loop09_1_frame01), sizeof(attr_kernel_bias_loop09_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[10][0], 0, attr_kernel_RDMA_RA_buffer_size[10][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[10][0], (MUINT8*)(attr_kernel_bias_loop10_0_frame01), sizeof(attr_kernel_bias_loop10_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[10][1], 0, attr_kernel_RDMA_RA_buffer_size[10][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[10][1], (MUINT8*)(attr_kernel_bias_loop10_1_frame01), sizeof(attr_kernel_bias_loop10_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[11][0], 0, attr_kernel_RDMA_RA_buffer_size[11][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[11][0], (MUINT8*)(attr_kernel_bias_loop11_0_frame01), sizeof(attr_kernel_bias_loop11_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[11][1], 0, attr_kernel_RDMA_RA_buffer_size[11][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[11][1], (MUINT8*)(attr_kernel_bias_loop11_1_frame01), sizeof(attr_kernel_bias_loop11_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[12][0], 0, attr_kernel_RDMA_RA_buffer_size[12][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[12][0], (MUINT8*)(attr_kernel_bias_loop12_0_frame01), sizeof(attr_kernel_bias_loop12_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[12][1], 0, attr_kernel_RDMA_RA_buffer_size[12][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[12][1], (MUINT8*)(attr_kernel_bias_loop12_1_frame01), sizeof(attr_kernel_bias_loop12_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[13][0], 0, attr_kernel_RDMA_RA_buffer_size[13][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[13][0], (MUINT8*)(attr_kernel_bias_loop13_0_frame01), sizeof(attr_kernel_bias_loop13_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[13][1], 0, attr_kernel_RDMA_RA_buffer_size[13][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[13][1], (MUINT8*)(attr_kernel_bias_loop13_1_frame01), sizeof(attr_kernel_bias_loop13_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[14][0], 0, attr_kernel_RDMA_RA_buffer_size[14][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[14][0], (MUINT8*)(attr_kernel_bias_loop14_0_frame01), sizeof(attr_kernel_bias_loop14_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[14][1], 0, attr_kernel_RDMA_RA_buffer_size[14][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[14][1], (MUINT8*)(attr_kernel_bias_loop14_1_frame01), sizeof(attr_kernel_bias_loop14_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[15][0], 0, attr_kernel_RDMA_RA_buffer_size[15][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[15][0], (MUINT8*)(attr_kernel_bias_loop15_0_frame01), sizeof(attr_kernel_bias_loop15_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[15][1], 0, attr_kernel_RDMA_RA_buffer_size[15][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[15][1], (MUINT8*)(attr_kernel_bias_loop15_1_frame01), sizeof(attr_kernel_bias_loop15_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[16][0], 0, attr_kernel_RDMA_RA_buffer_size[16][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[16][0], (MUINT8*)(attr_kernel_bias_loop16_0_frame01), sizeof(attr_kernel_bias_loop16_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[16][1], 0, attr_kernel_RDMA_RA_buffer_size[16][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[16][1], (MUINT8*)(attr_kernel_bias_loop16_1_frame01), sizeof(attr_kernel_bias_loop16_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[17][0], 0, attr_kernel_RDMA_RA_buffer_size[17][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[17][0], (MUINT8*)(attr_kernel_bias_loop17_0_frame01), sizeof(attr_kernel_bias_loop17_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->attr_kernel_VA[17][1], 0, attr_kernel_RDMA_RA_buffer_size[17][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->attr_kernel_VA[17][1], (MUINT8*)(attr_kernel_bias_loop17_1_frame01), sizeof(attr_kernel_bias_loop17_1_frame01));
/*
        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
*/

        // POSEMODE
        for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
        {
	        memcpy((MUINT8*)g_FdDrv_Para->POSEMODE_RS_Config_VA[i], (MUINT8*)(fdvt_POSE_rs_config), sizeof(fdvt_POSE_rs_config));
	        memcpy((MUINT8*)g_FdDrv_Para->POSEMODE_FD_Config_VA[i], (MUINT8*)(fdvt_POSE_fd_config), sizeof(fdvt_POSE_fd_config));
	        memcpy((MUINT8*)g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i], (MUINT8*)(fdvt_POSE_yuv2rgb_config), sizeof(fdvt_POSE_yuv2rgb_config));
        }

        // Copy kernel channel data
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[0][0], 0, pose_kernel_RDMA_RA_buffer_size[0][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[0][0], (MUINT8*)(pose_kernel_bias_loop00_0_frame01), sizeof(pose_kernel_bias_loop00_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[0][1], 0, pose_kernel_RDMA_RA_buffer_size[0][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[0][1], (MUINT8*)(pose_kernel_bias_loop00_1_frame01), sizeof(pose_kernel_bias_loop00_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[1][0], 0, pose_kernel_RDMA_RA_buffer_size[1][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[1][0], (MUINT8*)(pose_kernel_bias_loop01_0_frame01), sizeof(pose_kernel_bias_loop01_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[1][1], 0, pose_kernel_RDMA_RA_buffer_size[1][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[1][1], (MUINT8*)(pose_kernel_bias_loop01_1_frame01), sizeof(pose_kernel_bias_loop01_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[2][0], 0, pose_kernel_RDMA_RA_buffer_size[2][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[2][0], (MUINT8*)(pose_kernel_bias_loop02_0_frame01), sizeof(pose_kernel_bias_loop02_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[2][1], 0, pose_kernel_RDMA_RA_buffer_size[2][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[2][1], (MUINT8*)(pose_kernel_bias_loop02_1_frame01), sizeof(pose_kernel_bias_loop02_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[3][0], 0, pose_kernel_RDMA_RA_buffer_size[3][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[3][0], (MUINT8*)(pose_kernel_bias_loop03_0_frame01), sizeof(pose_kernel_bias_loop03_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[3][1], 0, pose_kernel_RDMA_RA_buffer_size[3][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[3][1], (MUINT8*)(pose_kernel_bias_loop03_1_frame01), sizeof(pose_kernel_bias_loop03_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[4][0], 0, pose_kernel_RDMA_RA_buffer_size[4][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[4][0], (MUINT8*)(pose_kernel_bias_loop04_0_frame01), sizeof(pose_kernel_bias_loop04_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[4][1], 0, pose_kernel_RDMA_RA_buffer_size[4][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[4][1], (MUINT8*)(pose_kernel_bias_loop04_1_frame01), sizeof(pose_kernel_bias_loop04_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[5][0], 0, pose_kernel_RDMA_RA_buffer_size[5][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[5][0], (MUINT8*)(pose_kernel_bias_loop05_0_frame01), sizeof(pose_kernel_bias_loop05_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[5][1], 0, pose_kernel_RDMA_RA_buffer_size[5][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[5][1], (MUINT8*)(pose_kernel_bias_loop05_1_frame01), sizeof(pose_kernel_bias_loop05_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[6][0], 0, pose_kernel_RDMA_RA_buffer_size[6][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[6][0], (MUINT8*)(pose_kernel_bias_loop06_0_frame01), sizeof(pose_kernel_bias_loop06_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[6][1], 0, pose_kernel_RDMA_RA_buffer_size[6][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[6][1], (MUINT8*)(pose_kernel_bias_loop06_1_frame01), sizeof(pose_kernel_bias_loop06_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[7][0], 0, pose_kernel_RDMA_RA_buffer_size[7][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[7][0], (MUINT8*)(pose_kernel_bias_loop07_0_frame01), sizeof(pose_kernel_bias_loop07_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[7][1], 0, pose_kernel_RDMA_RA_buffer_size[7][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[7][1], (MUINT8*)(pose_kernel_bias_loop07_1_frame01), sizeof(pose_kernel_bias_loop07_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[8][0], 0, pose_kernel_RDMA_RA_buffer_size[8][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[8][0], (MUINT8*)(pose_kernel_bias_loop08_0_frame01), sizeof(pose_kernel_bias_loop08_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[8][1], 0, pose_kernel_RDMA_RA_buffer_size[8][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[8][1], (MUINT8*)(pose_kernel_bias_loop08_1_frame01), sizeof(pose_kernel_bias_loop08_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[9][0], 0, pose_kernel_RDMA_RA_buffer_size[9][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[9][0], (MUINT8*)(pose_kernel_bias_loop09_0_frame01), sizeof(pose_kernel_bias_loop09_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[9][1], 0, pose_kernel_RDMA_RA_buffer_size[9][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[9][1], (MUINT8*)(pose_kernel_bias_loop09_1_frame01), sizeof(pose_kernel_bias_loop09_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[10][0], 0, pose_kernel_RDMA_RA_buffer_size[10][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[10][0], (MUINT8*)(pose_kernel_bias_loop10_0_frame01), sizeof(pose_kernel_bias_loop10_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[10][1], 0, pose_kernel_RDMA_RA_buffer_size[10][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[10][1], (MUINT8*)(pose_kernel_bias_loop10_1_frame01), sizeof(pose_kernel_bias_loop10_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[11][0], 0, pose_kernel_RDMA_RA_buffer_size[11][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[11][0], (MUINT8*)(pose_kernel_bias_loop11_0_frame01), sizeof(pose_kernel_bias_loop11_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[11][1], 0, pose_kernel_RDMA_RA_buffer_size[11][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[11][1], (MUINT8*)(pose_kernel_bias_loop11_1_frame01), sizeof(pose_kernel_bias_loop11_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[12][0], 0, pose_kernel_RDMA_RA_buffer_size[12][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[12][0], (MUINT8*)(pose_kernel_bias_loop12_0_frame01), sizeof(pose_kernel_bias_loop12_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[12][1], 0, pose_kernel_RDMA_RA_buffer_size[12][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[12][1], (MUINT8*)(pose_kernel_bias_loop12_1_frame01), sizeof(pose_kernel_bias_loop12_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[13][0], 0, pose_kernel_RDMA_RA_buffer_size[13][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[13][0], (MUINT8*)(pose_kernel_bias_loop13_0_frame01), sizeof(pose_kernel_bias_loop13_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[13][1], 0, pose_kernel_RDMA_RA_buffer_size[13][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[13][1], (MUINT8*)(pose_kernel_bias_loop13_1_frame01), sizeof(pose_kernel_bias_loop13_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[14][0], 0, pose_kernel_RDMA_RA_buffer_size[14][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[14][0], (MUINT8*)(pose_kernel_bias_loop14_0_frame01), sizeof(pose_kernel_bias_loop14_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[14][1], 0, pose_kernel_RDMA_RA_buffer_size[14][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[14][1], (MUINT8*)(pose_kernel_bias_loop14_1_frame01), sizeof(pose_kernel_bias_loop14_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[15][0], 0, pose_kernel_RDMA_RA_buffer_size[15][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[15][0], (MUINT8*)(pose_kernel_bias_loop15_0_frame01), sizeof(pose_kernel_bias_loop15_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[15][1], 0, pose_kernel_RDMA_RA_buffer_size[15][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[15][1], (MUINT8*)(pose_kernel_bias_loop15_1_frame01), sizeof(pose_kernel_bias_loop15_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[16][0], 0, pose_kernel_RDMA_RA_buffer_size[16][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[16][0], (MUINT8*)(pose_kernel_bias_loop16_0_frame01), sizeof(pose_kernel_bias_loop16_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[16][1], 0, pose_kernel_RDMA_RA_buffer_size[16][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[16][1], (MUINT8*)(pose_kernel_bias_loop16_1_frame01), sizeof(pose_kernel_bias_loop16_1_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[17][0], 0, pose_kernel_RDMA_RA_buffer_size[17][0]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[17][0], (MUINT8*)(pose_kernel_bias_loop17_0_frame01), sizeof(pose_kernel_bias_loop17_0_frame01));
        memset(g_FdDrv_Fd_DMA_Para->pose_kernel_VA[17][1], 0, pose_kernel_RDMA_RA_buffer_size[17][1]);
        memcpy((MUINT8*)g_FdDrv_Fd_DMA_Para->pose_kernel_VA[17][1], (MUINT8*)(pose_kernel_bias_loop17_1_frame01), sizeof(pose_kernel_bias_loop17_1_frame01));
/*
        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
*/
}

void FDVT_resetOutputDataBuffer(NSCam::NSIoPipe::FDVTConfig* pFdvtConfig)
{
    if (pFdvtConfig->FD_MODE == 0) // FDMODE
    {
        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_R_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_G_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid1_B_Result_VA, 0, fdvt_rs_pyramid1_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_R_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_G_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Para->RS_Pyramid2_B_Result_VA, 0, fdvt_rs_pyramid2_out_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn0_loop_num][0], 0, fdvt_fd_result_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn1_loop_num][0], 0, fdvt_fd_result_size);
        memset(g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn2_loop_num][0], 0, fdvt_fd_result_size);
    }
    else if (pFdvtConfig->FD_MODE == 1) // ATTRIBUTEMODE
    {
        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
    }
    else if (pFdvtConfig->FD_MODE == 2) // POSEMODE
    {
        memset(g_FdDrv_Para->YUV2RGB_R_Result_VA, 0, fdvt_frame_R_size);
        memset(g_FdDrv_Para->YUV2RGB_G_Result_VA, 0, fdvt_frame_G_size);
        memset(g_FdDrv_Para->YUV2RGB_B_Result_VA, 0, fdvt_frame_B_size);
        memset(g_FdDrv_Para->RS_Pyramid0_R_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_G_Result_VA, 0, fdvt_rs_pyramid0_out_size);
        memset(g_FdDrv_Para->RS_Pyramid0_B_Result_VA, 0, fdvt_rs_pyramid0_out_size);
    }
}

void FDVT_configDram(NSCam::NSIoPipe::FDVTConfig* pFdvtConfig)
{
    MUINT64  *image_buffer_address = pFdvtConfig->source_img_address;
    MUINT64  *image_buffer_address_UV = pFdvtConfig->source_img_address_UV;
    MUINT64  *yuv2rgb_cfg, *attr_yuv2rgb_cfg, *pose_yuv2rgb_cfg;
    MUINT64  *rs_cfg, *attr_rs_cfg, *pose_rs_cfg;
    MUINT64  *fd_cfg, *attr_fd_cfg, *pose_fd_cfg;
    MUINT64  srcbuf_64 = 0x0, srcbuf_UV_64 = 0x0;
    MUINT32  srcbuf = 0x0, srcbuf_UV = 0x0;
    MUINT16  pyramid0_out_w = 0x0, pyramid1_out_w = 0x0, pyramid2_out_w = 0x0;
    MUINT16  pyramid0_out_h = 0x0, pyramid1_out_h = 0x0, pyramid2_out_h = 0x0;
    MUINT16  xmag_0 = 0x0, ymag_0 = 0x0;
    MUINT16  attr_xmag_0 = 0x0, attr_ymag_0 = 0x0;
    MUINT16  pose_xmag_0 = 0x0, pose_ymag_0 = 0x0;
    MUINT16  fd_input_ht = 0x0, fd_output_ht = 0x0, fd_conv_ht = 0x0;
    MUINT16  fd_out_y_0 = 0x0, fd_out_y_1 = 0x0, fd_out_y_2 = 0x0, fd_out_y_3 = 0x0;
    MUINT8 i = 0, j = 0, k = 0;
    MUINT8 uesd_out_loop = 0, uesd_out_ch = 0;

    if(pFdvtConfig->FD_MODE == 0) // FDMODE
    {
        g_FdDrv_Para->FD_MODE = pFdvtConfig->FD_MODE;
        g_FdDrv_Para->source_img_address = pFdvtConfig->source_img_address;
        g_FdDrv_Para->source_img_address_UV = pFdvtConfig->source_img_address_UV;
        g_FdDrv_Para->SRC_Input_Width = pFdvtConfig->SRC_IMG_WIDTH;
        g_FdDrv_Para->SRC_Input_Height = pFdvtConfig->SRC_IMG_HEIGHT;
        g_FdDrv_Para->SRC_IMG_FMT = pFdvtConfig->SRC_IMG_FMT;
        g_FdDrv_Para->INPUT_ROTATE_DEGREE = pFdvtConfig->INPUT_ROTATE_DEGREE;
    }
    else if(pFdvtConfig->FD_MODE == 1) // ATTRIBUTEMODE
    {
        g_FdDrv_Attr_Para->FD_MODE[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->FD_MODE;
        g_FdDrv_Attr_Para->source_img_address[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->source_img_address;
        g_FdDrv_Attr_Para->source_img_address_UV[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->source_img_address_UV;
        g_FdDrv_Attr_Para->SRC_Input_Width[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->SRC_IMG_WIDTH;
        g_FdDrv_Attr_Para->SRC_Input_Height[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->SRC_IMG_HEIGHT;
        g_FdDrv_Attr_Para->SRC_IMG_FMT[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->SRC_IMG_FMT;
        g_FdDrv_Attr_Para->INPUT_ROTATE_DEGREE[g_FdDrv_Attr_Para->WriteIdx] = pFdvtConfig->INPUT_ROTATE_DEGREE;
    }
    else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
    {
        g_FdDrv_Pose_Para->FD_MODE[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->FD_MODE;
        g_FdDrv_Pose_Para->source_img_address[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->source_img_address;
        g_FdDrv_Pose_Para->source_img_address_UV[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->source_img_address_UV;
        g_FdDrv_Pose_Para->SRC_Input_Width[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->SRC_IMG_WIDTH;
        g_FdDrv_Pose_Para->SRC_Input_Height[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->SRC_IMG_HEIGHT;
        g_FdDrv_Pose_Para->SRC_IMG_FMT[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->SRC_IMG_FMT;
        g_FdDrv_Pose_Para->INPUT_ROTATE_DEGREE[g_FdDrv_Pose_Para->WriteIdx] = pFdvtConfig->INPUT_ROTATE_DEGREE;
    }

    if(pFdvtConfig->FD_MODE == 0) // FDMODE
    {
        yuv2rgb_cfg  = g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA;
        rs_cfg  = g_FdDrv_Para->FDMODE_RS_Config_VA;
        fd_cfg  = g_FdDrv_Para->FDMODE_FD_Config_VA;
    }
    else if(pFdvtConfig->FD_MODE == 1) // ATTRIBUTEMODE
    {
        attr_yuv2rgb_cfg  = g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[g_FdDrv_Attr_Para->WriteIdx];
        attr_rs_cfg  = g_FdDrv_Para->ATTRMODE_RS_Config_VA[g_FdDrv_Attr_Para->WriteIdx];
        attr_fd_cfg  = g_FdDrv_Para->ATTRMODE_FD_Config_VA[g_FdDrv_Attr_Para->WriteIdx];
    }
    else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
    {
        pose_yuv2rgb_cfg  = g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[g_FdDrv_Pose_Para->WriteIdx];
        pose_rs_cfg  = g_FdDrv_Para->POSEMODE_RS_Config_VA[g_FdDrv_Pose_Para->WriteIdx];
        pose_fd_cfg  = g_FdDrv_Para->POSEMODE_FD_Config_VA[g_FdDrv_Pose_Para->WriteIdx];
    }

    srcbuf_64=(MUINT64)image_buffer_address; //phyical address
    srcbuf = srcbuf_64 & 0x00000000ffffffff;
    if(pFdvtConfig->SRC_IMG_FMT < 3 ) // 2 plane
    {
        srcbuf_UV_64=(MUINT64)image_buffer_address_UV; //phyical address
        srcbuf_UV = srcbuf_UV_64 & 0x00000000ffffffff;
    }

    // yuv2rgb config
    if(pFdvtConfig->FD_MODE == 0) // FDMODE
    {
        *((MUINT32 *)yuv2rgb_cfg + 0) = (*((MUINT32 *)yuv2rgb_cfg + 0) & 0xFFFFFFF8) | ((pFdvtConfig->SRC_IMG_FMT) & 0x7);
        *((MUINT32 *)yuv2rgb_cfg + 1) = (*((MUINT32 *)yuv2rgb_cfg + 1) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        *((MUINT32 *)yuv2rgb_cfg + 2) = (*((MUINT32 *)yuv2rgb_cfg + 2) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        if(pFdvtConfig->SRC_IMG_FMT < 3 ) // 2 plane
        {
	        *((MUINT32 *)yuv2rgb_cfg + 3) = (*((MUINT32 *)yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x11; // RA_0_EN & RA_1_EN
        	*((MUINT32 *)yuv2rgb_cfg + 4) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
	        *((MUINT32 *)yuv2rgb_cfg + 5) = (*((MUINT32 *)yuv2rgb_cfg + 5) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_0 && IN_BUS_SIZE_0
	        *((MUINT32 *)yuv2rgb_cfg + 6) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
	        *((MUINT32 *)yuv2rgb_cfg + 7) = (*((MUINT32 *)yuv2rgb_cfg + 7) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        else // 1 plane
        {
	        *((MUINT32 *)yuv2rgb_cfg + 3) = (*((MUINT32 *)yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x1; // RA_0_EN
        	*((MUINT32 *)yuv2rgb_cfg + 4) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
	        *((MUINT32 *)yuv2rgb_cfg + 5) = (*((MUINT32 *)yuv2rgb_cfg + 5) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_0 && IN_BUS_SIZE_0
        	*((MUINT32 *)yuv2rgb_cfg + 6) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
	        *((MUINT32 *)yuv2rgb_cfg + 7) = (*((MUINT32 *)yuv2rgb_cfg + 7) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        *((MUINT32 *)yuv2rgb_cfg + 8) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)yuv2rgb_cfg + 9) = (*((MUINT32 *)yuv2rgb_cfg + 9) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)yuv2rgb_cfg + 10) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_1 & OUT_YSIZE_1
        *((MUINT32 *)yuv2rgb_cfg + 11) = (*((MUINT32 *)yuv2rgb_cfg + 11) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_1
        *((MUINT32 *)yuv2rgb_cfg + 12) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_2 & OUT_YSIZE_2
        *((MUINT32 *)yuv2rgb_cfg + 13) = (*((MUINT32 *)yuv2rgb_cfg + 13) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_2
        *((MUINT32 *)yuv2rgb_cfg + 14) = (MUINT32)srcbuf;
        *((MUINT32 *)yuv2rgb_cfg + 15) = (MUINT32)srcbuf_UV;
        *((MUINT32 *)yuv2rgb_cfg + 16) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)yuv2rgb_cfg + 17) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)yuv2rgb_cfg + 18) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
    }
    else if(pFdvtConfig->FD_MODE == 1) // ATTRMODE
    {
        *((MUINT32 *)attr_yuv2rgb_cfg + 0) = (*((MUINT32 *)attr_yuv2rgb_cfg + 0) & 0xFFFFFFF8) | ((pFdvtConfig->SRC_IMG_FMT) & 0x7);
        *((MUINT32 *)attr_yuv2rgb_cfg + 1) = (*((MUINT32 *)attr_yuv2rgb_cfg + 1) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        *((MUINT32 *)attr_yuv2rgb_cfg + 2) = (*((MUINT32 *)attr_yuv2rgb_cfg + 2) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        if(pFdvtConfig->SRC_IMG_FMT < 3 ) // 2 plane
        {
	        *((MUINT32 *)attr_yuv2rgb_cfg + 3) = (*((MUINT32 *)attr_yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x11; // RA_0_EN & RA_1_EN
        	*((MUINT32 *)attr_yuv2rgb_cfg + 4) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        	*((MUINT32 *)attr_yuv2rgb_cfg + 5) = (*((MUINT32 *)attr_yuv2rgb_cfg + 5) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_0 && IN_BUS_SIZE_0
        	*((MUINT32 *)attr_yuv2rgb_cfg + 6) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
        	*((MUINT32 *)attr_yuv2rgb_cfg + 7) = (*((MUINT32 *)attr_yuv2rgb_cfg + 7) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        else // 1 plane
        {
	        *((MUINT32 *)attr_yuv2rgb_cfg + 3) = (*((MUINT32 *)attr_yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x1; // RA_0_EN
        	*((MUINT32 *)attr_yuv2rgb_cfg + 4) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        	*((MUINT32 *)attr_yuv2rgb_cfg + 5) = (*((MUINT32 *)attr_yuv2rgb_cfg + 5) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_0 && IN_BUS_SIZE_0
        	*((MUINT32 *)attr_yuv2rgb_cfg + 6) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
        	*((MUINT32 *)attr_yuv2rgb_cfg + 7) = (*((MUINT32 *)attr_yuv2rgb_cfg + 7) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        *((MUINT32 *)attr_yuv2rgb_cfg + 8) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)attr_yuv2rgb_cfg + 9) = (*((MUINT32 *)attr_yuv2rgb_cfg + 9) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)attr_yuv2rgb_cfg + 10) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_1 & OUT_YSIZE_1
        *((MUINT32 *)attr_yuv2rgb_cfg + 11) = (*((MUINT32 *)attr_yuv2rgb_cfg + 11) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_1
        *((MUINT32 *)attr_yuv2rgb_cfg + 12) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_2 & OUT_YSIZE_2
        *((MUINT32 *)attr_yuv2rgb_cfg + 13) = (*((MUINT32 *)attr_yuv2rgb_cfg + 13) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_2
        *((MUINT32 *)attr_yuv2rgb_cfg + 14) = (MUINT32)srcbuf;
        *((MUINT32 *)attr_yuv2rgb_cfg + 15) = (MUINT32)srcbuf_UV;
        *((MUINT32 *)attr_yuv2rgb_cfg + 16) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_yuv2rgb_cfg + 17) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_yuv2rgb_cfg + 18) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
    }
    else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
    {
        *((MUINT32 *)pose_yuv2rgb_cfg + 0) = (*((MUINT32 *)pose_yuv2rgb_cfg + 0) & 0xFFFFFFF8) | ((pFdvtConfig->SRC_IMG_FMT) & 0x7);
        *((MUINT32 *)pose_yuv2rgb_cfg + 1) = (*((MUINT32 *)pose_yuv2rgb_cfg + 1) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        *((MUINT32 *)pose_yuv2rgb_cfg + 2) = (*((MUINT32 *)pose_yuv2rgb_cfg + 2) & 0xF800F800) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF);
        if(pFdvtConfig->SRC_IMG_FMT < 3 ) // 2 plane
        {
	        *((MUINT32 *)pose_yuv2rgb_cfg + 3) = (*((MUINT32 *)pose_yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x11; // RA_0_EN & RA_1_EN
        	*((MUINT32 *)pose_yuv2rgb_cfg + 4) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
	        *((MUINT32 *)pose_yuv2rgb_cfg + 5) = (*((MUINT32 *)pose_yuv2rgb_cfg + 5) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_0 && IN_BUS_SIZE_0
        	*((MUINT32 *)pose_yuv2rgb_cfg + 6) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
	        *((MUINT32 *)pose_yuv2rgb_cfg + 7) = (*((MUINT32 *)pose_yuv2rgb_cfg + 7) & 0xFFF0) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x1; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        else // 1 plane
        {
	        *((MUINT32 *)pose_yuv2rgb_cfg + 3) = (*((MUINT32 *)pose_yuv2rgb_cfg + 3) & 0xFFFFFFEE) | 0x1; // RA_0_EN
        	*((MUINT32 *)pose_yuv2rgb_cfg + 4) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
	        *((MUINT32 *)pose_yuv2rgb_cfg + 5) = (*((MUINT32 *)pose_yuv2rgb_cfg + 5) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_0 && IN_BUS_SIZE_0
        	*((MUINT32 *)pose_yuv2rgb_cfg + 6) = ((2*pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_1 & IN_YSIZE_1
	        *((MUINT32 *)pose_yuv2rgb_cfg + 7) = (*((MUINT32 *)pose_yuv2rgb_cfg + 7) & 0xFFF0) | (((2*pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000) | 0x3; // IN_STRIDE_1 && IN_BUS_SIZE_1
        }
        *((MUINT32 *)pose_yuv2rgb_cfg + 8) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)pose_yuv2rgb_cfg + 9) = (*((MUINT32 *)pose_yuv2rgb_cfg + 9) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)pose_yuv2rgb_cfg + 10) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_1 & OUT_YSIZE_1
        *((MUINT32 *)pose_yuv2rgb_cfg + 11) = (*((MUINT32 *)pose_yuv2rgb_cfg + 11) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_1
        *((MUINT32 *)pose_yuv2rgb_cfg + 12) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_2 & OUT_YSIZE_2
        *((MUINT32 *)pose_yuv2rgb_cfg + 13) = (*((MUINT32 *)pose_yuv2rgb_cfg + 13) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_WIDTH) << 16) & 0xFFFF0000); // OUT_STRIDE_2
        *((MUINT32 *)pose_yuv2rgb_cfg + 14) = (MUINT32)srcbuf;
        *((MUINT32 *)pose_yuv2rgb_cfg + 15) = (MUINT32)srcbuf_UV;
        *((MUINT32 *)pose_yuv2rgb_cfg + 16) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_yuv2rgb_cfg + 17) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_yuv2rgb_cfg + 18) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
    }

    // rs config
    if(pFdvtConfig->FD_MODE == 0) // FDMODE
    {
        pyramid0_out_w = 400;
        pyramid1_out_w = 200;
        pyramid2_out_w = 100;
        pyramid0_out_h = pyramid0_out_w * pFdvtConfig->SRC_IMG_HEIGHT / pFdvtConfig->SRC_IMG_WIDTH;
        pyramid1_out_h = pyramid0_out_h / 2;
        pyramid2_out_h = pyramid1_out_h / 2;
        xmag_0 = 512 * pFdvtConfig->SRC_IMG_WIDTH / pyramid0_out_w;
        ymag_0 = xmag_0;

        // pyramid 0 : width = 400
        *((MUINT32 *)rs_cfg + 12 * 0 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 0 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 0 + 2) = (*((MUINT32 *)rs_cfg + 12 * 0 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);

        *((MUINT32 *)rs_cfg + 12 * 0 + 3) = (*((MUINT32 *)rs_cfg + 12 * 0 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 0 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 0 + 6) = (*((MUINT32 *)rs_cfg + 12 * 0 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 0 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 0 + 8) = (*((MUINT32 *)rs_cfg + 12 * 0 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 0 + 9) = (xmag_0 & 0x3FFF) | ((ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)rs_cfg + 12 * 1 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 1 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 1 + 2) = (*((MUINT32 *)rs_cfg + 12 * 1 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 1 + 3) = (*((MUINT32 *)rs_cfg + 12 * 1 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 1 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 1 + 6) = (*((MUINT32 *)rs_cfg + 12 * 1 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 1 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 1 + 8) = (*((MUINT32 *)rs_cfg + 12 * 1 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 1 + 9) = (xmag_0 & 0x3FFF) | ((ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)rs_cfg + 12 * 2 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 2 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 2 + 2) = (*((MUINT32 *)rs_cfg + 12 * 2 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 2 + 3) = (*((MUINT32 *)rs_cfg + 12 * 2 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 2 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 2 + 6) = (*((MUINT32 *)rs_cfg + 12 * 2 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 2 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 2 + 8) = (*((MUINT32 *)rs_cfg + 12 * 2 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 2 + 9) = (xmag_0 & 0x3FFF) | ((ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        // pyramid 1 : width = 200
        *((MUINT32 *)rs_cfg + 12 * 3 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 3 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 3 + 2) = (*((MUINT32 *)rs_cfg + 12 * 3 + 2) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 3 + 3) = (*((MUINT32 *)rs_cfg + 12 * 3 + 3) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 3 + 5) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 3 + 6) = (*((MUINT32 *)rs_cfg + 12 * 3 + 6) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 3 + 7) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 3 + 8) = (*((MUINT32 *)rs_cfg + 12 * 3 + 8) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0

        *((MUINT32 *)rs_cfg + 12 * 4 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 4 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 4 + 2) = (*((MUINT32 *)rs_cfg + 12 * 4 + 2) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 4 + 3) = (*((MUINT32 *)rs_cfg + 12 * 4 + 3) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 4 + 5) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 4 + 6) = (*((MUINT32 *)rs_cfg + 12 * 4 + 6) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 4 + 7) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 4 + 8) = (*((MUINT32 *)rs_cfg + 12 * 4 + 8) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0

        *((MUINT32 *)rs_cfg + 12 * 5 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 5 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 5 + 2) = (*((MUINT32 *)rs_cfg + 12 * 5 + 2) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 5 + 3) = (*((MUINT32 *)rs_cfg + 12 * 5 + 3) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 5 + 5) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 5 + 6) = (*((MUINT32 *)rs_cfg + 12 * 5 + 6) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 5 + 7) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 5 + 8) = (*((MUINT32 *)rs_cfg + 12 * 5 + 8) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0

        // pyramid 2 : width = 100
        *((MUINT32 *)rs_cfg + 12 * 6 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 6 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 6 + 2) = (*((MUINT32 *)rs_cfg + 12 * 6 + 2) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 6 + 3) = (*((MUINT32 *)rs_cfg + 12 * 6 + 3) & 0xF800F800) | (pyramid2_out_h & 0x7FF) | ((pyramid2_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 6 + 5) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 6 + 6) = (*((MUINT32 *)rs_cfg + 12 * 6 + 6) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 6 + 7) = ((pyramid2_out_w - 1) & 0xFFFF) | (((pyramid2_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 6 + 8) = (*((MUINT32 *)rs_cfg + 12 * 6 + 8) & 0xFFFF) | (((((pyramid2_out_w+7)/8)*8) << 16) & 0xFFFF0000); // OUT_STRIDE_0

        *((MUINT32 *)rs_cfg + 12 * 7 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 7 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 7 + 2) = (*((MUINT32 *)rs_cfg + 12 * 7 + 2) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 7 + 3) = (*((MUINT32 *)rs_cfg + 12 * 7 + 3) & 0xF800F800) | (pyramid2_out_h & 0x7FF) | ((pyramid2_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 7 + 5) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 7 + 6) = (*((MUINT32 *)rs_cfg + 12 * 7 + 6) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 7 + 7) = ((pyramid2_out_w - 1) & 0xFFFF) | (((pyramid2_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 7 + 8) = (*((MUINT32 *)rs_cfg + 12 * 7 + 8) & 0xFFFF) | (((((pyramid2_out_w+7)/8)*8) << 16) & 0xFFFF0000); // OUT_STRIDE_0


        *((MUINT32 *)rs_cfg + 12 * 8 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 8 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)rs_cfg + 12 * 8 + 2) = (*((MUINT32 *)rs_cfg + 12 * 8 + 2) & 0xF800F800) | (pyramid1_out_h & 0x7FF) | ((pyramid1_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 8 + 3) = (*((MUINT32 *)rs_cfg + 12 * 8 + 3) & 0xF800F800) | (pyramid2_out_h & 0x7FF) | ((pyramid2_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)rs_cfg + 12 * 8 + 5) = ((pyramid1_out_w - 1) & 0xFFFF) | (((pyramid1_out_h - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 8 + 6) = (*((MUINT32 *)rs_cfg + 12 * 8 + 6) & 0xFFFF) | ((pyramid1_out_w << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)rs_cfg + 12 * 8 + 7) = ((pyramid2_out_w - 1) & 0xFFFF) | (((pyramid2_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)rs_cfg + 12 * 8 + 8) = (*((MUINT32 *)rs_cfg + 12 * 8 + 8) & 0xFFFF) | (((((pyramid2_out_w+7)/8)*8) << 16) & 0xFFFF0000); // OUT_STRIDE_0
    }
    else if(pFdvtConfig->FD_MODE == 1) // ATTRMODE
    {
        pyramid0_out_w = 128;
        pyramid0_out_h = pyramid0_out_w * pFdvtConfig->SRC_IMG_HEIGHT / pFdvtConfig->SRC_IMG_WIDTH;
        attr_xmag_0 = 512 * pFdvtConfig->SRC_IMG_WIDTH / pyramid0_out_w;
        attr_ymag_0 = attr_xmag_0;

        // pyramid 0 : width = 128
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 2) = (*((MUINT32 *)attr_rs_cfg + 12 * 0 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 3) = (*((MUINT32 *)attr_rs_cfg + 12 * 0 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 6) = (*((MUINT32 *)attr_rs_cfg + 12 * 0 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 8) = (*((MUINT32 *)attr_rs_cfg + 12 * 0 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 0 + 9) = (attr_xmag_0 & 0x3FFF) | ((attr_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 2) = (*((MUINT32 *)attr_rs_cfg + 12 * 1 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 3) = (*((MUINT32 *)attr_rs_cfg + 12 * 1 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 6) = (*((MUINT32 *)attr_rs_cfg + 12 * 1 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 8) = (*((MUINT32 *)attr_rs_cfg + 12 * 1 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 1 + 9) = (attr_xmag_0 & 0x3FFF) | ((attr_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 2) = (*((MUINT32 *)attr_rs_cfg + 12 * 2 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 3) = (*((MUINT32 *)attr_rs_cfg + 12 * 2 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 6) = (*((MUINT32 *)attr_rs_cfg + 12 * 2 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 8) = (*((MUINT32 *)attr_rs_cfg + 12 * 2 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)attr_rs_cfg + 12 * 2 + 9) = (attr_xmag_0 & 0x3FFF) | ((attr_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG
    }
    else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
    {
        pyramid0_out_w = 128;
        pyramid0_out_h = pyramid0_out_w * pFdvtConfig->SRC_IMG_HEIGHT / pFdvtConfig->SRC_IMG_WIDTH;
        pose_xmag_0 = 512 * pFdvtConfig->SRC_IMG_WIDTH / pyramid0_out_w;
        pose_ymag_0 = pose_xmag_0;

        // pyramid 0 : width = 128
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_R_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 2) = (*((MUINT32 *)pose_rs_cfg + 12 * 0 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 3) = (*((MUINT32 *)pose_rs_cfg + 12 * 0 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 6) = (*((MUINT32 *)pose_rs_cfg + 12 * 0 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 8) = (*((MUINT32 *)pose_rs_cfg + 12 * 0 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 0 + 9) = (pose_xmag_0 & 0x3FFF) | ((pose_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_G_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 2) = (*((MUINT32 *)pose_rs_cfg + 12 * 1 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 3) = (*((MUINT32 *)pose_rs_cfg + 12 * 1 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 6) = (*((MUINT32 *)pose_rs_cfg + 12 * 1 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 8) = (*((MUINT32 *)pose_rs_cfg + 12 * 1 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 1 + 9) = (pose_xmag_0 & 0x3FFF) | ((pose_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG

        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 0) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 1) = (MUINT32)((MUINTPTR)g_FdDrv_Para->YUV2RGB_B_Result_PA & 0x00000000ffffffff);
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 2) = (*((MUINT32 *)pose_rs_cfg + 12 * 2 + 2) & 0xF800F800) | (pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 3) = (*((MUINT32 *)pose_rs_cfg + 12 * 2 + 3) & 0xF800F800) | (pyramid0_out_h & 0x7FF) | ((pyramid0_out_w << 16) & 0x7FF0000);
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 5) = ((pFdvtConfig->SRC_IMG_WIDTH - 1) & 0xFFFF) | (((pFdvtConfig->SRC_IMG_HEIGHT - 1) << 16) & 0xFFFF0000); // IN_XSIZE_0 & IN_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 6) = (*((MUINT32 *)pose_rs_cfg + 12 * 2 + 6) & 0xFFFF) | ((pFdvtConfig->SRC_IMG_WIDTH << 16) & 0xFFFF0000); // IN_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 7) = ((pyramid0_out_w - 1) & 0xFFFF) | (((pyramid0_out_h - 1) << 16) & 0xFFFF0000); // OUT_XSIZE_0 & OUT_YSIZE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 8) = (*((MUINT32 *)pose_rs_cfg + 12 * 2 + 8) & 0xFFFF) | ((pyramid0_out_w << 16) & 0xFFFF0000); // OUT_STRIDE_0
        *((MUINT32 *)pose_rs_cfg + 12 * 2 + 9) = (pose_xmag_0 & 0x3FFF) | ((pose_ymag_0 << 16) & 0x3FFF0000); // X_MAG & Y_MAG
    }

	// fd config
	if(pFdvtConfig->FD_MODE == 0) // FDMODE : 50 x 32bits per fd_config block
	{
		for(i=0; i < fdvt_fd_loop_num; i++)
		{
			*((MUINT32 *)fd_cfg + 50 * i + 1) = (*((MUINT32 *)fd_cfg + 50 * i + 1) & 0xFFFF0FFF) | ((pFdvtConfig->INPUT_ROTATE_DEGREE << 12) & 0x3000); // INPUT_ROTATE
			if(i == 0)
				fd_input_ht = pyramid2_out_h;
			else if(i == (fdvt_fd_rpn2_loop_num + 1))
				fd_input_ht = pyramid1_out_h;
			else if(i == (fdvt_fd_rpn1_loop_num + 1))
				fd_input_ht = pyramid0_out_h;
			else
			{
				if(Used_Output_Stride2_as_Input[i] == 0)
					fd_input_ht = fd_output_ht;
				else if(Used_Output_Stride2_as_Input[i] == 1)
					fd_input_ht = (fd_output_ht + 1) / 2; // ceiling
			}
			fd_output_ht = (fd_input_ht + (1*fd_stride[i] + 2*fd_maxpool[i] - 1)) / (1*fd_stride[i] + 2*fd_maxpool[i]); // ceiling
			fd_conv_ht = (fd_input_ht + (1*fd_stride[i] - 1)) / (1*fd_stride[i]); // ceiling

			*((MUINT32 *)fd_cfg + 50 * i + 4) = (*((MUINT32 *)fd_cfg + 50 * i + 4) & 0xFFFF0000) | (fd_conv_ht & 0xFFFF); // CONV_IMG_HT
			*((MUINT32 *)fd_cfg + 50 * i + 5) = (*((MUINT32 *)fd_cfg + 50 * i + 5) & 0xFFFF0000) | (fd_input_ht & 0xFFFF); // INPUT_IMG_HT
			*((MUINT32 *)fd_cfg + 50 * i + 6) = (*((MUINT32 *)fd_cfg + 50 * i + 6) & 0xFFFF0000) | (fd_output_ht & 0xFFFF); // OUTPUT_IMG_HT
			*((MUINT32 *)fd_cfg + 50 * i + 9) = (*((MUINT32 *)fd_cfg + 50 * i + 9) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_0
			*((MUINT32 *)fd_cfg + 50 * i + 11) = (*((MUINT32 *)fd_cfg + 50 * i + 11) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_1
			*((MUINT32 *)fd_cfg + 50 * i + 13) = (*((MUINT32 *)fd_cfg + 50 * i + 13) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_2
			*((MUINT32 *)fd_cfg + 50 * i + 15) = (*((MUINT32 *)fd_cfg + 50 * i + 15) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_3

			if(i == fdvt_fd_rpn0_loop_num || i == fdvt_fd_rpn1_loop_num || i == fdvt_fd_rpn2_loop_num)
			{
				fd_out_y_0 = 0;
				fd_out_y_1 = 0;
				fd_out_y_2 = 0;
				fd_out_y_3 = 0;
			}
			else
			{
				fd_out_y_0 = fd_output_ht - 1;
				fd_out_y_1 = fd_output_ht - 1;
				if(out_2size[i] == 0)
				{
					fd_out_y_2 = fd_output_ht - 1;
					fd_out_y_3 = fd_output_ht - 1;
				}
				else if(out_2size[i] == 1)
				{
					fd_out_y_2 = (fd_output_ht + 1)/2 - 1;
					fd_out_y_3 = (fd_output_ht + 1)/2 - 1;
				}
			}

			*((MUINT32 *)fd_cfg + 50 * i + 17) = (*((MUINT32 *)fd_cfg + 50 * i + 17) & 0xFFFF) | ((fd_out_y_0 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_0
			*((MUINT32 *)fd_cfg + 50 * i + 19) = (*((MUINT32 *)fd_cfg + 50 * i + 19) & 0xFFFF) | ((fd_out_y_1 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_1
			*((MUINT32 *)fd_cfg + 50 * i + 21) = (*((MUINT32 *)fd_cfg + 50 * i + 21) & 0xFFFF) | ((fd_out_y_2 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_2
			*((MUINT32 *)fd_cfg + 50 * i + 23) = (*((MUINT32 *)fd_cfg + 50 * i + 23) & 0xFFFF) | ((fd_out_y_3 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_3

			// IN_FM_BASE_ADR
			if(i == 0)
			{
				*((MUINT32 *)fd_cfg + 50 * i + 27) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_R_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 28) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_G_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 29) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid2_B_Result_PA & 0x00000000ffffffff);
			}
			else if(i == (fdvt_fd_rpn2_loop_num + 1))
			{
				*((MUINT32 *)fd_cfg + 50 * i + 27) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_R_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 28) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_G_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 29) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid1_B_Result_PA & 0x00000000ffffffff);
			}
			else if(i == (fdvt_fd_rpn1_loop_num + 1))
			{
				*((MUINT32 *)fd_cfg + 50 * i + 27) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 28) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)fd_cfg + 50 * i + 29) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
			}
			else
			{
				for(j=0; j < input_WDMA_WRA_num ; j++)
				{
					if(input_RDMA_RA_buffer_en[i][j][0] != -1)
					{
						uesd_out_loop = input_RDMA_RA_buffer_en[i][j][0];
						uesd_out_ch = input_RDMA_RA_buffer_en[i][j][1];
						*((MUINT32 *)fd_cfg + 50 * i + (27 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[uesd_out_loop][uesd_out_ch] & 0x00000000ffffffff);
					}
				}
			}

			// OUT_FM_BASE_ADR
			for(j=0; j < output_WDMA_WRA_num ; j++)
			{
				if(output_WDMA_WRA_buffer_en[i][j] == 1)
				{
   					*((MUINT32 *)fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] & 0x00000000ffffffff);
				}
			}

			// KERNEL_BASE_ADR
			for(j=0; j < kernel_RDMA_RA_num ; j++)
			{
				if(kernel_RDMA_RA_buffer_en[i][j] == 1)
				{
					*((MUINT32 *)fd_cfg + 50 * i + (35 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->fd_kernel_PA[i][j] & 0x00000000ffffffff);
				}
			}
			if(i == fdvt_fd_rpn0_loop_num)
			{
				*((MUINT32 *)fd_cfg + 50 * i + 37) = (*((MUINT32 *)fd_cfg + 50 * i + 37) & 0xFFFF) | ((g_FdDrv_Para->RPN_ANCHOR_THRD << 16) & 0xFFFF0000); // RPN_ANCHOR_THRD
				*((MUINT32 *)fd_cfg + 50 * i + 39) = (*((MUINT32 *)fd_cfg + 50 * i + 39) & 0xF) | ((((1*pFdvtConfig->SRC_IMG_WIDTH*512)/pyramid0_out_w) << 4) & 0x7FFF0); // IMAGE_COORD_SCALE
			}
			else if(i == fdvt_fd_rpn1_loop_num)
			{
				*((MUINT32 *)fd_cfg + 50 * i + 37) = (*((MUINT32 *)fd_cfg + 50 * i + 37) & 0xFFFF) | ((g_FdDrv_Para->RPN_ANCHOR_THRD << 16) & 0xFFFF0000); // RPN_ANCHOR_THRD
				*((MUINT32 *)fd_cfg + 50 * i + 39) = (*((MUINT32 *)fd_cfg + 50 * i + 39) & 0xF) | ((((2*pFdvtConfig->SRC_IMG_WIDTH*512)/pyramid0_out_w) << 4) & 0x7FFF0); // IMAGE_COORD_SCALE
			}
			else if(i == fdvt_fd_rpn2_loop_num)
			{
				*((MUINT32 *)fd_cfg + 50 * i + 37) = (*((MUINT32 *)fd_cfg + 50 * i + 37) & 0xFFFF) | ((g_FdDrv_Para->RPN_ANCHOR_THRD << 16) & 0xFFFF0000); // RPN_ANCHOR_THRD
				*((MUINT32 *)fd_cfg + 50 * i + 39) = (*((MUINT32 *)fd_cfg + 50 * i + 39) & 0xF) | ((((4*pFdvtConfig->SRC_IMG_WIDTH*512)/pyramid0_out_w) << 4) & 0x7FFF0); // IMAGE_COORD_SCALE
			}
		}
	}
	else if(pFdvtConfig->FD_MODE == 1) // ATTRMODE
	{
		for(i=0; i < fdvt_attr_loop_num; i++)
		{
			*((MUINT32 *)attr_fd_cfg + 50 * i + 1) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 1) & 0xFFFF0FFF) | ((pFdvtConfig->INPUT_ROTATE_DEGREE << 12) & 0x3000); // INPUT_ROTATE
			if(i == 0)
				fd_input_ht = pyramid0_out_h;
			else
			{
				if(attr_Used_Output_Stride2_as_Input[i] == 0)
					fd_input_ht = fd_output_ht;
				else if(attr_Used_Output_Stride2_as_Input[i] == 1)
					fd_input_ht = (fd_output_ht + 1) / 2; // ceiling
			}
			fd_output_ht = (fd_input_ht + (1*attr_stride[i] + 2*attr_maxpool[i] - 1)) / (1*attr_stride[i] + 2*attr_maxpool[i]); // ceiling
			fd_conv_ht = (fd_input_ht + (1*attr_stride[i] - 1)) / (1*attr_stride[i]); // ceiling

			*((MUINT32 *)attr_fd_cfg + 50 * i + 4) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 4) & 0xFFFF0000) | (fd_conv_ht & 0xFFFF); // CONV_IMG_HT
			*((MUINT32 *)attr_fd_cfg + 50 * i + 5) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 5) & 0xFFFF0000) | (fd_input_ht & 0xFFFF); // INPUT_IMG_HT
			*((MUINT32 *)attr_fd_cfg + 50 * i + 6) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 6) & 0xFFFF0000) | (fd_output_ht & 0xFFFF); // OUTPUT_IMG_HT
			*((MUINT32 *)attr_fd_cfg + 50 * i + 9) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 9) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_0
			*((MUINT32 *)attr_fd_cfg + 50 * i + 11) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 11) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_1
			*((MUINT32 *)attr_fd_cfg + 50 * i + 13) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 13) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_2
			*((MUINT32 *)attr_fd_cfg + 50 * i + 15) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 15) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_3

			fd_out_y_0 = fd_output_ht - 1;
			fd_out_y_1 = fd_output_ht - 1;
			if(attr_out_2size[i] == 0)
			{
				fd_out_y_2 = fd_output_ht - 1;
				fd_out_y_3 = fd_output_ht - 1;
			}
			else if(attr_out_2size[i] == 1)
			{
				fd_out_y_2 = (fd_output_ht + 1)/2 - 1;
				fd_out_y_3 = (fd_output_ht + 1)/2 - 1;
			}

			*((MUINT32 *)attr_fd_cfg + 50 * i + 17) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 17) & 0xFFFF) | ((fd_out_y_0 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_0
			*((MUINT32 *)attr_fd_cfg + 50 * i + 19) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 19) & 0xFFFF) | ((fd_out_y_1 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_1
			*((MUINT32 *)attr_fd_cfg + 50 * i + 21) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 21) & 0xFFFF) | ((fd_out_y_2 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_2
			*((MUINT32 *)attr_fd_cfg + 50 * i + 23) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 23) & 0xFFFF) | ((fd_out_y_3 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_3

			// IN_FM_BASE_ADR
			if(i == 0)
			{
				*((MUINT32 *)attr_fd_cfg + 50 * i + 27) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)attr_fd_cfg + 50 * i + 28) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)attr_fd_cfg + 50 * i + 29) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
			}
			else
			{
				for(j=0; j < input_WDMA_WRA_num ; j++)
				{
					if(attr_input_RDMA_RA_buffer_en[i][j][0] != -1)
					{
						uesd_out_loop = attr_input_RDMA_RA_buffer_en[i][j][0];
						uesd_out_ch = attr_input_RDMA_RA_buffer_en[i][j][1];
						*((MUINT32 *)attr_fd_cfg + 50 * i + (27 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[uesd_out_loop][uesd_out_ch] & 0x00000000ffffffff);
					}
				}
			}

			// OUT_FM_BASE_ADR
			for(j=0; j < output_WDMA_WRA_num ; j++)
			{
				if(attr_output_WDMA_WRA_buffer_en[i][j] == 1)
				{
					if(i == fdvt_race_output_regression && j == 0)
					    *((MUINT32 *)attr_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->race_out_hw_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
					else if(i == fdvt_gender_output_regression && j == 0)
					    *((MUINT32 *)attr_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
					else
					    *((MUINT32 *)attr_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] & 0x00000000ffffffff);
				}
			}

			// KERNEL_BASE_ADR
			for(j=0; j < kernel_RDMA_RA_num ; j++)
			{
				if(attr_kernel_RDMA_RA_buffer_en[i][j] == 1)
				{
   					*((MUINT32 *)attr_fd_cfg + 50 * i + (35 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->attr_kernel_PA[i][j] & 0x00000000ffffffff);
				}
			}

			//*((MUINT32 *)attr_fd_cfg + 50 * i + 37) = (*((MUINT32 *)attr_fd_cfg + 50 * i + 37) & 0xFFFF) | ((g_FdDrv_Para->RPN_ANCHOR_THRD << 16) & 0xFFFF0000); // RPN_ANCHOR_THRD
		}
	}
	else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
	{
		for(i=0; i < fdvt_pose_loop_num; i++)
		{
			*((MUINT32 *)pose_fd_cfg + 50 * i + 1) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 1) & 0xFFFF0FFF) | ((pFdvtConfig->INPUT_ROTATE_DEGREE << 12) & 0x3000); // INPUT_ROTATE
			if(i == 0)
				fd_input_ht = pyramid0_out_h;
			else
			{
				if(pose_Used_Output_Stride2_as_Input[i] == 0)
					fd_input_ht = fd_output_ht;
				else if(pose_Used_Output_Stride2_as_Input[i] == 1)
					fd_input_ht = (fd_output_ht + 1) / 2; // ceiling
			}
			fd_output_ht = (fd_input_ht + (1*pose_stride[i] + 2*pose_maxpool[i] - 1)) / (1*pose_stride[i] + 2*pose_maxpool[i]); // ceiling
			fd_conv_ht = (fd_input_ht + (1*pose_stride[i] - 1)) / (1*pose_stride[i]); // ceiling

			*((MUINT32 *)pose_fd_cfg + 50 * i + 4) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 4) & 0xFFFF0000) | (fd_conv_ht & 0xFFFF); // CONV_IMG_HT
			*((MUINT32 *)pose_fd_cfg + 50 * i + 5) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 5) & 0xFFFF0000) | (fd_input_ht & 0xFFFF); // INPUT_IMG_HT
			*((MUINT32 *)pose_fd_cfg + 50 * i + 6) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 6) & 0xFFFF0000) | (fd_output_ht & 0xFFFF); // OUTPUT_IMG_HT
			*((MUINT32 *)pose_fd_cfg + 50 * i + 9) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 9) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_0
			*((MUINT32 *)pose_fd_cfg + 50 * i + 11) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 11) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_1
			*((MUINT32 *)pose_fd_cfg + 50 * i + 13) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 13) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_2
			*((MUINT32 *)pose_fd_cfg + 50 * i + 15) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 15) & 0xFFFF) | (((fd_input_ht - 1) << 16) & 0xFFFF0000); // INPUT_YSIZE_3

			fd_out_y_0 = fd_output_ht - 1;
			fd_out_y_1 = fd_output_ht - 1;
			if(pose_out_2size[i] == 0)
			{
				fd_out_y_2 = fd_output_ht - 1;
				fd_out_y_3 = fd_output_ht - 1;
			}
			else if(pose_out_2size[i] == 1)
			{
				fd_out_y_2 = (fd_output_ht + 1)/2 - 1;
				fd_out_y_3 = (fd_output_ht + 1)/2 - 1;
			}

			*((MUINT32 *)pose_fd_cfg + 50 * i + 17) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 17) & 0xFFFF) | ((fd_out_y_0 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_0
			*((MUINT32 *)pose_fd_cfg + 50 * i + 19) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 19) & 0xFFFF) | ((fd_out_y_1 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_1
			*((MUINT32 *)pose_fd_cfg + 50 * i + 21) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 21) & 0xFFFF) | ((fd_out_y_2 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_2
			*((MUINT32 *)pose_fd_cfg + 50 * i + 23) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 23) & 0xFFFF) | ((fd_out_y_3 << 16) & 0xFFFF0000); // OUTPUT_YSIZE_3

			// IN_FM_BASE_ADR
			if(i == 0)
			{
				*((MUINT32 *)pose_fd_cfg + 50 * i + 27) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_R_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)pose_fd_cfg + 50 * i + 28) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_G_Result_PA & 0x00000000ffffffff);
				*((MUINT32 *)pose_fd_cfg + 50 * i + 29) = (MUINT32)((MUINTPTR)g_FdDrv_Para->RS_Pyramid0_B_Result_PA & 0x00000000ffffffff);
			}
			else
			{
				for(j=0; j < input_WDMA_WRA_num ; j++)
				{
					if(pose_input_RDMA_RA_buffer_en[i][j][0] != -1)
					{
						uesd_out_loop = pose_input_RDMA_RA_buffer_en[i][j][0];
						uesd_out_ch = pose_input_RDMA_RA_buffer_en[i][j][1];
						*((MUINT32 *)pose_fd_cfg + 50 * i + (27 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[uesd_out_loop][uesd_out_ch] & 0x00000000ffffffff);
					}
				}
			}

			// OUT_FM_BASE_ADR
			for(j=0; j < output_WDMA_WRA_num ; j++)
			{
				if(pose_output_WDMA_WRA_buffer_en[i][j] == 1)
				{
					if(i == fdvt_rip_output_regression && j == 0)
					    *((MUINT32 *)pose_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
					else if(i == fdvt_rop_output_regression && j == 0)
					    *((MUINT32 *)pose_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
					else
					    *((MUINT32 *)pose_fd_cfg + 50 * i + (31 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] & 0x00000000ffffffff);
				}
			}

			// KERNEL_BASE_ADR
			for(j=0; j < kernel_RDMA_RA_num ; j++)
			{
				if(pose_kernel_RDMA_RA_buffer_en[i][j] == 1)
				{
					*((MUINT32 *)pose_fd_cfg + 50 * i + (35 + j)) = (MUINT32)((MUINTPTR)g_FdDrv_Fd_DMA_Para->pose_kernel_PA[i][j] & 0x00000000ffffffff);
				}
			}
			//*((MUINT32 *)pose_fd_cfg + 50 * i + 37) = (*((MUINT32 *)pose_fd_cfg + 50 * i + 37) & 0xFFFF) | ((g_FdDrv_Para->RPN_ANCHOR_THRD << 16) & 0xFFFF0000); // RPN_ANCHOR_THRD
		}
	}
}

void FDVT_DumpDRAMOut(unsigned int *hw, unsigned int size)
{
	unsigned int i;
	unsigned int comparetimes = size / 4;

	//LOG_INF("Total Byte Size: %d", size);
	for (i = 0;i < comparetimes; i+=4)
	{
		LOG_INF("0x%08x, 0x%08x, 0x%08x, 0x%08x",hw[i], hw[i+1], hw[i+2], hw[i+3]);
	}
	LOG_INF("Dump End");
}

#if (FD_Unit_Test || ATTR_Unit_Test || POSE_Unit_Test)
unsigned int FDVT_BitTrueCheck(unsigned int *hw, unsigned int *golden, unsigned int size)
{
	unsigned int i;
	unsigned int errCount = 0;
	unsigned int timesToBreak = 1000;
	unsigned int comparetimes = size / 4;

	//LOG_INF("Total Byte Size: %d", size);
	for (i = 0;i < comparetimes; i++)
	{
		//LOG_INF("Bit-true(%d of %d), OFFSET (0x%x) : HW (0x%08x) : GOLD (0x%08x)", i, comparetimes, i*sizeof(int), hw[i], golden[i]);
		if (hw[i] != golden[i])
		{
			errCount ++;
			if (errCount < timesToBreak)
			{
				LOG_INF("Bit-true(%d of %d) Fail!, OFFSET (0x%04x) : HW (0x%08x) : GOLD (0x%08x)", i, comparetimes, i*sizeof(int), hw[i], golden[i]);
			}
			//return false;
		}
	}
	if (errCount == 0)
		LOG_INF("Bit-true PASS\n");

	return errCount;
}

unsigned int FDVT_BitTrueCheck_withDummy(unsigned int *hw, unsigned int *golden, unsigned int totalSize, unsigned int validSize, unsigned int dummySize)
{
	unsigned int i = 0, j = 0, groupIndex = 0;
	unsigned int errCount = 0;
	unsigned int timesToBreak = 1000;
	unsigned int groupNumbers = totalSize / (validSize + dummySize);
	unsigned int comparetimes = validSize / sizeof(int);
	unsigned int jumpDistance_of_int = (validSize + dummySize) / sizeof(int);

	//LOG_MSG("Total Byte Size: %d, Valid Byte Size: %d, Dummy Byte Size: %d, Group Numbers: %d", totalSize, validSize, dummySize, groupNumbers);
	//LOG_MSG("Total Int Size: %d, Valid Int Size: %d, Dummy Int Size: %d", totalSize/4, validSize/4, dummySize/4);
	//LOG_MSG("Compare Times per Group: %d, Jump Distance of int: %d", comparetimes, jumpDistance_of_int);
	for (groupIndex = 0; groupIndex < groupNumbers; groupIndex ++)
	{
		//LOG_MSG("GroupIndex = %d, comparetimes = %d, jumpDistance_of_int = %d", groupIndex, comparetimes, jumpDistance_of_int);
		for (j = 0;j < comparetimes; j++)
		{
			//LOG_MSG("Bit-true(%d of %d), OFFSET (0x%x) : HW (0x%08x) : GOLD (0x%08x)", i+j, totalSize/4, (i+j)*sizeof(int), hw[i+j], golden[i+j]);
			if (hw[i+j] != golden[i+j])
			{
				errCount ++;
				if (errCount < timesToBreak)
				{
					LOG_INF("valid size = %d, dummy size = %d, groupIndex = %d, groupNumbers = %d, i = %d, j = %d", validSize, dummySize, groupIndex, groupNumbers, i, j);
					LOG_INF("Bit-true(%d of %d) Fail!, OFFSET (0x%x) : HW (0x%08x) : GOLD (0x%08x)", i+j, totalSize/4, (i+j)*sizeof(int), hw[i+j], golden[i+j]);
				}
				//return false;
			}
		}
		//LOG_MSG("jump distance %d from %d", jumpDistance_of_int, i);
		i = i + jumpDistance_of_int;
	}
	if (errCount == 0)
		LOG_INF("Bit-true PASS\n");
	return errCount;
}

bool FDVT_BitTrueTest()
{
	unsigned int errCount_FDVT_Result = 0;
	// FD PART
	//LOG_INF("bit true start: YUV_RGB Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, (unsigned int *)&fdvt_FD_yuv2rgb_config[0], fdvt_fdmode_yuv2rgb_config_size);

#if FD_Unit_Test
	LOG_INF("bit true start: R Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_R_Result_VA, fdvt_frame_R_golden, sizeof(fdvt_frame_R_golden));
	LOG_INF("bit true start: G Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_G_Result_VA, fdvt_frame_G_golden, sizeof(fdvt_frame_G_golden));
	LOG_INF("bit true start: B Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_B_Result_VA, fdvt_frame_B_golden, sizeof(fdvt_frame_B_golden));
#endif

	//LOG_INF("bit true start: RS Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->FDMODE_RS_Config_VA, (unsigned int *)&fdvt_FD_rs_config[0], fdvt_fdmode_rs_config_size);

#if FD_Unit_Test
	LOG_INF("bit true start: RGB Frames --- Pyramid0_R");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_R_Result_VA, fdvt_frame_R_pyramid0_golden, sizeof(fdvt_frame_R_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_G");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_G_Result_VA, fdvt_frame_G_pyramid0_golden, sizeof(fdvt_frame_G_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_B");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_B_Result_VA, fdvt_frame_B_pyramid0_golden, sizeof(fdvt_frame_B_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid1_R");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_R_Result_VA, fdvt_frame_R_pyramid1_golden, sizeof(fdvt_frame_R_pyramid1_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid1_G");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_G_Result_VA, fdvt_frame_G_pyramid1_golden, sizeof(fdvt_frame_G_pyramid1_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid1_B");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_B_Result_VA, fdvt_frame_B_pyramid1_golden, sizeof(fdvt_frame_B_pyramid1_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid2_R");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_R_Result_VA, fdvt_frame_R_pyramid2_golden, sizeof(fdvt_frame_R_pyramid2_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid2_G");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_G_Result_VA, fdvt_frame_G_pyramid2_golden, sizeof(fdvt_frame_G_pyramid2_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid2_B");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_B_Result_VA, fdvt_frame_B_pyramid2_golden, sizeof(fdvt_frame_B_pyramid2_golden));
#endif

	//LOG_INF("bit true start: FD Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->FDMODE_FD_Config_VA, (unsigned int *)&fdvt_FD_fd_config[0], fdvt_fdmode_fd_config_size);

/*
	LOG_INF("bit true start: FD RESULT00_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[0][0], fdvt_fd_out_loop00_0_golden, output_WDMA_WRA_buffer_size[0][0]);
	LOG_INF("bit true start: FD RESULT00_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[0][2], fdvt_fd_out_loop00_2_golden, output_WDMA_WRA_buffer_size[0][2]);
	LOG_INF("bit true start: FD RESULT01_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[1][0], fdvt_fd_out_loop01_0_golden, output_WDMA_WRA_buffer_size[1][0]);
	LOG_INF("bit true start: FD RESULT01_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[1][2], fdvt_fd_out_loop01_2_golden, output_WDMA_WRA_buffer_size[1][2]);
	LOG_INF("bit true start: FD RESULT02_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[2][0], fdvt_fd_out_loop02_0_golden, output_WDMA_WRA_buffer_size[2][0]);
	LOG_INF("bit true start: FD RESULT03_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[3][0], fdvt_fd_out_loop03_0_golden, output_WDMA_WRA_buffer_size[3][0]);
	LOG_INF("bit true start: FD RESULT03_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[3][1], fdvt_fd_out_loop03_1_golden, output_WDMA_WRA_buffer_size[3][1]);
	LOG_INF("bit true start: FD RESULT03_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[3][2], fdvt_fd_out_loop03_2_golden, output_WDMA_WRA_buffer_size[3][2]);
	LOG_INF("bit true start: FD RESULT03_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[3][3], fdvt_fd_out_loop03_3_golden, output_WDMA_WRA_buffer_size[3][3]);
	LOG_INF("bit true start: FD RESULT04_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[4][0], fdvt_fd_out_loop04_0_golden, output_WDMA_WRA_buffer_size[4][0]);
	LOG_INF("bit true start: FD RESULT04_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[4][1], fdvt_fd_out_loop04_1_golden, output_WDMA_WRA_buffer_size[4][1]);
	LOG_INF("bit true start: FD RESULT04_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[4][2], fdvt_fd_out_loop04_2_golden, output_WDMA_WRA_buffer_size[4][2]);
	LOG_INF("bit true start: FD RESULT04_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[4][3], fdvt_fd_out_loop04_3_golden, output_WDMA_WRA_buffer_size[4][3]);
	LOG_INF("bit true start: FD RESULT05_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[5][0], fdvt_fd_out_loop05_0_golden, output_WDMA_WRA_buffer_size[5][0]);
	LOG_INF("bit true start: FD RESULT05_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[5][2], fdvt_fd_out_loop05_2_golden, output_WDMA_WRA_buffer_size[5][2]);
	LOG_INF("bit true start: FD RESULT06_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[6][0], fdvt_fd_out_loop06_0_golden, output_WDMA_WRA_buffer_size[6][0]);
	LOG_INF("bit true start: FD RESULT06_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[6][1], fdvt_fd_out_loop06_1_golden, output_WDMA_WRA_buffer_size[6][1]);
	LOG_INF("bit true start: FD RESULT07_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[7][0], fdvt_fd_out_loop07_0_golden, output_WDMA_WRA_buffer_size[7][0]);
	LOG_INF("bit true start: FD RESULT07_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[7][2], fdvt_fd_out_loop07_2_golden, output_WDMA_WRA_buffer_size[7][2]);
	LOG_INF("bit true start: FD RESULT08_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[8][0], fdvt_fd_out_loop08_0_golden, output_WDMA_WRA_buffer_size[8][0]);
	LOG_INF("bit true start: FD RESULT08_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[8][1], fdvt_fd_out_loop08_1_golden, output_WDMA_WRA_buffer_size[8][1]);
	LOG_INF("bit true start: FD RESULT09_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[9][0], fdvt_fd_out_loop09_0_golden, output_WDMA_WRA_buffer_size[9][0]);
	LOG_INF("bit true start: FD RESULT10_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[10][0], fdvt_fd_out_loop10_0_golden, output_WDMA_WRA_buffer_size[10][0]);
	LOG_INF("bit true start: FD RESULT11_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[11][0], fdvt_fd_out_loop11_0_golden, output_WDMA_WRA_buffer_size[11][0]);
	LOG_INF("bit true start: FD RESULT12_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[12][0], fdvt_fd_out_loop12_0_golden, output_WDMA_WRA_buffer_size[12][0]);
	LOG_INF("bit true start: FD RESULT13_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[13][0], fdvt_fd_out_loop13_0_golden, output_WDMA_WRA_buffer_size[13][0]);
	LOG_INF("bit true start: FD RESULT14_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[14][0], fdvt_fd_out_loop14_0_golden, output_WDMA_WRA_buffer_size[14][0]);
	LOG_INF("bit true start: FD RESULT15_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[15][0], fdvt_fd_out_loop15_0_golden, output_WDMA_WRA_buffer_size[15][0]);
	LOG_INF("bit true start: FD RESULT15_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[15][1], fdvt_fd_out_loop15_1_golden, output_WDMA_WRA_buffer_size[15][1]);
	LOG_INF("bit true start: FD RESULT16_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][0], fdvt_fd_out_loop16_0_golden, output_WDMA_WRA_buffer_size[16][0], 448, 448);
	LOG_INF("bit true start: FD RESULT16_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][1], fdvt_fd_out_loop16_1_golden, output_WDMA_WRA_buffer_size[16][1], 448, 448);
	LOG_INF("bit true start: FD RESULT16_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][2], fdvt_fd_out_loop16_2_golden, output_WDMA_WRA_buffer_size[16][2], 448, 448);
	LOG_INF("bit true start: FD RESULT16_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[16][3], fdvt_fd_out_loop16_3_golden, output_WDMA_WRA_buffer_size[16][3], 448, 448);
	LOG_INF("bit true start: FD RESULT17_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[17][0], fdvt_fd_out_loop17_0_golden, output_WDMA_WRA_buffer_size[17][0], 224, 224);
	LOG_INF("bit true start: FD RESULT17_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[17][1], fdvt_fd_out_loop17_1_golden, output_WDMA_WRA_buffer_size[17][1], 224, 224);
	LOG_INF("bit true start: FD RESULT18_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[18][0], fdvt_fd_out_loop18_0_golden, output_WDMA_WRA_buffer_size[18][0], 448, 448);
	LOG_INF("bit true start: FD RESULT18_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[18][1], fdvt_fd_out_loop18_1_golden, output_WDMA_WRA_buffer_size[18][1], 448, 448);
*/

#if FD_Unit_Test
	LOG_INF("bit true start: FD RESULT19_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[19][0], fdvt_fd_out_loop19_0_golden, sizeof(fdvt_fd_out_loop19_0_golden));
#endif

/*
	LOG_INF("bit true start: FD RESULT20_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[20][0], fdvt_fd_out_loop20_0_golden, output_WDMA_WRA_buffer_size[20][0]);
	LOG_INF("bit true start: FD RESULT20_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[20][2], fdvt_fd_out_loop20_2_golden, output_WDMA_WRA_buffer_size[20][2]);
	LOG_INF("bit true start: FD RESULT21_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[21][0], fdvt_fd_out_loop21_0_golden, output_WDMA_WRA_buffer_size[21][0]);
	LOG_INF("bit true start: FD RESULT21_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[21][2], fdvt_fd_out_loop21_2_golden, output_WDMA_WRA_buffer_size[21][2]);
	LOG_INF("bit true start: FD RESULT22_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[22][0], fdvt_fd_out_loop22_0_golden, output_WDMA_WRA_buffer_size[22][0]);
	LOG_INF("bit true start: FD RESULT23_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[23][0], fdvt_fd_out_loop23_0_golden, output_WDMA_WRA_buffer_size[23][0]);
	LOG_INF("bit true start: FD RESULT23_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[23][1], fdvt_fd_out_loop23_1_golden, output_WDMA_WRA_buffer_size[23][1]);
	LOG_INF("bit true start: FD RESULT23_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[23][2], fdvt_fd_out_loop23_2_golden, output_WDMA_WRA_buffer_size[23][2]);
	LOG_INF("bit true start: FD RESULT23_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[23][3], fdvt_fd_out_loop23_3_golden, output_WDMA_WRA_buffer_size[23][3]);
	LOG_INF("bit true start: FD RESULT24_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[24][0], fdvt_fd_out_loop24_0_golden, output_WDMA_WRA_buffer_size[24][0]);
	LOG_INF("bit true start: FD RESULT24_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[24][1], fdvt_fd_out_loop24_1_golden, output_WDMA_WRA_buffer_size[24][1]);
	LOG_INF("bit true start: FD RESULT24_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[24][2], fdvt_fd_out_loop24_2_golden, output_WDMA_WRA_buffer_size[24][2]);
	LOG_INF("bit true start: FD RESULT24_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[24][3], fdvt_fd_out_loop24_3_golden, output_WDMA_WRA_buffer_size[24][3]);
	LOG_INF("bit true start: FD RESULT25_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[25][0], fdvt_fd_out_loop25_0_golden, output_WDMA_WRA_buffer_size[25][0]);
	LOG_INF("bit true start: FD RESULT25_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[25][2], fdvt_fd_out_loop25_2_golden, output_WDMA_WRA_buffer_size[25][2]);
	LOG_INF("bit true start: FD RESULT26_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[26][0], fdvt_fd_out_loop26_0_golden, output_WDMA_WRA_buffer_size[26][0]);
	LOG_INF("bit true start: FD RESULT26_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[26][1], fdvt_fd_out_loop26_1_golden, output_WDMA_WRA_buffer_size[26][1]);
	LOG_INF("bit true start: FD RESULT27_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[27][0], fdvt_fd_out_loop27_0_golden, output_WDMA_WRA_buffer_size[27][0]);
	LOG_INF("bit true start: FD RESULT27_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[27][2], fdvt_fd_out_loop27_2_golden, output_WDMA_WRA_buffer_size[27][2]);
	LOG_INF("bit true start: FD RESULT28_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[28][0], fdvt_fd_out_loop28_0_golden, output_WDMA_WRA_buffer_size[28][0]);
	LOG_INF("bit true start: FD RESULT28_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[28][1], fdvt_fd_out_loop28_1_golden, output_WDMA_WRA_buffer_size[28][1]);
	LOG_INF("bit true start: FD RESULT29_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[29][0], fdvt_fd_out_loop29_0_golden, output_WDMA_WRA_buffer_size[29][0]);
	LOG_INF("bit true start: FD RESULT30_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[30][0], fdvt_fd_out_loop30_0_golden, output_WDMA_WRA_buffer_size[30][0]);
	LOG_INF("bit true start: FD RESULT31_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[31][0], fdvt_fd_out_loop31_0_golden, output_WDMA_WRA_buffer_size[31][0]);
	LOG_INF("bit true start: FD RESULT32_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[32][0], fdvt_fd_out_loop32_0_golden, output_WDMA_WRA_buffer_size[32][0]);
	LOG_INF("bit true start: FD RESULT33_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[33][0], fdvt_fd_out_loop33_0_golden, output_WDMA_WRA_buffer_size[33][0]);
	LOG_INF("bit true start: FD RESULT34_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[34][0], fdvt_fd_out_loop34_0_golden, output_WDMA_WRA_buffer_size[34][0]);
	LOG_INF("bit true start: FD RESULT35_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[35][0], fdvt_fd_out_loop35_0_golden, output_WDMA_WRA_buffer_size[35][0]);
	LOG_INF("bit true start: FD RESULT35_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[35][1], fdvt_fd_out_loop35_1_golden, output_WDMA_WRA_buffer_size[35][1]);
	LOG_INF("bit true start: FD RESULT36_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][0], fdvt_fd_out_loop36_0_golden, output_WDMA_WRA_buffer_size[36][0], 832, 832);
	LOG_INF("bit true start: FD RESULT36_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][1], fdvt_fd_out_loop36_1_golden, output_WDMA_WRA_buffer_size[36][1], 832, 832);
	LOG_INF("bit true start: FD RESULT36_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][2], fdvt_fd_out_loop36_2_golden, output_WDMA_WRA_buffer_size[36][2], 832, 832);
	LOG_INF("bit true start: FD RESULT36_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[36][3], fdvt_fd_out_loop36_3_golden, output_WDMA_WRA_buffer_size[36][3], 832, 832);
	LOG_INF("bit true start: FD RESULT37_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[37][0], fdvt_fd_out_loop37_0_golden, output_WDMA_WRA_buffer_size[37][0], 416, 416);
	LOG_INF("bit true start: FD RESULT37_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[37][1], fdvt_fd_out_loop37_1_golden, output_WDMA_WRA_buffer_size[37][1], 416, 416);
	LOG_INF("bit true start: FD RESULT38_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[38][0], fdvt_fd_out_loop38_0_golden, output_WDMA_WRA_buffer_size[38][0], 832, 832);
	LOG_INF("bit true start: FD RESULT38_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[38][1], fdvt_fd_out_loop38_1_golden, output_WDMA_WRA_buffer_size[38][1], 832, 832);
*/

#if FD_Unit_Test
	LOG_INF("bit true start: FD RESULT39_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[39][0], fdvt_fd_out_loop39_0_golden, sizeof(fdvt_fd_out_loop39_0_golden));
#endif

/*
	LOG_INF("bit true start: FD RESULT40_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[40][0], fdvt_fd_out_loop40_0_golden, output_WDMA_WRA_buffer_size[40][0]);
	LOG_INF("bit true start: FD RESULT40_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[40][2], fdvt_fd_out_loop40_2_golden, output_WDMA_WRA_buffer_size[40][2]);
	LOG_INF("bit true start: FD RESULT41_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[41][0], fdvt_fd_out_loop41_0_golden, output_WDMA_WRA_buffer_size[41][0]);
	LOG_INF("bit true start: FD RESULT41_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[41][2], fdvt_fd_out_loop41_2_golden, output_WDMA_WRA_buffer_size[41][2]);
	LOG_INF("bit true start: FD RESULT42_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[42][0], fdvt_fd_out_loop42_0_golden, output_WDMA_WRA_buffer_size[42][0]);
	LOG_INF("bit true start: FD RESULT43_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[43][0], fdvt_fd_out_loop43_0_golden, output_WDMA_WRA_buffer_size[43][0]);
	LOG_INF("bit true start: FD RESULT43_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[43][1], fdvt_fd_out_loop43_1_golden, output_WDMA_WRA_buffer_size[43][1]);
	LOG_INF("bit true start: FD RESULT43_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[43][2], fdvt_fd_out_loop43_2_golden, output_WDMA_WRA_buffer_size[43][2]);
	LOG_INF("bit true start: FD RESULT43_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[43][3], fdvt_fd_out_loop43_3_golden, output_WDMA_WRA_buffer_size[43][3]);
	LOG_INF("bit true start: FD RESULT44_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[44][0], fdvt_fd_out_loop44_0_golden, output_WDMA_WRA_buffer_size[44][0]);
	LOG_INF("bit true start: FD RESULT44_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[44][1], fdvt_fd_out_loop44_1_golden, output_WDMA_WRA_buffer_size[44][1]);
	LOG_INF("bit true start: FD RESULT44_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[44][2], fdvt_fd_out_loop44_2_golden, output_WDMA_WRA_buffer_size[44][2]);
	LOG_INF("bit true start: FD RESULT44_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[44][3], fdvt_fd_out_loop44_3_golden, output_WDMA_WRA_buffer_size[44][3]);
	LOG_INF("bit true start: FD RESULT45_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[45][0], fdvt_fd_out_loop45_0_golden, output_WDMA_WRA_buffer_size[45][0]);
	LOG_INF("bit true start: FD RESULT45_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[45][2], fdvt_fd_out_loop45_2_golden, output_WDMA_WRA_buffer_size[45][2]);
	LOG_INF("bit true start: FD RESULT46_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[46][0], fdvt_fd_out_loop46_0_golden, output_WDMA_WRA_buffer_size[46][0]);
	LOG_INF("bit true start: FD RESULT46_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[46][1], fdvt_fd_out_loop46_1_golden, output_WDMA_WRA_buffer_size[46][1]);
	LOG_INF("bit true start: FD RESULT47_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[47][0], fdvt_fd_out_loop47_0_golden, output_WDMA_WRA_buffer_size[47][0]);
	LOG_INF("bit true start: FD RESULT47_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[47][2], fdvt_fd_out_loop47_2_golden, output_WDMA_WRA_buffer_size[47][2]);
	LOG_INF("bit true start: FD RESULT48_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[48][0], fdvt_fd_out_loop48_0_golden, output_WDMA_WRA_buffer_size[48][0]);
	LOG_INF("bit true start: FD RESULT48_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[48][1], fdvt_fd_out_loop48_1_golden, output_WDMA_WRA_buffer_size[48][1]);
	LOG_INF("bit true start: FD RESULT49_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[49][0], fdvt_fd_out_loop49_0_golden, output_WDMA_WRA_buffer_size[49][0]);
	LOG_INF("bit true start: FD RESULT50_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[50][0], fdvt_fd_out_loop50_0_golden, output_WDMA_WRA_buffer_size[50][0]);
	LOG_INF("bit true start: FD RESULT51_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[51][0], fdvt_fd_out_loop51_0_golden, output_WDMA_WRA_buffer_size[51][0]);
	LOG_INF("bit true start: FD RESULT52_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[52][0], fdvt_fd_out_loop52_0_golden, output_WDMA_WRA_buffer_size[52][0]);
	LOG_INF("bit true start: FD RESULT53_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[53][0], fdvt_fd_out_loop53_0_golden, output_WDMA_WRA_buffer_size[53][0]);
	LOG_INF("bit true start: FD RESULT54_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[54][0], fdvt_fd_out_loop54_0_golden, output_WDMA_WRA_buffer_size[54][0]);
	LOG_INF("bit true start: FD RESULT55_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[55][0], fdvt_fd_out_loop55_0_golden, output_WDMA_WRA_buffer_size[55][0]);
	LOG_INF("bit true start: FD RESULT55_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[55][1], fdvt_fd_out_loop55_1_golden, output_WDMA_WRA_buffer_size[55][1]);
	LOG_INF("bit true start: FD RESULT56_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][0], fdvt_fd_out_loop56_0_golden, output_WDMA_WRA_buffer_size[56][0], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT56_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][1], fdvt_fd_out_loop56_1_golden, output_WDMA_WRA_buffer_size[56][1], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT56_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][2], fdvt_fd_out_loop56_2_golden, output_WDMA_WRA_buffer_size[56][2], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT56_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[56][3], fdvt_fd_out_loop56_3_golden, output_WDMA_WRA_buffer_size[56][3], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT57_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][0], fdvt_fd_out_loop57_0_golden, output_WDMA_WRA_buffer_size[57][0], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT57_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][1], fdvt_fd_out_loop57_1_golden, output_WDMA_WRA_buffer_size[57][1], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT57_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][2], fdvt_fd_out_loop57_2_golden, output_WDMA_WRA_buffer_size[57][2], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT57_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[57][3], fdvt_fd_out_loop57_3_golden, output_WDMA_WRA_buffer_size[57][3], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT58_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[58][0], fdvt_fd_out_loop58_0_golden, output_WDMA_WRA_buffer_size[58][0], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT58_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[58][1], fdvt_fd_out_loop58_1_golden, output_WDMA_WRA_buffer_size[58][1], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT59_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][0], fdvt_fd_out_loop59_0_golden, output_WDMA_WRA_buffer_size[59][0], 800, 800*4);
	LOG_INF("bit true start: FD RESULT59_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[59][1], fdvt_fd_out_loop59_1_golden, output_WDMA_WRA_buffer_size[59][1], 800, 800*4);
	LOG_INF("bit true start: FD RESULT60_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[60][0], fdvt_fd_out_loop60_0_golden, output_WDMA_WRA_buffer_size[60][0], 800, 800*4);
	LOG_INF("bit true start: FD RESULT60_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[60][1], fdvt_fd_out_loop60_1_golden, output_WDMA_WRA_buffer_size[60][1], 800, 800*4);
	LOG_INF("bit true start: FD RESULT61_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[61][0], fdvt_fd_out_loop61_0_golden, output_WDMA_WRA_buffer_size[61][0], 800, 800*4);
	LOG_INF("bit true start: FD RESULT62_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][0], fdvt_fd_out_loop62_0_golden, output_WDMA_WRA_buffer_size[62][0], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT62_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[62][1], fdvt_fd_out_loop62_1_golden, output_WDMA_WRA_buffer_size[62][1], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT63_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[63][0], fdvt_fd_out_loop63_0_golden, output_WDMA_WRA_buffer_size[63][0], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT63_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[63][1], fdvt_fd_out_loop63_1_golden, output_WDMA_WRA_buffer_size[63][1], 1600, 1600*4);
	LOG_INF("bit true start: FD RESULT64_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck_withDummy((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[64][0], fdvt_fd_out_loop64_0_golden, output_WDMA_WRA_buffer_size[64][0], 1600, 1600*4);
*/

#if FD_Unit_Test
	LOG_INF("bit true start: FD RESULT65_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[65][0], fdvt_fd_out_loop65_0_golden, sizeof(fdvt_fd_out_loop65_0_golden));
#endif

	// ATTR PART
	//LOG_INF("bit true start: YUV_RGB Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[0], (unsigned int *)&fdvt_ATTR_yuv2rgb_config[0], fdvt_attrmode_yuv2rgb_config_size);

#if ATTR_Unit_Test
	LOG_INF("bit true start: R Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_R_Result_VA, attr_frame_R_golden, sizeof(attr_frame_R_golden));
	LOG_INF("bit true start: G Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_G_Result_VA, attr_frame_G_golden, sizeof(attr_frame_G_golden));
	LOG_INF("bit true start: B Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_B_Result_VA, attr_frame_B_golden, sizeof(attr_frame_B_golden));
#endif

	//LOG_INF("bit true start: RS Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->ATTRMODE_RS_Config_VA[0], (unsigned int *)&fdvt_ATTR_rs_config[0], fdvt_attrmode_rs_config_size);

#if ATTR_Unit_Test
	LOG_INF("bit true start: RGB Frames --- Pyramid0_R");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_R_Result_VA, attr_frame_R_pyramid0_golden, sizeof(attr_frame_R_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_G");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_G_Result_VA, attr_frame_G_pyramid0_golden, sizeof(attr_frame_G_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_B");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_B_Result_VA, attr_frame_B_pyramid0_golden, sizeof(attr_frame_B_pyramid0_golden));
#endif

	//LOG_INF("bit true start: FD Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->ATTRMODE_FD_Config_VA[0], (unsigned int *)&fdvt_ATTR_fd_config[0], fdvt_attrmode_fd_config_size);
/*
	LOG_INF("bit true start: FD RESULT00_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[0][0], attr_fd_out_loop00_0_golden, attr_output_WDMA_WRA_buffer_size[0][0]);
	LOG_INF("bit true start: FD RESULT00_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[0][2], attr_fd_out_loop00_2_golden, attr_output_WDMA_WRA_buffer_size[0][2]);
	LOG_INF("bit true start: FD RESULT01_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[1][0], attr_fd_out_loop01_0_golden, attr_output_WDMA_WRA_buffer_size[1][0]);
	LOG_INF("bit true start: FD RESULT01_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[1][2], attr_fd_out_loop01_2_golden, attr_output_WDMA_WRA_buffer_size[1][2]);
	LOG_INF("bit true start: FD RESULT02_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[2][0], attr_fd_out_loop02_0_golden, attr_output_WDMA_WRA_buffer_size[2][0]);
	LOG_INF("bit true start: FD RESULT03_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[3][0], attr_fd_out_loop03_0_golden, attr_output_WDMA_WRA_buffer_size[3][0]);
	LOG_INF("bit true start: FD RESULT03_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[3][1], attr_fd_out_loop03_1_golden, attr_output_WDMA_WRA_buffer_size[3][1]);
	LOG_INF("bit true start: FD RESULT03_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[3][2], attr_fd_out_loop03_2_golden, attr_output_WDMA_WRA_buffer_size[3][2]);
	LOG_INF("bit true start: FD RESULT03_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[3][3], attr_fd_out_loop03_3_golden, attr_output_WDMA_WRA_buffer_size[3][3]);
	LOG_INF("bit true start: FD RESULT04_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[4][0], attr_fd_out_loop04_0_golden, attr_output_WDMA_WRA_buffer_size[4][0]);
	LOG_INF("bit true start: FD RESULT04_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[4][1], attr_fd_out_loop04_1_golden, attr_output_WDMA_WRA_buffer_size[4][1]);
	LOG_INF("bit true start: FD RESULT04_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[4][2], attr_fd_out_loop04_2_golden, attr_output_WDMA_WRA_buffer_size[4][2]);
	LOG_INF("bit true start: FD RESULT04_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[4][3], attr_fd_out_loop04_3_golden, attr_output_WDMA_WRA_buffer_size[4][3]);
	LOG_INF("bit true start: FD RESULT05_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[5][0], attr_fd_out_loop05_0_golden, attr_output_WDMA_WRA_buffer_size[5][0]);
	LOG_INF("bit true start: FD RESULT05_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[5][2], attr_fd_out_loop05_2_golden, attr_output_WDMA_WRA_buffer_size[5][2]);
	LOG_INF("bit true start: FD RESULT06_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[6][0], attr_fd_out_loop06_0_golden, attr_output_WDMA_WRA_buffer_size[6][0]);
	LOG_INF("bit true start: FD RESULT06_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[6][1], attr_fd_out_loop06_1_golden, attr_output_WDMA_WRA_buffer_size[6][1]);
	LOG_INF("bit true start: FD RESULT07_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[7][0], attr_fd_out_loop07_0_golden, attr_output_WDMA_WRA_buffer_size[7][0]);
	LOG_INF("bit true start: FD RESULT07_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[7][2], attr_fd_out_loop07_2_golden, attr_output_WDMA_WRA_buffer_size[7][2]);
	LOG_INF("bit true start: FD RESULT08_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[8][0], attr_fd_out_loop08_0_golden, attr_output_WDMA_WRA_buffer_size[8][0]);
	LOG_INF("bit true start: FD RESULT08_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[8][1], attr_fd_out_loop08_1_golden, attr_output_WDMA_WRA_buffer_size[8][1]);
	LOG_INF("bit true start: FD RESULT09_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[9][0], attr_fd_out_loop09_0_golden, attr_output_WDMA_WRA_buffer_size[9][0]);
	LOG_INF("bit true start: FD RESULT10_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[10][0], attr_fd_out_loop10_0_golden, attr_output_WDMA_WRA_buffer_size[10][0]);
	LOG_INF("bit true start: FD RESULT11_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[11][0], attr_fd_out_loop11_0_golden, attr_output_WDMA_WRA_buffer_size[11][0]);
	LOG_INF("bit true start: FD RESULT12_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[12][0], attr_fd_out_loop12_0_golden, attr_output_WDMA_WRA_buffer_size[12][0]);
	LOG_INF("bit true start: FD RESULT13_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[13][0], attr_fd_out_loop13_0_golden, attr_output_WDMA_WRA_buffer_size[13][0]);
	LOG_INF("bit true start: FD RESULT14_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[14][0], attr_fd_out_loop14_0_golden, attr_output_WDMA_WRA_buffer_size[14][0]);
	LOG_INF("bit true start: FD RESULT15_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[15][0], attr_fd_out_loop15_0_golden, attr_output_WDMA_WRA_buffer_size[15][0]);
	LOG_INF("bit true start: FD RESULT15_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[15][1], attr_fd_out_loop15_1_golden, attr_output_WDMA_WRA_buffer_size[15][1]);
*/

#if ATTR_Unit_Test
	LOG_INF("bit true start: FD RESULT16_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[16][0], attr_fd_out_loop16_0_golden, attr_output_WDMA_WRA_buffer_size[16][0]);
	LOG_INF("bit true start: FD RESULT17_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[17][0], attr_fd_out_loop17_0_golden, attr_output_WDMA_WRA_buffer_size[17][0]);
#endif

	// POSE PART
	//LOG_INF("bit true start: YUV_RGB Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[0], (unsigned int *)&fdvt_POSE_yuv2rgb_config[0], fdvt_posemode_yuv2rgb_config_size);

#if POSE_Unit_Test
	LOG_INF("bit true start: R Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_R_Result_VA, pose_frame_R_golden, sizeof(pose_frame_R_golden));
	LOG_INF("bit true start: G Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_G_Result_VA, pose_frame_G_golden, sizeof(pose_frame_G_golden));
	LOG_INF("bit true start: B Frames");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->YUV2RGB_B_Result_VA, pose_frame_B_golden, sizeof(pose_frame_B_golden));
#endif

	//LOG_INF("bit true start: RS Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->POSEMODE_RS_Config_VA[0], (unsigned int *)&fdvt_POSE_rs_config[0], fdvt_posemode_rs_config_size);

#if POSE_Unit_Test
	LOG_INF("bit true start: RGB Frames --- Pyramid0_R");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_R_Result_VA, pose_frame_R_pyramid0_golden, sizeof(pose_frame_R_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_G");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_G_Result_VA, pose_frame_G_pyramid0_golden, sizeof(pose_frame_G_pyramid0_golden));
	LOG_INF("bit true start: RGB Frames --- Pyramid0_B");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_B_Result_VA, pose_frame_B_pyramid0_golden, sizeof(pose_frame_B_pyramid0_golden));
#endif

	//LOG_INF("bit true start: FD Config");
	//errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Para->POSEMODE_FD_Config_VA[0], (unsigned int *)&fdvt_POSE_fd_config[0], fdvt_posemode_fd_config_size);
/*
	LOG_INF("bit true start: FD RESULT00_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[0][0], pose_fd_out_loop00_0_golden, pose_output_WDMA_WRA_buffer_size[0][0]);
	LOG_INF("bit true start: FD RESULT00_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[0][2], pose_fd_out_loop00_2_golden, pose_output_WDMA_WRA_buffer_size[0][2]);
	LOG_INF("bit true start: FD RESULT01_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[1][0], pose_fd_out_loop01_0_golden, pose_output_WDMA_WRA_buffer_size[1][0]);
	LOG_INF("bit true start: FD RESULT01_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[1][2], pose_fd_out_loop01_2_golden, pose_output_WDMA_WRA_buffer_size[1][2]);
	LOG_INF("bit true start: FD RESULT02_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[2][0], pose_fd_out_loop02_0_golden, pose_output_WDMA_WRA_buffer_size[2][0]);
	LOG_INF("bit true start: FD RESULT03_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[3][0], pose_fd_out_loop03_0_golden, pose_output_WDMA_WRA_buffer_size[3][0]);
	LOG_INF("bit true start: FD RESULT03_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[3][1], pose_fd_out_loop03_1_golden, pose_output_WDMA_WRA_buffer_size[3][1]);
	LOG_INF("bit true start: FD RESULT03_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[3][2], pose_fd_out_loop03_2_golden, pose_output_WDMA_WRA_buffer_size[3][2]);
	LOG_INF("bit true start: FD RESULT03_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[3][3], pose_fd_out_loop03_3_golden, pose_output_WDMA_WRA_buffer_size[3][3]);
	LOG_INF("bit true start: FD RESULT04_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[4][0], pose_fd_out_loop04_0_golden, pose_output_WDMA_WRA_buffer_size[4][0]);
	LOG_INF("bit true start: FD RESULT04_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[4][1], pose_fd_out_loop04_1_golden, pose_output_WDMA_WRA_buffer_size[4][1]);
	LOG_INF("bit true start: FD RESULT04_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[4][2], pose_fd_out_loop04_2_golden, pose_output_WDMA_WRA_buffer_size[4][2]);
	LOG_INF("bit true start: FD RESULT04_3");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[4][3], pose_fd_out_loop04_3_golden, pose_output_WDMA_WRA_buffer_size[4][3]);
	LOG_INF("bit true start: FD RESULT05_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[5][0], pose_fd_out_loop05_0_golden, pose_output_WDMA_WRA_buffer_size[5][0]);
	LOG_INF("bit true start: FD RESULT05_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[5][2], pose_fd_out_loop05_2_golden, pose_output_WDMA_WRA_buffer_size[5][2]);
	LOG_INF("bit true start: FD RESULT06_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[6][0], pose_fd_out_loop06_0_golden, pose_output_WDMA_WRA_buffer_size[6][0]);
	LOG_INF("bit true start: FD RESULT06_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[6][1], pose_fd_out_loop06_1_golden, pose_output_WDMA_WRA_buffer_size[6][1]);
	LOG_INF("bit true start: FD RESULT07_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[7][0], pose_fd_out_loop07_0_golden, pose_output_WDMA_WRA_buffer_size[7][0]);
	LOG_INF("bit true start: FD RESULT07_2");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[7][2], pose_fd_out_loop07_2_golden, pose_output_WDMA_WRA_buffer_size[7][2]);
	LOG_INF("bit true start: FD RESULT08_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[8][0], pose_fd_out_loop08_0_golden, pose_output_WDMA_WRA_buffer_size[8][0]);
	LOG_INF("bit true start: FD RESULT08_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[8][1], pose_fd_out_loop08_1_golden, pose_output_WDMA_WRA_buffer_size[8][1]);
	LOG_INF("bit true start: FD RESULT09_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[9][0], pose_fd_out_loop09_0_golden, pose_output_WDMA_WRA_buffer_size[9][0]);
	LOG_INF("bit true start: FD RESULT10_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[10][0], pose_fd_out_loop10_0_golden, pose_output_WDMA_WRA_buffer_size[10][0]);
	LOG_INF("bit true start: FD RESULT11_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[11][0], pose_fd_out_loop11_0_golden, pose_output_WDMA_WRA_buffer_size[11][0]);
	LOG_INF("bit true start: FD RESULT12_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[12][0], pose_fd_out_loop12_0_golden, pose_output_WDMA_WRA_buffer_size[12][0]);
	LOG_INF("bit true start: FD RESULT13_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[13][0], pose_fd_out_loop13_0_golden, pose_output_WDMA_WRA_buffer_size[13][0]);
	LOG_INF("bit true start: FD RESULT14_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[14][0], pose_fd_out_loop14_0_golden, pose_output_WDMA_WRA_buffer_size[14][0]);
	LOG_INF("bit true start: FD RESULT15_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[15][0], pose_fd_out_loop15_0_golden, pose_output_WDMA_WRA_buffer_size[15][0]);
	LOG_INF("bit true start: FD RESULT15_1");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[15][1], pose_fd_out_loop15_1_golden, pose_output_WDMA_WRA_buffer_size[15][1]);
*/

#if POSE_Unit_Test
	LOG_INF("bit true start: FD RESULT16_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[16][0], pose_fd_out_loop16_0_golden, pose_output_WDMA_WRA_buffer_size[16][0]);
	LOG_INF("bit true start: FD RESULT17_0");
	errCount_FDVT_Result += FDVT_BitTrueCheck((MUINT32 *)g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[17][0], pose_fd_out_loop17_0_golden, pose_output_WDMA_WRA_buffer_size[17][0]);
#endif

	//while(1);
	if (errCount_FDVT_Result != 0)
	{
		LOG_INF("fd result bit true fail!! Err Count: %d", errCount_FDVT_Result);
	}

	if ((errCount_FDVT_Result) == 0)
	{
		LOG_INF("FDVT Bit True Pass !!\n");
		return 0;
	}
	else return 1;
}
#endif

void FDVT_ReleaseBuffer()
{
    MUINT8 i=0, j=0;
    FDVT_FreeMem_DramBuffer();
    FDVT_FreeMem_OutputBuffer();
    FDVT_FreeMem_FDDMABuffer();

    g_FdDrv_Para->FDMODE_FD_Config_VA = NULL;
    g_FdDrv_Para->FDMODE_RS_Config_VA = NULL;
    g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA = NULL;

    for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->ATTRMODE_FD_Config_VA[i] = NULL;
	    g_FdDrv_Para->ATTRMODE_RS_Config_VA[i] = NULL;
	    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[i] = NULL;

	    g_FdDrv_Para->POSEMODE_FD_Config_VA[i] = NULL;
	    g_FdDrv_Para->POSEMODE_RS_Config_VA[i] = NULL;
	    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[i] = NULL;
    }

    g_FdDrv_Para->YUV2RGB_R_Result_VA = NULL;
    g_FdDrv_Para->YUV2RGB_G_Result_VA = NULL;
    g_FdDrv_Para->YUV2RGB_B_Result_VA = NULL;

    g_FdDrv_Para->RS_Pyramid0_R_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid0_G_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid0_B_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid1_R_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid1_G_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid1_B_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid2_R_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid2_G_Result_VA = NULL;
    g_FdDrv_Para->RS_Pyramid2_B_Result_VA = NULL;

    for(i=0; i < fdvt_fd_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[i][j] = NULL;
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->fd_kernel_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->fd_kernel_PA[i][j] = NULL;
	    }
    }

    for(i=0; i < fdvt_attr_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->attr_out_hw_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->attr_out_hw_PA[i][j] = NULL;
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->attr_kernel_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->attr_kernel_PA[i][j] = NULL;
	    }
    }

    for(i=0; i < fdvt_pose_loop_num; i++)
    {
	    for(j=0; j < output_WDMA_WRA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->pose_out_hw_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->pose_out_hw_PA[i][j] = NULL;
	    }
	    for(j=0; j < kernel_RDMA_RA_num ; j++)
	    {
	        g_FdDrv_Fd_DMA_Para->pose_kernel_VA[i][j] = NULL;
	        g_FdDrv_Fd_DMA_Para->pose_kernel_PA[i][j] = NULL;
	    }
    }

    for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Fd_DMA_Para->race_out_hw_VA[i] = NULL;
	    g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[i] = NULL;

	    g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[i] = NULL;
	    g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[i] = NULL;
    }

    g_FdDrv_Para->FDMODE_FD_Config_PA = NULL;
    g_FdDrv_Para->FDMODE_RS_Config_PA = NULL;
    g_FdDrv_Para->FDMODE_YUV2RGB_Config_PA = NULL;

    for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Para->ATTRMODE_FD_Config_PA[i] = NULL;
	    g_FdDrv_Para->ATTRMODE_RS_Config_PA[i] = NULL;
	    g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[i] = NULL;

	    g_FdDrv_Para->POSEMODE_FD_Config_PA[i] = NULL;
	    g_FdDrv_Para->POSEMODE_RS_Config_PA[i] = NULL;
	    g_FdDrv_Para->POSEMODE_YUV2RGB_Config_PA[i] = NULL;
    }

    g_FdDrv_Para->YUV2RGB_R_Result_PA = NULL;
    g_FdDrv_Para->YUV2RGB_G_Result_PA = NULL;
    g_FdDrv_Para->YUV2RGB_B_Result_PA = NULL;

    g_FdDrv_Para->RS_Pyramid0_R_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid0_G_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid0_B_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid1_R_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid1_G_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid1_B_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid2_R_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid2_G_Result_PA = NULL;
    g_FdDrv_Para->RS_Pyramid2_B_Result_PA = NULL;

    for(i=0; i < MAX_ENQUE_FRAME_NUM; i++)
    {
	    g_FdDrv_Fd_DMA_Para->race_out_hw_PA[i] = NULL;
	    g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[i] = NULL;

	    g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[i] = NULL;
	    g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[i] = NULL;
    }

    g_FdDrv_Attr_Para->ReadIdx = 0;
    g_FdDrv_Attr_Para->WriteIdx = 0;

    g_FdDrv_Pose_Para->ReadIdx = 0;
    g_FdDrv_Pose_Para->WriteIdx = 0;
}

MINT32 FDVT_Imem_alloc(MUINT32 size,MINT32 *memId,MUINT8 **vAddr,MUINTPTR *pAddr,bool isSecure)
{
    MINT32 Ret = 0;
    if ( NULL == g_FdvtImemDrv ) {
        g_FdvtImemDrv = DipIMemDrv::createInstance();
        g_FdvtImemDrv->init();
    }
    //
    Fdvt_Imem_Buf_Info.size = size;
    Fdvt_Imem_Buf_Info.useNoncache = 1;

    if (isSecure == 1)
    {
        Ret = g_FdvtImemDrv->allocSecureBuf(&Fdvt_Imem_Buf_Info);
        if (Ret != 0)
        {
            LOG_INF("Imem Allocate Secure Handler Fail! (%d)", Ret);
            abort();
        }
        Fdvt_Imem_Buf_Info.secHandle = (MUINT32)Fdvt_Imem_Buf_Info.phyAddr;
        *memId = Fdvt_Imem_Buf_Info.memID;
        *vAddr = 0x0;
        *pAddr = (MUINTPTR)Fdvt_Imem_Buf_Info.phyAddr;
    }
    else
    {
        Ret = g_FdvtImemDrv->allocVirtBuf(&Fdvt_Imem_Buf_Info);
        if (Ret != 0)
        {
            LOG_INF("Imem Allocate Virtual Buffer Fail! (%d)", Ret);
            abort();
        }
        *memId = Fdvt_Imem_Buf_Info.memID;
        *vAddr = (MUINT8 *)Fdvt_Imem_Buf_Info.virtAddr;
        //
        Ret = g_FdvtImemDrv->mapPhyAddr(&Fdvt_Imem_Buf_Info);
        if (Ret != 0)
        {
            LOG_INF("Imem Map Physical Address Fail! (%d)", Ret);
            abort();
        }
        *pAddr = (MUINTPTR)Fdvt_Imem_Buf_Info.phyAddr;
    }
    Fdvt_Imem_AllocNum ++;

    /*MY_LOGD("Fdvt_Imem_AllocNum(%d)\n",Fdvt_Imem_AllocNum);*/
    LOG_INF("vAddr(%p), pAddr(%p), size(%d), memId(%d), Fdvt_Imem_AllocNum(%d)\n",*vAddr,*pAddr,size,*memId,Fdvt_Imem_AllocNum);

    return 0;
}

MINT32 FDVT_Imem_free(MUINT8 *vAddr, MUINTPTR phyAddr,MUINT32 size,MINT32 memId,bool isSecure)
{
    Fdvt_Imem_Buf_Info.size = size;
    Fdvt_Imem_Buf_Info.memID = memId;
    Fdvt_Imem_Buf_Info.virtAddr = (MUINTPTR)vAddr;
    Fdvt_Imem_Buf_Info.phyAddr = (MUINTPTR)phyAddr;
    //

    if(g_FdvtImemDrv)
    {
        if (isSecure == 1)
        {
            if(g_FdvtImemDrv->freeSecureBuf(&Fdvt_Imem_Buf_Info))
                LOG_INF("Imem Free SecureBuf Fail!");
        }
        else
        {
            if(g_FdvtImemDrv->unmapPhyAddr(&Fdvt_Imem_Buf_Info))
                LOG_INF("Imem Unmap Physical Address Fail!");

            if(g_FdvtImemDrv->freeVirtBuf(&Fdvt_Imem_Buf_Info))
                LOG_INF("Imem Free Virtual Buffer Fail!");
        }

        if(Fdvt_Imem_AllocNum)
        {
            Fdvt_Imem_AllocNum--;
            if(Fdvt_Imem_AllocNum==0)
            {
                g_FdvtImemDrv->uninit();
                g_FdvtImemDrv = NULL;
            }
        }
    }
    else
    {
        LOG_ERR("No FDVT ImemDrv!");
    }

    /*MY_LOGD("Fdvt_Imem_AllocNum(%d)\n",Fdvt_Imem_AllocNum);*/

    return 0;
}

MBOOL FdvtDrvImp::init(EGNInitInfo InitInfo, const char* userName)
{
    MBOOL Result = MTRUE;
    MUINT32 resetModule;
    int32_t old_cnt;
    //
    android::Mutex::Autolock lock(m_FdvtInitMutex);
    //

    char value[PROPERTY_VALUE_MAX] = {'\0'};
    property_get("vendor.fdvt.debug.enable", value, "0");
    g_isFDVTLogEnable = atoi(value);
    g_isFDVTSecure = InitInfo.IS_FDVT_SECURE;
    g_FDVTSecMemType = InitInfo.SEC_MEM_TYPE;
    g_isReleased = MTRUE;
    if( (userName==NULL) || (strlen(userName)<1) || (strlen(userName) >= MAX_USER_NAME_SIZE))
    {
        LOG_ERR("Plz add userName if you want to use fdvt driver\n");
        return MFALSE;
    }
    //
    LOG_INF("+,m_UserCnt(%d), curUser(%s).", this->m_UserCnt,userName);
    //
    if(this->m_UserCnt > 0)
    {
        if(this->m_UserCnt < MAX_USER_NUMBER){
            strncpy((char*)this->m_UserName[this->m_UserCnt], userName, MAX_USER_NAME_SIZE - 1);
            old_cnt = android_atomic_inc(&m_UserCnt);
            LOG_INF(" - X. m_UserCnt: %d.", this->m_UserCnt);
            return Result;
        }
        else{
            LOG_ERR("m_userCnt is over upper bound\n");
            return MFALSE;
        }
    }

    // Open fdvt device
    this->m_Fd = open(FDVT_DRV_DEV_NAME, O_RDWR);
    if (this->m_Fd < 0)    // 1st time open failed.
    {
        LOG_ERR("FDVT kernel 1st open fail, errno(%d):%s.", errno, strerror(errno));
        // Try again, using "Read Only".
        this->m_Fd = open(FDVT_DRV_DEV_NAME, O_RDONLY);
        if (this->m_Fd < 0) // 2nd time open failed.
        {
            LOG_ERR("FDVT kernel 2nd open fail, errno(%d):%s.", errno, strerror(errno));
            Result = MFALSE;
            goto EXIT;
        }
        else
            this->m_regRWMode=FDVT_DRV_R_ONLY;
    }
    else    // 1st time open success.   // Sometimes GDMA will go this path, too. e.g. File Manager -> Phone Storage -> Photo.
    {
        // fd opened only once at the very 1st init
        m_pFdvtHwRegAddr = (MUINT32 *) mmap(0, FDVT_REG_RANGE, (PROT_READ | PROT_WRITE | PROT_NOCACHE), MAP_SHARED, this->m_Fd, FDVT_BASE_HW);
        if(m_pFdvtHwRegAddr == MAP_FAILED)
        {
            LOG_ERR("FDVT mmap fail, errno(%d):%s", errno, strerror(errno));
            Result = MFALSE;
            goto EXIT;
        }
        this->m_regRWMode=FDVT_DRV_RW_MMAP;
    }

    g_FdDrv_Para->RPN_ANCHOR_THRD = InitInfo.feature_threshold;
    FDVT_getSizeOfData(InitInfo.MAX_SRC_IMG_WIDTH, InitInfo.MAX_SRC_IMG_HEIGHT);
    FDVT_allocateDramBuffer();
    FDVT_allocateOutputBuffer();
    FDVT_allocateFDDMABuffer();
    if (g_isFDVTSecure == 0)
    {
        FDVT_copyInputDataToBuffer();
    }
    //FDVT_logBufInfo();
    sem_init(&mEnque, 0, 1);

    g_FdDrv_Attr_Para->ReadIdx = 0;
    g_FdDrv_Attr_Para->WriteIdx = 0;
    g_FdDrv_Pose_Para->ReadIdx = 0;
    g_FdDrv_Pose_Para->WriteIdx = 0;

    if(ioctl(this->m_Fd, FDVT_RESET, NULL) < 0){
        LOG_ERR("FDVT Reset fail !!\n");
        Result = MFALSE;
        goto EXIT;
    }

    //
    strncpy((char*)this->m_UserName[this->m_UserCnt], userName, MAX_USER_NAME_SIZE - 1);
    old_cnt = android_atomic_inc(&m_UserCnt);

EXIT:

    //
    if (!Result)    // If some init step goes wrong.
    {
        if(this->m_Fd >= 0)
        {
            // unmap to avoid memory leakage
            munmap(m_pFdvtHwRegAddr, FDVT_REG_RANGE);

            close(this->m_Fd);
            this->m_Fd = -1;
            LOG_INF("close fdvt device Fd");
        }
    }

    LOG_DBG("-,ret: %d. mInitCount:(%d),m_pFdvtHwRegAddr(0x%p)", Result, this->m_UserCnt, (void*)m_pFdvtHwRegAddr);
    return Result;
}

//-----------------------------------------------------------------------------
MBOOL FdvtDrvImp::uninit(const char* userName)
{
    MBOOL Result = MTRUE;
    MUINT32 bMatch = 0;
    int32_t old_cnt;
    //
    android::Mutex::Autolock lock(m_FdvtInitMutex);
    //
    if((userName==NULL) || (strlen(userName)<1) || (strlen(userName) >= MAX_USER_NAME_SIZE))
    {
        LOG_ERR("Plz add userName if you want to uninit fdvt driver\n");
        return MFALSE;
    }
    //
    LOG_INF("-,m_UserCnt(%d),curUser(%s)", this->m_UserCnt,userName);

    //
    if(this->m_UserCnt <= 0)
    {
        LOG_ERR("no more user in FdvtDrv , curUser(%s)",userName);
        goto EXIT;
    }

    for(MUINT32 i=0;i<MAX_USER_NUMBER;i++){
        if(strcmp((const char*)this->m_UserName[i],userName) == 0){
            bMatch = i+1;   //avoid match at the very 1st
            break;
        }
    }

    if(!bMatch){
        LOG_ERR("no matching username:%s\n",userName);
        for(MUINT32 i=0;i<MAX_USER_NUMBER;i+=4)
           LOG_ERR("current user: %s, %s, %s, %s\n",this->m_UserName[i],this->m_UserName[i+1],this->m_UserName[i+2],this->m_UserName[i+3]);
        return MFALSE;
    }
    else
        this->m_UserName[bMatch-1][0] = '\0';

    //FDVT_Imem_free((MUINT8 *)g_FdvtTileBuffer.virtAddr, g_FdvtTileBuffer.phyAddr, g_FdvtTileBuffer.size, g_FdvtTileBuffer.memID);

    // More than one user
    old_cnt = android_atomic_dec(&m_UserCnt);

    if(this->m_UserCnt > 0)    // If there are still users, exit.
        goto EXIT;

    ::sem_destroy(&mEnque);
    FDVT_ReleaseBuffer();

    if(m_pFdvtHwRegAddr != MAP_FAILED){
         munmap(m_pFdvtHwRegAddr, FDVT_REG_RANGE);
    }

    //
    if(this->m_Fd >= 0)
    {
        close(this->m_Fd);
        this->m_Fd = -1;
        this->m_regRWMode=FDVT_DRV_R_ONLY;
    }

    //
EXIT:

    LOG_INF(" - X. ret: %d. m_UserCnt: %d.", Result, this->m_UserCnt);

    if(this->m_UserCnt!= 0){
        LOG_INF("current working user:\n");
        for(MUINT32 i=0;i<MAX_USER_NUMBER;i+=8)
            LOG_INF("current user: %s, %s, %s, %s, %s, %s, %s, %s\n"    \
            ,this->m_UserName[i],this->m_UserName[i+1],this->m_UserName[i+2],this->m_UserName[i+3]  \
            ,this->m_UserName[i+4],this->m_UserName[i+5],this->m_UserName[i+6],this->m_UserName[i+7]);
    }
    return Result;
}

#define FD_CHK()({\
    MINT32 Ret=0;\
    if(this->m_Fd < 0){\
        LOG_ERR("no fdvt device\n");\
        Ret = -1;\
    }\
    Ret;\
})

MBOOL FdvtDrvImp::waitIrq(FDVT_WAIT_IRQ_STRUCT* pWaitIrq)
{
    MINT32 Ret = 0;
    MUINT32 OrgTimeOut;
    FDVT_IRQ_CLEAR_ENUM OrgClr;
    FdvtDbgTimer dbgTmr("waitIrq");
    MUINT32 Ta=0,Tb=0;
    FDVT_WAIT_IRQ_STRUCT waitirq;
    LOG_DBG(" - E. Status(0x%08x),Timeout(%d).\n",pWaitIrq->Status, pWaitIrq->Timeout);
    if(-1 == FD_CHK()){
        return MFALSE;
    }
    waitirq.Clear=pWaitIrq->Clear;
    waitirq.Type=pWaitIrq->Type;
    waitirq.Status=pWaitIrq->Status;
    waitirq.Timeout=pWaitIrq->Timeout;
    waitirq.UserKey=pWaitIrq->UserKey;
    waitirq.ProcessID=pWaitIrq->ProcessID;
    waitirq.bDumpReg=pWaitIrq->bDumpReg;
    waitirq.isSecure=pWaitIrq->isSecure;

    while( waitirq.Timeout > 0 )//receive restart system call again
    {
        Ta=dbgTmr.getUs();
        Ret = ioctl(this->m_Fd,FDVT_WAIT_IRQ,&waitirq);
        Tb=dbgTmr.getUs();
        if( Ret== (-SIG_ERESTARTSYS) )
        {
            waitirq.Timeout=waitirq.Timeout - ((Tb-Ta)/1000);
            LOG_INF("ERESTARTSYS,Type(%d),Status(0x%08x),Timeout(%d us)\n",waitirq.Type, waitirq.Status, waitirq.Timeout);
        }
        else
        {
            break;
        }
    }

    if(Ret < 0) {
        LOG_ERR("FDVT_WAIT_IRQ fail(%d). Wait Status(0x%08x), Timeout(%d).\n", Ret,  pWaitIrq->Status, pWaitIrq->Timeout);
        return MFALSE;
    }

    return MTRUE;
}

MBOOL FdvtDrvImp::clearIrq(FDVT_CLEAR_IRQ_STRUCT* pClearIrq)
{
    MINT32 Ret;
    FDVT_CLEAR_IRQ_STRUCT clear;
    //
    LOG_DBG(" - E. user(%d), Status(%d)\n",pClearIrq->UserKey, pClearIrq->Status);
    if(-1 == FD_CHK()){
        return MFALSE;
    }

    memcpy(&clear, pClearIrq, sizeof(FDVT_CLEAR_IRQ_STRUCT));

    Ret = ioctl(this->m_Fd,FDVT_CLEAR_IRQ,&clear);
    if(Ret < 0)
    {
        LOG_ERR("FDVT_CLEAR_IRQ fail(%d)\n",Ret);
        return MFALSE;
    }
    return MTRUE;
}

MBOOL FdvtDrvImp::waitFrameDone(unsigned int Status, MINT32 timeoutMs)
{
    FDVT_WAIT_IRQ_STRUCT WaitIrq;
    WaitIrq.Clear = FDVT_IRQ_WAIT_CLEAR;
    WaitIrq.Type = FDVT_IRQ_TYPE_INT_FDVT_ST;
    WaitIrq.Status = Status;
    WaitIrq.Timeout = timeoutMs;
    WaitIrq.UserKey = 0x0; //Driver Key
    WaitIrq.ProcessID = 0x0;
    WaitIrq.bDumpReg = 0x1;
    WaitIrq.isSecure = g_isFDVTSecure;

    DRV_TRACE_BEGIN("FDVT waitIrq");

    if (MTRUE == waitIrq(&WaitIrq))
    {
        if (Status & FDVT_INT_ST)
        {
            LOG_INF("FDVT Wait Interupt Frame Done Success!!\n");
        }
        ::sem_post(&mEnque);
        DRV_TRACE_END();

        return MTRUE;
    }
    else
    {
        if (Status & FDVT_INT_ST)
        {
            LOG_INF("FDVT Wait Interupt Frame Done Fail!!\n");
            if (g_isFDVTSecure == 0)
            {
                LOG_INF("fdmode_fdvt_yuv2rgb_config:  0x%x, fdmode_fdvt_yuv2rgb_config_size: %d", g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, fdvt_fdmode_yuv2rgb_config_size);
                LOG_INF("fdmode_fdvt_rs_config:       0x%x, fdmode_fdvt_rs_config_size:      %d", g_FdDrv_Para->FDMODE_RS_Config_VA, fdvt_fdmode_rs_config_size);
                LOG_INF("fdmode_fdvt_fd_config:       0x%x, fdmode_fdvt_fd_config_size:      %d", g_FdDrv_Para->FDMODE_FD_Config_VA, fdvt_fdmode_fd_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->FDMODE_YUV2RGB_Config_VA, fdvt_fdmode_yuv2rgb_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->FDMODE_RS_Config_VA, fdvt_fdmode_rs_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->FDMODE_FD_Config_VA, fdvt_fdmode_fd_config_size);

                LOG_INF("attrmode_fdvt_yuv2rgb_config[%d]:  0x%x, attrmode_fdvt_yuv2rgb_config_size: %d", g_FdDrv_Attr_Para->ReadIdx, g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_yuv2rgb_config_size);
                LOG_INF("attrmode_fdvt_rs_config[%d]:       0x%x, attrmode_fdvt_rs_config_size:      %d", g_FdDrv_Attr_Para->ReadIdx, g_FdDrv_Para->ATTRMODE_RS_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_rs_config_size);
                LOG_INF("attrmode_fdvt_fd_config[%d]:       0x%x, attrmode_fdvt_fd_config_size:      %d", g_FdDrv_Attr_Para->ReadIdx, g_FdDrv_Para->ATTRMODE_FD_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_fd_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_yuv2rgb_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->ATTRMODE_RS_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_rs_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->ATTRMODE_FD_Config_VA[g_FdDrv_Attr_Para->ReadIdx], fdvt_attrmode_fd_config_size);

                LOG_INF("posemode_fdvt_yuv2rgb_config[%d]:  0x%x, posemode_fdvt_yuv2rgb_config_size: %d", g_FdDrv_Pose_Para->ReadIdx, g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_yuv2rgb_config_size);
                LOG_INF("posemode_fdvt_rs_config[%d]:       0x%x, posemode_fdvt_rs_config_size:      %d", g_FdDrv_Pose_Para->ReadIdx, g_FdDrv_Para->POSEMODE_RS_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_rs_config_size);
                LOG_INF("posemode_fdvt_fd_config[%d]:       0x%x, posemode_fdvt_fd_config_size:      %d", g_FdDrv_Pose_Para->ReadIdx, g_FdDrv_Para->POSEMODE_FD_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_fd_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->POSEMODE_YUV2RGB_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_yuv2rgb_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->POSEMODE_RS_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_rs_config_size);
                FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->POSEMODE_FD_Config_VA[g_FdDrv_Pose_Para->ReadIdx], fdvt_posemode_fd_config_size);
            }
        }
        ::sem_post(&mEnque);
        DRV_TRACE_END();
        return MFALSE;
    }
}

MBOOL FDVT_fillSecureMetaData(NSCam::NSIoPipe::FDVTConfig* pFdvtConfig, FDVT_Config *FDVTConfig)
{
    FDVTConfig->FDVT_METADATA_TO_GCE.FDMode = pFdvtConfig->FD_MODE;
    FDVTConfig->FDVT_METADATA_TO_GCE.srcImgFmt = pFdvtConfig->SRC_IMG_FMT;
    FDVTConfig->FDVT_METADATA_TO_GCE.srcImgWidth = pFdvtConfig->SRC_IMG_WIDTH;
    FDVTConfig->FDVT_METADATA_TO_GCE.srcImgHeight = pFdvtConfig->SRC_IMG_HEIGHT;
    FDVTConfig->FDVT_METADATA_TO_GCE.maxWidth = g_FdDrv_Para->MAX_SRC_Input_Width;
    FDVTConfig->FDVT_METADATA_TO_GCE.maxHeight = g_FdDrv_Para->MAX_SRC_Input_Height;
    FDVTConfig->FDVT_METADATA_TO_GCE.rotateDegree = pFdvtConfig->INPUT_ROTATE_DEGREE;
    FDVTConfig->FDVT_METADATA_TO_GCE.featureTH = g_FdDrv_Para->RPN_ANCHOR_THRD;
    FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrcY_Handler = (MUINT32)((MUINT64)pFdvtConfig->source_img_address & 0x00000000ffffffff);
    FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrc_Y_Size = pFdvtConfig->SRC_IMG_WIDTH * pFdvtConfig->SRC_IMG_HEIGHT;
    FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrcUV_Handler = (MUINT32)((MUINT64)pFdvtConfig->source_img_address_UV & 0x00000000ffffffff);
    FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrc_UV_Size = pFdvtConfig->SRC_IMG_WIDTH * pFdvtConfig->SRC_IMG_HEIGHT;
    FDVTConfig->FDVT_METADATA_TO_GCE.YUVConfig_Handler = (MUINT32)FDVTConfig->FDVT_YUV2RGBCON_BASE_ADR;
    FDVTConfig->FDVT_METADATA_TO_GCE.YUVConfigSize = fdvt_fdmode_yuv2rgb_config_size + fdvt_attrmode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM+ fdvt_posemode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM;
    FDVTConfig->FDVT_METADATA_TO_GCE.YUVOutBuf_Handler = (MUINT32)Imem_YUV2RGB_Outout_hw.phyAddr;
    FDVTConfig->FDVT_METADATA_TO_GCE.YUVOutBufSize = fdvt_frame_R_size+fdvt_frame_G_size+fdvt_frame_B_size;

    FDVTConfig->FDVT_METADATA_TO_GCE.RSConfig_Handler = (MUINT32)FDVTConfig->FDVT_RSCON_BASE_ADR;
    FDVTConfig->FDVT_METADATA_TO_GCE.RSConfigSize = fdvt_fdmode_rs_config_size + fdvt_attrmode_rs_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_rs_config_size*MAX_ENQUE_FRAME_NUM;
    FDVTConfig->FDVT_METADATA_TO_GCE.RSOutBuf_Handler = (MUINT32)Imem_RS_Output_hw.phyAddr;
    FDVTConfig->FDVT_METADATA_TO_GCE.RSOutBufSize = fdvt_rs_pyramid0_out_size*3 + fdvt_rs_pyramid1_out_size*3 + fdvt_rs_pyramid2_out_size*3;

    FDVTConfig->FDVT_METADATA_TO_GCE.FDConfig_Handler = (MUINT32)FDVTConfig->FDVT_FD_CON_BASE_ADR;
    FDVTConfig->FDVT_METADATA_TO_GCE.FDConfigSize = fdvt_fdmode_fd_config_size + fdvt_attrmode_fd_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_fd_config_size*MAX_ENQUE_FRAME_NUM;
    FDVTConfig->FDVT_METADATA_TO_GCE.FDOutBuf_Handler = (MUINT32)Imem_FD_DMA_hw.phyAddr;
    FDVTConfig->FDVT_METADATA_TO_GCE.FDOutBufSize = fdvt_fd_DMA_MAX_size;
    FDVTConfig->FDVT_METADATA_TO_GCE.FDResultBuf_MVA = (MUINT32)Imem_FD_DMA_Result_hw.phyAddr;
    FDVTConfig->FDVT_METADATA_TO_GCE.FDResultBufSize = fdvt_fd_DMA_Result_MAX_size;

    FDVTConfig->FDVT_METADATA_TO_GCE.SecMemType = g_FDVTSecMemType;
    FDVTConfig->FDVT_METADATA_TO_GCE.isReleased = g_isReleased;
    g_isReleased = MFALSE;
/*
    LOG_INF("MetaData->FDMode: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDMode);
    LOG_INF("MetaData->srcImgFmt: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.srcImgFmt);
    LOG_INF("MetaData->srcImgWidth: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.srcImgWidth);
    LOG_INF("MetaData->srcImgHeight: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.srcImgHeight);
    LOG_INF("MetaData->rotateDegree: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.rotateDegree);
    LOG_INF("MetaData->featureTH: %d\n", FDVTConfig->FDVT_METADATA_TO_GCE.featureTH);
    LOG_INF("MetaData->ImgSrcY_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrcY_Handler);
    LOG_INF("MetaData->ImgSrcUV_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.ImgSrcUV_Handler);
    LOG_INF("MetaData->YUVConfig_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.YUVConfig_Handler);
    LOG_INF("MetaData->YUVOutBuf_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.YUVOutBuf_Handler);
    LOG_INF("MetaData->RSConfig_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.RSConfig_Handler);
    LOG_INF("MetaData->RSOutBuf_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.RSOutBuf_Handler);
    LOG_INF("MetaData->FDConfig_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDConfig_Handler);
    LOG_INF("MetaData->FDOutBuf_Handler: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDOutBuf_Handler);
    LOG_INF("MetaData->FDResultBuf_MVA: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDResultBuf_MVA);
    LOG_INF("MetaData->YUVConfigSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.YUVConfigSize);
    LOG_INF("MetaData->YUVOutBufSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.YUVOutBufSize);
    LOG_INF("MetaData->RSConfigSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.RSConfigSize);
    LOG_INF("MetaData->RSOutBufSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.RSOutBufSize);
    LOG_INF("MetaData->FDConfigSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDConfigSize);
    LOG_INF("MetaData->FDOutBufSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDOutBufSize);
    LOG_INF("MetaData->FDResultBufSize: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.FDResultBufSize);
    LOG_INF("MetaData->SecMemType: %p\n", FDVTConfig->FDVT_METADATA_TO_GCE.SecMemType);
*/
    return 0;
}

#define BYPASS_REG (0)
MBOOL FdvtDrvImp::enque(vector<NSCam::NSIoPipe::FDVTConfig>& FdvtConfigVec)
{
    LOG_DBG("FDVT Start Enque!!\n");
    MINT32 Ret;
    MUINT32 min;
    unsigned int num = FdvtConfigVec.size();
    NSCam::NSIoPipe::FDVTConfig* pFdvtConfig;
    FDVT_Request fdvt_Request;
    FDVT_Config fdvt_Config[_SUPPORT_MAX_FDVT_FRAME_REQUEST_];
    memset(&fdvt_Config, 0, sizeof(fdvt_Config));

    LOG_DBG("Check Whether Enqueue is Enable Here");
    ::sem_wait(&mEnque);

    for (unsigned int i=0; i<FdvtConfigVec.size(); i++)
    {
        pFdvtConfig = &(FdvtConfigVec.at(i));

        if((pFdvtConfig->SRC_IMG_WIDTH > g_FdDrv_Para->MAX_SRC_Input_Width) || (pFdvtConfig->SRC_IMG_HEIGHT > g_FdDrv_Para->MAX_SRC_Input_Height))
        {
            LOG_ERR("[%d] Enque Size is out of range, Src_WD: %d, Src_HT: %d, MAX_Src_WD: %d, MAX_Src_HT: %d\n",
                    i, pFdvtConfig->SRC_IMG_WIDTH, pFdvtConfig->SRC_IMG_HEIGHT, g_FdDrv_Para->MAX_SRC_Input_Width, g_FdDrv_Para->MAX_SRC_Input_Height);
            return MFALSE;
        }

        LOG_INF("FDVT ConfigVec[%d] Enque, Mode: %d, Src_WD: %d, Src_HT: %d, INPUT_ROTATE_DEGREE: %d, Src_addr_Y: 0x%lx, Src_addr_UV: 0x%lx, MAX_Src_WD: %d, MAX_Src_HT: %d,Fd_version: %d, Attr_version: %d, Pose_version: %d, FD_Cfg_PA: 0x%x, RS_Cfg_PA: 0x%x, YUV2RGB_Cfg_PA: 0x%x, YUV2RGB_R_Result_PA: 0x%x, RS_Pyramid0_R_Result_PA: 0x%x, DMA_PA: 0x%x\n",
			    i, pFdvtConfig->FD_MODE, pFdvtConfig->SRC_IMG_WIDTH, pFdvtConfig->SRC_IMG_HEIGHT, pFdvtConfig->INPUT_ROTATE_DEGREE,
			    (unsigned long)pFdvtConfig->source_img_address, (unsigned long)pFdvtConfig->source_img_address_UV,
			    g_FdDrv_Para->MAX_SRC_Input_Width, g_FdDrv_Para->MAX_SRC_Input_Height, Fd_version, Attr_version, Pose_version,
			    g_FdDrv_Para->FDMODE_FD_Config_PA, g_FdDrv_Para->FDMODE_RS_Config_PA, g_FdDrv_Para->FDMODE_YUV2RGB_Config_PA,
			    g_FdDrv_Para->YUV2RGB_R_Result_PA, g_FdDrv_Para->RS_Pyramid0_R_Result_PA, g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[0][0]);

        if (g_isFDVTSecure == 0)
        {
            FDVT_resetOutputDataBuffer(pFdvtConfig);
        }

        fdvt_Config[i].FD_MODE  = pFdvtConfig->FD_MODE;
        if(pFdvtConfig->FD_MODE == 0) // FDMODE
        {
            fdvt_Config[i].FDVT_RSCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->FDMODE_RS_Config_PA & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_YUV2RGBCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->FDMODE_YUV2RGB_Config_PA & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_FD_CON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->FDMODE_FD_Config_PA & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_RSCON_BUFSIZE = fdvt_fdmode_rs_config_size + fdvt_attrmode_rs_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_rs_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_YUV2RGBCON_BUFSIZE = fdvt_fdmode_yuv2rgb_config_size + fdvt_attrmode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM+ fdvt_posemode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_FD_CON_BUFSIZE = fdvt_fdmode_fd_config_size + fdvt_attrmode_fd_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_fd_config_size*MAX_ENQUE_FRAME_NUM;
        }
        else if(pFdvtConfig->FD_MODE == 1) // ATTRMODE
        {
            fdvt_Config[i].FDVT_RSCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->ATTRMODE_RS_Config_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_YUV2RGBCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->ATTRMODE_YUV2RGB_Config_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_FD_CON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->ATTRMODE_FD_Config_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_RSCON_BUFSIZE = fdvt_fdmode_rs_config_size + fdvt_attrmode_rs_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_rs_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_YUV2RGBCON_BUFSIZE = fdvt_fdmode_yuv2rgb_config_size + fdvt_attrmode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM+ fdvt_posemode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_FD_CON_BUFSIZE = fdvt_fdmode_fd_config_size + fdvt_attrmode_fd_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_fd_config_size*MAX_ENQUE_FRAME_NUM;
            //fdvt_Config[i].FDVT_ATTR_RACE_RESULT_ADR = ((MUINTPTR)g_FdDrv_Fd_DMA_Para->race_out_hw_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
            //fdvt_Config[i].FDVT_ATTR_GENDER_RESULT_ADR = ((MUINTPTR)g_FdDrv_Fd_DMA_Para->gender_out_hw_PA[g_FdDrv_Attr_Para->WriteIdx] & 0x00000000ffffffff);
        }
        else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
        {
            fdvt_Config[i].FDVT_RSCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->POSEMODE_RS_Config_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_YUV2RGBCON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->POSEMODE_YUV2RGB_Config_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_FD_CON_BASE_ADR = ((MUINTPTR)g_FdDrv_Para->POSEMODE_FD_Config_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
            fdvt_Config[i].FDVT_RSCON_BUFSIZE = fdvt_fdmode_rs_config_size + fdvt_attrmode_rs_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_rs_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_YUV2RGBCON_BUFSIZE = fdvt_fdmode_yuv2rgb_config_size + fdvt_attrmode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM+ fdvt_posemode_yuv2rgb_config_size*MAX_ENQUE_FRAME_NUM;
            fdvt_Config[i].FDVT_FD_CON_BUFSIZE = fdvt_fdmode_fd_config_size + fdvt_attrmode_fd_config_size*MAX_ENQUE_FRAME_NUM + fdvt_posemode_fd_config_size*MAX_ENQUE_FRAME_NUM;
            //fdvt_Config[i].FDVT_POSE_RIP_RESULT_ADR = ((MUINTPTR)g_FdDrv_Fd_DMA_Para->rip_out_hw_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
            //fdvt_Config[i].FDVT_POSE_ROP_RESULT_ADR = ((MUINTPTR)g_FdDrv_Fd_DMA_Para->rop_out_hw_PA[g_FdDrv_Pose_Para->WriteIdx] & 0x00000000ffffffff);
        }
        fdvt_Config[i].FDVT_YUV2RGB = ((pFdvtConfig->SRC_IMG_FMT & 0x7) | (0x2 << 4));
        fdvt_Config[i].FDVT_YUV_SRC_WD_HT = ((pFdvtConfig->SRC_IMG_HEIGHT & 0x7FF) | ((pFdvtConfig->SRC_IMG_WIDTH & 0x7FF) << 16));

        if (g_isFDVTSecure == 0)
        {
            FDVT_configDram(pFdvtConfig);
        }

        if(pFdvtConfig->FD_MODE == 1) // ATTRMODE
        {
            LOG_INF("[ATTRMODE] WriteIdx = %d, ReadIdx = %d\n", g_FdDrv_Attr_Para->WriteIdx, g_FdDrv_Attr_Para->ReadIdx);
            g_FdDrv_Attr_Para->WriteIdx = (g_FdDrv_Attr_Para->WriteIdx + 1) % MAX_ENQUE_FRAME_NUM;
        }
        else if(pFdvtConfig->FD_MODE == 2) // POSEMODE
        {
            LOG_INF("[POSEMODE] WriteIdx = %d, ReadIdx = %d\n", g_FdDrv_Pose_Para->WriteIdx, g_FdDrv_Pose_Para->ReadIdx);
            g_FdDrv_Pose_Para->WriteIdx = (g_FdDrv_Pose_Para->WriteIdx + 1) % MAX_ENQUE_FRAME_NUM;
        }

        if (g_isFDVTSecure == 1)
        {
            fdvt_Config[i].FDVT_IS_SECURE = 1;
            FDVT_fillSecureMetaData(pFdvtConfig, &(fdvt_Config[i]));
        }
    }

    fdvt_Request.m_ReqNum = num;
    fdvt_Request.m_pFdvtConfig = fdvt_Config;

    LOG_INF("Start to trigger, ReqNum = %d\n", fdvt_Request.m_ReqNum);

    Ret = ioctl(this->m_Fd,FDVT_ENQUE_REQ,&fdvt_Request);
    if(Ret < 0)
    {
        LOG_ERR("FDVT_ENQUE_REQ fail(%d)\n", Ret);
        return MFALSE;
    }
    return MTRUE;
}

MBOOL FdvtDrvImp::deque(vector<NSCam::NSIoPipe::FDVTConfig>& FdvtConfigVec)
{
    MUINT64  *fd_pyramid0_result = NULL, *fd_pyramid1_result = NULL, *fd_pyramid2_result = NULL;
    MUINT64  *attr_race_result = NULL, *attr_gender_result = NULL;
    MUINT64  *pose_rip_result = NULL, *pose_rop_result = NULL;
    MINT32 Ret;
    MUINT32  fd_result_hw = 0x0, fd_result_1_hw = 0x0;
    MUINT32  fd_total_num = 0x0, fd_pyramid0_num = 0x0, fd_pyramid1_num = 0x0, fd_pyramid2_num = 0x0;
    MUINT32 j;
#if (FD_Unit_Test || ATTR_Unit_Test || POSE_Unit_Test)
    MUINT32 bittrue_result;
#endif
    NSCam::NSIoPipe::FDVTConfig FdvtConfig;
    FDVT_Request fdvt_Request;
    FDVT_Config fdvt_Config[_SUPPORT_MAX_FDVT_FRAME_REQUEST_];
    fdvt_Request.m_pFdvtConfig = fdvt_Config;
    Ret = ioctl(this->m_Fd,FDVT_DEQUE_REQ,&fdvt_Request);

    if(Ret < 0)
    {
        LOG_ERR("FDVT_DEQUE_REQ fail(%d)\n", Ret);
        return MFALSE;
    }

#if (FD_Unit_Test || ATTR_Unit_Test || POSE_Unit_Test)
    bittrue_result = FDVT_BitTrueTest();
#endif

    LOG_DBG("dequeFDVT num:%d\n", fdvt_Request.m_ReqNum);
    for (unsigned int i=0; i< fdvt_Request.m_ReqNum; i++)
    {
        /* TODO: Engine-specific statistics for feature use */
        FdvtConfig.Fd_version = Fd_version;
        FdvtConfig.Attr_version = Attr_version;
        FdvtConfig.Pose_version = Pose_version;
        LOG_DBG("FD_MODE: %d\n", fdvt_Config[i].FD_MODE);
        if (fdvt_Config[i].FD_MODE == 0) // FDMODE
        {
	        FdvtConfig.FD_MODE = g_FdDrv_Para->FD_MODE;
	        FdvtConfig.INPUT_ROTATE_DEGREE = g_FdDrv_Para->INPUT_ROTATE_DEGREE;
	        FdvtConfig.source_img_address = g_FdDrv_Para->source_img_address;
	        FdvtConfig.source_img_address_UV = g_FdDrv_Para->source_img_address_UV;
	        FdvtConfig.SRC_IMG_WIDTH = g_FdDrv_Para->SRC_Input_Width;
	        FdvtConfig.SRC_IMG_HEIGHT = g_FdDrv_Para->SRC_Input_Height;
	        FdvtConfig.SRC_IMG_FMT = g_FdDrv_Para->SRC_IMG_FMT;

	        fd_pyramid0_result = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn0_loop_num][0];
	        fd_pyramid1_result = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn1_loop_num][0];
	        fd_pyramid2_result = g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[fdvt_fd_rpn2_loop_num][0];
	        fd_result_hw = fdvt_Config[i].RESULT;
	        fd_result_1_hw = fdvt_Config[i].RESULT1;
	        //fd_result_hw = readReg(0x178, 0);
	        //fd_result_1_hw = readReg(0x17C, 0);
	        fd_total_num = fd_result_hw & 0xFFF;
	        fd_pyramid0_num = (fd_result_hw & 0xFFF0000) >> 16;
	        fd_pyramid1_num = fd_result_1_hw & 0xFFF;
	        fd_pyramid2_num = (fd_result_1_hw & 0xFFF0000) >> 16;

	        FdvtConfig.FDOUTPUT.FD_TOTAL_NUM = fd_total_num;
	        FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.fd_partial_result = fd_pyramid0_num;
	        FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.fd_partial_result = fd_pyramid1_num;
	        FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.fd_partial_result = fd_pyramid2_num;

	        LOG_DBG("FDVT ConfigVec[%d] Deque, Mode: %d, Feature_Thrd: 0x%x ,Src_WD: %d, Src_HT: %d, INPUT_ROTATE_DEGREE: %d, Src_addr_Y: 0x%lx, Src_addr_UV: 0x%lx, MAX_Src_WD: %d, MAX_Src_HT: %d\n",
			        i, FdvtConfig.FD_MODE, g_FdDrv_Para->RPN_ANCHOR_THRD ,FdvtConfig.SRC_IMG_WIDTH, FdvtConfig.SRC_IMG_HEIGHT, FdvtConfig.INPUT_ROTATE_DEGREE,
			        (unsigned long)FdvtConfig.source_img_address, (unsigned long)FdvtConfig.source_img_address_UV,
			        g_FdDrv_Para->MAX_SRC_Input_Width, g_FdDrv_Para->MAX_SRC_Input_Height);
/*
            LOG_INF("Dump R Out buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->YUV2RGB_R_Result_VA, (unsigned long)g_FdDrv_Para->YUV2RGB_R_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->YUV2RGB_R_Result_VA, fdvt_frame_R_size);
            LOG_INF("Dump G Out buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->YUV2RGB_G_Result_VA, (unsigned long)g_FdDrv_Para->YUV2RGB_G_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->YUV2RGB_G_Result_VA, fdvt_frame_G_size);
            LOG_INF("Dump B Out buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->YUV2RGB_B_Result_VA, (unsigned long)g_FdDrv_Para->YUV2RGB_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->YUV2RGB_B_Result_VA, fdvt_frame_B_size);

            LOG_INF("Dump pyramid0 R buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid0_R_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid0_R_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_R_Result_VA, fdvt_rs_pyramid0_out_size);
            LOG_INF("Dump pyramid0 G buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid0_G_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid0_G_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_G_Result_VA, fdvt_rs_pyramid0_out_size);
            LOG_INF("Dump pyramid0 B buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid0_B_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid0_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid0_B_Result_VA, fdvt_rs_pyramid0_out_size);

            LOG_INF("Dump pyramid1 R buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid1_R_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid1_R_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_R_Result_VA, fdvt_rs_pyramid1_out_size);
            LOG_INF("Dump pyramid1 G buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid1_G_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid1_G_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_G_Result_VA, fdvt_rs_pyramid1_out_size);
            LOG_INF("Dump pyramid1 B buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid1_B_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid1_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid1_B_Result_VA, fdvt_rs_pyramid1_out_size);

            LOG_INF("Dump pyramid2 R buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_R_Result_VA, fdvt_rs_pyramid2_out_size);
            LOG_INF("Dump pyramid2 G buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_G_Result_VA, fdvt_rs_pyramid2_out_size);
            LOG_INF("Dump pyramid2 B buffer, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_VA, (unsigned long)g_FdDrv_Para->RS_Pyramid2_B_Result_PA);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Para->RS_Pyramid2_B_Result_VA, fdvt_rs_pyramid2_out_size);

            LOG_INF("Dump Pyramid0 Result buffer65, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[65][0], (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[65][0]);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[65][0], output_WDMA_WRA_buffer_size[65][0]);
            LOG_INF("Dump Pyramid0 Result buffer39, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[39][0], (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[39][0]);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[39][0], output_WDMA_WRA_buffer_size[39][0]);
            LOG_INF("Dump Pyramid0 Result buffer19, addr: VA(0x%lx), PA(0x%lx)\n", (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[19][0], (unsigned long)g_FdDrv_Fd_DMA_Para->fd_out_hw_PA[19][0]);
            FDVT_DumpDRAMOut((MUINT32 *)g_FdDrv_Fd_DMA_Para->fd_out_hw_VA[19][0], output_WDMA_WRA_buffer_size[19][0]);
*/
	        for(j=0; j < fd_pyramid0_num; j++)
	        {
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_x0[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 0) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_y0[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 0) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_x1[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 1) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_y1[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 1) & 0xFFFF0000) >> 16);
// no need to use commented by algo
/*
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x0[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 2) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y0[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 2) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x1[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 3) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y1[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 3) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x2[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 4) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y2[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 4) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x3[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 5) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y3[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 5) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x4[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 6) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y4[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 6) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x5[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 7) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y5[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 7) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_x6[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 8) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_y6[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 8) & 0xFFFF0000) >> 16);
*/
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_score[j] = (*((MUINT32 *)fd_pyramid0_result + 12 * j + 9) & 0x3FF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_score[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_score[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_score[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_score[j]);
// no need to use commented by algo
/*
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score0[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 9) & 0xFFC00) >> 10);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score0[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score0[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score0[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score0[j]);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score1[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 9) & 0x3FF00000) >> 20);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score1[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score1[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score1[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score1[j]);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score2[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 9) & 0xC0000000) >> 30) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0xFF) << 2);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score2[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score2[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score2[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score2[j]);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score3[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0x3FF00) >> 8);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score3[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score3[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score3[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score3[j]);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score4[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0xFFC0000) >> 18);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score4[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score4[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score4[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score4[j]);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score5[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0xF0000000) >> 28) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0x3F) << 4);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score5[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score5[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score5[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score5[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score6[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0xFFC0) >> 6);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score6[j] = (((FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score6[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score6[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.landmark_score6[j]);
*/
    		  	FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.face_result_index[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0xFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID0_RESULT.anchor_index[j] = ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0x70000000) >> 28);
	        }
	        for(j=0; j < fd_pyramid1_num; j++)
	        {
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_x0[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 0) & 0xFFFF);
      			FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_y0[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 0) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_x1[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 1) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_y1[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 1) & 0xFFFF0000) >> 16);
// no need to use commented by algo
/*
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x0[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 2) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y0[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 2) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x1[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 3) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y1[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 3) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x2[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 4) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y2[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 4) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x3[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 5) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y3[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 5) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x4[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 6) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y4[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 6) & 0xFFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x5[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 7) & 0xFFFF);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y5[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 7) & 0xFFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_x6[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 8) & 0xFFFF);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_y6[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 8) & 0xFFFF0000) >> 16);
 */
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_score[j] = (*((MUINT32 *)fd_pyramid1_result + 12 * j + 9) & 0x3FF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_score[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_score[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_score[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_score[j]);
// no need to use commented by algo
/*
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score0[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 9) & 0xFFC00) >> 10);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score0[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score0[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score0[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score0[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score1[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 9) & 0x3FF00000) >> 20);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score1[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score1[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score1[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score1[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score2[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 9) & 0xC0000000) >> 30) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0xFF) << 2);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score2[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score2[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score2[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score2[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score3[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 10) & 0x3FF00) >> 8);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score3[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score3[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score3[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score3[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score4[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 10) & 0xFFC0000) >> 18);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score4[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score4[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score4[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score4[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score5[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 10) & 0xF0000000) >> 28) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0x3F) << 4);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score5[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score5[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score5[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score5[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score6[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 11) & 0xFFC0) >> 6);
    	  		FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score6[j] = (((FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score6[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score6[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.landmark_score6[j]);
*/
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.face_result_index[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 11) & 0xFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID1_RESULT.anchor_index[j] = ((*((MUINT32 *)fd_pyramid1_result + 12 * j + 11) & 0x70000000) >> 28);
	        }
	        for(j=0; j < fd_pyramid2_num; j++)
	        {
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_x0[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 0) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_y0[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 0) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_x1[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 1) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_y1[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 1) & 0xFFFF0000) >> 16);
// no need to use commented by algo
/*
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x0[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 2) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y0[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 2) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x1[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 3) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y1[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 3) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x2[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 4) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y2[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 4) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x3[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 5) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y3[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 5) & 0xFFFF0000) >> 16);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x4[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 6) & 0xFFFF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y4[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 6) & 0xFFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x5[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 7) & 0xFFFF);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y5[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 7) & 0xFFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_x6[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 8) & 0xFFFF);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_y6[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 8) & 0xFFFF0000) >> 16);
*/
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_score[j] = (*((MUINT32 *)fd_pyramid2_result + 12 * j + 9) & 0x3FF);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_score[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_score[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_score[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_score[j]);
// no need to use commented by algo
/*
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score0[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 9) & 0xFFC00) >> 10);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score0[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score0[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score0[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score0[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score1[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 9) & 0x3FF00000) >> 20);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score1[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score1[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score1[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score1[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score2[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 9) & 0xC0000000) >> 30) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 10) & 0xFF) << 2);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score2[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score2[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score2[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score2[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score3[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 10) & 0x3FF00) >> 8);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score3[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score3[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score3[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score3[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score4[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 10) & 0xFFC0000) >> 18);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score4[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score4[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score4[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score4[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score5[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 10) & 0xF0000000) >> 28) | ((*((MUINT32 *)fd_pyramid0_result + 12 * j + 11) & 0x3F) << 4);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score5[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score5[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score5[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score5[j]);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score6[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 11) & 0xFFC0) >> 6);
    	  		FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score6[j] = (((FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score6[j] & 0x200) >> 9) ? (FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score6[j] | 0xFE00) : FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.landmark_score6[j]);
*/
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.face_result_index[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 11) & 0xFFF0000) >> 16);
    		  	FdvtConfig.FDOUTPUT.PYRAMID2_RESULT.anchor_index[j] = ((*((MUINT32 *)fd_pyramid2_result + 12 * j + 11) & 0x70000000) >> 28);
	        }
        }
        else if (fdvt_Config[i].FD_MODE == 1) // ATTRIBUTEMODE
        {
	        FdvtConfig.FD_MODE = g_FdDrv_Attr_Para->FD_MODE[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.INPUT_ROTATE_DEGREE = g_FdDrv_Attr_Para->INPUT_ROTATE_DEGREE[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.source_img_address = g_FdDrv_Attr_Para->source_img_address[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.source_img_address_UV = g_FdDrv_Attr_Para->source_img_address_UV[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_WIDTH = g_FdDrv_Attr_Para->SRC_Input_Width[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_HEIGHT = g_FdDrv_Attr_Para->SRC_Input_Height[g_FdDrv_Attr_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_FMT = g_FdDrv_Attr_Para->SRC_IMG_FMT[g_FdDrv_Attr_Para->ReadIdx];

	        attr_race_result  = g_FdDrv_Fd_DMA_Para->race_out_hw_VA[g_FdDrv_Attr_Para->ReadIdx]; // 64 feature * 32 bytes
	        attr_gender_result  = g_FdDrv_Fd_DMA_Para->gender_out_hw_VA[g_FdDrv_Attr_Para->ReadIdx]; // 64 feature * 32 bytes

	        for(j=0; j < 64; j++)
	        {
                // ch0: bit0~15, ch1:bit16~31, ch2: bit32~47, ch3: bit 48~63, total 16 channels
                FdvtConfig.ATTRIBUTEOUTPUT.RACE_RESULT.RESULT[0][j] = (*((MUINT32 *)attr_race_result + 8 * j + 0) & 0xFFFF);
                FdvtConfig.ATTRIBUTEOUTPUT.RACE_RESULT.RESULT[1][j] = ((*((MUINT32 *)attr_race_result + 8 * j + 0) & 0xFFFF0000) >> 16);
                FdvtConfig.ATTRIBUTEOUTPUT.RACE_RESULT.RESULT[2][j] = (*((MUINT32 *)attr_race_result + 8 * j + 1) & 0xFFFF);
                FdvtConfig.ATTRIBUTEOUTPUT.RACE_RESULT.RESULT[3][j] = ((*((MUINT32 *)attr_race_result + 8 * j + 1) & 0xFFFF0000) >> 16);
                // ch0: bit0~15, ch1:bit16~31, total 16 channels
                FdvtConfig.ATTRIBUTEOUTPUT.GENDER_RESULT.RESULT[0][j] = (*((MUINT32 *)attr_gender_result + 8 * j + 0) & 0xFFFF);
                FdvtConfig.ATTRIBUTEOUTPUT.GENDER_RESULT.RESULT[1][j] = ((*((MUINT32 *)attr_gender_result + 8 * j + 0) & 0xFFFF0000) >> 16);
	        }

	        LOG_INF("[ATTRMODE] WriteIdx = %d, ReadIdx = %d\n", g_FdDrv_Attr_Para->WriteIdx, g_FdDrv_Attr_Para->ReadIdx);
	        g_FdDrv_Attr_Para->ReadIdx = (g_FdDrv_Attr_Para->ReadIdx + 1) % MAX_ENQUE_FRAME_NUM;
        }
        else if (fdvt_Config[i].FD_MODE == 2) // POSEMODE
        {
	        FdvtConfig.FD_MODE = g_FdDrv_Pose_Para->FD_MODE[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.INPUT_ROTATE_DEGREE = g_FdDrv_Pose_Para->INPUT_ROTATE_DEGREE[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.source_img_address = g_FdDrv_Pose_Para->source_img_address[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.source_img_address_UV = g_FdDrv_Pose_Para->source_img_address_UV[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_WIDTH = g_FdDrv_Pose_Para->SRC_Input_Width[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_HEIGHT = g_FdDrv_Pose_Para->SRC_Input_Height[g_FdDrv_Pose_Para->ReadIdx];
	        FdvtConfig.SRC_IMG_FMT = g_FdDrv_Pose_Para->SRC_IMG_FMT[g_FdDrv_Pose_Para->ReadIdx];

	        pose_rip_result  = g_FdDrv_Fd_DMA_Para->rip_out_hw_VA[g_FdDrv_Pose_Para->ReadIdx]; // 64 feature * 32 bytes
	        pose_rop_result  = g_FdDrv_Fd_DMA_Para->rop_out_hw_VA[g_FdDrv_Pose_Para->ReadIdx]; // 64 feature * 32 bytes

	        for(j=0; j < 64; j++)
	        {
                // ch0: bit0~15, ch1:bit16~31, ch2: bit32~47, ch3: bit 48~63, ch4: bit64~79, ch5:bit80~95, ch6: bit96~111, total 16 channels
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[0][j] = (*((MUINT32 *)pose_rip_result + 8 * j + 0) & 0xFFFF);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[1][j] = ((*((MUINT32 *)pose_rip_result + 8 * j + 0) & 0xFFFF0000) >> 16);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[2][j] = (*((MUINT32 *)pose_rip_result + 8 * j + 1) & 0xFFFF);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[3][j] = ((*((MUINT32 *)pose_rip_result + 8 * j + 1) & 0xFFFF0000) >> 16);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[4][j] = (*((MUINT32 *)pose_rip_result + 8 * j + 2) & 0xFFFF);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[5][j] = ((*((MUINT32 *)pose_rip_result + 8 * j + 2) & 0xFFFF0000) >> 16);
                FdvtConfig.POSEOUTPUT.RIP_RESULT.RESULT[6][j] = (*((MUINT32 *)pose_rip_result + 8 * j + 3) & 0xFFFF);
                // ch0: bit0~15, ch1:bit16~31, ch2: bit32~47, total 16 channels
                FdvtConfig.POSEOUTPUT.ROP_RESULT.RESULT[0][j] = (*((MUINT32 *)pose_rop_result + 8 * j + 0) & 0xFFFF);
                FdvtConfig.POSEOUTPUT.ROP_RESULT.RESULT[1][j] = ((*((MUINT32 *)pose_rop_result + 8 * j + 0) & 0xFFFF0000) >> 16);
                FdvtConfig.POSEOUTPUT.ROP_RESULT.RESULT[2][j] = (*((MUINT32 *)pose_rop_result + 8 * j + 1) & 0xFFFF);
	        }

	        LOG_INF("[POSEMODE] WriteIdx = %d, ReadIdx = %d\n", g_FdDrv_Pose_Para->WriteIdx, g_FdDrv_Pose_Para->ReadIdx);
	        g_FdDrv_Pose_Para->ReadIdx = (g_FdDrv_Pose_Para->ReadIdx + 1) % MAX_ENQUE_FRAME_NUM;
        }
        //FdvtConfig.feedback.reg1 = 0xFFFFFFFF;
        //FdvtConfig.feedback.reg2 = 0xFFFFFFFF;
        FdvtConfigVec.push_back(FdvtConfig);
    }

    return MTRUE;
}

MUINT32 FdvtDrvImp::readReg(MUINT32 Addr,MINT32 caller)
{
    MINT32 Ret=0;
    MUINT32 value=0x0;
    MUINT32 legal_range = FDVT_REG_RANGE;
    (void) caller;

    LOG_DBG("+,Fdvt_read:Addr(0x%x)\n",Addr);
    android::Mutex::Autolock lock(this->FdvtRegMutex);
    //(void)caller;
    if(-1 == FD_CHK()){
        return 1;
    }

    if(this->m_regRWMode==FDVT_DRV_RW_MMAP){
        if(Addr >= legal_range){
            LOG_ERR("over range(0x%x)\n",Addr);
            return 0;
        }
        value = this->m_pFdvtHwRegAddr[(Addr>>2)];
    }
    else{
        FDVT_REG_IO_STRUCT FdvtRegIo;
        FDVT_DRV_REG_IO_STRUCT RegIo;
        //RegIo.module = this->m_HWmodule;
        RegIo.Addr = Addr;
        FdvtRegIo.pData = (FDVT_REG_STRUCT*)&RegIo;
        FdvtRegIo.Count = 1;

        Ret = ioctl(this->m_Fd, FDVT_READ_REGISTER, &FdvtRegIo);
        if(Ret < 0)
        {
            LOG_ERR("FDVT_READ via IO fail(%d)", Ret);
            return value;
        }
        value=RegIo.Data;
    }
    LOG_DBG("-,Fdvt_read:(0x%x,0x%x)",Addr,value);
    return value;
}

//-----------------------------------------------------------------------------
MBOOL FdvtDrvImp::readRegs(FDVT_DRV_REG_IO_STRUCT* pRegIo,MUINT32 Count,MINT32 caller)
{
    MINT32 Ret;
    MUINT32 legal_range = FDVT_REG_RANGE;
    (void) caller;

    android::Mutex::Autolock lock(this->FdvtRegMutex);
    //(void)caller;
    if((-1 == FD_CHK()) || (NULL == pRegIo)){
        return MFALSE;
    }

    if(this->m_regRWMode == FDVT_DRV_RW_MMAP){
        unsigned int i;
        for (i=0; i<Count; i++)
        {
            if(pRegIo[i].Addr >= legal_range)
            {
                LOG_ERR("over range,bypass_0x%x\n",pRegIo[i].Addr);
            }
            else
            {
                pRegIo[i].Data = this->m_pFdvtHwRegAddr[(pRegIo[i].Addr>>2)];
            }
        }
    }
    else{
        FDVT_REG_IO_STRUCT FdvtRegIo;
        //pRegIo->module = this->m_HWmodule;
        FdvtRegIo.pData = (FDVT_REG_STRUCT*)pRegIo;
        FdvtRegIo.Count = Count;


        Ret = ioctl(this->m_Fd, FDVT_READ_REGISTER, &FdvtRegIo);
        if(Ret < 0)
        {
            LOG_ERR("FDVT_READ via IO fail(%d)", Ret);
            return MFALSE;
        }
    }

    LOG_DBG("Fdvt_reads_Cnt(%d): 0x%x_0x%x", Count, pRegIo[0].Addr,pRegIo[0].Data);
    return MTRUE;
}

MBOOL FdvtDrvImp::writeReg(MUINT32 Addr,unsigned long Data,MINT32 caller)
{
    MINT32 ret=0;
    MUINT32 legal_range = FDVT_REG_RANGE;
    (void) caller;

    LOG_DBG("Fdvt_write:m_regRWMode(0x%x),(0x%x,0x%lx)",this->m_regRWMode,Addr,Data);
    android::Mutex::Autolock lock(this->FdvtRegMutex);
    //(void)caller;
    if(-1 == FD_CHK()){
        return MFALSE;
    }

    switch(this->m_regRWMode){
        case FDVT_DRV_RW_MMAP:
            if(Addr >= legal_range){
                LOG_ERR("over range(0x%x)\n",Addr);
                return MFALSE;
            }
            this->m_pFdvtHwRegAddr[(Addr>>2)] = Data;
            break;
        case FDVT_DRV_RW_IOCTL:
            FDVT_REG_IO_STRUCT FdvtRegIo;
            FDVT_DRV_REG_IO_STRUCT RegIo;
            //RegIo.module = this->m_HWmodule;
            RegIo.Addr = Addr;
            RegIo.Data = Data;
            FdvtRegIo.pData = (FDVT_REG_STRUCT*)&RegIo;
            FdvtRegIo.Count = 1;
            ret = ioctl(this->m_Fd, FDVT_WRITE_REGISTER, &FdvtRegIo);
            if(ret < 0){
                LOG_ERR("FDVT_WRITE via IO fail(%d)", ret);
                return MFALSE;
            }
            break;
        case FDVT_DRV_R_ONLY:
            LOG_ERR("FDVT Read Only");
            return MFALSE;
            break;
        default:
            LOG_ERR("no this reg operation mode(0x%x)",this->m_regRWMode);
            return MFALSE;
            break;
    }
    //
    //release mutex in order to read back for DBG log
    this->FdvtRegMutex.unlock();
    //
    return MTRUE;
}

MBOOL FdvtDrvImp::writeRegs(FDVT_DRV_REG_IO_STRUCT*  pRegIo,MUINT32 Count,MINT32 caller)
{
    MINT32 Ret;
    unsigned int i=0;
    MUINT32 legal_range = FDVT_REG_RANGE;
    (void) caller;

    android::Mutex::Autolock lock(this->FdvtRegMutex);
    if(-1 == FD_CHK() || (NULL == pRegIo)){
        return MFALSE;
    }

    switch(this->m_regRWMode){
        case FDVT_DRV_RW_IOCTL:
            FDVT_REG_IO_STRUCT FdvtRegIo;
            //pRegIo->module = this->m_HWmodule;
            FdvtRegIo.pData = (FDVT_REG_STRUCT*)pRegIo;
            FdvtRegIo.Count = Count;

            Ret = ioctl(this->m_Fd, FDVT_WRITE_REGISTER, &FdvtRegIo);
            if(Ret < 0){
                LOG_ERR("FDVT_WRITE via IO fail(%d)",Ret);
                return MFALSE;
            }
            break;
        case FDVT_DRV_RW_MMAP:
            //if(this->m_HWmodule >= CAM_MAX )
            //    legal_range = DIP_BASE_RANGE_SPECIAL;
            do{
                if(pRegIo[i].Addr >= legal_range){
                    LOG_ERR("mmap over range,bypass_0x%x\n",pRegIo[i].Addr);
                    i = Count;
                }
                else
                    this->m_pFdvtHwRegAddr[(pRegIo[i].Addr>>2)] = pRegIo[i].Data;
            }while(++i<Count);
            break;
        case FDVT_DRV_R_ONLY:
            LOG_ERR("FDVT Read Only");
            return MFALSE;
            break;
        default:
            LOG_ERR("no this reg operation mode(0x%x)",this->m_regRWMode);
            return MFALSE;
            break;
    }
    LOG_DBG("Fdvt_writes(%d):0x%x_0x%x\n",Count,pRegIo[0].Addr,pRegIo[0].Data);
    return MTRUE;

}

MUINT32 FdvtDrvImp::getRWMode(void)
{
    return this->m_regRWMode;
}

MBOOL FdvtDrvImp::setRWMode(FDVT_DRV_RW_MODE rwMode)
{
    if(rwMode > FDVT_DRV_R_ONLY)
    {
        LOG_ERR("no this reg operation mode(0x%x)",this->m_regRWMode);
        return MFALSE;
    }

    this->m_regRWMode = rwMode;
    return MTRUE;
}

