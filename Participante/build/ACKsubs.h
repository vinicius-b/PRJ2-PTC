/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_ACKsubs_H_
#define	_ACKsubs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include <BOOLEAN.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ACKsubs */
typedef struct ACKsubs {
	OBJECT_IDENTIFIER_t	 subject;
	BOOLEAN_t	 value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ACKsubs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ACKsubs;

#ifdef __cplusplus
}
#endif

#endif	/* _ACKsubs_H_ */
#include <asn_internal.h>
