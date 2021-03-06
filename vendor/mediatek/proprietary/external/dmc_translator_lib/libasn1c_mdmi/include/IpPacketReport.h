/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _IpPacketReport_H_
#define _IpPacketReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include "IpVersion.h"
#include "OtaMessageDirection.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IpPacketReport */
typedef struct IpPacketReport {
    IpVersion_t  ip_version;
    OtaMessageDirection_t    direction;
    OCTET_STRING_t   ipPayload;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} IpPacketReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IpPacketReport;

#ifdef __cplusplus
}
#endif

#endif  /* _IpPacketReport_H_ */
#include <asn_internal.h>
