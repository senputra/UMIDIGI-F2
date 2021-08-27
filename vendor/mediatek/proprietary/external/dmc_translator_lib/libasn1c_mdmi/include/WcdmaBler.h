/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaBler_H_
#define _WcdmaBler_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WcdmaTransportChannelInfo;

/* WcdmaBler */
typedef struct WcdmaBler {
    long     windowSize;
    struct wcdmaTransportChannelInfos {
        A_SEQUENCE_OF(struct WcdmaTransportChannelInfo) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } wcdmaTransportChannelInfos;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaBler_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaBler;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WcdmaTransportChannelInfo.h"

#endif  /* _WcdmaBler_H_ */
#include <asn_internal.h>