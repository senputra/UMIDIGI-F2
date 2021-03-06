/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _UlBandwidthValue_H_
#define _UlBandwidthValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Bandwidth.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UlBandwidthValue */
typedef Bandwidth_t  UlBandwidthValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UlBandwidthValue;
asn_struct_free_f UlBandwidthValue_free;
asn_struct_print_f UlBandwidthValue_print;
asn_constr_check_f UlBandwidthValue_constraint;
ber_type_decoder_f UlBandwidthValue_decode_ber;
der_type_encoder_f UlBandwidthValue_encode_der;
xer_type_decoder_f UlBandwidthValue_decode_xer;
xer_type_encoder_f UlBandwidthValue_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _UlBandwidthValue_H_ */
#include <asn_internal.h>
