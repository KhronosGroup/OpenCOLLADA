/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15VALIDATIONDATA_H__
#define __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15VALIDATIONDATA_H__


namespace COLLADASaxFWL15
{


ParserError::ErrorType validate__version_enum( ParserString value );
ParserError::ErrorType validate__version_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__version_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__version_enum__streamEnd( const ParserChar* value, size_t length );

struct COLLADA__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t library_animations;
    size_t library_animation_clips;
    size_t library_cameras;
    size_t library_controllers;
    size_t library_geometries;
    size_t library_effects;
    size_t library_force_fields;
    size_t library_images;
    size_t library_lights;
    size_t library_materials;
    size_t library_nodes;
    size_t library_physics_materials;
    size_t library_physics_models;
    size_t library_physics_scenes;
    size_t library_visual_scenes;
    size_t library_joints;
    size_t library_kinematics_models;
    size_t library_articulated_systems;
    size_t library_kinematics_scenes;
    size_t library_formulas;
    size_t scene;
    size_t extra;
};

struct asset__ValidationData
{
    size_t contributor;
    size_t coverage;
    size_t created;
    size_t keywords;
    size_t modified;
    size_t revision;
    size_t subject;
    size_t title;
    size_t unit;
    size_t up_axis;
    size_t extra;
};

struct contributor__ValidationData
{
    size_t author;
    size_t author_email;
    size_t author_website;
    size_t authoring_tool;
    size_t comments;
    size_t copyright;
    size_t source_data;
};

ParserError::ErrorType validate__author_email( ParserString value );
ParserError::ErrorType validate__author_email( const ParserChar* value, size_t length );
ParserError::ErrorType validate__author_email__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__author_email__streamEnd( const ParserChar* value, size_t length );

struct coverage__ValidationData
{
    size_t geographic_location;
};

struct geographic_location__ValidationData
{
    size_t longitude;
    size_t latitude;
    size_t altitude;
};

ParserError::ErrorType validate__altitude_mode_enum( ParserString value );
ParserError::ErrorType validate__altitude_mode_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__altitude_mode_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__altitude_mode_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__NMTOKEN( ParserString value );
ParserError::ErrorType validate__NMTOKEN( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NMTOKEN__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NMTOKEN__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__up_axis_enum( ParserString value );
ParserError::ErrorType validate__up_axis_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__up_axis_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__up_axis_enum__streamEnd( const ParserChar* value, size_t length );

struct extra__ValidationData
{
    size_t asset;
    size_t technique;
};

struct technique____technique_type__ValidationData
{
    size_t _wildcard;
};

struct library_animations__ValidationData
{
    size_t asset;
    size_t animation;
    size_t extra;
};

struct animation__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t source;
    size_t sampler;
    size_t channel;
    size_t animation;
    size_t extra;
};

struct source__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t token_array;
    size_t IDREF_array;
    size_t Name_array;
    size_t bool_array;
    size_t float_array;
    size_t int_array;
    size_t SIDREF_array;
    size_t technique_common;
    size_t technique;
};

struct IDREF_array__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__IDREFS( const ParserString*value, size_t length );
ParserError::ErrorType validate__IDREFS__stream( const ParserString*value, size_t length );
ParserError::ErrorType validate__IDREFS__streamEnd( const ParserString*value, size_t length );

ParserError::ErrorType validate__Name( ParserString value );
ParserError::ErrorType validate__Name( const ParserChar* value, size_t length );
ParserError::ErrorType validate__Name__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__Name__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__digits_type( const uint8 value );

ParserError::ErrorType validate__magnitude_type( const sint16 value );

ParserError::ErrorType validate__sidref_type( ParserString value );
ParserError::ErrorType validate__sidref_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sidref_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sidref_type__streamEnd( const ParserChar* value, size_t length );

struct source_type____technique_common__ValidationData
{
    size_t accessor;
};

struct accessor__ValidationData
{
    size_t param;
};

ParserError::ErrorType validate__sid_type( ParserString value );
ParserError::ErrorType validate__sid_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sid_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sid_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__sampler_behavior_enum( ParserString value );
ParserError::ErrorType validate__sampler_behavior_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sampler_behavior_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__sampler_behavior_enum__streamEnd( const ParserChar* value, size_t length );

struct sampler__ValidationData
{
    size_t input;
};

ParserError::ErrorType validate__urifragment_type( ParserString value );
ParserError::ErrorType validate__urifragment_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__urifragment_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__urifragment_type__streamEnd( const ParserChar* value, size_t length );

struct library_animation_clips__ValidationData
{
    size_t asset;
    size_t animation_clip;
    size_t extra;
};

struct animation_clip__ValidationData
{
    size_t asset;
    size_t instance_animation;
    size_t instance_formula;
    size_t extra;
};

struct instance_animation__ValidationData
{
    size_t extra;
};

struct instance_formula__ValidationData
{
    size_t setparam;
};

struct setparam____formula_setparam_type__ValidationData
{
    size_t _float;
    size_t _int;
    size_t SIDREF;
    size_t _bool;
    size_t connect_param;
};

struct library_cameras__ValidationData
{
    size_t asset;
    size_t camera;
    size_t extra;
};

struct camera__ValidationData
{
    size_t asset;
    size_t optics;
    size_t imager;
    size_t extra;
};

struct optics__ValidationData
{
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct optics__technique_common__ValidationData
{
    size_t orthographic;
    size_t perspective;
};

struct orthographic__ValidationData
{
    size_t validation_current_state;
    size_t xmag;
    size_t ymag;
    size_t aspect_ratio;
    size_t znear;
    size_t zfar;
};

struct perspective__ValidationData
{
    size_t validation_current_state;
    size_t xfov;
    size_t yfov;
    size_t aspect_ratio;
    size_t znear;
    size_t zfar;
};

struct imager__ValidationData
{
    size_t technique;
    size_t extra;
};

struct library_controllers__ValidationData
{
    size_t asset;
    size_t controller;
    size_t extra;
};

struct controller__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t skin;
    size_t morph;
    size_t extra;
};

struct skin__ValidationData
{
    size_t bind_shape_matrix;
    size_t source;
    size_t joints;
    size_t vertex_weights;
    size_t extra;
};

struct bind_shape_matrix__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4x4_type( const float* value, size_t length );
ParserError::ErrorType validate__float4x4_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x4_type__streamEnd( const float* value, size_t length );

struct joints__ValidationData
{
    size_t input;
    size_t extra;
};

struct vertex_weights__ValidationData
{
    size_t input;
    size_t vcount;
    size_t v;
    size_t extra;
};

ParserError::ErrorType validate__morph_method_enum( ParserString value );
ParserError::ErrorType validate__morph_method_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__morph_method_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__morph_method_enum__streamEnd( const ParserChar* value, size_t length );

struct morph__ValidationData
{
    size_t source;
    size_t targets;
    size_t extra;
};

struct targets__ValidationData
{
    size_t input;
    size_t extra;
};

struct library_geometries__ValidationData
{
    size_t asset;
    size_t geometry;
    size_t extra;
};

struct geometry__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t convex_mesh;
    size_t mesh;
    size_t spline;
    size_t brep;
    size_t extra;
};

struct convex_mesh__ValidationData
{
    size_t validation_current_state;
    size_t source;
    size_t vertices;
    size_t lines;
    size_t linestrips;
    size_t polygons;
    size_t polylist;
    size_t triangles;
    size_t trifans;
    size_t tristrips;
    size_t extra;
};

struct vertices__ValidationData
{
    size_t input;
    size_t extra;
};

