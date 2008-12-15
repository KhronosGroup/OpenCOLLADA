/*
Copyright (c) 2008 NetAllied Systems GmbH

This file is part of COLLADASaxFrameworkLoader.

Licensed under the MIT Open Source License,
for details please see LICENSE file or the website
http://www.opensource.org/licenses/mit-license.php
*/



#ifndef __COLLADASAXFWL_COLLADAPARSERAUTOGENPRIVATE_H__
#define __COLLADASAXFWL_COLLADAPARSERAUTOGENPRIVATE_H__


#include "GeneratedSaxParserPrerequisites.h"
#include "GeneratedSaxParserTypes.h"
#include "GeneratedSaxParserParserTemplate.h"
#include "COLLADASaxFWLColladaParserAutoGenAttributes.h"


namespace COLLADASaxFWL
{


	typedef GeneratedSaxParser::StringHash StringHash;
	typedef GeneratedSaxParser::ParserChar ParserChar;
	typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
	typedef GeneratedSaxParser::ParserError ParserError;


	class ColladaParserAutoGenPrivate : public GeneratedSaxParser::ParserTemplate<ColladaParserAutoGenPrivate, ColladaParserAutoGen>
	{
	public:
		static const char* PARENT_CHILD_ELEMENT_SEPARATOR;

		ColladaParserAutoGenPrivate( COLLADASaxFWL::ColladaParserAutoGen* impl, GeneratedSaxParser::IErrorHandler* errorHandler = 0 );
		virtual ~ColladaParserAutoGenPrivate();


	private:


		bool _begin__library_force_fields( void* attributeData ){return mImpl->begin__library_force_fields(*static_cast<library_force_fields__AttributeData*>(attributeData));}
		bool _data__library_force_fields( const ParserChar* text, size_t textLength );
		bool _end__library_force_fields(){return mImpl->end__library_force_fields();}
		bool _validateBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields();

		bool _begin__library_force_fields__asset( void* attributeData ){return mImpl->begin__library_force_fields__asset();}
		bool _data__library_force_fields__asset( const ParserChar* text, size_t textLength );
		bool _end__library_force_fields__asset(){return mImpl->end__library_force_fields__asset();}
		bool _validateBegin__library_force_fields__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields__asset();

		bool _begin__contributor( void* attributeData ){return mImpl->begin__contributor();}
		bool _data__contributor( const ParserChar* text, size_t textLength );
		bool _end__contributor(){return mImpl->end__contributor();}
		bool _validateBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__contributor();

		bool _begin__author( void* attributeData ){return mImpl->begin__author();}
		bool _data__author( const ParserChar* text, size_t textLength );
		bool _end__author(){return mImpl->end__author();}
		bool _validateBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__author();

		bool _begin__authoring_tool( void* attributeData ){return mImpl->begin__authoring_tool();}
		bool _data__authoring_tool( const ParserChar* text, size_t textLength );
		bool _end__authoring_tool(){return mImpl->end__authoring_tool();}
		bool _validateBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__authoring_tool();

		bool _begin__comments( void* attributeData ){return mImpl->begin__comments();}
		bool _data__comments( const ParserChar* text, size_t textLength );
		bool _end__comments(){return mImpl->end__comments();}
		bool _validateBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__comments();

		bool _begin__copyright( void* attributeData ){return mImpl->begin__copyright();}
		bool _data__copyright( const ParserChar* text, size_t textLength );
		bool _end__copyright(){return mImpl->end__copyright();}
		bool _validateBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__copyright();

		bool _begin__source_data( void* attributeData ){return mImpl->begin__source_data();}
		bool _data__source_data( const ParserChar* text, size_t textLength );
		bool _end__source_data(){return mImpl->end__source_data();}
		bool _validateBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source_data();

		bool _begin__created( void* attributeData ){return mImpl->begin__created();}
		bool _data__created( const ParserChar* text, size_t textLength );
		bool _end__created(){return mImpl->end__created();}
		bool _validateBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__created();

		bool _begin__keywords( void* attributeData ){return mImpl->begin__keywords();}
		bool _data__keywords( const ParserChar* text, size_t textLength );
		bool _end__keywords(){return mImpl->end__keywords();}
		bool _validateBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__keywords();

		bool _begin__modified( void* attributeData ){return mImpl->begin__modified();}
		bool _data__modified( const ParserChar* text, size_t textLength );
		bool _end__modified(){return mImpl->end__modified();}
		bool _validateBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__modified();

		bool _begin__revision( void* attributeData ){return mImpl->begin__revision();}
		bool _data__revision( const ParserChar* text, size_t textLength );
		bool _end__revision(){return mImpl->end__revision();}
		bool _validateBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__revision();

		bool _begin__subject( void* attributeData ){return mImpl->begin__subject();}
		bool _data__subject( const ParserChar* text, size_t textLength );
		bool _end__subject(){return mImpl->end__subject();}
		bool _validateBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__subject();

		bool _begin__title( void* attributeData ){return mImpl->begin__title();}
		bool _data__title( const ParserChar* text, size_t textLength );
		bool _end__title(){return mImpl->end__title();}
		bool _validateBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__title();

		bool _begin__unit( void* attributeData ){return mImpl->begin__unit(*static_cast<unit__AttributeData*>(attributeData));}
		bool _data__unit( const ParserChar* text, size_t textLength );
		bool _end__unit(){return mImpl->end__unit();}
		bool _validateBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__unit();

		bool _begin__up_axis( void* attributeData ){return mImpl->begin__up_axis();}
		bool _data__up_axis( const ParserChar* text, size_t textLength );
		bool _end__up_axis(){return mImpl->end__up_axis();}
		bool _validateBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__up_axis();

		bool _begin__force_field( void* attributeData ){return mImpl->begin__force_field(*static_cast<force_field__AttributeData*>(attributeData));}
		bool _data__force_field( const ParserChar* text, size_t textLength );
		bool _end__force_field(){return mImpl->end__force_field();}
		bool _validateBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field();

		bool _begin__force_field__asset( void* attributeData ){return mImpl->begin__force_field__asset();}
		bool _data__force_field__asset( const ParserChar* text, size_t textLength );
		bool _end__force_field__asset(){return mImpl->end__force_field__asset();}
		bool _validateBegin__force_field__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__asset();

		bool _begin__force_field__technique( void* attributeData ){return mImpl->begin__force_field__technique(*static_cast<force_field__technique__AttributeData*>(attributeData));}
		bool _data__force_field__technique( const ParserChar* text, size_t textLength );
		bool _end__force_field__technique(){return mImpl->end__force_field__technique();}
		bool _validateBegin__force_field__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__technique();

		bool _begin__force_field__extra( void* attributeData ){return mImpl->begin__force_field__extra(*static_cast<force_field__extra__AttributeData*>(attributeData));}
		bool _data__force_field__extra( const ParserChar* text, size_t textLength );
		bool _end__force_field__extra(){return mImpl->end__force_field__extra();}
		bool _validateBegin__force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__force_field__extra();

		bool _begin__extra__asset( void* attributeData ){return mImpl->begin__extra__asset();}
		bool _data__extra__asset( const ParserChar* text, size_t textLength );
		bool _end__extra__asset(){return mImpl->end__extra__asset();}
		bool _validateBegin__extra__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra__asset();

		bool _begin__extra__technique( void* attributeData ){return mImpl->begin__extra__technique(*static_cast<extra__technique__AttributeData*>(attributeData));}
		bool _data__extra__technique( const ParserChar* text, size_t textLength );
		bool _end__extra__technique(){return mImpl->end__extra__technique();}
		bool _validateBegin__extra__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra__technique();

		bool _begin__library_force_fields__extra( void* attributeData ){return mImpl->begin__library_force_fields__extra(*static_cast<library_force_fields__extra__AttributeData*>(attributeData));}
		bool _data__library_force_fields__extra( const ParserChar* text, size_t textLength );
		bool _end__library_force_fields__extra(){return mImpl->end__library_force_fields__extra();}
		bool _validateBegin__library_force_fields__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_force_fields__extra();

		bool _begin__instance_effect( void* attributeData ){return mImpl->begin__instance_effect(*static_cast<instance_effect__AttributeData*>(attributeData));}
		bool _data__instance_effect( const ParserChar* text, size_t textLength );
		bool _end__instance_effect(){return mImpl->end__instance_effect();}
		bool _validateBegin__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect();

		bool _begin__technique_hint( void* attributeData ){return mImpl->begin__technique_hint(*static_cast<technique_hint__AttributeData*>(attributeData));}
		bool _data__technique_hint( const ParserChar* text, size_t textLength );
		bool _end__technique_hint(){return mImpl->end__technique_hint();}
		bool _validateBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_hint();

		bool _begin__instance_effect__setparam( void* attributeData ){return mImpl->begin__instance_effect__setparam(*static_cast<instance_effect__setparam__AttributeData*>(attributeData));}
		bool _data__instance_effect__setparam( const ParserChar* text, size_t textLength );
		bool _end__instance_effect__setparam(){return mImpl->end__instance_effect__setparam();}
		bool _validateBegin__instance_effect__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect__setparam();

		bool _begin__setparam__bool( void* attributeData ){return mImpl->begin__setparam__bool();}
		bool _data__setparam__bool( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool(){return mImpl->end__setparam__bool();}
		bool _validateBegin__setparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool();

		bool _begin__setparam__bool2( void* attributeData ){return mImpl->begin__setparam__bool2();}
		bool _data__setparam__bool2( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool2(){return mImpl->end__setparam__bool2();}
		bool _validateBegin__setparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2();

		bool _begin__setparam__bool3( void* attributeData ){return mImpl->begin__setparam__bool3();}
		bool _data__setparam__bool3( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool3(){return mImpl->end__setparam__bool3();}
		bool _validateBegin__setparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3();

		bool _begin__setparam__bool4( void* attributeData ){return mImpl->begin__setparam__bool4();}
		bool _data__setparam__bool4( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool4(){return mImpl->end__setparam__bool4();}
		bool _validateBegin__setparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4();

		bool _begin__setparam__int( void* attributeData ){return mImpl->begin__setparam__int();}
		bool _data__setparam__int( const ParserChar* text, size_t textLength );
		bool _end__setparam__int(){return mImpl->end__setparam__int();}
		bool _validateBegin__setparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int();

		bool _begin__setparam__int2( void* attributeData ){return mImpl->begin__setparam__int2();}
		bool _data__setparam__int2( const ParserChar* text, size_t textLength );
		bool _end__setparam__int2(){return mImpl->end__setparam__int2();}
		bool _validateBegin__setparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2();

		bool _begin__setparam__int3( void* attributeData ){return mImpl->begin__setparam__int3();}
		bool _data__setparam__int3( const ParserChar* text, size_t textLength );
		bool _end__setparam__int3(){return mImpl->end__setparam__int3();}
		bool _validateBegin__setparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3();

		bool _begin__setparam__int4( void* attributeData ){return mImpl->begin__setparam__int4();}
		bool _data__setparam__int4( const ParserChar* text, size_t textLength );
		bool _end__setparam__int4(){return mImpl->end__setparam__int4();}
		bool _validateBegin__setparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4();

		bool _begin__setparam__float( void* attributeData ){return mImpl->begin__setparam__float();}
		bool _data__setparam__float( const ParserChar* text, size_t textLength );
		bool _end__setparam__float(){return mImpl->end__setparam__float();}
		bool _validateBegin__setparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float();

		bool _begin__setparam__float2( void* attributeData ){return mImpl->begin__setparam__float2();}
		bool _data__setparam__float2( const ParserChar* text, size_t textLength );
		bool _end__setparam__float2(){return mImpl->end__setparam__float2();}
		bool _validateBegin__setparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2();

		bool _begin__setparam__float3( void* attributeData ){return mImpl->begin__setparam__float3();}
		bool _data__setparam__float3( const ParserChar* text, size_t textLength );
		bool _end__setparam__float3(){return mImpl->end__setparam__float3();}
		bool _validateBegin__setparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3();

		bool _begin__setparam__float4( void* attributeData ){return mImpl->begin__setparam__float4();}
		bool _data__setparam__float4( const ParserChar* text, size_t textLength );
		bool _end__setparam__float4(){return mImpl->end__setparam__float4();}
		bool _validateBegin__setparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4();

		bool _begin__setparam__float1x1( void* attributeData ){return mImpl->begin__setparam__float1x1();}
		bool _data__setparam__float1x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__float1x1(){return mImpl->end__setparam__float1x1();}
		bool _validateBegin__setparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x1();

		bool _begin__setparam__float1x2( void* attributeData ){return mImpl->begin__setparam__float1x2();}
		bool _data__setparam__float1x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__float1x2(){return mImpl->end__setparam__float1x2();}
		bool _validateBegin__setparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x2();

		bool _begin__setparam__float1x3( void* attributeData ){return mImpl->begin__setparam__float1x3();}
		bool _data__setparam__float1x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__float1x3(){return mImpl->end__setparam__float1x3();}
		bool _validateBegin__setparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x3();

		bool _begin__setparam__float1x4( void* attributeData ){return mImpl->begin__setparam__float1x4();}
		bool _data__setparam__float1x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__float1x4(){return mImpl->end__setparam__float1x4();}
		bool _validateBegin__setparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1x4();

		bool _begin__setparam__float2x1( void* attributeData ){return mImpl->begin__setparam__float2x1();}
		bool _data__setparam__float2x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__float2x1(){return mImpl->end__setparam__float2x1();}
		bool _validateBegin__setparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x1();

		bool _begin__setparam__float2x2( void* attributeData ){return mImpl->begin__setparam__float2x2();}
		bool _data__setparam__float2x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__float2x2(){return mImpl->end__setparam__float2x2();}
		bool _validateBegin__setparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x2();

		bool _begin__setparam__float2x3( void* attributeData ){return mImpl->begin__setparam__float2x3();}
		bool _data__setparam__float2x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__float2x3(){return mImpl->end__setparam__float2x3();}
		bool _validateBegin__setparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x3();

		bool _begin__setparam__float2x4( void* attributeData ){return mImpl->begin__setparam__float2x4();}
		bool _data__setparam__float2x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__float2x4(){return mImpl->end__setparam__float2x4();}
		bool _validateBegin__setparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float2x4();

		bool _begin__setparam__float3x1( void* attributeData ){return mImpl->begin__setparam__float3x1();}
		bool _data__setparam__float3x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__float3x1(){return mImpl->end__setparam__float3x1();}
		bool _validateBegin__setparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x1();

		bool _begin__setparam__float3x2( void* attributeData ){return mImpl->begin__setparam__float3x2();}
		bool _data__setparam__float3x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__float3x2(){return mImpl->end__setparam__float3x2();}
		bool _validateBegin__setparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x2();

		bool _begin__setparam__float3x3( void* attributeData ){return mImpl->begin__setparam__float3x3();}
		bool _data__setparam__float3x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__float3x3(){return mImpl->end__setparam__float3x3();}
		bool _validateBegin__setparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x3();

		bool _begin__setparam__float3x4( void* attributeData ){return mImpl->begin__setparam__float3x4();}
		bool _data__setparam__float3x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__float3x4(){return mImpl->end__setparam__float3x4();}
		bool _validateBegin__setparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float3x4();

		bool _begin__setparam__float4x1( void* attributeData ){return mImpl->begin__setparam__float4x1();}
		bool _data__setparam__float4x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__float4x1(){return mImpl->end__setparam__float4x1();}
		bool _validateBegin__setparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x1();

		bool _begin__setparam__float4x2( void* attributeData ){return mImpl->begin__setparam__float4x2();}
		bool _data__setparam__float4x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__float4x2(){return mImpl->end__setparam__float4x2();}
		bool _validateBegin__setparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x2();

		bool _begin__setparam__float4x3( void* attributeData ){return mImpl->begin__setparam__float4x3();}
		bool _data__setparam__float4x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__float4x3(){return mImpl->end__setparam__float4x3();}
		bool _validateBegin__setparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x3();

		bool _begin__setparam__float4x4( void* attributeData ){return mImpl->begin__setparam__float4x4();}
		bool _data__setparam__float4x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__float4x4(){return mImpl->end__setparam__float4x4();}
		bool _validateBegin__setparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float4x4();

		bool _begin__setparam__surface( void* attributeData ){return mImpl->begin__setparam__surface(*static_cast<setparam__surface__AttributeData*>(attributeData));}
		bool _data__setparam__surface( const ParserChar* text, size_t textLength );
		bool _end__setparam__surface(){return mImpl->end__setparam__surface();}
		bool _validateBegin__setparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__surface();

		bool _begin__init_as_null( void* attributeData ){return mImpl->begin__init_as_null();}
		bool _data__init_as_null( const ParserChar* text, size_t textLength );
		bool _end__init_as_null(){return mImpl->end__init_as_null();}
		bool _validateBegin__init_as_null( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_as_null();

		bool _begin__init_as_target( void* attributeData ){return mImpl->begin__init_as_target();}
		bool _data__init_as_target( const ParserChar* text, size_t textLength );
		bool _end__init_as_target(){return mImpl->end__init_as_target();}
		bool _validateBegin__init_as_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_as_target();

		bool _begin__init_cube( void* attributeData ){return mImpl->begin__init_cube();}
		bool _data__init_cube( const ParserChar* text, size_t textLength );
		bool _end__init_cube(){return mImpl->end__init_cube();}
		bool _validateBegin__init_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube();

		bool _begin__init_cube__all( void* attributeData ){return mImpl->begin__init_cube__all(*static_cast<init_cube__all__AttributeData*>(attributeData));}
		bool _data__init_cube__all( const ParserChar* text, size_t textLength );
		bool _end__init_cube__all(){return mImpl->end__init_cube__all();}
		bool _validateBegin__init_cube__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__all();

		bool _begin__init_cube__primary( void* attributeData ){return mImpl->begin__init_cube__primary(*static_cast<init_cube__primary__AttributeData*>(attributeData));}
		bool _data__init_cube__primary( const ParserChar* text, size_t textLength );
		bool _end__init_cube__primary(){return mImpl->end__init_cube__primary();}
		bool _validateBegin__init_cube__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__primary();

		bool _begin__order( void* attributeData ){return mImpl->begin__order();}
		bool _data__order( const ParserChar* text, size_t textLength );
		bool _end__order(){return mImpl->end__order();}
		bool _validateBegin__order( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__order();

		bool _begin__init_cube__face( void* attributeData ){return mImpl->begin__init_cube__face(*static_cast<init_cube__face__AttributeData*>(attributeData));}
		bool _data__init_cube__face( const ParserChar* text, size_t textLength );
		bool _end__init_cube__face(){return mImpl->end__init_cube__face();}
		bool _validateBegin__init_cube__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_cube__face();

		bool _begin__init_volume( void* attributeData ){return mImpl->begin__init_volume();}
		bool _data__init_volume( const ParserChar* text, size_t textLength );
		bool _end__init_volume(){return mImpl->end__init_volume();}
		bool _validateBegin__init_volume( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume();

		bool _begin__init_volume__all( void* attributeData ){return mImpl->begin__init_volume__all(*static_cast<init_volume__all__AttributeData*>(attributeData));}
		bool _data__init_volume__all( const ParserChar* text, size_t textLength );
		bool _end__init_volume__all(){return mImpl->end__init_volume__all();}
		bool _validateBegin__init_volume__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume__all();

		bool _begin__init_volume__primary( void* attributeData ){return mImpl->begin__init_volume__primary(*static_cast<init_volume__primary__AttributeData*>(attributeData));}
		bool _data__init_volume__primary( const ParserChar* text, size_t textLength );
		bool _end__init_volume__primary(){return mImpl->end__init_volume__primary();}
		bool _validateBegin__init_volume__primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_volume__primary();

		bool _begin__init_planar( void* attributeData ){return mImpl->begin__init_planar();}
		bool _data__init_planar( const ParserChar* text, size_t textLength );
		bool _end__init_planar(){return mImpl->end__init_planar();}
		bool _validateBegin__init_planar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_planar();

		bool _begin__init_planar__all( void* attributeData ){return mImpl->begin__init_planar__all(*static_cast<init_planar__all__AttributeData*>(attributeData));}
		bool _data__init_planar__all( const ParserChar* text, size_t textLength );
		bool _end__init_planar__all(){return mImpl->end__init_planar__all();}
		bool _validateBegin__init_planar__all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__init_planar__all();

		bool _begin__surface__init_from( void* attributeData ){return mImpl->begin__surface__init_from(*static_cast<surface__init_from__AttributeData*>(attributeData));}
		bool _data__surface__init_from( const ParserChar* text, size_t textLength );
		bool _end__surface__init_from(){return mImpl->end__surface__init_from();}
		bool _validateBegin__surface__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__init_from();

		bool _begin__format( void* attributeData ){return mImpl->begin__format();}
		bool _data__format( const ParserChar* text, size_t textLength );
		bool _end__format(){return mImpl->end__format();}
		bool _validateBegin__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format();

		bool _begin__format_hint( void* attributeData ){return mImpl->begin__format_hint();}
		bool _data__format_hint( const ParserChar* text, size_t textLength );
		bool _end__format_hint(){return mImpl->end__format_hint();}
		bool _validateBegin__format_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format_hint();

		bool _begin__channels( void* attributeData ){return mImpl->begin__channels();}
		bool _data__channels( const ParserChar* text, size_t textLength );
		bool _end__channels(){return mImpl->end__channels();}
		bool _validateBegin__channels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__channels();

		bool _begin__range( void* attributeData ){return mImpl->begin__range();}
		bool _data__range( const ParserChar* text, size_t textLength );
		bool _end__range(){return mImpl->end__range();}
		bool _validateBegin__range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__range();

		bool _begin__precision( void* attributeData ){return mImpl->begin__precision();}
		bool _data__precision( const ParserChar* text, size_t textLength );
		bool _end__precision(){return mImpl->end__precision();}
		bool _validateBegin__precision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__precision();

		bool _begin__option( void* attributeData ){return mImpl->begin__option();}
		bool _data__option( const ParserChar* text, size_t textLength );
		bool _end__option(){return mImpl->end__option();}
		bool _validateBegin__option( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__option();

		bool _begin__format_hint__extra( void* attributeData ){return mImpl->begin__format_hint__extra(*static_cast<format_hint__extra__AttributeData*>(attributeData));}
		bool _data__format_hint__extra( const ParserChar* text, size_t textLength );
		bool _end__format_hint__extra(){return mImpl->end__format_hint__extra();}
		bool _validateBegin__format_hint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__format_hint__extra();

		bool _begin__surface__size( void* attributeData ){return mImpl->begin__surface__size();}
		bool _data__surface__size( const ParserChar* text, size_t textLength );
		bool _end__surface__size(){return mImpl->end__surface__size();}
		bool _validateBegin__surface__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__size();

		bool _begin__viewport_ratio( void* attributeData ){return mImpl->begin__viewport_ratio();}
		bool _data__viewport_ratio( const ParserChar* text, size_t textLength );
		bool _end__viewport_ratio(){return mImpl->end__viewport_ratio();}
		bool _validateBegin__viewport_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__viewport_ratio();

		bool _begin__mip_levels( void* attributeData ){return mImpl->begin__mip_levels();}
		bool _data__mip_levels( const ParserChar* text, size_t textLength );
		bool _end__mip_levels(){return mImpl->end__mip_levels();}
		bool _validateBegin__mip_levels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mip_levels();

		bool _begin__mipmap_generate( void* attributeData ){return mImpl->begin__mipmap_generate();}
		bool _data__mipmap_generate( const ParserChar* text, size_t textLength );
		bool _end__mipmap_generate(){return mImpl->end__mipmap_generate();}
		bool _validateBegin__mipmap_generate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mipmap_generate();

		bool _begin__surface__extra( void* attributeData ){return mImpl->begin__surface__extra(*static_cast<surface__extra__AttributeData*>(attributeData));}
		bool _data__surface__extra( const ParserChar* text, size_t textLength );
		bool _end__surface__extra(){return mImpl->end__surface__extra();}
		bool _validateBegin__surface__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__surface__extra();

		bool _begin__setparam__sampler1D( void* attributeData ){return mImpl->begin__setparam__sampler1D();}
		bool _data__setparam__sampler1D( const ParserChar* text, size_t textLength );
		bool _end__setparam__sampler1D(){return mImpl->end__setparam__sampler1D();}
		bool _validateBegin__setparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler1D();

		bool _begin__sampler1D__source( void* attributeData ){return mImpl->begin__sampler1D__source();}
		bool _data__sampler1D__source( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__source(){return mImpl->end__sampler1D__source();}
		bool _validateBegin__sampler1D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__source();

		bool _begin__sampler1D__wrap_s( void* attributeData ){return mImpl->begin__sampler1D__wrap_s();}
		bool _data__sampler1D__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__wrap_s(){return mImpl->end__sampler1D__wrap_s();}
		bool _validateBegin__sampler1D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__wrap_s();

		bool _begin__sampler1D__minfilter( void* attributeData ){return mImpl->begin__sampler1D__minfilter();}
		bool _data__sampler1D__minfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__minfilter(){return mImpl->end__sampler1D__minfilter();}
		bool _validateBegin__sampler1D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__minfilter();

		bool _begin__sampler1D__magfilter( void* attributeData ){return mImpl->begin__sampler1D__magfilter();}
		bool _data__sampler1D__magfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__magfilter(){return mImpl->end__sampler1D__magfilter();}
		bool _validateBegin__sampler1D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__magfilter();

		bool _begin__sampler1D__mipfilter( void* attributeData ){return mImpl->begin__sampler1D__mipfilter();}
		bool _data__sampler1D__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__mipfilter(){return mImpl->end__sampler1D__mipfilter();}
		bool _validateBegin__sampler1D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipfilter();

		bool _begin__sampler1D__border_color( void* attributeData ){return mImpl->begin__sampler1D__border_color();}
		bool _data__sampler1D__border_color( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__border_color(){return mImpl->end__sampler1D__border_color();}
		bool _validateBegin__sampler1D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__border_color();

		bool _begin__sampler1D__mipmap_maxlevel( void* attributeData ){return mImpl->begin__sampler1D__mipmap_maxlevel();}
		bool _data__sampler1D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__mipmap_maxlevel(){return mImpl->end__sampler1D__mipmap_maxlevel();}
		bool _validateBegin__sampler1D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipmap_maxlevel();

		bool _begin__sampler1D__mipmap_bias( void* attributeData ){return mImpl->begin__sampler1D__mipmap_bias();}
		bool _data__sampler1D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__mipmap_bias(){return mImpl->end__sampler1D__mipmap_bias();}
		bool _validateBegin__sampler1D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__mipmap_bias();

		bool _begin__sampler1D__extra( void* attributeData ){return mImpl->begin__sampler1D__extra(*static_cast<sampler1D__extra__AttributeData*>(attributeData));}
		bool _data__sampler1D__extra( const ParserChar* text, size_t textLength );
		bool _end__sampler1D__extra(){return mImpl->end__sampler1D__extra();}
		bool _validateBegin__sampler1D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler1D__extra();

		bool _begin__setparam__sampler2D( void* attributeData ){return mImpl->begin__setparam__sampler2D();}
		bool _data__setparam__sampler2D( const ParserChar* text, size_t textLength );
		bool _end__setparam__sampler2D(){return mImpl->end__setparam__sampler2D();}
		bool _validateBegin__setparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler2D();

		bool _begin__sampler2D__source( void* attributeData ){return mImpl->begin__sampler2D__source();}
		bool _data__sampler2D__source( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__source(){return mImpl->end__sampler2D__source();}
		bool _validateBegin__sampler2D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__source();

		bool _begin__sampler2D__wrap_s( void* attributeData ){return mImpl->begin__sampler2D__wrap_s();}
		bool _data__sampler2D__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__wrap_s(){return mImpl->end__sampler2D__wrap_s();}
		bool _validateBegin__sampler2D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__wrap_s();

		bool _begin__sampler2D__wrap_t( void* attributeData ){return mImpl->begin__sampler2D__wrap_t();}
		bool _data__sampler2D__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__wrap_t(){return mImpl->end__sampler2D__wrap_t();}
		bool _validateBegin__sampler2D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__wrap_t();

		bool _begin__sampler2D__minfilter( void* attributeData ){return mImpl->begin__sampler2D__minfilter();}
		bool _data__sampler2D__minfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__minfilter(){return mImpl->end__sampler2D__minfilter();}
		bool _validateBegin__sampler2D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__minfilter();

		bool _begin__sampler2D__magfilter( void* attributeData ){return mImpl->begin__sampler2D__magfilter();}
		bool _data__sampler2D__magfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__magfilter(){return mImpl->end__sampler2D__magfilter();}
		bool _validateBegin__sampler2D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__magfilter();

		bool _begin__sampler2D__mipfilter( void* attributeData ){return mImpl->begin__sampler2D__mipfilter();}
		bool _data__sampler2D__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__mipfilter(){return mImpl->end__sampler2D__mipfilter();}
		bool _validateBegin__sampler2D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipfilter();

		bool _begin__sampler2D__border_color( void* attributeData ){return mImpl->begin__sampler2D__border_color();}
		bool _data__sampler2D__border_color( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__border_color(){return mImpl->end__sampler2D__border_color();}
		bool _validateBegin__sampler2D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__border_color();

		bool _begin__sampler2D__mipmap_maxlevel( void* attributeData ){return mImpl->begin__sampler2D__mipmap_maxlevel();}
		bool _data__sampler2D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__mipmap_maxlevel(){return mImpl->end__sampler2D__mipmap_maxlevel();}
		bool _validateBegin__sampler2D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipmap_maxlevel();

		bool _begin__sampler2D__mipmap_bias( void* attributeData ){return mImpl->begin__sampler2D__mipmap_bias();}
		bool _data__sampler2D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__mipmap_bias(){return mImpl->end__sampler2D__mipmap_bias();}
		bool _validateBegin__sampler2D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__mipmap_bias();

		bool _begin__sampler2D__extra( void* attributeData ){return mImpl->begin__sampler2D__extra(*static_cast<sampler2D__extra__AttributeData*>(attributeData));}
		bool _data__sampler2D__extra( const ParserChar* text, size_t textLength );
		bool _end__sampler2D__extra(){return mImpl->end__sampler2D__extra();}
		bool _validateBegin__sampler2D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler2D__extra();

		bool _begin__setparam__sampler3D( void* attributeData ){return mImpl->begin__setparam__sampler3D();}
		bool _data__setparam__sampler3D( const ParserChar* text, size_t textLength );
		bool _end__setparam__sampler3D(){return mImpl->end__setparam__sampler3D();}
		bool _validateBegin__setparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler3D();

		bool _begin__sampler3D__source( void* attributeData ){return mImpl->begin__sampler3D__source();}
		bool _data__sampler3D__source( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__source(){return mImpl->end__sampler3D__source();}
		bool _validateBegin__sampler3D__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__source();

		bool _begin__sampler3D__wrap_s( void* attributeData ){return mImpl->begin__sampler3D__wrap_s();}
		bool _data__sampler3D__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__wrap_s(){return mImpl->end__sampler3D__wrap_s();}
		bool _validateBegin__sampler3D__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_s();

		bool _begin__sampler3D__wrap_t( void* attributeData ){return mImpl->begin__sampler3D__wrap_t();}
		bool _data__sampler3D__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__wrap_t(){return mImpl->end__sampler3D__wrap_t();}
		bool _validateBegin__sampler3D__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_t();

		bool _begin__sampler3D__wrap_p( void* attributeData ){return mImpl->begin__sampler3D__wrap_p();}
		bool _data__sampler3D__wrap_p( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__wrap_p(){return mImpl->end__sampler3D__wrap_p();}
		bool _validateBegin__sampler3D__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__wrap_p();

		bool _begin__sampler3D__minfilter( void* attributeData ){return mImpl->begin__sampler3D__minfilter();}
		bool _data__sampler3D__minfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__minfilter(){return mImpl->end__sampler3D__minfilter();}
		bool _validateBegin__sampler3D__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__minfilter();

		bool _begin__sampler3D__magfilter( void* attributeData ){return mImpl->begin__sampler3D__magfilter();}
		bool _data__sampler3D__magfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__magfilter(){return mImpl->end__sampler3D__magfilter();}
		bool _validateBegin__sampler3D__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__magfilter();

		bool _begin__sampler3D__mipfilter( void* attributeData ){return mImpl->begin__sampler3D__mipfilter();}
		bool _data__sampler3D__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__mipfilter(){return mImpl->end__sampler3D__mipfilter();}
		bool _validateBegin__sampler3D__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipfilter();

		bool _begin__sampler3D__border_color( void* attributeData ){return mImpl->begin__sampler3D__border_color();}
		bool _data__sampler3D__border_color( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__border_color(){return mImpl->end__sampler3D__border_color();}
		bool _validateBegin__sampler3D__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__border_color();

		bool _begin__sampler3D__mipmap_maxlevel( void* attributeData ){return mImpl->begin__sampler3D__mipmap_maxlevel();}
		bool _data__sampler3D__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__mipmap_maxlevel(){return mImpl->end__sampler3D__mipmap_maxlevel();}
		bool _validateBegin__sampler3D__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipmap_maxlevel();

		bool _begin__sampler3D__mipmap_bias( void* attributeData ){return mImpl->begin__sampler3D__mipmap_bias();}
		bool _data__sampler3D__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__mipmap_bias(){return mImpl->end__sampler3D__mipmap_bias();}
		bool _validateBegin__sampler3D__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__mipmap_bias();

		bool _begin__sampler3D__extra( void* attributeData ){return mImpl->begin__sampler3D__extra(*static_cast<sampler3D__extra__AttributeData*>(attributeData));}
		bool _data__sampler3D__extra( const ParserChar* text, size_t textLength );
		bool _end__sampler3D__extra(){return mImpl->end__sampler3D__extra();}
		bool _validateBegin__sampler3D__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler3D__extra();

		bool _begin__setparam__samplerCUBE( void* attributeData ){return mImpl->begin__setparam__samplerCUBE();}
		bool _data__setparam__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _end__setparam__samplerCUBE(){return mImpl->end__setparam__samplerCUBE();}
		bool _validateBegin__setparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerCUBE();

		bool _begin__samplerCUBE__source( void* attributeData ){return mImpl->begin__samplerCUBE__source();}
		bool _data__samplerCUBE__source( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__source(){return mImpl->end__samplerCUBE__source();}
		bool _validateBegin__samplerCUBE__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__source();

		bool _begin__samplerCUBE__wrap_s( void* attributeData ){return mImpl->begin__samplerCUBE__wrap_s();}
		bool _data__samplerCUBE__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__wrap_s(){return mImpl->end__samplerCUBE__wrap_s();}
		bool _validateBegin__samplerCUBE__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_s();

		bool _begin__samplerCUBE__wrap_t( void* attributeData ){return mImpl->begin__samplerCUBE__wrap_t();}
		bool _data__samplerCUBE__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__wrap_t(){return mImpl->end__samplerCUBE__wrap_t();}
		bool _validateBegin__samplerCUBE__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_t();

		bool _begin__samplerCUBE__wrap_p( void* attributeData ){return mImpl->begin__samplerCUBE__wrap_p();}
		bool _data__samplerCUBE__wrap_p( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__wrap_p(){return mImpl->end__samplerCUBE__wrap_p();}
		bool _validateBegin__samplerCUBE__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__wrap_p();

		bool _begin__samplerCUBE__minfilter( void* attributeData ){return mImpl->begin__samplerCUBE__minfilter();}
		bool _data__samplerCUBE__minfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__minfilter(){return mImpl->end__samplerCUBE__minfilter();}
		bool _validateBegin__samplerCUBE__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__minfilter();

		bool _begin__samplerCUBE__magfilter( void* attributeData ){return mImpl->begin__samplerCUBE__magfilter();}
		bool _data__samplerCUBE__magfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__magfilter(){return mImpl->end__samplerCUBE__magfilter();}
		bool _validateBegin__samplerCUBE__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__magfilter();

		bool _begin__samplerCUBE__mipfilter( void* attributeData ){return mImpl->begin__samplerCUBE__mipfilter();}
		bool _data__samplerCUBE__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__mipfilter(){return mImpl->end__samplerCUBE__mipfilter();}
		bool _validateBegin__samplerCUBE__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipfilter();

		bool _begin__samplerCUBE__border_color( void* attributeData ){return mImpl->begin__samplerCUBE__border_color();}
		bool _data__samplerCUBE__border_color( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__border_color(){return mImpl->end__samplerCUBE__border_color();}
		bool _validateBegin__samplerCUBE__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__border_color();

		bool _begin__samplerCUBE__mipmap_maxlevel( void* attributeData ){return mImpl->begin__samplerCUBE__mipmap_maxlevel();}
		bool _data__samplerCUBE__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__mipmap_maxlevel(){return mImpl->end__samplerCUBE__mipmap_maxlevel();}
		bool _validateBegin__samplerCUBE__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipmap_maxlevel();

		bool _begin__samplerCUBE__mipmap_bias( void* attributeData ){return mImpl->begin__samplerCUBE__mipmap_bias();}
		bool _data__samplerCUBE__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__mipmap_bias(){return mImpl->end__samplerCUBE__mipmap_bias();}
		bool _validateBegin__samplerCUBE__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__mipmap_bias();

		bool _begin__samplerCUBE__extra( void* attributeData ){return mImpl->begin__samplerCUBE__extra(*static_cast<samplerCUBE__extra__AttributeData*>(attributeData));}
		bool _data__samplerCUBE__extra( const ParserChar* text, size_t textLength );
		bool _end__samplerCUBE__extra(){return mImpl->end__samplerCUBE__extra();}
		bool _validateBegin__samplerCUBE__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerCUBE__extra();

		bool _begin__setparam__samplerRECT( void* attributeData ){return mImpl->begin__setparam__samplerRECT();}
		bool _data__setparam__samplerRECT( const ParserChar* text, size_t textLength );
		bool _end__setparam__samplerRECT(){return mImpl->end__setparam__samplerRECT();}
		bool _validateBegin__setparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerRECT();

		bool _begin__samplerRECT__source( void* attributeData ){return mImpl->begin__samplerRECT__source();}
		bool _data__samplerRECT__source( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__source(){return mImpl->end__samplerRECT__source();}
		bool _validateBegin__samplerRECT__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__source();

		bool _begin__samplerRECT__wrap_s( void* attributeData ){return mImpl->begin__samplerRECT__wrap_s();}
		bool _data__samplerRECT__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__wrap_s(){return mImpl->end__samplerRECT__wrap_s();}
		bool _validateBegin__samplerRECT__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__wrap_s();

		bool _begin__samplerRECT__wrap_t( void* attributeData ){return mImpl->begin__samplerRECT__wrap_t();}
		bool _data__samplerRECT__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__wrap_t(){return mImpl->end__samplerRECT__wrap_t();}
		bool _validateBegin__samplerRECT__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__wrap_t();

		bool _begin__samplerRECT__minfilter( void* attributeData ){return mImpl->begin__samplerRECT__minfilter();}
		bool _data__samplerRECT__minfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__minfilter(){return mImpl->end__samplerRECT__minfilter();}
		bool _validateBegin__samplerRECT__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__minfilter();

		bool _begin__samplerRECT__magfilter( void* attributeData ){return mImpl->begin__samplerRECT__magfilter();}
		bool _data__samplerRECT__magfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__magfilter(){return mImpl->end__samplerRECT__magfilter();}
		bool _validateBegin__samplerRECT__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__magfilter();

		bool _begin__samplerRECT__mipfilter( void* attributeData ){return mImpl->begin__samplerRECT__mipfilter();}
		bool _data__samplerRECT__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__mipfilter(){return mImpl->end__samplerRECT__mipfilter();}
		bool _validateBegin__samplerRECT__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipfilter();

		bool _begin__samplerRECT__border_color( void* attributeData ){return mImpl->begin__samplerRECT__border_color();}
		bool _data__samplerRECT__border_color( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__border_color(){return mImpl->end__samplerRECT__border_color();}
		bool _validateBegin__samplerRECT__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__border_color();

		bool _begin__samplerRECT__mipmap_maxlevel( void* attributeData ){return mImpl->begin__samplerRECT__mipmap_maxlevel();}
		bool _data__samplerRECT__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__mipmap_maxlevel(){return mImpl->end__samplerRECT__mipmap_maxlevel();}
		bool _validateBegin__samplerRECT__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipmap_maxlevel();

		bool _begin__samplerRECT__mipmap_bias( void* attributeData ){return mImpl->begin__samplerRECT__mipmap_bias();}
		bool _data__samplerRECT__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__mipmap_bias(){return mImpl->end__samplerRECT__mipmap_bias();}
		bool _validateBegin__samplerRECT__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__mipmap_bias();

		bool _begin__samplerRECT__extra( void* attributeData ){return mImpl->begin__samplerRECT__extra(*static_cast<samplerRECT__extra__AttributeData*>(attributeData));}
		bool _data__samplerRECT__extra( const ParserChar* text, size_t textLength );
		bool _end__samplerRECT__extra(){return mImpl->end__samplerRECT__extra();}
		bool _validateBegin__samplerRECT__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerRECT__extra();

		bool _begin__setparam__samplerDEPTH( void* attributeData ){return mImpl->begin__setparam__samplerDEPTH();}
		bool _data__setparam__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _end__setparam__samplerDEPTH(){return mImpl->end__setparam__samplerDEPTH();}
		bool _validateBegin__setparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__samplerDEPTH();

		bool _begin__samplerDEPTH__source( void* attributeData ){return mImpl->begin__samplerDEPTH__source();}
		bool _data__samplerDEPTH__source( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__source(){return mImpl->end__samplerDEPTH__source();}
		bool _validateBegin__samplerDEPTH__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__source();

		bool _begin__samplerDEPTH__wrap_s( void* attributeData ){return mImpl->begin__samplerDEPTH__wrap_s();}
		bool _data__samplerDEPTH__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__wrap_s(){return mImpl->end__samplerDEPTH__wrap_s();}
		bool _validateBegin__samplerDEPTH__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__wrap_s();

		bool _begin__samplerDEPTH__wrap_t( void* attributeData ){return mImpl->begin__samplerDEPTH__wrap_t();}
		bool _data__samplerDEPTH__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__wrap_t(){return mImpl->end__samplerDEPTH__wrap_t();}
		bool _validateBegin__samplerDEPTH__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__wrap_t();

		bool _begin__samplerDEPTH__minfilter( void* attributeData ){return mImpl->begin__samplerDEPTH__minfilter();}
		bool _data__samplerDEPTH__minfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__minfilter(){return mImpl->end__samplerDEPTH__minfilter();}
		bool _validateBegin__samplerDEPTH__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__minfilter();

		bool _begin__samplerDEPTH__magfilter( void* attributeData ){return mImpl->begin__samplerDEPTH__magfilter();}
		bool _data__samplerDEPTH__magfilter( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__magfilter(){return mImpl->end__samplerDEPTH__magfilter();}
		bool _validateBegin__samplerDEPTH__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__magfilter();

		bool _begin__samplerDEPTH__extra( void* attributeData ){return mImpl->begin__samplerDEPTH__extra(*static_cast<samplerDEPTH__extra__AttributeData*>(attributeData));}
		bool _data__samplerDEPTH__extra( const ParserChar* text, size_t textLength );
		bool _end__samplerDEPTH__extra(){return mImpl->end__samplerDEPTH__extra();}
		bool _validateBegin__samplerDEPTH__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__samplerDEPTH__extra();

		bool _begin__setparam__enum( void* attributeData ){return mImpl->begin__setparam__enum();}
		bool _data__setparam__enum( const ParserChar* text, size_t textLength );
		bool _end__setparam__enum(){return mImpl->end__setparam__enum();}
		bool _validateBegin__setparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__enum();

		bool _begin__instance_effect__extra( void* attributeData ){return mImpl->begin__instance_effect__extra(*static_cast<instance_effect__extra__AttributeData*>(attributeData));}
		bool _data__instance_effect__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_effect__extra(){return mImpl->end__instance_effect__extra();}
		bool _validateBegin__instance_effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_effect__extra();

		bool _begin__animation( void* attributeData ){return mImpl->begin__animation(*static_cast<animation__AttributeData*>(attributeData));}
		bool _data__animation( const ParserChar* text, size_t textLength );
		bool _end__animation(){return mImpl->end__animation();}
		bool _validateBegin__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation();

		bool _begin__animation__asset( void* attributeData ){return mImpl->begin__animation__asset();}
		bool _data__animation__asset( const ParserChar* text, size_t textLength );
		bool _end__animation__asset(){return mImpl->end__animation__asset();}
		bool _validateBegin__animation__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__asset();

		bool _begin__animation__source( void* attributeData ){return mImpl->begin__animation__source(*static_cast<animation__source__AttributeData*>(attributeData));}
		bool _data__animation__source( const ParserChar* text, size_t textLength );
		bool _end__animation__source(){return mImpl->end__animation__source();}
		bool _validateBegin__animation__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__source();

		bool _begin__source__asset( void* attributeData ){return mImpl->begin__source__asset();}
		bool _data__source__asset( const ParserChar* text, size_t textLength );
		bool _end__source__asset(){return mImpl->end__source__asset();}
		bool _validateBegin__source__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__asset();

		bool _begin__IDREF_array( void* attributeData ){return mImpl->begin__IDREF_array(*static_cast<IDREF_array__AttributeData*>(attributeData));}
		bool _data__IDREF_array( const ParserChar* text, size_t textLength );
		bool _end__IDREF_array(){return mImpl->end__IDREF_array();}
		bool _validateBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__IDREF_array();

		bool _begin__Name_array( void* attributeData ){return mImpl->begin__Name_array(*static_cast<Name_array__AttributeData*>(attributeData));}
		bool _data__Name_array( const ParserChar* text, size_t textLength );
		bool _end__Name_array(){return mImpl->end__Name_array();}
		bool _validateBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__Name_array();

		bool _begin__bool_array( void* attributeData ){return mImpl->begin__bool_array(*static_cast<bool_array__AttributeData*>(attributeData));}
		bool _data__bool_array( const ParserChar* text, size_t textLength );
		bool _end__bool_array(){return mImpl->end__bool_array();}
		bool _validateBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bool_array();

		bool _begin__float_array( void* attributeData ){return mImpl->begin__float_array(*static_cast<float_array__AttributeData*>(attributeData));}
		bool _data__float_array( const ParserChar* text, size_t textLength );
		bool _end__float_array(){return mImpl->end__float_array();}
		bool _validateBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__float_array();

		bool _begin__int_array( void* attributeData ){return mImpl->begin__int_array(*static_cast<int_array__AttributeData*>(attributeData));}
		bool _data__int_array( const ParserChar* text, size_t textLength );
		bool _end__int_array(){return mImpl->end__int_array();}
		bool _validateBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__int_array();

		bool _begin__source__technique_common( void* attributeData ){return mImpl->begin__source__technique_common();}
		bool _data__source__technique_common( const ParserChar* text, size_t textLength );
		bool _end__source__technique_common(){return mImpl->end__source__technique_common();}
		bool _validateBegin__source__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__technique_common();

		bool _begin__accessor( void* attributeData ){return mImpl->begin__accessor(*static_cast<accessor__AttributeData*>(attributeData));}
		bool _data__accessor( const ParserChar* text, size_t textLength );
		bool _end__accessor(){return mImpl->end__accessor();}
		bool _validateBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__accessor();

		bool _begin__accessor__param( void* attributeData ){return mImpl->begin__accessor__param(*static_cast<accessor__param__AttributeData*>(attributeData));}
		bool _data__accessor__param( const ParserChar* text, size_t textLength );
		bool _end__accessor__param(){return mImpl->end__accessor__param();}
		bool _validateBegin__accessor__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__accessor__param();

		bool _begin__source__technique( void* attributeData ){return mImpl->begin__source__technique(*static_cast<source__technique__AttributeData*>(attributeData));}
		bool _data__source__technique( const ParserChar* text, size_t textLength );
		bool _end__source__technique(){return mImpl->end__source__technique();}
		bool _validateBegin__source__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source__technique();

		bool _begin__sampler( void* attributeData ){return mImpl->begin__sampler(*static_cast<sampler__AttributeData*>(attributeData));}
		bool _data__sampler( const ParserChar* text, size_t textLength );
		bool _end__sampler(){return mImpl->end__sampler();}
		bool _validateBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler();

		bool _begin__sampler__input( void* attributeData ){return mImpl->begin__sampler__input(*static_cast<sampler__input__AttributeData*>(attributeData));}
		bool _data__sampler__input( const ParserChar* text, size_t textLength );
		bool _end__sampler__input(){return mImpl->end__sampler__input();}
		bool _validateBegin__sampler__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler__input();

		bool _begin__channel( void* attributeData ){return mImpl->begin__channel(*static_cast<channel__AttributeData*>(attributeData));}
		bool _data__channel( const ParserChar* text, size_t textLength );
		bool _end__channel(){return mImpl->end__channel();}
		bool _validateBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__channel();

		bool _begin__animation__extra( void* attributeData ){return mImpl->begin__animation__extra(*static_cast<animation__extra__AttributeData*>(attributeData));}
		bool _data__animation__extra( const ParserChar* text, size_t textLength );
		bool _end__animation__extra(){return mImpl->end__animation__extra();}
		bool _validateBegin__animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation__extra();

		bool _begin__trifans( void* attributeData ){return mImpl->begin__trifans(*static_cast<trifans__AttributeData*>(attributeData));}
		bool _data__trifans( const ParserChar* text, size_t textLength );
		bool _end__trifans(){return mImpl->end__trifans();}
		bool _validateBegin__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans();

		bool _begin__trifans__input( void* attributeData ){return mImpl->begin__trifans__input(*static_cast<trifans__input__AttributeData*>(attributeData));}
		bool _data__trifans__input( const ParserChar* text, size_t textLength );
		bool _end__trifans__input(){return mImpl->end__trifans__input();}
		bool _validateBegin__trifans__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__input();

		bool _begin__trifans__p( void* attributeData ){return mImpl->begin__trifans__p();}
		bool _data__trifans__p( const ParserChar* text, size_t textLength );
		bool _end__trifans__p(){return mImpl->end__trifans__p();}
		bool _validateBegin__trifans__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__p();

		bool _begin__trifans__extra( void* attributeData ){return mImpl->begin__trifans__extra(*static_cast<trifans__extra__AttributeData*>(attributeData));}
		bool _data__trifans__extra( const ParserChar* text, size_t textLength );
		bool _end__trifans__extra(){return mImpl->end__trifans__extra();}
		bool _validateBegin__trifans__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__trifans__extra();

		bool _begin__source( void* attributeData ){return mImpl->begin__source(*static_cast<source__AttributeData*>(attributeData));}
		bool _data__source( const ParserChar* text, size_t textLength );
		bool _end__source(){return mImpl->end__source();}
		bool _validateBegin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__source();

		bool _begin__profile_GLES( void* attributeData ){return mImpl->begin__profile_GLES(*static_cast<profile_GLES__AttributeData*>(attributeData));}
		bool _data__profile_GLES( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES(){return mImpl->end__profile_GLES();}
		bool _validateBegin__profile_GLES( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES();

		bool _begin__profile_GLES__asset( void* attributeData ){return mImpl->begin__profile_GLES__asset();}
		bool _data__profile_GLES__asset( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES__asset(){return mImpl->end__profile_GLES__asset();}
		bool _validateBegin__profile_GLES__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__asset();

		bool _begin__profile_GLES__image( void* attributeData ){return mImpl->begin__profile_GLES__image(*static_cast<profile_GLES__image__AttributeData*>(attributeData));}
		bool _data__profile_GLES__image( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES__image(){return mImpl->end__profile_GLES__image();}
		bool _validateBegin__profile_GLES__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__image();

		bool _begin__image__asset( void* attributeData ){return mImpl->begin__image__asset();}
		bool _data__image__asset( const ParserChar* text, size_t textLength );
		bool _end__image__asset(){return mImpl->end__image__asset();}
		bool _validateBegin__image__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__asset();

		bool _begin__data( void* attributeData ){return mImpl->begin__data();}
		bool _data__data( const ParserChar* text, size_t textLength );
		bool _end__data(){return mImpl->end__data();}
		bool _validateBegin__data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__data();

		bool _begin__image__init_from( void* attributeData ){return mImpl->begin__image__init_from();}
		bool _data__image__init_from( const ParserChar* text, size_t textLength );
		bool _end__image__init_from(){return mImpl->end__image__init_from();}
		bool _validateBegin__image__init_from( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__init_from();

		bool _begin__image__extra( void* attributeData ){return mImpl->begin__image__extra(*static_cast<image__extra__AttributeData*>(attributeData));}
		bool _data__image__extra( const ParserChar* text, size_t textLength );
		bool _end__image__extra(){return mImpl->end__image__extra();}
		bool _validateBegin__image__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image__extra();

		bool _begin__profile_GLES__newparam( void* attributeData ){return mImpl->begin__profile_GLES__newparam(*static_cast<profile_GLES__newparam__AttributeData*>(attributeData));}
		bool _data__profile_GLES__newparam( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES__newparam(){return mImpl->end__profile_GLES__newparam();}
		bool _validateBegin__profile_GLES__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__newparam();

		bool _begin__newparam__annotate( void* attributeData ){return mImpl->begin__newparam__annotate(*static_cast<newparam__annotate__AttributeData*>(attributeData));}
		bool _data__newparam__annotate( const ParserChar* text, size_t textLength );
		bool _end__newparam__annotate(){return mImpl->end__newparam__annotate();}
		bool _validateBegin__newparam__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__annotate();

		bool _begin__annotate__bool( void* attributeData ){return mImpl->begin__annotate__bool();}
		bool _data__annotate__bool( const ParserChar* text, size_t textLength );
		bool _end__annotate__bool(){return mImpl->end__annotate__bool();}
		bool _validateBegin__annotate__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool();

		bool _begin__annotate__bool2( void* attributeData ){return mImpl->begin__annotate__bool2();}
		bool _data__annotate__bool2( const ParserChar* text, size_t textLength );
		bool _end__annotate__bool2(){return mImpl->end__annotate__bool2();}
		bool _validateBegin__annotate__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool2();

		bool _begin__annotate__bool3( void* attributeData ){return mImpl->begin__annotate__bool3();}
		bool _data__annotate__bool3( const ParserChar* text, size_t textLength );
		bool _end__annotate__bool3(){return mImpl->end__annotate__bool3();}
		bool _validateBegin__annotate__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool3();

		bool _begin__annotate__bool4( void* attributeData ){return mImpl->begin__annotate__bool4();}
		bool _data__annotate__bool4( const ParserChar* text, size_t textLength );
		bool _end__annotate__bool4(){return mImpl->end__annotate__bool4();}
		bool _validateBegin__annotate__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__bool4();

		bool _begin__annotate__int( void* attributeData ){return mImpl->begin__annotate__int();}
		bool _data__annotate__int( const ParserChar* text, size_t textLength );
		bool _end__annotate__int(){return mImpl->end__annotate__int();}
		bool _validateBegin__annotate__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int();

		bool _begin__annotate__int2( void* attributeData ){return mImpl->begin__annotate__int2();}
		bool _data__annotate__int2( const ParserChar* text, size_t textLength );
		bool _end__annotate__int2(){return mImpl->end__annotate__int2();}
		bool _validateBegin__annotate__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int2();

		bool _begin__annotate__int3( void* attributeData ){return mImpl->begin__annotate__int3();}
		bool _data__annotate__int3( const ParserChar* text, size_t textLength );
		bool _end__annotate__int3(){return mImpl->end__annotate__int3();}
		bool _validateBegin__annotate__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int3();

		bool _begin__annotate__int4( void* attributeData ){return mImpl->begin__annotate__int4();}
		bool _data__annotate__int4( const ParserChar* text, size_t textLength );
		bool _end__annotate__int4(){return mImpl->end__annotate__int4();}
		bool _validateBegin__annotate__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__int4();

		bool _begin__annotate__float( void* attributeData ){return mImpl->begin__annotate__float();}
		bool _data__annotate__float( const ParserChar* text, size_t textLength );
		bool _end__annotate__float(){return mImpl->end__annotate__float();}
		bool _validateBegin__annotate__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float();

		bool _begin__annotate__float2( void* attributeData ){return mImpl->begin__annotate__float2();}
		bool _data__annotate__float2( const ParserChar* text, size_t textLength );
		bool _end__annotate__float2(){return mImpl->end__annotate__float2();}
		bool _validateBegin__annotate__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float2();

		bool _begin__annotate__float3( void* attributeData ){return mImpl->begin__annotate__float3();}
		bool _data__annotate__float3( const ParserChar* text, size_t textLength );
		bool _end__annotate__float3(){return mImpl->end__annotate__float3();}
		bool _validateBegin__annotate__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float3();

		bool _begin__annotate__float4( void* attributeData ){return mImpl->begin__annotate__float4();}
		bool _data__annotate__float4( const ParserChar* text, size_t textLength );
		bool _end__annotate__float4(){return mImpl->end__annotate__float4();}
		bool _validateBegin__annotate__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float4();

		bool _begin__annotate__float2x2( void* attributeData ){return mImpl->begin__annotate__float2x2();}
		bool _data__annotate__float2x2( const ParserChar* text, size_t textLength );
		bool _end__annotate__float2x2(){return mImpl->end__annotate__float2x2();}
		bool _validateBegin__annotate__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float2x2();

		bool _begin__annotate__float3x3( void* attributeData ){return mImpl->begin__annotate__float3x3();}
		bool _data__annotate__float3x3( const ParserChar* text, size_t textLength );
		bool _end__annotate__float3x3(){return mImpl->end__annotate__float3x3();}
		bool _validateBegin__annotate__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float3x3();

		bool _begin__annotate__float4x4( void* attributeData ){return mImpl->begin__annotate__float4x4();}
		bool _data__annotate__float4x4( const ParserChar* text, size_t textLength );
		bool _end__annotate__float4x4(){return mImpl->end__annotate__float4x4();}
		bool _validateBegin__annotate__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__float4x4();

		bool _begin__annotate__string( void* attributeData ){return mImpl->begin__annotate__string();}
		bool _data__annotate__string( const ParserChar* text, size_t textLength );
		bool _end__annotate__string(){return mImpl->end__annotate__string();}
		bool _validateBegin__annotate__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__annotate__string();

		bool _begin__semantic( void* attributeData ){return mImpl->begin__semantic();}
		bool _data__semantic( const ParserChar* text, size_t textLength );
		bool _end__semantic(){return mImpl->end__semantic();}
		bool _validateBegin__semantic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__semantic();

		bool _begin__modifier( void* attributeData ){return mImpl->begin__modifier();}
		bool _data__modifier( const ParserChar* text, size_t textLength );
		bool _end__modifier(){return mImpl->end__modifier();}
		bool _validateBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__modifier();

		bool _begin__newparam__bool( void* attributeData ){return mImpl->begin__newparam__bool();}
		bool _data__newparam__bool( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool(){return mImpl->end__newparam__bool();}
		bool _validateBegin__newparam__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool();

		bool _begin__newparam__bool2( void* attributeData ){return mImpl->begin__newparam__bool2();}
		bool _data__newparam__bool2( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool2(){return mImpl->end__newparam__bool2();}
		bool _validateBegin__newparam__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2();

		bool _begin__newparam__bool3( void* attributeData ){return mImpl->begin__newparam__bool3();}
		bool _data__newparam__bool3( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool3(){return mImpl->end__newparam__bool3();}
		bool _validateBegin__newparam__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3();

		bool _begin__newparam__bool4( void* attributeData ){return mImpl->begin__newparam__bool4();}
		bool _data__newparam__bool4( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool4(){return mImpl->end__newparam__bool4();}
		bool _validateBegin__newparam__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4();

		bool _begin__newparam__int( void* attributeData ){return mImpl->begin__newparam__int();}
		bool _data__newparam__int( const ParserChar* text, size_t textLength );
		bool _end__newparam__int(){return mImpl->end__newparam__int();}
		bool _validateBegin__newparam__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int();

		bool _begin__newparam__int2( void* attributeData ){return mImpl->begin__newparam__int2();}
		bool _data__newparam__int2( const ParserChar* text, size_t textLength );
		bool _end__newparam__int2(){return mImpl->end__newparam__int2();}
		bool _validateBegin__newparam__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2();

		bool _begin__newparam__int3( void* attributeData ){return mImpl->begin__newparam__int3();}
		bool _data__newparam__int3( const ParserChar* text, size_t textLength );
		bool _end__newparam__int3(){return mImpl->end__newparam__int3();}
		bool _validateBegin__newparam__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3();

		bool _begin__newparam__int4( void* attributeData ){return mImpl->begin__newparam__int4();}
		bool _data__newparam__int4( const ParserChar* text, size_t textLength );
		bool _end__newparam__int4(){return mImpl->end__newparam__int4();}
		bool _validateBegin__newparam__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4();

		bool _begin__newparam__float( void* attributeData ){return mImpl->begin__newparam__float();}
		bool _data__newparam__float( const ParserChar* text, size_t textLength );
		bool _end__newparam__float(){return mImpl->end__newparam__float();}
		bool _validateBegin__newparam__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float();

		bool _begin__newparam__float2( void* attributeData ){return mImpl->begin__newparam__float2();}
		bool _data__newparam__float2( const ParserChar* text, size_t textLength );
		bool _end__newparam__float2(){return mImpl->end__newparam__float2();}
		bool _validateBegin__newparam__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2();

		bool _begin__newparam__float3( void* attributeData ){return mImpl->begin__newparam__float3();}
		bool _data__newparam__float3( const ParserChar* text, size_t textLength );
		bool _end__newparam__float3(){return mImpl->end__newparam__float3();}
		bool _validateBegin__newparam__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3();

		bool _begin__newparam__float4( void* attributeData ){return mImpl->begin__newparam__float4();}
		bool _data__newparam__float4( const ParserChar* text, size_t textLength );
		bool _end__newparam__float4(){return mImpl->end__newparam__float4();}
		bool _validateBegin__newparam__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4();

		bool _begin__newparam__float1x1( void* attributeData ){return mImpl->begin__newparam__float1x1();}
		bool _data__newparam__float1x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__float1x1(){return mImpl->end__newparam__float1x1();}
		bool _validateBegin__newparam__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x1();

		bool _begin__newparam__float1x2( void* attributeData ){return mImpl->begin__newparam__float1x2();}
		bool _data__newparam__float1x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__float1x2(){return mImpl->end__newparam__float1x2();}
		bool _validateBegin__newparam__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x2();

		bool _begin__newparam__float1x3( void* attributeData ){return mImpl->begin__newparam__float1x3();}
		bool _data__newparam__float1x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__float1x3(){return mImpl->end__newparam__float1x3();}
		bool _validateBegin__newparam__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x3();

		bool _begin__newparam__float1x4( void* attributeData ){return mImpl->begin__newparam__float1x4();}
		bool _data__newparam__float1x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__float1x4(){return mImpl->end__newparam__float1x4();}
		bool _validateBegin__newparam__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1x4();

		bool _begin__newparam__float2x1( void* attributeData ){return mImpl->begin__newparam__float2x1();}
		bool _data__newparam__float2x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__float2x1(){return mImpl->end__newparam__float2x1();}
		bool _validateBegin__newparam__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x1();

		bool _begin__newparam__float2x2( void* attributeData ){return mImpl->begin__newparam__float2x2();}
		bool _data__newparam__float2x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__float2x2(){return mImpl->end__newparam__float2x2();}
		bool _validateBegin__newparam__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x2();

		bool _begin__newparam__float2x3( void* attributeData ){return mImpl->begin__newparam__float2x3();}
		bool _data__newparam__float2x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__float2x3(){return mImpl->end__newparam__float2x3();}
		bool _validateBegin__newparam__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x3();

		bool _begin__newparam__float2x4( void* attributeData ){return mImpl->begin__newparam__float2x4();}
		bool _data__newparam__float2x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__float2x4(){return mImpl->end__newparam__float2x4();}
		bool _validateBegin__newparam__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float2x4();

		bool _begin__newparam__float3x1( void* attributeData ){return mImpl->begin__newparam__float3x1();}
		bool _data__newparam__float3x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__float3x1(){return mImpl->end__newparam__float3x1();}
		bool _validateBegin__newparam__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x1();

		bool _begin__newparam__float3x2( void* attributeData ){return mImpl->begin__newparam__float3x2();}
		bool _data__newparam__float3x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__float3x2(){return mImpl->end__newparam__float3x2();}
		bool _validateBegin__newparam__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x2();

		bool _begin__newparam__float3x3( void* attributeData ){return mImpl->begin__newparam__float3x3();}
		bool _data__newparam__float3x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__float3x3(){return mImpl->end__newparam__float3x3();}
		bool _validateBegin__newparam__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x3();

		bool _begin__newparam__float3x4( void* attributeData ){return mImpl->begin__newparam__float3x4();}
		bool _data__newparam__float3x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__float3x4(){return mImpl->end__newparam__float3x4();}
		bool _validateBegin__newparam__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float3x4();

		bool _begin__newparam__float4x1( void* attributeData ){return mImpl->begin__newparam__float4x1();}
		bool _data__newparam__float4x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__float4x1(){return mImpl->end__newparam__float4x1();}
		bool _validateBegin__newparam__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x1();

		bool _begin__newparam__float4x2( void* attributeData ){return mImpl->begin__newparam__float4x2();}
		bool _data__newparam__float4x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__float4x2(){return mImpl->end__newparam__float4x2();}
		bool _validateBegin__newparam__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x2();

		bool _begin__newparam__float4x3( void* attributeData ){return mImpl->begin__newparam__float4x3();}
		bool _data__newparam__float4x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__float4x3(){return mImpl->end__newparam__float4x3();}
		bool _validateBegin__newparam__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x3();

		bool _begin__newparam__float4x4( void* attributeData ){return mImpl->begin__newparam__float4x4();}
		bool _data__newparam__float4x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__float4x4(){return mImpl->end__newparam__float4x4();}
		bool _validateBegin__newparam__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float4x4();

		bool _begin__newparam__surface( void* attributeData ){return mImpl->begin__newparam__surface(*static_cast<newparam__surface__AttributeData*>(attributeData));}
		bool _data__newparam__surface( const ParserChar* text, size_t textLength );
		bool _end__newparam__surface(){return mImpl->end__newparam__surface();}
		bool _validateBegin__newparam__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__surface();

		bool _begin__newparam__texture_pipeline( void* attributeData ){return mImpl->begin__newparam__texture_pipeline(*static_cast<newparam__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__newparam__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _end__newparam__texture_pipeline(){return mImpl->end__newparam__texture_pipeline();}
		bool _validateBegin__newparam__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__texture_pipeline();

		bool _begin__texture_pipeline__texcombiner( void* attributeData ){return mImpl->begin__texture_pipeline__texcombiner();}
		bool _data__texture_pipeline__texcombiner( const ParserChar* text, size_t textLength );
		bool _end__texture_pipeline__texcombiner(){return mImpl->end__texture_pipeline__texcombiner();}
		bool _validateBegin__texture_pipeline__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__texcombiner();

		bool _begin__texcombiner__constant( void* attributeData ){return mImpl->begin__texcombiner__constant(*static_cast<texcombiner__constant__AttributeData*>(attributeData));}
		bool _data__texcombiner__constant( const ParserChar* text, size_t textLength );
		bool _end__texcombiner__constant(){return mImpl->end__texcombiner__constant();}
		bool _validateBegin__texcombiner__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcombiner__constant();

		bool _begin__RGB( void* attributeData ){return mImpl->begin__RGB(*static_cast<RGB__AttributeData*>(attributeData));}
		bool _data__RGB( const ParserChar* text, size_t textLength );
		bool _end__RGB(){return mImpl->end__RGB();}
		bool _validateBegin__RGB( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__RGB();

		bool _begin__RGB__argument( void* attributeData ){return mImpl->begin__RGB__argument(*static_cast<RGB__argument__AttributeData*>(attributeData));}
		bool _data__RGB__argument( const ParserChar* text, size_t textLength );
		bool _end__RGB__argument(){return mImpl->end__RGB__argument();}
		bool _validateBegin__RGB__argument( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__RGB__argument();

		bool _begin__texcombiner__alpha( void* attributeData ){return mImpl->begin__texcombiner__alpha(*static_cast<texcombiner__alpha__AttributeData*>(attributeData));}
		bool _data__texcombiner__alpha( const ParserChar* text, size_t textLength );
		bool _end__texcombiner__alpha(){return mImpl->end__texcombiner__alpha();}
		bool _validateBegin__texcombiner__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcombiner__alpha();

		bool _begin__alpha__argument( void* attributeData ){return mImpl->begin__alpha__argument(*static_cast<alpha__argument__AttributeData*>(attributeData));}
		bool _data__alpha__argument( const ParserChar* text, size_t textLength );
		bool _end__alpha__argument(){return mImpl->end__alpha__argument();}
		bool _validateBegin__alpha__argument( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha__argument();

		bool _begin__texture_pipeline__texenv( void* attributeData ){return mImpl->begin__texture_pipeline__texenv(*static_cast<texture_pipeline__texenv__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__texenv( const ParserChar* text, size_t textLength );
		bool _end__texture_pipeline__texenv(){return mImpl->end__texture_pipeline__texenv();}
		bool _validateBegin__texture_pipeline__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__texenv();

		bool _begin__texenv__constant( void* attributeData ){return mImpl->begin__texenv__constant(*static_cast<texenv__constant__AttributeData*>(attributeData));}
		bool _data__texenv__constant( const ParserChar* text, size_t textLength );
		bool _end__texenv__constant(){return mImpl->end__texenv__constant();}
		bool _validateBegin__texenv__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texenv__constant();

		bool _begin__texture_pipeline__extra( void* attributeData ){return mImpl->begin__texture_pipeline__extra(*static_cast<texture_pipeline__extra__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__extra( const ParserChar* text, size_t textLength );
		bool _end__texture_pipeline__extra(){return mImpl->end__texture_pipeline__extra();}
		bool _validateBegin__texture_pipeline__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__extra();

		bool _begin__newparam__sampler_state( void* attributeData ){return mImpl->begin__newparam__sampler_state(*static_cast<newparam__sampler_state__AttributeData*>(attributeData));}
		bool _data__newparam__sampler_state( const ParserChar* text, size_t textLength );
		bool _end__newparam__sampler_state(){return mImpl->end__newparam__sampler_state();}
		bool _validateBegin__newparam__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler_state();

		bool _begin__sampler_state__wrap_s( void* attributeData ){return mImpl->begin__sampler_state__wrap_s();}
		bool _data__sampler_state__wrap_s( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__wrap_s(){return mImpl->end__sampler_state__wrap_s();}
		bool _validateBegin__sampler_state__wrap_s( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__wrap_s();

		bool _begin__sampler_state__wrap_t( void* attributeData ){return mImpl->begin__sampler_state__wrap_t();}
		bool _data__sampler_state__wrap_t( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__wrap_t(){return mImpl->end__sampler_state__wrap_t();}
		bool _validateBegin__sampler_state__wrap_t( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__wrap_t();

		bool _begin__sampler_state__minfilter( void* attributeData ){return mImpl->begin__sampler_state__minfilter();}
		bool _data__sampler_state__minfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__minfilter(){return mImpl->end__sampler_state__minfilter();}
		bool _validateBegin__sampler_state__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__minfilter();

		bool _begin__sampler_state__magfilter( void* attributeData ){return mImpl->begin__sampler_state__magfilter();}
		bool _data__sampler_state__magfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__magfilter(){return mImpl->end__sampler_state__magfilter();}
		bool _validateBegin__sampler_state__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__magfilter();

		bool _begin__sampler_state__mipfilter( void* attributeData ){return mImpl->begin__sampler_state__mipfilter();}
		bool _data__sampler_state__mipfilter( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__mipfilter(){return mImpl->end__sampler_state__mipfilter();}
		bool _validateBegin__sampler_state__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipfilter();

		bool _begin__sampler_state__mipmap_maxlevel( void* attributeData ){return mImpl->begin__sampler_state__mipmap_maxlevel();}
		bool _data__sampler_state__mipmap_maxlevel( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__mipmap_maxlevel(){return mImpl->end__sampler_state__mipmap_maxlevel();}
		bool _validateBegin__sampler_state__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipmap_maxlevel();

		bool _begin__sampler_state__mipmap_bias( void* attributeData ){return mImpl->begin__sampler_state__mipmap_bias();}
		bool _data__sampler_state__mipmap_bias( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__mipmap_bias(){return mImpl->end__sampler_state__mipmap_bias();}
		bool _validateBegin__sampler_state__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__mipmap_bias();

		bool _begin__sampler_state__extra( void* attributeData ){return mImpl->begin__sampler_state__extra(*static_cast<sampler_state__extra__AttributeData*>(attributeData));}
		bool _data__sampler_state__extra( const ParserChar* text, size_t textLength );
		bool _end__sampler_state__extra(){return mImpl->end__sampler_state__extra();}
		bool _validateBegin__sampler_state__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sampler_state__extra();

		bool _begin__newparam__texture_unit( void* attributeData ){return mImpl->begin__newparam__texture_unit(*static_cast<newparam__texture_unit__AttributeData*>(attributeData));}
		bool _data__newparam__texture_unit( const ParserChar* text, size_t textLength );
		bool _end__newparam__texture_unit(){return mImpl->end__newparam__texture_unit();}
		bool _validateBegin__newparam__texture_unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__texture_unit();

		bool _begin__texture_unit__surface( void* attributeData ){return mImpl->begin__texture_unit__surface();}
		bool _data__texture_unit__surface( const ParserChar* text, size_t textLength );
		bool _end__texture_unit__surface(){return mImpl->end__texture_unit__surface();}
		bool _validateBegin__texture_unit__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__surface();

		bool _begin__texture_unit__sampler_state( void* attributeData ){return mImpl->begin__texture_unit__sampler_state();}
		bool _data__texture_unit__sampler_state( const ParserChar* text, size_t textLength );
		bool _end__texture_unit__sampler_state(){return mImpl->end__texture_unit__sampler_state();}
		bool _validateBegin__texture_unit__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__sampler_state();

		bool _begin__texcoord( void* attributeData ){return mImpl->begin__texcoord(*static_cast<texcoord__AttributeData*>(attributeData));}
		bool _data__texcoord( const ParserChar* text, size_t textLength );
		bool _end__texcoord(){return mImpl->end__texcoord();}
		bool _validateBegin__texcoord( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texcoord();

		bool _begin__texture_unit__extra( void* attributeData ){return mImpl->begin__texture_unit__extra(*static_cast<texture_unit__extra__AttributeData*>(attributeData));}
		bool _data__texture_unit__extra( const ParserChar* text, size_t textLength );
		bool _end__texture_unit__extra(){return mImpl->end__texture_unit__extra();}
		bool _validateBegin__texture_unit__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_unit__extra();

		bool _begin__newparam__enum( void* attributeData ){return mImpl->begin__newparam__enum();}
		bool _data__newparam__enum( const ParserChar* text, size_t textLength );
		bool _end__newparam__enum(){return mImpl->end__newparam__enum();}
		bool _validateBegin__newparam__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__enum();

		bool _begin__profile_GLES__technique( void* attributeData ){return mImpl->begin__profile_GLES__technique(*static_cast<profile_GLES__technique__AttributeData*>(attributeData));}
		bool _data__profile_GLES__technique( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES__technique(){return mImpl->end__profile_GLES__technique();}
		bool _validateBegin__profile_GLES__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__technique();

		bool _begin__technique__asset( void* attributeData ){return mImpl->begin__technique__asset();}
		bool _data__technique__asset( const ParserChar* text, size_t textLength );
		bool _end__technique__asset(){return mImpl->end__technique__asset();}
		bool _validateBegin__technique__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__asset();

		bool _begin__technique__annotate( void* attributeData ){return mImpl->begin__technique__annotate(*static_cast<technique__annotate__AttributeData*>(attributeData));}
		bool _data__technique__annotate( const ParserChar* text, size_t textLength );
		bool _end__technique__annotate(){return mImpl->end__technique__annotate();}
		bool _validateBegin__technique__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__annotate();

		bool _begin__technique__image( void* attributeData ){return mImpl->begin__technique__image(*static_cast<technique__image__AttributeData*>(attributeData));}
		bool _data__technique__image( const ParserChar* text, size_t textLength );
		bool _end__technique__image(){return mImpl->end__technique__image();}
		bool _validateBegin__technique__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__image();

		bool _begin__technique__newparam( void* attributeData ){return mImpl->begin__technique__newparam(*static_cast<technique__newparam__AttributeData*>(attributeData));}
		bool _data__technique__newparam( const ParserChar* text, size_t textLength );
		bool _end__technique__newparam(){return mImpl->end__technique__newparam();}
		bool _validateBegin__technique__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__newparam();

		bool _begin__technique__setparam( void* attributeData ){return mImpl->begin__technique__setparam(*static_cast<technique__setparam__AttributeData*>(attributeData));}
		bool _data__technique__setparam( const ParserChar* text, size_t textLength );
		bool _end__technique__setparam(){return mImpl->end__technique__setparam();}
		bool _validateBegin__technique__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__setparam();

		bool _begin__setparam__annotate( void* attributeData ){return mImpl->begin__setparam__annotate(*static_cast<setparam__annotate__AttributeData*>(attributeData));}
		bool _data__setparam__annotate( const ParserChar* text, size_t textLength );
		bool _end__setparam__annotate(){return mImpl->end__setparam__annotate();}
		bool _validateBegin__setparam__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__annotate();

		bool _begin__setparam__texture_pipeline( void* attributeData ){return mImpl->begin__setparam__texture_pipeline(*static_cast<setparam__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__setparam__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _end__setparam__texture_pipeline(){return mImpl->end__setparam__texture_pipeline();}
		bool _validateBegin__setparam__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__texture_pipeline();

		bool _begin__setparam__sampler_state( void* attributeData ){return mImpl->begin__setparam__sampler_state(*static_cast<setparam__sampler_state__AttributeData*>(attributeData));}
		bool _data__setparam__sampler_state( const ParserChar* text, size_t textLength );
		bool _end__setparam__sampler_state(){return mImpl->end__setparam__sampler_state();}
		bool _validateBegin__setparam__sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__sampler_state();

		bool _begin__setparam__texture_unit( void* attributeData ){return mImpl->begin__setparam__texture_unit(*static_cast<setparam__texture_unit__AttributeData*>(attributeData));}
		bool _data__setparam__texture_unit( const ParserChar* text, size_t textLength );
		bool _end__setparam__texture_unit(){return mImpl->end__setparam__texture_unit();}
		bool _validateBegin__setparam__texture_unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__texture_unit();

		bool _begin__pass( void* attributeData ){return mImpl->begin__pass(*static_cast<pass__AttributeData*>(attributeData));}
		bool _data__pass( const ParserChar* text, size_t textLength );
		bool _end__pass(){return mImpl->end__pass();}
		bool _validateBegin__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass();

		bool _begin__pass__annotate( void* attributeData ){return mImpl->begin__pass__annotate(*static_cast<pass__annotate__AttributeData*>(attributeData));}
		bool _data__pass__annotate( const ParserChar* text, size_t textLength );
		bool _end__pass__annotate(){return mImpl->end__pass__annotate();}
		bool _validateBegin__pass__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__annotate();

		bool _begin__color_target( void* attributeData ){return mImpl->begin__color_target();}
		bool _data__color_target( const ParserChar* text, size_t textLength );
		bool _end__color_target(){return mImpl->end__color_target();}
		bool _validateBegin__color_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_target();

		bool _begin__depth_target( void* attributeData ){return mImpl->begin__depth_target();}
		bool _data__depth_target( const ParserChar* text, size_t textLength );
		bool _end__depth_target(){return mImpl->end__depth_target();}
		bool _validateBegin__depth_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_target();

		bool _begin__stencil_target( void* attributeData ){return mImpl->begin__stencil_target();}
		bool _data__stencil_target( const ParserChar* text, size_t textLength );
		bool _end__stencil_target(){return mImpl->end__stencil_target();}
		bool _validateBegin__stencil_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_target();

		bool _begin__color_clear( void* attributeData ){return mImpl->begin__color_clear();}
		bool _data__color_clear( const ParserChar* text, size_t textLength );
		bool _end__color_clear(){return mImpl->end__color_clear();}
		bool _validateBegin__color_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_clear();

		bool _begin__depth_clear( void* attributeData ){return mImpl->begin__depth_clear();}
		bool _data__depth_clear( const ParserChar* text, size_t textLength );
		bool _end__depth_clear(){return mImpl->end__depth_clear();}
		bool _validateBegin__depth_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_clear();

		bool _begin__stencil_clear( void* attributeData ){return mImpl->begin__stencil_clear();}
		bool _data__stencil_clear( const ParserChar* text, size_t textLength );
		bool _end__stencil_clear(){return mImpl->end__stencil_clear();}
		bool _validateBegin__stencil_clear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_clear();

		bool _begin__draw( void* attributeData ){return mImpl->begin__draw();}
		bool _data__draw( const ParserChar* text, size_t textLength );
		bool _end__draw(){return mImpl->end__draw();}
		bool _validateBegin__draw( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__draw();

		bool _begin__alpha_func( void* attributeData ){return mImpl->begin__alpha_func();}
		bool _data__alpha_func( const ParserChar* text, size_t textLength );
		bool _end__alpha_func(){return mImpl->end__alpha_func();}
		bool _validateBegin__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func();

		bool _begin__alpha_func__func( void* attributeData ){return mImpl->begin__alpha_func__func(*static_cast<alpha_func__func__AttributeData*>(attributeData));}
		bool _data__alpha_func__func( const ParserChar* text, size_t textLength );
		bool _end__alpha_func__func(){return mImpl->end__alpha_func__func();}
		bool _validateBegin__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func__func();

		bool _begin__alpha_func__value( void* attributeData ){return mImpl->begin__alpha_func__value(*static_cast<alpha_func__value__AttributeData*>(attributeData));}
		bool _data__alpha_func__value( const ParserChar* text, size_t textLength );
		bool _end__alpha_func__value(){return mImpl->end__alpha_func__value();}
		bool _validateBegin__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_func__value();

		bool _begin__blend_func( void* attributeData ){return mImpl->begin__blend_func();}
		bool _data__blend_func( const ParserChar* text, size_t textLength );
		bool _end__blend_func(){return mImpl->end__blend_func();}
		bool _validateBegin__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blend_func();

		bool _begin__src( void* attributeData ){return mImpl->begin__src(*static_cast<src__AttributeData*>(attributeData));}
		bool _data__src( const ParserChar* text, size_t textLength );
		bool _end__src(){return mImpl->end__src();}
		bool _validateBegin__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__src();

		bool _begin__dest( void* attributeData ){return mImpl->begin__dest(*static_cast<dest__AttributeData*>(attributeData));}
		bool _data__dest( const ParserChar* text, size_t textLength );
		bool _end__dest(){return mImpl->end__dest();}
		bool _validateBegin__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dest();

		bool _begin__clear_color( void* attributeData ){return mImpl->begin__clear_color(*static_cast<clear_color__AttributeData*>(attributeData));}
		bool _data__clear_color( const ParserChar* text, size_t textLength );
		bool _end__clear_color(){return mImpl->end__clear_color();}
		bool _validateBegin__clear_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_color();

		bool _begin__clear_stencil( void* attributeData ){return mImpl->begin__clear_stencil(*static_cast<clear_stencil__AttributeData*>(attributeData));}
		bool _data__clear_stencil( const ParserChar* text, size_t textLength );
		bool _end__clear_stencil(){return mImpl->end__clear_stencil();}
		bool _validateBegin__clear_stencil( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_stencil();

		bool _begin__clear_depth( void* attributeData ){return mImpl->begin__clear_depth(*static_cast<clear_depth__AttributeData*>(attributeData));}
		bool _data__clear_depth( const ParserChar* text, size_t textLength );
		bool _end__clear_depth(){return mImpl->end__clear_depth();}
		bool _validateBegin__clear_depth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clear_depth();

		bool _begin__clip_plane( void* attributeData ){return mImpl->begin__clip_plane(*static_cast<clip_plane__AttributeData*>(attributeData));}
		bool _data__clip_plane( const ParserChar* text, size_t textLength );
		bool _end__clip_plane(){return mImpl->end__clip_plane();}
		bool _validateBegin__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clip_plane();

		bool _begin__color_mask( void* attributeData ){return mImpl->begin__color_mask(*static_cast<color_mask__AttributeData*>(attributeData));}
		bool _data__color_mask( const ParserChar* text, size_t textLength );
		bool _end__color_mask(){return mImpl->end__color_mask();}
		bool _validateBegin__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_mask();

		bool _begin__cull_face( void* attributeData ){return mImpl->begin__cull_face(*static_cast<cull_face__AttributeData*>(attributeData));}
		bool _data__cull_face( const ParserChar* text, size_t textLength );
		bool _end__cull_face(){return mImpl->end__cull_face();}
		bool _validateBegin__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cull_face();

		bool _begin__depth_func( void* attributeData ){return mImpl->begin__depth_func(*static_cast<depth_func__AttributeData*>(attributeData));}
		bool _data__depth_func( const ParserChar* text, size_t textLength );
		bool _end__depth_func(){return mImpl->end__depth_func();}
		bool _validateBegin__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_func();

		bool _begin__depth_mask( void* attributeData ){return mImpl->begin__depth_mask(*static_cast<depth_mask__AttributeData*>(attributeData));}
		bool _data__depth_mask( const ParserChar* text, size_t textLength );
		bool _end__depth_mask(){return mImpl->end__depth_mask();}
		bool _validateBegin__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_mask();

		bool _begin__depth_range( void* attributeData ){return mImpl->begin__depth_range(*static_cast<depth_range__AttributeData*>(attributeData));}
		bool _data__depth_range( const ParserChar* text, size_t textLength );
		bool _end__depth_range(){return mImpl->end__depth_range();}
		bool _validateBegin__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_range();

		bool _begin__fog_color( void* attributeData ){return mImpl->begin__fog_color(*static_cast<fog_color__AttributeData*>(attributeData));}
		bool _data__fog_color( const ParserChar* text, size_t textLength );
		bool _end__fog_color(){return mImpl->end__fog_color();}
		bool _validateBegin__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_color();

		bool _begin__fog_density( void* attributeData ){return mImpl->begin__fog_density(*static_cast<fog_density__AttributeData*>(attributeData));}
		bool _data__fog_density( const ParserChar* text, size_t textLength );
		bool _end__fog_density(){return mImpl->end__fog_density();}
		bool _validateBegin__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_density();

		bool _begin__fog_mode( void* attributeData ){return mImpl->begin__fog_mode(*static_cast<fog_mode__AttributeData*>(attributeData));}
		bool _data__fog_mode( const ParserChar* text, size_t textLength );
		bool _end__fog_mode(){return mImpl->end__fog_mode();}
		bool _validateBegin__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_mode();

		bool _begin__fog_start( void* attributeData ){return mImpl->begin__fog_start(*static_cast<fog_start__AttributeData*>(attributeData));}
		bool _data__fog_start( const ParserChar* text, size_t textLength );
		bool _end__fog_start(){return mImpl->end__fog_start();}
		bool _validateBegin__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_start();

		bool _begin__fog_end( void* attributeData ){return mImpl->begin__fog_end(*static_cast<fog_end__AttributeData*>(attributeData));}
		bool _data__fog_end( const ParserChar* text, size_t textLength );
		bool _end__fog_end(){return mImpl->end__fog_end();}
		bool _validateBegin__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_end();

		bool _begin__front_face( void* attributeData ){return mImpl->begin__front_face(*static_cast<front_face__AttributeData*>(attributeData));}
		bool _data__front_face( const ParserChar* text, size_t textLength );
		bool _end__front_face(){return mImpl->end__front_face();}
		bool _validateBegin__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__front_face();

		bool _begin__pass__texture_pipeline( void* attributeData ){return mImpl->begin__pass__texture_pipeline(*static_cast<pass__texture_pipeline__AttributeData*>(attributeData));}
		bool _data__pass__texture_pipeline( const ParserChar* text, size_t textLength );
		bool _end__pass__texture_pipeline(){return mImpl->end__pass__texture_pipeline();}
		bool _validateBegin__pass__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__texture_pipeline();

		bool _begin__texture_pipeline__value( void* attributeData ){return mImpl->begin__texture_pipeline__value(*static_cast<texture_pipeline__value__AttributeData*>(attributeData));}
		bool _data__texture_pipeline__value( const ParserChar* text, size_t textLength );
		bool _end__texture_pipeline__value(){return mImpl->end__texture_pipeline__value();}
		bool _validateBegin__texture_pipeline__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline__value();

		bool _begin__value__texcombiner( void* attributeData ){return mImpl->begin__value__texcombiner();}
		bool _data__value__texcombiner( const ParserChar* text, size_t textLength );
		bool _end__value__texcombiner(){return mImpl->end__value__texcombiner();}
		bool _validateBegin__value__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__texcombiner();

		bool _begin__value__texenv( void* attributeData ){return mImpl->begin__value__texenv(*static_cast<value__texenv__AttributeData*>(attributeData));}
		bool _data__value__texenv( const ParserChar* text, size_t textLength );
		bool _end__value__texenv(){return mImpl->end__value__texenv();}
		bool _validateBegin__value__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__texenv();

		bool _begin__value__extra( void* attributeData ){return mImpl->begin__value__extra(*static_cast<value__extra__AttributeData*>(attributeData));}
		bool _data__value__extra( const ParserChar* text, size_t textLength );
		bool _end__value__extra(){return mImpl->end__value__extra();}
		bool _validateBegin__value__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__value__extra();

		bool _begin__logic_op( void* attributeData ){return mImpl->begin__logic_op(*static_cast<logic_op__AttributeData*>(attributeData));}
		bool _data__logic_op( const ParserChar* text, size_t textLength );
		bool _end__logic_op(){return mImpl->end__logic_op();}
		bool _validateBegin__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__logic_op();

		bool _begin__light_ambient( void* attributeData ){return mImpl->begin__light_ambient(*static_cast<light_ambient__AttributeData*>(attributeData));}
		bool _data__light_ambient( const ParserChar* text, size_t textLength );
		bool _end__light_ambient(){return mImpl->end__light_ambient();}
		bool _validateBegin__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_ambient();

		bool _begin__light_diffuse( void* attributeData ){return mImpl->begin__light_diffuse(*static_cast<light_diffuse__AttributeData*>(attributeData));}
		bool _data__light_diffuse( const ParserChar* text, size_t textLength );
		bool _end__light_diffuse(){return mImpl->end__light_diffuse();}
		bool _validateBegin__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_diffuse();

		bool _begin__light_specular( void* attributeData ){return mImpl->begin__light_specular(*static_cast<light_specular__AttributeData*>(attributeData));}
		bool _data__light_specular( const ParserChar* text, size_t textLength );
		bool _end__light_specular(){return mImpl->end__light_specular();}
		bool _validateBegin__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_specular();

		bool _begin__light_position( void* attributeData ){return mImpl->begin__light_position(*static_cast<light_position__AttributeData*>(attributeData));}
		bool _data__light_position( const ParserChar* text, size_t textLength );
		bool _end__light_position(){return mImpl->end__light_position();}
		bool _validateBegin__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_position();

		bool _begin__light_constant_attenuation( void* attributeData ){return mImpl->begin__light_constant_attenuation(*static_cast<light_constant_attenuation__AttributeData*>(attributeData));}
		bool _data__light_constant_attenuation( const ParserChar* text, size_t textLength );
		bool _end__light_constant_attenuation(){return mImpl->end__light_constant_attenuation();}
		bool _validateBegin__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_constant_attenuation();

		bool _begin__light_linear_attenutation( void* attributeData ){return mImpl->begin__light_linear_attenutation(*static_cast<light_linear_attenutation__AttributeData*>(attributeData));}
		bool _data__light_linear_attenutation( const ParserChar* text, size_t textLength );
		bool _end__light_linear_attenutation(){return mImpl->end__light_linear_attenutation();}
		bool _validateBegin__light_linear_attenutation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_linear_attenutation();

		bool _begin__light_quadratic_attenuation( void* attributeData ){return mImpl->begin__light_quadratic_attenuation(*static_cast<light_quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _end__light_quadratic_attenuation(){return mImpl->end__light_quadratic_attenuation();}
		bool _validateBegin__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_quadratic_attenuation();

		bool _begin__light_spot_cutoff( void* attributeData ){return mImpl->begin__light_spot_cutoff(*static_cast<light_spot_cutoff__AttributeData*>(attributeData));}
		bool _data__light_spot_cutoff( const ParserChar* text, size_t textLength );
		bool _end__light_spot_cutoff(){return mImpl->end__light_spot_cutoff();}
		bool _validateBegin__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_cutoff();

		bool _begin__light_spot_direction( void* attributeData ){return mImpl->begin__light_spot_direction(*static_cast<light_spot_direction__AttributeData*>(attributeData));}
		bool _data__light_spot_direction( const ParserChar* text, size_t textLength );
		bool _end__light_spot_direction(){return mImpl->end__light_spot_direction();}
		bool _validateBegin__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_direction();

		bool _begin__light_spot_exponent( void* attributeData ){return mImpl->begin__light_spot_exponent(*static_cast<light_spot_exponent__AttributeData*>(attributeData));}
		bool _data__light_spot_exponent( const ParserChar* text, size_t textLength );
		bool _end__light_spot_exponent(){return mImpl->end__light_spot_exponent();}
		bool _validateBegin__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_spot_exponent();

		bool _begin__light_model_ambient( void* attributeData ){return mImpl->begin__light_model_ambient(*static_cast<light_model_ambient__AttributeData*>(attributeData));}
		bool _data__light_model_ambient( const ParserChar* text, size_t textLength );
		bool _end__light_model_ambient(){return mImpl->end__light_model_ambient();}
		bool _validateBegin__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_model_ambient();

		bool _begin__line_width( void* attributeData ){return mImpl->begin__line_width(*static_cast<line_width__AttributeData*>(attributeData));}
		bool _data__line_width( const ParserChar* text, size_t textLength );
		bool _end__line_width(){return mImpl->end__line_width();}
		bool _validateBegin__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__line_width();

		bool _begin__material_ambient( void* attributeData ){return mImpl->begin__material_ambient(*static_cast<material_ambient__AttributeData*>(attributeData));}
		bool _data__material_ambient( const ParserChar* text, size_t textLength );
		bool _end__material_ambient(){return mImpl->end__material_ambient();}
		bool _validateBegin__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_ambient();

		bool _begin__material_diffuse( void* attributeData ){return mImpl->begin__material_diffuse(*static_cast<material_diffuse__AttributeData*>(attributeData));}
		bool _data__material_diffuse( const ParserChar* text, size_t textLength );
		bool _end__material_diffuse(){return mImpl->end__material_diffuse();}
		bool _validateBegin__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_diffuse();

		bool _begin__material_emission( void* attributeData ){return mImpl->begin__material_emission(*static_cast<material_emission__AttributeData*>(attributeData));}
		bool _data__material_emission( const ParserChar* text, size_t textLength );
		bool _end__material_emission(){return mImpl->end__material_emission();}
		bool _validateBegin__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_emission();

		bool _begin__material_shininess( void* attributeData ){return mImpl->begin__material_shininess(*static_cast<material_shininess__AttributeData*>(attributeData));}
		bool _data__material_shininess( const ParserChar* text, size_t textLength );
		bool _end__material_shininess(){return mImpl->end__material_shininess();}
		bool _validateBegin__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_shininess();

		bool _begin__material_specular( void* attributeData ){return mImpl->begin__material_specular(*static_cast<material_specular__AttributeData*>(attributeData));}
		bool _data__material_specular( const ParserChar* text, size_t textLength );
		bool _end__material_specular(){return mImpl->end__material_specular();}
		bool _validateBegin__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material_specular();

		bool _begin__model_view_matrix( void* attributeData ){return mImpl->begin__model_view_matrix(*static_cast<model_view_matrix__AttributeData*>(attributeData));}
		bool _data__model_view_matrix( const ParserChar* text, size_t textLength );
		bool _end__model_view_matrix(){return mImpl->end__model_view_matrix();}
		bool _validateBegin__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__model_view_matrix();

		bool _begin__point_distance_attenuation( void* attributeData ){return mImpl->begin__point_distance_attenuation(*static_cast<point_distance_attenuation__AttributeData*>(attributeData));}
		bool _data__point_distance_attenuation( const ParserChar* text, size_t textLength );
		bool _end__point_distance_attenuation(){return mImpl->end__point_distance_attenuation();}
		bool _validateBegin__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_distance_attenuation();

		bool _begin__point_fade_threshold_size( void* attributeData ){return mImpl->begin__point_fade_threshold_size(*static_cast<point_fade_threshold_size__AttributeData*>(attributeData));}
		bool _data__point_fade_threshold_size( const ParserChar* text, size_t textLength );
		bool _end__point_fade_threshold_size(){return mImpl->end__point_fade_threshold_size();}
		bool _validateBegin__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_fade_threshold_size();

		bool _begin__point_size( void* attributeData ){return mImpl->begin__point_size(*static_cast<point_size__AttributeData*>(attributeData));}
		bool _data__point_size( const ParserChar* text, size_t textLength );
		bool _end__point_size(){return mImpl->end__point_size();}
		bool _validateBegin__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size();

		bool _begin__point_size_min( void* attributeData ){return mImpl->begin__point_size_min(*static_cast<point_size_min__AttributeData*>(attributeData));}
		bool _data__point_size_min( const ParserChar* text, size_t textLength );
		bool _end__point_size_min(){return mImpl->end__point_size_min();}
		bool _validateBegin__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size_min();

		bool _begin__point_size_max( void* attributeData ){return mImpl->begin__point_size_max(*static_cast<point_size_max__AttributeData*>(attributeData));}
		bool _data__point_size_max( const ParserChar* text, size_t textLength );
		bool _end__point_size_max(){return mImpl->end__point_size_max();}
		bool _validateBegin__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_size_max();

		bool _begin__polygon_offset( void* attributeData ){return mImpl->begin__polygon_offset(*static_cast<polygon_offset__AttributeData*>(attributeData));}
		bool _data__polygon_offset( const ParserChar* text, size_t textLength );
		bool _end__polygon_offset(){return mImpl->end__polygon_offset();}
		bool _validateBegin__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygon_offset();

		bool _begin__projection_matrix( void* attributeData ){return mImpl->begin__projection_matrix(*static_cast<projection_matrix__AttributeData*>(attributeData));}
		bool _data__projection_matrix( const ParserChar* text, size_t textLength );
		bool _end__projection_matrix(){return mImpl->end__projection_matrix();}
		bool _validateBegin__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__projection_matrix();

		bool _begin__scissor( void* attributeData ){return mImpl->begin__scissor(*static_cast<scissor__AttributeData*>(attributeData));}
		bool _data__scissor( const ParserChar* text, size_t textLength );
		bool _end__scissor(){return mImpl->end__scissor();}
		bool _validateBegin__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scissor();

		bool _begin__shade_model( void* attributeData ){return mImpl->begin__shade_model(*static_cast<shade_model__AttributeData*>(attributeData));}
		bool _data__shade_model( const ParserChar* text, size_t textLength );
		bool _end__shade_model(){return mImpl->end__shade_model();}
		bool _validateBegin__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shade_model();

		bool _begin__stencil_func( void* attributeData ){return mImpl->begin__stencil_func();}
		bool _data__stencil_func( const ParserChar* text, size_t textLength );
		bool _end__stencil_func(){return mImpl->end__stencil_func();}
		bool _validateBegin__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func();

		bool _begin__stencil_func__func( void* attributeData ){return mImpl->begin__stencil_func__func(*static_cast<stencil_func__func__AttributeData*>(attributeData));}
		bool _data__stencil_func__func( const ParserChar* text, size_t textLength );
		bool _end__stencil_func__func(){return mImpl->end__stencil_func__func();}
		bool _validateBegin__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__func();

		bool _begin__stencil_func__ref( void* attributeData ){return mImpl->begin__stencil_func__ref(*static_cast<stencil_func__ref__AttributeData*>(attributeData));}
		bool _data__stencil_func__ref( const ParserChar* text, size_t textLength );
		bool _end__stencil_func__ref(){return mImpl->end__stencil_func__ref();}
		bool _validateBegin__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__ref();

		bool _begin__stencil_func__mask( void* attributeData ){return mImpl->begin__stencil_func__mask(*static_cast<stencil_func__mask__AttributeData*>(attributeData));}
		bool _data__stencil_func__mask( const ParserChar* text, size_t textLength );
		bool _end__stencil_func__mask(){return mImpl->end__stencil_func__mask();}
		bool _validateBegin__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_func__mask();

		bool _begin__stencil_mask( void* attributeData ){return mImpl->begin__stencil_mask(*static_cast<stencil_mask__AttributeData*>(attributeData));}
		bool _data__stencil_mask( const ParserChar* text, size_t textLength );
		bool _end__stencil_mask(){return mImpl->end__stencil_mask();}
		bool _validateBegin__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_mask();

		bool _begin__stencil_op( void* attributeData ){return mImpl->begin__stencil_op();}
		bool _data__stencil_op( const ParserChar* text, size_t textLength );
		bool _end__stencil_op(){return mImpl->end__stencil_op();}
		bool _validateBegin__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op();

		bool _begin__stencil_op__fail( void* attributeData ){return mImpl->begin__stencil_op__fail(*static_cast<stencil_op__fail__AttributeData*>(attributeData));}
		bool _data__stencil_op__fail( const ParserChar* text, size_t textLength );
		bool _end__stencil_op__fail(){return mImpl->end__stencil_op__fail();}
		bool _validateBegin__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__fail();

		bool _begin__stencil_op__zfail( void* attributeData ){return mImpl->begin__stencil_op__zfail(*static_cast<stencil_op__zfail__AttributeData*>(attributeData));}
		bool _data__stencil_op__zfail( const ParserChar* text, size_t textLength );
		bool _end__stencil_op__zfail(){return mImpl->end__stencil_op__zfail();}
		bool _validateBegin__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__zfail();

		bool _begin__stencil_op__zpass( void* attributeData ){return mImpl->begin__stencil_op__zpass(*static_cast<stencil_op__zpass__AttributeData*>(attributeData));}
		bool _data__stencil_op__zpass( const ParserChar* text, size_t textLength );
		bool _end__stencil_op__zpass(){return mImpl->end__stencil_op__zpass();}
		bool _validateBegin__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_op__zpass();

		bool _begin__alpha_test_enable( void* attributeData ){return mImpl->begin__alpha_test_enable(*static_cast<alpha_test_enable__AttributeData*>(attributeData));}
		bool _data__alpha_test_enable( const ParserChar* text, size_t textLength );
		bool _end__alpha_test_enable(){return mImpl->end__alpha_test_enable();}
		bool _validateBegin__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__alpha_test_enable();

		bool _begin__blend_enable( void* attributeData ){return mImpl->begin__blend_enable(*static_cast<blend_enable__AttributeData*>(attributeData));}
		bool _data__blend_enable( const ParserChar* text, size_t textLength );
		bool _end__blend_enable(){return mImpl->end__blend_enable();}
		bool _validateBegin__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blend_enable();

		bool _begin__clip_plane_enable( void* attributeData ){return mImpl->begin__clip_plane_enable(*static_cast<clip_plane_enable__AttributeData*>(attributeData));}
		bool _data__clip_plane_enable( const ParserChar* text, size_t textLength );
		bool _end__clip_plane_enable(){return mImpl->end__clip_plane_enable();}
		bool _validateBegin__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__clip_plane_enable();

		bool _begin__color_logic_op_enable( void* attributeData ){return mImpl->begin__color_logic_op_enable(*static_cast<color_logic_op_enable__AttributeData*>(attributeData));}
		bool _data__color_logic_op_enable( const ParserChar* text, size_t textLength );
		bool _end__color_logic_op_enable(){return mImpl->end__color_logic_op_enable();}
		bool _validateBegin__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_logic_op_enable();

		bool _begin__color_material_enable( void* attributeData ){return mImpl->begin__color_material_enable(*static_cast<color_material_enable__AttributeData*>(attributeData));}
		bool _data__color_material_enable( const ParserChar* text, size_t textLength );
		bool _end__color_material_enable(){return mImpl->end__color_material_enable();}
		bool _validateBegin__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__color_material_enable();

		bool _begin__cull_face_enable( void* attributeData ){return mImpl->begin__cull_face_enable(*static_cast<cull_face_enable__AttributeData*>(attributeData));}
		bool _data__cull_face_enable( const ParserChar* text, size_t textLength );
		bool _end__cull_face_enable(){return mImpl->end__cull_face_enable();}
		bool _validateBegin__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cull_face_enable();

		bool _begin__depth_test_enable( void* attributeData ){return mImpl->begin__depth_test_enable(*static_cast<depth_test_enable__AttributeData*>(attributeData));}
		bool _data__depth_test_enable( const ParserChar* text, size_t textLength );
		bool _end__depth_test_enable(){return mImpl->end__depth_test_enable();}
		bool _validateBegin__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__depth_test_enable();

		bool _begin__dither_enable( void* attributeData ){return mImpl->begin__dither_enable(*static_cast<dither_enable__AttributeData*>(attributeData));}
		bool _data__dither_enable( const ParserChar* text, size_t textLength );
		bool _end__dither_enable(){return mImpl->end__dither_enable();}
		bool _validateBegin__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dither_enable();

		bool _begin__fog_enable( void* attributeData ){return mImpl->begin__fog_enable(*static_cast<fog_enable__AttributeData*>(attributeData));}
		bool _data__fog_enable( const ParserChar* text, size_t textLength );
		bool _end__fog_enable(){return mImpl->end__fog_enable();}
		bool _validateBegin__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fog_enable();

		bool _begin__texture_pipeline_enable( void* attributeData ){return mImpl->begin__texture_pipeline_enable(*static_cast<texture_pipeline_enable__AttributeData*>(attributeData));}
		bool _data__texture_pipeline_enable( const ParserChar* text, size_t textLength );
		bool _end__texture_pipeline_enable(){return mImpl->end__texture_pipeline_enable();}
		bool _validateBegin__texture_pipeline_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture_pipeline_enable();

		bool _begin__light_enable( void* attributeData ){return mImpl->begin__light_enable(*static_cast<light_enable__AttributeData*>(attributeData));}
		bool _data__light_enable( const ParserChar* text, size_t textLength );
		bool _end__light_enable(){return mImpl->end__light_enable();}
		bool _validateBegin__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_enable();

		bool _begin__lighting_enable( void* attributeData ){return mImpl->begin__lighting_enable(*static_cast<lighting_enable__AttributeData*>(attributeData));}
		bool _data__lighting_enable( const ParserChar* text, size_t textLength );
		bool _end__lighting_enable(){return mImpl->end__lighting_enable();}
		bool _validateBegin__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lighting_enable();

		bool _begin__light_model_two_side_enable( void* attributeData ){return mImpl->begin__light_model_two_side_enable(*static_cast<light_model_two_side_enable__AttributeData*>(attributeData));}
		bool _data__light_model_two_side_enable( const ParserChar* text, size_t textLength );
		bool _end__light_model_two_side_enable(){return mImpl->end__light_model_two_side_enable();}
		bool _validateBegin__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light_model_two_side_enable();

		bool _begin__line_smooth_enable( void* attributeData ){return mImpl->begin__line_smooth_enable(*static_cast<line_smooth_enable__AttributeData*>(attributeData));}
		bool _data__line_smooth_enable( const ParserChar* text, size_t textLength );
		bool _end__line_smooth_enable(){return mImpl->end__line_smooth_enable();}
		bool _validateBegin__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__line_smooth_enable();

		bool _begin__multisample_enable( void* attributeData ){return mImpl->begin__multisample_enable(*static_cast<multisample_enable__AttributeData*>(attributeData));}
		bool _data__multisample_enable( const ParserChar* text, size_t textLength );
		bool _end__multisample_enable(){return mImpl->end__multisample_enable();}
		bool _validateBegin__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__multisample_enable();

		bool _begin__normalize_enable( void* attributeData ){return mImpl->begin__normalize_enable(*static_cast<normalize_enable__AttributeData*>(attributeData));}
		bool _data__normalize_enable( const ParserChar* text, size_t textLength );
		bool _end__normalize_enable(){return mImpl->end__normalize_enable();}
		bool _validateBegin__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__normalize_enable();

		bool _begin__point_smooth_enable( void* attributeData ){return mImpl->begin__point_smooth_enable(*static_cast<point_smooth_enable__AttributeData*>(attributeData));}
		bool _data__point_smooth_enable( const ParserChar* text, size_t textLength );
		bool _end__point_smooth_enable(){return mImpl->end__point_smooth_enable();}
		bool _validateBegin__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point_smooth_enable();

		bool _begin__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__polygon_offset_fill_enable(*static_cast<polygon_offset_fill_enable__AttributeData*>(attributeData));}
		bool _data__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
		bool _end__polygon_offset_fill_enable(){return mImpl->end__polygon_offset_fill_enable();}
		bool _validateBegin__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygon_offset_fill_enable();

		bool _begin__rescale_normal_enable( void* attributeData ){return mImpl->begin__rescale_normal_enable(*static_cast<rescale_normal_enable__AttributeData*>(attributeData));}
		bool _data__rescale_normal_enable( const ParserChar* text, size_t textLength );
		bool _end__rescale_normal_enable(){return mImpl->end__rescale_normal_enable();}
		bool _validateBegin__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rescale_normal_enable();

		bool _begin__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__sample_alpha_to_coverage_enable(*static_cast<sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
		bool _data__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
		bool _end__sample_alpha_to_coverage_enable(){return mImpl->end__sample_alpha_to_coverage_enable();}
		bool _validateBegin__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_alpha_to_coverage_enable();

		bool _begin__sample_alpha_to_one_enable( void* attributeData ){return mImpl->begin__sample_alpha_to_one_enable(*static_cast<sample_alpha_to_one_enable__AttributeData*>(attributeData));}
		bool _data__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
		bool _end__sample_alpha_to_one_enable(){return mImpl->end__sample_alpha_to_one_enable();}
		bool _validateBegin__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_alpha_to_one_enable();

		bool _begin__sample_coverage_enable( void* attributeData ){return mImpl->begin__sample_coverage_enable(*static_cast<sample_coverage_enable__AttributeData*>(attributeData));}
		bool _data__sample_coverage_enable( const ParserChar* text, size_t textLength );
		bool _end__sample_coverage_enable(){return mImpl->end__sample_coverage_enable();}
		bool _validateBegin__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sample_coverage_enable();

		bool _begin__scissor_test_enable( void* attributeData ){return mImpl->begin__scissor_test_enable(*static_cast<scissor_test_enable__AttributeData*>(attributeData));}
		bool _data__scissor_test_enable( const ParserChar* text, size_t textLength );
		bool _end__scissor_test_enable(){return mImpl->end__scissor_test_enable();}
		bool _validateBegin__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scissor_test_enable();

		bool _begin__stencil_test_enable( void* attributeData ){return mImpl->begin__stencil_test_enable(*static_cast<stencil_test_enable__AttributeData*>(attributeData));}
		bool _data__stencil_test_enable( const ParserChar* text, size_t textLength );
		bool _end__stencil_test_enable(){return mImpl->end__stencil_test_enable();}
		bool _validateBegin__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__stencil_test_enable();

		bool _begin__pass__extra( void* attributeData ){return mImpl->begin__pass__extra(*static_cast<pass__extra__AttributeData*>(attributeData));}
		bool _data__pass__extra( const ParserChar* text, size_t textLength );
		bool _end__pass__extra(){return mImpl->end__pass__extra();}
		bool _validateBegin__pass__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__pass__extra();

		bool _begin__technique__extra( void* attributeData ){return mImpl->begin__technique__extra(*static_cast<technique__extra__AttributeData*>(attributeData));}
		bool _data__technique__extra( const ParserChar* text, size_t textLength );
		bool _end__technique__extra(){return mImpl->end__technique__extra();}
		bool _validateBegin__technique__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__extra();

		bool _begin__profile_GLES__extra( void* attributeData ){return mImpl->begin__profile_GLES__extra(*static_cast<profile_GLES__extra__AttributeData*>(attributeData));}
		bool _data__profile_GLES__extra( const ParserChar* text, size_t textLength );
		bool _end__profile_GLES__extra(){return mImpl->end__profile_GLES__extra();}
		bool _validateBegin__profile_GLES__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLES__extra();

		bool _begin__fx_profile_abstract( void* attributeData ){return mImpl->begin__fx_profile_abstract();}
		bool _data__fx_profile_abstract( const ParserChar* text, size_t textLength );
		bool _end__fx_profile_abstract(){return mImpl->end__fx_profile_abstract();}
		bool _validateBegin__fx_profile_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__fx_profile_abstract();

		bool _begin__mesh( void* attributeData ){return mImpl->begin__mesh();}
		bool _data__mesh( const ParserChar* text, size_t textLength );
		bool _end__mesh(){return mImpl->end__mesh();}
		bool _validateBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh();

		bool _begin__mesh__source( void* attributeData ){return mImpl->begin__mesh__source(*static_cast<mesh__source__AttributeData*>(attributeData));}
		bool _data__mesh__source( const ParserChar* text, size_t textLength );
		bool _end__mesh__source(){return mImpl->end__mesh__source();}
		bool _validateBegin__mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__source();

		bool _begin__mesh__vertices( void* attributeData ){return mImpl->begin__mesh__vertices(*static_cast<mesh__vertices__AttributeData*>(attributeData));}
		bool _data__mesh__vertices( const ParserChar* text, size_t textLength );
		bool _end__mesh__vertices(){return mImpl->end__mesh__vertices();}
		bool _validateBegin__mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__vertices();

		bool _begin__vertices__input( void* attributeData ){return mImpl->begin__vertices__input(*static_cast<vertices__input__AttributeData*>(attributeData));}
		bool _data__vertices__input( const ParserChar* text, size_t textLength );
		bool _end__vertices__input(){return mImpl->end__vertices__input();}
		bool _validateBegin__vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices__input();

		bool _begin__vertices__extra( void* attributeData ){return mImpl->begin__vertices__extra(*static_cast<vertices__extra__AttributeData*>(attributeData));}
		bool _data__vertices__extra( const ParserChar* text, size_t textLength );
		bool _end__vertices__extra(){return mImpl->end__vertices__extra();}
		bool _validateBegin__vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices__extra();

		bool _begin__mesh__lines( void* attributeData ){return mImpl->begin__mesh__lines(*static_cast<mesh__lines__AttributeData*>(attributeData));}
		bool _data__mesh__lines( const ParserChar* text, size_t textLength );
		bool _end__mesh__lines(){return mImpl->end__mesh__lines();}
		bool _validateBegin__mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__lines();

		bool _begin__lines__input( void* attributeData ){return mImpl->begin__lines__input(*static_cast<lines__input__AttributeData*>(attributeData));}
		bool _data__lines__input( const ParserChar* text, size_t textLength );
		bool _end__lines__input(){return mImpl->end__lines__input();}
		bool _validateBegin__lines__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__input();

		bool _begin__lines__p( void* attributeData ){return mImpl->begin__lines__p();}
		bool _data__lines__p( const ParserChar* text, size_t textLength );
		bool _end__lines__p(){return mImpl->end__lines__p();}
		bool _validateBegin__lines__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__p();

		bool _begin__lines__extra( void* attributeData ){return mImpl->begin__lines__extra(*static_cast<lines__extra__AttributeData*>(attributeData));}
		bool _data__lines__extra( const ParserChar* text, size_t textLength );
		bool _end__lines__extra(){return mImpl->end__lines__extra();}
		bool _validateBegin__lines__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines__extra();

		bool _begin__mesh__linestrips( void* attributeData ){return mImpl->begin__mesh__linestrips(*static_cast<mesh__linestrips__AttributeData*>(attributeData));}
		bool _data__mesh__linestrips( const ParserChar* text, size_t textLength );
		bool _end__mesh__linestrips(){return mImpl->end__mesh__linestrips();}
		bool _validateBegin__mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__linestrips();

		bool _begin__linestrips__input( void* attributeData ){return mImpl->begin__linestrips__input(*static_cast<linestrips__input__AttributeData*>(attributeData));}
		bool _data__linestrips__input( const ParserChar* text, size_t textLength );
		bool _end__linestrips__input(){return mImpl->end__linestrips__input();}
		bool _validateBegin__linestrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__input();

		bool _begin__linestrips__p( void* attributeData ){return mImpl->begin__linestrips__p();}
		bool _data__linestrips__p( const ParserChar* text, size_t textLength );
		bool _end__linestrips__p(){return mImpl->end__linestrips__p();}
		bool _validateBegin__linestrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__p();

		bool _begin__linestrips__extra( void* attributeData ){return mImpl->begin__linestrips__extra(*static_cast<linestrips__extra__AttributeData*>(attributeData));}
		bool _data__linestrips__extra( const ParserChar* text, size_t textLength );
		bool _end__linestrips__extra(){return mImpl->end__linestrips__extra();}
		bool _validateBegin__linestrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips__extra();

		bool _begin__mesh__polygons( void* attributeData ){return mImpl->begin__mesh__polygons(*static_cast<mesh__polygons__AttributeData*>(attributeData));}
		bool _data__mesh__polygons( const ParserChar* text, size_t textLength );
		bool _end__mesh__polygons(){return mImpl->end__mesh__polygons();}
		bool _validateBegin__mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__polygons();

		bool _begin__polygons__input( void* attributeData ){return mImpl->begin__polygons__input(*static_cast<polygons__input__AttributeData*>(attributeData));}
		bool _data__polygons__input( const ParserChar* text, size_t textLength );
		bool _end__polygons__input(){return mImpl->end__polygons__input();}
		bool _validateBegin__polygons__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__input();

		bool _begin__polygons__p( void* attributeData ){return mImpl->begin__polygons__p();}
		bool _data__polygons__p( const ParserChar* text, size_t textLength );
		bool _end__polygons__p(){return mImpl->end__polygons__p();}
		bool _validateBegin__polygons__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__p();

		bool _begin__ph( void* attributeData ){return mImpl->begin__ph();}
		bool _data__ph( const ParserChar* text, size_t textLength );
		bool _end__ph(){return mImpl->end__ph();}
		bool _validateBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ph();

		bool _begin__ph__p( void* attributeData ){return mImpl->begin__ph__p();}
		bool _data__ph__p( const ParserChar* text, size_t textLength );
		bool _end__ph__p(){return mImpl->end__ph__p();}
		bool _validateBegin__ph__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ph__p();

		bool _begin__h( void* attributeData ){return mImpl->begin__h();}
		bool _data__h( const ParserChar* text, size_t textLength );
		bool _end__h(){return mImpl->end__h();}
		bool _validateBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__h();

		bool _begin__polygons__extra( void* attributeData ){return mImpl->begin__polygons__extra(*static_cast<polygons__extra__AttributeData*>(attributeData));}
		bool _data__polygons__extra( const ParserChar* text, size_t textLength );
		bool _end__polygons__extra(){return mImpl->end__polygons__extra();}
		bool _validateBegin__polygons__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons__extra();

		bool _begin__mesh__polylist( void* attributeData ){return mImpl->begin__mesh__polylist(*static_cast<mesh__polylist__AttributeData*>(attributeData));}
		bool _data__mesh__polylist( const ParserChar* text, size_t textLength );
		bool _end__mesh__polylist(){return mImpl->end__mesh__polylist();}
		bool _validateBegin__mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__polylist();

		bool _begin__polylist__input( void* attributeData ){return mImpl->begin__polylist__input(*static_cast<polylist__input__AttributeData*>(attributeData));}
		bool _data__polylist__input( const ParserChar* text, size_t textLength );
		bool _end__polylist__input(){return mImpl->end__polylist__input();}
		bool _validateBegin__polylist__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__input();

		bool _begin__polylist__vcount( void* attributeData ){return mImpl->begin__polylist__vcount();}
		bool _data__polylist__vcount( const ParserChar* text, size_t textLength );
		bool _end__polylist__vcount(){return mImpl->end__polylist__vcount();}
		bool _validateBegin__polylist__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__vcount();

		bool _begin__polylist__p( void* attributeData ){return mImpl->begin__polylist__p();}
		bool _data__polylist__p( const ParserChar* text, size_t textLength );
		bool _end__polylist__p(){return mImpl->end__polylist__p();}
		bool _validateBegin__polylist__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__p();

		bool _begin__polylist__extra( void* attributeData ){return mImpl->begin__polylist__extra(*static_cast<polylist__extra__AttributeData*>(attributeData));}
		bool _data__polylist__extra( const ParserChar* text, size_t textLength );
		bool _end__polylist__extra(){return mImpl->end__polylist__extra();}
		bool _validateBegin__polylist__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist__extra();

		bool _begin__mesh__triangles( void* attributeData ){return mImpl->begin__mesh__triangles(*static_cast<mesh__triangles__AttributeData*>(attributeData));}
		bool _data__mesh__triangles( const ParserChar* text, size_t textLength );
		bool _end__mesh__triangles(){return mImpl->end__mesh__triangles();}
		bool _validateBegin__mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__triangles();

		bool _begin__triangles__input( void* attributeData ){return mImpl->begin__triangles__input(*static_cast<triangles__input__AttributeData*>(attributeData));}
		bool _data__triangles__input( const ParserChar* text, size_t textLength );
		bool _end__triangles__input(){return mImpl->end__triangles__input();}
		bool _validateBegin__triangles__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__input();

		bool _begin__triangles__p( void* attributeData ){return mImpl->begin__triangles__p();}
		bool _data__triangles__p( const ParserChar* text, size_t textLength );
		bool _end__triangles__p(){return mImpl->end__triangles__p();}
		bool _validateBegin__triangles__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__p();

		bool _begin__triangles__extra( void* attributeData ){return mImpl->begin__triangles__extra(*static_cast<triangles__extra__AttributeData*>(attributeData));}
		bool _data__triangles__extra( const ParserChar* text, size_t textLength );
		bool _end__triangles__extra(){return mImpl->end__triangles__extra();}
		bool _validateBegin__triangles__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles__extra();

		bool _begin__mesh__trifans( void* attributeData ){return mImpl->begin__mesh__trifans(*static_cast<mesh__trifans__AttributeData*>(attributeData));}
		bool _data__mesh__trifans( const ParserChar* text, size_t textLength );
		bool _end__mesh__trifans(){return mImpl->end__mesh__trifans();}
		bool _validateBegin__mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__trifans();

		bool _begin__mesh__tristrips( void* attributeData ){return mImpl->begin__mesh__tristrips(*static_cast<mesh__tristrips__AttributeData*>(attributeData));}
		bool _data__mesh__tristrips( const ParserChar* text, size_t textLength );
		bool _end__mesh__tristrips(){return mImpl->end__mesh__tristrips();}
		bool _validateBegin__mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__tristrips();

		bool _begin__tristrips__input( void* attributeData ){return mImpl->begin__tristrips__input(*static_cast<tristrips__input__AttributeData*>(attributeData));}
		bool _data__tristrips__input( const ParserChar* text, size_t textLength );
		bool _end__tristrips__input(){return mImpl->end__tristrips__input();}
		bool _validateBegin__tristrips__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__input();

		bool _begin__tristrips__p( void* attributeData ){return mImpl->begin__tristrips__p();}
		bool _data__tristrips__p( const ParserChar* text, size_t textLength );
		bool _end__tristrips__p(){return mImpl->end__tristrips__p();}
		bool _validateBegin__tristrips__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__p();

		bool _begin__tristrips__extra( void* attributeData ){return mImpl->begin__tristrips__extra(*static_cast<tristrips__extra__AttributeData*>(attributeData));}
		bool _data__tristrips__extra( const ParserChar* text, size_t textLength );
		bool _end__tristrips__extra(){return mImpl->end__tristrips__extra();}
		bool _validateBegin__tristrips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips__extra();

		bool _begin__mesh__extra( void* attributeData ){return mImpl->begin__mesh__extra(*static_cast<mesh__extra__AttributeData*>(attributeData));}
		bool _data__mesh__extra( const ParserChar* text, size_t textLength );
		bool _end__mesh__extra(){return mImpl->end__mesh__extra();}
		bool _validateBegin__mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mesh__extra();

		bool _begin__lines( void* attributeData ){return mImpl->begin__lines(*static_cast<lines__AttributeData*>(attributeData));}
		bool _data__lines( const ParserChar* text, size_t textLength );
		bool _end__lines(){return mImpl->end__lines();}
		bool _validateBegin__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lines();

		bool _begin__instance_node( void* attributeData ){return mImpl->begin__instance_node(*static_cast<instance_node__AttributeData*>(attributeData));}
		bool _data__instance_node( const ParserChar* text, size_t textLength );
		bool _end__instance_node(){return mImpl->end__instance_node();}
		bool _validateBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_node();

		bool _begin__instance_node__extra( void* attributeData ){return mImpl->begin__instance_node__extra(*static_cast<instance_node__extra__AttributeData*>(attributeData));}
		bool _data__instance_node__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_node__extra(){return mImpl->end__instance_node__extra();}
		bool _validateBegin__instance_node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_node__extra();

		bool _begin__visual_scene( void* attributeData ){return mImpl->begin__visual_scene(*static_cast<visual_scene__AttributeData*>(attributeData));}
		bool _data__visual_scene( const ParserChar* text, size_t textLength );
		bool _end__visual_scene(){return mImpl->end__visual_scene();}
		bool _validateBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene();

		bool _begin__visual_scene__asset( void* attributeData ){return mImpl->begin__visual_scene__asset();}
		bool _data__visual_scene__asset( const ParserChar* text, size_t textLength );
		bool _end__visual_scene__asset(){return mImpl->end__visual_scene__asset();}
		bool _validateBegin__visual_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__asset();

		bool _begin__visual_scene__node( void* attributeData ){return mImpl->begin__visual_scene__node(*static_cast<visual_scene__node__AttributeData*>(attributeData));}
		bool _data__visual_scene__node( const ParserChar* text, size_t textLength );
		bool _end__visual_scene__node(){return mImpl->end__visual_scene__node();}
		bool _validateBegin__visual_scene__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__node();

		bool _begin__node__asset( void* attributeData ){return mImpl->begin__node__asset();}
		bool _data__node__asset( const ParserChar* text, size_t textLength );
		bool _end__node__asset(){return mImpl->end__node__asset();}
		bool _validateBegin__node__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__asset();

		bool _begin__lookat( void* attributeData ){return mImpl->begin__lookat(*static_cast<lookat__AttributeData*>(attributeData));}
		bool _data__lookat( const ParserChar* text, size_t textLength );
		bool _end__lookat(){return mImpl->end__lookat();}
		bool _validateBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lookat();

		bool _begin__matrix( void* attributeData ){return mImpl->begin__matrix(*static_cast<matrix__AttributeData*>(attributeData));}
		bool _data__matrix( const ParserChar* text, size_t textLength );
		bool _end__matrix(){return mImpl->end__matrix();}
		bool _validateBegin__matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__matrix();

		bool _begin__node__rotate( void* attributeData ){return mImpl->begin__node__rotate(*static_cast<node__rotate__AttributeData*>(attributeData));}
		bool _data__node__rotate( const ParserChar* text, size_t textLength );
		bool _end__node__rotate(){return mImpl->end__node__rotate();}
		bool _validateBegin__node__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__rotate();

		bool _begin__scale( void* attributeData ){return mImpl->begin__scale(*static_cast<scale__AttributeData*>(attributeData));}
		bool _data__scale( const ParserChar* text, size_t textLength );
		bool _end__scale(){return mImpl->end__scale();}
		bool _validateBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scale();

		bool _begin__skew( void* attributeData ){return mImpl->begin__skew(*static_cast<skew__AttributeData*>(attributeData));}
		bool _data__skew( const ParserChar* text, size_t textLength );
		bool _end__skew(){return mImpl->end__skew();}
		bool _validateBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skew();

		bool _begin__node__translate( void* attributeData ){return mImpl->begin__node__translate(*static_cast<node__translate__AttributeData*>(attributeData));}
		bool _data__node__translate( const ParserChar* text, size_t textLength );
		bool _end__node__translate(){return mImpl->end__node__translate();}
		bool _validateBegin__node__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__translate();

		bool _begin__instance_camera( void* attributeData ){return mImpl->begin__instance_camera(*static_cast<instance_camera__AttributeData*>(attributeData));}
		bool _data__instance_camera( const ParserChar* text, size_t textLength );
		bool _end__instance_camera(){return mImpl->end__instance_camera();}
		bool _validateBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_camera();

		bool _begin__instance_camera__extra( void* attributeData ){return mImpl->begin__instance_camera__extra(*static_cast<instance_camera__extra__AttributeData*>(attributeData));}
		bool _data__instance_camera__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_camera__extra(){return mImpl->end__instance_camera__extra();}
		bool _validateBegin__instance_camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_camera__extra();

		bool _begin__instance_controller( void* attributeData ){return mImpl->begin__instance_controller(*static_cast<instance_controller__AttributeData*>(attributeData));}
		bool _data__instance_controller( const ParserChar* text, size_t textLength );
		bool _end__instance_controller(){return mImpl->end__instance_controller();}
		bool _validateBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller();

		bool _begin__skeleton( void* attributeData ){return mImpl->begin__skeleton();}
		bool _data__skeleton( const ParserChar* text, size_t textLength );
		bool _end__skeleton(){return mImpl->end__skeleton();}
		bool _validateBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skeleton();

		bool _begin__instance_controller__bind_material( void* attributeData ){return mImpl->begin__instance_controller__bind_material();}
		bool _data__instance_controller__bind_material( const ParserChar* text, size_t textLength );
		bool _end__instance_controller__bind_material(){return mImpl->end__instance_controller__bind_material();}
		bool _validateBegin__instance_controller__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller__bind_material();

		bool _begin__bind_material__param( void* attributeData ){return mImpl->begin__bind_material__param(*static_cast<bind_material__param__AttributeData*>(attributeData));}
		bool _data__bind_material__param( const ParserChar* text, size_t textLength );
		bool _end__bind_material__param(){return mImpl->end__bind_material__param();}
		bool _validateBegin__bind_material__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__param();

		bool _begin__bind_material__technique_common( void* attributeData ){return mImpl->begin__bind_material__technique_common();}
		bool _data__bind_material__technique_common( const ParserChar* text, size_t textLength );
		bool _end__bind_material__technique_common(){return mImpl->end__bind_material__technique_common();}
		bool _validateBegin__bind_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__technique_common();

		bool _begin__instance_material( void* attributeData ){return mImpl->begin__instance_material(*static_cast<instance_material__AttributeData*>(attributeData));}
		bool _data__instance_material( const ParserChar* text, size_t textLength );
		bool _end__instance_material(){return mImpl->end__instance_material();}
		bool _validateBegin__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material();

		bool _begin__instance_material__bind( void* attributeData ){return mImpl->begin__instance_material__bind(*static_cast<instance_material__bind__AttributeData*>(attributeData));}
		bool _data__instance_material__bind( const ParserChar* text, size_t textLength );
		bool _end__instance_material__bind(){return mImpl->end__instance_material__bind();}
		bool _validateBegin__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material__bind();

		bool _begin__bind_vertex_input( void* attributeData ){return mImpl->begin__bind_vertex_input(*static_cast<bind_vertex_input__AttributeData*>(attributeData));}
		bool _data__bind_vertex_input( const ParserChar* text, size_t textLength );
		bool _end__bind_vertex_input(){return mImpl->end__bind_vertex_input();}
		bool _validateBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_vertex_input();

		bool _begin__instance_material__extra( void* attributeData ){return mImpl->begin__instance_material__extra(*static_cast<instance_material__extra__AttributeData*>(attributeData));}
		bool _data__instance_material__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_material__extra(){return mImpl->end__instance_material__extra();}
		bool _validateBegin__instance_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_material__extra();

		bool _begin__bind_material__technique( void* attributeData ){return mImpl->begin__bind_material__technique(*static_cast<bind_material__technique__AttributeData*>(attributeData));}
		bool _data__bind_material__technique( const ParserChar* text, size_t textLength );
		bool _end__bind_material__technique(){return mImpl->end__bind_material__technique();}
		bool _validateBegin__bind_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__technique();

		bool _begin__bind_material__extra( void* attributeData ){return mImpl->begin__bind_material__extra(*static_cast<bind_material__extra__AttributeData*>(attributeData));}
		bool _data__bind_material__extra( const ParserChar* text, size_t textLength );
		bool _end__bind_material__extra(){return mImpl->end__bind_material__extra();}
		bool _validateBegin__bind_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material__extra();

		bool _begin__instance_controller__extra( void* attributeData ){return mImpl->begin__instance_controller__extra(*static_cast<instance_controller__extra__AttributeData*>(attributeData));}
		bool _data__instance_controller__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_controller__extra(){return mImpl->end__instance_controller__extra();}
		bool _validateBegin__instance_controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_controller__extra();

		bool _begin__node__instance_geometry( void* attributeData ){return mImpl->begin__node__instance_geometry(*static_cast<node__instance_geometry__AttributeData*>(attributeData));}
		bool _data__node__instance_geometry( const ParserChar* text, size_t textLength );
		bool _end__node__instance_geometry(){return mImpl->end__node__instance_geometry();}
		bool _validateBegin__node__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__instance_geometry();

		bool _begin__instance_geometry__bind_material( void* attributeData ){return mImpl->begin__instance_geometry__bind_material();}
		bool _data__instance_geometry__bind_material( const ParserChar* text, size_t textLength );
		bool _end__instance_geometry__bind_material(){return mImpl->end__instance_geometry__bind_material();}
		bool _validateBegin__instance_geometry__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry__bind_material();

		bool _begin__instance_geometry__extra( void* attributeData ){return mImpl->begin__instance_geometry__extra(*static_cast<instance_geometry__extra__AttributeData*>(attributeData));}
		bool _data__instance_geometry__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_geometry__extra(){return mImpl->end__instance_geometry__extra();}
		bool _validateBegin__instance_geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry__extra();

		bool _begin__instance_light( void* attributeData ){return mImpl->begin__instance_light(*static_cast<instance_light__AttributeData*>(attributeData));}
		bool _data__instance_light( const ParserChar* text, size_t textLength );
		bool _end__instance_light(){return mImpl->end__instance_light();}
		bool _validateBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_light();

		bool _begin__instance_light__extra( void* attributeData ){return mImpl->begin__instance_light__extra(*static_cast<instance_light__extra__AttributeData*>(attributeData));}
		bool _data__instance_light__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_light__extra(){return mImpl->end__instance_light__extra();}
		bool _validateBegin__instance_light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_light__extra();

		bool _begin__node__extra( void* attributeData ){return mImpl->begin__node__extra(*static_cast<node__extra__AttributeData*>(attributeData));}
		bool _data__node__extra( const ParserChar* text, size_t textLength );
		bool _end__node__extra(){return mImpl->end__node__extra();}
		bool _validateBegin__node__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node__extra();

		bool _begin__evaluate_scene( void* attributeData ){return mImpl->begin__evaluate_scene(*static_cast<evaluate_scene__AttributeData*>(attributeData));}
		bool _data__evaluate_scene( const ParserChar* text, size_t textLength );
		bool _end__evaluate_scene(){return mImpl->end__evaluate_scene();}
		bool _validateBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__evaluate_scene();

		bool _begin__render( void* attributeData ){return mImpl->begin__render(*static_cast<render__AttributeData*>(attributeData));}
		bool _data__render( const ParserChar* text, size_t textLength );
		bool _end__render(){return mImpl->end__render();}
		bool _validateBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__render();

		bool _begin__layer( void* attributeData ){return mImpl->begin__layer();}
		bool _data__layer( const ParserChar* text, size_t textLength );
		bool _end__layer(){return mImpl->end__layer();}
		bool _validateBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__layer();

		bool _begin__render__instance_effect( void* attributeData ){return mImpl->begin__render__instance_effect(*static_cast<render__instance_effect__AttributeData*>(attributeData));}
		bool _data__render__instance_effect( const ParserChar* text, size_t textLength );
		bool _end__render__instance_effect(){return mImpl->end__render__instance_effect();}
		bool _validateBegin__render__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__render__instance_effect();

		bool _begin__visual_scene__extra( void* attributeData ){return mImpl->begin__visual_scene__extra(*static_cast<visual_scene__extra__AttributeData*>(attributeData));}
		bool _data__visual_scene__extra( const ParserChar* text, size_t textLength );
		bool _end__visual_scene__extra(){return mImpl->end__visual_scene__extra();}
		bool _validateBegin__visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__visual_scene__extra();

		bool _begin__material( void* attributeData ){return mImpl->begin__material(*static_cast<material__AttributeData*>(attributeData));}
		bool _data__material( const ParserChar* text, size_t textLength );
		bool _end__material(){return mImpl->end__material();}
		bool _validateBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material();

		bool _begin__material__asset( void* attributeData ){return mImpl->begin__material__asset();}
		bool _data__material__asset( const ParserChar* text, size_t textLength );
		bool _end__material__asset(){return mImpl->end__material__asset();}
		bool _validateBegin__material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__asset();

		bool _begin__material__instance_effect( void* attributeData ){return mImpl->begin__material__instance_effect(*static_cast<material__instance_effect__AttributeData*>(attributeData));}
		bool _data__material__instance_effect( const ParserChar* text, size_t textLength );
		bool _end__material__instance_effect(){return mImpl->end__material__instance_effect();}
		bool _validateBegin__material__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__instance_effect();

		bool _begin__material__extra( void* attributeData ){return mImpl->begin__material__extra(*static_cast<material__extra__AttributeData*>(attributeData));}
		bool _data__material__extra( const ParserChar* text, size_t textLength );
		bool _end__material__extra(){return mImpl->end__material__extra();}
		bool _validateBegin__material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__material__extra();

		bool _begin__capsule( void* attributeData ){return mImpl->begin__capsule();}
		bool _data__capsule( const ParserChar* text, size_t textLength );
		bool _end__capsule(){return mImpl->end__capsule();}
		bool _validateBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule();

		bool _begin__capsule__height( void* attributeData ){return mImpl->begin__capsule__height();}
		bool _data__capsule__height( const ParserChar* text, size_t textLength );
		bool _end__capsule__height(){return mImpl->end__capsule__height();}
		bool _validateBegin__capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__height();

		bool _begin__capsule__radius( void* attributeData ){return mImpl->begin__capsule__radius();}
		bool _data__capsule__radius( const ParserChar* text, size_t textLength );
		bool _end__capsule__radius(){return mImpl->end__capsule__radius();}
		bool _validateBegin__capsule__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__radius();

		bool _begin__capsule__extra( void* attributeData ){return mImpl->begin__capsule__extra(*static_cast<capsule__extra__AttributeData*>(attributeData));}
		bool _data__capsule__extra( const ParserChar* text, size_t textLength );
		bool _end__capsule__extra(){return mImpl->end__capsule__extra();}
		bool _validateBegin__capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__capsule__extra();

		bool _begin__p( void* attributeData ){return mImpl->begin__p();}
		bool _data__p( const ParserChar* text, size_t textLength );
		bool _end__p(){return mImpl->end__p();}
		bool _validateBegin__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__p();

		bool _begin__ellipsoid( void* attributeData ){return mImpl->begin__ellipsoid();}
		bool _data__ellipsoid( const ParserChar* text, size_t textLength );
		bool _end__ellipsoid(){return mImpl->end__ellipsoid();}
		bool _validateBegin__ellipsoid( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ellipsoid();

		bool _begin__ellipsoid__size( void* attributeData ){return mImpl->begin__ellipsoid__size();}
		bool _data__ellipsoid__size( const ParserChar* text, size_t textLength );
		bool _end__ellipsoid__size(){return mImpl->end__ellipsoid__size();}
		bool _validateBegin__ellipsoid__size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ellipsoid__size();

		bool _begin__library_physics_scenes( void* attributeData ){return mImpl->begin__library_physics_scenes(*static_cast<library_physics_scenes__AttributeData*>(attributeData));}
		bool _data__library_physics_scenes( const ParserChar* text, size_t textLength );
		bool _end__library_physics_scenes(){return mImpl->end__library_physics_scenes();}
		bool _validateBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes();

		bool _begin__library_physics_scenes__asset( void* attributeData ){return mImpl->begin__library_physics_scenes__asset();}
		bool _data__library_physics_scenes__asset( const ParserChar* text, size_t textLength );
		bool _end__library_physics_scenes__asset(){return mImpl->end__library_physics_scenes__asset();}
		bool _validateBegin__library_physics_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes__asset();

		bool _begin__physics_scene( void* attributeData ){return mImpl->begin__physics_scene(*static_cast<physics_scene__AttributeData*>(attributeData));}
		bool _data__physics_scene( const ParserChar* text, size_t textLength );
		bool _end__physics_scene(){return mImpl->end__physics_scene();}
		bool _validateBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene();

		bool _begin__physics_scene__asset( void* attributeData ){return mImpl->begin__physics_scene__asset();}
		bool _data__physics_scene__asset( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__asset(){return mImpl->end__physics_scene__asset();}
		bool _validateBegin__physics_scene__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__asset();

		bool _begin__physics_scene__instance_force_field( void* attributeData ){return mImpl->begin__physics_scene__instance_force_field(*static_cast<physics_scene__instance_force_field__AttributeData*>(attributeData));}
		bool _data__physics_scene__instance_force_field( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__instance_force_field(){return mImpl->end__physics_scene__instance_force_field();}
		bool _validateBegin__physics_scene__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__instance_force_field();

		bool _begin__instance_force_field__extra( void* attributeData ){return mImpl->begin__instance_force_field__extra(*static_cast<instance_force_field__extra__AttributeData*>(attributeData));}
		bool _data__instance_force_field__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_force_field__extra(){return mImpl->end__instance_force_field__extra();}
		bool _validateBegin__instance_force_field__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_force_field__extra();

		bool _begin__physics_scene__instance_physics_model( void* attributeData ){return mImpl->begin__physics_scene__instance_physics_model(*static_cast<physics_scene__instance_physics_model__AttributeData*>(attributeData));}
		bool _data__physics_scene__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__instance_physics_model(){return mImpl->end__physics_scene__instance_physics_model();}
		bool _validateBegin__physics_scene__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__instance_physics_model();

		bool _begin__instance_physics_model__instance_force_field( void* attributeData ){return mImpl->begin__instance_physics_model__instance_force_field(*static_cast<instance_physics_model__instance_force_field__AttributeData*>(attributeData));}
		bool _data__instance_physics_model__instance_force_field( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_model__instance_force_field(){return mImpl->end__instance_physics_model__instance_force_field();}
		bool _validateBegin__instance_physics_model__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model__instance_force_field();

		bool _begin__instance_rigid_body( void* attributeData ){return mImpl->begin__instance_rigid_body(*static_cast<instance_rigid_body__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_body(){return mImpl->end__instance_rigid_body();}
		bool _validateBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body();

		bool _begin__instance_rigid_body__technique_common( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common();}
		bool _data__instance_rigid_body__technique_common( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_body__technique_common(){return mImpl->end__instance_rigid_body__technique_common();}
		bool _validateBegin__instance_rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__technique_common();

		bool _begin__angular_velocity( void* attributeData ){return mImpl->begin__angular_velocity();}
		bool _data__angular_velocity( const ParserChar* text, size_t textLength );
		bool _end__angular_velocity(){return mImpl->end__angular_velocity();}
		bool _validateBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular_velocity();

		bool _begin__velocity( void* attributeData ){return mImpl->begin__velocity();}
		bool _data__velocity( const ParserChar* text, size_t textLength );
		bool _end__velocity(){return mImpl->end__velocity();}
		bool _validateBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__velocity();

		bool _begin__dynamic( void* attributeData ){return mImpl->begin__dynamic(*static_cast<dynamic__AttributeData*>(attributeData));}
		bool _data__dynamic( const ParserChar* text, size_t textLength );
		bool _end__dynamic(){return mImpl->end__dynamic();}
		bool _validateBegin__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dynamic();

		bool _begin__technique_common__mass( void* attributeData ){return mImpl->begin__technique_common__mass(*static_cast<technique_common__mass__AttributeData*>(attributeData));}
		bool _data__technique_common__mass( const ParserChar* text, size_t textLength );
		bool _end__technique_common__mass(){return mImpl->end__technique_common__mass();}
		bool _validateBegin__technique_common__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__mass();

		bool _begin__mass_frame( void* attributeData ){return mImpl->begin__mass_frame();}
		bool _data__mass_frame( const ParserChar* text, size_t textLength );
		bool _end__mass_frame(){return mImpl->end__mass_frame();}
		bool _validateBegin__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame();

		bool _begin__mass_frame__translate( void* attributeData ){return mImpl->begin__mass_frame__translate(*static_cast<mass_frame__translate__AttributeData*>(attributeData));}
		bool _data__mass_frame__translate( const ParserChar* text, size_t textLength );
		bool _end__mass_frame__translate(){return mImpl->end__mass_frame__translate();}
		bool _validateBegin__mass_frame__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame__translate();

		bool _begin__mass_frame__rotate( void* attributeData ){return mImpl->begin__mass_frame__rotate(*static_cast<mass_frame__rotate__AttributeData*>(attributeData));}
		bool _data__mass_frame__rotate( const ParserChar* text, size_t textLength );
		bool _end__mass_frame__rotate(){return mImpl->end__mass_frame__rotate();}
		bool _validateBegin__mass_frame__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__mass_frame__rotate();

		bool _begin__inertia( void* attributeData ){return mImpl->begin__inertia(*static_cast<inertia__AttributeData*>(attributeData));}
		bool _data__inertia( const ParserChar* text, size_t textLength );
		bool _end__inertia(){return mImpl->end__inertia();}
		bool _validateBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__inertia();

		bool _begin__technique_common__instance_physics_material( void* attributeData ){return mImpl->begin__technique_common__instance_physics_material(*static_cast<technique_common__instance_physics_material__AttributeData*>(attributeData));}
		bool _data__technique_common__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _end__technique_common__instance_physics_material(){return mImpl->end__technique_common__instance_physics_material();}
		bool _validateBegin__technique_common__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__instance_physics_material();

		bool _begin__instance_physics_material__extra( void* attributeData ){return mImpl->begin__instance_physics_material__extra(*static_cast<instance_physics_material__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_material__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_material__extra(){return mImpl->end__instance_physics_material__extra();}
		bool _validateBegin__instance_physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_material__extra();

		bool _begin__technique_common__physics_material( void* attributeData ){return mImpl->begin__technique_common__physics_material(*static_cast<technique_common__physics_material__AttributeData*>(attributeData));}
		bool _data__technique_common__physics_material( const ParserChar* text, size_t textLength );
		bool _end__technique_common__physics_material(){return mImpl->end__technique_common__physics_material();}
		bool _validateBegin__technique_common__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__physics_material();

		bool _begin__physics_material__asset( void* attributeData ){return mImpl->begin__physics_material__asset();}
		bool _data__physics_material__asset( const ParserChar* text, size_t textLength );
		bool _end__physics_material__asset(){return mImpl->end__physics_material__asset();}
		bool _validateBegin__physics_material__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__asset();

		bool _begin__physics_material__technique_common( void* attributeData ){return mImpl->begin__physics_material__technique_common();}
		bool _data__physics_material__technique_common( const ParserChar* text, size_t textLength );
		bool _end__physics_material__technique_common(){return mImpl->end__physics_material__technique_common();}
		bool _validateBegin__physics_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__technique_common();

		bool _begin__dynamic_friction( void* attributeData ){return mImpl->begin__dynamic_friction(*static_cast<dynamic_friction__AttributeData*>(attributeData));}
		bool _data__dynamic_friction( const ParserChar* text, size_t textLength );
		bool _end__dynamic_friction(){return mImpl->end__dynamic_friction();}
		bool _validateBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__dynamic_friction();

		bool _begin__restitution( void* attributeData ){return mImpl->begin__restitution(*static_cast<restitution__AttributeData*>(attributeData));}
		bool _data__restitution( const ParserChar* text, size_t textLength );
		bool _end__restitution(){return mImpl->end__restitution();}
		bool _validateBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__restitution();

		bool _begin__static_friction( void* attributeData ){return mImpl->begin__static_friction(*static_cast<static_friction__AttributeData*>(attributeData));}
		bool _data__static_friction( const ParserChar* text, size_t textLength );
		bool _end__static_friction(){return mImpl->end__static_friction();}
		bool _validateBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__static_friction();

		bool _begin__physics_material__technique( void* attributeData ){return mImpl->begin__physics_material__technique(*static_cast<physics_material__technique__AttributeData*>(attributeData));}
		bool _data__physics_material__technique( const ParserChar* text, size_t textLength );
		bool _end__physics_material__technique(){return mImpl->end__physics_material__technique();}
		bool _validateBegin__physics_material__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__technique();

		bool _begin__physics_material__extra( void* attributeData ){return mImpl->begin__physics_material__extra(*static_cast<physics_material__extra__AttributeData*>(attributeData));}
		bool _data__physics_material__extra( const ParserChar* text, size_t textLength );
		bool _end__physics_material__extra(){return mImpl->end__physics_material__extra();}
		bool _validateBegin__physics_material__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material__extra();

		bool _begin__shape( void* attributeData ){return mImpl->begin__shape();}
		bool _data__shape( const ParserChar* text, size_t textLength );
		bool _end__shape(){return mImpl->end__shape();}
		bool _validateBegin__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape();

		bool _begin__hollow( void* attributeData ){return mImpl->begin__hollow(*static_cast<hollow__AttributeData*>(attributeData));}
		bool _data__hollow( const ParserChar* text, size_t textLength );
		bool _end__hollow(){return mImpl->end__hollow();}
		bool _validateBegin__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__hollow();

		bool _begin__shape__mass( void* attributeData ){return mImpl->begin__shape__mass(*static_cast<shape__mass__AttributeData*>(attributeData));}
		bool _data__shape__mass( const ParserChar* text, size_t textLength );
		bool _end__shape__mass(){return mImpl->end__shape__mass();}
		bool _validateBegin__shape__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__mass();

		bool _begin__density( void* attributeData ){return mImpl->begin__density(*static_cast<density__AttributeData*>(attributeData));}
		bool _data__density( const ParserChar* text, size_t textLength );
		bool _end__density(){return mImpl->end__density();}
		bool _validateBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__density();

		bool _begin__shape__instance_physics_material( void* attributeData ){return mImpl->begin__shape__instance_physics_material(*static_cast<shape__instance_physics_material__AttributeData*>(attributeData));}
		bool _data__shape__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _end__shape__instance_physics_material(){return mImpl->end__shape__instance_physics_material();}
		bool _validateBegin__shape__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__instance_physics_material();

		bool _begin__shape__physics_material( void* attributeData ){return mImpl->begin__shape__physics_material(*static_cast<shape__physics_material__AttributeData*>(attributeData));}
		bool _data__shape__physics_material( const ParserChar* text, size_t textLength );
		bool _end__shape__physics_material(){return mImpl->end__shape__physics_material();}
		bool _validateBegin__shape__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__physics_material();

		bool _begin__shape__instance_geometry( void* attributeData ){return mImpl->begin__shape__instance_geometry(*static_cast<shape__instance_geometry__AttributeData*>(attributeData));}
		bool _data__shape__instance_geometry( const ParserChar* text, size_t textLength );
		bool _end__shape__instance_geometry(){return mImpl->end__shape__instance_geometry();}
		bool _validateBegin__shape__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__instance_geometry();

		bool _begin__plane( void* attributeData ){return mImpl->begin__plane();}
		bool _data__plane( const ParserChar* text, size_t textLength );
		bool _end__plane(){return mImpl->end__plane();}
		bool _validateBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__plane();

		bool _begin__equation( void* attributeData ){return mImpl->begin__equation();}
		bool _data__equation( const ParserChar* text, size_t textLength );
		bool _end__equation(){return mImpl->end__equation();}
		bool _validateBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__equation();

		bool _begin__plane__extra( void* attributeData ){return mImpl->begin__plane__extra(*static_cast<plane__extra__AttributeData*>(attributeData));}
		bool _data__plane__extra( const ParserChar* text, size_t textLength );
		bool _end__plane__extra(){return mImpl->end__plane__extra();}
		bool _validateBegin__plane__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__plane__extra();

		bool _begin__box( void* attributeData ){return mImpl->begin__box();}
		bool _data__box( const ParserChar* text, size_t textLength );
		bool _end__box(){return mImpl->end__box();}
		bool _validateBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__box();

		bool _begin__half_extents( void* attributeData ){return mImpl->begin__half_extents();}
		bool _data__half_extents( const ParserChar* text, size_t textLength );
		bool _end__half_extents(){return mImpl->end__half_extents();}
		bool _validateBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__half_extents();

		bool _begin__box__extra( void* attributeData ){return mImpl->begin__box__extra(*static_cast<box__extra__AttributeData*>(attributeData));}
		bool _data__box__extra( const ParserChar* text, size_t textLength );
		bool _end__box__extra(){return mImpl->end__box__extra();}
		bool _validateBegin__box__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__box__extra();

		bool _begin__sphere( void* attributeData ){return mImpl->begin__sphere();}
		bool _data__sphere( const ParserChar* text, size_t textLength );
		bool _end__sphere(){return mImpl->end__sphere();}
		bool _validateBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere();

		bool _begin__sphere__radius( void* attributeData ){return mImpl->begin__sphere__radius();}
		bool _data__sphere__radius( const ParserChar* text, size_t textLength );
		bool _end__sphere__radius(){return mImpl->end__sphere__radius();}
		bool _validateBegin__sphere__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere__radius();

		bool _begin__sphere__extra( void* attributeData ){return mImpl->begin__sphere__extra(*static_cast<sphere__extra__AttributeData*>(attributeData));}
		bool _data__sphere__extra( const ParserChar* text, size_t textLength );
		bool _end__sphere__extra(){return mImpl->end__sphere__extra();}
		bool _validateBegin__sphere__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__sphere__extra();

		bool _begin__cylinder( void* attributeData ){return mImpl->begin__cylinder();}
		bool _data__cylinder( const ParserChar* text, size_t textLength );
		bool _end__cylinder(){return mImpl->end__cylinder();}
		bool _validateBegin__cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder();

		bool _begin__cylinder__height( void* attributeData ){return mImpl->begin__cylinder__height();}
		bool _data__cylinder__height( const ParserChar* text, size_t textLength );
		bool _end__cylinder__height(){return mImpl->end__cylinder__height();}
		bool _validateBegin__cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__height();

		bool _begin__cylinder__radius( void* attributeData ){return mImpl->begin__cylinder__radius();}
		bool _data__cylinder__radius( const ParserChar* text, size_t textLength );
		bool _end__cylinder__radius(){return mImpl->end__cylinder__radius();}
		bool _validateBegin__cylinder__radius( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__radius();

		bool _begin__cylinder__extra( void* attributeData ){return mImpl->begin__cylinder__extra(*static_cast<cylinder__extra__AttributeData*>(attributeData));}
		bool _data__cylinder__extra( const ParserChar* text, size_t textLength );
		bool _end__cylinder__extra(){return mImpl->end__cylinder__extra();}
		bool _validateBegin__cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__cylinder__extra();

		bool _begin__tapered_cylinder( void* attributeData ){return mImpl->begin__tapered_cylinder();}
		bool _data__tapered_cylinder( const ParserChar* text, size_t textLength );
		bool _end__tapered_cylinder(){return mImpl->end__tapered_cylinder();}
		bool _validateBegin__tapered_cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder();

		bool _begin__tapered_cylinder__height( void* attributeData ){return mImpl->begin__tapered_cylinder__height();}
		bool _data__tapered_cylinder__height( const ParserChar* text, size_t textLength );
		bool _end__tapered_cylinder__height(){return mImpl->end__tapered_cylinder__height();}
		bool _validateBegin__tapered_cylinder__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__height();

		bool _begin__tapered_cylinder__radius1( void* attributeData ){return mImpl->begin__tapered_cylinder__radius1();}
		bool _data__tapered_cylinder__radius1( const ParserChar* text, size_t textLength );
		bool _end__tapered_cylinder__radius1(){return mImpl->end__tapered_cylinder__radius1();}
		bool _validateBegin__tapered_cylinder__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__radius1();

		bool _begin__tapered_cylinder__radius2( void* attributeData ){return mImpl->begin__tapered_cylinder__radius2();}
		bool _data__tapered_cylinder__radius2( const ParserChar* text, size_t textLength );
		bool _end__tapered_cylinder__radius2(){return mImpl->end__tapered_cylinder__radius2();}
		bool _validateBegin__tapered_cylinder__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__radius2();

		bool _begin__tapered_cylinder__extra( void* attributeData ){return mImpl->begin__tapered_cylinder__extra(*static_cast<tapered_cylinder__extra__AttributeData*>(attributeData));}
		bool _data__tapered_cylinder__extra( const ParserChar* text, size_t textLength );
		bool _end__tapered_cylinder__extra(){return mImpl->end__tapered_cylinder__extra();}
		bool _validateBegin__tapered_cylinder__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_cylinder__extra();

		bool _begin__tapered_capsule( void* attributeData ){return mImpl->begin__tapered_capsule();}
		bool _data__tapered_capsule( const ParserChar* text, size_t textLength );
		bool _end__tapered_capsule(){return mImpl->end__tapered_capsule();}
		bool _validateBegin__tapered_capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule();

		bool _begin__tapered_capsule__height( void* attributeData ){return mImpl->begin__tapered_capsule__height();}
		bool _data__tapered_capsule__height( const ParserChar* text, size_t textLength );
		bool _end__tapered_capsule__height(){return mImpl->end__tapered_capsule__height();}
		bool _validateBegin__tapered_capsule__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__height();

		bool _begin__tapered_capsule__radius1( void* attributeData ){return mImpl->begin__tapered_capsule__radius1();}
		bool _data__tapered_capsule__radius1( const ParserChar* text, size_t textLength );
		bool _end__tapered_capsule__radius1(){return mImpl->end__tapered_capsule__radius1();}
		bool _validateBegin__tapered_capsule__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__radius1();

		bool _begin__tapered_capsule__radius2( void* attributeData ){return mImpl->begin__tapered_capsule__radius2();}
		bool _data__tapered_capsule__radius2( const ParserChar* text, size_t textLength );
		bool _end__tapered_capsule__radius2(){return mImpl->end__tapered_capsule__radius2();}
		bool _validateBegin__tapered_capsule__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__radius2();

		bool _begin__tapered_capsule__extra( void* attributeData ){return mImpl->begin__tapered_capsule__extra(*static_cast<tapered_capsule__extra__AttributeData*>(attributeData));}
		bool _data__tapered_capsule__extra( const ParserChar* text, size_t textLength );
		bool _end__tapered_capsule__extra(){return mImpl->end__tapered_capsule__extra();}
		bool _validateBegin__tapered_capsule__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tapered_capsule__extra();

		bool _begin__shape__translate( void* attributeData ){return mImpl->begin__shape__translate(*static_cast<shape__translate__AttributeData*>(attributeData));}
		bool _data__shape__translate( const ParserChar* text, size_t textLength );
		bool _end__shape__translate(){return mImpl->end__shape__translate();}
		bool _validateBegin__shape__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__translate();

		bool _begin__shape__rotate( void* attributeData ){return mImpl->begin__shape__rotate(*static_cast<shape__rotate__AttributeData*>(attributeData));}
		bool _data__shape__rotate( const ParserChar* text, size_t textLength );
		bool _end__shape__rotate(){return mImpl->end__shape__rotate();}
		bool _validateBegin__shape__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__rotate();

		bool _begin__shape__extra( void* attributeData ){return mImpl->begin__shape__extra(*static_cast<shape__extra__AttributeData*>(attributeData));}
		bool _data__shape__extra( const ParserChar* text, size_t textLength );
		bool _end__shape__extra(){return mImpl->end__shape__extra();}
		bool _validateBegin__shape__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shape__extra();

		bool _begin__instance_rigid_body__technique( void* attributeData ){return mImpl->begin__instance_rigid_body__technique(*static_cast<instance_rigid_body__technique__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body__technique( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_body__technique(){return mImpl->end__instance_rigid_body__technique();}
		bool _validateBegin__instance_rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__technique();

		bool _begin__instance_rigid_body__extra( void* attributeData ){return mImpl->begin__instance_rigid_body__extra(*static_cast<instance_rigid_body__extra__AttributeData*>(attributeData));}
		bool _data__instance_rigid_body__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_body__extra(){return mImpl->end__instance_rigid_body__extra();}
		bool _validateBegin__instance_rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_body__extra();

		bool _begin__instance_rigid_constraint( void* attributeData ){return mImpl->begin__instance_rigid_constraint(*static_cast<instance_rigid_constraint__AttributeData*>(attributeData));}
		bool _data__instance_rigid_constraint( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_constraint(){return mImpl->end__instance_rigid_constraint();}
		bool _validateBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_constraint();

		bool _begin__instance_rigid_constraint__extra( void* attributeData ){return mImpl->begin__instance_rigid_constraint__extra(*static_cast<instance_rigid_constraint__extra__AttributeData*>(attributeData));}
		bool _data__instance_rigid_constraint__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_rigid_constraint__extra(){return mImpl->end__instance_rigid_constraint__extra();}
		bool _validateBegin__instance_rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_rigid_constraint__extra();

		bool _begin__instance_physics_model__extra( void* attributeData ){return mImpl->begin__instance_physics_model__extra(*static_cast<instance_physics_model__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_model__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_model__extra(){return mImpl->end__instance_physics_model__extra();}
		bool _validateBegin__instance_physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model__extra();

		bool _begin__physics_scene__technique_common( void* attributeData ){return mImpl->begin__physics_scene__technique_common();}
		bool _data__physics_scene__technique_common( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__technique_common(){return mImpl->end__physics_scene__technique_common();}
		bool _validateBegin__physics_scene__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__technique_common();

		bool _begin__gravity( void* attributeData ){return mImpl->begin__gravity(*static_cast<gravity__AttributeData*>(attributeData));}
		bool _data__gravity( const ParserChar* text, size_t textLength );
		bool _end__gravity(){return mImpl->end__gravity();}
		bool _validateBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__gravity();

		bool _begin__time_step( void* attributeData ){return mImpl->begin__time_step(*static_cast<time_step__AttributeData*>(attributeData));}
		bool _data__time_step( const ParserChar* text, size_t textLength );
		bool _end__time_step(){return mImpl->end__time_step();}
		bool _validateBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__time_step();

		bool _begin__physics_scene__technique( void* attributeData ){return mImpl->begin__physics_scene__technique(*static_cast<physics_scene__technique__AttributeData*>(attributeData));}
		bool _data__physics_scene__technique( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__technique(){return mImpl->end__physics_scene__technique();}
		bool _validateBegin__physics_scene__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__technique();

		bool _begin__physics_scene__extra( void* attributeData ){return mImpl->begin__physics_scene__extra(*static_cast<physics_scene__extra__AttributeData*>(attributeData));}
		bool _data__physics_scene__extra( const ParserChar* text, size_t textLength );
		bool _end__physics_scene__extra(){return mImpl->end__physics_scene__extra();}
		bool _validateBegin__physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_scene__extra();

		bool _begin__library_physics_scenes__extra( void* attributeData ){return mImpl->begin__library_physics_scenes__extra(*static_cast<library_physics_scenes__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_scenes__extra( const ParserChar* text, size_t textLength );
		bool _end__library_physics_scenes__extra(){return mImpl->end__library_physics_scenes__extra();}
		bool _validateBegin__library_physics_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_scenes__extra();

		bool _begin__COLLADA( void* attributeData ){return mImpl->begin__COLLADA(*static_cast<COLLADA__AttributeData*>(attributeData));}
		bool _data__COLLADA( const ParserChar* text, size_t textLength );
		bool _end__COLLADA(){return mImpl->end__COLLADA();}
		bool _validateBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA();

		bool _begin__COLLADA__asset( void* attributeData ){return mImpl->begin__COLLADA__asset();}
		bool _data__COLLADA__asset( const ParserChar* text, size_t textLength );
		bool _end__COLLADA__asset(){return mImpl->end__COLLADA__asset();}
		bool _validateBegin__COLLADA__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA__asset();

		bool _begin__library_animations( void* attributeData ){return mImpl->begin__library_animations(*static_cast<library_animations__AttributeData*>(attributeData));}
		bool _data__library_animations( const ParserChar* text, size_t textLength );
		bool _end__library_animations(){return mImpl->end__library_animations();}
		bool _validateBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations();

		bool _begin__library_animations__asset( void* attributeData ){return mImpl->begin__library_animations__asset();}
		bool _data__library_animations__asset( const ParserChar* text, size_t textLength );
		bool _end__library_animations__asset(){return mImpl->end__library_animations__asset();}
		bool _validateBegin__library_animations__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations__asset();

		bool _begin__library_animations__extra( void* attributeData ){return mImpl->begin__library_animations__extra(*static_cast<library_animations__extra__AttributeData*>(attributeData));}
		bool _data__library_animations__extra( const ParserChar* text, size_t textLength );
		bool _end__library_animations__extra(){return mImpl->end__library_animations__extra();}
		bool _validateBegin__library_animations__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animations__extra();

		bool _begin__library_animation_clips( void* attributeData ){return mImpl->begin__library_animation_clips(*static_cast<library_animation_clips__AttributeData*>(attributeData));}
		bool _data__library_animation_clips( const ParserChar* text, size_t textLength );
		bool _end__library_animation_clips(){return mImpl->end__library_animation_clips();}
		bool _validateBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips();

		bool _begin__library_animation_clips__asset( void* attributeData ){return mImpl->begin__library_animation_clips__asset();}
		bool _data__library_animation_clips__asset( const ParserChar* text, size_t textLength );
		bool _end__library_animation_clips__asset(){return mImpl->end__library_animation_clips__asset();}
		bool _validateBegin__library_animation_clips__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips__asset();

		bool _begin__animation_clip( void* attributeData ){return mImpl->begin__animation_clip(*static_cast<animation_clip__AttributeData*>(attributeData));}
		bool _data__animation_clip( const ParserChar* text, size_t textLength );
		bool _end__animation_clip(){return mImpl->end__animation_clip();}
		bool _validateBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip();

		bool _begin__animation_clip__asset( void* attributeData ){return mImpl->begin__animation_clip__asset();}
		bool _data__animation_clip__asset( const ParserChar* text, size_t textLength );
		bool _end__animation_clip__asset(){return mImpl->end__animation_clip__asset();}
		bool _validateBegin__animation_clip__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip__asset();

		bool _begin__instance_animation( void* attributeData ){return mImpl->begin__instance_animation(*static_cast<instance_animation__AttributeData*>(attributeData));}
		bool _data__instance_animation( const ParserChar* text, size_t textLength );
		bool _end__instance_animation(){return mImpl->end__instance_animation();}
		bool _validateBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_animation();

		bool _begin__instance_animation__extra( void* attributeData ){return mImpl->begin__instance_animation__extra(*static_cast<instance_animation__extra__AttributeData*>(attributeData));}
		bool _data__instance_animation__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_animation__extra(){return mImpl->end__instance_animation__extra();}
		bool _validateBegin__instance_animation__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_animation__extra();

		bool _begin__animation_clip__extra( void* attributeData ){return mImpl->begin__animation_clip__extra(*static_cast<animation_clip__extra__AttributeData*>(attributeData));}
		bool _data__animation_clip__extra( const ParserChar* text, size_t textLength );
		bool _end__animation_clip__extra(){return mImpl->end__animation_clip__extra();}
		bool _validateBegin__animation_clip__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__animation_clip__extra();

		bool _begin__library_animation_clips__extra( void* attributeData ){return mImpl->begin__library_animation_clips__extra(*static_cast<library_animation_clips__extra__AttributeData*>(attributeData));}
		bool _data__library_animation_clips__extra( const ParserChar* text, size_t textLength );
		bool _end__library_animation_clips__extra(){return mImpl->end__library_animation_clips__extra();}
		bool _validateBegin__library_animation_clips__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_animation_clips__extra();

		bool _begin__library_cameras( void* attributeData ){return mImpl->begin__library_cameras(*static_cast<library_cameras__AttributeData*>(attributeData));}
		bool _data__library_cameras( const ParserChar* text, size_t textLength );
		bool _end__library_cameras(){return mImpl->end__library_cameras();}
		bool _validateBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras();

		bool _begin__library_cameras__asset( void* attributeData ){return mImpl->begin__library_cameras__asset();}
		bool _data__library_cameras__asset( const ParserChar* text, size_t textLength );
		bool _end__library_cameras__asset(){return mImpl->end__library_cameras__asset();}
		bool _validateBegin__library_cameras__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras__asset();

		bool _begin__camera( void* attributeData ){return mImpl->begin__camera(*static_cast<camera__AttributeData*>(attributeData));}
		bool _data__camera( const ParserChar* text, size_t textLength );
		bool _end__camera(){return mImpl->end__camera();}
		bool _validateBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera();

		bool _begin__camera__asset( void* attributeData ){return mImpl->begin__camera__asset();}
		bool _data__camera__asset( const ParserChar* text, size_t textLength );
		bool _end__camera__asset(){return mImpl->end__camera__asset();}
		bool _validateBegin__camera__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera__asset();

		bool _begin__optics( void* attributeData ){return mImpl->begin__optics();}
		bool _data__optics( const ParserChar* text, size_t textLength );
		bool _end__optics(){return mImpl->end__optics();}
		bool _validateBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics();

		bool _begin__optics__technique_common( void* attributeData ){return mImpl->begin__optics__technique_common();}
		bool _data__optics__technique_common( const ParserChar* text, size_t textLength );
		bool _end__optics__technique_common(){return mImpl->end__optics__technique_common();}
		bool _validateBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__technique_common();

		bool _begin__orthographic( void* attributeData ){return mImpl->begin__orthographic();}
		bool _data__orthographic( const ParserChar* text, size_t textLength );
		bool _end__orthographic(){return mImpl->end__orthographic();}
		bool _validateBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic();

		bool _begin__xmag( void* attributeData ){return mImpl->begin__xmag(*static_cast<xmag__AttributeData*>(attributeData));}
		bool _data__xmag( const ParserChar* text, size_t textLength );
		bool _end__xmag(){return mImpl->end__xmag();}
		bool _validateBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__xmag();

		bool _begin__ymag( void* attributeData ){return mImpl->begin__ymag(*static_cast<ymag__AttributeData*>(attributeData));}
		bool _data__ymag( const ParserChar* text, size_t textLength );
		bool _end__ymag(){return mImpl->end__ymag();}
		bool _validateBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ymag();

		bool _begin__orthographic__aspect_ratio( void* attributeData ){return mImpl->begin__orthographic__aspect_ratio(*static_cast<orthographic__aspect_ratio__AttributeData*>(attributeData));}
		bool _data__orthographic__aspect_ratio( const ParserChar* text, size_t textLength );
		bool _end__orthographic__aspect_ratio(){return mImpl->end__orthographic__aspect_ratio();}
		bool _validateBegin__orthographic__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__aspect_ratio();

		bool _begin__orthographic__znear( void* attributeData ){return mImpl->begin__orthographic__znear(*static_cast<orthographic__znear__AttributeData*>(attributeData));}
		bool _data__orthographic__znear( const ParserChar* text, size_t textLength );
		bool _end__orthographic__znear(){return mImpl->end__orthographic__znear();}
		bool _validateBegin__orthographic__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__znear();

		bool _begin__orthographic__zfar( void* attributeData ){return mImpl->begin__orthographic__zfar(*static_cast<orthographic__zfar__AttributeData*>(attributeData));}
		bool _data__orthographic__zfar( const ParserChar* text, size_t textLength );
		bool _end__orthographic__zfar(){return mImpl->end__orthographic__zfar();}
		bool _validateBegin__orthographic__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__orthographic__zfar();

		bool _begin__perspective( void* attributeData ){return mImpl->begin__perspective();}
		bool _data__perspective( const ParserChar* text, size_t textLength );
		bool _end__perspective(){return mImpl->end__perspective();}
		bool _validateBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective();

		bool _begin__xfov( void* attributeData ){return mImpl->begin__xfov(*static_cast<xfov__AttributeData*>(attributeData));}
		bool _data__xfov( const ParserChar* text, size_t textLength );
		bool _end__xfov(){return mImpl->end__xfov();}
		bool _validateBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__xfov();

		bool _begin__yfov( void* attributeData ){return mImpl->begin__yfov(*static_cast<yfov__AttributeData*>(attributeData));}
		bool _data__yfov( const ParserChar* text, size_t textLength );
		bool _end__yfov(){return mImpl->end__yfov();}
		bool _validateBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__yfov();

		bool _begin__perspective__aspect_ratio( void* attributeData ){return mImpl->begin__perspective__aspect_ratio(*static_cast<perspective__aspect_ratio__AttributeData*>(attributeData));}
		bool _data__perspective__aspect_ratio( const ParserChar* text, size_t textLength );
		bool _end__perspective__aspect_ratio(){return mImpl->end__perspective__aspect_ratio();}
		bool _validateBegin__perspective__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__aspect_ratio();

		bool _begin__perspective__znear( void* attributeData ){return mImpl->begin__perspective__znear(*static_cast<perspective__znear__AttributeData*>(attributeData));}
		bool _data__perspective__znear( const ParserChar* text, size_t textLength );
		bool _end__perspective__znear(){return mImpl->end__perspective__znear();}
		bool _validateBegin__perspective__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__znear();

		bool _begin__perspective__zfar( void* attributeData ){return mImpl->begin__perspective__zfar(*static_cast<perspective__zfar__AttributeData*>(attributeData));}
		bool _data__perspective__zfar( const ParserChar* text, size_t textLength );
		bool _end__perspective__zfar(){return mImpl->end__perspective__zfar();}
		bool _validateBegin__perspective__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__perspective__zfar();

		bool _begin__optics__technique( void* attributeData ){return mImpl->begin__optics__technique(*static_cast<optics__technique__AttributeData*>(attributeData));}
		bool _data__optics__technique( const ParserChar* text, size_t textLength );
		bool _end__optics__technique(){return mImpl->end__optics__technique();}
		bool _validateBegin__optics__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__technique();

		bool _begin__optics__extra( void* attributeData ){return mImpl->begin__optics__extra(*static_cast<optics__extra__AttributeData*>(attributeData));}
		bool _data__optics__extra( const ParserChar* text, size_t textLength );
		bool _end__optics__extra(){return mImpl->end__optics__extra();}
		bool _validateBegin__optics__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__optics__extra();

		bool _begin__imager( void* attributeData ){return mImpl->begin__imager();}
		bool _data__imager( const ParserChar* text, size_t textLength );
		bool _end__imager(){return mImpl->end__imager();}
		bool _validateBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager();

		bool _begin__imager__technique( void* attributeData ){return mImpl->begin__imager__technique(*static_cast<imager__technique__AttributeData*>(attributeData));}
		bool _data__imager__technique( const ParserChar* text, size_t textLength );
		bool _end__imager__technique(){return mImpl->end__imager__technique();}
		bool _validateBegin__imager__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager__technique();

		bool _begin__imager__extra( void* attributeData ){return mImpl->begin__imager__extra(*static_cast<imager__extra__AttributeData*>(attributeData));}
		bool _data__imager__extra( const ParserChar* text, size_t textLength );
		bool _end__imager__extra(){return mImpl->end__imager__extra();}
		bool _validateBegin__imager__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__imager__extra();

		bool _begin__camera__extra( void* attributeData ){return mImpl->begin__camera__extra(*static_cast<camera__extra__AttributeData*>(attributeData));}
		bool _data__camera__extra( const ParserChar* text, size_t textLength );
		bool _end__camera__extra(){return mImpl->end__camera__extra();}
		bool _validateBegin__camera__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__camera__extra();

		bool _begin__library_cameras__extra( void* attributeData ){return mImpl->begin__library_cameras__extra(*static_cast<library_cameras__extra__AttributeData*>(attributeData));}
		bool _data__library_cameras__extra( const ParserChar* text, size_t textLength );
		bool _end__library_cameras__extra(){return mImpl->end__library_cameras__extra();}
		bool _validateBegin__library_cameras__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_cameras__extra();

		bool _begin__library_controllers( void* attributeData ){return mImpl->begin__library_controllers(*static_cast<library_controllers__AttributeData*>(attributeData));}
		bool _data__library_controllers( const ParserChar* text, size_t textLength );
		bool _end__library_controllers(){return mImpl->end__library_controllers();}
		bool _validateBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers();

		bool _begin__library_controllers__asset( void* attributeData ){return mImpl->begin__library_controllers__asset();}
		bool _data__library_controllers__asset( const ParserChar* text, size_t textLength );
		bool _end__library_controllers__asset(){return mImpl->end__library_controllers__asset();}
		bool _validateBegin__library_controllers__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers__asset();

		bool _begin__controller( void* attributeData ){return mImpl->begin__controller(*static_cast<controller__AttributeData*>(attributeData));}
		bool _data__controller( const ParserChar* text, size_t textLength );
		bool _end__controller(){return mImpl->end__controller();}
		bool _validateBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller();

		bool _begin__controller__asset( void* attributeData ){return mImpl->begin__controller__asset();}
		bool _data__controller__asset( const ParserChar* text, size_t textLength );
		bool _end__controller__asset(){return mImpl->end__controller__asset();}
		bool _validateBegin__controller__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller__asset();

		bool _begin__skin( void* attributeData ){return mImpl->begin__skin(*static_cast<skin__AttributeData*>(attributeData));}
		bool _data__skin( const ParserChar* text, size_t textLength );
		bool _end__skin(){return mImpl->end__skin();}
		bool _validateBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin();

		bool _begin__bind_shape_matrix( void* attributeData ){return mImpl->begin__bind_shape_matrix();}
		bool _data__bind_shape_matrix( const ParserChar* text, size_t textLength );
		bool _end__bind_shape_matrix(){return mImpl->end__bind_shape_matrix();}
		bool _validateBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_shape_matrix();

		bool _begin__skin__source( void* attributeData ){return mImpl->begin__skin__source(*static_cast<skin__source__AttributeData*>(attributeData));}
		bool _data__skin__source( const ParserChar* text, size_t textLength );
		bool _end__skin__source(){return mImpl->end__skin__source();}
		bool _validateBegin__skin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin__source();

		bool _begin__joints( void* attributeData ){return mImpl->begin__joints();}
		bool _data__joints( const ParserChar* text, size_t textLength );
		bool _end__joints(){return mImpl->end__joints();}
		bool _validateBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints();

		bool _begin__joints__input( void* attributeData ){return mImpl->begin__joints__input(*static_cast<joints__input__AttributeData*>(attributeData));}
		bool _data__joints__input( const ParserChar* text, size_t textLength );
		bool _end__joints__input(){return mImpl->end__joints__input();}
		bool _validateBegin__joints__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints__input();

		bool _begin__joints__extra( void* attributeData ){return mImpl->begin__joints__extra(*static_cast<joints__extra__AttributeData*>(attributeData));}
		bool _data__joints__extra( const ParserChar* text, size_t textLength );
		bool _end__joints__extra(){return mImpl->end__joints__extra();}
		bool _validateBegin__joints__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__joints__extra();

		bool _begin__vertex_weights( void* attributeData ){return mImpl->begin__vertex_weights(*static_cast<vertex_weights__AttributeData*>(attributeData));}
		bool _data__vertex_weights( const ParserChar* text, size_t textLength );
		bool _end__vertex_weights(){return mImpl->end__vertex_weights();}
		bool _validateBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights();

		bool _begin__vertex_weights__input( void* attributeData ){return mImpl->begin__vertex_weights__input(*static_cast<vertex_weights__input__AttributeData*>(attributeData));}
		bool _data__vertex_weights__input( const ParserChar* text, size_t textLength );
		bool _end__vertex_weights__input(){return mImpl->end__vertex_weights__input();}
		bool _validateBegin__vertex_weights__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__input();

		bool _begin__vertex_weights__vcount( void* attributeData ){return mImpl->begin__vertex_weights__vcount();}
		bool _data__vertex_weights__vcount( const ParserChar* text, size_t textLength );
		bool _end__vertex_weights__vcount(){return mImpl->end__vertex_weights__vcount();}
		bool _validateBegin__vertex_weights__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__vcount();

		bool _begin__v( void* attributeData ){return mImpl->begin__v();}
		bool _data__v( const ParserChar* text, size_t textLength );
		bool _end__v(){return mImpl->end__v();}
		bool _validateBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__v();

		bool _begin__vertex_weights__extra( void* attributeData ){return mImpl->begin__vertex_weights__extra(*static_cast<vertex_weights__extra__AttributeData*>(attributeData));}
		bool _data__vertex_weights__extra( const ParserChar* text, size_t textLength );
		bool _end__vertex_weights__extra(){return mImpl->end__vertex_weights__extra();}
		bool _validateBegin__vertex_weights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertex_weights__extra();

		bool _begin__skin__extra( void* attributeData ){return mImpl->begin__skin__extra(*static_cast<skin__extra__AttributeData*>(attributeData));}
		bool _data__skin__extra( const ParserChar* text, size_t textLength );
		bool _end__skin__extra(){return mImpl->end__skin__extra();}
		bool _validateBegin__skin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__skin__extra();

		bool _begin__morph( void* attributeData ){return mImpl->begin__morph(*static_cast<morph__AttributeData*>(attributeData));}
		bool _data__morph( const ParserChar* text, size_t textLength );
		bool _end__morph(){return mImpl->end__morph();}
		bool _validateBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph();

		bool _begin__morph__source( void* attributeData ){return mImpl->begin__morph__source(*static_cast<morph__source__AttributeData*>(attributeData));}
		bool _data__morph__source( const ParserChar* text, size_t textLength );
		bool _end__morph__source(){return mImpl->end__morph__source();}
		bool _validateBegin__morph__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph__source();

		bool _begin__targets( void* attributeData ){return mImpl->begin__targets();}
		bool _data__targets( const ParserChar* text, size_t textLength );
		bool _end__targets(){return mImpl->end__targets();}
		bool _validateBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets();

		bool _begin__targets__input( void* attributeData ){return mImpl->begin__targets__input(*static_cast<targets__input__AttributeData*>(attributeData));}
		bool _data__targets__input( const ParserChar* text, size_t textLength );
		bool _end__targets__input(){return mImpl->end__targets__input();}
		bool _validateBegin__targets__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets__input();

		bool _begin__targets__extra( void* attributeData ){return mImpl->begin__targets__extra(*static_cast<targets__extra__AttributeData*>(attributeData));}
		bool _data__targets__extra( const ParserChar* text, size_t textLength );
		bool _end__targets__extra(){return mImpl->end__targets__extra();}
		bool _validateBegin__targets__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__targets__extra();

		bool _begin__morph__extra( void* attributeData ){return mImpl->begin__morph__extra(*static_cast<morph__extra__AttributeData*>(attributeData));}
		bool _data__morph__extra( const ParserChar* text, size_t textLength );
		bool _end__morph__extra(){return mImpl->end__morph__extra();}
		bool _validateBegin__morph__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__morph__extra();

		bool _begin__controller__extra( void* attributeData ){return mImpl->begin__controller__extra(*static_cast<controller__extra__AttributeData*>(attributeData));}
		bool _data__controller__extra( const ParserChar* text, size_t textLength );
		bool _end__controller__extra(){return mImpl->end__controller__extra();}
		bool _validateBegin__controller__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__controller__extra();

		bool _begin__library_controllers__extra( void* attributeData ){return mImpl->begin__library_controllers__extra(*static_cast<library_controllers__extra__AttributeData*>(attributeData));}
		bool _data__library_controllers__extra( const ParserChar* text, size_t textLength );
		bool _end__library_controllers__extra(){return mImpl->end__library_controllers__extra();}
		bool _validateBegin__library_controllers__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_controllers__extra();

		bool _begin__library_geometries( void* attributeData ){return mImpl->begin__library_geometries(*static_cast<library_geometries__AttributeData*>(attributeData));}
		bool _data__library_geometries( const ParserChar* text, size_t textLength );
		bool _end__library_geometries(){return mImpl->end__library_geometries();}
		bool _validateBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries();

		bool _begin__library_geometries__asset( void* attributeData ){return mImpl->begin__library_geometries__asset();}
		bool _data__library_geometries__asset( const ParserChar* text, size_t textLength );
		bool _end__library_geometries__asset(){return mImpl->end__library_geometries__asset();}
		bool _validateBegin__library_geometries__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries__asset();

		bool _begin__geometry( void* attributeData ){return mImpl->begin__geometry(*static_cast<geometry__AttributeData*>(attributeData));}
		bool _data__geometry( const ParserChar* text, size_t textLength );
		bool _end__geometry(){return mImpl->end__geometry();}
		bool _validateBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry();

		bool _begin__geometry__asset( void* attributeData ){return mImpl->begin__geometry__asset();}
		bool _data__geometry__asset( const ParserChar* text, size_t textLength );
		bool _end__geometry__asset(){return mImpl->end__geometry__asset();}
		bool _validateBegin__geometry__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry__asset();

		bool _begin__convex_mesh( void* attributeData ){return mImpl->begin__convex_mesh(*static_cast<convex_mesh__AttributeData*>(attributeData));}
		bool _data__convex_mesh( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh(){return mImpl->end__convex_mesh();}
		bool _validateBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh();

		bool _begin__convex_mesh__source( void* attributeData ){return mImpl->begin__convex_mesh__source(*static_cast<convex_mesh__source__AttributeData*>(attributeData));}
		bool _data__convex_mesh__source( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__source(){return mImpl->end__convex_mesh__source();}
		bool _validateBegin__convex_mesh__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__source();

		bool _begin__convex_mesh__vertices( void* attributeData ){return mImpl->begin__convex_mesh__vertices(*static_cast<convex_mesh__vertices__AttributeData*>(attributeData));}
		bool _data__convex_mesh__vertices( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__vertices(){return mImpl->end__convex_mesh__vertices();}
		bool _validateBegin__convex_mesh__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__vertices();

		bool _begin__convex_mesh__lines( void* attributeData ){return mImpl->begin__convex_mesh__lines(*static_cast<convex_mesh__lines__AttributeData*>(attributeData));}
		bool _data__convex_mesh__lines( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__lines(){return mImpl->end__convex_mesh__lines();}
		bool _validateBegin__convex_mesh__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__lines();

		bool _begin__convex_mesh__linestrips( void* attributeData ){return mImpl->begin__convex_mesh__linestrips(*static_cast<convex_mesh__linestrips__AttributeData*>(attributeData));}
		bool _data__convex_mesh__linestrips( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__linestrips(){return mImpl->end__convex_mesh__linestrips();}
		bool _validateBegin__convex_mesh__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__linestrips();

		bool _begin__convex_mesh__polygons( void* attributeData ){return mImpl->begin__convex_mesh__polygons(*static_cast<convex_mesh__polygons__AttributeData*>(attributeData));}
		bool _data__convex_mesh__polygons( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__polygons(){return mImpl->end__convex_mesh__polygons();}
		bool _validateBegin__convex_mesh__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__polygons();

		bool _begin__convex_mesh__polylist( void* attributeData ){return mImpl->begin__convex_mesh__polylist(*static_cast<convex_mesh__polylist__AttributeData*>(attributeData));}
		bool _data__convex_mesh__polylist( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__polylist(){return mImpl->end__convex_mesh__polylist();}
		bool _validateBegin__convex_mesh__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__polylist();

		bool _begin__convex_mesh__triangles( void* attributeData ){return mImpl->begin__convex_mesh__triangles(*static_cast<convex_mesh__triangles__AttributeData*>(attributeData));}
		bool _data__convex_mesh__triangles( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__triangles(){return mImpl->end__convex_mesh__triangles();}
		bool _validateBegin__convex_mesh__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__triangles();

		bool _begin__convex_mesh__trifans( void* attributeData ){return mImpl->begin__convex_mesh__trifans(*static_cast<convex_mesh__trifans__AttributeData*>(attributeData));}
		bool _data__convex_mesh__trifans( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__trifans(){return mImpl->end__convex_mesh__trifans();}
		bool _validateBegin__convex_mesh__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__trifans();

		bool _begin__convex_mesh__tristrips( void* attributeData ){return mImpl->begin__convex_mesh__tristrips(*static_cast<convex_mesh__tristrips__AttributeData*>(attributeData));}
		bool _data__convex_mesh__tristrips( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__tristrips(){return mImpl->end__convex_mesh__tristrips();}
		bool _validateBegin__convex_mesh__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__tristrips();

		bool _begin__convex_mesh__extra( void* attributeData ){return mImpl->begin__convex_mesh__extra(*static_cast<convex_mesh__extra__AttributeData*>(attributeData));}
		bool _data__convex_mesh__extra( const ParserChar* text, size_t textLength );
		bool _end__convex_mesh__extra(){return mImpl->end__convex_mesh__extra();}
		bool _validateBegin__convex_mesh__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__convex_mesh__extra();

		bool _begin__spline( void* attributeData ){return mImpl->begin__spline(*static_cast<spline__AttributeData*>(attributeData));}
		bool _data__spline( const ParserChar* text, size_t textLength );
		bool _end__spline(){return mImpl->end__spline();}
		bool _validateBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline();

		bool _begin__spline__source( void* attributeData ){return mImpl->begin__spline__source(*static_cast<spline__source__AttributeData*>(attributeData));}
		bool _data__spline__source( const ParserChar* text, size_t textLength );
		bool _end__spline__source(){return mImpl->end__spline__source();}
		bool _validateBegin__spline__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline__source();

		bool _begin__control_vertices( void* attributeData ){return mImpl->begin__control_vertices();}
		bool _data__control_vertices( const ParserChar* text, size_t textLength );
		bool _end__control_vertices(){return mImpl->end__control_vertices();}
		bool _validateBegin__control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices();

		bool _begin__control_vertices__input( void* attributeData ){return mImpl->begin__control_vertices__input(*static_cast<control_vertices__input__AttributeData*>(attributeData));}
		bool _data__control_vertices__input( const ParserChar* text, size_t textLength );
		bool _end__control_vertices__input(){return mImpl->end__control_vertices__input();}
		bool _validateBegin__control_vertices__input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices__input();

		bool _begin__control_vertices__extra( void* attributeData ){return mImpl->begin__control_vertices__extra(*static_cast<control_vertices__extra__AttributeData*>(attributeData));}
		bool _data__control_vertices__extra( const ParserChar* text, size_t textLength );
		bool _end__control_vertices__extra(){return mImpl->end__control_vertices__extra();}
		bool _validateBegin__control_vertices__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__control_vertices__extra();

		bool _begin__spline__extra( void* attributeData ){return mImpl->begin__spline__extra(*static_cast<spline__extra__AttributeData*>(attributeData));}
		bool _data__spline__extra( const ParserChar* text, size_t textLength );
		bool _end__spline__extra(){return mImpl->end__spline__extra();}
		bool _validateBegin__spline__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spline__extra();

		bool _begin__geometry__extra( void* attributeData ){return mImpl->begin__geometry__extra(*static_cast<geometry__extra__AttributeData*>(attributeData));}
		bool _data__geometry__extra( const ParserChar* text, size_t textLength );
		bool _end__geometry__extra(){return mImpl->end__geometry__extra();}
		bool _validateBegin__geometry__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__geometry__extra();

		bool _begin__library_geometries__extra( void* attributeData ){return mImpl->begin__library_geometries__extra(*static_cast<library_geometries__extra__AttributeData*>(attributeData));}
		bool _data__library_geometries__extra( const ParserChar* text, size_t textLength );
		bool _end__library_geometries__extra(){return mImpl->end__library_geometries__extra();}
		bool _validateBegin__library_geometries__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_geometries__extra();

		bool _begin__library_effects( void* attributeData ){return mImpl->begin__library_effects(*static_cast<library_effects__AttributeData*>(attributeData));}
		bool _data__library_effects( const ParserChar* text, size_t textLength );
		bool _end__library_effects(){return mImpl->end__library_effects();}
		bool _validateBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects();

		bool _begin__library_effects__asset( void* attributeData ){return mImpl->begin__library_effects__asset();}
		bool _data__library_effects__asset( const ParserChar* text, size_t textLength );
		bool _end__library_effects__asset(){return mImpl->end__library_effects__asset();}
		bool _validateBegin__library_effects__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects__asset();

		bool _begin__effect( void* attributeData ){return mImpl->begin__effect(*static_cast<effect__AttributeData*>(attributeData));}
		bool _data__effect( const ParserChar* text, size_t textLength );
		bool _end__effect(){return mImpl->end__effect();}
		bool _validateBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect();

		bool _begin__effect__asset( void* attributeData ){return mImpl->begin__effect__asset();}
		bool _data__effect__asset( const ParserChar* text, size_t textLength );
		bool _end__effect__asset(){return mImpl->end__effect__asset();}
		bool _validateBegin__effect__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__asset();

		bool _begin__effect__annotate( void* attributeData ){return mImpl->begin__effect__annotate(*static_cast<effect__annotate__AttributeData*>(attributeData));}
		bool _data__effect__annotate( const ParserChar* text, size_t textLength );
		bool _end__effect__annotate(){return mImpl->end__effect__annotate();}
		bool _validateBegin__effect__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__annotate();

		bool _begin__effect__image( void* attributeData ){return mImpl->begin__effect__image(*static_cast<effect__image__AttributeData*>(attributeData));}
		bool _data__effect__image( const ParserChar* text, size_t textLength );
		bool _end__effect__image(){return mImpl->end__effect__image();}
		bool _validateBegin__effect__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__image();

		bool _begin__effect__newparam( void* attributeData ){return mImpl->begin__effect__newparam(*static_cast<effect__newparam__AttributeData*>(attributeData));}
		bool _data__effect__newparam( const ParserChar* text, size_t textLength );
		bool _end__effect__newparam(){return mImpl->end__effect__newparam();}
		bool _validateBegin__effect__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__newparam();

		bool _begin__newparam__sampler1D( void* attributeData ){return mImpl->begin__newparam__sampler1D();}
		bool _data__newparam__sampler1D( const ParserChar* text, size_t textLength );
		bool _end__newparam__sampler1D(){return mImpl->end__newparam__sampler1D();}
		bool _validateBegin__newparam__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler1D();

		bool _begin__newparam__sampler2D( void* attributeData ){return mImpl->begin__newparam__sampler2D();}
		bool _data__newparam__sampler2D( const ParserChar* text, size_t textLength );
		bool _end__newparam__sampler2D(){return mImpl->end__newparam__sampler2D();}
		bool _validateBegin__newparam__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler2D();

		bool _begin__newparam__sampler3D( void* attributeData ){return mImpl->begin__newparam__sampler3D();}
		bool _data__newparam__sampler3D( const ParserChar* text, size_t textLength );
		bool _end__newparam__sampler3D(){return mImpl->end__newparam__sampler3D();}
		bool _validateBegin__newparam__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__sampler3D();

		bool _begin__newparam__samplerCUBE( void* attributeData ){return mImpl->begin__newparam__samplerCUBE();}
		bool _data__newparam__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _end__newparam__samplerCUBE(){return mImpl->end__newparam__samplerCUBE();}
		bool _validateBegin__newparam__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerCUBE();

		bool _begin__newparam__samplerRECT( void* attributeData ){return mImpl->begin__newparam__samplerRECT();}
		bool _data__newparam__samplerRECT( const ParserChar* text, size_t textLength );
		bool _end__newparam__samplerRECT(){return mImpl->end__newparam__samplerRECT();}
		bool _validateBegin__newparam__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerRECT();

		bool _begin__newparam__samplerDEPTH( void* attributeData ){return mImpl->begin__newparam__samplerDEPTH();}
		bool _data__newparam__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _end__newparam__samplerDEPTH(){return mImpl->end__newparam__samplerDEPTH();}
		bool _validateBegin__newparam__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__samplerDEPTH();

		bool _begin__effect__extra( void* attributeData ){return mImpl->begin__effect__extra(*static_cast<effect__extra__AttributeData*>(attributeData));}
		bool _data__effect__extra( const ParserChar* text, size_t textLength );
		bool _end__effect__extra(){return mImpl->end__effect__extra();}
		bool _validateBegin__effect__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__effect__extra();

		bool _begin__library_effects__extra( void* attributeData ){return mImpl->begin__library_effects__extra(*static_cast<library_effects__extra__AttributeData*>(attributeData));}
		bool _data__library_effects__extra( const ParserChar* text, size_t textLength );
		bool _end__library_effects__extra(){return mImpl->end__library_effects__extra();}
		bool _validateBegin__library_effects__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_effects__extra();

		bool _begin__library_images( void* attributeData ){return mImpl->begin__library_images(*static_cast<library_images__AttributeData*>(attributeData));}
		bool _data__library_images( const ParserChar* text, size_t textLength );
		bool _end__library_images(){return mImpl->end__library_images();}
		bool _validateBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images();

		bool _begin__library_images__asset( void* attributeData ){return mImpl->begin__library_images__asset();}
		bool _data__library_images__asset( const ParserChar* text, size_t textLength );
		bool _end__library_images__asset(){return mImpl->end__library_images__asset();}
		bool _validateBegin__library_images__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__asset();

		bool _begin__library_images__image( void* attributeData ){return mImpl->begin__library_images__image(*static_cast<library_images__image__AttributeData*>(attributeData));}
		bool _data__library_images__image( const ParserChar* text, size_t textLength );
		bool _end__library_images__image(){return mImpl->end__library_images__image();}
		bool _validateBegin__library_images__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__image();

		bool _begin__library_images__extra( void* attributeData ){return mImpl->begin__library_images__extra(*static_cast<library_images__extra__AttributeData*>(attributeData));}
		bool _data__library_images__extra( const ParserChar* text, size_t textLength );
		bool _end__library_images__extra(){return mImpl->end__library_images__extra();}
		bool _validateBegin__library_images__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_images__extra();

		bool _begin__library_lights( void* attributeData ){return mImpl->begin__library_lights(*static_cast<library_lights__AttributeData*>(attributeData));}
		bool _data__library_lights( const ParserChar* text, size_t textLength );
		bool _end__library_lights(){return mImpl->end__library_lights();}
		bool _validateBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights();

		bool _begin__library_lights__asset( void* attributeData ){return mImpl->begin__library_lights__asset();}
		bool _data__library_lights__asset( const ParserChar* text, size_t textLength );
		bool _end__library_lights__asset(){return mImpl->end__library_lights__asset();}
		bool _validateBegin__library_lights__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights__asset();

		bool _begin__light( void* attributeData ){return mImpl->begin__light(*static_cast<light__AttributeData*>(attributeData));}
		bool _data__light( const ParserChar* text, size_t textLength );
		bool _end__light(){return mImpl->end__light();}
		bool _validateBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light();

		bool _begin__light__asset( void* attributeData ){return mImpl->begin__light__asset();}
		bool _data__light__asset( const ParserChar* text, size_t textLength );
		bool _end__light__asset(){return mImpl->end__light__asset();}
		bool _validateBegin__light__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__asset();

		bool _begin__light__technique_common( void* attributeData ){return mImpl->begin__light__technique_common();}
		bool _data__light__technique_common( const ParserChar* text, size_t textLength );
		bool _end__light__technique_common(){return mImpl->end__light__technique_common();}
		bool _validateBegin__light__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__technique_common();

		bool _begin__technique_common__ambient( void* attributeData ){return mImpl->begin__technique_common__ambient();}
		bool _data__technique_common__ambient( const ParserChar* text, size_t textLength );
		bool _end__technique_common__ambient(){return mImpl->end__technique_common__ambient();}
		bool _validateBegin__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique_common__ambient();

		bool _begin__ambient__color( void* attributeData ){return mImpl->begin__ambient__color(*static_cast<ambient__color__AttributeData*>(attributeData));}
		bool _data__ambient__color( const ParserChar* text, size_t textLength );
		bool _end__ambient__color(){return mImpl->end__ambient__color();}
		bool _validateBegin__ambient__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__color();

		bool _begin__directional( void* attributeData ){return mImpl->begin__directional();}
		bool _data__directional( const ParserChar* text, size_t textLength );
		bool _end__directional(){return mImpl->end__directional();}
		bool _validateBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__directional();

		bool _begin__directional__color( void* attributeData ){return mImpl->begin__directional__color(*static_cast<directional__color__AttributeData*>(attributeData));}
		bool _data__directional__color( const ParserChar* text, size_t textLength );
		bool _end__directional__color(){return mImpl->end__directional__color();}
		bool _validateBegin__directional__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__directional__color();

		bool _begin__point( void* attributeData ){return mImpl->begin__point();}
		bool _data__point( const ParserChar* text, size_t textLength );
		bool _end__point(){return mImpl->end__point();}
		bool _validateBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point();

		bool _begin__point__color( void* attributeData ){return mImpl->begin__point__color(*static_cast<point__color__AttributeData*>(attributeData));}
		bool _data__point__color( const ParserChar* text, size_t textLength );
		bool _end__point__color(){return mImpl->end__point__color();}
		bool _validateBegin__point__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__color();

		bool _begin__point__constant_attenuation( void* attributeData ){return mImpl->begin__point__constant_attenuation(*static_cast<point__constant_attenuation__AttributeData*>(attributeData));}
		bool _data__point__constant_attenuation( const ParserChar* text, size_t textLength );
		bool _end__point__constant_attenuation(){return mImpl->end__point__constant_attenuation();}
		bool _validateBegin__point__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__constant_attenuation();

		bool _begin__point__linear_attenuation( void* attributeData ){return mImpl->begin__point__linear_attenuation(*static_cast<point__linear_attenuation__AttributeData*>(attributeData));}
		bool _data__point__linear_attenuation( const ParserChar* text, size_t textLength );
		bool _end__point__linear_attenuation(){return mImpl->end__point__linear_attenuation();}
		bool _validateBegin__point__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__linear_attenuation();

		bool _begin__point__quadratic_attenuation( void* attributeData ){return mImpl->begin__point__quadratic_attenuation(*static_cast<point__quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__point__quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _end__point__quadratic_attenuation(){return mImpl->end__point__quadratic_attenuation();}
		bool _validateBegin__point__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__point__quadratic_attenuation();

		bool _begin__spot( void* attributeData ){return mImpl->begin__spot();}
		bool _data__spot( const ParserChar* text, size_t textLength );
		bool _end__spot(){return mImpl->end__spot();}
		bool _validateBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot();

		bool _begin__spot__color( void* attributeData ){return mImpl->begin__spot__color(*static_cast<spot__color__AttributeData*>(attributeData));}
		bool _data__spot__color( const ParserChar* text, size_t textLength );
		bool _end__spot__color(){return mImpl->end__spot__color();}
		bool _validateBegin__spot__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__color();

		bool _begin__spot__constant_attenuation( void* attributeData ){return mImpl->begin__spot__constant_attenuation(*static_cast<spot__constant_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__constant_attenuation( const ParserChar* text, size_t textLength );
		bool _end__spot__constant_attenuation(){return mImpl->end__spot__constant_attenuation();}
		bool _validateBegin__spot__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__constant_attenuation();

		bool _begin__spot__linear_attenuation( void* attributeData ){return mImpl->begin__spot__linear_attenuation(*static_cast<spot__linear_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__linear_attenuation( const ParserChar* text, size_t textLength );
		bool _end__spot__linear_attenuation(){return mImpl->end__spot__linear_attenuation();}
		bool _validateBegin__spot__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__linear_attenuation();

		bool _begin__spot__quadratic_attenuation( void* attributeData ){return mImpl->begin__spot__quadratic_attenuation(*static_cast<spot__quadratic_attenuation__AttributeData*>(attributeData));}
		bool _data__spot__quadratic_attenuation( const ParserChar* text, size_t textLength );
		bool _end__spot__quadratic_attenuation(){return mImpl->end__spot__quadratic_attenuation();}
		bool _validateBegin__spot__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spot__quadratic_attenuation();

		bool _begin__falloff_angle( void* attributeData ){return mImpl->begin__falloff_angle(*static_cast<falloff_angle__AttributeData*>(attributeData));}
		bool _data__falloff_angle( const ParserChar* text, size_t textLength );
		bool _end__falloff_angle(){return mImpl->end__falloff_angle();}
		bool _validateBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__falloff_angle();

		bool _begin__falloff_exponent( void* attributeData ){return mImpl->begin__falloff_exponent(*static_cast<falloff_exponent__AttributeData*>(attributeData));}
		bool _data__falloff_exponent( const ParserChar* text, size_t textLength );
		bool _end__falloff_exponent(){return mImpl->end__falloff_exponent();}
		bool _validateBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__falloff_exponent();

		bool _begin__light__technique( void* attributeData ){return mImpl->begin__light__technique(*static_cast<light__technique__AttributeData*>(attributeData));}
		bool _data__light__technique( const ParserChar* text, size_t textLength );
		bool _end__light__technique(){return mImpl->end__light__technique();}
		bool _validateBegin__light__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__technique();

		bool _begin__light__extra( void* attributeData ){return mImpl->begin__light__extra(*static_cast<light__extra__AttributeData*>(attributeData));}
		bool _data__light__extra( const ParserChar* text, size_t textLength );
		bool _end__light__extra(){return mImpl->end__light__extra();}
		bool _validateBegin__light__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__light__extra();

		bool _begin__library_lights__extra( void* attributeData ){return mImpl->begin__library_lights__extra(*static_cast<library_lights__extra__AttributeData*>(attributeData));}
		bool _data__library_lights__extra( const ParserChar* text, size_t textLength );
		bool _end__library_lights__extra(){return mImpl->end__library_lights__extra();}
		bool _validateBegin__library_lights__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_lights__extra();

		bool _begin__library_materials( void* attributeData ){return mImpl->begin__library_materials(*static_cast<library_materials__AttributeData*>(attributeData));}
		bool _data__library_materials( const ParserChar* text, size_t textLength );
		bool _end__library_materials(){return mImpl->end__library_materials();}
		bool _validateBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials();

		bool _begin__library_materials__asset( void* attributeData ){return mImpl->begin__library_materials__asset();}
		bool _data__library_materials__asset( const ParserChar* text, size_t textLength );
		bool _end__library_materials__asset(){return mImpl->end__library_materials__asset();}
		bool _validateBegin__library_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials__asset();

		bool _begin__library_materials__extra( void* attributeData ){return mImpl->begin__library_materials__extra(*static_cast<library_materials__extra__AttributeData*>(attributeData));}
		bool _data__library_materials__extra( const ParserChar* text, size_t textLength );
		bool _end__library_materials__extra(){return mImpl->end__library_materials__extra();}
		bool _validateBegin__library_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_materials__extra();

		bool _begin__library_nodes( void* attributeData ){return mImpl->begin__library_nodes(*static_cast<library_nodes__AttributeData*>(attributeData));}
		bool _data__library_nodes( const ParserChar* text, size_t textLength );
		bool _end__library_nodes(){return mImpl->end__library_nodes();}
		bool _validateBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes();

		bool _begin__library_nodes__asset( void* attributeData ){return mImpl->begin__library_nodes__asset();}
		bool _data__library_nodes__asset( const ParserChar* text, size_t textLength );
		bool _end__library_nodes__asset(){return mImpl->end__library_nodes__asset();}
		bool _validateBegin__library_nodes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__asset();

		bool _begin__library_nodes__node( void* attributeData ){return mImpl->begin__library_nodes__node(*static_cast<library_nodes__node__AttributeData*>(attributeData));}
		bool _data__library_nodes__node( const ParserChar* text, size_t textLength );
		bool _end__library_nodes__node(){return mImpl->end__library_nodes__node();}
		bool _validateBegin__library_nodes__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__node();

		bool _begin__library_nodes__extra( void* attributeData ){return mImpl->begin__library_nodes__extra(*static_cast<library_nodes__extra__AttributeData*>(attributeData));}
		bool _data__library_nodes__extra( const ParserChar* text, size_t textLength );
		bool _end__library_nodes__extra(){return mImpl->end__library_nodes__extra();}
		bool _validateBegin__library_nodes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_nodes__extra();

		bool _begin__library_physics_materials( void* attributeData ){return mImpl->begin__library_physics_materials(*static_cast<library_physics_materials__AttributeData*>(attributeData));}
		bool _data__library_physics_materials( const ParserChar* text, size_t textLength );
		bool _end__library_physics_materials(){return mImpl->end__library_physics_materials();}
		bool _validateBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials();

		bool _begin__library_physics_materials__asset( void* attributeData ){return mImpl->begin__library_physics_materials__asset();}
		bool _data__library_physics_materials__asset( const ParserChar* text, size_t textLength );
		bool _end__library_physics_materials__asset(){return mImpl->end__library_physics_materials__asset();}
		bool _validateBegin__library_physics_materials__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__asset();

		bool _begin__library_physics_materials__physics_material( void* attributeData ){return mImpl->begin__library_physics_materials__physics_material(*static_cast<library_physics_materials__physics_material__AttributeData*>(attributeData));}
		bool _data__library_physics_materials__physics_material( const ParserChar* text, size_t textLength );
		bool _end__library_physics_materials__physics_material(){return mImpl->end__library_physics_materials__physics_material();}
		bool _validateBegin__library_physics_materials__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__physics_material();

		bool _begin__library_physics_materials__extra( void* attributeData ){return mImpl->begin__library_physics_materials__extra(*static_cast<library_physics_materials__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_materials__extra( const ParserChar* text, size_t textLength );
		bool _end__library_physics_materials__extra(){return mImpl->end__library_physics_materials__extra();}
		bool _validateBegin__library_physics_materials__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_materials__extra();

		bool _begin__library_physics_models( void* attributeData ){return mImpl->begin__library_physics_models(*static_cast<library_physics_models__AttributeData*>(attributeData));}
		bool _data__library_physics_models( const ParserChar* text, size_t textLength );
		bool _end__library_physics_models(){return mImpl->end__library_physics_models();}
		bool _validateBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models();

		bool _begin__library_physics_models__asset( void* attributeData ){return mImpl->begin__library_physics_models__asset();}
		bool _data__library_physics_models__asset( const ParserChar* text, size_t textLength );
		bool _end__library_physics_models__asset(){return mImpl->end__library_physics_models__asset();}
		bool _validateBegin__library_physics_models__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models__asset();

		bool _begin__physics_model( void* attributeData ){return mImpl->begin__physics_model(*static_cast<physics_model__AttributeData*>(attributeData));}
		bool _data__physics_model( const ParserChar* text, size_t textLength );
		bool _end__physics_model(){return mImpl->end__physics_model();}
		bool _validateBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model();

		bool _begin__physics_model__asset( void* attributeData ){return mImpl->begin__physics_model__asset();}
		bool _data__physics_model__asset( const ParserChar* text, size_t textLength );
		bool _end__physics_model__asset(){return mImpl->end__physics_model__asset();}
		bool _validateBegin__physics_model__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__asset();

		bool _begin__rigid_body( void* attributeData ){return mImpl->begin__rigid_body(*static_cast<rigid_body__AttributeData*>(attributeData));}
		bool _data__rigid_body( const ParserChar* text, size_t textLength );
		bool _end__rigid_body(){return mImpl->end__rigid_body();}
		bool _validateBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body();

		bool _begin__rigid_body__technique_common( void* attributeData ){return mImpl->begin__rigid_body__technique_common();}
		bool _data__rigid_body__technique_common( const ParserChar* text, size_t textLength );
		bool _end__rigid_body__technique_common(){return mImpl->end__rigid_body__technique_common();}
		bool _validateBegin__rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__technique_common();

		bool _begin__rigid_body__technique( void* attributeData ){return mImpl->begin__rigid_body__technique(*static_cast<rigid_body__technique__AttributeData*>(attributeData));}
		bool _data__rigid_body__technique( const ParserChar* text, size_t textLength );
		bool _end__rigid_body__technique(){return mImpl->end__rigid_body__technique();}
		bool _validateBegin__rigid_body__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__technique();

		bool _begin__rigid_body__extra( void* attributeData ){return mImpl->begin__rigid_body__extra(*static_cast<rigid_body__extra__AttributeData*>(attributeData));}
		bool _data__rigid_body__extra( const ParserChar* text, size_t textLength );
		bool _end__rigid_body__extra(){return mImpl->end__rigid_body__extra();}
		bool _validateBegin__rigid_body__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_body__extra();

		bool _begin__rigid_constraint( void* attributeData ){return mImpl->begin__rigid_constraint(*static_cast<rigid_constraint__AttributeData*>(attributeData));}
		bool _data__rigid_constraint( const ParserChar* text, size_t textLength );
		bool _end__rigid_constraint(){return mImpl->end__rigid_constraint();}
		bool _validateBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint();

		bool _begin__ref_attachment( void* attributeData ){return mImpl->begin__ref_attachment(*static_cast<ref_attachment__AttributeData*>(attributeData));}
		bool _data__ref_attachment( const ParserChar* text, size_t textLength );
		bool _end__ref_attachment(){return mImpl->end__ref_attachment();}
		bool _validateBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment();

		bool _begin__ref_attachment__translate( void* attributeData ){return mImpl->begin__ref_attachment__translate(*static_cast<ref_attachment__translate__AttributeData*>(attributeData));}
		bool _data__ref_attachment__translate( const ParserChar* text, size_t textLength );
		bool _end__ref_attachment__translate(){return mImpl->end__ref_attachment__translate();}
		bool _validateBegin__ref_attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__translate();

		bool _begin__ref_attachment__rotate( void* attributeData ){return mImpl->begin__ref_attachment__rotate(*static_cast<ref_attachment__rotate__AttributeData*>(attributeData));}
		bool _data__ref_attachment__rotate( const ParserChar* text, size_t textLength );
		bool _end__ref_attachment__rotate(){return mImpl->end__ref_attachment__rotate();}
		bool _validateBegin__ref_attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__rotate();

		bool _begin__ref_attachment__extra( void* attributeData ){return mImpl->begin__ref_attachment__extra(*static_cast<ref_attachment__extra__AttributeData*>(attributeData));}
		bool _data__ref_attachment__extra( const ParserChar* text, size_t textLength );
		bool _end__ref_attachment__extra(){return mImpl->end__ref_attachment__extra();}
		bool _validateBegin__ref_attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ref_attachment__extra();

		bool _begin__attachment( void* attributeData ){return mImpl->begin__attachment(*static_cast<attachment__AttributeData*>(attributeData));}
		bool _data__attachment( const ParserChar* text, size_t textLength );
		bool _end__attachment(){return mImpl->end__attachment();}
		bool _validateBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment();

		bool _begin__attachment__translate( void* attributeData ){return mImpl->begin__attachment__translate(*static_cast<attachment__translate__AttributeData*>(attributeData));}
		bool _data__attachment__translate( const ParserChar* text, size_t textLength );
		bool _end__attachment__translate(){return mImpl->end__attachment__translate();}
		bool _validateBegin__attachment__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__translate();

		bool _begin__attachment__rotate( void* attributeData ){return mImpl->begin__attachment__rotate(*static_cast<attachment__rotate__AttributeData*>(attributeData));}
		bool _data__attachment__rotate( const ParserChar* text, size_t textLength );
		bool _end__attachment__rotate(){return mImpl->end__attachment__rotate();}
		bool _validateBegin__attachment__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__rotate();

		bool _begin__attachment__extra( void* attributeData ){return mImpl->begin__attachment__extra(*static_cast<attachment__extra__AttributeData*>(attributeData));}
		bool _data__attachment__extra( const ParserChar* text, size_t textLength );
		bool _end__attachment__extra(){return mImpl->end__attachment__extra();}
		bool _validateBegin__attachment__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__attachment__extra();

		bool _begin__rigid_constraint__technique_common( void* attributeData ){return mImpl->begin__rigid_constraint__technique_common();}
		bool _data__rigid_constraint__technique_common( const ParserChar* text, size_t textLength );
		bool _end__rigid_constraint__technique_common(){return mImpl->end__rigid_constraint__technique_common();}
		bool _validateBegin__rigid_constraint__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__technique_common();

		bool _begin__enabled( void* attributeData ){return mImpl->begin__enabled(*static_cast<enabled__AttributeData*>(attributeData));}
		bool _data__enabled( const ParserChar* text, size_t textLength );
		bool _end__enabled(){return mImpl->end__enabled();}
		bool _validateBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__enabled();

		bool _begin__interpenetrate( void* attributeData ){return mImpl->begin__interpenetrate(*static_cast<interpenetrate__AttributeData*>(attributeData));}
		bool _data__interpenetrate( const ParserChar* text, size_t textLength );
		bool _end__interpenetrate(){return mImpl->end__interpenetrate();}
		bool _validateBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__interpenetrate();

		bool _begin__limits( void* attributeData ){return mImpl->begin__limits();}
		bool _data__limits( const ParserChar* text, size_t textLength );
		bool _end__limits(){return mImpl->end__limits();}
		bool _validateBegin__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__limits();

		bool _begin__swing_cone_and_twist( void* attributeData ){return mImpl->begin__swing_cone_and_twist();}
		bool _data__swing_cone_and_twist( const ParserChar* text, size_t textLength );
		bool _end__swing_cone_and_twist(){return mImpl->end__swing_cone_and_twist();}
		bool _validateBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist();

		bool _begin__swing_cone_and_twist__min( void* attributeData ){return mImpl->begin__swing_cone_and_twist__min(*static_cast<swing_cone_and_twist__min__AttributeData*>(attributeData));}
		bool _data__swing_cone_and_twist__min( const ParserChar* text, size_t textLength );
		bool _end__swing_cone_and_twist__min(){return mImpl->end__swing_cone_and_twist__min();}
		bool _validateBegin__swing_cone_and_twist__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist__min();

		bool _begin__swing_cone_and_twist__max( void* attributeData ){return mImpl->begin__swing_cone_and_twist__max(*static_cast<swing_cone_and_twist__max__AttributeData*>(attributeData));}
		bool _data__swing_cone_and_twist__max( const ParserChar* text, size_t textLength );
		bool _end__swing_cone_and_twist__max(){return mImpl->end__swing_cone_and_twist__max();}
		bool _validateBegin__swing_cone_and_twist__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__swing_cone_and_twist__max();

		bool _begin__limits__linear( void* attributeData ){return mImpl->begin__limits__linear();}
		bool _data__limits__linear( const ParserChar* text, size_t textLength );
		bool _end__limits__linear(){return mImpl->end__limits__linear();}
		bool _validateBegin__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__limits__linear();

		bool _begin__linear__min( void* attributeData ){return mImpl->begin__linear__min(*static_cast<linear__min__AttributeData*>(attributeData));}
		bool _data__linear__min( const ParserChar* text, size_t textLength );
		bool _end__linear__min(){return mImpl->end__linear__min();}
		bool _validateBegin__linear__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__min();

		bool _begin__linear__max( void* attributeData ){return mImpl->begin__linear__max(*static_cast<linear__max__AttributeData*>(attributeData));}
		bool _data__linear__max( const ParserChar* text, size_t textLength );
		bool _end__linear__max(){return mImpl->end__linear__max();}
		bool _validateBegin__linear__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__max();

		bool _begin__spring( void* attributeData ){return mImpl->begin__spring();}
		bool _data__spring( const ParserChar* text, size_t textLength );
		bool _end__spring(){return mImpl->end__spring();}
		bool _validateBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spring();

		bool _begin__angular( void* attributeData ){return mImpl->begin__angular();}
		bool _data__angular( const ParserChar* text, size_t textLength );
		bool _end__angular(){return mImpl->end__angular();}
		bool _validateBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular();

		bool _begin__angular__stiffness( void* attributeData ){return mImpl->begin__angular__stiffness(*static_cast<angular__stiffness__AttributeData*>(attributeData));}
		bool _data__angular__stiffness( const ParserChar* text, size_t textLength );
		bool _end__angular__stiffness(){return mImpl->end__angular__stiffness();}
		bool _validateBegin__angular__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__stiffness();

		bool _begin__angular__damping( void* attributeData ){return mImpl->begin__angular__damping(*static_cast<angular__damping__AttributeData*>(attributeData));}
		bool _data__angular__damping( const ParserChar* text, size_t textLength );
		bool _end__angular__damping(){return mImpl->end__angular__damping();}
		bool _validateBegin__angular__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__damping();

		bool _begin__angular__target_value( void* attributeData ){return mImpl->begin__angular__target_value(*static_cast<angular__target_value__AttributeData*>(attributeData));}
		bool _data__angular__target_value( const ParserChar* text, size_t textLength );
		bool _end__angular__target_value(){return mImpl->end__angular__target_value();}
		bool _validateBegin__angular__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__angular__target_value();

		bool _begin__spring__linear( void* attributeData ){return mImpl->begin__spring__linear();}
		bool _data__spring__linear( const ParserChar* text, size_t textLength );
		bool _end__spring__linear(){return mImpl->end__spring__linear();}
		bool _validateBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__spring__linear();

		bool _begin__linear__stiffness( void* attributeData ){return mImpl->begin__linear__stiffness(*static_cast<linear__stiffness__AttributeData*>(attributeData));}
		bool _data__linear__stiffness( const ParserChar* text, size_t textLength );
		bool _end__linear__stiffness(){return mImpl->end__linear__stiffness();}
		bool _validateBegin__linear__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__stiffness();

		bool _begin__linear__damping( void* attributeData ){return mImpl->begin__linear__damping(*static_cast<linear__damping__AttributeData*>(attributeData));}
		bool _data__linear__damping( const ParserChar* text, size_t textLength );
		bool _end__linear__damping(){return mImpl->end__linear__damping();}
		bool _validateBegin__linear__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__damping();

		bool _begin__linear__target_value( void* attributeData ){return mImpl->begin__linear__target_value(*static_cast<linear__target_value__AttributeData*>(attributeData));}
		bool _data__linear__target_value( const ParserChar* text, size_t textLength );
		bool _end__linear__target_value(){return mImpl->end__linear__target_value();}
		bool _validateBegin__linear__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linear__target_value();

		bool _begin__rigid_constraint__technique( void* attributeData ){return mImpl->begin__rigid_constraint__technique(*static_cast<rigid_constraint__technique__AttributeData*>(attributeData));}
		bool _data__rigid_constraint__technique( const ParserChar* text, size_t textLength );
		bool _end__rigid_constraint__technique(){return mImpl->end__rigid_constraint__technique();}
		bool _validateBegin__rigid_constraint__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__technique();

		bool _begin__rigid_constraint__extra( void* attributeData ){return mImpl->begin__rigid_constraint__extra(*static_cast<rigid_constraint__extra__AttributeData*>(attributeData));}
		bool _data__rigid_constraint__extra( const ParserChar* text, size_t textLength );
		bool _end__rigid_constraint__extra(){return mImpl->end__rigid_constraint__extra();}
		bool _validateBegin__rigid_constraint__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rigid_constraint__extra();

		bool _begin__physics_model__instance_physics_model( void* attributeData ){return mImpl->begin__physics_model__instance_physics_model(*static_cast<physics_model__instance_physics_model__AttributeData*>(attributeData));}
		bool _data__physics_model__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _end__physics_model__instance_physics_model(){return mImpl->end__physics_model__instance_physics_model();}
		bool _validateBegin__physics_model__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__instance_physics_model();

		bool _begin__physics_model__extra( void* attributeData ){return mImpl->begin__physics_model__extra(*static_cast<physics_model__extra__AttributeData*>(attributeData));}
		bool _data__physics_model__extra( const ParserChar* text, size_t textLength );
		bool _end__physics_model__extra(){return mImpl->end__physics_model__extra();}
		bool _validateBegin__physics_model__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_model__extra();

		bool _begin__library_physics_models__extra( void* attributeData ){return mImpl->begin__library_physics_models__extra(*static_cast<library_physics_models__extra__AttributeData*>(attributeData));}
		bool _data__library_physics_models__extra( const ParserChar* text, size_t textLength );
		bool _end__library_physics_models__extra(){return mImpl->end__library_physics_models__extra();}
		bool _validateBegin__library_physics_models__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_physics_models__extra();

		bool _begin__library_visual_scenes( void* attributeData ){return mImpl->begin__library_visual_scenes(*static_cast<library_visual_scenes__AttributeData*>(attributeData));}
		bool _data__library_visual_scenes( const ParserChar* text, size_t textLength );
		bool _end__library_visual_scenes(){return mImpl->end__library_visual_scenes();}
		bool _validateBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes();

		bool _begin__library_visual_scenes__asset( void* attributeData ){return mImpl->begin__library_visual_scenes__asset();}
		bool _data__library_visual_scenes__asset( const ParserChar* text, size_t textLength );
		bool _end__library_visual_scenes__asset(){return mImpl->end__library_visual_scenes__asset();}
		bool _validateBegin__library_visual_scenes__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes__asset();

		bool _begin__library_visual_scenes__extra( void* attributeData ){return mImpl->begin__library_visual_scenes__extra(*static_cast<library_visual_scenes__extra__AttributeData*>(attributeData));}
		bool _data__library_visual_scenes__extra( const ParserChar* text, size_t textLength );
		bool _end__library_visual_scenes__extra(){return mImpl->end__library_visual_scenes__extra();}
		bool _validateBegin__library_visual_scenes__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__library_visual_scenes__extra();

		bool _begin__scene( void* attributeData ){return mImpl->begin__scene();}
		bool _data__scene( const ParserChar* text, size_t textLength );
		bool _end__scene(){return mImpl->end__scene();}
		bool _validateBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scene();

		bool _begin__instance_physics_scene( void* attributeData ){return mImpl->begin__instance_physics_scene(*static_cast<instance_physics_scene__AttributeData*>(attributeData));}
		bool _data__instance_physics_scene( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_scene(){return mImpl->end__instance_physics_scene();}
		bool _validateBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_scene();

		bool _begin__instance_physics_scene__extra( void* attributeData ){return mImpl->begin__instance_physics_scene__extra(*static_cast<instance_physics_scene__extra__AttributeData*>(attributeData));}
		bool _data__instance_physics_scene__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_scene__extra(){return mImpl->end__instance_physics_scene__extra();}
		bool _validateBegin__instance_physics_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_scene__extra();

		bool _begin__instance_visual_scene( void* attributeData ){return mImpl->begin__instance_visual_scene(*static_cast<instance_visual_scene__AttributeData*>(attributeData));}
		bool _data__instance_visual_scene( const ParserChar* text, size_t textLength );
		bool _end__instance_visual_scene(){return mImpl->end__instance_visual_scene();}
		bool _validateBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_visual_scene();

		bool _begin__instance_visual_scene__extra( void* attributeData ){return mImpl->begin__instance_visual_scene__extra(*static_cast<instance_visual_scene__extra__AttributeData*>(attributeData));}
		bool _data__instance_visual_scene__extra( const ParserChar* text, size_t textLength );
		bool _end__instance_visual_scene__extra(){return mImpl->end__instance_visual_scene__extra();}
		bool _validateBegin__instance_visual_scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_visual_scene__extra();

		bool _begin__scene__extra( void* attributeData ){return mImpl->begin__scene__extra(*static_cast<scene__extra__AttributeData*>(attributeData));}
		bool _data__scene__extra( const ParserChar* text, size_t textLength );
		bool _end__scene__extra(){return mImpl->end__scene__extra();}
		bool _validateBegin__scene__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__scene__extra();

		bool _begin__COLLADA__extra( void* attributeData ){return mImpl->begin__COLLADA__extra(*static_cast<COLLADA__extra__AttributeData*>(attributeData));}
		bool _data__COLLADA__extra( const ParserChar* text, size_t textLength );
		bool _end__COLLADA__extra(){return mImpl->end__COLLADA__extra();}
		bool _validateBegin__COLLADA__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__COLLADA__extra();

		bool _begin__param( void* attributeData ){return mImpl->begin__param(*static_cast<param__AttributeData*>(attributeData));}
		bool _data__param( const ParserChar* text, size_t textLength );
		bool _end__param(){return mImpl->end__param();}
		bool _validateBegin__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__param();

		bool _begin__instance_geometry( void* attributeData ){return mImpl->begin__instance_geometry(*static_cast<instance_geometry__AttributeData*>(attributeData));}
		bool _data__instance_geometry( const ParserChar* text, size_t textLength );
		bool _end__instance_geometry(){return mImpl->end__instance_geometry();}
		bool _validateBegin__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_geometry();

		bool _begin__profile_GLSL( void* attributeData ){return mImpl->begin__profile_GLSL(*static_cast<profile_GLSL__AttributeData*>(attributeData));}
		bool _data__profile_GLSL( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL(){return mImpl->end__profile_GLSL();}
		bool _validateBegin__profile_GLSL( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL();

		bool _begin__profile_GLSL__asset( void* attributeData ){return mImpl->begin__profile_GLSL__asset();}
		bool _data__profile_GLSL__asset( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__asset(){return mImpl->end__profile_GLSL__asset();}
		bool _validateBegin__profile_GLSL__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__asset();

		bool _begin__profile_GLSL__code( void* attributeData ){return mImpl->begin__profile_GLSL__code(*static_cast<profile_GLSL__code__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__code( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__code(){return mImpl->end__profile_GLSL__code();}
		bool _validateBegin__profile_GLSL__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__code();

		bool _begin__profile_GLSL__include( void* attributeData ){return mImpl->begin__profile_GLSL__include(*static_cast<profile_GLSL__include__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__include( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__include(){return mImpl->end__profile_GLSL__include();}
		bool _validateBegin__profile_GLSL__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__include();

		bool _begin__profile_GLSL__image( void* attributeData ){return mImpl->begin__profile_GLSL__image(*static_cast<profile_GLSL__image__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__image( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__image(){return mImpl->end__profile_GLSL__image();}
		bool _validateBegin__profile_GLSL__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__image();

		bool _begin__profile_GLSL__newparam( void* attributeData ){return mImpl->begin__profile_GLSL__newparam(*static_cast<profile_GLSL__newparam__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__newparam( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__newparam(){return mImpl->end__profile_GLSL__newparam();}
		bool _validateBegin__profile_GLSL__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__newparam();

		bool _begin__newparam__array( void* attributeData ){return mImpl->begin__newparam__array(*static_cast<newparam__array__AttributeData*>(attributeData));}
		bool _data__newparam__array( const ParserChar* text, size_t textLength );
		bool _end__newparam__array(){return mImpl->end__newparam__array();}
		bool _validateBegin__newparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__array();

		bool _begin__array__bool( void* attributeData ){return mImpl->begin__array__bool();}
		bool _data__array__bool( const ParserChar* text, size_t textLength );
		bool _end__array__bool(){return mImpl->end__array__bool();}
		bool _validateBegin__array__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool();

		bool _begin__array__bool2( void* attributeData ){return mImpl->begin__array__bool2();}
		bool _data__array__bool2( const ParserChar* text, size_t textLength );
		bool _end__array__bool2(){return mImpl->end__array__bool2();}
		bool _validateBegin__array__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2();

		bool _begin__array__bool3( void* attributeData ){return mImpl->begin__array__bool3();}
		bool _data__array__bool3( const ParserChar* text, size_t textLength );
		bool _end__array__bool3(){return mImpl->end__array__bool3();}
		bool _validateBegin__array__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3();

		bool _begin__array__bool4( void* attributeData ){return mImpl->begin__array__bool4();}
		bool _data__array__bool4( const ParserChar* text, size_t textLength );
		bool _end__array__bool4(){return mImpl->end__array__bool4();}
		bool _validateBegin__array__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4();

		bool _begin__array__float( void* attributeData ){return mImpl->begin__array__float();}
		bool _data__array__float( const ParserChar* text, size_t textLength );
		bool _end__array__float(){return mImpl->end__array__float();}
		bool _validateBegin__array__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float();

		bool _begin__array__float2( void* attributeData ){return mImpl->begin__array__float2();}
		bool _data__array__float2( const ParserChar* text, size_t textLength );
		bool _end__array__float2(){return mImpl->end__array__float2();}
		bool _validateBegin__array__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2();

		bool _begin__array__float3( void* attributeData ){return mImpl->begin__array__float3();}
		bool _data__array__float3( const ParserChar* text, size_t textLength );
		bool _end__array__float3(){return mImpl->end__array__float3();}
		bool _validateBegin__array__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3();

		bool _begin__array__float4( void* attributeData ){return mImpl->begin__array__float4();}
		bool _data__array__float4( const ParserChar* text, size_t textLength );
		bool _end__array__float4(){return mImpl->end__array__float4();}
		bool _validateBegin__array__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4();

		bool _begin__array__float2x2( void* attributeData ){return mImpl->begin__array__float2x2();}
		bool _data__array__float2x2( const ParserChar* text, size_t textLength );
		bool _end__array__float2x2(){return mImpl->end__array__float2x2();}
		bool _validateBegin__array__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x2();

		bool _begin__array__float3x3( void* attributeData ){return mImpl->begin__array__float3x3();}
		bool _data__array__float3x3( const ParserChar* text, size_t textLength );
		bool _end__array__float3x3(){return mImpl->end__array__float3x3();}
		bool _validateBegin__array__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x3();

		bool _begin__array__float4x4( void* attributeData ){return mImpl->begin__array__float4x4();}
		bool _data__array__float4x4( const ParserChar* text, size_t textLength );
		bool _end__array__float4x4(){return mImpl->end__array__float4x4();}
		bool _validateBegin__array__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x4();

		bool _begin__array__int( void* attributeData ){return mImpl->begin__array__int();}
		bool _data__array__int( const ParserChar* text, size_t textLength );
		bool _end__array__int(){return mImpl->end__array__int();}
		bool _validateBegin__array__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int();

		bool _begin__array__int2( void* attributeData ){return mImpl->begin__array__int2();}
		bool _data__array__int2( const ParserChar* text, size_t textLength );
		bool _end__array__int2(){return mImpl->end__array__int2();}
		bool _validateBegin__array__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2();

		bool _begin__array__int3( void* attributeData ){return mImpl->begin__array__int3();}
		bool _data__array__int3( const ParserChar* text, size_t textLength );
		bool _end__array__int3(){return mImpl->end__array__int3();}
		bool _validateBegin__array__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3();

		bool _begin__array__int4( void* attributeData ){return mImpl->begin__array__int4();}
		bool _data__array__int4( const ParserChar* text, size_t textLength );
		bool _end__array__int4(){return mImpl->end__array__int4();}
		bool _validateBegin__array__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4();

		bool _begin__array__surface( void* attributeData ){return mImpl->begin__array__surface(*static_cast<array__surface__AttributeData*>(attributeData));}
		bool _data__array__surface( const ParserChar* text, size_t textLength );
		bool _end__array__surface(){return mImpl->end__array__surface();}
		bool _validateBegin__array__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__surface();

		bool _begin__generator( void* attributeData ){return mImpl->begin__generator();}
		bool _data__generator( const ParserChar* text, size_t textLength );
		bool _end__generator(){return mImpl->end__generator();}
		bool _validateBegin__generator( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator();

		bool _begin__generator__annotate( void* attributeData ){return mImpl->begin__generator__annotate(*static_cast<generator__annotate__AttributeData*>(attributeData));}
		bool _data__generator__annotate( const ParserChar* text, size_t textLength );
		bool _end__generator__annotate(){return mImpl->end__generator__annotate();}
		bool _validateBegin__generator__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__annotate();

		bool _begin__generator__code( void* attributeData ){return mImpl->begin__generator__code(*static_cast<generator__code__AttributeData*>(attributeData));}
		bool _data__generator__code( const ParserChar* text, size_t textLength );
		bool _end__generator__code(){return mImpl->end__generator__code();}
		bool _validateBegin__generator__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__code();

		bool _begin__generator__include( void* attributeData ){return mImpl->begin__generator__include(*static_cast<generator__include__AttributeData*>(attributeData));}
		bool _data__generator__include( const ParserChar* text, size_t textLength );
		bool _end__generator__include(){return mImpl->end__generator__include();}
		bool _validateBegin__generator__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__include();

		bool _begin__generator__name( void* attributeData ){return mImpl->begin__generator__name(*static_cast<generator__name__AttributeData*>(attributeData));}
		bool _data__generator__name( const ParserChar* text, size_t textLength );
		bool _end__generator__name(){return mImpl->end__generator__name();}
		bool _validateBegin__generator__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__name();

		bool _begin__generator__setparam( void* attributeData ){return mImpl->begin__generator__setparam(*static_cast<generator__setparam__AttributeData*>(attributeData));}
		bool _data__generator__setparam( const ParserChar* text, size_t textLength );
		bool _end__generator__setparam(){return mImpl->end__generator__setparam();}
		bool _validateBegin__generator__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__generator__setparam();

		bool _begin__array__sampler1D( void* attributeData ){return mImpl->begin__array__sampler1D();}
		bool _data__array__sampler1D( const ParserChar* text, size_t textLength );
		bool _end__array__sampler1D(){return mImpl->end__array__sampler1D();}
		bool _validateBegin__array__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler1D();

		bool _begin__array__sampler2D( void* attributeData ){return mImpl->begin__array__sampler2D();}
		bool _data__array__sampler2D( const ParserChar* text, size_t textLength );
		bool _end__array__sampler2D(){return mImpl->end__array__sampler2D();}
		bool _validateBegin__array__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler2D();

		bool _begin__array__sampler3D( void* attributeData ){return mImpl->begin__array__sampler3D();}
		bool _data__array__sampler3D( const ParserChar* text, size_t textLength );
		bool _end__array__sampler3D(){return mImpl->end__array__sampler3D();}
		bool _validateBegin__array__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__sampler3D();

		bool _begin__array__samplerCUBE( void* attributeData ){return mImpl->begin__array__samplerCUBE();}
		bool _data__array__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _end__array__samplerCUBE(){return mImpl->end__array__samplerCUBE();}
		bool _validateBegin__array__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerCUBE();

		bool _begin__array__samplerRECT( void* attributeData ){return mImpl->begin__array__samplerRECT();}
		bool _data__array__samplerRECT( const ParserChar* text, size_t textLength );
		bool _end__array__samplerRECT(){return mImpl->end__array__samplerRECT();}
		bool _validateBegin__array__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerRECT();

		bool _begin__array__samplerDEPTH( void* attributeData ){return mImpl->begin__array__samplerDEPTH();}
		bool _data__array__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _end__array__samplerDEPTH(){return mImpl->end__array__samplerDEPTH();}
		bool _validateBegin__array__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__samplerDEPTH();

		bool _begin__array__enum( void* attributeData ){return mImpl->begin__array__enum();}
		bool _data__array__enum( const ParserChar* text, size_t textLength );
		bool _end__array__enum(){return mImpl->end__array__enum();}
		bool _validateBegin__array__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__enum();

		bool _begin__array__array( void* attributeData ){return mImpl->begin__array__array(*static_cast<array__array__AttributeData*>(attributeData));}
		bool _data__array__array( const ParserChar* text, size_t textLength );
		bool _end__array__array(){return mImpl->end__array__array();}
		bool _validateBegin__array__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__array();

		bool _begin__profile_GLSL__technique( void* attributeData ){return mImpl->begin__profile_GLSL__technique(*static_cast<profile_GLSL__technique__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__technique( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__technique(){return mImpl->end__profile_GLSL__technique();}
		bool _validateBegin__profile_GLSL__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__technique();

		bool _begin__technique__code( void* attributeData ){return mImpl->begin__technique__code(*static_cast<technique__code__AttributeData*>(attributeData));}
		bool _data__technique__code( const ParserChar* text, size_t textLength );
		bool _end__technique__code(){return mImpl->end__technique__code();}
		bool _validateBegin__technique__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__code();

		bool _begin__technique__include( void* attributeData ){return mImpl->begin__technique__include(*static_cast<technique__include__AttributeData*>(attributeData));}
		bool _data__technique__include( const ParserChar* text, size_t textLength );
		bool _end__technique__include(){return mImpl->end__technique__include();}
		bool _validateBegin__technique__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__include();

		bool _begin__profile_GLSL__extra( void* attributeData ){return mImpl->begin__profile_GLSL__extra(*static_cast<profile_GLSL__extra__AttributeData*>(attributeData));}
		bool _data__profile_GLSL__extra( const ParserChar* text, size_t textLength );
		bool _end__profile_GLSL__extra(){return mImpl->end__profile_GLSL__extra();}
		bool _validateBegin__profile_GLSL__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_GLSL__extra();

		bool _begin__image( void* attributeData ){return mImpl->begin__image(*static_cast<image__AttributeData*>(attributeData));}
		bool _data__image( const ParserChar* text, size_t textLength );
		bool _end__image(){return mImpl->end__image();}
		bool _validateBegin__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__image();

		bool _begin__instance_physics_model( void* attributeData ){return mImpl->begin__instance_physics_model(*static_cast<instance_physics_model__AttributeData*>(attributeData));}
		bool _data__instance_physics_model( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_model(){return mImpl->end__instance_physics_model();}
		bool _validateBegin__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_model();

		bool _begin__physics_material( void* attributeData ){return mImpl->begin__physics_material(*static_cast<physics_material__AttributeData*>(attributeData));}
		bool _data__physics_material( const ParserChar* text, size_t textLength );
		bool _end__physics_material(){return mImpl->end__physics_material();}
		bool _validateBegin__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__physics_material();

		bool _begin__linestrips( void* attributeData ){return mImpl->begin__linestrips(*static_cast<linestrips__AttributeData*>(attributeData));}
		bool _data__linestrips( const ParserChar* text, size_t textLength );
		bool _end__linestrips(){return mImpl->end__linestrips();}
		bool _validateBegin__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__linestrips();

		bool _begin__gl_hook_abstract( void* attributeData ){return mImpl->begin__gl_hook_abstract();}
		bool _data__gl_hook_abstract( const ParserChar* text, size_t textLength );
		bool _end__gl_hook_abstract(){return mImpl->end__gl_hook_abstract();}
		bool _validateBegin__gl_hook_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__gl_hook_abstract();

		bool _begin__node( void* attributeData ){return mImpl->begin__node(*static_cast<node__AttributeData*>(attributeData));}
		bool _data__node( const ParserChar* text, size_t textLength );
		bool _end__node(){return mImpl->end__node();}
		bool _validateBegin__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__node();

		bool _begin__technique( void* attributeData ){return mImpl->begin__technique(*static_cast<technique__AttributeData*>(attributeData));}
		bool _data__technique( const ParserChar* text, size_t textLength );
		bool _end__technique(){return mImpl->end__technique();}
		bool _validateBegin__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique();

		bool _begin__tristrips( void* attributeData ){return mImpl->begin__tristrips(*static_cast<tristrips__AttributeData*>(attributeData));}
		bool _data__tristrips( const ParserChar* text, size_t textLength );
		bool _end__tristrips(){return mImpl->end__tristrips();}
		bool _validateBegin__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__tristrips();

		bool _begin__profile_CG( void* attributeData ){return mImpl->begin__profile_CG(*static_cast<profile_CG__AttributeData*>(attributeData));}
		bool _data__profile_CG( const ParserChar* text, size_t textLength );
		bool _end__profile_CG(){return mImpl->end__profile_CG();}
		bool _validateBegin__profile_CG( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG();

		bool _begin__profile_CG__asset( void* attributeData ){return mImpl->begin__profile_CG__asset();}
		bool _data__profile_CG__asset( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__asset(){return mImpl->end__profile_CG__asset();}
		bool _validateBegin__profile_CG__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__asset();

		bool _begin__profile_CG__code( void* attributeData ){return mImpl->begin__profile_CG__code(*static_cast<profile_CG__code__AttributeData*>(attributeData));}
		bool _data__profile_CG__code( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__code(){return mImpl->end__profile_CG__code();}
		bool _validateBegin__profile_CG__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__code();

		bool _begin__profile_CG__include( void* attributeData ){return mImpl->begin__profile_CG__include(*static_cast<profile_CG__include__AttributeData*>(attributeData));}
		bool _data__profile_CG__include( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__include(){return mImpl->end__profile_CG__include();}
		bool _validateBegin__profile_CG__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__include();

		bool _begin__profile_CG__image( void* attributeData ){return mImpl->begin__profile_CG__image(*static_cast<profile_CG__image__AttributeData*>(attributeData));}
		bool _data__profile_CG__image( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__image(){return mImpl->end__profile_CG__image();}
		bool _validateBegin__profile_CG__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__image();

		bool _begin__profile_CG__newparam( void* attributeData ){return mImpl->begin__profile_CG__newparam(*static_cast<profile_CG__newparam__AttributeData*>(attributeData));}
		bool _data__profile_CG__newparam( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__newparam(){return mImpl->end__profile_CG__newparam();}
		bool _validateBegin__profile_CG__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__newparam();

		bool _begin__newparam__bool1( void* attributeData ){return mImpl->begin__newparam__bool1();}
		bool _data__newparam__bool1( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool1(){return mImpl->end__newparam__bool1();}
		bool _validateBegin__newparam__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1();

		bool _begin__newparam__bool1x1( void* attributeData ){return mImpl->begin__newparam__bool1x1();}
		bool _data__newparam__bool1x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool1x1(){return mImpl->end__newparam__bool1x1();}
		bool _validateBegin__newparam__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x1();

		bool _begin__newparam__bool1x2( void* attributeData ){return mImpl->begin__newparam__bool1x2();}
		bool _data__newparam__bool1x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool1x2(){return mImpl->end__newparam__bool1x2();}
		bool _validateBegin__newparam__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x2();

		bool _begin__newparam__bool1x3( void* attributeData ){return mImpl->begin__newparam__bool1x3();}
		bool _data__newparam__bool1x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool1x3(){return mImpl->end__newparam__bool1x3();}
		bool _validateBegin__newparam__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x3();

		bool _begin__newparam__bool1x4( void* attributeData ){return mImpl->begin__newparam__bool1x4();}
		bool _data__newparam__bool1x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool1x4(){return mImpl->end__newparam__bool1x4();}
		bool _validateBegin__newparam__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool1x4();

		bool _begin__newparam__bool2x1( void* attributeData ){return mImpl->begin__newparam__bool2x1();}
		bool _data__newparam__bool2x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool2x1(){return mImpl->end__newparam__bool2x1();}
		bool _validateBegin__newparam__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x1();

		bool _begin__newparam__bool2x2( void* attributeData ){return mImpl->begin__newparam__bool2x2();}
		bool _data__newparam__bool2x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool2x2(){return mImpl->end__newparam__bool2x2();}
		bool _validateBegin__newparam__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x2();

		bool _begin__newparam__bool2x3( void* attributeData ){return mImpl->begin__newparam__bool2x3();}
		bool _data__newparam__bool2x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool2x3(){return mImpl->end__newparam__bool2x3();}
		bool _validateBegin__newparam__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x3();

		bool _begin__newparam__bool2x4( void* attributeData ){return mImpl->begin__newparam__bool2x4();}
		bool _data__newparam__bool2x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool2x4(){return mImpl->end__newparam__bool2x4();}
		bool _validateBegin__newparam__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool2x4();

		bool _begin__newparam__bool3x1( void* attributeData ){return mImpl->begin__newparam__bool3x1();}
		bool _data__newparam__bool3x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool3x1(){return mImpl->end__newparam__bool3x1();}
		bool _validateBegin__newparam__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x1();

		bool _begin__newparam__bool3x2( void* attributeData ){return mImpl->begin__newparam__bool3x2();}
		bool _data__newparam__bool3x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool3x2(){return mImpl->end__newparam__bool3x2();}
		bool _validateBegin__newparam__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x2();

		bool _begin__newparam__bool3x3( void* attributeData ){return mImpl->begin__newparam__bool3x3();}
		bool _data__newparam__bool3x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool3x3(){return mImpl->end__newparam__bool3x3();}
		bool _validateBegin__newparam__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x3();

		bool _begin__newparam__bool3x4( void* attributeData ){return mImpl->begin__newparam__bool3x4();}
		bool _data__newparam__bool3x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool3x4(){return mImpl->end__newparam__bool3x4();}
		bool _validateBegin__newparam__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool3x4();

		bool _begin__newparam__bool4x1( void* attributeData ){return mImpl->begin__newparam__bool4x1();}
		bool _data__newparam__bool4x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool4x1(){return mImpl->end__newparam__bool4x1();}
		bool _validateBegin__newparam__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x1();

		bool _begin__newparam__bool4x2( void* attributeData ){return mImpl->begin__newparam__bool4x2();}
		bool _data__newparam__bool4x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool4x2(){return mImpl->end__newparam__bool4x2();}
		bool _validateBegin__newparam__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x2();

		bool _begin__newparam__bool4x3( void* attributeData ){return mImpl->begin__newparam__bool4x3();}
		bool _data__newparam__bool4x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool4x3(){return mImpl->end__newparam__bool4x3();}
		bool _validateBegin__newparam__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x3();

		bool _begin__newparam__bool4x4( void* attributeData ){return mImpl->begin__newparam__bool4x4();}
		bool _data__newparam__bool4x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__bool4x4(){return mImpl->end__newparam__bool4x4();}
		bool _validateBegin__newparam__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__bool4x4();

		bool _begin__newparam__float1( void* attributeData ){return mImpl->begin__newparam__float1();}
		bool _data__newparam__float1( const ParserChar* text, size_t textLength );
		bool _end__newparam__float1(){return mImpl->end__newparam__float1();}
		bool _validateBegin__newparam__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__float1();

		bool _begin__newparam__int1( void* attributeData ){return mImpl->begin__newparam__int1();}
		bool _data__newparam__int1( const ParserChar* text, size_t textLength );
		bool _end__newparam__int1(){return mImpl->end__newparam__int1();}
		bool _validateBegin__newparam__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1();

		bool _begin__newparam__int1x1( void* attributeData ){return mImpl->begin__newparam__int1x1();}
		bool _data__newparam__int1x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__int1x1(){return mImpl->end__newparam__int1x1();}
		bool _validateBegin__newparam__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x1();

		bool _begin__newparam__int1x2( void* attributeData ){return mImpl->begin__newparam__int1x2();}
		bool _data__newparam__int1x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__int1x2(){return mImpl->end__newparam__int1x2();}
		bool _validateBegin__newparam__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x2();

		bool _begin__newparam__int1x3( void* attributeData ){return mImpl->begin__newparam__int1x3();}
		bool _data__newparam__int1x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__int1x3(){return mImpl->end__newparam__int1x3();}
		bool _validateBegin__newparam__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x3();

		bool _begin__newparam__int1x4( void* attributeData ){return mImpl->begin__newparam__int1x4();}
		bool _data__newparam__int1x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__int1x4(){return mImpl->end__newparam__int1x4();}
		bool _validateBegin__newparam__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int1x4();

		bool _begin__newparam__int2x1( void* attributeData ){return mImpl->begin__newparam__int2x1();}
		bool _data__newparam__int2x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__int2x1(){return mImpl->end__newparam__int2x1();}
		bool _validateBegin__newparam__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x1();

		bool _begin__newparam__int2x2( void* attributeData ){return mImpl->begin__newparam__int2x2();}
		bool _data__newparam__int2x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__int2x2(){return mImpl->end__newparam__int2x2();}
		bool _validateBegin__newparam__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x2();

		bool _begin__newparam__int2x3( void* attributeData ){return mImpl->begin__newparam__int2x3();}
		bool _data__newparam__int2x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__int2x3(){return mImpl->end__newparam__int2x3();}
		bool _validateBegin__newparam__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x3();

		bool _begin__newparam__int2x4( void* attributeData ){return mImpl->begin__newparam__int2x4();}
		bool _data__newparam__int2x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__int2x4(){return mImpl->end__newparam__int2x4();}
		bool _validateBegin__newparam__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int2x4();

		bool _begin__newparam__int3x1( void* attributeData ){return mImpl->begin__newparam__int3x1();}
		bool _data__newparam__int3x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__int3x1(){return mImpl->end__newparam__int3x1();}
		bool _validateBegin__newparam__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x1();

		bool _begin__newparam__int3x2( void* attributeData ){return mImpl->begin__newparam__int3x2();}
		bool _data__newparam__int3x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__int3x2(){return mImpl->end__newparam__int3x2();}
		bool _validateBegin__newparam__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x2();

		bool _begin__newparam__int3x3( void* attributeData ){return mImpl->begin__newparam__int3x3();}
		bool _data__newparam__int3x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__int3x3(){return mImpl->end__newparam__int3x3();}
		bool _validateBegin__newparam__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x3();

		bool _begin__newparam__int3x4( void* attributeData ){return mImpl->begin__newparam__int3x4();}
		bool _data__newparam__int3x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__int3x4(){return mImpl->end__newparam__int3x4();}
		bool _validateBegin__newparam__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int3x4();

		bool _begin__newparam__int4x1( void* attributeData ){return mImpl->begin__newparam__int4x1();}
		bool _data__newparam__int4x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__int4x1(){return mImpl->end__newparam__int4x1();}
		bool _validateBegin__newparam__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x1();

		bool _begin__newparam__int4x2( void* attributeData ){return mImpl->begin__newparam__int4x2();}
		bool _data__newparam__int4x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__int4x2(){return mImpl->end__newparam__int4x2();}
		bool _validateBegin__newparam__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x2();

		bool _begin__newparam__int4x3( void* attributeData ){return mImpl->begin__newparam__int4x3();}
		bool _data__newparam__int4x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__int4x3(){return mImpl->end__newparam__int4x3();}
		bool _validateBegin__newparam__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x3();

		bool _begin__newparam__int4x4( void* attributeData ){return mImpl->begin__newparam__int4x4();}
		bool _data__newparam__int4x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__int4x4(){return mImpl->end__newparam__int4x4();}
		bool _validateBegin__newparam__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__int4x4();

		bool _begin__newparam__half( void* attributeData ){return mImpl->begin__newparam__half();}
		bool _data__newparam__half( const ParserChar* text, size_t textLength );
		bool _end__newparam__half(){return mImpl->end__newparam__half();}
		bool _validateBegin__newparam__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half();

		bool _begin__newparam__half1( void* attributeData ){return mImpl->begin__newparam__half1();}
		bool _data__newparam__half1( const ParserChar* text, size_t textLength );
		bool _end__newparam__half1(){return mImpl->end__newparam__half1();}
		bool _validateBegin__newparam__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1();

		bool _begin__newparam__half2( void* attributeData ){return mImpl->begin__newparam__half2();}
		bool _data__newparam__half2( const ParserChar* text, size_t textLength );
		bool _end__newparam__half2(){return mImpl->end__newparam__half2();}
		bool _validateBegin__newparam__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2();

		bool _begin__newparam__half3( void* attributeData ){return mImpl->begin__newparam__half3();}
		bool _data__newparam__half3( const ParserChar* text, size_t textLength );
		bool _end__newparam__half3(){return mImpl->end__newparam__half3();}
		bool _validateBegin__newparam__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3();

		bool _begin__newparam__half4( void* attributeData ){return mImpl->begin__newparam__half4();}
		bool _data__newparam__half4( const ParserChar* text, size_t textLength );
		bool _end__newparam__half4(){return mImpl->end__newparam__half4();}
		bool _validateBegin__newparam__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4();

		bool _begin__newparam__half1x1( void* attributeData ){return mImpl->begin__newparam__half1x1();}
		bool _data__newparam__half1x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__half1x1(){return mImpl->end__newparam__half1x1();}
		bool _validateBegin__newparam__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x1();

		bool _begin__newparam__half1x2( void* attributeData ){return mImpl->begin__newparam__half1x2();}
		bool _data__newparam__half1x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__half1x2(){return mImpl->end__newparam__half1x2();}
		bool _validateBegin__newparam__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x2();

		bool _begin__newparam__half1x3( void* attributeData ){return mImpl->begin__newparam__half1x3();}
		bool _data__newparam__half1x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__half1x3(){return mImpl->end__newparam__half1x3();}
		bool _validateBegin__newparam__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x3();

		bool _begin__newparam__half1x4( void* attributeData ){return mImpl->begin__newparam__half1x4();}
		bool _data__newparam__half1x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__half1x4(){return mImpl->end__newparam__half1x4();}
		bool _validateBegin__newparam__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half1x4();

		bool _begin__newparam__half2x1( void* attributeData ){return mImpl->begin__newparam__half2x1();}
		bool _data__newparam__half2x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__half2x1(){return mImpl->end__newparam__half2x1();}
		bool _validateBegin__newparam__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x1();

		bool _begin__newparam__half2x2( void* attributeData ){return mImpl->begin__newparam__half2x2();}
		bool _data__newparam__half2x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__half2x2(){return mImpl->end__newparam__half2x2();}
		bool _validateBegin__newparam__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x2();

		bool _begin__newparam__half2x3( void* attributeData ){return mImpl->begin__newparam__half2x3();}
		bool _data__newparam__half2x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__half2x3(){return mImpl->end__newparam__half2x3();}
		bool _validateBegin__newparam__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x3();

		bool _begin__newparam__half2x4( void* attributeData ){return mImpl->begin__newparam__half2x4();}
		bool _data__newparam__half2x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__half2x4(){return mImpl->end__newparam__half2x4();}
		bool _validateBegin__newparam__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half2x4();

		bool _begin__newparam__half3x1( void* attributeData ){return mImpl->begin__newparam__half3x1();}
		bool _data__newparam__half3x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__half3x1(){return mImpl->end__newparam__half3x1();}
		bool _validateBegin__newparam__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x1();

		bool _begin__newparam__half3x2( void* attributeData ){return mImpl->begin__newparam__half3x2();}
		bool _data__newparam__half3x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__half3x2(){return mImpl->end__newparam__half3x2();}
		bool _validateBegin__newparam__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x2();

		bool _begin__newparam__half3x3( void* attributeData ){return mImpl->begin__newparam__half3x3();}
		bool _data__newparam__half3x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__half3x3(){return mImpl->end__newparam__half3x3();}
		bool _validateBegin__newparam__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x3();

		bool _begin__newparam__half3x4( void* attributeData ){return mImpl->begin__newparam__half3x4();}
		bool _data__newparam__half3x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__half3x4(){return mImpl->end__newparam__half3x4();}
		bool _validateBegin__newparam__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half3x4();

		bool _begin__newparam__half4x1( void* attributeData ){return mImpl->begin__newparam__half4x1();}
		bool _data__newparam__half4x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__half4x1(){return mImpl->end__newparam__half4x1();}
		bool _validateBegin__newparam__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x1();

		bool _begin__newparam__half4x2( void* attributeData ){return mImpl->begin__newparam__half4x2();}
		bool _data__newparam__half4x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__half4x2(){return mImpl->end__newparam__half4x2();}
		bool _validateBegin__newparam__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x2();

		bool _begin__newparam__half4x3( void* attributeData ){return mImpl->begin__newparam__half4x3();}
		bool _data__newparam__half4x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__half4x3(){return mImpl->end__newparam__half4x3();}
		bool _validateBegin__newparam__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x3();

		bool _begin__newparam__half4x4( void* attributeData ){return mImpl->begin__newparam__half4x4();}
		bool _data__newparam__half4x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__half4x4(){return mImpl->end__newparam__half4x4();}
		bool _validateBegin__newparam__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__half4x4();

		bool _begin__newparam__fixed( void* attributeData ){return mImpl->begin__newparam__fixed();}
		bool _data__newparam__fixed( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed(){return mImpl->end__newparam__fixed();}
		bool _validateBegin__newparam__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed();

		bool _begin__newparam__fixed1( void* attributeData ){return mImpl->begin__newparam__fixed1();}
		bool _data__newparam__fixed1( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed1(){return mImpl->end__newparam__fixed1();}
		bool _validateBegin__newparam__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1();

		bool _begin__newparam__fixed2( void* attributeData ){return mImpl->begin__newparam__fixed2();}
		bool _data__newparam__fixed2( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed2(){return mImpl->end__newparam__fixed2();}
		bool _validateBegin__newparam__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2();

		bool _begin__newparam__fixed3( void* attributeData ){return mImpl->begin__newparam__fixed3();}
		bool _data__newparam__fixed3( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed3(){return mImpl->end__newparam__fixed3();}
		bool _validateBegin__newparam__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3();

		bool _begin__newparam__fixed4( void* attributeData ){return mImpl->begin__newparam__fixed4();}
		bool _data__newparam__fixed4( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed4(){return mImpl->end__newparam__fixed4();}
		bool _validateBegin__newparam__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4();

		bool _begin__newparam__fixed1x1( void* attributeData ){return mImpl->begin__newparam__fixed1x1();}
		bool _data__newparam__fixed1x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed1x1(){return mImpl->end__newparam__fixed1x1();}
		bool _validateBegin__newparam__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x1();

		bool _begin__newparam__fixed1x2( void* attributeData ){return mImpl->begin__newparam__fixed1x2();}
		bool _data__newparam__fixed1x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed1x2(){return mImpl->end__newparam__fixed1x2();}
		bool _validateBegin__newparam__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x2();

		bool _begin__newparam__fixed1x3( void* attributeData ){return mImpl->begin__newparam__fixed1x3();}
		bool _data__newparam__fixed1x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed1x3(){return mImpl->end__newparam__fixed1x3();}
		bool _validateBegin__newparam__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x3();

		bool _begin__newparam__fixed1x4( void* attributeData ){return mImpl->begin__newparam__fixed1x4();}
		bool _data__newparam__fixed1x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed1x4(){return mImpl->end__newparam__fixed1x4();}
		bool _validateBegin__newparam__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed1x4();

		bool _begin__newparam__fixed2x1( void* attributeData ){return mImpl->begin__newparam__fixed2x1();}
		bool _data__newparam__fixed2x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed2x1(){return mImpl->end__newparam__fixed2x1();}
		bool _validateBegin__newparam__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x1();

		bool _begin__newparam__fixed2x2( void* attributeData ){return mImpl->begin__newparam__fixed2x2();}
		bool _data__newparam__fixed2x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed2x2(){return mImpl->end__newparam__fixed2x2();}
		bool _validateBegin__newparam__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x2();

		bool _begin__newparam__fixed2x3( void* attributeData ){return mImpl->begin__newparam__fixed2x3();}
		bool _data__newparam__fixed2x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed2x3(){return mImpl->end__newparam__fixed2x3();}
		bool _validateBegin__newparam__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x3();

		bool _begin__newparam__fixed2x4( void* attributeData ){return mImpl->begin__newparam__fixed2x4();}
		bool _data__newparam__fixed2x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed2x4(){return mImpl->end__newparam__fixed2x4();}
		bool _validateBegin__newparam__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed2x4();

		bool _begin__newparam__fixed3x1( void* attributeData ){return mImpl->begin__newparam__fixed3x1();}
		bool _data__newparam__fixed3x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed3x1(){return mImpl->end__newparam__fixed3x1();}
		bool _validateBegin__newparam__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x1();

		bool _begin__newparam__fixed3x2( void* attributeData ){return mImpl->begin__newparam__fixed3x2();}
		bool _data__newparam__fixed3x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed3x2(){return mImpl->end__newparam__fixed3x2();}
		bool _validateBegin__newparam__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x2();

		bool _begin__newparam__fixed3x3( void* attributeData ){return mImpl->begin__newparam__fixed3x3();}
		bool _data__newparam__fixed3x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed3x3(){return mImpl->end__newparam__fixed3x3();}
		bool _validateBegin__newparam__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x3();

		bool _begin__newparam__fixed3x4( void* attributeData ){return mImpl->begin__newparam__fixed3x4();}
		bool _data__newparam__fixed3x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed3x4(){return mImpl->end__newparam__fixed3x4();}
		bool _validateBegin__newparam__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed3x4();

		bool _begin__newparam__fixed4x1( void* attributeData ){return mImpl->begin__newparam__fixed4x1();}
		bool _data__newparam__fixed4x1( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed4x1(){return mImpl->end__newparam__fixed4x1();}
		bool _validateBegin__newparam__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x1();

		bool _begin__newparam__fixed4x2( void* attributeData ){return mImpl->begin__newparam__fixed4x2();}
		bool _data__newparam__fixed4x2( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed4x2(){return mImpl->end__newparam__fixed4x2();}
		bool _validateBegin__newparam__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x2();

		bool _begin__newparam__fixed4x3( void* attributeData ){return mImpl->begin__newparam__fixed4x3();}
		bool _data__newparam__fixed4x3( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed4x3(){return mImpl->end__newparam__fixed4x3();}
		bool _validateBegin__newparam__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x3();

		bool _begin__newparam__fixed4x4( void* attributeData ){return mImpl->begin__newparam__fixed4x4();}
		bool _data__newparam__fixed4x4( const ParserChar* text, size_t textLength );
		bool _end__newparam__fixed4x4(){return mImpl->end__newparam__fixed4x4();}
		bool _validateBegin__newparam__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__fixed4x4();

		bool _begin__newparam__string( void* attributeData ){return mImpl->begin__newparam__string();}
		bool _data__newparam__string( const ParserChar* text, size_t textLength );
		bool _end__newparam__string(){return mImpl->end__newparam__string();}
		bool _validateBegin__newparam__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__string();

		bool _begin__newparam__usertype( void* attributeData ){return mImpl->begin__newparam__usertype(*static_cast<newparam__usertype__AttributeData*>(attributeData));}
		bool _data__newparam__usertype( const ParserChar* text, size_t textLength );
		bool _end__newparam__usertype(){return mImpl->end__newparam__usertype();}
		bool _validateBegin__newparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__newparam__usertype();

		bool _begin__usertype__bool( void* attributeData ){return mImpl->begin__usertype__bool();}
		bool _data__usertype__bool( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool(){return mImpl->end__usertype__bool();}
		bool _validateBegin__usertype__bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool();

		bool _begin__usertype__bool1( void* attributeData ){return mImpl->begin__usertype__bool1();}
		bool _data__usertype__bool1( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool1(){return mImpl->end__usertype__bool1();}
		bool _validateBegin__usertype__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1();

		bool _begin__usertype__bool2( void* attributeData ){return mImpl->begin__usertype__bool2();}
		bool _data__usertype__bool2( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool2(){return mImpl->end__usertype__bool2();}
		bool _validateBegin__usertype__bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2();

		bool _begin__usertype__bool3( void* attributeData ){return mImpl->begin__usertype__bool3();}
		bool _data__usertype__bool3( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool3(){return mImpl->end__usertype__bool3();}
		bool _validateBegin__usertype__bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3();

		bool _begin__usertype__bool4( void* attributeData ){return mImpl->begin__usertype__bool4();}
		bool _data__usertype__bool4( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool4(){return mImpl->end__usertype__bool4();}
		bool _validateBegin__usertype__bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4();

		bool _begin__usertype__bool1x1( void* attributeData ){return mImpl->begin__usertype__bool1x1();}
		bool _data__usertype__bool1x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool1x1(){return mImpl->end__usertype__bool1x1();}
		bool _validateBegin__usertype__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x1();

		bool _begin__usertype__bool1x2( void* attributeData ){return mImpl->begin__usertype__bool1x2();}
		bool _data__usertype__bool1x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool1x2(){return mImpl->end__usertype__bool1x2();}
		bool _validateBegin__usertype__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x2();

		bool _begin__usertype__bool1x3( void* attributeData ){return mImpl->begin__usertype__bool1x3();}
		bool _data__usertype__bool1x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool1x3(){return mImpl->end__usertype__bool1x3();}
		bool _validateBegin__usertype__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x3();

		bool _begin__usertype__bool1x4( void* attributeData ){return mImpl->begin__usertype__bool1x4();}
		bool _data__usertype__bool1x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool1x4(){return mImpl->end__usertype__bool1x4();}
		bool _validateBegin__usertype__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool1x4();

		bool _begin__usertype__bool2x1( void* attributeData ){return mImpl->begin__usertype__bool2x1();}
		bool _data__usertype__bool2x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool2x1(){return mImpl->end__usertype__bool2x1();}
		bool _validateBegin__usertype__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x1();

		bool _begin__usertype__bool2x2( void* attributeData ){return mImpl->begin__usertype__bool2x2();}
		bool _data__usertype__bool2x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool2x2(){return mImpl->end__usertype__bool2x2();}
		bool _validateBegin__usertype__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x2();

		bool _begin__usertype__bool2x3( void* attributeData ){return mImpl->begin__usertype__bool2x3();}
		bool _data__usertype__bool2x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool2x3(){return mImpl->end__usertype__bool2x3();}
		bool _validateBegin__usertype__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x3();

		bool _begin__usertype__bool2x4( void* attributeData ){return mImpl->begin__usertype__bool2x4();}
		bool _data__usertype__bool2x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool2x4(){return mImpl->end__usertype__bool2x4();}
		bool _validateBegin__usertype__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool2x4();

		bool _begin__usertype__bool3x1( void* attributeData ){return mImpl->begin__usertype__bool3x1();}
		bool _data__usertype__bool3x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool3x1(){return mImpl->end__usertype__bool3x1();}
		bool _validateBegin__usertype__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x1();

		bool _begin__usertype__bool3x2( void* attributeData ){return mImpl->begin__usertype__bool3x2();}
		bool _data__usertype__bool3x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool3x2(){return mImpl->end__usertype__bool3x2();}
		bool _validateBegin__usertype__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x2();

		bool _begin__usertype__bool3x3( void* attributeData ){return mImpl->begin__usertype__bool3x3();}
		bool _data__usertype__bool3x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool3x3(){return mImpl->end__usertype__bool3x3();}
		bool _validateBegin__usertype__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x3();

		bool _begin__usertype__bool3x4( void* attributeData ){return mImpl->begin__usertype__bool3x4();}
		bool _data__usertype__bool3x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool3x4(){return mImpl->end__usertype__bool3x4();}
		bool _validateBegin__usertype__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool3x4();

		bool _begin__usertype__bool4x1( void* attributeData ){return mImpl->begin__usertype__bool4x1();}
		bool _data__usertype__bool4x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool4x1(){return mImpl->end__usertype__bool4x1();}
		bool _validateBegin__usertype__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x1();

		bool _begin__usertype__bool4x2( void* attributeData ){return mImpl->begin__usertype__bool4x2();}
		bool _data__usertype__bool4x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool4x2(){return mImpl->end__usertype__bool4x2();}
		bool _validateBegin__usertype__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x2();

		bool _begin__usertype__bool4x3( void* attributeData ){return mImpl->begin__usertype__bool4x3();}
		bool _data__usertype__bool4x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool4x3(){return mImpl->end__usertype__bool4x3();}
		bool _validateBegin__usertype__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x3();

		bool _begin__usertype__bool4x4( void* attributeData ){return mImpl->begin__usertype__bool4x4();}
		bool _data__usertype__bool4x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__bool4x4(){return mImpl->end__usertype__bool4x4();}
		bool _validateBegin__usertype__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__bool4x4();

		bool _begin__usertype__float( void* attributeData ){return mImpl->begin__usertype__float();}
		bool _data__usertype__float( const ParserChar* text, size_t textLength );
		bool _end__usertype__float(){return mImpl->end__usertype__float();}
		bool _validateBegin__usertype__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float();

		bool _begin__usertype__float1( void* attributeData ){return mImpl->begin__usertype__float1();}
		bool _data__usertype__float1( const ParserChar* text, size_t textLength );
		bool _end__usertype__float1(){return mImpl->end__usertype__float1();}
		bool _validateBegin__usertype__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1();

		bool _begin__usertype__float2( void* attributeData ){return mImpl->begin__usertype__float2();}
		bool _data__usertype__float2( const ParserChar* text, size_t textLength );
		bool _end__usertype__float2(){return mImpl->end__usertype__float2();}
		bool _validateBegin__usertype__float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2();

		bool _begin__usertype__float3( void* attributeData ){return mImpl->begin__usertype__float3();}
		bool _data__usertype__float3( const ParserChar* text, size_t textLength );
		bool _end__usertype__float3(){return mImpl->end__usertype__float3();}
		bool _validateBegin__usertype__float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3();

		bool _begin__usertype__float4( void* attributeData ){return mImpl->begin__usertype__float4();}
		bool _data__usertype__float4( const ParserChar* text, size_t textLength );
		bool _end__usertype__float4(){return mImpl->end__usertype__float4();}
		bool _validateBegin__usertype__float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4();

		bool _begin__usertype__float1x1( void* attributeData ){return mImpl->begin__usertype__float1x1();}
		bool _data__usertype__float1x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__float1x1(){return mImpl->end__usertype__float1x1();}
		bool _validateBegin__usertype__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x1();

		bool _begin__usertype__float1x2( void* attributeData ){return mImpl->begin__usertype__float1x2();}
		bool _data__usertype__float1x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__float1x2(){return mImpl->end__usertype__float1x2();}
		bool _validateBegin__usertype__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x2();

		bool _begin__usertype__float1x3( void* attributeData ){return mImpl->begin__usertype__float1x3();}
		bool _data__usertype__float1x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__float1x3(){return mImpl->end__usertype__float1x3();}
		bool _validateBegin__usertype__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x3();

		bool _begin__usertype__float1x4( void* attributeData ){return mImpl->begin__usertype__float1x4();}
		bool _data__usertype__float1x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__float1x4(){return mImpl->end__usertype__float1x4();}
		bool _validateBegin__usertype__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float1x4();

		bool _begin__usertype__float2x1( void* attributeData ){return mImpl->begin__usertype__float2x1();}
		bool _data__usertype__float2x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__float2x1(){return mImpl->end__usertype__float2x1();}
		bool _validateBegin__usertype__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x1();

		bool _begin__usertype__float2x2( void* attributeData ){return mImpl->begin__usertype__float2x2();}
		bool _data__usertype__float2x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__float2x2(){return mImpl->end__usertype__float2x2();}
		bool _validateBegin__usertype__float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x2();

		bool _begin__usertype__float2x3( void* attributeData ){return mImpl->begin__usertype__float2x3();}
		bool _data__usertype__float2x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__float2x3(){return mImpl->end__usertype__float2x3();}
		bool _validateBegin__usertype__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x3();

		bool _begin__usertype__float2x4( void* attributeData ){return mImpl->begin__usertype__float2x4();}
		bool _data__usertype__float2x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__float2x4(){return mImpl->end__usertype__float2x4();}
		bool _validateBegin__usertype__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float2x4();

		bool _begin__usertype__float3x1( void* attributeData ){return mImpl->begin__usertype__float3x1();}
		bool _data__usertype__float3x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__float3x1(){return mImpl->end__usertype__float3x1();}
		bool _validateBegin__usertype__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x1();

		bool _begin__usertype__float3x2( void* attributeData ){return mImpl->begin__usertype__float3x2();}
		bool _data__usertype__float3x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__float3x2(){return mImpl->end__usertype__float3x2();}
		bool _validateBegin__usertype__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x2();

		bool _begin__usertype__float3x3( void* attributeData ){return mImpl->begin__usertype__float3x3();}
		bool _data__usertype__float3x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__float3x3(){return mImpl->end__usertype__float3x3();}
		bool _validateBegin__usertype__float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x3();

		bool _begin__usertype__float3x4( void* attributeData ){return mImpl->begin__usertype__float3x4();}
		bool _data__usertype__float3x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__float3x4(){return mImpl->end__usertype__float3x4();}
		bool _validateBegin__usertype__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float3x4();

		bool _begin__usertype__float4x1( void* attributeData ){return mImpl->begin__usertype__float4x1();}
		bool _data__usertype__float4x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__float4x1(){return mImpl->end__usertype__float4x1();}
		bool _validateBegin__usertype__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x1();

		bool _begin__usertype__float4x2( void* attributeData ){return mImpl->begin__usertype__float4x2();}
		bool _data__usertype__float4x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__float4x2(){return mImpl->end__usertype__float4x2();}
		bool _validateBegin__usertype__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x2();

		bool _begin__usertype__float4x3( void* attributeData ){return mImpl->begin__usertype__float4x3();}
		bool _data__usertype__float4x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__float4x3(){return mImpl->end__usertype__float4x3();}
		bool _validateBegin__usertype__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x3();

		bool _begin__usertype__float4x4( void* attributeData ){return mImpl->begin__usertype__float4x4();}
		bool _data__usertype__float4x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__float4x4(){return mImpl->end__usertype__float4x4();}
		bool _validateBegin__usertype__float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__float4x4();

		bool _begin__usertype__int( void* attributeData ){return mImpl->begin__usertype__int();}
		bool _data__usertype__int( const ParserChar* text, size_t textLength );
		bool _end__usertype__int(){return mImpl->end__usertype__int();}
		bool _validateBegin__usertype__int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int();

		bool _begin__usertype__int1( void* attributeData ){return mImpl->begin__usertype__int1();}
		bool _data__usertype__int1( const ParserChar* text, size_t textLength );
		bool _end__usertype__int1(){return mImpl->end__usertype__int1();}
		bool _validateBegin__usertype__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1();

		bool _begin__usertype__int2( void* attributeData ){return mImpl->begin__usertype__int2();}
		bool _data__usertype__int2( const ParserChar* text, size_t textLength );
		bool _end__usertype__int2(){return mImpl->end__usertype__int2();}
		bool _validateBegin__usertype__int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2();

		bool _begin__usertype__int3( void* attributeData ){return mImpl->begin__usertype__int3();}
		bool _data__usertype__int3( const ParserChar* text, size_t textLength );
		bool _end__usertype__int3(){return mImpl->end__usertype__int3();}
		bool _validateBegin__usertype__int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3();

		bool _begin__usertype__int4( void* attributeData ){return mImpl->begin__usertype__int4();}
		bool _data__usertype__int4( const ParserChar* text, size_t textLength );
		bool _end__usertype__int4(){return mImpl->end__usertype__int4();}
		bool _validateBegin__usertype__int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4();

		bool _begin__usertype__int1x1( void* attributeData ){return mImpl->begin__usertype__int1x1();}
		bool _data__usertype__int1x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__int1x1(){return mImpl->end__usertype__int1x1();}
		bool _validateBegin__usertype__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x1();

		bool _begin__usertype__int1x2( void* attributeData ){return mImpl->begin__usertype__int1x2();}
		bool _data__usertype__int1x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__int1x2(){return mImpl->end__usertype__int1x2();}
		bool _validateBegin__usertype__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x2();

		bool _begin__usertype__int1x3( void* attributeData ){return mImpl->begin__usertype__int1x3();}
		bool _data__usertype__int1x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__int1x3(){return mImpl->end__usertype__int1x3();}
		bool _validateBegin__usertype__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x3();

		bool _begin__usertype__int1x4( void* attributeData ){return mImpl->begin__usertype__int1x4();}
		bool _data__usertype__int1x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__int1x4(){return mImpl->end__usertype__int1x4();}
		bool _validateBegin__usertype__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int1x4();

		bool _begin__usertype__int2x1( void* attributeData ){return mImpl->begin__usertype__int2x1();}
		bool _data__usertype__int2x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__int2x1(){return mImpl->end__usertype__int2x1();}
		bool _validateBegin__usertype__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x1();

		bool _begin__usertype__int2x2( void* attributeData ){return mImpl->begin__usertype__int2x2();}
		bool _data__usertype__int2x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__int2x2(){return mImpl->end__usertype__int2x2();}
		bool _validateBegin__usertype__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x2();

		bool _begin__usertype__int2x3( void* attributeData ){return mImpl->begin__usertype__int2x3();}
		bool _data__usertype__int2x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__int2x3(){return mImpl->end__usertype__int2x3();}
		bool _validateBegin__usertype__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x3();

		bool _begin__usertype__int2x4( void* attributeData ){return mImpl->begin__usertype__int2x4();}
		bool _data__usertype__int2x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__int2x4(){return mImpl->end__usertype__int2x4();}
		bool _validateBegin__usertype__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int2x4();

		bool _begin__usertype__int3x1( void* attributeData ){return mImpl->begin__usertype__int3x1();}
		bool _data__usertype__int3x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__int3x1(){return mImpl->end__usertype__int3x1();}
		bool _validateBegin__usertype__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x1();

		bool _begin__usertype__int3x2( void* attributeData ){return mImpl->begin__usertype__int3x2();}
		bool _data__usertype__int3x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__int3x2(){return mImpl->end__usertype__int3x2();}
		bool _validateBegin__usertype__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x2();

		bool _begin__usertype__int3x3( void* attributeData ){return mImpl->begin__usertype__int3x3();}
		bool _data__usertype__int3x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__int3x3(){return mImpl->end__usertype__int3x3();}
		bool _validateBegin__usertype__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x3();

		bool _begin__usertype__int3x4( void* attributeData ){return mImpl->begin__usertype__int3x4();}
		bool _data__usertype__int3x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__int3x4(){return mImpl->end__usertype__int3x4();}
		bool _validateBegin__usertype__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int3x4();

		bool _begin__usertype__int4x1( void* attributeData ){return mImpl->begin__usertype__int4x1();}
		bool _data__usertype__int4x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__int4x1(){return mImpl->end__usertype__int4x1();}
		bool _validateBegin__usertype__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x1();

		bool _begin__usertype__int4x2( void* attributeData ){return mImpl->begin__usertype__int4x2();}
		bool _data__usertype__int4x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__int4x2(){return mImpl->end__usertype__int4x2();}
		bool _validateBegin__usertype__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x2();

		bool _begin__usertype__int4x3( void* attributeData ){return mImpl->begin__usertype__int4x3();}
		bool _data__usertype__int4x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__int4x3(){return mImpl->end__usertype__int4x3();}
		bool _validateBegin__usertype__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x3();

		bool _begin__usertype__int4x4( void* attributeData ){return mImpl->begin__usertype__int4x4();}
		bool _data__usertype__int4x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__int4x4(){return mImpl->end__usertype__int4x4();}
		bool _validateBegin__usertype__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__int4x4();

		bool _begin__usertype__half( void* attributeData ){return mImpl->begin__usertype__half();}
		bool _data__usertype__half( const ParserChar* text, size_t textLength );
		bool _end__usertype__half(){return mImpl->end__usertype__half();}
		bool _validateBegin__usertype__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half();

		bool _begin__usertype__half1( void* attributeData ){return mImpl->begin__usertype__half1();}
		bool _data__usertype__half1( const ParserChar* text, size_t textLength );
		bool _end__usertype__half1(){return mImpl->end__usertype__half1();}
		bool _validateBegin__usertype__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1();

		bool _begin__usertype__half2( void* attributeData ){return mImpl->begin__usertype__half2();}
		bool _data__usertype__half2( const ParserChar* text, size_t textLength );
		bool _end__usertype__half2(){return mImpl->end__usertype__half2();}
		bool _validateBegin__usertype__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2();

		bool _begin__usertype__half3( void* attributeData ){return mImpl->begin__usertype__half3();}
		bool _data__usertype__half3( const ParserChar* text, size_t textLength );
		bool _end__usertype__half3(){return mImpl->end__usertype__half3();}
		bool _validateBegin__usertype__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3();

		bool _begin__usertype__half4( void* attributeData ){return mImpl->begin__usertype__half4();}
		bool _data__usertype__half4( const ParserChar* text, size_t textLength );
		bool _end__usertype__half4(){return mImpl->end__usertype__half4();}
		bool _validateBegin__usertype__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4();

		bool _begin__usertype__half1x1( void* attributeData ){return mImpl->begin__usertype__half1x1();}
		bool _data__usertype__half1x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__half1x1(){return mImpl->end__usertype__half1x1();}
		bool _validateBegin__usertype__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x1();

		bool _begin__usertype__half1x2( void* attributeData ){return mImpl->begin__usertype__half1x2();}
		bool _data__usertype__half1x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__half1x2(){return mImpl->end__usertype__half1x2();}
		bool _validateBegin__usertype__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x2();

		bool _begin__usertype__half1x3( void* attributeData ){return mImpl->begin__usertype__half1x3();}
		bool _data__usertype__half1x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__half1x3(){return mImpl->end__usertype__half1x3();}
		bool _validateBegin__usertype__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x3();

		bool _begin__usertype__half1x4( void* attributeData ){return mImpl->begin__usertype__half1x4();}
		bool _data__usertype__half1x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__half1x4(){return mImpl->end__usertype__half1x4();}
		bool _validateBegin__usertype__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half1x4();

		bool _begin__usertype__half2x1( void* attributeData ){return mImpl->begin__usertype__half2x1();}
		bool _data__usertype__half2x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__half2x1(){return mImpl->end__usertype__half2x1();}
		bool _validateBegin__usertype__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x1();

		bool _begin__usertype__half2x2( void* attributeData ){return mImpl->begin__usertype__half2x2();}
		bool _data__usertype__half2x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__half2x2(){return mImpl->end__usertype__half2x2();}
		bool _validateBegin__usertype__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x2();

		bool _begin__usertype__half2x3( void* attributeData ){return mImpl->begin__usertype__half2x3();}
		bool _data__usertype__half2x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__half2x3(){return mImpl->end__usertype__half2x3();}
		bool _validateBegin__usertype__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x3();

		bool _begin__usertype__half2x4( void* attributeData ){return mImpl->begin__usertype__half2x4();}
		bool _data__usertype__half2x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__half2x4(){return mImpl->end__usertype__half2x4();}
		bool _validateBegin__usertype__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half2x4();

		bool _begin__usertype__half3x1( void* attributeData ){return mImpl->begin__usertype__half3x1();}
		bool _data__usertype__half3x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__half3x1(){return mImpl->end__usertype__half3x1();}
		bool _validateBegin__usertype__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x1();

		bool _begin__usertype__half3x2( void* attributeData ){return mImpl->begin__usertype__half3x2();}
		bool _data__usertype__half3x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__half3x2(){return mImpl->end__usertype__half3x2();}
		bool _validateBegin__usertype__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x2();

		bool _begin__usertype__half3x3( void* attributeData ){return mImpl->begin__usertype__half3x3();}
		bool _data__usertype__half3x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__half3x3(){return mImpl->end__usertype__half3x3();}
		bool _validateBegin__usertype__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x3();

		bool _begin__usertype__half3x4( void* attributeData ){return mImpl->begin__usertype__half3x4();}
		bool _data__usertype__half3x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__half3x4(){return mImpl->end__usertype__half3x4();}
		bool _validateBegin__usertype__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half3x4();

		bool _begin__usertype__half4x1( void* attributeData ){return mImpl->begin__usertype__half4x1();}
		bool _data__usertype__half4x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__half4x1(){return mImpl->end__usertype__half4x1();}
		bool _validateBegin__usertype__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x1();

		bool _begin__usertype__half4x2( void* attributeData ){return mImpl->begin__usertype__half4x2();}
		bool _data__usertype__half4x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__half4x2(){return mImpl->end__usertype__half4x2();}
		bool _validateBegin__usertype__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x2();

		bool _begin__usertype__half4x3( void* attributeData ){return mImpl->begin__usertype__half4x3();}
		bool _data__usertype__half4x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__half4x3(){return mImpl->end__usertype__half4x3();}
		bool _validateBegin__usertype__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x3();

		bool _begin__usertype__half4x4( void* attributeData ){return mImpl->begin__usertype__half4x4();}
		bool _data__usertype__half4x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__half4x4(){return mImpl->end__usertype__half4x4();}
		bool _validateBegin__usertype__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__half4x4();

		bool _begin__usertype__fixed( void* attributeData ){return mImpl->begin__usertype__fixed();}
		bool _data__usertype__fixed( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed(){return mImpl->end__usertype__fixed();}
		bool _validateBegin__usertype__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed();

		bool _begin__usertype__fixed1( void* attributeData ){return mImpl->begin__usertype__fixed1();}
		bool _data__usertype__fixed1( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed1(){return mImpl->end__usertype__fixed1();}
		bool _validateBegin__usertype__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1();

		bool _begin__usertype__fixed2( void* attributeData ){return mImpl->begin__usertype__fixed2();}
		bool _data__usertype__fixed2( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed2(){return mImpl->end__usertype__fixed2();}
		bool _validateBegin__usertype__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2();

		bool _begin__usertype__fixed3( void* attributeData ){return mImpl->begin__usertype__fixed3();}
		bool _data__usertype__fixed3( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed3(){return mImpl->end__usertype__fixed3();}
		bool _validateBegin__usertype__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3();

		bool _begin__usertype__fixed4( void* attributeData ){return mImpl->begin__usertype__fixed4();}
		bool _data__usertype__fixed4( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed4(){return mImpl->end__usertype__fixed4();}
		bool _validateBegin__usertype__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4();

		bool _begin__usertype__fixed1x1( void* attributeData ){return mImpl->begin__usertype__fixed1x1();}
		bool _data__usertype__fixed1x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed1x1(){return mImpl->end__usertype__fixed1x1();}
		bool _validateBegin__usertype__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x1();

		bool _begin__usertype__fixed1x2( void* attributeData ){return mImpl->begin__usertype__fixed1x2();}
		bool _data__usertype__fixed1x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed1x2(){return mImpl->end__usertype__fixed1x2();}
		bool _validateBegin__usertype__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x2();

		bool _begin__usertype__fixed1x3( void* attributeData ){return mImpl->begin__usertype__fixed1x3();}
		bool _data__usertype__fixed1x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed1x3(){return mImpl->end__usertype__fixed1x3();}
		bool _validateBegin__usertype__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x3();

		bool _begin__usertype__fixed1x4( void* attributeData ){return mImpl->begin__usertype__fixed1x4();}
		bool _data__usertype__fixed1x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed1x4(){return mImpl->end__usertype__fixed1x4();}
		bool _validateBegin__usertype__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed1x4();

		bool _begin__usertype__fixed2x1( void* attributeData ){return mImpl->begin__usertype__fixed2x1();}
		bool _data__usertype__fixed2x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed2x1(){return mImpl->end__usertype__fixed2x1();}
		bool _validateBegin__usertype__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x1();

		bool _begin__usertype__fixed2x2( void* attributeData ){return mImpl->begin__usertype__fixed2x2();}
		bool _data__usertype__fixed2x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed2x2(){return mImpl->end__usertype__fixed2x2();}
		bool _validateBegin__usertype__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x2();

		bool _begin__usertype__fixed2x3( void* attributeData ){return mImpl->begin__usertype__fixed2x3();}
		bool _data__usertype__fixed2x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed2x3(){return mImpl->end__usertype__fixed2x3();}
		bool _validateBegin__usertype__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x3();

		bool _begin__usertype__fixed2x4( void* attributeData ){return mImpl->begin__usertype__fixed2x4();}
		bool _data__usertype__fixed2x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed2x4(){return mImpl->end__usertype__fixed2x4();}
		bool _validateBegin__usertype__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed2x4();

		bool _begin__usertype__fixed3x1( void* attributeData ){return mImpl->begin__usertype__fixed3x1();}
		bool _data__usertype__fixed3x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed3x1(){return mImpl->end__usertype__fixed3x1();}
		bool _validateBegin__usertype__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x1();

		bool _begin__usertype__fixed3x2( void* attributeData ){return mImpl->begin__usertype__fixed3x2();}
		bool _data__usertype__fixed3x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed3x2(){return mImpl->end__usertype__fixed3x2();}
		bool _validateBegin__usertype__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x2();

		bool _begin__usertype__fixed3x3( void* attributeData ){return mImpl->begin__usertype__fixed3x3();}
		bool _data__usertype__fixed3x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed3x3(){return mImpl->end__usertype__fixed3x3();}
		bool _validateBegin__usertype__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x3();

		bool _begin__usertype__fixed3x4( void* attributeData ){return mImpl->begin__usertype__fixed3x4();}
		bool _data__usertype__fixed3x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed3x4(){return mImpl->end__usertype__fixed3x4();}
		bool _validateBegin__usertype__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed3x4();

		bool _begin__usertype__fixed4x1( void* attributeData ){return mImpl->begin__usertype__fixed4x1();}
		bool _data__usertype__fixed4x1( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed4x1(){return mImpl->end__usertype__fixed4x1();}
		bool _validateBegin__usertype__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x1();

		bool _begin__usertype__fixed4x2( void* attributeData ){return mImpl->begin__usertype__fixed4x2();}
		bool _data__usertype__fixed4x2( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed4x2(){return mImpl->end__usertype__fixed4x2();}
		bool _validateBegin__usertype__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x2();

		bool _begin__usertype__fixed4x3( void* attributeData ){return mImpl->begin__usertype__fixed4x3();}
		bool _data__usertype__fixed4x3( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed4x3(){return mImpl->end__usertype__fixed4x3();}
		bool _validateBegin__usertype__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x3();

		bool _begin__usertype__fixed4x4( void* attributeData ){return mImpl->begin__usertype__fixed4x4();}
		bool _data__usertype__fixed4x4( const ParserChar* text, size_t textLength );
		bool _end__usertype__fixed4x4(){return mImpl->end__usertype__fixed4x4();}
		bool _validateBegin__usertype__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__fixed4x4();

		bool _begin__usertype__surface( void* attributeData ){return mImpl->begin__usertype__surface(*static_cast<usertype__surface__AttributeData*>(attributeData));}
		bool _data__usertype__surface( const ParserChar* text, size_t textLength );
		bool _end__usertype__surface(){return mImpl->end__usertype__surface();}
		bool _validateBegin__usertype__surface( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__surface();

		bool _begin__usertype__sampler1D( void* attributeData ){return mImpl->begin__usertype__sampler1D();}
		bool _data__usertype__sampler1D( const ParserChar* text, size_t textLength );
		bool _end__usertype__sampler1D(){return mImpl->end__usertype__sampler1D();}
		bool _validateBegin__usertype__sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler1D();

		bool _begin__usertype__sampler2D( void* attributeData ){return mImpl->begin__usertype__sampler2D();}
		bool _data__usertype__sampler2D( const ParserChar* text, size_t textLength );
		bool _end__usertype__sampler2D(){return mImpl->end__usertype__sampler2D();}
		bool _validateBegin__usertype__sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler2D();

		bool _begin__usertype__sampler3D( void* attributeData ){return mImpl->begin__usertype__sampler3D();}
		bool _data__usertype__sampler3D( const ParserChar* text, size_t textLength );
		bool _end__usertype__sampler3D(){return mImpl->end__usertype__sampler3D();}
		bool _validateBegin__usertype__sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__sampler3D();

		bool _begin__usertype__samplerRECT( void* attributeData ){return mImpl->begin__usertype__samplerRECT();}
		bool _data__usertype__samplerRECT( const ParserChar* text, size_t textLength );
		bool _end__usertype__samplerRECT(){return mImpl->end__usertype__samplerRECT();}
		bool _validateBegin__usertype__samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerRECT();

		bool _begin__usertype__samplerCUBE( void* attributeData ){return mImpl->begin__usertype__samplerCUBE();}
		bool _data__usertype__samplerCUBE( const ParserChar* text, size_t textLength );
		bool _end__usertype__samplerCUBE(){return mImpl->end__usertype__samplerCUBE();}
		bool _validateBegin__usertype__samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerCUBE();

		bool _begin__usertype__samplerDEPTH( void* attributeData ){return mImpl->begin__usertype__samplerDEPTH();}
		bool _data__usertype__samplerDEPTH( const ParserChar* text, size_t textLength );
		bool _end__usertype__samplerDEPTH(){return mImpl->end__usertype__samplerDEPTH();}
		bool _validateBegin__usertype__samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__samplerDEPTH();

		bool _begin__usertype__string( void* attributeData ){return mImpl->begin__usertype__string();}
		bool _data__usertype__string( const ParserChar* text, size_t textLength );
		bool _end__usertype__string(){return mImpl->end__usertype__string();}
		bool _validateBegin__usertype__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__string();

		bool _begin__usertype__enum( void* attributeData ){return mImpl->begin__usertype__enum();}
		bool _data__usertype__enum( const ParserChar* text, size_t textLength );
		bool _end__usertype__enum(){return mImpl->end__usertype__enum();}
		bool _validateBegin__usertype__enum( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__enum();

		bool _begin__usertype__array( void* attributeData ){return mImpl->begin__usertype__array(*static_cast<usertype__array__AttributeData*>(attributeData));}
		bool _data__usertype__array( const ParserChar* text, size_t textLength );
		bool _end__usertype__array(){return mImpl->end__usertype__array();}
		bool _validateBegin__usertype__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__array();

		bool _begin__array__bool1( void* attributeData ){return mImpl->begin__array__bool1();}
		bool _data__array__bool1( const ParserChar* text, size_t textLength );
		bool _end__array__bool1(){return mImpl->end__array__bool1();}
		bool _validateBegin__array__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1();

		bool _begin__array__bool1x1( void* attributeData ){return mImpl->begin__array__bool1x1();}
		bool _data__array__bool1x1( const ParserChar* text, size_t textLength );
		bool _end__array__bool1x1(){return mImpl->end__array__bool1x1();}
		bool _validateBegin__array__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x1();

		bool _begin__array__bool1x2( void* attributeData ){return mImpl->begin__array__bool1x2();}
		bool _data__array__bool1x2( const ParserChar* text, size_t textLength );
		bool _end__array__bool1x2(){return mImpl->end__array__bool1x2();}
		bool _validateBegin__array__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x2();

		bool _begin__array__bool1x3( void* attributeData ){return mImpl->begin__array__bool1x3();}
		bool _data__array__bool1x3( const ParserChar* text, size_t textLength );
		bool _end__array__bool1x3(){return mImpl->end__array__bool1x3();}
		bool _validateBegin__array__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x3();

		bool _begin__array__bool1x4( void* attributeData ){return mImpl->begin__array__bool1x4();}
		bool _data__array__bool1x4( const ParserChar* text, size_t textLength );
		bool _end__array__bool1x4(){return mImpl->end__array__bool1x4();}
		bool _validateBegin__array__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool1x4();

		bool _begin__array__bool2x1( void* attributeData ){return mImpl->begin__array__bool2x1();}
		bool _data__array__bool2x1( const ParserChar* text, size_t textLength );
		bool _end__array__bool2x1(){return mImpl->end__array__bool2x1();}
		bool _validateBegin__array__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x1();

		bool _begin__array__bool2x2( void* attributeData ){return mImpl->begin__array__bool2x2();}
		bool _data__array__bool2x2( const ParserChar* text, size_t textLength );
		bool _end__array__bool2x2(){return mImpl->end__array__bool2x2();}
		bool _validateBegin__array__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x2();

		bool _begin__array__bool2x3( void* attributeData ){return mImpl->begin__array__bool2x3();}
		bool _data__array__bool2x3( const ParserChar* text, size_t textLength );
		bool _end__array__bool2x3(){return mImpl->end__array__bool2x3();}
		bool _validateBegin__array__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x3();

		bool _begin__array__bool2x4( void* attributeData ){return mImpl->begin__array__bool2x4();}
		bool _data__array__bool2x4( const ParserChar* text, size_t textLength );
		bool _end__array__bool2x4(){return mImpl->end__array__bool2x4();}
		bool _validateBegin__array__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool2x4();

		bool _begin__array__bool3x1( void* attributeData ){return mImpl->begin__array__bool3x1();}
		bool _data__array__bool3x1( const ParserChar* text, size_t textLength );
		bool _end__array__bool3x1(){return mImpl->end__array__bool3x1();}
		bool _validateBegin__array__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x1();

		bool _begin__array__bool3x2( void* attributeData ){return mImpl->begin__array__bool3x2();}
		bool _data__array__bool3x2( const ParserChar* text, size_t textLength );
		bool _end__array__bool3x2(){return mImpl->end__array__bool3x2();}
		bool _validateBegin__array__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x2();

		bool _begin__array__bool3x3( void* attributeData ){return mImpl->begin__array__bool3x3();}
		bool _data__array__bool3x3( const ParserChar* text, size_t textLength );
		bool _end__array__bool3x3(){return mImpl->end__array__bool3x3();}
		bool _validateBegin__array__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x3();

		bool _begin__array__bool3x4( void* attributeData ){return mImpl->begin__array__bool3x4();}
		bool _data__array__bool3x4( const ParserChar* text, size_t textLength );
		bool _end__array__bool3x4(){return mImpl->end__array__bool3x4();}
		bool _validateBegin__array__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool3x4();

		bool _begin__array__bool4x1( void* attributeData ){return mImpl->begin__array__bool4x1();}
		bool _data__array__bool4x1( const ParserChar* text, size_t textLength );
		bool _end__array__bool4x1(){return mImpl->end__array__bool4x1();}
		bool _validateBegin__array__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x1();

		bool _begin__array__bool4x2( void* attributeData ){return mImpl->begin__array__bool4x2();}
		bool _data__array__bool4x2( const ParserChar* text, size_t textLength );
		bool _end__array__bool4x2(){return mImpl->end__array__bool4x2();}
		bool _validateBegin__array__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x2();

		bool _begin__array__bool4x3( void* attributeData ){return mImpl->begin__array__bool4x3();}
		bool _data__array__bool4x3( const ParserChar* text, size_t textLength );
		bool _end__array__bool4x3(){return mImpl->end__array__bool4x3();}
		bool _validateBegin__array__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x3();

		bool _begin__array__bool4x4( void* attributeData ){return mImpl->begin__array__bool4x4();}
		bool _data__array__bool4x4( const ParserChar* text, size_t textLength );
		bool _end__array__bool4x4(){return mImpl->end__array__bool4x4();}
		bool _validateBegin__array__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__bool4x4();

		bool _begin__array__float1( void* attributeData ){return mImpl->begin__array__float1();}
		bool _data__array__float1( const ParserChar* text, size_t textLength );
		bool _end__array__float1(){return mImpl->end__array__float1();}
		bool _validateBegin__array__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1();

		bool _begin__array__float1x1( void* attributeData ){return mImpl->begin__array__float1x1();}
		bool _data__array__float1x1( const ParserChar* text, size_t textLength );
		bool _end__array__float1x1(){return mImpl->end__array__float1x1();}
		bool _validateBegin__array__float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x1();

		bool _begin__array__float1x2( void* attributeData ){return mImpl->begin__array__float1x2();}
		bool _data__array__float1x2( const ParserChar* text, size_t textLength );
		bool _end__array__float1x2(){return mImpl->end__array__float1x2();}
		bool _validateBegin__array__float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x2();

		bool _begin__array__float1x3( void* attributeData ){return mImpl->begin__array__float1x3();}
		bool _data__array__float1x3( const ParserChar* text, size_t textLength );
		bool _end__array__float1x3(){return mImpl->end__array__float1x3();}
		bool _validateBegin__array__float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x3();

		bool _begin__array__float1x4( void* attributeData ){return mImpl->begin__array__float1x4();}
		bool _data__array__float1x4( const ParserChar* text, size_t textLength );
		bool _end__array__float1x4(){return mImpl->end__array__float1x4();}
		bool _validateBegin__array__float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float1x4();

		bool _begin__array__float2x1( void* attributeData ){return mImpl->begin__array__float2x1();}
		bool _data__array__float2x1( const ParserChar* text, size_t textLength );
		bool _end__array__float2x1(){return mImpl->end__array__float2x1();}
		bool _validateBegin__array__float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x1();

		bool _begin__array__float2x3( void* attributeData ){return mImpl->begin__array__float2x3();}
		bool _data__array__float2x3( const ParserChar* text, size_t textLength );
		bool _end__array__float2x3(){return mImpl->end__array__float2x3();}
		bool _validateBegin__array__float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x3();

		bool _begin__array__float2x4( void* attributeData ){return mImpl->begin__array__float2x4();}
		bool _data__array__float2x4( const ParserChar* text, size_t textLength );
		bool _end__array__float2x4(){return mImpl->end__array__float2x4();}
		bool _validateBegin__array__float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float2x4();

		bool _begin__array__float3x1( void* attributeData ){return mImpl->begin__array__float3x1();}
		bool _data__array__float3x1( const ParserChar* text, size_t textLength );
		bool _end__array__float3x1(){return mImpl->end__array__float3x1();}
		bool _validateBegin__array__float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x1();

		bool _begin__array__float3x2( void* attributeData ){return mImpl->begin__array__float3x2();}
		bool _data__array__float3x2( const ParserChar* text, size_t textLength );
		bool _end__array__float3x2(){return mImpl->end__array__float3x2();}
		bool _validateBegin__array__float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x2();

		bool _begin__array__float3x4( void* attributeData ){return mImpl->begin__array__float3x4();}
		bool _data__array__float3x4( const ParserChar* text, size_t textLength );
		bool _end__array__float3x4(){return mImpl->end__array__float3x4();}
		bool _validateBegin__array__float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float3x4();

		bool _begin__array__float4x1( void* attributeData ){return mImpl->begin__array__float4x1();}
		bool _data__array__float4x1( const ParserChar* text, size_t textLength );
		bool _end__array__float4x1(){return mImpl->end__array__float4x1();}
		bool _validateBegin__array__float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x1();

		bool _begin__array__float4x2( void* attributeData ){return mImpl->begin__array__float4x2();}
		bool _data__array__float4x2( const ParserChar* text, size_t textLength );
		bool _end__array__float4x2(){return mImpl->end__array__float4x2();}
		bool _validateBegin__array__float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x2();

		bool _begin__array__float4x3( void* attributeData ){return mImpl->begin__array__float4x3();}
		bool _data__array__float4x3( const ParserChar* text, size_t textLength );
		bool _end__array__float4x3(){return mImpl->end__array__float4x3();}
		bool _validateBegin__array__float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__float4x3();

		bool _begin__array__int1( void* attributeData ){return mImpl->begin__array__int1();}
		bool _data__array__int1( const ParserChar* text, size_t textLength );
		bool _end__array__int1(){return mImpl->end__array__int1();}
		bool _validateBegin__array__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1();

		bool _begin__array__int1x1( void* attributeData ){return mImpl->begin__array__int1x1();}
		bool _data__array__int1x1( const ParserChar* text, size_t textLength );
		bool _end__array__int1x1(){return mImpl->end__array__int1x1();}
		bool _validateBegin__array__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x1();

		bool _begin__array__int1x2( void* attributeData ){return mImpl->begin__array__int1x2();}
		bool _data__array__int1x2( const ParserChar* text, size_t textLength );
		bool _end__array__int1x2(){return mImpl->end__array__int1x2();}
		bool _validateBegin__array__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x2();

		bool _begin__array__int1x3( void* attributeData ){return mImpl->begin__array__int1x3();}
		bool _data__array__int1x3( const ParserChar* text, size_t textLength );
		bool _end__array__int1x3(){return mImpl->end__array__int1x3();}
		bool _validateBegin__array__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x3();

		bool _begin__array__int1x4( void* attributeData ){return mImpl->begin__array__int1x4();}
		bool _data__array__int1x4( const ParserChar* text, size_t textLength );
		bool _end__array__int1x4(){return mImpl->end__array__int1x4();}
		bool _validateBegin__array__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int1x4();

		bool _begin__array__int2x1( void* attributeData ){return mImpl->begin__array__int2x1();}
		bool _data__array__int2x1( const ParserChar* text, size_t textLength );
		bool _end__array__int2x1(){return mImpl->end__array__int2x1();}
		bool _validateBegin__array__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x1();

		bool _begin__array__int2x2( void* attributeData ){return mImpl->begin__array__int2x2();}
		bool _data__array__int2x2( const ParserChar* text, size_t textLength );
		bool _end__array__int2x2(){return mImpl->end__array__int2x2();}
		bool _validateBegin__array__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x2();

		bool _begin__array__int2x3( void* attributeData ){return mImpl->begin__array__int2x3();}
		bool _data__array__int2x3( const ParserChar* text, size_t textLength );
		bool _end__array__int2x3(){return mImpl->end__array__int2x3();}
		bool _validateBegin__array__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x3();

		bool _begin__array__int2x4( void* attributeData ){return mImpl->begin__array__int2x4();}
		bool _data__array__int2x4( const ParserChar* text, size_t textLength );
		bool _end__array__int2x4(){return mImpl->end__array__int2x4();}
		bool _validateBegin__array__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int2x4();

		bool _begin__array__int3x1( void* attributeData ){return mImpl->begin__array__int3x1();}
		bool _data__array__int3x1( const ParserChar* text, size_t textLength );
		bool _end__array__int3x1(){return mImpl->end__array__int3x1();}
		bool _validateBegin__array__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x1();

		bool _begin__array__int3x2( void* attributeData ){return mImpl->begin__array__int3x2();}
		bool _data__array__int3x2( const ParserChar* text, size_t textLength );
		bool _end__array__int3x2(){return mImpl->end__array__int3x2();}
		bool _validateBegin__array__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x2();

		bool _begin__array__int3x3( void* attributeData ){return mImpl->begin__array__int3x3();}
		bool _data__array__int3x3( const ParserChar* text, size_t textLength );
		bool _end__array__int3x3(){return mImpl->end__array__int3x3();}
		bool _validateBegin__array__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x3();

		bool _begin__array__int3x4( void* attributeData ){return mImpl->begin__array__int3x4();}
		bool _data__array__int3x4( const ParserChar* text, size_t textLength );
		bool _end__array__int3x4(){return mImpl->end__array__int3x4();}
		bool _validateBegin__array__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int3x4();

		bool _begin__array__int4x1( void* attributeData ){return mImpl->begin__array__int4x1();}
		bool _data__array__int4x1( const ParserChar* text, size_t textLength );
		bool _end__array__int4x1(){return mImpl->end__array__int4x1();}
		bool _validateBegin__array__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x1();

		bool _begin__array__int4x2( void* attributeData ){return mImpl->begin__array__int4x2();}
		bool _data__array__int4x2( const ParserChar* text, size_t textLength );
		bool _end__array__int4x2(){return mImpl->end__array__int4x2();}
		bool _validateBegin__array__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x2();

		bool _begin__array__int4x3( void* attributeData ){return mImpl->begin__array__int4x3();}
		bool _data__array__int4x3( const ParserChar* text, size_t textLength );
		bool _end__array__int4x3(){return mImpl->end__array__int4x3();}
		bool _validateBegin__array__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x3();

		bool _begin__array__int4x4( void* attributeData ){return mImpl->begin__array__int4x4();}
		bool _data__array__int4x4( const ParserChar* text, size_t textLength );
		bool _end__array__int4x4(){return mImpl->end__array__int4x4();}
		bool _validateBegin__array__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__int4x4();

		bool _begin__array__half( void* attributeData ){return mImpl->begin__array__half();}
		bool _data__array__half( const ParserChar* text, size_t textLength );
		bool _end__array__half(){return mImpl->end__array__half();}
		bool _validateBegin__array__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half();

		bool _begin__array__half1( void* attributeData ){return mImpl->begin__array__half1();}
		bool _data__array__half1( const ParserChar* text, size_t textLength );
		bool _end__array__half1(){return mImpl->end__array__half1();}
		bool _validateBegin__array__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1();

		bool _begin__array__half2( void* attributeData ){return mImpl->begin__array__half2();}
		bool _data__array__half2( const ParserChar* text, size_t textLength );
		bool _end__array__half2(){return mImpl->end__array__half2();}
		bool _validateBegin__array__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2();

		bool _begin__array__half3( void* attributeData ){return mImpl->begin__array__half3();}
		bool _data__array__half3( const ParserChar* text, size_t textLength );
		bool _end__array__half3(){return mImpl->end__array__half3();}
		bool _validateBegin__array__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3();

		bool _begin__array__half4( void* attributeData ){return mImpl->begin__array__half4();}
		bool _data__array__half4( const ParserChar* text, size_t textLength );
		bool _end__array__half4(){return mImpl->end__array__half4();}
		bool _validateBegin__array__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4();

		bool _begin__array__half1x1( void* attributeData ){return mImpl->begin__array__half1x1();}
		bool _data__array__half1x1( const ParserChar* text, size_t textLength );
		bool _end__array__half1x1(){return mImpl->end__array__half1x1();}
		bool _validateBegin__array__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x1();

		bool _begin__array__half1x2( void* attributeData ){return mImpl->begin__array__half1x2();}
		bool _data__array__half1x2( const ParserChar* text, size_t textLength );
		bool _end__array__half1x2(){return mImpl->end__array__half1x2();}
		bool _validateBegin__array__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x2();

		bool _begin__array__half1x3( void* attributeData ){return mImpl->begin__array__half1x3();}
		bool _data__array__half1x3( const ParserChar* text, size_t textLength );
		bool _end__array__half1x3(){return mImpl->end__array__half1x3();}
		bool _validateBegin__array__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x3();

		bool _begin__array__half1x4( void* attributeData ){return mImpl->begin__array__half1x4();}
		bool _data__array__half1x4( const ParserChar* text, size_t textLength );
		bool _end__array__half1x4(){return mImpl->end__array__half1x4();}
		bool _validateBegin__array__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half1x4();

		bool _begin__array__half2x1( void* attributeData ){return mImpl->begin__array__half2x1();}
		bool _data__array__half2x1( const ParserChar* text, size_t textLength );
		bool _end__array__half2x1(){return mImpl->end__array__half2x1();}
		bool _validateBegin__array__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x1();

		bool _begin__array__half2x2( void* attributeData ){return mImpl->begin__array__half2x2();}
		bool _data__array__half2x2( const ParserChar* text, size_t textLength );
		bool _end__array__half2x2(){return mImpl->end__array__half2x2();}
		bool _validateBegin__array__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x2();

		bool _begin__array__half2x3( void* attributeData ){return mImpl->begin__array__half2x3();}
		bool _data__array__half2x3( const ParserChar* text, size_t textLength );
		bool _end__array__half2x3(){return mImpl->end__array__half2x3();}
		bool _validateBegin__array__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x3();

		bool _begin__array__half2x4( void* attributeData ){return mImpl->begin__array__half2x4();}
		bool _data__array__half2x4( const ParserChar* text, size_t textLength );
		bool _end__array__half2x4(){return mImpl->end__array__half2x4();}
		bool _validateBegin__array__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half2x4();

		bool _begin__array__half3x1( void* attributeData ){return mImpl->begin__array__half3x1();}
		bool _data__array__half3x1( const ParserChar* text, size_t textLength );
		bool _end__array__half3x1(){return mImpl->end__array__half3x1();}
		bool _validateBegin__array__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x1();

		bool _begin__array__half3x2( void* attributeData ){return mImpl->begin__array__half3x2();}
		bool _data__array__half3x2( const ParserChar* text, size_t textLength );
		bool _end__array__half3x2(){return mImpl->end__array__half3x2();}
		bool _validateBegin__array__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x2();

		bool _begin__array__half3x3( void* attributeData ){return mImpl->begin__array__half3x3();}
		bool _data__array__half3x3( const ParserChar* text, size_t textLength );
		bool _end__array__half3x3(){return mImpl->end__array__half3x3();}
		bool _validateBegin__array__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x3();

		bool _begin__array__half3x4( void* attributeData ){return mImpl->begin__array__half3x4();}
		bool _data__array__half3x4( const ParserChar* text, size_t textLength );
		bool _end__array__half3x4(){return mImpl->end__array__half3x4();}
		bool _validateBegin__array__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half3x4();

		bool _begin__array__half4x1( void* attributeData ){return mImpl->begin__array__half4x1();}
		bool _data__array__half4x1( const ParserChar* text, size_t textLength );
		bool _end__array__half4x1(){return mImpl->end__array__half4x1();}
		bool _validateBegin__array__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x1();

		bool _begin__array__half4x2( void* attributeData ){return mImpl->begin__array__half4x2();}
		bool _data__array__half4x2( const ParserChar* text, size_t textLength );
		bool _end__array__half4x2(){return mImpl->end__array__half4x2();}
		bool _validateBegin__array__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x2();

		bool _begin__array__half4x3( void* attributeData ){return mImpl->begin__array__half4x3();}
		bool _data__array__half4x3( const ParserChar* text, size_t textLength );
		bool _end__array__half4x3(){return mImpl->end__array__half4x3();}
		bool _validateBegin__array__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x3();

		bool _begin__array__half4x4( void* attributeData ){return mImpl->begin__array__half4x4();}
		bool _data__array__half4x4( const ParserChar* text, size_t textLength );
		bool _end__array__half4x4(){return mImpl->end__array__half4x4();}
		bool _validateBegin__array__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__half4x4();

		bool _begin__array__fixed( void* attributeData ){return mImpl->begin__array__fixed();}
		bool _data__array__fixed( const ParserChar* text, size_t textLength );
		bool _end__array__fixed(){return mImpl->end__array__fixed();}
		bool _validateBegin__array__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed();

		bool _begin__array__fixed1( void* attributeData ){return mImpl->begin__array__fixed1();}
		bool _data__array__fixed1( const ParserChar* text, size_t textLength );
		bool _end__array__fixed1(){return mImpl->end__array__fixed1();}
		bool _validateBegin__array__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1();

		bool _begin__array__fixed2( void* attributeData ){return mImpl->begin__array__fixed2();}
		bool _data__array__fixed2( const ParserChar* text, size_t textLength );
		bool _end__array__fixed2(){return mImpl->end__array__fixed2();}
		bool _validateBegin__array__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2();

		bool _begin__array__fixed3( void* attributeData ){return mImpl->begin__array__fixed3();}
		bool _data__array__fixed3( const ParserChar* text, size_t textLength );
		bool _end__array__fixed3(){return mImpl->end__array__fixed3();}
		bool _validateBegin__array__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3();

		bool _begin__array__fixed4( void* attributeData ){return mImpl->begin__array__fixed4();}
		bool _data__array__fixed4( const ParserChar* text, size_t textLength );
		bool _end__array__fixed4(){return mImpl->end__array__fixed4();}
		bool _validateBegin__array__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4();

		bool _begin__array__fixed1x1( void* attributeData ){return mImpl->begin__array__fixed1x1();}
		bool _data__array__fixed1x1( const ParserChar* text, size_t textLength );
		bool _end__array__fixed1x1(){return mImpl->end__array__fixed1x1();}
		bool _validateBegin__array__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x1();

		bool _begin__array__fixed1x2( void* attributeData ){return mImpl->begin__array__fixed1x2();}
		bool _data__array__fixed1x2( const ParserChar* text, size_t textLength );
		bool _end__array__fixed1x2(){return mImpl->end__array__fixed1x2();}
		bool _validateBegin__array__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x2();

		bool _begin__array__fixed1x3( void* attributeData ){return mImpl->begin__array__fixed1x3();}
		bool _data__array__fixed1x3( const ParserChar* text, size_t textLength );
		bool _end__array__fixed1x3(){return mImpl->end__array__fixed1x3();}
		bool _validateBegin__array__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x3();

		bool _begin__array__fixed1x4( void* attributeData ){return mImpl->begin__array__fixed1x4();}
		bool _data__array__fixed1x4( const ParserChar* text, size_t textLength );
		bool _end__array__fixed1x4(){return mImpl->end__array__fixed1x4();}
		bool _validateBegin__array__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed1x4();

		bool _begin__array__fixed2x1( void* attributeData ){return mImpl->begin__array__fixed2x1();}
		bool _data__array__fixed2x1( const ParserChar* text, size_t textLength );
		bool _end__array__fixed2x1(){return mImpl->end__array__fixed2x1();}
		bool _validateBegin__array__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x1();

		bool _begin__array__fixed2x2( void* attributeData ){return mImpl->begin__array__fixed2x2();}
		bool _data__array__fixed2x2( const ParserChar* text, size_t textLength );
		bool _end__array__fixed2x2(){return mImpl->end__array__fixed2x2();}
		bool _validateBegin__array__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x2();

		bool _begin__array__fixed2x3( void* attributeData ){return mImpl->begin__array__fixed2x3();}
		bool _data__array__fixed2x3( const ParserChar* text, size_t textLength );
		bool _end__array__fixed2x3(){return mImpl->end__array__fixed2x3();}
		bool _validateBegin__array__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x3();

		bool _begin__array__fixed2x4( void* attributeData ){return mImpl->begin__array__fixed2x4();}
		bool _data__array__fixed2x4( const ParserChar* text, size_t textLength );
		bool _end__array__fixed2x4(){return mImpl->end__array__fixed2x4();}
		bool _validateBegin__array__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed2x4();

		bool _begin__array__fixed3x1( void* attributeData ){return mImpl->begin__array__fixed3x1();}
		bool _data__array__fixed3x1( const ParserChar* text, size_t textLength );
		bool _end__array__fixed3x1(){return mImpl->end__array__fixed3x1();}
		bool _validateBegin__array__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x1();

		bool _begin__array__fixed3x2( void* attributeData ){return mImpl->begin__array__fixed3x2();}
		bool _data__array__fixed3x2( const ParserChar* text, size_t textLength );
		bool _end__array__fixed3x2(){return mImpl->end__array__fixed3x2();}
		bool _validateBegin__array__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x2();

		bool _begin__array__fixed3x3( void* attributeData ){return mImpl->begin__array__fixed3x3();}
		bool _data__array__fixed3x3( const ParserChar* text, size_t textLength );
		bool _end__array__fixed3x3(){return mImpl->end__array__fixed3x3();}
		bool _validateBegin__array__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x3();

		bool _begin__array__fixed3x4( void* attributeData ){return mImpl->begin__array__fixed3x4();}
		bool _data__array__fixed3x4( const ParserChar* text, size_t textLength );
		bool _end__array__fixed3x4(){return mImpl->end__array__fixed3x4();}
		bool _validateBegin__array__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed3x4();

		bool _begin__array__fixed4x1( void* attributeData ){return mImpl->begin__array__fixed4x1();}
		bool _data__array__fixed4x1( const ParserChar* text, size_t textLength );
		bool _end__array__fixed4x1(){return mImpl->end__array__fixed4x1();}
		bool _validateBegin__array__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x1();

		bool _begin__array__fixed4x2( void* attributeData ){return mImpl->begin__array__fixed4x2();}
		bool _data__array__fixed4x2( const ParserChar* text, size_t textLength );
		bool _end__array__fixed4x2(){return mImpl->end__array__fixed4x2();}
		bool _validateBegin__array__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x2();

		bool _begin__array__fixed4x3( void* attributeData ){return mImpl->begin__array__fixed4x3();}
		bool _data__array__fixed4x3( const ParserChar* text, size_t textLength );
		bool _end__array__fixed4x3(){return mImpl->end__array__fixed4x3();}
		bool _validateBegin__array__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x3();

		bool _begin__array__fixed4x4( void* attributeData ){return mImpl->begin__array__fixed4x4();}
		bool _data__array__fixed4x4( const ParserChar* text, size_t textLength );
		bool _end__array__fixed4x4(){return mImpl->end__array__fixed4x4();}
		bool _validateBegin__array__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__fixed4x4();

		bool _begin__array__string( void* attributeData ){return mImpl->begin__array__string();}
		bool _data__array__string( const ParserChar* text, size_t textLength );
		bool _end__array__string(){return mImpl->end__array__string();}
		bool _validateBegin__array__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__string();

		bool _begin__array__usertype( void* attributeData ){return mImpl->begin__array__usertype(*static_cast<array__usertype__AttributeData*>(attributeData));}
		bool _data__array__usertype( const ParserChar* text, size_t textLength );
		bool _end__array__usertype(){return mImpl->end__array__usertype();}
		bool _validateBegin__array__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__array__usertype();

		bool _begin__usertype__usertype( void* attributeData ){return mImpl->begin__usertype__usertype(*static_cast<usertype__usertype__AttributeData*>(attributeData));}
		bool _data__usertype__usertype( const ParserChar* text, size_t textLength );
		bool _end__usertype__usertype(){return mImpl->end__usertype__usertype();}
		bool _validateBegin__usertype__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__usertype();

		bool _begin__usertype__connect_param( void* attributeData ){return mImpl->begin__usertype__connect_param(*static_cast<usertype__connect_param__AttributeData*>(attributeData));}
		bool _data__usertype__connect_param( const ParserChar* text, size_t textLength );
		bool _end__usertype__connect_param(){return mImpl->end__usertype__connect_param();}
		bool _validateBegin__usertype__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__connect_param();

		bool _begin__usertype__setparam( void* attributeData ){return mImpl->begin__usertype__setparam(*static_cast<usertype__setparam__AttributeData*>(attributeData));}
		bool _data__usertype__setparam( const ParserChar* text, size_t textLength );
		bool _end__usertype__setparam(){return mImpl->end__usertype__setparam();}
		bool _validateBegin__usertype__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__usertype__setparam();

		bool _begin__setparam__bool1( void* attributeData ){return mImpl->begin__setparam__bool1();}
		bool _data__setparam__bool1( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool1(){return mImpl->end__setparam__bool1();}
		bool _validateBegin__setparam__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1();

		bool _begin__setparam__bool1x1( void* attributeData ){return mImpl->begin__setparam__bool1x1();}
		bool _data__setparam__bool1x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool1x1(){return mImpl->end__setparam__bool1x1();}
		bool _validateBegin__setparam__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x1();

		bool _begin__setparam__bool1x2( void* attributeData ){return mImpl->begin__setparam__bool1x2();}
		bool _data__setparam__bool1x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool1x2(){return mImpl->end__setparam__bool1x2();}
		bool _validateBegin__setparam__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x2();

		bool _begin__setparam__bool1x3( void* attributeData ){return mImpl->begin__setparam__bool1x3();}
		bool _data__setparam__bool1x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool1x3(){return mImpl->end__setparam__bool1x3();}
		bool _validateBegin__setparam__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x3();

		bool _begin__setparam__bool1x4( void* attributeData ){return mImpl->begin__setparam__bool1x4();}
		bool _data__setparam__bool1x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool1x4(){return mImpl->end__setparam__bool1x4();}
		bool _validateBegin__setparam__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool1x4();

		bool _begin__setparam__bool2x1( void* attributeData ){return mImpl->begin__setparam__bool2x1();}
		bool _data__setparam__bool2x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool2x1(){return mImpl->end__setparam__bool2x1();}
		bool _validateBegin__setparam__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x1();

		bool _begin__setparam__bool2x2( void* attributeData ){return mImpl->begin__setparam__bool2x2();}
		bool _data__setparam__bool2x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool2x2(){return mImpl->end__setparam__bool2x2();}
		bool _validateBegin__setparam__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x2();

		bool _begin__setparam__bool2x3( void* attributeData ){return mImpl->begin__setparam__bool2x3();}
		bool _data__setparam__bool2x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool2x3(){return mImpl->end__setparam__bool2x3();}
		bool _validateBegin__setparam__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x3();

		bool _begin__setparam__bool2x4( void* attributeData ){return mImpl->begin__setparam__bool2x4();}
		bool _data__setparam__bool2x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool2x4(){return mImpl->end__setparam__bool2x4();}
		bool _validateBegin__setparam__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool2x4();

		bool _begin__setparam__bool3x1( void* attributeData ){return mImpl->begin__setparam__bool3x1();}
		bool _data__setparam__bool3x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool3x1(){return mImpl->end__setparam__bool3x1();}
		bool _validateBegin__setparam__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x1();

		bool _begin__setparam__bool3x2( void* attributeData ){return mImpl->begin__setparam__bool3x2();}
		bool _data__setparam__bool3x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool3x2(){return mImpl->end__setparam__bool3x2();}
		bool _validateBegin__setparam__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x2();

		bool _begin__setparam__bool3x3( void* attributeData ){return mImpl->begin__setparam__bool3x3();}
		bool _data__setparam__bool3x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool3x3(){return mImpl->end__setparam__bool3x3();}
		bool _validateBegin__setparam__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x3();

		bool _begin__setparam__bool3x4( void* attributeData ){return mImpl->begin__setparam__bool3x4();}
		bool _data__setparam__bool3x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool3x4(){return mImpl->end__setparam__bool3x4();}
		bool _validateBegin__setparam__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool3x4();

		bool _begin__setparam__bool4x1( void* attributeData ){return mImpl->begin__setparam__bool4x1();}
		bool _data__setparam__bool4x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool4x1(){return mImpl->end__setparam__bool4x1();}
		bool _validateBegin__setparam__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x1();

		bool _begin__setparam__bool4x2( void* attributeData ){return mImpl->begin__setparam__bool4x2();}
		bool _data__setparam__bool4x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool4x2(){return mImpl->end__setparam__bool4x2();}
		bool _validateBegin__setparam__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x2();

		bool _begin__setparam__bool4x3( void* attributeData ){return mImpl->begin__setparam__bool4x3();}
		bool _data__setparam__bool4x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool4x3(){return mImpl->end__setparam__bool4x3();}
		bool _validateBegin__setparam__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x3();

		bool _begin__setparam__bool4x4( void* attributeData ){return mImpl->begin__setparam__bool4x4();}
		bool _data__setparam__bool4x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__bool4x4(){return mImpl->end__setparam__bool4x4();}
		bool _validateBegin__setparam__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__bool4x4();

		bool _begin__setparam__float1( void* attributeData ){return mImpl->begin__setparam__float1();}
		bool _data__setparam__float1( const ParserChar* text, size_t textLength );
		bool _end__setparam__float1(){return mImpl->end__setparam__float1();}
		bool _validateBegin__setparam__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__float1();

		bool _begin__setparam__int1( void* attributeData ){return mImpl->begin__setparam__int1();}
		bool _data__setparam__int1( const ParserChar* text, size_t textLength );
		bool _end__setparam__int1(){return mImpl->end__setparam__int1();}
		bool _validateBegin__setparam__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1();

		bool _begin__setparam__int1x1( void* attributeData ){return mImpl->begin__setparam__int1x1();}
		bool _data__setparam__int1x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__int1x1(){return mImpl->end__setparam__int1x1();}
		bool _validateBegin__setparam__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x1();

		bool _begin__setparam__int1x2( void* attributeData ){return mImpl->begin__setparam__int1x2();}
		bool _data__setparam__int1x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__int1x2(){return mImpl->end__setparam__int1x2();}
		bool _validateBegin__setparam__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x2();

		bool _begin__setparam__int1x3( void* attributeData ){return mImpl->begin__setparam__int1x3();}
		bool _data__setparam__int1x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__int1x3(){return mImpl->end__setparam__int1x3();}
		bool _validateBegin__setparam__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x3();

		bool _begin__setparam__int1x4( void* attributeData ){return mImpl->begin__setparam__int1x4();}
		bool _data__setparam__int1x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__int1x4(){return mImpl->end__setparam__int1x4();}
		bool _validateBegin__setparam__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int1x4();

		bool _begin__setparam__int2x1( void* attributeData ){return mImpl->begin__setparam__int2x1();}
		bool _data__setparam__int2x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__int2x1(){return mImpl->end__setparam__int2x1();}
		bool _validateBegin__setparam__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x1();

		bool _begin__setparam__int2x2( void* attributeData ){return mImpl->begin__setparam__int2x2();}
		bool _data__setparam__int2x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__int2x2(){return mImpl->end__setparam__int2x2();}
		bool _validateBegin__setparam__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x2();

		bool _begin__setparam__int2x3( void* attributeData ){return mImpl->begin__setparam__int2x3();}
		bool _data__setparam__int2x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__int2x3(){return mImpl->end__setparam__int2x3();}
		bool _validateBegin__setparam__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x3();

		bool _begin__setparam__int2x4( void* attributeData ){return mImpl->begin__setparam__int2x4();}
		bool _data__setparam__int2x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__int2x4(){return mImpl->end__setparam__int2x4();}
		bool _validateBegin__setparam__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int2x4();

		bool _begin__setparam__int3x1( void* attributeData ){return mImpl->begin__setparam__int3x1();}
		bool _data__setparam__int3x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__int3x1(){return mImpl->end__setparam__int3x1();}
		bool _validateBegin__setparam__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x1();

		bool _begin__setparam__int3x2( void* attributeData ){return mImpl->begin__setparam__int3x2();}
		bool _data__setparam__int3x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__int3x2(){return mImpl->end__setparam__int3x2();}
		bool _validateBegin__setparam__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x2();

		bool _begin__setparam__int3x3( void* attributeData ){return mImpl->begin__setparam__int3x3();}
		bool _data__setparam__int3x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__int3x3(){return mImpl->end__setparam__int3x3();}
		bool _validateBegin__setparam__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x3();

		bool _begin__setparam__int3x4( void* attributeData ){return mImpl->begin__setparam__int3x4();}
		bool _data__setparam__int3x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__int3x4(){return mImpl->end__setparam__int3x4();}
		bool _validateBegin__setparam__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int3x4();

		bool _begin__setparam__int4x1( void* attributeData ){return mImpl->begin__setparam__int4x1();}
		bool _data__setparam__int4x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__int4x1(){return mImpl->end__setparam__int4x1();}
		bool _validateBegin__setparam__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x1();

		bool _begin__setparam__int4x2( void* attributeData ){return mImpl->begin__setparam__int4x2();}
		bool _data__setparam__int4x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__int4x2(){return mImpl->end__setparam__int4x2();}
		bool _validateBegin__setparam__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x2();

		bool _begin__setparam__int4x3( void* attributeData ){return mImpl->begin__setparam__int4x3();}
		bool _data__setparam__int4x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__int4x3(){return mImpl->end__setparam__int4x3();}
		bool _validateBegin__setparam__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x3();

		bool _begin__setparam__int4x4( void* attributeData ){return mImpl->begin__setparam__int4x4();}
		bool _data__setparam__int4x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__int4x4(){return mImpl->end__setparam__int4x4();}
		bool _validateBegin__setparam__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__int4x4();

		bool _begin__setparam__half( void* attributeData ){return mImpl->begin__setparam__half();}
		bool _data__setparam__half( const ParserChar* text, size_t textLength );
		bool _end__setparam__half(){return mImpl->end__setparam__half();}
		bool _validateBegin__setparam__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half();

		bool _begin__setparam__half1( void* attributeData ){return mImpl->begin__setparam__half1();}
		bool _data__setparam__half1( const ParserChar* text, size_t textLength );
		bool _end__setparam__half1(){return mImpl->end__setparam__half1();}
		bool _validateBegin__setparam__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1();

		bool _begin__setparam__half2( void* attributeData ){return mImpl->begin__setparam__half2();}
		bool _data__setparam__half2( const ParserChar* text, size_t textLength );
		bool _end__setparam__half2(){return mImpl->end__setparam__half2();}
		bool _validateBegin__setparam__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2();

		bool _begin__setparam__half3( void* attributeData ){return mImpl->begin__setparam__half3();}
		bool _data__setparam__half3( const ParserChar* text, size_t textLength );
		bool _end__setparam__half3(){return mImpl->end__setparam__half3();}
		bool _validateBegin__setparam__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3();

		bool _begin__setparam__half4( void* attributeData ){return mImpl->begin__setparam__half4();}
		bool _data__setparam__half4( const ParserChar* text, size_t textLength );
		bool _end__setparam__half4(){return mImpl->end__setparam__half4();}
		bool _validateBegin__setparam__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4();

		bool _begin__setparam__half1x1( void* attributeData ){return mImpl->begin__setparam__half1x1();}
		bool _data__setparam__half1x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__half1x1(){return mImpl->end__setparam__half1x1();}
		bool _validateBegin__setparam__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x1();

		bool _begin__setparam__half1x2( void* attributeData ){return mImpl->begin__setparam__half1x2();}
		bool _data__setparam__half1x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__half1x2(){return mImpl->end__setparam__half1x2();}
		bool _validateBegin__setparam__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x2();

		bool _begin__setparam__half1x3( void* attributeData ){return mImpl->begin__setparam__half1x3();}
		bool _data__setparam__half1x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__half1x3(){return mImpl->end__setparam__half1x3();}
		bool _validateBegin__setparam__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x3();

		bool _begin__setparam__half1x4( void* attributeData ){return mImpl->begin__setparam__half1x4();}
		bool _data__setparam__half1x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__half1x4(){return mImpl->end__setparam__half1x4();}
		bool _validateBegin__setparam__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half1x4();

		bool _begin__setparam__half2x1( void* attributeData ){return mImpl->begin__setparam__half2x1();}
		bool _data__setparam__half2x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__half2x1(){return mImpl->end__setparam__half2x1();}
		bool _validateBegin__setparam__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x1();

		bool _begin__setparam__half2x2( void* attributeData ){return mImpl->begin__setparam__half2x2();}
		bool _data__setparam__half2x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__half2x2(){return mImpl->end__setparam__half2x2();}
		bool _validateBegin__setparam__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x2();

		bool _begin__setparam__half2x3( void* attributeData ){return mImpl->begin__setparam__half2x3();}
		bool _data__setparam__half2x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__half2x3(){return mImpl->end__setparam__half2x3();}
		bool _validateBegin__setparam__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x3();

		bool _begin__setparam__half2x4( void* attributeData ){return mImpl->begin__setparam__half2x4();}
		bool _data__setparam__half2x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__half2x4(){return mImpl->end__setparam__half2x4();}
		bool _validateBegin__setparam__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half2x4();

		bool _begin__setparam__half3x1( void* attributeData ){return mImpl->begin__setparam__half3x1();}
		bool _data__setparam__half3x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__half3x1(){return mImpl->end__setparam__half3x1();}
		bool _validateBegin__setparam__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x1();

		bool _begin__setparam__half3x2( void* attributeData ){return mImpl->begin__setparam__half3x2();}
		bool _data__setparam__half3x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__half3x2(){return mImpl->end__setparam__half3x2();}
		bool _validateBegin__setparam__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x2();

		bool _begin__setparam__half3x3( void* attributeData ){return mImpl->begin__setparam__half3x3();}
		bool _data__setparam__half3x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__half3x3(){return mImpl->end__setparam__half3x3();}
		bool _validateBegin__setparam__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x3();

		bool _begin__setparam__half3x4( void* attributeData ){return mImpl->begin__setparam__half3x4();}
		bool _data__setparam__half3x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__half3x4(){return mImpl->end__setparam__half3x4();}
		bool _validateBegin__setparam__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half3x4();

		bool _begin__setparam__half4x1( void* attributeData ){return mImpl->begin__setparam__half4x1();}
		bool _data__setparam__half4x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__half4x1(){return mImpl->end__setparam__half4x1();}
		bool _validateBegin__setparam__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x1();

		bool _begin__setparam__half4x2( void* attributeData ){return mImpl->begin__setparam__half4x2();}
		bool _data__setparam__half4x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__half4x2(){return mImpl->end__setparam__half4x2();}
		bool _validateBegin__setparam__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x2();

		bool _begin__setparam__half4x3( void* attributeData ){return mImpl->begin__setparam__half4x3();}
		bool _data__setparam__half4x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__half4x3(){return mImpl->end__setparam__half4x3();}
		bool _validateBegin__setparam__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x3();

		bool _begin__setparam__half4x4( void* attributeData ){return mImpl->begin__setparam__half4x4();}
		bool _data__setparam__half4x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__half4x4(){return mImpl->end__setparam__half4x4();}
		bool _validateBegin__setparam__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__half4x4();

		bool _begin__setparam__fixed( void* attributeData ){return mImpl->begin__setparam__fixed();}
		bool _data__setparam__fixed( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed(){return mImpl->end__setparam__fixed();}
		bool _validateBegin__setparam__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed();

		bool _begin__setparam__fixed1( void* attributeData ){return mImpl->begin__setparam__fixed1();}
		bool _data__setparam__fixed1( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed1(){return mImpl->end__setparam__fixed1();}
		bool _validateBegin__setparam__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1();

		bool _begin__setparam__fixed2( void* attributeData ){return mImpl->begin__setparam__fixed2();}
		bool _data__setparam__fixed2( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed2(){return mImpl->end__setparam__fixed2();}
		bool _validateBegin__setparam__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2();

		bool _begin__setparam__fixed3( void* attributeData ){return mImpl->begin__setparam__fixed3();}
		bool _data__setparam__fixed3( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed3(){return mImpl->end__setparam__fixed3();}
		bool _validateBegin__setparam__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3();

		bool _begin__setparam__fixed4( void* attributeData ){return mImpl->begin__setparam__fixed4();}
		bool _data__setparam__fixed4( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed4(){return mImpl->end__setparam__fixed4();}
		bool _validateBegin__setparam__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4();

		bool _begin__setparam__fixed1x1( void* attributeData ){return mImpl->begin__setparam__fixed1x1();}
		bool _data__setparam__fixed1x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed1x1(){return mImpl->end__setparam__fixed1x1();}
		bool _validateBegin__setparam__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x1();

		bool _begin__setparam__fixed1x2( void* attributeData ){return mImpl->begin__setparam__fixed1x2();}
		bool _data__setparam__fixed1x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed1x2(){return mImpl->end__setparam__fixed1x2();}
		bool _validateBegin__setparam__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x2();

		bool _begin__setparam__fixed1x3( void* attributeData ){return mImpl->begin__setparam__fixed1x3();}
		bool _data__setparam__fixed1x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed1x3(){return mImpl->end__setparam__fixed1x3();}
		bool _validateBegin__setparam__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x3();

		bool _begin__setparam__fixed1x4( void* attributeData ){return mImpl->begin__setparam__fixed1x4();}
		bool _data__setparam__fixed1x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed1x4(){return mImpl->end__setparam__fixed1x4();}
		bool _validateBegin__setparam__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed1x4();

		bool _begin__setparam__fixed2x1( void* attributeData ){return mImpl->begin__setparam__fixed2x1();}
		bool _data__setparam__fixed2x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed2x1(){return mImpl->end__setparam__fixed2x1();}
		bool _validateBegin__setparam__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x1();

		bool _begin__setparam__fixed2x2( void* attributeData ){return mImpl->begin__setparam__fixed2x2();}
		bool _data__setparam__fixed2x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed2x2(){return mImpl->end__setparam__fixed2x2();}
		bool _validateBegin__setparam__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x2();

		bool _begin__setparam__fixed2x3( void* attributeData ){return mImpl->begin__setparam__fixed2x3();}
		bool _data__setparam__fixed2x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed2x3(){return mImpl->end__setparam__fixed2x3();}
		bool _validateBegin__setparam__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x3();

		bool _begin__setparam__fixed2x4( void* attributeData ){return mImpl->begin__setparam__fixed2x4();}
		bool _data__setparam__fixed2x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed2x4(){return mImpl->end__setparam__fixed2x4();}
		bool _validateBegin__setparam__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed2x4();

		bool _begin__setparam__fixed3x1( void* attributeData ){return mImpl->begin__setparam__fixed3x1();}
		bool _data__setparam__fixed3x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed3x1(){return mImpl->end__setparam__fixed3x1();}
		bool _validateBegin__setparam__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x1();

		bool _begin__setparam__fixed3x2( void* attributeData ){return mImpl->begin__setparam__fixed3x2();}
		bool _data__setparam__fixed3x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed3x2(){return mImpl->end__setparam__fixed3x2();}
		bool _validateBegin__setparam__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x2();

		bool _begin__setparam__fixed3x3( void* attributeData ){return mImpl->begin__setparam__fixed3x3();}
		bool _data__setparam__fixed3x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed3x3(){return mImpl->end__setparam__fixed3x3();}
		bool _validateBegin__setparam__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x3();

		bool _begin__setparam__fixed3x4( void* attributeData ){return mImpl->begin__setparam__fixed3x4();}
		bool _data__setparam__fixed3x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed3x4(){return mImpl->end__setparam__fixed3x4();}
		bool _validateBegin__setparam__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed3x4();

		bool _begin__setparam__fixed4x1( void* attributeData ){return mImpl->begin__setparam__fixed4x1();}
		bool _data__setparam__fixed4x1( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed4x1(){return mImpl->end__setparam__fixed4x1();}
		bool _validateBegin__setparam__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x1();

		bool _begin__setparam__fixed4x2( void* attributeData ){return mImpl->begin__setparam__fixed4x2();}
		bool _data__setparam__fixed4x2( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed4x2(){return mImpl->end__setparam__fixed4x2();}
		bool _validateBegin__setparam__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x2();

		bool _begin__setparam__fixed4x3( void* attributeData ){return mImpl->begin__setparam__fixed4x3();}
		bool _data__setparam__fixed4x3( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed4x3(){return mImpl->end__setparam__fixed4x3();}
		bool _validateBegin__setparam__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x3();

		bool _begin__setparam__fixed4x4( void* attributeData ){return mImpl->begin__setparam__fixed4x4();}
		bool _data__setparam__fixed4x4( const ParserChar* text, size_t textLength );
		bool _end__setparam__fixed4x4(){return mImpl->end__setparam__fixed4x4();}
		bool _validateBegin__setparam__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__fixed4x4();

		bool _begin__setparam__string( void* attributeData ){return mImpl->begin__setparam__string();}
		bool _data__setparam__string( const ParserChar* text, size_t textLength );
		bool _end__setparam__string(){return mImpl->end__setparam__string();}
		bool _validateBegin__setparam__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__string();

		bool _begin__setparam__usertype( void* attributeData ){return mImpl->begin__setparam__usertype(*static_cast<setparam__usertype__AttributeData*>(attributeData));}
		bool _data__setparam__usertype( const ParserChar* text, size_t textLength );
		bool _end__setparam__usertype(){return mImpl->end__setparam__usertype();}
		bool _validateBegin__setparam__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__usertype();

		bool _begin__setparam__array( void* attributeData ){return mImpl->begin__setparam__array(*static_cast<setparam__array__AttributeData*>(attributeData));}
		bool _data__setparam__array( const ParserChar* text, size_t textLength );
		bool _end__setparam__array(){return mImpl->end__setparam__array();}
		bool _validateBegin__setparam__array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__array();

		bool _begin__setparam__connect_param( void* attributeData ){return mImpl->begin__setparam__connect_param(*static_cast<setparam__connect_param__AttributeData*>(attributeData));}
		bool _data__setparam__connect_param( const ParserChar* text, size_t textLength );
		bool _end__setparam__connect_param(){return mImpl->end__setparam__connect_param();}
		bool _validateBegin__setparam__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__setparam__connect_param();

		bool _begin__profile_CG__technique( void* attributeData ){return mImpl->begin__profile_CG__technique(*static_cast<profile_CG__technique__AttributeData*>(attributeData));}
		bool _data__profile_CG__technique( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__technique(){return mImpl->end__profile_CG__technique();}
		bool _validateBegin__profile_CG__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__technique();

		bool _begin__profile_CG__extra( void* attributeData ){return mImpl->begin__profile_CG__extra(*static_cast<profile_CG__extra__AttributeData*>(attributeData));}
		bool _data__profile_CG__extra( const ParserChar* text, size_t textLength );
		bool _end__profile_CG__extra(){return mImpl->end__profile_CG__extra();}
		bool _validateBegin__profile_CG__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_CG__extra();

		bool _begin__profile_COMMON( void* attributeData ){return mImpl->begin__profile_COMMON(*static_cast<profile_COMMON__AttributeData*>(attributeData));}
		bool _data__profile_COMMON( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON(){return mImpl->end__profile_COMMON();}
		bool _validateBegin__profile_COMMON( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON();

		bool _begin__profile_COMMON__asset( void* attributeData ){return mImpl->begin__profile_COMMON__asset();}
		bool _data__profile_COMMON__asset( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON__asset(){return mImpl->end__profile_COMMON__asset();}
		bool _validateBegin__profile_COMMON__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__asset();

		bool _begin__profile_COMMON__image( void* attributeData ){return mImpl->begin__profile_COMMON__image(*static_cast<profile_COMMON__image__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__image( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON__image(){return mImpl->end__profile_COMMON__image();}
		bool _validateBegin__profile_COMMON__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__image();

		bool _begin__profile_COMMON__newparam( void* attributeData ){return mImpl->begin__profile_COMMON__newparam(*static_cast<profile_COMMON__newparam__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__newparam( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON__newparam(){return mImpl->end__profile_COMMON__newparam();}
		bool _validateBegin__profile_COMMON__newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__newparam();

		bool _begin__profile_COMMON__technique( void* attributeData ){return mImpl->begin__profile_COMMON__technique(*static_cast<profile_COMMON__technique__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__technique( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON__technique(){return mImpl->end__profile_COMMON__technique();}
		bool _validateBegin__profile_COMMON__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__technique();

		bool _begin__technique__constant( void* attributeData ){return mImpl->begin__technique__constant();}
		bool _data__technique__constant( const ParserChar* text, size_t textLength );
		bool _end__technique__constant(){return mImpl->end__technique__constant();}
		bool _validateBegin__technique__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__technique__constant();

		bool _begin__constant__emission( void* attributeData ){return mImpl->begin__constant__emission();}
		bool _data__constant__emission( const ParserChar* text, size_t textLength );
		bool _end__constant__emission(){return mImpl->end__constant__emission();}
		bool _validateBegin__constant__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__emission();

		bool _begin__emission__color( void* attributeData ){return mImpl->begin__emission__color(*static_cast<emission__color__AttributeData*>(attributeData));}
		bool _data__emission__color( const ParserChar* text, size_t textLength );
		bool _end__emission__color(){return mImpl->end__emission__color();}
		bool _validateBegin__emission__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__color();

		bool _begin__emission__param( void* attributeData ){return mImpl->begin__emission__param(*static_cast<emission__param__AttributeData*>(attributeData));}
		bool _data__emission__param( const ParserChar* text, size_t textLength );
		bool _end__emission__param(){return mImpl->end__emission__param();}
		bool _validateBegin__emission__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__param();

		bool _begin__emission__texture( void* attributeData ){return mImpl->begin__emission__texture(*static_cast<emission__texture__AttributeData*>(attributeData));}
		bool _data__emission__texture( const ParserChar* text, size_t textLength );
		bool _end__emission__texture(){return mImpl->end__emission__texture();}
		bool _validateBegin__emission__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__emission__texture();

		bool _begin__texture__extra( void* attributeData ){return mImpl->begin__texture__extra(*static_cast<texture__extra__AttributeData*>(attributeData));}
		bool _data__texture__extra( const ParserChar* text, size_t textLength );
		bool _end__texture__extra(){return mImpl->end__texture__extra();}
		bool _validateBegin__texture__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__texture__extra();

		bool _begin__constant__reflective( void* attributeData ){return mImpl->begin__constant__reflective();}
		bool _data__constant__reflective( const ParserChar* text, size_t textLength );
		bool _end__constant__reflective(){return mImpl->end__constant__reflective();}
		bool _validateBegin__constant__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__reflective();

		bool _begin__reflective__color( void* attributeData ){return mImpl->begin__reflective__color(*static_cast<reflective__color__AttributeData*>(attributeData));}
		bool _data__reflective__color( const ParserChar* text, size_t textLength );
		bool _end__reflective__color(){return mImpl->end__reflective__color();}
		bool _validateBegin__reflective__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__color();

		bool _begin__reflective__param( void* attributeData ){return mImpl->begin__reflective__param(*static_cast<reflective__param__AttributeData*>(attributeData));}
		bool _data__reflective__param( const ParserChar* text, size_t textLength );
		bool _end__reflective__param(){return mImpl->end__reflective__param();}
		bool _validateBegin__reflective__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__param();

		bool _begin__reflective__texture( void* attributeData ){return mImpl->begin__reflective__texture(*static_cast<reflective__texture__AttributeData*>(attributeData));}
		bool _data__reflective__texture( const ParserChar* text, size_t textLength );
		bool _end__reflective__texture(){return mImpl->end__reflective__texture();}
		bool _validateBegin__reflective__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflective__texture();

		bool _begin__constant__reflectivity( void* attributeData ){return mImpl->begin__constant__reflectivity();}
		bool _data__constant__reflectivity( const ParserChar* text, size_t textLength );
		bool _end__constant__reflectivity(){return mImpl->end__constant__reflectivity();}
		bool _validateBegin__constant__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__reflectivity();

		bool _begin__reflectivity__float( void* attributeData ){return mImpl->begin__reflectivity__float(*static_cast<reflectivity__float__AttributeData*>(attributeData));}
		bool _data__reflectivity__float( const ParserChar* text, size_t textLength );
		bool _end__reflectivity__float(){return mImpl->end__reflectivity__float();}
		bool _validateBegin__reflectivity__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflectivity__float();

		bool _begin__reflectivity__param( void* attributeData ){return mImpl->begin__reflectivity__param(*static_cast<reflectivity__param__AttributeData*>(attributeData));}
		bool _data__reflectivity__param( const ParserChar* text, size_t textLength );
		bool _end__reflectivity__param(){return mImpl->end__reflectivity__param();}
		bool _validateBegin__reflectivity__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__reflectivity__param();

		bool _begin__constant__transparent( void* attributeData ){return mImpl->begin__constant__transparent(*static_cast<constant__transparent__AttributeData*>(attributeData));}
		bool _data__constant__transparent( const ParserChar* text, size_t textLength );
		bool _end__constant__transparent(){return mImpl->end__constant__transparent();}
		bool _validateBegin__constant__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__transparent();

		bool _begin__transparent__color( void* attributeData ){return mImpl->begin__transparent__color(*static_cast<transparent__color__AttributeData*>(attributeData));}
		bool _data__transparent__color( const ParserChar* text, size_t textLength );
		bool _end__transparent__color(){return mImpl->end__transparent__color();}
		bool _validateBegin__transparent__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__color();

		bool _begin__transparent__param( void* attributeData ){return mImpl->begin__transparent__param(*static_cast<transparent__param__AttributeData*>(attributeData));}
		bool _data__transparent__param( const ParserChar* text, size_t textLength );
		bool _end__transparent__param(){return mImpl->end__transparent__param();}
		bool _validateBegin__transparent__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__param();

		bool _begin__transparent__texture( void* attributeData ){return mImpl->begin__transparent__texture(*static_cast<transparent__texture__AttributeData*>(attributeData));}
		bool _data__transparent__texture( const ParserChar* text, size_t textLength );
		bool _end__transparent__texture(){return mImpl->end__transparent__texture();}
		bool _validateBegin__transparent__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparent__texture();

		bool _begin__constant__transparency( void* attributeData ){return mImpl->begin__constant__transparency();}
		bool _data__constant__transparency( const ParserChar* text, size_t textLength );
		bool _end__constant__transparency(){return mImpl->end__constant__transparency();}
		bool _validateBegin__constant__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__transparency();

		bool _begin__transparency__float( void* attributeData ){return mImpl->begin__transparency__float(*static_cast<transparency__float__AttributeData*>(attributeData));}
		bool _data__transparency__float( const ParserChar* text, size_t textLength );
		bool _end__transparency__float(){return mImpl->end__transparency__float();}
		bool _validateBegin__transparency__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparency__float();

		bool _begin__transparency__param( void* attributeData ){return mImpl->begin__transparency__param(*static_cast<transparency__param__AttributeData*>(attributeData));}
		bool _data__transparency__param( const ParserChar* text, size_t textLength );
		bool _end__transparency__param(){return mImpl->end__transparency__param();}
		bool _validateBegin__transparency__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__transparency__param();

		bool _begin__constant__index_of_refraction( void* attributeData ){return mImpl->begin__constant__index_of_refraction();}
		bool _data__constant__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _end__constant__index_of_refraction(){return mImpl->end__constant__index_of_refraction();}
		bool _validateBegin__constant__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__constant__index_of_refraction();

		bool _begin__index_of_refraction__float( void* attributeData ){return mImpl->begin__index_of_refraction__float(*static_cast<index_of_refraction__float__AttributeData*>(attributeData));}
		bool _data__index_of_refraction__float( const ParserChar* text, size_t textLength );
		bool _end__index_of_refraction__float(){return mImpl->end__index_of_refraction__float();}
		bool _validateBegin__index_of_refraction__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__index_of_refraction__float();

		bool _begin__index_of_refraction__param( void* attributeData ){return mImpl->begin__index_of_refraction__param(*static_cast<index_of_refraction__param__AttributeData*>(attributeData));}
		bool _data__index_of_refraction__param( const ParserChar* text, size_t textLength );
		bool _end__index_of_refraction__param(){return mImpl->end__index_of_refraction__param();}
		bool _validateBegin__index_of_refraction__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__index_of_refraction__param();

		bool _begin__lambert( void* attributeData ){return mImpl->begin__lambert();}
		bool _data__lambert( const ParserChar* text, size_t textLength );
		bool _end__lambert(){return mImpl->end__lambert();}
		bool _validateBegin__lambert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert();

		bool _begin__lambert__emission( void* attributeData ){return mImpl->begin__lambert__emission();}
		bool _data__lambert__emission( const ParserChar* text, size_t textLength );
		bool _end__lambert__emission(){return mImpl->end__lambert__emission();}
		bool _validateBegin__lambert__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__emission();

		bool _begin__lambert__ambient( void* attributeData ){return mImpl->begin__lambert__ambient();}
		bool _data__lambert__ambient( const ParserChar* text, size_t textLength );
		bool _end__lambert__ambient(){return mImpl->end__lambert__ambient();}
		bool _validateBegin__lambert__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__ambient();

		bool _begin__ambient__param( void* attributeData ){return mImpl->begin__ambient__param(*static_cast<ambient__param__AttributeData*>(attributeData));}
		bool _data__ambient__param( const ParserChar* text, size_t textLength );
		bool _end__ambient__param(){return mImpl->end__ambient__param();}
		bool _validateBegin__ambient__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__param();

		bool _begin__ambient__texture( void* attributeData ){return mImpl->begin__ambient__texture(*static_cast<ambient__texture__AttributeData*>(attributeData));}
		bool _data__ambient__texture( const ParserChar* text, size_t textLength );
		bool _end__ambient__texture(){return mImpl->end__ambient__texture();}
		bool _validateBegin__ambient__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__ambient__texture();

		bool _begin__lambert__diffuse( void* attributeData ){return mImpl->begin__lambert__diffuse();}
		bool _data__lambert__diffuse( const ParserChar* text, size_t textLength );
		bool _end__lambert__diffuse(){return mImpl->end__lambert__diffuse();}
		bool _validateBegin__lambert__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__diffuse();

		bool _begin__diffuse__color( void* attributeData ){return mImpl->begin__diffuse__color(*static_cast<diffuse__color__AttributeData*>(attributeData));}
		bool _data__diffuse__color( const ParserChar* text, size_t textLength );
		bool _end__diffuse__color(){return mImpl->end__diffuse__color();}
		bool _validateBegin__diffuse__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__color();

		bool _begin__diffuse__param( void* attributeData ){return mImpl->begin__diffuse__param(*static_cast<diffuse__param__AttributeData*>(attributeData));}
		bool _data__diffuse__param( const ParserChar* text, size_t textLength );
		bool _end__diffuse__param(){return mImpl->end__diffuse__param();}
		bool _validateBegin__diffuse__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__param();

		bool _begin__diffuse__texture( void* attributeData ){return mImpl->begin__diffuse__texture(*static_cast<diffuse__texture__AttributeData*>(attributeData));}
		bool _data__diffuse__texture( const ParserChar* text, size_t textLength );
		bool _end__diffuse__texture(){return mImpl->end__diffuse__texture();}
		bool _validateBegin__diffuse__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__diffuse__texture();

		bool _begin__lambert__reflective( void* attributeData ){return mImpl->begin__lambert__reflective();}
		bool _data__lambert__reflective( const ParserChar* text, size_t textLength );
		bool _end__lambert__reflective(){return mImpl->end__lambert__reflective();}
		bool _validateBegin__lambert__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__reflective();

		bool _begin__lambert__reflectivity( void* attributeData ){return mImpl->begin__lambert__reflectivity();}
		bool _data__lambert__reflectivity( const ParserChar* text, size_t textLength );
		bool _end__lambert__reflectivity(){return mImpl->end__lambert__reflectivity();}
		bool _validateBegin__lambert__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__reflectivity();

		bool _begin__lambert__transparent( void* attributeData ){return mImpl->begin__lambert__transparent(*static_cast<lambert__transparent__AttributeData*>(attributeData));}
		bool _data__lambert__transparent( const ParserChar* text, size_t textLength );
		bool _end__lambert__transparent(){return mImpl->end__lambert__transparent();}
		bool _validateBegin__lambert__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__transparent();

		bool _begin__lambert__transparency( void* attributeData ){return mImpl->begin__lambert__transparency();}
		bool _data__lambert__transparency( const ParserChar* text, size_t textLength );
		bool _end__lambert__transparency(){return mImpl->end__lambert__transparency();}
		bool _validateBegin__lambert__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__transparency();

		bool _begin__lambert__index_of_refraction( void* attributeData ){return mImpl->begin__lambert__index_of_refraction();}
		bool _data__lambert__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _end__lambert__index_of_refraction(){return mImpl->end__lambert__index_of_refraction();}
		bool _validateBegin__lambert__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__lambert__index_of_refraction();

		bool _begin__phong( void* attributeData ){return mImpl->begin__phong();}
		bool _data__phong( const ParserChar* text, size_t textLength );
		bool _end__phong(){return mImpl->end__phong();}
		bool _validateBegin__phong( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong();

		bool _begin__phong__emission( void* attributeData ){return mImpl->begin__phong__emission();}
		bool _data__phong__emission( const ParserChar* text, size_t textLength );
		bool _end__phong__emission(){return mImpl->end__phong__emission();}
		bool _validateBegin__phong__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__emission();

		bool _begin__phong__ambient( void* attributeData ){return mImpl->begin__phong__ambient();}
		bool _data__phong__ambient( const ParserChar* text, size_t textLength );
		bool _end__phong__ambient(){return mImpl->end__phong__ambient();}
		bool _validateBegin__phong__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__ambient();

		bool _begin__phong__diffuse( void* attributeData ){return mImpl->begin__phong__diffuse();}
		bool _data__phong__diffuse( const ParserChar* text, size_t textLength );
		bool _end__phong__diffuse(){return mImpl->end__phong__diffuse();}
		bool _validateBegin__phong__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__diffuse();

		bool _begin__phong__specular( void* attributeData ){return mImpl->begin__phong__specular();}
		bool _data__phong__specular( const ParserChar* text, size_t textLength );
		bool _end__phong__specular(){return mImpl->end__phong__specular();}
		bool _validateBegin__phong__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__specular();

		bool _begin__specular__color( void* attributeData ){return mImpl->begin__specular__color(*static_cast<specular__color__AttributeData*>(attributeData));}
		bool _data__specular__color( const ParserChar* text, size_t textLength );
		bool _end__specular__color(){return mImpl->end__specular__color();}
		bool _validateBegin__specular__color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__color();

		bool _begin__specular__param( void* attributeData ){return mImpl->begin__specular__param(*static_cast<specular__param__AttributeData*>(attributeData));}
		bool _data__specular__param( const ParserChar* text, size_t textLength );
		bool _end__specular__param(){return mImpl->end__specular__param();}
		bool _validateBegin__specular__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__param();

		bool _begin__specular__texture( void* attributeData ){return mImpl->begin__specular__texture(*static_cast<specular__texture__AttributeData*>(attributeData));}
		bool _data__specular__texture( const ParserChar* text, size_t textLength );
		bool _end__specular__texture(){return mImpl->end__specular__texture();}
		bool _validateBegin__specular__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__specular__texture();

		bool _begin__phong__shininess( void* attributeData ){return mImpl->begin__phong__shininess();}
		bool _data__phong__shininess( const ParserChar* text, size_t textLength );
		bool _end__phong__shininess(){return mImpl->end__phong__shininess();}
		bool _validateBegin__phong__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__shininess();

		bool _begin__shininess__float( void* attributeData ){return mImpl->begin__shininess__float(*static_cast<shininess__float__AttributeData*>(attributeData));}
		bool _data__shininess__float( const ParserChar* text, size_t textLength );
		bool _end__shininess__float(){return mImpl->end__shininess__float();}
		bool _validateBegin__shininess__float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shininess__float();

		bool _begin__shininess__param( void* attributeData ){return mImpl->begin__shininess__param(*static_cast<shininess__param__AttributeData*>(attributeData));}
		bool _data__shininess__param( const ParserChar* text, size_t textLength );
		bool _end__shininess__param(){return mImpl->end__shininess__param();}
		bool _validateBegin__shininess__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__shininess__param();

		bool _begin__phong__reflective( void* attributeData ){return mImpl->begin__phong__reflective();}
		bool _data__phong__reflective( const ParserChar* text, size_t textLength );
		bool _end__phong__reflective(){return mImpl->end__phong__reflective();}
		bool _validateBegin__phong__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__reflective();

		bool _begin__phong__reflectivity( void* attributeData ){return mImpl->begin__phong__reflectivity();}
		bool _data__phong__reflectivity( const ParserChar* text, size_t textLength );
		bool _end__phong__reflectivity(){return mImpl->end__phong__reflectivity();}
		bool _validateBegin__phong__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__reflectivity();

		bool _begin__phong__transparent( void* attributeData ){return mImpl->begin__phong__transparent(*static_cast<phong__transparent__AttributeData*>(attributeData));}
		bool _data__phong__transparent( const ParserChar* text, size_t textLength );
		bool _end__phong__transparent(){return mImpl->end__phong__transparent();}
		bool _validateBegin__phong__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__transparent();

		bool _begin__phong__transparency( void* attributeData ){return mImpl->begin__phong__transparency();}
		bool _data__phong__transparency( const ParserChar* text, size_t textLength );
		bool _end__phong__transparency(){return mImpl->end__phong__transparency();}
		bool _validateBegin__phong__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__transparency();

		bool _begin__phong__index_of_refraction( void* attributeData ){return mImpl->begin__phong__index_of_refraction();}
		bool _data__phong__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _end__phong__index_of_refraction(){return mImpl->end__phong__index_of_refraction();}
		bool _validateBegin__phong__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__phong__index_of_refraction();

		bool _begin__blinn( void* attributeData ){return mImpl->begin__blinn();}
		bool _data__blinn( const ParserChar* text, size_t textLength );
		bool _end__blinn(){return mImpl->end__blinn();}
		bool _validateBegin__blinn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn();

		bool _begin__blinn__emission( void* attributeData ){return mImpl->begin__blinn__emission();}
		bool _data__blinn__emission( const ParserChar* text, size_t textLength );
		bool _end__blinn__emission(){return mImpl->end__blinn__emission();}
		bool _validateBegin__blinn__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__emission();

		bool _begin__blinn__ambient( void* attributeData ){return mImpl->begin__blinn__ambient();}
		bool _data__blinn__ambient( const ParserChar* text, size_t textLength );
		bool _end__blinn__ambient(){return mImpl->end__blinn__ambient();}
		bool _validateBegin__blinn__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__ambient();

		bool _begin__blinn__diffuse( void* attributeData ){return mImpl->begin__blinn__diffuse();}
		bool _data__blinn__diffuse( const ParserChar* text, size_t textLength );
		bool _end__blinn__diffuse(){return mImpl->end__blinn__diffuse();}
		bool _validateBegin__blinn__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__diffuse();

		bool _begin__blinn__specular( void* attributeData ){return mImpl->begin__blinn__specular();}
		bool _data__blinn__specular( const ParserChar* text, size_t textLength );
		bool _end__blinn__specular(){return mImpl->end__blinn__specular();}
		bool _validateBegin__blinn__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__specular();

		bool _begin__blinn__shininess( void* attributeData ){return mImpl->begin__blinn__shininess();}
		bool _data__blinn__shininess( const ParserChar* text, size_t textLength );
		bool _end__blinn__shininess(){return mImpl->end__blinn__shininess();}
		bool _validateBegin__blinn__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__shininess();

		bool _begin__blinn__reflective( void* attributeData ){return mImpl->begin__blinn__reflective();}
		bool _data__blinn__reflective( const ParserChar* text, size_t textLength );
		bool _end__blinn__reflective(){return mImpl->end__blinn__reflective();}
		bool _validateBegin__blinn__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__reflective();

		bool _begin__blinn__reflectivity( void* attributeData ){return mImpl->begin__blinn__reflectivity();}
		bool _data__blinn__reflectivity( const ParserChar* text, size_t textLength );
		bool _end__blinn__reflectivity(){return mImpl->end__blinn__reflectivity();}
		bool _validateBegin__blinn__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__reflectivity();

		bool _begin__blinn__transparent( void* attributeData ){return mImpl->begin__blinn__transparent(*static_cast<blinn__transparent__AttributeData*>(attributeData));}
		bool _data__blinn__transparent( const ParserChar* text, size_t textLength );
		bool _end__blinn__transparent(){return mImpl->end__blinn__transparent();}
		bool _validateBegin__blinn__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__transparent();

		bool _begin__blinn__transparency( void* attributeData ){return mImpl->begin__blinn__transparency();}
		bool _data__blinn__transparency( const ParserChar* text, size_t textLength );
		bool _end__blinn__transparency(){return mImpl->end__blinn__transparency();}
		bool _validateBegin__blinn__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__transparency();

		bool _begin__blinn__index_of_refraction( void* attributeData ){return mImpl->begin__blinn__index_of_refraction();}
		bool _data__blinn__index_of_refraction( const ParserChar* text, size_t textLength );
		bool _end__blinn__index_of_refraction(){return mImpl->end__blinn__index_of_refraction();}
		bool _validateBegin__blinn__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__blinn__index_of_refraction();

		bool _begin__profile_COMMON__extra( void* attributeData ){return mImpl->begin__profile_COMMON__extra(*static_cast<profile_COMMON__extra__AttributeData*>(attributeData));}
		bool _data__profile_COMMON__extra( const ParserChar* text, size_t textLength );
		bool _end__profile_COMMON__extra(){return mImpl->end__profile_COMMON__extra();}
		bool _validateBegin__profile_COMMON__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__profile_COMMON__extra();

		bool _begin__triangles( void* attributeData ){return mImpl->begin__triangles(*static_cast<triangles__AttributeData*>(attributeData));}
		bool _data__triangles( const ParserChar* text, size_t textLength );
		bool _end__triangles(){return mImpl->end__triangles();}
		bool _validateBegin__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__triangles();

		bool _begin__rotate( void* attributeData ){return mImpl->begin__rotate(*static_cast<rotate__AttributeData*>(attributeData));}
		bool _data__rotate( const ParserChar* text, size_t textLength );
		bool _end__rotate(){return mImpl->end__rotate();}
		bool _validateBegin__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__rotate();

		bool _begin__bind_material( void* attributeData ){return mImpl->begin__bind_material();}
		bool _data__bind_material( const ParserChar* text, size_t textLength );
		bool _end__bind_material(){return mImpl->end__bind_material();}
		bool _validateBegin__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__bind_material();

		bool _begin__instance_force_field( void* attributeData ){return mImpl->begin__instance_force_field(*static_cast<instance_force_field__AttributeData*>(attributeData));}
		bool _data__instance_force_field( const ParserChar* text, size_t textLength );
		bool _end__instance_force_field(){return mImpl->end__instance_force_field();}
		bool _validateBegin__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_force_field();

		bool _begin__asset( void* attributeData ){return mImpl->begin__asset();}
		bool _data__asset( const ParserChar* text, size_t textLength );
		bool _end__asset(){return mImpl->end__asset();}
		bool _validateBegin__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__asset();

		bool _begin__polygons( void* attributeData ){return mImpl->begin__polygons(*static_cast<polygons__AttributeData*>(attributeData));}
		bool _data__polygons( const ParserChar* text, size_t textLength );
		bool _end__polygons(){return mImpl->end__polygons();}
		bool _validateBegin__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polygons();

		bool _begin__vertices( void* attributeData ){return mImpl->begin__vertices(*static_cast<vertices__AttributeData*>(attributeData));}
		bool _data__vertices( const ParserChar* text, size_t textLength );
		bool _end__vertices(){return mImpl->end__vertices();}
		bool _validateBegin__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__vertices();

		bool _begin__extra( void* attributeData ){return mImpl->begin__extra(*static_cast<extra__AttributeData*>(attributeData));}
		bool _data__extra( const ParserChar* text, size_t textLength );
		bool _end__extra(){return mImpl->end__extra();}
		bool _validateBegin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__extra();

		bool _begin__instance_physics_material( void* attributeData ){return mImpl->begin__instance_physics_material(*static_cast<instance_physics_material__AttributeData*>(attributeData));}
		bool _data__instance_physics_material( const ParserChar* text, size_t textLength );
		bool _end__instance_physics_material(){return mImpl->end__instance_physics_material();}
		bool _validateBegin__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__instance_physics_material();

		bool _begin__polylist( void* attributeData ){return mImpl->begin__polylist(*static_cast<polylist__AttributeData*>(attributeData));}
		bool _data__polylist( const ParserChar* text, size_t textLength );
		bool _end__polylist(){return mImpl->end__polylist();}
		bool _validateBegin__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__polylist();

		bool _begin__translate( void* attributeData ){return mImpl->begin__translate(*static_cast<translate__AttributeData*>(attributeData));}
		bool _data__translate( const ParserChar* text, size_t textLength );
		bool _end__translate(){return mImpl->end__translate();}
		bool _validateBegin__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
		bool _validateEnd__translate();



	private:
		/** Disable default copy ctor. */
		ColladaParserAutoGenPrivate( const ColladaParserAutoGenPrivate& pre );
		/** Disable default assignment operator. */
		const ColladaParserAutoGenPrivate& operator= ( const ColladaParserAutoGenPrivate& pre );

		void initFunctionMap();
		void initNameMap();

	};

}
#endif
