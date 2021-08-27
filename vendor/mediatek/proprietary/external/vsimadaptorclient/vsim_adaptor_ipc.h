#ifndef VSIMADAPTOR_IPC_H
#define VSIMADAPTOR_IPC_H 1


/* vsim start */
typedef struct VsimMessage {
    uint32_t transaction_id;
    uint32_t message_id;    // refer to MessageId
    uint32_t slotId;
    uint32_t length;
} __attribute__((packed)) VsimMessage;

typedef struct VsimEvent {
    uint32_t eventId;   // refer to EventTypeId
    uint32_t sim_type;  // refer to SimType, PersistType
} __attribute__((packed)) VsimEvent;

typedef struct VsimResponse {
    int32_t result;     // 0: successful, < 0: error cause
} __attribute__((packed)) VsimResponse;

typedef struct VsimUiccPowerDown {
    int32_t mode;       // no used currently
} __attribute__((packed)) VsimUiccPowerDown;

typedef struct VsimServiceState {
    int32_t voiceRejectCause;
    int32_t dataRejectCause;
} __attribute__((packed)) VsimServiceState;

// "supportedVersion" is bit wise value as below:
#define CAPABILITY_NOT_SUPPORT                  0x0
#define CAPABILITY_SUPPORT_EXTERNAL_SIM         0x1
#define CAPABILITY_SUPPORT_PERSIST_EXTERNAL_SIM 0x2
#define CAPABILITY_SUPPORT_NON_DSDA_REMOTE_SIM  0x4

typedef struct PlatformCapability {
    uint32_t multiSim;          // refer to MultiSim
    uint32_t supportedVersion;
    uint32_t allowedSimSlots;
} __attribute__((packed)) PlatformCapability;

#define MAX_UICC_CMD_LEN (261)

typedef struct VsimUiccCmd {
    uint32_t type;      // refer to UiccCmdType
    uint32_t data_len;
    uint8_t data[MAX_UICC_CMD_LEN];
} VsimUiccCmd;

typedef struct VsimData {
    uint8_t isResponseValid;
    VsimResponse response;
    uint8_t isEventValid;
    VsimEvent event;
    uint8_t isCapabilityValid;
    PlatformCapability capability;
    uint8_t isUiccCmdValid;
    VsimUiccCmd uiccCmd;
    uint8_t isUiccPowerDownValid;
    VsimUiccPowerDown uiccPowerDown;
    uint8_t isServiceStateValid;
    VsimServiceState serviceState;
} __attribute__((packed)) VsimData;

typedef struct VsimUiccResponse {
    int32_t result;     // 0: successful, < 0: error cause
    uint32_t data_length;
    uint8_t* data;
} __attribute__((packed)) VsimUiccResponse;

enum MessageId {
    MSG_ID_INITIALIZATION_REQUEST           = 1,
    MSG_ID_GET_PLATFORM_CAPABILITY_REQUEST  = 2,
    MSG_ID_EVENT_REQUEST                    = 3,
    MSG_ID_UICC_RESET_RESPONSE              = 4,
    MSG_ID_UICC_APDU_RESPONSE               = 5,
    MSG_ID_UICC_POWER_DOWN_RESPONSE         = 6,
    MSG_ID_GET_SERVICE_STATE_REQUEST        = 7,
    MSG_ID_FINALIZATION_REQUEST             = 8,
    // VSIM 3.0 [Start]
    MSG_ID_UICC_AUTHENTICATION_DONE_ACK     = 9,
    // VSIM 3.0 [End]

