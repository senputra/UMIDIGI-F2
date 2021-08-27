/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPIRrcMessageRecord_H_
#define _MAPIRrcMessageRecord_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MAPIRrcPduType.h"
#include "MAPIRATType.h"
#include "MAPISIBType.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MAPIVersion3gpp;

/* MAPIRrcMessageRecord */
typedef struct MAPIRrcMessageRecord {
    struct MAPIVersion3gpp  *rrcVersion /* OPTIONAL */;
    MAPIRrcPduType_t    *pduType    /* OPTIONAL */;
    MAPIRATType_t   *ratType    /* OPTIONAL */;
    MAPISIBType_t   *sibType    /* OPTIONAL */;
    OCTET_STRING_t  *rrcPayload /* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPIRrcMessageRecord_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIRrcMessageRecord;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MAPIVersion3gpp.h"

#endif  /* _MAPIRrcMessageRecord_H_ */
#include <asn_internal.h>