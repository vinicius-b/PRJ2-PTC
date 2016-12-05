/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_DualTeleServiceCode_H_
#define	_DualTeleServiceCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HexString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* DualTeleServiceCode */
typedef HexString_t	 DualTeleServiceCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DualTeleServiceCode;
asn_struct_free_f DualTeleServiceCode_free;
asn_struct_print_f DualTeleServiceCode_print;
asn_constr_check_f DualTeleServiceCode_constraint;
ber_type_decoder_f DualTeleServiceCode_decode_ber;
der_type_encoder_f DualTeleServiceCode_encode_der;
xer_type_decoder_f DualTeleServiceCode_decode_xer;
xer_type_encoder_f DualTeleServiceCode_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _DualTeleServiceCode_H_ */
#include <asn_internal.h>
