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
#ifndef _CCU_CTRL_H_
#define _CCU_CTRL_H_

#include "ccuif_compat.h"
#include "ccu_cmd_param_info.h"
#include "iccu_ctrl.h"
#include "ccu_mgr.h"
#include "ccu_udrv.h"

namespace NSCcuIf {

class AbsCcuCtrlBase: public virtual ICcuCtrl
{

enum IoBufType
{
    SYS_DRAM_IO,
    CCU_SRAM_IO
};
struct CcuIOBufInfo
{
    enum IoBufType bufType;
    MUINT8 *addr_ap;
    MUINT8 *addr_ap_interm;
    MUINT32 addr_ccu;
};

public:
    AbsCcuCtrlBase(void);
    virtual int init(MUINT32 sensorIdx, ESensorDev_T sensorDev);
    virtual int init();
    virtual int uninit();
    virtual int ccuControl(uint32_t msgId, void *inDataPtr, void *outDataPtr);

private:
    MBOOL resolveCmdIOBuf(const struct CcuCtrlParamDescriptor *paramDescptr, CcuIOBufInfo *inDataBufInfo, CcuIOBufInfo *outDataBufInfo);
    MBOOL copyIntermCmdInDataIoBuf(CcuIOBufInfo *inDataBufInfo);
    MBOOL copyIntermCmdOutDataIoBuf(CcuIOBufInfo *inDataBufInfo);
    int CcuControlHandleInput(uint32_t msgId, const struct CcuCtrlParamDescriptor *paramDescptr, void *inDataPtr, void *inDataBuf);
    int sendCcuCommnadIpc(uint32_t msgId, MUINT32 inDataAddrCcu, MUINT32 outDataAddrCcu);
    bool validateCommand(uint32_t msg_id);

protected:
    CcuDrvImp *m_pDrvCcu;
    CcuBufferList *m_pBufferList;
    MUINT32 m_sensorIdx;
    MUINT32 m_ccuInstanceIdx;
    ESensorDev_T m_sensorDev;
    enum ccu_feature_type m_featureType;
    bool m_initialized;
    static android::Mutex   m_CcuccuControlMutex;

    virtual enum ccu_tg_info getCcuTgInfo();
    virtual enum ccu_tg_info getCcuTgInfowithsensorDev(ESensorDev_T sensorDev, MUINT32 sensorIdx);
    virtual enum ccu_feature_type _getFeatureType() = 0;
    virtual bool ccuCtrlPreprocess(uint32_t msgId, void *inDataPtr, void *inDataBuf) = 0;
    virtual bool ccuCtrlPostprocess(uint32_t msgId, void *outDataPtr, void *inDataBuf) = 0;
};

};  //namespace NSCcuIf

#endif