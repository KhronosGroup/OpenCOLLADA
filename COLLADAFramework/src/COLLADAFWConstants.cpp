/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADAFWStableHeaders.h"
#include "COLLADAFWConstants.h"


namespace COLLADAFW
{
    
    const String Constants::EMPTY_STRING = "";
    const String Constants::ERR_UNKNOWN_INPUT = "UNKNOWN INPUT ERROR";

    const String Constants::SEMANTIC_BINORMAL = "BINORMAL";
    const String Constants::SEMANTIC_COLOR = "COLOR";
    const String Constants::SEMANTIC_CONTINUITY = "CONTINUITY";
    const String Constants::SEMANTIC_IMAGE = "IMAGE";
    const String Constants::SEMANTIC_INPUT = "INPUT";
    const String Constants::SEMANTIC_IN_TANGENT = "IN_TANGENT";
    const String Constants::SEMANTIC_INTERPOLATION = "INTERPOLATION";
    const String Constants::SEMANTIC_INV_BIND_MATRIX = "INV_BIND_MATRIX";
    const String Constants::SEMANTIC_JOINT = "JOINT";
    const String Constants::SEMANTIC_LINEAR_STEPS = "LINEAR_STEPS";
    const String Constants::SEMANTIC_MORPH_TARGET = "MORPH_TARGET";
    const String Constants::SEMANTIC_MORPH_WEIGHT = "MORPH_WEIGHT";
    const String Constants::SEMANTIC_NORMAL = "NORMAL";
    const String Constants::SEMANTIC_OUTPUT = "OUTPUT";
    const String Constants::SEMANTIC_OUT_TANGENT = "OUT_TANGENT";
    const String Constants::SEMANTIC_POSITION = "POSITION";
    const String Constants::SEMANTIC_TANGENT = "TANGENT";
    const String Constants::SEMANTIC_TEXBINORMAL = "TEXBINORMAL";
    const String Constants::SEMANTIC_TEXCOORD = "TEXCOORD";
    const String Constants::SEMANTIC_TEXTANGENT = "TEXTANGENT";
    const String Constants::SEMANTIC_UV = "UV";
    const String Constants::SEMANTIC_VERTEX = "VERTEX";
    const String Constants::SEMANTIC_WEIGHT = "WEIGHT";

    const String Constants::VALUE_TYPE_BOOL = "bool";
    const String Constants::VALUE_TYPE_BOOL2 = "bool2";
    const String Constants::VALUE_TYPE_BOOL3 = "bool3";
    const String Constants::VALUE_TYPE_BOOL4 = "bool4";
    const String Constants::VALUE_TYPE_INT = "int";
    const String Constants::VALUE_TYPE_INT2 = "int2";
    const String Constants::VALUE_TYPE_INT3 = "int3";
    const String Constants::VALUE_TYPE_INT4 = "int4";
    const String Constants::VALUE_TYPE_FLOAT = "float";
    const String Constants::VALUE_TYPE_FLOAT2 = "float2";
    const String Constants::VALUE_TYPE_FLOAT3 = "float3";
    const String Constants::VALUE_TYPE_FLOAT4 = "float4";
    const String Constants::VALUE_TYPE_FLOAT2x2 = "float2x2";
    const String Constants::VALUE_TYPE_FLOAT3x3 = "float3x3";
    const String Constants::VALUE_TYPE_FLOAT4x4 = "float4x4";
    const String Constants::VALUE_TYPE_STRING = "string";
    const String Constants::VALUE_TYPE_SURFACE = "surface";
    const String Constants::VALUE_TYPE_SAMPLER_1D = "sampler1D";
    const String Constants::VALUE_TYPE_SAMPLER_2D = "sampler2D";
    const String Constants::VALUE_TYPE_SAMPLER_3D = "sampler3D";
    const String Constants::VALUE_TYPE_SAMPLER_CUBE = "samplerCUBE";
    const String Constants::VALUE_TYPE_SAMPLER_RECT = "samplerRECT";
    const String Constants::VALUE_TYPE_SAMPLER_DEPTH = "samplerDEPTH";
    const String Constants::VALUE_TYPE_SAMPLER_STATE = "sampler_state";
    const String Constants::VALUE_TYPE_NAME = "name";
    const String Constants::VALUE_TYPE_IDREF = "IDREF";

