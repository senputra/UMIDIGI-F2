#define LOG_TAG "path_cam"
//
//
#include "cam_path_cam.h"
#include "cam_capibility.h"
#include "sec_mgr.h"

//



#undef   DBG_LOG_TAG                        // Decide a Log TAG for current file.
#ifndef USING_MTK_LDVT   // Not using LDVT.
#define  DBG_LOG_TAG        ""
#else
#define  DBG_LOG_TAG        LOG_TAG
#endif

#include "imageio_log.h"                        // Note: DBG_LOG_TAG/LEVEL will be used in header file, so header must be included after definition.
//DECLARE_DBG_LOG_VARIABLE(path);
EXTERN_DBG_LOG_VARIABLE(path);
using namespace NSImageio;
using namespace NSIspio;


#define UNUSED(var) (void)(var)
/*/////////////////////////////////////////////////////////////////////////////
  CamPathPass1
  /////////////////////////////////////////////////////////////////////////////*/
MINT32 CamPathPass1::config( struct CamPathPass1Parameter* p_parameter )
{
    MINT32 ret = 0;
    ISP_PATH_DBG("CamPathPass1::config E");
    MUINT32 cnt=0;
    CAM_TIMESTAMP* pTime = CAM_TIMESTAMP::getInstance(this->m_hwModule,NULL);

    //reset previous notifyobj
    for(MUINT32 i=0;i<p1Notify_node;i++)
        this->m_p1NotifyObj[i] = NULL;

    if(this->m_pCmdQdrv == NULL){
        ISP_PATH_ERR("NULL cmdQMgr\n");
        return 1;
    }

    //function List
    //top must be at 1st
    this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_TopCtrl;

    if(p_parameter->m_Path == CamPathPass1Parameter::_TG_IN){
        switch(p_parameter->m_top_ctl.FMT_SEL.Bits.TG_FMT){
            case TG_FMT_RAW8:
            case TG_FMT_RAW10:
            case TG_FMT_RAW12:
            case TG_FMT_RAW14:
                this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_RawCtrl;
                break;
            case TG_FMT_YUV422:
                this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_YuvCtrl;
                break;
            default:
                ISP_PATH_ERR("unsupported TG format:0x%x\n",p_parameter->m_top_ctl.FMT_SEL.Bits.TG_FMT);
                return 1;
                break;
        }
    }else{
        switch(p_parameter->m_RawIFmt){
            case RAWI_FMT_RAW8:
            case RAWI_FMT_RAW10:
            case RAWI_FMT_RAW12:
            case RAWI_FMT_RAW14:
                this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_RawCtrl;
                break;
            default:
                ISP_PATH_ERR("unsupported DMAI format:0x%x\n",p_parameter->m_RawIFmt);
                return 1;
                break;
        }
    }

    if(p_parameter->bypass_imgo == MFALSE){
        //revmove from functionlist, because of dmao enable & disable r via CQ.
        //it means dmao enable/disable need to start/stop as much times as DupCmdQ number
        //this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_Imgo;
    }
    else
        this->m_Imgo.m_pIspDrv = NULL;
    if(p_parameter->bypass_rrzo == MFALSE){
        //revmove from functionlist, because of dmao enable & disable r via CQ.
        //it means dmao enable/disable need to start/stop as much times as DupCmdQ number
        //this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_Rrzo;

        this->m_isp_function_list[cnt++ ] = (IspFunction_B*)&this->m_Rrz;
    }
    else
        this->m_Rrzo.m_pIspDrv = NULL;

    this->m_isp_function_count = cnt;



    //cfg CmdQMgr
    //CQ config moved into CmdQMgr
    //this->m_pCmdQdrv->CmdQMgr_attach(p_parameter->m_fps,p_parameter->m_subSample,this->m_hwModule,ISP_DRV_CQ_THRE0,(void*)&this->m_CQ0);

    //tg
    if(p_parameter->bypass_tg == MFALSE){
        this->m_TgCtrl.m_Crop = p_parameter->m_src_size;
        if(p_parameter->m_Path == CamPathPass1Parameter::_TG_IN)//TG input support only continuous mode
            this->m_TgCtrl.m_continuous = MTRUE;
        else
            this->m_TgCtrl.m_continuous = MFALSE;

        this->m_TgCtrl.m_SubSample = p_parameter->m_subSample;

        this->m_TgCtrl.m_PixMode = p_parameter->m_src_pixmode;

        //tg setting is via phy reg, so all vir_ptr are all acceptable
        this->m_TgCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0];

        //
        if(p_parameter->m_top_ctl.FUNC_EN.Bits.DBN_EN){
            if(p_parameter->m_data_pat == 3){
                this->m_TgCtrl.m_Datapat = CAM_TG_CTRL::_tg_4cell_;
            }
            else{
                this->m_TgCtrl.m_Datapat = CAM_TG_CTRL::_tg_dual_pix_;
            }
        }
        else {
            if (p_parameter->m_top_ctl.FMT_SEL.Bits.TG_FMT == TG_FMT_YUV422) {
                this->m_TgCtrl.m_Datapat = CAM_TG_CTRL::_tg_yuv_;
            }
            else {
                this->m_TgCtrl.m_Datapat = CAM_TG_CTRL::_tg_normal_;
            }
        }

        //tg setting is not via m_isp_function_list . so setting directly here
        ret += this->m_TgCtrl.config();
        //tg need to enable 1st for vsync signal
        ret += this->m_TgCtrl.enable(NULL);

    }

    //asign timestamp clk rate

    pTime->TimeStamp_SrcClk(p_parameter->m_tTimeClk);
#if (TEMP_SW_TIMESTAMP == 1)
    if(p_parameter->bypass_imgo == MFALSE){
        this->m_Imgo_FBC.m_TimeStamp.TimeStamp_SrcClk(p_parameter->m_tTimeClk);
    }
    else if(p_parameter->bypass_rrzo == MFALSE){
        this->m_Rrzo_FBC.m_TimeStamp.TimeStamp_SrcClk(p_parameter->m_tTimeClk);
    }