ParserError::ErrorType validate__NCName( ParserString value );
ParserError::ErrorType validate__NCName( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NCName__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NCName__streamEnd( const ParserChar* value, size_t length );

struct lines__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct linestrips__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct polygons__ValidationData
{
    size_t validation_current_state;
    size_t input;
    size_t p;
    size_t ph;
    size_t extra;
};

struct ph__ValidationData
{
    size_t p;
    size_t h;
};

struct polylist__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct triangles__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct trifans__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct tristrips__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct mesh__ValidationData
{
    size_t validation_current_state;
    size_t source;
    size_t vertices;
    size_t lines;
    size_t linestrips;
    size_t polygons;
    size_t polylist;
    size_t triangles;
    size_t trifans;
    size_t tristrips;
    size_t extra;
};

struct spline__ValidationData
{
    size_t source;
    size_t control_vertices;
    size_t extra;
};

struct spline_type____control_vertices__ValidationData
{
    size_t input;
    size_t extra;
};

struct brep__ValidationData
{
    size_t curves;
    size_t surface_curves;
    size_t surfaces;
    size_t source;
    size_t vertices;
    size_t edges;
    size_t wires;
    size_t faces;
    size_t pcurves;
    size_t shells;
    size_t solids;
    size_t extra;
};

struct curves__ValidationData
{
    size_t curve;
    size_t extra;
};

struct curve__ValidationData
{
    size_t validation_current_state;
    size_t line;
    size_t circle;
    size_t ellipse;
    size_t parabola;
    size_t hyperbola;
    size_t nurbs;
    size_t orient;
    size_t origin;
};

struct line__ValidationData
{
    size_t origin;
    size_t direction;
    size_t extra;
};

struct origin____float3_type__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3_type( const float* value, size_t length );
ParserError::ErrorType validate__float3_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3_type__streamEnd( const float* value, size_t length );

struct circle__ValidationData
{
    size_t radius;
    size_t extra;
};

struct ellipse__ValidationData
{
    size_t radius;
    size_t extra;
};

struct radius____float2_type__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2_type( const float* value, size_t length );
ParserError::ErrorType validate__float2_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2_type__streamEnd( const float* value, size_t length );

struct parabola__ValidationData
{
    size_t focal;
    size_t extra;
};

struct hyperbola__ValidationData
{
    size_t radius;
    size_t extra;
};

struct nurbs__ValidationData
{
    size_t source;
    size_t control_vertices;
    size_t extra;
};

struct nurbs_type____control_vertices__ValidationData
{
    size_t input;
    size_t extra;
};

struct orient__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4_type( const float* value, size_t length );
ParserError::ErrorType validate__float4_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4_type__streamEnd( const float* value, size_t length );

struct origin____origin_type__ValidationData
{
    size_t validationWholeSize;
};

struct surface_curves__ValidationData
{
    size_t curve;
    size_t extra;
};

struct surfaces__ValidationData
{
    size_t surface;
    size_t extra;
};

struct surface__ValidationData
{
    size_t validation_current_state;
    size_t plane;
    size_t sphere;
    size_t torus;
    size_t swept_surface;
    size_t nurbs_surface;
    size_t cone;
    size_t cylinder;
    size_t orient;
    size_t origin;
};

struct plane__ValidationData
{
    size_t equation;
    size_t extra;
};

struct sphere__ValidationData
{
    size_t radius;
    size_t extra;
};

struct torus__ValidationData
{
    size_t radius;
    size_t extra;
};

struct swept_surface__ValidationData
{
    size_t validation_current_state;
    size_t curve;
    size_t direction;
    size_t origin;
    size_t axis;
    size_t extra;
};

struct nurbs_surface__ValidationData
{
    size_t source;
    size_t control_vertices;
    size_t extra;
};

struct nurbs_surface_type____control_vertices__ValidationData
{
    size_t input;
    size_t extra;
};

struct cone__ValidationData
{
    size_t radius;
    size_t angle;
    size_t extra;
};

struct surface_type____cylinder__ValidationData
{
    size_t radius;
    size_t extra;
};

struct edges__ValidationData
{
    size_t input;
    size_t p;
    size_t extra;
};

struct wires__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct faces__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct pcurves__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct shells__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct solids__ValidationData
{
    size_t input;
    size_t vcount;
    size_t p;
    size_t extra;
};

struct library_effects__ValidationData
{
    size_t asset;
    size_t effect;
    size_t extra;
};

struct effect__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t annotate;
    size_t newparam;
    size_t profile_COMMON;
    size_t profile_BRIDGE;
    size_t profile_GLES2;
    size_t profile_GLSL;
    size_t profile_CG;
    size_t profile_GLES;
    size_t extra;
};

struct annotate__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x2;
    size_t float3x3;
    size_t float4x4;
    size_t string;
};

struct bool2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool2_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool2_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool2_type__streamEnd( const bool* value, size_t length );

struct bool3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool3_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool3_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool3_type__streamEnd( const bool* value, size_t length );

struct bool4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool4_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool4_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool4_type__streamEnd( const bool* value, size_t length );

struct int2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int2_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int2_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int2_type__streamEnd( const sint64* value, size_t length );

struct int3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int3_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int3_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int3_type__streamEnd( const sint64* value, size_t length );

struct int4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int4_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int4_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int4_type__streamEnd( const sint64* value, size_t length );

struct float2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x2_type( const float* value, size_t length );
ParserError::ErrorType validate__float2x2_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x2_type__streamEnd( const float* value, size_t length );

struct float3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x3_type( const float* value, size_t length );
ParserError::ErrorType validate__float3x3_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x3_type__streamEnd( const float* value, size_t length );

struct newparam____fx_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
};

ParserError::ErrorType validate__fx_modifier_enum( ParserString value );
ParserError::ErrorType validate__fx_modifier_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_modifier_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_modifier_enum__streamEnd( const ParserChar* value, size_t length );

struct float2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x3_type( const float* value, size_t length );
ParserError::ErrorType validate__float2x3_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x3_type__streamEnd( const float* value, size_t length );

struct float2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x4_type( const float* value, size_t length );
ParserError::ErrorType validate__float2x4_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x4_type__streamEnd( const float* value, size_t length );

struct float3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x2_type( const float* value, size_t length );
ParserError::ErrorType validate__float3x2_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x2_type__streamEnd( const float* value, size_t length );

struct float3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x4_type( const float* value, size_t length );
ParserError::ErrorType validate__float3x4_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x4_type__streamEnd( const float* value, size_t length );

struct float4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4x2_type( const float* value, size_t length );
ParserError::ErrorType validate__float4x2_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x2_type__streamEnd( const float* value, size_t length );

struct float4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4x3_type( const float* value, size_t length );
ParserError::ErrorType validate__float4x3_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x3_type__streamEnd( const float* value, size_t length );

struct sampler1D__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct instance_image__ValidationData
{
    size_t extra;
};

ParserError::ErrorType validate__fx_sampler_wrap_enum( ParserString value );
ParserError::ErrorType validate__fx_sampler_wrap_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_wrap_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_wrap_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_sampler_min_filter_enum( ParserString value );
ParserError::ErrorType validate__fx_sampler_min_filter_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_min_filter_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_min_filter_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_sampler_mag_filter_enum( ParserString value );
ParserError::ErrorType validate__fx_sampler_mag_filter_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_mag_filter_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_mag_filter_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_sampler_mip_filter_enum( ParserString value );
ParserError::ErrorType validate__fx_sampler_mip_filter_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_mip_filter_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_mip_filter_enum__streamEnd( const ParserChar* value, size_t length );

struct border_color__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__fx_color_type( const float* value, size_t length );
ParserError::ErrorType validate__fx_color_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__fx_color_type__streamEnd( const float* value, size_t length );

struct sampler2D____fx_sampler2D_type__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct sampler3D__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct samplerCUBE__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct samplerRECT__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct samplerDEPTH__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct profile_COMMON__ValidationData
{
    size_t asset;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____fx_common_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t semantic;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t sampler2D;
};

struct profile_common_type____technique__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t constant;
    size_t lambert;
    size_t phong;
    size_t blinn;
    size_t extra;
};

struct profile_COMMON__technique__constant__ValidationData
{
    size_t emission;
    size_t reflective;
    size_t reflectivity;
    size_t transparent;
    size_t transparency;
    size_t index_of_refraction;
};

struct emission__ValidationData
{
    size_t color;
    size_t param;
    size_t texture;
};

struct fx_common_color_or_texture_type____color__ValidationData
{
    size_t validationWholeSize;
};

struct texture__ValidationData
{
    size_t extra;
};

struct reflectivity__ValidationData
{
    size_t _float;
    size_t param;
};

ParserError::ErrorType validate__fx_opaque_enum( ParserString value );
ParserError::ErrorType validate__fx_opaque_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_opaque_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_opaque_enum__streamEnd( const ParserChar* value, size_t length );

struct transparent__ValidationData
{
    size_t color;
    size_t param;
    size_t texture;
};

struct lambert__ValidationData
{
    size_t emission;
    size_t ambient;
    size_t diffuse;
    size_t reflective;
    size_t reflectivity;
    size_t transparent;
    size_t transparency;
    size_t index_of_refraction;
};

struct phong__ValidationData
{
    size_t emission;
    size_t ambient;
    size_t diffuse;
    size_t specular;
    size_t shininess;
    size_t reflective;
    size_t reflectivity;
    size_t transparent;
    size_t transparency;
    size_t index_of_refraction;
};

struct blinn__ValidationData
{
    size_t emission;
    size_t ambient;
    size_t diffuse;
    size_t specular;
    size_t shininess;
    size_t reflective;
    size_t reflectivity;
    size_t transparent;
    size_t transparency;
    size_t index_of_refraction;
};

struct profile_BRIDGE__ValidationData
{
    size_t asset;
    size_t extra;
};

struct profile_GLES2__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t include;
    size_t code;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct profile_gles2_type____newparam__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bvec2;
    size_t bvec3;
    size_t bvec4;
    size_t _float;
    size_t vec2;
    size_t vec3;
    size_t vec4;
    size_t mat2;
    size_t mat3;
    size_t mat4;
    size_t _int;
    size_t ivec2;
    size_t ivec3;
    size_t ivec4;
    size_t _enum;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t usertype;
    size_t array;
};

