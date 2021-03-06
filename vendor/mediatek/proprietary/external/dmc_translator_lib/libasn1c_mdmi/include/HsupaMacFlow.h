/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _HsupaMacFlow_H_
#define _HsupaMacFlow_H_


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
struct HsupaMacLogicalChannelInfo;

/* HsupaMacFlow */
typedef struct HsupaMacFlow {
    long     flowId;
    long     powerOffset;
    long     numMaxRetx;
    long     grantType;
    struct logicalChannels {
        A_SEQUENCE_OF(struct HsupaMacLogicalChannelInfo) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } logicalChannels;
    long     nonScheduledGrantValue;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} HsupaMacFlow_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HsupaMacFlow;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "HsupaMacLogicalChannelInfo.h"

#endif  /* _HsupaMacFlow_H_ */
#include <asn_internal.h>
