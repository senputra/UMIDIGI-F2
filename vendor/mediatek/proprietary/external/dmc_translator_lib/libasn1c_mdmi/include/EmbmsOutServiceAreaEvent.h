/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _EmbmsOutServiceAreaEvent_H_
#define _EmbmsOutServiceAreaEvent_H_


#include <asn_application.h>

/* Including external dependencies */
#include "OutServiceAreaEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

/* EmbmsOutServiceAreaEvent */
typedef OutServiceAreaEvent_t    EmbmsOutServiceAreaEvent_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EmbmsOutServiceAreaEvent;
asn_struct_free_f EmbmsOutServiceAreaEvent_free;
asn_struct_print_f EmbmsOutServiceAreaEvent_print;
asn_constr_check_f EmbmsOutServiceAreaEvent_constraint;
ber_type_decoder_f EmbmsOutServiceAreaEvent_decode_ber;
der_type_encoder_f EmbmsOutServiceAreaEvent_encode_der;
xer_type_decoder_f EmbmsOutServiceAreaEvent_decode_xer;
xer_type_encoder_f EmbmsOutServiceAreaEvent_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _EmbmsOutServiceAreaEvent_H_ */
#include <asn_internal.h>