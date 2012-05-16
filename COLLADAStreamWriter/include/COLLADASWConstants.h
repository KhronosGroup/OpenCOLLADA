/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_CSWC_H__
#define __COLLADASTREAMWRITER_CSWC_H__

#include "COLLADASWPrerequisites.h"

namespace COLLADASW
{

    /** A class that contains all constants used by COLLADAStreamWriter. */
    class CSWC
    {

    public:

        static const String EMPTY_STRING;
        static const String CSW_ERR_UNKNOWN_INPUT;

        static const String XML_START_ELEMENT;
        static const String CSW_NAMESPACE_1_4_1;
        static const String CSW_VERSION_1_4_1;

		static const String CSW_NAMESPACE_1_5_0;
		static const String CSW_VERSION_1_5_0;
		static const String CSW_SCHEMALOCATION_1_5_0;
		static const String CSW_XMLNS_XSI_1_5_0;

		static const String CSW_PLATFORM_PC_OGL;

        static const String CSW_ELEMENT_ACCESSOR;
        static const String CSW_ELEMENT_AMBIENT;
        static const String CSW_ELEMENT_ANIMATION;
        static const String CSW_ELEMENT_ANIMATION_CLIP;
        static const String CSW_ELEMENT_ANNOTATE;
        static const String CSW_ELEMENT_ASPECT_RATIO;
        static const String CSW_ELEMENT_ASSET;
        static const String CSW_ELEMENT_AUTHOR;
        static const String CSW_ELEMENT_AUTHORING_TOOL;
        static const String CSW_ELEMENT_BLINN;
        static const String CSW_ELEMENT_BIND;
        static const String CSW_ELEMENT_BIND_MATERIAL;
		static const String CSW_ELEMENT_BIND_SHAPE_MATRIX;
		static const String CSW_ELEMENT_BIND_VERTEX_INPUT;
        static const String CSW_ELEMENT_BORDER_COLOR;
        static const String CSW_ELEMENT_CAMERA;
        static const String CSW_ELEMENT_CAMERA_ORTHOGRAPHIC;
        static const String CSW_ELEMENT_CAMERA_PERSPECTIVE;
        static const String CSW_ELEMENT_CHANNEL;
        static const String CSW_ELEMENT_CHANNELS;
        static const String CSW_ELEMENT_CODE;
        static const String CSW_ELEMENT_COMMENTS;
        static const String CSW_ELEMENT_COMPILER_TARGET;
        static const String CSW_ELEMENT_COMPILER_OPTIONS;
		static const String CSW_ELEMENT_CONSTANT_ATTENUATION;
        static const String CSW_ELEMENT_CONSTANT;
        static const String CSW_ELEMENT_CONTRIBUTOR;
		static const String CSW_ELEMENT_CONTROLLER;
		static const String CSW_ELEMENT_CONTROL_VERTICES;
        static const String CSW_ELEMENT_COPYRIGHT;
        static const String CSW_ELEMENT_CREATED;
        static const String CSW_ELEMENT_COLLADA;
        static const String CSW_ELEMENT_COLOR;
        static const String CSW_ELEMENT_COLOR_CLEAR;
		static const String CSW_ELEMENT_COLOR_TARGET;
		static const String CSW_ELEMENT_CREATE_2D;
        static const String CSW_ELEMENT_DATA;
        static const String CSW_ELEMENT_DEPTH_CLEAR;
        static const String CSW_ELEMENT_DEPTH_TARGET;
        static const String CSW_ELEMENT_DIFFUSE;
		static const String CSW_ELEMENT_DIRECTIONAL;
        static const String CSW_ELEMENT_DRAW;
        static const String CSW_ELEMENT_EFFECT;
        static const String CSW_ELEMENT_EMISSION;
        static const String CSW_ELEMENT_EXTRA;
        static const String CSW_ELEMENT_FALLOFF_ANGLE; 
        static const String CSW_ELEMENT_FALLOFF_EXPONENT;
        static const String CSW_ELEMENT_FLOAT;
        static const String CSW_ELEMENT_FLOAT_ARRAY;
        static const String CSW_ELEMENT_FORMAT;
        static const String CSW_ELEMENT_FORMAT_HINT;
        static const String CSW_ELEMENT_GEOMETRY;
        static const String CSW_ELEMENT_H;
        static const String CSW_ELEMENT_IDREF_ARRAY;
        static const String CSW_ELEMENT_IMAGE;
        static const String CSW_ELEMENT_INCLUDE;
        static const String CSW_ELEMENT_INDEX_OF_REFRACTION;
        static const String CSW_ELEMENT_INIT_FROM;
        static const String CSW_ELEMENT_INIT_AS_TARGET;
        static const String CSW_ELEMENT_INIT_CUBE;
        static const String CSW_ELEMENT_ALL;
        static const String CSW_ELEMENT_PRIMARY;
        static const String CSW_ELEMENT_ORDER;
        static const String CSW_ELEMENT_FACE;
        static const String CSW_ELEMENT_INIT_VOLUME;
        static const String CSW_ELEMENT_INIT_PLANAR;
        static const String CSW_ELEMENT_INIT_AS_NULL;
        static const String CSW_ELEMENT_INPUT;
        static const String CSW_ELEMENT_INSTANCE_ANIMATION;
        static const String CSW_ELEMENT_INSTANCE_CAMERA;
        static const String CSW_ELEMENT_INSTANCE_CONTROLLER;
        static const String CSW_ELEMENT_INSTANCE_EFFECT;
		static const String CSW_ELEMENT_INSTANCE_GEOMETRY;
		static const String CSW_ELEMENT_INSTANCE_IMAGE;
        static const String CSW_ELEMENT_INSTANCE_LIGHT;
        static const String CSW_ELEMENT_INSTANCE_MATERIAL;
        static const String CSW_ELEMENT_INSTANCE_NODE;
        static const String CSW_ELEMENT_INSTANCE_VISUAL_SCENE;
        static const String CSW_ELEMENT_JOINTS;
        static const String CSW_ELEMENT_KEYWORDS;
        static const String CSW_ELEMENT_LAMBERT;
        static const String CSW_ELEMENT_LIBRARY_ANIMATIONS;
        static const String CSW_ELEMENT_LIBRARY_ANIMATION_CLIPS;
        static const String CSW_ELEMENT_LIBRARY_CAMERAS;
        static const String CSW_ELEMENT_LIBRARY_CONTROLLERS;
        static const String CSW_ELEMENT_LIBRARY_EFFECTS;
        static const String CSW_ELEMENT_LIBRARY_GEOMETRIES;
        static const String CSW_ELEMENT_LIBRARY_IMAGES;
        static const String CSW_ELEMENT_LIBRARY_LIGHTS;
        static const String CSW_ELEMENT_LIBRARY_MATERIALS;
        static const String CSW_ELEMENT_LIBRARY_VISUAL_SCENES;
        static const String CSW_ELEMENT_LIGHT;
		static const String CSW_ELEMENT_LINEAR_ATTENUATION;
		static const String CSW_ELEMENT_LINES;
		static const String CSW_ELEMENT_LINE_STRIPS;
        static const String CSW_ELEMENT_LOOKAT;
        static const String CSW_ELEMENT_MAGFILTER;
        static const String CSW_ELEMENT_MATERIAL;
        static const String CSW_ELEMENT_MATRIX;
        static const String CSW_ELEMENT_MESH;
        static const String CSW_ELEMENT_MINFILTER;
        static const String CSW_ELEMENT_MIPFILTER;
        static const String CSW_ELEMENT_MIP_LEVELS;
        static const String CSW_ELEMENT_MIPMAP_BIAS;
        static const String CSW_ELEMENT_MIPMAP_GENERATE;
        static const String CSW_ELEMENT_MIPMAP_MAXLEVEL;
        static const String CSW_ELEMENT_MODIFIED;
        static const String CSW_ELEMENT_MODIFIER;
        static const String CSW_ELEMENT_MORPH;
        static const String CSW_ELEMENT_NAME;
        static const String CSW_ELEMENT_NAME_ARRAY;
        static const String CSW_ELEMENT_NEWPARAM;
        static const String CSW_ELEMENT_NODE;
        static const String CSW_ELEMENT_OPTICS;
        static const String CSW_ELEMENT_OPTION;
        static const String CSW_ELEMENT_P;
        static const String CSW_ELEMENT_PARAM;
        static const String CSW_ELEMENT_PASS;
        static const String CSW_ELEMENT_PH;
        static const String CSW_ELEMENT_PHONG;
		static const String CSW_ELEMENT_POINT;
        static const String CSW_ELEMENT_POLYLIST;
        static const String CSW_ELEMENT_POLYGONS;
        static const String CSW_ELEMENT_PRECISION;
        static const String CSW_ELEMENT_PROFILE_COMMON;
        static const String CSW_ELEMENT_PROFILE_CG;
        static const String CSW_ELEMENT_PROFILE_GLES;
        static const String CSW_ELEMENT_PROFILE_GLSL;
		static const String CSW_ELEMENT_RANGE;
		static const String CSW_ELEMENT_REF;
		static const String CSW_ELEMENT_QUADRATIC_ATTENUATION;
        static const String CSW_ELEMENT_REFLECTIVE;
        static const String CSW_ELEMENT_REFLECTIVITY;
        static const String CSW_ELEMENT_REVISION;
        static const String CSW_ELEMENT_ROTATE;
        static const String CSW_ELEMENT_SAMPLER;
        static const String CSW_ELEMENT_SAMPLER2D;
        static const String CSW_ELEMENT_SCALE;
        static const String CSW_ELEMENT_SCENE;
        static const String CSW_ELEMENT_SETPARAM;
        static const String CSW_ELEMENT_SEMANTIC;
        static const String CSW_ELEMENT_SHADER;
        static const String CSW_ELEMENT_SHININESS;
        static const String CSW_ELEMENT_SIZE;
        static const String CSW_ELEMENT_SKELETON;
        static const String CSW_ELEMENT_SKEW;
        static const String CSW_ELEMENT_SKIN;
        static const String CSW_ELEMENT_SOURCE;
        static const String CSW_ELEMENT_SPECULAR;
        static const String CSW_ELEMENT_SOURCE_DATA;
		static const String CSW_ELEMENT_SPLINE;
		static const String CSW_ELEMENT_SPOT;
        static const String CSW_ELEMENT_STENCIL_CLEAR;
        static const String CSW_ELEMENT_STENCIL_TARGET;
        static const String CSW_ELEMENT_SUBJECT;
        static const String CSW_ELEMENT_SURFACE;
        static const String CSW_ELEMENT_TARGETS;
        static const String CSW_ELEMENT_TECHNIQUE;
        static const String CSW_ELEMENT_TECHNIQUE_HINT;
        static const String CSW_ELEMENT_TECHNIQUE_COMMON;
        static const String CSW_ELEMENT_TEXTURE;
        static const String CSW_ELEMENT_TITLE;
        static const String CSW_ELEMENT_TRANSLATE;
        static const String CSW_ELEMENT_TRANSPARENCY;
        static const String CSW_ELEMENT_TRANSPARENT;
        static const String CSW_ELEMENT_TRIANGLES;
		static const String CSW_ELEMENT_TRIFANS;
		static const String CSW_ELEMENT_TRISTRIPS;
        static const String CSW_ELEMENT_UNIT;
        static const String CSW_ELEMENT_UP_AXIS;
        static const String CSW_ELEMENT_V;
        static const String CSW_ELEMENT_VCOUNT;
        static const String CSW_ELEMENT_VERTEX_WEIGHTS;
        static const String CSW_ELEMENT_VERTICES;
        static const String CSW_ELEMENT_VIEWPORT_RATIO;
        static const String CSW_ELEMENT_VISUAL_SCENE;
        static const String CSW_ELEMENT_WRAP_S;
        static const String CSW_ELEMENT_WRAP_T;
        static const String CSW_ELEMENT_WRAP_P;
        static const String CSW_ELEMENT_XFOV;
        static const String CSW_ELEMENT_XMAG;
        static const String CSW_ELEMENT_YFOV;
        static const String CSW_ELEMENT_YMAG;
        static const String CSW_ELEMENT_ZFAR;
        static const String CSW_ELEMENT_ZNEAR;


