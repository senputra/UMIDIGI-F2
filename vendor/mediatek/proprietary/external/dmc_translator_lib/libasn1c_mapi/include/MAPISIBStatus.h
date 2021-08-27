/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPISIBStatus_H_
#define _MAPISIBStatus_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPISIBStatus */
typedef struct MAPISIBStatus {
    unsigned long   *sibScheduled   /* OPTIONAL */;
    unsigned long   *rcvdSibType    /* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} MAPISIBStatus_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_sibScheduled_2; // (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_rcvdSibType_3;  // (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_MAPISIBStatus;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPISIBStatus_H_ */
#include <asn_internal.h>