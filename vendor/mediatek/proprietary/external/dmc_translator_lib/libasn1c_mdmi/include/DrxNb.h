/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _DrxNb_H_
#define _DrxNb_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DrxNb {
    DrxNb_fourt = 0,
    DrxNb_twot  = 1,
    DrxNb_onet  = 2,
    DrxNb_halft = 3,
    DrxNb_quartert  = 4,
    DrxNb_oneeightt = 5,
    DrxNb_onesixteentht = 6,
    DrxNb_onethirtysecondt  = 7
} e_DrxNb;

/* DrxNb */
typedef long     DrxNb_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DrxNb;
asn_struct_free_f DrxNb_free;
asn_struct_print_f DrxNb_print;
asn_constr_check_f DrxNb_constraint;
ber_type_decoder_f DrxNb_decode_ber;
der_type_encoder_f DrxNb_encode_der;
xer_type_decoder_f DrxNb_decode_xer;
xer_type_encoder_f DrxNb_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _DrxNb_H_ */
#include <asn_internal.h>
