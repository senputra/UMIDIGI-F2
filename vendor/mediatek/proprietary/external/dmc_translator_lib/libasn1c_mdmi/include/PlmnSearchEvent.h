/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PlmnSearchEvent_H_
#define _PlmnSearchEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PlmnSearch.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PlmnSearchEvent */
typedef PlmnSearch_t     PlmnSearchEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PlmnSearchEvent;
asn_struct_free_f PlmnSearchEvent_free;
asn_struct_print_f PlmnSearchEvent_print;
asn_constr_check_f PlmnSearchEvent_constraint;
ber_type_decoder_f PlmnSearchEvent_decode_ber;
der_type_encoder_f PlmnSearchEvent_encode_der;
xer_type_decoder_f PlmnSearchEvent_decode_xer;
xer_type_encoder_f PlmnSearchEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _PlmnSearchEvent_H_ */
#include <asn_internal.h>
