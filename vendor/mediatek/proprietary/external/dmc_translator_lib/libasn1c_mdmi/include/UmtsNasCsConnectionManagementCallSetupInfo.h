/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _UmtsNasCsConnectionManagementCallSetupInfo_H_
#define _UmtsNasCsConnectionManagementCallSetupInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "MultiPartyState.h"
#include "HoldState.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UmtsNasCsConnectionManagementCallSetupInfo */
typedef struct UmtsNasCsConnectionManagementCallSetupInfo {
    long     circuitCallId;
    long     streamId;
    long     callControlState;
    MultiPartyState_t    multiPartyState;
    HoldState_t  holdState;
    long     callType;
    long     callDirection;
    OCTET_STRING_t   calledPartyBcdNumber;
    OCTET_STRING_t   callingPartyBcdNumber;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} UmtsNasCsConnectionManagementCallSetupInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UmtsNasCsConnectionManagementCallSetupInfo;

#ifdef __cplusplus
}
#endif

#endif  /* _UmtsNasCsConnectionManagementCallSetupInfo_H_ */
#include <asn_internal.h>