/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaMacUlLogicalChannelInfo_H_
#define _WcdmaMacUlLogicalChannelInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "LogicalChannelName.h"
#include "RlcUlState.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* WcdmaMacUlLogicalChannelInfo */
typedef struct WcdmaMacUlLogicalChannelInfo {
    long     channelId;
    LogicalChannelName_t     logicalChannelName;
    RlcUlState_t     rlcState;
    long     radioBearerId;
    long     macId;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaMacUlLogicalChannelInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaMacUlLogicalChannelInfo;

#ifdef __cplusplus
}
#endif

#endif  /* _WcdmaMacUlLogicalChannelInfo_H_ */
#include <asn_internal.h>