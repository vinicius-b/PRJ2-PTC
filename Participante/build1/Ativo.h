/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_Ativo_H_
#define	_Ativo_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <NumericString.h>
#include "Tipo1.h"
#include "Tipo2.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum id_PR {
	id_PR_NOTHING,	/* No components present */
	id_PR_t1,
	id_PR_t2
} id_PR;

/* Ativo */
typedef struct Ativo {
	struct id {
		id_PR present;
		union Ativo__id_u {
			Tipo1_t	 t1;
			Tipo2_t	 t2;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} id;
	long	 valor;
	NumericString_t	 data;
	NumericString_t	 horario;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Ativo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ativo;

#ifdef __cplusplus
}
#endif

#endif	/* _Ativo_H_ */
#include <asn_internal.h>
