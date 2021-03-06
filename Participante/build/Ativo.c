/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#include "Ativo.h"

static asn_TYPE_member_t asn_MBR_id_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct id, choice.pub),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Publish,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"pub"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct id, choice.sub),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Subscribe,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"sub"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct id, choice.un),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Unsubscribe,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"un"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct id, choice.noty),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Notify,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"noty"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct id, choice.ack),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ACKsubs,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"ack"
		},
};
static asn_TYPE_tag2member_t asn_MAP_id_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pub */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sub */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* un */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* noty */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* ack */
};
static asn_CHOICE_specifics_t asn_SPC_id_specs_2 = {
	sizeof(struct id),
	offsetof(struct id, _asn_ctx),
	offsetof(struct id, present),
	sizeof(((struct id *)0)->present),
	asn_MAP_id_tag2el_2,
	5,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_id_2 = {
	"id",
	"id",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_id_2,
	5,	/* Elements count */
	&asn_SPC_id_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Ativo_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Ativo, id),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_id_2,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Ativo, cod),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"cod"
		},
};
static ber_tlv_tag_t asn_DEF_Ativo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Ativo_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* cod */
};
static asn_SEQUENCE_specifics_t asn_SPC_Ativo_specs_1 = {
	sizeof(struct Ativo),
	offsetof(struct Ativo, _asn_ctx),
	asn_MAP_Ativo_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Ativo = {
	"Ativo",
	"Ativo",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Ativo_tags_1,
	sizeof(asn_DEF_Ativo_tags_1)
		/sizeof(asn_DEF_Ativo_tags_1[0]), /* 1 */
	asn_DEF_Ativo_tags_1,	/* Same as above */
	sizeof(asn_DEF_Ativo_tags_1)
		/sizeof(asn_DEF_Ativo_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Ativo_1,
	2,	/* Elements count */
	&asn_SPC_Ativo_specs_1	/* Additional specs */
};

