/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLColladaParserAutoGenEnums.h"
#include "GeneratedSaxParserUtils.h"


namespace COLLADASaxFWL
{


//---------------------------------------------------------------------
const std::pair<StringHash, UpAxisType> UpAxisTypeMap[UpAxisType__COUNT] = 
{
    std::pair<StringHash, UpAxisType>(386208, UpAxisType__X_UP),
    std::pair<StringHash, UpAxisType>(390304, UpAxisType__Y_UP),
    std::pair<StringHash, UpAxisType>(394400, UpAxisType__Z_UP)
};

//---------------------------------------------------------------------
UpAxisType toEnum_UpAxisType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<UpAxisType, StringHash, UpAxisType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_modifier_enum_common> fx_modifier_enum_commonMap[fx_modifier_enum_common__COUNT] = 
{
    std::pair<StringHash, fx_modifier_enum_common>(4735876, fx_modifier_enum_common__CONST),
    std::pair<StringHash, fx_modifier_enum_common>(78482030, fx_modifier_enum_common__EXTERN),
    std::pair<StringHash, fx_modifier_enum_common>(92038804, fx_modifier_enum_common__SHARED),
    std::pair<StringHash, fx_modifier_enum_common>(92825811, fx_modifier_enum_common__STATIC),
    std::pair<StringHash, fx_modifier_enum_common>(170767421, fx_modifier_enum_common__UNIFORM),
    std::pair<StringHash, fx_modifier_enum_common>(174579319, fx_modifier_enum_common__VARYING),
    std::pair<StringHash, fx_modifier_enum_common>(67537333, fx_modifier_enum_common__VOLATILE)
};

//---------------------------------------------------------------------
fx_modifier_enum_common toEnum_fx_modifier_enum_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_modifier_enum_common, StringHash, fx_modifier_enum_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_type_enum> fx_surface_type_enumMap[fx_surface_type_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_type_enum>(852, fx_surface_type_enum__1D),
    std::pair<StringHash, fx_surface_type_enum>(868, fx_surface_type_enum__2D),
    std::pair<StringHash, fx_surface_type_enum>(884, fx_surface_type_enum__3D),
    std::pair<StringHash, fx_surface_type_enum>(297317, fx_surface_type_enum__CUBE),
    std::pair<StringHash, fx_surface_type_enum>(4760968, fx_surface_type_enum__DEPTH),
    std::pair<StringHash, fx_surface_type_enum>(354692, fx_surface_type_enum__RECT),
    std::pair<StringHash, fx_surface_type_enum>(171566276, fx_surface_type_enum__UNTYPED)
};

//---------------------------------------------------------------------
fx_surface_type_enum toEnum_fx_surface_type_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_type_enum, StringHash, fx_surface_type_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_face_enum> fx_surface_face_enumMap[fx_surface_face_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_face_enum>(109806840, fx_surface_face_enum__NEGATIVE_X),
    std::pair<StringHash, fx_surface_face_enum>(109806841, fx_surface_face_enum__NEGATIVE_Y),
    std::pair<StringHash, fx_surface_face_enum>(109806842, fx_surface_face_enum__NEGATIVE_Z),
    std::pair<StringHash, fx_surface_face_enum>(244055864, fx_surface_face_enum__POSITIVE_X),
    std::pair<StringHash, fx_surface_face_enum>(244055865, fx_surface_face_enum__POSITIVE_Y),
    std::pair<StringHash, fx_surface_face_enum>(244055866, fx_surface_face_enum__POSITIVE_Z)
};

//---------------------------------------------------------------------
fx_surface_face_enum toEnum_fx_surface_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_face_enum, StringHash, fx_surface_face_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_format_hint_channels_enum> fx_surface_format_hint_channels_enumMap[fx_surface_format_hint_channels_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(68, fx_surface_format_hint_channels_enum__D),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(76, fx_surface_format_hint_channels_enum__L),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(1281, fx_surface_format_hint_channels_enum__LA),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(22194, fx_surface_format_hint_channels_enum__RGB),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(355169, fx_surface_format_hint_channels_enum__RGBA),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(24042, fx_surface_format_hint_channels_enum__XYZ),
    std::pair<StringHash, fx_surface_format_hint_channels_enum>(384759, fx_surface_format_hint_channels_enum__XYZW)
};

//---------------------------------------------------------------------
fx_surface_format_hint_channels_enum toEnum_fx_surface_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_format_hint_channels_enum, StringHash, fx_surface_format_hint_channels_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_format_hint_range_enum> fx_surface_format_hint_range_enumMap[fx_surface_format_hint_range_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_format_hint_range_enum>(4920164, fx_surface_format_hint_range_enum__FLOAT),
    std::pair<StringHash, fx_surface_format_hint_range_enum>(359988, fx_surface_format_hint_range_enum__SINT),
    std::pair<StringHash, fx_surface_format_hint_range_enum>(5780589, fx_surface_format_hint_range_enum__SNORM),
    std::pair<StringHash, fx_surface_format_hint_range_enum>(368180, fx_surface_format_hint_range_enum__UINT),
    std::pair<StringHash, fx_surface_format_hint_range_enum>(5911661, fx_surface_format_hint_range_enum__UNORM)
};

//---------------------------------------------------------------------
fx_surface_format_hint_range_enum toEnum_fx_surface_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_format_hint_range_enum, StringHash, fx_surface_format_hint_range_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_format_hint_precision_enum> fx_surface_format_hint_precision_enumMap[fx_surface_format_hint_precision_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_format_hint_precision_enum>(314808, fx_surface_format_hint_precision_enum__HIGH),
    std::pair<StringHash, fx_surface_format_hint_precision_enum>(20807, fx_surface_format_hint_precision_enum__LOW),
    std::pair<StringHash, fx_surface_format_hint_precision_enum>(20948, fx_surface_format_hint_precision_enum__MID)
};

//---------------------------------------------------------------------
fx_surface_format_hint_precision_enum toEnum_fx_surface_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_format_hint_precision_enum, StringHash, fx_surface_format_hint_precision_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_surface_format_hint_option_enum> fx_surface_format_hint_option_enumMap[fx_surface_format_hint_option_enum__COUNT] = 
{
    std::pair<StringHash, fx_surface_format_hint_option_enum>(235107429, fx_surface_format_hint_option_enum__COMPRESSABLE),
    std::pair<StringHash, fx_surface_format_hint_option_enum>(106802787, fx_surface_format_hint_option_enum__NORMALIZED3),
    std::pair<StringHash, fx_surface_format_hint_option_enum>(106802788, fx_surface_format_hint_option_enum__NORMALIZED4),
    std::pair<StringHash, fx_surface_format_hint_option_enum>(138340513, fx_surface_format_hint_option_enum__SRGB_GAMMA)
};

//---------------------------------------------------------------------
fx_surface_format_hint_option_enum toEnum_fx_surface_format_hint_option_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_surface_format_hint_option_enum, StringHash, fx_surface_format_hint_option_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texcombiner_operatorRGB_enums> gles_texcombiner_operatorRGB_enumsMap[gles_texcombiner_operatorRGB_enums__COUNT] = 
{
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(17796, gles_texcombiner_operatorRGB_enums__ADD),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(75102772, gles_texcombiner_operatorRGB_enums__ADD_SIGNED),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(75055650, gles_texcombiner_operatorRGB_enums__DOT3_RGB),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(127148577, gles_texcombiner_operatorRGB_enums__DOT3_RGBA),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(119422501, gles_texcombiner_operatorRGB_enums__INTERPOLATE),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(60425125, gles_texcombiner_operatorRGB_enums__MODULATE),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(111478053, gles_texcombiner_operatorRGB_enums__REPLACE),
    std::pair<StringHash, gles_texcombiner_operatorRGB_enums>(158949380, gles_texcombiner_operatorRGB_enums__SUBTRACT)
};

//---------------------------------------------------------------------
gles_texcombiner_operatorRGB_enums toEnum_gles_texcombiner_operatorRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texcombiner_operatorRGB_enums, StringHash, gles_texcombiner_operatorRGB_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texcombiner_source_enums> gles_texcombiner_source_enumsMap[gles_texcombiner_source_enums__COUNT] = 
{
    std::pair<StringHash, gles_texcombiner_source_enums>(70812340, gles_texcombiner_source_enums__CONSTANT),
    std::pair<StringHash, gles_texcombiner_source_enums>(111862259, gles_texcombiner_source_enums__PREVIOUS),
    std::pair<StringHash, gles_texcombiner_source_enums>(91100713, gles_texcombiner_source_enums__PRIMARY),
    std::pair<StringHash, gles_texcombiner_source_enums>(145594933, gles_texcombiner_source_enums__TEXTURE)
};

//---------------------------------------------------------------------
gles_texcombiner_source_enums toEnum_gles_texcombiner_source_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texcombiner_source_enums, StringHash, gles_texcombiner_source_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texcombiner_operandRGB_enums> gles_texcombiner_operandRGB_enumsMap[gles_texcombiner_operandRGB_enums__COUNT] = 
{
    std::pair<StringHash, gles_texcombiner_operandRGB_enums>(11673281, gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, gles_texcombiner_operandRGB_enums>(11815746, gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, gles_texcombiner_operandRGB_enums>(154553505, gles_texcombiner_operandRGB_enums__SRC_ALPHA),
    std::pair<StringHash, gles_texcombiner_operandRGB_enums>(154695970, gles_texcombiner_operandRGB_enums__SRC_COLOR)
};

//---------------------------------------------------------------------
gles_texcombiner_operandRGB_enums toEnum_gles_texcombiner_operandRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texcombiner_operandRGB_enums, StringHash, gles_texcombiner_operandRGB_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texcombiner_operatorAlpha_enums> gles_texcombiner_operatorAlpha_enumsMap[gles_texcombiner_operatorAlpha_enums__COUNT] = 
{
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(17796, gles_texcombiner_operatorAlpha_enums__ADD),
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(75102772, gles_texcombiner_operatorAlpha_enums__ADD_SIGNED),
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(119422501, gles_texcombiner_operatorAlpha_enums__INTERPOLATE),
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(60425125, gles_texcombiner_operatorAlpha_enums__MODULATE),
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(111478053, gles_texcombiner_operatorAlpha_enums__REPLACE),
    std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>(158949380, gles_texcombiner_operatorAlpha_enums__SUBTRACT)
};

//---------------------------------------------------------------------
gles_texcombiner_operatorAlpha_enums toEnum_gles_texcombiner_operatorAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texcombiner_operatorAlpha_enums, StringHash, gles_texcombiner_operatorAlpha_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texcombiner_operandAlpha_enums> gles_texcombiner_operandAlpha_enumsMap[gles_texcombiner_operandAlpha_enums__COUNT] = 
{
    std::pair<StringHash, gles_texcombiner_operandAlpha_enums>(11673281, gles_texcombiner_operandAlpha_enums__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, gles_texcombiner_operandAlpha_enums>(154553505, gles_texcombiner_operandAlpha_enums__SRC_ALPHA)
};

//---------------------------------------------------------------------
gles_texcombiner_operandAlpha_enums toEnum_gles_texcombiner_operandAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texcombiner_operandAlpha_enums, StringHash, gles_texcombiner_operandAlpha_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_texenv_mode_enums> gles_texenv_mode_enumsMap[gles_texenv_mode_enums__COUNT] = 
{
    std::pair<StringHash, gles_texenv_mode_enums>(17796, gles_texenv_mode_enums__ADD),
    std::pair<StringHash, gles_texenv_mode_enums>(4655652, gles_texenv_mode_enums__BLEND),
    std::pair<StringHash, gles_texenv_mode_enums>(4757340, gles_texenv_mode_enums__DECAL),
    std::pair<StringHash, gles_texenv_mode_enums>(60425125, gles_texenv_mode_enums__MODULATE),
    std::pair<StringHash, gles_texenv_mode_enums>(111478053, gles_texenv_mode_enums__REPLACE)
};

//---------------------------------------------------------------------
gles_texenv_mode_enums toEnum_gles_texenv_mode_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_texenv_mode_enums, StringHash, gles_texenv_mode_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_sampler_wrap> gles_sampler_wrapMap[gles_sampler_wrap__COUNT] = 
{
    std::pair<StringHash, gles_sampler_wrap>(4720160, gles_sampler_wrap__CLAMP),
    std::pair<StringHash, gles_sampler_wrap>(22396597, gles_sampler_wrap__CLAMP_TO_EDGE),
    std::pair<StringHash, gles_sampler_wrap>(52326884, gles_sampler_wrap__MIRRORED_REPEAT),
    std::pair<StringHash, gles_sampler_wrap>(90851684, gles_sampler_wrap__REPEAT)
};

//---------------------------------------------------------------------
gles_sampler_wrap toEnum_gles_sampler_wrap (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_sampler_wrap, StringHash, gles_sampler_wrap__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_sampler_filter_common> fx_sampler_filter_commonMap[fx_sampler_filter_common__COUNT] = 
{
    std::pair<StringHash, fx_sampler_filter_common>(84814178, fx_sampler_filter_common__LINEAR),
    std::pair<StringHash, fx_sampler_filter_common>(230972482, fx_sampler_filter_common__LINEAR_MIPMAP_LINEAR),
    std::pair<StringHash, fx_sampler_filter_common>(242301012, fx_sampler_filter_common__LINEAR_MIPMAP_NEAREST),
    std::pair<StringHash, fx_sampler_filter_common>(43412180, fx_sampler_filter_common__NEAREST),
    std::pair<StringHash, fx_sampler_filter_common>(92529554, fx_sampler_filter_common__NEAREST_MIPMAP_LINEAR),
    std::pair<StringHash, fx_sampler_filter_common>(174769620, fx_sampler_filter_common__NEAREST_MIPMAP_NEAREST),
    std::pair<StringHash, fx_sampler_filter_common>(341029, fx_sampler_filter_common__NONE)
};

//---------------------------------------------------------------------
fx_sampler_filter_common toEnum_fx_sampler_filter_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_sampler_filter_common, StringHash, fx_sampler_filter_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_func_type> gl_func_typeMap[gl_func_type__COUNT] = 
{
    std::pair<StringHash, gl_func_type>(73512675, gl_func_type__ALWAYS),
    std::pair<StringHash, gl_func_type>(4876636, gl_func_type__EQUAL),
    std::pair<StringHash, gl_func_type>(79325532, gl_func_type__GEQUAL),
    std::pair<StringHash, gl_func_type>(208234722, gl_func_type__GREATER),
    std::pair<StringHash, gl_func_type>(84568412, gl_func_type__LEQUAL),
    std::pair<StringHash, gl_func_type>(330371, gl_func_type__LESS),
    std::pair<StringHash, gl_func_type>(5417634, gl_func_type__NEVER),
    std::pair<StringHash, gl_func_type>(76180588, gl_func_type__NOTEQUAL)
};

//---------------------------------------------------------------------
gl_func_type toEnum_gl_func_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_func_type, StringHash, gl_func_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_blend_type> gl_blend_typeMap[gl_blend_type__COUNT] = 
{
    std::pair<StringHash, gl_blend_type>(235837041, gl_blend_type__CONSTANT_ALPHA),
    std::pair<StringHash, gl_blend_type>(235979762, gl_blend_type__CONSTANT_COLOR),
    std::pair<StringHash, gl_blend_type>(171232194, gl_blend_type__DEST_COLOR),
    std::pair<StringHash, gl_blend_type>(171334977, gl_blend_type__DST_ALPHA),
    std::pair<StringHash, gl_blend_type>(21541, gl_blend_type__ONE),
    std::pair<StringHash, gl_blend_type>(58120065, gl_blend_type__ONE_MINUS_CONSTANT_ALPHA),
    std::pair<StringHash, gl_blend_type>(58262530, gl_blend_type__ONE_MINUS_CONSTANT_COLOR),
    std::pair<StringHash, gl_blend_type>(41006258, gl_blend_type__ONE_MINUS_DEST_COLOR),
    std::pair<StringHash, gl_blend_type>(263351505, gl_blend_type__ONE_MINUS_DST_ALPHA),
    std::pair<StringHash, gl_blend_type>(11673281, gl_blend_type__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, gl_blend_type>(11815746, gl_blend_type__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, gl_blend_type>(154553505, gl_blend_type__SRC_ALPHA),
    std::pair<StringHash, gl_blend_type>(38887829, gl_blend_type__SRC_ALPHA_SATURATE),
    std::pair<StringHash, gl_blend_type>(154695970, gl_blend_type__SRC_COLOR),
    std::pair<StringHash, gl_blend_type>(387695, gl_blend_type__ZERO)
};

//---------------------------------------------------------------------
gl_blend_type toEnum_gl_blend_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_blend_type, StringHash, gl_blend_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_face_type> gl_face_typeMap[gl_face_type__COUNT] = 
{
    std::pair<StringHash, gl_face_type>(288123, gl_face_type__BACK),
    std::pair<StringHash, gl_face_type>(4944948, gl_face_type__FRONT),
    std::pair<StringHash, gl_face_type>(98615947, gl_face_type__FRONT_AND_BACK)
};

//---------------------------------------------------------------------
gl_face_type toEnum_gl_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_face_type, StringHash, gl_face_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_fog_type> gl_fog_typeMap[gl_fog_type__COUNT] = 
{
    std::pair<StringHash, gl_fog_type>(19152, gl_fog_type__EXP),
    std::pair<StringHash, gl_fog_type>(306482, gl_fog_type__EXP2),
    std::pair<StringHash, gl_fog_type>(84814178, gl_fog_type__LINEAR)
};

//---------------------------------------------------------------------
gl_fog_type toEnum_gl_fog_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_fog_type, StringHash, gl_fog_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_front_face_type> gl_front_face_typeMap[gl_front_face_type__COUNT] = 
{
    std::pair<StringHash, gl_front_face_type>(18311, gl_front_face_type__CCW),
    std::pair<StringHash, gl_front_face_type>(1159, gl_front_face_type__CW)
};

//---------------------------------------------------------------------
gl_front_face_type toEnum_gl_front_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_front_face_type, StringHash, gl_front_face_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_logic_op_type> gl_logic_op_typeMap[gl_logic_op_type__COUNT] = 
{
    std::pair<StringHash, gl_logic_op_type>(17956, gl_logic_op_type__AND),
    std::pair<StringHash, gl_logic_op_type>(130603892, gl_logic_op_type__AND_INVERTED),
    std::pair<StringHash, gl_logic_op_type>(116165941, gl_logic_op_type__AND_REVERSE),
    std::pair<StringHash, gl_logic_op_type>(4720994, gl_logic_op_type__CLEAR),
    std::pair<StringHash, gl_logic_op_type>(296025, gl_logic_op_type__COPY),
    std::pair<StringHash, gl_logic_op_type>(200248116, gl_logic_op_type__COPY_INVERTED),
    std::pair<StringHash, gl_logic_op_type>(4876774, gl_logic_op_type__EQUIV),
    std::pair<StringHash, gl_logic_op_type>(82029172, gl_logic_op_type__INVERT),
    std::pair<StringHash, gl_logic_op_type>(337444, gl_logic_op_type__NAND),
    std::pair<StringHash, gl_logic_op_type>(341056, gl_logic_op_type__NOOP),
    std::pair<StringHash, gl_logic_op_type>(21314, gl_logic_op_type__NOR),
    std::pair<StringHash, gl_logic_op_type>(1346, gl_logic_op_type__OR),
    std::pair<StringHash, gl_logic_op_type>(112193333, gl_logic_op_type__OR_REVERSE),
    std::pair<StringHash, gl_logic_op_type>(22436, gl_logic_op_type__SET),
    std::pair<StringHash, gl_logic_op_type>(23874, gl_logic_op_type__XOR)
};

//---------------------------------------------------------------------
gl_logic_op_type toEnum_gl_logic_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_logic_op_type, StringHash, gl_logic_op_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gl_shade_model_type> gl_shade_model_typeMap[gl_shade_model_type__COUNT] = 
{
    std::pair<StringHash, gl_shade_model_type>(307300, gl_shade_model_type__FLAT),
    std::pair<StringHash, gl_shade_model_type>(92423304, gl_shade_model_type__SMOOTH)
};

//---------------------------------------------------------------------
gl_shade_model_type toEnum_gl_shade_model_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gl_shade_model_type, StringHash, gl_shade_model_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, gles_stencil_op_type> gles_stencil_op_typeMap[gles_stencil_op_type__COUNT] = 
{
    std::pair<StringHash, gles_stencil_op_type>(297346, gles_stencil_op_type__DECR),
    std::pair<StringHash, gles_stencil_op_type>(320130, gles_stencil_op_type__INCR),
    std::pair<StringHash, gles_stencil_op_type>(82029172, gles_stencil_op_type__INVERT),
    std::pair<StringHash, gles_stencil_op_type>(326048, gles_stencil_op_type__KEEP),
    std::pair<StringHash, gles_stencil_op_type>(111478053, gles_stencil_op_type__REPLACE),
    std::pair<StringHash, gles_stencil_op_type>(387695, gles_stencil_op_type__ZERO)
};

//---------------------------------------------------------------------
gles_stencil_op_type toEnum_gles_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<gles_stencil_op_type, StringHash, gles_stencil_op_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, VersionType> VersionTypeMap[VersionType__COUNT] = 
{
    std::pair<StringHash, VersionType>(3413776, VersionType__1_4_0),
    std::pair<StringHash, VersionType>(3413777, VersionType__1_4_1)
};

//---------------------------------------------------------------------
VersionType toEnum_VersionType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<VersionType, StringHash, VersionType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, MorphMethodType> MorphMethodTypeMap[MorphMethodType__COUNT] = 
{
    std::pair<StringHash, MorphMethodType>(23452388, MorphMethodType__NORMALIZED),
    std::pair<StringHash, MorphMethodType>(168201157, MorphMethodType__RELATIVE)
};

//---------------------------------------------------------------------
MorphMethodType toEnum_MorphMethodType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<MorphMethodType, StringHash, MorphMethodType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_sampler_wrap_common> fx_sampler_wrap_commonMap[fx_sampler_wrap_common__COUNT] = 
{
    std::pair<StringHash, fx_sampler_wrap_common>(74737826, fx_sampler_wrap_common__BORDER),
    std::pair<StringHash, fx_sampler_wrap_common>(4720160, fx_sampler_wrap_common__CLAMP),
    std::pair<StringHash, fx_sampler_wrap_common>(85882690, fx_sampler_wrap_common__MIRROR),
    std::pair<StringHash, fx_sampler_wrap_common>(341029, fx_sampler_wrap_common__NONE),
    std::pair<StringHash, fx_sampler_wrap_common>(378464, fx_sampler_wrap_common__WRAP)
};

//---------------------------------------------------------------------
fx_sampler_wrap_common toEnum_fx_sampler_wrap_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_sampler_wrap_common, StringHash, fx_sampler_wrap_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, NodeType> NodeTypeMap[NodeType__COUNT] = 
{
    std::pair<StringHash, NodeType>(5193268, NodeType__JOINT),
    std::pair<StringHash, NodeType>(340869, NodeType__NODE)
};

//---------------------------------------------------------------------
NodeType toEnum_NodeType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<NodeType, StringHash, NodeType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, fx_opaque_enum> fx_opaque_enumMap[fx_opaque_enum__COUNT] = 
{
    std::pair<StringHash, fx_opaque_enum>(4670501, fx_opaque_enum__A_ONE),
    std::pair<StringHash, fx_opaque_enum>(193261327, fx_opaque_enum__RGB_ZERO)
};

//---------------------------------------------------------------------
fx_opaque_enum toEnum_fx_opaque_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<fx_opaque_enum, StringHash, fx_opaque_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


}
