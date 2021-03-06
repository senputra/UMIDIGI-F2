/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RegistrationType_H_
#define _RegistrationType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RegistrationType {
    RegistrationType_normal = 1,
    RegistrationType_emergency  = 2
} e_RegistrationType;

/* RegistrationType */
typedef long     RegistrationType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RegistrationType;
asn_struct_free_f RegistrationType_free;
asn_struct_print_f RegistrationType_print;
asn_constr_check_f RegistrationType_constraint;
ber_type_decoder_f RegistrationType_decode_ber;
der_type_encoder_f RegistrationType_encode_der;
xer_type_decoder_f RegistrationType_decode_xer;
xer_type_encoder_f RegistrationType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _RegistrationType_H_ */
#include <asn_internal.h>
