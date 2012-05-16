/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAFramework.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_CONSTANTS_H__
#define __COLLADAFW_CONSTANTS_H__

#include "COLLADAFWPrerequisites.h"
#include "COLLADAFWArrayPrimitiveType.h"


namespace COLLADAFW
{



    /** TODO Documentation */
	class Constants 	
    {
    public:

        static const String EMPTY_STRING;
        static const String ERR_UNKNOWN_INPUT;

        static const String SEMANTIC_BINORMAL;
        static const String SEMANTIC_COLOR;
        static const String SEMANTIC_CONTINUITY;
        static const String SEMANTIC_IMAGE;
        static const String SEMANTIC_INPUT;
        static const String SEMANTIC_IN_TANGENT;
        static const String SEMANTIC_INTERPOLATION;
        static const String SEMANTIC_INV_BIND_MATRIX;
        static const String SEMANTIC_JOINT;
        static const String SEMANTIC_LINEAR_STEPS;
        static const String SEMANTIC_MORPH_TARGET;
        static const String SEMANTIC_MORPH_WEIGHT;
        static const String SEMANTIC_NORMAL;
        static const String SEMANTIC_OUTPUT;
        static const String SEMANTIC_OUT_TANGENT;
        static const String SEMANTIC_POSITION;
        static const String SEMANTIC_TANGENT;
        static const String SEMANTIC_TEXBINORMAL;
        static const String SEMANTIC_TEXCOORD;
        static const String SEMANTIC_TEXTANGENT;
        static const String SEMANTIC_UV;
        static const String SEMANTIC_VERTEX;
        static const String SEMANTIC_WEIGHT;

        static const String VALUE_TYPE_BOOL;
        static const String VALUE_TYPE_BOOL2;
        static const String VALUE_TYPE_BOOL3;
        static const String VALUE_TYPE_BOOL4;
        static const String VALUE_TYPE_INT;
        static const String VALUE_TYPE_INT2;
        static const String VALUE_TYPE_INT3;
        static const String VALUE_TYPE_INT4;
        static const String VALUE_TYPE_FLOAT;
        static const String VALUE_TYPE_FLOAT2;
        static const String VALUE_TYPE_FLOAT3;
        static const String VALUE_TYPE_FLOAT4;
        static const String VALUE_TYPE_FLOAT2x2;
        static const String VALUE_TYPE_FLOAT3x3;
        static const String VALUE_TYPE_FLOAT4x4;
        static const String VALUE_TYPE_STRING;
        static const String VALUE_TYPE_SURFACE;
        static const String VALUE_TYPE_SAMPLER_1D;
        static const String VALUE_TYPE_SAMPLER_2D;
        static const String VALUE_TYPE_SAMPLER_3D;
        static const String VALUE_TYPE_SAMPLER_CUBE;
        static const String VALUE_TYPE_SAMPLER_RECT;
        static const String VALUE_TYPE_SAMPLER_DEPTH;
        static const String VALUE_TYPE_SAMPLER_STATE;
        static const String VALUE_TYPE_NAME;
        static const String VALUE_TYPE_IDREF;

        static const String FX_FUNCTION_NEVER;
        static const String FX_FUNCTION_LESS;
        static const String FX_FUNCTION_EQUAL;
        static const String FX_FUNCTION_LEQUAL;
        static const String FX_FUNCTION_GREATER;
        static const String FX_FUNCTION_NEQUAL;
        static const String FX_FUNCTION_GEQUAL;
        static const String FX_FUNCTION_ALWAYS;

        static const String FX_ANNOTATION_RESOURCE_NAME;
        static const String FX_ANNOTATION_RESOURCE_TYPE;
        static const String FX_SHADER_STAGE_VERTEX;
        static const String FX_SHADER_STAGE_VERTEXPROGRAM;
        static const String FX_SHADER_STAGE_FRAGMENT;
        static const String FX_SHADER_STAGE_FRAGMENTPROGRAM;

