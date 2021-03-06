/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _DetectedCell_H_
#define _DetectedCell_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "Earfcn.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DetectedCell */
typedef struct DetectedCell {
    long     cellId;
    Earfcn_t     earfcn;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} DetectedCell_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DetectedCell;

#ifdef __cplusplus
}
#endif

#endif  /* _DetectedCell_H_ */
#include <asn_internal.h>
