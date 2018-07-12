/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASaxFWLStableHeaders.h"
#include "COLLADASaxFWLColladaParserAutoGen15Enums.h"
#include "GeneratedSaxParserUtils.h"


namespace COLLADASaxFWL15
{


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__version_enum> ENUM__version_enumMap[ENUM__version_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__version_enum>(3414032, ENUM__version_enum__1_5_0)
};

//---------------------------------------------------------------------
ENUM__version_enum toEnum_ENUM__version_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__version_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__version_enum, StringHash, ENUM__version_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__altitude_mode_enum> ENUM__altitude_mode_enumMap[ENUM__altitude_mode_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__altitude_mode_enum>(161888981, ENUM__altitude_mode_enum__absolute),
    std::pair<StringHash, ENUM__altitude_mode_enum>(190852820, ENUM__altitude_mode_enum__relativeToGround)
};

//---------------------------------------------------------------------
ENUM__altitude_mode_enum toEnum_ENUM__altitude_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__altitude_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__altitude_mode_enum, StringHash, ENUM__altitude_mode_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__up_axis_enum> ENUM__up_axis_enumMap[ENUM__up_axis_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__up_axis_enum>(386208, ENUM__up_axis_enum__X_UP),
    std::pair<StringHash, ENUM__up_axis_enum>(390304, ENUM__up_axis_enum__Y_UP),
    std::pair<StringHash, ENUM__up_axis_enum>(394400, ENUM__up_axis_enum__Z_UP)
};

//---------------------------------------------------------------------
ENUM__up_axis_enum toEnum_ENUM__up_axis_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__up_axis_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__up_axis_enum, StringHash, ENUM__up_axis_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__sampler_behavior_enum> ENUM__sampler_behavior_enumMap[ENUM__sampler_behavior_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__sampler_behavior_enum>(70812340, ENUM__sampler_behavior_enum__CONSTANT),
    std::pair<StringHash, ENUM__sampler_behavior_enum>(4773893, ENUM__sampler_behavior_enum__CYCLE),
    std::pair<StringHash, ENUM__sampler_behavior_enum>(92683845, ENUM__sampler_behavior_enum__CYCLE_RELATIVE),
    std::pair<StringHash, ENUM__sampler_behavior_enum>(106487540, ENUM__sampler_behavior_enum__GRADIENT),
    std::pair<StringHash, ENUM__sampler_behavior_enum>(132207349, ENUM__sampler_behavior_enum__OSCILLATE),
    std::pair<StringHash, ENUM__sampler_behavior_enum>(144349364, ENUM__sampler_behavior_enum__UNDEFINED)
};

//---------------------------------------------------------------------
ENUM__sampler_behavior_enum toEnum_ENUM__sampler_behavior_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__sampler_behavior_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__sampler_behavior_enum, StringHash, ENUM__sampler_behavior_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__morph_method_enum> ENUM__morph_method_enumMap[ENUM__morph_method_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__morph_method_enum>(23452388, ENUM__morph_method_enum__NORMALIZED),
    std::pair<StringHash, ENUM__morph_method_enum>(168201157, ENUM__morph_method_enum__RELATIVE)
};

//---------------------------------------------------------------------
ENUM__morph_method_enum toEnum_ENUM__morph_method_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__morph_method_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__morph_method_enum, StringHash, ENUM__morph_method_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_modifier_enum> ENUM__fx_modifier_enumMap[ENUM__fx_modifier_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_modifier_enum>(4735876, ENUM__fx_modifier_enum__CONST),
    std::pair<StringHash, ENUM__fx_modifier_enum>(78482030, ENUM__fx_modifier_enum__EXTERN),
    std::pair<StringHash, ENUM__fx_modifier_enum>(92038804, ENUM__fx_modifier_enum__SHARED),
    std::pair<StringHash, ENUM__fx_modifier_enum>(92825811, ENUM__fx_modifier_enum__STATIC),
    std::pair<StringHash, ENUM__fx_modifier_enum>(170767421, ENUM__fx_modifier_enum__UNIFORM),
    std::pair<StringHash, ENUM__fx_modifier_enum>(174579319, ENUM__fx_modifier_enum__VARYING),
    std::pair<StringHash, ENUM__fx_modifier_enum>(67537333, ENUM__fx_modifier_enum__VOLATILE)
};

//---------------------------------------------------------------------
ENUM__fx_modifier_enum toEnum_ENUM__fx_modifier_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_modifier_enum, StringHash, ENUM__fx_modifier_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_wrap_enum> ENUM__fx_sampler_wrap_enumMap[ENUM__fx_sampler_wrap_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_wrap_enum>(74737826, ENUM__fx_sampler_wrap_enum__BORDER),
    std::pair<StringHash, ENUM__fx_sampler_wrap_enum>(4720160, ENUM__fx_sampler_wrap_enum__CLAMP),
    std::pair<StringHash, ENUM__fx_sampler_wrap_enum>(85882690, ENUM__fx_sampler_wrap_enum__MIRROR),
    std::pair<StringHash, ENUM__fx_sampler_wrap_enum>(70509829, ENUM__fx_sampler_wrap_enum__MIRROR_ONCE),
    std::pair<StringHash, ENUM__fx_sampler_wrap_enum>(378464, ENUM__fx_sampler_wrap_enum__WRAP)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_wrap_enum toEnum_ENUM__fx_sampler_wrap_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_wrap_enum, StringHash, ENUM__fx_sampler_wrap_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum> ENUM__fx_sampler_min_filter_enumMap[ENUM__fx_sampler_min_filter_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>(80833107, ENUM__fx_sampler_min_filter_enum__ANISOTROPIC),
    std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>(84814178, ENUM__fx_sampler_min_filter_enum__LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>(43412180, ENUM__fx_sampler_min_filter_enum__NEAREST)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_min_filter_enum toEnum_ENUM__fx_sampler_min_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_min_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_min_filter_enum, StringHash, ENUM__fx_sampler_min_filter_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum> ENUM__fx_sampler_mag_filter_enumMap[ENUM__fx_sampler_mag_filter_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>(84814178, ENUM__fx_sampler_mag_filter_enum__LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>(43412180, ENUM__fx_sampler_mag_filter_enum__NEAREST)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_mag_filter_enum toEnum_ENUM__fx_sampler_mag_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mag_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_mag_filter_enum, StringHash, ENUM__fx_sampler_mag_filter_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum> ENUM__fx_sampler_mip_filter_enumMap[ENUM__fx_sampler_mip_filter_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>(84814178, ENUM__fx_sampler_mip_filter_enum__LINEAR),
    std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>(43412180, ENUM__fx_sampler_mip_filter_enum__NEAREST),
    std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>(341029, ENUM__fx_sampler_mip_filter_enum__NONE)
};

//---------------------------------------------------------------------
ENUM__fx_sampler_mip_filter_enum toEnum_ENUM__fx_sampler_mip_filter_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_mip_filter_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_sampler_mip_filter_enum, StringHash, ENUM__fx_sampler_mip_filter_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_opaque_enum> ENUM__fx_opaque_enumMap[ENUM__fx_opaque_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_opaque_enum>(4670501, ENUM__fx_opaque_enum__A_ONE),
    std::pair<StringHash, ENUM__fx_opaque_enum>(74771055, ENUM__fx_opaque_enum__A_ZERO),
    std::pair<StringHash, ENUM__fx_opaque_enum>(112739445, ENUM__fx_opaque_enum__RGB_ONE),
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


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_blend_enum> ENUM__gl_blend_enumMap[ENUM__gl_blend_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_blend_enum>(235837041, ENUM__gl_blend_enum__CONSTANT_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(235979762, ENUM__gl_blend_enum__CONSTANT_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(171232194, ENUM__gl_blend_enum__DEST_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(171334977, ENUM__gl_blend_enum__DST_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(21541, ENUM__gl_blend_enum__ONE),
    std::pair<StringHash, ENUM__gl_blend_enum>(58120065, ENUM__gl_blend_enum__ONE_MINUS_CONSTANT_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(58262530, ENUM__gl_blend_enum__ONE_MINUS_CONSTANT_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(41006258, ENUM__gl_blend_enum__ONE_MINUS_DEST_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(263351505, ENUM__gl_blend_enum__ONE_MINUS_DST_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(11673281, ENUM__gl_blend_enum__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(11815746, ENUM__gl_blend_enum__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(154553505, ENUM__gl_blend_enum__SRC_ALPHA),
    std::pair<StringHash, ENUM__gl_blend_enum>(38887829, ENUM__gl_blend_enum__SRC_ALPHA_SATURATE),
    std::pair<StringHash, ENUM__gl_blend_enum>(154695970, ENUM__gl_blend_enum__SRC_COLOR),
    std::pair<StringHash, ENUM__gl_blend_enum>(387695, ENUM__gl_blend_enum__ZERO)
};

//---------------------------------------------------------------------
ENUM__gl_blend_enum toEnum_ENUM__gl_blend_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_blend_enum, StringHash, ENUM__gl_blend_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_face_enum> ENUM__gl_face_enumMap[ENUM__gl_face_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_face_enum>(288123, ENUM__gl_face_enum__BACK),
    std::pair<StringHash, ENUM__gl_face_enum>(4944948, ENUM__gl_face_enum__FRONT),
    std::pair<StringHash, ENUM__gl_face_enum>(98615947, ENUM__gl_face_enum__FRONT_AND_BACK)
};

//---------------------------------------------------------------------
ENUM__gl_face_enum toEnum_ENUM__gl_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_face_enum, StringHash, ENUM__gl_face_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_blend_equation_enum> ENUM__gl_blend_equation_enumMap[ENUM__gl_blend_equation_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_blend_equation_enum>(170471732, ENUM__gl_blend_equation_enum__FUNC_ADD),
    std::pair<StringHash, ENUM__gl_blend_equation_enum>(26931204, ENUM__gl_blend_equation_enum__FUNC_REVERSE_SUBTRACT),
    std::pair<StringHash, ENUM__gl_blend_equation_enum>(47968580, ENUM__gl_blend_equation_enum__FUNC_SUBTRACT),
    std::pair<StringHash, ENUM__gl_blend_equation_enum>(20840, ENUM__gl_blend_equation_enum__MAX),
    std::pair<StringHash, ENUM__gl_blend_equation_enum>(20958, ENUM__gl_blend_equation_enum__MIN)
};

//---------------------------------------------------------------------
ENUM__gl_blend_equation_enum toEnum_ENUM__gl_blend_equation_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_blend_equation_enum, StringHash, ENUM__gl_blend_equation_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_func_enum> ENUM__gl_func_enumMap[ENUM__gl_func_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_func_enum>(73512675, ENUM__gl_func_enum__ALWAYS),
    std::pair<StringHash, ENUM__gl_func_enum>(4876636, ENUM__gl_func_enum__EQUAL),
    std::pair<StringHash, ENUM__gl_func_enum>(79325532, ENUM__gl_func_enum__GEQUAL),
    std::pair<StringHash, ENUM__gl_func_enum>(208234722, ENUM__gl_func_enum__GREATER),
    std::pair<StringHash, ENUM__gl_func_enum>(84568412, ENUM__gl_func_enum__LEQUAL),
    std::pair<StringHash, ENUM__gl_func_enum>(330371, ENUM__gl_func_enum__LESS),
    std::pair<StringHash, ENUM__gl_func_enum>(5417634, ENUM__gl_func_enum__NEVER),
    std::pair<StringHash, ENUM__gl_func_enum>(76180588, ENUM__gl_func_enum__NOTEQUAL)
};

//---------------------------------------------------------------------
ENUM__gl_func_enum toEnum_ENUM__gl_func_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_func_enum, StringHash, ENUM__gl_func_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_stencil_op_enum> ENUM__gl_stencil_op_enumMap[ENUM__gl_stencil_op_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(297346, ENUM__gl_stencil_op_enum__DECR),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(142905072, ENUM__gl_stencil_op_enum__DECR_WRAP),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(320130, ENUM__gl_stencil_op_enum__INCR),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(142903360, ENUM__gl_stencil_op_enum__INCR_WRAP),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(82029172, ENUM__gl_stencil_op_enum__INVERT),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(326048, ENUM__gl_stencil_op_enum__KEEP),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(111478053, ENUM__gl_stencil_op_enum__REPLACE),
    std::pair<StringHash, ENUM__gl_stencil_op_enum>(387695, ENUM__gl_stencil_op_enum__ZERO)
};

//---------------------------------------------------------------------
ENUM__gl_stencil_op_enum toEnum_ENUM__gl_stencil_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_stencil_op_enum, StringHash, ENUM__gl_stencil_op_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_material_enum> ENUM__gl_material_enumMap[ENUM__gl_material_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_material_enum>(102161012, ENUM__gl_material_enum__AMBIENT),
    std::pair<StringHash, ENUM__gl_material_enum>(150884037, ENUM__gl_material_enum__AMBIENT_AND_DIFFUSE),
    std::pair<StringHash, ENUM__gl_material_enum>(148552245, ENUM__gl_material_enum__DIFFUSE),
    std::pair<StringHash, ENUM__gl_material_enum>(32012958, ENUM__gl_material_enum__EMISSION),
    std::pair<StringHash, ENUM__gl_material_enum>(77112802, ENUM__gl_material_enum__SPECULAR)
};

//---------------------------------------------------------------------
ENUM__gl_material_enum toEnum_ENUM__gl_material_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_material_enum, StringHash, ENUM__gl_material_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_fog_enum> ENUM__gl_fog_enumMap[ENUM__gl_fog_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_fog_enum>(19152, ENUM__gl_fog_enum__EXP),
    std::pair<StringHash, ENUM__gl_fog_enum>(306482, ENUM__gl_fog_enum__EXP2),
    std::pair<StringHash, ENUM__gl_fog_enum>(84814178, ENUM__gl_fog_enum__LINEAR)
};

//---------------------------------------------------------------------
ENUM__gl_fog_enum toEnum_ENUM__gl_fog_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_fog_enum, StringHash, ENUM__gl_fog_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_fog_coord_src_enum> ENUM__gl_fog_coord_src_enumMap[ENUM__gl_fog_coord_src_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_fog_coord_src_enum>(90156661, ENUM__gl_fog_coord_src_enum__FOG_COORDINATE),
    std::pair<StringHash, ENUM__gl_fog_coord_src_enum>(6601496, ENUM__gl_fog_coord_src_enum__FRAGMENT_DEPTH)
};

//---------------------------------------------------------------------
ENUM__gl_fog_coord_src_enum toEnum_ENUM__gl_fog_coord_src_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_fog_coord_src_enum, StringHash, ENUM__gl_fog_coord_src_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_front_face_enum> ENUM__gl_front_face_enumMap[ENUM__gl_front_face_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_front_face_enum>(18311, ENUM__gl_front_face_enum__CCW),
    std::pair<StringHash, ENUM__gl_front_face_enum>(1159, ENUM__gl_front_face_enum__CW)
};

//---------------------------------------------------------------------
ENUM__gl_front_face_enum toEnum_ENUM__gl_front_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_front_face_enum, StringHash, ENUM__gl_front_face_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_light_model_color_control_enum> ENUM__gl_light_model_color_control_enumMap[ENUM__gl_light_model_color_control_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_light_model_color_control_enum>(110211522, ENUM__gl_light_model_color_control_enum__SEPARATE_SPECULAR_COLOR),
    std::pair<StringHash, ENUM__gl_light_model_color_control_enum>(4861266, ENUM__gl_light_model_color_control_enum__SINGLE_COLOR)
};

//---------------------------------------------------------------------
ENUM__gl_light_model_color_control_enum toEnum_ENUM__gl_light_model_color_control_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_light_model_color_control_enum, StringHash, ENUM__gl_light_model_color_control_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_logic_op_enum> ENUM__gl_logic_op_enumMap[ENUM__gl_logic_op_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_logic_op_enum>(17956, ENUM__gl_logic_op_enum__AND),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(130603892, ENUM__gl_logic_op_enum__AND_INVERTED),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(116165941, ENUM__gl_logic_op_enum__AND_REVERSE),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(4720994, ENUM__gl_logic_op_enum__CLEAR),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(296025, ENUM__gl_logic_op_enum__COPY),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(200248116, ENUM__gl_logic_op_enum__COPY_INVERTED),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(4876774, ENUM__gl_logic_op_enum__EQUIV),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(82029172, ENUM__gl_logic_op_enum__INVERT),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(337444, ENUM__gl_logic_op_enum__NAND),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(341056, ENUM__gl_logic_op_enum__NOOP),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(21314, ENUM__gl_logic_op_enum__NOR),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(1346, ENUM__gl_logic_op_enum__OR),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(112193333, ENUM__gl_logic_op_enum__OR_REVERSE),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(22436, ENUM__gl_logic_op_enum__SET),
    std::pair<StringHash, ENUM__gl_logic_op_enum>(23874, ENUM__gl_logic_op_enum__XOR)
};

//---------------------------------------------------------------------
ENUM__gl_logic_op_enum toEnum_ENUM__gl_logic_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_logic_op_enum, StringHash, ENUM__gl_logic_op_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_polygon_mode_enum> ENUM__gl_polygon_mode_enumMap[ENUM__gl_polygon_mode_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_polygon_mode_enum>(306700, ENUM__gl_polygon_mode_enum__FILL),
    std::pair<StringHash, ENUM__gl_polygon_mode_enum>(331301, ENUM__gl_polygon_mode_enum__LINE),
    std::pair<StringHash, ENUM__gl_polygon_mode_enum>(5586484, ENUM__gl_polygon_mode_enum__POINT)
};

//---------------------------------------------------------------------
ENUM__gl_polygon_mode_enum toEnum_ENUM__gl_polygon_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_polygon_mode_enum, StringHash, ENUM__gl_polygon_mode_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gl_shade_model_enum> ENUM__gl_shade_model_enumMap[ENUM__gl_shade_model_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gl_shade_model_enum>(307300, ENUM__gl_shade_model_enum__FLAT),
    std::pair<StringHash, ENUM__gl_shade_model_enum>(92423304, ENUM__gl_shade_model_enum__SMOOTH)
};

//---------------------------------------------------------------------
ENUM__gl_shade_model_enum toEnum_ENUM__gl_shade_model_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gl_shade_model_enum, StringHash, ENUM__gl_shade_model_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar* buffer, size_t length, bool& failed )
{
    UNION__gl_enumeration_type returnValue;
    const ParserChar* tmpBuf;

    tmpBuf = buffer;
    ENUM__gl_blend_enum tmp0 = Utils::toEnum<ENUM__gl_blend_enum, StringHash, ENUM__gl_blend_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_BLEND_ENUM;
        returnValue.union_data.GL_BLEND_ENUM = tmp0;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_face_enum tmp1 = Utils::toEnum<ENUM__gl_face_enum, StringHash, ENUM__gl_face_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_face_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_FACE_ENUM;
        returnValue.union_data.GL_FACE_ENUM = tmp1;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_blend_equation_enum tmp2 = Utils::toEnum<ENUM__gl_blend_equation_enum, StringHash, ENUM__gl_blend_equation_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_equation_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_BLEND_EQUATION_ENUM;
        returnValue.union_data.GL_BLEND_EQUATION_ENUM = tmp2;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_func_enum tmp3 = Utils::toEnum<ENUM__gl_func_enum, StringHash, ENUM__gl_func_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_func_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_FUNC_ENUM;
        returnValue.union_data.GL_FUNC_ENUM = tmp3;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_stencil_op_enum tmp4 = Utils::toEnum<ENUM__gl_stencil_op_enum, StringHash, ENUM__gl_stencil_op_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_stencil_op_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_STENCIL_OP_ENUM;
        returnValue.union_data.GL_STENCIL_OP_ENUM = tmp4;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_material_enum tmp5 = Utils::toEnum<ENUM__gl_material_enum, StringHash, ENUM__gl_material_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_material_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_MATERIAL_ENUM;
        returnValue.union_data.GL_MATERIAL_ENUM = tmp5;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_enum tmp6 = Utils::toEnum<ENUM__gl_fog_enum, StringHash, ENUM__gl_fog_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_FOG_ENUM;
        returnValue.union_data.GL_FOG_ENUM = tmp6;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_coord_src_enum tmp7 = Utils::toEnum<ENUM__gl_fog_coord_src_enum, StringHash, ENUM__gl_fog_coord_src_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_coord_src_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_FOG_COORD_SRC_ENUM;
        returnValue.union_data.GL_FOG_COORD_SRC_ENUM = tmp7;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_front_face_enum tmp8 = Utils::toEnum<ENUM__gl_front_face_enum, StringHash, ENUM__gl_front_face_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_front_face_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_FRONT_FACE_ENUM;
        returnValue.union_data.GL_FRONT_FACE_ENUM = tmp8;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_light_model_color_control_enum tmp9 = Utils::toEnum<ENUM__gl_light_model_color_control_enum, StringHash, ENUM__gl_light_model_color_control_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_light_model_color_control_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_LIGHT_MODEL_COLOR_CONTROL_ENUM;
        returnValue.union_data.GL_LIGHT_MODEL_COLOR_CONTROL_ENUM = tmp9;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_logic_op_enum tmp10 = Utils::toEnum<ENUM__gl_logic_op_enum, StringHash, ENUM__gl_logic_op_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_logic_op_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_LOGIC_OP_ENUM;
        returnValue.union_data.GL_LOGIC_OP_ENUM = tmp10;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_polygon_mode_enum tmp11 = Utils::toEnum<ENUM__gl_polygon_mode_enum, StringHash, ENUM__gl_polygon_mode_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_polygon_mode_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_POLYGON_MODE_ENUM;
        returnValue.union_data.GL_POLYGON_MODE_ENUM = tmp11;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_shade_model_enum tmp12 = Utils::toEnum<ENUM__gl_shade_model_enum, StringHash, ENUM__gl_shade_model_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_shade_model_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gl_enumeration_type::GL_SHADE_MODEL_ENUM;
        returnValue.union_data.GL_SHADE_MODEL_ENUM = tmp12;
        return returnValue;
    }


    returnValue.union_type = UNION__gl_enumeration_type::INVALID;
    return returnValue;
}


//---------------------------------------------------------------------
UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, bufferEnd, failed );
    return toUnion_UNION__gl_enumeration_type( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
UNION__gl_enumeration_type toUnion_UNION__gl_enumeration_type ( const ParserChar** buffer, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, failed );
    return toUnion_UNION__gl_enumeration_type( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__fx_pipeline_stage_enum> ENUM__fx_pipeline_stage_enumMap[ENUM__fx_pipeline_stage_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__fx_pipeline_stage_enum>(106700420, ENUM__fx_pipeline_stage_enum__FRAGMENT),
    std::pair<StringHash, ENUM__fx_pipeline_stage_enum>(172076489, ENUM__fx_pipeline_stage_enum__GEOMETRY),
    std::pair<StringHash, ENUM__fx_pipeline_stage_enum>(109841310, ENUM__fx_pipeline_stage_enum__TESSELLATION),
    std::pair<StringHash, ENUM__fx_pipeline_stage_enum>(95058088, ENUM__fx_pipeline_stage_enum__VERTEX)
};

//---------------------------------------------------------------------
ENUM__fx_pipeline_stage_enum toEnum_ENUM__fx_pipeline_stage_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_pipeline_stage_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__fx_pipeline_stage_enum, StringHash, ENUM__fx_pipeline_stage_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__image_face_enum> ENUM__image_face_enumMap[ENUM__image_face_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__image_face_enum>(109806840, ENUM__image_face_enum__NEGATIVE_X),
    std::pair<StringHash, ENUM__image_face_enum>(109806841, ENUM__image_face_enum__NEGATIVE_Y),
    std::pair<StringHash, ENUM__image_face_enum>(109806842, ENUM__image_face_enum__NEGATIVE_Z),
    std::pair<StringHash, ENUM__image_face_enum>(244055864, ENUM__image_face_enum__POSITIVE_X),
    std::pair<StringHash, ENUM__image_face_enum>(244055865, ENUM__image_face_enum__POSITIVE_Y),
    std::pair<StringHash, ENUM__image_face_enum>(244055866, ENUM__image_face_enum__POSITIVE_Z)
};

//---------------------------------------------------------------------
ENUM__image_face_enum toEnum_ENUM__image_face_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__image_face_enum, StringHash, ENUM__image_face_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_sampler_wrap_enum> ENUM__gles_sampler_wrap_enumMap[ENUM__gles_sampler_wrap_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_sampler_wrap_enum>(4720160, ENUM__gles_sampler_wrap_enum__CLAMP),
    std::pair<StringHash, ENUM__gles_sampler_wrap_enum>(22396597, ENUM__gles_sampler_wrap_enum__CLAMP_TO_EDGE),
    std::pair<StringHash, ENUM__gles_sampler_wrap_enum>(52326884, ENUM__gles_sampler_wrap_enum__MIRRORED_REPEAT),
    std::pair<StringHash, ENUM__gles_sampler_wrap_enum>(90851684, ENUM__gles_sampler_wrap_enum__REPEAT)
};

//---------------------------------------------------------------------
ENUM__gles_sampler_wrap_enum toEnum_ENUM__gles_sampler_wrap_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_sampler_wrap_enum, StringHash, ENUM__gles_sampler_wrap_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar* buffer, size_t length, bool& failed )
{
    UNION__gles_enumeration_type returnValue;
    const ParserChar* tmpBuf;

    tmpBuf = buffer;
    ENUM__gl_blend_enum tmp0 = Utils::toEnum<ENUM__gl_blend_enum, StringHash, ENUM__gl_blend_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_blend_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_BLEND_ENUM;
        returnValue.union_data.GL_BLEND_ENUM = tmp0;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_face_enum tmp1 = Utils::toEnum<ENUM__gl_face_enum, StringHash, ENUM__gl_face_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_face_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_FACE_ENUM;
        returnValue.union_data.GL_FACE_ENUM = tmp1;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_func_enum tmp2 = Utils::toEnum<ENUM__gl_func_enum, StringHash, ENUM__gl_func_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_func_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_FUNC_ENUM;
        returnValue.union_data.GL_FUNC_ENUM = tmp2;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_stencil_op_enum tmp3 = Utils::toEnum<ENUM__gl_stencil_op_enum, StringHash, ENUM__gl_stencil_op_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_stencil_op_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_STENCIL_OP_ENUM;
        returnValue.union_data.GL_STENCIL_OP_ENUM = tmp3;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_material_enum tmp4 = Utils::toEnum<ENUM__gl_material_enum, StringHash, ENUM__gl_material_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_material_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_MATERIAL_ENUM;
        returnValue.union_data.GL_MATERIAL_ENUM = tmp4;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_fog_enum tmp5 = Utils::toEnum<ENUM__gl_fog_enum, StringHash, ENUM__gl_fog_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_fog_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_FOG_ENUM;
        returnValue.union_data.GL_FOG_ENUM = tmp5;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_front_face_enum tmp6 = Utils::toEnum<ENUM__gl_front_face_enum, StringHash, ENUM__gl_front_face_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_front_face_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_FRONT_FACE_ENUM;
        returnValue.union_data.GL_FRONT_FACE_ENUM = tmp6;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_light_model_color_control_enum tmp7 = Utils::toEnum<ENUM__gl_light_model_color_control_enum, StringHash, ENUM__gl_light_model_color_control_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_light_model_color_control_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_LIGHT_MODEL_COLOR_CONTROL_ENUM;
        returnValue.union_data.GL_LIGHT_MODEL_COLOR_CONTROL_ENUM = tmp7;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_logic_op_enum tmp8 = Utils::toEnum<ENUM__gl_logic_op_enum, StringHash, ENUM__gl_logic_op_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_logic_op_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_LOGIC_OP_ENUM;
        returnValue.union_data.GL_LOGIC_OP_ENUM = tmp8;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_polygon_mode_enum tmp9 = Utils::toEnum<ENUM__gl_polygon_mode_enum, StringHash, ENUM__gl_polygon_mode_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_polygon_mode_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_POLYGON_MODE_ENUM;
        returnValue.union_data.GL_POLYGON_MODE_ENUM = tmp9;
        return returnValue;
    }

    tmpBuf = buffer;
    ENUM__gl_shade_model_enum tmp10 = Utils::toEnum<ENUM__gl_shade_model_enum, StringHash, ENUM__gl_shade_model_enum__COUNT>( (const ParserChar**)&tmpBuf, (const ParserChar*)(buffer+length), failed, ENUM__gl_shade_model_enumMap, Utils::calculateStringHash );
    if( !failed )
    {
        returnValue.union_type = UNION__gles_enumeration_type::GL_SHADE_MODEL_ENUM;
        returnValue.union_data.GL_SHADE_MODEL_ENUM = tmp10;
        return returnValue;
    }


    returnValue.union_type = UNION__gles_enumeration_type::INVALID;
    return returnValue;
}


//---------------------------------------------------------------------
UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar** buffer, const ParserChar* bufferEnd, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, bufferEnd, failed );
    return toUnion_UNION__gles_enumeration_type( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
UNION__gles_enumeration_type toUnion_UNION__gles_enumeration_type ( const ParserChar** buffer, bool& failed )
{
    ParserString tmp = Utils::toStringListItem( buffer, failed );
    return toUnion_UNION__gles_enumeration_type( tmp.str, tmp.length, failed );
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_stencil_op_enum> ENUM__gles_stencil_op_enumMap[ENUM__gles_stencil_op_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(297346, ENUM__gles_stencil_op_enum__DECR),
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(320130, ENUM__gles_stencil_op_enum__INCR),
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(82029172, ENUM__gles_stencil_op_enum__INVERT),
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(326048, ENUM__gles_stencil_op_enum__KEEP),
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(111478053, ENUM__gles_stencil_op_enum__REPLACE),
    std::pair<StringHash, ENUM__gles_stencil_op_enum>(387695, ENUM__gles_stencil_op_enum__ZERO)
};

//---------------------------------------------------------------------
ENUM__gles_stencil_op_enum toEnum_ENUM__gles_stencil_op_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_stencil_op_enum, StringHash, ENUM__gles_stencil_op_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum> ENUM__gles_texcombiner_operator_rgb_enumMap[ENUM__gles_texcombiner_operator_rgb_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(17796, ENUM__gles_texcombiner_operator_rgb_enum__ADD),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(75102772, ENUM__gles_texcombiner_operator_rgb_enum__ADD_SIGNED),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(75055650, ENUM__gles_texcombiner_operator_rgb_enum__DOT3_RGB),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(127148577, ENUM__gles_texcombiner_operator_rgb_enum__DOT3_RGBA),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(119422501, ENUM__gles_texcombiner_operator_rgb_enum__INTERPOLATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(60425125, ENUM__gles_texcombiner_operator_rgb_enum__MODULATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(111478053, ENUM__gles_texcombiner_operator_rgb_enum__REPLACE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>(158949380, ENUM__gles_texcombiner_operator_rgb_enum__SUBTRACT)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operator_rgb_enum toEnum_ENUM__gles_texcombiner_operator_rgb_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operator_rgb_enum, StringHash, ENUM__gles_texcombiner_operator_rgb_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_source_enum> ENUM__gles_texcombiner_source_enumMap[ENUM__gles_texcombiner_source_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_source_enum>(70812340, ENUM__gles_texcombiner_source_enum__CONSTANT),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enum>(111862259, ENUM__gles_texcombiner_source_enum__PREVIOUS),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enum>(91100713, ENUM__gles_texcombiner_source_enum__PRIMARY),
    std::pair<StringHash, ENUM__gles_texcombiner_source_enum>(145594933, ENUM__gles_texcombiner_source_enum__TEXTURE)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_source_enum toEnum_ENUM__gles_texcombiner_source_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_source_enum, StringHash, ENUM__gles_texcombiner_source_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum> ENUM__gles_texcombiner_operand_rgb_enumMap[ENUM__gles_texcombiner_operand_rgb_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>(11673281, ENUM__gles_texcombiner_operand_rgb_enum__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>(11815746, ENUM__gles_texcombiner_operand_rgb_enum__ONE_MINUS_SRC_COLOR),
    std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>(154553505, ENUM__gles_texcombiner_operand_rgb_enum__SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>(154695970, ENUM__gles_texcombiner_operand_rgb_enum__SRC_COLOR)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operand_rgb_enum toEnum_ENUM__gles_texcombiner_operand_rgb_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_rgb_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operand_rgb_enum, StringHash, ENUM__gles_texcombiner_operand_rgb_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum> ENUM__gles_texcombiner_operator_alpha_enumMap[ENUM__gles_texcombiner_operator_alpha_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(17796, ENUM__gles_texcombiner_operator_alpha_enum__ADD),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(75102772, ENUM__gles_texcombiner_operator_alpha_enum__ADD_SIGNED),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(119422501, ENUM__gles_texcombiner_operator_alpha_enum__INTERPOLATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(60425125, ENUM__gles_texcombiner_operator_alpha_enum__MODULATE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(111478053, ENUM__gles_texcombiner_operator_alpha_enum__REPLACE),
    std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>(158949380, ENUM__gles_texcombiner_operator_alpha_enum__SUBTRACT)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operator_alpha_enum toEnum_ENUM__gles_texcombiner_operator_alpha_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operator_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operator_alpha_enum, StringHash, ENUM__gles_texcombiner_operator_alpha_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum> ENUM__gles_texcombiner_operand_alpha_enumMap[ENUM__gles_texcombiner_operand_alpha_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>(11673281, ENUM__gles_texcombiner_operand_alpha_enum__ONE_MINUS_SRC_ALPHA),
    std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>(154553505, ENUM__gles_texcombiner_operand_alpha_enum__SRC_ALPHA)
};

//---------------------------------------------------------------------
ENUM__gles_texcombiner_operand_alpha_enum toEnum_ENUM__gles_texcombiner_operand_alpha_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operand_alpha_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texcombiner_operand_alpha_enum, StringHash, ENUM__gles_texcombiner_operand_alpha_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__gles_texenv_mode_enum> ENUM__gles_texenv_mode_enumMap[ENUM__gles_texenv_mode_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__gles_texenv_mode_enum>(17796, ENUM__gles_texenv_mode_enum__ADD),
    std::pair<StringHash, ENUM__gles_texenv_mode_enum>(4655652, ENUM__gles_texenv_mode_enum__BLEND),
    std::pair<StringHash, ENUM__gles_texenv_mode_enum>(4757340, ENUM__gles_texenv_mode_enum__DECAL),
    std::pair<StringHash, ENUM__gles_texenv_mode_enum>(60425125, ENUM__gles_texenv_mode_enum__MODULATE),
    std::pair<StringHash, ENUM__gles_texenv_mode_enum>(111478053, ENUM__gles_texenv_mode_enum__REPLACE)
};

//---------------------------------------------------------------------
ENUM__gles_texenv_mode_enum toEnum_ENUM__gles_texenv_mode_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__gles_texenv_mode_enum, StringHash, ENUM__gles_texenv_mode_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__image_format_hint_channels_enum> ENUM__image_format_hint_channels_enumMap[ENUM__image_format_hint_channels_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(68, ENUM__image_format_hint_channels_enum__D),
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(76, ENUM__image_format_hint_channels_enum__L),
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(1281, ENUM__image_format_hint_channels_enum__LA),
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(22194, ENUM__image_format_hint_channels_enum__RGB),
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(355169, ENUM__image_format_hint_channels_enum__RGBA),
    std::pair<StringHash, ENUM__image_format_hint_channels_enum>(355173, ENUM__image_format_hint_channels_enum__RGBE)
};

//---------------------------------------------------------------------
ENUM__image_format_hint_channels_enum toEnum_ENUM__image_format_hint_channels_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__image_format_hint_channels_enum, StringHash, ENUM__image_format_hint_channels_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__image_format_hint_range_enum> ENUM__image_format_hint_range_enumMap[ENUM__image_format_hint_range_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__image_format_hint_range_enum>(4920164, ENUM__image_format_hint_range_enum__FLOAT),
    std::pair<StringHash, ENUM__image_format_hint_range_enum>(359988, ENUM__image_format_hint_range_enum__SINT),
    std::pair<StringHash, ENUM__image_format_hint_range_enum>(5780589, ENUM__image_format_hint_range_enum__SNORM),
    std::pair<StringHash, ENUM__image_format_hint_range_enum>(368180, ENUM__image_format_hint_range_enum__UINT),
    std::pair<StringHash, ENUM__image_format_hint_range_enum>(5911661, ENUM__image_format_hint_range_enum__UNORM)
};

//---------------------------------------------------------------------
ENUM__image_format_hint_range_enum toEnum_ENUM__image_format_hint_range_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__image_format_hint_range_enum, StringHash, ENUM__image_format_hint_range_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__image_format_hint_precision_enum> ENUM__image_format_hint_precision_enumMap[ENUM__image_format_hint_precision_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__image_format_hint_precision_enum>(144337492, ENUM__image_format_hint_precision_enum__DEFAULT),
    std::pair<StringHash, ENUM__image_format_hint_precision_enum>(314808, ENUM__image_format_hint_precision_enum__HIGH),
    std::pair<StringHash, ENUM__image_format_hint_precision_enum>(20807, ENUM__image_format_hint_precision_enum__LOW),
    std::pair<StringHash, ENUM__image_format_hint_precision_enum>(20840, ENUM__image_format_hint_precision_enum__MAX),
    std::pair<StringHash, ENUM__image_format_hint_precision_enum>(20948, ENUM__image_format_hint_precision_enum__MID)
};

//---------------------------------------------------------------------
ENUM__image_format_hint_precision_enum toEnum_ENUM__image_format_hint_precision_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__image_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__image_format_hint_precision_enum, StringHash, ENUM__image_format_hint_precision_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__node_enum> ENUM__node_enumMap[ENUM__node_enum__COUNT] = 
{
    std::pair<StringHash, ENUM__node_enum>(5193268, ENUM__node_enum__JOINT),
    std::pair<StringHash, ENUM__node_enum>(340869, ENUM__node_enum__NODE)
};

//---------------------------------------------------------------------
ENUM__node_enum toEnum_ENUM__node_enum (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__node_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__node_enum, StringHash, ENUM__node_enum__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__overflow> ENUM__mathml__overflowMap[ENUM__mathml__overflow__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__overflow>(7090085, ENUM__mathml__overflow__elide),
    std::pair<StringHash, ENUM__mathml__overflow>(7968805, ENUM__mathml__overflow__scale),
    std::pair<StringHash, ENUM__mathml__overflow>(127571500, ENUM__mathml__overflow__scroll),
    std::pair<StringHash, ENUM__mathml__overflow>(163880725, ENUM__mathml__overflow__truncate)
};

//---------------------------------------------------------------------
ENUM__mathml__overflow toEnum_ENUM__mathml__overflow (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__overflow>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__overflow, StringHash, ENUM__mathml__overflow__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__display> ENUM__mathml__displayMap[ENUM__mathml__display__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__display>(6895003, ENUM__mathml__display__block),
    std::pair<StringHash, ENUM__mathml__display>(117780549, ENUM__mathml__display__inline)
};

//---------------------------------------------------------------------
ENUM__mathml__display toEnum_ENUM__mathml__display (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__display>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__display, StringHash, ENUM__mathml__display__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__cn__type> ENUM__mathml__cn__typeMap[ENUM__mathml__cn__type__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__cn__type>(185451150, ENUM__mathml__cn__type__complex_cartesian),
    std::pair<StringHash, ENUM__mathml__cn__type>(19083298, ENUM__mathml__cn__type__complex_polar),
    std::pair<StringHash, ENUM__mathml__cn__type>(106603252, ENUM__mathml__cn__type__constant),
    std::pair<StringHash, ENUM__mathml__cn__type>(112077838, ENUM__mathml__cn__type__e_notation),
    std::pair<StringHash, ENUM__mathml__cn__type>(5946802, ENUM__mathml__cn__type__integer),
    std::pair<StringHash, ENUM__mathml__cn__type>(145777660, ENUM__mathml__cn__type__rational),
    std::pair<StringHash, ENUM__mathml__cn__type>(494460, ENUM__mathml__cn__type__real)
};

//---------------------------------------------------------------------
ENUM__mathml__cn__type toEnum_ENUM__mathml__cn__type (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__cn__type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__cn__type, StringHash, ENUM__mathml__cn__type__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__list__order> ENUM__mathml__list__orderMap[ENUM__mathml__list__order__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__list__order>(205952211, ENUM__mathml__list__order__lexicographic),
    std::pair<StringHash, ENUM__mathml__list__order>(96716931, ENUM__mathml__list__order__numeric)
};

//---------------------------------------------------------------------
ENUM__mathml__list__order toEnum_ENUM__mathml__list__order (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__list__order>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__list__order, StringHash, ENUM__mathml__list__order__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__interval__closure> ENUM__mathml__interval__closureMap[ENUM__mathml__interval__closure__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__interval__closure>(111372724, ENUM__mathml__interval__closure__closed),
    std::pair<StringHash, ENUM__mathml__interval__closure>(186273838, ENUM__mathml__interval__closure__closed_open),
    std::pair<StringHash, ENUM__mathml__interval__closure>(485054, ENUM__mathml__interval__closure__open),
    std::pair<StringHash, ENUM__mathml__interval__closure>(66389412, ENUM__mathml__interval__closure__open_closed)
};

//---------------------------------------------------------------------
ENUM__mathml__interval__closure toEnum_ENUM__mathml__interval__closure (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__interval__closure>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__interval__closure, StringHash, ENUM__mathml__interval__closure__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}


//---------------------------------------------------------------------
const std::pair<StringHash, ENUM__mathml__declare__occurrence> ENUM__mathml__declare__occurrenceMap[ENUM__mathml__declare__occurrence__COUNT] = 
{
    std::pair<StringHash, ENUM__mathml__declare__occurrence>(227209260, ENUM__mathml__declare__occurrence__function_model),
    std::pair<StringHash, ENUM__mathml__declare__occurrence>(7359752, ENUM__mathml__declare__occurrence__infix),
    std::pair<StringHash, ENUM__mathml__declare__occurrence>(125353224, ENUM__mathml__declare__occurrence__prefix)
};

//---------------------------------------------------------------------
ENUM__mathml__declare__occurrence toEnum_ENUM__mathml__declare__occurrence (
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__mathml__declare__occurrence>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
)
{
    return Utils::toEnum<ENUM__mathml__declare__occurrence, StringHash, ENUM__mathml__declare__occurrence__COUNT>(buffer, bufferEnd, failed, enumMap, baseConversionFunc);
}



} // namespace
