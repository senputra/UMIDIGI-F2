/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PdschDecodingResult_H_
#define _PdschDecodingResult_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SystemFrameNumber.h"
#include "SubFrameNumber.h"
#include <NativeInteger.h>
#include "ServingCellIndex.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PdschDecodingStream;

/* PdschDecodingResult */
typedef struct PdschDecodingResult {
    SystemFrameNumber_t  sysFrameNumber;
    SubFrameNumber_t     subFrameNumber;
    long     servingCellId;
    ServingCellIndex_t   servingCellIndex;
    long     harqId;
    long     pdschChannelId;
    struct streams {
        A_SEQUENCE_OF(struct PdschDecodingStream) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } streams;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} PdschDecodingResult_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PdschDecodingResult;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PdschDecodingStream.h"

#endif  /* _PdschDecodingResult_H_ */
#include <asn_internal.h>