    const String Constants::FX_FUNCTION_NEVER = "NEVER";
    const String Constants::FX_FUNCTION_LESS = "LESS";
    const String Constants::FX_FUNCTION_EQUAL = "EQUAL";
    const String Constants::FX_FUNCTION_LEQUAL = "LEQUAL";
    const String Constants::FX_FUNCTION_GREATER = "GREATER";
    const String Constants::FX_FUNCTION_NEQUAL = "NOTEQUAL";
    const String Constants::FX_FUNCTION_GEQUAL = "GEQUAL";
    const String Constants::FX_FUNCTION_ALWAYS = "ALWAYS";

    const String Constants::FX_ANNOTATION_RESOURCE_NAME = "ResourceName";
    const String Constants::FX_ANNOTATION_RESOURCE_TYPE = "ResourceType";
    const String Constants::FX_SHADER_STAGE_VERTEX = "VERTEX";
    const String Constants::FX_SHADER_STAGE_VERTEXPROGRAM = "VERTEXPROGRAM";
    const String Constants::FX_SHADER_STAGE_FRAGMENT = "FRAGMENT";
    const String Constants::FX_SHADER_STAGE_FRAGMENTPROGRAM = "FRAGMENTPROGRAM";

    const String Constants::FX_STATE_ALPHA_FUNC = "alpha_func";
    const String Constants::FX_STATE_BLEND_FUNC = "blend_func";
    const String Constants::FX_STATE_BLEND_FUNC_SEPARATE = "blend_func_separate";
    const String Constants::FX_STATE_BLEND_EQUATION = "blend_equation";
    const String Constants::FX_STATE_BLEND_EQUATION_SEPARATE = "blend_equation_separate";
    const String Constants::FX_STATE_COLOR_MATERIAL = "color_material";
    const String Constants::FX_STATE_CULL_FACE = "cull_face";
    const String Constants::FX_STATE_DEPTH_FUNC = "depth_func";
    const String Constants::FX_STATE_FOG_MODE = "fog_mode";
    const String Constants::FX_STATE_FOG_COORD_SRC = "fog_coord_src";
    const String Constants::FX_STATE_FRONT_FACE = "front_face";
    const String Constants::FX_STATE_LIGHT_MODEL_COLOR_CONTROL = "light_model_color_control";
    const String Constants::FX_STATE_LOGIC_OP = "logic_op";
    const String Constants::FX_STATE_POLYGON_MODE = "polygon_mode";
    const String Constants::FX_STATE_SHADE_MODEL = "shade_model";
    const String Constants::FX_STATE_STENCIL_FUNC = "stencil_func";
    const String Constants::FX_STATE_STENCIL_OP = "stencil_op";
    const String Constants::FX_STATE_STENCIL_FUNC_SEPARATE = "stencil_func_separate";
    const String Constants::FX_STATE_STENCIL_OP_SEPARATE = "stencil_op_separate";
    const String Constants::FX_STATE_STENCIL_MASK_SEPARATE = "stencil_mask_separate";
    const String Constants::FX_STATE_LIGHT_ENABLE = "light_enable";
    const String Constants::FX_STATE_LIGHT_AMBIENT = "light_ambient";
    const String Constants::FX_STATE_LIGHT_DIFFUSE = "light_diffuse";
    const String Constants::FX_STATE_LIGHT_SPECULAR = "light_specular";
    const String Constants::FX_STATE_LIGHT_POSITION = "light_position";
    const String Constants::FX_STATE_LIGHT_CONSTANT_ATTENUATION = "light_constant_attenuation";
    const String Constants::FX_STATE_LIGHT_LINEAR_ATTENUATION = "light_linear_attenuation";
    const String Constants::FX_STATE_LIGHT_QUADRATIC_ATTENUATION = "light_quadratic_attenuation";
    const String Constants::FX_STATE_LIGHT_SPOT_CUTOFF = "light_spot_cutoff";
    const String Constants::FX_STATE_LIGHT_SPOT_DIRECTION = "light_spot_direction";
    const String Constants::FX_STATE_LIGHT_SPOT_EXPONENT = "light_spot_exponent";
    const String Constants::FX_STATE_TEXTURE1D = "texture1D";
    const String Constants::FX_STATE_TEXTURE2D = "texture2D";
    const String Constants::FX_STATE_TEXTURE3D = "texture3D";
    const String Constants::FX_STATE_TEXTURECUBE = "textureCUBE";
    const String Constants::FX_STATE_TEXTURERECT = "textureRECT";
    const String Constants::FX_STATE_TEXTUREDEPTH = "textureDEPTH";
    const String Constants::FX_STATE_TEXTURE1D_ENABLE = "texture1D_enable";
    const String Constants::FX_STATE_TEXTURE2D_ENABLE = "texture2D_enable";
    const String Constants::FX_STATE_TEXTURE3D_ENABLE = "texture3D_enable";
    const String Constants::FX_STATE_TEXTURECUBE_ENABLE = "textureCUBE_enable";
    const String Constants::FX_STATE_TEXTURERECT_ENABLE = "textureRECT_enable";
    const String Constants::FX_STATE_TEXTUREDEPTH_ENABLE = "textureDEPTH_enable";
    const String Constants::FX_STATE_TEXTURE_ENV_COLOR = "texture_env_color";
    const String Constants::FX_STATE_TEXTURE_ENV_MODE = "texture_env_mode";
    const String Constants::FX_STATE_CLIP_PLANE = "clip_plane";
    const String Constants::FX_STATE_CLIP_PLANE_ENABLE = "clip_plane_enable";
    const String Constants::FX_STATE_BLEND_COLOR = "blend_color";
    const String Constants::FX_STATE_CLEAR_COLOR = "clear_color";
    const String Constants::FX_STATE_CLEAR_STENCIL = "clear_stencil";
    const String Constants::FX_STATE_CLEAR_DEPTH = "clear_depth";
    const String Constants::FX_STATE_COLOR_MASK = "color_mask";
    const String Constants::FX_STATE_DEPTH_BOUNDS = "depth_bounds";
    const String Constants::FX_STATE_DEPTH_MASK = "depth_mask";
    const String Constants::FX_STATE_DEPTH_RANGE = "depth_range";
    const String Constants::FX_STATE_FOG_DENSITY = "fog_density";
    const String Constants::FX_STATE_FOG_START = "fog_start";
    const String Constants::FX_STATE_FOG_END = "fog_end";
    const String Constants::FX_STATE_FOG_COLOR = "fog_color";
    const String Constants::FX_STATE_LIGHT_MODEL_AMBIENT = "light_model_ambient";
    const String Constants::FX_STATE_LIGHTING_ENABLE = "lighting_enable";
    const String Constants::FX_STATE_LINE_STIPPLE = "line_stipple";
    const String Constants::FX_STATE_LINE_STIPPLE_ENABLE = "line_stipple_enable";
    const String Constants::FX_STATE_LINE_WIDTH = "line_width";
    const String Constants::FX_STATE_MATERIAL_AMBIENT = "material_ambient";
    const String Constants::FX_STATE_MATERIAL_DIFFUSE = "material_diffuse";
    const String Constants::FX_STATE_MATERIAL_EMISSION = "material_emission";
    const String Constants::FX_STATE_MATERIAL_SHININESS = "material_shininess";
    const String Constants::FX_STATE_MATERIAL_SPECULAR = "material_specular";
    const String Constants::FX_STATE_MODEL_VIEW_MATRIX = "model_view_matrix";
    const String Constants::FX_STATE_POINT_DISTANCE_ATTENUATION = "point_distance_attenuation";
    const String Constants::FX_STATE_POINT_FADE_THRESHOLD_SIZE = "point_fade_threshold_size";
    const String Constants::FX_STATE_POINT_SIZE = "point_size";
    const String Constants::FX_STATE_POINT_SIZE_MIN = "point_size_min";
    const String Constants::FX_STATE_POINT_SIZE_MAX = "point_size_max";
    const String Constants::FX_STATE_POLYGON_OFFSET = "polygon_offset";
    const String Constants::FX_STATE_PROJECTION_MATRIX = "projection_matrix";
    const String Constants::FX_STATE_SCISSOR = "scissor";
    const String Constants::FX_STATE_STENCIL_MASK = "stencil_mask";
    const String Constants::FX_STATE_ALPHA_TEST_ENABLE = "alpha_test_enable";
    const String Constants::FX_STATE_AUTO_NORMAL_ENABLE = "auto_normal_enable";
    const String Constants::FX_STATE_BLEND_ENABLE = "blend_enable";
    const String Constants::FX_STATE_COLOR_LOGIC_OP_ENABLE = "color_logic_op_enable";
    const String Constants::FX_STATE_COLOR_MATERIAL_ENABLE = "color_material_enable";
    const String Constants::FX_STATE_CULL_FACE_ENABLE = "cull_face_enable";
    const String Constants::FX_STATE_DEPTH_BOUNDS_ENABLE = "depth_bounds_enable";
    const String Constants::FX_STATE_DEPTH_CLAMP_ENABLE = "depth_clamp_enable";
    const String Constants::FX_STATE_DEPTH_TEST_ENABLE = "depth_test_enable";
    const String Constants::FX_STATE_DITHER_ENABLE = "dither_enable";
    const String Constants::FX_STATE_FOG_ENABLE = "fog_enable";
    const String Constants::FX_STATE_LIGHT_MODEL_LOCAL_VIEWER_ENABLE = "light_model_local_viewer_enable";
    const String Constants::FX_STATE_LIGHT_MODEL_TWO_SIDE_ENABLE = "light_model_two_side_enable";
    const String Constants::FX_STATE_LINE_SMOOTH_ENABLE = "line_smooth_enable";
    const String Constants::FX_STATE_LOGIC_OP_ENABLE = "logic_op_enable";
    const String Constants::FX_STATE_MULTISAMPLE_ENABLE = "multisample_enable";
    const String Constants::FX_STATE_NORMALIZE_ENABLE = "normalize_enable";
    const String Constants::FX_STATE_POINT_SMOOTH_ENABLE = "point_smooth_enable";
    const String Constants::FX_STATE_POLYGON_OFFSET_FILL_ENABLE = "polygon_offset_fill_enable";
    const String Constants::FX_STATE_POLYGON_OFFSET_LINE_ENABLE = "polygon_offset_line_enable";
    const String Constants::FX_STATE_POLYGON_OFFSET_POINT_ENABLE = "polygon_offset_point_enable";
    const String Constants::FX_STATE_POLYGON_SMOOTH_ENABLE = "polygon_smooth_enable";
    const String Constants::FX_STATE_POLYGON_STIPPLE_ENABLE = "polygon_stipple_enable";
    const String Constants::FX_STATE_RESCALE_NORMAL_ENABLE = "rescale_normal_enable";
    const String Constants::FX_STATE_SAMPLE_ALPHA_TO_COVERAGE_ENABLE = "sample_alpha_to_coverage_enable";
    const String Constants::FX_STATE_SAMPLE_ALPHA_TO_ONE_ENABLE = "sample_alpha_to_one_enable";
    const String Constants::FX_STATE_SAMPLE_COVERAGE_ENABLE = "sample_coverage_enable";
    const String Constants::FX_STATE_SCISSOR_TEST_ENABLE = "scissor_test_enable";
    const String Constants::FX_STATE_STENCIL_TEST_ENABLE = "stencil_test_enable";

} // namespace COLLADAFW