struct profile_GLES2__newparam__usertype__ValidationData
{
    size_t setparam;
};

struct profile_GLES2__newparam__usertype__setparam__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bvec2;
    size_t bvec3;
    size_t bvec4;
    size_t _float;
    size_t vec2;
    size_t vec3;
    size_t vec4;
    size_t mat2;
    size_t mat3;
    size_t mat4;
    size_t _int;
    size_t ivec2;
    size_t ivec3;
    size_t ivec4;
    size_t _enum;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t usertype;
    size_t array;
};

ParserError::ErrorType validate__positiveInteger( const uint64 value );

struct profile_GLES2__newparam__usertype__setparam__array__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bvec2;
    size_t bvec3;
    size_t bvec4;
    size_t _float;
    size_t vec2;
    size_t vec3;
    size_t vec4;
    size_t mat2;
    size_t mat3;
    size_t mat4;
    size_t _int;
    size_t ivec2;
    size_t ivec3;
    size_t ivec4;
    size_t _enum;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t usertype;
    size_t array;
};

struct profile_gles2_type____technique__ValidationData
{
    size_t asset;
    size_t annotate;
    size_t pass;
    size_t extra;
};

struct pass____gles2_pass_type__ValidationData
{
    size_t annotate;
    size_t states;
    size_t program;
    size_t evaluate;
    size_t extra;
};

struct gles2_pass_type____states__ValidationData
{
    size_t validation_current_state;
    size_t blend_color;
    size_t blend_equation;
    size_t blend_equation_separate;
    size_t blend_func;
    size_t blend_func_separate;
    size_t color_mask;
    size_t cull_face;
    size_t depth_func;
    size_t depth_mask;
    size_t depth_range;
    size_t front_face;
    size_t line_width;
    size_t polygon_offset;
    size_t point_size;
    size_t sample_coverage;
    size_t scissor;
    size_t stencil_func;
    size_t stencil_func_separate;
    size_t stencil_mask;
    size_t stencil_mask_separate;
    size_t stencil_op;
    size_t stencil_op_separate;
    size_t blend_enable;
    size_t cull_face_enable;
    size_t depth_test_enable;
    size_t dither_enable;
    size_t polygon_offset_fill_enable;
    size_t point_size_enable;
    size_t sample_alpha_to_coverage_enable;
    size_t sample_coverage_enable;
    size_t scissor_test_enable;
    size_t stencil_test_enable;
};

ParserError::ErrorType validate__gl_blend_equation_enum( ParserString value );
ParserError::ErrorType validate__gl_blend_equation_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_equation_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_equation_enum__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES2__technique__pass__states__blend_equation_separate__ValidationData
{
    size_t rgb;
    size_t alpha;
};

struct profile_GLES2__technique__pass__states__blend_func__ValidationData
{
    size_t src;
    size_t dest;
};

ParserError::ErrorType validate__gl_blend_enum( ParserString value );
ParserError::ErrorType validate__gl_blend_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_enum__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES2__technique__pass__states__blend_func_separate__ValidationData
{
    size_t src_rgb;
    size_t dest_rgb;
    size_t src_alpha;
    size_t dest_alpha;
};

ParserError::ErrorType validate__gl_face_enum( ParserString value );
ParserError::ErrorType validate__gl_face_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_face_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_face_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_func_enum( ParserString value );
ParserError::ErrorType validate__gl_func_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_func_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_func_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_front_face_enum( ParserString value );
ParserError::ErrorType validate__gl_front_face_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_front_face_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_front_face_enum__streamEnd( const ParserChar* value, size_t length );

struct sample_coverage__ValidationData
{
    size_t value;
    size_t invert;
};

struct profile_GLES2__technique__pass__states__stencil_func__ValidationData
{
    size_t func;
    size_t ref;
    size_t mask;
};

struct profile_GLES2__technique__pass__states__stencil_func_separate__ValidationData
{
    size_t front;
    size_t back;
    size_t ref;
    size_t mask;
};

struct profile_GLES2__technique__pass__states__stencil_mask_separate__ValidationData
{
    size_t face;
    size_t mask;
};

struct profile_GLES2__technique__pass__states__stencil_op__ValidationData
{
    size_t fail;
    size_t zfail;
    size_t zpass;
};

ParserError::ErrorType validate__gl_stencil_op_enum( ParserString value );
ParserError::ErrorType validate__gl_stencil_op_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_stencil_op_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_stencil_op_enum__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES2__technique__pass__states__stencil_op_separate__ValidationData
{
    size_t face;
    size_t fail;
    size_t zfail;
    size_t zpass;
};

struct program____gles2_program_type__ValidationData
{
    size_t shader;
    size_t linker;
    size_t bind_attribute;
    size_t bind_uniform;
};

ParserError::ErrorType validate__fx_pipeline_stage_enum( ParserString value );
ParserError::ErrorType validate__fx_pipeline_stage_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_pipeline_stage_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_pipeline_stage_enum__streamEnd( const ParserChar* value, size_t length );

struct shader____gles2_shader_type__ValidationData
{
    size_t sources;
    size_t compiler;
    size_t extra;
};

struct gles2_shader_type____sources__ValidationData
{
    size_t validation_current_state;
    size_t inline_;
    size_t import;
};

struct compiler__ValidationData
{
    size_t binary;
};

struct binary__ValidationData
{
    size_t ref;
    size_t hex;
};

struct gles2_program_type____bind_attribute__ValidationData
{
    size_t semantic;
};

struct gles2_program_type____bind_uniform__ValidationData
{
    size_t validation_current_state;
    size_t param;
    size_t _bool;
    size_t bvec2;
    size_t bvec3;
    size_t bvec4;
    size_t _float;
    size_t vec2;
    size_t vec3;
    size_t vec4;
    size_t mat2;
    size_t mat3;
    size_t mat4;
    size_t _int;
    size_t ivec2;
    size_t ivec3;
    size_t ivec4;
    size_t _enum;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t usertype;
    size_t array;
};

struct gles2_pass_type____evaluate__ValidationData
{
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t stencil_clear;
    size_t depth_clear;
    size_t draw;
};

ParserError::ErrorType validate__image_face_enum( ParserString value );
ParserError::ErrorType validate__image_face_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_face_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_face_enum__streamEnd( const ParserChar* value, size_t length );

struct color_target__ValidationData
{
    size_t param;
    size_t instance_image;
};

struct depth_target__ValidationData
{
    size_t param;
    size_t instance_image;
};

struct stencil_target__ValidationData
{
    size_t param;
    size_t instance_image;
};

struct color_clear__ValidationData
{
    size_t validationWholeSize;
};

struct profile_GLSL__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t code;
    size_t include;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____glsl_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x2;
    size_t float3x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct array____glsl_array_type__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x2;
    size_t float3x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct profile_glsl_type____technique__ValidationData
{
    size_t asset;
    size_t annotate;
    size_t pass;
    size_t extra;
};

struct profile_GLSL__technique__pass__ValidationData
{
    size_t annotate;
    size_t states;
    size_t program;
    size_t evaluate;
    size_t extra;
};

struct profile_GLSL__technique__pass__states__ValidationData
{
    size_t validation_current_state;
    size_t alpha_func;
    size_t blend_func;
    size_t blend_func_separate;
    size_t blend_equation;
    size_t blend_equation_separate;
    size_t color_material;
    size_t cull_face;
    size_t depth_func;
    size_t fog_mode;
    size_t fog_coord_src;
    size_t front_face;
    size_t light_model_color_control;
    size_t logic_op;
    size_t polygon_mode;
    size_t shade_model;
    size_t stencil_func;
    size_t stencil_op;
    size_t stencil_func_separate;
    size_t stencil_op_separate;
    size_t stencil_mask_separate;
    size_t light_enable;
    size_t light_ambient;
    size_t light_diffuse;
    size_t light_specular;
    size_t light_position;
    size_t light_constant_attenuation;
    size_t light_linear_attenuation;
    size_t light_quadratic_attenuation;
    size_t light_spot_cutoff;
    size_t light_spot_direction;
    size_t light_spot_exponent;
    size_t texture1D;
    size_t texture2D;
    size_t texture3D;
    size_t textureCUBE;
    size_t textureRECT;
    size_t textureDEPTH;
    size_t texture1D_enable;
    size_t texture2D_enable;
    size_t texture3D_enable;
    size_t textureCUBE_enable;
    size_t textureRECT_enable;
    size_t textureDEPTH_enable;
    size_t texture_env_color;
    size_t texture_env_mode;
    size_t clip_plane;
    size_t clip_plane_enable;
    size_t blend_color;
    size_t color_mask;
    size_t depth_bounds;
    size_t depth_mask;
    size_t depth_range;
    size_t fog_density;
    size_t fog_start;
    size_t fog_end;
    size_t fog_color;
    size_t light_model_ambient;
    size_t lighting_enable;
    size_t line_stipple;
    size_t line_width;
    size_t material_ambient;
    size_t material_diffuse;
    size_t material_emission;
    size_t material_shininess;
    size_t material_specular;
    size_t model_view_matrix;
    size_t point_distance_attenuation;
    size_t point_fade_threshold_size;
    size_t point_size;
    size_t point_size_min;
    size_t point_size_max;
    size_t polygon_offset;
    size_t projection_matrix;
    size_t scissor;
    size_t stencil_mask;
    size_t alpha_test_enable;
    size_t blend_enable;
    size_t color_logic_op_enable;
    size_t color_material_enable;
    size_t cull_face_enable;
    size_t depth_bounds_enable;
    size_t depth_clamp_enable;
    size_t depth_test_enable;
    size_t dither_enable;
    size_t fog_enable;
    size_t light_model_local_viewer_enable;
    size_t light_model_two_side_enable;
    size_t line_smooth_enable;
    size_t line_stipple_enable;
    size_t logic_op_enable;
    size_t multisample_enable;
    size_t normalize_enable;
    size_t point_smooth_enable;
    size_t polygon_offset_fill_enable;
    size_t polygon_offset_line_enable;
    size_t polygon_offset_point_enable;
    size_t polygon_smooth_enable;
    size_t polygon_stipple_enable;
    size_t rescale_normal_enable;
    size_t sample_alpha_to_coverage_enable;
    size_t sample_alpha_to_one_enable;
    size_t sample_coverage_enable;
    size_t scissor_test_enable;
    size_t stencil_test_enable;
};

