/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_CSWC_H__
#define __COLLADASTREAMWRITER_CSWC_H__

#include "COLLADAPrerequisites.h"

namespace COLLADA
{

    /** A class that contains all constants used by COLLADAStreamWriter*/
    class CSWC
    {

    public:

        static const String EMPTY_STRING;

        static const String XML_START_ELEMENT;
        static const String COLLADA_NAMESPACE;
        static const String COLLADA_VERSION;


        static const String COLLADA_ELEMENT_ACCESSOR;
        static const String COLLADA_ELEMENT_AMBIENT;
        static const String COLLADA_ELEMENT_ANIMATION;
        static const String COLLADA_ELEMENT_ANIMATION_CLIP;
        static const String COLLADA_ELEMENT_ASPECT_RATIO;
        static const String COLLADA_ELEMENT_ASSET;
        static const String COLLADA_ELEMENT_ATTENUATION_CONSTANT;
        static const String COLLADA_ELEMENT_ATTENUATION_LINEAR;
        static const String COLLADA_ELEMENT_ATTENUATION_QUADRATIC;
        static const String COLLADA_ELEMENT_AUTHOR;
        static const String COLLADA_ELEMENT_AUTHORING_TOOL;
        static const String COLLADA_ELEMENT_BLINN;
        static const String COLLADA_ELEMENT_BIND_MATERIAL;
        static const String COLLADA_ELEMENT_BIND_SHAPE_MATRIX;
        static const String COLLADA_ELEMENT_CAMERA;
        static const String COLLADA_ELEMENT_CAMERA_ORTHOGRAPHIC;
        static const String COLLADA_ELEMENT_CAMERA_PERSPECTIVE;
        static const String COLLADA_ELEMENT_CHANNEL;
        static const String COLLADA_ELEMENT_COMMENTS;
        static const String COLLADA_ELEMENT_CONSTANT;
        static const String COLLADA_ELEMENT_CONTRIBUTOR;
        static const String COLLADA_ELEMENT_CONTROLLER;
        static const String COLLADA_ELEMENT_COPYRIGHT;
        static const String COLLADA_ELEMENT_CREATED;
        static const String COLLADA_ELEMENT_COLLADA;
        static const String COLLADA_ELEMENT_COLOR;
        static const String COLLADA_ELEMENT_DIFFUSE;
        static const String COLLADA_ELEMENT_EFFECT;
        static const String COLLADA_ELEMENT_EMISSION;
        static const String COLLADA_ELEMENT_EXTRA;
        static const String COLLADA_ELEMENT_FALLOFF_ANGLE; 
        static const String COLLADA_ELEMENT_FALLOFF_EXPONENT;
        static const String COLLADA_ELEMENT_FLOAT;
        static const String COLLADA_ELEMENT_FLOAT_ARRAY;
        static const String COLLADA_ELEMENT_FORMAT;
        static const String COLLADA_ELEMENT_GEOMETRY;
        static const String COLLADA_ELEMENT_H;
        static const String COLLADA_ELEMENT_IDREF_ARRAY;
        static const String COLLADA_ELEMENT_IMAGE;
        static const String COLLADA_ELEMENT_INIT_FROM;
        static const String COLLADA_ELEMENT_INPUT;
        static const String COLLADA_ELEMENT_INSTANCE_ANIMATION;
        static const String COLLADA_ELEMENT_INSTANCE_CAMERA;
        static const String COLLADA_ELEMENT_INSTANCE_CONTROLLER;
        static const String COLLADA_ELEMENT_INSTANCE_EFFECT;
        static const String COLLADA_ELEMENT_INSTANCE_GEOMETRY;
        static const String COLLADA_ELEMENT_INSTANCE_LIGHT;
        static const String COLLADA_ELEMENT_INSTANCE_MATERIAL;
        static const String COLLADA_ELEMENT_INSTANCE_NODE;
        static const String COLLADA_ELEMENT_INSTANCE_VISUAL_SCENE;
        static const String COLLADA_ELEMENT_JOINTS;
        static const String COLLADA_ELEMENT_KEYWORDS;
        static const String COLLADA_ELEMENT_LAMBERT;
        static const String COLLADA_ELEMENT_LIBRARY_ANIMATIONS;
        static const String COLLADA_ELEMENT_LIBRARY_ANIMATION_CLIPS;
        static const String COLLADA_ELEMENT_LIBRARY_CAMERAS;
        static const String COLLADA_ELEMENT_LIBRARY_CONTROLLERS;
        static const String COLLADA_ELEMENT_LIBRARY_EFFECTS;
        static const String COLLADA_ELEMENT_LIBRARY_GEOMETRIES;
        static const String COLLADA_ELEMENT_LIBRARY_IMAGES;
        static const String COLLADA_ELEMENT_LIBRARY_LIGHTS;
        static const String COLLADA_ELEMENT_LIBRARY_MATERIALS;
        static const String COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES;
        static const String COLLADA_ELEMENT_LIGHT;
        static const String COLLADA_ELEMENT_LIGHT_INSTANCE_LIGHT;
        static const String COLLADA_ELEMENT_LIGHT_AMBIENT;
        static const String COLLADA_ELEMENT_LIGHT_DIRECTIONAL;
        static const String COLLADA_ELEMENT_LIGHT_POINT;
        static const String COLLADA_ELEMENT_LIGHT_SPOT;
        static const String COLLADA_ELEMENT_LOOKAT;
        static const String COLLADA_ELEMENT_MAGFILTER;
        static const String COLLADA_ELEMENT_MATERIAL;
        static const String COLLADA_ELEMENT_MATRIX;
        static const String COLLADA_ELEMENT_MESH;
        static const String COLLADA_ELEMENT_MINFILTER;
        static const String COLLADA_ELEMENT_MIPFILTER;
        static const String COLLADA_ELEMENT_MODIFIED;
        static const String COLLADA_ELEMENT_MORPH;
        static const String COLLADA_ELEMENT_NAME_ARRAY;
        static const String COLLADA_ELEMENT_NEWPARAM;
        static const String COLLADA_ELEMENT_NODE;
        static const String COLLADA_ELEMENT_OPTICS;
        static const String COLLADA_ELEMENT_P;
        static const String COLLADA_ELEMENT_PARAM;
        static const String COLLADA_ELEMENT_PH;
        static const String COLLADA_ELEMENT_PHONG;
        static const String COLLADA_ELEMENT_POLYLIST;
        static const String COLLADA_ELEMENT_POLYGONS;
        static const String COLLADA_ELEMENT_PROFILE_COMMON;
        static const String COLLADA_ELEMENT_REFLECTIVE;
        static const String COLLADA_ELEMENT_REFLECTIVITY;
        static const String COLLADA_ELEMENT_REVISION;
        static const String COLLADA_ELEMENT_ROTATE;
        static const String COLLADA_ELEMENT_SAMPLER;
        static const String COLLADA_ELEMENT_SAMPLER2D;
        static const String COLLADA_ELEMENT_SCALE;
        static const String COLLADA_ELEMENT_SCENE;
        static const String COLLADA_ELEMENT_SHININESS;
        static const String COLLADA_ELEMENT_SKELETON;
        static const String COLLADA_ELEMENT_SKEW;
        static const String COLLADA_ELEMENT_SKIN;
        static const String COLLADA_ELEMENT_SPECULAR;
        static const String COLLADA_ELEMENT_SOURCE;
        static const String COLLADA_ELEMENT_SOURCE_DATA;
        static const String COLLADA_ELEMENT_SUBJECT;
        static const String COLLADA_ELEMENT_SURFACE;
        static const String COLLADA_ELEMENT_TARGETS;
        static const String COLLADA_ELEMENT_TECHNIQUE;
        static const String COLLADA_ELEMENT_TECHNIQUE_COMMON;
        static const String COLLADA_ELEMENT_TEXTURE;
        static const String COLLADA_ELEMENT_TITLE;
        static const String COLLADA_ELEMENT_TRANSLATE;
        static const String COLLADA_ELEMENT_TRANSPARENCY;
        static const String COLLADA_ELEMENT_TRANSPARENT;
        static const String COLLADA_ELEMENT_TRIANGLES;
        static const String COLLADA_ELEMENT_UNIT;
        static const String COLLADA_ELEMENT_UP_AXIS;
        static const String COLLADA_ELEMENT_V;
        static const String COLLADA_ELEMENT_VCOUNT;
        static const String COLLADA_ELEMENT_VERTEX_WEIGHTS;
        static const String COLLADA_ELEMENT_VERTICES;
        static const String COLLADA_ELEMENT_VISUAL_SCENE;
        static const String COLLADA_ELEMENT_WRAP_S;
        static const String COLLADA_ELEMENT_WRAP_T;
        static const String COLLADA_ELEMENT_WRAP_P;
        static const String COLLADA_ELEMENT_XFOV;
        static const String COLLADA_ELEMENT_XMAG;
        static const String COLLADA_ELEMENT_YFOV;
        static const String COLLADA_ELEMENT_YMAG;
        static const String COLLADA_ELEMENT_ZFAR;
        static const String COLLADA_ELEMENT_ZNEAR;


