/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _T310Timer_H_
#define _T310Timer_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum T310Timer {
    T310Timer_stopped   = 0,
    T310Timer_running   = 1
} e_T310Timer;

/* T310Timer */
typedef long     T310Timer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_T310Timer;
asn_struct_free_f T310Timer_free;
asn_struct_print_f T310Timer_print;
asn_constr_check_f T310Timer_constraint;
ber_type_decoder_f T310Timer_decode_ber;
der_type_encoder_f T310Timer_encode_der;
xer_type_decoder_f T310Timer_decode_xer;
xer_type_encoder_f T310Timer_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _T310Timer_H_ */
#include <asn_internal.h>