struct profile_GLSL__technique__pass__states__alpha_func__ValidationData
{
    size_t func;
    size_t value;
};

ParserError::ErrorType validate__gl_alpha_value_type( const float value );

struct profile_GLSL__technique__pass__states__blend_func__ValidationData
{
    size_t src;
    size_t dest;
};

struct profile_GLSL__technique__pass__states__blend_func_separate__ValidationData
{
    size_t src_rgb;
    size_t dest_rgb;
    size_t src_alpha;
    size_t dest_alpha;
};

struct profile_GLSL__technique__pass__states__blend_equation_separate__ValidationData
{
    size_t rgb;
    size_t alpha;
};

struct color_material__ValidationData
{
    size_t face;
    size_t mode;
};

ParserError::ErrorType validate__gl_material_enum( ParserString value );
ParserError::ErrorType validate__gl_material_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_material_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_material_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_fog_enum( ParserString value );
ParserError::ErrorType validate__gl_fog_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_fog_coord_src_enum( ParserString value );
ParserError::ErrorType validate__gl_fog_coord_src_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_coord_src_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_coord_src_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_light_model_color_control_enum( ParserString value );
ParserError::ErrorType validate__gl_light_model_color_control_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_light_model_color_control_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_light_model_color_control_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_logic_op_enum( ParserString value );
ParserError::ErrorType validate__gl_logic_op_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_logic_op_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_logic_op_enum__streamEnd( const ParserChar* value, size_t length );

struct polygon_mode__ValidationData
{
    size_t face;
    size_t mode;
};

ParserError::ErrorType validate__gl_polygon_mode_enum( ParserString value );
ParserError::ErrorType validate__gl_polygon_mode_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_polygon_mode_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_polygon_mode_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_shade_model_enum( ParserString value );
ParserError::ErrorType validate__gl_shade_model_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_shade_model_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_shade_model_enum__streamEnd( const ParserChar* value, size_t length );

struct profile_GLSL__technique__pass__states__stencil_func__ValidationData
{
    size_t func;
    size_t ref;
    size_t mask;
};

struct profile_GLSL__technique__pass__states__stencil_op__ValidationData
{
    size_t fail;
    size_t zfail;
    size_t zpass;
};

struct profile_GLSL__technique__pass__states__stencil_func_separate__ValidationData
{
    size_t front;
    size_t back;
    size_t ref;
    size_t mask;
};

struct profile_GLSL__technique__pass__states__stencil_op_separate__ValidationData
{
    size_t face;
    size_t fail;
    size_t zfail;
    size_t zpass;
};

struct profile_GLSL__technique__pass__states__stencil_mask_separate__ValidationData
{
    size_t face;
    size_t mask;
};

struct texture1D__ValidationData
{
    size_t value;
    size_t param;
};

struct texture2D__ValidationData
{
    size_t value;
    size_t param;
};

struct texture3D__ValidationData
{
    size_t value;
    size_t param;
};

struct textureCUBE__ValidationData
{
    size_t value;
    size_t param;
};

struct textureRECT__ValidationData
{
    size_t value;
    size_t param;
};

struct textureDEPTH__ValidationData
{
    size_t value;
    size_t param;
};

struct program____glsl_program_type__ValidationData
{
    size_t shader;
    size_t bind_attribute;
    size_t bind_uniform;
};

struct shader____glsl_shader_type__ValidationData
{
    size_t sources;
    size_t extra;
};

struct sources____fx_sources_type__ValidationData
{
    size_t validation_current_state;
    size_t inline_;
    size_t import;
};

struct glsl_program_type____bind_attribute__ValidationData
{
    size_t semantic;
};

struct glsl_program_type____bind_uniform__ValidationData
{
    size_t validation_current_state;
    size_t param;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x2;
    size_t float3x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct profile_GLSL__technique__pass__evaluate__ValidationData
{
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
};

struct profile_CG__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t code;
    size_t include;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____cg_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool2x1;
    size_t bool2x2;
    size_t bool2x3;
    size_t bool2x4;
    size_t bool3x1;
    size_t bool3x2;
    size_t bool3x3;
    size_t bool3x4;
    size_t bool4x1;
    size_t bool4x2;
    size_t bool4x3;
    size_t bool4x4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int2x1;
    size_t int2x2;
    size_t int2x3;
    size_t int2x4;
    size_t int3x1;
    size_t int3x2;
    size_t int3x3;
    size_t int3x4;
    size_t int4x1;
    size_t int4x2;
    size_t int4x3;
    size_t int4x4;
    size_t half;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half2x1;
    size_t half2x2;
    size_t half2x3;
    size_t half2x4;
    size_t half3x1;
    size_t half3x2;
    size_t half3x3;
    size_t half3x4;
    size_t half4x1;
    size_t half4x2;
    size_t half4x3;
    size_t _half4x4;
    size_t fixed;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed2x1;
    size_t fixed2x2;
    size_t fixed2x3;
    size_t fixed2x4;
    size_t fixed3x1;
    size_t fixed3x2;
    size_t fixed3x3;
    size_t fixed3x4;
    size_t fixed4x1;
    size_t fixed4x2;
    size_t fixed4x3;
    size_t fixed4x4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t array;
    size_t usertype;
};

struct bool2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool2x2_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x2_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x2_type__streamEnd( const bool* value, size_t length );

struct bool2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool2x3_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x3_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x3_type__streamEnd( const bool* value, size_t length );

struct bool2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool2x4_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x4_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool2x4_type__streamEnd( const bool* value, size_t length );

struct bool3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool3x2_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x2_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x2_type__streamEnd( const bool* value, size_t length );

struct bool3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool3x3_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x3_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x3_type__streamEnd( const bool* value, size_t length );

struct bool3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool3x4_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x4_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool3x4_type__streamEnd( const bool* value, size_t length );

struct bool4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool4x2_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x2_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x2_type__streamEnd( const bool* value, size_t length );

struct bool4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool4x3_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x3_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x3_type__streamEnd( const bool* value, size_t length );

