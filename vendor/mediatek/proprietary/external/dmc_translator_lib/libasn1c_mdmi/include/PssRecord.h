/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PssRecord_H_
#define _PssRecord_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SystemFrameNumber.h"
#include "SubFrameNumber.h"
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PssRecord */
typedef struct PssRecord {
    SystemFrameNumber_t  sysFrameNumber;
    SubFrameNumber_t     subFrameNumber;
    long     peakValue;
    long     peakPosition;
    long     index;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PssRecord_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PssRecord;

#ifdef __cplusplus
}
#endif

#endif  /* _PssRecord_H_ */
#include <asn_internal.h>