#endif
    //top
    switch(this->m_hwModule){
        case CAM_A:
            if(p_parameter->m_Path == CamPathPass1Parameter::_TG_IN){
                this->m_TopCtrl.CAM_Path = IF_CAM_A;

            }
            else{
                this->m_TopCtrl.CAM_Path = IF_RAWI_CAM_A;
            }
            break;
        case CAM_B:
            if(p_parameter->m_Path == CamPathPass1Parameter::_TG_IN){
                this->m_TopCtrl.CAM_Path = IF_CAM_B;

            }
            else{
                this->m_TopCtrl.CAM_Path = IF_RAWI_CAM_B;
            }
            break;
        default:
            ISP_PATH_ERR("config fail:module out of range:0x%x\n",this->m_hwModule);
            return -1;
            break;
    }

    this->m_TopCtrl.SubSample = p_parameter->m_subSample;//this->m_pCmdQdrv->CmdQMgr_GetBurstQ(); // not drv self-define

    // C++11 do not allow this kind of operation, use memcpy for workaround
    //this->m_TopCtrl.cam_top_ctl = p_parameter->m_top_ctl;
    memcpy((void *) &m_TopCtrl.cam_top_ctl, (void *) &p_parameter->m_top_ctl, sizeof(ST_CAM_TOP_CTRL));
    //this->m_TopCtrl.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];


    //raw or yuv pipe
    if(p_parameter->m_Path == CamPathPass1Parameter::_TG_IN){
        switch(p_parameter->m_top_ctl.FMT_SEL.Bits.TG_FMT){
            case TG_FMT_RAW8:
            case TG_FMT_RAW10:
            case TG_FMT_RAW12:
            case TG_FMT_RAW14:
                //raw pipe
                switch(p_parameter->m_NonScale_RawType){
                    case CamPathPass1Parameter::_PURE_RAW:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_FromTG;
                        break;
                    case CamPathPass1Parameter::_NON_LSC_RAW:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_BeforLSC;
                        break;
                    default:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_AFTERLSC;
                        break;
                }
                this->m_RawCtrl.m_Source = this->m_TopCtrl.CAM_Path;
                this->m_RawCtrl.m_pP1Tuning = NULL;//null at config()
                //this->m_RawCtrl.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                break;
            case TG_FMT_YUV422:
                //yuv pipe
                this->m_YuvCtrl.m_pP1Tuning = NULL;
                //this->m_YuvCtrl.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                break;
            default:
                ISP_PATH_ERR("unsupported TG format:0x%x\n",p_parameter->m_top_ctl.FMT_SEL.Bits.TG_FMT);
                return 1;
                break;
        }
    }
    else{
        switch(p_parameter->m_RawIFmt){
            case RAWI_FMT_RAW8:
            case RAWI_FMT_RAW10:
            case RAWI_FMT_RAW12:
            case RAWI_FMT_RAW14:
                //raw pipe
                switch(p_parameter->m_NonScale_RawType){
                    case CamPathPass1Parameter::_PURE_RAW:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_FromTG;
                        break;
                    case CamPathPass1Parameter::_NON_LSC_RAW:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_BeforLSC;
                        break;
                    default:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_AFTERLSC;
                        break;
                }
                this->m_RawCtrl.m_Source = this->m_TopCtrl.CAM_Path;
                this->m_RawCtrl.m_pP1Tuning = NULL;//null at config()

                if(this->m_hwModule == p_parameter->m_pUniMgr->UniMgr_GetCurLink())
                    this->m_RawCtrl.m_pUniDrv = p_parameter->m_pUniMgr->UniMgr_GetCurObj();
                else{
                    this->m_RawCtrl.m_pUniDrv = NULL;
                    ISP_PATH_ERR("current cam:0x%x need uni, but uni is connect with cam:0x%x\n",\
                        this->m_hwModule,\
                        p_parameter->m_pUniMgr->UniMgr_GetCurLink());
                    return 1;
                }

                //this->m_RawCtrl.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                break;
            default:
                ISP_PATH_ERR("unsupported DMAI format:0x%x\n",p_parameter->m_RawIFmt);
                return 1;
                break;
        }
    }

    this->m_RawCtrl.m_DataPat = p_parameter->m_data_pat;

    //dmao & dmao fbc
    if(p_parameter->bypass_imgo == MFALSE){
        this->m_Imgo.dma_cfg = p_parameter->m_imgo.dmao;
        this->m_Imgo.Header_Addr = p_parameter->m_imgo.FH_PA;
        this->m_Imgo.m_fps = p_parameter->m_fps;

        //this->m_Imgo.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];

    }
    if(p_parameter->bypass_rrzo == MFALSE){
        this->m_Rrzo.dma_cfg = p_parameter->m_rrzo.dmao;
        this->m_Rrzo.Header_Addr = p_parameter->m_rrzo.FH_PA;
        this->m_Rrzo.m_fps = p_parameter->m_fps;

        //this->m_Rrzo.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];


        //rrz initial-cfg
        this->m_Rrz.rrz_in_roi = p_parameter->rrz_in_roi;
        this->m_Rrz.rrz_out_size = p_parameter->m_Scaler;
        this->m_Rrz.rrz_rlb_offset = p_parameter->rrz_rlb_offset;


        //this->m_Rrz.m_pIspDrv = this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
    }

    //UFEO
    if(p_parameter->bypass_ufeo == MFALSE){
        this->m_Ufeo.dma_cfg = p_parameter->m_ufeo.dmao;
        this->m_Ufeo.Header_Addr = p_parameter->m_ufeo.FH_PA;
        this->m_Ufeo.m_fps = p_parameter->m_fps;
    }

    //loop for burst / duplicated cmdQ
    for(MUINT32 i = 0;i<this->m_pCmdQdrv->CmdQMgr_GetDuqQ();i++){
        for(MUINT32 j=0;j<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();j++){
            //top
            this->m_TopCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];


            //CQ need no update burst & dup here. [cq-config r all phy]

            //raw or yuv pipe
            if(p_parameter->bypass_ispRawPipe == MFALSE){
                this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
            }
            else{
                this->m_YuvCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
            }

            //dmao & dmao fbc
            //if(p_parameter->bypass_imgo == MFALSE){
            //    this->m_Imgo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];

            //}

            if(p_parameter->bypass_rrzo == MFALSE){
                //this->m_Rrzo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];


                this->m_Rrz.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
            }
            ret += this->_config(NULL);
        }
    }


#if 0 //remove into p1notify_mapping, fbc will be opened until notify is enabled
    this->m_Lcso_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0];
    this->m_Lcso_FBC.config();
    this->m_Lcso_FBC.enable(NULL);
#endif
    //module on uni will be re-moved into uni_mgr, uni_mgr ctrl only following operation:cfg/enable/disable
    //this->m_Rsso_FBC;
    //this->m_Eiso_FBC;


    for(MUINT32 i = 0;i<this->m_pCmdQdrv->CmdQMgr_GetDuqQ();i++){
        for(MUINT32 j=0;j<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();j++){
            if(p_parameter->bypass_imgo == MFALSE){
                //FBC is a specal case, fbc need to enable before enque, so put here to cofig and start at one time
                //FBC cfg is moving to enque (because of UNI , uni will be allcoated during cfg to start)
                this->m_Imgo_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Imgo_FBC.config();
                ret += this->m_Imgo_FBC.write2CQ();
                ret += this->m_Imgo_FBC.enable(NULL);
                //
                this->m_Imgo_FBC.m_pTimeStamp = pTime;

                //special case for imgo/rrzo dmao_en,  because dma_en is via cq .
                //plz reference the description at line:81
                this->m_Imgo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Imgo.config();
                ret += this->m_Imgo.write2CQ();
                ret += this->m_Imgo.enable(NULL);
            }
            if(p_parameter->bypass_rrzo == MFALSE){
                //FBC is a specal case, fbc need to enable before enque, so put here to cofig and start at one time
                //FBC cfg is moving to enque (because of UNI , uni will be allcoated during cfg to start)
                this->m_Rrzo_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Rrzo_FBC.config();
                ret += this->m_Rrzo_FBC.write2CQ();
                ret += this->m_Rrzo_FBC.enable(NULL);
                //
                this->m_Rrzo_FBC.m_pTimeStamp = pTime;

                //special case for imgo/rrzo dmao_en,  because dma_en is via cq .
                //plz reference the description at line:81
                this->m_Rrzo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Rrzo.config();
                ret += this->m_Rrzo.write2CQ();
                ret += this->m_Rrzo.enable(NULL);
            }
            if(p_parameter->bypass_ufeo == MFALSE){
                this->m_Ufeo_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Ufeo_FBC.config();
                ret += this->m_Ufeo_FBC.write2CQ();
                ret += this->m_Ufeo_FBC.enable(NULL);
                //
                this->m_Ufeo_FBC.m_pTimeStamp = pTime;

                this->m_Ufeo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Ufeo.config();
                ret += this->m_Ufeo.write2CQ();
                ret += this->m_Ufeo.enable(NULL);
            }
        }
    }
    if (p_parameter->bypass_imgo == MFALSE) {
        this->m_Imgo_FBC.m_fps[this->m_hwModule] = p_parameter->m_fps;
        for (MUINT32 iii = 0; iii < MAX_RECENT_GRPFRM_TIME; iii++) {
            this->m_Imgo_FBC.m_recentFrmTimeMs[this->m_hwModule][iii] = MIN_GRPFRM_TIME_MS;
        }
    }
    if (p_parameter->bypass_rrzo == MFALSE) {
        this->m_Rrzo_FBC.m_fps[this->m_hwModule] = p_parameter->m_fps;
        for (MUINT32 iii = 0; iii < MAX_RECENT_GRPFRM_TIME; iii++) {
            this->m_Rrzo_FBC.m_recentFrmTimeMs[this->m_hwModule][iii] = MIN_GRPFRM_TIME_MS;
        }
    }
    if (p_parameter->bypass_ufeo == MFALSE) {
        this->m_Ufeo_FBC.m_fps[this->m_hwModule] = p_parameter->m_fps;
        for (MUINT32 iii = 0; iii < MAX_RECENT_GRPFRM_TIME; iii++) {
            this->m_Ufeo_FBC.m_recentFrmTimeMs[this->m_hwModule][iii] = MIN_GRPFRM_TIME_MS;
        }
    }

    CAM_BUF_CTRL::updateState(CAM_BUF_CTRL::eCamState_runnable, this->m_hwModule, CAM_BUF_CTRL::eCamDmaType_main);

    //tuning drv need to init before isp start, and init only once before or after start
    //no sensor id , remove to p1tunecfg
    //this->m_Tuning._config();
    //this->m_Tuning._enable(NULL);

    ISP_PATH_DBG("CamPathPass1::config X");

    //inorder to dump 1st frame cq for dbg only
    this->m_TopCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0];
    return ret;
}