struct bool4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool4x4_type( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x4_type__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool4x4_type__streamEnd( const bool* value, size_t length );

struct int2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int2x2_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x2_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x2_type__streamEnd( const sint64* value, size_t length );

struct int2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int2x3_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x3_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x3_type__streamEnd( const sint64* value, size_t length );

struct int2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int2x4_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x4_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int2x4_type__streamEnd( const sint64* value, size_t length );

struct int3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int3x2_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x2_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x2_type__streamEnd( const sint64* value, size_t length );

struct int3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int3x3_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x3_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x3_type__streamEnd( const sint64* value, size_t length );

struct int3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int3x4_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x4_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int3x4_type__streamEnd( const sint64* value, size_t length );

struct int4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int4x2_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x2_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x2_type__streamEnd( const sint64* value, size_t length );

struct int4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int4x3_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x3_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x3_type__streamEnd( const sint64* value, size_t length );

struct int4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int4x4_type( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x4_type__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int4x4_type__streamEnd( const sint64* value, size_t length );

struct array____cg_array_type__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool2x1;
    size_t bool2x2;
    size_t bool2x3;
    size_t bool2x4;
    size_t bool3x1;
    size_t bool3x2;
    size_t bool3x3;
    size_t bool3x4;
    size_t bool4x1;
    size_t bool4x2;
    size_t bool4x3;
    size_t bool4x4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int2x1;
    size_t int2x2;
    size_t int2x3;
    size_t int2x4;
    size_t int3x1;
    size_t int3x2;
    size_t int3x3;
    size_t int3x4;
    size_t int4x1;
    size_t int4x2;
    size_t int4x3;
    size_t int4x4;
    size_t half;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half2x1;
    size_t half2x2;
    size_t half2x3;
    size_t half2x4;
    size_t half3x1;
    size_t half3x2;
    size_t half3x3;
    size_t half3x4;
    size_t half4x1;
    size_t half4x2;
    size_t half4x3;
    size_t _half4x4;
    size_t fixed;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed2x1;
    size_t fixed2x2;
    size_t fixed2x3;
    size_t fixed2x4;
    size_t fixed3x1;
    size_t fixed3x2;
    size_t fixed3x3;
    size_t fixed3x4;
    size_t fixed4x1;
    size_t fixed4x2;
    size_t fixed4x3;
    size_t fixed4x4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t array;
    size_t usertype;
};

struct usertype____cg_user_type__ValidationData
{
    size_t setparam;
};

struct setparam____cg_setparam_type__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool2x1;
    size_t bool2x2;
    size_t bool2x3;
    size_t bool2x4;
    size_t bool3x1;
    size_t bool3x2;
    size_t bool3x3;
    size_t bool3x4;
    size_t bool4x1;
    size_t bool4x2;
    size_t bool4x3;
    size_t bool4x4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int2x1;
    size_t int2x2;
    size_t int2x3;
    size_t int2x4;
    size_t int3x1;
    size_t int3x2;
    size_t int3x3;
    size_t int3x4;
    size_t int4x1;
    size_t int4x2;
    size_t int4x3;
    size_t int4x4;
    size_t half;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half2x1;
    size_t half2x2;
    size_t half2x3;
    size_t half2x4;
    size_t half3x1;
    size_t half3x2;
    size_t half3x3;
    size_t half3x4;
    size_t half4x1;
    size_t half4x2;
    size_t half4x3;
    size_t _half4x4;
    size_t fixed;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed2x1;
    size_t fixed2x2;
    size_t fixed2x3;
    size_t fixed2x4;
    size_t fixed3x1;
    size_t fixed3x2;
    size_t fixed3x3;
    size_t fixed3x4;
    size_t fixed4x1;
    size_t fixed4x2;
    size_t fixed4x3;
    size_t fixed4x4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t array;
    size_t usertype;
};

struct profile_cg_type____technique__ValidationData
{
    size_t asset;
    size_t annotate;
    size_t pass;
    size_t extra;
};

struct pass____cg_pass_type__ValidationData
{
    size_t annotate;
    size_t states;
    size_t program;
    size_t evaluate;
    size_t extra;
};

struct cg_pass_type____states__ValidationData
{
    size_t validation_current_state;
    size_t alpha_func;
    size_t blend_func;
    size_t blend_func_separate;
    size_t blend_equation;
    size_t blend_equation_separate;
    size_t color_material;
    size_t cull_face;
    size_t depth_func;
    size_t fog_mode;
    size_t fog_coord_src;
    size_t front_face;
    size_t light_model_color_control;
    size_t logic_op;
    size_t polygon_mode;
    size_t shade_model;
    size_t stencil_func;
    size_t stencil_op;
    size_t stencil_func_separate;
    size_t stencil_op_separate;
    size_t stencil_mask_separate;
    size_t light_enable;
    size_t light_ambient;
    size_t light_diffuse;
    size_t light_specular;
    size_t light_position;
    size_t light_constant_attenuation;
    size_t light_linear_attenuation;
    size_t light_quadratic_attenuation;
    size_t light_spot_cutoff;
    size_t light_spot_direction;
    size_t light_spot_exponent;
    size_t texture1D;
    size_t texture2D;
    size_t texture3D;
    size_t textureCUBE;
    size_t textureRECT;
    size_t textureDEPTH;
    size_t texture1D_enable;
    size_t texture2D_enable;
    size_t texture3D_enable;
    size_t textureCUBE_enable;
    size_t textureRECT_enable;
    size_t textureDEPTH_enable;
    size_t texture_env_color;
    size_t texture_env_mode;
    size_t clip_plane;
    size_t clip_plane_enable;
    size_t blend_color;
    size_t color_mask;
    size_t depth_bounds;
    size_t depth_mask;
    size_t depth_range;
    size_t fog_density;
    size_t fog_start;
    size_t fog_end;
    size_t fog_color;
    size_t light_model_ambient;
    size_t lighting_enable;
    size_t line_stipple;
    size_t line_width;
    size_t material_ambient;
    size_t material_diffuse;
    size_t material_emission;
    size_t material_shininess;
    size_t material_specular;
    size_t model_view_matrix;
    size_t point_distance_attenuation;
    size_t point_fade_threshold_size;
    size_t point_size;
    size_t point_size_min;
    size_t point_size_max;
    size_t polygon_offset;
    size_t projection_matrix;
    size_t scissor;
    size_t stencil_mask;
    size_t alpha_test_enable;
    size_t blend_enable;
    size_t color_logic_op_enable;
    size_t color_material_enable;
    size_t cull_face_enable;
    size_t depth_bounds_enable;
    size_t depth_clamp_enable;
    size_t depth_test_enable;
    size_t dither_enable;
    size_t fog_enable;
    size_t light_model_local_viewer_enable;
    size_t light_model_two_side_enable;
    size_t line_smooth_enable;
    size_t line_stipple_enable;
    size_t logic_op_enable;
    size_t multisample_enable;
    size_t normalize_enable;
    size_t point_smooth_enable;
    size_t polygon_offset_fill_enable;
    size_t polygon_offset_line_enable;
    size_t polygon_offset_point_enable;
    size_t polygon_smooth_enable;
    size_t polygon_stipple_enable;
    size_t rescale_normal_enable;
    size_t sample_alpha_to_coverage_enable;
    size_t sample_alpha_to_one_enable;
    size_t sample_coverage_enable;
    size_t scissor_test_enable;
    size_t stencil_test_enable;
};

struct cg_pass_type____program__ValidationData
{
    size_t shader;
};

struct profile_CG__technique__pass__program__shader__ValidationData
{
    size_t sources;
    size_t compiler;
    size_t bind_uniform;
};

struct profile_CG__technique__pass__program__shader__sources__ValidationData
{
    size_t validation_current_state;
    size_t inline_;
    size_t import;
};

struct profile_CG__technique__pass__program__shader__bind_uniform__ValidationData
{
    size_t validation_current_state;
    size_t param;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool2x1;
    size_t bool2x2;
    size_t bool2x3;
    size_t bool2x4;
    size_t bool3x1;
    size_t bool3x2;
    size_t bool3x3;
    size_t bool3x4;
    size_t bool4x1;
    size_t bool4x2;
    size_t bool4x3;
    size_t bool4x4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int2x1;
    size_t int2x2;
    size_t int2x3;
    size_t int2x4;
    size_t int3x1;
    size_t int3x2;
    size_t int3x3;
    size_t int3x4;
    size_t int4x1;
    size_t int4x2;
    size_t int4x3;
    size_t int4x4;
    size_t half;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half2x1;
    size_t half2x2;
    size_t half2x3;
    size_t half2x4;
    size_t half3x1;
    size_t half3x2;
    size_t half3x3;
    size_t half3x4;
    size_t half4x1;
    size_t half4x2;
    size_t half4x3;
    size_t _half4x4;
    size_t fixed;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed2x1;
    size_t fixed2x2;
    size_t fixed2x3;
    size_t fixed2x4;
    size_t fixed3x1;
    size_t fixed3x2;
    size_t fixed3x3;
    size_t fixed3x4;
    size_t fixed4x1;
    size_t fixed4x2;
    size_t fixed4x3;
    size_t fixed4x4;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t array;
    size_t usertype;
};

struct cg_pass_type____evaluate__ValidationData
{
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
};

struct profile_GLES__ValidationData
{
    size_t asset;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____gles_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float1x1;
    size_t float1x2;
    size_t float1x3;
    size_t float1x4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t sampler2D;
    size_t _enum;
};

struct sampler2D____gles_sampler_type__ValidationData
{
    size_t validation_current_state;
    size_t instance_image;
    size_t texcoord;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t mip_max_level;
    size_t mip_bias;
    size_t extra;
};

ParserError::ErrorType validate__gles_sampler_wrap_enum( ParserString value );
ParserError::ErrorType validate__gles_sampler_wrap_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_sampler_wrap_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_sampler_wrap_enum__streamEnd( const ParserChar* value, size_t length );

struct profile_gles_type____technique__ValidationData
{
    size_t asset;
    size_t annotate;
    size_t pass;
    size_t extra;
};

