/*
 * Generated by asn1c-0.9.21 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "D:\Module\NA\feature\MAPI\decode\MAPI-MIB_v3.0.asn"
 * 	`asn1c -fnative-types -fskeletons-copy -S`
 */

#ifndef	_MAPIUiccAccessApdu_H_
#define	_MAPIUiccAccessApdu_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MAPIUiccAccessApdu */
typedef struct MAPIUiccAccessApdu {
	OCTET_STRING_t	*cmdApdu	/* OPTIONAL */;
	OCTET_STRING_t	*responseApdu	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MAPIUiccAccessApdu_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPIUiccAccessApdu;

#ifdef __cplusplus
}
#endif

#endif	/* _MAPIUiccAccessApdu_H_ */
#include <asn_internal.h>