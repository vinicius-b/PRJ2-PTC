/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_CamelCallReferenceNumber_H_
#define	_CamelCallReferenceNumber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "HexString.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CamelCallReferenceNumber */
typedef HexString_t	 CamelCallReferenceNumber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CamelCallReferenceNumber;
asn_struct_free_f CamelCallReferenceNumber_free;
asn_struct_print_f CamelCallReferenceNumber_print;
asn_constr_check_f CamelCallReferenceNumber_constraint;
ber_type_decoder_f CamelCallReferenceNumber_decode_ber;
der_type_encoder_f CamelCallReferenceNumber_encode_der;
xer_type_decoder_f CamelCallReferenceNumber_decode_xer;
xer_type_encoder_f CamelCallReferenceNumber_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _CamelCallReferenceNumber_H_ */
#include <asn_internal.h>
