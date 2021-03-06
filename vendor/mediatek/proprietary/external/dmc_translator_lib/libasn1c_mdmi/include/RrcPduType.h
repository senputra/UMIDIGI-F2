/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RrcPduType_H_
#define _RrcPduType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RrcPduType {
    RrcPduType_pcch = 1,
    RrcPduType_dlCcch   = 2,
    RrcPduType_dlDcch   = 3,
    RrcPduType_ulCcch   = 4,
    RrcPduType_ulDcch   = 5,
    RrcPduType_mcch = 6,
    RrcPduType_bcchDlSch    = 7
} e_RrcPduType;

/* RrcPduType */
typedef long     RrcPduType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RrcPduType;
asn_struct_free_f RrcPduType_free;
asn_struct_print_f RrcPduType_print;
asn_constr_check_f RrcPduType_constraint;
ber_type_decoder_f RrcPduType_decode_ber;
der_type_encoder_f RrcPduType_encode_der;
xer_type_decoder_f RrcPduType_decode_xer;
xer_type_encoder_f RrcPduType_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _RrcPduType_H_ */
#include <asn_internal.h>