/**
add this membor is for FBC disable
*/
MINT32 CamPathPass1::_stop( void* pParam )
{
    ISP_PATH_DBG("_stop:0x%x E ",this->m_hwModule);

    MINT32  ret = 0;
    IspFunction_B**  isplist;
    int             ispcount;

    isplist  =  this->isp_function_list();
    ispcount =  this->isp_function_count();

    for(MUINT32 i = 0;i<this->m_pCmdQdrv->CmdQMgr_GetDuqQ();i++){
        for(MUINT32 j=0;j<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();j++){
            if(this->m_Imgo.m_pIspDrv != NULL){
                this->m_Imgo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Imgo.disable();
            }
            if(this->m_Rrzo.m_pIspDrv != NULL){
                this->m_Rrzo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                ret += this->m_Rrzo.disable();
            }
        }
    }

    for( int i = 0; i < ispcount; i++ )
    {
        //ISP_PATH_DBG("<%s> disable.",isplist[i]->name_Str() );
        if( ( ret += isplist[i]->disable(pParam) ) != 0 ){
            ISP_PATH_ERR("_stop fail\n");
            goto EXIT;
        }
    }

    //
    if((this->m_Lcso_FBC.m_pIspDrv || this->m_Rrzo_FBC.m_pIspDrv || this->m_Imgo_FBC.m_pIspDrv)){
        for(MUINT32 i = 0;i<this->m_pCmdQdrv->CmdQMgr_GetDuqQ();i++){
            for(MUINT32 j=0;j<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();j++){
                //
                if(this->m_Lcso_FBC.m_pIspDrv != NULL){
                    this->m_Lcso_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                    ret += this->m_Lcso_FBC.disable();
                }
                //
                if(this->m_Rrzo_FBC.m_pIspDrv != NULL){
                    this->m_Rrzo_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                    ret += this->m_Rrzo_FBC.disable();
                }
                //
                if(this->m_Imgo_FBC.m_pIspDrv != NULL){
                    this->m_Imgo_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                    ret += this->m_Imgo_FBC.disable();
                }
            }
        }
    }

    this->m_Tuning._disable();
    this->m_TuningFlg = MFALSE;

    //
    if (this->m_TgCtrl.m_pIspDrv != NULL) {
        this->m_TgCtrl.disable();


    }

    CAM_BUF_CTRL::updateState(CAM_BUF_CTRL::eCamState_stop, this->m_hwModule, CAM_BUF_CTRL::eCamDmaType_main);

    EXIT:

    ISP_PATH_DBG(":X ");

    return ret;
}


MINT32 CamPathPass1::setP1ImgoCfg(vector<DMACfg>* pImgo_cfg_L)
{
    MINT32 ret = 0;
    capibility CamInfo;
    tCAM_rst rst;
    tCAM_rst rstStrideByte;
    MUINT32 targetIdx = 0;
    MUINT32 _pix = _1_pix_;
    NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode = NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE;
    vector<DMACfg>::iterator it;
    int i;
    MUINT32 HwImgoFmt = IMGO_FMT_RAW8;
    Header_IMGO fh_imgo;
    Header_UFEO fh_ufeo;
    CAM_REG_CTL_FMT_SEL fmt_sel;

    if(pImgo_cfg_L->size() != this->m_pCmdQdrv->CmdQMgr_GetBurstQ()){
        ISP_PATH_ERR("imgo data length mismatch:0x%x_0x%x\n",(MUINT32)pImgo_cfg_L->size(),this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return 1;
    }

    if(this->m_FSM == op_start)
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    else
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

    for(i=0,it = pImgo_cfg_L->begin(); it!=pImgo_cfg_L->end();it++,i++)
    {
        switch(this->m_TopCtrl.cam_top_ctl.FMT_SEL.Bits.TG_FMT){
            case TG_FMT_RAW8:
            case TG_FMT_RAW10:
            case TG_FMT_RAW12:
            case TG_FMT_RAW14:
                switch(it->rawType){
                    case 0:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_AFTERLSC;
                        break;
                    case 1:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_FromTG;
                        break;
                    case 2:
                        this->m_RawCtrl.m_RawType = CAM_RAW_PIPE::E_BeforLSC;
                        break;
                    default:
                        ISP_PATH_ERR("unsupported format:%d\n",it->rawType);
                        break;
                }
                this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
                _pix = (NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE)this->m_RawCtrl.getCurPixMode(_imgo_);
                this->m_RawCtrl.setIMG_SEL();
                break;
            case TG_FMT_YUV422:
                _pix = (NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE)this->m_YuvCtrl.getCurPixMode(_imgo_);
                break;
            default:
                ISP_PATH_ERR("unsupported TG format:0x%x\n",this->m_TopCtrl.cam_top_ctl.FMT_SEL.Bits.TG_FMT);
                break;
        }

        switch(_pix){
            case _1_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE;
                break;
            case _2_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE;
                break;
            case _4_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE;
                break;
            default:
                ISP_PATH_ERR("unsupported pix mode:%d\n",_pix);
                pixMode = NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE;
                break;
        }

        this->m_Imgo.dma_cfg.lIspColorfmt = it->img_fmt;

        if (CamInfo.GetCapibility(
                EPortIndex_IMGO,
                NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_CROP_X_BYTE,
                NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo((EImageFormat)this->m_Imgo.dma_cfg.lIspColorfmt, it->crop.w, pixMode),
                rst, E_CAM_UNKNOWNN) == MFALSE) {
            ISP_PATH_ERR("cropping size err(0x%lx)\n",it->crop.w);
            ret = 1;
        }

        if (CamInfo.GetCapibility(
                EPortIndex_IMGO,
                NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_STRIDE_BYTE,
                NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo((EImageFormat)this->m_Imgo.dma_cfg.lIspColorfmt, it->tgCropW, ePixMode_4),
                rstStrideByte, E_CAM_UNKNOWNN) == MFALSE) {
            ISP_PATH_ERR("querying STRIDE_BYTE size err(0x%x)\n",it->tgCropW);
            ret = 1;
        }

        if(it->enqueue_img_stride != rstStrideByte.stride_byte){
            ISP_PATH_ERR("enqueue_img_stride(%d) != query_img_stride(%d)\n",it->enqueue_img_stride, rstStrideByte.stride_byte);
            return 1;
        }

        // Dynamic Change Pak/Unpak Fmt
        if(MTRUE == dynamicPakFmtMapping(this->m_Imgo.dma_cfg.lIspColorfmt, (MUINT32*)&HwImgoFmt)){
            this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
            if(MFALSE == this->m_RawCtrl.dynamicPak(HwImgoFmt)){
                ISP_PATH_ERR("dynamicPak error at burstidx:0x%x\n",i);
                ret = 1;
            }
        }

        //new IMGO FMT's stride for Dynamic UFO/Pak/UnPak
        this->m_Imgo.dma_cfg.size.stride = rstStrideByte.stride_byte;

        ISP_PATH_DBG("BurstIdx:0x%x,imago:0x%x_0x%x_0x%lx_0x%lx_0x%x,rawtype:0x%x,dbn:%d,bin:%d\n",i,\
            it->crop.x,\
            it->crop.y,\
            it->crop.w,\
            it->crop.h,\
            rst.xsize_byte,\
            it->rawType,\
            this->m_TopCtrl.cam_top_ctl.FUNC_EN.Bits.DBN_EN,\
            this->m_TopCtrl.cam_top_ctl.FUNC_EN.Bits.BIN_EN);

        //After Config, Enque New Img Fmt to Header
        fmt_sel.Raw = CAM_READ_REG(this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i], CAM_CTL_FMT_SEL);
        fh_imgo.Header_Enque(Header_IMGO::E_FMT,(ISP_DRV_CAM*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i], fmt_sel.Bits.IMGO_FMT);
        fh_ufeo.Header_Enque(Header_UFEO::E_FMT,(ISP_DRV_CAM*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i], fmt_sel.Bits.IMGO_FMT);

        this->m_Imgo.dma_cfg.crop.x = it->crop.x;
        this->m_Imgo.dma_cfg.crop.y = it->crop.y;
        this->m_Imgo.dma_cfg.crop.w = it->crop.w;
        this->m_Imgo.dma_cfg.crop.h = it->crop.h;
        this->m_Imgo.dma_cfg.size.xsize = rst.xsize_byte;
        this->m_Imgo.dma_cfg.size.h = it->crop.h;

        this->m_Imgo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if(this->m_Imgo.config()!=0){
            ISP_PATH_ERR("imgo config error at burstidx:0x%x\n",i);
            ret = 1;
        }


    }

    return ret;
}

