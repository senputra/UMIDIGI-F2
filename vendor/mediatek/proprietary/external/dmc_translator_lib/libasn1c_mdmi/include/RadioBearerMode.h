/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RadioBearerMode_H_
#define _RadioBearerMode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RadioBearerMode {
    RadioBearerMode_am  = 0,
    RadioBearerMode_um  = 1
} e_RadioBearerMode;

/* RadioBearerMode */
typedef long     RadioBearerMode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RadioBearerMode;
asn_struct_free_f RadioBearerMode_free;
asn_struct_print_f RadioBearerMode_print;
asn_constr_check_f RadioBearerMode_constraint;
ber_type_decoder_f RadioBearerMode_decode_ber;
der_type_encoder_f RadioBearerMode_encode_der;
xer_type_decoder_f RadioBearerMode_decode_xer;
xer_type_encoder_f RadioBearerMode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _RadioBearerMode_H_ */
#include <asn_internal.h>
