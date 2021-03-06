/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _SrsTxPowerMeasurement_H_
#define _SrsTxPowerMeasurement_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SrsTxPowerReport;

/* SrsTxPowerMeasurement */
typedef struct SrsTxPowerMeasurement {
    A_SEQUENCE_OF(struct SrsTxPowerReport) list;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} SrsTxPowerMeasurement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SrsTxPowerMeasurement;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SrsTxPowerReport.h"

#endif  /* _SrsTxPowerMeasurement_H_ */
#include <asn_internal.h>
