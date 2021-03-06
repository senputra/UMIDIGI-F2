/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _PlmnSelectionMode_H_
#define _PlmnSelectionMode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PlmnSelectionMode {
    PlmnSelectionMode_automatic = 0,
    PlmnSelectionMode_manual    = 1
} e_PlmnSelectionMode;

/* PlmnSelectionMode */
typedef long     PlmnSelectionMode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PlmnSelectionMode;
asn_struct_free_f PlmnSelectionMode_free;
asn_struct_print_f PlmnSelectionMode_print;
asn_constr_check_f PlmnSelectionMode_constraint;
ber_type_decoder_f PlmnSelectionMode_decode_ber;
der_type_encoder_f PlmnSelectionMode_encode_der;
xer_type_decoder_f PlmnSelectionMode_decode_xer;
xer_type_encoder_f PlmnSelectionMode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _PlmnSelectionMode_H_ */
#include <asn_internal.h>
