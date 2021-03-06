/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaActiveCommonPhysicalChannelsDl_H_
#define _WcdmaActiveCommonPhysicalChannelsDl_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "DlPhysicalChannelName.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* WcdmaActiveCommonPhysicalChannelsDl */
typedef struct WcdmaActiveCommonPhysicalChannelsDl {
    long     numPhysicalChannel;
    DlPhysicalChannelName_t  dlPhysicalChannelName;
    long     sccpchSlotFormat;
    long     scramblingCodeIndex;
    long     diversityMode;
    long     cctrchId;
    long     sccpchOffset;
    long     channelizationCodeIndex;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaActiveCommonPhysicalChannelsDl_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaActiveCommonPhysicalChannelsDl;

#ifdef __cplusplus
}
#endif

#endif  /* _WcdmaActiveCommonPhysicalChannelsDl_H_ */
#include <asn_internal.h>
