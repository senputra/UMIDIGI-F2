#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <cutils/properties.h>
#include <cutils/sockets.h>
#include <android/log.h>
#include "vsim_adaptor_ipc.h"

#define LOGD(format, ...)  \
    __android_log_print(ANDROID_LOG_DEBUG, "VsimAdaptor", (format), ##__VA_ARGS__ )

#define LOGW(format, ...)  \
    __android_log_print(ANDROID_LOG_WARN, "VsimAdaptor", (format), ##__VA_ARGS__ )

#define LOGE(format, ...)  \
    __android_log_print(ANDROID_LOG_ERROR, "VsimAdaptor", (format), ##__VA_ARGS__ )

#define LOGI(format, ...)  \
    __android_log_print(ANDROID_LOG_INFO, "VsimAdaptor", (format), ##__VA_ARGS__ )

#define VSIM_ADAPTOR_SOCKET_NAME "vsim-adaptor"

int isEngLoad() {
    int isEngLoad = 0;
    char property_value[PROPERTY_VALUE_MAX] = { 0 };
    property_get("ro.build.type", property_value, "");
    isEngLoad = (strcmp("eng", property_value) == 0);
    return isEngLoad;
}

int toByte(char c){
    if (c >= '0' && c <= '9') return (c - '0');
    if (c >= 'A' && c <= 'F') return (c - 'A' + 10);
    if (c >= 'a' && c <= 'f') return (c - 'a' + 10);

    LOGE("toByte Error: %c",c);
    return 0;
}

int checkByte(unsigned char* hexString){
    unsigned int i = 0;

    for (i = 0; i < strlen((const char*)hexString); i++) {
        if (!((hexString[i] >= '0' && hexString[i] <= '9')
            ||(hexString[i] >= 'A' && hexString[i] <= 'F')
            ||(hexString[i] >= 'a' && hexString[i] <= 'f'))) {

            LOGE("checkByte Error: %c", hexString[i] );
            return -1;
        }
    }

    return 0;
}

int hexStringToByteArray(unsigned char* hexString, unsigned char* dest, unsigned int destLength)
{
    unsigned int length = strlen((char*)hexString);
    unsigned char* buffer = malloc(length / 2);
    assert(buffer != NULL);
    unsigned int i = 0;

    if (isEngLoad() == 1) {
        LOGD("hexStringToByteArray: hexString=%u, destLength=%u", length, destLength);
    }

    if (dest == NULL || destLength < (length / 2)) {
        LOGE("hexStringToByteArray: buffer size is too small");
        return MODEM_STATUS_INVALID_DATA_TYPE;
    }

    for (i = 0; i < length; i += 2)
    {
        buffer[i / 2] = (unsigned char)((toByte(hexString[i]) << 4) | toByte(hexString[i+1]));
        //LOGI("hexStringToByteArray: buffer=%d, index=%d", buffer[i / 2], i/2);
    }

    memcpy(dest, buffer, (length / 2));

    free(buffer);

    return (length/2);
}

const char HEX_DIGITS[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

unsigned char* byteArrayToHexString(unsigned char* array,int length)
{
    unsigned char* buf = calloc(1, length*2 + 1);
    assert(buf != NULL);
    int bufIndex = 0;
    int i = 0;
    for (i = 0 ; i < length; i++)
    {
        unsigned char b = array[i];
        buf[bufIndex++] = HEX_DIGITS[(b >> 4) & 0x0F];
        buf[bufIndex++] = HEX_DIGITS[b & 0x0F];
    }
    buf[bufIndex] = '\0';
    return buf;
}

/* vsim start */

static int32_t blockingWrite(int fd, const void *buffer, size_t len) {
    size_t writeOffset = 0;
    const uint8_t *toWrite;

    toWrite = (const uint8_t *)buffer;

    while (writeOffset < len) {
        ssize_t written;
        do {
            written = write(fd, toWrite + writeOffset,
                                len - writeOffset);
        } while (written < 0 && ((errno == EINTR) || (errno == EAGAIN)));

        if (written > 0) {
            writeOffset += written;
        } else {   // written < 0
            LOGE ("[blockingWrite] written:%zu, errno:%d", written, errno);
            close(fd);
            return -1;
        }
    }

    return 0;
}

static int32_t blockingRead(int fd, void *buffer, size_t len) {
    size_t readOffset = 0;
    uint8_t *toRead;

    toRead = (uint8_t *)buffer;

    while (readOffset < len) {
        ssize_t reader;
        do {
            reader = recv(fd, toRead + readOffset, len - readOffset, 0);
        } while (reader <= 0 && ((errno == EINTR) || (errno == EAGAIN)));

        if (reader > 0) {
            readOffset += reader;
        } else {   // reader <= 0
            LOGE ("[blockingRead] reader:%zu, errno:%d", reader, errno);
            close(fd);
            return -1;
        }
    }

    return 0;
}

/**
 * Dump VsimMessage and VsimData with valid filed.
 */
static void dump_vsim_msg(VsimMessage *msg, VsimData *msg_data, int msg_data_length) {
    if (isEngLoad() == 0) {
        return;
    }

    LOGD("dump_vsim_msg: start, msg_data_length=%d", msg_data_length);

    LOGD("dump_vsim_msg: msg.trasaction_id = %d, msg.message_id = %d, msg.slotId = %d, msg.length = %d",
            msg->transaction_id, msg->message_id, msg->slotId, msg->length);

    if (msg_data->isResponseValid != 0) {
        LOGD("dump_vsim_msg: result = %d", msg_data->response.result);
    }

    if (msg_data->isEventValid != 0) {
        unsigned char* temp =
                byteArrayToHexString((unsigned char*)&msg_data->event, sizeof(msg_data->event));
        if (temp != NULL) {
            unsigned int tempLen = strlen(temp);
            if (tempLen < 6) {
                LOGD("dump_vsim_msg: is_event_valid = %d, event = %s", msg_data->isEventValid,
                        temp);
            } else {
                LOGD("dump_vsim_msg: is_event_valid = %d, event = %c%c***%c%c%c%c",
                        msg_data->isEventValid, temp[0], temp[1], temp[tempLen - 4],
                        temp[tempLen - 3], temp[tempLen - 2], temp[tempLen - 1]);
            }
            free(temp);
        }
    }

    if (msg_data->isCapabilityValid != 0) {
        unsigned char* temp =
                byteArrayToHexString((unsigned char*)&msg_data->capability, sizeof(msg_data->capability));
        LOGD("dump_vsim_msg: is_capablity_valid = %d, capabliity = %s", msg_data->isCapabilityValid, temp);
        free(temp);
    }

    if (msg_data->isUiccCmdValid != 0) {
        unsigned char* temp =
                byteArrayToHexString((unsigned char*)&msg_data->uiccCmd,
                (sizeof(msg_data->uiccCmd.type) + sizeof(msg_data->uiccCmd.data_len)
                + msg_data->uiccCmd.data_len));
        if (temp != NULL) {
            unsigned int tempLen = strlen(temp);
            if (tempLen < 6) {
                LOGD("dump_vsim_msg: is_uicc_cmd_valid = %d, uiccCmd = %s",
                        msg_data->isUiccCmdValid, temp);
            } else {
                LOGD("dump_vsim_msg: is_uicc_cmd_valid = %d, uiccCmd = %c%c***%c%c%c%c",
                        msg_data->isUiccCmdValid, temp[0], temp[1], temp[tempLen - 4],
                        temp[tempLen - 3], temp[tempLen - 2], temp[tempLen - 1]);
            }
            free(temp);
        }
    }

    if (msg_data->isUiccPowerDownValid != 0) {
        unsigned char* temp =
                byteArrayToHexString((unsigned char*)&msg_data->uiccPowerDown,
                sizeof(msg_data->uiccPowerDown));
        LOGD("dump_vsim_msg: isUiccPowerDownValid = %d, uiccPowerDown = %s",
                msg_data->isUiccPowerDownValid, temp);
        free(temp);
    }

    if (msg_data->isServiceStateValid != 0) {
        unsigned char* temp =
                byteArrayToHexString((unsigned char*)&msg_data->serviceState,
                sizeof(msg_data->serviceState));
        if (temp != NULL) {
            unsigned int tempLen = strlen(temp);
            if (tempLen < 6) {
                LOGD("dump_vsim_msg: isServiceStateValid = %d, serviceState = %s",
                        msg_data->isServiceStateValid, temp);
            } else {
                LOGD("dump_vsim_msg: isServiceStateValid = %d, serviceState = %c%c***%c%c%c%c",
                        msg_data->isServiceStateValid, temp[0], temp[1], temp[tempLen - 4],
                        temp[tempLen - 3], temp[tempLen - 2], temp[tempLen - 1]);
            }
            free(temp);
        }
    }

done:
    LOGD("dump_vsim_msg: end");
}

/**
 * Use to read vsim data with indicated message id.
 *
 * NOTE. Please don't use this function directly. It is an internal function.
 */
static int recv_vsim_data(int fd, VsimMessage *msg, VsimData *msg_data, int msg_data_length) {
    int ret = MODEM_STATUS_OK;

    if (isEngLoad() == 1) LOGD("recv_vsim_data: start, msg_data_length=%d", msg_data_length);

    switch (msg->message_id) {
        case MSG_ID_INITIALIZATION_RESPONSE:
        case MSG_ID_FINALIZATION_RESPONSE:
            /* Customized */
            break;
        case MSG_ID_GET_PLATFORM_CAPABILITY_RESPONSE: {
            msg_data->isResponseValid = 1;
            if (blockingRead(fd, &msg_data->response, sizeof(msg_data->response)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            msg_data->isCapabilityValid = 1;
            if (blockingRead(fd, &msg_data->capability, sizeof(PlatformCapability)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            if (isEngLoad() == 1) {
                LOGD("recv_vsim_data, multiSim = %d, supported = %d, allowedSimslots = %d, result = %d",
                        msg_data->capability.multiSim,
                        msg_data->capability.supportedVersion,
                        msg_data->capability.allowedSimSlots,
                        msg_data->response.result);
            }
            break;
        }
        case MSG_ID_EVENT_RESPONSE: {
            msg_data->isResponseValid = 1;
            if (blockingRead(fd, &(msg_data->response), sizeof(msg_data->response)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            if (isEngLoad() == 1) LOGD("recv_vsim_data, result = %d", msg_data->response.result);
            break;
        }
        case MSG_ID_UICC_RESET_REQUEST: {
            /* No user data*/
            break;
        }
        case MSG_ID_UICC_APDU_REQUEST: {
            msg_data->isUiccCmdValid = 1;
            msg_data->uiccCmd.type = UICC_CMD_TYPE_APDU_COMMAND;

            if (blockingRead(fd, &(msg_data->uiccCmd.data_len), sizeof(msg_data->uiccCmd.data_len)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            if (msg_data->uiccCmd.data_len > MAX_UICC_CMD_LEN
                    || (msg->length - sizeof(msg_data->uiccCmd.data_len)) > MAX_UICC_CMD_LEN) {
                ret = MODEM_STATUS_INVALID_DATA_TYPE;
                goto done;
            }

            if (blockingRead(fd, &msg_data->uiccCmd.data, (msg->length - sizeof(msg_data->uiccCmd.data_len))) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            if (isEngLoad() == 1) {
                LOGD("recv_vsim_data, apdu_length = %d", msg_data->uiccCmd.data_len);
            }
            break;
        }
        case MSG_ID_UICC_POWER_DOWN_REQUEST: {
            msg_data->isUiccPowerDownValid = 1;

            if (blockingRead(fd, &(msg_data->uiccPowerDown), sizeof(msg_data->uiccPowerDown)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            break;
        }
        case MSG_ID_GET_SERVICE_STATE_RESPONSE: {
            msg_data->isResponseValid = 1;
            if (blockingRead(fd, &(msg_data->response), sizeof(msg_data->response)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            msg_data->isServiceStateValid = 1;
            if (blockingRead(fd, &(msg_data->serviceState), sizeof(msg_data->serviceState)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            break;
        }
        // VSIM 3.0 [Start]
        case MSG_ID_UICC_AUTHENTICATION_DONE_IND:
        case MSG_ID_UICC_AUTHENTICATION_ABORT_IND: {
            /* No user data*/
            break;
        }
        // VSIM 3.0 [End]
        default:
            LOGD("recv_vsim_data: unsupport message id received.");
            break;
    }

done:
    if (isEngLoad() == 1) LOGD("recv_vsim_data: end, ret = %d", ret);
    return ret;
}

/**
 * Connect to VSIM adaptor socket and return a socket fd which will be used
 * to communicate with server side.
 */
int connect_socket() {
    LOGI("connect_socket start");

    int fd = socket_local_client(VSIM_ADAPTOR_SOCKET_NAME,
                  ANDROID_SOCKET_NAMESPACE_ABSTRACT, SOCK_STREAM);

    if(fd < 0) {
        LOGE("Fail to connect to socket vsim-adaptor. return code: %d", fd);
        return MODEM_STATUS_CONNECTION_FAILED;
    }

    LOGI("connect_socket: fd = %d, end", fd);

    return fd;
}

/**
 * Disconnect from VSIM adaptor socket.
 */
int disconnect_socket(int fd) {
    if(fd < 0) {
        LOGE("[disconnect_socket] Invalid fd: %d", fd);
        return MODEM_STATUS_CONNECTION_FAILED;
    }

    LOGI("disconnect_socket: fd = %d", fd);

    return close(fd);
}

/**
 * Provide a function used to send VsimMessage and VsimData to indicated socket fd.
 *
 * We only send the neccessary data according to the indicated msg.message_id parameter,
 * please set the correct data valid flag when you try to send data.
 *
 * [Valid Flag Setting]
 * MSG_ID_GET_PLATFORM_CAPABILITY_REQUEST: msg_data->isEventValid = 1
 * MSG_ID_EVENT_REQUEST: msg_data->isEventValid = 1
 * MSG_ID_UICC_RESET_RESPONSE: msg_data->isUiccCmdValid = 1 and msg_data->isResponseValid = 1
 * MSG_ID_UICC_APDU_RESPONSE: msg_data->isUiccCmdValid = 1 and msg_data->isResponseValid = 1
 * MSG_ID_UICC_POWER_DOWN_RESPONSE: msg_data->isResponseValid = 1
 * MSG_ID_GET_SERVICE_STATE_REQUEST: N/A
 *
 */
int32_t send_vsim_msg(int fd, VsimMessage *msg, VsimData *msg_data) {
    int ret = MODEM_STATUS_OK;
    //VsimUiccResponse *response = NULL;

    if (isEngLoad() == 1) LOGD("send_vsim_msg: start");

    switch (msg->message_id) {
        case MSG_ID_INITIALIZATION_REQUEST:
        case MSG_ID_FINALIZATION_REQUEST:
            /* Allow to customized */
            break;
        case MSG_ID_GET_PLATFORM_CAPABILITY_REQUEST:
        case MSG_ID_EVENT_REQUEST:
            if (isEngLoad() == 1) LOGD("send_vsim_msg: isEventValid[%d]", msg_data->isEventValid);

            if(msg_data->isEventValid == 0) {
                ret = MODEM_STATUS_INVALID_DATA_TYPE;
                goto done;
            }

            msg->length = sizeof(VsimEvent);
            if (blockingWrite(fd, (const void*)msg, sizeof(VsimMessage)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            if(blockingWrite(fd, (const void*)&msg_data->event, sizeof(msg_data->event)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            break;
        case MSG_ID_UICC_RESET_RESPONSE:
        case MSG_ID_UICC_APDU_RESPONSE:
        case MSG_ID_UICC_TEST_MODE_REQUEST:
            if (isEngLoad() == 1) {
                LOGD("send_vsim_msg: isUiccCmdValid[%d], isResponseValid[%d]",
                        msg_data->isUiccCmdValid, msg_data->isResponseValid);
            }

            if(msg_data->isResponseValid == 0 || msg_data->isUiccCmdValid == 0) {
                ret = MODEM_STATUS_INVALID_DATA_TYPE;
                goto done;
            }

            msg->length = sizeof(msg_data->response.result)
                    + sizeof(msg_data->uiccCmd.data_len) + msg_data->uiccCmd.data_len;

            if (blockingWrite(fd, (const void*)msg, sizeof(VsimMessage)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            if (blockingWrite(fd, (const void*)&(msg_data->response.result),
                    sizeof(msg_data->response.result)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            if (blockingWrite(fd, (const void*)&(msg_data->uiccCmd.data_len),
                sizeof(msg_data->uiccCmd.data_len)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            if (blockingWrite(fd, (const void*)&msg_data->uiccCmd.data, msg_data->uiccCmd.data_len) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            break;
        case MSG_ID_UICC_POWER_DOWN_RESPONSE:
            if (isEngLoad() == 1) LOGD("send_vsim_msg: isResponseValid[%d]", msg_data->isResponseValid);

            if(msg_data->isResponseValid == 0) {
                ret = MODEM_STATUS_INVALID_DATA_TYPE;
                goto done;
            }

            msg->length = sizeof(VsimResponse);
            if (blockingWrite(fd, (const void*)msg, sizeof(VsimMessage)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            if (blockingWrite(fd, (const void*)&msg_data->response, sizeof(msg_data->response)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }

            break;
        case MSG_ID_GET_SERVICE_STATE_REQUEST:
            msg->length = 0;
            if (blockingWrite(fd, (const void*)msg, sizeof(VsimMessage)) < 0) {
                ret = MODEM_STATUS_CONNECTION_FAILED;
                goto done;
            }
            break;
        default:
            ret = MODEM_STATUS_UNSUPPORTED_COMMAND;
            break;
    }

done:
    dump_vsim_msg(msg, msg_data, sizeof(msg_data));

    if (isEngLoad() == 1) LOGD("send_vsim_msg: end, ret = %d", ret);
    return ret;
}


/**
 * Provide a function used to receive VsimMessage and VsimData from indicated socket fd.
 *
 * The received msg_data's data valid flag will be set to 1 means the following data
 * structure is meaningful.
 *
 */
int32_t recv_vsim_msg(int fd, VsimMessage *msg,  VsimData *msg_data, int msg_data_length) {
    int ret = MODEM_STATUS_OK;

    if (isEngLoad() == 1) LOGD("recv_vsim_msg: start");

    if (blockingRead(fd, msg, sizeof(VsimMessage)) < 0) {
        ret = MODEM_STATUS_CONNECTION_FAILED;
        goto done;
    }

    //LOGI("recv_vsim_msg: msg.trasaction_id = %d, msg.message_id = %d, msg.slotId = %d, msg.length = %d",
    //        msg->transaction_id, msg->message_id, msg->slotId, msg->length);

    memset(msg_data, 0, sizeof(VsimData));

    ret = recv_vsim_data(fd, msg, msg_data, msg_data_length);

done:
    dump_vsim_msg(msg, msg_data, sizeof(msg_data));
    if (isEngLoad() == 1) LOGD("recv_vsim_msg: end, ret = %d", ret);
    return ret;
}

#if 0
int32_t send_vsim_test_data() {
    int ret = MODEM_STATUS_OK;
    int fd = -1;

    fd = connect_socket();

    LOGI("send_vsim_test_data: start, fd: %d", fd);

    if (fd < 0) {
        ret = MODEM_STATUS_CONNECTION_FAILED;
        goto done;
    }

    VsimMessage msg;
    VsimData data;
    memset(&data, 0, sizeof(data));
    VsimEvent event;
    VsimResponse response;

    // 1. Test get platfrom capability (remote sim)
    msg.transaction_id = 0;
    msg.message_id = MSG_ID_GET_PLATFORM_CAPABILITY_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = -1;     //un-used
    data.isEventValid = 1;
    data.event.eventId = 0;  //un-used
    data.event.sim_type = SIM_TYPE_REMOTE_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // Test set rsim mapping info
    msg.transaction_id = 1;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = 2;
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_SET_MAPPING_INFO;
    data.event.sim_type = SIM_TYPE_REMOTE_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 1. Test get platfrom capability (local sim)
    msg.transaction_id = 0;
    msg.message_id = MSG_ID_GET_PLATFORM_CAPABILITY_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = -1;     //un-used
    data.isEventValid = 1;
    data.event.eventId = 0;  //un-used
    data.event.sim_type = SIM_TYPE_AKA_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 2. Test enable external SIM (local sim)
    msg.transaction_id = 1;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = 1;
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_ENABLE_EXTERNAL_SIM;
    data.event.sim_type = SIM_TYPE_AKA_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 3. Test enable external SIM (local sim)
    msg.transaction_id = 3;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.slotId = 1;
    msg.length = sizeof(VsimData);
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_PLUG_IN;
    data.event.sim_type = SIM_TYPE_LOCAL_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 2. Test enable external SIM (remote sim)
    msg.transaction_id = 1;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = 2;
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_ENABLE_EXTERNAL_SIM;
    data.event.sim_type = SIM_TYPE_REMOTE_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 3. Test enable external SIM (remote sim)
    msg.transaction_id = 3;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.slotId = 2;
    msg.length = sizeof(VsimData);
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_PLUG_IN;
    data.event.sim_type = SIM_TYPE_REMOTE_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 2. Test plug out external SIM (local sim)
    msg.transaction_id = 1;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = 1;
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_PLUG_OUT;
    data.event.sim_type = SIM_TYPE_LOCAL_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 3. Test disable external SIM (local sim)
    msg.transaction_id = 3;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.slotId = 1;
    msg.length = sizeof(VsimData);
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_DISABLE_EXTERNAL_SIM;
    data.event.sim_type = SIM_TYPE_LOCAL_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 4. Test set persist external SIM (VSIM 2.0 supported)
    msg.transaction_id = 4;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.slotId = 2;
    msg.length = sizeof(VsimData);
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_SET_PERSIST_TYPE;
    data.event.sim_type = PERSIST_TYPE_KEEP_PERSIST_VSIM_ONLY;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // **Receive power down
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

    // 5. Test handle reset request
    // (a) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));
    // (b) send
    msg.transaction_id = 5;
    msg.message_id = MSG_ID_UICC_RESET_RESPONSE;
    msg.slotId = 2;

    #define ATR_EXAMPLE "3B9E96801FC78031E073FE211B66D0007A008000FA"
    data.isResponseValid = 1;
    data.response.result = 0;
    data.isUiccCmdValid = 1;
    data.uiccCmd.type = UICC_CMD_TYPE_ATR;
    data.uiccCmd.data_len = strlen(ATR_EXAMPLE) / 2;
    data.uiccCmd.type = ((msg.message_id == MSG_ID_UICC_RESET_RESPONSE) ? UICC_CMD_TYPE_ATR : UICC_CMD_TYPE_APDU_RESPONSE);
    memset(data.uiccCmd.data, 0, sizeof(data.uiccCmd.data));
    hexStringToByteArray((unsigned char *)ATR_EXAMPLE, data.uiccCmd.data, data.uiccCmd.data_len);

    msg.length = sizeof(VsimData);

    send_vsim_msg(fd, &msg, &data);

    // 6. Test get service state
    msg.transaction_id = 6;
    msg.message_id = MSG_ID_GET_SERVICE_STATE_REQUEST;
    msg.slotId = 1;
    msg.length = sizeof(VsimData);
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));

#if 0
    // 6. Test disable external sim
    msg.transaction_id = 1;
    msg.message_id = MSG_ID_EVENT_REQUEST;
    msg.length = sizeof(VsimData);
    msg.slotId = 1;
    data.isEventValid = 1;
    data.event.eventId = REQUEST_TYPE_DISABLE_EXTERNAL_SIM;
    data.event.sim_type = SIM_TYPE_REMOTE_SIM;
    // (a) send
    send_vsim_msg(fd, &msg, &data);
    // (b) recv
    recv_vsim_msg(fd, &msg, &data, sizeof(data));
#endif

    LOGI("send_vsim_test_data: end");

    while(true) {
        recv_vsim_msg(fd, &msg, &data, sizeof(data));
    }

done:
    return ret;
}
#endif
/* vsim end */


