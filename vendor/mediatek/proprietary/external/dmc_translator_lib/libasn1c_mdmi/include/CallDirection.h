/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _CallDirection_H_
#define _CallDirection_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CallDirection {
    CallDirection_mo    = 0,
    CallDirection_mt    = 1
} e_CallDirection;

/* CallDirection */
typedef long     CallDirection_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CallDirection;
asn_struct_free_f CallDirection_free;
asn_struct_print_f CallDirection_print;
asn_constr_check_f CallDirection_constraint;
ber_type_decoder_f CallDirection_decode_ber;
der_type_encoder_f CallDirection_encode_der;
xer_type_decoder_f CallDirection_decode_xer;
xer_type_encoder_f CallDirection_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _CallDirection_H_ */
#include <asn_internal.h>