MINT32 CamPathPass1::setP1RrzCfg(vector<IspRrzCfg>* pRrz_cfg_L)
{
    MINT32 ret = 0;
    capibility CamInfo;
    tCAM_rst rst;
    MUINT32 targetIdx = 0;
    vector<IspRrzCfg>::iterator it;
    int i;
    NSCam::NSIoPipe::NSCamIOPipe::Normalpipe_PIXMODE pixMode = NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE;

    if(pRrz_cfg_L->size() != this->m_pCmdQdrv->CmdQMgr_GetBurstQ()){
        ISP_PATH_ERR("rrz data length mismatch:0x%x_0x%x\n",(MUINT32)pRrz_cfg_L->size(),this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return 1;
    }

    if(this->m_FSM == op_start)
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    else
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

    for(i=0,it=pRrz_cfg_L->begin();it!=pRrz_cfg_L->end();i++,it++)
    {
        ISP_PATH_DBG("BurstIdx:0x%x,rrz out:0x%lx_0x%lx, roi:0x%x_0x%x_0x%lx_0x%lx\n",i,\
            it->rrz_out_size.w,\
            it->rrz_out_size.h,\
            it->rrz_in_roi.x,\
            it->rrz_in_roi.y,\
            it->rrz_in_roi.w,\
            it->rrz_in_roi.h);

        //rrzo use no dmao cropping function, cropping function is depended on rrz
        this->m_Rrzo.dma_cfg.crop.x = 0;
        this->m_Rrzo.dma_cfg.crop.y = 0;
        this->m_Rrzo.dma_cfg.crop.floatX = 0;
        this->m_Rrzo.dma_cfg.crop.floatY = 0;
        this->m_Rrzo.dma_cfg.crop.w = it->rrz_in_roi.w;
        this->m_Rrzo.dma_cfg.crop.h = it->rrz_in_roi.h;
        this->m_Rrzo.dma_cfg.size.w = it->rrz_out_size.w;
        this->m_Rrzo.dma_cfg.size.h = it->rrz_out_size.h;


        //mark, use original stride which is configured at init phase
        //DMARrzo.dma_cfg.size.stride = rrz_cfg.rrz_out_size.stride;
        this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        switch(this->m_RawCtrl.getCurPixMode(_rrzo_)){
            case _1_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_1_PIX_MODE;
                break;
            case _2_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_2_PIX_MODE;
                break;
            case _4_pix_:   pixMode = NSCam::NSIoPipe::NSCamIOPipe::_4_PIX_MODE;
                break;
            default:
                ISP_PATH_ERR("unsupported pix mode:%d\n",this->m_RawCtrl.getCurPixMode(_rrzo_));
                pixMode = NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE;
                break;
        }
        if (CamInfo.GetCapibility(
                EPortIndex_RRZO,
                NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE,
                NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo((EImageFormat)this->m_Rrzo.dma_cfg.lIspColorfmt,
                                                                    this->m_Rrzo.dma_cfg.size.w,
                                                                    pixMode),
                rst, E_CAM_UNKNOWNN) == MFALSE) {
            ISP_PATH_ERR("rrzo size err(0x%lx)\n",this->m_Rrzo.dma_cfg.size.w);
            ret = 1;
        }
        this->m_Rrzo.dma_cfg.size.xsize      =  rst.xsize_byte;

        //update xsize cfg
        this->m_Rrzo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if(this->m_Rrzo.config()!=0){
            ISP_PATH_ERR("rrzo config error at burstidx:0x%x\n",i);
            ret = 1;
        }

        //update rrz
        this->m_Rrz.rrz_in_roi      = it->rrz_in_roi;
        this->m_Rrz.rrz_out_size    = it->rrz_out_size;


        //update rrz cfg
        this->m_Rrz.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if(this->m_Rrz.config() != 0){
            ISP_PATH_ERR("rrz config error at burstidx:0x%x\n",i);
            ret = 1;
        }

    }

    return ret;
}

MINT32 CamPathPass1::setP1UfeoCfg(vector<DMACfg>* pUfeo_cfg_L)
{
	MINT32 ret = 0;
    capibility CamInfo;
    tCAM_rst rst;
    MUINT32 targetIdx = 0;
    vector<DMACfg>::iterator it;
    int i;

    if(pUfeo_cfg_L->size() != this->m_pCmdQdrv->CmdQMgr_GetBurstQ()){
        ISP_PATH_ERR("ufeo data length mismatch:0x%x_0x%x\n",(MUINT32)pUfeo_cfg_L->size(),this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return 1;
    }

    if(this->m_FSM == op_start)
            targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
        else
            targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

    for(i = 0, it = pUfeo_cfg_L->begin(); it != pUfeo_cfg_L->end(); i++, it++)
        {
             ISP_PATH_DBG("BurstIdx:0x%x,ufeo out:0x%lx_0x%lx",i,\
                 it->out.w,\
                 it->out.h);

             this->m_Ufeo.dma_cfg.size.w = it->out.w;
             this->m_Ufeo.dma_cfg.size.h = it->out.h;

             //UFEO xsize
             if (CamInfo.GetCapibility(
                     EPortIndex_UFEO,
                     NSCam::NSIoPipe::NSCamIOPipe::ENPipeQueryCmd_X_BYTE,
                     NSCam::NSIoPipe::NSCamIOPipe::NormalPipe_InputInfo((EImageFormat)this->m_Ufeo.dma_cfg.lIspColorfmt,
                                                                        this->m_Ufeo.dma_cfg.size.w,
                                                                        NSCam::NSIoPipe::NSCamIOPipe::_UNKNOWN_PIX_MODE),
                     rst, E_CAM_UNKNOWNN) == MFALSE) {
                 ISP_PATH_ERR("rrzo size err(0x%lx)\n",this->m_Rrzo.dma_cfg.size.w);
                 ret = 1;
             }
             this->m_Ufeo.dma_cfg.size.xsize      =  rst.xsize_byte;

             //update xsize cfg
             this->m_Ufeo.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
             if(this->m_Ufeo.config()!=0){
                 ISP_PATH_ERR("ufeo config error at burstidx:0x%x\n",i);
                 ret = 1;
             }
         }
	return ret;
}

MINT32 CamPathPass1::setP1TuneCfg(vector<IspP1TuningCfg>* pTune_L)
{
    MINT32 ret = 0;
    MUINT32 targetIdx = 0;
    vector<IspP1TuningCfg>::iterator it;
    int i;

    if(pTune_L->size() != this->m_pCmdQdrv->CmdQMgr_GetBurstQ()){
        ISP_PATH_ERR("tuning data length mismatch:0x%x_0x%x\n",(MUINT32)pTune_L->size(),this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return 1;
    }

    if(this->m_FSM == op_start){
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    }
    else{
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();
    }

    if(this->m_TuningFlg == MFALSE){
        //ref line:344
        this->m_Tuning.m_SenDev = pTune_L->begin()->SenDev;
        this->m_Tuning._config();
        this->m_Tuning._enable(NULL);
        if(NULL != this->m_Tuning.m_Magic){
            //free here , not at stop is because of user can uninit before stop.
            free(this->m_Tuning.m_Magic);
        }
        this->m_Tuning.m_Magic = (MUINT32*)malloc(sizeof(MINT32) * this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        this->m_TuningFlg = MTRUE;
    }

    for(i=0,it=pTune_L->begin();it!=pTune_L->end();i++,it++){
        this->m_Tuning.m_Magic[i] = it->magic;
    }

    for(i=0,it=pTune_L->begin();it!=pTune_L->end();i++,it++)
    {
        ISP_PATH_DBG("BurstIdx:0x%x,magic:0x%x\n",i,it->magic);

        //update magic
        this->m_Magic.m_nMagic = it->magic;

        this->m_Magic.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if(this->m_Magic._config()!=0){
            ISP_PATH_ERR("maic config error at burstidx:0x%x\n",i);
            ret = 1;
        }

        //update tuning
        //remove to above for loop for working with tuningMgr.
        //this->m_Tuning.m_Magic[i] = it->magic;
        this->m_Tuning.m_SenDev = it->SenDev;
        //
        if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
            this->m_Tuning.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
        }
        else{
            this->m_Tuning.m_pUniDrv = NULL;
        }

        this->m_Tuning.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if(this->m_Tuning.update() != 0){
            ISP_PATH_ERR("Tuning error\n");
            ret = 1;
        }
    }

    if(this->m_Tuning.update_end() != 0){
        ISP_PATH_ERR("Tuning enque error\n");
        ret = 1;
    }


    return ret;
}

MBOOL CamPathPass1::P1Notify_Mapping(MUINT32 cmd,P1_TUNING_NOTIFY* pObj)
{
    MBOOL ret = MTRUE;
    MUINT32 tbl_len = 0;

    while(tbl_len < p1Notify_node){
        if(this->m_p1NotifyTbl[tbl_len] == cmd)
            break;
        tbl_len++;
    }

    //if notify module is exist in drv,
    //enabled FBC , modules which belong to FBC is enabled in UNI_MGR
    if(tbl_len < p1Notify_node){
        switch(cmd){
            case EPIPECmd_SET_LCS_CBFP:
                {
                    for(MUINT32 i=0;i<this->m_pCmdQdrv->CmdQMgr_GetDuqQ();i++){
                        for(MUINT32 j=0;j<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();j++){
                            this->m_Lcso_FBC.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(i)[j];
                            this->m_Lcso_FBC.config();
                            this->m_Lcso_FBC.write2CQ();
                            this->m_Lcso_FBC.enable(NULL);
                        }
                    }
                    //
                    this->m_Lcso_FBC.m_pTimeStamp = CAM_TIMESTAMP::getInstance(this->m_hwModule,NULL);

                    this->m_p1NotifyObj[tbl_len] = pObj;
                }
                break;
            case EPIPECmd_SET_EIS_CBFP:
            case EPIPECmd_SET_SGG2_CBFP:
            case EPIPECmd_SET_RSS_CBFP:
            case EPIPECmd_SET_REGDUMP_CBFP:
                this->m_p1NotifyObj[tbl_len] = pObj;
                break;
            default:
                ret = MFALSE;
                ISP_PATH_ERR("un-supported p1notify_0x%x\n",cmd);
                break;
        }
    }

    return ret;
}

MINT32 CamPathPass1::setP1Notify(void)
{
    MUINT32 node = 0;
    MINT32 ret = 0;
    MUINT32 targetIdx = 0;

    if(this->m_FSM == op_start)
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    else
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

    switch(this->m_TopCtrl.cam_top_ctl.FMT_SEL.Bits.TG_FMT){
        case TG_FMT_RAW8:
        case TG_FMT_RAW10:
        case TG_FMT_RAW12:
        case TG_FMT_RAW14:

            while(node < p1Notify_node){
                if(this->m_p1NotifyObj[node]!= NULL){

                    this->m_RawCtrl.m_pP1Tuning = (P1_TUNING_NOTIFY*)this->m_p1NotifyObj[node];
                        ISP_PATH_DBG("CAM(%d), P1Notify: %s\n", this->m_hwModule, this->m_RawCtrl.m_pP1Tuning->TuningName());

                    //
                    for(MUINT32 i=0;i<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();i++){

                        this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
                        switch(node){
                            case _EIS_:
                                //
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_RawCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_RawCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                     ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_RawCtrl.m_pP1Tuning->TuningName(),
                                                this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_RawCtrl.setEIS() == MFALSE)
                                    ret =1;
                                break;
                            case _LCS_:
                                if(this->m_RawCtrl.setLCS() == MFALSE)
                                    ret = 1;
                                break;
                            case _SGG2_:
                                //
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_RawCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_RawCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                    ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_RawCtrl.m_pP1Tuning->TuningName(),
                                                this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_RawCtrl.setSGG2() == MFALSE)
                                    ret = 1;
                                break;
                            case _RSS_:
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_RawCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_RawCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                    ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_RawCtrl.m_pP1Tuning->TuningName()
                                        ,this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_RawCtrl.setRSS() == MFALSE)
                                    ret = 1;
                                break;
                            case _REG_DUMP_:
                                if (this->m_RawCtrl.dumpCQReg() == MFALSE) {
                                    ret = 1;
                                }
                                break;
                            default:
                                    ISP_PATH_INF("P1Notify: [%s] node:0x%x is not supported in drv\n",this->m_RawCtrl.m_pP1Tuning->TuningName(), node);
                                ret =1;
                                break;
                        }
                        if(ret != 0)
                            ISP_PATH_ERR("P1Notify_%s fail! \n",this->m_RawCtrl.m_pP1Tuning->TuningName());
                    }
                }
                node++;
            }

            break;
        case TG_FMT_YUV422:

            while(node < p1Notify_node){
                if(this->m_p1NotifyObj[node]!= NULL){

                    this->m_YuvCtrl.m_pP1Tuning = (P1_TUNING_NOTIFY*)this->m_p1NotifyObj[node];
                    ISP_PATH_INF("P1Notify: %s\n",this->m_YuvCtrl.m_pP1Tuning->TuningName());
                    //
                    for(MUINT32 i=0;i<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();i++){

                        this->m_YuvCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
                        switch(node){
                            case _EIS_:
                                //
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_YuvCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_YuvCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                    ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_YuvCtrl.m_pP1Tuning->TuningName()
                                        ,this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_YuvCtrl.setEIS() == MFALSE)
                                    ret = 1;
                                break;
                            case _LCS_:
                                if(this->m_YuvCtrl.setLCS() == MFALSE)
                                    ret = 1;
                                break;
                            case _SGG2_:
                                //
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_YuvCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_YuvCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                    ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_YuvCtrl.m_pP1Tuning->TuningName(),
                                        this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_YuvCtrl.setSGG2() == MFALSE)
                                    ret = 1;
                                break;
                            case _RSS_:
                                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                                    this->m_YuvCtrl.m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                                }
                                else{
                                    this->m_YuvCtrl.m_pUniDrv = NULL;
                                    //this should not be happened, because if uni is not linked with current cam, HOOK CB should fail earlier.
                                    ISP_PATH_ERR("P1Notify: [%s][%d] uni is linked with cam:%d\n",this->m_YuvCtrl.m_pP1Tuning->TuningName(),
                                        this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                                    return 1;
                                }
                                if(this->m_YuvCtrl.setRSS() == MFALSE)
                                    ret = 1;
                                break;
                            case _REG_DUMP_:
                            default:
                                ISP_PATH_INF("P1Notify: [%s] node:0x%x is not supported in drv\n",this->m_YuvCtrl.m_pP1Tuning->TuningName(), node);
                                ret =1;
                                break;
                        }
                        if(ret != 0)
                            ISP_PATH_ERR("P1Notify_%s fail! \n",this->m_YuvCtrl.m_pP1Tuning->TuningName());
                    }
                }
                node++;
            }

            break;
        default:
            ISP_PATH_ERR("P1Notify: [%s] unsupported TG format:0x%x\n",this->m_YuvCtrl.m_pP1Tuning->TuningName(),
                this->m_TopCtrl.cam_top_ctl.FMT_SEL.Bits.TG_FMT);
            return 1;
            break;
    }


    return ret;
}


