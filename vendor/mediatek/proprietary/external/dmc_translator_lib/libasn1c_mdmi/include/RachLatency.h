/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RachLatency_H_
#define _RachLatency_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SystemFrameNumber.h"
#include "SubFrameNumber.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RachLatency */
typedef struct RachLatency {
    SystemFrameNumber_t  sysFrameNumber;
    SubFrameNumber_t     subFrameNumber;
    long     rachLatencyVal;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} RachLatency_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RachLatency;

#ifdef __cplusplus
}
#endif

#endif  /* _RachLatency_H_ */
#include <asn_internal.h>
