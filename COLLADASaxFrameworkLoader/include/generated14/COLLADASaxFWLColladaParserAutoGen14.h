/*
    Copyright (c) 2008-2013 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14_H__
#define __COLLADASAXFWL14_COLLADAPARSERAUTOGEN14_H__


#include "COLLADASaxFWLColladaParserAutoGen14Attributes.h"


namespace COLLADASaxFWL14
{


class ColladaParserAutoGen14
{
public:
ColladaParserAutoGen14(){}
virtual ~ColladaParserAutoGen14(){}


virtual bool begin__COLLADA( const COLLADA__AttributeData& attributeData ){return true;}
virtual bool end__COLLADA(){return true;}

virtual bool begin__asset(){return true;}
virtual bool end__asset(){return true;}

virtual bool begin__contributor(){return true;}
virtual bool end__contributor(){return true;}

virtual bool begin__author(){return true;}
virtual bool end__author(){return true;}
virtual bool data__author( const ParserChar* value, size_t length ){return true;}

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
virtual bool data__up_axis( const ENUM__UpAxisType value ){return true;}

virtual bool begin__library_animations( const library_animations__AttributeData& attributeData ){return true;}
virtual bool end__library_animations(){return true;}

virtual bool begin__animation( const animation__AttributeData& attributeData ){return true;}
virtual bool end__animation(){return true;}

virtual bool begin__source( const source__AttributeData& attributeData ){return true;}
virtual bool end__source(){return true;}

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

virtual bool begin__animation__source__technique_common(){return true;}
virtual bool end__animation__source__technique_common(){return true;}

virtual bool begin__accessor( const accessor__AttributeData& attributeData ){return true;}
virtual bool end__accessor(){return true;}

virtual bool begin__param( const param__AttributeData& attributeData ){return true;}
virtual bool end__param(){return true;}
virtual bool data__param( const ParserChar* value, size_t length ){return true;}

virtual bool begin__technique( const technique__AttributeData& attributeData ){return true;}
virtual bool end__technique(){return true;}

virtual bool begin__sampler( const sampler__AttributeData& attributeData ){return true;}
virtual bool end__sampler(){return true;}

virtual bool begin__input____InputLocal( const input____InputLocal__AttributeData& attributeData ){return true;}
virtual bool end__input____InputLocal(){return true;}

virtual bool begin__channel( const channel__AttributeData& attributeData ){return true;}
virtual bool end__channel(){return true;}

virtual bool begin__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__extra(){return true;}

virtual bool begin__library_animation_clips( const library_animation_clips__AttributeData& attributeData ){return true;}
virtual bool end__library_animation_clips(){return true;}

virtual bool begin__animation_clip( const animation_clip__AttributeData& attributeData ){return true;}
virtual bool end__animation_clip(){return true;}

virtual bool begin__instance_animation( const instance_animation__AttributeData& attributeData ){return true;}
virtual bool end__instance_animation(){return true;}

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

virtual bool begin__input____InputLocalOffset( const input____InputLocalOffset__AttributeData& attributeData ){return true;}
virtual bool end__input____InputLocalOffset(){return true;}

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

virtual bool begin__control_vertices(){return true;}
virtual bool end__control_vertices(){return true;}

virtual bool begin__library_effects( const library_effects__AttributeData& attributeData ){return true;}
virtual bool end__library_effects(){return true;}

virtual bool begin__effect( const effect__AttributeData& attributeData ){return true;}
virtual bool end__effect(){return true;}

virtual bool begin__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__annotate(){return true;}

virtual bool begin__bool____bool(){return true;}
virtual bool end__bool____bool(){return true;}
virtual bool data__bool____bool( bool value ){return true;}

virtual bool begin__bool2____bool2(){return true;}
virtual bool end__bool2____bool2(){return true;}
virtual bool data__bool2____bool2( const bool* value, size_t length ){return true;}

virtual bool begin__bool3____bool3(){return true;}
virtual bool end__bool3____bool3(){return true;}
virtual bool data__bool3____bool3( const bool* value, size_t length ){return true;}

virtual bool begin__bool4____bool4(){return true;}
virtual bool end__bool4____bool4(){return true;}
virtual bool data__bool4____bool4( const bool* value, size_t length ){return true;}

virtual bool begin__int____int(){return true;}
virtual bool end__int____int(){return true;}
virtual bool data__int____int( sint64 value ){return true;}

virtual bool begin__int2____int2(){return true;}
virtual bool end__int2____int2(){return true;}
virtual bool data__int2____int2( const sint64* value, size_t length ){return true;}

virtual bool begin__int3____int3(){return true;}
virtual bool end__int3____int3(){return true;}
virtual bool data__int3____int3( const sint64* value, size_t length ){return true;}

virtual bool begin__int4____int4(){return true;}
virtual bool end__int4____int4(){return true;}
virtual bool data__int4____int4( const sint64* value, size_t length ){return true;}

virtual bool begin__float____float(){return true;}
virtual bool end__float____float(){return true;}
virtual bool data__float____float( float value ){return true;}

virtual bool begin__float2____float2(){return true;}
virtual bool end__float2____float2(){return true;}
virtual bool data__float2____float2( const float* value, size_t length ){return true;}

virtual bool begin__float3____float3(){return true;}
virtual bool end__float3____float3(){return true;}
virtual bool data__float3____float3( const float* value, size_t length ){return true;}

virtual bool begin__float4____float4(){return true;}
virtual bool end__float4____float4(){return true;}
virtual bool data__float4____float4( const float* value, size_t length ){return true;}

virtual bool begin__float2x2____float2x2(){return true;}
virtual bool end__float2x2____float2x2(){return true;}
virtual bool data__float2x2____float2x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x3____float3x3(){return true;}
virtual bool end__float3x3____float3x3(){return true;}
virtual bool data__float3x3____float3x3( const float* value, size_t length ){return true;}

virtual bool begin__float4x4____float4x4(){return true;}
virtual bool end__float4x4____float4x4(){return true;}
virtual bool data__float4x4____float4x4( const float* value, size_t length ){return true;}

virtual bool begin__string(){return true;}
virtual bool end__string(){return true;}
virtual bool data__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__image(){return true;}

virtual bool begin__data(){return true;}
virtual bool end__data(){return true;}
virtual bool data__data( const uint8* value, size_t length ){return true;}

virtual bool begin__init_from____anyURI(){return true;}
virtual bool end__init_from____anyURI(){return true;}
virtual bool data__init_from____anyURI( COLLADABU::URI value ){return true;}

virtual bool begin__newparam____fx_newparam_common( const newparam____fx_newparam_common__AttributeData& attributeData ){return true;}
virtual bool end__newparam____fx_newparam_common(){return true;}

virtual bool begin__semantic(){return true;}
virtual bool end__semantic(){return true;}
virtual bool data__semantic( const ParserChar* value, size_t length ){return true;}

virtual bool begin__modifier(){return true;}
virtual bool end__modifier(){return true;}
virtual bool data__modifier( const ENUM__fx_modifier_enum_common value ){return true;}

virtual bool begin__float1x1____float(){return true;}
virtual bool end__float1x1____float(){return true;}
virtual bool data__float1x1____float( float value ){return true;}

virtual bool begin__float1x2____float2(){return true;}
virtual bool end__float1x2____float2(){return true;}
virtual bool data__float1x2____float2( const float* value, size_t length ){return true;}

virtual bool begin__float1x3____float3(){return true;}
virtual bool end__float1x3____float3(){return true;}
virtual bool data__float1x3____float3( const float* value, size_t length ){return true;}

virtual bool begin__float1x4____float4(){return true;}
virtual bool end__float1x4____float4(){return true;}
virtual bool data__float1x4____float4( const float* value, size_t length ){return true;}

virtual bool begin__float2x1____float2(){return true;}
virtual bool end__float2x1____float2(){return true;}
virtual bool data__float2x1____float2( const float* value, size_t length ){return true;}

virtual bool begin__float2x3____float2x3(){return true;}
virtual bool end__float2x3____float2x3(){return true;}
virtual bool data__float2x3____float2x3( const float* value, size_t length ){return true;}

virtual bool begin__float2x4____float2x4(){return true;}
virtual bool end__float2x4____float2x4(){return true;}
virtual bool data__float2x4____float2x4( const float* value, size_t length ){return true;}

virtual bool begin__float3x1____float3(){return true;}
virtual bool end__float3x1____float3(){return true;}
virtual bool data__float3x1____float3( const float* value, size_t length ){return true;}

virtual bool begin__float3x2____float3x2(){return true;}
virtual bool end__float3x2____float3x2(){return true;}
virtual bool data__float3x2____float3x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x4____float3x4(){return true;}
virtual bool end__float3x4____float3x4(){return true;}
virtual bool data__float3x4____float3x4( const float* value, size_t length ){return true;}

virtual bool begin__float4x1____float4(){return true;}
virtual bool end__float4x1____float4(){return true;}
virtual bool data__float4x1____float4( const float* value, size_t length ){return true;}

virtual bool begin__float4x2____float4x2(){return true;}
virtual bool end__float4x2____float4x2(){return true;}
virtual bool data__float4x2____float4x2( const float* value, size_t length ){return true;}

virtual bool begin__float4x3____float4x3(){return true;}
virtual bool end__float4x3____float4x3(){return true;}
virtual bool data__float4x3____float4x3( const float* value, size_t length ){return true;}

virtual bool begin__surface____fx_surface_common( const surface____fx_surface_common__AttributeData& attributeData ){return true;}
virtual bool end__surface____fx_surface_common(){return true;}

virtual bool begin__init_as_null( const init_as_null__AttributeData& attributeData ){return true;}
virtual bool end__init_as_null(){return true;}
virtual bool data__init_as_null( const ParserChar* value, size_t length ){return true;}

virtual bool begin__init_as_target( const init_as_target__AttributeData& attributeData ){return true;}
virtual bool end__init_as_target(){return true;}
virtual bool data__init_as_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__init_cube(){return true;}
virtual bool end__init_cube(){return true;}

virtual bool begin__fx_surface_init_cube_common____all( const fx_surface_init_cube_common____all__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_cube_common____all(){return true;}

virtual bool begin__fx_surface_init_cube_common____primary( const fx_surface_init_cube_common____primary__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_cube_common____primary(){return true;}

virtual bool begin__order(){return true;}
virtual bool end__order(){return true;}
virtual bool data__order( const ENUM__fx_surface_face_enum value ){return true;}

virtual bool begin__fx_surface_init_cube_common____face( const fx_surface_init_cube_common____face__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_cube_common____face(){return true;}

virtual bool begin__init_volume(){return true;}
virtual bool end__init_volume(){return true;}

virtual bool begin__fx_surface_init_volume_common____all( const fx_surface_init_volume_common____all__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_volume_common____all(){return true;}

virtual bool begin__fx_surface_init_volume_common____primary( const fx_surface_init_volume_common____primary__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_volume_common____primary(){return true;}

virtual bool begin__init_planar(){return true;}
virtual bool end__init_planar(){return true;}

virtual bool begin__fx_surface_init_planar_common____all( const fx_surface_init_planar_common____all__AttributeData& attributeData ){return true;}
virtual bool end__fx_surface_init_planar_common____all(){return true;}

virtual bool begin__init_from____fx_surface_init_from_common( const init_from____fx_surface_init_from_common__AttributeData& attributeData ){return true;}
virtual bool end__init_from____fx_surface_init_from_common(){return true;}
virtual bool data__init_from____fx_surface_init_from_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__format(){return true;}
virtual bool end__format(){return true;}
virtual bool data__format( const ParserChar* value, size_t length ){return true;}

virtual bool begin__format_hint(){return true;}
virtual bool end__format_hint(){return true;}

virtual bool begin__channels(){return true;}
virtual bool end__channels(){return true;}
virtual bool data__channels( const ENUM__fx_surface_format_hint_channels_enum value ){return true;}

virtual bool begin__range(){return true;}
virtual bool end__range(){return true;}
virtual bool data__range( const ENUM__fx_surface_format_hint_range_enum value ){return true;}

virtual bool begin__precision(){return true;}
virtual bool end__precision(){return true;}
virtual bool data__precision( const ENUM__fx_surface_format_hint_precision_enum value ){return true;}

virtual bool begin__option(){return true;}
virtual bool end__option(){return true;}
virtual bool data__option( const ENUM__fx_surface_format_hint_option_enum value ){return true;}

virtual bool begin__size____int3(){return true;}
virtual bool end__size____int3(){return true;}
virtual bool data__size____int3( const sint64* value, size_t length ){return true;}

virtual bool begin__viewport_ratio(){return true;}
virtual bool end__viewport_ratio(){return true;}
virtual bool data__viewport_ratio( const float* value, size_t length ){return true;}

virtual bool begin__mip_levels(){return true;}
virtual bool end__mip_levels(){return true;}
virtual bool data__mip_levels( uint32 value ){return true;}

virtual bool begin__mipmap_generate(){return true;}
virtual bool end__mipmap_generate(){return true;}
virtual bool data__mipmap_generate( bool value ){return true;}

virtual bool begin__sampler1D____fx_sampler1D_common(){return true;}
virtual bool end__sampler1D____fx_sampler1D_common(){return true;}

virtual bool begin__source____NCName(){return true;}
virtual bool end__source____NCName(){return true;}
virtual bool data__source____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__wrap_s____fx_sampler_wrap_common(){return true;}
virtual bool end__wrap_s____fx_sampler_wrap_common(){return true;}
virtual bool data__wrap_s____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value ){return true;}

virtual bool begin__minfilter(){return true;}
virtual bool end__minfilter(){return true;}
virtual bool data__minfilter( const ENUM__fx_sampler_filter_common value ){return true;}

virtual bool begin__magfilter(){return true;}
virtual bool end__magfilter(){return true;}
virtual bool data__magfilter( const ENUM__fx_sampler_filter_common value ){return true;}

virtual bool begin__mipfilter(){return true;}
virtual bool end__mipfilter(){return true;}
virtual bool data__mipfilter( const ENUM__fx_sampler_filter_common value ){return true;}

virtual bool begin__border_color(){return true;}
virtual bool end__border_color(){return true;}
virtual bool data__border_color( const float* value, size_t length ){return true;}

virtual bool begin__mipmap_maxlevel(){return true;}
virtual bool end__mipmap_maxlevel(){return true;}
virtual bool data__mipmap_maxlevel( uint8 value ){return true;}

virtual bool begin__mipmap_bias(){return true;}
virtual bool end__mipmap_bias(){return true;}
virtual bool data__mipmap_bias( float value ){return true;}

virtual bool begin__sampler2D____fx_sampler2D_common(){return true;}
virtual bool end__sampler2D____fx_sampler2D_common(){return true;}

virtual bool begin__wrap_t____fx_sampler_wrap_common(){return true;}
virtual bool end__wrap_t____fx_sampler_wrap_common(){return true;}
virtual bool data__wrap_t____fx_sampler_wrap_common( const ENUM__fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler3D____fx_sampler3D_common(){return true;}
virtual bool end__sampler3D____fx_sampler3D_common(){return true;}

virtual bool begin__wrap_p(){return true;}
virtual bool end__wrap_p(){return true;}
virtual bool data__wrap_p( const ENUM__fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerCUBE____fx_samplerCUBE_common(){return true;}
virtual bool end__samplerCUBE____fx_samplerCUBE_common(){return true;}

virtual bool begin__samplerRECT____fx_samplerRECT_common(){return true;}
virtual bool end__samplerRECT____fx_samplerRECT_common(){return true;}

virtual bool begin__samplerDEPTH____fx_samplerDEPTH_common(){return true;}
virtual bool end__samplerDEPTH____fx_samplerDEPTH_common(){return true;}

virtual bool begin__enum____string(){return true;}
virtual bool end__enum____string(){return true;}
virtual bool data__enum____string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__fx_profile_abstract( const fx_profile_abstract__AttributeData& attributeData ){return true;}
virtual bool end__fx_profile_abstract(){return true;}
virtual bool data__fx_profile_abstract( const ParserChar* value, size_t length ){return true;}

virtual bool begin__library_force_fields( const library_force_fields__AttributeData& attributeData ){return true;}
virtual bool end__library_force_fields(){return true;}

virtual bool begin__force_field( const force_field__AttributeData& attributeData ){return true;}
virtual bool end__force_field(){return true;}

virtual bool begin__library_images( const library_images__AttributeData& attributeData ){return true;}
virtual bool end__library_images(){return true;}

virtual bool begin__library_lights( const library_lights__AttributeData& attributeData ){return true;}
virtual bool end__library_lights(){return true;}

virtual bool begin__light( const light__AttributeData& attributeData ){return true;}
virtual bool end__light(){return true;}

virtual bool begin__light__technique_common(){return true;}
virtual bool end__light__technique_common(){return true;}

virtual bool begin__light__technique_common__ambient(){return true;}
virtual bool end__light__technique_common__ambient(){return true;}

virtual bool begin__color____TargetableFloat3( const color____TargetableFloat3__AttributeData& attributeData ){return true;}
virtual bool end__color____TargetableFloat3(){return true;}
virtual bool data__color____TargetableFloat3( const float* value, size_t length ){return true;}

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

virtual bool begin__instance_effect__setparam( const instance_effect__setparam__AttributeData& attributeData ){return true;}
virtual bool end__instance_effect__setparam(){return true;}

virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData ){return true;}
virtual bool end__library_nodes(){return true;}

virtual bool begin__node( const node__AttributeData& attributeData ){return true;}
virtual bool end__node(){return true;}

virtual bool begin__lookat( const lookat__AttributeData& attributeData ){return true;}
virtual bool end__lookat(){return true;}
virtual bool data__lookat( const float* value, size_t length ){return true;}

virtual bool begin__matrix( const matrix__AttributeData& attributeData ){return true;}
virtual bool end__matrix(){return true;}
virtual bool data__matrix( const float* value, size_t length ){return true;}

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

virtual bool begin__bind_material__technique_common(){return true;}
virtual bool end__bind_material__technique_common(){return true;}

virtual bool begin__instance_material( const instance_material__AttributeData& attributeData ){return true;}
virtual bool end__instance_material(){return true;}

virtual bool begin__instance_material__bind( const instance_material__bind__AttributeData& attributeData ){return true;}
virtual bool end__instance_material__bind(){return true;}

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

virtual bool begin__physics_material__technique_common(){return true;}
virtual bool end__physics_material__technique_common(){return true;}

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

virtual bool begin__rigid_body__technique_common(){return true;}
virtual bool end__rigid_body__technique_common(){return true;}

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

virtual bool begin__plane(){return true;}
virtual bool end__plane(){return true;}

virtual bool begin__equation(){return true;}
virtual bool end__equation(){return true;}
virtual bool data__equation( const float* value, size_t length ){return true;}

virtual bool begin__box(){return true;}
virtual bool end__box(){return true;}

virtual bool begin__half_extents(){return true;}
virtual bool end__half_extents(){return true;}
virtual bool data__half_extents( const float* value, size_t length ){return true;}

virtual bool begin__sphere(){return true;}
virtual bool end__sphere(){return true;}

virtual bool begin__radius____float(){return true;}
virtual bool end__radius____float(){return true;}
virtual bool data__radius____float( float value ){return true;}

virtual bool begin__cylinder(){return true;}
virtual bool end__cylinder(){return true;}

virtual bool begin__height(){return true;}
virtual bool end__height(){return true;}
virtual bool data__height( float value ){return true;}

virtual bool begin__radius____float2(){return true;}
virtual bool end__radius____float2(){return true;}
virtual bool data__radius____float2( const float* value, size_t length ){return true;}

virtual bool begin__tapered_cylinder(){return true;}
virtual bool end__tapered_cylinder(){return true;}

virtual bool begin__radius1(){return true;}
virtual bool end__radius1(){return true;}
virtual bool data__radius1( const float* value, size_t length ){return true;}

virtual bool begin__radius2(){return true;}
virtual bool end__radius2(){return true;}
virtual bool data__radius2( const float* value, size_t length ){return true;}

virtual bool begin__capsule(){return true;}
virtual bool end__capsule(){return true;}

virtual bool begin__tapered_capsule(){return true;}
virtual bool end__tapered_capsule(){return true;}

virtual bool begin__rigid_constraint( const rigid_constraint__AttributeData& attributeData ){return true;}
virtual bool end__rigid_constraint(){return true;}

virtual bool begin__ref_attachment( const ref_attachment__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment(){return true;}

virtual bool begin__attachment( const attachment__AttributeData& attributeData ){return true;}
virtual bool end__attachment(){return true;}

virtual bool begin__rigid_constraint__technique_common(){return true;}
virtual bool end__rigid_constraint__technique_common(){return true;}

virtual bool begin__enabled( const enabled__AttributeData& attributeData ){return true;}
virtual bool end__enabled(){return true;}
virtual bool data__enabled( bool value ){return true;}

virtual bool begin__interpenetrate( const interpenetrate__AttributeData& attributeData ){return true;}
virtual bool end__interpenetrate(){return true;}
virtual bool data__interpenetrate( bool value ){return true;}

virtual bool begin__limits(){return true;}
virtual bool end__limits(){return true;}

virtual bool begin__swing_cone_and_twist(){return true;}
virtual bool end__swing_cone_and_twist(){return true;}

virtual bool begin__min( const min__AttributeData& attributeData ){return true;}
virtual bool end__min(){return true;}
virtual bool data__min( const float* value, size_t length ){return true;}

virtual bool begin__max( const max__AttributeData& attributeData ){return true;}
virtual bool end__max(){return true;}
virtual bool data__max( const float* value, size_t length ){return true;}

virtual bool begin__limits__linear(){return true;}
virtual bool end__limits__linear(){return true;}

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

virtual bool begin__instance_rigid_body__technique_common(){return true;}
virtual bool end__instance_rigid_body__technique_common(){return true;}

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

virtual bool begin__physics_scene__technique_common(){return true;}
virtual bool end__physics_scene__technique_common(){return true;}

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

virtual bool begin__scene(){return true;}
virtual bool end__scene(){return true;}

virtual bool begin__instance_physics_scene( const instance_physics_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_scene(){return true;}

virtual bool begin__instance_visual_scene( const instance_visual_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_visual_scene(){return true;}

virtual bool begin__profile_GLES( const profile_GLES__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES(){return true;}

virtual bool begin__newparam____gles_newparam( const newparam____gles_newparam__AttributeData& attributeData ){return true;}
virtual bool end__newparam____gles_newparam(){return true;}

virtual bool begin__texture_pipeline____gles_texture_pipeline( const texture_pipeline____gles_texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline____gles_texture_pipeline(){return true;}

virtual bool begin__texcombiner(){return true;}
virtual bool end__texcombiner(){return true;}

virtual bool begin__constant____gles_texture_constant_type( const constant____gles_texture_constant_type__AttributeData& attributeData ){return true;}
virtual bool end__constant____gles_texture_constant_type(){return true;}

virtual bool begin__RGB( const RGB__AttributeData& attributeData ){return true;}
virtual bool end__RGB(){return true;}

virtual bool begin__argument____gles_texcombiner_argumentRGB_type( const argument____gles_texcombiner_argumentRGB_type__AttributeData& attributeData ){return true;}
virtual bool end__argument____gles_texcombiner_argumentRGB_type(){return true;}

virtual bool begin__alpha____gles_texcombiner_commandAlpha_type( const alpha____gles_texcombiner_commandAlpha_type__AttributeData& attributeData ){return true;}
virtual bool end__alpha____gles_texcombiner_commandAlpha_type(){return true;}

virtual bool begin__argument____gles_texcombiner_argumentAlpha_type( const argument____gles_texcombiner_argumentAlpha_type__AttributeData& attributeData ){return true;}
virtual bool end__argument____gles_texcombiner_argumentAlpha_type(){return true;}

virtual bool begin__texenv( const texenv__AttributeData& attributeData ){return true;}
virtual bool end__texenv(){return true;}

virtual bool begin__sampler_state____gles_sampler_state( const sampler_state____gles_sampler_state__AttributeData& attributeData ){return true;}
virtual bool end__sampler_state____gles_sampler_state(){return true;}

virtual bool begin__wrap_s____gles_sampler_wrap(){return true;}
virtual bool end__wrap_s____gles_sampler_wrap(){return true;}
virtual bool data__wrap_s____gles_sampler_wrap( const ENUM__gles_sampler_wrap value ){return true;}

virtual bool begin__wrap_t____gles_sampler_wrap(){return true;}
virtual bool end__wrap_t____gles_sampler_wrap(){return true;}
virtual bool data__wrap_t____gles_sampler_wrap( const ENUM__gles_sampler_wrap value ){return true;}

virtual bool begin__texture_unit( const texture_unit__AttributeData& attributeData ){return true;}
virtual bool end__texture_unit(){return true;}

virtual bool begin__surface____NCName(){return true;}
virtual bool end__surface____NCName(){return true;}
virtual bool data__surface____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler_state____NCName(){return true;}
virtual bool end__sampler_state____NCName(){return true;}
virtual bool data__sampler_state____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__texcoord( const texcoord__AttributeData& attributeData ){return true;}
virtual bool end__texcoord(){return true;}

virtual bool begin__enum____gles_enumeration(){return true;}
virtual bool end__enum____gles_enumeration(){return true;}
virtual bool data__enum____gles_enumeration( UNION__gles_enumeration value ){return true;}

virtual bool begin__profile_GLES__technique( const profile_GLES__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique(){return true;}

virtual bool begin__profile_GLES__technique__setparam( const profile_GLES__technique__setparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__setparam(){return true;}

virtual bool begin__profile_GLES__technique__pass( const profile_GLES__technique__pass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass(){return true;}

virtual bool begin__color_target____gles_rendertarget_common(){return true;}
virtual bool end__color_target____gles_rendertarget_common(){return true;}
virtual bool data__color_target____gles_rendertarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__depth_target____gles_rendertarget_common(){return true;}
virtual bool end__depth_target____gles_rendertarget_common(){return true;}
virtual bool data__depth_target____gles_rendertarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__stencil_target____gles_rendertarget_common(){return true;}
virtual bool end__stencil_target____gles_rendertarget_common(){return true;}
virtual bool data__stencil_target____gles_rendertarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__color_clear____fx_color_common(){return true;}
virtual bool end__color_clear____fx_color_common(){return true;}
virtual bool data__color_clear____fx_color_common( const float* value, size_t length ){return true;}

virtual bool begin__depth_clear____float(){return true;}
virtual bool end__depth_clear____float(){return true;}
virtual bool data__depth_clear____float( float value ){return true;}

virtual bool begin__stencil_clear____byte(){return true;}
virtual bool end__stencil_clear____byte(){return true;}
virtual bool data__stencil_clear____byte( sint8 value ){return true;}

virtual bool begin__draw(){return true;}
virtual bool end__draw(){return true;}
virtual bool data__draw( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLES__technique__pass__alpha_func(){return true;}
virtual bool end__profile_GLES__technique__pass__alpha_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__alpha_func__func( const profile_GLES__technique__pass__alpha_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__alpha_func__func(){return true;}

virtual bool begin__profile_GLES__technique__pass__alpha_func__value( const profile_GLES__technique__pass__alpha_func__value__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__alpha_func__value(){return true;}

virtual bool begin__profile_GLES__technique__pass__blend_func(){return true;}
virtual bool end__profile_GLES__technique__pass__blend_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__blend_func__src( const profile_GLES__technique__pass__blend_func__src__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__blend_func__src(){return true;}

virtual bool begin__profile_GLES__technique__pass__blend_func__dest( const profile_GLES__technique__pass__blend_func__dest__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__blend_func__dest(){return true;}

virtual bool begin__profile_GLES__technique__pass__clear_color( const profile_GLES__technique__pass__clear_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__clear_color(){return true;}

virtual bool begin__profile_GLES__technique__pass__clear_stencil( const profile_GLES__technique__pass__clear_stencil__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__clear_stencil(){return true;}

virtual bool begin__profile_GLES__technique__pass__clear_depth( const profile_GLES__technique__pass__clear_depth__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__clear_depth(){return true;}

virtual bool begin__profile_GLES__technique__pass__clip_plane( const profile_GLES__technique__pass__clip_plane__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__clip_plane(){return true;}

virtual bool begin__profile_GLES__technique__pass__color_mask( const profile_GLES__technique__pass__color_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__color_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__cull_face( const profile_GLES__technique__pass__cull_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__cull_face(){return true;}

virtual bool begin__profile_GLES__technique__pass__depth_func( const profile_GLES__technique__pass__depth_func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__depth_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__depth_mask( const profile_GLES__technique__pass__depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__depth_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__depth_range( const profile_GLES__technique__pass__depth_range__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__depth_range(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_color( const profile_GLES__technique__pass__fog_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_color(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_density( const profile_GLES__technique__pass__fog_density__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_density(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_mode( const profile_GLES__technique__pass__fog_mode__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_mode(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_start( const profile_GLES__technique__pass__fog_start__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_start(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_end( const profile_GLES__technique__pass__fog_end__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_end(){return true;}

virtual bool begin__profile_GLES__technique__pass__front_face( const profile_GLES__technique__pass__front_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__front_face(){return true;}

virtual bool begin__profile_GLES__technique__pass__texture_pipeline( const profile_GLES__technique__pass__texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__texture_pipeline(){return true;}

virtual bool begin__value____gles_texture_pipeline( const value____gles_texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__value____gles_texture_pipeline(){return true;}

virtual bool begin__profile_GLES__technique__pass__logic_op( const profile_GLES__technique__pass__logic_op__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__logic_op(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_ambient( const profile_GLES__technique__pass__light_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_diffuse( const profile_GLES__technique__pass__light_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_diffuse(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_specular( const profile_GLES__technique__pass__light_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_specular(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_position( const profile_GLES__technique__pass__light_position__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_position(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_constant_attenuation( const profile_GLES__technique__pass__light_constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_constant_attenuation(){return true;}

virtual bool begin__light_linear_attenutation( const light_linear_attenutation__AttributeData& attributeData ){return true;}
virtual bool end__light_linear_attenutation(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_quadratic_attenuation( const profile_GLES__technique__pass__light_quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_quadratic_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_spot_cutoff( const profile_GLES__technique__pass__light_spot_cutoff__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_spot_cutoff(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_spot_direction( const profile_GLES__technique__pass__light_spot_direction__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_spot_direction(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_spot_exponent( const profile_GLES__technique__pass__light_spot_exponent__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_spot_exponent(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_model_ambient( const profile_GLES__technique__pass__light_model_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_model_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__line_width( const profile_GLES__technique__pass__line_width__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__line_width(){return true;}

virtual bool begin__profile_GLES__technique__pass__material_ambient( const profile_GLES__technique__pass__material_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__material_ambient(){return true;}

virtual bool begin__profile_GLES__technique__pass__material_diffuse( const profile_GLES__technique__pass__material_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__material_diffuse(){return true;}

virtual bool begin__profile_GLES__technique__pass__material_emission( const profile_GLES__technique__pass__material_emission__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__material_emission(){return true;}

virtual bool begin__profile_GLES__technique__pass__material_shininess( const profile_GLES__technique__pass__material_shininess__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__material_shininess(){return true;}

virtual bool begin__profile_GLES__technique__pass__material_specular( const profile_GLES__technique__pass__material_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__material_specular(){return true;}

virtual bool begin__profile_GLES__technique__pass__model_view_matrix( const profile_GLES__technique__pass__model_view_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__model_view_matrix(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_distance_attenuation( const profile_GLES__technique__pass__point_distance_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_distance_attenuation(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_fade_threshold_size( const profile_GLES__technique__pass__point_fade_threshold_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_fade_threshold_size(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_size( const profile_GLES__technique__pass__point_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_size(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_size_min( const profile_GLES__technique__pass__point_size_min__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_size_min(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_size_max( const profile_GLES__technique__pass__point_size_max__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_size_max(){return true;}

virtual bool begin__profile_GLES__technique__pass__polygon_offset( const profile_GLES__technique__pass__polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__polygon_offset(){return true;}

virtual bool begin__profile_GLES__technique__pass__projection_matrix( const profile_GLES__technique__pass__projection_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__projection_matrix(){return true;}

virtual bool begin__profile_GLES__technique__pass__scissor( const profile_GLES__technique__pass__scissor__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__scissor(){return true;}

virtual bool begin__profile_GLES__technique__pass__shade_model( const profile_GLES__technique__pass__shade_model__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__shade_model(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_func(){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_func(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_func__func( const profile_GLES__technique__pass__stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_func__func(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_func__ref( const profile_GLES__technique__pass__stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_func__ref(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_func__mask( const profile_GLES__technique__pass__stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_func__mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_mask( const profile_GLES__technique__pass__stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_mask(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_op(){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_op(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_op__fail( const profile_GLES__technique__pass__stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_op__fail(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_op__zfail( const profile_GLES__technique__pass__stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_op__zfail(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_op__zpass( const profile_GLES__technique__pass__stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_op__zpass(){return true;}

virtual bool begin__profile_GLES__technique__pass__alpha_test_enable( const profile_GLES__technique__pass__alpha_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__alpha_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__blend_enable( const profile_GLES__technique__pass__blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__blend_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__clip_plane_enable( const profile_GLES__technique__pass__clip_plane_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__clip_plane_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__color_logic_op_enable( const profile_GLES__technique__pass__color_logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__color_logic_op_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__color_material_enable( const profile_GLES__technique__pass__color_material_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__color_material_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__cull_face_enable( const profile_GLES__technique__pass__cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__cull_face_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__depth_test_enable( const profile_GLES__technique__pass__depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__depth_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__dither_enable( const profile_GLES__technique__pass__dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__dither_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__fog_enable( const profile_GLES__technique__pass__fog_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__fog_enable(){return true;}

virtual bool begin__texture_pipeline_enable( const texture_pipeline_enable__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_enable( const profile_GLES__technique__pass__light_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__lighting_enable( const profile_GLES__technique__pass__lighting_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__lighting_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__light_model_two_side_enable( const profile_GLES__technique__pass__light_model_two_side_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__light_model_two_side_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__line_smooth_enable( const profile_GLES__technique__pass__line_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__line_smooth_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__multisample_enable( const profile_GLES__technique__pass__multisample_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__multisample_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__normalize_enable( const profile_GLES__technique__pass__normalize_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__normalize_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__point_smooth_enable( const profile_GLES__technique__pass__point_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__point_smooth_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__polygon_offset_fill_enable( const profile_GLES__technique__pass__polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__polygon_offset_fill_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__rescale_normal_enable( const profile_GLES__technique__pass__rescale_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__rescale_normal_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__sample_alpha_to_coverage_enable( const profile_GLES__technique__pass__sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__sample_alpha_to_one_enable( const profile_GLES__technique__pass__sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__sample_alpha_to_one_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__sample_coverage_enable( const profile_GLES__technique__pass__sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__sample_coverage_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__scissor_test_enable( const profile_GLES__technique__pass__scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__scissor_test_enable(){return true;}

virtual bool begin__profile_GLES__technique__pass__stencil_test_enable( const profile_GLES__technique__pass__stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique__pass__stencil_test_enable(){return true;}

virtual bool begin__size____float3(){return true;}
virtual bool end__size____float3(){return true;}
virtual bool data__size____float3( const float* value, size_t length ){return true;}

virtual bool begin__profile_GLSL( const profile_GLSL__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL(){return true;}

virtual bool begin__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__code(){return true;}
virtual bool data__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__include(){return true;}

virtual bool begin__newparam____glsl_newparam( const newparam____glsl_newparam__AttributeData& attributeData ){return true;}
virtual bool end__newparam____glsl_newparam(){return true;}

virtual bool begin__bool____glsl_bool(){return true;}
virtual bool end__bool____glsl_bool(){return true;}
virtual bool data__bool____glsl_bool( bool value ){return true;}

virtual bool begin__bool2____glsl_bool2(){return true;}
virtual bool end__bool2____glsl_bool2(){return true;}
virtual bool data__bool2____glsl_bool2( const bool* value, size_t length ){return true;}

virtual bool begin__bool3____glsl_bool3(){return true;}
virtual bool end__bool3____glsl_bool3(){return true;}
virtual bool data__bool3____glsl_bool3( const bool* value, size_t length ){return true;}

virtual bool begin__bool4____glsl_bool4(){return true;}
virtual bool end__bool4____glsl_bool4(){return true;}
virtual bool data__bool4____glsl_bool4( const bool* value, size_t length ){return true;}

virtual bool begin__float____glsl_float(){return true;}
virtual bool end__float____glsl_float(){return true;}
virtual bool data__float____glsl_float( float value ){return true;}

virtual bool begin__float2____glsl_float2(){return true;}
virtual bool end__float2____glsl_float2(){return true;}
virtual bool data__float2____glsl_float2( const float* value, size_t length ){return true;}

virtual bool begin__float3____glsl_float3(){return true;}
virtual bool end__float3____glsl_float3(){return true;}
virtual bool data__float3____glsl_float3( const float* value, size_t length ){return true;}

virtual bool begin__float4____glsl_float4(){return true;}
virtual bool end__float4____glsl_float4(){return true;}
virtual bool data__float4____glsl_float4( const float* value, size_t length ){return true;}

virtual bool begin__float2x2____glsl_float2x2(){return true;}
virtual bool end__float2x2____glsl_float2x2(){return true;}
virtual bool data__float2x2____glsl_float2x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x3____glsl_float3x3(){return true;}
virtual bool end__float3x3____glsl_float3x3(){return true;}
virtual bool data__float3x3____glsl_float3x3( const float* value, size_t length ){return true;}

virtual bool begin__float4x4____glsl_float4x4(){return true;}
virtual bool end__float4x4____glsl_float4x4(){return true;}
virtual bool data__float4x4____glsl_float4x4( const float* value, size_t length ){return true;}

virtual bool begin__int____glsl_int(){return true;}
virtual bool end__int____glsl_int(){return true;}
virtual bool data__int____glsl_int( sint32 value ){return true;}

virtual bool begin__int2____glsl_int2(){return true;}
virtual bool end__int2____glsl_int2(){return true;}
virtual bool data__int2____glsl_int2( const sint32* value, size_t length ){return true;}

virtual bool begin__int3____glsl_int3(){return true;}
virtual bool end__int3____glsl_int3(){return true;}
virtual bool data__int3____glsl_int3( const sint32* value, size_t length ){return true;}

virtual bool begin__int4____glsl_int4(){return true;}
virtual bool end__int4____glsl_int4(){return true;}
virtual bool data__int4____glsl_int4( const sint32* value, size_t length ){return true;}

virtual bool begin__surface____glsl_surface_type( const surface____glsl_surface_type__AttributeData& attributeData ){return true;}
virtual bool end__surface____glsl_surface_type(){return true;}

virtual bool begin__glsl_surface_type____generator(){return true;}
virtual bool end__glsl_surface_type____generator(){return true;}

virtual bool begin__profile_GLSL__newparam__surface__generator__name( const profile_GLSL__newparam__surface__generator__name__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__newparam__surface__generator__name(){return true;}
virtual bool data__profile_GLSL__newparam__surface__generator__name( const ParserChar* value, size_t length ){return true;}

virtual bool begin__setparam____glsl_setparam_simple( const setparam____glsl_setparam_simple__AttributeData& attributeData ){return true;}
virtual bool end__setparam____glsl_setparam_simple(){return true;}

virtual bool begin__sampler1D____gl_sampler1D(){return true;}
virtual bool end__sampler1D____gl_sampler1D(){return true;}

virtual bool begin__sampler2D____gl_sampler2D(){return true;}
virtual bool end__sampler2D____gl_sampler2D(){return true;}

virtual bool begin__sampler3D____gl_sampler3D(){return true;}
virtual bool end__sampler3D____gl_sampler3D(){return true;}

virtual bool begin__samplerCUBE____gl_samplerCUBE(){return true;}
virtual bool end__samplerCUBE____gl_samplerCUBE(){return true;}

virtual bool begin__samplerRECT____gl_samplerRECT(){return true;}
virtual bool end__samplerRECT____gl_samplerRECT(){return true;}

virtual bool begin__samplerDEPTH____gl_samplerDEPTH(){return true;}
virtual bool end__samplerDEPTH____gl_samplerDEPTH(){return true;}

virtual bool begin__enum____gl_enumeration(){return true;}
virtual bool end__enum____gl_enumeration(){return true;}
virtual bool data__enum____gl_enumeration( UNION__gl_enumeration value ){return true;}

virtual bool begin__array____glsl_newarray_type( const array____glsl_newarray_type__AttributeData& attributeData ){return true;}
virtual bool end__array____glsl_newarray_type(){return true;}

virtual bool begin__profile_GLSL__technique( const profile_GLSL__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique(){return true;}

virtual bool begin__setparam____glsl_setparam( const setparam____glsl_setparam__AttributeData& attributeData ){return true;}
virtual bool end__setparam____glsl_setparam(){return true;}

virtual bool begin__array____glsl_setarray_type( const array____glsl_setarray_type__AttributeData& attributeData ){return true;}
virtual bool end__array____glsl_setarray_type(){return true;}

virtual bool begin__profile_GLSL__technique__pass( const profile_GLSL__technique__pass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass(){return true;}

virtual bool begin__color_target____fx_colortarget_common( const color_target____fx_colortarget_common__AttributeData& attributeData ){return true;}
virtual bool end__color_target____fx_colortarget_common(){return true;}
virtual bool data__color_target____fx_colortarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__depth_target____fx_depthtarget_common( const depth_target____fx_depthtarget_common__AttributeData& attributeData ){return true;}
virtual bool end__depth_target____fx_depthtarget_common(){return true;}
virtual bool data__depth_target____fx_depthtarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__stencil_target____fx_stenciltarget_common( const stencil_target____fx_stenciltarget_common__AttributeData& attributeData ){return true;}
virtual bool end__stencil_target____fx_stenciltarget_common(){return true;}
virtual bool data__stencil_target____fx_stenciltarget_common( const ParserChar* value, size_t length ){return true;}

virtual bool begin__color_clear____fx_clearcolor_common( const color_clear____fx_clearcolor_common__AttributeData& attributeData ){return true;}
virtual bool end__color_clear____fx_clearcolor_common(){return true;}
virtual bool data__color_clear____fx_clearcolor_common( const float* value, size_t length ){return true;}

virtual bool begin__depth_clear____fx_cleardepth_common( const depth_clear____fx_cleardepth_common__AttributeData& attributeData ){return true;}
virtual bool end__depth_clear____fx_cleardepth_common(){return true;}
virtual bool data__depth_clear____fx_cleardepth_common( float value ){return true;}

virtual bool begin__stencil_clear____fx_clearstencil_common( const stencil_clear____fx_clearstencil_common__AttributeData& attributeData ){return true;}
virtual bool end__stencil_clear____fx_clearstencil_common(){return true;}
virtual bool data__stencil_clear____fx_clearstencil_common( sint8 value ){return true;}

virtual bool begin__profile_GLSL__technique__pass__alpha_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__alpha_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__alpha_func__func( const profile_GLSL__technique__pass__alpha_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__alpha_func__func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__alpha_func__value( const profile_GLSL__technique__pass__alpha_func__value__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__alpha_func__value(){return true;}

virtual bool begin__profile_GLSL__technique__pass__blend_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__blend_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__blend_func__src( const profile_GLSL__technique__pass__blend_func__src__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__blend_func__src(){return true;}

virtual bool begin__profile_GLSL__technique__pass__blend_func__dest( const profile_GLSL__technique__pass__blend_func__dest__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__blend_func__dest(){return true;}

virtual bool begin__blend_func_separate(){return true;}
virtual bool end__blend_func_separate(){return true;}

virtual bool begin__src_rgb( const src_rgb__AttributeData& attributeData ){return true;}
virtual bool end__src_rgb(){return true;}

virtual bool begin__dest_rgb( const dest_rgb__AttributeData& attributeData ){return true;}
virtual bool end__dest_rgb(){return true;}

virtual bool begin__src_alpha( const src_alpha__AttributeData& attributeData ){return true;}
virtual bool end__src_alpha(){return true;}

virtual bool begin__dest_alpha( const dest_alpha__AttributeData& attributeData ){return true;}
virtual bool end__dest_alpha(){return true;}

virtual bool begin__blend_equation( const blend_equation__AttributeData& attributeData ){return true;}
virtual bool end__blend_equation(){return true;}

virtual bool begin__blend_equation_separate(){return true;}
virtual bool end__blend_equation_separate(){return true;}

virtual bool begin__rgb( const rgb__AttributeData& attributeData ){return true;}
virtual bool end__rgb(){return true;}

virtual bool begin__blend_equation_separate__alpha( const blend_equation_separate__alpha__AttributeData& attributeData ){return true;}
virtual bool end__blend_equation_separate__alpha(){return true;}

virtual bool begin__color_material(){return true;}
virtual bool end__color_material(){return true;}

virtual bool begin__color_material__face( const color_material__face__AttributeData& attributeData ){return true;}
virtual bool end__color_material__face(){return true;}

virtual bool begin__color_material__mode( const color_material__mode__AttributeData& attributeData ){return true;}
virtual bool end__color_material__mode(){return true;}

virtual bool begin__profile_GLSL__technique__pass__cull_face( const profile_GLSL__technique__pass__cull_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__cull_face(){return true;}

virtual bool begin__profile_GLSL__technique__pass__depth_func( const profile_GLSL__technique__pass__depth_func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__depth_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_mode( const profile_GLSL__technique__pass__fog_mode__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_mode(){return true;}

virtual bool begin__fog_coord_src( const fog_coord_src__AttributeData& attributeData ){return true;}
virtual bool end__fog_coord_src(){return true;}

virtual bool begin__profile_GLSL__technique__pass__front_face( const profile_GLSL__technique__pass__front_face__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__front_face(){return true;}

virtual bool begin__light_model_color_control( const light_model_color_control__AttributeData& attributeData ){return true;}
virtual bool end__light_model_color_control(){return true;}

virtual bool begin__profile_GLSL__technique__pass__logic_op( const profile_GLSL__technique__pass__logic_op__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__logic_op(){return true;}

virtual bool begin__polygon_mode(){return true;}
virtual bool end__polygon_mode(){return true;}

virtual bool begin__polygon_mode__face( const polygon_mode__face__AttributeData& attributeData ){return true;}
virtual bool end__polygon_mode__face(){return true;}

virtual bool begin__polygon_mode__mode( const polygon_mode__mode__AttributeData& attributeData ){return true;}
virtual bool end__polygon_mode__mode(){return true;}

virtual bool begin__profile_GLSL__technique__pass__shade_model( const profile_GLSL__technique__pass__shade_model__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__shade_model(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_func(){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_func__func( const profile_GLSL__technique__pass__stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_func__func(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_func__ref( const profile_GLSL__technique__pass__stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_func__ref(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_func__mask( const profile_GLSL__technique__pass__stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_func__mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_op(){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_op(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_op__fail( const profile_GLSL__technique__pass__stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_op__fail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_op__zfail( const profile_GLSL__technique__pass__stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_op__zfail(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_op__zpass( const profile_GLSL__technique__pass__stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_op__zpass(){return true;}

virtual bool begin__stencil_func_separate(){return true;}
virtual bool end__stencil_func_separate(){return true;}

virtual bool begin__front( const front__AttributeData& attributeData ){return true;}
virtual bool end__front(){return true;}

virtual bool begin__back( const back__AttributeData& attributeData ){return true;}
virtual bool end__back(){return true;}

virtual bool begin__stencil_func_separate__ref( const stencil_func_separate__ref__AttributeData& attributeData ){return true;}
virtual bool end__stencil_func_separate__ref(){return true;}

virtual bool begin__stencil_func_separate__mask( const stencil_func_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__stencil_func_separate__mask(){return true;}

virtual bool begin__stencil_op_separate(){return true;}
virtual bool end__stencil_op_separate(){return true;}

virtual bool begin__stencil_op_separate__face( const stencil_op_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op_separate__face(){return true;}

virtual bool begin__stencil_op_separate__fail( const stencil_op_separate__fail__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op_separate__fail(){return true;}

virtual bool begin__stencil_op_separate__zfail( const stencil_op_separate__zfail__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op_separate__zfail(){return true;}

virtual bool begin__stencil_op_separate__zpass( const stencil_op_separate__zpass__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op_separate__zpass(){return true;}

virtual bool begin__stencil_mask_separate(){return true;}
virtual bool end__stencil_mask_separate(){return true;}

virtual bool begin__stencil_mask_separate__face( const stencil_mask_separate__face__AttributeData& attributeData ){return true;}
virtual bool end__stencil_mask_separate__face(){return true;}

virtual bool begin__stencil_mask_separate__mask( const stencil_mask_separate__mask__AttributeData& attributeData ){return true;}
virtual bool end__stencil_mask_separate__mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_enable( const profile_GLSL__technique__pass__light_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_ambient( const profile_GLSL__technique__pass__light_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_diffuse( const profile_GLSL__technique__pass__light_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_diffuse(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_specular( const profile_GLSL__technique__pass__light_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_specular(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_position( const profile_GLSL__technique__pass__light_position__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_position(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_constant_attenuation( const profile_GLSL__technique__pass__light_constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_constant_attenuation(){return true;}

virtual bool begin__light_linear_attenuation( const light_linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__light_linear_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_quadratic_attenuation( const profile_GLSL__technique__pass__light_quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_quadratic_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_spot_cutoff( const profile_GLSL__technique__pass__light_spot_cutoff__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_spot_cutoff(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_spot_direction( const profile_GLSL__technique__pass__light_spot_direction__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_spot_direction(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_spot_exponent( const profile_GLSL__technique__pass__light_spot_exponent__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_spot_exponent(){return true;}

virtual bool begin__texture1D( const texture1D__AttributeData& attributeData ){return true;}
virtual bool end__texture1D(){return true;}

virtual bool begin__value____gl_sampler1D(){return true;}
virtual bool end__value____gl_sampler1D(){return true;}

virtual bool begin__param____NCName(){return true;}
virtual bool end__param____NCName(){return true;}
virtual bool data__param____NCName( const ParserChar* value, size_t length ){return true;}

virtual bool begin__texture2D( const texture2D__AttributeData& attributeData ){return true;}
virtual bool end__texture2D(){return true;}

virtual bool begin__value____gl_sampler2D(){return true;}
virtual bool end__value____gl_sampler2D(){return true;}

virtual bool begin__texture3D( const texture3D__AttributeData& attributeData ){return true;}
virtual bool end__texture3D(){return true;}

virtual bool begin__value____gl_sampler3D(){return true;}
virtual bool end__value____gl_sampler3D(){return true;}

virtual bool begin__textureCUBE( const textureCUBE__AttributeData& attributeData ){return true;}
virtual bool end__textureCUBE(){return true;}

virtual bool begin__value____gl_samplerCUBE(){return true;}
virtual bool end__value____gl_samplerCUBE(){return true;}

virtual bool begin__textureRECT( const textureRECT__AttributeData& attributeData ){return true;}
virtual bool end__textureRECT(){return true;}

virtual bool begin__value____gl_samplerRECT(){return true;}
virtual bool end__value____gl_samplerRECT(){return true;}

virtual bool begin__textureDEPTH( const textureDEPTH__AttributeData& attributeData ){return true;}
virtual bool end__textureDEPTH(){return true;}

virtual bool begin__value____gl_samplerDEPTH(){return true;}
virtual bool end__value____gl_samplerDEPTH(){return true;}

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

virtual bool begin__profile_GLSL__technique__pass__clip_plane( const profile_GLSL__technique__pass__clip_plane__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__clip_plane(){return true;}

virtual bool begin__profile_GLSL__technique__pass__clip_plane_enable( const profile_GLSL__technique__pass__clip_plane_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__clip_plane_enable(){return true;}

virtual bool begin__blend_color( const blend_color__AttributeData& attributeData ){return true;}
virtual bool end__blend_color(){return true;}

virtual bool begin__profile_GLSL__technique__pass__clear_color( const profile_GLSL__technique__pass__clear_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__clear_color(){return true;}

virtual bool begin__profile_GLSL__technique__pass__clear_stencil( const profile_GLSL__technique__pass__clear_stencil__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__clear_stencil(){return true;}

virtual bool begin__profile_GLSL__technique__pass__clear_depth( const profile_GLSL__technique__pass__clear_depth__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__clear_depth(){return true;}

virtual bool begin__profile_GLSL__technique__pass__color_mask( const profile_GLSL__technique__pass__color_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__color_mask(){return true;}

virtual bool begin__depth_bounds( const depth_bounds__AttributeData& attributeData ){return true;}
virtual bool end__depth_bounds(){return true;}

virtual bool begin__profile_GLSL__technique__pass__depth_mask( const profile_GLSL__technique__pass__depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__depth_mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__depth_range( const profile_GLSL__technique__pass__depth_range__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__depth_range(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_density( const profile_GLSL__technique__pass__fog_density__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_density(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_start( const profile_GLSL__technique__pass__fog_start__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_start(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_end( const profile_GLSL__technique__pass__fog_end__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_end(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_color( const profile_GLSL__technique__pass__fog_color__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_color(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_model_ambient( const profile_GLSL__technique__pass__light_model_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_model_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__lighting_enable( const profile_GLSL__technique__pass__lighting_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__lighting_enable(){return true;}

virtual bool begin__line_stipple( const line_stipple__AttributeData& attributeData ){return true;}
virtual bool end__line_stipple(){return true;}

virtual bool begin__profile_GLSL__technique__pass__line_width( const profile_GLSL__technique__pass__line_width__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__line_width(){return true;}

virtual bool begin__profile_GLSL__technique__pass__material_ambient( const profile_GLSL__technique__pass__material_ambient__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__material_ambient(){return true;}

virtual bool begin__profile_GLSL__technique__pass__material_diffuse( const profile_GLSL__technique__pass__material_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__material_diffuse(){return true;}

virtual bool begin__profile_GLSL__technique__pass__material_emission( const profile_GLSL__technique__pass__material_emission__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__material_emission(){return true;}

virtual bool begin__profile_GLSL__technique__pass__material_shininess( const profile_GLSL__technique__pass__material_shininess__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__material_shininess(){return true;}

virtual bool begin__profile_GLSL__technique__pass__material_specular( const profile_GLSL__technique__pass__material_specular__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__material_specular(){return true;}

virtual bool begin__profile_GLSL__technique__pass__model_view_matrix( const profile_GLSL__technique__pass__model_view_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__model_view_matrix(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_distance_attenuation( const profile_GLSL__technique__pass__point_distance_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_distance_attenuation(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_fade_threshold_size( const profile_GLSL__technique__pass__point_fade_threshold_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_fade_threshold_size(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_size( const profile_GLSL__technique__pass__point_size__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_size(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_size_min( const profile_GLSL__technique__pass__point_size_min__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_size_min(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_size_max( const profile_GLSL__technique__pass__point_size_max__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_size_max(){return true;}

virtual bool begin__profile_GLSL__technique__pass__polygon_offset( const profile_GLSL__technique__pass__polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__polygon_offset(){return true;}

virtual bool begin__profile_GLSL__technique__pass__projection_matrix( const profile_GLSL__technique__pass__projection_matrix__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__projection_matrix(){return true;}

virtual bool begin__profile_GLSL__technique__pass__scissor( const profile_GLSL__technique__pass__scissor__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__scissor(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_mask( const profile_GLSL__technique__pass__stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_mask(){return true;}

virtual bool begin__profile_GLSL__technique__pass__alpha_test_enable( const profile_GLSL__technique__pass__alpha_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__alpha_test_enable(){return true;}

virtual bool begin__auto_normal_enable( const auto_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__auto_normal_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__blend_enable( const profile_GLSL__technique__pass__blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__blend_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__color_logic_op_enable( const profile_GLSL__technique__pass__color_logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__color_logic_op_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__color_material_enable( const profile_GLSL__technique__pass__color_material_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__color_material_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__cull_face_enable( const profile_GLSL__technique__pass__cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__cull_face_enable(){return true;}

virtual bool begin__depth_bounds_enable( const depth_bounds_enable__AttributeData& attributeData ){return true;}
virtual bool end__depth_bounds_enable(){return true;}

virtual bool begin__depth_clamp_enable( const depth_clamp_enable__AttributeData& attributeData ){return true;}
virtual bool end__depth_clamp_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__depth_test_enable( const profile_GLSL__technique__pass__depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__depth_test_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__dither_enable( const profile_GLSL__technique__pass__dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__dither_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__fog_enable( const profile_GLSL__technique__pass__fog_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__fog_enable(){return true;}

virtual bool begin__light_model_local_viewer_enable( const light_model_local_viewer_enable__AttributeData& attributeData ){return true;}
virtual bool end__light_model_local_viewer_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__light_model_two_side_enable( const profile_GLSL__technique__pass__light_model_two_side_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__light_model_two_side_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__line_smooth_enable( const profile_GLSL__technique__pass__line_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__line_smooth_enable(){return true;}

virtual bool begin__line_stipple_enable( const line_stipple_enable__AttributeData& attributeData ){return true;}
virtual bool end__line_stipple_enable(){return true;}

virtual bool begin__logic_op_enable( const logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__logic_op_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__multisample_enable( const profile_GLSL__technique__pass__multisample_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__multisample_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__normalize_enable( const profile_GLSL__technique__pass__normalize_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__normalize_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__point_smooth_enable( const profile_GLSL__technique__pass__point_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__point_smooth_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__polygon_offset_fill_enable( const profile_GLSL__technique__pass__polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__polygon_offset_fill_enable(){return true;}

virtual bool begin__polygon_offset_line_enable( const polygon_offset_line_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset_line_enable(){return true;}

virtual bool begin__polygon_offset_point_enable( const polygon_offset_point_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset_point_enable(){return true;}

virtual bool begin__polygon_smooth_enable( const polygon_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_smooth_enable(){return true;}

virtual bool begin__polygon_stipple_enable( const polygon_stipple_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_stipple_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__rescale_normal_enable( const profile_GLSL__technique__pass__rescale_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__rescale_normal_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable( const profile_GLSL__technique__pass__sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__sample_alpha_to_one_enable( const profile_GLSL__technique__pass__sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__sample_alpha_to_one_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__sample_coverage_enable( const profile_GLSL__technique__pass__sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__sample_coverage_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__scissor_test_enable( const profile_GLSL__technique__pass__scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__scissor_test_enable(){return true;}

virtual bool begin__profile_GLSL__technique__pass__stencil_test_enable( const profile_GLSL__technique__pass__stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__stencil_test_enable(){return true;}

virtual bool begin__gl_hook_abstract( const gl_hook_abstract__AttributeData& attributeData ){return true;}
virtual bool end__gl_hook_abstract(){return true;}
virtual bool data__gl_hook_abstract( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLSL__technique__pass__shader( const profile_GLSL__technique__pass__shader__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__shader(){return true;}

virtual bool begin__profile_GLSL__technique__pass__shader__compiler_target(){return true;}
virtual bool end__profile_GLSL__technique__pass__shader__compiler_target(){return true;}
virtual bool data__profile_GLSL__technique__pass__shader__compiler_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__compiler_options(){return true;}
virtual bool end__compiler_options(){return true;}
virtual bool data__compiler_options( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLSL__technique__pass__shader__name( const profile_GLSL__technique__pass__shader__name__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__shader__name(){return true;}
virtual bool data__profile_GLSL__technique__pass__shader__name( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLSL__technique__pass__shader__bind( const profile_GLSL__technique__pass__shader__bind__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__shader__bind(){return true;}

virtual bool begin__profile_GLSL__technique__pass__shader__bind__param( const profile_GLSL__technique__pass__shader__bind__param__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique__pass__shader__bind__param(){return true;}

virtual bool begin__profile_CG( const profile_CG__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG(){return true;}

virtual bool begin__newparam____cg_newparam( const newparam____cg_newparam__AttributeData& attributeData ){return true;}
virtual bool end__newparam____cg_newparam(){return true;}

virtual bool begin__bool____cg_bool(){return true;}
virtual bool end__bool____cg_bool(){return true;}
virtual bool data__bool____cg_bool( bool value ){return true;}

virtual bool begin__bool1(){return true;}
virtual bool end__bool1(){return true;}
virtual bool data__bool1( bool value ){return true;}

virtual bool begin__bool2____cg_bool2(){return true;}
virtual bool end__bool2____cg_bool2(){return true;}
virtual bool data__bool2____cg_bool2( const bool* value, size_t length ){return true;}

virtual bool begin__bool3____cg_bool3(){return true;}
virtual bool end__bool3____cg_bool3(){return true;}
virtual bool data__bool3____cg_bool3( const bool* value, size_t length ){return true;}

virtual bool begin__bool4____cg_bool4(){return true;}
virtual bool end__bool4____cg_bool4(){return true;}
virtual bool data__bool4____cg_bool4( const bool* value, size_t length ){return true;}

virtual bool begin__bool1x1(){return true;}
virtual bool end__bool1x1(){return true;}
virtual bool data__bool1x1( const bool* value, size_t length ){return true;}

virtual bool begin__bool1x2(){return true;}
virtual bool end__bool1x2(){return true;}
virtual bool data__bool1x2( const bool* value, size_t length ){return true;}

virtual bool begin__bool1x3(){return true;}
virtual bool end__bool1x3(){return true;}
virtual bool data__bool1x3( const bool* value, size_t length ){return true;}

virtual bool begin__bool1x4(){return true;}
virtual bool end__bool1x4(){return true;}
virtual bool data__bool1x4( const bool* value, size_t length ){return true;}

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

virtual bool begin__float____cg_float(){return true;}
virtual bool end__float____cg_float(){return true;}
virtual bool data__float____cg_float( float value ){return true;}

virtual bool begin__float1(){return true;}
virtual bool end__float1(){return true;}
virtual bool data__float1( float value ){return true;}

virtual bool begin__float2____cg_float2(){return true;}
virtual bool end__float2____cg_float2(){return true;}
virtual bool data__float2____cg_float2( const float* value, size_t length ){return true;}

virtual bool begin__float3____cg_float3(){return true;}
virtual bool end__float3____cg_float3(){return true;}
virtual bool data__float3____cg_float3( const float* value, size_t length ){return true;}

virtual bool begin__float4____cg_float4(){return true;}
virtual bool end__float4____cg_float4(){return true;}
virtual bool data__float4____cg_float4( const float* value, size_t length ){return true;}

virtual bool begin__float1x1____cg_float1x1(){return true;}
virtual bool end__float1x1____cg_float1x1(){return true;}
virtual bool data__float1x1____cg_float1x1( const float* value, size_t length ){return true;}

virtual bool begin__float1x2____cg_float1x2(){return true;}
virtual bool end__float1x2____cg_float1x2(){return true;}
virtual bool data__float1x2____cg_float1x2( const float* value, size_t length ){return true;}

virtual bool begin__float1x3____cg_float1x3(){return true;}
virtual bool end__float1x3____cg_float1x3(){return true;}
virtual bool data__float1x3____cg_float1x3( const float* value, size_t length ){return true;}

virtual bool begin__float1x4____cg_float1x4(){return true;}
virtual bool end__float1x4____cg_float1x4(){return true;}
virtual bool data__float1x4____cg_float1x4( const float* value, size_t length ){return true;}

virtual bool begin__float2x1____cg_float2x1(){return true;}
virtual bool end__float2x1____cg_float2x1(){return true;}
virtual bool data__float2x1____cg_float2x1( const float* value, size_t length ){return true;}

virtual bool begin__float2x2____cg_float2x2(){return true;}
virtual bool end__float2x2____cg_float2x2(){return true;}
virtual bool data__float2x2____cg_float2x2( const float* value, size_t length ){return true;}

virtual bool begin__float2x3____cg_float2x3(){return true;}
virtual bool end__float2x3____cg_float2x3(){return true;}
virtual bool data__float2x3____cg_float2x3( const float* value, size_t length ){return true;}

virtual bool begin__float2x4____cg_float2x4(){return true;}
virtual bool end__float2x4____cg_float2x4(){return true;}
virtual bool data__float2x4____cg_float2x4( const float* value, size_t length ){return true;}

virtual bool begin__float3x1____cg_float3x1(){return true;}
virtual bool end__float3x1____cg_float3x1(){return true;}
virtual bool data__float3x1____cg_float3x1( const float* value, size_t length ){return true;}

virtual bool begin__float3x2____cg_float3x2(){return true;}
virtual bool end__float3x2____cg_float3x2(){return true;}
virtual bool data__float3x2____cg_float3x2( const float* value, size_t length ){return true;}

virtual bool begin__float3x3____cg_float3x3(){return true;}
virtual bool end__float3x3____cg_float3x3(){return true;}
virtual bool data__float3x3____cg_float3x3( const float* value, size_t length ){return true;}

virtual bool begin__float3x4____cg_float3x4(){return true;}
virtual bool end__float3x4____cg_float3x4(){return true;}
virtual bool data__float3x4____cg_float3x4( const float* value, size_t length ){return true;}

virtual bool begin__float4x1____cg_float4x1(){return true;}
virtual bool end__float4x1____cg_float4x1(){return true;}
virtual bool data__float4x1____cg_float4x1( const float* value, size_t length ){return true;}

virtual bool begin__float4x2____cg_float4x2(){return true;}
virtual bool end__float4x2____cg_float4x2(){return true;}
virtual bool data__float4x2____cg_float4x2( const float* value, size_t length ){return true;}

virtual bool begin__float4x3____cg_float4x3(){return true;}
virtual bool end__float4x3____cg_float4x3(){return true;}
virtual bool data__float4x3____cg_float4x3( const float* value, size_t length ){return true;}

virtual bool begin__float4x4____cg_float4x4(){return true;}
virtual bool end__float4x4____cg_float4x4(){return true;}
virtual bool data__float4x4____cg_float4x4( const float* value, size_t length ){return true;}

virtual bool begin__int____cg_int(){return true;}
virtual bool end__int____cg_int(){return true;}
virtual bool data__int____cg_int( sint32 value ){return true;}

virtual bool begin__int1(){return true;}
virtual bool end__int1(){return true;}
virtual bool data__int1( sint32 value ){return true;}

virtual bool begin__int2____cg_int2(){return true;}
virtual bool end__int2____cg_int2(){return true;}
virtual bool data__int2____cg_int2( const sint32* value, size_t length ){return true;}

virtual bool begin__int3____cg_int3(){return true;}
virtual bool end__int3____cg_int3(){return true;}
virtual bool data__int3____cg_int3( const sint32* value, size_t length ){return true;}

virtual bool begin__int4____cg_int4(){return true;}
virtual bool end__int4____cg_int4(){return true;}
virtual bool data__int4____cg_int4( const sint32* value, size_t length ){return true;}

virtual bool begin__int1x1(){return true;}
virtual bool end__int1x1(){return true;}
virtual bool data__int1x1( const sint32* value, size_t length ){return true;}

virtual bool begin__int1x2(){return true;}
virtual bool end__int1x2(){return true;}
virtual bool data__int1x2( const sint32* value, size_t length ){return true;}

virtual bool begin__int1x3(){return true;}
virtual bool end__int1x3(){return true;}
virtual bool data__int1x3( const sint32* value, size_t length ){return true;}

virtual bool begin__int1x4(){return true;}
virtual bool end__int1x4(){return true;}
virtual bool data__int1x4( const sint32* value, size_t length ){return true;}

virtual bool begin__int2x1(){return true;}
virtual bool end__int2x1(){return true;}
virtual bool data__int2x1( const sint32* value, size_t length ){return true;}

virtual bool begin__int2x2(){return true;}
virtual bool end__int2x2(){return true;}
virtual bool data__int2x2( const sint32* value, size_t length ){return true;}

virtual bool begin__int2x3(){return true;}
virtual bool end__int2x3(){return true;}
virtual bool data__int2x3( const sint32* value, size_t length ){return true;}

virtual bool begin__int2x4(){return true;}
virtual bool end__int2x4(){return true;}
virtual bool data__int2x4( const sint32* value, size_t length ){return true;}

virtual bool begin__int3x1(){return true;}
virtual bool end__int3x1(){return true;}
virtual bool data__int3x1( const sint32* value, size_t length ){return true;}

virtual bool begin__int3x2(){return true;}
virtual bool end__int3x2(){return true;}
virtual bool data__int3x2( const sint32* value, size_t length ){return true;}

virtual bool begin__int3x3(){return true;}
virtual bool end__int3x3(){return true;}
virtual bool data__int3x3( const sint32* value, size_t length ){return true;}

virtual bool begin__int3x4(){return true;}
virtual bool end__int3x4(){return true;}
virtual bool data__int3x4( const sint32* value, size_t length ){return true;}

virtual bool begin__int4x1(){return true;}
virtual bool end__int4x1(){return true;}
virtual bool data__int4x1( const sint32* value, size_t length ){return true;}

virtual bool begin__int4x2(){return true;}
virtual bool end__int4x2(){return true;}
virtual bool data__int4x2( const sint32* value, size_t length ){return true;}

virtual bool begin__int4x3(){return true;}
virtual bool end__int4x3(){return true;}
virtual bool data__int4x3( const sint32* value, size_t length ){return true;}

virtual bool begin__int4x4(){return true;}
virtual bool end__int4x4(){return true;}
virtual bool data__int4x4( const sint32* value, size_t length ){return true;}

virtual bool begin__half(){return true;}
virtual bool end__half(){return true;}
virtual bool data__half( float value ){return true;}

virtual bool begin__half1(){return true;}
virtual bool end__half1(){return true;}
virtual bool data__half1( float value ){return true;}

virtual bool begin__half2(){return true;}
virtual bool end__half2(){return true;}
virtual bool data__half2( const float* value, size_t length ){return true;}

virtual bool begin__half3(){return true;}
virtual bool end__half3(){return true;}
virtual bool data__half3( const float* value, size_t length ){return true;}

virtual bool begin__half4(){return true;}
virtual bool end__half4(){return true;}
virtual bool data__half4( const float* value, size_t length ){return true;}

virtual bool begin__half1x1(){return true;}
virtual bool end__half1x1(){return true;}
virtual bool data__half1x1( const float* value, size_t length ){return true;}

virtual bool begin__half1x2(){return true;}
virtual bool end__half1x2(){return true;}
virtual bool data__half1x2( const float* value, size_t length ){return true;}

virtual bool begin__half1x3(){return true;}
virtual bool end__half1x3(){return true;}
virtual bool data__half1x3( const float* value, size_t length ){return true;}

virtual bool begin__half1x4(){return true;}
virtual bool end__half1x4(){return true;}
virtual bool data__half1x4( const float* value, size_t length ){return true;}

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

virtual bool begin__fixed1(){return true;}
virtual bool end__fixed1(){return true;}
virtual bool data__fixed1( float value ){return true;}

virtual bool begin__fixed2(){return true;}
virtual bool end__fixed2(){return true;}
virtual bool data__fixed2( const float* value, size_t length ){return true;}

virtual bool begin__fixed3(){return true;}
virtual bool end__fixed3(){return true;}
virtual bool data__fixed3( const float* value, size_t length ){return true;}

virtual bool begin__fixed4(){return true;}
virtual bool end__fixed4(){return true;}
virtual bool data__fixed4( const float* value, size_t length ){return true;}

virtual bool begin__fixed1x1(){return true;}
virtual bool end__fixed1x1(){return true;}
virtual bool data__fixed1x1( const float* value, size_t length ){return true;}

virtual bool begin__fixed1x2(){return true;}
virtual bool end__fixed1x2(){return true;}
virtual bool data__fixed1x2( const float* value, size_t length ){return true;}

virtual bool begin__fixed1x3(){return true;}
virtual bool end__fixed1x3(){return true;}
virtual bool data__fixed1x3( const float* value, size_t length ){return true;}

virtual bool begin__fixed1x4(){return true;}
virtual bool end__fixed1x4(){return true;}
virtual bool data__fixed1x4( const float* value, size_t length ){return true;}

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

virtual bool begin__surface____cg_surface_type( const surface____cg_surface_type__AttributeData& attributeData ){return true;}
virtual bool end__surface____cg_surface_type(){return true;}

virtual bool begin__cg_surface_type____generator(){return true;}
virtual bool end__cg_surface_type____generator(){return true;}

virtual bool begin__profile_CG__newparam__surface__generator__name( const profile_CG__newparam__surface__generator__name__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__newparam__surface__generator__name(){return true;}
virtual bool data__profile_CG__newparam__surface__generator__name( const ParserChar* value, size_t length ){return true;}

virtual bool begin__setparam____cg_setparam_simple( const setparam____cg_setparam_simple__AttributeData& attributeData ){return true;}
virtual bool end__setparam____cg_setparam_simple(){return true;}

virtual bool begin__sampler1D____cg_sampler1D(){return true;}
virtual bool end__sampler1D____cg_sampler1D(){return true;}

virtual bool begin__sampler2D____cg_sampler2D(){return true;}
virtual bool end__sampler2D____cg_sampler2D(){return true;}

virtual bool begin__sampler3D____cg_sampler3D(){return true;}
virtual bool end__sampler3D____cg_sampler3D(){return true;}

virtual bool begin__samplerRECT____cg_samplerRECT(){return true;}
virtual bool end__samplerRECT____cg_samplerRECT(){return true;}

virtual bool begin__samplerCUBE____cg_samplerCUBE(){return true;}
virtual bool end__samplerCUBE____cg_samplerCUBE(){return true;}

virtual bool begin__samplerDEPTH____cg_samplerDEPTH(){return true;}
virtual bool end__samplerDEPTH____cg_samplerDEPTH(){return true;}

virtual bool begin__usertype( const usertype__AttributeData& attributeData ){return true;}
virtual bool end__usertype(){return true;}

virtual bool begin__array____cg_setarray_type( const array____cg_setarray_type__AttributeData& attributeData ){return true;}
virtual bool end__array____cg_setarray_type(){return true;}

virtual bool begin__connect_param( const connect_param__AttributeData& attributeData ){return true;}
virtual bool end__connect_param(){return true;}

virtual bool begin__setparam____cg_setparam( const setparam____cg_setparam__AttributeData& attributeData ){return true;}
virtual bool end__setparam____cg_setparam(){return true;}

virtual bool begin__array____cg_newarray_type( const array____cg_newarray_type__AttributeData& attributeData ){return true;}
virtual bool end__array____cg_newarray_type(){return true;}

virtual bool begin__profile_CG__technique( const profile_CG__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique(){return true;}

virtual bool begin__profile_CG__technique__pass( const profile_CG__technique__pass__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass(){return true;}

virtual bool begin__profile_CG__technique__pass__shader( const profile_CG__technique__pass__shader__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__shader(){return true;}

virtual bool begin__profile_CG__technique__pass__shader__compiler_target(){return true;}
virtual bool end__profile_CG__technique__pass__shader__compiler_target(){return true;}
virtual bool data__profile_CG__technique__pass__shader__compiler_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_CG__technique__pass__shader__name( const profile_CG__technique__pass__shader__name__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__shader__name(){return true;}
virtual bool data__profile_CG__technique__pass__shader__name( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_CG__technique__pass__shader__bind( const profile_CG__technique__pass__shader__bind__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__shader__bind(){return true;}

virtual bool begin__profile_CG__technique__pass__shader__bind__param( const profile_CG__technique__pass__shader__bind__param__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique__pass__shader__bind__param(){return true;}

virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON(){return true;}

virtual bool begin__newparam____common_newparam_type( const newparam____common_newparam_type__AttributeData& attributeData ){return true;}
virtual bool end__newparam____common_newparam_type(){return true;}

virtual bool begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON__technique(){return true;}

virtual bool begin__profile_COMMON__technique__constant(){return true;}
virtual bool end__profile_COMMON__technique__constant(){return true;}

virtual bool begin__emission(){return true;}
virtual bool end__emission(){return true;}

virtual bool begin__common_color_or_texture_type____color( const common_color_or_texture_type____color__AttributeData& attributeData ){return true;}
virtual bool end__common_color_or_texture_type____color(){return true;}
virtual bool data__common_color_or_texture_type____color( const float* value, size_t length ){return true;}

virtual bool begin__common_color_or_texture_type____param( const common_color_or_texture_type____param__AttributeData& attributeData ){return true;}
virtual bool end__common_color_or_texture_type____param(){return true;}

virtual bool begin__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__texture(){return true;}

virtual bool begin__reflective(){return true;}
virtual bool end__reflective(){return true;}

virtual bool begin__reflectivity(){return true;}
virtual bool end__reflectivity(){return true;}

virtual bool begin__common_float_or_param_type____float( const common_float_or_param_type____float__AttributeData& attributeData ){return true;}
virtual bool end__common_float_or_param_type____float(){return true;}
virtual bool data__common_float_or_param_type____float( float value ){return true;}

virtual bool begin__common_float_or_param_type____param( const common_float_or_param_type____param__AttributeData& attributeData ){return true;}
virtual bool end__common_float_or_param_type____param(){return true;}

virtual bool begin__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__transparent(){return true;}

virtual bool begin__transparency(){return true;}
virtual bool end__transparency(){return true;}

virtual bool begin__index_of_refraction(){return true;}
virtual bool end__index_of_refraction(){return true;}

virtual bool begin__lambert(){return true;}
virtual bool end__lambert(){return true;}

virtual bool begin__ambient____common_color_or_texture_type(){return true;}
virtual bool end__ambient____common_color_or_texture_type(){return true;}

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



private:
/** Disable default copy ctor. */
ColladaParserAutoGen14( const ColladaParserAutoGen14& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen14& operator= ( const ColladaParserAutoGen14& pre );

};

} // namespace
#endif
