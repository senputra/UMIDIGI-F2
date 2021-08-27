/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _LogicalChannelMode_H_
#define _LogicalChannelMode_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum LogicalChannelMode {
    LogicalChannelMode_tm   = 0,
    LogicalChannelMode_um   = 1,
    LogicalChannelMode_am   = 2
} e_LogicalChannelMode;

/* LogicalChannelMode */
typedef long     LogicalChannelMode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_LogicalChannelMode;
asn_struct_free_f LogicalChannelMode_free;
asn_struct_print_f LogicalChannelMode_print;
asn_constr_check_f LogicalChannelMode_constraint;
ber_type_decoder_f LogicalChannelMode_decode_ber;
der_type_encoder_f LogicalChannelMode_encode_der;
xer_type_decoder_f LogicalChannelMode_decode_xer;
xer_type_encoder_f LogicalChannelMode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _LogicalChannelMode_H_ */
#include <asn_internal.h>