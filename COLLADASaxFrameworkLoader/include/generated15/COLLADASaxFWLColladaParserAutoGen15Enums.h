/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15ENUMS_H__
#define __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15ENUMS_H__


#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserUtils.h"
#include "GeneratedSaxParserParserError.h"


namespace COLLADASaxFWL15
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


enum ENUM__version_enum
{
    ENUM__version_enum__1_5_0 = 0,
    ENUM__version_enum__COUNT = 1,
    ENUM__version_enum__NOT_PRESENT = 2
};

extern const std::pair<StringHash, ENUM__version_enum> ENUM__version_enumMap[ENUM__version_enum__COUNT];


ENUM__version_enum toEnum_ENUM__version_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__version_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__altitude_mode_enum
{
    ENUM__altitude_mode_enum__absolute = 0,
    ENUM__altitude_mode_enum__relativeToGround = 1,
    ENUM__altitude_mode_enum__COUNT = 2,
    ENUM__altitude_mode_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__altitude_mode_enum> ENUM__altitude_mode_enumMap[ENUM__altitude_mode_enum__COUNT];


ENUM__altitude_mode_enum toEnum_ENUM__altitude_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__altitude_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__up_axis_enum
{
    ENUM__up_axis_enum__X_UP = 0,
    ENUM__up_axis_enum__Y_UP = 1,
    ENUM__up_axis_enum__Z_UP = 2,
    ENUM__up_axis_enum__COUNT = 3,
    ENUM__up_axis_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__up_axis_enum> ENUM__up_axis_enumMap[ENUM__up_axis_enum__COUNT];


ENUM__up_axis_enum toEnum_ENUM__up_axis_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__up_axis_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__sampler_behavior_enum
{
    ENUM__sampler_behavior_enum__CONSTANT = 0,
    ENUM__sampler_behavior_enum__CYCLE = 1,
    ENUM__sampler_behavior_enum__CYCLE_RELATIVE = 2,
    ENUM__sampler_behavior_enum__GRADIENT = 3,
    ENUM__sampler_behavior_enum__OSCILLATE = 4,
    ENUM__sampler_behavior_enum__UNDEFINED = 5,
    ENUM__sampler_behavior_enum__COUNT = 6,
    ENUM__sampler_behavior_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__sampler_behavior_enum> ENUM__sampler_behavior_enumMap[ENUM__sampler_behavior_enum__COUNT];


ENUM__sampler_behavior_enum toEnum_ENUM__sampler_behavior_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__sampler_behavior_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__morph_method_enum
{
    ENUM__morph_method_enum__NORMALIZED = 0,
    ENUM__morph_method_enum__RELATIVE = 1,
    ENUM__morph_method_enum__COUNT = 2,
    ENUM__morph_method_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__morph_method_enum> ENUM__morph_method_enumMap[ENUM__morph_method_enum__COUNT];


ENUM__morph_method_enum toEnum_ENUM__morph_method_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__morph_method_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_modifier_enum
{
    ENUM__fx_modifier_enum__CONST = 0,
    ENUM__fx_modifier_enum__UNIFORM = 1,
    ENUM__fx_modifier_enum__VARYING = 2,
    ENUM__fx_modifier_enum__STATIC = 3,
    ENUM__fx_modifier_enum__VOLATILE = 4,
    ENUM__fx_modifier_enum__EXTERN = 5,
    ENUM__fx_modifier_enum__SHARED = 6,
    ENUM__fx_modifier_enum__COUNT = 7,
    ENUM__fx_modifier_enum__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__fx_modifier_enum> ENUM__fx_modifier_enumMap[ENUM__fx_modifier_enum__COUNT];


ENUM__fx_modifier_enum toEnum_ENUM__fx_modifier_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_wrap_enum
{
    ENUM__fx_sampler_wrap_enum__WRAP = 0,
    ENUM__fx_sampler_wrap_enum__CLAMP = 1,
    ENUM__fx_sampler_wrap_enum__BORDER = 2,
    ENUM__fx_sampler_wrap_enum__MIRROR = 3,
    ENUM__fx_sampler_wrap_enum__MIRROR_ONCE = 4,
    ENUM__fx_sampler_wrap_enum__COUNT = 5,
    ENUM__fx_sampler_wrap_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__fx_sampler_wrap_enum> ENUM__fx_sampler_wrap_enumMap[ENUM__fx_sampler_wrap_enum__COUNT];


ENUM__fx_sampler_wrap_enum toEnum_ENUM__fx_sampler_wrap_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_min_filter_enum
{
    ENUM__fx_sampler_min_filter_enum__NEAREST = 0,
    ENUM__fx_sampler_min_filter_enum__LINEAR = 1,
    ENUM__fx_sampler_min_filter_enum__ANISOTROPIC = 2,
    ENUM__fx_sampler_min_filter_enum__COUNT = 3,
    ENUM__fx_sampler_min_filter_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum> ENUM__fx_sampler_min_filter_enumMap[ENUM__fx_sampler_min_filter_enum__COUNT];


ENUM__fx_sampler_min_filter_enum toEnum_ENUM__fx_sampler_min_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_mag_filter_enum
{
    ENUM__fx_sampler_mag_filter_enum__NEAREST = 0,
    ENUM__fx_sampler_mag_filter_enum__LINEAR = 1,
    ENUM__fx_sampler_mag_filter_enum__COUNT = 2,
    ENUM__fx_sampler_mag_filter_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum> ENUM__fx_sampler_mag_filter_enumMap[ENUM__fx_sampler_mag_filter_enum__COUNT];


ENUM__fx_sampler_mag_filter_enum toEnum_ENUM__fx_sampler_mag_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_sampler_mip_filter_enum
{
    ENUM__fx_sampler_mip_filter_enum__NONE = 0,
    ENUM__fx_sampler_mip_filter_enum__NEAREST = 1,
    ENUM__fx_sampler_mip_filter_enum__LINEAR = 2,
    ENUM__fx_sampler_mip_filter_enum__COUNT = 3,
    ENUM__fx_sampler_mip_filter_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum> ENUM__fx_sampler_mip_filter_enumMap[ENUM__fx_sampler_mip_filter_enum__COUNT];


ENUM__fx_sampler_mip_filter_enum toEnum_ENUM__fx_sampler_mip_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__fx_opaque_enum
{
    ENUM__fx_opaque_enum__A_ONE = 0,
    ENUM__fx_opaque_enum__A_ZERO = 1,
    ENUM__fx_opaque_enum__RGB_ONE = 2,
    ENUM__fx_opaque_enum__RGB_ZERO = 3,
    ENUM__fx_opaque_enum__COUNT = 4,
    ENUM__fx_opaque_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__fx_opaque_enum> ENUM__fx_opaque_enumMap[ENUM__fx_opaque_enum__COUNT];


ENUM__fx_opaque_enum toEnum_ENUM__fx_opaque_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_blend_enum
{
    ENUM__gl_blend_enum__ZERO = 0,
    ENUM__gl_blend_enum__ONE = 1,
    ENUM__gl_blend_enum__SRC_COLOR = 2,
    ENUM__gl_blend_enum__ONE_MINUS_SRC_COLOR = 3,
    ENUM__gl_blend_enum__DEST_COLOR = 4,
    ENUM__gl_blend_enum__ONE_MINUS_DEST_COLOR = 5,
    ENUM__gl_blend_enum__SRC_ALPHA = 6,
    ENUM__gl_blend_enum__ONE_MINUS_SRC_ALPHA = 7,
    ENUM__gl_blend_enum__DST_ALPHA = 8,
    ENUM__gl_blend_enum__ONE_MINUS_DST_ALPHA = 9,
    ENUM__gl_blend_enum__CONSTANT_COLOR = 10,
    ENUM__gl_blend_enum__ONE_MINUS_CONSTANT_COLOR = 11,
    ENUM__gl_blend_enum__CONSTANT_ALPHA = 12,
    ENUM__gl_blend_enum__ONE_MINUS_CONSTANT_ALPHA = 13,
    ENUM__gl_blend_enum__SRC_ALPHA_SATURATE = 14,
    ENUM__gl_blend_enum__COUNT = 15,
    ENUM__gl_blend_enum__NOT_PRESENT = 16
};

extern const std::pair<StringHash, ENUM__gl_blend_enum> ENUM__gl_blend_enumMap[ENUM__gl_blend_enum__COUNT];


ENUM__gl_blend_enum toEnum_ENUM__gl_blend_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_face_enum
{
    ENUM__gl_face_enum__FRONT = 0,
    ENUM__gl_face_enum__BACK = 1,
    ENUM__gl_face_enum__FRONT_AND_BACK = 2,
    ENUM__gl_face_enum__COUNT = 3,
    ENUM__gl_face_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_face_enum> ENUM__gl_face_enumMap[ENUM__gl_face_enum__COUNT];


ENUM__gl_face_enum toEnum_ENUM__gl_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_blend_equation_enum
{
    ENUM__gl_blend_equation_enum__FUNC_ADD = 0,
    ENUM__gl_blend_equation_enum__FUNC_SUBTRACT = 1,
    ENUM__gl_blend_equation_enum__FUNC_REVERSE_SUBTRACT = 2,
    ENUM__gl_blend_equation_enum__MIN = 3,
    ENUM__gl_blend_equation_enum__MAX = 4,
    ENUM__gl_blend_equation_enum__COUNT = 5,
    ENUM__gl_blend_equation_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gl_blend_equation_enum> ENUM__gl_blend_equation_enumMap[ENUM__gl_blend_equation_enum__COUNT];


ENUM__gl_blend_equation_enum toEnum_ENUM__gl_blend_equation_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_func_enum
{
    ENUM__gl_func_enum__NEVER = 0,
    ENUM__gl_func_enum__LESS = 1,
    ENUM__gl_func_enum__LEQUAL = 2,
    ENUM__gl_func_enum__EQUAL = 3,
    ENUM__gl_func_enum__GREATER = 4,
    ENUM__gl_func_enum__NOTEQUAL = 5,
    ENUM__gl_func_enum__GEQUAL = 6,
    ENUM__gl_func_enum__ALWAYS = 7,
    ENUM__gl_func_enum__COUNT = 8,
    ENUM__gl_func_enum__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gl_func_enum> ENUM__gl_func_enumMap[ENUM__gl_func_enum__COUNT];


ENUM__gl_func_enum toEnum_ENUM__gl_func_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_stencil_op_enum
{
    ENUM__gl_stencil_op_enum__KEEP = 0,
    ENUM__gl_stencil_op_enum__ZERO = 1,
    ENUM__gl_stencil_op_enum__REPLACE = 2,
    ENUM__gl_stencil_op_enum__INCR = 3,
    ENUM__gl_stencil_op_enum__DECR = 4,
    ENUM__gl_stencil_op_enum__INVERT = 5,
    ENUM__gl_stencil_op_enum__INCR_WRAP = 6,
    ENUM__gl_stencil_op_enum__DECR_WRAP = 7,
    ENUM__gl_stencil_op_enum__COUNT = 8,
    ENUM__gl_stencil_op_enum__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gl_stencil_op_enum> ENUM__gl_stencil_op_enumMap[ENUM__gl_stencil_op_enum__COUNT];


ENUM__gl_stencil_op_enum toEnum_ENUM__gl_stencil_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_material_enum
{
    ENUM__gl_material_enum__EMISSION = 0,
    ENUM__gl_material_enum__AMBIENT = 1,
    ENUM__gl_material_enum__DIFFUSE = 2,
    ENUM__gl_material_enum__SPECULAR = 3,
    ENUM__gl_material_enum__AMBIENT_AND_DIFFUSE = 4,
    ENUM__gl_material_enum__COUNT = 5,
    ENUM__gl_material_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gl_material_enum> ENUM__gl_material_enumMap[ENUM__gl_material_enum__COUNT];


ENUM__gl_material_enum toEnum_ENUM__gl_material_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_fog_enum
{
    ENUM__gl_fog_enum__LINEAR = 0,
    ENUM__gl_fog_enum__EXP = 1,
    ENUM__gl_fog_enum__EXP2 = 2,
    ENUM__gl_fog_enum__COUNT = 3,
    ENUM__gl_fog_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_fog_enum> ENUM__gl_fog_enumMap[ENUM__gl_fog_enum__COUNT];


ENUM__gl_fog_enum toEnum_ENUM__gl_fog_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_fog_coord_src_enum
{
    ENUM__gl_fog_coord_src_enum__FOG_COORDINATE = 0,
    ENUM__gl_fog_coord_src_enum__FRAGMENT_DEPTH = 1,
    ENUM__gl_fog_coord_src_enum__COUNT = 2,
    ENUM__gl_fog_coord_src_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_fog_coord_src_enum> ENUM__gl_fog_coord_src_enumMap[ENUM__gl_fog_coord_src_enum__COUNT];


ENUM__gl_fog_coord_src_enum toEnum_ENUM__gl_fog_coord_src_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_front_face_enum
{
    ENUM__gl_front_face_enum__CW = 0,
    ENUM__gl_front_face_enum__CCW = 1,
    ENUM__gl_front_face_enum__COUNT = 2,
    ENUM__gl_front_face_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_front_face_enum> ENUM__gl_front_face_enumMap[ENUM__gl_front_face_enum__COUNT];


ENUM__gl_front_face_enum toEnum_ENUM__gl_front_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_light_model_color_control_enum
{
    ENUM__gl_light_model_color_control_enum__SINGLE_COLOR = 0,
    ENUM__gl_light_model_color_control_enum__SEPARATE_SPECULAR_COLOR = 1,
    ENUM__gl_light_model_color_control_enum__COUNT = 2,
    ENUM__gl_light_model_color_control_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_light_model_color_control_enum> ENUM__gl_light_model_color_control_enumMap[ENUM__gl_light_model_color_control_enum__COUNT];


ENUM__gl_light_model_color_control_enum toEnum_ENUM__gl_light_model_color_control_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_logic_op_enum
{
    ENUM__gl_logic_op_enum__CLEAR = 0,
    ENUM__gl_logic_op_enum__AND = 1,
    ENUM__gl_logic_op_enum__AND_REVERSE = 2,
    ENUM__gl_logic_op_enum__COPY = 3,
    ENUM__gl_logic_op_enum__AND_INVERTED = 4,
    ENUM__gl_logic_op_enum__NOOP = 5,
    ENUM__gl_logic_op_enum__XOR = 6,
    ENUM__gl_logic_op_enum__OR = 7,
    ENUM__gl_logic_op_enum__NOR = 8,
    ENUM__gl_logic_op_enum__EQUIV = 9,
    ENUM__gl_logic_op_enum__INVERT = 10,
    ENUM__gl_logic_op_enum__OR_REVERSE = 11,
    ENUM__gl_logic_op_enum__COPY_INVERTED = 12,
    ENUM__gl_logic_op_enum__NAND = 13,
    ENUM__gl_logic_op_enum__SET = 14,
    ENUM__gl_logic_op_enum__COUNT = 15,
    ENUM__gl_logic_op_enum__NOT_PRESENT = 16
};

extern const std::pair<StringHash, ENUM__gl_logic_op_enum> ENUM__gl_logic_op_enumMap[ENUM__gl_logic_op_enum__COUNT];


ENUM__gl_logic_op_enum toEnum_ENUM__gl_logic_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_polygon_mode_enum
{
    ENUM__gl_polygon_mode_enum__POINT = 0,
    ENUM__gl_polygon_mode_enum__LINE = 1,
    ENUM__gl_polygon_mode_enum__FILL = 2,
    ENUM__gl_polygon_mode_enum__COUNT = 3,
    ENUM__gl_polygon_mode_enum__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__gl_polygon_mode_enum> ENUM__gl_polygon_mode_enumMap[ENUM__gl_polygon_mode_enum__COUNT];


ENUM__gl_polygon_mode_enum toEnum_ENUM__gl_polygon_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gl_shade_model_enum
{
    ENUM__gl_shade_model_enum__FLAT = 0,
    ENUM__gl_shade_model_enum__SMOOTH = 1,
    ENUM__gl_shade_model_enum__COUNT = 2,
    ENUM__gl_shade_model_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gl_shade_model_enum> ENUM__gl_shade_model_enumMap[ENUM__gl_shade_model_enum__COUNT];


ENUM__gl_shade_model_enum toEnum_ENUM__gl_shade_model_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



struct UNION__gl_enumeration_type
{
    UNION__gl_enumeration_type():union_type(INVALID){}
    UNION__gl_enumeration_type( int value ):union_type(INVALID){}

    enum Types
    {
        GL_BLEND_ENUM,
        GL_FACE_ENUM,
        GL_BLEND_EQUATION_ENUM,
        GL_FUNC_ENUM,
        GL_STENCIL_OP_ENUM,
        GL_MATERIAL_ENUM,
        GL_FOG_ENUM,
        GL_FOG_COORD_SRC_ENUM,
        GL_FRONT_FACE_ENUM,
        GL_LIGHT_MODEL_COLOR_CONTROL_ENUM,
        GL_LOGIC_OP_ENUM,
        GL_POLYGON_MODE_ENUM,
        GL_SHADE_MODEL_ENUM,
        INVALID
    } union_type;

    union Data
    {
        ENUM__gl_blend_enum GL_BLEND_ENUM;
        ENUM__gl_face_enum GL_FACE_ENUM;
        ENUM__gl_blend_equation_enum GL_BLEND_EQUATION_ENUM;
        ENUM__gl_func_enum GL_FUNC_ENUM;
        ENUM__gl_stencil_op_enum GL_STENCIL_OP_ENUM;
        ENUM__gl_material_enum GL_MATERIAL_ENUM;
        ENUM__gl_fog_enum GL_FOG_ENUM;
        ENUM__gl_fog_coord_src_enum GL_FOG_COORD_SRC_ENUM;
        ENUM__gl_front_face_enum GL_FRONT_FACE_ENUM;
        ENUM__gl_light_model_color_control_enum GL_LIGHT_MODEL_COLOR_CONTROL_ENUM;
        ENUM__gl_logic_op_enum GL_LOGIC_OP_ENUM;
        ENUM__gl_polygon_mode_enum GL_POLYGON_MODE_ENUM;
        ENUM__gl_shade_model_enum GL_SHADE_MODEL_ENUM;
    } union_data;
};

UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar* buffer, size_t length, bool& failed );



UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed );



UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar** buffer, bool& failed );



enum ENUM__fx_pipeline_stage_enum
{
    ENUM__fx_pipeline_stage_enum__TESSELLATION = 0,
    ENUM__fx_pipeline_stage_enum__VERTEX = 1,
    ENUM__fx_pipeline_stage_enum__GEOMETRY = 2,
    ENUM__fx_pipeline_stage_enum__FRAGMENT = 3,
    ENUM__fx_pipeline_stage_enum__COUNT = 4,
    ENUM__fx_pipeline_stage_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__fx_pipeline_stage_enum> ENUM__fx_pipeline_stage_enumMap[ENUM__fx_pipeline_stage_enum__COUNT];


ENUM__fx_pipeline_stage_enum toEnum_ENUM__fx_pipeline_stage_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_pipeline_stage_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__image_face_enum
{
    ENUM__image_face_enum__POSITIVE_X = 0,
    ENUM__image_face_enum__NEGATIVE_X = 1,
    ENUM__image_face_enum__POSITIVE_Y = 2,
    ENUM__image_face_enum__NEGATIVE_Y = 3,
    ENUM__image_face_enum__POSITIVE_Z = 4,
    ENUM__image_face_enum__NEGATIVE_Z = 5,
    ENUM__image_face_enum__COUNT = 6,
    ENUM__image_face_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__image_face_enum> ENUM__image_face_enumMap[ENUM__image_face_enum__COUNT];


ENUM__image_face_enum toEnum_ENUM__image_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_sampler_wrap_enum
{
    ENUM__gles_sampler_wrap_enum__REPEAT = 0,
    ENUM__gles_sampler_wrap_enum__CLAMP = 1,
    ENUM__gles_sampler_wrap_enum__CLAMP_TO_EDGE = 2,
    ENUM__gles_sampler_wrap_enum__MIRRORED_REPEAT = 3,
    ENUM__gles_sampler_wrap_enum__COUNT = 4,
    ENUM__gles_sampler_wrap_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_sampler_wrap_enum> ENUM__gles_sampler_wrap_enumMap[ENUM__gles_sampler_wrap_enum__COUNT];


ENUM__gles_sampler_wrap_enum toEnum_ENUM__gles_sampler_wrap_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



struct UNION__gles_enumeration_type
{
    UNION__gles_enumeration_type():union_type(INVALID){}
    UNION__gles_enumeration_type( int value ):union_type(INVALID){}

    enum Types
    {
        GL_BLEND_ENUM,
        GL_FACE_ENUM,
        GL_FUNC_ENUM,
        GL_STENCIL_OP_ENUM,
        GL_MATERIAL_ENUM,
        GL_FOG_ENUM,
        GL_FRONT_FACE_ENUM,
        GL_LIGHT_MODEL_COLOR_CONTROL_ENUM,
        GL_LOGIC_OP_ENUM,
        GL_POLYGON_MODE_ENUM,
        GL_SHADE_MODEL_ENUM,
        INVALID
    } union_type;

    union Data
    {
        ENUM__gl_blend_enum GL_BLEND_ENUM;
        ENUM__gl_face_enum GL_FACE_ENUM;
        ENUM__gl_func_enum GL_FUNC_ENUM;
        ENUM__gl_stencil_op_enum GL_STENCIL_OP_ENUM;
        ENUM__gl_material_enum GL_MATERIAL_ENUM;
        ENUM__gl_fog_enum GL_FOG_ENUM;
        ENUM__gl_front_face_enum GL_FRONT_FACE_ENUM;
        ENUM__gl_light_model_color_control_enum GL_LIGHT_MODEL_COLOR_CONTROL_ENUM;
        ENUM__gl_logic_op_enum GL_LOGIC_OP_ENUM;
        ENUM__gl_polygon_mode_enum GL_POLYGON_MODE_ENUM;
        ENUM__gl_shade_model_enum GL_SHADE_MODEL_ENUM;
    } union_data;
};

UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar* buffer, size_t length, bool& failed );



UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed );



UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar** buffer, bool& failed );



enum ENUM__gles_stencil_op_enum
{
    ENUM__gles_stencil_op_enum__KEEP = 0,
    ENUM__gles_stencil_op_enum__ZERO = 1,
    ENUM__gles_stencil_op_enum__REPLACE = 2,
    ENUM__gles_stencil_op_enum__INCR = 3,
    ENUM__gles_stencil_op_enum__DECR = 4,
    ENUM__gles_stencil_op_enum__INVERT = 5,
    ENUM__gles_stencil_op_enum__COUNT = 6,
    ENUM__gles_stencil_op_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__gles_stencil_op_enum> ENUM__gles_stencil_op_enumMap[ENUM__gles_stencil_op_enum__COUNT];


ENUM__gles_stencil_op_enum toEnum_ENUM__gles_stencil_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operator_rgb_enum
{
    ENUM__gles_texcombiner_operator_rgb_enum__REPLACE = 0,
    ENUM__gles_texcombiner_operator_rgb_enum__MODULATE = 1,
    ENUM__gles_texcombiner_operator_rgb_enum__ADD = 2,
    ENUM__gles_texcombiner_operator_rgb_enum__ADD_SIGNED = 3,
    ENUM__gles_texcombiner_operator_rgb_enum__INTERPOLATE = 4,
    ENUM__gles_texcombiner_operator_rgb_enum__SUBTRACT = 5,
    ENUM__gles_texcombiner_operator_rgb_enum__DOT3_RGB = 6,
    ENUM__gles_texcombiner_operator_rgb_enum__DOT3_RGBA = 7,
    ENUM__gles_texcombiner_operator_rgb_enum__COUNT = 8,
    ENUM__gles_texcombiner_operator_rgb_enum__NOT_PRESENT = 9
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum> ENUM__gles_texcombiner_operator_rgb_enumMap[ENUM__gles_texcombiner_operator_rgb_enum__COUNT];


ENUM__gles_texcombiner_operator_rgb_enum toEnum_ENUM__gles_texcombiner_operator_rgb_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_source_enum
{
    ENUM__gles_texcombiner_source_enum__TEXTURE = 0,
    ENUM__gles_texcombiner_source_enum__CONSTANT = 1,
    ENUM__gles_texcombiner_source_enum__PRIMARY = 2,
    ENUM__gles_texcombiner_source_enum__PREVIOUS = 3,
    ENUM__gles_texcombiner_source_enum__COUNT = 4,
    ENUM__gles_texcombiner_source_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_source_enum> ENUM__gles_texcombiner_source_enumMap[ENUM__gles_texcombiner_source_enum__COUNT];


ENUM__gles_texcombiner_source_enum toEnum_ENUM__gles_texcombiner_source_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operand_rgb_enum
{
    ENUM__gles_texcombiner_operand_rgb_enum__SRC_COLOR = 0,
    ENUM__gles_texcombiner_operand_rgb_enum__ONE_MINUS_SRC_COLOR = 1,
    ENUM__gles_texcombiner_operand_rgb_enum__SRC_ALPHA = 2,
    ENUM__gles_texcombiner_operand_rgb_enum__ONE_MINUS_SRC_ALPHA = 3,
    ENUM__gles_texcombiner_operand_rgb_enum__COUNT = 4,
    ENUM__gles_texcombiner_operand_rgb_enum__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum> ENUM__gles_texcombiner_operand_rgb_enumMap[ENUM__gles_texcombiner_operand_rgb_enum__COUNT];


ENUM__gles_texcombiner_operand_rgb_enum toEnum_ENUM__gles_texcombiner_operand_rgb_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operator_alpha_enum
{
    ENUM__gles_texcombiner_operator_alpha_enum__REPLACE = 0,
    ENUM__gles_texcombiner_operator_alpha_enum__MODULATE = 1,
    ENUM__gles_texcombiner_operator_alpha_enum__ADD = 2,
    ENUM__gles_texcombiner_operator_alpha_enum__ADD_SIGNED = 3,
    ENUM__gles_texcombiner_operator_alpha_enum__INTERPOLATE = 4,
    ENUM__gles_texcombiner_operator_alpha_enum__SUBTRACT = 5,
    ENUM__gles_texcombiner_operator_alpha_enum__COUNT = 6,
    ENUM__gles_texcombiner_operator_alpha_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum> ENUM__gles_texcombiner_operator_alpha_enumMap[ENUM__gles_texcombiner_operator_alpha_enum__COUNT];


ENUM__gles_texcombiner_operator_alpha_enum toEnum_ENUM__gles_texcombiner_operator_alpha_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texcombiner_operand_alpha_enum
{
    ENUM__gles_texcombiner_operand_alpha_enum__SRC_ALPHA = 0,
    ENUM__gles_texcombiner_operand_alpha_enum__ONE_MINUS_SRC_ALPHA = 1,
    ENUM__gles_texcombiner_operand_alpha_enum__COUNT = 2,
    ENUM__gles_texcombiner_operand_alpha_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum> ENUM__gles_texcombiner_operand_alpha_enumMap[ENUM__gles_texcombiner_operand_alpha_enum__COUNT];


ENUM__gles_texcombiner_operand_alpha_enum toEnum_ENUM__gles_texcombiner_operand_alpha_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__gles_texenv_mode_enum
{
    ENUM__gles_texenv_mode_enum__REPLACE = 0,
    ENUM__gles_texenv_mode_enum__MODULATE = 1,
    ENUM__gles_texenv_mode_enum__DECAL = 2,
    ENUM__gles_texenv_mode_enum__BLEND = 3,
    ENUM__gles_texenv_mode_enum__ADD = 4,
    ENUM__gles_texenv_mode_enum__COUNT = 5,
    ENUM__gles_texenv_mode_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__gles_texenv_mode_enum> ENUM__gles_texenv_mode_enumMap[ENUM__gles_texenv_mode_enum__COUNT];


ENUM__gles_texenv_mode_enum toEnum_ENUM__gles_texenv_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__image_format_hint_channels_enum
{
    ENUM__image_format_hint_channels_enum__RGB = 0,
    ENUM__image_format_hint_channels_enum__RGBA = 1,
    ENUM__image_format_hint_channels_enum__RGBE = 2,
    ENUM__image_format_hint_channels_enum__L = 3,
    ENUM__image_format_hint_channels_enum__LA = 4,
    ENUM__image_format_hint_channels_enum__D = 5,
    ENUM__image_format_hint_channels_enum__COUNT = 6,
    ENUM__image_format_hint_channels_enum__NOT_PRESENT = 7
};

extern const std::pair<StringHash, ENUM__image_format_hint_channels_enum> ENUM__image_format_hint_channels_enumMap[ENUM__image_format_hint_channels_enum__COUNT];


ENUM__image_format_hint_channels_enum toEnum_ENUM__image_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__image_format_hint_range_enum
{
    ENUM__image_format_hint_range_enum__SNORM = 0,
    ENUM__image_format_hint_range_enum__UNORM = 1,
    ENUM__image_format_hint_range_enum__SINT = 2,
    ENUM__image_format_hint_range_enum__UINT = 3,
    ENUM__image_format_hint_range_enum__FLOAT = 4,
    ENUM__image_format_hint_range_enum__COUNT = 5,
    ENUM__image_format_hint_range_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__image_format_hint_range_enum> ENUM__image_format_hint_range_enumMap[ENUM__image_format_hint_range_enum__COUNT];


ENUM__image_format_hint_range_enum toEnum_ENUM__image_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__image_format_hint_precision_enum
{
    ENUM__image_format_hint_precision_enum__DEFAULT = 0,
    ENUM__image_format_hint_precision_enum__LOW = 1,
    ENUM__image_format_hint_precision_enum__MID = 2,
    ENUM__image_format_hint_precision_enum__HIGH = 3,
    ENUM__image_format_hint_precision_enum__MAX = 4,
    ENUM__image_format_hint_precision_enum__COUNT = 5,
    ENUM__image_format_hint_precision_enum__NOT_PRESENT = 6
};

extern const std::pair<StringHash, ENUM__image_format_hint_precision_enum> ENUM__image_format_hint_precision_enumMap[ENUM__image_format_hint_precision_enum__COUNT];


ENUM__image_format_hint_precision_enum toEnum_ENUM__image_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__node_enum
{
    ENUM__node_enum__JOINT = 0,
    ENUM__node_enum__NODE = 1,
    ENUM__node_enum__COUNT = 2,
    ENUM__node_enum__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__node_enum> ENUM__node_enumMap[ENUM__node_enum__COUNT];


ENUM__node_enum toEnum_ENUM__node_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__node_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__overflow
{
    ENUM__mathml__overflow__scroll = 0,
    ENUM__mathml__overflow__elide = 1,
    ENUM__mathml__overflow__truncate = 2,
    ENUM__mathml__overflow__scale = 3,
    ENUM__mathml__overflow__COUNT = 4,
    ENUM__mathml__overflow__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__mathml__overflow> ENUM__mathml__overflowMap[ENUM__mathml__overflow__COUNT];


ENUM__mathml__overflow toEnum_ENUM__mathml__overflow (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__overflow>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__display
{
    ENUM__mathml__display__block = 0,
    ENUM__mathml__display__inline = 1,
    ENUM__mathml__display__COUNT = 2,
    ENUM__mathml__display__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__mathml__display> ENUM__mathml__displayMap[ENUM__mathml__display__COUNT];


ENUM__mathml__display toEnum_ENUM__mathml__display (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__display>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__cn__type
{
    ENUM__mathml__cn__type__e_notation = 0,
    ENUM__mathml__cn__type__integer = 1,
    ENUM__mathml__cn__type__rational = 2,
    ENUM__mathml__cn__type__real = 3,
    ENUM__mathml__cn__type__complex_cartesian = 4,
    ENUM__mathml__cn__type__complex_polar = 5,
    ENUM__mathml__cn__type__constant = 6,
    ENUM__mathml__cn__type__COUNT = 7,
    ENUM__mathml__cn__type__NOT_PRESENT = 8
};

extern const std::pair<StringHash, ENUM__mathml__cn__type> ENUM__mathml__cn__typeMap[ENUM__mathml__cn__type__COUNT];


ENUM__mathml__cn__type toEnum_ENUM__mathml__cn__type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__cn__type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__list__order
{
    ENUM__mathml__list__order__lexicographic = 0,
    ENUM__mathml__list__order__numeric = 1,
    ENUM__mathml__list__order__COUNT = 2,
    ENUM__mathml__list__order__NOT_PRESENT = 3
};

extern const std::pair<StringHash, ENUM__mathml__list__order> ENUM__mathml__list__orderMap[ENUM__mathml__list__order__COUNT];


ENUM__mathml__list__order toEnum_ENUM__mathml__list__order (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__list__order>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__interval__closure
{
    ENUM__mathml__interval__closure__closed = 0,
    ENUM__mathml__interval__closure__open = 1,
    ENUM__mathml__interval__closure__open_closed = 2,
    ENUM__mathml__interval__closure__closed_open = 3,
    ENUM__mathml__interval__closure__COUNT = 4,
    ENUM__mathml__interval__closure__NOT_PRESENT = 5
};

extern const std::pair<StringHash, ENUM__mathml__interval__closure> ENUM__mathml__interval__closureMap[ENUM__mathml__interval__closure__COUNT];


ENUM__mathml__interval__closure toEnum_ENUM__mathml__interval__closure (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__interval__closure>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);



enum ENUM__mathml__declare__occurrence
{
    ENUM__mathml__declare__occurrence__prefix = 0,
    ENUM__mathml__declare__occurrence__infix = 1,
    ENUM__mathml__declare__occurrence__function_model = 2,
    ENUM__mathml__declare__occurrence__COUNT = 3,
    ENUM__mathml__declare__occurrence__NOT_PRESENT = 4
};

extern const std::pair<StringHash, ENUM__mathml__declare__occurrence> ENUM__mathml__declare__occurrenceMap[ENUM__mathml__declare__occurrence__COUNT];


ENUM__mathml__declare__occurrence toEnum_ENUM__mathml__declare__occurrence (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__declare__occurrence>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);





} // namespace
#endif
