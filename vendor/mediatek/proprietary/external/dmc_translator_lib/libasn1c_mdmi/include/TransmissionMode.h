/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _TransmissionMode_H_
#define _TransmissionMode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TransmissionMode {
    TransmissionMode_tmInvalid  = 0,
    TransmissionMode_tmSingleAntPort0   = 1,
    TransmissionMode_tmTdRank1  = 2,
    TransmissionMode_tmOlSm = 3,
    TransmissionMode_tmClSm = 4,
    TransmissionMode_tmMuMimo   = 5,
    TransmissionMode_tmClRank1Pc    = 6,
    TransmissionMode_tmSingleAntPort5   = 7,
    TransmissionMode_mode8  = 8,
    TransmissionMode_mode9  = 9
} e_TransmissionMode;

/* TransmissionMode */
typedef long     TransmissionMode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TransmissionMode;
asn_struct_free_f TransmissionMode_free;
asn_struct_print_f TransmissionMode_print;
asn_constr_check_f TransmissionMode_constraint;
ber_type_decoder_f TransmissionMode_decode_ber;
der_type_encoder_f TransmissionMode_encode_der;
xer_type_decoder_f TransmissionMode_decode_xer;
xer_type_encoder_f TransmissionMode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _TransmissionMode_H_ */
#include <asn_internal.h>
