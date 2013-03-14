/*
    Copyright (c) 2008-2013 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14VALIDATIONDATA_H__
#define __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14VALIDATIONDATA_H__


namespace COLLADASaxFWL14
{


ParserError::ErrorType validate__VersionType( ParserString value );
ParserError::ErrorType validate__VersionType( const ParserChar* value, size_t length );
ParserError::ErrorType validate__VersionType__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__VersionType__streamEnd( const ParserChar* value, size_t length );

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
    size_t scene;
    size_t extra;
};

struct asset__ValidationData
{
    size_t contributor;
    size_t created;
    size_t keywords;
    size_t modified;
    size_t revision;
    size_t subject;
    size_t title;
    size_t unit;
    size_t up_axis;
};

struct contributor__ValidationData
{
    size_t author;
    size_t authoring_tool;
    size_t comments;
    size_t copyright;
    size_t source_data;
};

ParserError::ErrorType validate__NMTOKEN( ParserString value );
ParserError::ErrorType validate__NMTOKEN( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NMTOKEN__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NMTOKEN__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__UpAxisType( ParserString value );
ParserError::ErrorType validate__UpAxisType( const ParserChar* value, size_t length );
ParserError::ErrorType validate__UpAxisType__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__UpAxisType__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__NCName( ParserString value );
ParserError::ErrorType validate__NCName( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NCName__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NCName__streamEnd( const ParserChar* value, size_t length );

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
    size_t IDREF_array;
    size_t Name_array;
    size_t bool_array;
    size_t float_array;
    size_t int_array;
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

struct animation__source__technique_common__ValidationData
{
    size_t accessor;
};

struct accessor__ValidationData
{
    size_t param;
};

struct technique__ValidationData
{
    size_t _wildcard;
};

struct sampler__ValidationData
{
    size_t input;
};

ParserError::ErrorType validate__URIFragmentType( ParserString value );
ParserError::ErrorType validate__URIFragmentType( const ParserChar* value, size_t length );
ParserError::ErrorType validate__URIFragmentType__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__URIFragmentType__streamEnd( const ParserChar* value, size_t length );

struct extra__ValidationData
{
    size_t asset;
    size_t technique;
};

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
    size_t extra;
};

struct instance_animation__ValidationData
{
    size_t extra;
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

ParserError::ErrorType validate__float4x4( const float* value, size_t length );
ParserError::ErrorType validate__float4x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x4__streamEnd( const float* value, size_t length );

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

ParserError::ErrorType validate__MorphMethodType( ParserString value );
ParserError::ErrorType validate__MorphMethodType( const ParserChar* value, size_t length );
ParserError::ErrorType validate__MorphMethodType__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__MorphMethodType__streamEnd( const ParserChar* value, size_t length );

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

struct control_vertices__ValidationData
{
    size_t input;
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
    size_t asset;
    size_t annotate;
    size_t image;
    size_t newparam;
    size_t fx_profile_abstract;
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

struct bool2____bool2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool2( const bool* value, size_t length );
ParserError::ErrorType validate__bool2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool2__streamEnd( const bool* value, size_t length );

struct bool3____bool3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool3( const bool* value, size_t length );
ParserError::ErrorType validate__bool3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool3__streamEnd( const bool* value, size_t length );

struct bool4____bool4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__bool4( const bool* value, size_t length );
ParserError::ErrorType validate__bool4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__bool4__streamEnd( const bool* value, size_t length );

struct int2____int2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int2( const sint64* value, size_t length );
ParserError::ErrorType validate__int2__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int2__streamEnd( const sint64* value, size_t length );

struct int3____int3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int3( const sint64* value, size_t length );
ParserError::ErrorType validate__int3__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int3__streamEnd( const sint64* value, size_t length );

struct int4____int4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__int4( const sint64* value, size_t length );
ParserError::ErrorType validate__int4__stream( const sint64* value, size_t length );
ParserError::ErrorType validate__int4__streamEnd( const sint64* value, size_t length );

struct float2____float2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2( const float* value, size_t length );
ParserError::ErrorType validate__float2__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2__streamEnd( const float* value, size_t length );

struct float3____float3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3( const float* value, size_t length );
ParserError::ErrorType validate__float3__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3__streamEnd( const float* value, size_t length );

struct float4____float4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4( const float* value, size_t length );
ParserError::ErrorType validate__float4__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4__streamEnd( const float* value, size_t length );

struct float2x2____float2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x2( const float* value, size_t length );
ParserError::ErrorType validate__float2x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x2__streamEnd( const float* value, size_t length );

struct float3x3____float3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x3( const float* value, size_t length );
ParserError::ErrorType validate__float3x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x3__streamEnd( const float* value, size_t length );

struct image__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t data;
    size_t init_from;
    size_t extra;
};

struct newparam____fx_newparam_common__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
};

ParserError::ErrorType validate__fx_modifier_enum_common( ParserString value );
ParserError::ErrorType validate__fx_modifier_enum_common( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_modifier_enum_common__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_modifier_enum_common__streamEnd( const ParserChar* value, size_t length );

struct float2x3____float2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x3( const float* value, size_t length );
ParserError::ErrorType validate__float2x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x3__streamEnd( const float* value, size_t length );

struct float2x4____float2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float2x4( const float* value, size_t length );
ParserError::ErrorType validate__float2x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__float2x4__streamEnd( const float* value, size_t length );

struct float3x2____float3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x2( const float* value, size_t length );
ParserError::ErrorType validate__float3x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x2__streamEnd( const float* value, size_t length );

struct float3x4____float3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float3x4( const float* value, size_t length );
ParserError::ErrorType validate__float3x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__float3x4__streamEnd( const float* value, size_t length );

struct float4x2____float4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4x2( const float* value, size_t length );
ParserError::ErrorType validate__float4x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x2__streamEnd( const float* value, size_t length );

struct float4x3____float4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float4x3( const float* value, size_t length );
ParserError::ErrorType validate__float4x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__float4x3__streamEnd( const float* value, size_t length );

ParserError::ErrorType validate__fx_surface_type_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_type_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_type_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_type_enum__streamEnd( const ParserChar* value, size_t length );

struct surface____fx_surface_common__ValidationData
{
    size_t validation_current_state;
    size_t init_as_null;
    size_t init_as_target;
    size_t init_cube;
    size_t init_volume;
    size_t init_planar;
    size_t init_from;
    size_t format;
    size_t format_hint;
    size_t size;
    size_t viewport_ratio;
    size_t mip_levels;
    size_t mipmap_generate;
    size_t extra;
};

struct init_as_null__ValidationData
{
    size_t _wildcard;
    size_t validationWholeSize;
};

struct init_cube__ValidationData
{
    size_t all;
    size_t primary;
    size_t face;
};

struct fx_surface_init_cube_common____primary__ValidationData
{
    size_t order;
};

ParserError::ErrorType validate__fx_surface_face_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_face_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_face_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_face_enum__streamEnd( const ParserChar* value, size_t length );

struct init_volume__ValidationData
{
    size_t all;
    size_t primary;
};

struct init_planar__ValidationData
{
    size_t all;
};

ParserError::ErrorType validate__unsignedInt( const uint32 value );

struct format_hint__ValidationData
{
    size_t channels;
    size_t range;
    size_t precision;
    size_t option;
    size_t extra;
};

ParserError::ErrorType validate__fx_surface_format_hint_channels_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_format_hint_channels_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_channels_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_channels_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_surface_format_hint_range_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_format_hint_range_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_range_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_range_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_surface_format_hint_precision_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_format_hint_precision_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_precision_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_precision_enum__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_surface_format_hint_option_enum( ParserString value );
ParserError::ErrorType validate__fx_surface_format_hint_option_enum( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_option_enum__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_surface_format_hint_option_enum__streamEnd( const ParserChar* value, size_t length );

struct sampler1D____fx_sampler1D_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

ParserError::ErrorType validate__fx_sampler_wrap_common( ParserString value );
ParserError::ErrorType validate__fx_sampler_wrap_common( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_wrap_common__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_wrap_common__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__fx_sampler_filter_common( ParserString value );
ParserError::ErrorType validate__fx_sampler_filter_common( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_filter_common__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__fx_sampler_filter_common__streamEnd( const ParserChar* value, size_t length );

struct border_color__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__fx_color_common( const float* value, size_t length );
ParserError::ErrorType validate__fx_color_common__stream( const float* value, size_t length );
ParserError::ErrorType validate__fx_color_common__streamEnd( const float* value, size_t length );

struct sampler2D____fx_sampler2D_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct sampler3D____fx_sampler3D_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerCUBE____fx_samplerCUBE_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerRECT____fx_samplerRECT_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerDEPTH____fx_samplerDEPTH_common__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t extra;
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

struct light__technique_common__ValidationData
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

struct color____TargetableFloat3__ValidationData
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

struct instance_effect__setparam__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
};

struct library_nodes__ValidationData
{
    size_t asset;
    size_t node;
    size_t extra;
};

ParserError::ErrorType validate__NodeType( ParserString value );
ParserError::ErrorType validate__NodeType( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NodeType__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__NodeType__streamEnd( const ParserChar* value, size_t length );

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

struct matrix__ValidationData
{
    size_t validationWholeSize;
};

struct rotate__ValidationData
{
    size_t validationWholeSize;
};

struct skew__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__float7( const float* value, size_t length );
ParserError::ErrorType validate__float7__stream( const float* value, size_t length );
ParserError::ErrorType validate__float7__streamEnd( const float* value, size_t length );

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

struct bind_material__technique_common__ValidationData
{
    size_t instance_material;
};

struct instance_material__ValidationData
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

struct physics_material__technique_common__ValidationData
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

struct rigid_body__technique_common__ValidationData
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
    size_t tapered_cylinder;
    size_t capsule;
    size_t tapered_capsule;
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct plane__ValidationData
{
    size_t equation;
    size_t extra;
};

struct box__ValidationData
{
    size_t half_extents;
    size_t extra;
};

struct sphere__ValidationData
{
    size_t radius;
    size_t extra;
};

struct cylinder__ValidationData
{
    size_t height;
    size_t radius;
    size_t extra;
};

struct tapered_cylinder__ValidationData
{
    size_t height;
    size_t radius1;
    size_t radius2;
    size_t extra;
};

struct capsule__ValidationData
{
    size_t height;
    size_t radius;
    size_t extra;
};

struct tapered_capsule__ValidationData
{
    size_t height;
    size_t radius1;
    size_t radius2;
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
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct attachment__ValidationData
{
    size_t translate;
    size_t rotate;
    size_t extra;
};

struct rigid_constraint__technique_common__ValidationData
{
    size_t enabled;
    size_t interpenetrate;
    size_t limits;
    size_t spring;
};

struct limits__ValidationData
{
    size_t swing_cone_and_twist;
    size_t linear;
};

struct swing_cone_and_twist__ValidationData
{
    size_t min;
    size_t max;
};

struct limits__linear__ValidationData
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

struct instance_rigid_body__ValidationData
{
    size_t technique_common;
    size_t technique;
    size_t extra;
};

struct instance_rigid_body__technique_common__ValidationData
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
    size_t tapered_cylinder;
    size_t capsule;
    size_t tapered_capsule;
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

struct physics_scene__technique_common__ValidationData
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
    size_t render;
};

struct render__ValidationData
{
    size_t layer;
    size_t instance_effect;
};

struct scene__ValidationData
{
    size_t instance_physics_scene;
    size_t instance_visual_scene;
    size_t extra;
};

struct profile_GLES__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t image;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____gles_newparam__ValidationData
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
    size_t surface;
    size_t texture_pipeline;
    size_t sampler_state;
    size_t texture_unit;
    size_t _enum;
};

struct texture_pipeline____gles_texture_pipeline__ValidationData
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

ParserError::ErrorType validate__gles_texcombiner_operatorRGB_enums( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operatorRGB_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operatorRGB_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operatorRGB_enums__streamEnd( const ParserChar* value, size_t length );

struct RGB__ValidationData
{
    size_t argument;
};

ParserError::ErrorType validate__gles_texcombiner_source_enums( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_source_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_source_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_source_enums__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texcombiner_operandRGB_enums( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operandRGB_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operandRGB_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operandRGB_enums__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texcombiner_operatorAlpha_enums( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operatorAlpha_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operatorAlpha_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operatorAlpha_enums__streamEnd( const ParserChar* value, size_t length );

struct alpha____gles_texcombiner_commandAlpha_type__ValidationData
{
    size_t argument;
};

ParserError::ErrorType validate__gles_texcombiner_operandAlpha_enums( ParserString value );
ParserError::ErrorType validate__gles_texcombiner_operandAlpha_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operandAlpha_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texcombiner_operandAlpha_enums__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gles_texenv_mode_enums( ParserString value );
ParserError::ErrorType validate__gles_texenv_mode_enums( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texenv_mode_enums__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_texenv_mode_enums__streamEnd( const ParserChar* value, size_t length );

struct texenv__ValidationData
{
    size_t constant;
};

struct sampler_state____gles_sampler_state__ValidationData
{
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

ParserError::ErrorType validate__gles_sampler_wrap( ParserString value );
ParserError::ErrorType validate__gles_sampler_wrap( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_sampler_wrap__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_sampler_wrap__streamEnd( const ParserChar* value, size_t length );

struct texture_unit__ValidationData
{
    size_t surface;
    size_t sampler_state;
    size_t texcoord;
    size_t extra;
};

struct profile_GLES__technique__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t annotate;
    size_t image;
    size_t newparam;
    size_t setparam;
    size_t pass;
    size_t extra;
};

struct profile_GLES__technique__setparam__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
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
    size_t surface;
    size_t texture_pipeline;
    size_t sampler_state;
    size_t texture_unit;
    size_t _enum;
};

struct profile_GLES__technique__pass__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
    size_t alpha_func;
    size_t blend_func;
    size_t clear_color;
    size_t clear_stencil;
    size_t clear_depth;
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
    size_t texture_pipeline;
    size_t logic_op;
    size_t light_ambient;
    size_t light_diffuse;
    size_t light_specular;
    size_t light_position;
    size_t light_constant_attenuation;
    size_t light_linear_attenutation;
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
    size_t alpha_test_enable;
    size_t blend_enable;
    size_t clip_plane_enable;
    size_t color_logic_op_enable;
    size_t color_material_enable;
    size_t cull_face_enable;
    size_t depth_test_enable;
    size_t dither_enable;
    size_t fog_enable;
    size_t texture_pipeline_enable;
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
    size_t extra;
};

ParserError::ErrorType validate__gles_rendertarget_common( ParserString value );
ParserError::ErrorType validate__gles_rendertarget_common( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_rendertarget_common__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_rendertarget_common__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES__technique__pass__alpha_func__ValidationData
{
    size_t func;
    size_t value;
};

ParserError::ErrorType validate__gl_func_type( ParserString value );
ParserError::ErrorType validate__gl_func_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_func_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_func_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_alpha_value_type( const float value );

struct profile_GLES__technique__pass__blend_func__ValidationData
{
    size_t src;
    size_t dest;
};

ParserError::ErrorType validate__gl_blend_type( ParserString value );
ParserError::ErrorType validate__gl_blend_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__GLES_MAX_CLIP_PLANES_index( const uint64 value );

ParserError::ErrorType validate__gl_face_type( ParserString value );
ParserError::ErrorType validate__gl_face_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_face_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_face_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_fog_type( ParserString value );
ParserError::ErrorType validate__gl_fog_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_front_face_type( ParserString value );
ParserError::ErrorType validate__gl_front_face_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_front_face_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_front_face_type__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES__technique__pass__texture_pipeline__ValidationData
{
    size_t value;
};

ParserError::ErrorType validate__gl_logic_op_type( ParserString value );
ParserError::ErrorType validate__gl_logic_op_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_logic_op_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_logic_op_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__GLES_MAX_LIGHTS_index( const uint64 value );

ParserError::ErrorType validate__gl_shade_model_type( ParserString value );
ParserError::ErrorType validate__gl_shade_model_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_shade_model_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_shade_model_type__streamEnd( const ParserChar* value, size_t length );

struct profile_GLES__technique__pass__stencil_func__ValidationData
{
    size_t func;
    size_t ref;
    size_t mask;
};

struct profile_GLES__technique__pass__stencil_op__ValidationData
{
    size_t fail;
    size_t zfail;
    size_t zpass;
};

ParserError::ErrorType validate__gles_stencil_op_type( ParserString value );
ParserError::ErrorType validate__gles_stencil_op_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_stencil_op_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gles_stencil_op_type__streamEnd( const ParserChar* value, size_t length );

struct profile_GLSL__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t code;
    size_t include;
    size_t image;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____glsl_newparam__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct bool2____glsl_bool2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_bool2( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool2__streamEnd( const bool* value, size_t length );

struct bool3____glsl_bool3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_bool3( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool3__streamEnd( const bool* value, size_t length );

struct bool4____glsl_bool4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_bool4( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__glsl_bool4__streamEnd( const bool* value, size_t length );

struct float2____glsl_float2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float2( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float2__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float2__streamEnd( const float* value, size_t length );

struct float3____glsl_float3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float3( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float3__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float3__streamEnd( const float* value, size_t length );

struct float4____glsl_float4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float4( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float4__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float4__streamEnd( const float* value, size_t length );

struct float2x2____glsl_float2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float2x2( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float2x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float2x2__streamEnd( const float* value, size_t length );

struct float3x3____glsl_float3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float3x3( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float3x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float3x3__streamEnd( const float* value, size_t length );

struct float4x4____glsl_float4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_float4x4( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float4x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__glsl_float4x4__streamEnd( const float* value, size_t length );

ParserError::ErrorType validate__glsl_int( const sint32 value );

struct int2____glsl_int2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_int2( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int2__streamEnd( const sint32* value, size_t length );

struct int3____glsl_int3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_int3( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int3__streamEnd( const sint32* value, size_t length );

struct int4____glsl_int4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__glsl_int4( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__glsl_int4__streamEnd( const sint32* value, size_t length );

struct surface____glsl_surface_type__ValidationData
{
    size_t validation_current_state;
    size_t init_as_null;
    size_t init_as_target;
    size_t init_cube;
    size_t init_volume;
    size_t init_planar;
    size_t init_from;
    size_t format;
    size_t format_hint;
    size_t size;
    size_t viewport_ratio;
    size_t mip_levels;
    size_t mipmap_generate;
    size_t extra;
    size_t generator;
};

struct glsl_surface_type____generator__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t code;
    size_t include;
    size_t name;
    size_t setparam;
};

struct setparam____glsl_setparam_simple__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
};

struct sampler1D____gl_sampler1D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct sampler2D____gl_sampler2D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct sampler3D____gl_sampler3D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerCUBE____gl_samplerCUBE__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerRECT____gl_samplerRECT__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerDEPTH____gl_samplerDEPTH__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t extra;
};

ParserError::ErrorType validate__positiveInteger( const uint64 value );

struct array____glsl_newarray_type__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct profile_GLSL__technique__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t code;
    size_t include;
    size_t image;
    size_t newparam;
    size_t setparam;
    size_t pass;
    size_t extra;
};

struct setparam____glsl_setparam__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct array____glsl_setarray_type__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t array;
};

struct profile_GLSL__technique__pass__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
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
    size_t clear_color;
    size_t clear_stencil;
    size_t clear_depth;
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
    size_t auto_normal_enable;
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
    size_t gl_hook_abstract;
    size_t shader;
    size_t extra;
};

struct color_clear____fx_clearcolor_common__ValidationData
{
    size_t validationWholeSize;
};

struct profile_GLSL__technique__pass__alpha_func__ValidationData
{
    size_t func;
    size_t value;
};

struct profile_GLSL__technique__pass__blend_func__ValidationData
{
    size_t src;
    size_t dest;
};

struct blend_func_separate__ValidationData
{
    size_t src_rgb;
    size_t dest_rgb;
    size_t src_alpha;
    size_t dest_alpha;
};

ParserError::ErrorType validate__gl_blend_equation_type( ParserString value );
ParserError::ErrorType validate__gl_blend_equation_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_equation_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_blend_equation_type__streamEnd( const ParserChar* value, size_t length );

struct blend_equation_separate__ValidationData
{
    size_t rgb;
    size_t alpha;
};

struct color_material__ValidationData
{
    size_t face;
    size_t mode;
};

ParserError::ErrorType validate__gl_material_type( ParserString value );
ParserError::ErrorType validate__gl_material_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_material_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_material_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_fog_coord_src_type( ParserString value );
ParserError::ErrorType validate__gl_fog_coord_src_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_coord_src_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_fog_coord_src_type__streamEnd( const ParserChar* value, size_t length );

ParserError::ErrorType validate__gl_light_model_color_control_type( ParserString value );
ParserError::ErrorType validate__gl_light_model_color_control_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_light_model_color_control_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_light_model_color_control_type__streamEnd( const ParserChar* value, size_t length );

struct polygon_mode__ValidationData
{
    size_t face;
    size_t mode;
};

ParserError::ErrorType validate__gl_polygon_mode_type( ParserString value );
ParserError::ErrorType validate__gl_polygon_mode_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_polygon_mode_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_polygon_mode_type__streamEnd( const ParserChar* value, size_t length );

struct profile_GLSL__technique__pass__stencil_func__ValidationData
{
    size_t func;
    size_t ref;
    size_t mask;
};

struct profile_GLSL__technique__pass__stencil_op__ValidationData
{
    size_t fail;
    size_t zfail;
    size_t zpass;
};

ParserError::ErrorType validate__gl_stencil_op_type( ParserString value );
ParserError::ErrorType validate__gl_stencil_op_type( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_stencil_op_type__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__gl_stencil_op_type__streamEnd( const ParserChar* value, size_t length );

struct stencil_func_separate__ValidationData
{
    size_t front;
    size_t back;
    size_t ref;
    size_t mask;
};

struct stencil_op_separate__ValidationData
{
    size_t face;
    size_t fail;
    size_t zfail;
    size_t zpass;
};

struct stencil_mask_separate__ValidationData
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

ParserError::ErrorType validate__glsl_pipeline_stage( ParserString value );
ParserError::ErrorType validate__glsl_pipeline_stage( const ParserChar* value, size_t length );
ParserError::ErrorType validate__glsl_pipeline_stage__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__glsl_pipeline_stage__streamEnd( const ParserChar* value, size_t length );

struct profile_GLSL__technique__pass__shader__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t compiler_target;
    size_t compiler_options;
    size_t name;
    size_t bind;
};

struct profile_GLSL__technique__pass__shader__bind__ValidationData
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerCUBE;
    size_t samplerRECT;
    size_t samplerDEPTH;
    size_t _enum;
    size_t param;
};

struct profile_CG__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t code;
    size_t include;
    size_t image;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____cg_newparam__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t semantic;
    size_t modifier;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t usertype;
    size_t array;
};

struct bool2____cg_bool2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool2( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2__streamEnd( const bool* value, size_t length );

struct bool3____cg_bool3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool3( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3__streamEnd( const bool* value, size_t length );

struct bool4____cg_bool4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool4( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4__streamEnd( const bool* value, size_t length );

struct bool1x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool1x1( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x1__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x1__streamEnd( const bool* value, size_t length );

struct bool1x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool1x2( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x2__streamEnd( const bool* value, size_t length );

struct bool1x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool1x3( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x3__streamEnd( const bool* value, size_t length );

struct bool1x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool1x4( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool1x4__streamEnd( const bool* value, size_t length );

struct bool2x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool2x1( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x1__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x1__streamEnd( const bool* value, size_t length );

struct bool2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool2x2( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x2__streamEnd( const bool* value, size_t length );

struct bool2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool2x3( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x3__streamEnd( const bool* value, size_t length );

struct bool2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool2x4( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool2x4__streamEnd( const bool* value, size_t length );

struct bool3x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool3x1( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x1__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x1__streamEnd( const bool* value, size_t length );

struct bool3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool3x2( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x2__streamEnd( const bool* value, size_t length );

struct bool3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool3x3( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x3__streamEnd( const bool* value, size_t length );

struct bool3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool3x4( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool3x4__streamEnd( const bool* value, size_t length );

struct bool4x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool4x1( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x1__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x1__streamEnd( const bool* value, size_t length );

struct bool4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool4x2( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x2__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x2__streamEnd( const bool* value, size_t length );

struct bool4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool4x3( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x3__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x3__streamEnd( const bool* value, size_t length );

struct bool4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_bool4x4( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x4__stream( const bool* value, size_t length );
ParserError::ErrorType validate__cg_bool4x4__streamEnd( const bool* value, size_t length );

struct float2____cg_float2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float2( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2__streamEnd( const float* value, size_t length );

struct float3____cg_float3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float3( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3__streamEnd( const float* value, size_t length );

struct float4____cg_float4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float4( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4__streamEnd( const float* value, size_t length );

struct float1x1____cg_float1x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float1x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x1__streamEnd( const float* value, size_t length );

struct float1x2____cg_float1x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float1x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x2__streamEnd( const float* value, size_t length );

struct float1x3____cg_float1x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float1x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x3__streamEnd( const float* value, size_t length );

struct float1x4____cg_float1x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float1x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float1x4__streamEnd( const float* value, size_t length );

struct float2x1____cg_float2x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float2x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x1__streamEnd( const float* value, size_t length );

struct float2x2____cg_float2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float2x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x2__streamEnd( const float* value, size_t length );

struct float2x3____cg_float2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float2x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x3__streamEnd( const float* value, size_t length );

struct float2x4____cg_float2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float2x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float2x4__streamEnd( const float* value, size_t length );

struct float3x1____cg_float3x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float3x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x1__streamEnd( const float* value, size_t length );

struct float3x2____cg_float3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float3x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x2__streamEnd( const float* value, size_t length );

struct float3x3____cg_float3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float3x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x3__streamEnd( const float* value, size_t length );

struct float3x4____cg_float3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float3x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float3x4__streamEnd( const float* value, size_t length );

struct float4x1____cg_float4x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float4x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x1__streamEnd( const float* value, size_t length );

struct float4x2____cg_float4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float4x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x2__streamEnd( const float* value, size_t length );

struct float4x3____cg_float4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float4x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x3__streamEnd( const float* value, size_t length );

struct float4x4____cg_float4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_float4x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_float4x4__streamEnd( const float* value, size_t length );

ParserError::ErrorType validate__cg_int( const sint32 value );

ParserError::ErrorType validate__cg_int1( const sint32 value );

struct int2____cg_int2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int2( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2__streamEnd( const sint32* value, size_t length );

struct int3____cg_int3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int3( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3__streamEnd( const sint32* value, size_t length );

struct int4____cg_int4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int4( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4__streamEnd( const sint32* value, size_t length );

struct int1x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int1x1( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x1__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x1__streamEnd( const sint32* value, size_t length );

struct int1x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int1x2( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x2__streamEnd( const sint32* value, size_t length );

struct int1x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int1x3( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x3__streamEnd( const sint32* value, size_t length );

struct int1x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int1x4( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int1x4__streamEnd( const sint32* value, size_t length );

struct int2x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int2x1( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x1__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x1__streamEnd( const sint32* value, size_t length );

struct int2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int2x2( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x2__streamEnd( const sint32* value, size_t length );

struct int2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int2x3( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x3__streamEnd( const sint32* value, size_t length );

struct int2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int2x4( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int2x4__streamEnd( const sint32* value, size_t length );

struct int3x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int3x1( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x1__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x1__streamEnd( const sint32* value, size_t length );

struct int3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int3x2( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x2__streamEnd( const sint32* value, size_t length );

struct int3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int3x3( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x3__streamEnd( const sint32* value, size_t length );

struct int3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int3x4( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int3x4__streamEnd( const sint32* value, size_t length );

struct int4x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int4x1( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x1__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x1__streamEnd( const sint32* value, size_t length );

struct int4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int4x2( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x2__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x2__streamEnd( const sint32* value, size_t length );

struct int4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int4x3( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x3__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x3__streamEnd( const sint32* value, size_t length );

struct int4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_int4x4( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x4__stream( const sint32* value, size_t length );
ParserError::ErrorType validate__cg_int4x4__streamEnd( const sint32* value, size_t length );

struct half2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half2( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2__streamEnd( const float* value, size_t length );

struct half3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half3( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3__streamEnd( const float* value, size_t length );

struct half4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half4( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4__streamEnd( const float* value, size_t length );

struct half1x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half1x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x1__streamEnd( const float* value, size_t length );

struct half1x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half1x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x2__streamEnd( const float* value, size_t length );

struct half1x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half1x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x3__streamEnd( const float* value, size_t length );

struct half1x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half1x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half1x4__streamEnd( const float* value, size_t length );

struct half2x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half2x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x1__streamEnd( const float* value, size_t length );

struct half2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half2x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x2__streamEnd( const float* value, size_t length );

struct half2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half2x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x3__streamEnd( const float* value, size_t length );

struct half2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half2x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half2x4__streamEnd( const float* value, size_t length );

struct half3x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half3x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x1__streamEnd( const float* value, size_t length );

struct half3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half3x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x2__streamEnd( const float* value, size_t length );

struct half3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half3x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x3__streamEnd( const float* value, size_t length );

struct half3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half3x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half3x4__streamEnd( const float* value, size_t length );

struct half4x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half4x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x1__streamEnd( const float* value, size_t length );

struct half4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half4x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x2__streamEnd( const float* value, size_t length );

struct half4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half4x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x3__streamEnd( const float* value, size_t length );

struct half4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_half4x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_half4x4__streamEnd( const float* value, size_t length );

ParserError::ErrorType validate__cg_fixed( const float value );

ParserError::ErrorType validate__cg_fixed1( const float value );

struct fixed2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed2( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2__streamEnd( const float* value, size_t length );

struct fixed3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed3( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3__streamEnd( const float* value, size_t length );

struct fixed4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed4( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4__streamEnd( const float* value, size_t length );

struct fixed1x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed1x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x1__streamEnd( const float* value, size_t length );

struct fixed1x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed1x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x2__streamEnd( const float* value, size_t length );

struct fixed1x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed1x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x3__streamEnd( const float* value, size_t length );

struct fixed1x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed1x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed1x4__streamEnd( const float* value, size_t length );

struct fixed2x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed2x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x1__streamEnd( const float* value, size_t length );

struct fixed2x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed2x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x2__streamEnd( const float* value, size_t length );

struct fixed2x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed2x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x3__streamEnd( const float* value, size_t length );

struct fixed2x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed2x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed2x4__streamEnd( const float* value, size_t length );

struct fixed3x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed3x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x1__streamEnd( const float* value, size_t length );

struct fixed3x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed3x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x2__streamEnd( const float* value, size_t length );

struct fixed3x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed3x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x3__streamEnd( const float* value, size_t length );

struct fixed3x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed3x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed3x4__streamEnd( const float* value, size_t length );

struct fixed4x1__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed4x1( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x1__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x1__streamEnd( const float* value, size_t length );

struct fixed4x2__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed4x2( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x2__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x2__streamEnd( const float* value, size_t length );

struct fixed4x3__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed4x3( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x3__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x3__streamEnd( const float* value, size_t length );

struct fixed4x4__ValidationData
{
    size_t validationWholeSize;
};

ParserError::ErrorType validate__cg_fixed4x4( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x4__stream( const float* value, size_t length );
ParserError::ErrorType validate__cg_fixed4x4__streamEnd( const float* value, size_t length );

struct surface____cg_surface_type__ValidationData
{
    size_t validation_current_state;
    size_t init_as_null;
    size_t init_as_target;
    size_t init_cube;
    size_t init_volume;
    size_t init_planar;
    size_t init_from;
    size_t format;
    size_t format_hint;
    size_t size;
    size_t viewport_ratio;
    size_t mip_levels;
    size_t mipmap_generate;
    size_t extra;
    size_t generator;
};

struct cg_surface_type____generator__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t code;
    size_t include;
    size_t name;
    size_t setparam;
};

struct setparam____cg_setparam_simple__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
};

struct sampler1D____cg_sampler1D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct sampler2D____cg_sampler2D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct sampler3D____cg_sampler3D__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerRECT____cg_samplerRECT__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerCUBE____cg_samplerCUBE__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t wrap_p;
    size_t minfilter;
    size_t magfilter;
    size_t mipfilter;
    size_t border_color;
    size_t mipmap_maxlevel;
    size_t mipmap_bias;
    size_t extra;
};

struct samplerDEPTH____cg_samplerDEPTH__ValidationData
{
    size_t source;
    size_t wrap_s;
    size_t wrap_t;
    size_t minfilter;
    size_t magfilter;
    size_t extra;
};

struct usertype__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
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
    size_t connect_param;
    size_t setparam;
};

struct array____cg_setarray_type__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
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

struct setparam____cg_setparam__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t usertype;
    size_t array;
    size_t connect_param;
};

struct array____cg_newarray_type__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
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
    size_t connect_param;
};

struct profile_CG__technique__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t annotate;
    size_t code;
    size_t include;
    size_t image;
    size_t newparam;
    size_t setparam;
    size_t pass;
    size_t extra;
};

struct profile_CG__technique__pass__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t color_target;
    size_t depth_target;
    size_t stencil_target;
    size_t color_clear;
    size_t depth_clear;
    size_t stencil_clear;
    size_t draw;
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
    size_t clear_color;
    size_t clear_stencil;
    size_t clear_depth;
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
    size_t auto_normal_enable;
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
    size_t gl_hook_abstract;
    size_t shader;
    size_t extra;
};

ParserError::ErrorType validate__cg_pipeline_stage( ParserString value );
ParserError::ErrorType validate__cg_pipeline_stage( const ParserChar* value, size_t length );
ParserError::ErrorType validate__cg_pipeline_stage__stream( const ParserChar* value, size_t length );
ParserError::ErrorType validate__cg_pipeline_stage__streamEnd( const ParserChar* value, size_t length );

struct profile_CG__technique__pass__shader__ValidationData
{
    size_t validation_current_state;
    size_t annotate;
    size_t compiler_target;
    size_t compiler_options;
    size_t name;
    size_t bind;
};

struct profile_CG__technique__pass__shader__bind__ValidationData
{
    size_t validation_current_state;
    size_t _bool;
    size_t bool1;
    size_t bool2;
    size_t bool3;
    size_t bool4;
    size_t bool1x1;
    size_t bool1x2;
    size_t bool1x3;
    size_t bool1x4;
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
    size_t float1;
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
    size_t _int;
    size_t int1;
    size_t int2;
    size_t int3;
    size_t int4;
    size_t int1x1;
    size_t int1x2;
    size_t int1x3;
    size_t int1x4;
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
    size_t half1;
    size_t half2;
    size_t half3;
    size_t half4;
    size_t half1x1;
    size_t half1x2;
    size_t half1x3;
    size_t half1x4;
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
    size_t _fixed1;
    size_t fixed2;
    size_t fixed3;
    size_t fixed4;
    size_t fixed1x1;
    size_t fixed1x2;
    size_t fixed1x3;
    size_t fixed1x4;
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
    size_t surface;
    size_t sampler1D;
    size_t sampler2D;
    size_t sampler3D;
    size_t samplerRECT;
    size_t samplerCUBE;
    size_t samplerDEPTH;
    size_t string;
    size_t _enum;
    size_t param;
};

struct profile_COMMON__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t image;
    size_t newparam;
    size_t technique;
    size_t extra;
};

struct newparam____common_newparam_type__ValidationData
{
    size_t validation_current_state;
    size_t semantic;
    size_t _float;
    size_t float2;
    size_t float3;
    size_t float4;
    size_t surface;
    size_t sampler2D;
};

struct profile_COMMON__technique__ValidationData
{
    size_t validation_current_state;
    size_t asset;
    size_t image;
    size_t newparam;
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

struct common_color_or_texture_type____color__ValidationData
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



} // namespace
#endif