        static const String COLLADA_ATTRIBUTE_COUNT;
        static const String COLLADA_ATTRIBUTE_END;
        static const String COLLADA_ATTRIBUTE_ID;
        static const String COLLADA_ATTRIBUTE_MATERIAL;
        static const String COLLADA_ATTRIBUTE_METER;
        static const String COLLADA_ATTRIBUTE_METHOD;
        static const String COLLADA_ATTRIBUTE_NAME;
        static const String COLLADA_ATTRIBUTE_OFFSET;
        static const String COLLADA_ATTRIBUTE_OPAQUE;
        static const String COLLADA_ATTRIBUTE_PROFILE;
        static const String COLLADA_ATTRIBUTE_SEMANTIC;
        static const String COLLADA_ATTRIBUTE_SET;
        static const String COLLADA_ATTRIBUTE_SID;
        static const String COLLADA_ATTRIBUTE_SOURCE;
        static const String COLLADA_ATTRIBUTE_START;
        static const String COLLADA_ATTRIBUTE_STRIDE;
        static const String COLLADA_ATTRIBUTE_SYMBOL;
        static const String COLLADA_ATTRIBUTE_TARGET;
        static const String COLLADA_ATTRIBUTE_TEXCOORD;
        static const String COLLADA_ATTRIBUTE_TEXTURE;
        static const String COLLADA_ATTRIBUTE_TYPE;
        static const String COLLADA_ATTRIBUTE_URL;
        static const String COLLADA_ATTRIBUTE_VERSION;
        static const String COLLADA_ATTRIBUTE_XMLNS;

