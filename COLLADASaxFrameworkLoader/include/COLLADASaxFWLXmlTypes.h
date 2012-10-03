/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_XMLTYPES_H__
#define __COLLADASAXFWL_XMLTYPES_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLTypes.h"

#include "GeneratedSaxParser.h"

namespace COLLADASaxFWL
{

	typedef GeneratedSaxParser::sint8 sint8;
	typedef GeneratedSaxParser::sint16 sint16;
	typedef GeneratedSaxParser::sint32 sint32;
	typedef GeneratedSaxParser::sint64 sint64;
	typedef GeneratedSaxParser::uint8 uint8;
	typedef GeneratedSaxParser::uint16 uint16;
	typedef GeneratedSaxParser::uint32 uint32;
	typedef GeneratedSaxParser::uint64 uint64;

	typedef GeneratedSaxParser::StringHash StringHash;
	typedef GeneratedSaxParser::ParserChar ParserChar;
	typedef GeneratedSaxParser::ParserString ParserString;
	typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
	typedef GeneratedSaxParser::Utils Utils;
	typedef GeneratedSaxParser::ParserError ParserError;
	typedef GeneratedSaxParser::StringHashPair StringHashPair;


    enum ENUM__UpAxisType
    {
        ENUM__UpAxisType__X_UP = 0,
        ENUM__UpAxisType__Y_UP = 1,
        ENUM__UpAxisType__Z_UP = 2,
        ENUM__UpAxisType__INVALID = 3,
        ENUM__UpAxisType__NOT_PRESENT = 4
    };
    enum ENUM__NodeType
    {
        ENUM__NodeType__JOINT = 0,
        ENUM__NodeType__NODE = 1,
        ENUM__NodeType__INVALID = 2,
        ENUM__NodeType__NOT_PRESENT = 3
    };
    enum ENUM__sampler_behavior
    {
        ENUM__sampler_behavior__CONSTANT = 0,
        ENUM__sampler_behavior__CYCLE = 1,
        ENUM__sampler_behavior__CYCLE_RELATIVE = 2,
        ENUM__sampler_behavior__GRADIENT = 3,
        ENUM__sampler_behavior__OSCILLATE = 4,
        ENUM__sampler_behavior__UNDEFINED = 5,
        ENUM__sampler_behavior__INVALID = 6,
        ENUM__sampler_behavior__NOT_PRESENT = 7
    };
    enum ENUM__MorphMethodType
    {
        ENUM__MorphMethodType__NORMALIZED = 0,
        ENUM__MorphMethodType__RELATIVE = 1,
        ENUM__MorphMethodType__INVLAID = 2,
        ENUM__MorphMethodType__NOT_PRESENT = 3
    };
    enum ENUM__fx_surface_type
    {
        ENUM__fx_surface_type__UNTYPED = 0,
        ENUM__fx_surface_type__1D = 1,
        ENUM__fx_surface_type__2D = 2,
        ENUM__fx_surface_type__3D = 3,
        ENUM__fx_surface_type__RECT = 4,
        ENUM__fx_surface_type__CUBE = 5,
        ENUM__fx_surface_type__DEPTH = 6,
        ENUM__fx_surface_type__INVALID = 7,
        ENUM__fx_surface_type__NOT_PRESENT = 8
    };
    enum ENUM__fx_surface_face
    {
        ENUM__fx_surface_face__POSITIVE_X = 0,
        ENUM__fx_surface_face__NEGATIVE_X = 1,
        ENUM__fx_surface_face__POSITIVE_Y = 2,
        ENUM__fx_surface_face__NEGATIVE_Y = 3,
        ENUM__fx_surface_face__POSITIVE_Z = 4,
        ENUM__fx_surface_face__NEGATIVE_Z = 5,
        ENUM__fx_surface_face__INVALID = 6,
        ENUM__fx_surface_face__NOT_PRESENT = 7
    };
    enum ENUM__fx_opaque
    {
        ENUM__fx_opaque__A_ONE = 0,
        ENUM__fx_opaque__A_ZERO = 1,
        ENUM__fx_opaque__RGB_ONE = 2,
        ENUM__fx_opaque__RGB_ZERO = 3,
        ENUM__fx_opaque__INVALID = 4,
        ENUM__fx_opaque__NOT_PRESENT = 5
    };


