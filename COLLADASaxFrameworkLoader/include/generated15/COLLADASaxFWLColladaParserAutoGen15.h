/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15_H__
#define __COLLADASAXFWL15_COLLADAPARSERAUTOGEN15_H__


#include "COLLADASaxFWLColladaParserAutoGen15Attributes.h"


namespace COLLADASaxFWL15
{


class ColladaParserAutoGen15
{
public:
ColladaParserAutoGen15(){}
virtual ~ColladaParserAutoGen15(){}


virtual bool begin__COLLADA( const COLLADA__AttributeData& attributeData ){return true;}
virtual bool end__COLLADA(){return true;}

virtual bool begin__asset(){return true;}
virtual bool end__asset(){return true;}

virtual bool begin__contributor(){return true;}
virtual bool end__contributor(){return true;}

virtual bool begin__author(){return true;}
virtual bool end__author(){return true;}
virtual bool data__author( const ParserChar* value, size_t length ){return true;}

virtual bool begin__author_email(){return true;}
virtual bool end__author_email(){return true;}
virtual bool data__author_email( const ParserChar* value, size_t length ){return true;}

virtual bool begin__author_website(){return true;}
virtual bool end__author_website(){return true;}
virtual bool data__author_website( COLLADABU::URI value ){return true;}

virtual bool begin__authoring_tool(){return true;}
virtual bool end__authoring_tool(){return true;}
virtual bool data__authoring_tool( const ParserChar* value, size_t length ){return true;}

virtual bool begin__comments(){return true;}
virtual bool end__comments(){return true;}
virtual bool data__comments( const ParserChar* value, size_t length ){return true;}

virtual bool begin__copyright(){return true;}
virtual bool end__copyright(){return true;}
virtual bool data__copyright( const ParserChar* value, size_t length ){return true;}

virtual bool begin__source_data(){return true;}
virtual bool end__source_data(){return true;}
virtual bool data__source_data( COLLADABU::URI value ){return true;}

virtual bool begin__coverage(){return true;}
virtual bool end__coverage(){return true;}

virtual bool begin__geographic_location(){return true;}
virtual bool end__geographic_location(){return true;}

virtual bool begin__longitude(){return true;}
virtual bool end__longitude(){return true;}
virtual bool data__longitude( float value ){return true;}

virtual bool begin__latitude(){return true;}
virtual bool end__latitude(){return true;}
virtual bool data__latitude( float value ){return true;}

virtual bool begin__altitude( const altitude__AttributeData& attributeData ){return true;}
virtual bool end__altitude(){return true;}
virtual bool data__altitude( float value ){return true;}

virtual bool begin__created(){return true;}
virtual bool end__created(){return true;}
virtual bool data__created( const ParserChar* value, size_t length ){return true;}

virtual bool begin__keywords(){return true;}
virtual bool end__keywords(){return true;}
virtual bool data__keywords( const ParserChar* value, size_t length ){return true;}

virtual bool begin__modified(){return true;}
virtual bool end__modified(){return true;}
virtual bool data__modified( const ParserChar* value, size_t length ){return true;}

virtual bool begin__revision(){return true;}
virtual bool end__revision(){return true;}
virtual bool data__revision( const ParserChar* value, size_t length ){return true;}

virtual bool begin__subject(){return true;}
virtual bool end__subject(){return true;}
virtual bool data__subject( const ParserChar* value, size_t length ){return true;}

virtual bool begin__title(){return true;}
virtual bool end__title(){return true;}
virtual bool data__title( const ParserChar* value, size_t length ){return true;}

virtual bool begin__unit( const unit__AttributeData& attributeData ){return true;}
virtual bool end__unit(){return true;}

virtual bool begin__up_axis(){return true;}
virtual bool end__up_axis(){return true;}
virtual bool data__up_axis( const ENUM__up_axis_enum value ){return true;}

virtual bool begin__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__extra(){return true;}

virtual bool begin__technique____technique_type( const technique____technique_type__AttributeData& attributeData ){return true;}
virtual bool end__technique____technique_type(){return true;}

virtual bool begin__library_animations( const library_animations__AttributeData& attributeData ){return true;}
virtual bool end__library_animations(){return true;}

virtual bool begin__animation( const animation__AttributeData& attributeData ){return true;}
virtual bool end__animation(){return true;}

virtual bool begin__source( const source__AttributeData& attributeData ){return true;}
virtual bool end__source(){return true;}

virtual bool begin__token_array( const token_array__AttributeData& attributeData ){return true;}
virtual bool end__token_array(){return true;}
virtual bool data__token_array( const ParserString* value, size_t length ){return true;}

virtual bool begin__IDREF_array( const IDREF_array__AttributeData& attributeData ){return true;}
virtual bool end__IDREF_array(){return true;}
virtual bool data__IDREF_array( const ParserString* value, size_t length ){return true;}

virtual bool begin__Name_array( const Name_array__AttributeData& attributeData ){return true;}
virtual bool end__Name_array(){return true;}
virtual bool data__Name_array( const ParserString* value, size_t length ){return true;}

virtual bool begin__bool_array( const bool_array__AttributeData& attributeData ){return true;}
virtual bool end__bool_array(){return true;}
virtual bool data__bool_array( const bool* value, size_t length ){return true;}

virtual bool begin__float_array( const float_array__AttributeData& attributeData ){return true;}
virtual bool end__float_array(){return true;}
virtual bool data__float_array( const float* value, size_t length ){return true;}

virtual bool begin__int_array( const int_array__AttributeData& attributeData ){return true;}
virtual bool end__int_array(){return true;}
virtual bool data__int_array( const sint64* value, size_t length ){return true;}

virtual bool begin__SIDREF_array( const SIDREF_array__AttributeData& attributeData ){return true;}
virtual bool end__SIDREF_array(){return true;}
virtual bool data__SIDREF_array( const ParserString* value, size_t length ){return true;}

virtual bool begin__source_type____technique_common(){return true;}
virtual bool end__source_type____technique_common(){return true;}

virtual bool begin__accessor( const accessor__AttributeData& attributeData ){return true;}
virtual bool end__accessor(){return true;}

virtual bool begin__param____param_type( const param____param_type__AttributeData& attributeData ){return true;}
virtual bool end__param____param_type(){return true;}
virtual bool data__param____param_type( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler( const sampler__AttributeData& attributeData ){return true;}
virtual bool end__sampler(){return true;}

virtual bool begin__input____input_local_type( const input____input_local_type__AttributeData& attributeData ){return true;}
virtual bool end__input____input_local_type(){return true;}

virtual bool begin__channel( const channel__AttributeData& attributeData ){return true;}
virtual bool end__channel(){return true;}

virtual bool begin__library_animation_clips( const library_animation_clips__AttributeData& attributeData ){return true;}
virtual bool end__library_animation_clips(){return true;}

virtual bool begin__animation_clip( const animation_clip__AttributeData& attributeData ){return true;}
virtual bool end__animation_clip(){return true;}

virtual bool begin__instance_animation( const instance_animation__AttributeData& attributeData ){return true;}
virtual bool end__instance_animation(){return true;}

virtual bool begin__instance_formula( const instance_formula__AttributeData& attributeData ){return true;}
virtual bool end__instance_formula(){return true;}

virtual bool begin__setparam____formula_setparam_type( const setparam____formula_setparam_type__AttributeData& attributeData ){return true;}
virtual bool end__setparam____formula_setparam_type(){return true;}

virtual bool begin__float____float_type(){return true;}
virtual bool end__float____float_type(){return true;}
virtual bool data__float____float_type( float value ){return true;}

virtual bool begin__int____int_type(){return true;}
virtual bool end__int____int_type(){return true;}
virtual bool data__int____int_type( sint64 value ){return true;}

virtual bool begin__SIDREF(){return true;}
virtual bool end__SIDREF(){return true;}
virtual bool data__SIDREF( const ParserChar* value, size_t length ){return true;}

virtual bool begin__bool(){return true;}
virtual bool end__bool(){return true;}
virtual bool data__bool( bool value ){return true;}

virtual bool begin__connect_param( const connect_param__AttributeData& attributeData ){return true;}
virtual bool end__connect_param(){return true;}

virtual bool begin__library_cameras( const library_cameras__AttributeData& attributeData ){return true;}
virtual bool end__library_cameras(){return true;}

virtual bool begin__camera( const camera__AttributeData& attributeData ){return true;}
virtual bool end__camera(){return true;}

virtual bool begin__optics(){return true;}
virtual bool end__optics(){return true;}

virtual bool begin__optics__technique_common(){return true;}
virtual bool end__optics__technique_common(){return true;}

virtual bool begin__orthographic(){return true;}
virtual bool end__orthographic(){return true;}

virtual bool begin__xmag( const xmag__AttributeData& attributeData ){return true;}
virtual bool end__xmag(){return true;}
virtual bool data__xmag( float value ){return true;}

virtual bool begin__ymag( const ymag__AttributeData& attributeData ){return true;}
virtual bool end__ymag(){return true;}
virtual bool data__ymag( float value ){return true;}

virtual bool begin__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){return true;}
virtual bool end__aspect_ratio(){return true;}
virtual bool data__aspect_ratio( float value ){return true;}

virtual bool begin__znear( const znear__AttributeData& attributeData ){return true;}
virtual bool end__znear(){return true;}
virtual bool data__znear( float value ){return true;}

virtual bool begin__zfar( const zfar__AttributeData& attributeData ){return true;}
virtual bool end__zfar(){return true;}
virtual bool data__zfar( float value ){return true;}

virtual bool begin__perspective(){return true;}
virtual bool end__perspective(){return true;}

virtual bool begin__xfov( const xfov__AttributeData& attributeData ){return true;}
virtual bool end__xfov(){return true;}
virtual bool data__xfov( float value ){return true;}

virtual bool begin__yfov( const yfov__AttributeData& attributeData ){return true;}
virtual bool end__yfov(){return true;}
virtual bool data__yfov( float value ){return true;}

virtual bool begin__imager(){return true;}
virtual bool end__imager(){return true;}

virtual bool begin__library_controllers( const library_controllers__AttributeData& attributeData ){return true;}
virtual bool end__library_controllers(){return true;}

virtual bool begin__controller( const controller__AttributeData& attributeData ){return true;}
virtual bool end__controller(){return true;}

virtual bool begin__skin( const skin__AttributeData& attributeData ){return true;}
virtual bool end__skin(){return true;}

virtual bool begin__bind_shape_matrix(){return true;}
virtual bool end__bind_shape_matrix(){return true;}
virtual bool data__bind_shape_matrix( const float* value, size_t length ){return true;}

virtual bool begin__joints(){return true;}
virtual bool end__joints(){return true;}

virtual bool begin__vertex_weights( const vertex_weights__AttributeData& attributeData ){return true;}
virtual bool end__vertex_weights(){return true;}

virtual bool begin__input____input_local_offset_type( const input____input_local_offset_type__AttributeData& attributeData ){return true;}
virtual bool end__input____input_local_offset_type(){return true;}

virtual bool begin__vcount(){return true;}
virtual bool end__vcount(){return true;}
virtual bool data__vcount( const uint64* value, size_t length ){return true;}

virtual bool begin__v(){return true;}
virtual bool end__v(){return true;}
virtual bool data__v( const sint64* value, size_t length ){return true;}

virtual bool begin__morph( const morph__AttributeData& attributeData ){return true;}
virtual bool end__morph(){return true;}

virtual bool begin__targets(){return true;}
virtual bool end__targets(){return true;}

virtual bool begin__library_geometries( const library_geometries__AttributeData& attributeData ){return true;}
virtual bool end__library_geometries(){return true;}

virtual bool begin__geometry( const geometry__AttributeData& attributeData ){return true;}
virtual bool end__geometry(){return true;}

virtual bool begin__convex_mesh( const convex_mesh__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh(){return true;}

virtual bool begin__vertices( const vertices__AttributeData& attributeData ){return true;}
virtual bool end__vertices(){return true;}

virtual bool begin__lines( const lines__AttributeData& attributeData ){return true;}
virtual bool end__lines(){return true;}

virtual bool begin__p(){return true;}
virtual bool end__p(){return true;}
virtual bool data__p( const uint64* value, size_t length ){return true;}

virtual bool begin__linestrips( const linestrips__AttributeData& attributeData ){return true;}
virtual bool end__linestrips(){return true;}

virtual bool begin__polygons( const polygons__AttributeData& attributeData ){return true;}
virtual bool end__polygons(){return true;}

virtual bool begin__ph(){return true;}
virtual bool end__ph(){return true;}

virtual bool begin__h(){return true;}
virtual bool end__h(){return true;}
virtual bool data__h( const uint64* value, size_t length ){return true;}

virtual bool begin__polylist( const polylist__AttributeData& attributeData ){return true;}
virtual bool end__polylist(){return true;}

virtual bool begin__triangles( const triangles__AttributeData& attributeData ){return true;}
virtual bool end__triangles(){return true;}

virtual bool begin__trifans( const trifans__AttributeData& attributeData ){return true;}
virtual bool end__trifans(){return true;}

virtual bool begin__tristrips( const tristrips__AttributeData& attributeData ){return true;}
virtual bool end__tristrips(){return true;}

virtual bool begin__mesh(){return true;}
virtual bool end__mesh(){return true;}

virtual bool begin__spline( const spline__AttributeData& attributeData ){return true;}
virtual bool end__spline(){return true;}

virtual bool begin__spline_type____control_vertices(){return true;}
virtual bool end__spline_type____control_vertices(){return true;}

virtual bool begin__brep(){return true;}
virtual bool end__brep(){return true;}

virtual bool begin__curves(){return true;}
virtual bool end__curves(){return true;}

virtual bool begin__curve( const curve__AttributeData& attributeData ){return true;}
virtual bool end__curve(){return true;}

virtual bool begin__line(){return true;}
virtual bool end__line(){return true;}

virtual bool begin__origin____float3_type(){return true;}
virtual bool end__origin____float3_type(){return true;}
virtual bool data__origin____float3_type( const float* value, size_t length ){return true;}

virtual bool begin__direction(){return true;}
virtual bool end__direction(){return true;}
virtual bool data__direction( const float* value, size_t length ){return true;}

virtual bool begin__circle(){return true;}
virtual bool end__circle(){return true;}

virtual bool begin__radius____float_type(){return true;}
virtual bool end__radius____float_type(){return true;}
virtual bool data__radius____float_type( float value ){return true;}

virtual bool begin__ellipse(){return true;}
virtual bool end__ellipse(){return true;}

virtual bool begin__radius____float2_type(){return true;}
virtual bool end__radius____float2_type(){return true;}
virtual bool data__radius____float2_type( const float* value, size_t length ){return true;}

virtual bool begin__parabola(){return true;}
virtual bool end__parabola(){return true;}

virtual bool begin__focal(){return true;}
virtual bool end__focal(){return true;}
virtual bool data__focal( float value ){return true;}

virtual bool begin__hyperbola(){return true;}
virtual bool end__hyperbola(){return true;}

virtual bool begin__nurbs( const nurbs__AttributeData& attributeData ){return true;}
virtual bool end__nurbs(){return true;}

virtual bool begin__nurbs_type____control_vertices(){return true;}
virtual bool end__nurbs_type____control_vertices(){return true;}

virtual bool begin__orient(){return true;}
virtual bool end__orient(){return true;}
virtual bool data__orient( const float* value, size_t length ){return true;}

virtual bool begin__origin____origin_type(){return true;}
virtual bool end__origin____origin_type(){return true;}
virtual bool data__origin____origin_type( const float* value, size_t length ){return true;}

virtual bool begin__surface_curves(){return true;}
virtual bool end__surface_curves(){return true;}

virtual bool begin__surfaces(){return true;}
virtual bool end__surfaces(){return true;}

virtual bool begin__surface( const surface__AttributeData& attributeData ){return true;}
virtual bool end__surface(){return true;}

virtual bool begin__plane(){return true;}
virtual bool end__plane(){return true;}

virtual bool begin__equation(){return true;}
virtual bool end__equation(){return true;}
virtual bool data__equation( const float* value, size_t length ){return true;}

virtual bool begin__sphere(){return true;}
virtual bool end__sphere(){return true;}

virtual bool begin__torus(){return true;}
virtual bool end__torus(){return true;}

virtual bool begin__swept_surface(){return true;}
virtual bool end__swept_surface(){return true;}

virtual bool begin__axis____float3_type(){return true;}
virtual bool end__axis____float3_type(){return true;}
virtual bool data__axis____float3_type( const float* value, size_t length ){return true;}

virtual bool begin__nurbs_surface( const nurbs_surface__AttributeData& attributeData ){return true;}
virtual bool end__nurbs_surface(){return true;}

virtual bool begin__nurbs_surface_type____control_vertices(){return true;}
virtual bool end__nurbs_surface_type____control_vertices(){return true;}

virtual bool begin__cone(){return true;}
virtual bool end__cone(){return true;}

virtual bool begin__angle(){return true;}
virtual bool end__angle(){return true;}
virtual bool data__angle( float value ){return true;}

virtual bool begin__surface_type____cylinder(){return true;}
virtual bool end__surface_type____cylinder(){return true;}

virtual bool begin__edges( const edges__AttributeData& attributeData ){return true;}
virtual bool end__edges(){return true;}

virtual bool begin__wires( const wires__AttributeData& attributeData ){return true;}
virtual bool end__wires(){return true;}

virtual bool begin__faces( const faces__AttributeData& attributeData ){return true;}
virtual bool end__faces(){return true;}

virtual bool begin__pcurves( const pcurves__AttributeData& attributeData ){return true;}
virtual bool end__pcurves(){return true;}

virtual bool begin__shells( const shells__AttributeData& attributeData ){return true;}
virtual bool end__shells(){return true;}

virtual bool begin__solids( const solids__AttributeData& attributeData ){return true;}
virtual bool end__solids(){return true;}

virtual bool begin__library_effects( const library_effects__AttributeData& attributeData ){return true;}
virtual bool end__library_effects(){return true;}

virtual bool begin__effect( const effect__AttributeData& attributeData ){return true;}
virtual bool end__effect(){return true;}

virtual bool begin__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__annotate(){return true;}

virtual bool begin__bool2(){return true;}
virtual bool end__bool2(){return true;}
virtual bool data__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__bool3(){return true;}
virtual bool end__bool3(){return true;}
virtual bool data__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__bool4(){return true;}
virtual bool end__bool4(){return true;}
virtual bool data__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__int2(){return true;}
virtual bool end__int2(){return true;}
virtual bool data__int2( const sint64* value, size_t length ){return true;}

virtual bool begin__int3(){return true;}
virtual bool end__int3(){return true;}
virtual bool data__int3( const sint64* value, size_t length ){return true;}

virtual bool begin__int4(){return true;}
virtual bool end__int4(){return true;}
virtual bool data__int4( const sint64* value, size_t length ){return true;}

virtual bool begin__float2(){return true;}
virtual bool end__float2(){return true;}
virtual bool data__float2( const float* value, size_t length ){return true;}

virtual bool begin__float3(){return true;}
virtual bool end__float3(){return true;}
virtual bool data__float3( const float* value, size_t length ){return true;}

virtual bool begin__float4(){return true;}
virtual bool end__float4(){return true;}
virtual bool data__float4( const float* value, size_t length ){return true;}

virtual bool begin__float2x2(){return true;}
virtual bool end__float2x2(){return true;}
virtual bool data__float2x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x3(){return true;}
virtual bool end__float3x3(){return true;}
virtual bool data__float3x3( const float* value, size_t length ){return true;}

virtual bool begin__float4x4(){return true;}
virtual bool end__float4x4(){return true;}
virtual bool data__float4x4( const float* value, size_t length ){return true;}

virtual bool begin__string(){return true;}
virtual bool end__string(){return true;}
virtual bool data__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__newparam____fx_newparam_type( const newparam____fx_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____fx_newparam_type(){return true;}

virtual bool begin__semantic____NCName(){return true;}
virtual bool end__semantic____NCName(){return true;}
virtual bool data__semantic____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__modifier(){return true;}
virtual bool end__modifier(){return true;}
virtual bool data__modifier( const ENUM__fx_modifier_enum value ){return true;}

virtual bool begin__float2x1(){return true;}
virtual bool end__float2x1(){return true;}
virtual bool data__float2x1( const float* value, size_t length ){return true;}

virtual bool begin__float2x3(){return true;}
virtual bool end__float2x3(){return true;}
virtual bool data__float2x3( const float* value, size_t length ){return true;}

virtual bool begin__float2x4(){return true;}
virtual bool end__float2x4(){return true;}
virtual bool data__float2x4( const float* value, size_t length ){return true;}

virtual bool begin__float3x1(){return true;}
virtual bool end__float3x1(){return true;}
virtual bool data__float3x1( const float* value, size_t length ){return true;}

virtual bool begin__float3x2(){return true;}
virtual bool end__float3x2(){return true;}
virtual bool data__float3x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x4(){return true;}
virtual bool end__float3x4(){return true;}
virtual bool data__float3x4( const float* value, size_t length ){return true;}

virtual bool begin__float4x1(){return true;}
virtual bool end__float4x1(){return true;}
virtual bool data__float4x1( const float* value, size_t length ){return true;}

virtual bool begin__float4x2(){return true;}
virtual bool end__float4x2(){return true;}
virtual bool data__float4x2( const float* value, size_t length ){return true;}

virtual bool begin__float4x3(){return true;}
virtual bool end__float4x3(){return true;}
virtual bool data__float4x3( const float* value, size_t length ){return true;}

virtual bool begin__sampler1D(){return true;}
virtual bool end__sampler1D(){return true;}

virtual bool begin__instance_image( const instance_image__AttributeData& attributeData ){return true;}
virtual bool end__instance_image(){return true;}

virtual bool begin__wrap_s____fx_sampler_wrap_enum(){return true;}
virtual bool end__wrap_s____fx_sampler_wrap_enum(){return true;}
virtual bool data__wrap_s____fx_sampler_wrap_enum( const ENUM__fx_sampler_wrap_enum value ){return true;}

virtual bool begin__wrap_t____fx_sampler_wrap_enum(){return true;}
virtual bool end__wrap_t____fx_sampler_wrap_enum(){return true;}
virtual bool data__wrap_t____fx_sampler_wrap_enum( const ENUM__fx_sampler_wrap_enum value ){return true;}

virtual bool begin__wrap_p(){return true;}
virtual bool end__wrap_p(){return true;}
virtual bool data__wrap_p( const ENUM__fx_sampler_wrap_enum value ){return true;}

virtual bool begin__minfilter(){return true;}
virtual bool end__minfilter(){return true;}
virtual bool data__minfilter( const ENUM__fx_sampler_min_filter_enum value ){return true;}

virtual bool begin__magfilter(){return true;}
virtual bool end__magfilter(){return true;}
virtual bool data__magfilter( const ENUM__fx_sampler_mag_filter_enum value ){return true;}

virtual bool begin__mipfilter(){return true;}
virtual bool end__mipfilter(){return true;}
virtual bool data__mipfilter( const ENUM__fx_sampler_mip_filter_enum value ){return true;}

virtual bool begin__border_color(){return true;}
virtual bool end__border_color(){return true;}
virtual bool data__border_color( const float* value, size_t length ){return true;}

virtual bool begin__mip_max_level(){return true;}
virtual bool end__mip_max_level(){return true;}
virtual bool data__mip_max_level( uint8 value ){return true;}

virtual bool begin__mip_min_level(){return true;}
virtual bool end__mip_min_level(){return true;}
virtual bool data__mip_min_level( uint8 value ){return true;}

virtual bool begin__mip_bias(){return true;}
virtual bool end__mip_bias(){return true;}
virtual bool data__mip_bias( float value ){return true;}

virtual bool begin__max_anisotropy(){return true;}
virtual bool end__max_anisotropy(){return true;}
virtual bool data__max_anisotropy( uint32 value ){return true;}

virtual bool begin__sampler2D____fx_sampler2D_type(){return true;}
virtual bool end__sampler2D____fx_sampler2D_type(){return true;}

virtual bool begin__sampler3D(){return true;}
virtual bool end__sampler3D(){return true;}

virtual bool begin__samplerCUBE(){return true;}
virtual bool end__samplerCUBE(){return true;}

virtual bool begin__samplerRECT(){return true;}
virtual bool end__samplerRECT(){return true;}

virtual bool begin__samplerDEPTH(){return true;}
virtual bool end__samplerDEPTH(){return true;}

virtual bool begin__enum____string(){return true;}
virtual bool end__enum____string(){return true;}
virtual bool data__enum____string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON(){return true;}

virtual bool begin__newparam____fx_common_newparam_type( const newparam____fx_common_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____fx_common_newparam_type(){return true;}

virtual bool begin__profile_common_type____technique( const profile_common_type____technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_common_type____technique(){return true;}

virtual bool begin__profile_COMMON__technique__constant(){return true;}
virtual bool end__profile_COMMON__technique__constant(){return true;}

virtual bool begin__emission(){return true;}
virtual bool end__emission(){return true;}

virtual bool begin__fx_common_color_or_texture_type____color( const fx_common_color_or_texture_type____color__AttributeData& attributeData ){return true;}
virtual bool end__fx_common_color_or_texture_type____color(){return true;}
virtual bool data__fx_common_color_or_texture_type____color( const float* value, size_t length ){return true;}

virtual bool begin__fx_common_color_or_texture_type____param( const fx_common_color_or_texture_type____param__AttributeData& attributeData ){return true;}
virtual bool end__fx_common_color_or_texture_type____param(){return true;}

virtual bool begin__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__texture(){return true;}

virtual bool begin__reflective(){return true;}
virtual bool end__reflective(){return true;}

virtual bool begin__reflectivity(){return true;}
virtual bool end__reflectivity(){return true;}

virtual bool begin__fx_common_float_or_param_type____float( const fx_common_float_or_param_type____float__AttributeData& attributeData ){return true;}
virtual bool end__fx_common_float_or_param_type____float(){return true;}
virtual bool data__fx_common_float_or_param_type____float( float value ){return true;}

virtual bool begin__fx_common_float_or_param_type____param( const fx_common_float_or_param_type____param__AttributeData& attributeData ){return true;}
virtual bool end__fx_common_float_or_param_type____param(){return true;}

virtual bool begin__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__transparent(){return true;}

virtual bool begin__transparency(){return true;}
virtual bool end__transparency(){return true;}

virtual bool begin__index_of_refraction(){return true;}
virtual bool end__index_of_refraction(){return true;}

virtual bool begin__lambert(){return true;}
virtual bool end__lambert(){return true;}

virtual bool begin__ambient____fx_common_color_or_texture_type(){return true;}
virtual bool end__ambient____fx_common_color_or_texture_type(){return true;}

virtual bool begin__diffuse(){return true;}
virtual bool end__diffuse(){return true;}

virtual bool begin__phong(){return true;}
virtual bool end__phong(){return true;}

virtual bool begin__specular(){return true;}
virtual bool end__specular(){return true;}

virtual bool begin__shininess(){return true;}
virtual bool end__shininess(){return true;}

virtual bool begin__blinn(){return true;}
virtual bool end__blinn(){return true;}

virtual bool begin__profile_BRIDGE( const profile_BRIDGE__AttributeData& attributeData ){return true;}
virtual bool end__profile_BRIDGE(){return true;}

virtual bool begin__profile_GLES2( const profile_GLES2__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2(){return true;}

virtual bool begin__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__include(){return true;}

virtual bool begin__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__code(){return true;}
virtual bool data__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_gles2_type____newparam( const profile_gles2_type____newparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_gles2_type____newparam(){return true;}

virtual bool begin__bvec2(){return true;}
virtual bool end__bvec2(){return true;}
virtual bool data__bvec2( const bool* value, size_t length ){return true;}

virtual bool begin__bvec3(){return true;}
virtual bool end__bvec3(){return true;}
virtual bool data__bvec3( const bool* value, size_t length ){return true;}

virtual bool begin__bvec4(){return true;}
virtual bool end__bvec4(){return true;}
virtual bool data__bvec4( const bool* value, size_t length ){return true;}

virtual bool begin__vec2(){return true;}
virtual bool end__vec2(){return true;}
virtual bool data__vec2( const float* value, size_t length ){return true;}

virtual bool begin__vec3(){return true;}
virtual bool end__vec3(){return true;}
virtual bool data__vec3( const float* value, size_t length ){return true;}

virtual bool begin__vec4(){return true;}
virtual bool end__vec4(){return true;}
virtual bool data__vec4( const float* value, size_t length ){return true;}

virtual bool begin__mat2(){return true;}
virtual bool end__mat2(){return true;}
virtual bool data__mat2( const float* value, size_t length ){return true;}

virtual bool begin__mat3(){return true;}
virtual bool end__mat3(){return true;}
virtual bool data__mat3( const float* value, size_t length ){return true;}

virtual bool begin__mat4(){return true;}
virtual bool end__mat4(){return true;}
virtual bool data__mat4( const float* value, size_t length ){return true;}

virtual bool begin__ivec2(){return true;}
virtual bool end__ivec2(){return true;}
virtual bool data__ivec2( const sint64* value, size_t length ){return true;}

virtual bool begin__ivec3(){return true;}
virtual bool end__ivec3(){return true;}
virtual bool data__ivec3( const sint64* value, size_t length ){return true;}

virtual bool begin__ivec4(){return true;}
virtual bool end__ivec4(){return true;}
virtual bool data__ivec4( const sint64* value, size_t length ){return true;}

virtual bool begin__enum____gl_enumeration_type(){return true;}
virtual bool end__enum____gl_enumeration_type(){return true;}
virtual bool data__enum____gl_enumeration_type( UNION__gl_enumeration_type value ){return true;}

virtual bool begin__profile_GLES2__newparam__usertype( const profile_GLES2__newparam__usertype__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__newparam__usertype(){return true;}

virtual bool begin__profile_GLES2__newparam__usertype__setparam( const profile_GLES2__newparam__usertype__setparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__newparam__usertype__setparam(){return true;}

virtual bool begin__profile_GLES2__newparam__usertype__setparam__array( const profile_GLES2__newparam__usertype__setparam__array__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__newparam__usertype__setparam__array(){return true;}

virtual bool begin__profile_gles2_type____technique( const profile_gles2_type____technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_gles2_type____technique(){return true;}

virtual bool begin__pass____gles2_pass_type( const pass____gles2_pass_type__AttributeData& attributeData ){return true;}
virtual bool end__pass____gles2_pass_type(){return true;}

virtual bool begin__gles2_pass_type____states(){return true;}
virtual bool end__gles2_pass_type____states(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_color( const profile_GLES2__technique__pass__states__blend_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_color(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_equation( const profile_GLES2__technique__pass__states__blend_equation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_equation(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_equation_separate(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_equation_separate(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_equation_separate__rgb( const profile_GLES2__technique__pass__states__blend_equation_separate__rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_equation_separate__rgb(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_equation_separate__alpha( const profile_GLES2__technique__pass__states__blend_equation_separate__alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_equation_separate__alpha(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func__src( const profile_GLES2__technique__pass__states__blend_func__src__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func__src(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func__dest( const profile_GLES2__technique__pass__states__blend_func__dest__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func__dest(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func_separate(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func_separate(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb( const profile_GLES2__technique__pass__states__blend_func_separate__src_rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func_separate__src_rgb(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb( const profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func_separate__dest_rgb(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha( const profile_GLES2__technique__pass__states__blend_func_separate__src_alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func_separate__src_alpha(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha( const profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_func_separate__dest_alpha(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__color_mask( const profile_GLES2__technique__pass__states__color_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__color_mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__cull_face( const profile_GLES2__technique__pass__states__cull_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__cull_face(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__depth_func( const profile_GLES2__technique__pass__states__depth_func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__depth_func(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__depth_mask( const profile_GLES2__technique__pass__states__depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__depth_mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__depth_range( const profile_GLES2__technique__pass__states__depth_range__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__depth_range(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__front_face( const profile_GLES2__technique__pass__states__front_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__front_face(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__line_width( const profile_GLES2__technique__pass__states__line_width__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__line_width(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__polygon_offset( const profile_GLES2__technique__pass__states__polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__polygon_offset(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__point_size( const profile_GLES2__technique__pass__states__point_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__point_size(){return true;}

virtual bool begin__sample_coverage(){return true;}
virtual bool end__sample_coverage(){return true;}

virtual bool begin__sample_coverage__value( const sample_coverage__value__AttributeData& attributeData ){return true;}
virtual bool end__sample_coverage__value(){return true;}

virtual bool begin__invert( const invert__AttributeData& attributeData ){return true;}
virtual bool end__invert(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__scissor( const profile_GLES2__technique__pass__states__scissor__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__scissor(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func__func( const profile_GLES2__technique__pass__states__stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func__func(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func__ref( const profile_GLES2__technique__pass__states__stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func__ref(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func__mask( const profile_GLES2__technique__pass__states__stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func__mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func_separate(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func_separate(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func_separate__front( const profile_GLES2__technique__pass__states__stencil_func_separate__front__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func_separate__front(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func_separate__back( const profile_GLES2__technique__pass__states__stencil_func_separate__back__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func_separate__back(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func_separate__ref( const profile_GLES2__technique__pass__states__stencil_func_separate__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func_separate__ref(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_func_separate__mask( const profile_GLES2__technique__pass__states__stencil_func_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_func_separate__mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_mask( const profile_GLES2__technique__pass__states__stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_mask_separate(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_mask_separate(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_mask_separate__face( const profile_GLES2__technique__pass__states__stencil_mask_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_mask_separate__face(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_mask_separate__mask( const profile_GLES2__technique__pass__states__stencil_mask_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_mask_separate__mask(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op__fail( const profile_GLES2__technique__pass__states__stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op__fail(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op__zfail( const profile_GLES2__technique__pass__states__stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op__zfail(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op__zpass( const profile_GLES2__technique__pass__states__stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op__zpass(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op_separate(){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op_separate(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op_separate__face( const profile_GLES2__technique__pass__states__stencil_op_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op_separate__face(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op_separate__fail( const profile_GLES2__technique__pass__states__stencil_op_separate__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op_separate__fail(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op_separate__zfail( const profile_GLES2__technique__pass__states__stencil_op_separate__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op_separate__zfail(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_op_separate__zpass( const profile_GLES2__technique__pass__states__stencil_op_separate__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_op_separate__zpass(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__blend_enable( const profile_GLES2__technique__pass__states__blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__blend_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__cull_face_enable( const profile_GLES2__technique__pass__states__cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__cull_face_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__depth_test_enable( const profile_GLES2__technique__pass__states__depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__depth_test_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__dither_enable( const profile_GLES2__technique__pass__states__dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__dither_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__polygon_offset_fill_enable( const profile_GLES2__technique__pass__states__polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__polygon_offset_fill_enable(){return true;}

virtual bool begin__point_size_enable( const point_size_enable__AttributeData& attributeData ){return true;}
virtual bool end__point_size_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable( const profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__sample_coverage_enable( const profile_GLES2__technique__pass__states__sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__sample_coverage_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__scissor_test_enable( const profile_GLES2__technique__pass__states__scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__scissor_test_enable(){return true;}

virtual bool begin__profile_GLES2__technique__pass__states__stencil_test_enable( const profile_GLES2__technique__pass__states__stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__states__stencil_test_enable(){return true;}

virtual bool begin__program____gles2_program_type(){return true;}
virtual bool end__program____gles2_program_type(){return true;}

virtual bool begin__shader____gles2_shader_type( const shader____gles2_shader_type__AttributeData& attributeData ){return true;}
virtual bool end__shader____gles2_shader_type(){return true;}

virtual bool begin__gles2_shader_type____sources( const gles2_shader_type____sources__AttributeData& attributeData ){return true;}
virtual bool end__gles2_shader_type____sources(){return true;}

virtual bool begin__inline(){return true;}
virtual bool end__inline(){return true;}
virtual bool data__inline( const ParserChar* value, size_t length ){return true;}

virtual bool begin__import( const import__AttributeData& attributeData ){return true;}
virtual bool end__import(){return true;}

virtual bool begin__compiler( const compiler__AttributeData& attributeData ){return true;}
virtual bool end__compiler(){return true;}

virtual bool begin__binary(){return true;}
virtual bool end__binary(){return true;}

virtual bool begin__ref____anyURI(){return true;}
virtual bool end__ref____anyURI(){return true;}
virtual bool data__ref____anyURI( COLLADABU::URI value ){return true;}

virtual bool begin__binary__hex( const binary__hex__AttributeData& attributeData ){return true;}
virtual bool end__binary__hex(){return true;}
virtual bool data__binary__hex( const uint8* value, size_t length ){return true;}

virtual bool begin__linker( const linker__AttributeData& attributeData ){return true;}
virtual bool end__linker(){return true;}

virtual bool begin__gles2_program_type____bind_attribute( const gles2_program_type____bind_attribute__AttributeData& attributeData ){return true;}
virtual bool end__gles2_program_type____bind_attribute(){return true;}

virtual bool begin__semantic____token(){return true;}
virtual bool end__semantic____token(){return true;}
virtual bool data__semantic____token( const ParserChar* value, size_t length ){return true;}

virtual bool begin__gles2_program_type____bind_uniform( const gles2_program_type____bind_uniform__AttributeData& attributeData ){return true;}
virtual bool end__gles2_program_type____bind_uniform(){return true;}

virtual bool begin__profile_GLES2__technique__pass__program__bind_uniform__param( const profile_GLES2__technique__pass__program__bind_uniform__param__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES2__technique__pass__program__bind_uniform__param(){return true;}

virtual bool begin__gles2_pass_type____evaluate(){return true;}
virtual bool end__gles2_pass_type____evaluate(){return true;}

virtual bool begin__color_target( const color_target__AttributeData& attributeData ){return true;}
virtual bool end__color_target(){return true;}

virtual bool begin__fx_colortarget_type____param( const fx_colortarget_type____param__AttributeData& attributeData ){return true;}
virtual bool end__fx_colortarget_type____param(){return true;}

virtual bool begin__depth_target( const depth_target__AttributeData& attributeData ){return true;}
virtual bool end__depth_target(){return true;}

virtual bool begin__stencil_target( const stencil_target__AttributeData& attributeData ){return true;}
virtual bool end__stencil_target(){return true;}

virtual bool begin__color_clear( const color_clear__AttributeData& attributeData ){return true;}
virtual bool end__color_clear(){return true;}
virtual bool data__color_clear( const float* value, size_t length ){return true;}

virtual bool begin__stencil_clear( const stencil_clear__AttributeData& attributeData ){return true;}
virtual bool end__stencil_clear(){return true;}
virtual bool data__stencil_clear( sint8 value ){return true;}

virtual bool begin__depth_clear( const depth_clear__AttributeData& attributeData ){return true;}
virtual bool end__depth_clear(){return true;}
virtual bool data__depth_clear( float value ){return true;}

virtual bool begin__draw(){return true;}
virtual bool end__draw(){return true;}
virtual bool data__draw( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLSL( const profile_GLSL__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL(){return true;}

virtual bool begin__newparam____glsl_newparam_type( const newparam____glsl_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____glsl_newparam_type(){return true;}

virtual bool begin__array____glsl_array_type( const array____glsl_array_type__AttributeData& attributeData ){return true;}
virtual bool end__array____glsl_array_type(){return true;}

virtual bool begin__profile_glsl_type____technique( const profile_glsl_type____technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_glsl_type____technique(){return true;}

virtual bool begin__profile_GLSL__technique__pass( const profile_GLSL__technique__pass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states(){return true;}
virtual bool end__profile_GLSL__technique__pass__states(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__alpha_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__alpha_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__alpha_func__func( const profile_GLSL__technique__pass__states__alpha_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__alpha_func__func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__alpha_func__value( const profile_GLSL__technique__pass__states__alpha_func__value__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__alpha_func__value(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func__src( const profile_GLSL__technique__pass__states__blend_func__src__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func__src(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func__dest( const profile_GLSL__technique__pass__states__blend_func__dest__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func__dest(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func_separate(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func_separate(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb( const profile_GLSL__technique__pass__states__blend_func_separate__src_rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func_separate__src_rgb(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb( const profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func_separate__dest_rgb(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha( const profile_GLSL__technique__pass__states__blend_func_separate__src_alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func_separate__src_alpha(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha( const profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_func_separate__dest_alpha(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_equation( const profile_GLSL__technique__pass__states__blend_equation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_equation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_equation_separate(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_equation_separate(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_equation_separate__rgb( const profile_GLSL__technique__pass__states__blend_equation_separate__rgb__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_equation_separate__rgb(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_equation_separate__alpha( const profile_GLSL__technique__pass__states__blend_equation_separate__alpha__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_equation_separate__alpha(){return true;}

virtual bool begin__color_material(){return true;}
virtual bool end__color_material(){return true;}

virtual bool begin__color_material__face( const color_material__face__AttributeData& attributeData ){return true;}
virtual bool end__color_material__face(){return true;}

virtual bool begin__color_material__mode( const color_material__mode__AttributeData& attributeData ){return true;}
virtual bool end__color_material__mode(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__cull_face( const profile_GLSL__technique__pass__states__cull_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__cull_face(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__depth_func( const profile_GLSL__technique__pass__states__depth_func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__depth_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_mode( const profile_GLSL__technique__pass__states__fog_mode__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_mode(){return true;}

virtual bool begin__fog_coord_src( const fog_coord_src__AttributeData& attributeData ){return true;}
virtual bool end__fog_coord_src(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__front_face( const profile_GLSL__technique__pass__states__front_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__front_face(){return true;}

virtual bool begin__light_model_color_control( const light_model_color_control__AttributeData& attributeData ){return true;}
virtual bool end__light_model_color_control(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__logic_op( const profile_GLSL__technique__pass__states__logic_op__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__logic_op(){return true;}

virtual bool begin__polygon_mode(){return true;}
virtual bool end__polygon_mode(){return true;}

virtual bool begin__polygon_mode__face( const polygon_mode__face__AttributeData& attributeData ){return true;}
virtual bool end__polygon_mode__face(){return true;}

virtual bool begin__polygon_mode__mode( const polygon_mode__mode__AttributeData& attributeData ){return true;}
virtual bool end__polygon_mode__mode(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__shade_model( const profile_GLSL__technique__pass__states__shade_model__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__shade_model(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func__func( const profile_GLSL__technique__pass__states__stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func__func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func__ref( const profile_GLSL__technique__pass__states__stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func__ref(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func__mask( const profile_GLSL__technique__pass__states__stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func__mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op__fail( const profile_GLSL__technique__pass__states__stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op__fail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op__zfail( const profile_GLSL__technique__pass__states__stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op__zfail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op__zpass( const profile_GLSL__technique__pass__states__stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op__zpass(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func_separate(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func_separate(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func_separate__front( const profile_GLSL__technique__pass__states__stencil_func_separate__front__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func_separate__front(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func_separate__back( const profile_GLSL__technique__pass__states__stencil_func_separate__back__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func_separate__back(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func_separate__ref( const profile_GLSL__technique__pass__states__stencil_func_separate__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func_separate__ref(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_func_separate__mask( const profile_GLSL__technique__pass__states__stencil_func_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_func_separate__mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op_separate(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op_separate(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op_separate__face( const profile_GLSL__technique__pass__states__stencil_op_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op_separate__face(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op_separate__fail( const profile_GLSL__technique__pass__states__stencil_op_separate__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op_separate__fail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op_separate__zfail( const profile_GLSL__technique__pass__states__stencil_op_separate__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op_separate__zfail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_op_separate__zpass( const profile_GLSL__technique__pass__states__stencil_op_separate__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_op_separate__zpass(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_mask_separate(){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_mask_separate(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_mask_separate__face( const profile_GLSL__technique__pass__states__stencil_mask_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_mask_separate__face(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_mask_separate__mask( const profile_GLSL__technique__pass__states__stencil_mask_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_mask_separate__mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_enable( const profile_GLSL__technique__pass__states__light_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_ambient( const profile_GLSL__technique__pass__states__light_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_diffuse( const profile_GLSL__technique__pass__states__light_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_diffuse(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_specular( const profile_GLSL__technique__pass__states__light_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_specular(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_position( const profile_GLSL__technique__pass__states__light_position__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_position(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_constant_attenuation( const profile_GLSL__technique__pass__states__light_constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_constant_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_linear_attenuation( const profile_GLSL__technique__pass__states__light_linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_linear_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_quadratic_attenuation( const profile_GLSL__technique__pass__states__light_quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_quadratic_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_spot_cutoff( const profile_GLSL__technique__pass__states__light_spot_cutoff__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_spot_cutoff(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_spot_direction( const profile_GLSL__technique__pass__states__light_spot_direction__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_spot_direction(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_spot_exponent( const profile_GLSL__technique__pass__states__light_spot_exponent__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_spot_exponent(){return true;}

virtual bool begin__texture1D( const texture1D__AttributeData& attributeData ){return true;}
virtual bool end__texture1D(){return true;}

virtual bool begin__value____fx_sampler1D_type(){return true;}
virtual bool end__value____fx_sampler1D_type(){return true;}

virtual bool begin__param____NCName(){return true;}
virtual bool end__param____NCName(){return true;}
virtual bool data__param____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__texture2D( const texture2D__AttributeData& attributeData ){return true;}
virtual bool end__texture2D(){return true;}

virtual bool begin__value____fx_sampler2D_type(){return true;}
virtual bool end__value____fx_sampler2D_type(){return true;}

virtual bool begin__texture3D( const texture3D__AttributeData& attributeData ){return true;}
virtual bool end__texture3D(){return true;}

virtual bool begin__value____fx_sampler3D_type(){return true;}
virtual bool end__value____fx_sampler3D_type(){return true;}

virtual bool begin__textureCUBE( const textureCUBE__AttributeData& attributeData ){return true;}
virtual bool end__textureCUBE(){return true;}

virtual bool begin__value____fx_samplerCUBE_type(){return true;}
virtual bool end__value____fx_samplerCUBE_type(){return true;}

virtual bool begin__textureRECT( const textureRECT__AttributeData& attributeData ){return true;}
virtual bool end__textureRECT(){return true;}

virtual bool begin__value____fx_samplerRECT_type(){return true;}
virtual bool end__value____fx_samplerRECT_type(){return true;}

virtual bool begin__textureDEPTH( const textureDEPTH__AttributeData& attributeData ){return true;}
virtual bool end__textureDEPTH(){return true;}

virtual bool begin__value____fx_samplerDEPTH_type(){return true;}
virtual bool end__value____fx_samplerDEPTH_type(){return true;}

virtual bool begin__texture1D_enable( const texture1D_enable__AttributeData& attributeData ){return true;}
virtual bool end__texture1D_enable(){return true;}

virtual bool begin__texture2D_enable( const texture2D_enable__AttributeData& attributeData ){return true;}
virtual bool end__texture2D_enable(){return true;}

virtual bool begin__texture3D_enable( const texture3D_enable__AttributeData& attributeData ){return true;}
virtual bool end__texture3D_enable(){return true;}

virtual bool begin__textureCUBE_enable( const textureCUBE_enable__AttributeData& attributeData ){return true;}
virtual bool end__textureCUBE_enable(){return true;}

virtual bool begin__textureRECT_enable( const textureRECT_enable__AttributeData& attributeData ){return true;}
virtual bool end__textureRECT_enable(){return true;}

virtual bool begin__textureDEPTH_enable( const textureDEPTH_enable__AttributeData& attributeData ){return true;}
virtual bool end__textureDEPTH_enable(){return true;}

virtual bool begin__texture_env_color( const texture_env_color__AttributeData& attributeData ){return true;}
virtual bool end__texture_env_color(){return true;}

virtual bool begin__texture_env_mode( const texture_env_mode__AttributeData& attributeData ){return true;}
virtual bool end__texture_env_mode(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__clip_plane( const profile_GLSL__technique__pass__states__clip_plane__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__clip_plane(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__clip_plane_enable( const profile_GLSL__technique__pass__states__clip_plane_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__clip_plane_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_color( const profile_GLSL__technique__pass__states__blend_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_color(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__color_mask( const profile_GLSL__technique__pass__states__color_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__color_mask(){return true;}

virtual bool begin__depth_bounds( const depth_bounds__AttributeData& attributeData ){return true;}
virtual bool end__depth_bounds(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__depth_mask( const profile_GLSL__technique__pass__states__depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__depth_mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__depth_range( const profile_GLSL__technique__pass__states__depth_range__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__depth_range(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_density( const profile_GLSL__technique__pass__states__fog_density__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_density(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_start( const profile_GLSL__technique__pass__states__fog_start__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_start(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_end( const profile_GLSL__technique__pass__states__fog_end__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_end(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_color( const profile_GLSL__technique__pass__states__fog_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_color(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_model_ambient( const profile_GLSL__technique__pass__states__light_model_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_model_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__lighting_enable( const profile_GLSL__technique__pass__states__lighting_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__lighting_enable(){return true;}

virtual bool begin__line_stipple( const line_stipple__AttributeData& attributeData ){return true;}
virtual bool end__line_stipple(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__line_width( const profile_GLSL__technique__pass__states__line_width__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__line_width(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__material_ambient( const profile_GLSL__technique__pass__states__material_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__material_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__material_diffuse( const profile_GLSL__technique__pass__states__material_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__material_diffuse(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__material_emission( const profile_GLSL__technique__pass__states__material_emission__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__material_emission(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__material_shininess( const profile_GLSL__technique__pass__states__material_shininess__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__material_shininess(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__material_specular( const profile_GLSL__technique__pass__states__material_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__material_specular(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__model_view_matrix( const profile_GLSL__technique__pass__states__model_view_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__model_view_matrix(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_distance_attenuation( const profile_GLSL__technique__pass__states__point_distance_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_distance_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_fade_threshold_size( const profile_GLSL__technique__pass__states__point_fade_threshold_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_fade_threshold_size(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_size( const profile_GLSL__technique__pass__states__point_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_size(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_size_min( const profile_GLSL__technique__pass__states__point_size_min__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_size_min(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_size_max( const profile_GLSL__technique__pass__states__point_size_max__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_size_max(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__polygon_offset( const profile_GLSL__technique__pass__states__polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__polygon_offset(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__projection_matrix( const profile_GLSL__technique__pass__states__projection_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__projection_matrix(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__scissor( const profile_GLSL__technique__pass__states__scissor__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__scissor(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_mask( const profile_GLSL__technique__pass__states__stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__alpha_test_enable( const profile_GLSL__technique__pass__states__alpha_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__alpha_test_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__blend_enable( const profile_GLSL__technique__pass__states__blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__blend_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__color_logic_op_enable( const profile_GLSL__technique__pass__states__color_logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__color_logic_op_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__color_material_enable( const profile_GLSL__technique__pass__states__color_material_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__color_material_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__cull_face_enable( const profile_GLSL__technique__pass__states__cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__cull_face_enable(){return true;}

virtual bool begin__depth_bounds_enable( const depth_bounds_enable__AttributeData& attributeData ){return true;}
virtual bool end__depth_bounds_enable(){return true;}

virtual bool begin__depth_clamp_enable( const depth_clamp_enable__AttributeData& attributeData ){return true;}
virtual bool end__depth_clamp_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__depth_test_enable( const profile_GLSL__technique__pass__states__depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__depth_test_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__dither_enable( const profile_GLSL__technique__pass__states__dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__dither_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__fog_enable( const profile_GLSL__technique__pass__states__fog_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__fog_enable(){return true;}

virtual bool begin__light_model_local_viewer_enable( const light_model_local_viewer_enable__AttributeData& attributeData ){return true;}
virtual bool end__light_model_local_viewer_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__light_model_two_side_enable( const profile_GLSL__technique__pass__states__light_model_two_side_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__light_model_two_side_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__line_smooth_enable( const profile_GLSL__technique__pass__states__line_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__line_smooth_enable(){return true;}

virtual bool begin__line_stipple_enable( const line_stipple_enable__AttributeData& attributeData ){return true;}
virtual bool end__line_stipple_enable(){return true;}

virtual bool begin__logic_op_enable( const logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__logic_op_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__multisample_enable( const profile_GLSL__technique__pass__states__multisample_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__multisample_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__normalize_enable( const profile_GLSL__technique__pass__states__normalize_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__normalize_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__point_smooth_enable( const profile_GLSL__technique__pass__states__point_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__point_smooth_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__polygon_offset_fill_enable( const profile_GLSL__technique__pass__states__polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__polygon_offset_fill_enable(){return true;}

virtual bool begin__polygon_offset_line_enable( const polygon_offset_line_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset_line_enable(){return true;}

virtual bool begin__polygon_offset_point_enable( const polygon_offset_point_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset_point_enable(){return true;}

virtual bool begin__polygon_smooth_enable( const polygon_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_smooth_enable(){return true;}

virtual bool begin__polygon_stipple_enable( const polygon_stipple_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_stipple_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__rescale_normal_enable( const profile_GLSL__technique__pass__states__rescale_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__rescale_normal_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable( const profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable( const profile_GLSL__technique__pass__states__sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__sample_alpha_to_one_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__sample_coverage_enable( const profile_GLSL__technique__pass__states__sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__sample_coverage_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__scissor_test_enable( const profile_GLSL__technique__pass__states__scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__scissor_test_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__states__stencil_test_enable( const profile_GLSL__technique__pass__states__stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__states__stencil_test_enable(){return true;}

virtual bool begin__program____glsl_program_type(){return true;}
virtual bool end__program____glsl_program_type(){return true;}

virtual bool begin__shader____glsl_shader_type( const shader____glsl_shader_type__AttributeData& attributeData ){return true;}
virtual bool end__shader____glsl_shader_type(){return true;}

virtual bool begin__sources____fx_sources_type(){return true;}
virtual bool end__sources____fx_sources_type(){return true;}

virtual bool begin__glsl_program_type____bind_attribute( const glsl_program_type____bind_attribute__AttributeData& attributeData ){return true;}
virtual bool end__glsl_program_type____bind_attribute(){return true;}

virtual bool begin__glsl_program_type____bind_uniform( const glsl_program_type____bind_uniform__AttributeData& attributeData ){return true;}
virtual bool end__glsl_program_type____bind_uniform(){return true;}

virtual bool begin__profile_GLSL__technique__pass__program__bind_uniform__param( const profile_GLSL__technique__pass__program__bind_uniform__param__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__program__bind_uniform__param(){return true;}

virtual bool begin__profile_GLSL__technique__pass__evaluate(){return true;}
virtual bool end__profile_GLSL__technique__pass__evaluate(){return true;}

virtual bool begin__profile_CG( const profile_CG__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG(){return true;}

virtual bool begin__newparam____cg_newparam_type( const newparam____cg_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____cg_newparam_type(){return true;}

virtual bool begin__bool2x1(){return true;}
virtual bool end__bool2x1(){return true;}
virtual bool data__bool2x1( const bool* value, size_t length ){return true;}

virtual bool begin__bool2x2(){return true;}
virtual bool end__bool2x2(){return true;}
virtual bool data__bool2x2( const bool* value, size_t length ){return true;}

virtual bool begin__bool2x3(){return true;}
virtual bool end__bool2x3(){return true;}
virtual bool data__bool2x3( const bool* value, size_t length ){return true;}

virtual bool begin__bool2x4(){return true;}
virtual bool end__bool2x4(){return true;}
virtual bool data__bool2x4( const bool* value, size_t length ){return true;}

virtual bool begin__bool3x1(){return true;}
virtual bool end__bool3x1(){return true;}
virtual bool data__bool3x1( const bool* value, size_t length ){return true;}

virtual bool begin__bool3x2(){return true;}
virtual bool end__bool3x2(){return true;}
virtual bool data__bool3x2( const bool* value, size_t length ){return true;}

virtual bool begin__bool3x3(){return true;}
virtual bool end__bool3x3(){return true;}
virtual bool data__bool3x3( const bool* value, size_t length ){return true;}

virtual bool begin__bool3x4(){return true;}
virtual bool end__bool3x4(){return true;}
virtual bool data__bool3x4( const bool* value, size_t length ){return true;}

virtual bool begin__bool4x1(){return true;}
virtual bool end__bool4x1(){return true;}
virtual bool data__bool4x1( const bool* value, size_t length ){return true;}

virtual bool begin__bool4x2(){return true;}
virtual bool end__bool4x2(){return true;}
virtual bool data__bool4x2( const bool* value, size_t length ){return true;}

virtual bool begin__bool4x3(){return true;}
virtual bool end__bool4x3(){return true;}
virtual bool data__bool4x3( const bool* value, size_t length ){return true;}

virtual bool begin__bool4x4(){return true;}
virtual bool end__bool4x4(){return true;}
virtual bool data__bool4x4( const bool* value, size_t length ){return true;}

virtual bool begin__int2x1(){return true;}
virtual bool end__int2x1(){return true;}
virtual bool data__int2x1( const sint64* value, size_t length ){return true;}

virtual bool begin__int2x2(){return true;}
virtual bool end__int2x2(){return true;}
virtual bool data__int2x2( const sint64* value, size_t length ){return true;}

virtual bool begin__int2x3(){return true;}
virtual bool end__int2x3(){return true;}
virtual bool data__int2x3( const sint64* value, size_t length ){return true;}

virtual bool begin__int2x4(){return true;}
virtual bool end__int2x4(){return true;}
virtual bool data__int2x4( const sint64* value, size_t length ){return true;}

virtual bool begin__int3x1(){return true;}
virtual bool end__int3x1(){return true;}
virtual bool data__int3x1( const sint64* value, size_t length ){return true;}

virtual bool begin__int3x2(){return true;}
virtual bool end__int3x2(){return true;}
virtual bool data__int3x2( const sint64* value, size_t length ){return true;}

virtual bool begin__int3x3(){return true;}
virtual bool end__int3x3(){return true;}
virtual bool data__int3x3( const sint64* value, size_t length ){return true;}

virtual bool begin__int3x4(){return true;}
virtual bool end__int3x4(){return true;}
virtual bool data__int3x4( const sint64* value, size_t length ){return true;}

virtual bool begin__int4x1(){return true;}
virtual bool end__int4x1(){return true;}
virtual bool data__int4x1( const sint64* value, size_t length ){return true;}

virtual bool begin__int4x2(){return true;}
virtual bool end__int4x2(){return true;}
virtual bool data__int4x2( const sint64* value, size_t length ){return true;}

virtual bool begin__int4x3(){return true;}
virtual bool end__int4x3(){return true;}
virtual bool data__int4x3( const sint64* value, size_t length ){return true;}

virtual bool begin__int4x4(){return true;}
virtual bool end__int4x4(){return true;}
virtual bool data__int4x4( const sint64* value, size_t length ){return true;}

virtual bool begin__half(){return true;}
virtual bool end__half(){return true;}
virtual bool data__half( float value ){return true;}

virtual bool begin__half2(){return true;}
virtual bool end__half2(){return true;}
virtual bool data__half2( const float* value, size_t length ){return true;}

virtual bool begin__half3(){return true;}
virtual bool end__half3(){return true;}
virtual bool data__half3( const float* value, size_t length ){return true;}

virtual bool begin__half4(){return true;}
virtual bool end__half4(){return true;}
virtual bool data__half4( const float* value, size_t length ){return true;}

virtual bool begin__half2x1(){return true;}
virtual bool end__half2x1(){return true;}
virtual bool data__half2x1( const float* value, size_t length ){return true;}

virtual bool begin__half2x2(){return true;}
virtual bool end__half2x2(){return true;}
virtual bool data__half2x2( const float* value, size_t length ){return true;}

virtual bool begin__half2x3(){return true;}
virtual bool end__half2x3(){return true;}
virtual bool data__half2x3( const float* value, size_t length ){return true;}

virtual bool begin__half2x4(){return true;}
virtual bool end__half2x4(){return true;}
virtual bool data__half2x4( const float* value, size_t length ){return true;}

virtual bool begin__half3x1(){return true;}
virtual bool end__half3x1(){return true;}
virtual bool data__half3x1( const float* value, size_t length ){return true;}

virtual bool begin__half3x2(){return true;}
virtual bool end__half3x2(){return true;}
virtual bool data__half3x2( const float* value, size_t length ){return true;}

virtual bool begin__half3x3(){return true;}
virtual bool end__half3x3(){return true;}
virtual bool data__half3x3( const float* value, size_t length ){return true;}

virtual bool begin__half3x4(){return true;}
virtual bool end__half3x4(){return true;}
virtual bool data__half3x4( const float* value, size_t length ){return true;}

virtual bool begin__half4x1(){return true;}
virtual bool end__half4x1(){return true;}
virtual bool data__half4x1( const float* value, size_t length ){return true;}

virtual bool begin__half4x2(){return true;}
virtual bool end__half4x2(){return true;}
virtual bool data__half4x2( const float* value, size_t length ){return true;}

virtual bool begin__half4x3(){return true;}
virtual bool end__half4x3(){return true;}
virtual bool data__half4x3( const float* value, size_t length ){return true;}

virtual bool begin__half4x4(){return true;}
virtual bool end__half4x4(){return true;}
virtual bool data__half4x4( const float* value, size_t length ){return true;}

virtual bool begin__fixed(){return true;}
virtual bool end__fixed(){return true;}
virtual bool data__fixed( float value ){return true;}

virtual bool begin__fixed2(){return true;}
virtual bool end__fixed2(){return true;}
virtual bool data__fixed2( const float* value, size_t length ){return true;}

virtual bool begin__fixed3(){return true;}
virtual bool end__fixed3(){return true;}
virtual bool data__fixed3( const float* value, size_t length ){return true;}

virtual bool begin__fixed4(){return true;}
virtual bool end__fixed4(){return true;}
virtual bool data__fixed4( const float* value, size_t length ){return true;}

virtual bool begin__fixed2x1(){return true;}
virtual bool end__fixed2x1(){return true;}
virtual bool data__fixed2x1( const float* value, size_t length ){return true;}

virtual bool begin__fixed2x2(){return true;}
virtual bool end__fixed2x2(){return true;}
virtual bool data__fixed2x2( const float* value, size_t length ){return true;}

virtual bool begin__fixed2x3(){return true;}
virtual bool end__fixed2x3(){return true;}
virtual bool data__fixed2x3( const float* value, size_t length ){return true;}

virtual bool begin__fixed2x4(){return true;}
virtual bool end__fixed2x4(){return true;}
virtual bool data__fixed2x4( const float* value, size_t length ){return true;}

virtual bool begin__fixed3x1(){return true;}
virtual bool end__fixed3x1(){return true;}
virtual bool data__fixed3x1( const float* value, size_t length ){return true;}

virtual bool begin__fixed3x2(){return true;}
virtual bool end__fixed3x2(){return true;}
virtual bool data__fixed3x2( const float* value, size_t length ){return true;}

virtual bool begin__fixed3x3(){return true;}
virtual bool end__fixed3x3(){return true;}
virtual bool data__fixed3x3( const float* value, size_t length ){return true;}

virtual bool begin__fixed3x4(){return true;}
virtual bool end__fixed3x4(){return true;}
virtual bool data__fixed3x4( const float* value, size_t length ){return true;}

virtual bool begin__fixed4x1(){return true;}
virtual bool end__fixed4x1(){return true;}
virtual bool data__fixed4x1( const float* value, size_t length ){return true;}

virtual bool begin__fixed4x2(){return true;}
virtual bool end__fixed4x2(){return true;}
virtual bool data__fixed4x2( const float* value, size_t length ){return true;}

virtual bool begin__fixed4x3(){return true;}
virtual bool end__fixed4x3(){return true;}
virtual bool data__fixed4x3( const float* value, size_t length ){return true;}

virtual bool begin__fixed4x4(){return true;}
virtual bool end__fixed4x4(){return true;}
virtual bool data__fixed4x4( const float* value, size_t length ){return true;}

virtual bool begin__array____cg_array_type( const array____cg_array_type__AttributeData& attributeData ){return true;}
virtual bool end__array____cg_array_type(){return true;}

virtual bool begin__usertype____cg_user_type( const usertype____cg_user_type__AttributeData& attributeData ){return true;}
virtual bool end__usertype____cg_user_type(){return true;}

virtual bool begin__setparam____cg_setparam_type( const setparam____cg_setparam_type__AttributeData& attributeData ){return true;}
virtual bool end__setparam____cg_setparam_type(){return true;}

virtual bool begin__profile_cg_type____technique( const profile_cg_type____technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_cg_type____technique(){return true;}

virtual bool begin__pass____cg_pass_type( const pass____cg_pass_type__AttributeData& attributeData ){return true;}
virtual bool end__pass____cg_pass_type(){return true;}

virtual bool begin__cg_pass_type____states(){return true;}
virtual bool end__cg_pass_type____states(){return true;}

virtual bool begin__cg_pass_type____program(){return true;}
virtual bool end__cg_pass_type____program(){return true;}

virtual bool begin__profile_CG__technique__pass__program__shader( const profile_CG__technique__pass__program__shader__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__program__shader(){return true;}

virtual bool begin__profile_CG__technique__pass__program__shader__sources( const profile_CG__technique__pass__program__shader__sources__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__program__shader__sources(){return true;}

virtual bool begin__profile_CG__technique__pass__program__shader__bind_uniform( const profile_CG__technique__pass__program__shader__bind_uniform__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__program__shader__bind_uniform(){return true;}

virtual bool begin__profile_CG__technique__pass__program__shader__bind_uniform__param( const profile_CG__technique__pass__program__shader__bind_uniform__param__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__program__shader__bind_uniform__param(){return true;}

virtual bool begin__cg_pass_type____evaluate(){return true;}
virtual bool end__cg_pass_type____evaluate(){return true;}

virtual bool begin__profile_GLES( const profile_GLES__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES(){return true;}

virtual bool begin__newparam____gles_newparam_type( const newparam____gles_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____gles_newparam_type(){return true;}

virtual bool begin__float1x1(){return true;}
virtual bool end__float1x1(){return true;}
virtual bool data__float1x1( float value ){return true;}

virtual bool begin__float1x2(){return true;}
virtual bool end__float1x2(){return true;}
virtual bool data__float1x2( const float* value, size_t length ){return true;}

virtual bool begin__float1x3(){return true;}
virtual bool end__float1x3(){return true;}
virtual bool data__float1x3( const float* value, size_t length ){return true;}

virtual bool begin__float1x4(){return true;}
virtual bool end__float1x4(){return true;}
virtual bool data__float1x4( const float* value, size_t length ){return true;}

virtual bool begin__sampler2D____gles_sampler_type(){return true;}
virtual bool end__sampler2D____gles_sampler_type(){return true;}

virtual bool begin__texcoord( const texcoord__AttributeData& attributeData ){return true;}
virtual bool end__texcoord(){return true;}

virtual bool begin__wrap_s____gles_sampler_wrap_enum(){return true;}
virtual bool end__wrap_s____gles_sampler_wrap_enum(){return true;}
virtual bool data__wrap_s____gles_sampler_wrap_enum( const ENUM__gles_sampler_wrap_enum value ){return true;}

virtual bool begin__wrap_t____gles_sampler_wrap_enum(){return true;}
virtual bool end__wrap_t____gles_sampler_wrap_enum(){return true;}
virtual bool data__wrap_t____gles_sampler_wrap_enum( const ENUM__gles_sampler_wrap_enum value ){return true;}

virtual bool begin__enum____gles_enumeration_type(){return true;}
virtual bool end__enum____gles_enumeration_type(){return true;}
virtual bool data__enum____gles_enumeration_type( UNION__gles_enumeration_type value ){return true;}

virtual bool begin__profile_gles_type____technique( const profile_gles_type____technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_gles_type____technique(){return true;}

virtual bool begin__profile_GLES__technique__pass( const profile_GLES__technique__pass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass(){return true;}

virtual bool begin__profile_GLES__technique__pass__states(){return true;}
virtual bool end__profile_GLES__technique__pass__states(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__alpha_func(){return true;}
virtual bool end__profile_GLES__technique__pass__states__alpha_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__alpha_func__func( const profile_GLES__technique__pass__states__alpha_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__alpha_func__func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__alpha_func__value( const profile_GLES__technique__pass__states__alpha_func__value__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__alpha_func__value(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__blend_func(){return true;}
virtual bool end__profile_GLES__technique__pass__states__blend_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__blend_func__src( const profile_GLES__technique__pass__states__blend_func__src__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__blend_func__src(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__blend_func__dest( const profile_GLES__technique__pass__states__blend_func__dest__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__blend_func__dest(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__clip_plane( const profile_GLES__technique__pass__states__clip_plane__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__clip_plane(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__color_mask( const profile_GLES__technique__pass__states__color_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__color_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__cull_face( const profile_GLES__technique__pass__states__cull_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__cull_face(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__depth_func( const profile_GLES__technique__pass__states__depth_func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__depth_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__depth_mask( const profile_GLES__technique__pass__states__depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__depth_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__depth_range( const profile_GLES__technique__pass__states__depth_range__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__depth_range(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_color( const profile_GLES__technique__pass__states__fog_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_color(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_density( const profile_GLES__technique__pass__states__fog_density__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_density(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_mode( const profile_GLES__technique__pass__states__fog_mode__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_mode(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_start( const profile_GLES__technique__pass__states__fog_start__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_start(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_end( const profile_GLES__technique__pass__states__fog_end__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_end(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__front_face( const profile_GLES__technique__pass__states__front_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__front_face(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__logic_op( const profile_GLES__technique__pass__states__logic_op__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__logic_op(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_ambient( const profile_GLES__technique__pass__states__light_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_diffuse( const profile_GLES__technique__pass__states__light_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_diffuse(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_specular( const profile_GLES__technique__pass__states__light_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_specular(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_position( const profile_GLES__technique__pass__states__light_position__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_position(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_constant_attenuation( const profile_GLES__technique__pass__states__light_constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_constant_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_linear_attenuation( const profile_GLES__technique__pass__states__light_linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_linear_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_quadratic_attenuation( const profile_GLES__technique__pass__states__light_quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_quadratic_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_spot_cutoff( const profile_GLES__technique__pass__states__light_spot_cutoff__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_spot_cutoff(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_spot_direction( const profile_GLES__technique__pass__states__light_spot_direction__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_spot_direction(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_spot_exponent( const profile_GLES__technique__pass__states__light_spot_exponent__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_spot_exponent(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_model_ambient( const profile_GLES__technique__pass__states__light_model_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_model_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__line_width( const profile_GLES__technique__pass__states__line_width__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__line_width(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__material_ambient( const profile_GLES__technique__pass__states__material_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__material_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__material_diffuse( const profile_GLES__technique__pass__states__material_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__material_diffuse(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__material_emission( const profile_GLES__technique__pass__states__material_emission__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__material_emission(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__material_shininess( const profile_GLES__technique__pass__states__material_shininess__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__material_shininess(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__material_specular( const profile_GLES__technique__pass__states__material_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__material_specular(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__model_view_matrix( const profile_GLES__technique__pass__states__model_view_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__model_view_matrix(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_distance_attenuation( const profile_GLES__technique__pass__states__point_distance_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_distance_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_fade_threshold_size( const profile_GLES__technique__pass__states__point_fade_threshold_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_fade_threshold_size(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_size( const profile_GLES__technique__pass__states__point_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_size(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_size_min( const profile_GLES__technique__pass__states__point_size_min__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_size_min(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_size_max( const profile_GLES__technique__pass__states__point_size_max__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_size_max(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__polygon_offset( const profile_GLES__technique__pass__states__polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__polygon_offset(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__projection_matrix( const profile_GLES__technique__pass__states__projection_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__projection_matrix(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__scissor( const profile_GLES__technique__pass__states__scissor__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__scissor(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__shade_model( const profile_GLES__technique__pass__states__shade_model__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__shade_model(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_func(){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_func__func( const profile_GLES__technique__pass__states__stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_func__func(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_func__ref( const profile_GLES__technique__pass__states__stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_func__ref(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_func__mask( const profile_GLES__technique__pass__states__stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_func__mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_mask( const profile_GLES__technique__pass__states__stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_op(){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_op(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_op__fail( const profile_GLES__technique__pass__states__stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_op__fail(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_op__zfail( const profile_GLES__technique__pass__states__stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_op__zfail(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_op__zpass( const profile_GLES__technique__pass__states__stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_op__zpass(){return true;}

virtual bool begin__texture_pipeline(){return true;}
virtual bool end__texture_pipeline(){return true;}

virtual bool begin__value____gles_texture_pipeline_type( const value____gles_texture_pipeline_type__AttributeData& attributeData ){return true;}
virtual bool end__value____gles_texture_pipeline_type(){return true;}

virtual bool begin__texcombiner(){return true;}
virtual bool end__texcombiner(){return true;}

virtual bool begin__constant____gles_texture_constant_type( const constant____gles_texture_constant_type__AttributeData& attributeData ){return true;}
virtual bool end__constant____gles_texture_constant_type(){return true;}

virtual bool begin__RGB( const RGB__AttributeData& attributeData ){return true;}
virtual bool end__RGB(){return true;}

virtual bool begin__argument____gles_texcombiner_argument_rgb_type( const argument____gles_texcombiner_argument_rgb_type__AttributeData& attributeData ){return true;}
virtual bool end__argument____gles_texcombiner_argument_rgb_type(){return true;}

virtual bool begin__alpha____gles_texcombiner_command_alpha_type( const alpha____gles_texcombiner_command_alpha_type__AttributeData& attributeData ){return true;}
virtual bool end__alpha____gles_texcombiner_command_alpha_type(){return true;}

virtual bool begin__argument____gles_texcombiner_argument_alpha_type( const argument____gles_texcombiner_argument_alpha_type__AttributeData& attributeData ){return true;}
virtual bool end__argument____gles_texcombiner_argument_alpha_type(){return true;}

virtual bool begin__texenv( const texenv__AttributeData& attributeData ){return true;}
virtual bool end__texenv(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__alpha_test_enable( const profile_GLES__technique__pass__states__alpha_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__alpha_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__blend_enable( const profile_GLES__technique__pass__states__blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__blend_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__clip_plane_enable( const profile_GLES__technique__pass__states__clip_plane_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__clip_plane_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__color_logic_op_enable( const profile_GLES__technique__pass__states__color_logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__color_logic_op_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__color_material_enable( const profile_GLES__technique__pass__states__color_material_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__color_material_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__cull_face_enable( const profile_GLES__technique__pass__states__cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__cull_face_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__depth_test_enable( const profile_GLES__technique__pass__states__depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__depth_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__dither_enable( const profile_GLES__technique__pass__states__dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__dither_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__fog_enable( const profile_GLES__technique__pass__states__fog_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__fog_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_enable( const profile_GLES__technique__pass__states__light_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__lighting_enable( const profile_GLES__technique__pass__states__lighting_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__lighting_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__light_model_two_side_enable( const profile_GLES__technique__pass__states__light_model_two_side_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__light_model_two_side_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__line_smooth_enable( const profile_GLES__technique__pass__states__line_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__line_smooth_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__multisample_enable( const profile_GLES__technique__pass__states__multisample_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__multisample_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__normalize_enable( const profile_GLES__technique__pass__states__normalize_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__normalize_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__point_smooth_enable( const profile_GLES__technique__pass__states__point_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__point_smooth_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__polygon_offset_fill_enable( const profile_GLES__technique__pass__states__polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__polygon_offset_fill_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__rescale_normal_enable( const profile_GLES__technique__pass__states__rescale_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__rescale_normal_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable( const profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__sample_alpha_to_one_enable( const profile_GLES__technique__pass__states__sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__sample_alpha_to_one_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__sample_coverage_enable( const profile_GLES__technique__pass__states__sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__sample_coverage_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__scissor_test_enable( const profile_GLES__technique__pass__states__scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__scissor_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__states__stencil_test_enable( const profile_GLES__technique__pass__states__stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__states__stencil_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__evaluate(){return true;}
virtual bool end__profile_GLES__technique__pass__evaluate(){return true;}

virtual bool begin__library_force_fields( const library_force_fields__AttributeData& attributeData ){return true;}
virtual bool end__library_force_fields(){return true;}

virtual bool begin__force_field( const force_field__AttributeData& attributeData ){return true;}
virtual bool end__force_field(){return true;}

virtual bool begin__library_images( const library_images__AttributeData& attributeData ){return true;}
virtual bool end__library_images(){return true;}

virtual bool begin__image____image_type( const image____image_type__AttributeData& attributeData ){return true;}
virtual bool end__image____image_type(){return true;}

virtual bool begin__renderable( const renderable__AttributeData& attributeData ){return true;}
virtual bool end__renderable(){return true;}

virtual bool begin__image_type____init_from( const image_type____init_from__AttributeData& attributeData ){return true;}
virtual bool end__image_type____init_from(){return true;}

virtual bool begin__library_images__image__init_from__hex( const library_images__image__init_from__hex__AttributeData& attributeData ){return true;}
virtual bool end__library_images__image__init_from__hex(){return true;}
virtual bool data__library_images__image__init_from__hex( const uint8* value, size_t length ){return true;}

virtual bool begin__create_2d(){return true;}
virtual bool end__create_2d(){return true;}

virtual bool begin__size_exact( const size_exact__AttributeData& attributeData ){return true;}
virtual bool end__size_exact(){return true;}

virtual bool begin__size_ratio( const size_ratio__AttributeData& attributeData ){return true;}
virtual bool end__size_ratio(){return true;}

virtual bool begin__mips( const mips__AttributeData& attributeData ){return true;}
virtual bool end__mips(){return true;}

virtual bool begin__unnormalized( const unnormalized__AttributeData& attributeData ){return true;}
virtual bool end__unnormalized(){return true;}
virtual bool data__unnormalized( const ParserChar* value, size_t length ){return true;}

virtual bool begin__create_2d__array( const create_2d__array__AttributeData& attributeData ){return true;}
virtual bool end__create_2d__array(){return true;}

virtual bool begin__create_2d__format(){return true;}
virtual bool end__create_2d__format(){return true;}

virtual bool begin__create_2d__format__hint( const create_2d__format__hint__AttributeData& attributeData ){return true;}
virtual bool end__create_2d__format__hint(){return true;}

virtual bool begin__exact(){return true;}
virtual bool end__exact(){return true;}
virtual bool data__exact( const ParserChar* value, size_t length ){return true;}

virtual bool begin__create_2d__init_from( const create_2d__init_from__AttributeData& attributeData ){return true;}
virtual bool end__create_2d__init_from(){return true;}

virtual bool begin__create_3d(){return true;}
virtual bool end__create_3d(){return true;}

virtual bool begin__create_3d__size( const create_3d__size__AttributeData& attributeData ){return true;}
virtual bool end__create_3d__size(){return true;}

virtual bool begin__create_3d__array( const create_3d__array__AttributeData& attributeData ){return true;}
virtual bool end__create_3d__array(){return true;}

virtual bool begin__create_3d__format(){return true;}
virtual bool end__create_3d__format(){return true;}

virtual bool begin__create_3d__format__hint( const create_3d__format__hint__AttributeData& attributeData ){return true;}
virtual bool end__create_3d__format__hint(){return true;}

virtual bool begin__create_3d__init_from( const create_3d__init_from__AttributeData& attributeData ){return true;}
virtual bool end__create_3d__init_from(){return true;}

virtual bool begin__create_cube(){return true;}
virtual bool end__create_cube(){return true;}

virtual bool begin__create_cube__size( const create_cube__size__AttributeData& attributeData ){return true;}
virtual bool end__create_cube__size(){return true;}

virtual bool begin__create_cube__array( const create_cube__array__AttributeData& attributeData ){return true;}
virtual bool end__create_cube__array(){return true;}

virtual bool begin__create_cube__format(){return true;}
virtual bool end__create_cube__format(){return true;}

virtual bool begin__create_cube__format__hint( const create_cube__format__hint__AttributeData& attributeData ){return true;}
virtual bool end__create_cube__format__hint(){return true;}

virtual bool begin__create_cube__init_from( const create_cube__init_from__AttributeData& attributeData ){return true;}
virtual bool end__create_cube__init_from(){return true;}

virtual bool begin__library_lights( const library_lights__AttributeData& attributeData ){return true;}
virtual bool end__library_lights(){return true;}

virtual bool begin__light( const light__AttributeData& attributeData ){return true;}
virtual bool end__light(){return true;}

virtual bool begin__light_type____technique_common(){return true;}
virtual bool end__light_type____technique_common(){return true;}

virtual bool begin__light__technique_common__ambient(){return true;}
virtual bool end__light__technique_common__ambient(){return true;}

virtual bool begin__color____targetable_float3_type( const color____targetable_float3_type__AttributeData& attributeData ){return true;}
virtual bool end__color____targetable_float3_type(){return true;}
virtual bool data__color____targetable_float3_type( const float* value, size_t length ){return true;}

virtual bool begin__directional(){return true;}
virtual bool end__directional(){return true;}

virtual bool begin__point(){return true;}
virtual bool end__point(){return true;}

virtual bool begin__constant_attenuation( const constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__constant_attenuation(){return true;}
virtual bool data__constant_attenuation( float value ){return true;}

virtual bool begin__linear_attenuation( const linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__linear_attenuation(){return true;}
virtual bool data__linear_attenuation( float value ){return true;}

virtual bool begin__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__quadratic_attenuation(){return true;}
virtual bool data__quadratic_attenuation( float value ){return true;}

virtual bool begin__spot(){return true;}
virtual bool end__spot(){return true;}

virtual bool begin__falloff_angle( const falloff_angle__AttributeData& attributeData ){return true;}
virtual bool end__falloff_angle(){return true;}
virtual bool data__falloff_angle( float value ){return true;}

virtual bool begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData ){return true;}
virtual bool end__falloff_exponent(){return true;}
virtual bool data__falloff_exponent( float value ){return true;}

virtual bool begin__library_materials( const library_materials__AttributeData& attributeData ){return true;}
virtual bool end__library_materials(){return true;}

virtual bool begin__material( const material__AttributeData& attributeData ){return true;}
virtual bool end__material(){return true;}

virtual bool begin__instance_effect( const instance_effect__AttributeData& attributeData ){return true;}
virtual bool end__instance_effect(){return true;}

virtual bool begin__technique_hint( const technique_hint__AttributeData& attributeData ){return true;}
virtual bool end__technique_hint(){return true;}

virtual bool begin__instance_effect_type____setparam( const instance_effect_type____setparam__AttributeData& attributeData ){return true;}
virtual bool end__instance_effect_type____setparam(){return true;}

virtual bool begin__sampler_image( const sampler_image__AttributeData& attributeData ){return true;}
virtual bool end__sampler_image(){return true;}

virtual bool begin__sampler_states(){return true;}
virtual bool end__sampler_states(){return true;}

virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData ){return true;}
virtual bool end__library_nodes(){return true;}

virtual bool begin__node( const node__AttributeData& attributeData ){return true;}
virtual bool end__node(){return true;}

virtual bool begin__lookat( const lookat__AttributeData& attributeData ){return true;}
virtual bool end__lookat(){return true;}
virtual bool data__lookat( const float* value, size_t length ){return true;}

virtual bool begin__matrix____matrix_type( const matrix____matrix_type__AttributeData& attributeData ){return true;}
virtual bool end__matrix____matrix_type(){return true;}
virtual bool data__matrix____matrix_type( const float* value, size_t length ){return true;}

virtual bool begin__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__rotate(){return true;}
virtual bool data__rotate( const float* value, size_t length ){return true;}

virtual bool begin__scale( const scale__AttributeData& attributeData ){return true;}
virtual bool end__scale(){return true;}
virtual bool data__scale( const float* value, size_t length ){return true;}

virtual bool begin__skew( const skew__AttributeData& attributeData ){return true;}
virtual bool end__skew(){return true;}
virtual bool data__skew( const float* value, size_t length ){return true;}

virtual bool begin__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__translate(){return true;}
virtual bool data__translate( const float* value, size_t length ){return true;}

virtual bool begin__instance_camera( const instance_camera__AttributeData& attributeData ){return true;}
virtual bool end__instance_camera(){return true;}

virtual bool begin__instance_controller( const instance_controller__AttributeData& attributeData ){return true;}
virtual bool end__instance_controller(){return true;}

virtual bool begin__skeleton(){return true;}
virtual bool end__skeleton(){return true;}
virtual bool data__skeleton( COLLADABU::URI value ){return true;}

virtual bool begin__bind_material(){return true;}
virtual bool end__bind_material(){return true;}

virtual bool begin__bind_material_type____technique_common(){return true;}
virtual bool end__bind_material_type____technique_common(){return true;}

virtual bool begin__instance_material____instance_material_type( const instance_material____instance_material_type__AttributeData& attributeData ){return true;}
virtual bool end__instance_material____instance_material_type(){return true;}

virtual bool begin__instance_material_type____bind( const instance_material_type____bind__AttributeData& attributeData ){return true;}
virtual bool end__instance_material_type____bind(){return true;}

virtual bool begin__bind_vertex_input( const bind_vertex_input__AttributeData& attributeData ){return true;}
virtual bool end__bind_vertex_input(){return true;}

virtual bool begin__instance_geometry( const instance_geometry__AttributeData& attributeData ){return true;}
virtual bool end__instance_geometry(){return true;}

virtual bool begin__instance_light( const instance_light__AttributeData& attributeData ){return true;}
virtual bool end__instance_light(){return true;}

virtual bool begin__instance_node( const instance_node__AttributeData& attributeData ){return true;}
virtual bool end__instance_node(){return true;}

virtual bool begin__library_physics_materials( const library_physics_materials__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_materials(){return true;}

virtual bool begin__physics_material( const physics_material__AttributeData& attributeData ){return true;}
virtual bool end__physics_material(){return true;}

virtual bool begin__physics_material_type____technique_common(){return true;}
virtual bool end__physics_material_type____technique_common(){return true;}

virtual bool begin__dynamic_friction( const dynamic_friction__AttributeData& attributeData ){return true;}
virtual bool end__dynamic_friction(){return true;}
virtual bool data__dynamic_friction( float value ){return true;}

virtual bool begin__restitution( const restitution__AttributeData& attributeData ){return true;}
virtual bool end__restitution(){return true;}
virtual bool data__restitution( float value ){return true;}

virtual bool begin__static_friction( const static_friction__AttributeData& attributeData ){return true;}
virtual bool end__static_friction(){return true;}
virtual bool data__static_friction( float value ){return true;}

virtual bool begin__library_physics_models( const library_physics_models__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_models(){return true;}

virtual bool begin__physics_model( const physics_model__AttributeData& attributeData ){return true;}
virtual bool end__physics_model(){return true;}

virtual bool begin__rigid_body( const rigid_body__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body(){return true;}

virtual bool begin__rigid_body_type____technique_common(){return true;}
virtual bool end__rigid_body_type____technique_common(){return true;}

virtual bool begin__rigid_body__technique_common__dynamic( const rigid_body__technique_common__dynamic__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body__technique_common__dynamic(){return true;}
virtual bool data__rigid_body__technique_common__dynamic( bool value ){return true;}

virtual bool begin__mass( const mass__AttributeData& attributeData ){return true;}
virtual bool end__mass(){return true;}
virtual bool data__mass( float value ){return true;}

virtual bool begin__rigid_body__technique_common__mass_frame(){return true;}
virtual bool end__rigid_body__technique_common__mass_frame(){return true;}

virtual bool begin__inertia( const inertia__AttributeData& attributeData ){return true;}
virtual bool end__inertia(){return true;}
virtual bool data__inertia( const float* value, size_t length ){return true;}

virtual bool begin__instance_physics_material( const instance_physics_material__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_material(){return true;}

virtual bool begin__rigid_body__technique_common__shape(){return true;}
virtual bool end__rigid_body__technique_common__shape(){return true;}

virtual bool begin__rigid_body__technique_common__shape__hollow( const rigid_body__technique_common__shape__hollow__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body__technique_common__shape__hollow(){return true;}
virtual bool data__rigid_body__technique_common__shape__hollow( bool value ){return true;}

virtual bool begin__density( const density__AttributeData& attributeData ){return true;}
virtual bool end__density(){return true;}
virtual bool data__density( float value ){return true;}

virtual bool begin__box(){return true;}
virtual bool end__box(){return true;}

virtual bool begin__half_extents(){return true;}
virtual bool end__half_extents(){return true;}
virtual bool data__half_extents( const float* value, size_t length ){return true;}

virtual bool begin__cylinder____cylinder_type(){return true;}
virtual bool end__cylinder____cylinder_type(){return true;}

virtual bool begin__height(){return true;}
virtual bool end__height(){return true;}
virtual bool data__height( float value ){return true;}

virtual bool begin__capsule(){return true;}
virtual bool end__capsule(){return true;}

virtual bool begin__radius____float3_type(){return true;}
virtual bool end__radius____float3_type(){return true;}
virtual bool data__radius____float3_type( const float* value, size_t length ){return true;}

virtual bool begin__rigid_constraint( const rigid_constraint__AttributeData& attributeData ){return true;}
virtual bool end__rigid_constraint(){return true;}

virtual bool begin__ref_attachment( const ref_attachment__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment(){return true;}

virtual bool begin__attachment( const attachment__AttributeData& attributeData ){return true;}
virtual bool end__attachment(){return true;}

virtual bool begin__rigid_constraint_type____technique_common(){return true;}
virtual bool end__rigid_constraint_type____technique_common(){return true;}

virtual bool begin__enabled( const enabled__AttributeData& attributeData ){return true;}
virtual bool end__enabled(){return true;}
virtual bool data__enabled( bool value ){return true;}

virtual bool begin__interpenetrate( const interpenetrate__AttributeData& attributeData ){return true;}
virtual bool end__interpenetrate(){return true;}
virtual bool data__interpenetrate( bool value ){return true;}

virtual bool begin__rigid_constraint__technique_common__limits(){return true;}
virtual bool end__rigid_constraint__technique_common__limits(){return true;}

virtual bool begin__swing_cone_and_twist(){return true;}
virtual bool end__swing_cone_and_twist(){return true;}

virtual bool begin__min____targetable_float3_type( const min____targetable_float3_type__AttributeData& attributeData ){return true;}
virtual bool end__min____targetable_float3_type(){return true;}
virtual bool data__min____targetable_float3_type( const float* value, size_t length ){return true;}

virtual bool begin__max____targetable_float3_type( const max____targetable_float3_type__AttributeData& attributeData ){return true;}
virtual bool end__max____targetable_float3_type(){return true;}
virtual bool data__max____targetable_float3_type( const float* value, size_t length ){return true;}

virtual bool begin__rigid_constraint__technique_common__limits__linear(){return true;}
virtual bool end__rigid_constraint__technique_common__limits__linear(){return true;}

virtual bool begin__spring(){return true;}
virtual bool end__spring(){return true;}

virtual bool begin__angular(){return true;}
virtual bool end__angular(){return true;}

virtual bool begin__stiffness( const stiffness__AttributeData& attributeData ){return true;}
virtual bool end__stiffness(){return true;}
virtual bool data__stiffness( float value ){return true;}

virtual bool begin__damping( const damping__AttributeData& attributeData ){return true;}
virtual bool end__damping(){return true;}
virtual bool data__damping( float value ){return true;}

virtual bool begin__target_value( const target_value__AttributeData& attributeData ){return true;}
virtual bool end__target_value(){return true;}
virtual bool data__target_value( float value ){return true;}

virtual bool begin__spring__linear(){return true;}
virtual bool end__spring__linear(){return true;}

virtual bool begin__instance_physics_model( const instance_physics_model__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_model(){return true;}

virtual bool begin__instance_force_field( const instance_force_field__AttributeData& attributeData ){return true;}
virtual bool end__instance_force_field(){return true;}

virtual bool begin__instance_rigid_body( const instance_rigid_body__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body(){return true;}

virtual bool begin__instance_rigid_body_type____technique_common(){return true;}
virtual bool end__instance_rigid_body_type____technique_common(){return true;}

virtual bool begin__angular_velocity(){return true;}
virtual bool end__angular_velocity(){return true;}
virtual bool data__angular_velocity( const float* value, size_t length ){return true;}

virtual bool begin__velocity(){return true;}
virtual bool end__velocity(){return true;}
virtual bool data__velocity( const float* value, size_t length ){return true;}

virtual bool begin__instance_rigid_body__technique_common__dynamic( const instance_rigid_body__technique_common__dynamic__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body__technique_common__dynamic(){return true;}
virtual bool data__instance_rigid_body__technique_common__dynamic( bool value ){return true;}

virtual bool begin__instance_rigid_body__technique_common__mass_frame(){return true;}
virtual bool end__instance_rigid_body__technique_common__mass_frame(){return true;}

virtual bool begin__instance_rigid_body__technique_common__shape(){return true;}
virtual bool end__instance_rigid_body__technique_common__shape(){return true;}

virtual bool begin__instance_rigid_body__technique_common__shape__hollow( const instance_rigid_body__technique_common__shape__hollow__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body__technique_common__shape__hollow(){return true;}
virtual bool data__instance_rigid_body__technique_common__shape__hollow( bool value ){return true;}

virtual bool begin__instance_rigid_constraint( const instance_rigid_constraint__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_constraint(){return true;}

virtual bool begin__library_physics_scenes( const library_physics_scenes__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_scenes(){return true;}

virtual bool begin__physics_scene( const physics_scene__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene(){return true;}

virtual bool begin__physics_scene_type____technique_common(){return true;}
virtual bool end__physics_scene_type____technique_common(){return true;}

virtual bool begin__gravity( const gravity__AttributeData& attributeData ){return true;}
virtual bool end__gravity(){return true;}
virtual bool data__gravity( const float* value, size_t length ){return true;}

virtual bool begin__time_step( const time_step__AttributeData& attributeData ){return true;}
virtual bool end__time_step(){return true;}
virtual bool data__time_step( float value ){return true;}

virtual bool begin__library_visual_scenes( const library_visual_scenes__AttributeData& attributeData ){return true;}
virtual bool end__library_visual_scenes(){return true;}

virtual bool begin__visual_scene( const visual_scene__AttributeData& attributeData ){return true;}
virtual bool end__visual_scene(){return true;}

virtual bool begin__evaluate_scene( const evaluate_scene__AttributeData& attributeData ){return true;}
virtual bool end__evaluate_scene(){return true;}

virtual bool begin__render( const render__AttributeData& attributeData ){return true;}
virtual bool end__render(){return true;}

virtual bool begin__layer(){return true;}
virtual bool end__layer(){return true;}
virtual bool data__layer( const ParserChar* value, size_t length ){return true;}

virtual bool begin__render__instance_material( const render__instance_material__AttributeData& attributeData ){return true;}
virtual bool end__render__instance_material(){return true;}

virtual bool begin__technique_override( const technique_override__AttributeData& attributeData ){return true;}
virtual bool end__technique_override(){return true;}

virtual bool begin__render__instance_material__bind( const render__instance_material__bind__AttributeData& attributeData ){return true;}
virtual bool end__render__instance_material__bind(){return true;}

virtual bool begin__library_joints( const library_joints__AttributeData& attributeData ){return true;}
virtual bool end__library_joints(){return true;}

virtual bool begin__joint( const joint__AttributeData& attributeData ){return true;}
virtual bool end__joint(){return true;}

virtual bool begin__prismatic( const prismatic__AttributeData& attributeData ){return true;}
virtual bool end__prismatic(){return true;}

virtual bool begin__axis____axis_type( const axis____axis_type__AttributeData& attributeData ){return true;}
virtual bool end__axis____axis_type(){return true;}
virtual bool data__axis____axis_type( const float* value, size_t length ){return true;}

virtual bool begin__limits____joint_limits_type(){return true;}
virtual bool end__limits____joint_limits_type(){return true;}

virtual bool begin__min____minmax_type( const min____minmax_type__AttributeData& attributeData ){return true;}
virtual bool end__min____minmax_type(){return true;}
virtual bool data__min____minmax_type( float value ){return true;}

virtual bool begin__max____minmax_type( const max____minmax_type__AttributeData& attributeData ){return true;}
virtual bool end__max____minmax_type(){return true;}
virtual bool data__max____minmax_type( float value ){return true;}

virtual bool begin__revolute( const revolute__AttributeData& attributeData ){return true;}
virtual bool end__revolute(){return true;}

virtual bool begin__library_kinematics_models( const library_kinematics_models__AttributeData& attributeData ){return true;}
virtual bool end__library_kinematics_models(){return true;}

virtual bool begin__kinematics_model( const kinematics_model__AttributeData& attributeData ){return true;}
virtual bool end__kinematics_model(){return true;}

virtual bool begin__technique_common____kinematics_model_technique_type(){return true;}
virtual bool end__technique_common____kinematics_model_technique_type(){return true;}

virtual bool begin__newparam____kinematics_newparam_type( const newparam____kinematics_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____kinematics_newparam_type(){return true;}

virtual bool begin__instance_joint( const instance_joint__AttributeData& attributeData ){return true;}
virtual bool end__instance_joint(){return true;}

virtual bool begin__link( const link__AttributeData& attributeData ){return true;}
virtual bool end__link(){return true;}

virtual bool begin__attachment_full( const attachment_full__AttributeData& attributeData ){return true;}
virtual bool end__attachment_full(){return true;}

virtual bool begin__attachment_start( const attachment_start__AttributeData& attributeData ){return true;}
virtual bool end__attachment_start(){return true;}

virtual bool begin__attachment_end( const attachment_end__AttributeData& attributeData ){return true;}
virtual bool end__attachment_end(){return true;}

virtual bool begin__formula( const formula__AttributeData& attributeData ){return true;}
virtual bool end__formula(){return true;}

virtual bool begin__newparam____formula_newparam_type( const newparam____formula_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____formula_newparam_type(){return true;}

virtual bool begin__target(){return true;}
virtual bool end__target(){return true;}

virtual bool begin__param____common_param_type(){return true;}
virtual bool end__param____common_param_type(){return true;}
virtual bool data__param____common_param_type( const ParserChar* value, size_t length ){return true;}

virtual bool begin__technique_common____formula_technique_type(){return true;}
virtual bool end__technique_common____formula_technique_type(){return true;}

virtual bool begin__math( const math__AttributeData& attributeData ){return true;}
virtual bool end__math(){return true;}

virtual bool begin__cn( const cn__AttributeData& attributeData ){return true;}
virtual bool end__cn(){return true;}
virtual bool data__cn( const ParserChar* value, size_t length ){return true;}

virtual bool begin__ci( const ci__AttributeData& attributeData ){return true;}
virtual bool end__ci(){return true;}
virtual bool data__ci( const ParserChar* value, size_t length ){return true;}

virtual bool begin__csymbol( const csymbol__AttributeData& attributeData ){return true;}
virtual bool end__csymbol(){return true;}
virtual bool data__csymbol( const ParserChar* value, size_t length ){return true;}

virtual bool begin__abs( const abs__AttributeData& attributeData ){return true;}
virtual bool end__abs(){return true;}

virtual bool begin__conjugate( const conjugate__AttributeData& attributeData ){return true;}
virtual bool end__conjugate(){return true;}

virtual bool begin__factorial( const factorial__AttributeData& attributeData ){return true;}
virtual bool end__factorial(){return true;}

virtual bool begin__arg( const arg__AttributeData& attributeData ){return true;}
virtual bool end__arg(){return true;}

virtual bool begin__real( const real__AttributeData& attributeData ){return true;}
virtual bool end__real(){return true;}

virtual bool begin__imaginary( const imaginary__AttributeData& attributeData ){return true;}
virtual bool end__imaginary(){return true;}

virtual bool begin__floor( const floor__AttributeData& attributeData ){return true;}
virtual bool end__floor(){return true;}

virtual bool begin__ceiling( const ceiling__AttributeData& attributeData ){return true;}
virtual bool end__ceiling(){return true;}

virtual bool begin__quotient( const quotient__AttributeData& attributeData ){return true;}
virtual bool end__quotient(){return true;}

virtual bool begin__divide( const divide__AttributeData& attributeData ){return true;}
virtual bool end__divide(){return true;}

virtual bool begin__rem( const rem__AttributeData& attributeData ){return true;}
virtual bool end__rem(){return true;}

virtual bool begin__minus( const minus__AttributeData& attributeData ){return true;}
virtual bool end__minus(){return true;}

virtual bool begin__plus( const plus__AttributeData& attributeData ){return true;}
virtual bool end__plus(){return true;}

virtual bool begin__times( const times__AttributeData& attributeData ){return true;}
virtual bool end__times(){return true;}

virtual bool begin__power( const power__AttributeData& attributeData ){return true;}
virtual bool end__power(){return true;}

virtual bool begin__root( const root__AttributeData& attributeData ){return true;}
virtual bool end__root(){return true;}

virtual bool begin__max____Arith_type( const max____Arith_type__AttributeData& attributeData ){return true;}
virtual bool end__max____Arith_type(){return true;}

virtual bool begin__min____Arith_type( const min____Arith_type__AttributeData& attributeData ){return true;}
virtual bool end__min____Arith_type(){return true;}

virtual bool begin__gcd( const gcd__AttributeData& attributeData ){return true;}
virtual bool end__gcd(){return true;}

virtual bool begin__lcm( const lcm__AttributeData& attributeData ){return true;}
virtual bool end__lcm(){return true;}

virtual bool begin__sum( const sum__AttributeData& attributeData ){return true;}
virtual bool end__sum(){return true;}

virtual bool begin__product( const product__AttributeData& attributeData ){return true;}
virtual bool end__product(){return true;}

virtual bool begin__compose( const compose__AttributeData& attributeData ){return true;}
virtual bool end__compose(){return true;}

virtual bool begin__domain( const domain__AttributeData& attributeData ){return true;}
virtual bool end__domain(){return true;}

virtual bool begin__codomain( const codomain__AttributeData& attributeData ){return true;}
virtual bool end__codomain(){return true;}

virtual bool begin__image____Functions_type( const image____Functions_type__AttributeData& attributeData ){return true;}
virtual bool end__image____Functions_type(){return true;}

virtual bool begin__domainofapplication( const domainofapplication__AttributeData& attributeData ){return true;}
virtual bool end__domainofapplication(){return true;}

virtual bool begin__ident( const ident__AttributeData& attributeData ){return true;}
virtual bool end__ident(){return true;}

virtual bool begin__and( const and__AttributeData& attributeData ){return true;}
virtual bool end__and(){return true;}

virtual bool begin__or( const or__AttributeData& attributeData ){return true;}
virtual bool end__or(){return true;}

virtual bool begin__xor( const xor__AttributeData& attributeData ){return true;}
virtual bool end__xor(){return true;}

virtual bool begin__not( const not__AttributeData& attributeData ){return true;}
virtual bool end__not(){return true;}

virtual bool begin__exists( const exists__AttributeData& attributeData ){return true;}
virtual bool end__exists(){return true;}

virtual bool begin__forall( const forall__AttributeData& attributeData ){return true;}
virtual bool end__forall(){return true;}

virtual bool begin__implies( const implies__AttributeData& attributeData ){return true;}
virtual bool end__implies(){return true;}

virtual bool begin__naturalnumbers( const naturalnumbers__AttributeData& attributeData ){return true;}
virtual bool end__naturalnumbers(){return true;}

virtual bool begin__primes( const primes__AttributeData& attributeData ){return true;}
virtual bool end__primes(){return true;}

virtual bool begin__integers( const integers__AttributeData& attributeData ){return true;}
virtual bool end__integers(){return true;}

virtual bool begin__rationals( const rationals__AttributeData& attributeData ){return true;}
virtual bool end__rationals(){return true;}

virtual bool begin__reals( const reals__AttributeData& attributeData ){return true;}
virtual bool end__reals(){return true;}

virtual bool begin__complexes( const complexes__AttributeData& attributeData ){return true;}
virtual bool end__complexes(){return true;}

virtual bool begin__emptyset( const emptyset__AttributeData& attributeData ){return true;}
virtual bool end__emptyset(){return true;}

virtual bool begin__exponentiale( const exponentiale__AttributeData& attributeData ){return true;}
virtual bool end__exponentiale(){return true;}

virtual bool begin__imaginaryi( const imaginaryi__AttributeData& attributeData ){return true;}
virtual bool end__imaginaryi(){return true;}

virtual bool begin__pi( const pi__AttributeData& attributeData ){return true;}
virtual bool end__pi(){return true;}

virtual bool begin__eulergamma( const eulergamma__AttributeData& attributeData ){return true;}
virtual bool end__eulergamma(){return true;}

virtual bool begin__true( const true__AttributeData& attributeData ){return true;}
virtual bool end__true(){return true;}

virtual bool begin__false( const false__AttributeData& attributeData ){return true;}
virtual bool end__false(){return true;}

virtual bool begin__infinity( const infinity__AttributeData& attributeData ){return true;}
virtual bool end__infinity(){return true;}

virtual bool begin__notanumber( const notanumber__AttributeData& attributeData ){return true;}
virtual bool end__notanumber(){return true;}

virtual bool begin__set( const set__AttributeData& attributeData ){return true;}
virtual bool end__set(){return true;}

virtual bool begin__list( const list__AttributeData& attributeData ){return true;}
virtual bool end__list(){return true;}

virtual bool begin__union( const union__AttributeData& attributeData ){return true;}
virtual bool end__union(){return true;}

virtual bool begin__intersect( const intersect__AttributeData& attributeData ){return true;}
virtual bool end__intersect(){return true;}

virtual bool begin__in( const in__AttributeData& attributeData ){return true;}
virtual bool end__in(){return true;}

virtual bool begin__notin( const notin__AttributeData& attributeData ){return true;}
virtual bool end__notin(){return true;}

virtual bool begin__subset( const subset__AttributeData& attributeData ){return true;}
virtual bool end__subset(){return true;}

virtual bool begin__prsubset( const prsubset__AttributeData& attributeData ){return true;}
virtual bool end__prsubset(){return true;}

virtual bool begin__notsubset( const notsubset__AttributeData& attributeData ){return true;}
virtual bool end__notsubset(){return true;}

virtual bool begin__notprsubset( const notprsubset__AttributeData& attributeData ){return true;}
virtual bool end__notprsubset(){return true;}

virtual bool begin__setdiff( const setdiff__AttributeData& attributeData ){return true;}
virtual bool end__setdiff(){return true;}

virtual bool begin__card( const card__AttributeData& attributeData ){return true;}
virtual bool end__card(){return true;}

virtual bool begin__cartesianproduct( const cartesianproduct__AttributeData& attributeData ){return true;}
virtual bool end__cartesianproduct(){return true;}

virtual bool begin__eq( const eq__AttributeData& attributeData ){return true;}
virtual bool end__eq(){return true;}

virtual bool begin__neq( const neq__AttributeData& attributeData ){return true;}
virtual bool end__neq(){return true;}

virtual bool begin__leq( const leq__AttributeData& attributeData ){return true;}
virtual bool end__leq(){return true;}

virtual bool begin__lt( const lt__AttributeData& attributeData ){return true;}
virtual bool end__lt(){return true;}

virtual bool begin__geq( const geq__AttributeData& attributeData ){return true;}
virtual bool end__geq(){return true;}

virtual bool begin__gt( const gt__AttributeData& attributeData ){return true;}
virtual bool end__gt(){return true;}

virtual bool begin__equivalent( const equivalent__AttributeData& attributeData ){return true;}
virtual bool end__equivalent(){return true;}

virtual bool begin__approx( const approx__AttributeData& attributeData ){return true;}
virtual bool end__approx(){return true;}

virtual bool begin__factorof( const factorof__AttributeData& attributeData ){return true;}
virtual bool end__factorof(){return true;}

virtual bool begin__exp( const exp__AttributeData& attributeData ){return true;}
virtual bool end__exp(){return true;}

virtual bool begin__ln( const ln__AttributeData& attributeData ){return true;}
virtual bool end__ln(){return true;}

virtual bool begin__log( const log__AttributeData& attributeData ){return true;}
virtual bool end__log(){return true;}

virtual bool begin__logbase( const logbase__AttributeData& attributeData ){return true;}
virtual bool end__logbase(){return true;}

virtual bool begin__sin( const sin__AttributeData& attributeData ){return true;}
virtual bool end__sin(){return true;}

virtual bool begin__cos( const cos__AttributeData& attributeData ){return true;}
virtual bool end__cos(){return true;}

virtual bool begin__tan( const tan__AttributeData& attributeData ){return true;}
virtual bool end__tan(){return true;}

virtual bool begin__sec( const sec__AttributeData& attributeData ){return true;}
virtual bool end__sec(){return true;}

virtual bool begin__csc( const csc__AttributeData& attributeData ){return true;}
virtual bool end__csc(){return true;}

virtual bool begin__cot( const cot__AttributeData& attributeData ){return true;}
virtual bool end__cot(){return true;}

virtual bool begin__arcsin( const arcsin__AttributeData& attributeData ){return true;}
virtual bool end__arcsin(){return true;}

virtual bool begin__arccos( const arccos__AttributeData& attributeData ){return true;}
virtual bool end__arccos(){return true;}

virtual bool begin__arctan( const arctan__AttributeData& attributeData ){return true;}
virtual bool end__arctan(){return true;}

virtual bool begin__arcsec( const arcsec__AttributeData& attributeData ){return true;}
virtual bool end__arcsec(){return true;}

virtual bool begin__arccsc( const arccsc__AttributeData& attributeData ){return true;}
virtual bool end__arccsc(){return true;}

virtual bool begin__arccot( const arccot__AttributeData& attributeData ){return true;}
virtual bool end__arccot(){return true;}

virtual bool begin__sinh( const sinh__AttributeData& attributeData ){return true;}
virtual bool end__sinh(){return true;}

virtual bool begin__cosh( const cosh__AttributeData& attributeData ){return true;}
virtual bool end__cosh(){return true;}

virtual bool begin__tanh( const tanh__AttributeData& attributeData ){return true;}
virtual bool end__tanh(){return true;}

virtual bool begin__sech( const sech__AttributeData& attributeData ){return true;}
virtual bool end__sech(){return true;}

virtual bool begin__csch( const csch__AttributeData& attributeData ){return true;}
virtual bool end__csch(){return true;}

virtual bool begin__coth( const coth__AttributeData& attributeData ){return true;}
virtual bool end__coth(){return true;}

virtual bool begin__arccosh( const arccosh__AttributeData& attributeData ){return true;}
virtual bool end__arccosh(){return true;}

virtual bool begin__arccoth( const arccoth__AttributeData& attributeData ){return true;}
virtual bool end__arccoth(){return true;}

virtual bool begin__arccsch( const arccsch__AttributeData& attributeData ){return true;}
virtual bool end__arccsch(){return true;}

virtual bool begin__arcsech( const arcsech__AttributeData& attributeData ){return true;}
virtual bool end__arcsech(){return true;}

virtual bool begin__arcsinh( const arcsinh__AttributeData& attributeData ){return true;}
virtual bool end__arcsinh(){return true;}

virtual bool begin__arctanh( const arctanh__AttributeData& attributeData ){return true;}
virtual bool end__arctanh(){return true;}

virtual bool begin__int____int_type____mathml( const int____int_type____mathml__AttributeData& attributeData ){return true;}
virtual bool end__int____int_type____mathml(){return true;}

virtual bool begin__diff( const diff__AttributeData& attributeData ){return true;}
virtual bool end__diff(){return true;}

virtual bool begin__partialdiff( const partialdiff__AttributeData& attributeData ){return true;}
virtual bool end__partialdiff(){return true;}

virtual bool begin__limit( const limit__AttributeData& attributeData ){return true;}
virtual bool end__limit(){return true;}

virtual bool begin__lowlimit( const lowlimit__AttributeData& attributeData ){return true;}
virtual bool end__lowlimit(){return true;}

virtual bool begin__uplimit( const uplimit__AttributeData& attributeData ){return true;}
virtual bool end__uplimit(){return true;}

virtual bool begin__tendsto( const tendsto__AttributeData& attributeData ){return true;}
virtual bool end__tendsto(){return true;}

virtual bool begin__vector( const vector__AttributeData& attributeData ){return true;}
virtual bool end__vector(){return true;}

virtual bool begin__matrix____matrix_type____mathml( const matrix____matrix_type____mathml__AttributeData& attributeData ){return true;}
virtual bool end__matrix____matrix_type____mathml(){return true;}

virtual bool begin__matrixrow( const matrixrow__AttributeData& attributeData ){return true;}
virtual bool end__matrixrow(){return true;}

virtual bool begin__determinant( const determinant__AttributeData& attributeData ){return true;}
virtual bool end__determinant(){return true;}

virtual bool begin__transpose( const transpose__AttributeData& attributeData ){return true;}
virtual bool end__transpose(){return true;}

virtual bool begin__selector( const selector__AttributeData& attributeData ){return true;}
virtual bool end__selector(){return true;}

virtual bool begin__vectorproduct( const vectorproduct__AttributeData& attributeData ){return true;}
virtual bool end__vectorproduct(){return true;}

virtual bool begin__scalarproduct( const scalarproduct__AttributeData& attributeData ){return true;}
virtual bool end__scalarproduct(){return true;}

virtual bool begin__outerproduct( const outerproduct__AttributeData& attributeData ){return true;}
virtual bool end__outerproduct(){return true;}

virtual bool begin__divergence( const divergence__AttributeData& attributeData ){return true;}
virtual bool end__divergence(){return true;}

virtual bool begin__grad( const grad__AttributeData& attributeData ){return true;}
virtual bool end__grad(){return true;}

virtual bool begin__curl( const curl__AttributeData& attributeData ){return true;}
virtual bool end__curl(){return true;}

virtual bool begin__laplacian( const laplacian__AttributeData& attributeData ){return true;}
virtual bool end__laplacian(){return true;}

virtual bool begin__mean( const mean__AttributeData& attributeData ){return true;}
virtual bool end__mean(){return true;}

virtual bool begin__sdev( const sdev__AttributeData& attributeData ){return true;}
virtual bool end__sdev(){return true;}

virtual bool begin__variance( const variance__AttributeData& attributeData ){return true;}
virtual bool end__variance(){return true;}

virtual bool begin__median( const median__AttributeData& attributeData ){return true;}
virtual bool end__median(){return true;}

virtual bool begin__mode____mode_type( const mode____mode_type__AttributeData& attributeData ){return true;}
virtual bool end__mode____mode_type(){return true;}

virtual bool begin__moment( const moment__AttributeData& attributeData ){return true;}
virtual bool end__moment(){return true;}

virtual bool begin__momentabout( const momentabout__AttributeData& attributeData ){return true;}
virtual bool end__momentabout(){return true;}

virtual bool begin__apply( const apply__AttributeData& attributeData ){return true;}
virtual bool end__apply(){return true;}

virtual bool begin__interval( const interval__AttributeData& attributeData ){return true;}
virtual bool end__interval(){return true;}

virtual bool begin__inverse( const inverse__AttributeData& attributeData ){return true;}
virtual bool end__inverse(){return true;}

virtual bool begin__condition( const condition__AttributeData& attributeData ){return true;}
virtual bool end__condition(){return true;}

virtual bool begin__declare( const declare__AttributeData& attributeData ){return true;}
virtual bool end__declare(){return true;}

virtual bool begin__lambda( const lambda__AttributeData& attributeData ){return true;}
virtual bool end__lambda(){return true;}

virtual bool begin__piecewise( const piecewise__AttributeData& attributeData ){return true;}
virtual bool end__piecewise(){return true;}

virtual bool begin__piece(){return true;}
virtual bool end__piece(){return true;}

virtual bool begin__bvar( const bvar__AttributeData& attributeData ){return true;}
virtual bool end__bvar(){return true;}

virtual bool begin__degree( const degree__AttributeData& attributeData ){return true;}
virtual bool end__degree(){return true;}

virtual bool begin__semantics( const semantics__AttributeData& attributeData ){return true;}
virtual bool end__semantics(){return true;}

virtual bool begin__annotation( const annotation__AttributeData& attributeData ){return true;}
virtual bool end__annotation(){return true;}
virtual bool data__annotation( const ParserChar* value, size_t length ){return true;}

virtual bool begin__annotation_xml( const annotation_xml__AttributeData& attributeData ){return true;}
virtual bool end__annotation_xml(){return true;}

virtual bool begin__otherwise( const otherwise__AttributeData& attributeData ){return true;}
virtual bool end__otherwise(){return true;}

virtual bool begin__sep(){return true;}
virtual bool end__sep(){return true;}

virtual bool begin__library_articulated_systems( const library_articulated_systems__AttributeData& attributeData ){return true;}
virtual bool end__library_articulated_systems(){return true;}

virtual bool begin__articulated_system( const articulated_system__AttributeData& attributeData ){return true;}
virtual bool end__articulated_system(){return true;}

virtual bool begin__kinematics(){return true;}
virtual bool end__kinematics(){return true;}

virtual bool begin__instance_kinematics_model( const instance_kinematics_model__AttributeData& attributeData ){return true;}
virtual bool end__instance_kinematics_model(){return true;}

virtual bool begin__bind____kinematics_bind_type( const bind____kinematics_bind_type__AttributeData& attributeData ){return true;}
virtual bool end__bind____kinematics_bind_type(){return true;}

virtual bool begin__param____kinematics_param_type( const param____kinematics_param_type__AttributeData& attributeData ){return true;}
virtual bool end__param____kinematics_param_type(){return true;}

virtual bool begin__setparam____kinematics_setparam_type( const setparam____kinematics_setparam_type__AttributeData& attributeData ){return true;}
virtual bool end__setparam____kinematics_setparam_type(){return true;}

virtual bool begin__technique_common____kinematics_technique_type(){return true;}
virtual bool end__technique_common____kinematics_technique_type(){return true;}

virtual bool begin__axis_info____kinematics_axis_info_type( const axis_info____kinematics_axis_info_type__AttributeData& attributeData ){return true;}
virtual bool end__axis_info____kinematics_axis_info_type(){return true;}

virtual bool begin__active(){return true;}
virtual bool end__active(){return true;}

virtual bool begin__locked(){return true;}
virtual bool end__locked(){return true;}

virtual bool begin__index( const index__AttributeData& attributeData ){return true;}
virtual bool end__index(){return true;}

virtual bool begin__limits____kinematics_limits_type(){return true;}
virtual bool end__limits____kinematics_limits_type(){return true;}

virtual bool begin__min____common_float_or_param_type(){return true;}
virtual bool end__min____common_float_or_param_type(){return true;}

virtual bool begin__max____common_float_or_param_type(){return true;}
virtual bool end__max____common_float_or_param_type(){return true;}

virtual bool begin__frame_origin( const frame_origin__AttributeData& attributeData ){return true;}
virtual bool end__frame_origin(){return true;}

virtual bool begin__frame_tip( const frame_tip__AttributeData& attributeData ){return true;}
virtual bool end__frame_tip(){return true;}

virtual bool begin__frame_tcp( const frame_tcp__AttributeData& attributeData ){return true;}
virtual bool end__frame_tcp(){return true;}

virtual bool begin__frame_object( const frame_object__AttributeData& attributeData ){return true;}
virtual bool end__frame_object(){return true;}

virtual bool begin__motion(){return true;}
virtual bool end__motion(){return true;}

virtual bool begin__instance_articulated_system( const instance_articulated_system__AttributeData& attributeData ){return true;}
virtual bool end__instance_articulated_system(){return true;}

virtual bool begin__technique_common____motion_technique_type(){return true;}
virtual bool end__technique_common____motion_technique_type(){return true;}

virtual bool begin__axis_info____motion_axis_info_type( const axis_info____motion_axis_info_type__AttributeData& attributeData ){return true;}
virtual bool end__axis_info____motion_axis_info_type(){return true;}

virtual bool begin__speed____common_float_or_param_type(){return true;}
virtual bool end__speed____common_float_or_param_type(){return true;}

virtual bool begin__acceleration____common_float_or_param_type(){return true;}
virtual bool end__acceleration____common_float_or_param_type(){return true;}

virtual bool begin__deceleration____common_float_or_param_type(){return true;}
virtual bool end__deceleration____common_float_or_param_type(){return true;}

virtual bool begin__jerk____common_float_or_param_type(){return true;}
virtual bool end__jerk____common_float_or_param_type(){return true;}

virtual bool begin__effector_info( const effector_info__AttributeData& attributeData ){return true;}
virtual bool end__effector_info(){return true;}

virtual bool begin__speed____common_float2_or_param_type(){return true;}
virtual bool end__speed____common_float2_or_param_type(){return true;}

virtual bool begin__acceleration____common_float2_or_param_type(){return true;}
virtual bool end__acceleration____common_float2_or_param_type(){return true;}

virtual bool begin__deceleration____common_float2_or_param_type(){return true;}
virtual bool end__deceleration____common_float2_or_param_type(){return true;}

virtual bool begin__jerk____common_float2_or_param_type(){return true;}
virtual bool end__jerk____common_float2_or_param_type(){return true;}

virtual bool begin__library_kinematics_scenes( const library_kinematics_scenes__AttributeData& attributeData ){return true;}
virtual bool end__library_kinematics_scenes(){return true;}

virtual bool begin__kinematics_scene( const kinematics_scene__AttributeData& attributeData ){return true;}
virtual bool end__kinematics_scene(){return true;}

virtual bool begin__library_formulas( const library_formulas__AttributeData& attributeData ){return true;}
virtual bool end__library_formulas(){return true;}

virtual bool begin__scene(){return true;}
virtual bool end__scene(){return true;}

virtual bool begin__instance_physics_scene( const instance_physics_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_scene(){return true;}

virtual bool begin__instance_visual_scene( const instance_visual_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_visual_scene(){return true;}

virtual bool begin__instance_kinematics_scene( const instance_kinematics_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_kinematics_scene(){return true;}

virtual bool begin__bind_kinematics_model( const bind_kinematics_model__AttributeData& attributeData ){return true;}
virtual bool end__bind_kinematics_model(){return true;}

virtual bool begin__bind_joint_axis( const bind_joint_axis__AttributeData& attributeData ){return true;}
virtual bool end__bind_joint_axis(){return true;}

virtual bool begin__axis____common_sidref_or_param_type(){return true;}
virtual bool end__axis____common_sidref_or_param_type(){return true;}

virtual bool begin__value____common_float_or_param_type(){return true;}
virtual bool end__value____common_float_or_param_type(){return true;}



private:
/** Disable default copy ctor. */
ColladaParserAutoGen15( const ColladaParserAutoGen15& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen15& operator= ( const ColladaParserAutoGen15& pre );

};

} // namespace
#endif
