/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MTK-EM"
 * 	found in "MAPI-MIB v1.9.2.asn"
 * 	`asn1c -fcompound-names`
 */

#ifndef _MAPISmNsapi9Status_H_
#define _MAPISmNsapi9Status_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MAPISmNsapiXStatus.h"

#ifdef __cplusplus
extern "C" {
#endif

/* MAPISmNsapi9Status */
typedef MAPISmNsapiXStatus_t     MAPISmNsapi9Status_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MAPISmNsapi9Status;
asn_struct_free_f MAPISmNsapi9Status_free;
asn_struct_print_f MAPISmNsapi9Status_print;
asn_constr_check_f MAPISmNsapi9Status_constraint;
ber_type_decoder_f MAPISmNsapi9Status_decode_ber;
der_type_encoder_f MAPISmNsapi9Status_encode_der;
xer_type_decoder_f MAPISmNsapi9Status_decode_xer;
xer_type_encoder_f MAPISmNsapi9Status_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _MAPISmNsapi9Status_H_ */
#include <asn_internal.h>