/* return value:
   0: sucessed
else: fail */
MINT32 CamPathPass1::enqueueBuf( MUINT32 const dmaChannel, ISP_BUF_INFO_L& bufInfo, MVOID* private_data, MBOOL bImdMode )
{
    CAM_BUF_CTRL* pFBC = NULL;
    DMAO_B* pDmao = NULL;
    MUINT32 targetIdx = 0;
    MINT32 ret = 0;

    //warning free
    UNUSED(private_data);
    UNUSED(bImdMode);

    switch(dmaChannel){
        case _imgo_:
            pFBC = &this->m_Imgo_FBC;
            pDmao = &this->m_Imgo;
            break;
        case _rrzo_:
            pFBC = &this->m_Rrzo_FBC;
            pDmao = &this->m_Rrzo;
            break;
        case _ufeo_:
            pFBC = &this->m_Ufeo_FBC;
            pDmao = &this->m_Ufeo;
            break;
        case _lcso_:
            pFBC = &this->m_Lcso_FBC;
            pDmao = &this->m_Lcso;
            break;
        case _eiso_:
            if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                MUINTPTR _pdmao,_pfbc;
                if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_EIS_,&_pdmao,&_pfbc) == MFALSE){
                    return 1;
                }
                pFBC = (CAM_BUF_CTRL*)_pfbc;
                pDmao = (DMAO_B*)_pdmao;

                pFBC->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                pDmao->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
            }
            else{
                ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                return 1;
            }
            break;
        case _rsso_:
            if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                MUINTPTR _pdmao,_pfbc;
                if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_RSS_,&_pdmao,&_pfbc) == MFALSE){
                    return 1;
                }
                pFBC = (CAM_BUF_CTRL*)_pfbc;
                pDmao = (DMAO_B*)_pdmao;
                pFBC->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                pDmao->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
            }
            else{
                ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                return 1;
            }
            break;
        default:
            ISP_PATH_ERR("unsupported dmao:0x%x\n",dmaChannel);
            return 1;
            break;
    }

    if(bufInfo.size() != this->m_pCmdQdrv->CmdQMgr_GetBurstQ()){
        ISP_PATH_ERR("enque data length mismatch:0x%x_0x%x\n",(MUINT32)bufInfo.size(),this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return 1;
    }

    if (this->m_FSM == op_start) {
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    } else {
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();
    }

    this->m_lock.lock();
    for (MUINT32 i = 0; i < this->m_pCmdQdrv->CmdQMgr_GetBurstQ(); i++) {

        pFBC->m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];

        if (eCmd_Fail == pFBC->enqueueHwBuf(bufInfo.at(i),bImdMode)) {
            ISP_PATH_ERR("enque fail at burst:0x%x\n",i);
            ret = 1;
        }

        if (bufInfo.at(i).bReplace == MTRUE) {
            pDmao->dma_cfg.memBuf.base_pAddr = bufInfo.at(i).Replace.image.mem_info.pa_addr;
            pDmao->Header_Addr = bufInfo.at(i).Replace.header.pa_addr;
        } else {
            pDmao->dma_cfg.memBuf.base_pAddr = bufInfo.at(i).u_op.enque.image.mem_info.pa_addr;
            pDmao->Header_Addr = bufInfo.at(i).u_op.enque.header.pa_addr;

            if (SecMgr::SecMgr_GetSecureCamStatus(this->m_hwModule) > 0) {
                if (SecMgr::SecMgr_GetSecurePortStatus(this->m_hwModule, dmaChannel)) {
                    SecMgr *mpSecMgr = SecMgr::SecMgr_GetMgrObj();
                    MUINT32 SecPA = 0;
                    SecMgr_SecInfo secinfo;

                    memset(&secinfo, 0, sizeof(SecMgr_SecInfo));
                    secinfo.type = SECMEM_FRAME_HEADER;
                    secinfo.module = this->m_hwModule;
                    secinfo.buff_size = bufInfo.at(i).u_op.enque.header.size;
                    secinfo.buff_va = bufInfo.at(i).u_op.enque.header.va_addr;
                    secinfo.port = dmaChannel;
                    if (mpSecMgr->SecMgr_QueryFHSecMVA(secinfo, &SecPA)) {
                        pDmao->Header_Addr = SecPA;
                        ISP_PATH_INF("Sec FH Addr:0x%x", pDmao->Header_Addr);
                    } else {
                        ISP_PATH_ERR("Translate FH PA failed");
                        ret = 1;
                        goto EXIT;
                    }
                }
            }
        }
        pDmao->m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        if (pDmao->setBaseAddr()) {
            ISP_PATH_ERR("set baseaddress at burst:0x%x\n",i);
            ret = 1;
        }
    }
