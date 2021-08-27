/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _WcdmaActiveCellInfo_H_
#define _WcdmaActiveCellInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "CpichDiversity.h"
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* WcdmaActiveCellInfo */
typedef struct WcdmaActiveCellInfo {
    long     primaryScramblingCodeIndex;
    long     cellTpc;
    CpichDiversity_t     cpichDiversity;
    BOOLEAN_t    secondaryCpich;
    long     secondaryScramblingCodeIndex;
    long     channelizationCodeIndex;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} WcdmaActiveCellInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WcdmaActiveCellInfo;

#ifdef __cplusplus
}
#endif

#endif  /* _WcdmaActiveCellInfo_H_ */
#include <asn_internal.h>