	enum ENUM__fx_sampler_wrap_common
	{
		ENUM__fx_sampler_wrap_common__NONE = 0,
		ENUM__fx_sampler_wrap_common__WRAP = 1,
		ENUM__fx_sampler_wrap_common__MIRROR = 2,
		ENUM__fx_sampler_wrap_common__MIRROR_ONCE = 3,
		ENUM__fx_sampler_wrap_common__CLAMP = 4,
		ENUM__fx_sampler_wrap_common__BORDER = 5,
		ENUM__fx_sampler_wrap_common__COUNT = 6,
		ENUM__fx_sampler_wrap_common__NOT_PRESENT = 7
	};

    struct unit__AttributeData
    {
        float meter;
        const ParserChar* name;
    };
    struct instance_visual_scene__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct node__AttributeData
    {
        static const uint32 ATTRIBUTE_LAYER_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* id;
        const ParserChar* name;
        const ParserChar* sid;
        ENUM__NodeType type;
        GeneratedSaxParser::XSList<ParserString> layer;
    };
    struct translate__AttributeData
    {
        const ParserChar* sid;
    };
    struct rotate__AttributeData
    {
        const ParserChar* sid;
    };
    struct matrix__AttributeData
    {
        const ParserChar* sid;
    };
    struct scale__AttributeData
    {
        const ParserChar* sid;
    };
    struct skew__AttributeData
    {
        const ParserChar* sid;
    };
    struct lookat__AttributeData
    {
        const ParserChar* sid;
    };
    struct instance_geometry__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct instance_material__AttributeData
    {
        static const uint32 ATTRIBUTE_TARGET_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* symbol;
        COLLADABU::URI target;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct bind_vertex_input__AttributeData
    {
        static const uint32 ATTRIBUTE_INPUT_SET_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* semantic;
        const ParserChar* input_semantic;
        uint64 input_set;
    };
    struct instance_node__AttributeData
    {
        static const uint32 ATTRIBUTE_PROXY_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x2;

        uint32 present_attributes;

        COLLADABU::URI proxy;
        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct instance_camera__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct instance_light__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct instance_controller__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct float_array__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* id;
        const ParserChar* name;
        uint64 count;
        sint16 digits;
        sint16 magnitude;
    };
    struct accessor__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_SOURCE_PRESENT = 0x2;

        uint32 present_attributes;

        uint64 count;
        uint64 offset;
        COLLADABU::URI source;
        uint64 stride;
    };
    struct param__AttributeData
    {
        const ParserChar* name;
        const ParserChar* sid;
        const ParserChar* semantic;
        const ParserChar* type;
    };
    struct source__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct vertices__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct input____InputLocal__AttributeData
    {
        const ParserChar* semantic;
        const ParserChar* source;
    };
    struct input____InputLocalOffset__AttributeData
    {
        static const uint32 ATTRIBUTE_OFFSET_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_SET_PRESENT = 0x2;

        uint32 present_attributes;

