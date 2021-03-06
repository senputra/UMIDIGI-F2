/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MDMI"
 * 	found in "MDMI-MIB v2.8.2.asn"
 */

#ifndef _RrcStateChangeCause_H_
#define _RrcStateChangeCause_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RrcStateChangeCause {
    RrcStateChangeCause_toNull  = 0,
    RrcStateChangeCause_idleFromUpperLayer  = 1,
    RrcStateChangeCause_idleT300Expiry  = 2,
    RrcStateChangeCause_idleConnectionReject    = 3,
    RrcStateChangeCause_idleCellReselectionFailure  = 4,
    RrcStateChangeCause_idleBarred  = 5,
    RrcStateChangeCause_idleOtherRrcFailue  = 6,
    RrcStateChangeCause_idleEnteringLte = 7,
    RrcStateChangeCause_connectingEmergencyCall = 8,
    RrcStateChangeCause_connectingHighPriAccess = 9,
    RrcStateChangeCause_connectingReceiveCall   = 10,
    RrcStateChangeCause_connectingMakingCall    = 11,
    RrcStateChangeCause_connectingMoData    = 12,
    RrcStateChangeCause_embmsFileRepair = 13,
    RrcStateChangeCause_embmsReceptionReport    = 14,
    RrcStateChangeCause_connectingVolteCall = 15,
    RrcStateChangeCause_connectedHoFailure  = 16,
    RrcStateChangeCause_connectedOther  = 17,
    RrcStateChangeCause_releasingT311Expriry    = 18,
    RrcStateChangeCause_releasingT301Expriry    = 19,
    RrcStateChangeCause_releasingReject = 20,
    RrcStateChangeCause_connectingOther = 21
} e_RrcStateChangeCause;

/* RrcStateChangeCause */
typedef long     RrcStateChangeCause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RrcStateChangeCause;
asn_struct_free_f RrcStateChangeCause_free;
asn_struct_print_f RrcStateChangeCause_print;
asn_constr_check_f RrcStateChangeCause_constraint;
ber_type_decoder_f RrcStateChangeCause_decode_ber;
der_type_encoder_f RrcStateChangeCause_encode_der;
xer_type_decoder_f RrcStateChangeCause_decode_xer;
xer_type_encoder_f RrcStateChangeCause_encode_xer;

#ifdef __cplusplus
}
#endif

#endif  /* _RrcStateChangeCause_H_ */
#include <asn_internal.h>
