/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _HsdpaMacHsConfig_H_
#define _HsdpaMacHsConfig_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include "ReorderingQueues.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct HsdpaMacDFlow;

/* HsdpaMacHsConfig */
typedef struct HsdpaMacHsConfig {
    struct mac_d_flows {
        A_SEQUENCE_OF(struct HsdpaMacDFlow) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } mac_d_flows;
    BOOLEAN_t    macHsResetIndicator;
    BOOLEAN_t    mac_ehs_enabled;
    ReorderingQueues_t   reorderingQueues;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} HsdpaMacHsConfig_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HsdpaMacHsConfig;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "HsdpaMacDFlow.h"

#endif  /* _HsdpaMacHsConfig_H_ */
#include <asn_internal.h>