EXIT:
    this->m_lock.unlock();
    return ret;

}


/* return value:
 2: suspending
 1: already stopped
 0: sucessed
-1: fail */
MINT32 CamPathPass1::dequeueBuf( MUINT32 const dmaChannel ,vector<BufInfo>& bufInfo,MUINT32 const u4TimeoutMs, CAM_STATE_NOTIFY *pNotify)
{
    CAM_BUF_CTRL* pFBC = NULL;
    BufInfo buf;
    MINT32 ret = 0;

    u4TimeoutMs;
    switch(dmaChannel){
        case _imgo_:
            pFBC = &this->m_Imgo_FBC;
            break;
        case _rrzo_:
            pFBC = &this->m_Rrzo_FBC;
            break;
        case _ufeo_:
            pFBC = &this->m_Ufeo_FBC;
            break;
        case _lcso_:
            pFBC = &this->m_Lcso_FBC;
            break;
        case _eiso_:
            {
                MUINTPTR _pfbc,ptr;
                if(this->m_UniMgr.UniMgr_GetCurLink() != this->m_hwModule){
                    ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                    return -1;
                }
                if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_EIS_,&ptr,&_pfbc) == MFALSE){
                    return -1;
                }
                pFBC = (CAM_BUF_CTRL*)_pfbc;
                break;
            }
        case _rsso_:
            {
                MUINTPTR _pfbc,ptr;
                if(this->m_UniMgr.UniMgr_GetCurLink() != this->m_hwModule){
                    ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                    return -1;
                }
                if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_RSS_,&ptr,&_pfbc) == MFALSE){
                    return -1;
                }
                pFBC = (CAM_BUF_CTRL*)_pfbc;
                break;
            }
        default:
            ISP_PATH_ERR("unsupported dmao:0x%x\n",dmaChannel);
            return -1;
            break;
    }

    if(bufInfo.size() != 0){
        ISP_PATH_ERR("list is not empty\n");
        return -1;
    }

    //for dbg mechanism,pipecheck, when current dmao is not belong to UNI.
    if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
        pFBC->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
    }
    else
        pFBC->m_pUniDrv = NULL;//avoid pipe check NE if previous scenario have uni ptr and current scenario have deque fail

    //can't update this para. , in order to prevent racing condition
    //pFBC->m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx())[0];
    //check if there is already filled buffer
    switch(pFBC->waitBufReady(pNotify)){
        case eCmd_Fail:
            return -1;
            break;
        case eCmd_Stop_Pass:
            ISP_PATH_WRN("waitBufRdy: VF_EN=0, dma(0x%x)\n", dmaChannel);
            return 1;
            break;
        case eCmd_Suspending_Pass:
            //need to do deque , in order to pop all those requests in drv.
            break;
        default:
            break;
    }

    this->m_lock.lock();
    for(MUINT32 i=0;i<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();i++){
        //can't update this para. , in order to prevent racing condition
        //pFBC->m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx())[i];
        switch(pFBC->dequeueHwBuf( buf )){
            case eCmd_Fail:
                ISP_PATH_ERR("data is rdy on dram,but deque fail at burst:0x%x\n",i);
                ret = -1;
                break;
            case eCmd_Stop_Pass:
                ISP_PATH_WRN("current status:eCmd_Stop_Pass\n");
                ret = 1;
                break;
            case eCmd_Suspending_Pass:
                ISP_PATH_WRN("current status:eCmd_Suspending_Pass\n");
                ret = 2;
                break;
            default:
                break;
        }
        bufInfo.push_back(buf);
    }
    this->m_lock.unlock();

    return ret;
}

