/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIIntraInfo_H_
#define _MAPIIntraInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MAPIBandwidth.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MAPIIntraECellInfo;

/* MAPIIntraInfo */
typedef struct MAPIIntraInfo {
    MAPIBandwidth_t *bandwidth  /* OPTIONAL */;
    struct MAPIIntraInfo__intraCell {
        A_SEQUENCE_OF(struct MAPIIntraECellInfo) list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } *intraCell;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPIIntraInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIIntraInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MAPIIntraECellInfo.h"

#endif  /* _MAPIIntraInfo_H_ */
#include <asn_internal.h>
