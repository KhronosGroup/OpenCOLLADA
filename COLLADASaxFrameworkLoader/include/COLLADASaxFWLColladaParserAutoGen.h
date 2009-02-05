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


virtual bool begin__profile_GLES( const profile_GLES__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES(){return true;}

virtual bool begin__profile_GLES__asset(){return true;}
virtual bool end__profile_GLES__asset(){return true;}

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
virtual bool data__up_axis( const UpAxisType value ){return true;}

virtual bool begin__profile_GLES__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__image(){return true;}

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

virtual bool begin__extra__asset(){return true;}
virtual bool end__extra__asset(){return true;}

virtual bool begin__extra__technique( const extra__technique__AttributeData& attributeData ){return true;}
virtual bool end__extra__technique(){return true;}

virtual bool begin__profile_GLES__newparam( const profile_GLES__newparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__newparam(){return true;}

virtual bool begin__newparam__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__newparam__annotate(){return true;}

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

virtual bool begin__semantic(){return true;}
virtual bool end__semantic(){return true;}
virtual bool data__semantic( const ParserChar* value, size_t length ){return true;}

virtual bool begin__modifier(){return true;}
virtual bool end__modifier(){return true;}
virtual bool data__modifier( const fx_modifier_enum_common value ){return true;}

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
virtual bool data__order( const fx_surface_face_enum value ){return true;}

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
virtual bool data__channels( const fx_surface_format_hint_channels_enum value ){return true;}

virtual bool begin__range(){return true;}
virtual bool end__range(){return true;}
virtual bool data__range( const fx_surface_format_hint_range_enum value ){return true;}

virtual bool begin__precision(){return true;}
virtual bool end__precision(){return true;}
virtual bool data__precision( const fx_surface_format_hint_precision_enum value ){return true;}

virtual bool begin__option(){return true;}
virtual bool end__option(){return true;}
virtual bool data__option( const fx_surface_format_hint_option_enum value ){return true;}

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

virtual bool begin__newparam__texture_pipeline( const newparam__texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__newparam__texture_pipeline(){return true;}

virtual bool begin__texture_pipeline__texcombiner(){return true;}
virtual bool end__texture_pipeline__texcombiner(){return true;}

virtual bool begin__texcombiner__constant( const texcombiner__constant__AttributeData& attributeData ){return true;}
virtual bool end__texcombiner__constant(){return true;}

virtual bool begin__RGB( const RGB__AttributeData& attributeData ){return true;}
virtual bool end__RGB(){return true;}

virtual bool begin__RGB__argument( const RGB__argument__AttributeData& attributeData ){return true;}
virtual bool end__RGB__argument(){return true;}

virtual bool begin__texcombiner__alpha( const texcombiner__alpha__AttributeData& attributeData ){return true;}
virtual bool end__texcombiner__alpha(){return true;}

virtual bool begin__alpha__argument( const alpha__argument__AttributeData& attributeData ){return true;}
virtual bool end__alpha__argument(){return true;}

virtual bool begin__texture_pipeline__texenv( const texenv__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline__texenv(){return true;}

virtual bool begin__texenv__constant( const texenv__constant__AttributeData& attributeData ){return true;}
virtual bool end__texenv__constant(){return true;}

virtual bool begin__texture_pipeline__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline__extra(){return true;}

virtual bool begin__newparam__sampler_state( const newparam__sampler_state__AttributeData& attributeData ){return true;}
virtual bool end__newparam__sampler_state(){return true;}

virtual bool begin__sampler_state__wrap_s(){return true;}
virtual bool end__sampler_state__wrap_s(){return true;}
virtual bool data__sampler_state__wrap_s( const gles_sampler_wrap value ){return true;}

virtual bool begin__sampler_state__wrap_t(){return true;}
virtual bool end__sampler_state__wrap_t(){return true;}
virtual bool data__sampler_state__wrap_t( const gles_sampler_wrap value ){return true;}

virtual bool begin__sampler_state__minfilter(){return true;}
virtual bool end__sampler_state__minfilter(){return true;}
virtual bool data__sampler_state__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler_state__magfilter(){return true;}
virtual bool end__sampler_state__magfilter(){return true;}
virtual bool data__sampler_state__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler_state__mipfilter(){return true;}
virtual bool end__sampler_state__mipfilter(){return true;}
virtual bool data__sampler_state__mipfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler_state__mipmap_maxlevel(){return true;}
virtual bool end__sampler_state__mipmap_maxlevel(){return true;}
virtual bool data__sampler_state__mipmap_maxlevel( unsigned short value ){return true;}

virtual bool begin__sampler_state__mipmap_bias(){return true;}
virtual bool end__sampler_state__mipmap_bias(){return true;}
virtual bool data__sampler_state__mipmap_bias( double value ){return true;}

virtual bool begin__sampler_state__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__sampler_state__extra(){return true;}

virtual bool begin__newparam__texture_unit( const texture_unit__AttributeData& attributeData ){return true;}
virtual bool end__newparam__texture_unit(){return true;}

virtual bool begin__texture_unit__surface(){return true;}
virtual bool end__texture_unit__surface(){return true;}
virtual bool data__texture_unit__surface( const ParserChar* value, size_t length ){return true;}

virtual bool begin__texture_unit__sampler_state(){return true;}
virtual bool end__texture_unit__sampler_state(){return true;}
virtual bool data__texture_unit__sampler_state( const ParserChar* value, size_t length ){return true;}

virtual bool begin__texcoord( const texcoord__AttributeData& attributeData ){return true;}
virtual bool end__texcoord(){return true;}

virtual bool begin__texture_unit__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__texture_unit__extra(){return true;}

virtual bool begin__newparam__enum(){return true;}
virtual bool end__newparam__enum(){return true;}
virtual bool data__newparam__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLES__technique( const profile_GLES__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__technique(){return true;}

virtual bool begin__technique__asset(){return true;}
virtual bool end__technique__asset(){return true;}

virtual bool begin__technique__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__technique__annotate(){return true;}

virtual bool begin__technique__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__technique__image(){return true;}

virtual bool begin__technique__newparam( const technique__newparam__AttributeData& attributeData ){return true;}
virtual bool end__technique__newparam(){return true;}

virtual bool begin__technique__setparam( const technique__setparam__AttributeData& attributeData ){return true;}
virtual bool end__technique__setparam(){return true;}

virtual bool begin__setparam__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__setparam__annotate(){return true;}

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

virtual bool begin__setparam__texture_pipeline( const setparam__texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__setparam__texture_pipeline(){return true;}

virtual bool begin__setparam__sampler_state( const setparam__sampler_state__AttributeData& attributeData ){return true;}
virtual bool end__setparam__sampler_state(){return true;}

virtual bool begin__setparam__texture_unit( const texture_unit__AttributeData& attributeData ){return true;}
virtual bool end__setparam__texture_unit(){return true;}

virtual bool begin__setparam__enum(){return true;}
virtual bool end__setparam__enum(){return true;}
virtual bool data__setparam__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__pass( const pass__AttributeData& attributeData ){return true;}
virtual bool end__pass(){return true;}

virtual bool begin__pass__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__pass__annotate(){return true;}

virtual bool begin__color_target(){return true;}
virtual bool end__color_target(){return true;}
virtual bool data__color_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__depth_target(){return true;}
virtual bool end__depth_target(){return true;}
virtual bool data__depth_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__stencil_target(){return true;}
virtual bool end__stencil_target(){return true;}
virtual bool data__stencil_target( const ParserChar* value, size_t length ){return true;}

virtual bool begin__color_clear(){return true;}
virtual bool end__color_clear(){return true;}
virtual bool data__color_clear( const double* value, size_t length ){return true;}

virtual bool begin__depth_clear(){return true;}
virtual bool end__depth_clear(){return true;}
virtual bool data__depth_clear( double value ){return true;}

virtual bool begin__stencil_clear(){return true;}
virtual bool end__stencil_clear(){return true;}
virtual bool data__stencil_clear( short value ){return true;}

virtual bool begin__draw(){return true;}
virtual bool end__draw(){return true;}
virtual bool data__draw( const ParserChar* value, size_t length ){return true;}

virtual bool begin__alpha_func(){return true;}
virtual bool end__alpha_func(){return true;}

virtual bool begin__alpha_func__func( const alpha_func__func__AttributeData& attributeData ){return true;}
virtual bool end__alpha_func__func(){return true;}

virtual bool begin__alpha_func__value( const alpha_func__value__AttributeData& attributeData ){return true;}
virtual bool end__alpha_func__value(){return true;}

virtual bool begin__blend_func(){return true;}
virtual bool end__blend_func(){return true;}

virtual bool begin__src( const src__AttributeData& attributeData ){return true;}
virtual bool end__src(){return true;}

virtual bool begin__dest( const dest__AttributeData& attributeData ){return true;}
virtual bool end__dest(){return true;}

virtual bool begin__clear_color( const clear_color__AttributeData& attributeData ){return true;}
virtual bool end__clear_color(){return true;}

virtual bool begin__clear_stencil( const clear_stencil__AttributeData& attributeData ){return true;}
virtual bool end__clear_stencil(){return true;}

virtual bool begin__clear_depth( const clear_depth__AttributeData& attributeData ){return true;}
virtual bool end__clear_depth(){return true;}

virtual bool begin__clip_plane( const clip_plane__AttributeData& attributeData ){return true;}
virtual bool end__clip_plane(){return true;}

virtual bool begin__color_mask( const color_mask__AttributeData& attributeData ){return true;}
virtual bool end__color_mask(){return true;}

virtual bool begin__cull_face( const cull_face__AttributeData& attributeData ){return true;}
virtual bool end__cull_face(){return true;}

virtual bool begin__depth_func( const depth_func__AttributeData& attributeData ){return true;}
virtual bool end__depth_func(){return true;}

virtual bool begin__depth_mask( const depth_mask__AttributeData& attributeData ){return true;}
virtual bool end__depth_mask(){return true;}

virtual bool begin__depth_range( const depth_range__AttributeData& attributeData ){return true;}
virtual bool end__depth_range(){return true;}

virtual bool begin__fog_color( const fog_color__AttributeData& attributeData ){return true;}
virtual bool end__fog_color(){return true;}

virtual bool begin__fog_density( const fog_density__AttributeData& attributeData ){return true;}
virtual bool end__fog_density(){return true;}

virtual bool begin__fog_mode( const fog_mode__AttributeData& attributeData ){return true;}
virtual bool end__fog_mode(){return true;}

virtual bool begin__fog_start( const fog_start__AttributeData& attributeData ){return true;}
virtual bool end__fog_start(){return true;}

virtual bool begin__fog_end( const fog_end__AttributeData& attributeData ){return true;}
virtual bool end__fog_end(){return true;}

virtual bool begin__front_face( const front_face__AttributeData& attributeData ){return true;}
virtual bool end__front_face(){return true;}

virtual bool begin__pass__texture_pipeline( const pass__texture_pipeline__AttributeData& attributeData ){return true;}
virtual bool end__pass__texture_pipeline(){return true;}

virtual bool begin__texture_pipeline__value( const texture_pipeline__value__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline__value(){return true;}

virtual bool begin__value__texcombiner(){return true;}
virtual bool end__value__texcombiner(){return true;}

virtual bool begin__value__texenv( const texenv__AttributeData& attributeData ){return true;}
virtual bool end__value__texenv(){return true;}

virtual bool begin__value__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__value__extra(){return true;}

virtual bool begin__logic_op( const logic_op__AttributeData& attributeData ){return true;}
virtual bool end__logic_op(){return true;}

virtual bool begin__light_ambient( const light_ambient__AttributeData& attributeData ){return true;}
virtual bool end__light_ambient(){return true;}

virtual bool begin__light_diffuse( const light_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__light_diffuse(){return true;}

virtual bool begin__light_specular( const light_specular__AttributeData& attributeData ){return true;}
virtual bool end__light_specular(){return true;}

virtual bool begin__light_position( const light_position__AttributeData& attributeData ){return true;}
virtual bool end__light_position(){return true;}

virtual bool begin__light_constant_attenuation( const light_constant_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__light_constant_attenuation(){return true;}

virtual bool begin__light_linear_attenutation( const light_linear_attenutation__AttributeData& attributeData ){return true;}
virtual bool end__light_linear_attenutation(){return true;}

virtual bool begin__light_quadratic_attenuation( const light_quadratic_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__light_quadratic_attenuation(){return true;}

virtual bool begin__light_spot_cutoff( const light_spot_cutoff__AttributeData& attributeData ){return true;}
virtual bool end__light_spot_cutoff(){return true;}

virtual bool begin__light_spot_direction( const light_spot_direction__AttributeData& attributeData ){return true;}
virtual bool end__light_spot_direction(){return true;}

virtual bool begin__light_spot_exponent( const light_spot_exponent__AttributeData& attributeData ){return true;}
virtual bool end__light_spot_exponent(){return true;}

virtual bool begin__light_model_ambient( const light_model_ambient__AttributeData& attributeData ){return true;}
virtual bool end__light_model_ambient(){return true;}

virtual bool begin__line_width( const line_width__AttributeData& attributeData ){return true;}
virtual bool end__line_width(){return true;}

virtual bool begin__material_ambient( const material_ambient__AttributeData& attributeData ){return true;}
virtual bool end__material_ambient(){return true;}

virtual bool begin__material_diffuse( const material_diffuse__AttributeData& attributeData ){return true;}
virtual bool end__material_diffuse(){return true;}

virtual bool begin__material_emission( const material_emission__AttributeData& attributeData ){return true;}
virtual bool end__material_emission(){return true;}

virtual bool begin__material_shininess( const material_shininess__AttributeData& attributeData ){return true;}
virtual bool end__material_shininess(){return true;}

virtual bool begin__material_specular( const material_specular__AttributeData& attributeData ){return true;}
virtual bool end__material_specular(){return true;}

virtual bool begin__model_view_matrix( const model_view_matrix__AttributeData& attributeData ){return true;}
virtual bool end__model_view_matrix(){return true;}

virtual bool begin__point_distance_attenuation( const point_distance_attenuation__AttributeData& attributeData ){return true;}
virtual bool end__point_distance_attenuation(){return true;}

virtual bool begin__point_fade_threshold_size( const point_fade_threshold_size__AttributeData& attributeData ){return true;}
virtual bool end__point_fade_threshold_size(){return true;}

virtual bool begin__point_size( const point_size__AttributeData& attributeData ){return true;}
virtual bool end__point_size(){return true;}

virtual bool begin__point_size_min( const point_size_min__AttributeData& attributeData ){return true;}
virtual bool end__point_size_min(){return true;}

virtual bool begin__point_size_max( const point_size_max__AttributeData& attributeData ){return true;}
virtual bool end__point_size_max(){return true;}

virtual bool begin__polygon_offset( const polygon_offset__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset(){return true;}

virtual bool begin__projection_matrix( const projection_matrix__AttributeData& attributeData ){return true;}
virtual bool end__projection_matrix(){return true;}

virtual bool begin__scissor( const scissor__AttributeData& attributeData ){return true;}
virtual bool end__scissor(){return true;}

virtual bool begin__shade_model( const shade_model__AttributeData& attributeData ){return true;}
virtual bool end__shade_model(){return true;}

virtual bool begin__stencil_func(){return true;}
virtual bool end__stencil_func(){return true;}

virtual bool begin__stencil_func__func( const stencil_func__func__AttributeData& attributeData ){return true;}
virtual bool end__stencil_func__func(){return true;}

virtual bool begin__stencil_func__ref( const stencil_func__ref__AttributeData& attributeData ){return true;}
virtual bool end__stencil_func__ref(){return true;}

virtual bool begin__stencil_func__mask( const stencil_func__mask__AttributeData& attributeData ){return true;}
virtual bool end__stencil_func__mask(){return true;}

virtual bool begin__stencil_mask( const stencil_mask__AttributeData& attributeData ){return true;}
virtual bool end__stencil_mask(){return true;}

virtual bool begin__stencil_op(){return true;}
virtual bool end__stencil_op(){return true;}

virtual bool begin__stencil_op__fail( const stencil_op__fail__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op__fail(){return true;}

virtual bool begin__stencil_op__zfail( const stencil_op__zfail__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op__zfail(){return true;}

virtual bool begin__stencil_op__zpass( const stencil_op__zpass__AttributeData& attributeData ){return true;}
virtual bool end__stencil_op__zpass(){return true;}

virtual bool begin__alpha_test_enable( const alpha_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__alpha_test_enable(){return true;}

virtual bool begin__blend_enable( const blend_enable__AttributeData& attributeData ){return true;}
virtual bool end__blend_enable(){return true;}

virtual bool begin__clip_plane_enable( const clip_plane_enable__AttributeData& attributeData ){return true;}
virtual bool end__clip_plane_enable(){return true;}

virtual bool begin__color_logic_op_enable( const color_logic_op_enable__AttributeData& attributeData ){return true;}
virtual bool end__color_logic_op_enable(){return true;}

virtual bool begin__color_material_enable( const color_material_enable__AttributeData& attributeData ){return true;}
virtual bool end__color_material_enable(){return true;}

virtual bool begin__cull_face_enable( const cull_face_enable__AttributeData& attributeData ){return true;}
virtual bool end__cull_face_enable(){return true;}

virtual bool begin__depth_test_enable( const depth_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__depth_test_enable(){return true;}

virtual bool begin__dither_enable( const dither_enable__AttributeData& attributeData ){return true;}
virtual bool end__dither_enable(){return true;}

virtual bool begin__fog_enable( const fog_enable__AttributeData& attributeData ){return true;}
virtual bool end__fog_enable(){return true;}

virtual bool begin__texture_pipeline_enable( const texture_pipeline_enable__AttributeData& attributeData ){return true;}
virtual bool end__texture_pipeline_enable(){return true;}

virtual bool begin__light_enable( const light_enable__AttributeData& attributeData ){return true;}
virtual bool end__light_enable(){return true;}

virtual bool begin__lighting_enable( const lighting_enable__AttributeData& attributeData ){return true;}
virtual bool end__lighting_enable(){return true;}

virtual bool begin__light_model_two_side_enable( const light_model_two_side_enable__AttributeData& attributeData ){return true;}
virtual bool end__light_model_two_side_enable(){return true;}

virtual bool begin__line_smooth_enable( const line_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__line_smooth_enable(){return true;}

virtual bool begin__multisample_enable( const multisample_enable__AttributeData& attributeData ){return true;}
virtual bool end__multisample_enable(){return true;}

virtual bool begin__normalize_enable( const normalize_enable__AttributeData& attributeData ){return true;}
virtual bool end__normalize_enable(){return true;}

virtual bool begin__point_smooth_enable( const point_smooth_enable__AttributeData& attributeData ){return true;}
virtual bool end__point_smooth_enable(){return true;}

virtual bool begin__polygon_offset_fill_enable( const polygon_offset_fill_enable__AttributeData& attributeData ){return true;}
virtual bool end__polygon_offset_fill_enable(){return true;}

virtual bool begin__rescale_normal_enable( const rescale_normal_enable__AttributeData& attributeData ){return true;}
virtual bool end__rescale_normal_enable(){return true;}

virtual bool begin__sample_alpha_to_coverage_enable( const sample_alpha_to_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__sample_alpha_to_coverage_enable(){return true;}

virtual bool begin__sample_alpha_to_one_enable( const sample_alpha_to_one_enable__AttributeData& attributeData ){return true;}
virtual bool end__sample_alpha_to_one_enable(){return true;}

virtual bool begin__sample_coverage_enable( const sample_coverage_enable__AttributeData& attributeData ){return true;}
virtual bool end__sample_coverage_enable(){return true;}

virtual bool begin__scissor_test_enable( const scissor_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__scissor_test_enable(){return true;}

virtual bool begin__stencil_test_enable( const stencil_test_enable__AttributeData& attributeData ){return true;}
virtual bool end__stencil_test_enable(){return true;}

virtual bool begin__pass__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__pass__extra(){return true;}

virtual bool begin__technique__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__technique__extra(){return true;}

virtual bool begin__profile_GLES__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLES__extra(){return true;}

virtual bool begin__COLLADA( const COLLADA__AttributeData& attributeData ){return true;}
virtual bool end__COLLADA(){return true;}

virtual bool begin__COLLADA__asset(){return true;}
virtual bool end__COLLADA__asset(){return true;}

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

virtual bool begin__effect__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__effect__image(){return true;}

virtual bool begin__effect__newparam( const effect__newparam__AttributeData& attributeData ){return true;}
virtual bool end__effect__newparam(){return true;}

virtual bool begin__newparam__sampler1D(){return true;}
virtual bool end__newparam__sampler1D(){return true;}

virtual bool begin__sampler1D__source(){return true;}
virtual bool end__sampler1D__source(){return true;}
virtual bool data__sampler1D__source( const ParserChar* value, size_t length ){return true;}

virtual bool begin__sampler1D__wrap_s(){return true;}
virtual bool end__sampler1D__wrap_s(){return true;}
virtual bool data__sampler1D__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler1D__minfilter(){return true;}
virtual bool end__sampler1D__minfilter(){return true;}
virtual bool data__sampler1D__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler1D__magfilter(){return true;}
virtual bool end__sampler1D__magfilter(){return true;}
virtual bool data__sampler1D__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler1D__mipfilter(){return true;}
virtual bool end__sampler1D__mipfilter(){return true;}
virtual bool data__sampler1D__mipfilter( const fx_sampler_filter_common value ){return true;}

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
virtual bool data__sampler2D__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler2D__wrap_t(){return true;}
virtual bool end__sampler2D__wrap_t(){return true;}
virtual bool data__sampler2D__wrap_t( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler2D__minfilter(){return true;}
virtual bool end__sampler2D__minfilter(){return true;}
virtual bool data__sampler2D__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler2D__magfilter(){return true;}
virtual bool end__sampler2D__magfilter(){return true;}
virtual bool data__sampler2D__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler2D__mipfilter(){return true;}
virtual bool end__sampler2D__mipfilter(){return true;}
virtual bool data__sampler2D__mipfilter( const fx_sampler_filter_common value ){return true;}

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
virtual bool data__sampler3D__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler3D__wrap_t(){return true;}
virtual bool end__sampler3D__wrap_t(){return true;}
virtual bool data__sampler3D__wrap_t( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler3D__wrap_p(){return true;}
virtual bool end__sampler3D__wrap_p(){return true;}
virtual bool data__sampler3D__wrap_p( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__sampler3D__minfilter(){return true;}
virtual bool end__sampler3D__minfilter(){return true;}
virtual bool data__sampler3D__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler3D__magfilter(){return true;}
virtual bool end__sampler3D__magfilter(){return true;}
virtual bool data__sampler3D__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__sampler3D__mipfilter(){return true;}
virtual bool end__sampler3D__mipfilter(){return true;}
virtual bool data__sampler3D__mipfilter( const fx_sampler_filter_common value ){return true;}

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
virtual bool data__samplerCUBE__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerCUBE__wrap_t(){return true;}
virtual bool end__samplerCUBE__wrap_t(){return true;}
virtual bool data__samplerCUBE__wrap_t( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerCUBE__wrap_p(){return true;}
virtual bool end__samplerCUBE__wrap_p(){return true;}
virtual bool data__samplerCUBE__wrap_p( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerCUBE__minfilter(){return true;}
virtual bool end__samplerCUBE__minfilter(){return true;}
virtual bool data__samplerCUBE__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerCUBE__magfilter(){return true;}
virtual bool end__samplerCUBE__magfilter(){return true;}
virtual bool data__samplerCUBE__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerCUBE__mipfilter(){return true;}
virtual bool end__samplerCUBE__mipfilter(){return true;}
virtual bool data__samplerCUBE__mipfilter( const fx_sampler_filter_common value ){return true;}

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
virtual bool data__samplerRECT__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerRECT__wrap_t(){return true;}
virtual bool end__samplerRECT__wrap_t(){return true;}
virtual bool data__samplerRECT__wrap_t( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerRECT__minfilter(){return true;}
virtual bool end__samplerRECT__minfilter(){return true;}
virtual bool data__samplerRECT__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerRECT__magfilter(){return true;}
virtual bool end__samplerRECT__magfilter(){return true;}
virtual bool data__samplerRECT__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerRECT__mipfilter(){return true;}
virtual bool end__samplerRECT__mipfilter(){return true;}
virtual bool data__samplerRECT__mipfilter( const fx_sampler_filter_common value ){return true;}

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
virtual bool data__samplerDEPTH__wrap_s( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerDEPTH__wrap_t(){return true;}
virtual bool end__samplerDEPTH__wrap_t(){return true;}
virtual bool data__samplerDEPTH__wrap_t( const fx_sampler_wrap_common value ){return true;}

virtual bool begin__samplerDEPTH__minfilter(){return true;}
virtual bool end__samplerDEPTH__minfilter(){return true;}
virtual bool data__samplerDEPTH__minfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerDEPTH__magfilter(){return true;}
virtual bool end__samplerDEPTH__magfilter(){return true;}
virtual bool data__samplerDEPTH__magfilter( const fx_sampler_filter_common value ){return true;}

virtual bool begin__samplerDEPTH__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__samplerDEPTH__extra(){return true;}

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

virtual bool begin__profile_GLSL( const profile_GLSL__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL(){return true;}

virtual bool begin__profile_GLSL__asset(){return true;}
virtual bool end__profile_GLSL__asset(){return true;}

virtual bool begin__profile_GLSL__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__code(){return true;}
virtual bool data__profile_GLSL__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_GLSL__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__include(){return true;}

virtual bool begin__profile_GLSL__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__image(){return true;}

virtual bool begin__profile_GLSL__newparam( const profile_GLSL__newparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__newparam(){return true;}

virtual bool begin__newparam__array( const newparam__array__AttributeData& attributeData ){return true;}
virtual bool end__newparam__array(){return true;}

virtual bool begin__array__bool(){return true;}
virtual bool end__array__bool(){return true;}
virtual bool data__array__bool( bool value ){return true;}

virtual bool begin__array__bool2(){return true;}
virtual bool end__array__bool2(){return true;}
virtual bool data__array__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool3(){return true;}
virtual bool end__array__bool3(){return true;}
virtual bool data__array__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool4(){return true;}
virtual bool end__array__bool4(){return true;}
virtual bool data__array__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__array__float(){return true;}
virtual bool end__array__float(){return true;}
virtual bool data__array__float( double value ){return true;}

virtual bool begin__array__float2(){return true;}
virtual bool end__array__float2(){return true;}
virtual bool data__array__float2( const double* value, size_t length ){return true;}

virtual bool begin__array__float3(){return true;}
virtual bool end__array__float3(){return true;}
virtual bool data__array__float3( const double* value, size_t length ){return true;}

virtual bool begin__array__float4(){return true;}
virtual bool end__array__float4(){return true;}
virtual bool data__array__float4( const double* value, size_t length ){return true;}

virtual bool begin__array__float2x2(){return true;}
virtual bool end__array__float2x2(){return true;}
virtual bool data__array__float2x2( const double* value, size_t length ){return true;}

virtual bool begin__array__float3x3(){return true;}
virtual bool end__array__float3x3(){return true;}
virtual bool data__array__float3x3( const double* value, size_t length ){return true;}

virtual bool begin__array__float4x4(){return true;}
virtual bool end__array__float4x4(){return true;}
virtual bool data__array__float4x4( const double* value, size_t length ){return true;}

virtual bool begin__array__int(){return true;}
virtual bool end__array__int(){return true;}
virtual bool data__array__int( long value ){return true;}

virtual bool begin__array__int2(){return true;}
virtual bool end__array__int2(){return true;}
virtual bool data__array__int2( const long* value, size_t length ){return true;}

virtual bool begin__array__int3(){return true;}
virtual bool end__array__int3(){return true;}
virtual bool data__array__int3( const long* value, size_t length ){return true;}

virtual bool begin__array__int4(){return true;}
virtual bool end__array__int4(){return true;}
virtual bool data__array__int4( const long* value, size_t length ){return true;}

virtual bool begin__array__surface( const array__surface__AttributeData& attributeData ){return true;}
virtual bool end__array__surface(){return true;}

virtual bool begin__generator(){return true;}
virtual bool end__generator(){return true;}

virtual bool begin__generator__annotate( const annotate__AttributeData& attributeData ){return true;}
virtual bool end__generator__annotate(){return true;}

virtual bool begin__generator__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__generator__code(){return true;}
virtual bool data__generator__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__generator__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__generator__include(){return true;}

virtual bool begin__generator__name( const generator__name__AttributeData& attributeData ){return true;}
virtual bool end__generator__name(){return true;}
virtual bool data__generator__name( const ParserChar* value, size_t length ){return true;}

virtual bool begin__generator__setparam( const generator__setparam__AttributeData& attributeData ){return true;}
virtual bool end__generator__setparam(){return true;}

virtual bool begin__array__sampler1D(){return true;}
virtual bool end__array__sampler1D(){return true;}

virtual bool begin__array__sampler2D(){return true;}
virtual bool end__array__sampler2D(){return true;}

virtual bool begin__array__sampler3D(){return true;}
virtual bool end__array__sampler3D(){return true;}

virtual bool begin__array__samplerCUBE(){return true;}
virtual bool end__array__samplerCUBE(){return true;}

virtual bool begin__array__samplerRECT(){return true;}
virtual bool end__array__samplerRECT(){return true;}

virtual bool begin__array__samplerDEPTH(){return true;}
virtual bool end__array__samplerDEPTH(){return true;}

virtual bool begin__array__enum(){return true;}
virtual bool end__array__enum(){return true;}
virtual bool data__array__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__array__array( const array__array__AttributeData& attributeData ){return true;}
virtual bool end__array__array(){return true;}

virtual bool begin__profile_GLSL__technique( const profile_GLSL__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__technique(){return true;}

virtual bool begin__technique__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__technique__code(){return true;}
virtual bool data__technique__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__technique__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__technique__include(){return true;}

virtual bool begin__profile_GLSL__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__profile_GLSL__extra(){return true;}

virtual bool begin__profile_CG( const profile_CG__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG(){return true;}

virtual bool begin__profile_CG__asset(){return true;}
virtual bool end__profile_CG__asset(){return true;}

virtual bool begin__profile_CG__code( const code__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__code(){return true;}
virtual bool data__profile_CG__code( const ParserChar* value, size_t length ){return true;}

virtual bool begin__profile_CG__include( const include__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__include(){return true;}

virtual bool begin__profile_CG__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__image(){return true;}

virtual bool begin__profile_CG__newparam( const profile_CG__newparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__newparam(){return true;}

virtual bool begin__newparam__bool1(){return true;}
virtual bool end__newparam__bool1(){return true;}
virtual bool data__newparam__bool1( bool value ){return true;}

virtual bool begin__newparam__bool1x1(){return true;}
virtual bool end__newparam__bool1x1(){return true;}
virtual bool data__newparam__bool1x1( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool1x2(){return true;}
virtual bool end__newparam__bool1x2(){return true;}
virtual bool data__newparam__bool1x2( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool1x3(){return true;}
virtual bool end__newparam__bool1x3(){return true;}
virtual bool data__newparam__bool1x3( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool1x4(){return true;}
virtual bool end__newparam__bool1x4(){return true;}
virtual bool data__newparam__bool1x4( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool2x1(){return true;}
virtual bool end__newparam__bool2x1(){return true;}
virtual bool data__newparam__bool2x1( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool2x2(){return true;}
virtual bool end__newparam__bool2x2(){return true;}
virtual bool data__newparam__bool2x2( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool2x3(){return true;}
virtual bool end__newparam__bool2x3(){return true;}
virtual bool data__newparam__bool2x3( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool2x4(){return true;}
virtual bool end__newparam__bool2x4(){return true;}
virtual bool data__newparam__bool2x4( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool3x1(){return true;}
virtual bool end__newparam__bool3x1(){return true;}
virtual bool data__newparam__bool3x1( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool3x2(){return true;}
virtual bool end__newparam__bool3x2(){return true;}
virtual bool data__newparam__bool3x2( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool3x3(){return true;}
virtual bool end__newparam__bool3x3(){return true;}
virtual bool data__newparam__bool3x3( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool3x4(){return true;}
virtual bool end__newparam__bool3x4(){return true;}
virtual bool data__newparam__bool3x4( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool4x1(){return true;}
virtual bool end__newparam__bool4x1(){return true;}
virtual bool data__newparam__bool4x1( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool4x2(){return true;}
virtual bool end__newparam__bool4x2(){return true;}
virtual bool data__newparam__bool4x2( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool4x3(){return true;}
virtual bool end__newparam__bool4x3(){return true;}
virtual bool data__newparam__bool4x3( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__bool4x4(){return true;}
virtual bool end__newparam__bool4x4(){return true;}
virtual bool data__newparam__bool4x4( const bool* value, size_t length ){return true;}

virtual bool begin__newparam__float1(){return true;}
virtual bool end__newparam__float1(){return true;}
virtual bool data__newparam__float1( double value ){return true;}

virtual bool begin__newparam__int1(){return true;}
virtual bool end__newparam__int1(){return true;}
virtual bool data__newparam__int1( long value ){return true;}

virtual bool begin__newparam__int1x1(){return true;}
virtual bool end__newparam__int1x1(){return true;}
virtual bool data__newparam__int1x1( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int1x2(){return true;}
virtual bool end__newparam__int1x2(){return true;}
virtual bool data__newparam__int1x2( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int1x3(){return true;}
virtual bool end__newparam__int1x3(){return true;}
virtual bool data__newparam__int1x3( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int1x4(){return true;}
virtual bool end__newparam__int1x4(){return true;}
virtual bool data__newparam__int1x4( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int2x1(){return true;}
virtual bool end__newparam__int2x1(){return true;}
virtual bool data__newparam__int2x1( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int2x2(){return true;}
virtual bool end__newparam__int2x2(){return true;}
virtual bool data__newparam__int2x2( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int2x3(){return true;}
virtual bool end__newparam__int2x3(){return true;}
virtual bool data__newparam__int2x3( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int2x4(){return true;}
virtual bool end__newparam__int2x4(){return true;}
virtual bool data__newparam__int2x4( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int3x1(){return true;}
virtual bool end__newparam__int3x1(){return true;}
virtual bool data__newparam__int3x1( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int3x2(){return true;}
virtual bool end__newparam__int3x2(){return true;}
virtual bool data__newparam__int3x2( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int3x3(){return true;}
virtual bool end__newparam__int3x3(){return true;}
virtual bool data__newparam__int3x3( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int3x4(){return true;}
virtual bool end__newparam__int3x4(){return true;}
virtual bool data__newparam__int3x4( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int4x1(){return true;}
virtual bool end__newparam__int4x1(){return true;}
virtual bool data__newparam__int4x1( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int4x2(){return true;}
virtual bool end__newparam__int4x2(){return true;}
virtual bool data__newparam__int4x2( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int4x3(){return true;}
virtual bool end__newparam__int4x3(){return true;}
virtual bool data__newparam__int4x3( const long* value, size_t length ){return true;}

virtual bool begin__newparam__int4x4(){return true;}
virtual bool end__newparam__int4x4(){return true;}
virtual bool data__newparam__int4x4( const long* value, size_t length ){return true;}

virtual bool begin__newparam__half(){return true;}
virtual bool end__newparam__half(){return true;}
virtual bool data__newparam__half( double value ){return true;}

virtual bool begin__newparam__half1(){return true;}
virtual bool end__newparam__half1(){return true;}
virtual bool data__newparam__half1( double value ){return true;}

virtual bool begin__newparam__half2(){return true;}
virtual bool end__newparam__half2(){return true;}
virtual bool data__newparam__half2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half3(){return true;}
virtual bool end__newparam__half3(){return true;}
virtual bool data__newparam__half3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half4(){return true;}
virtual bool end__newparam__half4(){return true;}
virtual bool data__newparam__half4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half1x1(){return true;}
virtual bool end__newparam__half1x1(){return true;}
virtual bool data__newparam__half1x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half1x2(){return true;}
virtual bool end__newparam__half1x2(){return true;}
virtual bool data__newparam__half1x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half1x3(){return true;}
virtual bool end__newparam__half1x3(){return true;}
virtual bool data__newparam__half1x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half1x4(){return true;}
virtual bool end__newparam__half1x4(){return true;}
virtual bool data__newparam__half1x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half2x1(){return true;}
virtual bool end__newparam__half2x1(){return true;}
virtual bool data__newparam__half2x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half2x2(){return true;}
virtual bool end__newparam__half2x2(){return true;}
virtual bool data__newparam__half2x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half2x3(){return true;}
virtual bool end__newparam__half2x3(){return true;}
virtual bool data__newparam__half2x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half2x4(){return true;}
virtual bool end__newparam__half2x4(){return true;}
virtual bool data__newparam__half2x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half3x1(){return true;}
virtual bool end__newparam__half3x1(){return true;}
virtual bool data__newparam__half3x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half3x2(){return true;}
virtual bool end__newparam__half3x2(){return true;}
virtual bool data__newparam__half3x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half3x3(){return true;}
virtual bool end__newparam__half3x3(){return true;}
virtual bool data__newparam__half3x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half3x4(){return true;}
virtual bool end__newparam__half3x4(){return true;}
virtual bool data__newparam__half3x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half4x1(){return true;}
virtual bool end__newparam__half4x1(){return true;}
virtual bool data__newparam__half4x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half4x2(){return true;}
virtual bool end__newparam__half4x2(){return true;}
virtual bool data__newparam__half4x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half4x3(){return true;}
virtual bool end__newparam__half4x3(){return true;}
virtual bool data__newparam__half4x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__half4x4(){return true;}
virtual bool end__newparam__half4x4(){return true;}
virtual bool data__newparam__half4x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed(){return true;}
virtual bool end__newparam__fixed(){return true;}
virtual bool data__newparam__fixed( double value ){return true;}

virtual bool begin__newparam__fixed1(){return true;}
virtual bool end__newparam__fixed1(){return true;}
virtual bool data__newparam__fixed1( double value ){return true;}

virtual bool begin__newparam__fixed2(){return true;}
virtual bool end__newparam__fixed2(){return true;}
virtual bool data__newparam__fixed2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed3(){return true;}
virtual bool end__newparam__fixed3(){return true;}
virtual bool data__newparam__fixed3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed4(){return true;}
virtual bool end__newparam__fixed4(){return true;}
virtual bool data__newparam__fixed4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed1x1(){return true;}
virtual bool end__newparam__fixed1x1(){return true;}
virtual bool data__newparam__fixed1x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed1x2(){return true;}
virtual bool end__newparam__fixed1x2(){return true;}
virtual bool data__newparam__fixed1x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed1x3(){return true;}
virtual bool end__newparam__fixed1x3(){return true;}
virtual bool data__newparam__fixed1x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed1x4(){return true;}
virtual bool end__newparam__fixed1x4(){return true;}
virtual bool data__newparam__fixed1x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed2x1(){return true;}
virtual bool end__newparam__fixed2x1(){return true;}
virtual bool data__newparam__fixed2x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed2x2(){return true;}
virtual bool end__newparam__fixed2x2(){return true;}
virtual bool data__newparam__fixed2x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed2x3(){return true;}
virtual bool end__newparam__fixed2x3(){return true;}
virtual bool data__newparam__fixed2x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed2x4(){return true;}
virtual bool end__newparam__fixed2x4(){return true;}
virtual bool data__newparam__fixed2x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed3x1(){return true;}
virtual bool end__newparam__fixed3x1(){return true;}
virtual bool data__newparam__fixed3x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed3x2(){return true;}
virtual bool end__newparam__fixed3x2(){return true;}
virtual bool data__newparam__fixed3x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed3x3(){return true;}
virtual bool end__newparam__fixed3x3(){return true;}
virtual bool data__newparam__fixed3x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed3x4(){return true;}
virtual bool end__newparam__fixed3x4(){return true;}
virtual bool data__newparam__fixed3x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed4x1(){return true;}
virtual bool end__newparam__fixed4x1(){return true;}
virtual bool data__newparam__fixed4x1( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed4x2(){return true;}
virtual bool end__newparam__fixed4x2(){return true;}
virtual bool data__newparam__fixed4x2( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed4x3(){return true;}
virtual bool end__newparam__fixed4x3(){return true;}
virtual bool data__newparam__fixed4x3( const double* value, size_t length ){return true;}

virtual bool begin__newparam__fixed4x4(){return true;}
virtual bool end__newparam__fixed4x4(){return true;}
virtual bool data__newparam__fixed4x4( const double* value, size_t length ){return true;}

virtual bool begin__newparam__string(){return true;}
virtual bool end__newparam__string(){return true;}
virtual bool data__newparam__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__newparam__usertype( const usertype__AttributeData& attributeData ){return true;}
virtual bool end__newparam__usertype(){return true;}

virtual bool begin__usertype__bool(){return true;}
virtual bool end__usertype__bool(){return true;}
virtual bool data__usertype__bool( bool value ){return true;}

virtual bool begin__usertype__bool1(){return true;}
virtual bool end__usertype__bool1(){return true;}
virtual bool data__usertype__bool1( bool value ){return true;}

virtual bool begin__usertype__bool2(){return true;}
virtual bool end__usertype__bool2(){return true;}
virtual bool data__usertype__bool2( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool3(){return true;}
virtual bool end__usertype__bool3(){return true;}
virtual bool data__usertype__bool3( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool4(){return true;}
virtual bool end__usertype__bool4(){return true;}
virtual bool data__usertype__bool4( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool1x1(){return true;}
virtual bool end__usertype__bool1x1(){return true;}
virtual bool data__usertype__bool1x1( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool1x2(){return true;}
virtual bool end__usertype__bool1x2(){return true;}
virtual bool data__usertype__bool1x2( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool1x3(){return true;}
virtual bool end__usertype__bool1x3(){return true;}
virtual bool data__usertype__bool1x3( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool1x4(){return true;}
virtual bool end__usertype__bool1x4(){return true;}
virtual bool data__usertype__bool1x4( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool2x1(){return true;}
virtual bool end__usertype__bool2x1(){return true;}
virtual bool data__usertype__bool2x1( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool2x2(){return true;}
virtual bool end__usertype__bool2x2(){return true;}
virtual bool data__usertype__bool2x2( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool2x3(){return true;}
virtual bool end__usertype__bool2x3(){return true;}
virtual bool data__usertype__bool2x3( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool2x4(){return true;}
virtual bool end__usertype__bool2x4(){return true;}
virtual bool data__usertype__bool2x4( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool3x1(){return true;}
virtual bool end__usertype__bool3x1(){return true;}
virtual bool data__usertype__bool3x1( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool3x2(){return true;}
virtual bool end__usertype__bool3x2(){return true;}
virtual bool data__usertype__bool3x2( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool3x3(){return true;}
virtual bool end__usertype__bool3x3(){return true;}
virtual bool data__usertype__bool3x3( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool3x4(){return true;}
virtual bool end__usertype__bool3x4(){return true;}
virtual bool data__usertype__bool3x4( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool4x1(){return true;}
virtual bool end__usertype__bool4x1(){return true;}
virtual bool data__usertype__bool4x1( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool4x2(){return true;}
virtual bool end__usertype__bool4x2(){return true;}
virtual bool data__usertype__bool4x2( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool4x3(){return true;}
virtual bool end__usertype__bool4x3(){return true;}
virtual bool data__usertype__bool4x3( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__bool4x4(){return true;}
virtual bool end__usertype__bool4x4(){return true;}
virtual bool data__usertype__bool4x4( const bool* value, size_t length ){return true;}

virtual bool begin__usertype__float(){return true;}
virtual bool end__usertype__float(){return true;}
virtual bool data__usertype__float( double value ){return true;}

virtual bool begin__usertype__float1(){return true;}
virtual bool end__usertype__float1(){return true;}
virtual bool data__usertype__float1( double value ){return true;}

virtual bool begin__usertype__float2(){return true;}
virtual bool end__usertype__float2(){return true;}
virtual bool data__usertype__float2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float3(){return true;}
virtual bool end__usertype__float3(){return true;}
virtual bool data__usertype__float3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float4(){return true;}
virtual bool end__usertype__float4(){return true;}
virtual bool data__usertype__float4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float1x1(){return true;}
virtual bool end__usertype__float1x1(){return true;}
virtual bool data__usertype__float1x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float1x2(){return true;}
virtual bool end__usertype__float1x2(){return true;}
virtual bool data__usertype__float1x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float1x3(){return true;}
virtual bool end__usertype__float1x3(){return true;}
virtual bool data__usertype__float1x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float1x4(){return true;}
virtual bool end__usertype__float1x4(){return true;}
virtual bool data__usertype__float1x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float2x1(){return true;}
virtual bool end__usertype__float2x1(){return true;}
virtual bool data__usertype__float2x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float2x2(){return true;}
virtual bool end__usertype__float2x2(){return true;}
virtual bool data__usertype__float2x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float2x3(){return true;}
virtual bool end__usertype__float2x3(){return true;}
virtual bool data__usertype__float2x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float2x4(){return true;}
virtual bool end__usertype__float2x4(){return true;}
virtual bool data__usertype__float2x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float3x1(){return true;}
virtual bool end__usertype__float3x1(){return true;}
virtual bool data__usertype__float3x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float3x2(){return true;}
virtual bool end__usertype__float3x2(){return true;}
virtual bool data__usertype__float3x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float3x3(){return true;}
virtual bool end__usertype__float3x3(){return true;}
virtual bool data__usertype__float3x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float3x4(){return true;}
virtual bool end__usertype__float3x4(){return true;}
virtual bool data__usertype__float3x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float4x1(){return true;}
virtual bool end__usertype__float4x1(){return true;}
virtual bool data__usertype__float4x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float4x2(){return true;}
virtual bool end__usertype__float4x2(){return true;}
virtual bool data__usertype__float4x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float4x3(){return true;}
virtual bool end__usertype__float4x3(){return true;}
virtual bool data__usertype__float4x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__float4x4(){return true;}
virtual bool end__usertype__float4x4(){return true;}
virtual bool data__usertype__float4x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__int(){return true;}
virtual bool end__usertype__int(){return true;}
virtual bool data__usertype__int( long value ){return true;}

virtual bool begin__usertype__int1(){return true;}
virtual bool end__usertype__int1(){return true;}
virtual bool data__usertype__int1( long value ){return true;}

virtual bool begin__usertype__int2(){return true;}
virtual bool end__usertype__int2(){return true;}
virtual bool data__usertype__int2( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int3(){return true;}
virtual bool end__usertype__int3(){return true;}
virtual bool data__usertype__int3( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int4(){return true;}
virtual bool end__usertype__int4(){return true;}
virtual bool data__usertype__int4( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int1x1(){return true;}
virtual bool end__usertype__int1x1(){return true;}
virtual bool data__usertype__int1x1( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int1x2(){return true;}
virtual bool end__usertype__int1x2(){return true;}
virtual bool data__usertype__int1x2( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int1x3(){return true;}
virtual bool end__usertype__int1x3(){return true;}
virtual bool data__usertype__int1x3( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int1x4(){return true;}
virtual bool end__usertype__int1x4(){return true;}
virtual bool data__usertype__int1x4( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int2x1(){return true;}
virtual bool end__usertype__int2x1(){return true;}
virtual bool data__usertype__int2x1( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int2x2(){return true;}
virtual bool end__usertype__int2x2(){return true;}
virtual bool data__usertype__int2x2( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int2x3(){return true;}
virtual bool end__usertype__int2x3(){return true;}
virtual bool data__usertype__int2x3( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int2x4(){return true;}
virtual bool end__usertype__int2x4(){return true;}
virtual bool data__usertype__int2x4( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int3x1(){return true;}
virtual bool end__usertype__int3x1(){return true;}
virtual bool data__usertype__int3x1( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int3x2(){return true;}
virtual bool end__usertype__int3x2(){return true;}
virtual bool data__usertype__int3x2( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int3x3(){return true;}
virtual bool end__usertype__int3x3(){return true;}
virtual bool data__usertype__int3x3( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int3x4(){return true;}
virtual bool end__usertype__int3x4(){return true;}
virtual bool data__usertype__int3x4( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int4x1(){return true;}
virtual bool end__usertype__int4x1(){return true;}
virtual bool data__usertype__int4x1( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int4x2(){return true;}
virtual bool end__usertype__int4x2(){return true;}
virtual bool data__usertype__int4x2( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int4x3(){return true;}
virtual bool end__usertype__int4x3(){return true;}
virtual bool data__usertype__int4x3( const long* value, size_t length ){return true;}

virtual bool begin__usertype__int4x4(){return true;}
virtual bool end__usertype__int4x4(){return true;}
virtual bool data__usertype__int4x4( const long* value, size_t length ){return true;}

virtual bool begin__usertype__half(){return true;}
virtual bool end__usertype__half(){return true;}
virtual bool data__usertype__half( double value ){return true;}

virtual bool begin__usertype__half1(){return true;}
virtual bool end__usertype__half1(){return true;}
virtual bool data__usertype__half1( double value ){return true;}

virtual bool begin__usertype__half2(){return true;}
virtual bool end__usertype__half2(){return true;}
virtual bool data__usertype__half2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half3(){return true;}
virtual bool end__usertype__half3(){return true;}
virtual bool data__usertype__half3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half4(){return true;}
virtual bool end__usertype__half4(){return true;}
virtual bool data__usertype__half4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half1x1(){return true;}
virtual bool end__usertype__half1x1(){return true;}
virtual bool data__usertype__half1x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half1x2(){return true;}
virtual bool end__usertype__half1x2(){return true;}
virtual bool data__usertype__half1x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half1x3(){return true;}
virtual bool end__usertype__half1x3(){return true;}
virtual bool data__usertype__half1x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half1x4(){return true;}
virtual bool end__usertype__half1x4(){return true;}
virtual bool data__usertype__half1x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half2x1(){return true;}
virtual bool end__usertype__half2x1(){return true;}
virtual bool data__usertype__half2x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half2x2(){return true;}
virtual bool end__usertype__half2x2(){return true;}
virtual bool data__usertype__half2x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half2x3(){return true;}
virtual bool end__usertype__half2x3(){return true;}
virtual bool data__usertype__half2x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half2x4(){return true;}
virtual bool end__usertype__half2x4(){return true;}
virtual bool data__usertype__half2x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half3x1(){return true;}
virtual bool end__usertype__half3x1(){return true;}
virtual bool data__usertype__half3x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half3x2(){return true;}
virtual bool end__usertype__half3x2(){return true;}
virtual bool data__usertype__half3x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half3x3(){return true;}
virtual bool end__usertype__half3x3(){return true;}
virtual bool data__usertype__half3x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half3x4(){return true;}
virtual bool end__usertype__half3x4(){return true;}
virtual bool data__usertype__half3x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half4x1(){return true;}
virtual bool end__usertype__half4x1(){return true;}
virtual bool data__usertype__half4x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half4x2(){return true;}
virtual bool end__usertype__half4x2(){return true;}
virtual bool data__usertype__half4x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half4x3(){return true;}
virtual bool end__usertype__half4x3(){return true;}
virtual bool data__usertype__half4x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__half4x4(){return true;}
virtual bool end__usertype__half4x4(){return true;}
virtual bool data__usertype__half4x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed(){return true;}
virtual bool end__usertype__fixed(){return true;}
virtual bool data__usertype__fixed( double value ){return true;}

virtual bool begin__usertype__fixed1(){return true;}
virtual bool end__usertype__fixed1(){return true;}
virtual bool data__usertype__fixed1( double value ){return true;}

virtual bool begin__usertype__fixed2(){return true;}
virtual bool end__usertype__fixed2(){return true;}
virtual bool data__usertype__fixed2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed3(){return true;}
virtual bool end__usertype__fixed3(){return true;}
virtual bool data__usertype__fixed3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed4(){return true;}
virtual bool end__usertype__fixed4(){return true;}
virtual bool data__usertype__fixed4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed1x1(){return true;}
virtual bool end__usertype__fixed1x1(){return true;}
virtual bool data__usertype__fixed1x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed1x2(){return true;}
virtual bool end__usertype__fixed1x2(){return true;}
virtual bool data__usertype__fixed1x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed1x3(){return true;}
virtual bool end__usertype__fixed1x3(){return true;}
virtual bool data__usertype__fixed1x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed1x4(){return true;}
virtual bool end__usertype__fixed1x4(){return true;}
virtual bool data__usertype__fixed1x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed2x1(){return true;}
virtual bool end__usertype__fixed2x1(){return true;}
virtual bool data__usertype__fixed2x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed2x2(){return true;}
virtual bool end__usertype__fixed2x2(){return true;}
virtual bool data__usertype__fixed2x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed2x3(){return true;}
virtual bool end__usertype__fixed2x3(){return true;}
virtual bool data__usertype__fixed2x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed2x4(){return true;}
virtual bool end__usertype__fixed2x4(){return true;}
virtual bool data__usertype__fixed2x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed3x1(){return true;}
virtual bool end__usertype__fixed3x1(){return true;}
virtual bool data__usertype__fixed3x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed3x2(){return true;}
virtual bool end__usertype__fixed3x2(){return true;}
virtual bool data__usertype__fixed3x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed3x3(){return true;}
virtual bool end__usertype__fixed3x3(){return true;}
virtual bool data__usertype__fixed3x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed3x4(){return true;}
virtual bool end__usertype__fixed3x4(){return true;}
virtual bool data__usertype__fixed3x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed4x1(){return true;}
virtual bool end__usertype__fixed4x1(){return true;}
virtual bool data__usertype__fixed4x1( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed4x2(){return true;}
virtual bool end__usertype__fixed4x2(){return true;}
virtual bool data__usertype__fixed4x2( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed4x3(){return true;}
virtual bool end__usertype__fixed4x3(){return true;}
virtual bool data__usertype__fixed4x3( const double* value, size_t length ){return true;}

virtual bool begin__usertype__fixed4x4(){return true;}
virtual bool end__usertype__fixed4x4(){return true;}
virtual bool data__usertype__fixed4x4( const double* value, size_t length ){return true;}

virtual bool begin__usertype__surface( const usertype__surface__AttributeData& attributeData ){return true;}
virtual bool end__usertype__surface(){return true;}

virtual bool begin__usertype__sampler1D(){return true;}
virtual bool end__usertype__sampler1D(){return true;}

virtual bool begin__usertype__sampler2D(){return true;}
virtual bool end__usertype__sampler2D(){return true;}

virtual bool begin__usertype__sampler3D(){return true;}
virtual bool end__usertype__sampler3D(){return true;}

virtual bool begin__usertype__samplerRECT(){return true;}
virtual bool end__usertype__samplerRECT(){return true;}

virtual bool begin__usertype__samplerCUBE(){return true;}
virtual bool end__usertype__samplerCUBE(){return true;}

virtual bool begin__usertype__samplerDEPTH(){return true;}
virtual bool end__usertype__samplerDEPTH(){return true;}

virtual bool begin__usertype__string(){return true;}
virtual bool end__usertype__string(){return true;}
virtual bool data__usertype__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__usertype__enum(){return true;}
virtual bool end__usertype__enum(){return true;}
virtual bool data__usertype__enum( const ParserChar* value, size_t length ){return true;}

virtual bool begin__usertype__array( const usertype__array__AttributeData& attributeData ){return true;}
virtual bool end__usertype__array(){return true;}

virtual bool begin__array__bool1(){return true;}
virtual bool end__array__bool1(){return true;}
virtual bool data__array__bool1( bool value ){return true;}

virtual bool begin__array__bool1x1(){return true;}
virtual bool end__array__bool1x1(){return true;}
virtual bool data__array__bool1x1( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool1x2(){return true;}
virtual bool end__array__bool1x2(){return true;}
virtual bool data__array__bool1x2( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool1x3(){return true;}
virtual bool end__array__bool1x3(){return true;}
virtual bool data__array__bool1x3( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool1x4(){return true;}
virtual bool end__array__bool1x4(){return true;}
virtual bool data__array__bool1x4( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool2x1(){return true;}
virtual bool end__array__bool2x1(){return true;}
virtual bool data__array__bool2x1( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool2x2(){return true;}
virtual bool end__array__bool2x2(){return true;}
virtual bool data__array__bool2x2( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool2x3(){return true;}
virtual bool end__array__bool2x3(){return true;}
virtual bool data__array__bool2x3( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool2x4(){return true;}
virtual bool end__array__bool2x4(){return true;}
virtual bool data__array__bool2x4( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool3x1(){return true;}
virtual bool end__array__bool3x1(){return true;}
virtual bool data__array__bool3x1( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool3x2(){return true;}
virtual bool end__array__bool3x2(){return true;}
virtual bool data__array__bool3x2( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool3x3(){return true;}
virtual bool end__array__bool3x3(){return true;}
virtual bool data__array__bool3x3( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool3x4(){return true;}
virtual bool end__array__bool3x4(){return true;}
virtual bool data__array__bool3x4( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool4x1(){return true;}
virtual bool end__array__bool4x1(){return true;}
virtual bool data__array__bool4x1( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool4x2(){return true;}
virtual bool end__array__bool4x2(){return true;}
virtual bool data__array__bool4x2( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool4x3(){return true;}
virtual bool end__array__bool4x3(){return true;}
virtual bool data__array__bool4x3( const bool* value, size_t length ){return true;}

virtual bool begin__array__bool4x4(){return true;}
virtual bool end__array__bool4x4(){return true;}
virtual bool data__array__bool4x4( const bool* value, size_t length ){return true;}

virtual bool begin__array__float1(){return true;}
virtual bool end__array__float1(){return true;}
virtual bool data__array__float1( double value ){return true;}

virtual bool begin__array__float1x1(){return true;}
virtual bool end__array__float1x1(){return true;}
virtual bool data__array__float1x1( const double* value, size_t length ){return true;}

virtual bool begin__array__float1x2(){return true;}
virtual bool end__array__float1x2(){return true;}
virtual bool data__array__float1x2( const double* value, size_t length ){return true;}

virtual bool begin__array__float1x3(){return true;}
virtual bool end__array__float1x3(){return true;}
virtual bool data__array__float1x3( const double* value, size_t length ){return true;}

virtual bool begin__array__float1x4(){return true;}
virtual bool end__array__float1x4(){return true;}
virtual bool data__array__float1x4( const double* value, size_t length ){return true;}

virtual bool begin__array__float2x1(){return true;}
virtual bool end__array__float2x1(){return true;}
virtual bool data__array__float2x1( const double* value, size_t length ){return true;}

virtual bool begin__array__float2x3(){return true;}
virtual bool end__array__float2x3(){return true;}
virtual bool data__array__float2x3( const double* value, size_t length ){return true;}

virtual bool begin__array__float2x4(){return true;}
virtual bool end__array__float2x4(){return true;}
virtual bool data__array__float2x4( const double* value, size_t length ){return true;}

virtual bool begin__array__float3x1(){return true;}
virtual bool end__array__float3x1(){return true;}
virtual bool data__array__float3x1( const double* value, size_t length ){return true;}

virtual bool begin__array__float3x2(){return true;}
virtual bool end__array__float3x2(){return true;}
virtual bool data__array__float3x2( const double* value, size_t length ){return true;}

virtual bool begin__array__float3x4(){return true;}
virtual bool end__array__float3x4(){return true;}
virtual bool data__array__float3x4( const double* value, size_t length ){return true;}

virtual bool begin__array__float4x1(){return true;}
virtual bool end__array__float4x1(){return true;}
virtual bool data__array__float4x1( const double* value, size_t length ){return true;}

virtual bool begin__array__float4x2(){return true;}
virtual bool end__array__float4x2(){return true;}
virtual bool data__array__float4x2( const double* value, size_t length ){return true;}

virtual bool begin__array__float4x3(){return true;}
virtual bool end__array__float4x3(){return true;}
virtual bool data__array__float4x3( const double* value, size_t length ){return true;}

virtual bool begin__array__int1(){return true;}
virtual bool end__array__int1(){return true;}
virtual bool data__array__int1( long value ){return true;}

virtual bool begin__array__int1x1(){return true;}
virtual bool end__array__int1x1(){return true;}
virtual bool data__array__int1x1( const long* value, size_t length ){return true;}

virtual bool begin__array__int1x2(){return true;}
virtual bool end__array__int1x2(){return true;}
virtual bool data__array__int1x2( const long* value, size_t length ){return true;}

virtual bool begin__array__int1x3(){return true;}
virtual bool end__array__int1x3(){return true;}
virtual bool data__array__int1x3( const long* value, size_t length ){return true;}

virtual bool begin__array__int1x4(){return true;}
virtual bool end__array__int1x4(){return true;}
virtual bool data__array__int1x4( const long* value, size_t length ){return true;}

virtual bool begin__array__int2x1(){return true;}
virtual bool end__array__int2x1(){return true;}
virtual bool data__array__int2x1( const long* value, size_t length ){return true;}

virtual bool begin__array__int2x2(){return true;}
virtual bool end__array__int2x2(){return true;}
virtual bool data__array__int2x2( const long* value, size_t length ){return true;}

virtual bool begin__array__int2x3(){return true;}
virtual bool end__array__int2x3(){return true;}
virtual bool data__array__int2x3( const long* value, size_t length ){return true;}

virtual bool begin__array__int2x4(){return true;}
virtual bool end__array__int2x4(){return true;}
virtual bool data__array__int2x4( const long* value, size_t length ){return true;}

virtual bool begin__array__int3x1(){return true;}
virtual bool end__array__int3x1(){return true;}
virtual bool data__array__int3x1( const long* value, size_t length ){return true;}

virtual bool begin__array__int3x2(){return true;}
virtual bool end__array__int3x2(){return true;}
virtual bool data__array__int3x2( const long* value, size_t length ){return true;}

virtual bool begin__array__int3x3(){return true;}
virtual bool end__array__int3x3(){return true;}
virtual bool data__array__int3x3( const long* value, size_t length ){return true;}

virtual bool begin__array__int3x4(){return true;}
virtual bool end__array__int3x4(){return true;}
virtual bool data__array__int3x4( const long* value, size_t length ){return true;}

virtual bool begin__array__int4x1(){return true;}
virtual bool end__array__int4x1(){return true;}
virtual bool data__array__int4x1( const long* value, size_t length ){return true;}

virtual bool begin__array__int4x2(){return true;}
virtual bool end__array__int4x2(){return true;}
virtual bool data__array__int4x2( const long* value, size_t length ){return true;}

virtual bool begin__array__int4x3(){return true;}
virtual bool end__array__int4x3(){return true;}
virtual bool data__array__int4x3( const long* value, size_t length ){return true;}

virtual bool begin__array__int4x4(){return true;}
virtual bool end__array__int4x4(){return true;}
virtual bool data__array__int4x4( const long* value, size_t length ){return true;}

virtual bool begin__array__half(){return true;}
virtual bool end__array__half(){return true;}
virtual bool data__array__half( double value ){return true;}

virtual bool begin__array__half1(){return true;}
virtual bool end__array__half1(){return true;}
virtual bool data__array__half1( double value ){return true;}

virtual bool begin__array__half2(){return true;}
virtual bool end__array__half2(){return true;}
virtual bool data__array__half2( const double* value, size_t length ){return true;}

virtual bool begin__array__half3(){return true;}
virtual bool end__array__half3(){return true;}
virtual bool data__array__half3( const double* value, size_t length ){return true;}

virtual bool begin__array__half4(){return true;}
virtual bool end__array__half4(){return true;}
virtual bool data__array__half4( const double* value, size_t length ){return true;}

virtual bool begin__array__half1x1(){return true;}
virtual bool end__array__half1x1(){return true;}
virtual bool data__array__half1x1( const double* value, size_t length ){return true;}

virtual bool begin__array__half1x2(){return true;}
virtual bool end__array__half1x2(){return true;}
virtual bool data__array__half1x2( const double* value, size_t length ){return true;}

virtual bool begin__array__half1x3(){return true;}
virtual bool end__array__half1x3(){return true;}
virtual bool data__array__half1x3( const double* value, size_t length ){return true;}

virtual bool begin__array__half1x4(){return true;}
virtual bool end__array__half1x4(){return true;}
virtual bool data__array__half1x4( const double* value, size_t length ){return true;}

virtual bool begin__array__half2x1(){return true;}
virtual bool end__array__half2x1(){return true;}
virtual bool data__array__half2x1( const double* value, size_t length ){return true;}

virtual bool begin__array__half2x2(){return true;}
virtual bool end__array__half2x2(){return true;}
virtual bool data__array__half2x2( const double* value, size_t length ){return true;}

virtual bool begin__array__half2x3(){return true;}
virtual bool end__array__half2x3(){return true;}
virtual bool data__array__half2x3( const double* value, size_t length ){return true;}

virtual bool begin__array__half2x4(){return true;}
virtual bool end__array__half2x4(){return true;}
virtual bool data__array__half2x4( const double* value, size_t length ){return true;}

virtual bool begin__array__half3x1(){return true;}
virtual bool end__array__half3x1(){return true;}
virtual bool data__array__half3x1( const double* value, size_t length ){return true;}

virtual bool begin__array__half3x2(){return true;}
virtual bool end__array__half3x2(){return true;}
virtual bool data__array__half3x2( const double* value, size_t length ){return true;}

virtual bool begin__array__half3x3(){return true;}
virtual bool end__array__half3x3(){return true;}
virtual bool data__array__half3x3( const double* value, size_t length ){return true;}

virtual bool begin__array__half3x4(){return true;}
virtual bool end__array__half3x4(){return true;}
virtual bool data__array__half3x4( const double* value, size_t length ){return true;}

virtual bool begin__array__half4x1(){return true;}
virtual bool end__array__half4x1(){return true;}
virtual bool data__array__half4x1( const double* value, size_t length ){return true;}

virtual bool begin__array__half4x2(){return true;}
virtual bool end__array__half4x2(){return true;}
virtual bool data__array__half4x2( const double* value, size_t length ){return true;}

virtual bool begin__array__half4x3(){return true;}
virtual bool end__array__half4x3(){return true;}
virtual bool data__array__half4x3( const double* value, size_t length ){return true;}

virtual bool begin__array__half4x4(){return true;}
virtual bool end__array__half4x4(){return true;}
virtual bool data__array__half4x4( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed(){return true;}
virtual bool end__array__fixed(){return true;}
virtual bool data__array__fixed( double value ){return true;}

virtual bool begin__array__fixed1(){return true;}
virtual bool end__array__fixed1(){return true;}
virtual bool data__array__fixed1( double value ){return true;}

virtual bool begin__array__fixed2(){return true;}
virtual bool end__array__fixed2(){return true;}
virtual bool data__array__fixed2( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed3(){return true;}
virtual bool end__array__fixed3(){return true;}
virtual bool data__array__fixed3( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed4(){return true;}
virtual bool end__array__fixed4(){return true;}
virtual bool data__array__fixed4( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed1x1(){return true;}
virtual bool end__array__fixed1x1(){return true;}
virtual bool data__array__fixed1x1( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed1x2(){return true;}
virtual bool end__array__fixed1x2(){return true;}
virtual bool data__array__fixed1x2( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed1x3(){return true;}
virtual bool end__array__fixed1x3(){return true;}
virtual bool data__array__fixed1x3( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed1x4(){return true;}
virtual bool end__array__fixed1x4(){return true;}
virtual bool data__array__fixed1x4( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed2x1(){return true;}
virtual bool end__array__fixed2x1(){return true;}
virtual bool data__array__fixed2x1( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed2x2(){return true;}
virtual bool end__array__fixed2x2(){return true;}
virtual bool data__array__fixed2x2( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed2x3(){return true;}
virtual bool end__array__fixed2x3(){return true;}
virtual bool data__array__fixed2x3( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed2x4(){return true;}
virtual bool end__array__fixed2x4(){return true;}
virtual bool data__array__fixed2x4( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed3x1(){return true;}
virtual bool end__array__fixed3x1(){return true;}
virtual bool data__array__fixed3x1( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed3x2(){return true;}
virtual bool end__array__fixed3x2(){return true;}
virtual bool data__array__fixed3x2( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed3x3(){return true;}
virtual bool end__array__fixed3x3(){return true;}
virtual bool data__array__fixed3x3( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed3x4(){return true;}
virtual bool end__array__fixed3x4(){return true;}
virtual bool data__array__fixed3x4( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed4x1(){return true;}
virtual bool end__array__fixed4x1(){return true;}
virtual bool data__array__fixed4x1( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed4x2(){return true;}
virtual bool end__array__fixed4x2(){return true;}
virtual bool data__array__fixed4x2( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed4x3(){return true;}
virtual bool end__array__fixed4x3(){return true;}
virtual bool data__array__fixed4x3( const double* value, size_t length ){return true;}

virtual bool begin__array__fixed4x4(){return true;}
virtual bool end__array__fixed4x4(){return true;}
virtual bool data__array__fixed4x4( const double* value, size_t length ){return true;}

virtual bool begin__array__string(){return true;}
virtual bool end__array__string(){return true;}
virtual bool data__array__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__array__usertype( const usertype__AttributeData& attributeData ){return true;}
virtual bool end__array__usertype(){return true;}

virtual bool begin__usertype__usertype( const usertype__AttributeData& attributeData ){return true;}
virtual bool end__usertype__usertype(){return true;}

virtual bool begin__usertype__connect_param( const connect_param__AttributeData& attributeData ){return true;}
virtual bool end__usertype__connect_param(){return true;}

virtual bool begin__usertype__setparam( const usertype__setparam__AttributeData& attributeData ){return true;}
virtual bool end__usertype__setparam(){return true;}

virtual bool begin__setparam__bool1(){return true;}
virtual bool end__setparam__bool1(){return true;}
virtual bool data__setparam__bool1( bool value ){return true;}

virtual bool begin__setparam__bool1x1(){return true;}
virtual bool end__setparam__bool1x1(){return true;}
virtual bool data__setparam__bool1x1( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool1x2(){return true;}
virtual bool end__setparam__bool1x2(){return true;}
virtual bool data__setparam__bool1x2( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool1x3(){return true;}
virtual bool end__setparam__bool1x3(){return true;}
virtual bool data__setparam__bool1x3( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool1x4(){return true;}
virtual bool end__setparam__bool1x4(){return true;}
virtual bool data__setparam__bool1x4( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool2x1(){return true;}
virtual bool end__setparam__bool2x1(){return true;}
virtual bool data__setparam__bool2x1( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool2x2(){return true;}
virtual bool end__setparam__bool2x2(){return true;}
virtual bool data__setparam__bool2x2( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool2x3(){return true;}
virtual bool end__setparam__bool2x3(){return true;}
virtual bool data__setparam__bool2x3( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool2x4(){return true;}
virtual bool end__setparam__bool2x4(){return true;}
virtual bool data__setparam__bool2x4( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool3x1(){return true;}
virtual bool end__setparam__bool3x1(){return true;}
virtual bool data__setparam__bool3x1( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool3x2(){return true;}
virtual bool end__setparam__bool3x2(){return true;}
virtual bool data__setparam__bool3x2( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool3x3(){return true;}
virtual bool end__setparam__bool3x3(){return true;}
virtual bool data__setparam__bool3x3( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool3x4(){return true;}
virtual bool end__setparam__bool3x4(){return true;}
virtual bool data__setparam__bool3x4( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool4x1(){return true;}
virtual bool end__setparam__bool4x1(){return true;}
virtual bool data__setparam__bool4x1( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool4x2(){return true;}
virtual bool end__setparam__bool4x2(){return true;}
virtual bool data__setparam__bool4x2( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool4x3(){return true;}
virtual bool end__setparam__bool4x3(){return true;}
virtual bool data__setparam__bool4x3( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__bool4x4(){return true;}
virtual bool end__setparam__bool4x4(){return true;}
virtual bool data__setparam__bool4x4( const bool* value, size_t length ){return true;}

virtual bool begin__setparam__float1(){return true;}
virtual bool end__setparam__float1(){return true;}
virtual bool data__setparam__float1( double value ){return true;}

virtual bool begin__setparam__int1(){return true;}
virtual bool end__setparam__int1(){return true;}
virtual bool data__setparam__int1( long value ){return true;}

virtual bool begin__setparam__int1x1(){return true;}
virtual bool end__setparam__int1x1(){return true;}
virtual bool data__setparam__int1x1( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int1x2(){return true;}
virtual bool end__setparam__int1x2(){return true;}
virtual bool data__setparam__int1x2( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int1x3(){return true;}
virtual bool end__setparam__int1x3(){return true;}
virtual bool data__setparam__int1x3( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int1x4(){return true;}
virtual bool end__setparam__int1x4(){return true;}
virtual bool data__setparam__int1x4( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int2x1(){return true;}
virtual bool end__setparam__int2x1(){return true;}
virtual bool data__setparam__int2x1( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int2x2(){return true;}
virtual bool end__setparam__int2x2(){return true;}
virtual bool data__setparam__int2x2( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int2x3(){return true;}
virtual bool end__setparam__int2x3(){return true;}
virtual bool data__setparam__int2x3( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int2x4(){return true;}
virtual bool end__setparam__int2x4(){return true;}
virtual bool data__setparam__int2x4( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int3x1(){return true;}
virtual bool end__setparam__int3x1(){return true;}
virtual bool data__setparam__int3x1( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int3x2(){return true;}
virtual bool end__setparam__int3x2(){return true;}
virtual bool data__setparam__int3x2( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int3x3(){return true;}
virtual bool end__setparam__int3x3(){return true;}
virtual bool data__setparam__int3x3( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int3x4(){return true;}
virtual bool end__setparam__int3x4(){return true;}
virtual bool data__setparam__int3x4( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int4x1(){return true;}
virtual bool end__setparam__int4x1(){return true;}
virtual bool data__setparam__int4x1( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int4x2(){return true;}
virtual bool end__setparam__int4x2(){return true;}
virtual bool data__setparam__int4x2( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int4x3(){return true;}
virtual bool end__setparam__int4x3(){return true;}
virtual bool data__setparam__int4x3( const long* value, size_t length ){return true;}

virtual bool begin__setparam__int4x4(){return true;}
virtual bool end__setparam__int4x4(){return true;}
virtual bool data__setparam__int4x4( const long* value, size_t length ){return true;}

virtual bool begin__setparam__half(){return true;}
virtual bool end__setparam__half(){return true;}
virtual bool data__setparam__half( double value ){return true;}

virtual bool begin__setparam__half1(){return true;}
virtual bool end__setparam__half1(){return true;}
virtual bool data__setparam__half1( double value ){return true;}

virtual bool begin__setparam__half2(){return true;}
virtual bool end__setparam__half2(){return true;}
virtual bool data__setparam__half2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half3(){return true;}
virtual bool end__setparam__half3(){return true;}
virtual bool data__setparam__half3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half4(){return true;}
virtual bool end__setparam__half4(){return true;}
virtual bool data__setparam__half4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half1x1(){return true;}
virtual bool end__setparam__half1x1(){return true;}
virtual bool data__setparam__half1x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half1x2(){return true;}
virtual bool end__setparam__half1x2(){return true;}
virtual bool data__setparam__half1x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half1x3(){return true;}
virtual bool end__setparam__half1x3(){return true;}
virtual bool data__setparam__half1x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half1x4(){return true;}
virtual bool end__setparam__half1x4(){return true;}
virtual bool data__setparam__half1x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half2x1(){return true;}
virtual bool end__setparam__half2x1(){return true;}
virtual bool data__setparam__half2x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half2x2(){return true;}
virtual bool end__setparam__half2x2(){return true;}
virtual bool data__setparam__half2x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half2x3(){return true;}
virtual bool end__setparam__half2x3(){return true;}
virtual bool data__setparam__half2x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half2x4(){return true;}
virtual bool end__setparam__half2x4(){return true;}
virtual bool data__setparam__half2x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half3x1(){return true;}
virtual bool end__setparam__half3x1(){return true;}
virtual bool data__setparam__half3x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half3x2(){return true;}
virtual bool end__setparam__half3x2(){return true;}
virtual bool data__setparam__half3x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half3x3(){return true;}
virtual bool end__setparam__half3x3(){return true;}
virtual bool data__setparam__half3x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half3x4(){return true;}
virtual bool end__setparam__half3x4(){return true;}
virtual bool data__setparam__half3x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half4x1(){return true;}
virtual bool end__setparam__half4x1(){return true;}
virtual bool data__setparam__half4x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half4x2(){return true;}
virtual bool end__setparam__half4x2(){return true;}
virtual bool data__setparam__half4x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half4x3(){return true;}
virtual bool end__setparam__half4x3(){return true;}
virtual bool data__setparam__half4x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__half4x4(){return true;}
virtual bool end__setparam__half4x4(){return true;}
virtual bool data__setparam__half4x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed(){return true;}
virtual bool end__setparam__fixed(){return true;}
virtual bool data__setparam__fixed( double value ){return true;}

virtual bool begin__setparam__fixed1(){return true;}
virtual bool end__setparam__fixed1(){return true;}
virtual bool data__setparam__fixed1( double value ){return true;}

virtual bool begin__setparam__fixed2(){return true;}
virtual bool end__setparam__fixed2(){return true;}
virtual bool data__setparam__fixed2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed3(){return true;}
virtual bool end__setparam__fixed3(){return true;}
virtual bool data__setparam__fixed3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed4(){return true;}
virtual bool end__setparam__fixed4(){return true;}
virtual bool data__setparam__fixed4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed1x1(){return true;}
virtual bool end__setparam__fixed1x1(){return true;}
virtual bool data__setparam__fixed1x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed1x2(){return true;}
virtual bool end__setparam__fixed1x2(){return true;}
virtual bool data__setparam__fixed1x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed1x3(){return true;}
virtual bool end__setparam__fixed1x3(){return true;}
virtual bool data__setparam__fixed1x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed1x4(){return true;}
virtual bool end__setparam__fixed1x4(){return true;}
virtual bool data__setparam__fixed1x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed2x1(){return true;}
virtual bool end__setparam__fixed2x1(){return true;}
virtual bool data__setparam__fixed2x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed2x2(){return true;}
virtual bool end__setparam__fixed2x2(){return true;}
virtual bool data__setparam__fixed2x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed2x3(){return true;}
virtual bool end__setparam__fixed2x3(){return true;}
virtual bool data__setparam__fixed2x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed2x4(){return true;}
virtual bool end__setparam__fixed2x4(){return true;}
virtual bool data__setparam__fixed2x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed3x1(){return true;}
virtual bool end__setparam__fixed3x1(){return true;}
virtual bool data__setparam__fixed3x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed3x2(){return true;}
virtual bool end__setparam__fixed3x2(){return true;}
virtual bool data__setparam__fixed3x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed3x3(){return true;}
virtual bool end__setparam__fixed3x3(){return true;}
virtual bool data__setparam__fixed3x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed3x4(){return true;}
virtual bool end__setparam__fixed3x4(){return true;}
virtual bool data__setparam__fixed3x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed4x1(){return true;}
virtual bool end__setparam__fixed4x1(){return true;}
virtual bool data__setparam__fixed4x1( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed4x2(){return true;}
virtual bool end__setparam__fixed4x2(){return true;}
virtual bool data__setparam__fixed4x2( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed4x3(){return true;}
virtual bool end__setparam__fixed4x3(){return true;}
virtual bool data__setparam__fixed4x3( const double* value, size_t length ){return true;}

virtual bool begin__setparam__fixed4x4(){return true;}
virtual bool end__setparam__fixed4x4(){return true;}
virtual bool data__setparam__fixed4x4( const double* value, size_t length ){return true;}

virtual bool begin__setparam__string(){return true;}
virtual bool end__setparam__string(){return true;}
virtual bool data__setparam__string( const ParserChar* value, size_t length ){return true;}

virtual bool begin__setparam__usertype( const usertype__AttributeData& attributeData ){return true;}
virtual bool end__setparam__usertype(){return true;}

virtual bool begin__setparam__array( const setparam__array__AttributeData& attributeData ){return true;}
virtual bool end__setparam__array(){return true;}

virtual bool begin__setparam__connect_param( const connect_param__AttributeData& attributeData ){return true;}
virtual bool end__setparam__connect_param(){return true;}

virtual bool begin__profile_CG__technique( const profile_CG__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__technique(){return true;}

virtual bool begin__profile_CG__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__profile_CG__extra(){return true;}

virtual bool begin__profile_COMMON( const profile_COMMON__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON(){return true;}

virtual bool begin__profile_COMMON__asset(){return true;}
virtual bool end__profile_COMMON__asset(){return true;}

virtual bool begin__profile_COMMON__image( const image__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON__image(){return true;}

virtual bool begin__profile_COMMON__newparam( const profile_COMMON__newparam__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON__newparam(){return true;}

virtual bool begin__profile_COMMON__technique( const profile_COMMON__technique__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON__technique(){return true;}

virtual bool begin__technique__constant(){return true;}
virtual bool end__technique__constant(){return true;}

virtual bool begin__constant__emission(){return true;}
virtual bool end__constant__emission(){return true;}

virtual bool begin__emission__color( const emission__color__AttributeData& attributeData ){return true;}
virtual bool end__emission__color(){return true;}
virtual bool data__emission__color( const double* value, size_t length ){return true;}

virtual bool begin__emission__param( const emission__param__AttributeData& attributeData ){return true;}
virtual bool end__emission__param(){return true;}

virtual bool begin__emission__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__emission__texture(){return true;}

virtual bool begin__texture__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__texture__extra(){return true;}

virtual bool begin__constant__reflective(){return true;}
virtual bool end__constant__reflective(){return true;}

virtual bool begin__reflective__color( const reflective__color__AttributeData& attributeData ){return true;}
virtual bool end__reflective__color(){return true;}
virtual bool data__reflective__color( const double* value, size_t length ){return true;}

virtual bool begin__reflective__param( const reflective__param__AttributeData& attributeData ){return true;}
virtual bool end__reflective__param(){return true;}

virtual bool begin__reflective__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__reflective__texture(){return true;}

virtual bool begin__constant__reflectivity(){return true;}
virtual bool end__constant__reflectivity(){return true;}

virtual bool begin__reflectivity__float( const reflectivity__float__AttributeData& attributeData ){return true;}
virtual bool end__reflectivity__float(){return true;}
virtual bool data__reflectivity__float( double value ){return true;}

virtual bool begin__reflectivity__param( const reflectivity__param__AttributeData& attributeData ){return true;}
virtual bool end__reflectivity__param(){return true;}

virtual bool begin__constant__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__constant__transparent(){return true;}

virtual bool begin__transparent__color( const transparent__color__AttributeData& attributeData ){return true;}
virtual bool end__transparent__color(){return true;}
virtual bool data__transparent__color( const double* value, size_t length ){return true;}

virtual bool begin__transparent__param( const transparent__param__AttributeData& attributeData ){return true;}
virtual bool end__transparent__param(){return true;}

virtual bool begin__transparent__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__transparent__texture(){return true;}

virtual bool begin__constant__transparency(){return true;}
virtual bool end__constant__transparency(){return true;}

virtual bool begin__transparency__float( const transparency__float__AttributeData& attributeData ){return true;}
virtual bool end__transparency__float(){return true;}
virtual bool data__transparency__float( double value ){return true;}

virtual bool begin__transparency__param( const transparency__param__AttributeData& attributeData ){return true;}
virtual bool end__transparency__param(){return true;}

virtual bool begin__constant__index_of_refraction(){return true;}
virtual bool end__constant__index_of_refraction(){return true;}

virtual bool begin__index_of_refraction__float( const index_of_refraction__float__AttributeData& attributeData ){return true;}
virtual bool end__index_of_refraction__float(){return true;}
virtual bool data__index_of_refraction__float( double value ){return true;}

virtual bool begin__index_of_refraction__param( const index_of_refraction__param__AttributeData& attributeData ){return true;}
virtual bool end__index_of_refraction__param(){return true;}

virtual bool begin__lambert(){return true;}
virtual bool end__lambert(){return true;}

virtual bool begin__lambert__emission(){return true;}
virtual bool end__lambert__emission(){return true;}

virtual bool begin__lambert__ambient(){return true;}
virtual bool end__lambert__ambient(){return true;}

virtual bool begin__ambient__param( const ambient__param__AttributeData& attributeData ){return true;}
virtual bool end__ambient__param(){return true;}

virtual bool begin__ambient__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__ambient__texture(){return true;}

virtual bool begin__lambert__diffuse(){return true;}
virtual bool end__lambert__diffuse(){return true;}

virtual bool begin__diffuse__color( const diffuse__color__AttributeData& attributeData ){return true;}
virtual bool end__diffuse__color(){return true;}
virtual bool data__diffuse__color( const double* value, size_t length ){return true;}

virtual bool begin__diffuse__param( const diffuse__param__AttributeData& attributeData ){return true;}
virtual bool end__diffuse__param(){return true;}

virtual bool begin__diffuse__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__diffuse__texture(){return true;}

virtual bool begin__lambert__reflective(){return true;}
virtual bool end__lambert__reflective(){return true;}

virtual bool begin__lambert__reflectivity(){return true;}
virtual bool end__lambert__reflectivity(){return true;}

virtual bool begin__lambert__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__lambert__transparent(){return true;}

virtual bool begin__lambert__transparency(){return true;}
virtual bool end__lambert__transparency(){return true;}

virtual bool begin__lambert__index_of_refraction(){return true;}
virtual bool end__lambert__index_of_refraction(){return true;}

virtual bool begin__phong(){return true;}
virtual bool end__phong(){return true;}

virtual bool begin__phong__emission(){return true;}
virtual bool end__phong__emission(){return true;}

virtual bool begin__phong__ambient(){return true;}
virtual bool end__phong__ambient(){return true;}

virtual bool begin__phong__diffuse(){return true;}
virtual bool end__phong__diffuse(){return true;}

virtual bool begin__phong__specular(){return true;}
virtual bool end__phong__specular(){return true;}

virtual bool begin__specular__color( const specular__color__AttributeData& attributeData ){return true;}
virtual bool end__specular__color(){return true;}
virtual bool data__specular__color( const double* value, size_t length ){return true;}

virtual bool begin__specular__param( const specular__param__AttributeData& attributeData ){return true;}
virtual bool end__specular__param(){return true;}

virtual bool begin__specular__texture( const texture__AttributeData& attributeData ){return true;}
virtual bool end__specular__texture(){return true;}

virtual bool begin__phong__shininess(){return true;}
virtual bool end__phong__shininess(){return true;}

virtual bool begin__shininess__float( const shininess__float__AttributeData& attributeData ){return true;}
virtual bool end__shininess__float(){return true;}
virtual bool data__shininess__float( double value ){return true;}

virtual bool begin__shininess__param( const shininess__param__AttributeData& attributeData ){return true;}
virtual bool end__shininess__param(){return true;}

virtual bool begin__phong__reflective(){return true;}
virtual bool end__phong__reflective(){return true;}

virtual bool begin__phong__reflectivity(){return true;}
virtual bool end__phong__reflectivity(){return true;}

virtual bool begin__phong__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__phong__transparent(){return true;}

virtual bool begin__phong__transparency(){return true;}
virtual bool end__phong__transparency(){return true;}

virtual bool begin__phong__index_of_refraction(){return true;}
virtual bool end__phong__index_of_refraction(){return true;}

virtual bool begin__blinn(){return true;}
virtual bool end__blinn(){return true;}

virtual bool begin__blinn__emission(){return true;}
virtual bool end__blinn__emission(){return true;}

virtual bool begin__blinn__ambient(){return true;}
virtual bool end__blinn__ambient(){return true;}

virtual bool begin__blinn__diffuse(){return true;}
virtual bool end__blinn__diffuse(){return true;}

virtual bool begin__blinn__specular(){return true;}
virtual bool end__blinn__specular(){return true;}

virtual bool begin__blinn__shininess(){return true;}
virtual bool end__blinn__shininess(){return true;}

virtual bool begin__blinn__reflective(){return true;}
virtual bool end__blinn__reflective(){return true;}

virtual bool begin__blinn__reflectivity(){return true;}
virtual bool end__blinn__reflectivity(){return true;}

virtual bool begin__blinn__transparent( const transparent__AttributeData& attributeData ){return true;}
virtual bool end__blinn__transparent(){return true;}

virtual bool begin__blinn__transparency(){return true;}
virtual bool end__blinn__transparency(){return true;}

virtual bool begin__blinn__index_of_refraction(){return true;}
virtual bool end__blinn__index_of_refraction(){return true;}

virtual bool begin__profile_COMMON__extra( const extra__AttributeData& attributeData ){return true;}
virtual bool end__profile_COMMON__extra(){return true;}



private:
/** Disable default copy ctor. */
ColladaParserAutoGen( const ColladaParserAutoGen& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGen& operator= ( const ColladaParserAutoGen& pre );

};

}
#endif
