/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _UmtsUeStaticId_H_
#define _UmtsUeStaticId_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UmtsUeStaticId */
typedef struct UmtsUeStaticId {
    OCTET_STRING_t   imei;
    OCTET_STRING_t   imsi;
    OCTET_STRING_t   imeiSv;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} UmtsUeStaticId_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UmtsUeStaticId;

#ifdef __cplusplus
}
#endif

#endif  /* _UmtsUeStaticId_H_ */
#include <asn_internal.h>