MINT32 CamPathPass1::dropEnqueueBuf(vector<MUINT32>* pLPortNum, vector<MUINT32>* pLMagicNum)
{
    MINT32          ret = MTRUE;
    CAM_BUF_CTRL    *pFBC = NULL;
    DMAO_B          *pDmao = NULL;
    MUINT32         targetIdx = 0;
    vector<MUINT32>::iterator it;

    ISP_PATH_INF(": +\n");

    if (this->m_pCmdQdrv->CmdQMgr_GetBurstQ() != pLMagicNum->size()) {
        ISP_PATH_ERR("data length mismatch:0x%x_0x%x\n",pLMagicNum->size(),
                this->m_pCmdQdrv->CmdQMgr_GetBurstQ());
        return MFALSE;
    }

    for(it = pLPortNum->begin(); it!= pLPortNum->end(); it++) {
        switch (*it){
            case _imgo_:
                pFBC = &this->m_Imgo_FBC;
                pDmao = &this->m_Imgo;
                break;
            case _rrzo_:
                pFBC = &this->m_Rrzo_FBC;
                pDmao = &this->m_Rrzo;
                break;
            case _ufeo_:
                pFBC = &this->m_Ufeo_FBC;
                pDmao = &this->m_Ufeo;
                break;
            case _lcso_:
                pFBC = &this->m_Lcso_FBC;
                pDmao = &this->m_Lcso;
                break;
            case _eiso_:
                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                    MUINTPTR _pdmao,_pfbc;
                    if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_EIS_,&_pdmao,&_pfbc) == MFALSE){
                        return MFALSE;
                    }
                    pFBC = (CAM_BUF_CTRL*)_pfbc;
                    pDmao = (DMAO_B*)_pdmao;

                    pFBC->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                    pDmao->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                }
                else{
                    ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                    return MFALSE;
                }
                break;
            case _rsso_:
                if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                    MUINTPTR _pdmao,_pfbc;
                    if(this->m_UniMgr.UniMgr_GetModuleObj(UniMgr::_UNI_RSS_,&_pdmao,&_pfbc) == MFALSE){
                        return MFALSE;
                    }
                    pFBC = (CAM_BUF_CTRL*)_pfbc;
                    pDmao = (DMAO_B*)_pdmao;
                    pFBC->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                    pDmao->m_pUniDrv = this->m_UniMgr.UniMgr_GetCurObj();
                }
                else{
                    ISP_PATH_ERR("[%d] uni is linked with cam:%d\n",this->m_hwModule,this->m_UniMgr.UniMgr_GetCurLink());
                    return MFALSE;
                }
                break;

            default:
                ISP_PATH_INF("unsupported port:%d\n", *it);
                break;
        }

        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

        this->m_lock.lock();
        for(MUINT32 i=0; i<this->m_pCmdQdrv->CmdQMgr_GetBurstQ(); i++) {
            IspDrvVir *_pCurDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];

            pFBC->m_pIspDrv = _pCurDrv;
            if(eCmd_Fail == pFBC->dropEnqueueHwBuf()){
                ISP_PATH_ERR("drop fail at burst:0x%x\n",i);
                ret = MFALSE;
            }
        }
        this->m_lock.unlock();
    }
    ISP_PATH_INF(": -\n");

    return ret;
}

MBOOL CamPathPass1::suspend(E_CAMPATH_SUSPEND_OP eOP)
{
    MUINT32 _step = 0;
    UniDrvImp *pUniAttach;

    ISP_PATH_DBG("enter suspending mode:\n");

    switch (eOP) {
    case _CAMPATH_SUSPEND_STOPHW:
        if (CAM_BUF_CTRL::suspend(this->m_hwModule, this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0],
                                    NULL, CAM_BUF_CTRL::eSus_HWOFF) == MFALSE) {
            _step = 1;
        }

        if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
            pUniAttach = this->m_UniMgr.UniMgr_GetCurObj();
        }
        else {
            pUniAttach = NULL;
        }
        if (CAM_BUF_CTRL::suspend(this->m_hwModule, this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0],
                                    pUniAttach, CAM_BUF_CTRL::eSus_HW_SW_STATE) == MFALSE) {
            _step = 2;
        }
        break;
    case _CAMPATH_SUSPEND_FLUSH:
        if (CAM_BUF_CTRL::suspend(this->m_hwModule, this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0],
                                    NULL, CAM_BUF_CTRL::eSus_SIGNAL) == MFALSE) {
            _step = 3;
        }
        break;
    default:
        ISP_PATH_ERR("Error suspend state: %d\n", (MUINT32)eOP);
        return MFALSE;
    }

    if (_step) {
        ISP_PATH_ERR("Error suspending step:%d, op:%d\n", _step, (MUINT32)eOP);
        return MFALSE;
    }

    return MTRUE;
}

MBOOL CamPathPass1::resume(void)
{
    MBOOL ret;

    ISP_PATH_INF("exit suspending mode");

    if (this->m_pCmdQdrv->CmdQMgr_ImmStart()) {
        ISP_PATH_ERR("cam_path cmdQMgr immStart fail!\n");
        return MFALSE;
    }

    return CAM_BUF_CTRL::resume(this->m_hwModule, this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(0)[0]);
}

