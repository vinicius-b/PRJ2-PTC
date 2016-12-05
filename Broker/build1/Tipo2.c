/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#include "Tipo2.h"

static asn_TYPE_member_t asn_MBR_Tipo2_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Tipo2, id),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BoolList,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Tipo2, nome),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PrintableString,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nome"
		},
};
static ber_tlv_tag_t asn_DEF_Tipo2_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Tipo2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nome */
};
static asn_SEQUENCE_specifics_t asn_SPC_Tipo2_specs_1 = {
	sizeof(struct Tipo2),
	offsetof(struct Tipo2, _asn_ctx),
	asn_MAP_Tipo2_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Tipo2 = {
	"Tipo2",
	"Tipo2",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Tipo2_tags_1,
	sizeof(asn_DEF_Tipo2_tags_1)
		/sizeof(asn_DEF_Tipo2_tags_1[0]), /* 1 */
	asn_DEF_Tipo2_tags_1,	/* Same as above */
	sizeof(asn_DEF_Tipo2_tags_1)
		/sizeof(asn_DEF_Tipo2_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Tipo2_1,
	2,	/* Elements count */
	&asn_SPC_Tipo2_specs_1	/* Additional specs */
};

