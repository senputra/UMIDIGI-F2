/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PdcpMessageRecord_H_
#define _PdcpMessageRecord_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Version3gpp.h"
#include "OtaMessageDirection.h"
#include "PdcpMessageType.h"
#include "RadioBearerType.h"
#include "RlcMode.h"
#include "PdcpSnSize.h"
#include <NativeInteger.h>
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PdcpMessageRecord */
typedef struct PdcpMessageRecord {
    Version3gpp_t    pdcp_version;
    OtaMessageDirection_t    direction;
    PdcpMessageType_t    type;
    RadioBearerType_t    radioBearerType;
    RlcMode_t    rlcMode;
    PdcpSnSize_t     pdcpSnSize;
    long     radioBearerConfigId;
    OCTET_STRING_t   pdcpHeader;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PdcpMessageRecord_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PdcpMessageRecord;

#ifdef __cplusplus
}
#endif

#endif  /* _PdcpMessageRecord_H_ */
#include <asn_internal.h>