    MSG_ID_INITIALIZATION_RESPONSE          = 1001,
    MSG_ID_GET_PLATFORM_CAPABILITY_RESPONSE = 1002,
    MSG_ID_EVENT_RESPONSE                   = 1003,
    MSG_ID_UICC_RESET_REQUEST               = 1004,
    MSG_ID_UICC_APDU_REQUEST                = 1005,
    MSG_ID_UICC_POWER_DOWN_REQUEST          = 1006,
    MSG_ID_GET_SERVICE_STATE_RESPONSE       = 1007,
    MSG_ID_FINALIZATION_RESPONSE            = 1008,
    // VSIM 3.0 [Start]
    MSG_ID_UICC_AUTHENTICATION_DONE_IND     = 1009,
    MSG_ID_UICC_AUTHENTICATION_ABORT_IND    = 1010,
    // VSIM 3.0 [End]

    // Unused, Test mode
    MSG_ID_UICC_TEST_MODE_REQUEST           = 5001,
};

enum SimType {
    SIM_TYPE_LOCAL_SIM  = 1,
    SIM_TYPE_REMOTE_SIM = 2,
    SIM_TYPE_AKA_SIM    = 3,
};

// VSIM 2.0 [Start]
enum PersistType {
    // Default value, will disable VSIM after reboot device
    PERSIST_TYPE_DISABLE_AFTER_REBOOT   = 0,
    // Will disable physical SIM if VSIM enabled before device reboot
    PERSIST_TYPE_KEEP_PERSIST_VSIM_ONLY = 1,
    // Will disable physical SIM within a time out duration to wait
    // VSIM connection after device reboot
    PERSIST_TYPE_KEEP_PERSIST_VSIM_WITH_TIMEOUT = 2,
};
// VSIM 2.0 [End]

enum EventTypeId {
    REQUEST_TYPE_ENABLE_EXTERNAL_SIM    = 1,
    REQUEST_TYPE_DISABLE_EXTERNAL_SIM   = 2,
    REQUEST_TYPE_PLUG_OUT               = 3,
    REQUEST_TYPE_PLUG_IN                = 4,
    REQUEST_TYPE_SET_PERSIST_TYPE       = 5,  // VSIM 2.0 refer to PersistType
    REQUEST_TYPE_SET_MAPPING_INFO       = 6,  // VSIM 3.0
    REQUEST_TYPE_RESET_MAPPING_INFO     = 7,  // VSIM 3.0
    REQUEST_TYPE_SET_TIMEOUT_TIMER      = 8,  // VSIM 3.0
    REQUEST_TYPE_DISABLE_SIM_DIALOG     = 9,  // VSIM 3.0
    REQUEST_TYPE_ENABLE_SIM_DIALOG      = 10, // VSIM 3.0
    REQUEST_TYPE_SET_PERSIST_TIMEOUT    = 11, // VSIM 2.0 fill timeout on VsimEvent.simType with second unit
};

enum MultiSim{
    MULTISIM_CONFIG_UNKNOWN = 0,
    MULTISIM_CONFIG_DSDS    = 1,
    MULTISIM_CONFIG_DSDA    = 2,
    MULTISIM_CONFIG_TSTS    = 3,
};

enum ResponseResult {
    RESPONSE_RESULT_OK                  = 0,
    RESPONSE_RESULT_GENERIC_ERROR       = -1,
    RESPONSE_RESULT_PLATFORM_NOT_READY  = -2,
};

enum UiccCmdType {
    UICC_CMD_TYPE_ATR           = 1,
    UICC_CMD_TYPE_APDU_COMMAND  = 2,
    UICC_CMD_TYPE_APDU_RESPONSE = 3,
};

enum ModeomStatus
{
    MODEM_STATUS_OK                     = 0,
    MODEM_STATUS_CONNECTION_FAILED      = -1,
    MODEM_STATUS_UNSUPPORTED_COMMAND    = -2,
    MODEM_STATUS_INVALID_DATA_TYPE      = -3,
};

extern int connect_socket();
extern int disconnect_socket(int fd);
extern int32_t send_vsim_msg(int fd, VsimMessage *msg, VsimData *msg_data);
extern int32_t recv_vsim_msg(int fd, VsimMessage *msg,  VsimData *msg_data, int msg_data_length);
extern int32_t send_vsim_test_data();

#endif /*VSIMADAPTOR_IPC_H*/