		static const String CSW_ATTRIBUTE_CLOSED;
		static const String CSW_ATTRIBUTE_COUNT;
        static const String CSW_ATTRIBUTE_END;
        static const String CSW_ATTRIBUTE_FACE;
        static const String CSW_ATTRIBUTE_ID;
		static const String CSW_ATTRIBUTE_INDEX;
		static const String CSW_ATTRIBUTE_INPUT_SEMANTIC;
		static const String CSW_ATTRIBUTE_INPUT_SET;
        static const String CSW_ATTRIBUTE_MATERIAL;
        static const String CSW_ATTRIBUTE_METER;
        static const String CSW_ATTRIBUTE_METHOD;
        static const String CSW_ATTRIBUTE_MIP;
        static const String CSW_ATTRIBUTE_NAME;
        static const String CSW_ATTRIBUTE_OFFSET;
        static const String CSW_ATTRIBUTE_OPAQUE;
        static const String CSW_ATTRIBUTE_PLATFORM;
        static const String CSW_ATTRIBUTE_PROFILE;
        static const String CSW_ATTRIBUTE_PROGRAM;
        static const String CSW_ATTRIBUTE_REF;
        static const String CSW_ATTRIBUTE_SEMANTIC;
        static const String CSW_ATTRIBUTE_SET;
        static const String CSW_ATTRIBUTE_SID;
        static const String CSW_ATTRIBUTE_SLICE;
        static const String CSW_ATTRIBUTE_SOURCE;
        static const String CSW_ATTRIBUTE_STAGE;
        static const String CSW_ATTRIBUTE_START;
        static const String CSW_ATTRIBUTE_STRIDE;
        static const String CSW_ATTRIBUTE_SYMBOL;
        static const String CSW_ATTRIBUTE_TARGET;
        static const String CSW_ATTRIBUTE_TEXCOORD;
        static const String CSW_ATTRIBUTE_TEXTURE;
        static const String CSW_ATTRIBUTE_TYPE;
        static const String CSW_ATTRIBUTE_URL;
        static const String CSW_ATTRIBUTE_VALUE;
        static const String CSW_ATTRIBUTE_VERSION;
		static const String CSW_ATTRIBUTE_XMLNS;
		static const String CSW_ATTRIBUTE_XMLNS_XSI;
		static const String CSW_ATTRIBUTE_XSI_SCHEMALOCATION;

