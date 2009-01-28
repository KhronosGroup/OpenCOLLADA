/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGEN_H__


#include "COLLADASaxFWLColladaParserAutoGenAttributes.h"


namespace COLLADASaxFWL
{


class ColladaParserAutoGen
{
public:
ColladaParserAutoGen(){}
virtual ~ColladaParserAutoGen(){}


virtual bool begin__COLLADA( const COLLADA__AttributeData& attributeData ){return true;}
virtual bool end__COLLADA(){return true;}

virtual bool begin__COLLADA__asset(){return true;}
virtual bool end__COLLADA__asset(){return true;}

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
virtual bool data__source_data( const ParserChar* value, size_t length ){return true;}

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
virtual bool data__up_axis( const ParserChar* value, size_t length ){return true;}

virtual bool begin__library_animations( const library_animations__AttributeData& attributeData ){return true;}
virtual bool end__library_animations(){return true;}

virtual bool begin__library_animations__asset(){return true;}
virtual bool end__library_animations__asset(){return true;}

virtual bool begin__library_animations__animation( const animation__AttributeData& attributeData ){return true;}
virtual bool end__library_animations__animation(){return true;}

virtual bool begin__animation__asset(){return true;}
virtual bool end__animation__asset(){return true;}

virtual bool begin__animation__source( const animation__source__AttributeData& attributeData ){return true;}
virtual bool end__animation__source(){return true;}

virtual bool begin__source__asset(){return true;}
virtual bool end__source__asset(){return true;}

virtual bool begin__IDREF_array( const IDREF_array__AttributeData& attributeData ){return true;}
virtual bool end__IDREF_array(){return true;}
virtual bool data__IDREF_array( const ParserChar* value, size_t length ){return true;}

virtual bool begin__Name_array( const Name_array__AttributeData& attributeData ){return true;}
virtual bool end__Name_array(){return true;}
virtual bool data__Name_array( const ParserChar* value, size_t length ){return true;}

virtual bool begin__bool_array( const bool_array__AttributeData& attributeData ){return true;}
virtual bool end__bool_array(){return true;}
virtual bool data__bool_array( const bool* value, size_t length ){return true;}

virtual bool begin__float_array( const float_array__AttributeData& attributeData ){return true;}
virtual bool end__float_array(){return true;}
virtual bool data__float_array( const double* value, size_t length ){return true;}

virtual bool begin__int_array( const int_array__AttributeData& attributeData ){return true;}
virtual bool end__int_array(){return true;}
virtual bool data__int_array( const long* value, size_t length ){return true;}

virtual bool begin__source__technique_common(){return true;}
virtual bool end__source__technique_common(){return true;}

virtual bool begin__accessor( const accessor__AttributeData& attributeData ){return true;}
virtual bool end__accessor(){return true;}

virtual bool begin__accessor__param( const accessor__param__AttributeData& attributeData ){return true;}
virtual bool end__accessor__param(){return true;}
virtual bool data__accessor__param( const ParserChar* value, size_t length ){return true;}

virtual bool begin__source__technique( const source__technique__AttributeData& attributeData ){return true;}
virtual bool end__source__technique(){return true;}

virtual bool begin__sampler( const sampler__AttributeData& attributeData ){return true;}
virtual bool end__sampler(){return true;}

virtual bool begin__sampler__input( const sampler__input__AttributeData& attributeData ){return true;}
virtual bool end__sampler__input(){return true;}

virtual bool begin__channel( const channel__AttributeData& attributeData ){return true;}
virtual bool end__channel(){return true;}

virtual bool begin__animation__animation( const animation__AttributeData& attributeData ){return true;}
virtual bool end__animation__animation(){return true;}

virtual bool begin__animation__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__animation__extra(){return true;}

virtual bool begin__extra__asset(){return true;}
virtual bool end__extra__asset(){return true;}

virtual bool begin__extra__technique( const extra__technique__AttributeData& attributeData ){return true;}
virtual bool end__extra__technique(){return true;}

virtual bool begin__library_animations__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_animations__extra(){return true;}

virtual bool begin__library_animation_clips( const library_animation_clips__AttributeData& attributeData ){return true;}
virtual bool end__library_animation_clips(){return true;}

virtual bool begin__library_animation_clips__asset(){return true;}
virtual bool end__library_animation_clips__asset(){return true;}

virtual bool begin__animation_clip( const animation_clip__AttributeData& attributeData ){return true;}
virtual bool end__animation_clip(){return true;}

virtual bool begin__animation_clip__asset(){return true;}
virtual bool end__animation_clip__asset(){return true;}

virtual bool begin__instance_animation( const instance_animation__AttributeData& attributeData ){return true;}
virtual bool end__instance_animation(){return true;}

virtual bool begin__instance_animation__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_animation__extra(){return true;}

virtual bool begin__animation_clip__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__animation_clip__extra(){return true;}

virtual bool begin__library_animation_clips__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_animation_clips__extra(){return true;}

virtual bool begin__library_cameras( const library_cameras__AttributeData& attributeData ){return true;}
virtual bool end__library_cameras(){return true;}

virtual bool begin__library_cameras__asset(){return true;}
virtual bool end__library_cameras__asset(){return true;}

virtual bool begin__camera( const camera__AttributeData& attributeData ){return true;}
virtual bool end__camera(){return true;}

virtual bool begin__camera__asset(){return true;}
virtual bool end__camera__asset(){return true;}

virtual bool begin__optics(){return true;}
virtual bool end__optics(){return true;}

virtual bool begin__optics__technique_common(){return true;}
virtual bool end__optics__technique_common(){return true;}

virtual bool begin__orthographic(){return true;}
virtual bool end__orthographic(){return true;}

virtual bool begin__xmag( const xmag__AttributeData& attributeData ){return true;}
virtual bool end__xmag(){return true;}
virtual bool data__xmag( double value ){return true;}

virtual bool begin__ymag( const ymag__AttributeData& attributeData ){return true;}
virtual bool end__ymag(){return true;}
virtual bool data__ymag( double value ){return true;}

virtual bool begin__orthographic__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){return true;}
virtual bool end__orthographic__aspect_ratio(){return true;}
virtual bool data__orthographic__aspect_ratio( double value ){return true;}

virtual bool begin__orthographic__znear( const znear__AttributeData& attributeData ){return true;}
virtual bool end__orthographic__znear(){return true;}
virtual bool data__orthographic__znear( double value ){return true;}

virtual bool begin__orthographic__zfar( const zfar__AttributeData& attributeData ){return true;}
virtual bool end__orthographic__zfar(){return true;}
virtual bool data__orthographic__zfar( double value ){return true;}

virtual bool begin__perspective(){return true;}
virtual bool end__perspective(){return true;}

virtual bool begin__xfov( const xfov__AttributeData& attributeData ){return true;}
virtual bool end__xfov(){return true;}
virtual bool data__xfov( double value ){return true;}

virtual bool begin__yfov( const yfov__AttributeData& attributeData ){return true;}
virtual bool end__yfov(){return true;}
virtual bool data__yfov( double value ){return true;}

virtual bool begin__perspective__aspect_ratio( const aspect_ratio__AttributeData& attributeData ){return true;}
virtual bool end__perspective__aspect_ratio(){return true;}
virtual bool data__perspective__aspect_ratio( double value ){return true;}

virtual bool begin__perspective__znear( const znear__AttributeData& attributeData ){return true;}
virtual bool end__perspective__znear(){return true;}
virtual bool data__perspective__znear( double value ){return true;}

virtual bool begin__perspective__zfar( const zfar__AttributeData& attributeData ){return true;}
virtual bool end__perspective__zfar(){return true;}
virtual bool data__perspective__zfar( double value ){return true;}

virtual bool begin__optics__technique( const optics__technique__AttributeData& attributeData ){return true;}
virtual bool end__optics__technique(){return true;}

virtual bool begin__optics__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__optics__extra(){return true;}

virtual bool begin__imager(){return true;}
virtual bool end__imager(){return true;}

virtual bool begin__imager__technique( const imager__technique__AttributeData& attributeData ){return true;}
virtual bool end__imager__technique(){return true;}

virtual bool begin__imager__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__imager__extra(){return true;}

virtual bool begin__camera__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__camera__extra(){return true;}

virtual bool begin__library_cameras__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_cameras__extra(){return true;}

virtual bool begin__library_controllers( const library_controllers__AttributeData& attributeData ){return true;}
virtual bool end__library_controllers(){return true;}

virtual bool begin__library_controllers__asset(){return true;}
virtual bool end__library_controllers__asset(){return true;}

virtual bool begin__controller( const controller__AttributeData& attributeData ){return true;}
virtual bool end__controller(){return true;}

virtual bool begin__controller__asset(){return true;}
virtual bool end__controller__asset(){return true;}

virtual bool begin__skin( const skin__AttributeData& attributeData ){return true;}
virtual bool end__skin(){return true;}

virtual bool begin__bind_shape_matrix(){return true;}
virtual bool end__bind_shape_matrix(){return true;}
virtual bool data__bind_shape_matrix( const double* value, size_t length ){return true;}

virtual bool begin__skin__source( const skin__source__AttributeData& attributeData ){return true;}
virtual bool end__skin__source(){return true;}

virtual bool begin__joints(){return true;}
virtual bool end__joints(){return true;}

virtual bool begin__joints__input( const joints__input__AttributeData& attributeData ){return true;}
virtual bool end__joints__input(){return true;}

virtual bool begin__joints__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__joints__extra(){return true;}

virtual bool begin__vertex_weights( const vertex_weights__AttributeData& attributeData ){return true;}
virtual bool end__vertex_weights(){return true;}

virtual bool begin__vertex_weights__input( const vertex_weights__input__AttributeData& attributeData ){return true;}
virtual bool end__vertex_weights__input(){return true;}

virtual bool begin__vertex_weights__vcount(){return true;}
virtual bool end__vertex_weights__vcount(){return true;}
virtual bool data__vertex_weights__vcount( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__v(){return true;}
virtual bool end__v(){return true;}
virtual bool data__v( const long* value, size_t length ){return true;}

virtual bool begin__vertex_weights__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__vertex_weights__extra(){return true;}

virtual bool begin__skin__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__skin__extra(){return true;}

virtual bool begin__morph( const morph__AttributeData& attributeData ){return true;}
virtual bool end__morph(){return true;}

virtual bool begin__morph__source( const morph__source__AttributeData& attributeData ){return true;}
virtual bool end__morph__source(){return true;}

virtual bool begin__targets(){return true;}
virtual bool end__targets(){return true;}

virtual bool begin__targets__input( const targets__input__AttributeData& attributeData ){return true;}
virtual bool end__targets__input(){return true;}

virtual bool begin__targets__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__targets__extra(){return true;}

virtual bool begin__morph__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__morph__extra(){return true;}

virtual bool begin__controller__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__controller__extra(){return true;}

virtual bool begin__library_controllers__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_controllers__extra(){return true;}

virtual bool begin__library_geometries( const library_geometries__AttributeData& attributeData ){return true;}
virtual bool end__library_geometries(){return true;}

virtual bool begin__library_geometries__asset(){return true;}
virtual bool end__library_geometries__asset(){return true;}

virtual bool begin__geometry( const geometry__AttributeData& attributeData ){return true;}
virtual bool end__geometry(){return true;}

virtual bool begin__geometry__asset(){return true;}
virtual bool end__geometry__asset(){return true;}

virtual bool begin__convex_mesh( const convex_mesh__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh(){return true;}

virtual bool begin__convex_mesh__source( const convex_mesh__source__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__source(){return true;}

virtual bool begin__convex_mesh__vertices( const vertices__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__vertices(){return true;}

virtual bool begin__vertices__input( const vertices__input__AttributeData& attributeData ){return true;}
virtual bool end__vertices__input(){return true;}

virtual bool begin__vertices__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__vertices__extra(){return true;}

virtual bool begin__convex_mesh__lines( const lines__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__lines(){return true;}

virtual bool begin__lines__input( const lines__input__AttributeData& attributeData ){return true;}
virtual bool end__lines__input(){return true;}

virtual bool begin__lines__p(){return true;}
virtual bool end__lines__p(){return true;}
virtual bool data__lines__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__lines__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__lines__extra(){return true;}

virtual bool begin__convex_mesh__linestrips( const linestrips__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__linestrips(){return true;}

virtual bool begin__linestrips__input( const linestrips__input__AttributeData& attributeData ){return true;}
virtual bool end__linestrips__input(){return true;}

virtual bool begin__linestrips__p(){return true;}
virtual bool end__linestrips__p(){return true;}
virtual bool data__linestrips__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__linestrips__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__linestrips__extra(){return true;}

virtual bool begin__convex_mesh__polygons( const polygons__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__polygons(){return true;}

virtual bool begin__polygons__input( const polygons__input__AttributeData& attributeData ){return true;}
virtual bool end__polygons__input(){return true;}

virtual bool begin__polygons__p(){return true;}
virtual bool end__polygons__p(){return true;}
virtual bool data__polygons__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__ph(){return true;}
virtual bool end__ph(){return true;}

virtual bool begin__ph__p(){return true;}
virtual bool end__ph__p(){return true;}
virtual bool data__ph__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__h(){return true;}
virtual bool end__h(){return true;}
virtual bool data__h( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__polygons__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__polygons__extra(){return true;}

virtual bool begin__convex_mesh__polylist( const polylist__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__polylist(){return true;}

virtual bool begin__polylist__input( const polylist__input__AttributeData& attributeData ){return true;}
virtual bool end__polylist__input(){return true;}

virtual bool begin__polylist__vcount(){return true;}
virtual bool end__polylist__vcount(){return true;}
virtual bool data__polylist__vcount( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__polylist__p(){return true;}
virtual bool end__polylist__p(){return true;}
virtual bool data__polylist__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__polylist__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__polylist__extra(){return true;}

virtual bool begin__convex_mesh__triangles( const triangles__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__triangles(){return true;}

virtual bool begin__triangles__input( const triangles__input__AttributeData& attributeData ){return true;}
virtual bool end__triangles__input(){return true;}

virtual bool begin__triangles__p(){return true;}
virtual bool end__triangles__p(){return true;}
virtual bool data__triangles__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__triangles__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__triangles__extra(){return true;}

virtual bool begin__convex_mesh__trifans( const trifans__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__trifans(){return true;}

virtual bool begin__trifans__input( const trifans__input__AttributeData& attributeData ){return true;}
virtual bool end__trifans__input(){return true;}

virtual bool begin__trifans__p(){return true;}
virtual bool end__trifans__p(){return true;}
virtual bool data__trifans__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__trifans__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__trifans__extra(){return true;}

virtual bool begin__convex_mesh__tristrips( const tristrips__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__tristrips(){return true;}

virtual bool begin__tristrips__input( const tristrips__input__AttributeData& attributeData ){return true;}
virtual bool end__tristrips__input(){return true;}

virtual bool begin__tristrips__p(){return true;}
virtual bool end__tristrips__p(){return true;}
virtual bool data__tristrips__p( const unsigned long long* value, size_t length ){return true;}

virtual bool begin__tristrips__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__tristrips__extra(){return true;}

virtual bool begin__convex_mesh__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__convex_mesh__extra(){return true;}

virtual bool begin__mesh(){return true;}
virtual bool end__mesh(){return true;}

virtual bool begin__mesh__source( const mesh__source__AttributeData& attributeData ){return true;}
virtual bool end__mesh__source(){return true;}

virtual bool begin__mesh__vertices( const vertices__AttributeData& attributeData ){return true;}
virtual bool end__mesh__vertices(){return true;}

virtual bool begin__mesh__lines( const lines__AttributeData& attributeData ){return true;}
virtual bool end__mesh__lines(){return true;}

virtual bool begin__mesh__linestrips( const linestrips__AttributeData& attributeData ){return true;}
virtual bool end__mesh__linestrips(){return true;}

virtual bool begin__mesh__polygons( const polygons__AttributeData& attributeData ){return true;}
virtual bool end__mesh__polygons(){return true;}

virtual bool begin__mesh__polylist( const polylist__AttributeData& attributeData ){return true;}
virtual bool end__mesh__polylist(){return true;}

virtual bool begin__mesh__triangles( const triangles__AttributeData& attributeData ){return true;}
virtual bool end__mesh__triangles(){return true;}

virtual bool begin__mesh__trifans( const trifans__AttributeData& attributeData ){return true;}
virtual bool end__mesh__trifans(){return true;}

virtual bool begin__mesh__tristrips( const tristrips__AttributeData& attributeData ){return true;}
virtual bool end__mesh__tristrips(){return true;}

virtual bool begin__mesh__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__mesh__extra(){return true;}

virtual bool begin__spline( const spline__AttributeData& attributeData ){return true;}
virtual bool end__spline(){return true;}

virtual bool begin__spline__source( const spline__source__AttributeData& attributeData ){return true;}
virtual bool end__spline__source(){return true;}

virtual bool begin__control_vertices(){return true;}
virtual bool end__control_vertices(){return true;}

virtual bool begin__control_vertices__input( const control_vertices__input__AttributeData& attributeData ){return true;}
virtual bool end__control_vertices__input(){return true;}

virtual bool begin__control_vertices__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__control_vertices__extra(){return true;}

virtual bool begin__spline__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__spline__extra(){return true;}

virtual bool begin__geometry__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__geometry__extra(){return true;}

virtual bool begin__library_geometries__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_geometries__extra(){return true;}

virtual bool begin__library_effects( const library_effects__AttributeData& attributeData ){return true;}
virtual bool end__library_effects(){return true;}

virtual bool begin__library_effects__asset(){return true;}
virtual bool end__library_effects__asset(){return true;}

virtual bool begin__effect( const effect__AttributeData& attributeData ){return true;}
virtual bool end__effect(){return true;}

virtual bool begin__effect__asset(){return true;}
virtual bool end__effect__asset(){return true;}

virtual bool begin__effect__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__effect__annotate(){return true;}

virtual bool begin__annotate__bool(){return true;}
virtual bool end__annotate__bool(){return true;}
virtual bool data__annotate__bool( bool value ){return true;}

virtual bool begin__annotate__bool2(){return true;}
virtual bool end__annotate__bool2(){return true;}
virtual bool data__annotate__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__annotate__bool3(){return true;}
virtual bool end__annotate__bool3(){return true;}
virtual bool data__annotate__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__annotate__bool4(){return true;}
virtual bool end__annotate__bool4(){return true;}
virtual bool data__annotate__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__annotate__int(){return true;}
virtual bool end__annotate__int(){return true;}
virtual bool data__annotate__int( long value ){return true;}

virtual bool begin__annotate__int2(){return true;}
virtual bool end__annotate__int2(){return true;}
virtual bool data__annotate__int2( const long* value, size_t length ){return true;}

virtual bool begin__annotate__int3(){return true;}
virtual bool end__annotate__int3(){return true;}
virtual bool data__annotate__int3( const long* value, size_t length ){return true;}

virtual bool begin__annotate__int4(){return true;}
virtual bool end__annotate__int4(){return true;}
virtual bool data__annotate__int4( const long* value, size_t length ){return true;}

virtual bool begin__annotate__float(){return true;}
virtual bool end__annotate__float(){return true;}
virtual bool data__annotate__float( double value ){return true;}

virtual bool begin__annotate__float2(){return true;}
virtual bool end__annotate__float2(){return true;}
virtual bool data__annotate__float2( const double* value, size_t length ){return true;}

virtual bool begin__annotate__float3(){return true;}
virtual bool end__annotate__float3(){return true;}
virtual bool data__annotate__float3( const double* value, size_t length ){return true;}

virtual bool begin__annotate__float4(){return true;}
virtual bool end__annotate__float4(){return true;}
virtual bool data__annotate__float4( const double* value, size_t length ){return true;}

virtual bool begin__annotate__float2x2(){return true;}
virtual bool end__annotate__float2x2(){return true;}
virtual bool data__annotate__float2x2( const double* value, size_t length ){return true;}

virtual bool begin__annotate__float3x3(){return true;}
virtual bool end__annotate__float3x3(){return true;}
virtual bool data__annotate__float3x3( const double* value, size_t length ){return true;}

virtual bool begin__annotate__float4x4(){return true;}
virtual bool end__annotate__float4x4(){return true;}
virtual bool data__annotate__float4x4( const double* value, size_t length ){return true;}

virtual bool begin__annotate__string(){return true;}
virtual bool end__annotate__string(){return true;}
virtual bool data__annotate__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__effect__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__effect__image(){return true;}

virtual bool begin__image__asset(){return true;}
virtual bool end__image__asset(){return true;}

virtual bool begin__data(){return true;}
virtual bool end__data(){return true;}
virtual bool data__data( const ParserChar* value, size_t length ){return true;}

virtual bool begin__image__init_from(){return true;}
virtual bool end__image__init_from(){return true;}
virtual bool data__image__init_from( const ParserChar* value, size_t length ){return true;}

virtual bool begin__image__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__image__extra(){return true;}

virtual bool begin__effect__newparam( const effect__newparam__AttributeData& attributeData ){return true;}
virtual bool end__effect__newparam(){return true;}

virtual bool begin__newparam__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__newparam__annotate(){return true;}

virtual bool begin__semantic(){return true;}
virtual bool end__semantic(){return true;}
virtual bool data__semantic( const ParserChar* value, size_t length ){return true;}

virtual bool begin__modifier(){return true;}
virtual bool end__modifier(){return true;}
virtual bool data__modifier( const ParserChar* value, size_t length ){return true;}

virtual bool begin__newparam__bool(){return true;}
virtual bool end__newparam__bool(){return true;}
virtual bool data__newparam__bool( bool value ){return true;}

virtual bool begin__newparam__bool2(){return true;}
virtual bool end__newparam__bool2(){return true;}
virtual bool data__newparam__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool3(){return true;}
virtual bool end__newparam__bool3(){return true;}
virtual bool data__newparam__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool4(){return true;}
virtual bool end__newparam__bool4(){return true;}
virtual bool data__newparam__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__int(){return true;}
virtual bool end__newparam__int(){return true;}
virtual bool data__newparam__int( long value ){return true;}

virtual bool begin__newparam__int2(){return true;}
virtual bool end__newparam__int2(){return true;}
virtual bool data__newparam__int2( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int3(){return true;}
virtual bool end__newparam__int3(){return true;}
virtual bool data__newparam__int3( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int4(){return true;}
virtual bool end__newparam__int4(){return true;}
virtual bool data__newparam__int4( const long* value, size_t length ){return true;}

virtual bool begin__newparam__float(){return true;}
virtual bool end__newparam__float(){return true;}
virtual bool data__newparam__float( double value ){return true;}

virtual bool begin__newparam__float2(){return true;}
virtual bool end__newparam__float2(){return true;}
virtual bool data__newparam__float2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float3(){return true;}
virtual bool end__newparam__float3(){return true;}
virtual bool data__newparam__float3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float4(){return true;}
virtual bool end__newparam__float4(){return true;}
virtual bool data__newparam__float4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float1x1(){return true;}
virtual bool end__newparam__float1x1(){return true;}
virtual bool data__newparam__float1x1( double value ){return true;}

virtual bool begin__newparam__float1x2(){return true;}
virtual bool end__newparam__float1x2(){return true;}
virtual bool data__newparam__float1x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float1x3(){return true;}
virtual bool end__newparam__float1x3(){return true;}
virtual bool data__newparam__float1x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float1x4(){return true;}
virtual bool end__newparam__float1x4(){return true;}
virtual bool data__newparam__float1x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float2x1(){return true;}
virtual bool end__newparam__float2x1(){return true;}
virtual bool data__newparam__float2x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float2x2(){return true;}
virtual bool end__newparam__float2x2(){return true;}
virtual bool data__newparam__float2x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float2x3(){return true;}
virtual bool end__newparam__float2x3(){return true;}
virtual bool data__newparam__float2x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float2x4(){return true;}
virtual bool end__newparam__float2x4(){return true;}
virtual bool data__newparam__float2x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float3x1(){return true;}
virtual bool end__newparam__float3x1(){return true;}
virtual bool data__newparam__float3x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float3x2(){return true;}
virtual bool end__newparam__float3x2(){return true;}
virtual bool data__newparam__float3x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float3x3(){return true;}
virtual bool end__newparam__float3x3(){return true;}
virtual bool data__newparam__float3x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float3x4(){return true;}
virtual bool end__newparam__float3x4(){return true;}
virtual bool data__newparam__float3x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float4x1(){return true;}
virtual bool end__newparam__float4x1(){return true;}
virtual bool data__newparam__float4x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float4x2(){return true;}
virtual bool end__newparam__float4x2(){return true;}
virtual bool data__newparam__float4x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float4x3(){return true;}
virtual bool end__newparam__float4x3(){return true;}
virtual bool data__newparam__float4x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__float4x4(){return true;}
virtual bool end__newparam__float4x4(){return true;}
virtual bool data__newparam__float4x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__surface( const newparam__surface__AttributeData& attributeData ){return true;}
virtual bool end__newparam__surface(){return true;}

virtual bool begin__init_as_null(){return true;}
virtual bool end__init_as_null(){return true;}
virtual bool data__init_as_null( const ParserChar* value, size_t length ){return true;}

virtual bool begin__init_as_target(){return true;}
virtual bool end__init_as_target(){return true;}
virtual bool data__init_as_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__init_cube(){return true;}
virtual bool end__init_cube(){return true;}

virtual bool begin__init_cube__all( const init_cube__all__AttributeData& attributeData ){return true;}
virtual bool end__init_cube__all(){return true;}

virtual bool begin__init_cube__primary( const init_cube__primary__AttributeData& attributeData ){return true;}
virtual bool end__init_cube__primary(){return true;}

virtual bool begin__order(){return true;}
virtual bool end__order(){return true;}
virtual bool data__order( const ParserChar* value, size_t length ){return true;}

virtual bool begin__init_cube__face( const init_cube__face__AttributeData& attributeData ){return true;}
virtual bool end__init_cube__face(){return true;}

virtual bool begin__init_volume(){return true;}
virtual bool end__init_volume(){return true;}

virtual bool begin__init_volume__all( const init_volume__all__AttributeData& attributeData ){return true;}
virtual bool end__init_volume__all(){return true;}

virtual bool begin__init_volume__primary( const init_volume__primary__AttributeData& attributeData ){return true;}
virtual bool end__init_volume__primary(){return true;}

virtual bool begin__init_planar(){return true;}
virtual bool end__init_planar(){return true;}

virtual bool begin__init_planar__all( const init_planar__all__AttributeData& attributeData ){return true;}
virtual bool end__init_planar__all(){return true;}

virtual bool begin__surface__init_from( const surface__init_from__AttributeData& attributeData ){return true;}
virtual bool end__surface__init_from(){return true;}
virtual bool data__surface__init_from( const ParserChar* value, size_t length ){return true;}

virtual bool begin__format(){return true;}
virtual bool end__format(){return true;}
virtual bool data__format( const ParserChar* value, size_t length ){return true;}

virtual bool begin__format_hint(){return true;}
virtual bool end__format_hint(){return true;}

virtual bool begin__channels(){return true;}
virtual bool end__channels(){return true;}
virtual bool data__channels( const ParserChar* value, size_t length ){return true;}

virtual bool begin__range(){return true;}
virtual bool end__range(){return true;}
virtual bool data__range( const ParserChar* value, size_t length ){return true;}

virtual bool begin__precision(){return true;}
virtual bool end__precision(){return true;}
virtual bool data__precision( const ParserChar* value, size_t length ){return true;}

virtual bool begin__option(){return true;}
virtual bool end__option(){return true;}
virtual bool data__option( const ParserChar* value, size_t length ){return true;}

virtual bool begin__format_hint__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__format_hint__extra(){return true;}

virtual bool begin__surface__size(){return true;}
virtual bool end__surface__size(){return true;}
virtual bool data__surface__size( const long* value, size_t length ){return true;}

virtual bool begin__viewport_ratio(){return true;}
virtual bool end__viewport_ratio(){return true;}
virtual bool data__viewport_ratio( const double* value, size_t length ){return true;}

virtual bool begin__mip_levels(){return true;}
virtual bool end__mip_levels(){return true;}
virtual bool data__mip_levels( unsigned long value ){return true;}

virtual bool begin__mipmap_generate(){return true;}
virtual bool end__mipmap_generate(){return true;}
virtual bool data__mipmap_generate( bool value ){return true;}

virtual bool begin__surface__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__surface__extra(){return true;}

virtual bool begin__newparam__sampler1D(){return true;}
virtual bool end__newparam__sampler1D(){return true;}

virtual bool begin__sampler1D__source(){return true;}
virtual bool end__sampler1D__source(){return true;}
virtual bool data__sampler1D__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__wrap_s(){return true;}
virtual bool end__sampler1D__wrap_s(){return true;}
virtual bool data__sampler1D__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__minfilter(){return true;}
virtual bool end__sampler1D__minfilter(){return true;}
virtual bool data__sampler1D__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__magfilter(){return true;}
virtual bool end__sampler1D__magfilter(){return true;}
virtual bool data__sampler1D__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__mipfilter(){return true;}
virtual bool end__sampler1D__mipfilter(){return true;}
virtual bool data__sampler1D__mipfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__border_color(){return true;}
virtual bool end__sampler1D__border_color(){return true;}
virtual bool data__sampler1D__border_color( const double* value, size_t length ){return true;}

virtual bool begin__sampler1D__mipmap_maxlevel(){return true;}
virtual bool end__sampler1D__mipmap_maxlevel(){return true;}
virtual bool data__sampler1D__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__sampler1D__mipmap_bias(){return true;}
virtual bool end__sampler1D__mipmap_bias(){return true;}
virtual bool data__sampler1D__mipmap_bias( double value ){return true;}

virtual bool begin__sampler1D__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__sampler1D__extra(){return true;}

virtual bool begin__newparam__sampler2D(){return true;}
virtual bool end__newparam__sampler2D(){return true;}

virtual bool begin__sampler2D__source(){return true;}
virtual bool end__sampler2D__source(){return true;}
virtual bool data__sampler2D__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__wrap_s(){return true;}
virtual bool end__sampler2D__wrap_s(){return true;}
virtual bool data__sampler2D__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__wrap_t(){return true;}
virtual bool end__sampler2D__wrap_t(){return true;}
virtual bool data__sampler2D__wrap_t( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__minfilter(){return true;}
virtual bool end__sampler2D__minfilter(){return true;}
virtual bool data__sampler2D__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__magfilter(){return true;}
virtual bool end__sampler2D__magfilter(){return true;}
virtual bool data__sampler2D__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__mipfilter(){return true;}
virtual bool end__sampler2D__mipfilter(){return true;}
virtual bool data__sampler2D__mipfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler2D__border_color(){return true;}
virtual bool end__sampler2D__border_color(){return true;}
virtual bool data__sampler2D__border_color( const double* value, size_t length ){return true;}

virtual bool begin__sampler2D__mipmap_maxlevel(){return true;}
virtual bool end__sampler2D__mipmap_maxlevel(){return true;}
virtual bool data__sampler2D__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__sampler2D__mipmap_bias(){return true;}
virtual bool end__sampler2D__mipmap_bias(){return true;}
virtual bool data__sampler2D__mipmap_bias( double value ){return true;}

virtual bool begin__sampler2D__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__sampler2D__extra(){return true;}

virtual bool begin__newparam__sampler3D(){return true;}
virtual bool end__newparam__sampler3D(){return true;}

virtual bool begin__sampler3D__source(){return true;}
virtual bool end__sampler3D__source(){return true;}
virtual bool data__sampler3D__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__wrap_s(){return true;}
virtual bool end__sampler3D__wrap_s(){return true;}
virtual bool data__sampler3D__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__wrap_t(){return true;}
virtual bool end__sampler3D__wrap_t(){return true;}
virtual bool data__sampler3D__wrap_t( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__wrap_p(){return true;}
virtual bool end__sampler3D__wrap_p(){return true;}
virtual bool data__sampler3D__wrap_p( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__minfilter(){return true;}
virtual bool end__sampler3D__minfilter(){return true;}
virtual bool data__sampler3D__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__magfilter(){return true;}
virtual bool end__sampler3D__magfilter(){return true;}
virtual bool data__sampler3D__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__mipfilter(){return true;}
virtual bool end__sampler3D__mipfilter(){return true;}
virtual bool data__sampler3D__mipfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler3D__border_color(){return true;}
virtual bool end__sampler3D__border_color(){return true;}
virtual bool data__sampler3D__border_color( const double* value, size_t length ){return true;}

virtual bool begin__sampler3D__mipmap_maxlevel(){return true;}
virtual bool end__sampler3D__mipmap_maxlevel(){return true;}
virtual bool data__sampler3D__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__sampler3D__mipmap_bias(){return true;}
virtual bool end__sampler3D__mipmap_bias(){return true;}
virtual bool data__sampler3D__mipmap_bias( double value ){return true;}

virtual bool begin__sampler3D__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__sampler3D__extra(){return true;}

virtual bool begin__newparam__samplerCUBE(){return true;}
virtual bool end__newparam__samplerCUBE(){return true;}

virtual bool begin__samplerCUBE__source(){return true;}
virtual bool end__samplerCUBE__source(){return true;}
virtual bool data__samplerCUBE__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__wrap_s(){return true;}
virtual bool end__samplerCUBE__wrap_s(){return true;}
virtual bool data__samplerCUBE__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__wrap_t(){return true;}
virtual bool end__samplerCUBE__wrap_t(){return true;}
virtual bool data__samplerCUBE__wrap_t( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__wrap_p(){return true;}
virtual bool end__samplerCUBE__wrap_p(){return true;}
virtual bool data__samplerCUBE__wrap_p( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__minfilter(){return true;}
virtual bool end__samplerCUBE__minfilter(){return true;}
virtual bool data__samplerCUBE__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__magfilter(){return true;}
virtual bool end__samplerCUBE__magfilter(){return true;}
virtual bool data__samplerCUBE__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__mipfilter(){return true;}
virtual bool end__samplerCUBE__mipfilter(){return true;}
virtual bool data__samplerCUBE__mipfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__border_color(){return true;}
virtual bool end__samplerCUBE__border_color(){return true;}
virtual bool data__samplerCUBE__border_color( const double* value, size_t length ){return true;}

virtual bool begin__samplerCUBE__mipmap_maxlevel(){return true;}
virtual bool end__samplerCUBE__mipmap_maxlevel(){return true;}
virtual bool data__samplerCUBE__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__samplerCUBE__mipmap_bias(){return true;}
virtual bool end__samplerCUBE__mipmap_bias(){return true;}
virtual bool data__samplerCUBE__mipmap_bias( double value ){return true;}

virtual bool begin__samplerCUBE__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__samplerCUBE__extra(){return true;}

virtual bool begin__newparam__samplerRECT(){return true;}
virtual bool end__newparam__samplerRECT(){return true;}

virtual bool begin__samplerRECT__source(){return true;}
virtual bool end__samplerRECT__source(){return true;}
virtual bool data__samplerRECT__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__wrap_s(){return true;}
virtual bool end__samplerRECT__wrap_s(){return true;}
virtual bool data__samplerRECT__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__wrap_t(){return true;}
virtual bool end__samplerRECT__wrap_t(){return true;}
virtual bool data__samplerRECT__wrap_t( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__minfilter(){return true;}
virtual bool end__samplerRECT__minfilter(){return true;}
virtual bool data__samplerRECT__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__magfilter(){return true;}
virtual bool end__samplerRECT__magfilter(){return true;}
virtual bool data__samplerRECT__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__mipfilter(){return true;}
virtual bool end__samplerRECT__mipfilter(){return true;}
virtual bool data__samplerRECT__mipfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerRECT__border_color(){return true;}
virtual bool end__samplerRECT__border_color(){return true;}
virtual bool data__samplerRECT__border_color( const double* value, size_t length ){return true;}

virtual bool begin__samplerRECT__mipmap_maxlevel(){return true;}
virtual bool end__samplerRECT__mipmap_maxlevel(){return true;}
virtual bool data__samplerRECT__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__samplerRECT__mipmap_bias(){return true;}
virtual bool end__samplerRECT__mipmap_bias(){return true;}
virtual bool data__samplerRECT__mipmap_bias( double value ){return true;}

virtual bool begin__samplerRECT__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__samplerRECT__extra(){return true;}

virtual bool begin__newparam__samplerDEPTH(){return true;}
virtual bool end__newparam__samplerDEPTH(){return true;}

virtual bool begin__samplerDEPTH__source(){return true;}
virtual bool end__samplerDEPTH__source(){return true;}
virtual bool data__samplerDEPTH__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerDEPTH__wrap_s(){return true;}
virtual bool end__samplerDEPTH__wrap_s(){return true;}
virtual bool data__samplerDEPTH__wrap_s( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerDEPTH__wrap_t(){return true;}
virtual bool end__samplerDEPTH__wrap_t(){return true;}
virtual bool data__samplerDEPTH__wrap_t( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerDEPTH__minfilter(){return true;}
virtual bool end__samplerDEPTH__minfilter(){return true;}
virtual bool data__samplerDEPTH__minfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerDEPTH__magfilter(){return true;}
virtual bool end__samplerDEPTH__magfilter(){return true;}
virtual bool data__samplerDEPTH__magfilter( const ParserChar* value, size_t length ){return true;}

virtual bool begin__samplerDEPTH__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__samplerDEPTH__extra(){return true;}

virtual bool begin__newparam__enum(){return true;}
virtual bool end__newparam__enum(){return true;}
virtual bool data__newparam__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__fx_profile_abstract(){return true;}
virtual bool end__fx_profile_abstract(){return true;}
virtual bool data__fx_profile_abstract( const ParserChar* value, size_t length ){return true;}

virtual bool begin__effect__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__effect__extra(){return true;}

virtual bool begin__library_effects__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_effects__extra(){return true;}

virtual bool begin__library_force_fields( const library_force_fields__AttributeData& attributeData ){return true;}
virtual bool end__library_force_fields(){return true;}

virtual bool begin__library_force_fields__asset(){return true;}
virtual bool end__library_force_fields__asset(){return true;}

virtual bool begin__force_field( const force_field__AttributeData& attributeData ){return true;}
virtual bool end__force_field(){return true;}

virtual bool begin__force_field__asset(){return true;}
virtual bool end__force_field__asset(){return true;}

virtual bool begin__force_field__technique( const force_field__technique__AttributeData& attributeData ){return true;}
virtual bool end__force_field__technique(){return true;}

virtual bool begin__force_field__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__force_field__extra(){return true;}

virtual bool begin__library_force_fields__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_force_fields__extra(){return true;}

virtual bool begin__library_images( const library_images__AttributeData& attributeData ){return true;}
virtual bool end__library_images(){return true;}

virtual bool begin__library_images__asset(){return true;}
virtual bool end__library_images__asset(){return true;}

virtual bool begin__library_images__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__library_images__image(){return true;}

virtual bool begin__library_images__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_images__extra(){return true;}

virtual bool begin__library_lights( const library_lights__AttributeData& attributeData ){return true;}
virtual bool end__library_lights(){return true;}

virtual bool begin__library_lights__asset(){return true;}
virtual bool end__library_lights__asset(){return true;}

virtual bool begin__light( const light__AttributeData& attributeData ){return true;}
virtual bool end__light(){return true;}

virtual bool begin__light__asset(){return true;}
virtual bool end__light__asset(){return true;}

virtual bool begin__light__technique_common(){return true;}
virtual bool end__light__technique_common(){return true;}

virtual bool begin__technique_common__ambient(){return true;}
virtual bool end__technique_common__ambient(){return true;}

virtual bool begin__ambient__color( const ambient__color__AttributeData& attributeData ){return true;}
virtual bool end__ambient__color(){return true;}
virtual bool data__ambient__color( const double* value, size_t length ){return true;}

virtual bool begin__directional(){return true;}
virtual bool end__directional(){return true;}

virtual bool begin__directional__color( const directional__color__AttributeData& attributeData ){return true;}
virtual bool end__directional__color(){return true;}
virtual bool data__directional__color( const double* value, size_t length ){return true;}

virtual bool begin__point(){return true;}
virtual bool end__point(){return true;}

virtual bool begin__point__color( const point__color__AttributeData& attributeData ){return true;}
virtual bool end__point__color(){return true;}
virtual bool data__point__color( const double* value, size_t length ){return true;}

virtual bool begin__point__constant_attenuation( const constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__point__constant_attenuation(){return true;}
virtual bool data__point__constant_attenuation( double value ){return true;}

virtual bool begin__point__linear_attenuation( const linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__point__linear_attenuation(){return true;}
virtual bool data__point__linear_attenuation( double value ){return true;}

virtual bool begin__point__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__point__quadratic_attenuation(){return true;}
virtual bool data__point__quadratic_attenuation( double value ){return true;}

virtual bool begin__spot(){return true;}
virtual bool end__spot(){return true;}

virtual bool begin__spot__color( const spot__color__AttributeData& attributeData ){return true;}
virtual bool end__spot__color(){return true;}
virtual bool data__spot__color( const double* value, size_t length ){return true;}

virtual bool begin__spot__constant_attenuation( const constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__spot__constant_attenuation(){return true;}
virtual bool data__spot__constant_attenuation( double value ){return true;}

virtual bool begin__spot__linear_attenuation( const linear_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__spot__linear_attenuation(){return true;}
virtual bool data__spot__linear_attenuation( double value ){return true;}

virtual bool begin__spot__quadratic_attenuation( const quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__spot__quadratic_attenuation(){return true;}
virtual bool data__spot__quadratic_attenuation( double value ){return true;}

virtual bool begin__falloff_angle( const falloff_angle__AttributeData& attributeData ){return true;}
virtual bool end__falloff_angle(){return true;}
virtual bool data__falloff_angle( double value ){return true;}

virtual bool begin__falloff_exponent( const falloff_exponent__AttributeData& attributeData ){return true;}
virtual bool end__falloff_exponent(){return true;}
virtual bool data__falloff_exponent( double value ){return true;}

virtual bool begin__light__technique( const light__technique__AttributeData& attributeData ){return true;}
virtual bool end__light__technique(){return true;}

virtual bool begin__light__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__light__extra(){return true;}

virtual bool begin__library_lights__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_lights__extra(){return true;}

virtual bool begin__library_materials( const library_materials__AttributeData& attributeData ){return true;}
virtual bool end__library_materials(){return true;}

virtual bool begin__library_materials__asset(){return true;}
virtual bool end__library_materials__asset(){return true;}

virtual bool begin__material( const material__AttributeData& attributeData ){return true;}
virtual bool end__material(){return true;}

virtual bool begin__material__asset(){return true;}
virtual bool end__material__asset(){return true;}

virtual bool begin__material__instance_effect( const instance_effect__AttributeData& attributeData ){return true;}
virtual bool end__material__instance_effect(){return true;}

virtual bool begin__technique_hint( const technique_hint__AttributeData& attributeData ){return true;}
virtual bool end__technique_hint(){return true;}

virtual bool begin__instance_effect__setparam( const instance_effect__setparam__AttributeData& attributeData ){return true;}
virtual bool end__instance_effect__setparam(){return true;}

virtual bool begin__setparam__bool(){return true;}
virtual bool end__setparam__bool(){return true;}
virtual bool data__setparam__bool( bool value ){return true;}

virtual bool begin__setparam__bool2(){return true;}
virtual bool end__setparam__bool2(){return true;}
virtual bool data__setparam__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool3(){return true;}
virtual bool end__setparam__bool3(){return true;}
virtual bool data__setparam__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool4(){return true;}
virtual bool end__setparam__bool4(){return true;}
virtual bool data__setparam__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__int(){return true;}
virtual bool end__setparam__int(){return true;}
virtual bool data__setparam__int( long value ){return true;}

virtual bool begin__setparam__int2(){return true;}
virtual bool end__setparam__int2(){return true;}
virtual bool data__setparam__int2( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int3(){return true;}
virtual bool end__setparam__int3(){return true;}
virtual bool data__setparam__int3( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int4(){return true;}
virtual bool end__setparam__int4(){return true;}
virtual bool data__setparam__int4( const long* value, size_t length ){return true;}

virtual bool begin__setparam__float(){return true;}
virtual bool end__setparam__float(){return true;}
virtual bool data__setparam__float( double value ){return true;}

virtual bool begin__setparam__float2(){return true;}
virtual bool end__setparam__float2(){return true;}
virtual bool data__setparam__float2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float3(){return true;}
virtual bool end__setparam__float3(){return true;}
virtual bool data__setparam__float3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float4(){return true;}
virtual bool end__setparam__float4(){return true;}
virtual bool data__setparam__float4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float1x1(){return true;}
virtual bool end__setparam__float1x1(){return true;}
virtual bool data__setparam__float1x1( double value ){return true;}

virtual bool begin__setparam__float1x2(){return true;}
virtual bool end__setparam__float1x2(){return true;}
virtual bool data__setparam__float1x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float1x3(){return true;}
virtual bool end__setparam__float1x3(){return true;}
virtual bool data__setparam__float1x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float1x4(){return true;}
virtual bool end__setparam__float1x4(){return true;}
virtual bool data__setparam__float1x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float2x1(){return true;}
virtual bool end__setparam__float2x1(){return true;}
virtual bool data__setparam__float2x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float2x2(){return true;}
virtual bool end__setparam__float2x2(){return true;}
virtual bool data__setparam__float2x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float2x3(){return true;}
virtual bool end__setparam__float2x3(){return true;}
virtual bool data__setparam__float2x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float2x4(){return true;}
virtual bool end__setparam__float2x4(){return true;}
virtual bool data__setparam__float2x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float3x1(){return true;}
virtual bool end__setparam__float3x1(){return true;}
virtual bool data__setparam__float3x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float3x2(){return true;}
virtual bool end__setparam__float3x2(){return true;}
virtual bool data__setparam__float3x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float3x3(){return true;}
virtual bool end__setparam__float3x3(){return true;}
virtual bool data__setparam__float3x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float3x4(){return true;}
virtual bool end__setparam__float3x4(){return true;}
virtual bool data__setparam__float3x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float4x1(){return true;}
virtual bool end__setparam__float4x1(){return true;}
virtual bool data__setparam__float4x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float4x2(){return true;}
virtual bool end__setparam__float4x2(){return true;}
virtual bool data__setparam__float4x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float4x3(){return true;}
virtual bool end__setparam__float4x3(){return true;}
virtual bool data__setparam__float4x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__float4x4(){return true;}
virtual bool end__setparam__float4x4(){return true;}
virtual bool data__setparam__float4x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__surface( const setparam__surface__AttributeData& attributeData ){return true;}
virtual bool end__setparam__surface(){return true;}

virtual bool begin__setparam__sampler1D(){return true;}
virtual bool end__setparam__sampler1D(){return true;}

virtual bool begin__setparam__sampler2D(){return true;}
virtual bool end__setparam__sampler2D(){return true;}

virtual bool begin__setparam__sampler3D(){return true;}
virtual bool end__setparam__sampler3D(){return true;}

virtual bool begin__setparam__samplerCUBE(){return true;}
virtual bool end__setparam__samplerCUBE(){return true;}

virtual bool begin__setparam__samplerRECT(){return true;}
virtual bool end__setparam__samplerRECT(){return true;}

virtual bool begin__setparam__samplerDEPTH(){return true;}
virtual bool end__setparam__samplerDEPTH(){return true;}

virtual bool begin__setparam__enum(){return true;}
virtual bool end__setparam__enum(){return true;}
virtual bool data__setparam__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__instance_effect__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_effect__extra(){return true;}

virtual bool begin__material__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__material__extra(){return true;}

virtual bool begin__library_materials__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_materials__extra(){return true;}

virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData ){return true;}
virtual bool end__library_nodes(){return true;}

virtual bool begin__library_nodes__asset(){return true;}
virtual bool end__library_nodes__asset(){return true;}

virtual bool begin__library_nodes__node( const node__AttributeData& attributeData ){return true;}
virtual bool end__library_nodes__node(){return true;}

virtual bool begin__node__asset(){return true;}
virtual bool end__node__asset(){return true;}

virtual bool begin__lookat( const lookat__AttributeData& attributeData ){return true;}
virtual bool end__lookat(){return true;}
virtual bool data__lookat( const double* value, size_t length ){return true;}

virtual bool begin__matrix( const matrix__AttributeData& attributeData ){return true;}
virtual bool end__matrix(){return true;}
virtual bool data__matrix( const double* value, size_t length ){return true;}

virtual bool begin__node__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__node__rotate(){return true;}
virtual bool data__node__rotate( const double* value, size_t length ){return true;}

virtual bool begin__scale( const scale__AttributeData& attributeData ){return true;}
virtual bool end__scale(){return true;}
virtual bool data__scale( const double* value, size_t length ){return true;}

virtual bool begin__skew( const skew__AttributeData& attributeData ){return true;}
virtual bool end__skew(){return true;}
virtual bool data__skew( const double* value, size_t length ){return true;}

virtual bool begin__node__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__node__translate(){return true;}
virtual bool data__node__translate( const double* value, size_t length ){return true;}

virtual bool begin__instance_camera( const instance_camera__AttributeData& attributeData ){return true;}
virtual bool end__instance_camera(){return true;}

virtual bool begin__instance_camera__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_camera__extra(){return true;}

virtual bool begin__instance_controller( const instance_controller__AttributeData& attributeData ){return true;}
virtual bool end__instance_controller(){return true;}

virtual bool begin__skeleton(){return true;}
virtual bool end__skeleton(){return true;}
virtual bool data__skeleton( const ParserChar* value, size_t length ){return true;}

virtual bool begin__instance_controller__bind_material(){return true;}
virtual bool end__instance_controller__bind_material(){return true;}

virtual bool begin__bind_material__param( const bind_material__param__AttributeData& attributeData ){return true;}
virtual bool end__bind_material__param(){return true;}
virtual bool data__bind_material__param( const ParserChar* value, size_t length ){return true;}

virtual bool begin__bind_material__technique_common(){return true;}
virtual bool end__bind_material__technique_common(){return true;}

virtual bool begin__instance_material( const instance_material__AttributeData& attributeData ){return true;}
virtual bool end__instance_material(){return true;}

virtual bool begin__instance_material__bind( const instance_material__bind__AttributeData& attributeData ){return true;}
virtual bool end__instance_material__bind(){return true;}

virtual bool begin__bind_vertex_input( const bind_vertex_input__AttributeData& attributeData ){return true;}
virtual bool end__bind_vertex_input(){return true;}

virtual bool begin__instance_material__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_material__extra(){return true;}

virtual bool begin__bind_material__technique( const bind_material__technique__AttributeData& attributeData ){return true;}
virtual bool end__bind_material__technique(){return true;}

virtual bool begin__bind_material__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__bind_material__extra(){return true;}

virtual bool begin__instance_controller__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_controller__extra(){return true;}

virtual bool begin__node__instance_geometry( const instance_geometry__AttributeData& attributeData ){return true;}
virtual bool end__node__instance_geometry(){return true;}

virtual bool begin__instance_geometry__bind_material(){return true;}
virtual bool end__instance_geometry__bind_material(){return true;}

virtual bool begin__instance_geometry__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_geometry__extra(){return true;}

virtual bool begin__instance_light( const instance_light__AttributeData& attributeData ){return true;}
virtual bool end__instance_light(){return true;}

virtual bool begin__instance_light__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_light__extra(){return true;}

virtual bool begin__instance_node( const instance_node__AttributeData& attributeData ){return true;}
virtual bool end__instance_node(){return true;}

virtual bool begin__instance_node__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_node__extra(){return true;}

virtual bool begin__node__node( const node__AttributeData& attributeData ){return true;}
virtual bool end__node__node(){return true;}

virtual bool begin__node__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__node__extra(){return true;}

virtual bool begin__library_nodes__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_nodes__extra(){return true;}

virtual bool begin__library_physics_materials( const library_physics_materials__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_materials(){return true;}

virtual bool begin__library_physics_materials__asset(){return true;}
virtual bool end__library_physics_materials__asset(){return true;}

virtual bool begin__library_physics_materials__physics_material( const physics_material__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_materials__physics_material(){return true;}

virtual bool begin__physics_material__asset(){return true;}
virtual bool end__physics_material__asset(){return true;}

virtual bool begin__physics_material__technique_common(){return true;}
virtual bool end__physics_material__technique_common(){return true;}

virtual bool begin__dynamic_friction( const dynamic_friction__AttributeData& attributeData ){return true;}
virtual bool end__dynamic_friction(){return true;}
virtual bool data__dynamic_friction( double value ){return true;}

virtual bool begin__restitution( const restitution__AttributeData& attributeData ){return true;}
virtual bool end__restitution(){return true;}
virtual bool data__restitution( double value ){return true;}

virtual bool begin__static_friction( const static_friction__AttributeData& attributeData ){return true;}
virtual bool end__static_friction(){return true;}
virtual bool data__static_friction( double value ){return true;}

virtual bool begin__physics_material__technique( const physics_material__technique__AttributeData& attributeData ){return true;}
virtual bool end__physics_material__technique(){return true;}

virtual bool begin__physics_material__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__physics_material__extra(){return true;}

virtual bool begin__library_physics_materials__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_materials__extra(){return true;}

virtual bool begin__library_physics_models( const library_physics_models__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_models(){return true;}

virtual bool begin__library_physics_models__asset(){return true;}
virtual bool end__library_physics_models__asset(){return true;}

virtual bool begin__physics_model( const physics_model__AttributeData& attributeData ){return true;}
virtual bool end__physics_model(){return true;}

virtual bool begin__physics_model__asset(){return true;}
virtual bool end__physics_model__asset(){return true;}

virtual bool begin__rigid_body( const rigid_body__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body(){return true;}

virtual bool begin__rigid_body__technique_common(){return true;}
virtual bool end__rigid_body__technique_common(){return true;}

virtual bool begin__dynamic( const dynamic__AttributeData& attributeData ){return true;}
virtual bool end__dynamic(){return true;}
virtual bool data__dynamic( bool value ){return true;}

virtual bool begin__technique_common__mass( const mass__AttributeData& attributeData ){return true;}
virtual bool end__technique_common__mass(){return true;}
virtual bool data__technique_common__mass( double value ){return true;}

virtual bool begin__mass_frame(){return true;}
virtual bool end__mass_frame(){return true;}

virtual bool begin__mass_frame__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__mass_frame__translate(){return true;}
virtual bool data__mass_frame__translate( const double* value, size_t length ){return true;}

virtual bool begin__mass_frame__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__mass_frame__rotate(){return true;}
virtual bool data__mass_frame__rotate( const double* value, size_t length ){return true;}

virtual bool begin__inertia( const inertia__AttributeData& attributeData ){return true;}
virtual bool end__inertia(){return true;}
virtual bool data__inertia( const double* value, size_t length ){return true;}

virtual bool begin__technique_common__instance_physics_material( const instance_physics_material__AttributeData& attributeData ){return true;}
virtual bool end__technique_common__instance_physics_material(){return true;}

virtual bool begin__instance_physics_material__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_material__extra(){return true;}

virtual bool begin__technique_common__physics_material( const physics_material__AttributeData& attributeData ){return true;}
virtual bool end__technique_common__physics_material(){return true;}

virtual bool begin__shape(){return true;}
virtual bool end__shape(){return true;}

virtual bool begin__hollow( const hollow__AttributeData& attributeData ){return true;}
virtual bool end__hollow(){return true;}
virtual bool data__hollow( bool value ){return true;}

virtual bool begin__shape__mass( const mass__AttributeData& attributeData ){return true;}
virtual bool end__shape__mass(){return true;}
virtual bool data__shape__mass( double value ){return true;}

virtual bool begin__density( const density__AttributeData& attributeData ){return true;}
virtual bool end__density(){return true;}
virtual bool data__density( double value ){return true;}

virtual bool begin__shape__instance_physics_material( const instance_physics_material__AttributeData& attributeData ){return true;}
virtual bool end__shape__instance_physics_material(){return true;}

virtual bool begin__shape__physics_material( const physics_material__AttributeData& attributeData ){return true;}
virtual bool end__shape__physics_material(){return true;}

virtual bool begin__shape__instance_geometry( const instance_geometry__AttributeData& attributeData ){return true;}
virtual bool end__shape__instance_geometry(){return true;}

virtual bool begin__plane(){return true;}
virtual bool end__plane(){return true;}

virtual bool begin__equation(){return true;}
virtual bool end__equation(){return true;}
virtual bool data__equation( const double* value, size_t length ){return true;}

virtual bool begin__plane__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__plane__extra(){return true;}

virtual bool begin__box(){return true;}
virtual bool end__box(){return true;}

virtual bool begin__half_extents(){return true;}
virtual bool end__half_extents(){return true;}
virtual bool data__half_extents( const double* value, size_t length ){return true;}

virtual bool begin__box__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__box__extra(){return true;}

virtual bool begin__sphere(){return true;}
virtual bool end__sphere(){return true;}

virtual bool begin__sphere__radius(){return true;}
virtual bool end__sphere__radius(){return true;}
virtual bool data__sphere__radius( double value ){return true;}

virtual bool begin__sphere__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__sphere__extra(){return true;}

virtual bool begin__cylinder(){return true;}
virtual bool end__cylinder(){return true;}

virtual bool begin__cylinder__height(){return true;}
virtual bool end__cylinder__height(){return true;}
virtual bool data__cylinder__height( double value ){return true;}

virtual bool begin__cylinder__radius(){return true;}
virtual bool end__cylinder__radius(){return true;}
virtual bool data__cylinder__radius( const double* value, size_t length ){return true;}

virtual bool begin__cylinder__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__cylinder__extra(){return true;}

virtual bool begin__tapered_cylinder(){return true;}
virtual bool end__tapered_cylinder(){return true;}

virtual bool begin__tapered_cylinder__height(){return true;}
virtual bool end__tapered_cylinder__height(){return true;}
virtual bool data__tapered_cylinder__height( double value ){return true;}

virtual bool begin__tapered_cylinder__radius1(){return true;}
virtual bool end__tapered_cylinder__radius1(){return true;}
virtual bool data__tapered_cylinder__radius1( const double* value, size_t length ){return true;}

virtual bool begin__tapered_cylinder__radius2(){return true;}
virtual bool end__tapered_cylinder__radius2(){return true;}
virtual bool data__tapered_cylinder__radius2( const double* value, size_t length ){return true;}

virtual bool begin__tapered_cylinder__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__tapered_cylinder__extra(){return true;}

virtual bool begin__capsule(){return true;}
virtual bool end__capsule(){return true;}

virtual bool begin__capsule__height(){return true;}
virtual bool end__capsule__height(){return true;}
virtual bool data__capsule__height( double value ){return true;}

virtual bool begin__capsule__radius(){return true;}
virtual bool end__capsule__radius(){return true;}
virtual bool data__capsule__radius( const double* value, size_t length ){return true;}

virtual bool begin__capsule__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__capsule__extra(){return true;}

virtual bool begin__tapered_capsule(){return true;}
virtual bool end__tapered_capsule(){return true;}

virtual bool begin__tapered_capsule__height(){return true;}
virtual bool end__tapered_capsule__height(){return true;}
virtual bool data__tapered_capsule__height( double value ){return true;}

virtual bool begin__tapered_capsule__radius1(){return true;}
virtual bool end__tapered_capsule__radius1(){return true;}
virtual bool data__tapered_capsule__radius1( const double* value, size_t length ){return true;}

virtual bool begin__tapered_capsule__radius2(){return true;}
virtual bool end__tapered_capsule__radius2(){return true;}
virtual bool data__tapered_capsule__radius2( const double* value, size_t length ){return true;}

virtual bool begin__tapered_capsule__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__tapered_capsule__extra(){return true;}

virtual bool begin__shape__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__shape__translate(){return true;}
virtual bool data__shape__translate( const double* value, size_t length ){return true;}

virtual bool begin__shape__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__shape__rotate(){return true;}
virtual bool data__shape__rotate( const double* value, size_t length ){return true;}

virtual bool begin__shape__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__shape__extra(){return true;}

virtual bool begin__rigid_body__technique( const rigid_body__technique__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body__technique(){return true;}

virtual bool begin__rigid_body__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__rigid_body__extra(){return true;}

virtual bool begin__rigid_constraint( const rigid_constraint__AttributeData& attributeData ){return true;}
virtual bool end__rigid_constraint(){return true;}

virtual bool begin__ref_attachment( const ref_attachment__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment(){return true;}

virtual bool begin__ref_attachment__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment__translate(){return true;}
virtual bool data__ref_attachment__translate( const double* value, size_t length ){return true;}

virtual bool begin__ref_attachment__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment__rotate(){return true;}
virtual bool data__ref_attachment__rotate( const double* value, size_t length ){return true;}

virtual bool begin__ref_attachment__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__ref_attachment__extra(){return true;}

virtual bool begin__attachment( const attachment__AttributeData& attributeData ){return true;}
virtual bool end__attachment(){return true;}

virtual bool begin__attachment__translate( const translate__AttributeData& attributeData ){return true;}
virtual bool end__attachment__translate(){return true;}
virtual bool data__attachment__translate( const double* value, size_t length ){return true;}

virtual bool begin__attachment__rotate( const rotate__AttributeData& attributeData ){return true;}
virtual bool end__attachment__rotate(){return true;}
virtual bool data__attachment__rotate( const double* value, size_t length ){return true;}

virtual bool begin__attachment__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__attachment__extra(){return true;}

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

virtual bool begin__swing_cone_and_twist__min( const min__AttributeData& attributeData ){return true;}
virtual bool end__swing_cone_and_twist__min(){return true;}
virtual bool data__swing_cone_and_twist__min( const double* value, size_t length ){return true;}

virtual bool begin__swing_cone_and_twist__max( const max__AttributeData& attributeData ){return true;}
virtual bool end__swing_cone_and_twist__max(){return true;}
virtual bool data__swing_cone_and_twist__max( const double* value, size_t length ){return true;}

virtual bool begin__limits__linear(){return true;}
virtual bool end__limits__linear(){return true;}

virtual bool begin__linear__min( const min__AttributeData& attributeData ){return true;}
virtual bool end__linear__min(){return true;}
virtual bool data__linear__min( const double* value, size_t length ){return true;}

virtual bool begin__linear__max( const max__AttributeData& attributeData ){return true;}
virtual bool end__linear__max(){return true;}
virtual bool data__linear__max( const double* value, size_t length ){return true;}

virtual bool begin__spring(){return true;}
virtual bool end__spring(){return true;}

virtual bool begin__angular(){return true;}
virtual bool end__angular(){return true;}

virtual bool begin__angular__stiffness( const stiffness__AttributeData& attributeData ){return true;}
virtual bool end__angular__stiffness(){return true;}
virtual bool data__angular__stiffness( double value ){return true;}

virtual bool begin__angular__damping( const damping__AttributeData& attributeData ){return true;}
virtual bool end__angular__damping(){return true;}
virtual bool data__angular__damping( double value ){return true;}

virtual bool begin__angular__target_value( const target_value__AttributeData& attributeData ){return true;}
virtual bool end__angular__target_value(){return true;}
virtual bool data__angular__target_value( double value ){return true;}

virtual bool begin__spring__linear(){return true;}
virtual bool end__spring__linear(){return true;}

virtual bool begin__linear__stiffness( const stiffness__AttributeData& attributeData ){return true;}
virtual bool end__linear__stiffness(){return true;}
virtual bool data__linear__stiffness( double value ){return true;}

virtual bool begin__linear__damping( const damping__AttributeData& attributeData ){return true;}
virtual bool end__linear__damping(){return true;}
virtual bool data__linear__damping( double value ){return true;}

virtual bool begin__linear__target_value( const target_value__AttributeData& attributeData ){return true;}
virtual bool end__linear__target_value(){return true;}
virtual bool data__linear__target_value( double value ){return true;}

virtual bool begin__rigid_constraint__technique( const rigid_constraint__technique__AttributeData& attributeData ){return true;}
virtual bool end__rigid_constraint__technique(){return true;}

virtual bool begin__rigid_constraint__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__rigid_constraint__extra(){return true;}

virtual bool begin__physics_model__instance_physics_model( const instance_physics_model__AttributeData& attributeData ){return true;}
virtual bool end__physics_model__instance_physics_model(){return true;}

virtual bool begin__instance_physics_model__instance_force_field( const instance_force_field__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_model__instance_force_field(){return true;}

virtual bool begin__instance_force_field__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_force_field__extra(){return true;}

virtual bool begin__instance_rigid_body( const instance_rigid_body__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body(){return true;}

virtual bool begin__instance_rigid_body__technique_common(){return true;}
virtual bool end__instance_rigid_body__technique_common(){return true;}

virtual bool begin__angular_velocity(){return true;}
virtual bool end__angular_velocity(){return true;}
virtual bool data__angular_velocity( const double* value, size_t length ){return true;}

virtual bool begin__velocity(){return true;}
virtual bool end__velocity(){return true;}
virtual bool data__velocity( const double* value, size_t length ){return true;}

virtual bool begin__instance_rigid_body__technique( const instance_rigid_body__technique__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body__technique(){return true;}

virtual bool begin__instance_rigid_body__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_body__extra(){return true;}

virtual bool begin__instance_rigid_constraint( const instance_rigid_constraint__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_constraint(){return true;}

virtual bool begin__instance_rigid_constraint__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_rigid_constraint__extra(){return true;}

virtual bool begin__instance_physics_model__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_model__extra(){return true;}

virtual bool begin__physics_model__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__physics_model__extra(){return true;}

virtual bool begin__library_physics_models__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_models__extra(){return true;}

virtual bool begin__library_physics_scenes( const library_physics_scenes__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_scenes(){return true;}

virtual bool begin__library_physics_scenes__asset(){return true;}
virtual bool end__library_physics_scenes__asset(){return true;}

virtual bool begin__physics_scene( const physics_scene__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene(){return true;}

virtual bool begin__physics_scene__asset(){return true;}
virtual bool end__physics_scene__asset(){return true;}

virtual bool begin__physics_scene__instance_force_field( const instance_force_field__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene__instance_force_field(){return true;}

virtual bool begin__physics_scene__instance_physics_model( const instance_physics_model__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene__instance_physics_model(){return true;}

virtual bool begin__physics_scene__technique_common(){return true;}
virtual bool end__physics_scene__technique_common(){return true;}

virtual bool begin__gravity( const gravity__AttributeData& attributeData ){return true;}
virtual bool end__gravity(){return true;}
virtual bool data__gravity( const double* value, size_t length ){return true;}

virtual bool begin__time_step( const time_step__AttributeData& attributeData ){return true;}
virtual bool end__time_step(){return true;}
virtual bool data__time_step( double value ){return true;}

virtual bool begin__physics_scene__technique( const physics_scene__technique__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene__technique(){return true;}

virtual bool begin__physics_scene__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__physics_scene__extra(){return true;}

virtual bool begin__library_physics_scenes__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_physics_scenes__extra(){return true;}

virtual bool begin__library_visual_scenes( const library_visual_scenes__AttributeData& attributeData ){return true;}
virtual bool end__library_visual_scenes(){return true;}

virtual bool begin__library_visual_scenes__asset(){return true;}
virtual bool end__library_visual_scenes__asset(){return true;}

virtual bool begin__visual_scene( const visual_scene__AttributeData& attributeData ){return true;}
virtual bool end__visual_scene(){return true;}

virtual bool begin__visual_scene__asset(){return true;}
virtual bool end__visual_scene__asset(){return true;}

virtual bool begin__visual_scene__node( const node__AttributeData& attributeData ){return true;}
virtual bool end__visual_scene__node(){return true;}

virtual bool begin__evaluate_scene( const evaluate_scene__AttributeData& attributeData ){return true;}
virtual bool end__evaluate_scene(){return true;}

virtual bool begin__render( const render__AttributeData& attributeData ){return true;}
virtual bool end__render(){return true;}

virtual bool begin__layer(){return true;}
virtual bool end__layer(){return true;}
virtual bool data__layer( const ParserChar* value, size_t length ){return true;}

virtual bool begin__render__instance_effect( const instance_effect__AttributeData& attributeData ){return true;}
virtual bool end__render__instance_effect(){return true;}

virtual bool begin__visual_scene__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__visual_scene__extra(){return true;}

virtual bool begin__library_visual_scenes__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__library_visual_scenes__extra(){return true;}

virtual bool begin__scene(){return true;}
virtual bool end__scene(){return true;}

virtual bool begin__instance_physics_scene( const instance_physics_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_scene(){return true;}

virtual bool begin__instance_physics_scene__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_physics_scene__extra(){return true;}

virtual bool begin__instance_visual_scene( const instance_visual_scene__AttributeData& attributeData ){return true;}
virtual bool end__instance_visual_scene(){return true;}

virtual bool begin__instance_visual_scene__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__instance_visual_scene__extra(){return true;}

virtual bool begin__scene__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__scene__extra(){return true;}

virtual bool begin__COLLADA__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__COLLADA__extra(){return true;}



private:
/** Disable default copy ctor. */
ColladaParserAutoGen( const ColladaParserAutoGen& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen& operator= ( const ColladaParserAutoGen& pre );

};

}
#endif
