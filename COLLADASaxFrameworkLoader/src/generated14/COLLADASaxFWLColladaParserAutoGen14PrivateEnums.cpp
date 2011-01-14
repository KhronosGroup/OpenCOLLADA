/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLColladaParserAutoGen14Enums.h"
#include "GeneratedSaxParserUtils.h"


namespace COLLADASaxFWL14
{


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__VersionType> ENUM__VersionTypeMap[ENUM__VersionType__COUNT] = 
{
    std::pair<StringHash, ENUM__VersionType>(3413776, ENUM__VersionType__1_4_0),
    std::pair<StringHash, ENUM__VersionType>(3413777, ENUM__VersionType__1_4_1)
};

//---------------------------------------------------------------------
ENUM__VersionType toEnum_ENUM__VersionType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__VersionType, StringHash, ENUM__VersionType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__UpAxisType> ENUM__UpAxisTypeMap[ENUM__UpAxisType__COUNT] = 
{
    std::pair<StringHash, ENUM__UpAxisType>(386208, ENUM__UpAxisType__X_UP),
    std::pair<StringHash, ENUM__UpAxisType>(390304, ENUM__UpAxisType__Y_UP),
    std::pair<StringHash, ENUM__UpAxisType>(394400, ENUM__UpAxisType__Z_UP)
};

//---------------------------------------------------------------------
ENUM__UpAxisType toEnum_ENUM__UpAxisType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__UpAxisType, StringHash, ENUM__UpAxisType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__MorphMethodType> ENUM__MorphMethodTypeMap[ENUM__MorphMethodType__COUNT] = 
{
    std::pair<StringHash, ENUM__MorphMethodType>(23452388, ENUM__MorphMethodType__NORMALIZED),
    std::pair<StringHash, ENUM__MorphMethodType>(168201157, ENUM__MorphMethodType__RELATIVE)
};

//---------------------------------------------------------------------
ENUM__MorphMethodType toEnum_ENUM__MorphMethodType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__MorphMethodType, StringHash, ENUM__MorphMethodType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_modifier_enum_common> ENUM__fx_modifier_enum_commonMap[ENUM__fx_modifier_enum_common__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(4735876, ENUM__fx_modifier_enum_common__CONST),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(78482030, ENUM__fx_modifier_enum_common__EXTERN),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(92038804, ENUM__fx_modifier_enum_common__SHARED),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(92825811, ENUM__fx_modifier_enum_common__STATIC),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(170767421, ENUM__fx_modifier_enum_common__UNIFORM),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(174579319, ENUM__fx_modifier_enum_common__VARYING),
    std::pair<StringHash, ENUM__fx_modifier_enum_common>(67537333, ENUM__fx_modifier_enum_common__VOLATILE)
};

//---------------------------------------------------------------------
ENUM__fx_modifier_enum_common toEnum_ENUM__fx_modifier_enum_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_modifier_enum_common, StringHash, ENUM__fx_modifier_enum_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_type_enum> ENUM__fx_surface_type_enumMap[ENUM__fx_surface_type_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_type_enum>(852, ENUM__fx_surface_type_enum__1D),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(868, ENUM__fx_surface_type_enum__2D),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(884, ENUM__fx_surface_type_enum__3D),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(297317, ENUM__fx_surface_type_enum__CUBE),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(4760968, ENUM__fx_surface_type_enum__DEPTH),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(354692, ENUM__fx_surface_type_enum__RECT),
    std::pair<StringHash, ENUM__fx_surface_type_enum>(171566276, ENUM__fx_surface_type_enum__UNTYPED)
};

//---------------------------------------------------------------------
ENUM__fx_surface_type_enum toEnum_ENUM__fx_surface_type_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_type_enum, StringHash, ENUM__fx_surface_type_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_face_enum> ENUM__fx_surface_face_enumMap[ENUM__fx_surface_face_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_face_enum>(109806840, ENUM__fx_surface_face_enum__NEGATIVE_X),
    std::pair<StringHash, ENUM__fx_surface_face_enum>(109806841, ENUM__fx_surface_face_enum__NEGATIVE_Y),
    std::pair<StringHash, ENUM__fx_surface_face_enum>(109806842, ENUM__fx_surface_face_enum__NEGATIVE_Z),
    std::pair<StringHash, ENUM__fx_surface_face_enum>(244055864, ENUM__fx_surface_face_enum__POSITIVE_X),
    std::pair<StringHash, ENUM__fx_surface_face_enum>(244055865, ENUM__fx_surface_face_enum__POSITIVE_Y),
    std::pair<StringHash, ENUM__fx_surface_face_enum>(244055866, ENUM__fx_surface_face_enum__POSITIVE_Z)
};

//---------------------------------------------------------------------
ENUM__fx_surface_face_enum toEnum_ENUM__fx_surface_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_face_enum, StringHash, ENUM__fx_surface_face_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum> ENUM__fx_surface_format_hint_channels_enumMap[ENUM__fx_surface_format_hint_channels_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(68, ENUM__fx_surface_format_hint_channels_enum__D),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(76, ENUM__fx_surface_format_hint_channels_enum__L),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(1281, ENUM__fx_surface_format_hint_channels_enum__LA),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(22194, ENUM__fx_surface_format_hint_channels_enum__RGB),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(355169, ENUM__fx_surface_format_hint_channels_enum__RGBA),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(24042, ENUM__fx_surface_format_hint_channels_enum__XYZ),
    std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>(384759, ENUM__fx_surface_format_hint_channels_enum__XYZW)
};

//---------------------------------------------------------------------
ENUM__fx_surface_format_hint_channels_enum toEnum_ENUM__fx_surface_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_format_hint_channels_enum, StringHash, ENUM__fx_surface_format_hint_channels_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum> ENUM__fx_surface_format_hint_range_enumMap[ENUM__fx_surface_format_hint_range_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>(4920164, ENUM__fx_surface_format_hint_range_enum__FLOAT),
    std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>(359988, ENUM__fx_surface_format_hint_range_enum__SINT),
    std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>(5780589, ENUM__fx_surface_format_hint_range_enum__SNORM),
    std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>(368180, ENUM__fx_surface_format_hint_range_enum__UINT),
    std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>(5911661, ENUM__fx_surface_format_hint_range_enum__UNORM)
};

//---------------------------------------------------------------------
ENUM__fx_surface_format_hint_range_enum toEnum_ENUM__fx_surface_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_format_hint_range_enum, StringHash, ENUM__fx_surface_format_hint_range_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum> ENUM__fx_surface_format_hint_precision_enumMap[ENUM__fx_surface_format_hint_precision_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>(314808, ENUM__fx_surface_format_hint_precision_enum__HIGH),
    std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>(20807, ENUM__fx_surface_format_hint_precision_enum__LOW),
    std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>(20948, ENUM__fx_surface_format_hint_precision_enum__MID)
};

//---------------------------------------------------------------------
ENUM__fx_surface_format_hint_precision_enum toEnum_ENUM__fx_surface_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_format_hint_precision_enum, StringHash, ENUM__fx_surface_format_hint_precision_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum> ENUM__fx_surface_format_hint_option_enumMap[ENUM__fx_surface_format_hint_option_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>(235107429, ENUM__fx_surface_format_hint_option_enum__COMPRESSABLE),
    std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>(106802787, ENUM__fx_surface_format_hint_option_enum__NORMALIZED3),
    std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>(106802788, ENUM__fx_surface_format_hint_option_enum__NORMALIZED4),
    std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>(138340513, ENUM__fx_surface_format_hint_option_enum__SRGB_GAMMA)
};

//---------------------------------------------------------------------
ENUM__fx_surface_format_hint_option_enum toEnum_ENUM__fx_surface_format_hint_option_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_surface_format_hint_option_enum, StringHash, ENUM__fx_surface_format_hint_option_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_wrap_common> ENUM__fx_sampler_wrap_commonMap[ENUM__fx_sampler_wrap_common__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_wrap_common>(74737826, ENUM__fx_sampler_wrap_common__BORDER),
    std::pair<StringHash, ENUM__fx_sampler_wrap_common>(4720160, ENUM__fx_sampler_wrap_common__CLAMP),
    std::pair<StringHash, ENUM__fx_sampler_wrap_common>(85882690, ENUM__fx_sampler_wrap_common__MIRROR),
    std::pair<StringHash, ENUM__fx_sampler_wrap_common>(341029, ENUM__fx_sampler_wrap_common__NONE),
    std::pair<StringHash, ENUM__fx_sampler_wrap_common>(378464, ENUM__fx_sampler_wrap_common__WRAP)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_wrap_common toEnum_ENUM__fx_sampler_wrap_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_wrap_common, StringHash, ENUM__fx_sampler_wrap_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_filter_common> ENUM__fx_sampler_filter_commonMap[ENUM__fx_sampler_filter_common__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(84814178, ENUM__fx_sampler_filter_common__LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(230972482, ENUM__fx_sampler_filter_common__LINEAR_MIPMAP_LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(242301012, ENUM__fx_sampler_filter_common__LINEAR_MIPMAP_NEAREST),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(43412180, ENUM__fx_sampler_filter_common__NEAREST),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(92529554, ENUM__fx_sampler_filter_common__NEAREST_MIPMAP_LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(174769620, ENUM__fx_sampler_filter_common__NEAREST_MIPMAP_NEAREST),
    std::pair<StringHash, ENUM__fx_sampler_filter_common>(341029, ENUM__fx_sampler_filter_common__NONE)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_filter_common toEnum_ENUM__fx_sampler_filter_common (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_filter_common, StringHash, ENUM__fx_sampler_filter_common__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__NodeType> ENUM__NodeTypeMap[ENUM__NodeType__COUNT] = 
{
    std::pair<StringHash, ENUM__NodeType>(5193268, ENUM__NodeType__JOINT),
    std::pair<StringHash, ENUM__NodeType>(340869, ENUM__NodeType__NODE)
};

//---------------------------------------------------------------------
ENUM__NodeType toEnum_ENUM__NodeType (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__NodeType, StringHash, ENUM__NodeType__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums> ENUM__gles_texcombiner_operatorRGB_enumsMap[ENUM__gles_texcombiner_operatorRGB_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(17796, ENUM__gles_texcombiner_operatorRGB_enums__ADD),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(75102772, ENUM__gles_texcombiner_operatorRGB_enums__ADD_SIGNED),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(75055650, ENUM__gles_texcombiner_operatorRGB_enums__DOT3_RGB),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(127148577, ENUM__gles_texcombiner_operatorRGB_enums__DOT3_RGBA),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(119422501, ENUM__gles_texcombiner_operatorRGB_enums__INTERPOLATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(60425125, ENUM__gles_texcombiner_operatorRGB_enums__MODULATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(111478053, ENUM__gles_texcombiner_operatorRGB_enums__REPLACE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>(158949380, ENUM__gles_texcombiner_operatorRGB_enums__SUBTRACT)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operatorRGB_enums toEnum_ENUM__gles_texcombiner_operatorRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operatorRGB_enums, StringHash, ENUM__gles_texcombiner_operatorRGB_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_source_enums> ENUM__gles_texcombiner_source_enumsMap[ENUM__gles_texcombiner_source_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_source_enums>(70812340, ENUM__gles_texcombiner_source_enums__CONSTANT),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enums>(111862259, ENUM__gles_texcombiner_source_enums__PREVIOUS),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enums>(91100713, ENUM__gles_texcombiner_source_enums__PRIMARY),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enums>(145594933, ENUM__gles_texcombiner_source_enums__TEXTURE)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_source_enums toEnum_ENUM__gles_texcombiner_source_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_source_enums, StringHash, ENUM__gles_texcombiner_source_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums> ENUM__gles_texcombiner_operandRGB_enumsMap[ENUM__gles_texcombiner_operandRGB_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>(11673281, ENUM__gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>(11815746, ENUM__gles_texcombiner_operandRGB_enums__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>(154553505, ENUM__gles_texcombiner_operandRGB_enums__SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>(154695970, ENUM__gles_texcombiner_operandRGB_enums__SRC_COLOR)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operandRGB_enums toEnum_ENUM__gles_texcombiner_operandRGB_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operandRGB_enums, StringHash, ENUM__gles_texcombiner_operandRGB_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums> ENUM__gles_texcombiner_operatorAlpha_enumsMap[ENUM__gles_texcombiner_operatorAlpha_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(17796, ENUM__gles_texcombiner_operatorAlpha_enums__ADD),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(75102772, ENUM__gles_texcombiner_operatorAlpha_enums__ADD_SIGNED),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(119422501, ENUM__gles_texcombiner_operatorAlpha_enums__INTERPOLATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(60425125, ENUM__gles_texcombiner_operatorAlpha_enums__MODULATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(111478053, ENUM__gles_texcombiner_operatorAlpha_enums__REPLACE),
    std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>(158949380, ENUM__gles_texcombiner_operatorAlpha_enums__SUBTRACT)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operatorAlpha_enums toEnum_ENUM__gles_texcombiner_operatorAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operatorAlpha_enums, StringHash, ENUM__gles_texcombiner_operatorAlpha_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums> ENUM__gles_texcombiner_operandAlpha_enumsMap[ENUM__gles_texcombiner_operandAlpha_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>(11673281, ENUM__gles_texcombiner_operandAlpha_enums__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>(154553505, ENUM__gles_texcombiner_operandAlpha_enums__SRC_ALPHA)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operandAlpha_enums toEnum_ENUM__gles_texcombiner_operandAlpha_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operandAlpha_enums, StringHash, ENUM__gles_texcombiner_operandAlpha_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texenv_mode_enums> ENUM__gles_texenv_mode_enumsMap[ENUM__gles_texenv_mode_enums__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texenv_mode_enums>(17796, ENUM__gles_texenv_mode_enums__ADD),
    std::pair<StringHash, ENUM__gles_texenv_mode_enums>(4655652, ENUM__gles_texenv_mode_enums__BLEND),
    std::pair<StringHash, ENUM__gles_texenv_mode_enums>(4757340, ENUM__gles_texenv_mode_enums__DECAL),
    std::pair<StringHash, ENUM__gles_texenv_mode_enums>(60425125, ENUM__gles_texenv_mode_enums__MODULATE),
    std::pair<StringHash, ENUM__gles_texenv_mode_enums>(111478053, ENUM__gles_texenv_mode_enums__REPLACE)
};

//---------------------------------------------------------------------
ENUM__gles_texenv_mode_enums toEnum_ENUM__gles_texenv_mode_enums (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texenv_mode_enums, StringHash, ENUM__gles_texenv_mode_enums__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_sampler_wrap> ENUM__gles_sampler_wrapMap[ENUM__gles_sampler_wrap__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_sampler_wrap>(4720160, ENUM__gles_sampler_wrap__CLAMP),
    std::pair<StringHash, ENUM__gles_sampler_wrap>(22396597, ENUM__gles_sampler_wrap__CLAMP_TO_EDGE),
    std::pair<StringHash, ENUM__gles_sampler_wrap>(52326884, ENUM__gles_sampler_wrap__MIRRORED_REPEAT),
    std::pair<StringHash, ENUM__gles_sampler_wrap>(90851684, ENUM__gles_sampler_wrap__REPEAT)
};

//---------------------------------------------------------------------
ENUM__gles_sampler_wrap toEnum_ENUM__gles_sampler_wrap (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_sampler_wrap, StringHash, ENUM__gles_sampler_wrap__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_blend_type> ENUM__gl_blend_typeMap[ENUM__gl_blend_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_blend_type>(235837041, ENUM__gl_blend_type__CONSTANT_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(235979762, ENUM__gl_blend_type__CONSTANT_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(171232194, ENUM__gl_blend_type__DEST_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(171334977, ENUM__gl_blend_type__DST_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(21541, ENUM__gl_blend_type__ONE),
    std::pair<StringHash, ENUM__gl_blend_type>(58120065, ENUM__gl_blend_type__ONE_MINUS_CONSTANT_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(58262530, ENUM__gl_blend_type__ONE_MINUS_CONSTANT_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(41006258, ENUM__gl_blend_type__ONE_MINUS_DEST_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(263351505, ENUM__gl_blend_type__ONE_MINUS_DST_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(11673281, ENUM__gl_blend_type__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(11815746, ENUM__gl_blend_type__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(154553505, ENUM__gl_blend_type__SRC_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_type>(38887829, ENUM__gl_blend_type__SRC_ALPHA_SATURATE),
    std::pair<StringHash, ENUM__gl_blend_type>(154695970, ENUM__gl_blend_type__SRC_COLOR),
    std::pair<StringHash, ENUM__gl_blend_type>(387695, ENUM__gl_blend_type__ZERO)
};

//---------------------------------------------------------------------
ENUM__gl_blend_type toEnum_ENUM__gl_blend_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_blend_type, StringHash, ENUM__gl_blend_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_face_type> ENUM__gl_face_typeMap[ENUM__gl_face_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_face_type>(288123, ENUM__gl_face_type__BACK),
    std::pair<StringHash, ENUM__gl_face_type>(4944948, ENUM__gl_face_type__FRONT),
    std::pair<StringHash, ENUM__gl_face_type>(98615947, ENUM__gl_face_type__FRONT_AND_BACK)
};

//---------------------------------------------------------------------
ENUM__gl_face_type toEnum_ENUM__gl_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_face_type, StringHash, ENUM__gl_face_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_func_type> ENUM__gl_func_typeMap[ENUM__gl_func_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_func_type>(73512675, ENUM__gl_func_type__ALWAYS),
    std::pair<StringHash, ENUM__gl_func_type>(4876636, ENUM__gl_func_type__EQUAL),
    std::pair<StringHash, ENUM__gl_func_type>(79325532, ENUM__gl_func_type__GEQUAL),
    std::pair<StringHash, ENUM__gl_func_type>(208234722, ENUM__gl_func_type__GREATER),
    std::pair<StringHash, ENUM__gl_func_type>(84568412, ENUM__gl_func_type__LEQUAL),
    std::pair<StringHash, ENUM__gl_func_type>(330371, ENUM__gl_func_type__LESS),
    std::pair<StringHash, ENUM__gl_func_type>(5417634, ENUM__gl_func_type__NEVER),
    std::pair<StringHash, ENUM__gl_func_type>(76180588, ENUM__gl_func_type__NOTEQUAL)
};

//---------------------------------------------------------------------
ENUM__gl_func_type toEnum_ENUM__gl_func_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_func_type, StringHash, ENUM__gl_func_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_stencil_op_type> ENUM__gl_stencil_op_typeMap[ENUM__gl_stencil_op_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_stencil_op_type>(297346, ENUM__gl_stencil_op_type__DECR),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(142905072, ENUM__gl_stencil_op_type__DECR_WRAP),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(320130, ENUM__gl_stencil_op_type__INCR),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(142903360, ENUM__gl_stencil_op_type__INCR_WRAP),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(82029172, ENUM__gl_stencil_op_type__INVERT),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(326048, ENUM__gl_stencil_op_type__KEEP),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(111478053, ENUM__gl_stencil_op_type__REPLACE),
    std::pair<StringHash, ENUM__gl_stencil_op_type>(387695, ENUM__gl_stencil_op_type__ZERO)
};

//---------------------------------------------------------------------
ENUM__gl_stencil_op_type toEnum_ENUM__gl_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_stencil_op_type, StringHash, ENUM__gl_stencil_op_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_material_type> ENUM__gl_material_typeMap[ENUM__gl_material_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_material_type>(102161012, ENUM__gl_material_type__AMBIENT),
    std::pair<StringHash, ENUM__gl_material_type>(150884037, ENUM__gl_material_type__AMBIENT_AND_DIFFUSE),
    std::pair<StringHash, ENUM__gl_material_type>(148552245, ENUM__gl_material_type__DIFFUSE),
    std::pair<StringHash, ENUM__gl_material_type>(32012958, ENUM__gl_material_type__EMISSION),
    std::pair<StringHash, ENUM__gl_material_type>(77112802, ENUM__gl_material_type__SPECULAR)
};

//---------------------------------------------------------------------
ENUM__gl_material_type toEnum_ENUM__gl_material_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_material_type, StringHash, ENUM__gl_material_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_fog_type> ENUM__gl_fog_typeMap[ENUM__gl_fog_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_fog_type>(19152, ENUM__gl_fog_type__EXP),
    std::pair<StringHash, ENUM__gl_fog_type>(306482, ENUM__gl_fog_type__EXP2),
    std::pair<StringHash, ENUM__gl_fog_type>(84814178, ENUM__gl_fog_type__LINEAR)
};

//---------------------------------------------------------------------
ENUM__gl_fog_type toEnum_ENUM__gl_fog_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_fog_type, StringHash, ENUM__gl_fog_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_front_face_type> ENUM__gl_front_face_typeMap[ENUM__gl_front_face_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_front_face_type>(18311, ENUM__gl_front_face_type__CCW),
    std::pair<StringHash, ENUM__gl_front_face_type>(1159, ENUM__gl_front_face_type__CW)
};

//---------------------------------------------------------------------
ENUM__gl_front_face_type toEnum_ENUM__gl_front_face_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_front_face_type, StringHash, ENUM__gl_front_face_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_light_model_color_control_type> ENUM__gl_light_model_color_control_typeMap[ENUM__gl_light_model_color_control_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_light_model_color_control_type>(110211522, ENUM__gl_light_model_color_control_type__SEPARATE_SPECULAR_COLOR),
    std::pair<StringHash, ENUM__gl_light_model_color_control_type>(4861266, ENUM__gl_light_model_color_control_type__SINGLE_COLOR)
};

//---------------------------------------------------------------------
ENUM__gl_light_model_color_control_type toEnum_ENUM__gl_light_model_color_control_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_light_model_color_control_type, StringHash, ENUM__gl_light_model_color_control_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_logic_op_type> ENUM__gl_logic_op_typeMap[ENUM__gl_logic_op_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_logic_op_type>(17956, ENUM__gl_logic_op_type__AND),
    std::pair<StringHash, ENUM__gl_logic_op_type>(130603892, ENUM__gl_logic_op_type__AND_INVERTED),
    std::pair<StringHash, ENUM__gl_logic_op_type>(116165941, ENUM__gl_logic_op_type__AND_REVERSE),
    std::pair<StringHash, ENUM__gl_logic_op_type>(4720994, ENUM__gl_logic_op_type__CLEAR),
    std::pair<StringHash, ENUM__gl_logic_op_type>(296025, ENUM__gl_logic_op_type__COPY),
    std::pair<StringHash, ENUM__gl_logic_op_type>(200248116, ENUM__gl_logic_op_type__COPY_INVERTED),
    std::pair<StringHash, ENUM__gl_logic_op_type>(4876774, ENUM__gl_logic_op_type__EQUIV),
    std::pair<StringHash, ENUM__gl_logic_op_type>(82029172, ENUM__gl_logic_op_type__INVERT),
    std::pair<StringHash, ENUM__gl_logic_op_type>(337444, ENUM__gl_logic_op_type__NAND),
    std::pair<StringHash, ENUM__gl_logic_op_type>(341056, ENUM__gl_logic_op_type__NOOP),
    std::pair<StringHash, ENUM__gl_logic_op_type>(21314, ENUM__gl_logic_op_type__NOR),
    std::pair<StringHash, ENUM__gl_logic_op_type>(1346, ENUM__gl_logic_op_type__OR),
    std::pair<StringHash, ENUM__gl_logic_op_type>(112193333, ENUM__gl_logic_op_type__OR_REVERSE),
    std::pair<StringHash, ENUM__gl_logic_op_type>(22436, ENUM__gl_logic_op_type__SET),
    std::pair<StringHash, ENUM__gl_logic_op_type>(23874, ENUM__gl_logic_op_type__XOR)
};

//---------------------------------------------------------------------
ENUM__gl_logic_op_type toEnum_ENUM__gl_logic_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_logic_op_type, StringHash, ENUM__gl_logic_op_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_polygon_mode_type> ENUM__gl_polygon_mode_typeMap[ENUM__gl_polygon_mode_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_polygon_mode_type>(306700, ENUM__gl_polygon_mode_type__FILL),
    std::pair<StringHash, ENUM__gl_polygon_mode_type>(331301, ENUM__gl_polygon_mode_type__LINE),
    std::pair<StringHash, ENUM__gl_polygon_mode_type>(5586484, ENUM__gl_polygon_mode_type__POINT)
};

//---------------------------------------------------------------------
ENUM__gl_polygon_mode_type toEnum_ENUM__gl_polygon_mode_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_polygon_mode_type, StringHash, ENUM__gl_polygon_mode_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_shade_model_type> ENUM__gl_shade_model_typeMap[ENUM__gl_shade_model_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_shade_model_type>(307300, ENUM__gl_shade_model_type__FLAT),
    std::pair<StringHash, ENUM__gl_shade_model_type>(92423304, ENUM__gl_shade_model_type__SMOOTH)
};

//---------------------------------------------------------------------
ENUM__gl_shade_model_type toEnum_ENUM__gl_shade_model_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_shade_model_type, StringHash, ENUM__gl_shade_model_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar* buffer, size_t length, bool& failed )
{
    UNION__gles_enumeration returnValue;
    const ParserChar* tmpBuf;

    tmpBuf = buffer;
    ENUM__gl_blend_type tmp0 = Utils::toEnum<ENUM__gl_blend_type, StringHash, ENUM__gl_blend_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_BLEND_TYPE;
        returnValue.union_data.GL_BLEND_TYPE = tmp0;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_face_type tmp1 = Utils::toEnum<ENUM__gl_face_type, StringHash, ENUM__gl_face_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_face_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_FACE_TYPE;
        returnValue.union_data.GL_FACE_TYPE = tmp1;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_func_type tmp2 = Utils::toEnum<ENUM__gl_func_type, StringHash, ENUM__gl_func_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_func_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_FUNC_TYPE;
        returnValue.union_data.GL_FUNC_TYPE = tmp2;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_stencil_op_type tmp3 = Utils::toEnum<ENUM__gl_stencil_op_type, StringHash, ENUM__gl_stencil_op_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_stencil_op_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_STENCIL_OP_TYPE;
        returnValue.union_data.GL_STENCIL_OP_TYPE = tmp3;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_material_type tmp4 = Utils::toEnum<ENUM__gl_material_type, StringHash, ENUM__gl_material_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_material_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_MATERIAL_TYPE;
        returnValue.union_data.GL_MATERIAL_TYPE = tmp4;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_type tmp5 = Utils::toEnum<ENUM__gl_fog_type, StringHash, ENUM__gl_fog_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_FOG_TYPE;
        returnValue.union_data.GL_FOG_TYPE = tmp5;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_front_face_type tmp6 = Utils::toEnum<ENUM__gl_front_face_type, StringHash, ENUM__gl_front_face_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_front_face_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_FRONT_FACE_TYPE;
        returnValue.union_data.GL_FRONT_FACE_TYPE = tmp6;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_light_model_color_control_type tmp7 = Utils::toEnum<ENUM__gl_light_model_color_control_type, StringHash, ENUM__gl_light_model_color_control_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_light_model_color_control_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_LIGHT_MODEL_COLOR_CONTROL_TYPE;
        returnValue.union_data.GL_LIGHT_MODEL_COLOR_CONTROL_TYPE = tmp7;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_logic_op_type tmp8 = Utils::toEnum<ENUM__gl_logic_op_type, StringHash, ENUM__gl_logic_op_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_logic_op_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_LOGIC_OP_TYPE;
        returnValue.union_data.GL_LOGIC_OP_TYPE = tmp8;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_polygon_mode_type tmp9 = Utils::toEnum<ENUM__gl_polygon_mode_type, StringHash, ENUM__gl_polygon_mode_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_polygon_mode_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_POLYGON_MODE_TYPE;
        returnValue.union_data.GL_POLYGON_MODE_TYPE = tmp9;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_shade_model_type tmp10 = Utils::toEnum<ENUM__gl_shade_model_type, StringHash, ENUM__gl_shade_model_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_shade_model_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration::GL_SHADE_MODEL_TYPE;
        returnValue.union_data.GL_SHADE_MODEL_TYPE = tmp10;
        return returnValue;
    }


    returnValue.union_type = UNION__gles_enumeration::INVALID;
    return returnValue;
}


//---------------------------------------------------------------------
UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, bufferEnd, failed );
    return toUnion_UNION__gles_enumeration( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
UNION__gles_enumeration toUnion_UNION__gles_enumeration ( const ParserChar** buffer, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, failed );
    return toUnion_UNION__gles_enumeration( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_stencil_op_type> ENUM__gles_stencil_op_typeMap[ENUM__gles_stencil_op_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_stencil_op_type>(297346, ENUM__gles_stencil_op_type__DECR),
    std::pair<StringHash, ENUM__gles_stencil_op_type>(320130, ENUM__gles_stencil_op_type__INCR),
    std::pair<StringHash, ENUM__gles_stencil_op_type>(82029172, ENUM__gles_stencil_op_type__INVERT),
    std::pair<StringHash, ENUM__gles_stencil_op_type>(326048, ENUM__gles_stencil_op_type__KEEP),
    std::pair<StringHash, ENUM__gles_stencil_op_type>(111478053, ENUM__gles_stencil_op_type__REPLACE),
    std::pair<StringHash, ENUM__gles_stencil_op_type>(387695, ENUM__gles_stencil_op_type__ZERO)
};

//---------------------------------------------------------------------
ENUM__gles_stencil_op_type toEnum_ENUM__gles_stencil_op_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_stencil_op_type, StringHash, ENUM__gles_stencil_op_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_blend_equation_type> ENUM__gl_blend_equation_typeMap[ENUM__gl_blend_equation_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_blend_equation_type>(170471732, ENUM__gl_blend_equation_type__FUNC_ADD),
    std::pair<StringHash, ENUM__gl_blend_equation_type>(26931204, ENUM__gl_blend_equation_type__FUNC_REVERSE_SUBTRACT),
    std::pair<StringHash, ENUM__gl_blend_equation_type>(47968580, ENUM__gl_blend_equation_type__FUNC_SUBTRACT),
    std::pair<StringHash, ENUM__gl_blend_equation_type>(20840, ENUM__gl_blend_equation_type__MAX),
    std::pair<StringHash, ENUM__gl_blend_equation_type>(20958, ENUM__gl_blend_equation_type__MIN)
};

//---------------------------------------------------------------------
ENUM__gl_blend_equation_type toEnum_ENUM__gl_blend_equation_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_blend_equation_type, StringHash, ENUM__gl_blend_equation_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_fog_coord_src_type> ENUM__gl_fog_coord_src_typeMap[ENUM__gl_fog_coord_src_type__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_fog_coord_src_type>(90156661, ENUM__gl_fog_coord_src_type__FOG_COORDINATE),
    std::pair<StringHash, ENUM__gl_fog_coord_src_type>(6601496, ENUM__gl_fog_coord_src_type__FRAGMENT_DEPTH)
};

//---------------------------------------------------------------------
ENUM__gl_fog_coord_src_type toEnum_ENUM__gl_fog_coord_src_type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_fog_coord_src_type, StringHash, ENUM__gl_fog_coord_src_type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar* buffer, size_t length, bool& failed )
{
    UNION__gl_enumeration returnValue;
    const ParserChar* tmpBuf;

    tmpBuf = buffer;
    ENUM__gl_blend_type tmp0 = Utils::toEnum<ENUM__gl_blend_type, StringHash, ENUM__gl_blend_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_BLEND_TYPE;
        returnValue.union_data.GL_BLEND_TYPE = tmp0;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_face_type tmp1 = Utils::toEnum<ENUM__gl_face_type, StringHash, ENUM__gl_face_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_face_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_FACE_TYPE;
        returnValue.union_data.GL_FACE_TYPE = tmp1;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_blend_equation_type tmp2 = Utils::toEnum<ENUM__gl_blend_equation_type, StringHash, ENUM__gl_blend_equation_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_equation_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_BLEND_EQUATION_TYPE;
        returnValue.union_data.GL_BLEND_EQUATION_TYPE = tmp2;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_func_type tmp3 = Utils::toEnum<ENUM__gl_func_type, StringHash, ENUM__gl_func_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_func_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_FUNC_TYPE;
        returnValue.union_data.GL_FUNC_TYPE = tmp3;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_stencil_op_type tmp4 = Utils::toEnum<ENUM__gl_stencil_op_type, StringHash, ENUM__gl_stencil_op_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_stencil_op_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_STENCIL_OP_TYPE;
        returnValue.union_data.GL_STENCIL_OP_TYPE = tmp4;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_material_type tmp5 = Utils::toEnum<ENUM__gl_material_type, StringHash, ENUM__gl_material_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_material_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_MATERIAL_TYPE;
        returnValue.union_data.GL_MATERIAL_TYPE = tmp5;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_type tmp6 = Utils::toEnum<ENUM__gl_fog_type, StringHash, ENUM__gl_fog_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_FOG_TYPE;
        returnValue.union_data.GL_FOG_TYPE = tmp6;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_coord_src_type tmp7 = Utils::toEnum<ENUM__gl_fog_coord_src_type, StringHash, ENUM__gl_fog_coord_src_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_coord_src_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_FOG_COORD_SRC_TYPE;
        returnValue.union_data.GL_FOG_COORD_SRC_TYPE = tmp7;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_front_face_type tmp8 = Utils::toEnum<ENUM__gl_front_face_type, StringHash, ENUM__gl_front_face_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_front_face_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_FRONT_FACE_TYPE;
        returnValue.union_data.GL_FRONT_FACE_TYPE = tmp8;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_light_model_color_control_type tmp9 = Utils::toEnum<ENUM__gl_light_model_color_control_type, StringHash, ENUM__gl_light_model_color_control_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_light_model_color_control_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_LIGHT_MODEL_COLOR_CONTROL_TYPE;
        returnValue.union_data.GL_LIGHT_MODEL_COLOR_CONTROL_TYPE = tmp9;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_logic_op_type tmp10 = Utils::toEnum<ENUM__gl_logic_op_type, StringHash, ENUM__gl_logic_op_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_logic_op_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_LOGIC_OP_TYPE;
        returnValue.union_data.GL_LOGIC_OP_TYPE = tmp10;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_polygon_mode_type tmp11 = Utils::toEnum<ENUM__gl_polygon_mode_type, StringHash, ENUM__gl_polygon_mode_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_polygon_mode_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_POLYGON_MODE_TYPE;
        returnValue.union_data.GL_POLYGON_MODE_TYPE = tmp11;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_shade_model_type tmp12 = Utils::toEnum<ENUM__gl_shade_model_type, StringHash, ENUM__gl_shade_model_type__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_shade_model_typeMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration::GL_SHADE_MODEL_TYPE;
        returnValue.union_data.GL_SHADE_MODEL_TYPE = tmp12;
        return returnValue;
    }


    returnValue.union_type = UNION__gl_enumeration::INVALID;
    return returnValue;
}


//---------------------------------------------------------------------
UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, bufferEnd, failed );
    return toUnion_UNION__gl_enumeration( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
UNION__gl_enumeration toUnion_UNION__gl_enumeration ( const ParserChar** buffer, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, failed );
    return toUnion_UNION__gl_enumeration( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__glsl_pipeline_stage> ENUM__glsl_pipeline_stageMap[ENUM__glsl_pipeline_stage__COUNT] = 
{
    std::pair<StringHash, ENUM__glsl_pipeline_stage>(11677357, ENUM__glsl_pipeline_stage__FRAGMENTPROGRAM),
    std::pair<StringHash, ENUM__glsl_pipeline_stage>(265571549, ENUM__glsl_pipeline_stage__VERTEXPROGRAM)
};

//---------------------------------------------------------------------
ENUM__glsl_pipeline_stage toEnum_ENUM__glsl_pipeline_stage (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__glsl_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__glsl_pipeline_stage, StringHash, ENUM__glsl_pipeline_stage__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__cg_pipeline_stage> ENUM__cg_pipeline_stageMap[ENUM__cg_pipeline_stage__COUNT] = 
{
    std::pair<StringHash, ENUM__cg_pipeline_stage>(106700420, ENUM__cg_pipeline_stage__FRAGMENT),
    std::pair<StringHash, ENUM__cg_pipeline_stage>(95058088, ENUM__cg_pipeline_stage__VERTEX)
};

//---------------------------------------------------------------------
ENUM__cg_pipeline_stage toEnum_ENUM__cg_pipeline_stage (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__cg_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__cg_pipeline_stage, StringHash, ENUM__cg_pipeline_stage__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_opaque_enum> ENUM__fx_opaque_enumMap[ENUM__fx_opaque_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_opaque_enum>(4670501, ENUM__fx_opaque_enum__A_ONE),
    std::pair<StringHash, ENUM__fx_opaque_enum>(193261327, ENUM__fx_opaque_enum__RGB_ZERO)
};

//---------------------------------------------------------------------
ENUM__fx_opaque_enum toEnum_ENUM__fx_opaque_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_opaque_enum, StringHash, ENUM__fx_opaque_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}



} // namespace