        static const String FX_STATE_ALPHA_FUNC;
        static const String FX_STATE_BLEND_FUNC;
        static const String FX_STATE_BLEND_FUNC_SEPARATE;
        static const String FX_STATE_BLEND_EQUATION;
        static const String FX_STATE_BLEND_EQUATION_SEPARATE;
        static const String FX_STATE_COLOR_MATERIAL;
        static const String FX_STATE_CULL_FACE;
        static const String FX_STATE_DEPTH_FUNC;
        static const String FX_STATE_FOG_MODE;
        static const String FX_STATE_FOG_COORD_SRC;
        static const String FX_STATE_FRONT_FACE;
        static const String FX_STATE_LIGHT_MODEL_COLOR_CONTROL;
        static const String FX_STATE_LOGIC_OP;
        static const String FX_STATE_POLYGON_MODE;
        static const String FX_STATE_SHADE_MODEL;
        static const String FX_STATE_STENCIL_FUNC;
        static const String FX_STATE_STENCIL_OP;
        static const String FX_STATE_STENCIL_FUNC_SEPARATE;
        static const String FX_STATE_STENCIL_OP_SEPARATE;
        static const String FX_STATE_STENCIL_MASK_SEPARATE;
        static const String FX_STATE_LIGHT_ENABLE;
        static const String FX_STATE_LIGHT_AMBIENT;
        static const String FX_STATE_LIGHT_DIFFUSE;
        static const String FX_STATE_LIGHT_SPECULAR;
        static const String FX_STATE_LIGHT_POSITION;
        static const String FX_STATE_LIGHT_CONSTANT_ATTENUATION;
        static const String FX_STATE_LIGHT_LINEAR_ATTENUATION;
        static const String FX_STATE_LIGHT_QUADRATIC_ATTENUATION;
        static const String FX_STATE_LIGHT_SPOT_CUTOFF;
        static const String FX_STATE_LIGHT_SPOT_DIRECTION;
        static const String FX_STATE_LIGHT_SPOT_EXPONENT;
        static const String FX_STATE_TEXTURE1D;
        static const String FX_STATE_TEXTURE2D;
        static const String FX_STATE_TEXTURE3D;
        static const String FX_STATE_TEXTURECUBE;
        static const String FX_STATE_TEXTURERECT;
        static const String FX_STATE_TEXTUREDEPTH;
        static const String FX_STATE_TEXTURE1D_ENABLE;
        static const String FX_STATE_TEXTURE2D_ENABLE;
        static const String FX_STATE_TEXTURE3D_ENABLE;
        static const String FX_STATE_TEXTURECUBE_ENABLE;
        static const String FX_STATE_TEXTURERECT_ENABLE;
        static const String FX_STATE_TEXTUREDEPTH_ENABLE;
        static const String FX_STATE_TEXTURE_ENV_COLOR;
        static const String FX_STATE_TEXTURE_ENV_MODE;
        static const String FX_STATE_CLIP_PLANE;
        static const String FX_STATE_CLIP_PLANE_ENABLE;
        static const String FX_STATE_BLEND_COLOR;
        static const String FX_STATE_CLEAR_COLOR;
        static const String FX_STATE_CLEAR_STENCIL;
        static const String FX_STATE_CLEAR_DEPTH;
        static const String FX_STATE_COLOR_MASK;
        static const String FX_STATE_DEPTH_BOUNDS;
        static const String FX_STATE_DEPTH_MASK;
        static const String FX_STATE_DEPTH_RANGE;
        static const String FX_STATE_FOG_DENSITY;
        static const String FX_STATE_FOG_START;
        static const String FX_STATE_FOG_END;
        static const String FX_STATE_FOG_COLOR;
        static const String FX_STATE_LIGHT_MODEL_AMBIENT;
        static const String FX_STATE_LIGHTING_ENABLE;
        static const String FX_STATE_LINE_STIPPLE;
        static const String FX_STATE_LINE_STIPPLE_ENABLE;
        static const String FX_STATE_LINE_WIDTH;
        static const String FX_STATE_MATERIAL_AMBIENT;
        static const String FX_STATE_MATERIAL_DIFFUSE;
        static const String FX_STATE_MATERIAL_EMISSION;
        static const String FX_STATE_MATERIAL_SHININESS;
        static const String FX_STATE_MATERIAL_SPECULAR;
        static const String FX_STATE_MODEL_VIEW_MATRIX;
        static const String FX_STATE_POINT_DISTANCE_ATTENUATION;
        static const String FX_STATE_POINT_FADE_THRESHOLD_SIZE;
        static const String FX_STATE_POINT_SIZE;
        static const String FX_STATE_POINT_SIZE_MIN;
        static const String FX_STATE_POINT_SIZE_MAX;
        static const String FX_STATE_POLYGON_OFFSET;
        static const String FX_STATE_PROJECTION_MATRIX;
        static const String FX_STATE_SCISSOR;
        static const String FX_STATE_STENCIL_MASK;
        static const String FX_STATE_ALPHA_TEST_ENABLE;
        static const String FX_STATE_AUTO_NORMAL_ENABLE;
        static const String FX_STATE_BLEND_ENABLE;
        static const String FX_STATE_COLOR_LOGIC_OP_ENABLE;
        static const String FX_STATE_COLOR_MATERIAL_ENABLE;
        static const String FX_STATE_CULL_FACE_ENABLE;
        static const String FX_STATE_DEPTH_BOUNDS_ENABLE;
        static const String FX_STATE_DEPTH_CLAMP_ENABLE;
        static const String FX_STATE_DEPTH_TEST_ENABLE;
        static const String FX_STATE_DITHER_ENABLE;
        static const String FX_STATE_FOG_ENABLE;
        static const String FX_STATE_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
        static const String FX_STATE_LIGHT_MODEL_TWO_SIDE_ENABLE;
        static const String FX_STATE_LINE_SMOOTH_ENABLE;
        static const String FX_STATE_LOGIC_OP_ENABLE;
        static const String FX_STATE_MULTISAMPLE_ENABLE;
        static const String FX_STATE_NORMALIZE_ENABLE;
        static const String FX_STATE_POINT_SMOOTH_ENABLE;
        static const String FX_STATE_POLYGON_OFFSET_FILL_ENABLE;
        static const String FX_STATE_POLYGON_OFFSET_LINE_ENABLE;
        static const String FX_STATE_POLYGON_OFFSET_POINT_ENABLE;
        static const String FX_STATE_POLYGON_SMOOTH_ENABLE;
        static const String FX_STATE_POLYGON_STIPPLE_ENABLE;
        static const String FX_STATE_RESCALE_NORMAL_ENABLE;
        static const String FX_STATE_SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
        static const String FX_STATE_SAMPLE_ALPHA_TO_ONE_ENABLE;
        static const String FX_STATE_SAMPLE_COVERAGE_ENABLE;
        static const String FX_STATE_SCISSOR_TEST_ENABLE;
        static const String FX_STATE_STENCIL_TEST_ENABLE;

	};

} // namespace COLLADAFW

#endif // __COLLADAFW_CONSTANTS_H__
