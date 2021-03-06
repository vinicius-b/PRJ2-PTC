/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_CalledCountryCode_H_
#define	_CalledCountryCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AsciiString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CalledCountryCode */
typedef AsciiString_t	 CalledCountryCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CalledCountryCode;
asn_struct_free_f CalledCountryCode_free;
asn_struct_print_f CalledCountryCode_print;
asn_constr_check_f CalledCountryCode_constraint;
ber_type_decoder_f CalledCountryCode_decode_ber;
der_type_encoder_f CalledCountryCode_encode_der;
xer_type_decoder_f CalledCountryCode_decode_xer;
xer_type_encoder_f CalledCountryCode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CalledCountryCode_H_ */
#include <asn_internal.h>