MBOOL CamPathPass1::HW_recover(E_CAMPATH_STEP op)
{
    ISP_PATH_DBG("enter HW_recover:%d\n",op);
    switch(op){
        case eCmd_path_stop:
            if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                this->m_UniMgr.UniMgr_recover(eCmd_Uni_stop,this->m_hwModule);
            }

            return this->m_TopCtrl.HW_recover(0);
            break;
        case eCmd_path_restart:
            if(this->m_UniMgr.UniMgr_GetCurLink() == this->m_hwModule){
                this->m_UniMgr.UniMgr_recover(eCmd_Uni_restart,this->m_hwModule);
            }

            return this->m_TopCtrl.HW_recover(1);
            break;
        default:
            ISP_PATH_ERR("unsupported:%d",op);
            return MFALSE;
            break;
    }
    return MTRUE;
}

MBOOL CamPathPass1::updateFrameTime(MUINT32 timeInMs, MUINT32 reqOffset)
{
    return CAM_BUF_CTRL::updateFrameTime(timeInMs, reqOffset, this->m_hwModule);
}

MBOOL CamPathPass1::updateXMXO(T_XMXO* pxmx)
{
    MBOOL ret = MTRUE;
    MUINT32 targetIdx = 0;

    if(this->m_FSM == op_start)
        targetIdx = ((this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx() + 1)% this->m_pCmdQdrv->CmdQMgr_GetDuqQ());
    else
        targetIdx = this->m_pCmdQdrv->CmdQMgr_GetDuqQIdx();

    //
    memcpy((void *) &this->m_RawCtrl.m_xmxo, (void *) pxmx, sizeof(T_XMXO));

    //
    for(MUINT32 i=0;i<this->m_pCmdQdrv->CmdQMgr_GetBurstQ();i++){
        //
        this->m_RawCtrl.m_pIspDrv = (IspDrvVir*)this->m_pCmdQdrv->CmdQMgr_GetCurCycleObj(targetIdx)[i];
        this->m_RawCtrl.config();
    }

    return ret;
}


MBOOL CamPathPass1::dynamicPakFmtMapping(ImgInfo::EImgFmt_t imgFmt, MUINT32* pHwImgoFmt)
{
    MBOOL ret = MTRUE;

    switch (imgFmt) {
        case eImgFmt_BAYER8:          //= 0x0001,   //Bayer format, 8-bit
            *pHwImgoFmt = IMGO_FMT_RAW8;
            break;
        case eImgFmt_BAYER10:         //= 0x0002,   //Bayer format, 10-bit
            *pHwImgoFmt = IMGO_FMT_RAW10;
            break;
        case eImgFmt_BAYER12:         //= 0x0004,   //Bayer format, 12-bit
            *pHwImgoFmt = IMGO_FMT_RAW12;
            break;
        case eImgFmt_BAYER14:         //= 0x0008,   //Bayer format, 14-bit
            *pHwImgoFmt = IMGO_FMT_RAW14;
            break;
        case eImgFmt_BAYER8_UNPAK:
            *pHwImgoFmt = IMGO_FMT_RAW8_2B;
            break;
        case eImgFmt_BAYER10_UNPAK:
            *pHwImgoFmt = IMGO_FMT_RAW10_2B;
            break;
        case eImgFmt_BAYER12_UNPAK:
            *pHwImgoFmt = IMGO_FMT_RAW12_2B;
            break;
        case eImgFmt_BAYER14_UNPAK:
            *pHwImgoFmt = IMGO_FMT_RAW14_2B;
            break;
        default:
            ISP_PATH_DBG("eImgFmt:[0x%x]NOT Support PakUnPakFmtMapping",imgFmt);
            ret = MFALSE;
    }
    //
    ISP_PATH_DBG("input imgFmt(0x%x),output HwImgoFmtValue:0x%x",imgFmt, *pHwImgoFmt);
    return ret;
}


Cam_path_sel::Cam_path_sel(CamPathPass1Parameter* pObj)
{
    m_this = pObj;
}

Cam_path_sel::~Cam_path_sel()
{}

MBOOL Cam_path_sel::Path_sel_YUV(MBOOL bPureRaw,MBOOL bPak,MBOOL bRawI,E_DatPat data_pat)
{   // YUV
    MBOOL rst = MTRUE;

    bPureRaw;bPak;bRawI;data_pat;

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= HDS1_SEL_0;

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= SGG_SEL_0;

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= LCS_SEL_0;

    //IMG_SEL + UFE_SEL
    this->m_this->m_top_ctl.CTRL_SEL.Raw |= IMG_SEL_1;
    this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFE_SEL_2;

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= FLK1_SEL_1;


    //PMX & RCP3 is useless under YUV format

    return rst;
}


MBOOL Cam_path_sel::Path_sel_RAW(MBOOL bPureRaw,MBOOL bPak,MBOOL bRawI,E_DatPat data_pat)
{    //bayer
    MBOOL rst = MTRUE;
    bRawI;

    if(this->m_this->bypass_rrzo)
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= HDS1_SEL_0;
    else
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= HDS1_SEL_1;

    if(this->m_this->bypass_ufeo){
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFEG_SEL_0;
    }
    else{
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFEG_SEL_1;
    }
    this->m_this->m_top_ctl.CTRL_SEL.Raw |= SGG_SEL_1;

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= LCS_SEL_1;

    //IMG_SEL + UFE_SEL + PMX + rcp3
    if(bPureRaw){
        if(bPak)
            this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFE_SEL_0;
        else
            this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFE_SEL_2;

        //rcp3 is userless at pure data when data
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= RCP3_SEL_2;

        //PMX+rcp3
        switch(data_pat){
            case _dual_pix_:
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= PMX_SEL_1;

                //rcp3 is fixed at 2 when pure + dual pattern
                 this->m_this->m_top_ctl.CTRL_SEL.Raw |= RCP3_SEL_2;
                break;
            case _4cell_:
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= IMG_SEL_1;
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= PMX_SEL_0;
                break;
            case _normal_:
            default:
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= PMX_SEL_2;
                //rcp3 is useless under normal pattern at pure data
                break;
        }
    }
    else{
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= IMG_SEL_2;
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= UFE_SEL_0;

        //PMX+rcp3
        switch(data_pat){
            case _dual_pix_:
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= PMX_SEL_1;
                break;
            case _4cell_:
                ISP_PATH_ERR("quad_code don't support process raw\n");
                rst = MFALSE;
                break;
            case _normal_:
            default:
                this->m_this->m_top_ctl.CTRL_SEL.Raw |= PMX_SEL_2;
                break;
        }
        //rcp3 is fixed , 0/1 is not supported yet!
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= RCP3_SEL_3;
    }

    this->m_this->m_top_ctl.CTRL_SEL.Raw |= FLK1_SEL_0;

    return rst;
}




MBOOL Cam_path_sel::Path_sel(MBOOL bPureRaw,MBOOL bPak,MBOOL bRawI,E_DatPat data_pat)
{
    MBOOL rst = MTRUE;
    this->m_this->m_top_ctl.CTRL_SEL.Raw = 0x0;

    if(bRawI){  //DMAI

        //DMX_SEL
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= DMX_SEL_2;
        ISP_PATH_ERR("RAW IN is not supported yet!\n");
        rst = MFALSE;
    }
    else{   // TG IN.

        //DMX_SEL
        this->m_this->m_top_ctl.CTRL_SEL.Raw |= DMX_SEL_0;
    }

    if(this->m_this->bypass_ispRawPipe == MFALSE){    //bayer

        rst = this->Path_sel_RAW(bPureRaw,bPak,bRawI,data_pat);

    }
    else{   // YUV

        rst = this->Path_sel_YUV(bPureRaw,bPak,bRawI,data_pat);
    }

    return rst;
}


