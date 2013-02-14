/*
    Copyright (c) 2008-2013 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14ENUMS_H__
#define __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14ENUMS_H__


#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserParserError.h"


namespace COLLADASaxFWL14
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


enum ENUM__VersionType
{
    ENUM__VersionType__1_4_0 = 0,
    ENUM__VersionType__1_4_1 = 1,
    ENUM__VersionType__COUNT = 2,
    ENUM__VersionType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__VersionType> ENUM__VersionTypeMap[ENUM__VersionType__COUNT];


ENUM__VersionType toEnum_ENUM__VersionType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__UpAxisType
{
    ENUM__UpAxisType__X_UP = 0,
    ENUM__UpAxisType__Y_UP = 1,
    ENUM__UpAxisType__Z_UP = 2,
    ENUM__UpAxisType__COUNT = 3,
    ENUM__UpAxisType__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__UpAxisType> ENUM__UpAxisTypeMap[ENUM__UpAxisType__COUNT];


ENUM__UpAxisType toEnum_ENUM__UpAxisType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__MorphMethodType
{
    ENUM__MorphMethodType__NORMALIZED = 0,
    ENUM__MorphMethodType__RELATIVE = 1,
    ENUM__MorphMethodType__COUNT = 2,
    ENUM__MorphMethodType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__MorphMethodType> ENUM__MorphMethodTypeMap[ENUM__MorphMethodType__COUNT];


ENUM__MorphMethodType toEnum_ENUM__MorphMethodType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_modifier_enum_common
{
    ENUM__fx_modifier_enum_common__CONST = 0,
    ENUM__fx_modifier_enum_common__UNIFORM = 1,
    ENUM__fx_modifier_enum_common__VARYING = 2,
    ENUM__fx_modifier_enum_common__STATIC = 3,
    ENUM__fx_modifier_enum_common__VOLATILE = 4,
    ENUM__fx_modifier_enum_common__EXTERN = 5,
    ENUM__fx_modifier_enum_common__SHARED = 6,
    ENUM__fx_modifier_enum_common__COUNT = 7,
    ENUM__fx_modifier_enum_common__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__fx_modifier_enum_common> ENUM__fx_modifier_enum_commonMap[ENUM__fx_modifier_enum_common__COUNT];


ENUM__fx_modifier_enum_common toEnum_ENUM__fx_modifier_enum_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_type_enum
{
    ENUM__fx_surface_type_enum__UNTYPED = 0,
    ENUM__fx_surface_type_enum__1D = 1,
    ENUM__fx_surface_type_enum__2D = 2,
    ENUM__fx_surface_type_enum__3D = 3,
    ENUM__fx_surface_type_enum__RECT = 4,
    ENUM__fx_surface_type_enum__CUBE = 5,
    ENUM__fx_surface_type_enum__DEPTH = 6,
    ENUM__fx_surface_type_enum__COUNT = 7,
    ENUM__fx_surface_type_enum__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__fx_surface_type_enum> ENUM__fx_surface_type_enumMap[ENUM__fx_surface_type_enum__COUNT];


ENUM__fx_surface_type_enum toEnum_ENUM__fx_surface_type_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_face_enum
{
    ENUM__fx_surface_face_enum__POSITIVE_X = 0,
    ENUM__fx_surface_face_enum__NEGATIVE_X = 1,
    ENUM__fx_surface_face_enum__POSITIVE_Y = 2,
    ENUM__fx_surface_face_enum__NEGATIVE_Y = 3,
    ENUM__fx_surface_face_enum__POSITIVE_Z = 4,
    ENUM__fx_surface_face_enum__NEGATIVE_Z = 5,
    ENUM__fx_surface_face_enum__COUNT = 6,
    ENUM__fx_surface_face_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__fx_surface_face_enum> ENUM__fx_surface_face_enumMap[ENUM__fx_surface_face_enum__COUNT];


ENUM__fx_surface_face_enum toEnum_ENUM__fx_surface_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_format_hint_channels_enum
{
    ENUM__fx_surface_format_hint_channels_enum__RGB = 0,
    ENUM__fx_surface_format_hint_channels_enum__RGBA = 1,
    ENUM__fx_surface_format_hint_channels_enum__L = 2,
    ENUM__fx_surface_format_hint_channels_enum__LA = 3,
    ENUM__fx_surface_format_hint_channels_enum__D = 4,
    ENUM__fx_surface_format_hint_channels_enum__XYZ = 5,
    ENUM__fx_surface_format_hint_channels_enum__XYZW = 6,
    ENUM__fx_surface_format_hint_channels_enum__COUNT = 7,
    ENUM__fx_surface_format_hint_channels_enum__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum> ENUM__fx_surface_format_hint_channels_enumMap[ENUM__fx_surface_format_hint_channels_enum__COUNT];


ENUM__fx_surface_format_hint_channels_enum toEnum_ENUM__fx_surface_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_format_hint_range_enum
{
    ENUM__fx_surface_format_hint_range_enum__SNORM = 0,
    ENUM__fx_surface_format_hint_range_enum__UNORM = 1,
    ENUM__fx_surface_format_hint_range_enum__SINT = 2,
    ENUM__fx_surface_format_hint_range_enum__UINT = 3,
    ENUM__fx_surface_format_hint_range_enum__FLOAT = 4,
    ENUM__fx_surface_format_hint_range_enum__COUNT = 5,
    ENUM__fx_surface_format_hint_range_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum> ENUM__fx_surface_format_hint_range_enumMap[ENUM__fx_surface_format_hint_range_enum__COUNT];


ENUM__fx_surface_format_hint_range_enum toEnum_ENUM__fx_surface_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_format_hint_precision_enum
{
    ENUM__fx_surface_format_hint_precision_enum__LOW = 0,
    ENUM__fx_surface_format_hint_precision_enum__MID = 1,
    ENUM__fx_surface_format_hint_precision_enum__HIGH = 2,
    ENUM__fx_surface_format_hint_precision_enum__COUNT = 3,
    ENUM__fx_surface_format_hint_precision_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum> ENUM__fx_surface_format_hint_precision_enumMap[ENUM__fx_surface_format_hint_precision_enum__COUNT];


ENUM__fx_surface_format_hint_precision_enum toEnum_ENUM__fx_surface_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_surface_format_hint_option_enum
{
    ENUM__fx_surface_format_hint_option_enum__SRGB_GAMMA = 0,
    ENUM__fx_surface_format_hint_option_enum__NORMALIZED3 = 1,
    ENUM__fx_surface_format_hint_option_enum__NORMALIZED4 = 2,
    ENUM__fx_surface_format_hint_option_enum__COMPRESSABLE = 3,
    ENUM__fx_surface_format_hint_option_enum__COUNT = 4,
    ENUM__fx_surface_format_hint_option_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum> ENUM__fx_surface_format_hint_option_enumMap[ENUM__fx_surface_format_hint_option_enum__COUNT];


ENUM__fx_surface_format_hint_option_enum toEnum_ENUM__fx_surface_format_hint_option_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_wrap_common
{
    ENUM__fx_sampler_wrap_common__NONE = 0,
    ENUM__fx_sampler_wrap_common__WRAP = 1,
    ENUM__fx_sampler_wrap_common__MIRROR = 2,
    ENUM__fx_sampler_wrap_common__CLAMP = 3,
    ENUM__fx_sampler_wrap_common__BORDER = 4,
    ENUM__fx_sampler_wrap_common__COUNT = 5,
    ENUM__fx_sampler_wrap_common__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__fx_sampler_wrap_common> ENUM__fx_sampler_wrap_commonMap[ENUM__fx_sampler_wrap_common__COUNT];


ENUM__fx_sampler_wrap_common toEnum_ENUM__fx_sampler_wrap_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_filter_common
{
    ENUM__fx_sampler_filter_common__NONE = 0,
    ENUM__fx_sampler_filter_common__NEAREST = 1,
    ENUM__fx_sampler_filter_common__LINEAR = 2,
    ENUM__fx_sampler_filter_common__NEAREST_MIPMAP_NEAREST = 3,
    ENUM__fx_sampler_filter_common__LINEAR_MIPMAP_NEAREST = 4,
    ENUM__fx_sampler_filter_common__NEAREST_MIPMAP_LINEAR = 5,
    ENUM__fx_sampler_filter_common__LINEAR_MIPMAP_LINEAR = 6,
    ENUM__fx_sampler_filter_common__COUNT = 7,
    ENUM__fx_sampler_filter_common__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__fx_sampler_filter_common> ENUM__fx_sampler_filter_commonMap[ENUM__fx_sampler_filter_common__COUNT];


ENUM__fx_sampler_filter_common toEnum_ENUM__fx_sampler_filter_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__NodeType
{
    ENUM__NodeType__JOINT = 0,
    ENUM__NodeType__NODE = 1,
    ENUM__NodeType__COUNT = 2,
    ENUM__NodeType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__NodeType> ENUM__NodeTypeMap[ENUM__NodeType__COUNT];


ENUM__NodeType toEnum_ENUM__NodeType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operatorRGB_enums
{
    ENUM__gles_texcombiner_operatorRGB_enums__REPLACE = 0,
    ENUM__gles_texcombiner_operatorRGB_enums__MODULATE = 1,
    ENUM__gles_texcombiner_operatorRGB_enums__ADD = 2,
    ENUM__gles_texcombiner_operatorRGB_enums__ADD_SIGNED = 3,
    ENUM__gles_texcombiner_operatorRGB_enums__INTERPOLATE = 4,
    ENUM__gles_texcombiner_operatorRGB_enums__SUBTRACT = 5,
    ENUM__gles_texcombiner_operatorRGB_enums__DOT3_RGB = 6,
    ENUM__gles_texcombiner_operatorRGB_enums__DOT3_RGBA = 7,
    ENUM__gles_texcombiner_operatorRGB_enums__COUNT = 8,
    ENUM__gles_texcombiner_operatorRGB_enums__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums> ENUM__gles_texcombiner_operatorRGB_enumsMap[ENUM__gles_texcombiner_operatorRGB_enums__COUNT];


ENUM__gles_texcombiner_operatorRGB_enums toEnum_ENUM__gles_texcombiner_operatorRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_source_enums
{
    ENUM__gles_texcombiner_source_enums__TEXTURE = 0,
    ENUM__gles_texcombiner_source_enums__CONSTANT = 1,
    ENUM__gles_texcombiner_source_enums__PRIMARY = 2,
    ENUM__gles_texcombiner_source_enums__PREVIOUS = 3,
    ENUM__gles_texcombiner_source_enums__COUNT = 4,
    ENUM__gles_texcombiner_source_enums__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_source_enums> ENUM__gles_texcombiner_source_enumsMap[ENUM__gles_texcombiner_source_enums__COUNT];


ENUM__gles_texcombiner_source_enums toEnum_ENUM__gles_texcombiner_source_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operandRGB_enums
{
    ENUM__gles_texcombiner_operandRGB_enums__SRC_COLOR = 0,
    ENUM__gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_COLOR = 1,
    ENUM__gles_texcombiner_operandRGB_enums__SRC_ALPHA = 2,
    ENUM__gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_ALPHA = 3,
    ENUM__gles_texcombiner_operandRGB_enums__COUNT = 4,
    ENUM__gles_texcombiner_operandRGB_enums__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums> ENUM__gles_texcombiner_operandRGB_enumsMap[ENUM__gles_texcombiner_operandRGB_enums__COUNT];


ENUM__gles_texcombiner_operandRGB_enums toEnum_ENUM__gles_texcombiner_operandRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operatorAlpha_enums
{
    ENUM__gles_texcombiner_operatorAlpha_enums__REPLACE = 0,
    ENUM__gles_texcombiner_operatorAlpha_enums__MODULATE = 1,
    ENUM__gles_texcombiner_operatorAlpha_enums__ADD = 2,
    ENUM__gles_texcombiner_operatorAlpha_enums__ADD_SIGNED = 3,
    ENUM__gles_texcombiner_operatorAlpha_enums__INTERPOLATE = 4,
    ENUM__gles_texcombiner_operatorAlpha_enums__SUBTRACT = 5,
    ENUM__gles_texcombiner_operatorAlpha_enums__COUNT = 6,
    ENUM__gles_texcombiner_operatorAlpha_enums__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums> ENUM__gles_texcombiner_operatorAlpha_enumsMap[ENUM__gles_texcombiner_operatorAlpha_enums__COUNT];


ENUM__gles_texcombiner_operatorAlpha_enums toEnum_ENUM__gles_texcombiner_operatorAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operandAlpha_enums
{
    ENUM__gles_texcombiner_operandAlpha_enums__SRC_ALPHA = 0,
    ENUM__gles_texcombiner_operandAlpha_enums__ONE_MINUS_SRC_ALPHA = 1,
    ENUM__gles_texcombiner_operandAlpha_enums__COUNT = 2,
    ENUM__gles_texcombiner_operandAlpha_enums__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums> ENUM__gles_texcombiner_operandAlpha_enumsMap[ENUM__gles_texcombiner_operandAlpha_enums__COUNT];


ENUM__gles_texcombiner_operandAlpha_enums toEnum_ENUM__gles_texcombiner_operandAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texenv_mode_enums
{
    ENUM__gles_texenv_mode_enums__REPLACE = 0,
    ENUM__gles_texenv_mode_enums__MODULATE = 1,
    ENUM__gles_texenv_mode_enums__DECAL = 2,
    ENUM__gles_texenv_mode_enums__BLEND = 3,
    ENUM__gles_texenv_mode_enums__ADD = 4,
    ENUM__gles_texenv_mode_enums__COUNT = 5,
    ENUM__gles_texenv_mode_enums__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gles_texenv_mode_enums> ENUM__gles_texenv_mode_enumsMap[ENUM__gles_texenv_mode_enums__COUNT];


ENUM__gles_texenv_mode_enums toEnum_ENUM__gles_texenv_mode_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_sampler_wrap
{
    ENUM__gles_sampler_wrap__REPEAT = 0,
    ENUM__gles_sampler_wrap__CLAMP = 1,
    ENUM__gles_sampler_wrap__CLAMP_TO_EDGE = 2,
    ENUM__gles_sampler_wrap__MIRRORED_REPEAT = 3,
    ENUM__gles_sampler_wrap__COUNT = 4,
    ENUM__gles_sampler_wrap__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_sampler_wrap> ENUM__gles_sampler_wrapMap[ENUM__gles_sampler_wrap__COUNT];


ENUM__gles_sampler_wrap toEnum_ENUM__gles_sampler_wrap (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_blend_type
{
    ENUM__gl_blend_type__ZERO = 0,
    ENUM__gl_blend_type__ONE = 1,
    ENUM__gl_blend_type__SRC_COLOR = 2,
    ENUM__gl_blend_type__ONE_MINUS_SRC_COLOR = 3,
    ENUM__gl_blend_type__DEST_COLOR = 4,
    ENUM__gl_blend_type__ONE_MINUS_DEST_COLOR = 5,
    ENUM__gl_blend_type__SRC_ALPHA = 6,
    ENUM__gl_blend_type__ONE_MINUS_SRC_ALPHA = 7,
    ENUM__gl_blend_type__DST_ALPHA = 8,
    ENUM__gl_blend_type__ONE_MINUS_DST_ALPHA = 9,
    ENUM__gl_blend_type__CONSTANT_COLOR = 10,
    ENUM__gl_blend_type__ONE_MINUS_CONSTANT_COLOR = 11,
    ENUM__gl_blend_type__CONSTANT_ALPHA = 12,
    ENUM__gl_blend_type__ONE_MINUS_CONSTANT_ALPHA = 13,
    ENUM__gl_blend_type__SRC_ALPHA_SATURATE = 14,
    ENUM__gl_blend_type__COUNT = 15,
    ENUM__gl_blend_type__NOT_PRESENT = 16
};

extern const std::pair<StringHash, ENUM__gl_blend_type> ENUM__gl_blend_typeMap[ENUM__gl_blend_type__COUNT];


ENUM__gl_blend_type toEnum_ENUM__gl_blend_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_face_type
{
    ENUM__gl_face_type__FRONT = 0,
    ENUM__gl_face_type__BACK = 1,
    ENUM__gl_face_type__FRONT_AND_BACK = 2,
    ENUM__gl_face_type__COUNT = 3,
    ENUM__gl_face_type__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_face_type> ENUM__gl_face_typeMap[ENUM__gl_face_type__COUNT];


ENUM__gl_face_type toEnum_ENUM__gl_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_func_type
{
    ENUM__gl_func_type__NEVER = 0,
    ENUM__gl_func_type__LESS = 1,
    ENUM__gl_func_type__LEQUAL = 2,
    ENUM__gl_func_type__EQUAL = 3,
    ENUM__gl_func_type__GREATER = 4,
    ENUM__gl_func_type__NOTEQUAL = 5,
    ENUM__gl_func_type__GEQUAL = 6,
    ENUM__gl_func_type__ALWAYS = 7,
    ENUM__gl_func_type__COUNT = 8,
    ENUM__gl_func_type__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gl_func_type> ENUM__gl_func_typeMap[ENUM__gl_func_type__COUNT];


ENUM__gl_func_type toEnum_ENUM__gl_func_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_stencil_op_type
{
    ENUM__gl_stencil_op_type__KEEP = 0,
    ENUM__gl_stencil_op_type__ZERO = 1,
    ENUM__gl_stencil_op_type__REPLACE = 2,
    ENUM__gl_stencil_op_type__INCR = 3,
    ENUM__gl_stencil_op_type__DECR = 4,
    ENUM__gl_stencil_op_type__INVERT = 5,
    ENUM__gl_stencil_op_type__INCR_WRAP = 6,
    ENUM__gl_stencil_op_type__DECR_WRAP = 7,
    ENUM__gl_stencil_op_type__COUNT = 8,
    ENUM__gl_stencil_op_type__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gl_stencil_op_type> ENUM__gl_stencil_op_typeMap[ENUM__gl_stencil_op_type__COUNT];


ENUM__gl_stencil_op_type toEnum_ENUM__gl_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_material_type
{
    ENUM__gl_material_type__EMISSION = 0,
    ENUM__gl_material_type__AMBIENT = 1,
    ENUM__gl_material_type__DIFFUSE = 2,
    ENUM__gl_material_type__SPECULAR = 3,
    ENUM__gl_material_type__AMBIENT_AND_DIFFUSE = 4,
    ENUM__gl_material_type__COUNT = 5,
    ENUM__gl_material_type__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gl_material_type> ENUM__gl_material_typeMap[ENUM__gl_material_type__COUNT];


ENUM__gl_material_type toEnum_ENUM__gl_material_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_fog_type
{
    ENUM__gl_fog_type__LINEAR = 0,
    ENUM__gl_fog_type__EXP = 1,
    ENUM__gl_fog_type__EXP2 = 2,
    ENUM__gl_fog_type__COUNT = 3,
    ENUM__gl_fog_type__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_fog_type> ENUM__gl_fog_typeMap[ENUM__gl_fog_type__COUNT];


ENUM__gl_fog_type toEnum_ENUM__gl_fog_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_front_face_type
{
    ENUM__gl_front_face_type__CW = 0,
    ENUM__gl_front_face_type__CCW = 1,
    ENUM__gl_front_face_type__COUNT = 2,
    ENUM__gl_front_face_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_front_face_type> ENUM__gl_front_face_typeMap[ENUM__gl_front_face_type__COUNT];


ENUM__gl_front_face_type toEnum_ENUM__gl_front_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_light_model_color_control_type
{
    ENUM__gl_light_model_color_control_type__SINGLE_COLOR = 0,
    ENUM__gl_light_model_color_control_type__SEPARATE_SPECULAR_COLOR = 1,
    ENUM__gl_light_model_color_control_type__COUNT = 2,
    ENUM__gl_light_model_color_control_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_light_model_color_control_type> ENUM__gl_light_model_color_control_typeMap[ENUM__gl_light_model_color_control_type__COUNT];


ENUM__gl_light_model_color_control_type toEnum_ENUM__gl_light_model_color_control_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_logic_op_type
{
    ENUM__gl_logic_op_type__CLEAR = 0,
    ENUM__gl_logic_op_type__AND = 1,
    ENUM__gl_logic_op_type__AND_REVERSE = 2,
    ENUM__gl_logic_op_type__COPY = 3,
    ENUM__gl_logic_op_type__AND_INVERTED = 4,
    ENUM__gl_logic_op_type__NOOP = 5,
    ENUM__gl_logic_op_type__XOR = 6,
    ENUM__gl_logic_op_type__OR = 7,
    ENUM__gl_logic_op_type__NOR = 8,
    ENUM__gl_logic_op_type__EQUIV = 9,
    ENUM__gl_logic_op_type__INVERT = 10,
    ENUM__gl_logic_op_type__OR_REVERSE = 11,
    ENUM__gl_logic_op_type__COPY_INVERTED = 12,
    ENUM__gl_logic_op_type__NAND = 13,
    ENUM__gl_logic_op_type__SET = 14,
    ENUM__gl_logic_op_type__COUNT = 15,
    ENUM__gl_logic_op_type__NOT_PRESENT = 16
};

extern const std::pair<StringHash, ENUM__gl_logic_op_type> ENUM__gl_logic_op_typeMap[ENUM__gl_logic_op_type__COUNT];


ENUM__gl_logic_op_type toEnum_ENUM__gl_logic_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_polygon_mode_type
{
    ENUM__gl_polygon_mode_type__POINT = 0,
    ENUM__gl_polygon_mode_type__LINE = 1,
    ENUM__gl_polygon_mode_type__FILL = 2,
    ENUM__gl_polygon_mode_type__COUNT = 3,
    ENUM__gl_polygon_mode_type__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_polygon_mode_type> ENUM__gl_polygon_mode_typeMap[ENUM__gl_polygon_mode_type__COUNT];


ENUM__gl_polygon_mode_type toEnum_ENUM__gl_polygon_mode_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_shade_model_type
{
    ENUM__gl_shade_model_type__FLAT = 0,
    ENUM__gl_shade_model_type__SMOOTH = 1,
    ENUM__gl_shade_model_type__COUNT = 2,
    ENUM__gl_shade_model_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_shade_model_type> ENUM__gl_shade_model_typeMap[ENUM__gl_shade_model_type__COUNT];


ENUM__gl_shade_model_type toEnum_ENUM__gl_shade_model_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



struct UNION__gles_enumeration
{
    UNION__gles_enumeration():union_type(INVALID){}
    UNION__gles_enumeration( int value ):union_type(INVALID){}

    enum Types
    {
        GL_BLEND_TYPE,
        GL_FACE_TYPE,
        GL_FUNC_TYPE,
        GL_STENCIL_OP_TYPE,
        GL_MATERIAL_TYPE,
        GL_FOG_TYPE,
        GL_FRONT_FACE_TYPE,
        GL_LIGHT_MODEL_COLOR_CONTROL_TYPE,
        GL_LOGIC_OP_TYPE,
        GL_POLYGON_MODE_TYPE,
        GL_SHADE_MODEL_TYPE,
        INVALID
    } union_type;

    union Data
    {
        ENUM__gl_blend_type GL_BLEND_TYPE;
        ENUM__gl_face_type GL_FACE_TYPE;
        ENUM__gl_func_type GL_FUNC_TYPE;
        ENUM__gl_stencil_op_type GL_STENCIL_OP_TYPE;
        ENUM__gl_material_type GL_MATERIAL_TYPE;
        ENUM__gl_fog_type GL_FOG_TYPE;
        ENUM__gl_front_face_type GL_FRONT_FACE_TYPE;
        ENUM__gl_light_model_color_control_type GL_LIGHT_MODEL_COLOR_CONTROL_TYPE;
        ENUM__gl_logic_op_type GL_LOGIC_OP_TYPE;
        ENUM__gl_polygon_mode_type GL_POLYGON_MODE_TYPE;
        ENUM__gl_shade_model_type GL_SHADE_MODEL_TYPE;
    } union_data;
};

UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar* buffer, size_t length, bool& failed );



UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed );



UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar** buffer, bool& failed );



enum ENUM__gles_stencil_op_type
{
    ENUM__gles_stencil_op_type__KEEP = 0,
    ENUM__gles_stencil_op_type__ZERO = 1,
    ENUM__gles_stencil_op_type__REPLACE = 2,
    ENUM__gles_stencil_op_type__INCR = 3,
    ENUM__gles_stencil_op_type__DECR = 4,
    ENUM__gles_stencil_op_type__INVERT = 5,
    ENUM__gles_stencil_op_type__COUNT = 6,
    ENUM__gles_stencil_op_type__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__gles_stencil_op_type> ENUM__gles_stencil_op_typeMap[ENUM__gles_stencil_op_type__COUNT];


ENUM__gles_stencil_op_type toEnum_ENUM__gles_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_blend_equation_type
{
    ENUM__gl_blend_equation_type__FUNC_ADD = 0,
    ENUM__gl_blend_equation_type__FUNC_SUBTRACT = 1,
    ENUM__gl_blend_equation_type__FUNC_REVERSE_SUBTRACT = 2,
    ENUM__gl_blend_equation_type__MIN = 3,
    ENUM__gl_blend_equation_type__MAX = 4,
    ENUM__gl_blend_equation_type__COUNT = 5,
    ENUM__gl_blend_equation_type__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gl_blend_equation_type> ENUM__gl_blend_equation_typeMap[ENUM__gl_blend_equation_type__COUNT];


ENUM__gl_blend_equation_type toEnum_ENUM__gl_blend_equation_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_fog_coord_src_type
{
    ENUM__gl_fog_coord_src_type__FOG_COORDINATE = 0,
    ENUM__gl_fog_coord_src_type__FRAGMENT_DEPTH = 1,
    ENUM__gl_fog_coord_src_type__COUNT = 2,
    ENUM__gl_fog_coord_src_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_fog_coord_src_type> ENUM__gl_fog_coord_src_typeMap[ENUM__gl_fog_coord_src_type__COUNT];


ENUM__gl_fog_coord_src_type toEnum_ENUM__gl_fog_coord_src_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



struct UNION__gl_enumeration
{
    UNION__gl_enumeration():union_type(INVALID){}
    UNION__gl_enumeration( int value ):union_type(INVALID){}

    enum Types
    {
        GL_BLEND_TYPE,
        GL_FACE_TYPE,
        GL_BLEND_EQUATION_TYPE,
        GL_FUNC_TYPE,
        GL_STENCIL_OP_TYPE,
        GL_MATERIAL_TYPE,
        GL_FOG_TYPE,
        GL_FOG_COORD_SRC_TYPE,
        GL_FRONT_FACE_TYPE,
        GL_LIGHT_MODEL_COLOR_CONTROL_TYPE,
        GL_LOGIC_OP_TYPE,
        GL_POLYGON_MODE_TYPE,
        GL_SHADE_MODEL_TYPE,
        INVALID
    } union_type;

    union Data
    {
        ENUM__gl_blend_type GL_BLEND_TYPE;
        ENUM__gl_face_type GL_FACE_TYPE;
        ENUM__gl_blend_equation_type GL_BLEND_EQUATION_TYPE;
        ENUM__gl_func_type GL_FUNC_TYPE;
        ENUM__gl_stencil_op_type GL_STENCIL_OP_TYPE;
        ENUM__gl_material_type GL_MATERIAL_TYPE;
        ENUM__gl_fog_type GL_FOG_TYPE;
        ENUM__gl_fog_coord_src_type GL_FOG_COORD_SRC_TYPE;
        ENUM__gl_front_face_type GL_FRONT_FACE_TYPE;
        ENUM__gl_light_model_color_control_type GL_LIGHT_MODEL_COLOR_CONTROL_TYPE;
        ENUM__gl_logic_op_type GL_LOGIC_OP_TYPE;
        ENUM__gl_polygon_mode_type GL_POLYGON_MODE_TYPE;
        ENUM__gl_shade_model_type GL_SHADE_MODEL_TYPE;
    } union_data;
};

UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar* buffer, size_t length, bool& failed );



UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed );



UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar** buffer, bool& failed );



enum ENUM__glsl_pipeline_stage
{
    ENUM__glsl_pipeline_stage__VERTEXPROGRAM = 0,
    ENUM__glsl_pipeline_stage__FRAGMENTPROGRAM = 1,
    ENUM__glsl_pipeline_stage__COUNT = 2,
    ENUM__glsl_pipeline_stage__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__glsl_pipeline_stage> ENUM__glsl_pipeline_stageMap[ENUM__glsl_pipeline_stage__COUNT];


ENUM__glsl_pipeline_stage toEnum_ENUM__glsl_pipeline_stage (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__glsl_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__cg_pipeline_stage
{
    ENUM__cg_pipeline_stage__VERTEX = 0,
    ENUM__cg_pipeline_stage__FRAGMENT = 1,
    ENUM__cg_pipeline_stage__COUNT = 2,
    ENUM__cg_pipeline_stage__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__cg_pipeline_stage> ENUM__cg_pipeline_stageMap[ENUM__cg_pipeline_stage__COUNT];


ENUM__cg_pipeline_stage toEnum_ENUM__cg_pipeline_stage (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__cg_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_opaque_enum
{
    ENUM__fx_opaque_enum__A_ONE = 0,
    ENUM__fx_opaque_enum__RGB_ZERO = 1,
    ENUM__fx_opaque_enum__COUNT = 2,
    ENUM__fx_opaque_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__fx_opaque_enum> ENUM__fx_opaque_enumMap[ENUM__fx_opaque_enum__COUNT];


ENUM__fx_opaque_enum toEnum_ENUM__fx_opaque_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);





} // namespace
#endif