        static const String CSW_SEMANTIC_BINDMATRIX;
        static const String CSW_SEMANTIC_COLOR;
        static const String CSW_SEMANTIC_CONTINUITY;
        static const String CSW_SEMANTIC_INPUT;
        static const String CSW_SEMANTIC_INTERPOLATION;
        static const String CSW_SEMANTIC_IN_TANGENT;
        static const String CSW_SEMANTIC_JOINT;
        static const String CSW_SEMANTIC_LINEAR_STEPS;
        static const String CSW_SEMANTIC_MORPH_WEIGHT;
        static const String CSW_SEMANTIC_MORPH_TARGET;
        static const String CSW_SEMANTIC_NORMAL;
        static const String CSW_SEMANTIC_OUTPUT;
        static const String CSW_SEMANTIC_OUT_TANGENT;
        static const String CSW_SEMANTIC_POSITION;
		static const String CSW_SEMANTIC_TEXCOORD;
		static const String CSW_SEMANTIC_TANGENT;
		static const String CSW_SEMANTIC_BINORMAL;
        static const String CSW_SEMANTIC_TEXTANGENT;
        static const String CSW_SEMANTIC_TEXBINORMAL;
        static const String CSW_SEMANTIC_VERTEX;
        static const String CSW_SEMANTIC_WEIGHT;

