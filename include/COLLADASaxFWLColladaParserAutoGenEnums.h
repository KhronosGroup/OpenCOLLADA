/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGENENUMS_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGENENUMS_H__


#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserUtils.h"


namespace COLLADASaxFWL
{


typedef GeneratedSaxParser::StringHash StringHash;
typedef GeneratedSaxParser::ParserChar ParserChar;
typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
typedef GeneratedSaxParser::Utils Utils;


enum UpAxisType
{
    UpAxisType__X_UP = 0,
    UpAxisType__Y_UP = 1,
    UpAxisType__Z_UP = 2,
    UpAxisType__COUNT = 3,
    UpAxisType__NOT_PRESENT = 4
};

extern const std::pair<StringHash, UpAxisType> UpAxisTypeMap[UpAxisType__COUNT];


UpAxisType toEnum_UpAxisType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_modifier_enum_common
{
    fx_modifier_enum_common__CONST = 0,
    fx_modifier_enum_common__UNIFORM = 1,
    fx_modifier_enum_common__VARYING = 2,
    fx_modifier_enum_common__STATIC = 3,
    fx_modifier_enum_common__VOLATILE = 4,
    fx_modifier_enum_common__EXTERN = 5,
    fx_modifier_enum_common__SHARED = 6,
    fx_modifier_enum_common__COUNT = 7,
    fx_modifier_enum_common__NOT_PRESENT = 8
};

extern const std::pair<StringHash, fx_modifier_enum_common> fx_modifier_enum_commonMap[fx_modifier_enum_common__COUNT];


fx_modifier_enum_common toEnum_fx_modifier_enum_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_type_enum
{
    fx_surface_type_enum__UNTYPED = 0,
    fx_surface_type_enum__1D = 1,
    fx_surface_type_enum__2D = 2,
    fx_surface_type_enum__3D = 3,
    fx_surface_type_enum__RECT = 4,
    fx_surface_type_enum__CUBE = 5,
    fx_surface_type_enum__DEPTH = 6,
    fx_surface_type_enum__COUNT = 7,
    fx_surface_type_enum__NOT_PRESENT = 8
};

extern const std::pair<StringHash, fx_surface_type_enum> fx_surface_type_enumMap[fx_surface_type_enum__COUNT];


fx_surface_type_enum toEnum_fx_surface_type_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_face_enum
{
    fx_surface_face_enum__POSITIVE_X = 0,
    fx_surface_face_enum__NEGATIVE_X = 1,
    fx_surface_face_enum__POSITIVE_Y = 2,
    fx_surface_face_enum__NEGATIVE_Y = 3,
    fx_surface_face_enum__POSITIVE_Z = 4,
    fx_surface_face_enum__NEGATIVE_Z = 5,
    fx_surface_face_enum__COUNT = 6,
    fx_surface_face_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, fx_surface_face_enum> fx_surface_face_enumMap[fx_surface_face_enum__COUNT];


fx_surface_face_enum toEnum_fx_surface_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_format_hint_channels_enum
{
    fx_surface_format_hint_channels_enum__RGB = 0,
    fx_surface_format_hint_channels_enum__RGBA = 1,
    fx_surface_format_hint_channels_enum__L = 2,
    fx_surface_format_hint_channels_enum__LA = 3,
    fx_surface_format_hint_channels_enum__D = 4,
    fx_surface_format_hint_channels_enum__XYZ = 5,
    fx_surface_format_hint_channels_enum__XYZW = 6,
    fx_surface_format_hint_channels_enum__COUNT = 7,
    fx_surface_format_hint_channels_enum__NOT_PRESENT = 8
};

extern const std::pair<StringHash, fx_surface_format_hint_channels_enum> fx_surface_format_hint_channels_enumMap[fx_surface_format_hint_channels_enum__COUNT];


fx_surface_format_hint_channels_enum toEnum_fx_surface_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_format_hint_range_enum
{
    fx_surface_format_hint_range_enum__SNORM = 0,
    fx_surface_format_hint_range_enum__UNORM = 1,
    fx_surface_format_hint_range_enum__SINT = 2,
    fx_surface_format_hint_range_enum__UINT = 3,
    fx_surface_format_hint_range_enum__FLOAT = 4,
    fx_surface_format_hint_range_enum__COUNT = 5,
    fx_surface_format_hint_range_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, fx_surface_format_hint_range_enum> fx_surface_format_hint_range_enumMap[fx_surface_format_hint_range_enum__COUNT];


fx_surface_format_hint_range_enum toEnum_fx_surface_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_format_hint_precision_enum
{
    fx_surface_format_hint_precision_enum__LOW = 0,
    fx_surface_format_hint_precision_enum__MID = 1,
    fx_surface_format_hint_precision_enum__HIGH = 2,
    fx_surface_format_hint_precision_enum__COUNT = 3,
    fx_surface_format_hint_precision_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, fx_surface_format_hint_precision_enum> fx_surface_format_hint_precision_enumMap[fx_surface_format_hint_precision_enum__COUNT];


fx_surface_format_hint_precision_enum toEnum_fx_surface_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_surface_format_hint_option_enum
{
    fx_surface_format_hint_option_enum__SRGB_GAMMA = 0,
    fx_surface_format_hint_option_enum__NORMALIZED3 = 1,
    fx_surface_format_hint_option_enum__NORMALIZED4 = 2,
    fx_surface_format_hint_option_enum__COMPRESSABLE = 3,
    fx_surface_format_hint_option_enum__COUNT = 4,
    fx_surface_format_hint_option_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, fx_surface_format_hint_option_enum> fx_surface_format_hint_option_enumMap[fx_surface_format_hint_option_enum__COUNT];


fx_surface_format_hint_option_enum toEnum_fx_surface_format_hint_option_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texcombiner_operatorRGB_enums
{
    gles_texcombiner_operatorRGB_enums__REPLACE = 0,
    gles_texcombiner_operatorRGB_enums__MODULATE = 1,
    gles_texcombiner_operatorRGB_enums__ADD = 2,
    gles_texcombiner_operatorRGB_enums__ADD_SIGNED = 3,
    gles_texcombiner_operatorRGB_enums__INTERPOLATE = 4,
    gles_texcombiner_operatorRGB_enums__SUBTRACT = 5,
    gles_texcombiner_operatorRGB_enums__DOT3_RGB = 6,
    gles_texcombiner_operatorRGB_enums__DOT3_RGBA = 7,
    gles_texcombiner_operatorRGB_enums__COUNT = 8,
    gles_texcombiner_operatorRGB_enums__NOT_PRESENT = 9
};

extern const std::pair<StringHash, gles_texcombiner_operatorRGB_enums> gles_texcombiner_operatorRGB_enumsMap[gles_texcombiner_operatorRGB_enums__COUNT];


gles_texcombiner_operatorRGB_enums toEnum_gles_texcombiner_operatorRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texcombiner_source_enums
{
    gles_texcombiner_source_enums__TEXTURE = 0,
    gles_texcombiner_source_enums__CONSTANT = 1,
    gles_texcombiner_source_enums__PRIMARY = 2,
    gles_texcombiner_source_enums__PREVIOUS = 3,
    gles_texcombiner_source_enums__COUNT = 4,
    gles_texcombiner_source_enums__NOT_PRESENT = 5
};

extern const std::pair<StringHash, gles_texcombiner_source_enums> gles_texcombiner_source_enumsMap[gles_texcombiner_source_enums__COUNT];


gles_texcombiner_source_enums toEnum_gles_texcombiner_source_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texcombiner_operandRGB_enums
{
    gles_texcombiner_operandRGB_enums__SRC_COLOR = 0,
    gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_COLOR = 1,
    gles_texcombiner_operandRGB_enums__SRC_ALPHA = 2,
    gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_ALPHA = 3,
    gles_texcombiner_operandRGB_enums__COUNT = 4,
    gles_texcombiner_operandRGB_enums__NOT_PRESENT = 5
};

extern const std::pair<StringHash, gles_texcombiner_operandRGB_enums> gles_texcombiner_operandRGB_enumsMap[gles_texcombiner_operandRGB_enums__COUNT];


gles_texcombiner_operandRGB_enums toEnum_gles_texcombiner_operandRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texcombiner_operatorAlpha_enums
{
    gles_texcombiner_operatorAlpha_enums__REPLACE = 0,
    gles_texcombiner_operatorAlpha_enums__MODULATE = 1,
    gles_texcombiner_operatorAlpha_enums__ADD = 2,
    gles_texcombiner_operatorAlpha_enums__ADD_SIGNED = 3,
    gles_texcombiner_operatorAlpha_enums__INTERPOLATE = 4,
    gles_texcombiner_operatorAlpha_enums__SUBTRACT = 5,
    gles_texcombiner_operatorAlpha_enums__COUNT = 6,
    gles_texcombiner_operatorAlpha_enums__NOT_PRESENT = 7
};

extern const std::pair<StringHash, gles_texcombiner_operatorAlpha_enums> gles_texcombiner_operatorAlpha_enumsMap[gles_texcombiner_operatorAlpha_enums__COUNT];


gles_texcombiner_operatorAlpha_enums toEnum_gles_texcombiner_operatorAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texcombiner_operandAlpha_enums
{
    gles_texcombiner_operandAlpha_enums__SRC_ALPHA = 0,
    gles_texcombiner_operandAlpha_enums__ONE_MINUS_SRC_ALPHA = 1,
    gles_texcombiner_operandAlpha_enums__COUNT = 2,
    gles_texcombiner_operandAlpha_enums__NOT_PRESENT = 3
};

extern const std::pair<StringHash, gles_texcombiner_operandAlpha_enums> gles_texcombiner_operandAlpha_enumsMap[gles_texcombiner_operandAlpha_enums__COUNT];


gles_texcombiner_operandAlpha_enums toEnum_gles_texcombiner_operandAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_texenv_mode_enums
{
    gles_texenv_mode_enums__REPLACE = 0,
    gles_texenv_mode_enums__MODULATE = 1,
    gles_texenv_mode_enums__DECAL = 2,
    gles_texenv_mode_enums__BLEND = 3,
    gles_texenv_mode_enums__ADD = 4,
    gles_texenv_mode_enums__COUNT = 5,
    gles_texenv_mode_enums__NOT_PRESENT = 6
};

extern const std::pair<StringHash, gles_texenv_mode_enums> gles_texenv_mode_enumsMap[gles_texenv_mode_enums__COUNT];


gles_texenv_mode_enums toEnum_gles_texenv_mode_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_sampler_wrap
{
    gles_sampler_wrap__REPEAT = 0,
    gles_sampler_wrap__CLAMP = 1,
    gles_sampler_wrap__CLAMP_TO_EDGE = 2,
    gles_sampler_wrap__MIRRORED_REPEAT = 3,
    gles_sampler_wrap__COUNT = 4,
    gles_sampler_wrap__NOT_PRESENT = 5
};

extern const std::pair<StringHash, gles_sampler_wrap> gles_sampler_wrapMap[gles_sampler_wrap__COUNT];


gles_sampler_wrap toEnum_gles_sampler_wrap (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_sampler_filter_common
{
    fx_sampler_filter_common__NONE = 0,
    fx_sampler_filter_common__NEAREST = 1,
    fx_sampler_filter_common__LINEAR = 2,
    fx_sampler_filter_common__NEAREST_MIPMAP_NEAREST = 3,
    fx_sampler_filter_common__LINEAR_MIPMAP_NEAREST = 4,
    fx_sampler_filter_common__NEAREST_MIPMAP_LINEAR = 5,
    fx_sampler_filter_common__LINEAR_MIPMAP_LINEAR = 6,
    fx_sampler_filter_common__COUNT = 7,
    fx_sampler_filter_common__NOT_PRESENT = 8
};

extern const std::pair<StringHash, fx_sampler_filter_common> fx_sampler_filter_commonMap[fx_sampler_filter_common__COUNT];


fx_sampler_filter_common toEnum_fx_sampler_filter_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_func_type
{
    gl_func_type__NEVER = 0,
    gl_func_type__LESS = 1,
    gl_func_type__LEQUAL = 2,
    gl_func_type__EQUAL = 3,
    gl_func_type__GREATER = 4,
    gl_func_type__NOTEQUAL = 5,
    gl_func_type__GEQUAL = 6,
    gl_func_type__ALWAYS = 7,
    gl_func_type__COUNT = 8,
    gl_func_type__NOT_PRESENT = 9
};

extern const std::pair<StringHash, gl_func_type> gl_func_typeMap[gl_func_type__COUNT];


gl_func_type toEnum_gl_func_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_blend_type
{
    gl_blend_type__ZERO = 0,
    gl_blend_type__ONE = 1,
    gl_blend_type__SRC_COLOR = 2,
    gl_blend_type__ONE_MINUS_SRC_COLOR = 3,
    gl_blend_type__DEST_COLOR = 4,
    gl_blend_type__ONE_MINUS_DEST_COLOR = 5,
    gl_blend_type__SRC_ALPHA = 6,
    gl_blend_type__ONE_MINUS_SRC_ALPHA = 7,
    gl_blend_type__DST_ALPHA = 8,
    gl_blend_type__ONE_MINUS_DST_ALPHA = 9,
    gl_blend_type__CONSTANT_COLOR = 10,
    gl_blend_type__ONE_MINUS_CONSTANT_COLOR = 11,
    gl_blend_type__CONSTANT_ALPHA = 12,
    gl_blend_type__ONE_MINUS_CONSTANT_ALPHA = 13,
    gl_blend_type__SRC_ALPHA_SATURATE = 14,
    gl_blend_type__COUNT = 15,
    gl_blend_type__NOT_PRESENT = 16
};

extern const std::pair<StringHash, gl_blend_type> gl_blend_typeMap[gl_blend_type__COUNT];


gl_blend_type toEnum_gl_blend_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_face_type
{
    gl_face_type__FRONT = 0,
    gl_face_type__BACK = 1,
    gl_face_type__FRONT_AND_BACK = 2,
    gl_face_type__COUNT = 3,
    gl_face_type__NOT_PRESENT = 4
};

extern const std::pair<StringHash, gl_face_type> gl_face_typeMap[gl_face_type__COUNT];


gl_face_type toEnum_gl_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_fog_type
{
    gl_fog_type__LINEAR = 0,
    gl_fog_type__EXP = 1,
    gl_fog_type__EXP2 = 2,
    gl_fog_type__COUNT = 3,
    gl_fog_type__NOT_PRESENT = 4
};

extern const std::pair<StringHash, gl_fog_type> gl_fog_typeMap[gl_fog_type__COUNT];


gl_fog_type toEnum_gl_fog_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_front_face_type
{
    gl_front_face_type__CW = 0,
    gl_front_face_type__CCW = 1,
    gl_front_face_type__COUNT = 2,
    gl_front_face_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, gl_front_face_type> gl_front_face_typeMap[gl_front_face_type__COUNT];


gl_front_face_type toEnum_gl_front_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_logic_op_type
{
    gl_logic_op_type__CLEAR = 0,
    gl_logic_op_type__AND = 1,
    gl_logic_op_type__AND_REVERSE = 2,
    gl_logic_op_type__COPY = 3,
    gl_logic_op_type__AND_INVERTED = 4,
    gl_logic_op_type__NOOP = 5,
    gl_logic_op_type__XOR = 6,
    gl_logic_op_type__OR = 7,
    gl_logic_op_type__NOR = 8,
    gl_logic_op_type__EQUIV = 9,
    gl_logic_op_type__INVERT = 10,
    gl_logic_op_type__OR_REVERSE = 11,
    gl_logic_op_type__COPY_INVERTED = 12,
    gl_logic_op_type__NAND = 13,
    gl_logic_op_type__SET = 14,
    gl_logic_op_type__COUNT = 15,
    gl_logic_op_type__NOT_PRESENT = 16
};

extern const std::pair<StringHash, gl_logic_op_type> gl_logic_op_typeMap[gl_logic_op_type__COUNT];


gl_logic_op_type toEnum_gl_logic_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gl_shade_model_type
{
    gl_shade_model_type__FLAT = 0,
    gl_shade_model_type__SMOOTH = 1,
    gl_shade_model_type__COUNT = 2,
    gl_shade_model_type__NOT_PRESENT = 3
};

extern const std::pair<StringHash, gl_shade_model_type> gl_shade_model_typeMap[gl_shade_model_type__COUNT];


gl_shade_model_type toEnum_gl_shade_model_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum gles_stencil_op_type
{
    gles_stencil_op_type__KEEP = 0,
    gles_stencil_op_type__ZERO = 1,
    gles_stencil_op_type__REPLACE = 2,
    gles_stencil_op_type__INCR = 3,
    gles_stencil_op_type__DECR = 4,
    gles_stencil_op_type__INVERT = 5,
    gles_stencil_op_type__COUNT = 6,
    gles_stencil_op_type__NOT_PRESENT = 7
};

extern const std::pair<StringHash, gles_stencil_op_type> gles_stencil_op_typeMap[gles_stencil_op_type__COUNT];


gles_stencil_op_type toEnum_gles_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum VersionType
{
    VersionType__1_4_0 = 0,
    VersionType__1_4_1 = 1,
    VersionType__COUNT = 2,
    VersionType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, VersionType> VersionTypeMap[VersionType__COUNT];


VersionType toEnum_VersionType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum MorphMethodType
{
    MorphMethodType__NORMALIZED = 0,
    MorphMethodType__RELATIVE = 1,
    MorphMethodType__COUNT = 2,
    MorphMethodType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, MorphMethodType> MorphMethodTypeMap[MorphMethodType__COUNT];


MorphMethodType toEnum_MorphMethodType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_sampler_wrap_common
{
    fx_sampler_wrap_common__NONE = 0,
    fx_sampler_wrap_common__WRAP = 1,
    fx_sampler_wrap_common__MIRROR = 2,
    fx_sampler_wrap_common__CLAMP = 3,
    fx_sampler_wrap_common__BORDER = 4,
    fx_sampler_wrap_common__COUNT = 5,
    fx_sampler_wrap_common__NOT_PRESENT = 6
};

extern const std::pair<StringHash, fx_sampler_wrap_common> fx_sampler_wrap_commonMap[fx_sampler_wrap_common__COUNT];


fx_sampler_wrap_common toEnum_fx_sampler_wrap_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum NodeType
{
    NodeType__JOINT = 0,
    NodeType__NODE = 1,
    NodeType__COUNT = 2,
    NodeType__NOT_PRESENT = 3
};

extern const std::pair<StringHash, NodeType> NodeTypeMap[NodeType__COUNT];


NodeType toEnum_NodeType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum fx_opaque_enum
{
    fx_opaque_enum__A_ONE = 0,
    fx_opaque_enum__RGB_ZERO = 1,
    fx_opaque_enum__COUNT = 2,
    fx_opaque_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, fx_opaque_enum> fx_opaque_enumMap[fx_opaque_enum__COUNT];


fx_opaque_enum toEnum_fx_opaque_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);





}
#endif