struct profile_GLES__technique__pass__ValidationData
{
    size_t annotate;
    size_t states;
    size_t evaluate;
    size_t extra;
};

struct profile_GLES__technique__pass__states__ValidationData
{
    size_t validation_current_state;
    size_t alpha_func;
    size_t blend_func;
    size_t clip_plane;
    size_t color_mask;
    size_t cull_face;
    size_t depth_func;
    size_t depth_mask;
    size_t depth_range;
    size_t fog_color;
    size_t fog_density;
    size_t fog_mode;
    size_t fog_start;
    size_t fog_end;
    size_t front_face;
    size_t logic_op;
    size_t light_ambient;
    size_t light_diffuse;
    size_t light_specular;
    size_t light_position;
    size_t light_constant_attenuation;
    size_t light_linear_attenuation;
    size_t light_quadratic_attenuation;
    size_t light_spot_cutoff;
    size_t light_spot_direction;
    size_t light_spot_exponent;
    size_t light_model_ambient;
    size_t line_width;
    size_t material_ambient;
    size_t material_diffuse;
    size_t material_emission;
    size_t material_shininess;
    size_t material_specular;
    size_t model_view_matrix;
    size_t point_distance_attenuation;
    size_t point_fade_threshold_size;
    size_t point_size;
    size_t point_size_min;
    size_t point_size_max;
    size_t polygon_offset;
    size_t projection_matrix;
    size_t scissor;
    size_t shade_model;
    size_t stencil_func;
    size_t stencil_mask;
    size_t stencil_op;
    size_t texture_pipeline;
    size_t alpha_test_enable;
    size_t blend_enable;
    size_t clip_plane_enable;
    size_t color_logic_op_enable;
    size_t color_material_enable;
    size_t cull_face_enable;
    size_t depth_test_enable;
    size_t dither_enable;
    size_t fog_enable;
    size_t light_enable;
    size_t lighting_enable;
    size_t light_model_two_side_enable;
    size_t line_smooth_enable;
    size_t multisample_enable;
    size_t normalize_enable;
    size_t point_smooth_enable;
    size_t polygon_offset_fill_enable;
    size_t rescale_normal_enable;
    size_t sample_alpha_to_coverage_enable;
    size_t sample_alpha_to_one_enable;
    size_t sample_coverage_enable;
    size_t scissor_test_enable;
    size_t stencil_test_enable;
};

struct profile_GLES__technique__pass__states__alpha_func__ValidationData
{
    size_t func;
    size_t value;
};

struct profile_GLES__technique__pass__states__blend_func__ValidationData
{
    size_t src;
    size_t dest;
};

ParserError::ErrorType validate__gles_max_clip_planes_index_type( const uint64 value );

ParserError::ErrorType validate__gles_max_lights_index_type( const uint64 value );

struct profile_GLES__technique__pass__states__stencil_func__ValidationData
{
    size_t func;
    size_t ref;
    size_t mask;
};

struct profile_GLES__technique__pass__states__stencil_op__ValidationData
{
    size_t fail;
    size_t zfail;
    size_t zpass;
};

ParserError::ErrorType validate__gles_stencil_op_enum( ParserString value );
ParserError::ErrorType validate__gles_stencil_op_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_stencil_op_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_stencil_op_enum__streamEnd( const ParserChar* value, size_t length );

struct texture_pipeline__ValidationData
{
    size_t value;
};

struct value____gles_texture_pipeline_type__ValidationData
{
    size_t texcombiner;
    size_t texenv;
    size_t extra;
};

struct texcombiner__ValidationData
{
    size_t constant;
    size_t RGB;
    size_t alpha;
};