        static const String CSW_TEXT_X_UP;
        static const String CSW_TEXT_Y_UP;
        static const String CSW_TEXT_Z_UP;

        static const String CSW_NODE_TYPE_JOINT;
        static const String CSW_NODE_TYPE_NODE;

        static const String CSW_VALUE_TYPE_BOOL;
        static const String CSW_VALUE_TYPE_BOOL2;
        static const String CSW_VALUE_TYPE_BOOL3;
        static const String CSW_VALUE_TYPE_BOOL4;
        static const String CSW_VALUE_TYPE_INT;
        static const String CSW_VALUE_TYPE_INT2;
        static const String CSW_VALUE_TYPE_INT3;
        static const String CSW_VALUE_TYPE_INT4;
        static const String CSW_VALUE_TYPE_FLOAT;
        static const String CSW_VALUE_TYPE_FLOAT2;
        static const String CSW_VALUE_TYPE_FLOAT3;
        static const String CSW_VALUE_TYPE_FLOAT4;
        static const String CSW_VALUE_TYPE_FLOAT2x2;
        static const String CSW_VALUE_TYPE_FLOAT3x3;
        static const String CSW_VALUE_TYPE_FLOAT4x4;
        static const String CSW_VALUE_TYPE_STRING;
        static const String CSW_VALUE_TYPE_SURFACE;
        static const String CSW_VALUE_TYPE_SAMPLER_1D;
        static const String CSW_VALUE_TYPE_SAMPLER_2D;
        static const String CSW_VALUE_TYPE_SAMPLER_3D;
        static const String CSW_VALUE_TYPE_SAMPLER_CUBE;
        static const String CSW_VALUE_TYPE_SAMPLER_RECT;
        static const String CSW_VALUE_TYPE_SAMPLER_DEPTH;
        static const String CSW_VALUE_TYPE_SAMPLER_STATE;
        static const String CSW_VALUE_TYPE_NAME;
        static const String CSW_VALUE_TYPE_IDREF;

