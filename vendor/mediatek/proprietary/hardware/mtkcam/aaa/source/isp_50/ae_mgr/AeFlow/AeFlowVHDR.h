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
#ifndef _AE_FLOW_VHDR_H_
#define _AE_FLOW_VHDR_H_


#include <aaa_types.h>
#include <isp_tuning.h>
#include <AeFlow/AeFlowDefault.h>
#include <AeFlow/IAeFlow.h>
#include <dbg_aaa_param.h>
#include <dbg_ae_param.h>
#include <ae_algo_if.h>


using namespace NSIspTuning;
namespace NS3Av3
{
class AeFlowVHDR : protected AeFlowDefault
{
public:

    static IAeFlow*    getInstance(ESensorDev_T sensor);
    virtual MVOID      schedulePvAE(MVOID* input, MVOID* output);
    virtual MVOID      calculateAE(MVOID* input, MVOID* output);

    virtual MVOID      setMVHDR3ExpoProcInfo(MVOID* pMVHDR3ExpoStatBuf, MUINT32 u4MVHDRRatio_x100);

//protected:
                         AeFlowVHDR(ESensorDev_T sensor);
    virtual            ~AeFlowVHDR();
private:
    MVOID updatePreviewParamsByiVHDR(strAEOutput *sAEInfo);
    MVOID updatePreviewParamsBymVHDR(strAEOutput *sAEInfo);
    MVOID updatePreviewParamsBymVHDR3Expo(strAEOutput *sAEInfo);
    MRESULT updatePreviewParamsByzVHDR(strAEOutput *sAEInfo,MUINT32 u4VHDRratio);
    MUINT32 m_u4AEISOSpeed;
    MBOOL m_bRealISOSpeed;
};
};
#endif //_AE_FLOW_VHDR_H_