ParserError::ErrorType validate__gles_texcombiner_operator_rgb_enum( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operator_rgb_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operator_rgb_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operator_rgb_enum__streamEnd( const ParserChar* value, size_t length );

struct RGB__ValidationData
{
    size_t argument;
};

ParserError::ErrorType validate__gles_texcombiner_source_enum( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_source_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_source_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_source_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texcombiner_operand_rgb_enum( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operand_rgb_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operand_rgb_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operand_rgb_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texcombiner_operator_alpha_enum( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operator_alpha_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operator_alpha_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operator_alpha_enum__streamEnd( const ParserChar* value, size_t length );

struct alpha____gles_texcombiner_command_alpha_type__ValidationData
{
    size_t argument;
};

ParserError::ErrorType validate__gles_texcombiner_operand_alpha_enum( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operand_alpha_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operand_alpha_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operand_alpha_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texenv_mode_enum( ParserString value );
ParserError::ErrorType validate__gles_texenv_mode_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texenv_mode_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texenv_mode_enum__streamEnd( const ParserChar* value, size_t length );

struct texenv__ValidationData
{
    size_t constant;
};

struct profile_GLES__technique__pass__evaluate__ValidationData
{
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
};

struct library_force_fields__ValidationData
{
    size_t asset;
    size_t force_field;
    size_t extra;
};

struct force_field__ValidationData
{
    size_t asset;
    size_t technique;
    size_t extra;
};

struct library_images__ValidationData
{
    size_t asset;
    size_t image;
    size_t extra;
};

struct image____image_type__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t renderable;
    size_t init_from;
    size_t create_2d;
    size_t create_3d;
    size_t create_cube;
    size_t extra;
};

struct image_type____init_from__ValidationData
{
    size_t ref;
    size_t hex;
};

struct create_2d__ValidationData
{
    size_t validation_current_state;
    size_t size_exact;
    size_t size_ratio;
    size_t mips;
    size_t unnormalized;
    size_t array;
    size_t format;
    size_t init_from;
};

struct unnormalized__ValidationData
{
    size_t _wildcard;
    size_t validationWholeSize;
};

struct create_2d__format__ValidationData
{
    size_t hint;
    size_t exact;
};

ParserError::ErrorType validate__image_format_hint_channels_enum( ParserString value );
ParserError::ErrorType validate__image_format_hint_channels_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_channels_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_channels_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__image_format_hint_range_enum( ParserString value );
ParserError::ErrorType validate__image_format_hint_range_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_range_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_range_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__image_format_hint_precision_enum( ParserString value );
ParserError::ErrorType validate__image_format_hint_precision_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_precision_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__image_format_hint_precision_enum__streamEnd( const ParserChar* value, size_t length );

struct create_2d__init_from__ValidationData
{
    size_t ref;
    size_t hex;
};

struct create_3d__ValidationData
{
    size_t size;
    size_t mips;
    size_t array;
    size_t format;
    size_t init_from;
};

struct create_3d__format__ValidationData
{
    size_t hint;
    size_t exact;
};

struct create_3d__init_from__ValidationData
{
    size_t ref;
    size_t hex;
};

struct create_cube__ValidationData
{
    size_t size;
    size_t mips;
    size_t array;
    size_t format;
    size_t init_from;
};

struct create_cube__format__ValidationData
{
    size_t hint;
    size_t exact;
};

struct create_cube__init_from__ValidationData
{
    size_t ref;
    size_t hex;
};

struct library_lights__ValidationData
{
    size_t asset;
    size_t light;
    size_t extra;
};

struct light__ValidationData
{
    size_t asset;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct light_type____technique_common__ValidationData
{
    size_t ambient;
    size_t directional;
    size_t point;
    size_t spot;
};

struct light__technique_common__ambient__ValidationData
{
    size_t color;
};

struct color____targetable_float3_type__ValidationData
{
    size_t validationWholeSize;
};

struct directional__ValidationData
{
    size_t color;
};

struct point__ValidationData
{
    size_t color;
    size_t constant_attenuation;
    size_t linear_attenuation;
    size_t quadratic_attenuation;
};

struct spot__ValidationData
{
    size_t color;
    size_t constant_attenuation;
    size_t linear_attenuation;
    size_t quadratic_attenuation;
    size_t falloff_angle;
    size_t falloff_exponent;
};

struct library_materials__ValidationData
{
    size_t asset;
    size_t material;
    size_t extra;
};

struct material__ValidationData
{
    size_t asset;
    size_t instance_effect;
    size_t extra;
};

struct instance_effect__ValidationData
{
    size_t technique_hint;
    size_t setparam;
    size_t extra;
};

struct instance_effect_type____setparam__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t _int;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t float2x1;
    size_t float2x2;
    size_t float2x3;
    size_t float2x4;
    size_t float3x1;
    size_t float3x2;
    size_t float3x3;
    size_t float3x4;
    size_t float4x1;
    size_t float4x2;
    size_t float4x3;
    size_t float4x4;
    size_t _enum;
    size_t sampler_image;
    size_t sampler_states;
};

struct sampler_states__ValidationData
{
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mip_max_level;
    size_t mip_min_level;
    size_t mip_bias;
    size_t max_anisotropy;
    size_t extra;
};

struct library_nodes__ValidationData
{
    size_t asset;
    size_t node;
    size_t extra;
};

ParserError::ErrorType validate__node_enum( ParserString value );
ParserError::ErrorType validate__node_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__node_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__node_enum__streamEnd( const ParserChar* value, size_t length );

struct node__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t lookat;
    size_t matrix;
    size_t rotate;
    size_t scale;
    size_t skew;
    size_t translate;
    size_t instance_camera;
    size_t instance_controller;
    size_t instance_geometry;
    size_t instance_light;
    size_t instance_node;
    size_t node;
    size_t extra;
};

struct lookat__ValidationData
{
    size_t validationWholeSize;
};

struct matrix____matrix_type__ValidationData
{
    size_t validationWholeSize;
};

struct rotate__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__rotate( const float* value, size_t length );
ParserError::ErrorType validate__rotate__stream( const float* value, size_t length );
ParserError::ErrorType validate__rotate__streamEnd( const float* value, size_t length );

struct scale__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__scale( const float* value, size_t length );
ParserError::ErrorType validate__scale__stream( const float* value, size_t length );
ParserError::ErrorType validate__scale__streamEnd( const float* value, size_t length );

struct skew__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float7_type( const float* value, size_t length );
ParserError::ErrorType validate__float7_type__stream( const float* value, size_t length );
ParserError::ErrorType validate__float7_type__streamEnd( const float* value, size_t length );

struct translate__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__translate( const float* value, size_t length );
ParserError::ErrorType validate__translate__stream( const float* value, size_t length );
ParserError::ErrorType validate__translate__streamEnd( const float* value, size_t length );

struct instance_camera__ValidationData
{
    size_t extra;
};

struct instance_controller__ValidationData
{
    size_t skeleton;
    size_t bind_material;
    size_t extra;
};

struct bind_material__ValidationData
{
    size_t param;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct bind_material_type____technique_common__ValidationData
{
    size_t instance_material;
};

struct instance_material____instance_material_type__ValidationData
{
    size_t bind;
    size_t bind_vertex_input;
    size_t extra;
};

struct instance_geometry__ValidationData
{
    size_t bind_material;
    size_t extra;
};

struct instance_light__ValidationData
{
    size_t extra;
};

struct instance_node__ValidationData
{
    size_t extra;
};

struct library_physics_materials__ValidationData
{
    size_t asset;
    size_t physics_material;
    size_t extra;
};

struct physics_material__ValidationData
{
    size_t asset;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct physics_material_type____technique_common__ValidationData
{
    size_t dynamic_friction;
    size_t restitution;
    size_t static_friction;
};

struct library_physics_models__ValidationData
{
    size_t asset;
    size_t physics_model;
    size_t extra;
};

struct physics_model__ValidationData
{
    size_t asset;
    size_t rigid_body;
    size_t rigid_constraint;
    size_t instance_physics_model;
    size_t extra;
};

struct rigid_body__ValidationData
{
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct rigid_body_type____technique_common__ValidationData
{
    size_t validation_current_state;
    size_t dynamic;
    size_t mass;
    size_t mass_frame;
    size_t inertia;
    size_t instance_physics_material;
    size_t physics_material;
    size_t shape;
};

struct rigid_body__technique_common__mass_frame__ValidationData
{
    size_t translate;
    size_t rotate;
};

struct instance_physics_material__ValidationData
{
    size_t extra;
};

struct rigid_body__technique_common__shape__ValidationData
{
    size_t validation_current_state;
    size_t hollow;
    size_t mass;
    size_t density;
    size_t instance_physics_material;
    size_t physics_material;
    size_t instance_geometry;
    size_t plane;
    size_t box;
    size_t sphere;
    size_t cylinder;
    size_t capsule;
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct box__ValidationData
{
    size_t half_extents;
    size_t extra;
};

struct cylinder____cylinder_type__ValidationData
{
    size_t height;
    size_t radius;
    size_t extra;
};

struct capsule__ValidationData
{
    size_t height;
    size_t radius;
    size_t extra;
};

struct rigid_constraint__ValidationData
{
    size_t ref_attachment;
    size_t attachment;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct ref_attachment__ValidationData
{
    size_t validation_current_state;
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct attachment__ValidationData
{
    size_t validation_current_state;
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct rigid_constraint_type____technique_common__ValidationData
{
    size_t enabled;
    size_t interpenetrate;
    size_t limits;
    size_t spring;
};

struct rigid_constraint__technique_common__limits__ValidationData
{
    size_t swing_cone_and_twist;
    size_t linear;
};

struct swing_cone_and_twist__ValidationData
{
    size_t min;
    size_t max;
};

struct rigid_constraint__technique_common__limits__linear__ValidationData
{
    size_t min;
    size_t max;
};

struct spring__ValidationData
{
    size_t angular;
    size_t linear;
};

struct angular__ValidationData
{
    size_t stiffness;
    size_t damping;
    size_t target_value;
};

struct spring__linear__ValidationData
{
    size_t stiffness;
    size_t damping;
    size_t target_value;
};

struct instance_physics_model__ValidationData
{
    size_t instance_force_field;
    size_t instance_rigid_body;
    size_t instance_rigid_constraint;
    size_t extra;
};

struct instance_force_field__ValidationData
{
    size_t extra;
};

struct instance_rigid_body__ValidationData
{
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct instance_rigid_body_type____technique_common__ValidationData
{
    size_t validation_current_state;
    size_t angular_velocity;
    size_t velocity;
    size_t dynamic;
    size_t mass;
    size_t mass_frame;
    size_t inertia;
    size_t instance_physics_material;
    size_t physics_material;
    size_t shape;
};

struct instance_rigid_body__technique_common__mass_frame__ValidationData
{
    size_t translate;
    size_t rotate;
};

struct instance_rigid_body__technique_common__shape__ValidationData
{
    size_t validation_current_state;
    size_t hollow;
    size_t mass;
    size_t density;
    size_t instance_physics_material;
    size_t physics_material;
    size_t instance_geometry;
    size_t plane;
    size_t box;
    size_t sphere;
    size_t cylinder;
    size_t capsule;
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct instance_rigid_constraint__ValidationData
{
    size_t extra;
};

struct library_physics_scenes__ValidationData
{
    size_t asset;
    size_t physics_scene;
    size_t extra;
};

struct physics_scene__ValidationData
{
    size_t asset;
    size_t instance_force_field;
    size_t instance_physics_model;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct physics_scene_type____technique_common__ValidationData
{
    size_t gravity;
    size_t time_step;
};

struct library_visual_scenes__ValidationData
{
    size_t asset;
    size_t visual_scene;
    size_t extra;
};

struct visual_scene__ValidationData
{
    size_t asset;
    size_t node;
    size_t evaluate_scene;
    size_t extra;
};

struct evaluate_scene__ValidationData
{
    size_t asset;
    size_t render;
    size_t extra;
};

struct render__ValidationData
{
    size_t layer;
    size_t instance_material;
    size_t extra;
};

struct render__instance_material__ValidationData
{
    size_t technique_override;
    size_t bind;
    size_t extra;
};

struct library_joints__ValidationData
{
    size_t asset;
    size_t joint;
    size_t extra;
};

struct joint__ValidationData
{
    size_t validation_current_state;
    size_t prismatic;
    size_t revolute;
    size_t extra;
};

struct prismatic__ValidationData
{
    size_t axis;
    size_t limits;
};

struct axis____axis_type__ValidationData
{
    size_t validationWholeSize;
};

struct limits____joint_limits_type__ValidationData
{
    size_t min;
    size_t max;
};

struct library_kinematics_models__ValidationData
{
    size_t asset;
    size_t kinematics_model;
    size_t extra;
};

struct kinematics_model__ValidationData
{
    size_t asset;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct technique_common____kinematics_model_technique_type__ValidationData
{
    size_t validation_current_state;
    size_t newparam;
    size_t instance_joint;
    size_t joint;
    size_t link;
    size_t formula;
    size_t instance_formula;
};

struct newparam____kinematics_newparam_type__ValidationData
{
    size_t _float;
    size_t _int;
    size_t SIDREF;
    size_t _bool;
};

struct instance_joint__ValidationData
{
    size_t extra;
};

struct link__ValidationData
{
    size_t validation_current_state;
    size_t rotate;
    size_t translate;
    size_t attachment_full;
    size_t attachment_start;
    size_t attachment_end;
};

struct attachment_full__ValidationData
{
    size_t validation_current_state;
    size_t rotate;
    size_t translate;
    size_t link;
};

struct attachment_start__ValidationData
{
    size_t rotate;
    size_t translate;
};

struct attachment_end__ValidationData
{
    size_t rotate;
    size_t translate;
};

struct formula__ValidationData
{
    size_t newparam;
    size_t target;
    size_t technique_common;
    size_t technique;
};

struct newparam____formula_newparam_type__ValidationData
{
    size_t _float;
    size_t _int;
    size_t SIDREF;
    size_t _bool;
};

struct target__ValidationData
{
    size_t _float;
    size_t param;
};

struct technique_common____formula_technique_type__ValidationData
{
    size_t math;
};

ParserError::ErrorType validate__math( ParserString value );
ParserError::ErrorType validate__math( const ParserChar* value, size_t length );
ParserError::ErrorType validate__math__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__math__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__NMTOKENS( const ParserString*value, size_t length );
ParserError::ErrorType validate__NMTOKENS__stream( const ParserString*value, size_t length );
ParserError::ErrorType validate__NMTOKENS__streamEnd( const ParserString*value, size_t length );

struct math__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

ParserError::ErrorType validate__cn( const uint64 value );

struct cn__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
    size_t sep;
    size_t validationWholeSize;
};

struct ci__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
    size_t validationWholeSize;
};

struct csymbol__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
    size_t validationWholeSize;
};

struct domainofapplication__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct set__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

ParserError::ErrorType validate__list( ParserString value );
ParserError::ErrorType validate__list( const ParserChar* value, size_t length );
ParserError::ErrorType validate__list__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__list__streamEnd( const ParserChar* value, size_t length );

struct list__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct logbase__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct lowlimit__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct uplimit__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct vector__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct matrix____matrix_type____mathml__ValidationData
{
    size_t matrixrow;
};

struct matrixrow__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct momentabout__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct apply__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

ParserError::ErrorType validate__interval( ParserString value );
ParserError::ErrorType validate__interval( const ParserChar* value, size_t length );
ParserError::ErrorType validate__interval__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__interval__streamEnd( const ParserChar* value, size_t length );

struct interval__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct condition__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

ParserError::ErrorType validate__declare( ParserString value );
ParserError::ErrorType validate__declare( const ParserChar* value, size_t length );
ParserError::ErrorType validate__declare__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__declare__streamEnd( const ParserChar* value, size_t length );

struct declare__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct lambda__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct piecewise__ValidationData
{
    size_t validation_current_state;
    size_t piece;
    size_t otherwise;
};

struct piece__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct bvar__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct degree__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct semantics__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
    size_t annotation;
    size_t annotation_xml;
};

struct annotation__ValidationData
{
    size_t validationWholeSize;
};

struct annotation_xml__ValidationData
{
    size_t _wildcard;
};

struct otherwise__ValidationData
{
    size_t validation_current_state;
    size_t cn;
    size_t ci;
    size_t csymbol;
    size_t abs;
    size_t conjugate;
    size_t factorial;
    size_t arg;
    size_t real;
    size_t imaginary;
    size_t floor;
    size_t ceiling;
    size_t quotient;
    size_t divide;
    size_t rem;
    size_t minus;
    size_t plus;
    size_t times;
    size_t power;
    size_t root;
    size_t max;
    size_t min;
    size_t gcd;
    size_t lcm;
    size_t sum;
    size_t product;
    size_t compose;
    size_t domain;
    size_t codomain;
    size_t image;
    size_t domainofapplication;
    size_t ident;
    size_t _and;
    size_t _or;
    size_t _xor;
    size_t _not;
    size_t exists;
    size_t forall;
    size_t implies;
    size_t naturalnumbers;
    size_t primes;
    size_t integers;
    size_t rationals;
    size_t reals;
    size_t complexes;
    size_t emptyset;
    size_t exponentiale;
    size_t imaginaryi;
    size_t pi;
    size_t eulergamma;
    size_t _true;
    size_t _false;
    size_t infinity;
    size_t notanumber;
    size_t set;
    size_t list;
    size_t _union;
    size_t intersect;
    size_t _in;
    size_t notin;
    size_t subset;
    size_t prsubset;
    size_t notsubset;
    size_t notprsubset;
    size_t setdiff;
    size_t card;
    size_t cartesianproduct;
    size_t eq;
    size_t neq;
    size_t leq;
    size_t lt;
    size_t geq;
    size_t gt;
    size_t equivalent;
    size_t approx;
    size_t factorof;
    size_t exp;
    size_t ln;
    size_t log;
    size_t logbase;
    size_t sin;
    size_t cos;
    size_t tan;
    size_t sec;
    size_t csc;
    size_t cot;
    size_t arcsin;
    size_t arccos;
    size_t arctan;
    size_t arcsec;
    size_t arccsc;
    size_t arccot;
    size_t sinh;
    size_t cosh;
    size_t tanh;
    size_t sech;
    size_t csch;
    size_t coth;
    size_t arccosh;
    size_t arccoth;
    size_t arccsch;
    size_t arcsech;
    size_t arcsinh;
    size_t arctanh;
    size_t _int;
    size_t diff;
    size_t partialdiff;
    size_t limit;
    size_t lowlimit;
    size_t uplimit;
    size_t tendsto;
    size_t vector;
    size_t matrix;
    size_t determinant;
    size_t transpose;
    size_t selector;
    size_t vectorproduct;
    size_t scalarproduct;
    size_t outerproduct;
    size_t divergence;
    size_t grad;
    size_t curl;
    size_t laplacian;
    size_t mean;
    size_t sdev;
    size_t variance;
    size_t median;
    size_t mode;
    size_t moment;
    size_t momentabout;
    size_t apply;
    size_t interval;
    size_t inverse;
    size_t condition;
    size_t declare;
    size_t lambda;
    size_t piecewise;
    size_t bvar;
    size_t degree;
    size_t semantics;
};

struct library_articulated_systems__ValidationData
{
    size_t asset;
    size_t articulated_system;
    size_t extra;
};

struct articulated_system__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t kinematics;
    size_t motion;
    size_t extra;
};

struct kinematics__ValidationData
{
    size_t instance_kinematics_model;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct instance_kinematics_model__ValidationData
{
    size_t bind;
    size_t newparam;
    size_t setparam;
    size_t extra;
};

struct bind____kinematics_bind_type__ValidationData
{
    size_t param;
    size_t _bool;
    size_t _float;
    size_t _int;
    size_t SIDREF;
};

struct setparam____kinematics_setparam_type__ValidationData
{
    size_t _float;
    size_t _int;
    size_t SIDREF;
    size_t _bool;
    size_t connect_param;
};

struct technique_common____kinematics_technique_type__ValidationData
{
    size_t axis_info;
    size_t frame_origin;
    size_t frame_tip;
    size_t frame_tcp;
    size_t frame_object;
};

struct axis_info____kinematics_axis_info_type__ValidationData
{
    size_t validation_current_state;
    size_t newparam;
    size_t active;
    size_t locked;
    size_t index;
    size_t limits;
    size_t formula;
    size_t instance_formula;
};

struct active__ValidationData
{
    size_t _bool;
    size_t param;
};

struct index__ValidationData
{
    size_t _int;
    size_t param;
};

struct limits____kinematics_limits_type__ValidationData
{
    size_t min;
    size_t max;
};

struct frame_origin__ValidationData
{
    size_t translate;
    size_t rotate;
};

struct motion__ValidationData
{
    size_t instance_articulated_system;
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct instance_articulated_system__ValidationData
{
    size_t bind;
    size_t setparam;
    size_t newparam;
    size_t extra;
};

struct technique_common____motion_technique_type__ValidationData
{
    size_t axis_info;
    size_t effector_info;
};

struct axis_info____motion_axis_info_type__ValidationData
{
    size_t bind;
    size_t newparam;
    size_t setparam;
    size_t speed;
    size_t acceleration;
    size_t deceleration;
    size_t jerk;
};

struct effector_info__ValidationData
{
    size_t bind;
    size_t newparam;
    size_t setparam;
    size_t speed;
    size_t acceleration;
    size_t deceleration;
    size_t jerk;
};

struct speed____common_float2_or_param_type__ValidationData
{
    size_t float2;
    size_t param;
};

struct library_kinematics_scenes__ValidationData
{
    size_t asset;
    size_t kinematics_scene;
    size_t extra;
};

struct kinematics_scene__ValidationData
{
    size_t asset;
    size_t instance_kinematics_model;
    size_t instance_articulated_system;
    size_t extra;
};

struct library_formulas__ValidationData
{
    size_t asset;
    size_t formula;
    size_t extra;
};

struct scene__ValidationData
{
    size_t instance_physics_scene;
    size_t instance_visual_scene;
    size_t instance_kinematics_scene;
    size_t extra;
};

struct instance_kinematics_scene__ValidationData
{
    size_t asset;
    size_t newparam;
    size_t setparam;
    size_t bind_kinematics_model;
    size_t bind_joint_axis;
    size_t extra;
};

struct bind_kinematics_model__ValidationData
{
    size_t SIDREF;
    size_t param;
};

struct bind_joint_axis__ValidationData
{
    size_t axis;
    size_t value;
};

struct axis____common_sidref_or_param_type__ValidationData
{
    size_t SIDREF;
    size_t param;
};



} // namespace
#endif