        uint64 offset;
        const ParserChar* semantic;
        const ParserChar* source;
        uint64 set;
    };
    struct triangles__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct tristrips__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct trifans__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct polygons__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct polylist__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct lines__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct linestrips__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* name;
        uint64 count;
        const ParserChar* material;
    };
    struct animation__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct sampler__AttributeData
    {
        const ParserChar* id;
        ENUM__sampler_behavior pre_behavior;
        ENUM__sampler_behavior post_behavior;
    };
    struct channel__AttributeData
    {
        const ParserChar* source;
        const ParserChar* target;
    };
    struct Name_array__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* id;
        const ParserChar* name;
        uint64 count;
    };
    struct controller__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct skin__AttributeData
    {
        static const uint32 ATTRIBUTE_SOURCE_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI source;
    };
    struct morph__AttributeData
    {
        static const uint32 ATTRIBUTE_SOURCE_PRESENT = 0x1;

        uint32 present_attributes;

        ENUM__MorphMethodType method;
        COLLADABU::URI source;
    };
    struct vertex_weights__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        uint64 count;
    };
    struct IDREF_array__AttributeData
    {
        static const uint32 ATTRIBUTE_COUNT_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* id;
        const ParserChar* name;
        uint64 count;
    };
    struct camera__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct xfov__AttributeData
    {
        const ParserChar* sid;
    };
    struct yfov__AttributeData
    {
        const ParserChar* sid;
    };
    struct xmag__AttributeData
    {
        const ParserChar* sid;
    };
    struct ymag__AttributeData
    {
        const ParserChar* sid;
    };
    struct aspect_ratio__AttributeData
    {
        const ParserChar* sid;
    };
    struct znear__AttributeData
    {
        const ParserChar* sid;
    };
    struct zfar__AttributeData
    {
        const ParserChar* sid;
    };
    struct light__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct color____TargetableFloat3__AttributeData
    {
        const ParserChar* sid;
    };
    struct constant_attenuation__AttributeData
    {
        const ParserChar* sid;
    };
    struct linear_attenuation__AttributeData
    {
        const ParserChar* sid;
    };
    struct quadratic_attenuation__AttributeData
    {
        const ParserChar* sid;
    };
    struct falloff_angle__AttributeData
    {
        const ParserChar* sid;
    };
    struct falloff_exponent__AttributeData
    {
        const ParserChar* sid;
    };
    struct material__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct instance_effect__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };
    struct image__AttributeData
    {
        static const uint32 ATTRIBUTE_HEIGHT_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_WIDTH_PRESENT = 0x2;

        uint32 present_attributes;

        const ParserChar* id;
        const ParserChar* sid;
        const ParserChar* name;
        const ParserChar* format;
        uint64 height;
        uint64 width;
        uint64 depth;
    };
    struct binary__hex__AttributeData
    {
        const ParserChar* format;
    };
    struct effect__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
    };
    struct profile_COMMON__AttributeData
    {
        const ParserChar* id;
    };
    struct newparam____fx_newparam_common__AttributeData
    {
        const ParserChar* sid;
    };
    struct newparam____cg_newparam__AttributeData
    {
        const ParserChar* sid;
    };
    struct newparam____common_newparam_type__AttributeData
    {
        const ParserChar* sid;
    };
    struct surface____fx_surface_common__AttributeData
    {
        ENUM__fx_surface_type type;
    };
    struct init_from____fx_surface_init_from_common__AttributeData
    {
        uint32 mip;
        uint32 slice;
        ENUM__fx_surface_face face;
    };
    struct profile_COMMON__technique__AttributeData
    {
        const ParserChar* id;
        const ParserChar* sid;
    };
    struct transparent__AttributeData
    {
        ENUM__fx_opaque opaque;
    };
    struct common_color_or_texture_type____color__AttributeData
    {
        const ParserChar* sid;
    };
    struct common_float_or_param_type____float__AttributeData
    {
        const ParserChar* sid;
    };
    struct texture__AttributeData
    {
        const ParserChar* texture;
        const ParserChar* texcoord;
    };
    struct instance_image__AttributeData
    {
        static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

        uint32 present_attributes;

        COLLADABU::URI url;
        const ParserChar* sid;
        const ParserChar* name;
    };

    struct spline__AttributeData
    {
        bool closed;
    };
    struct technique__AttributeData
    {
        const ParserChar* profile;
    };



    ////////////////////////////////////////////////////////
    // MathML related
    ////////////////////////////////////////////////////////

    struct formula__AttributeData
    {
        const ParserChar* id;
        const ParserChar* name;
        const ParserChar* sid;
    };
    struct formula_newparam_type__AttributeData
    {
        const ParserChar* sid;
    };


    enum ENUM__mathml__overflow
    {
        ENUM__mathml__overflow__scroll = 0,
        ENUM__mathml__overflow__elide = 1,
        ENUM__mathml__overflow__truncate = 2,
        ENUM__mathml__overflow__scale = 3,
        ENUM__mathml__overflow__INVALID = 4,
        ENUM__mathml__overflow__NOT_PRESENT = 5
    };

    enum ENUM__mathml__display
    {
        ENUM__mathml__display__block = 0,
        ENUM__mathml__display__inline = 1,
        ENUM__mathml__display__INVALID = 2,
        ENUM__mathml__display__NOT_PRESENT = 3
    };

    enum ENUM__mathml__cn__type
    {
        ENUM__mathml__cn__type__e_notation = 0,
        ENUM__mathml__cn__type__integer = 1,
        ENUM__mathml__cn__type__rational = 2,
        ENUM__mathml__cn__type__real = 3,
        ENUM__mathml__cn__type__complex_cartesian = 4,
        ENUM__mathml__cn__type__complex_polar = 5,
        ENUM__mathml__cn__type__constant = 6,
        ENUM__mathml__cn__type__INVALID = 7,
        ENUM__mathml__cn__type__NOT_PRESENT = 8
    };

    enum ENUM__mathml__list__order
    {
        ENUM__mathml__list__order__lexicographic = 0,
        ENUM__mathml__list__order__numeric = 1,
        ENUM__mathml__list__order__INVALID = 2,
        ENUM__mathml__list__order__NOT_PRESENT = 3
    };

    enum ENUM__mathml__interval__closure
    {
        ENUM__mathml__interval__closure__closed = 0,
        ENUM__mathml__interval__closure__open = 1,
        ENUM__mathml__interval__closure__open_closed = 2,
        ENUM__mathml__interval__closure__closed_open = 3,
        ENUM__mathml__interval__closure__INVALID = 4,
        ENUM__mathml__interval__closure__NOT_PRESENT = 5
    };

    enum ENUM__mathml__declare__occurrence
    {
        ENUM__mathml__declare__occurrence__prefix = 0,
        ENUM__mathml__declare__occurrence__infix = 1,
        ENUM__mathml__declare__occurrence__function_model = 2,
        ENUM__mathml__declare__occurrence__INVALID = 3,
        ENUM__mathml__declare__occurrence__NOT_PRESENT = 4
    };

    struct math__AttributeData
    {
        static const uint32 ATTRIBUTE_ALTIMG_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* baseline;
        ENUM__mathml__overflow overflow;
        COLLADABU::URI altimg;
        const ParserChar* alttext;
        const ParserChar* type;
        const ParserChar* name;
        const ParserChar* height;
        const ParserChar* width;
        const ParserChar* macros;
        ENUM__mathml__display display;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct cn__AttributeData
    {
        static const uint32 ATTRIBUTE_BASE_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x2;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x4;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x8;

        uint32 present_attributes;

        uint64 base;
        ENUM__mathml__cn__type type;
        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct ci__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* type;
        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct csymbol__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct abs__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct conjugate__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct factorial__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arg__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct real__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct imaginary__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct floor__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct ceiling__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct quotient__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct divide__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct rem__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct minus__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct plus__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct times__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct power__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct root__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    typedef root__AttributeData max__AttributeData;

    typedef root__AttributeData min__AttributeData;

    struct gcd__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct lcm__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sum__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct product__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct compose__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct domain__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct codomain__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    typedef codomain__AttributeData image____Functions_type__AttributeData;

    struct domainofapplication__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct ident__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct and__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct or__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct xor__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct not__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct exists__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct forall__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct implies__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct naturalnumbers__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct primes__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct integers__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct rationals__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct reals__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct complexes__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct emptyset__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct exponentiale__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct imaginaryi__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct pi__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct eulergamma__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct true__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct false__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct infinity__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct notanumber__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct set__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        const ParserChar* type;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct list__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        ENUM__mathml__list__order order;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct union__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct intersect__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct in__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct notin__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct subset__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct prsubset__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct notsubset__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct notprsubset__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct setdiff__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct card__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct cartesianproduct__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct eq__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct neq__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct leq__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct lt__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct geq__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct gt__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct equivalent__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct approx__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct factorof__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct exp__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct ln__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct log__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct logbase__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sin__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct cos__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct tan__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sec__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct csc__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct cot__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arcsin__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccos__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arctan__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arcsec__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccsc__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccot__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sinh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct cosh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct tanh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sech__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct csch__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct coth__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccosh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccoth__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arccsch__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arcsech__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arcsinh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct arctanh__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct int____int_type____mathml__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct diff__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct partialdiff__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct limit__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct lowlimit__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct uplimit__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct tendsto__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* type;
        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct vector__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct matrix____matrix_type____mathml__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct matrixrow__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct determinant__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct transpose__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct selector__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct vectorproduct__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct scalarproduct__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct outerproduct__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct divergence__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct grad__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct curl__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct laplacian__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct mean__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct sdev__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct variance__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct median__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct mode____mode_type__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct moment__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct momentabout__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct apply__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct interval__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        ENUM__mathml__interval__closure closure;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct inverse__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct condition__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
    };

    struct declare__AttributeData
    {
        static const uint32 ATTRIBUTE_NARGS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x2;

        uint32 present_attributes;

        const ParserChar* type;
        const ParserChar* scope;
        uint64 nargs;
        ENUM__mathml__declare__occurrence occurrence;
        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
    };

    struct lambda__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct piecewise__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct bvar__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct degree__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct semantics__AttributeData
    {
        static const uint32 ATTRIBUTE_DEFINITIONURL_PRESENT = 0x1;
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x2;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x4;

        uint32 present_attributes;

        const ParserChar* encoding;
        COLLADABU::URI definitionURL;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct annotation__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        const ParserChar* encoding;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct annotation_xml__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        const ParserChar* encoding;
        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };

    struct otherwise__AttributeData
    {
        static const uint32 ATTRIBUTE__CLASS_PRESENT = 0x1;
        static const uint32 ATTRIBUTE_HREF_PRESENT = 0x2;

        uint32 present_attributes;

        GeneratedSaxParser::XSList<ParserString> _class;
        const ParserChar* style;
        const ParserChar* xref;
        const ParserChar* id;
        COLLADABU::URI href;

        GeneratedSaxParser::XSList<const ParserChar*> unknownAttributes;
    };


	//*******************************************   kinematics   ********************************************

	struct joint__AttributeData
	{
		static const joint__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
		const ParserChar* sid;
	};

	struct prismatic__AttributeData
	{
		static const prismatic__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	struct axis____axis_type__AttributeData
	{
		static const axis____axis_type__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* name;
	};

	struct min____minmax_type__AttributeData
	{
		static const min____minmax_type__AttributeData DEFAULT;

		const ParserChar* name;
		const ParserChar* sid;
	};

	typedef min____minmax_type__AttributeData max____minmax_type__AttributeData;

	struct revolute__AttributeData
	{
		static const revolute__AttributeData DEFAULT;

		const ParserChar* sid;
	};


	struct kinematics_model__AttributeData
	{
		static const kinematics_model__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	struct newparam____kinematics_newparam_type__AttributeData
	{
		static const newparam____kinematics_newparam_type__AttributeData DEFAULT;

		const ParserChar* sid;
	};

	struct instance_joint__AttributeData
	{
		static const instance_joint__AttributeData DEFAULT;

		static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

		uint32 present_attributes;

		COLLADABU::URI url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	struct link__AttributeData
	{
		static const link__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* name;
	};

	struct attachment_AttributeData
	{
		static const attachment_AttributeData DEFAULT;

		const ParserChar* joint;
	};


	struct articulated_system__AttributeData
	{
		static const articulated_system__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	struct instance_kinematics_model__AttributeData
	{
		static const instance_kinematics_model__AttributeData DEFAULT;

		static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

		uint32 present_attributes;

		COLLADABU::URI url;
		const ParserChar* sid;
		const ParserChar* name;
	};

	struct bind____kinematics_bind_type__AttributeData
	{
		static const bind____kinematics_bind_type__AttributeData DEFAULT;

		const ParserChar* symbol;
	};

	struct param____kinematics_param_type__AttributeData
	{
		static const param____kinematics_param_type__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	struct setparam____kinematics_setparam_type__AttributeData
	{
		static const setparam____kinematics_setparam_type__AttributeData DEFAULT;

		const ParserChar* ref;
	};

	struct axis_info____kinematics_axis_info_type__AttributeData
	{
		static const axis_info____kinematics_axis_info_type__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* name;
		const ParserChar* axis;
	};

	struct index__AttributeData
	{
		static const index__AttributeData DEFAULT;

		const ParserChar* semantic;
	};

	struct frame__AttributeData
	{
		static const frame__AttributeData DEFAULT;

		const ParserChar* link;
	};

	struct instance_articulated_system__AttributeData
	{
		static const instance_articulated_system__AttributeData DEFAULT;

		static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

		uint32 present_attributes;

		const ParserChar* sid;
		COLLADABU::URI url;
		const ParserChar* name;
	};

	struct axis_info____motion_axis_info_type__AttributeData
	{
		static const axis_info____motion_axis_info_type__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* axis;
		const ParserChar* name;
	};

	struct effector_info__AttributeData
	{
		static const effector_info__AttributeData DEFAULT;

		const ParserChar* sid;
		const ParserChar* name;
	};



	struct instance_kinematics_scene__AttributeData
	{
		static const instance_kinematics_scene__AttributeData DEFAULT;

		static const uint32 ATTRIBUTE_URL_PRESENT = 0x1;

		uint32 present_attributes;

		COLLADABU::URI url;
		const ParserChar* sid;
		const ParserChar* name;
	};


	struct bind_joint_axis__AttributeData
	{
		static const bind_joint_axis__AttributeData DEFAULT;

		const ParserChar* target;
	};

	struct kinematics_scene__AttributeData
	{
		static const kinematics_scene__AttributeData DEFAULT;

		const ParserChar* id;
		const ParserChar* name;
	};

	struct bind_kinematics_model__AttributeData
	{
		static const bind_kinematics_model__AttributeData DEFAULT;

		const ParserChar* node;
	};


}

#endif // __COLLADASAXFWL_XMLTYPES_H__