        static const String COLLADA_SEMANTIC_BINDMATRIX;
        static const String COLLADA_SEMANTIC_COLOR;
        static const String COLLADA_SEMANTIC_CONTINUITY;
        static const String COLLADA_SEMANTIC_INPUT;
        static const String COLLADA_SEMANTIC_INTERPOLATION;
        static const String COLLADA_SEMANTIC_IN_TANGENT;
        static const String COLLADA_SEMANTIC_JOINT;
        static const String COLLADA_SEMANTIC_LINEAR_STEPS;
        static const String COLLADA_SEMANTIC_MORPH_WEIGHT;
        static const String COLLADA_SEMANTIC_MORPH_TARGET;
        static const String COLLADA_SEMANTIC_NORMAL;
        static const String COLLADA_SEMANTIC_OUTPUT;
        static const String COLLADA_SEMANTIC_OUT_TANGENT;
        static const String COLLADA_SEMANTIC_POSITION;
        static const String COLLADA_SEMANTIC_TEXCOORD;
        static const String COLLADA_SEMANTIC_VERTEX;
        static const String COLLADA_SEMANTIC_WEIGHT;

        static const String COLLADA_TEXT_X_UP;
        static const String COLLADA_TEXT_Y_UP;
        static const String COLLADA_TEXT_Z_UP;

        static const String COLLADA_NODE_TYPE_JOINT;
        static const String COLLADA_NODE_TYPE_NODE;

        static const String COLLADA_PARAM_TYPE_FLOAT;
        static const String COLLADA_PARAM_TYPE_FLOAT4x4;
        static const String COLLADA_PARAM_TYPE_NAME;
        static const String COLLADA_PARAM_TYPE_IDREF;

        static const String COLLADA_SAMPLER_FILTER_LINEAR;
        static const String COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_LINEAR;
        static const String COLLADA_SAMPLER_FILTER_LINEAR_MIPMAP_NEAREST;
        static const String COLLADA_SAMPLER_FILTER_NEAREST;
        static const String COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_LINEAR;
        static const String COLLADA_SAMPLER_FILTER_NEAREST_MIPMAP_NEAREST;
        static const String COLLADA_SAMPLER_FILTER_NONE;

        // texture wrap modes
        static const String COLLADA_TEXTURE_WRAP_NONE;
        static const String COLLADA_TEXTURE_WRAP_WRAP;
        static const String COLLADA_TEXTURE_WRAP_MIRROR;
        static const String COLLADA_TEXTURE_WRAP_CLAMP;
        static const String COLLADA_TEXTURE_WRAP_BORDER;
        static const String COLLADA_TEXTURE_WRAP_UNKNOWN;

        static const String COLLADA_SURFACE_TYPE_UNTYPED;
        static const String COLLADA_SURFACE_TYPE_1D;
        static const String COLLADA_SURFACE_TYPE_2D;
        static const String COLLADA_SURFACE_TYPE_3D;
        static const String COLLADA_SURFACE_TYPE_RECT;
        static const String COLLADA_SURFACE_TYPE_CUBE;
        static const String COLLADA_SURFACE_TYPE_DEPTH;

        static const String COLLADA_OPAQUE_TYPE_UNTYPED;
        static const String COLLADA_OPAQUE_TYPE_A_ONE;
        static const String COLLADA_OPAQUE_TYPE_RGB_ONE;
        static const String COLLADA_OPAQUE_TYPE_RGB_ZERO;
        static const String COLLADA_OPAQUE_TYPE_A_ZERO;




    };

}

#endif // __COLLADASTREAMWRITER_CSWC_H__
