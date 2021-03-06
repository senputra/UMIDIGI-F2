/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _CallStatus_H_
#define _CallStatus_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CallStatus {
    CallStatus_inactive = 0,
    CallStatus_active   = 1,
    CallStatus_attempting   = 2,
    CallStatus_hold = 3
} e_CallStatus;

/* CallStatus */
typedef long     CallStatus_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CallStatus;
asn_struct_free_f CallStatus_free;
asn_struct_print_f CallStatus_print;
asn_constr_check_f CallStatus_constraint;
ber_type_decoder_f CallStatus_decode_ber;
der_type_encoder_f CallStatus_encode_der;
xer_type_decoder_f CallStatus_decode_xer;
xer_type_encoder_f CallStatus_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _CallStatus_H_ */
#include <asn_internal.h>
