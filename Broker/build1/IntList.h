/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_IntList_H_
#define	_IntList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IntList */
typedef struct IntList {
	A_SEQUENCE_OF(long) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IntList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IntList;

#ifdef __cplusplus
}
#endif

#endif	/* _IntList_H_ */
#include <asn_internal.h>
