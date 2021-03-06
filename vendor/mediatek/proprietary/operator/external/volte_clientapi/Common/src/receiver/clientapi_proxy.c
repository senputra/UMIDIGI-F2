#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "clientapi_comm.h"
#include "clientapi_proxy.h"
#include "clientapi_proxy_adapter.h"
#include "clientapi_proxy_dispatcher.h"
#include "debug.h"


#define LOGGER_ENTRY_MAX_LEN        (4*4096)


char* getClientapiEvent(int requestId) {

    switch (requestId) {
        case CMD_REQ_REG_INFO:          return "CMD_REQ_REG_INFO";
        case CMD_IMS_REGISTER:          return "CMD_IMS_REGISTER";
        case CMD_IMS_DEREGISTER:        return "CMD_IMS_DEREGISTER";
        case CMD_SEND_SIP_MSG:          return "CMD_SEND_SIP_MSG";
        case CMD_UNPUBLISH_COMPLETED:   return "CMD_UNPUBLISH_COMPLETED";
        case CMD_IMS_RECOVER_REGISTER_IND:   return "CMD_IMS_RECOVER_REGISTER_IND";
        case RSP_REQ_REG_INFO:          return "RSP_REQ_REG_INFO";
        case RSP_IMS_REGISTER:          return "RSP_IMS_REGISTER";
        case RSP_EVENT_SIP_MSG:         return "RSP_EVENT_SIP_MSG";
        case VOLTE_IND_SIPTX_REG_STATE: return "VOLTE_IND_SIPTX_REG_STATE";
        default:                        return "unknown_clientapi_event";
    }
}

/* hanld events from the dispatcher */
int handleEventFromDispatcher(CLIENTAPI_EventMsg_t *event) {

    DbgMsg("send clientapi event to adapter:  %s", getClientapiEvent(event->request_id));

    switch (event->request_id) {

        case RSP_REQ_REG_INFO:
            CLIENTAPI_COMM_Send(event);
            break;
        case RSP_IMS_REGISTER:
            break;
        case RSP_EVENT_SIP_MSG:
            CLIENTAPI_COMM_Send(event);
            break;
        default:
            break;
    }

    return 0;

}

/* handle events from the clientapi adapter */
int handleEventFromAdapter(CLIENTAPI_EventMsg_t *event) {

    DbgMsg("handle clientapi event from adapter: %s", (char *)getClientapiEvent(event->request_id));

    CLIENTAPI_EventMsg_t *resp_event;
    char *clientapi_data = 0;

    switch (event->request_id) {

        case CMD_REQ_REG_INFO:
            // [TBD], send to Rcs Volte stack or Volte stack?
            CLIENTAPI_dispatcher_Send_Req_Reg_Info();
            break;

        case CMD_SEND_SIP_MSG: {
            SipmMsgRsp* sipmsg;
            int request_id = 0;
            int conn_id = 0;
            int sip_message_len;

            sipmsg = (SipmMsgRsp*) event->data;
            request_id = sipmsg->req_id;
            conn_id = sipmsg->con_id;
            sip_message_len = sipmsg->data_len;

#if 0
            DbgMsg("req_id %d ", request_id) ;
            DbgMsg("conn_id %d ", conn_id) ;
            DbgMsg("sip message length %d ", sip_message_len) ;
#endif

            send_sip_message(request_id, conn_id, sipmsg->sip_data, sip_message_len);
            break;
        }
        case CMD_UNPUBLISH_COMPLETED:
            handle_ims_dereg_unpublish_done(event);
            break;
	case CMD_IMS_RECOVER_REGISTER_IND:
		handle_ims_recover_reg();
		break;
        default:
            break;
    }
    return 0;
}
