/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_Notify_H_
#define	_Notify_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include <BOOLEAN.h>
#include <PrintableString.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Notify */
typedef struct Notify {
	OBJECT_IDENTIFIER_t	 subject;
	BOOLEAN_t	 value;
	PrintableString_t	 ip;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Notify_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Notify;

#ifdef __cplusplus
}
#endif

#endif	/* _Notify_H_ */
#include <asn_internal.h>
