/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaMacDlLogicalChannels_H_
#define _WcdmaMacDlLogicalChannels_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WcdmaMacDlLogicalChannelInfo;

/* WcdmaMacDlLogicalChannels */
typedef struct WcdmaMacDlLogicalChannels {
    BOOLEAN_t    ciphering;
    long     cipheringKeyId;
    long     hfn;
    struct channels {
        A_SEQUENCE_OF(struct WcdmaMacDlLogicalChannelInfo) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } channels;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaMacDlLogicalChannels_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaMacDlLogicalChannels;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WcdmaMacDlLogicalChannelInfo.h"

#endif  /* _WcdmaMacDlLogicalChannels_H_ */
#include <asn_internal.h>