        static const String CSW_SAMPLER_FILTER_LINEAR;
        static const String CSW_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR;
        static const String CSW_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST;
        static const String CSW_SAMPLER_FILTER_NEAREST;
        static const String CSW_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR;
        static const String CSW_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST;
        static const String CSW_SAMPLER_FILTER_NONE;

        static const String CSW_CHANNEL_RGB;
        static const String CSW_CHANNEL_RGBA;
        static const String CSW_CHANNEL_L;
        static const String CSW_CHANNEL_LA;
        static const String CSW_CHANNEL_D;
        static const String CSW_CHANNEL_XYZ;
        static const String CSW_CHANNEL_XYZW;

        static const String CSW_RANGE_SNORM;
        static const String CSW_RANGE_UNORM;
        static const String CSW_RANGE_SINT;
        static const String CSW_RANGE_UINT;
        static const String CSW_RANGE_FLOAT;

        static const String CSW_PRECISION_LOW;
        static const String CSW_PRECISION_MID;
        static const String CSW_PRECISION_HIGH;

        static const String CSW_OPTION_SRGB_GAMMA;
        static const String CSW_OPTION_NORMALIZED3;
        static const String CSW_OPTION_NORMALIZED4;
        static const String CSW_OPTION_COMPRESSABLE;

        // texture wrap modes
        static const String CSW_TEXTURE_WRAP_NONE;
        static const String CSW_TEXTURE_WRAP_WRAP;
        static const String CSW_TEXTURE_WRAP_MIRROR;
        static const String CSW_TEXTURE_WRAP_CLAMP;
        static const String CSW_TEXTURE_WRAP_BORDER;
        static const String CSW_TEXTURE_WRAP_UNKNOWN;

        static const String CSW_SURFACE_TYPE_UNTYPED;
        static const String CSW_SURFACE_TYPE_1D;
        static const String CSW_SURFACE_TYPE_2D;
        static const String CSW_SURFACE_TYPE_3D;
        static const String CSW_SURFACE_TYPE_RECT;
        static const String CSW_SURFACE_TYPE_CUBE;
        static const String CSW_SURFACE_TYPE_DEPTH;

        static const String CSW_OPAQUE_TYPE_UNTYPED;
        static const String CSW_OPAQUE_TYPE_A_ONE;
        static const String CSW_OPAQUE_TYPE_RGB_ONE;
        static const String CSW_OPAQUE_TYPE_RGB_ZERO;
        static const String CSW_OPAQUE_TYPE_A_ZERO;

        static const String CSW_FACE_POSITIVE_X;
        static const String CSW_FACE_NEGATIVE_X;
        static const String CSW_FACE_POSITIVE_Y;
        static const String CSW_FACE_NEGATIVE_Y; 
        static const String CSW_FACE_POSITIVE_Z;
        static const String CSW_FACE_NEGATIVE_Z;

        static const String CSW_MODIFIER_CONST;
        static const String CSW_MODIFIER_UNIFORM;
        static const String CSW_MODIFIER_VARYING;
        static const String CSW_MODIFIER_STATIC;
        static const String CSW_MODIFIER_VOLATILE;
        static const String CSW_MODIFIER_EXTERN;
        static const String CSW_MODIFIER_SHARED;

        static const String CSW_FX_FUNCTION_NEVER;
        static const String CSW_FX_FUNCTION_LESS;
        static const String CSW_FX_FUNCTION_EQUAL;
        static const String CSW_FX_FUNCTION_LEQUAL;
        static const String CSW_FX_FUNCTION_GREATER;
        static const String CSW_FX_FUNCTION_NEQUAL;
        static const String CSW_FX_FUNCTION_GEQUAL;
        static const String CSW_FX_FUNCTION_ALWAYS;

        static const String CSW_FX_ANNOTATION_RESOURCE_NAME;
        static const String CSW_FX_ANNOTATION_RESOURCE_TYPE;
        static const String CSW_FX_SHADER_STAGE_VERTEX;
        static const String CSW_FX_SHADER_STAGE_VERTEXPROGRAM;
        static const String CSW_FX_SHADER_STAGE_FRAGMENT;
        static const String CSW_FX_SHADER_STAGE_FRAGMENTPROGRAM;

        static const String CSW_FX_STATE_ALPHA_FUNC;
        static const String CSW_FX_STATE_BLEND_FUNC;
        static const String CSW_FX_STATE_BLEND_FUNC_SEPARATE;
        static const String CSW_FX_STATE_BLEND_EQUATION;
        static const String CSW_FX_STATE_BLEND_EQUATION_SEPARATE;
        static const String CSW_FX_STATE_COLOR_MATERIAL;
        static const String CSW_FX_STATE_CULL_FACE;
        static const String CSW_FX_STATE_DEPTH_FUNC;
        static const String CSW_FX_STATE_FOG_MODE;
        static const String CSW_FX_STATE_FOG_COORD_SRC;
        static const String CSW_FX_STATE_FRONT_FACE;
        static const String CSW_FX_STATE_LIGHT_MODEL_COLOR_CONTROL;
        static const String CSW_FX_STATE_LOGIC_OP;
        static const String CSW_FX_STATE_POLYGON_MODE;
        static const String CSW_FX_STATE_SHADE_MODEL;
        static const String CSW_FX_STATE_STENCIL_FUNC;
        static const String CSW_FX_STATE_STENCIL_OP;
        static const String CSW_FX_STATE_STENCIL_FUNC_SEPARATE;
        static const String CSW_FX_STATE_STENCIL_OP_SEPARATE;
        static const String CSW_FX_STATE_STENCIL_MASK_SEPARATE;
        static const String CSW_FX_STATE_LIGHT_ENABLE;
        static const String CSW_FX_STATE_LIGHT_AMBIENT;
        static const String CSW_FX_STATE_LIGHT_DIFFUSE;
        static const String CSW_FX_STATE_LIGHT_SPECULAR;
        static const String CSW_FX_STATE_LIGHT_POSITION;
        static const String CSW_FX_STATE_LIGHT_CONSTANT_ATTENUATION;
        static const String CSW_FX_STATE_LIGHT_LINEAR_ATTENUATION;
        static const String CSW_FX_STATE_LIGHT_QUADRATIC_ATTENUATION;
        static const String CSW_FX_STATE_LIGHT_SPOT_CUTOFF;
        static const String CSW_FX_STATE_LIGHT_SPOT_DIRECTION;
        static const String CSW_FX_STATE_LIGHT_SPOT_EXPONENT;
        static const String CSW_FX_STATE_TEXTURE1D;
        static const String CSW_FX_STATE_TEXTURE2D;
        static const String CSW_FX_STATE_TEXTURE3D;
        static const String CSW_FX_STATE_TEXTURECUBE;
        static const String CSW_FX_STATE_TEXTURERECT;
        static const String CSW_FX_STATE_TEXTUREDEPTH;
        static const String CSW_FX_STATE_TEXTURE1D_ENABLE;
        static const String CSW_FX_STATE_TEXTURE2D_ENABLE;
        static const String CSW_FX_STATE_TEXTURE3D_ENABLE;
        static const String CSW_FX_STATE_TEXTURECUBE_ENABLE;
        static const String CSW_FX_STATE_TEXTURERECT_ENABLE;
        static const String CSW_FX_STATE_TEXTUREDEPTH_ENABLE;
        static const String CSW_FX_STATE_TEXTURE_ENV_COLOR;
        static const String CSW_FX_STATE_TEXTURE_ENV_MODE;
        static const String CSW_FX_STATE_CLIP_PLANE;
        static const String CSW_FX_STATE_CLIP_PLANE_ENABLE;
        static const String CSW_FX_STATE_BLEND_COLOR;
        static const String CSW_FX_STATE_CLEAR_COLOR;
        static const String CSW_FX_STATE_CLEAR_STENCIL;
        static const String CSW_FX_STATE_CLEAR_DEPTH;
        static const String CSW_FX_STATE_COLOR_MASK;
        static const String CSW_FX_STATE_DEPTH_BOUNDS;
        static const String CSW_FX_STATE_DEPTH_MASK;
        static const String CSW_FX_STATE_DEPTH_RANGE;
        static const String CSW_FX_STATE_FOG_DENSITY;
        static const String CSW_FX_STATE_FOG_START;
        static const String CSW_FX_STATE_FOG_END;
        static const String CSW_FX_STATE_FOG_COLOR;
        static const String CSW_FX_STATE_LIGHT_MODEL_AMBIENT;
        static const String CSW_FX_STATE_LIGHTING_ENABLE;
        static const String CSW_FX_STATE_LINE_STIPPLE;
        static const String CSW_FX_STATE_LINE_STIPPLE_ENABLE;
        static const String CSW_FX_STATE_LINE_WIDTH;
        static const String CSW_FX_STATE_MATERIAL_AMBIENT;
        static const String CSW_FX_STATE_MATERIAL_DIFFUSE;
        static const String CSW_FX_STATE_MATERIAL_EMISSION;
        static const String CSW_FX_STATE_MATERIAL_SHININESS;
        static const String CSW_FX_STATE_MATERIAL_SPECULAR;
        static const String CSW_FX_STATE_MODEL_VIEW_MATRIX;
        static const String CSW_FX_STATE_POINT_DISTANCE_ATTENUATION;
        static const String CSW_FX_STATE_POINT_FADE_THRESHOLD_SIZE;
        static const String CSW_FX_STATE_POINT_SIZE;
        static const String CSW_FX_STATE_POINT_SIZE_MIN;
        static const String CSW_FX_STATE_POINT_SIZE_MAX;
        static const String CSW_FX_STATE_POLYGON_OFFSET;
        static const String CSW_FX_STATE_PROJECTION_MATRIX;
        static const String CSW_FX_STATE_SCISSOR;
        static const String CSW_FX_STATE_STENCIL_MASK;
        static const String CSW_FX_STATE_ALPHA_TEST_ENABLE;
        static const String CSW_FX_STATE_AUTO_NORMAL_ENABLE;
        static const String CSW_FX_STATE_BLEND_ENABLE;
        static const String CSW_FX_STATE_COLOR_LOGIC_OP_ENABLE;
        static const String CSW_FX_STATE_COLOR_MATERIAL_ENABLE;
        static const String CSW_FX_STATE_CULL_FACE_ENABLE;
        static const String CSW_FX_STATE_DEPTH_BOUNDS_ENABLE;
        static const String CSW_FX_STATE_DEPTH_CLAMP_ENABLE;
        static const String CSW_FX_STATE_DEPTH_TEST_ENABLE;
        static const String CSW_FX_STATE_DITHER_ENABLE;
        static const String CSW_FX_STATE_FOG_ENABLE;
        static const String CSW_FX_STATE_LIGHT_MODEL_LOCAL_VIEWER_ENABLE;
        static const String CSW_FX_STATE_LIGHT_MODEL_TWO_SIDE_ENABLE;
        static const String CSW_FX_STATE_LINE_SMOOTH_ENABLE;
        static const String CSW_FX_STATE_LOGIC_OP_ENABLE;
        static const String CSW_FX_STATE_MULTISAMPLE_ENABLE;
        static const String CSW_FX_STATE_NORMALIZE_ENABLE;
        static const String CSW_FX_STATE_POINT_SMOOTH_ENABLE;
        static const String CSW_FX_STATE_POLYGON_OFFSET_FILL_ENABLE;
        static const String CSW_FX_STATE_POLYGON_OFFSET_LINE_ENABLE;
        static const String CSW_FX_STATE_POLYGON_OFFSET_POINT_ENABLE;
        static const String CSW_FX_STATE_POLYGON_SMOOTH_ENABLE;
        static const String CSW_FX_STATE_POLYGON_STIPPLE_ENABLE;
        static const String CSW_FX_STATE_RESCALE_NORMAL_ENABLE;
        static const String CSW_FX_STATE_SAMPLE_ALPHA_TO_COVERAGE_ENABLE;
        static const String CSW_FX_STATE_SAMPLE_ALPHA_TO_ONE_ENABLE;
        static const String CSW_FX_STATE_SAMPLE_COVERAGE_ENABLE;
        static const String CSW_FX_STATE_SCISSOR_TEST_ENABLE;
        static const String CSW_FX_STATE_STENCIL_TEST_ENABLE;

    };

}

#endif // __COLLADASTREAMWRITER_CSWC_H__
