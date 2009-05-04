/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

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
#include "COLLADASaxFWLColladaParserAutoGen.h"
#include "COLLADASaxFWLColladaParserAutoGenValidationData.h"


// you may disable validation here
#define VALIDATION
//#undef VALIDATION


namespace COLLADASaxFWL
{


typedef GeneratedSaxParser::sint8 sint8;
typedef GeneratedSaxParser::sint16 sint16;
typedef GeneratedSaxParser::sint32 sint32;
typedef GeneratedSaxParser::sint64 sint64;
typedef GeneratedSaxParser::uint8 uint8;
typedef GeneratedSaxParser::uint16 uint16;
typedef GeneratedSaxParser::uint32 uint32;
typedef GeneratedSaxParser::uint64 uint64;

typedef GeneratedSaxParser::StringHash StringHash;
typedef GeneratedSaxParser::ParserChar ParserChar;
typedef GeneratedSaxParser::ParserString ParserString;
typedef GeneratedSaxParser::ParserAttributes ParserAttributes;
typedef GeneratedSaxParser::Utils Utils;
typedef GeneratedSaxParser::ParserError ParserError;
typedef GeneratedSaxParser::StringHashPair StringHashPair;
typedef GeneratedSaxParser::ParserError ParserError;


class FunctionMapFactory;


class ColladaParserAutoGenPrivate : public GeneratedSaxParser::ParserTemplate<ColladaParserAutoGenPrivate, ColladaParserAutoGen>
{
public:
static const StringHash TARGET_NAMESPACE = 221035537;

static const char* PARENT_CHILD_ELEMENT_SEPARATOR;

ColladaParserAutoGenPrivate( COLLADASaxFWL::ColladaParserAutoGen* impl, GeneratedSaxParser::IErrorHandler* errorHandler = 0 );
virtual ~ColladaParserAutoGenPrivate();


private:
friend class FunctionMapFactory;


bool _begin__COLLADA( void* attributeData ){return mImpl->begin__COLLADA(*static_cast<COLLADA__AttributeData*>(attributeData));}
bool _data__COLLADA( const ParserChar* text, size_t textLength );
bool _end__COLLADA(){return mImpl->end__COLLADA();}
bool _validateBegin__COLLADA( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__COLLADA();
bool _freeAttributes__COLLADA( void* attributeData );


ENUM__VersionType toEnumDataPrefix_ENUM__VersionType (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__VersionType (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__VersionType*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__VersionType (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__VersionType*, size_t ),
    const std::pair<StringHash, ENUM__VersionType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__VersionType (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__VersionType>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__asset( void* attributeData ){return mImpl->begin__asset();}
bool _data__asset( const ParserChar* text, size_t textLength );
bool _end__asset(){return mImpl->end__asset();}
bool _validateBegin__asset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__asset();
bool _freeAttributes__asset( void* attributeData );

bool _begin__contributor( void* attributeData ){return mImpl->begin__contributor();}
bool _data__contributor( const ParserChar* text, size_t textLength );
bool _end__contributor(){return mImpl->end__contributor();}
bool _validateBegin__contributor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__contributor();
bool _freeAttributes__contributor( void* attributeData );

bool _begin__author( void* attributeData ){return mImpl->begin__author();}
bool _data__author( const ParserChar* text, size_t textLength );
bool _end__author(){return mImpl->end__author();}
bool _validateBegin__author( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__author();
bool _freeAttributes__author( void* attributeData );

bool _begin__authoring_tool( void* attributeData ){return mImpl->begin__authoring_tool();}
bool _data__authoring_tool( const ParserChar* text, size_t textLength );
bool _end__authoring_tool(){return mImpl->end__authoring_tool();}
bool _validateBegin__authoring_tool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__authoring_tool();
bool _freeAttributes__authoring_tool( void* attributeData );

bool _begin__comments( void* attributeData ){return mImpl->begin__comments();}
bool _data__comments( const ParserChar* text, size_t textLength );
bool _end__comments(){return mImpl->end__comments();}
bool _validateBegin__comments( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__comments();
bool _freeAttributes__comments( void* attributeData );

bool _begin__copyright( void* attributeData ){return mImpl->begin__copyright();}
bool _data__copyright( const ParserChar* text, size_t textLength );
bool _end__copyright(){return mImpl->end__copyright();}
bool _validateBegin__copyright( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__copyright();
bool _freeAttributes__copyright( void* attributeData );

bool _begin__source_data( void* attributeData ){return mImpl->begin__source_data();}
bool _data__source_data( const ParserChar* text, size_t textLength );
bool _end__source_data(){return mImpl->end__source_data();}
bool _validateBegin__source_data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source_data();
bool _freeAttributes__source_data( void* attributeData );

bool _begin__created( void* attributeData ){return mImpl->begin__created();}
bool _data__created( const ParserChar* text, size_t textLength );
bool _end__created(){return mImpl->end__created();}
bool _validateBegin__created( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__created();
bool _freeAttributes__created( void* attributeData );

bool _begin__keywords( void* attributeData ){return mImpl->begin__keywords();}
bool _data__keywords( const ParserChar* text, size_t textLength );
bool _end__keywords(){return mImpl->end__keywords();}
bool _validateBegin__keywords( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__keywords();
bool _freeAttributes__keywords( void* attributeData );

bool _begin__modified( void* attributeData ){return mImpl->begin__modified();}
bool _data__modified( const ParserChar* text, size_t textLength );
bool _end__modified(){return mImpl->end__modified();}
bool _validateBegin__modified( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__modified();
bool _freeAttributes__modified( void* attributeData );

bool _begin__revision( void* attributeData ){return mImpl->begin__revision();}
bool _data__revision( const ParserChar* text, size_t textLength );
bool _end__revision(){return mImpl->end__revision();}
bool _validateBegin__revision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__revision();
bool _freeAttributes__revision( void* attributeData );

bool _begin__subject( void* attributeData ){return mImpl->begin__subject();}
bool _data__subject( const ParserChar* text, size_t textLength );
bool _end__subject(){return mImpl->end__subject();}
bool _validateBegin__subject( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__subject();
bool _freeAttributes__subject( void* attributeData );

bool _begin__title( void* attributeData ){return mImpl->begin__title();}
bool _data__title( const ParserChar* text, size_t textLength );
bool _end__title(){return mImpl->end__title();}
bool _validateBegin__title( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__title();
bool _freeAttributes__title( void* attributeData );

bool _begin__unit( void* attributeData ){return mImpl->begin__unit(*static_cast<unit__AttributeData*>(attributeData));}
bool _data__unit( const ParserChar* text, size_t textLength );
bool _end__unit(){return mImpl->end__unit();}
bool _validateBegin__unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__unit();
bool _freeAttributes__unit( void* attributeData );

bool _begin__up_axis( void* attributeData ){return mImpl->begin__up_axis();}
bool _data__up_axis( const ParserChar* text, size_t textLength );
bool _end__up_axis(){return mImpl->end__up_axis();}
bool _validateBegin__up_axis( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__up_axis();
bool _freeAttributes__up_axis( void* attributeData );


ENUM__UpAxisType toEnumDataPrefix_ENUM__UpAxisType (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__UpAxisType (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__UpAxisType*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__UpAxisType (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__UpAxisType*, size_t ),
    const std::pair<StringHash, ENUM__UpAxisType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__UpAxisType (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__UpAxisType>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__library_animations( void* attributeData ){return mImpl->begin__library_animations(*static_cast<library_animations__AttributeData*>(attributeData));}
bool _data__library_animations( const ParserChar* text, size_t textLength );
bool _end__library_animations(){return mImpl->end__library_animations();}
bool _validateBegin__library_animations( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_animations();
bool _freeAttributes__library_animations( void* attributeData );

bool _begin__animation( void* attributeData ){return mImpl->begin__animation(*static_cast<animation__AttributeData*>(attributeData));}
bool _data__animation( const ParserChar* text, size_t textLength );
bool _end__animation(){return mImpl->end__animation();}
bool _validateBegin__animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__animation();
bool _freeAttributes__animation( void* attributeData );

bool _begin__source( void* attributeData ){return mImpl->begin__source(*static_cast<source__AttributeData*>(attributeData));}
bool _data__source( const ParserChar* text, size_t textLength );
bool _end__source(){return mImpl->end__source();}
bool _validateBegin__source( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source();
bool _freeAttributes__source( void* attributeData );

bool _begin__IDREF_array( void* attributeData ){return mImpl->begin__IDREF_array(*static_cast<IDREF_array__AttributeData*>(attributeData));}
bool _data__IDREF_array( const ParserChar* text, size_t textLength );
bool _end__IDREF_array(){return mImpl->end__IDREF_array();}
bool _validateBegin__IDREF_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__IDREF_array();
bool _freeAttributes__IDREF_array( void* attributeData );

bool _begin__Name_array( void* attributeData ){return mImpl->begin__Name_array(*static_cast<Name_array__AttributeData*>(attributeData));}
bool _data__Name_array( const ParserChar* text, size_t textLength );
bool _end__Name_array(){return mImpl->end__Name_array();}
bool _validateBegin__Name_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__Name_array();
bool _freeAttributes__Name_array( void* attributeData );

bool _begin__bool_array( void* attributeData ){return mImpl->begin__bool_array(*static_cast<bool_array__AttributeData*>(attributeData));}
bool _data__bool_array( const ParserChar* text, size_t textLength );
bool _end__bool_array(){return mImpl->end__bool_array();}
bool _validateBegin__bool_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool_array();
bool _freeAttributes__bool_array( void* attributeData );

bool _begin__float_array( void* attributeData ){return mImpl->begin__float_array(*static_cast<float_array__AttributeData*>(attributeData));}
bool _data__float_array( const ParserChar* text, size_t textLength );
bool _end__float_array(){return mImpl->end__float_array();}
bool _validateBegin__float_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float_array();
bool _freeAttributes__float_array( void* attributeData );

bool _begin__int_array( void* attributeData ){return mImpl->begin__int_array(*static_cast<int_array__AttributeData*>(attributeData));}
bool _data__int_array( const ParserChar* text, size_t textLength );
bool _end__int_array(){return mImpl->end__int_array();}
bool _validateBegin__int_array( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int_array();
bool _freeAttributes__int_array( void* attributeData );

bool _begin__animation__source__technique_common( void* attributeData ){return mImpl->begin__animation__source__technique_common();}
bool _data__animation__source__technique_common( const ParserChar* text, size_t textLength );
bool _end__animation__source__technique_common(){return mImpl->end__animation__source__technique_common();}
bool _validateBegin__animation__source__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__animation__source__technique_common();
bool _freeAttributes__animation__source__technique_common( void* attributeData );

bool _begin__accessor( void* attributeData ){return mImpl->begin__accessor(*static_cast<accessor__AttributeData*>(attributeData));}
bool _data__accessor( const ParserChar* text, size_t textLength );
bool _end__accessor(){return mImpl->end__accessor();}
bool _validateBegin__accessor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__accessor();
bool _freeAttributes__accessor( void* attributeData );

bool _begin__param( void* attributeData ){return mImpl->begin__param(*static_cast<param__AttributeData*>(attributeData));}
bool _data__param( const ParserChar* text, size_t textLength );
bool _end__param(){return mImpl->end__param();}
bool _validateBegin__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param();
bool _freeAttributes__param( void* attributeData );

bool _begin__technique( void* attributeData ){return mImpl->begin__technique(*static_cast<technique__AttributeData*>(attributeData));}
bool _data__technique( const ParserChar* text, size_t textLength );
bool _end__technique(){return mImpl->end__technique();}
bool _validateBegin__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique();
bool _freeAttributes__technique( void* attributeData );

bool _begin__sampler( void* attributeData ){return mImpl->begin__sampler(*static_cast<sampler__AttributeData*>(attributeData));}
bool _data__sampler( const ParserChar* text, size_t textLength );
bool _end__sampler(){return mImpl->end__sampler();}
bool _validateBegin__sampler( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler();
bool _freeAttributes__sampler( void* attributeData );

bool _begin__input____InputLocal( void* attributeData ){return mImpl->begin__input____InputLocal(*static_cast<input____InputLocal__AttributeData*>(attributeData));}
bool _data__input____InputLocal( const ParserChar* text, size_t textLength );
bool _end__input____InputLocal(){return mImpl->end__input____InputLocal();}
bool _validateBegin__input____InputLocal( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__input____InputLocal();
bool _freeAttributes__input____InputLocal( void* attributeData );

bool _begin__channel( void* attributeData ){return mImpl->begin__channel(*static_cast<channel__AttributeData*>(attributeData));}
bool _data__channel( const ParserChar* text, size_t textLength );
bool _end__channel(){return mImpl->end__channel();}
bool _validateBegin__channel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__channel();
bool _freeAttributes__channel( void* attributeData );

bool _begin__extra( void* attributeData ){return mImpl->begin__extra(*static_cast<extra__AttributeData*>(attributeData));}
bool _data__extra( const ParserChar* text, size_t textLength );
bool _end__extra(){return mImpl->end__extra();}
bool _validateBegin__extra( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__extra();
bool _freeAttributes__extra( void* attributeData );

bool _begin__library_animation_clips( void* attributeData ){return mImpl->begin__library_animation_clips(*static_cast<library_animation_clips__AttributeData*>(attributeData));}
bool _data__library_animation_clips( const ParserChar* text, size_t textLength );
bool _end__library_animation_clips(){return mImpl->end__library_animation_clips();}
bool _validateBegin__library_animation_clips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_animation_clips();
bool _freeAttributes__library_animation_clips( void* attributeData );

bool _begin__animation_clip( void* attributeData ){return mImpl->begin__animation_clip(*static_cast<animation_clip__AttributeData*>(attributeData));}
bool _data__animation_clip( const ParserChar* text, size_t textLength );
bool _end__animation_clip(){return mImpl->end__animation_clip();}
bool _validateBegin__animation_clip( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__animation_clip();
bool _freeAttributes__animation_clip( void* attributeData );

bool _begin__instance_animation( void* attributeData ){return mImpl->begin__instance_animation(*static_cast<instance_animation__AttributeData*>(attributeData));}
bool _data__instance_animation( const ParserChar* text, size_t textLength );
bool _end__instance_animation(){return mImpl->end__instance_animation();}
bool _validateBegin__instance_animation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_animation();
bool _freeAttributes__instance_animation( void* attributeData );

bool _begin__library_cameras( void* attributeData ){return mImpl->begin__library_cameras(*static_cast<library_cameras__AttributeData*>(attributeData));}
bool _data__library_cameras( const ParserChar* text, size_t textLength );
bool _end__library_cameras(){return mImpl->end__library_cameras();}
bool _validateBegin__library_cameras( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_cameras();
bool _freeAttributes__library_cameras( void* attributeData );

bool _begin__camera( void* attributeData ){return mImpl->begin__camera(*static_cast<camera__AttributeData*>(attributeData));}
bool _data__camera( const ParserChar* text, size_t textLength );
bool _end__camera(){return mImpl->end__camera();}
bool _validateBegin__camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__camera();
bool _freeAttributes__camera( void* attributeData );

bool _begin__optics( void* attributeData ){return mImpl->begin__optics();}
bool _data__optics( const ParserChar* text, size_t textLength );
bool _end__optics(){return mImpl->end__optics();}
bool _validateBegin__optics( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__optics();
bool _freeAttributes__optics( void* attributeData );

bool _begin__optics__technique_common( void* attributeData ){return mImpl->begin__optics__technique_common();}
bool _data__optics__technique_common( const ParserChar* text, size_t textLength );
bool _end__optics__technique_common(){return mImpl->end__optics__technique_common();}
bool _validateBegin__optics__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__optics__technique_common();
bool _freeAttributes__optics__technique_common( void* attributeData );

bool _begin__orthographic( void* attributeData ){return mImpl->begin__orthographic();}
bool _data__orthographic( const ParserChar* text, size_t textLength );
bool _end__orthographic(){return mImpl->end__orthographic();}
bool _validateBegin__orthographic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__orthographic();
bool _freeAttributes__orthographic( void* attributeData );

bool _begin__xmag( void* attributeData ){return mImpl->begin__xmag(*static_cast<xmag__AttributeData*>(attributeData));}
bool _data__xmag( const ParserChar* text, size_t textLength );
bool _end__xmag(){return mImpl->end__xmag();}
bool _validateBegin__xmag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__xmag();
bool _freeAttributes__xmag( void* attributeData );

bool _begin__ymag( void* attributeData ){return mImpl->begin__ymag(*static_cast<ymag__AttributeData*>(attributeData));}
bool _data__ymag( const ParserChar* text, size_t textLength );
bool _end__ymag(){return mImpl->end__ymag();}
bool _validateBegin__ymag( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ymag();
bool _freeAttributes__ymag( void* attributeData );

bool _begin__aspect_ratio( void* attributeData ){return mImpl->begin__aspect_ratio(*static_cast<aspect_ratio__AttributeData*>(attributeData));}
bool _data__aspect_ratio( const ParserChar* text, size_t textLength );
bool _end__aspect_ratio(){return mImpl->end__aspect_ratio();}
bool _validateBegin__aspect_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__aspect_ratio();
bool _freeAttributes__aspect_ratio( void* attributeData );

bool _begin__znear( void* attributeData ){return mImpl->begin__znear(*static_cast<znear__AttributeData*>(attributeData));}
bool _data__znear( const ParserChar* text, size_t textLength );
bool _end__znear(){return mImpl->end__znear();}
bool _validateBegin__znear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__znear();
bool _freeAttributes__znear( void* attributeData );

bool _begin__zfar( void* attributeData ){return mImpl->begin__zfar(*static_cast<zfar__AttributeData*>(attributeData));}
bool _data__zfar( const ParserChar* text, size_t textLength );
bool _end__zfar(){return mImpl->end__zfar();}
bool _validateBegin__zfar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__zfar();
bool _freeAttributes__zfar( void* attributeData );

bool _begin__perspective( void* attributeData ){return mImpl->begin__perspective();}
bool _data__perspective( const ParserChar* text, size_t textLength );
bool _end__perspective(){return mImpl->end__perspective();}
bool _validateBegin__perspective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__perspective();
bool _freeAttributes__perspective( void* attributeData );

bool _begin__xfov( void* attributeData ){return mImpl->begin__xfov(*static_cast<xfov__AttributeData*>(attributeData));}
bool _data__xfov( const ParserChar* text, size_t textLength );
bool _end__xfov(){return mImpl->end__xfov();}
bool _validateBegin__xfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__xfov();
bool _freeAttributes__xfov( void* attributeData );

bool _begin__yfov( void* attributeData ){return mImpl->begin__yfov(*static_cast<yfov__AttributeData*>(attributeData));}
bool _data__yfov( const ParserChar* text, size_t textLength );
bool _end__yfov(){return mImpl->end__yfov();}
bool _validateBegin__yfov( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__yfov();
bool _freeAttributes__yfov( void* attributeData );

bool _begin__imager( void* attributeData ){return mImpl->begin__imager();}
bool _data__imager( const ParserChar* text, size_t textLength );
bool _end__imager(){return mImpl->end__imager();}
bool _validateBegin__imager( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__imager();
bool _freeAttributes__imager( void* attributeData );

bool _begin__library_controllers( void* attributeData ){return mImpl->begin__library_controllers(*static_cast<library_controllers__AttributeData*>(attributeData));}
bool _data__library_controllers( const ParserChar* text, size_t textLength );
bool _end__library_controllers(){return mImpl->end__library_controllers();}
bool _validateBegin__library_controllers( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_controllers();
bool _freeAttributes__library_controllers( void* attributeData );

bool _begin__controller( void* attributeData ){return mImpl->begin__controller(*static_cast<controller__AttributeData*>(attributeData));}
bool _data__controller( const ParserChar* text, size_t textLength );
bool _end__controller(){return mImpl->end__controller();}
bool _validateBegin__controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__controller();
bool _freeAttributes__controller( void* attributeData );

bool _begin__skin( void* attributeData ){return mImpl->begin__skin(*static_cast<skin__AttributeData*>(attributeData));}
bool _data__skin( const ParserChar* text, size_t textLength );
bool _end__skin(){return mImpl->end__skin();}
bool _validateBegin__skin( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skin();
bool _freeAttributes__skin( void* attributeData );

bool _begin__bind_shape_matrix( void* attributeData ){return mImpl->begin__bind_shape_matrix();}
bool _data__bind_shape_matrix( const ParserChar* text, size_t textLength );
bool _end__bind_shape_matrix(){return mImpl->end__bind_shape_matrix();}
bool _validateBegin__bind_shape_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_shape_matrix();
bool _freeAttributes__bind_shape_matrix( void* attributeData );

bool _begin__joints( void* attributeData ){return mImpl->begin__joints();}
bool _data__joints( const ParserChar* text, size_t textLength );
bool _end__joints(){return mImpl->end__joints();}
bool _validateBegin__joints( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__joints();
bool _freeAttributes__joints( void* attributeData );

bool _begin__vertex_weights( void* attributeData ){return mImpl->begin__vertex_weights(*static_cast<vertex_weights__AttributeData*>(attributeData));}
bool _data__vertex_weights( const ParserChar* text, size_t textLength );
bool _end__vertex_weights(){return mImpl->end__vertex_weights();}
bool _validateBegin__vertex_weights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vertex_weights();
bool _freeAttributes__vertex_weights( void* attributeData );

bool _begin__input____InputLocalOffset( void* attributeData ){return mImpl->begin__input____InputLocalOffset(*static_cast<input____InputLocalOffset__AttributeData*>(attributeData));}
bool _data__input____InputLocalOffset( const ParserChar* text, size_t textLength );
bool _end__input____InputLocalOffset(){return mImpl->end__input____InputLocalOffset();}
bool _validateBegin__input____InputLocalOffset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__input____InputLocalOffset();
bool _freeAttributes__input____InputLocalOffset( void* attributeData );

bool _begin__vcount( void* attributeData ){return mImpl->begin__vcount();}
bool _data__vcount( const ParserChar* text, size_t textLength );
bool _end__vcount(){return mImpl->end__vcount();}
bool _validateBegin__vcount( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vcount();
bool _freeAttributes__vcount( void* attributeData );

bool _begin__v( void* attributeData ){return mImpl->begin__v();}
bool _data__v( const ParserChar* text, size_t textLength );
bool _end__v(){return mImpl->end__v();}
bool _validateBegin__v( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__v();
bool _freeAttributes__v( void* attributeData );

bool _begin__morph( void* attributeData ){return mImpl->begin__morph(*static_cast<morph__AttributeData*>(attributeData));}
bool _data__morph( const ParserChar* text, size_t textLength );
bool _end__morph(){return mImpl->end__morph();}
bool _validateBegin__morph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__morph();
bool _freeAttributes__morph( void* attributeData );


ENUM__MorphMethodType toEnumDataPrefix_ENUM__MorphMethodType (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__MorphMethodType (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__MorphMethodType*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__MorphMethodType (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__MorphMethodType*, size_t ),
    const std::pair<StringHash, ENUM__MorphMethodType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__MorphMethodType (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__MorphMethodType>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__targets( void* attributeData ){return mImpl->begin__targets();}
bool _data__targets( const ParserChar* text, size_t textLength );
bool _end__targets(){return mImpl->end__targets();}
bool _validateBegin__targets( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__targets();
bool _freeAttributes__targets( void* attributeData );

bool _begin__library_geometries( void* attributeData ){return mImpl->begin__library_geometries(*static_cast<library_geometries__AttributeData*>(attributeData));}
bool _data__library_geometries( const ParserChar* text, size_t textLength );
bool _end__library_geometries(){return mImpl->end__library_geometries();}
bool _validateBegin__library_geometries( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_geometries();
bool _freeAttributes__library_geometries( void* attributeData );

bool _begin__geometry( void* attributeData ){return mImpl->begin__geometry(*static_cast<geometry__AttributeData*>(attributeData));}
bool _data__geometry( const ParserChar* text, size_t textLength );
bool _end__geometry(){return mImpl->end__geometry();}
bool _validateBegin__geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__geometry();
bool _freeAttributes__geometry( void* attributeData );

bool _begin__convex_mesh( void* attributeData ){return mImpl->begin__convex_mesh(*static_cast<convex_mesh__AttributeData*>(attributeData));}
bool _data__convex_mesh( const ParserChar* text, size_t textLength );
bool _end__convex_mesh(){return mImpl->end__convex_mesh();}
bool _validateBegin__convex_mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__convex_mesh();
bool _freeAttributes__convex_mesh( void* attributeData );

bool _begin__vertices( void* attributeData ){return mImpl->begin__vertices(*static_cast<vertices__AttributeData*>(attributeData));}
bool _data__vertices( const ParserChar* text, size_t textLength );
bool _end__vertices(){return mImpl->end__vertices();}
bool _validateBegin__vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__vertices();
bool _freeAttributes__vertices( void* attributeData );

bool _begin__lines( void* attributeData ){return mImpl->begin__lines(*static_cast<lines__AttributeData*>(attributeData));}
bool _data__lines( const ParserChar* text, size_t textLength );
bool _end__lines(){return mImpl->end__lines();}
bool _validateBegin__lines( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lines();
bool _freeAttributes__lines( void* attributeData );

bool _begin__p( void* attributeData ){return mImpl->begin__p();}
bool _data__p( const ParserChar* text, size_t textLength );
bool _end__p(){return mImpl->end__p();}
bool _validateBegin__p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__p();
bool _freeAttributes__p( void* attributeData );

bool _begin__linestrips( void* attributeData ){return mImpl->begin__linestrips(*static_cast<linestrips__AttributeData*>(attributeData));}
bool _data__linestrips( const ParserChar* text, size_t textLength );
bool _end__linestrips(){return mImpl->end__linestrips();}
bool _validateBegin__linestrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__linestrips();
bool _freeAttributes__linestrips( void* attributeData );

bool _begin__polygons( void* attributeData ){return mImpl->begin__polygons(*static_cast<polygons__AttributeData*>(attributeData));}
bool _data__polygons( const ParserChar* text, size_t textLength );
bool _end__polygons(){return mImpl->end__polygons();}
bool _validateBegin__polygons( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygons();
bool _freeAttributes__polygons( void* attributeData );

bool _begin__ph( void* attributeData ){return mImpl->begin__ph();}
bool _data__ph( const ParserChar* text, size_t textLength );
bool _end__ph(){return mImpl->end__ph();}
bool _validateBegin__ph( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ph();
bool _freeAttributes__ph( void* attributeData );

bool _begin__h( void* attributeData ){return mImpl->begin__h();}
bool _data__h( const ParserChar* text, size_t textLength );
bool _end__h(){return mImpl->end__h();}
bool _validateBegin__h( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__h();
bool _freeAttributes__h( void* attributeData );

bool _begin__polylist( void* attributeData ){return mImpl->begin__polylist(*static_cast<polylist__AttributeData*>(attributeData));}
bool _data__polylist( const ParserChar* text, size_t textLength );
bool _end__polylist(){return mImpl->end__polylist();}
bool _validateBegin__polylist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polylist();
bool _freeAttributes__polylist( void* attributeData );

bool _begin__triangles( void* attributeData ){return mImpl->begin__triangles(*static_cast<triangles__AttributeData*>(attributeData));}
bool _data__triangles( const ParserChar* text, size_t textLength );
bool _end__triangles(){return mImpl->end__triangles();}
bool _validateBegin__triangles( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__triangles();
bool _freeAttributes__triangles( void* attributeData );

bool _begin__trifans( void* attributeData ){return mImpl->begin__trifans(*static_cast<trifans__AttributeData*>(attributeData));}
bool _data__trifans( const ParserChar* text, size_t textLength );
bool _end__trifans(){return mImpl->end__trifans();}
bool _validateBegin__trifans( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__trifans();
bool _freeAttributes__trifans( void* attributeData );

bool _begin__tristrips( void* attributeData ){return mImpl->begin__tristrips(*static_cast<tristrips__AttributeData*>(attributeData));}
bool _data__tristrips( const ParserChar* text, size_t textLength );
bool _end__tristrips(){return mImpl->end__tristrips();}
bool _validateBegin__tristrips( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tristrips();
bool _freeAttributes__tristrips( void* attributeData );

bool _begin__mesh( void* attributeData ){return mImpl->begin__mesh();}
bool _data__mesh( const ParserChar* text, size_t textLength );
bool _end__mesh(){return mImpl->end__mesh();}
bool _validateBegin__mesh( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mesh();
bool _freeAttributes__mesh( void* attributeData );

bool _begin__spline( void* attributeData ){return mImpl->begin__spline(*static_cast<spline__AttributeData*>(attributeData));}
bool _data__spline( const ParserChar* text, size_t textLength );
bool _end__spline(){return mImpl->end__spline();}
bool _validateBegin__spline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spline();
bool _freeAttributes__spline( void* attributeData );

bool _begin__control_vertices( void* attributeData ){return mImpl->begin__control_vertices();}
bool _data__control_vertices( const ParserChar* text, size_t textLength );
bool _end__control_vertices(){return mImpl->end__control_vertices();}
bool _validateBegin__control_vertices( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__control_vertices();
bool _freeAttributes__control_vertices( void* attributeData );

bool _begin__library_effects( void* attributeData ){return mImpl->begin__library_effects(*static_cast<library_effects__AttributeData*>(attributeData));}
bool _data__library_effects( const ParserChar* text, size_t textLength );
bool _end__library_effects(){return mImpl->end__library_effects();}
bool _validateBegin__library_effects( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_effects();
bool _freeAttributes__library_effects( void* attributeData );

bool _begin__effect( void* attributeData ){return mImpl->begin__effect(*static_cast<effect__AttributeData*>(attributeData));}
bool _data__effect( const ParserChar* text, size_t textLength );
bool _end__effect(){return mImpl->end__effect();}
bool _validateBegin__effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__effect();
bool _freeAttributes__effect( void* attributeData );

bool _begin__annotate( void* attributeData ){return mImpl->begin__annotate(*static_cast<annotate__AttributeData*>(attributeData));}
bool _data__annotate( const ParserChar* text, size_t textLength );
bool _end__annotate(){return mImpl->end__annotate();}
bool _validateBegin__annotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__annotate();
bool _freeAttributes__annotate( void* attributeData );

bool _begin__bool____bool( void* attributeData ){return mImpl->begin__bool____bool();}
bool _data__bool____bool( const ParserChar* text, size_t textLength );
bool _end__bool____bool(){return mImpl->end__bool____bool();}
bool _validateBegin__bool____bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool____bool();
bool _freeAttributes__bool____bool( void* attributeData );

bool _begin__bool2____bool2( void* attributeData ){return mImpl->begin__bool2____bool2();}
bool _data__bool2____bool2( const ParserChar* text, size_t textLength );
bool _end__bool2____bool2(){return mImpl->end__bool2____bool2();}
bool _validateBegin__bool2____bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2____bool2();
bool _freeAttributes__bool2____bool2( void* attributeData );

bool _begin__bool3____bool3( void* attributeData ){return mImpl->begin__bool3____bool3();}
bool _data__bool3____bool3( const ParserChar* text, size_t textLength );
bool _end__bool3____bool3(){return mImpl->end__bool3____bool3();}
bool _validateBegin__bool3____bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3____bool3();
bool _freeAttributes__bool3____bool3( void* attributeData );

bool _begin__bool4____bool4( void* attributeData ){return mImpl->begin__bool4____bool4();}
bool _data__bool4____bool4( const ParserChar* text, size_t textLength );
bool _end__bool4____bool4(){return mImpl->end__bool4____bool4();}
bool _validateBegin__bool4____bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4____bool4();
bool _freeAttributes__bool4____bool4( void* attributeData );

bool _begin__int____int( void* attributeData ){return mImpl->begin__int____int();}
bool _data__int____int( const ParserChar* text, size_t textLength );
bool _end__int____int(){return mImpl->end__int____int();}
bool _validateBegin__int____int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int____int();
bool _freeAttributes__int____int( void* attributeData );

bool _begin__int2____int2( void* attributeData ){return mImpl->begin__int2____int2();}
bool _data__int2____int2( const ParserChar* text, size_t textLength );
bool _end__int2____int2(){return mImpl->end__int2____int2();}
bool _validateBegin__int2____int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2____int2();
bool _freeAttributes__int2____int2( void* attributeData );

bool _begin__int3____int3( void* attributeData ){return mImpl->begin__int3____int3();}
bool _data__int3____int3( const ParserChar* text, size_t textLength );
bool _end__int3____int3(){return mImpl->end__int3____int3();}
bool _validateBegin__int3____int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3____int3();
bool _freeAttributes__int3____int3( void* attributeData );

bool _begin__int4____int4( void* attributeData ){return mImpl->begin__int4____int4();}
bool _data__int4____int4( const ParserChar* text, size_t textLength );
bool _end__int4____int4(){return mImpl->end__int4____int4();}
bool _validateBegin__int4____int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4____int4();
bool _freeAttributes__int4____int4( void* attributeData );

bool _begin__float____float( void* attributeData ){return mImpl->begin__float____float();}
bool _data__float____float( const ParserChar* text, size_t textLength );
bool _end__float____float(){return mImpl->end__float____float();}
bool _validateBegin__float____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float____float();
bool _freeAttributes__float____float( void* attributeData );

bool _begin__float2____float2( void* attributeData ){return mImpl->begin__float2____float2();}
bool _data__float2____float2( const ParserChar* text, size_t textLength );
bool _end__float2____float2(){return mImpl->end__float2____float2();}
bool _validateBegin__float2____float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2____float2();
bool _freeAttributes__float2____float2( void* attributeData );

bool _begin__float3____float3( void* attributeData ){return mImpl->begin__float3____float3();}
bool _data__float3____float3( const ParserChar* text, size_t textLength );
bool _end__float3____float3(){return mImpl->end__float3____float3();}
bool _validateBegin__float3____float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3____float3();
bool _freeAttributes__float3____float3( void* attributeData );

bool _begin__float4____float4( void* attributeData ){return mImpl->begin__float4____float4();}
bool _data__float4____float4( const ParserChar* text, size_t textLength );
bool _end__float4____float4(){return mImpl->end__float4____float4();}
bool _validateBegin__float4____float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4____float4();
bool _freeAttributes__float4____float4( void* attributeData );

bool _begin__float2x2____float2x2( void* attributeData ){return mImpl->begin__float2x2____float2x2();}
bool _data__float2x2____float2x2( const ParserChar* text, size_t textLength );
bool _end__float2x2____float2x2(){return mImpl->end__float2x2____float2x2();}
bool _validateBegin__float2x2____float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x2____float2x2();
bool _freeAttributes__float2x2____float2x2( void* attributeData );

bool _begin__float3x3____float3x3( void* attributeData ){return mImpl->begin__float3x3____float3x3();}
bool _data__float3x3____float3x3( const ParserChar* text, size_t textLength );
bool _end__float3x3____float3x3(){return mImpl->end__float3x3____float3x3();}
bool _validateBegin__float3x3____float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x3____float3x3();
bool _freeAttributes__float3x3____float3x3( void* attributeData );

bool _begin__float4x4____float4x4( void* attributeData ){return mImpl->begin__float4x4____float4x4();}
bool _data__float4x4____float4x4( const ParserChar* text, size_t textLength );
bool _end__float4x4____float4x4(){return mImpl->end__float4x4____float4x4();}
bool _validateBegin__float4x4____float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x4____float4x4();
bool _freeAttributes__float4x4____float4x4( void* attributeData );

bool _begin__string( void* attributeData ){return mImpl->begin__string();}
bool _data__string( const ParserChar* text, size_t textLength );
bool _end__string(){return mImpl->end__string();}
bool _validateBegin__string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__string();
bool _freeAttributes__string( void* attributeData );

bool _begin__image( void* attributeData ){return mImpl->begin__image(*static_cast<image__AttributeData*>(attributeData));}
bool _data__image( const ParserChar* text, size_t textLength );
bool _end__image(){return mImpl->end__image();}
bool _validateBegin__image( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__image();
bool _freeAttributes__image( void* attributeData );

bool _begin__data( void* attributeData ){return mImpl->begin__data();}
bool _data__data( const ParserChar* text, size_t textLength );
bool _end__data(){return mImpl->end__data();}
bool _validateBegin__data( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__data();
bool _freeAttributes__data( void* attributeData );

bool _begin__init_from____anyURI( void* attributeData ){return mImpl->begin__init_from____anyURI();}
bool _data__init_from____anyURI( const ParserChar* text, size_t textLength );
bool _end__init_from____anyURI(){return mImpl->end__init_from____anyURI();}
bool _validateBegin__init_from____anyURI( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_from____anyURI();
bool _freeAttributes__init_from____anyURI( void* attributeData );

bool _begin__newparam____fx_newparam_common( void* attributeData ){return mImpl->begin__newparam____fx_newparam_common(*static_cast<newparam____fx_newparam_common__AttributeData*>(attributeData));}
bool _data__newparam____fx_newparam_common( const ParserChar* text, size_t textLength );
bool _end__newparam____fx_newparam_common(){return mImpl->end__newparam____fx_newparam_common();}
bool _validateBegin__newparam____fx_newparam_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____fx_newparam_common();
bool _freeAttributes__newparam____fx_newparam_common( void* attributeData );

bool _begin__semantic( void* attributeData ){return mImpl->begin__semantic();}
bool _data__semantic( const ParserChar* text, size_t textLength );
bool _end__semantic(){return mImpl->end__semantic();}
bool _validateBegin__semantic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__semantic();
bool _freeAttributes__semantic( void* attributeData );

bool _begin__modifier( void* attributeData ){return mImpl->begin__modifier();}
bool _data__modifier( const ParserChar* text, size_t textLength );
bool _end__modifier(){return mImpl->end__modifier();}
bool _validateBegin__modifier( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__modifier();
bool _freeAttributes__modifier( void* attributeData );


ENUM__fx_modifier_enum_common toEnumDataPrefix_ENUM__fx_modifier_enum_common (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_modifier_enum_common (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_modifier_enum_common*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_modifier_enum_common (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_modifier_enum_common*, size_t ),
    const std::pair<StringHash, ENUM__fx_modifier_enum_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_modifier_enum_common (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_modifier_enum_common>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__float1x1____float( void* attributeData ){return mImpl->begin__float1x1____float();}
bool _data__float1x1____float( const ParserChar* text, size_t textLength );
bool _end__float1x1____float(){return mImpl->end__float1x1____float();}
bool _validateBegin__float1x1____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x1____float();
bool _freeAttributes__float1x1____float( void* attributeData );

bool _begin__float1x2____float2( void* attributeData ){return mImpl->begin__float1x2____float2();}
bool _data__float1x2____float2( const ParserChar* text, size_t textLength );
bool _end__float1x2____float2(){return mImpl->end__float1x2____float2();}
bool _validateBegin__float1x2____float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x2____float2();
bool _freeAttributes__float1x2____float2( void* attributeData );

bool _begin__float1x3____float3( void* attributeData ){return mImpl->begin__float1x3____float3();}
bool _data__float1x3____float3( const ParserChar* text, size_t textLength );
bool _end__float1x3____float3(){return mImpl->end__float1x3____float3();}
bool _validateBegin__float1x3____float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x3____float3();
bool _freeAttributes__float1x3____float3( void* attributeData );

bool _begin__float1x4____float4( void* attributeData ){return mImpl->begin__float1x4____float4();}
bool _data__float1x4____float4( const ParserChar* text, size_t textLength );
bool _end__float1x4____float4(){return mImpl->end__float1x4____float4();}
bool _validateBegin__float1x4____float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x4____float4();
bool _freeAttributes__float1x4____float4( void* attributeData );

bool _begin__float2x1____float2( void* attributeData ){return mImpl->begin__float2x1____float2();}
bool _data__float2x1____float2( const ParserChar* text, size_t textLength );
bool _end__float2x1____float2(){return mImpl->end__float2x1____float2();}
bool _validateBegin__float2x1____float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x1____float2();
bool _freeAttributes__float2x1____float2( void* attributeData );

bool _begin__float2x3____float2x3( void* attributeData ){return mImpl->begin__float2x3____float2x3();}
bool _data__float2x3____float2x3( const ParserChar* text, size_t textLength );
bool _end__float2x3____float2x3(){return mImpl->end__float2x3____float2x3();}
bool _validateBegin__float2x3____float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x3____float2x3();
bool _freeAttributes__float2x3____float2x3( void* attributeData );

bool _begin__float2x4____float2x4( void* attributeData ){return mImpl->begin__float2x4____float2x4();}
bool _data__float2x4____float2x4( const ParserChar* text, size_t textLength );
bool _end__float2x4____float2x4(){return mImpl->end__float2x4____float2x4();}
bool _validateBegin__float2x4____float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x4____float2x4();
bool _freeAttributes__float2x4____float2x4( void* attributeData );

bool _begin__float3x1____float3( void* attributeData ){return mImpl->begin__float3x1____float3();}
bool _data__float3x1____float3( const ParserChar* text, size_t textLength );
bool _end__float3x1____float3(){return mImpl->end__float3x1____float3();}
bool _validateBegin__float3x1____float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x1____float3();
bool _freeAttributes__float3x1____float3( void* attributeData );

bool _begin__float3x2____float3x2( void* attributeData ){return mImpl->begin__float3x2____float3x2();}
bool _data__float3x2____float3x2( const ParserChar* text, size_t textLength );
bool _end__float3x2____float3x2(){return mImpl->end__float3x2____float3x2();}
bool _validateBegin__float3x2____float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x2____float3x2();
bool _freeAttributes__float3x2____float3x2( void* attributeData );

bool _begin__float3x4____float3x4( void* attributeData ){return mImpl->begin__float3x4____float3x4();}
bool _data__float3x4____float3x4( const ParserChar* text, size_t textLength );
bool _end__float3x4____float3x4(){return mImpl->end__float3x4____float3x4();}
bool _validateBegin__float3x4____float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x4____float3x4();
bool _freeAttributes__float3x4____float3x4( void* attributeData );

bool _begin__float4x1____float4( void* attributeData ){return mImpl->begin__float4x1____float4();}
bool _data__float4x1____float4( const ParserChar* text, size_t textLength );
bool _end__float4x1____float4(){return mImpl->end__float4x1____float4();}
bool _validateBegin__float4x1____float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x1____float4();
bool _freeAttributes__float4x1____float4( void* attributeData );

bool _begin__float4x2____float4x2( void* attributeData ){return mImpl->begin__float4x2____float4x2();}
bool _data__float4x2____float4x2( const ParserChar* text, size_t textLength );
bool _end__float4x2____float4x2(){return mImpl->end__float4x2____float4x2();}
bool _validateBegin__float4x2____float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x2____float4x2();
bool _freeAttributes__float4x2____float4x2( void* attributeData );

bool _begin__float4x3____float4x3( void* attributeData ){return mImpl->begin__float4x3____float4x3();}
bool _data__float4x3____float4x3( const ParserChar* text, size_t textLength );
bool _end__float4x3____float4x3(){return mImpl->end__float4x3____float4x3();}
bool _validateBegin__float4x3____float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x3____float4x3();
bool _freeAttributes__float4x3____float4x3( void* attributeData );

bool _begin__surface____fx_surface_common( void* attributeData ){return mImpl->begin__surface____fx_surface_common(*static_cast<surface____fx_surface_common__AttributeData*>(attributeData));}
bool _data__surface____fx_surface_common( const ParserChar* text, size_t textLength );
bool _end__surface____fx_surface_common(){return mImpl->end__surface____fx_surface_common();}
bool _validateBegin__surface____fx_surface_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface____fx_surface_common();
bool _freeAttributes__surface____fx_surface_common( void* attributeData );


ENUM__fx_surface_type_enum toEnumDataPrefix_ENUM__fx_surface_type_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_type_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_type_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_type_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_type_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_type_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_type_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_type_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__init_as_null( void* attributeData ){return mImpl->begin__init_as_null();}
bool _data__init_as_null( const ParserChar* text, size_t textLength );
bool _end__init_as_null(){return mImpl->end__init_as_null();}
bool _validateBegin__init_as_null( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_as_null();
bool _freeAttributes__init_as_null( void* attributeData );

bool _begin__init_as_target( void* attributeData ){return mImpl->begin__init_as_target();}
bool _data__init_as_target( const ParserChar* text, size_t textLength );
bool _end__init_as_target(){return mImpl->end__init_as_target();}
bool _validateBegin__init_as_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_as_target();
bool _freeAttributes__init_as_target( void* attributeData );

bool _begin__init_cube( void* attributeData ){return mImpl->begin__init_cube();}
bool _data__init_cube( const ParserChar* text, size_t textLength );
bool _end__init_cube(){return mImpl->end__init_cube();}
bool _validateBegin__init_cube( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_cube();
bool _freeAttributes__init_cube( void* attributeData );

bool _begin__fx_surface_init_cube_common____all( void* attributeData ){return mImpl->begin__fx_surface_init_cube_common____all(*static_cast<fx_surface_init_cube_common____all__AttributeData*>(attributeData));}
bool _data__fx_surface_init_cube_common____all( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_cube_common____all(){return mImpl->end__fx_surface_init_cube_common____all();}
bool _validateBegin__fx_surface_init_cube_common____all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_cube_common____all();
bool _freeAttributes__fx_surface_init_cube_common____all( void* attributeData );

bool _begin__fx_surface_init_cube_common____primary( void* attributeData ){return mImpl->begin__fx_surface_init_cube_common____primary(*static_cast<fx_surface_init_cube_common____primary__AttributeData*>(attributeData));}
bool _data__fx_surface_init_cube_common____primary( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_cube_common____primary(){return mImpl->end__fx_surface_init_cube_common____primary();}
bool _validateBegin__fx_surface_init_cube_common____primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_cube_common____primary();
bool _freeAttributes__fx_surface_init_cube_common____primary( void* attributeData );

bool _begin__order( void* attributeData ){return mImpl->begin__order();}
bool _data__order( const ParserChar* text, size_t textLength );
bool _end__order(){return mImpl->end__order();}
bool _validateBegin__order( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__order();
bool _freeAttributes__order( void* attributeData );


ENUM__fx_surface_face_enum toEnumDataPrefix_ENUM__fx_surface_face_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_face_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_face_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_face_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_face_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_face_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_face_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_face_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__fx_surface_init_cube_common____face( void* attributeData ){return mImpl->begin__fx_surface_init_cube_common____face(*static_cast<fx_surface_init_cube_common____face__AttributeData*>(attributeData));}
bool _data__fx_surface_init_cube_common____face( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_cube_common____face(){return mImpl->end__fx_surface_init_cube_common____face();}
bool _validateBegin__fx_surface_init_cube_common____face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_cube_common____face();
bool _freeAttributes__fx_surface_init_cube_common____face( void* attributeData );

bool _begin__init_volume( void* attributeData ){return mImpl->begin__init_volume();}
bool _data__init_volume( const ParserChar* text, size_t textLength );
bool _end__init_volume(){return mImpl->end__init_volume();}
bool _validateBegin__init_volume( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_volume();
bool _freeAttributes__init_volume( void* attributeData );

bool _begin__fx_surface_init_volume_common____all( void* attributeData ){return mImpl->begin__fx_surface_init_volume_common____all(*static_cast<fx_surface_init_volume_common____all__AttributeData*>(attributeData));}
bool _data__fx_surface_init_volume_common____all( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_volume_common____all(){return mImpl->end__fx_surface_init_volume_common____all();}
bool _validateBegin__fx_surface_init_volume_common____all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_volume_common____all();
bool _freeAttributes__fx_surface_init_volume_common____all( void* attributeData );

bool _begin__fx_surface_init_volume_common____primary( void* attributeData ){return mImpl->begin__fx_surface_init_volume_common____primary(*static_cast<fx_surface_init_volume_common____primary__AttributeData*>(attributeData));}
bool _data__fx_surface_init_volume_common____primary( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_volume_common____primary(){return mImpl->end__fx_surface_init_volume_common____primary();}
bool _validateBegin__fx_surface_init_volume_common____primary( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_volume_common____primary();
bool _freeAttributes__fx_surface_init_volume_common____primary( void* attributeData );

bool _begin__init_planar( void* attributeData ){return mImpl->begin__init_planar();}
bool _data__init_planar( const ParserChar* text, size_t textLength );
bool _end__init_planar(){return mImpl->end__init_planar();}
bool _validateBegin__init_planar( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_planar();
bool _freeAttributes__init_planar( void* attributeData );

bool _begin__fx_surface_init_planar_common____all( void* attributeData ){return mImpl->begin__fx_surface_init_planar_common____all(*static_cast<fx_surface_init_planar_common____all__AttributeData*>(attributeData));}
bool _data__fx_surface_init_planar_common____all( const ParserChar* text, size_t textLength );
bool _end__fx_surface_init_planar_common____all(){return mImpl->end__fx_surface_init_planar_common____all();}
bool _validateBegin__fx_surface_init_planar_common____all( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_surface_init_planar_common____all();
bool _freeAttributes__fx_surface_init_planar_common____all( void* attributeData );

bool _begin__init_from____fx_surface_init_from_common( void* attributeData ){return mImpl->begin__init_from____fx_surface_init_from_common(*static_cast<init_from____fx_surface_init_from_common__AttributeData*>(attributeData));}
bool _data__init_from____fx_surface_init_from_common( const ParserChar* text, size_t textLength );
bool _end__init_from____fx_surface_init_from_common(){return mImpl->end__init_from____fx_surface_init_from_common();}
bool _validateBegin__init_from____fx_surface_init_from_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__init_from____fx_surface_init_from_common();
bool _freeAttributes__init_from____fx_surface_init_from_common( void* attributeData );

bool _begin__format( void* attributeData ){return mImpl->begin__format();}
bool _data__format( const ParserChar* text, size_t textLength );
bool _end__format(){return mImpl->end__format();}
bool _validateBegin__format( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__format();
bool _freeAttributes__format( void* attributeData );

bool _begin__format_hint( void* attributeData ){return mImpl->begin__format_hint();}
bool _data__format_hint( const ParserChar* text, size_t textLength );
bool _end__format_hint(){return mImpl->end__format_hint();}
bool _validateBegin__format_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__format_hint();
bool _freeAttributes__format_hint( void* attributeData );

bool _begin__channels( void* attributeData ){return mImpl->begin__channels();}
bool _data__channels( const ParserChar* text, size_t textLength );
bool _end__channels(){return mImpl->end__channels();}
bool _validateBegin__channels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__channels();
bool _freeAttributes__channels( void* attributeData );


ENUM__fx_surface_format_hint_channels_enum toEnumDataPrefix_ENUM__fx_surface_format_hint_channels_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_format_hint_channels_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_channels_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_format_hint_channels_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_channels_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_format_hint_channels_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_format_hint_channels_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__range( void* attributeData ){return mImpl->begin__range();}
bool _data__range( const ParserChar* text, size_t textLength );
bool _end__range(){return mImpl->end__range();}
bool _validateBegin__range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__range();
bool _freeAttributes__range( void* attributeData );


ENUM__fx_surface_format_hint_range_enum toEnumDataPrefix_ENUM__fx_surface_format_hint_range_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_format_hint_range_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_range_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_format_hint_range_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_range_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_format_hint_range_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_format_hint_range_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__precision( void* attributeData ){return mImpl->begin__precision();}
bool _data__precision( const ParserChar* text, size_t textLength );
bool _end__precision(){return mImpl->end__precision();}
bool _validateBegin__precision( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__precision();
bool _freeAttributes__precision( void* attributeData );


ENUM__fx_surface_format_hint_precision_enum toEnumDataPrefix_ENUM__fx_surface_format_hint_precision_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_format_hint_precision_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_precision_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_format_hint_precision_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_precision_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_format_hint_precision_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_format_hint_precision_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__option( void* attributeData ){return mImpl->begin__option();}
bool _data__option( const ParserChar* text, size_t textLength );
bool _end__option(){return mImpl->end__option();}
bool _validateBegin__option( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__option();
bool _freeAttributes__option( void* attributeData );


ENUM__fx_surface_format_hint_option_enum toEnumDataPrefix_ENUM__fx_surface_format_hint_option_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_surface_format_hint_option_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_option_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_surface_format_hint_option_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_surface_format_hint_option_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_surface_format_hint_option_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_surface_format_hint_option_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__size____int3( void* attributeData ){return mImpl->begin__size____int3();}
bool _data__size____int3( const ParserChar* text, size_t textLength );
bool _end__size____int3(){return mImpl->end__size____int3();}
bool _validateBegin__size____int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__size____int3();
bool _freeAttributes__size____int3( void* attributeData );

bool _begin__viewport_ratio( void* attributeData ){return mImpl->begin__viewport_ratio();}
bool _data__viewport_ratio( const ParserChar* text, size_t textLength );
bool _end__viewport_ratio(){return mImpl->end__viewport_ratio();}
bool _validateBegin__viewport_ratio( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__viewport_ratio();
bool _freeAttributes__viewport_ratio( void* attributeData );

bool _begin__mip_levels( void* attributeData ){return mImpl->begin__mip_levels();}
bool _data__mip_levels( const ParserChar* text, size_t textLength );
bool _end__mip_levels(){return mImpl->end__mip_levels();}
bool _validateBegin__mip_levels( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mip_levels();
bool _freeAttributes__mip_levels( void* attributeData );

bool _begin__mipmap_generate( void* attributeData ){return mImpl->begin__mipmap_generate();}
bool _data__mipmap_generate( const ParserChar* text, size_t textLength );
bool _end__mipmap_generate(){return mImpl->end__mipmap_generate();}
bool _validateBegin__mipmap_generate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mipmap_generate();
bool _freeAttributes__mipmap_generate( void* attributeData );

bool _begin__sampler1D____fx_sampler1D_common( void* attributeData ){return mImpl->begin__sampler1D____fx_sampler1D_common();}
bool _data__sampler1D____fx_sampler1D_common( const ParserChar* text, size_t textLength );
bool _end__sampler1D____fx_sampler1D_common(){return mImpl->end__sampler1D____fx_sampler1D_common();}
bool _validateBegin__sampler1D____fx_sampler1D_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler1D____fx_sampler1D_common();
bool _freeAttributes__sampler1D____fx_sampler1D_common( void* attributeData );

bool _begin__source____NCName( void* attributeData ){return mImpl->begin__source____NCName();}
bool _data__source____NCName( const ParserChar* text, size_t textLength );
bool _end__source____NCName(){return mImpl->end__source____NCName();}
bool _validateBegin__source____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__source____NCName();
bool _freeAttributes__source____NCName( void* attributeData );

bool _begin__wrap_s____fx_sampler_wrap_common( void* attributeData ){return mImpl->begin__wrap_s____fx_sampler_wrap_common();}
bool _data__wrap_s____fx_sampler_wrap_common( const ParserChar* text, size_t textLength );
bool _end__wrap_s____fx_sampler_wrap_common(){return mImpl->end__wrap_s____fx_sampler_wrap_common();}
bool _validateBegin__wrap_s____fx_sampler_wrap_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_s____fx_sampler_wrap_common();
bool _freeAttributes__wrap_s____fx_sampler_wrap_common( void* attributeData );


ENUM__fx_sampler_wrap_common toEnumDataPrefix_ENUM__fx_sampler_wrap_common (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_wrap_common (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_sampler_wrap_common*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_wrap_common (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_sampler_wrap_common*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_wrap_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_wrap_common (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_wrap_common>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__minfilter( void* attributeData ){return mImpl->begin__minfilter();}
bool _data__minfilter( const ParserChar* text, size_t textLength );
bool _end__minfilter(){return mImpl->end__minfilter();}
bool _validateBegin__minfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__minfilter();
bool _freeAttributes__minfilter( void* attributeData );


ENUM__fx_sampler_filter_common toEnumDataPrefix_ENUM__fx_sampler_filter_common (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_sampler_filter_common (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_sampler_filter_common*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_sampler_filter_common (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_sampler_filter_common*, size_t ),
    const std::pair<StringHash, ENUM__fx_sampler_filter_common>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_sampler_filter_common (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_sampler_filter_common>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__magfilter( void* attributeData ){return mImpl->begin__magfilter();}
bool _data__magfilter( const ParserChar* text, size_t textLength );
bool _end__magfilter(){return mImpl->end__magfilter();}
bool _validateBegin__magfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__magfilter();
bool _freeAttributes__magfilter( void* attributeData );

bool _begin__mipfilter( void* attributeData ){return mImpl->begin__mipfilter();}
bool _data__mipfilter( const ParserChar* text, size_t textLength );
bool _end__mipfilter(){return mImpl->end__mipfilter();}
bool _validateBegin__mipfilter( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mipfilter();
bool _freeAttributes__mipfilter( void* attributeData );

bool _begin__border_color( void* attributeData ){return mImpl->begin__border_color();}
bool _data__border_color( const ParserChar* text, size_t textLength );
bool _end__border_color(){return mImpl->end__border_color();}
bool _validateBegin__border_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__border_color();
bool _freeAttributes__border_color( void* attributeData );

bool _begin__mipmap_maxlevel( void* attributeData ){return mImpl->begin__mipmap_maxlevel();}
bool _data__mipmap_maxlevel( const ParserChar* text, size_t textLength );
bool _end__mipmap_maxlevel(){return mImpl->end__mipmap_maxlevel();}
bool _validateBegin__mipmap_maxlevel( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mipmap_maxlevel();
bool _freeAttributes__mipmap_maxlevel( void* attributeData );

bool _begin__mipmap_bias( void* attributeData ){return mImpl->begin__mipmap_bias();}
bool _data__mipmap_bias( const ParserChar* text, size_t textLength );
bool _end__mipmap_bias(){return mImpl->end__mipmap_bias();}
bool _validateBegin__mipmap_bias( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mipmap_bias();
bool _freeAttributes__mipmap_bias( void* attributeData );

bool _begin__sampler2D____fx_sampler2D_common( void* attributeData ){return mImpl->begin__sampler2D____fx_sampler2D_common();}
bool _data__sampler2D____fx_sampler2D_common( const ParserChar* text, size_t textLength );
bool _end__sampler2D____fx_sampler2D_common(){return mImpl->end__sampler2D____fx_sampler2D_common();}
bool _validateBegin__sampler2D____fx_sampler2D_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler2D____fx_sampler2D_common();
bool _freeAttributes__sampler2D____fx_sampler2D_common( void* attributeData );

bool _begin__wrap_t____fx_sampler_wrap_common( void* attributeData ){return mImpl->begin__wrap_t____fx_sampler_wrap_common();}
bool _data__wrap_t____fx_sampler_wrap_common( const ParserChar* text, size_t textLength );
bool _end__wrap_t____fx_sampler_wrap_common(){return mImpl->end__wrap_t____fx_sampler_wrap_common();}
bool _validateBegin__wrap_t____fx_sampler_wrap_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_t____fx_sampler_wrap_common();
bool _freeAttributes__wrap_t____fx_sampler_wrap_common( void* attributeData );

bool _begin__sampler3D____fx_sampler3D_common( void* attributeData ){return mImpl->begin__sampler3D____fx_sampler3D_common();}
bool _data__sampler3D____fx_sampler3D_common( const ParserChar* text, size_t textLength );
bool _end__sampler3D____fx_sampler3D_common(){return mImpl->end__sampler3D____fx_sampler3D_common();}
bool _validateBegin__sampler3D____fx_sampler3D_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler3D____fx_sampler3D_common();
bool _freeAttributes__sampler3D____fx_sampler3D_common( void* attributeData );

bool _begin__wrap_p( void* attributeData ){return mImpl->begin__wrap_p();}
bool _data__wrap_p( const ParserChar* text, size_t textLength );
bool _end__wrap_p(){return mImpl->end__wrap_p();}
bool _validateBegin__wrap_p( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_p();
bool _freeAttributes__wrap_p( void* attributeData );

bool _begin__samplerCUBE____fx_samplerCUBE_common( void* attributeData ){return mImpl->begin__samplerCUBE____fx_samplerCUBE_common();}
bool _data__samplerCUBE____fx_samplerCUBE_common( const ParserChar* text, size_t textLength );
bool _end__samplerCUBE____fx_samplerCUBE_common(){return mImpl->end__samplerCUBE____fx_samplerCUBE_common();}
bool _validateBegin__samplerCUBE____fx_samplerCUBE_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerCUBE____fx_samplerCUBE_common();
bool _freeAttributes__samplerCUBE____fx_samplerCUBE_common( void* attributeData );

bool _begin__samplerRECT____fx_samplerRECT_common( void* attributeData ){return mImpl->begin__samplerRECT____fx_samplerRECT_common();}
bool _data__samplerRECT____fx_samplerRECT_common( const ParserChar* text, size_t textLength );
bool _end__samplerRECT____fx_samplerRECT_common(){return mImpl->end__samplerRECT____fx_samplerRECT_common();}
bool _validateBegin__samplerRECT____fx_samplerRECT_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerRECT____fx_samplerRECT_common();
bool _freeAttributes__samplerRECT____fx_samplerRECT_common( void* attributeData );

bool _begin__samplerDEPTH____fx_samplerDEPTH_common( void* attributeData ){return mImpl->begin__samplerDEPTH____fx_samplerDEPTH_common();}
bool _data__samplerDEPTH____fx_samplerDEPTH_common( const ParserChar* text, size_t textLength );
bool _end__samplerDEPTH____fx_samplerDEPTH_common(){return mImpl->end__samplerDEPTH____fx_samplerDEPTH_common();}
bool _validateBegin__samplerDEPTH____fx_samplerDEPTH_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerDEPTH____fx_samplerDEPTH_common();
bool _freeAttributes__samplerDEPTH____fx_samplerDEPTH_common( void* attributeData );

bool _begin__enum____string( void* attributeData ){return mImpl->begin__enum____string();}
bool _data__enum____string( const ParserChar* text, size_t textLength );
bool _end__enum____string(){return mImpl->end__enum____string();}
bool _validateBegin__enum____string( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____string();
bool _freeAttributes__enum____string( void* attributeData );

bool _begin__fx_profile_abstract( void* attributeData ){return mImpl->begin__fx_profile_abstract();}
bool _data__fx_profile_abstract( const ParserChar* text, size_t textLength );
bool _end__fx_profile_abstract(){return mImpl->end__fx_profile_abstract();}
bool _validateBegin__fx_profile_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fx_profile_abstract();
bool _freeAttributes__fx_profile_abstract( void* attributeData );

bool _begin__library_force_fields( void* attributeData ){return mImpl->begin__library_force_fields(*static_cast<library_force_fields__AttributeData*>(attributeData));}
bool _data__library_force_fields( const ParserChar* text, size_t textLength );
bool _end__library_force_fields(){return mImpl->end__library_force_fields();}
bool _validateBegin__library_force_fields( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_force_fields();
bool _freeAttributes__library_force_fields( void* attributeData );

bool _begin__force_field( void* attributeData ){return mImpl->begin__force_field(*static_cast<force_field__AttributeData*>(attributeData));}
bool _data__force_field( const ParserChar* text, size_t textLength );
bool _end__force_field(){return mImpl->end__force_field();}
bool _validateBegin__force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__force_field();
bool _freeAttributes__force_field( void* attributeData );

bool _begin__library_images( void* attributeData ){return mImpl->begin__library_images(*static_cast<library_images__AttributeData*>(attributeData));}
bool _data__library_images( const ParserChar* text, size_t textLength );
bool _end__library_images(){return mImpl->end__library_images();}
bool _validateBegin__library_images( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_images();
bool _freeAttributes__library_images( void* attributeData );

bool _begin__library_lights( void* attributeData ){return mImpl->begin__library_lights(*static_cast<library_lights__AttributeData*>(attributeData));}
bool _data__library_lights( const ParserChar* text, size_t textLength );
bool _end__library_lights(){return mImpl->end__library_lights();}
bool _validateBegin__library_lights( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_lights();
bool _freeAttributes__library_lights( void* attributeData );

bool _begin__light( void* attributeData ){return mImpl->begin__light(*static_cast<light__AttributeData*>(attributeData));}
bool _data__light( const ParserChar* text, size_t textLength );
bool _end__light(){return mImpl->end__light();}
bool _validateBegin__light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light();
bool _freeAttributes__light( void* attributeData );

bool _begin__light__technique_common( void* attributeData ){return mImpl->begin__light__technique_common();}
bool _data__light__technique_common( const ParserChar* text, size_t textLength );
bool _end__light__technique_common(){return mImpl->end__light__technique_common();}
bool _validateBegin__light__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light__technique_common();
bool _freeAttributes__light__technique_common( void* attributeData );

bool _begin__light__technique_common__ambient( void* attributeData ){return mImpl->begin__light__technique_common__ambient();}
bool _data__light__technique_common__ambient( const ParserChar* text, size_t textLength );
bool _end__light__technique_common__ambient(){return mImpl->end__light__technique_common__ambient();}
bool _validateBegin__light__technique_common__ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light__technique_common__ambient();
bool _freeAttributes__light__technique_common__ambient( void* attributeData );

bool _begin__color____TargetableFloat3( void* attributeData ){return mImpl->begin__color____TargetableFloat3(*static_cast<color____TargetableFloat3__AttributeData*>(attributeData));}
bool _data__color____TargetableFloat3( const ParserChar* text, size_t textLength );
bool _end__color____TargetableFloat3(){return mImpl->end__color____TargetableFloat3();}
bool _validateBegin__color____TargetableFloat3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color____TargetableFloat3();
bool _freeAttributes__color____TargetableFloat3( void* attributeData );

bool _begin__directional( void* attributeData ){return mImpl->begin__directional();}
bool _data__directional( const ParserChar* text, size_t textLength );
bool _end__directional(){return mImpl->end__directional();}
bool _validateBegin__directional( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__directional();
bool _freeAttributes__directional( void* attributeData );

bool _begin__point( void* attributeData ){return mImpl->begin__point();}
bool _data__point( const ParserChar* text, size_t textLength );
bool _end__point(){return mImpl->end__point();}
bool _validateBegin__point( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__point();
bool _freeAttributes__point( void* attributeData );

bool _begin__constant_attenuation( void* attributeData ){return mImpl->begin__constant_attenuation(*static_cast<constant_attenuation__AttributeData*>(attributeData));}
bool _data__constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__constant_attenuation(){return mImpl->end__constant_attenuation();}
bool _validateBegin__constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__constant_attenuation();
bool _freeAttributes__constant_attenuation( void* attributeData );

bool _begin__linear_attenuation( void* attributeData ){return mImpl->begin__linear_attenuation(*static_cast<linear_attenuation__AttributeData*>(attributeData));}
bool _data__linear_attenuation( const ParserChar* text, size_t textLength );
bool _end__linear_attenuation(){return mImpl->end__linear_attenuation();}
bool _validateBegin__linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__linear_attenuation();
bool _freeAttributes__linear_attenuation( void* attributeData );

bool _begin__quadratic_attenuation( void* attributeData ){return mImpl->begin__quadratic_attenuation(*static_cast<quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__quadratic_attenuation(){return mImpl->end__quadratic_attenuation();}
bool _validateBegin__quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__quadratic_attenuation();
bool _freeAttributes__quadratic_attenuation( void* attributeData );

bool _begin__spot( void* attributeData ){return mImpl->begin__spot();}
bool _data__spot( const ParserChar* text, size_t textLength );
bool _end__spot(){return mImpl->end__spot();}
bool _validateBegin__spot( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spot();
bool _freeAttributes__spot( void* attributeData );

bool _begin__falloff_angle( void* attributeData ){return mImpl->begin__falloff_angle(*static_cast<falloff_angle__AttributeData*>(attributeData));}
bool _data__falloff_angle( const ParserChar* text, size_t textLength );
bool _end__falloff_angle(){return mImpl->end__falloff_angle();}
bool _validateBegin__falloff_angle( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__falloff_angle();
bool _freeAttributes__falloff_angle( void* attributeData );

bool _begin__falloff_exponent( void* attributeData ){return mImpl->begin__falloff_exponent(*static_cast<falloff_exponent__AttributeData*>(attributeData));}
bool _data__falloff_exponent( const ParserChar* text, size_t textLength );
bool _end__falloff_exponent(){return mImpl->end__falloff_exponent();}
bool _validateBegin__falloff_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__falloff_exponent();
bool _freeAttributes__falloff_exponent( void* attributeData );

bool _begin__library_materials( void* attributeData ){return mImpl->begin__library_materials(*static_cast<library_materials__AttributeData*>(attributeData));}
bool _data__library_materials( const ParserChar* text, size_t textLength );
bool _end__library_materials(){return mImpl->end__library_materials();}
bool _validateBegin__library_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_materials();
bool _freeAttributes__library_materials( void* attributeData );

bool _begin__material( void* attributeData ){return mImpl->begin__material(*static_cast<material__AttributeData*>(attributeData));}
bool _data__material( const ParserChar* text, size_t textLength );
bool _end__material(){return mImpl->end__material();}
bool _validateBegin__material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__material();
bool _freeAttributes__material( void* attributeData );

bool _begin__instance_effect( void* attributeData ){return mImpl->begin__instance_effect(*static_cast<instance_effect__AttributeData*>(attributeData));}
bool _data__instance_effect( const ParserChar* text, size_t textLength );
bool _end__instance_effect(){return mImpl->end__instance_effect();}
bool _validateBegin__instance_effect( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_effect();
bool _freeAttributes__instance_effect( void* attributeData );

bool _begin__technique_hint( void* attributeData ){return mImpl->begin__technique_hint(*static_cast<technique_hint__AttributeData*>(attributeData));}
bool _data__technique_hint( const ParserChar* text, size_t textLength );
bool _end__technique_hint(){return mImpl->end__technique_hint();}
bool _validateBegin__technique_hint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__technique_hint();
bool _freeAttributes__technique_hint( void* attributeData );

bool _begin__instance_effect__setparam( void* attributeData ){return mImpl->begin__instance_effect__setparam(*static_cast<instance_effect__setparam__AttributeData*>(attributeData));}
bool _data__instance_effect__setparam( const ParserChar* text, size_t textLength );
bool _end__instance_effect__setparam(){return mImpl->end__instance_effect__setparam();}
bool _validateBegin__instance_effect__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_effect__setparam();
bool _freeAttributes__instance_effect__setparam( void* attributeData );

bool _begin__library_nodes( void* attributeData ){return mImpl->begin__library_nodes(*static_cast<library_nodes__AttributeData*>(attributeData));}
bool _data__library_nodes( const ParserChar* text, size_t textLength );
bool _end__library_nodes(){return mImpl->end__library_nodes();}
bool _validateBegin__library_nodes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_nodes();
bool _freeAttributes__library_nodes( void* attributeData );

bool _begin__node( void* attributeData ){return mImpl->begin__node(*static_cast<node__AttributeData*>(attributeData));}
bool _data__node( const ParserChar* text, size_t textLength );
bool _end__node(){return mImpl->end__node();}
bool _validateBegin__node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__node();
bool _freeAttributes__node( void* attributeData );


ENUM__NodeType toEnumDataPrefix_ENUM__NodeType (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__NodeType (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__NodeType*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__NodeType (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__NodeType*, size_t ),
    const std::pair<StringHash, ENUM__NodeType>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__NodeType (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__NodeType>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__lookat( void* attributeData ){return mImpl->begin__lookat(*static_cast<lookat__AttributeData*>(attributeData));}
bool _data__lookat( const ParserChar* text, size_t textLength );
bool _end__lookat(){return mImpl->end__lookat();}
bool _validateBegin__lookat( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lookat();
bool _freeAttributes__lookat( void* attributeData );

bool _begin__matrix( void* attributeData ){return mImpl->begin__matrix(*static_cast<matrix__AttributeData*>(attributeData));}
bool _data__matrix( const ParserChar* text, size_t textLength );
bool _end__matrix(){return mImpl->end__matrix();}
bool _validateBegin__matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__matrix();
bool _freeAttributes__matrix( void* attributeData );

bool _begin__rotate( void* attributeData ){return mImpl->begin__rotate(*static_cast<rotate__AttributeData*>(attributeData));}
bool _data__rotate( const ParserChar* text, size_t textLength );
bool _end__rotate(){return mImpl->end__rotate();}
bool _validateBegin__rotate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rotate();
bool _freeAttributes__rotate( void* attributeData );

bool _begin__scale( void* attributeData ){return mImpl->begin__scale(*static_cast<scale__AttributeData*>(attributeData));}
bool _data__scale( const ParserChar* text, size_t textLength );
bool _end__scale(){return mImpl->end__scale();}
bool _validateBegin__scale( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__scale();
bool _freeAttributes__scale( void* attributeData );

bool _begin__skew( void* attributeData ){return mImpl->begin__skew(*static_cast<skew__AttributeData*>(attributeData));}
bool _data__skew( const ParserChar* text, size_t textLength );
bool _end__skew(){return mImpl->end__skew();}
bool _validateBegin__skew( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skew();
bool _freeAttributes__skew( void* attributeData );

bool _begin__translate( void* attributeData ){return mImpl->begin__translate(*static_cast<translate__AttributeData*>(attributeData));}
bool _data__translate( const ParserChar* text, size_t textLength );
bool _end__translate(){return mImpl->end__translate();}
bool _validateBegin__translate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__translate();
bool _freeAttributes__translate( void* attributeData );

bool _begin__instance_camera( void* attributeData ){return mImpl->begin__instance_camera(*static_cast<instance_camera__AttributeData*>(attributeData));}
bool _data__instance_camera( const ParserChar* text, size_t textLength );
bool _end__instance_camera(){return mImpl->end__instance_camera();}
bool _validateBegin__instance_camera( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_camera();
bool _freeAttributes__instance_camera( void* attributeData );

bool _begin__instance_controller( void* attributeData ){return mImpl->begin__instance_controller(*static_cast<instance_controller__AttributeData*>(attributeData));}
bool _data__instance_controller( const ParserChar* text, size_t textLength );
bool _end__instance_controller(){return mImpl->end__instance_controller();}
bool _validateBegin__instance_controller( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_controller();
bool _freeAttributes__instance_controller( void* attributeData );

bool _begin__skeleton( void* attributeData ){return mImpl->begin__skeleton();}
bool _data__skeleton( const ParserChar* text, size_t textLength );
bool _end__skeleton(){return mImpl->end__skeleton();}
bool _validateBegin__skeleton( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__skeleton();
bool _freeAttributes__skeleton( void* attributeData );

bool _begin__bind_material( void* attributeData ){return mImpl->begin__bind_material();}
bool _data__bind_material( const ParserChar* text, size_t textLength );
bool _end__bind_material(){return mImpl->end__bind_material();}
bool _validateBegin__bind_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_material();
bool _freeAttributes__bind_material( void* attributeData );

bool _begin__bind_material__technique_common( void* attributeData ){return mImpl->begin__bind_material__technique_common();}
bool _data__bind_material__technique_common( const ParserChar* text, size_t textLength );
bool _end__bind_material__technique_common(){return mImpl->end__bind_material__technique_common();}
bool _validateBegin__bind_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_material__technique_common();
bool _freeAttributes__bind_material__technique_common( void* attributeData );

bool _begin__instance_material( void* attributeData ){return mImpl->begin__instance_material(*static_cast<instance_material__AttributeData*>(attributeData));}
bool _data__instance_material( const ParserChar* text, size_t textLength );
bool _end__instance_material(){return mImpl->end__instance_material();}
bool _validateBegin__instance_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_material();
bool _freeAttributes__instance_material( void* attributeData );

bool _begin__instance_material__bind( void* attributeData ){return mImpl->begin__instance_material__bind(*static_cast<instance_material__bind__AttributeData*>(attributeData));}
bool _data__instance_material__bind( const ParserChar* text, size_t textLength );
bool _end__instance_material__bind(){return mImpl->end__instance_material__bind();}
bool _validateBegin__instance_material__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_material__bind();
bool _freeAttributes__instance_material__bind( void* attributeData );

bool _begin__bind_vertex_input( void* attributeData ){return mImpl->begin__bind_vertex_input(*static_cast<bind_vertex_input__AttributeData*>(attributeData));}
bool _data__bind_vertex_input( const ParserChar* text, size_t textLength );
bool _end__bind_vertex_input(){return mImpl->end__bind_vertex_input();}
bool _validateBegin__bind_vertex_input( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bind_vertex_input();
bool _freeAttributes__bind_vertex_input( void* attributeData );

bool _begin__instance_geometry( void* attributeData ){return mImpl->begin__instance_geometry(*static_cast<instance_geometry__AttributeData*>(attributeData));}
bool _data__instance_geometry( const ParserChar* text, size_t textLength );
bool _end__instance_geometry(){return mImpl->end__instance_geometry();}
bool _validateBegin__instance_geometry( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_geometry();
bool _freeAttributes__instance_geometry( void* attributeData );

bool _begin__instance_light( void* attributeData ){return mImpl->begin__instance_light(*static_cast<instance_light__AttributeData*>(attributeData));}
bool _data__instance_light( const ParserChar* text, size_t textLength );
bool _end__instance_light(){return mImpl->end__instance_light();}
bool _validateBegin__instance_light( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_light();
bool _freeAttributes__instance_light( void* attributeData );

bool _begin__instance_node( void* attributeData ){return mImpl->begin__instance_node(*static_cast<instance_node__AttributeData*>(attributeData));}
bool _data__instance_node( const ParserChar* text, size_t textLength );
bool _end__instance_node(){return mImpl->end__instance_node();}
bool _validateBegin__instance_node( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_node();
bool _freeAttributes__instance_node( void* attributeData );

bool _begin__library_physics_materials( void* attributeData ){return mImpl->begin__library_physics_materials(*static_cast<library_physics_materials__AttributeData*>(attributeData));}
bool _data__library_physics_materials( const ParserChar* text, size_t textLength );
bool _end__library_physics_materials(){return mImpl->end__library_physics_materials();}
bool _validateBegin__library_physics_materials( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_materials();
bool _freeAttributes__library_physics_materials( void* attributeData );

bool _begin__physics_material( void* attributeData ){return mImpl->begin__physics_material(*static_cast<physics_material__AttributeData*>(attributeData));}
bool _data__physics_material( const ParserChar* text, size_t textLength );
bool _end__physics_material(){return mImpl->end__physics_material();}
bool _validateBegin__physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_material();
bool _freeAttributes__physics_material( void* attributeData );

bool _begin__physics_material__technique_common( void* attributeData ){return mImpl->begin__physics_material__technique_common();}
bool _data__physics_material__technique_common( const ParserChar* text, size_t textLength );
bool _end__physics_material__technique_common(){return mImpl->end__physics_material__technique_common();}
bool _validateBegin__physics_material__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_material__technique_common();
bool _freeAttributes__physics_material__technique_common( void* attributeData );

bool _begin__dynamic_friction( void* attributeData ){return mImpl->begin__dynamic_friction(*static_cast<dynamic_friction__AttributeData*>(attributeData));}
bool _data__dynamic_friction( const ParserChar* text, size_t textLength );
bool _end__dynamic_friction(){return mImpl->end__dynamic_friction();}
bool _validateBegin__dynamic_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__dynamic_friction();
bool _freeAttributes__dynamic_friction( void* attributeData );

bool _begin__restitution( void* attributeData ){return mImpl->begin__restitution(*static_cast<restitution__AttributeData*>(attributeData));}
bool _data__restitution( const ParserChar* text, size_t textLength );
bool _end__restitution(){return mImpl->end__restitution();}
bool _validateBegin__restitution( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__restitution();
bool _freeAttributes__restitution( void* attributeData );

bool _begin__static_friction( void* attributeData ){return mImpl->begin__static_friction(*static_cast<static_friction__AttributeData*>(attributeData));}
bool _data__static_friction( const ParserChar* text, size_t textLength );
bool _end__static_friction(){return mImpl->end__static_friction();}
bool _validateBegin__static_friction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__static_friction();
bool _freeAttributes__static_friction( void* attributeData );

bool _begin__library_physics_models( void* attributeData ){return mImpl->begin__library_physics_models(*static_cast<library_physics_models__AttributeData*>(attributeData));}
bool _data__library_physics_models( const ParserChar* text, size_t textLength );
bool _end__library_physics_models(){return mImpl->end__library_physics_models();}
bool _validateBegin__library_physics_models( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_models();
bool _freeAttributes__library_physics_models( void* attributeData );

bool _begin__physics_model( void* attributeData ){return mImpl->begin__physics_model(*static_cast<physics_model__AttributeData*>(attributeData));}
bool _data__physics_model( const ParserChar* text, size_t textLength );
bool _end__physics_model(){return mImpl->end__physics_model();}
bool _validateBegin__physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_model();
bool _freeAttributes__physics_model( void* attributeData );

bool _begin__rigid_body( void* attributeData ){return mImpl->begin__rigid_body(*static_cast<rigid_body__AttributeData*>(attributeData));}
bool _data__rigid_body( const ParserChar* text, size_t textLength );
bool _end__rigid_body(){return mImpl->end__rigid_body();}
bool _validateBegin__rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body();
bool _freeAttributes__rigid_body( void* attributeData );

bool _begin__rigid_body__technique_common( void* attributeData ){return mImpl->begin__rigid_body__technique_common();}
bool _data__rigid_body__technique_common( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common(){return mImpl->end__rigid_body__technique_common();}
bool _validateBegin__rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common();
bool _freeAttributes__rigid_body__technique_common( void* attributeData );

bool _begin__rigid_body__technique_common__dynamic( void* attributeData ){return mImpl->begin__rigid_body__technique_common__dynamic(*static_cast<rigid_body__technique_common__dynamic__AttributeData*>(attributeData));}
bool _data__rigid_body__technique_common__dynamic( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__dynamic(){return mImpl->end__rigid_body__technique_common__dynamic();}
bool _validateBegin__rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__dynamic();
bool _freeAttributes__rigid_body__technique_common__dynamic( void* attributeData );

bool _begin__mass( void* attributeData ){return mImpl->begin__mass(*static_cast<mass__AttributeData*>(attributeData));}
bool _data__mass( const ParserChar* text, size_t textLength );
bool _end__mass(){return mImpl->end__mass();}
bool _validateBegin__mass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__mass();
bool _freeAttributes__mass( void* attributeData );

bool _begin__rigid_body__technique_common__mass_frame( void* attributeData ){return mImpl->begin__rigid_body__technique_common__mass_frame();}
bool _data__rigid_body__technique_common__mass_frame( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__mass_frame(){return mImpl->end__rigid_body__technique_common__mass_frame();}
bool _validateBegin__rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__mass_frame();
bool _freeAttributes__rigid_body__technique_common__mass_frame( void* attributeData );

bool _begin__inertia( void* attributeData ){return mImpl->begin__inertia(*static_cast<inertia__AttributeData*>(attributeData));}
bool _data__inertia( const ParserChar* text, size_t textLength );
bool _end__inertia(){return mImpl->end__inertia();}
bool _validateBegin__inertia( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__inertia();
bool _freeAttributes__inertia( void* attributeData );

bool _begin__instance_physics_material( void* attributeData ){return mImpl->begin__instance_physics_material(*static_cast<instance_physics_material__AttributeData*>(attributeData));}
bool _data__instance_physics_material( const ParserChar* text, size_t textLength );
bool _end__instance_physics_material(){return mImpl->end__instance_physics_material();}
bool _validateBegin__instance_physics_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_material();
bool _freeAttributes__instance_physics_material( void* attributeData );

bool _begin__rigid_body__technique_common__shape( void* attributeData ){return mImpl->begin__rigid_body__technique_common__shape();}
bool _data__rigid_body__technique_common__shape( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__shape(){return mImpl->end__rigid_body__technique_common__shape();}
bool _validateBegin__rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__shape();
bool _freeAttributes__rigid_body__technique_common__shape( void* attributeData );

bool _begin__rigid_body__technique_common__shape__hollow( void* attributeData ){return mImpl->begin__rigid_body__technique_common__shape__hollow(*static_cast<rigid_body__technique_common__shape__hollow__AttributeData*>(attributeData));}
bool _data__rigid_body__technique_common__shape__hollow( const ParserChar* text, size_t textLength );
bool _end__rigid_body__technique_common__shape__hollow(){return mImpl->end__rigid_body__technique_common__shape__hollow();}
bool _validateBegin__rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_body__technique_common__shape__hollow();
bool _freeAttributes__rigid_body__technique_common__shape__hollow( void* attributeData );

bool _begin__density( void* attributeData ){return mImpl->begin__density(*static_cast<density__AttributeData*>(attributeData));}
bool _data__density( const ParserChar* text, size_t textLength );
bool _end__density(){return mImpl->end__density();}
bool _validateBegin__density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__density();
bool _freeAttributes__density( void* attributeData );

bool _begin__plane( void* attributeData ){return mImpl->begin__plane();}
bool _data__plane( const ParserChar* text, size_t textLength );
bool _end__plane(){return mImpl->end__plane();}
bool _validateBegin__plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__plane();
bool _freeAttributes__plane( void* attributeData );

bool _begin__equation( void* attributeData ){return mImpl->begin__equation();}
bool _data__equation( const ParserChar* text, size_t textLength );
bool _end__equation(){return mImpl->end__equation();}
bool _validateBegin__equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__equation();
bool _freeAttributes__equation( void* attributeData );

bool _begin__box( void* attributeData ){return mImpl->begin__box();}
bool _data__box( const ParserChar* text, size_t textLength );
bool _end__box(){return mImpl->end__box();}
bool _validateBegin__box( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__box();
bool _freeAttributes__box( void* attributeData );

bool _begin__half_extents( void* attributeData ){return mImpl->begin__half_extents();}
bool _data__half_extents( const ParserChar* text, size_t textLength );
bool _end__half_extents(){return mImpl->end__half_extents();}
bool _validateBegin__half_extents( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half_extents();
bool _freeAttributes__half_extents( void* attributeData );

bool _begin__sphere( void* attributeData ){return mImpl->begin__sphere();}
bool _data__sphere( const ParserChar* text, size_t textLength );
bool _end__sphere(){return mImpl->end__sphere();}
bool _validateBegin__sphere( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sphere();
bool _freeAttributes__sphere( void* attributeData );

bool _begin__radius____float( void* attributeData ){return mImpl->begin__radius____float();}
bool _data__radius____float( const ParserChar* text, size_t textLength );
bool _end__radius____float(){return mImpl->end__radius____float();}
bool _validateBegin__radius____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius____float();
bool _freeAttributes__radius____float( void* attributeData );

bool _begin__cylinder( void* attributeData ){return mImpl->begin__cylinder();}
bool _data__cylinder( const ParserChar* text, size_t textLength );
bool _end__cylinder(){return mImpl->end__cylinder();}
bool _validateBegin__cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cylinder();
bool _freeAttributes__cylinder( void* attributeData );

bool _begin__height( void* attributeData ){return mImpl->begin__height();}
bool _data__height( const ParserChar* text, size_t textLength );
bool _end__height(){return mImpl->end__height();}
bool _validateBegin__height( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__height();
bool _freeAttributes__height( void* attributeData );

bool _begin__radius____float2( void* attributeData ){return mImpl->begin__radius____float2();}
bool _data__radius____float2( const ParserChar* text, size_t textLength );
bool _end__radius____float2(){return mImpl->end__radius____float2();}
bool _validateBegin__radius____float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius____float2();
bool _freeAttributes__radius____float2( void* attributeData );

bool _begin__tapered_cylinder( void* attributeData ){return mImpl->begin__tapered_cylinder();}
bool _data__tapered_cylinder( const ParserChar* text, size_t textLength );
bool _end__tapered_cylinder(){return mImpl->end__tapered_cylinder();}
bool _validateBegin__tapered_cylinder( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tapered_cylinder();
bool _freeAttributes__tapered_cylinder( void* attributeData );

bool _begin__radius1( void* attributeData ){return mImpl->begin__radius1();}
bool _data__radius1( const ParserChar* text, size_t textLength );
bool _end__radius1(){return mImpl->end__radius1();}
bool _validateBegin__radius1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius1();
bool _freeAttributes__radius1( void* attributeData );

bool _begin__radius2( void* attributeData ){return mImpl->begin__radius2();}
bool _data__radius2( const ParserChar* text, size_t textLength );
bool _end__radius2(){return mImpl->end__radius2();}
bool _validateBegin__radius2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__radius2();
bool _freeAttributes__radius2( void* attributeData );

bool _begin__capsule( void* attributeData ){return mImpl->begin__capsule();}
bool _data__capsule( const ParserChar* text, size_t textLength );
bool _end__capsule(){return mImpl->end__capsule();}
bool _validateBegin__capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__capsule();
bool _freeAttributes__capsule( void* attributeData );

bool _begin__tapered_capsule( void* attributeData ){return mImpl->begin__tapered_capsule();}
bool _data__tapered_capsule( const ParserChar* text, size_t textLength );
bool _end__tapered_capsule(){return mImpl->end__tapered_capsule();}
bool _validateBegin__tapered_capsule( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__tapered_capsule();
bool _freeAttributes__tapered_capsule( void* attributeData );

bool _begin__rigid_constraint( void* attributeData ){return mImpl->begin__rigid_constraint(*static_cast<rigid_constraint__AttributeData*>(attributeData));}
bool _data__rigid_constraint( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint(){return mImpl->end__rigid_constraint();}
bool _validateBegin__rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint();
bool _freeAttributes__rigid_constraint( void* attributeData );

bool _begin__ref_attachment( void* attributeData ){return mImpl->begin__ref_attachment(*static_cast<ref_attachment__AttributeData*>(attributeData));}
bool _data__ref_attachment( const ParserChar* text, size_t textLength );
bool _end__ref_attachment(){return mImpl->end__ref_attachment();}
bool _validateBegin__ref_attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ref_attachment();
bool _freeAttributes__ref_attachment( void* attributeData );

bool _begin__attachment( void* attributeData ){return mImpl->begin__attachment(*static_cast<attachment__AttributeData*>(attributeData));}
bool _data__attachment( const ParserChar* text, size_t textLength );
bool _end__attachment(){return mImpl->end__attachment();}
bool _validateBegin__attachment( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__attachment();
bool _freeAttributes__attachment( void* attributeData );

bool _begin__rigid_constraint__technique_common( void* attributeData ){return mImpl->begin__rigid_constraint__technique_common();}
bool _data__rigid_constraint__technique_common( const ParserChar* text, size_t textLength );
bool _end__rigid_constraint__technique_common(){return mImpl->end__rigid_constraint__technique_common();}
bool _validateBegin__rigid_constraint__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rigid_constraint__technique_common();
bool _freeAttributes__rigid_constraint__technique_common( void* attributeData );

bool _begin__enabled( void* attributeData ){return mImpl->begin__enabled(*static_cast<enabled__AttributeData*>(attributeData));}
bool _data__enabled( const ParserChar* text, size_t textLength );
bool _end__enabled(){return mImpl->end__enabled();}
bool _validateBegin__enabled( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enabled();
bool _freeAttributes__enabled( void* attributeData );

bool _begin__interpenetrate( void* attributeData ){return mImpl->begin__interpenetrate(*static_cast<interpenetrate__AttributeData*>(attributeData));}
bool _data__interpenetrate( const ParserChar* text, size_t textLength );
bool _end__interpenetrate(){return mImpl->end__interpenetrate();}
bool _validateBegin__interpenetrate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__interpenetrate();
bool _freeAttributes__interpenetrate( void* attributeData );

bool _begin__limits( void* attributeData ){return mImpl->begin__limits();}
bool _data__limits( const ParserChar* text, size_t textLength );
bool _end__limits(){return mImpl->end__limits();}
bool _validateBegin__limits( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__limits();
bool _freeAttributes__limits( void* attributeData );

bool _begin__swing_cone_and_twist( void* attributeData ){return mImpl->begin__swing_cone_and_twist();}
bool _data__swing_cone_and_twist( const ParserChar* text, size_t textLength );
bool _end__swing_cone_and_twist(){return mImpl->end__swing_cone_and_twist();}
bool _validateBegin__swing_cone_and_twist( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__swing_cone_and_twist();
bool _freeAttributes__swing_cone_and_twist( void* attributeData );

bool _begin__min( void* attributeData ){return mImpl->begin__min(*static_cast<min__AttributeData*>(attributeData));}
bool _data__min( const ParserChar* text, size_t textLength );
bool _end__min(){return mImpl->end__min();}
bool _validateBegin__min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__min();
bool _freeAttributes__min( void* attributeData );

bool _begin__max( void* attributeData ){return mImpl->begin__max(*static_cast<max__AttributeData*>(attributeData));}
bool _data__max( const ParserChar* text, size_t textLength );
bool _end__max(){return mImpl->end__max();}
bool _validateBegin__max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__max();
bool _freeAttributes__max( void* attributeData );

bool _begin__limits__linear( void* attributeData ){return mImpl->begin__limits__linear();}
bool _data__limits__linear( const ParserChar* text, size_t textLength );
bool _end__limits__linear(){return mImpl->end__limits__linear();}
bool _validateBegin__limits__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__limits__linear();
bool _freeAttributes__limits__linear( void* attributeData );

bool _begin__spring( void* attributeData ){return mImpl->begin__spring();}
bool _data__spring( const ParserChar* text, size_t textLength );
bool _end__spring(){return mImpl->end__spring();}
bool _validateBegin__spring( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spring();
bool _freeAttributes__spring( void* attributeData );

bool _begin__angular( void* attributeData ){return mImpl->begin__angular();}
bool _data__angular( const ParserChar* text, size_t textLength );
bool _end__angular(){return mImpl->end__angular();}
bool _validateBegin__angular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__angular();
bool _freeAttributes__angular( void* attributeData );

bool _begin__stiffness( void* attributeData ){return mImpl->begin__stiffness(*static_cast<stiffness__AttributeData*>(attributeData));}
bool _data__stiffness( const ParserChar* text, size_t textLength );
bool _end__stiffness(){return mImpl->end__stiffness();}
bool _validateBegin__stiffness( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stiffness();
bool _freeAttributes__stiffness( void* attributeData );

bool _begin__damping( void* attributeData ){return mImpl->begin__damping(*static_cast<damping__AttributeData*>(attributeData));}
bool _data__damping( const ParserChar* text, size_t textLength );
bool _end__damping(){return mImpl->end__damping();}
bool _validateBegin__damping( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__damping();
bool _freeAttributes__damping( void* attributeData );

bool _begin__target_value( void* attributeData ){return mImpl->begin__target_value(*static_cast<target_value__AttributeData*>(attributeData));}
bool _data__target_value( const ParserChar* text, size_t textLength );
bool _end__target_value(){return mImpl->end__target_value();}
bool _validateBegin__target_value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__target_value();
bool _freeAttributes__target_value( void* attributeData );

bool _begin__spring__linear( void* attributeData ){return mImpl->begin__spring__linear();}
bool _data__spring__linear( const ParserChar* text, size_t textLength );
bool _end__spring__linear(){return mImpl->end__spring__linear();}
bool _validateBegin__spring__linear( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__spring__linear();
bool _freeAttributes__spring__linear( void* attributeData );

bool _begin__instance_physics_model( void* attributeData ){return mImpl->begin__instance_physics_model(*static_cast<instance_physics_model__AttributeData*>(attributeData));}
bool _data__instance_physics_model( const ParserChar* text, size_t textLength );
bool _end__instance_physics_model(){return mImpl->end__instance_physics_model();}
bool _validateBegin__instance_physics_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_model();
bool _freeAttributes__instance_physics_model( void* attributeData );

bool _begin__instance_force_field( void* attributeData ){return mImpl->begin__instance_force_field(*static_cast<instance_force_field__AttributeData*>(attributeData));}
bool _data__instance_force_field( const ParserChar* text, size_t textLength );
bool _end__instance_force_field(){return mImpl->end__instance_force_field();}
bool _validateBegin__instance_force_field( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_force_field();
bool _freeAttributes__instance_force_field( void* attributeData );

bool _begin__instance_rigid_body( void* attributeData ){return mImpl->begin__instance_rigid_body(*static_cast<instance_rigid_body__AttributeData*>(attributeData));}
bool _data__instance_rigid_body( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body(){return mImpl->end__instance_rigid_body();}
bool _validateBegin__instance_rigid_body( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body();
bool _freeAttributes__instance_rigid_body( void* attributeData );

bool _begin__instance_rigid_body__technique_common( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common();}
bool _data__instance_rigid_body__technique_common( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common(){return mImpl->end__instance_rigid_body__technique_common();}
bool _validateBegin__instance_rigid_body__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common();
bool _freeAttributes__instance_rigid_body__technique_common( void* attributeData );

bool _begin__angular_velocity( void* attributeData ){return mImpl->begin__angular_velocity();}
bool _data__angular_velocity( const ParserChar* text, size_t textLength );
bool _end__angular_velocity(){return mImpl->end__angular_velocity();}
bool _validateBegin__angular_velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__angular_velocity();
bool _freeAttributes__angular_velocity( void* attributeData );

bool _begin__velocity( void* attributeData ){return mImpl->begin__velocity();}
bool _data__velocity( const ParserChar* text, size_t textLength );
bool _end__velocity(){return mImpl->end__velocity();}
bool _validateBegin__velocity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__velocity();
bool _freeAttributes__velocity( void* attributeData );

bool _begin__instance_rigid_body__technique_common__dynamic( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__dynamic(*static_cast<instance_rigid_body__technique_common__dynamic__AttributeData*>(attributeData));}
bool _data__instance_rigid_body__technique_common__dynamic( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__dynamic(){return mImpl->end__instance_rigid_body__technique_common__dynamic();}
bool _validateBegin__instance_rigid_body__technique_common__dynamic( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__dynamic();
bool _freeAttributes__instance_rigid_body__technique_common__dynamic( void* attributeData );

bool _begin__instance_rigid_body__technique_common__mass_frame( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__mass_frame();}
bool _data__instance_rigid_body__technique_common__mass_frame( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__mass_frame(){return mImpl->end__instance_rigid_body__technique_common__mass_frame();}
bool _validateBegin__instance_rigid_body__technique_common__mass_frame( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__mass_frame();
bool _freeAttributes__instance_rigid_body__technique_common__mass_frame( void* attributeData );

bool _begin__instance_rigid_body__technique_common__shape( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__shape();}
bool _data__instance_rigid_body__technique_common__shape( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__shape(){return mImpl->end__instance_rigid_body__technique_common__shape();}
bool _validateBegin__instance_rigid_body__technique_common__shape( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__shape();
bool _freeAttributes__instance_rigid_body__technique_common__shape( void* attributeData );

bool _begin__instance_rigid_body__technique_common__shape__hollow( void* attributeData ){return mImpl->begin__instance_rigid_body__technique_common__shape__hollow(*static_cast<instance_rigid_body__technique_common__shape__hollow__AttributeData*>(attributeData));}
bool _data__instance_rigid_body__technique_common__shape__hollow( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_body__technique_common__shape__hollow(){return mImpl->end__instance_rigid_body__technique_common__shape__hollow();}
bool _validateBegin__instance_rigid_body__technique_common__shape__hollow( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_body__technique_common__shape__hollow();
bool _freeAttributes__instance_rigid_body__technique_common__shape__hollow( void* attributeData );

bool _begin__instance_rigid_constraint( void* attributeData ){return mImpl->begin__instance_rigid_constraint(*static_cast<instance_rigid_constraint__AttributeData*>(attributeData));}
bool _data__instance_rigid_constraint( const ParserChar* text, size_t textLength );
bool _end__instance_rigid_constraint(){return mImpl->end__instance_rigid_constraint();}
bool _validateBegin__instance_rigid_constraint( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_rigid_constraint();
bool _freeAttributes__instance_rigid_constraint( void* attributeData );

bool _begin__library_physics_scenes( void* attributeData ){return mImpl->begin__library_physics_scenes(*static_cast<library_physics_scenes__AttributeData*>(attributeData));}
bool _data__library_physics_scenes( const ParserChar* text, size_t textLength );
bool _end__library_physics_scenes(){return mImpl->end__library_physics_scenes();}
bool _validateBegin__library_physics_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_physics_scenes();
bool _freeAttributes__library_physics_scenes( void* attributeData );

bool _begin__physics_scene( void* attributeData ){return mImpl->begin__physics_scene(*static_cast<physics_scene__AttributeData*>(attributeData));}
bool _data__physics_scene( const ParserChar* text, size_t textLength );
bool _end__physics_scene(){return mImpl->end__physics_scene();}
bool _validateBegin__physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_scene();
bool _freeAttributes__physics_scene( void* attributeData );

bool _begin__physics_scene__technique_common( void* attributeData ){return mImpl->begin__physics_scene__technique_common();}
bool _data__physics_scene__technique_common( const ParserChar* text, size_t textLength );
bool _end__physics_scene__technique_common(){return mImpl->end__physics_scene__technique_common();}
bool _validateBegin__physics_scene__technique_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__physics_scene__technique_common();
bool _freeAttributes__physics_scene__technique_common( void* attributeData );

bool _begin__gravity( void* attributeData ){return mImpl->begin__gravity(*static_cast<gravity__AttributeData*>(attributeData));}
bool _data__gravity( const ParserChar* text, size_t textLength );
bool _end__gravity(){return mImpl->end__gravity();}
bool _validateBegin__gravity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gravity();
bool _freeAttributes__gravity( void* attributeData );

bool _begin__time_step( void* attributeData ){return mImpl->begin__time_step(*static_cast<time_step__AttributeData*>(attributeData));}
bool _data__time_step( const ParserChar* text, size_t textLength );
bool _end__time_step(){return mImpl->end__time_step();}
bool _validateBegin__time_step( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__time_step();
bool _freeAttributes__time_step( void* attributeData );

bool _begin__library_visual_scenes( void* attributeData ){return mImpl->begin__library_visual_scenes(*static_cast<library_visual_scenes__AttributeData*>(attributeData));}
bool _data__library_visual_scenes( const ParserChar* text, size_t textLength );
bool _end__library_visual_scenes(){return mImpl->end__library_visual_scenes();}
bool _validateBegin__library_visual_scenes( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__library_visual_scenes();
bool _freeAttributes__library_visual_scenes( void* attributeData );

bool _begin__visual_scene( void* attributeData ){return mImpl->begin__visual_scene(*static_cast<visual_scene__AttributeData*>(attributeData));}
bool _data__visual_scene( const ParserChar* text, size_t textLength );
bool _end__visual_scene(){return mImpl->end__visual_scene();}
bool _validateBegin__visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__visual_scene();
bool _freeAttributes__visual_scene( void* attributeData );

bool _begin__evaluate_scene( void* attributeData ){return mImpl->begin__evaluate_scene(*static_cast<evaluate_scene__AttributeData*>(attributeData));}
bool _data__evaluate_scene( const ParserChar* text, size_t textLength );
bool _end__evaluate_scene(){return mImpl->end__evaluate_scene();}
bool _validateBegin__evaluate_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__evaluate_scene();
bool _freeAttributes__evaluate_scene( void* attributeData );

bool _begin__render( void* attributeData ){return mImpl->begin__render(*static_cast<render__AttributeData*>(attributeData));}
bool _data__render( const ParserChar* text, size_t textLength );
bool _end__render(){return mImpl->end__render();}
bool _validateBegin__render( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__render();
bool _freeAttributes__render( void* attributeData );

bool _begin__layer( void* attributeData ){return mImpl->begin__layer();}
bool _data__layer( const ParserChar* text, size_t textLength );
bool _end__layer(){return mImpl->end__layer();}
bool _validateBegin__layer( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__layer();
bool _freeAttributes__layer( void* attributeData );

bool _begin__scene( void* attributeData ){return mImpl->begin__scene();}
bool _data__scene( const ParserChar* text, size_t textLength );
bool _end__scene(){return mImpl->end__scene();}
bool _validateBegin__scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__scene();
bool _freeAttributes__scene( void* attributeData );

bool _begin__instance_physics_scene( void* attributeData ){return mImpl->begin__instance_physics_scene(*static_cast<instance_physics_scene__AttributeData*>(attributeData));}
bool _data__instance_physics_scene( const ParserChar* text, size_t textLength );
bool _end__instance_physics_scene(){return mImpl->end__instance_physics_scene();}
bool _validateBegin__instance_physics_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_physics_scene();
bool _freeAttributes__instance_physics_scene( void* attributeData );

bool _begin__instance_visual_scene( void* attributeData ){return mImpl->begin__instance_visual_scene(*static_cast<instance_visual_scene__AttributeData*>(attributeData));}
bool _data__instance_visual_scene( const ParserChar* text, size_t textLength );
bool _end__instance_visual_scene(){return mImpl->end__instance_visual_scene();}
bool _validateBegin__instance_visual_scene( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__instance_visual_scene();
bool _freeAttributes__instance_visual_scene( void* attributeData );

bool _begin__profile_GLES( void* attributeData ){return mImpl->begin__profile_GLES(*static_cast<profile_GLES__AttributeData*>(attributeData));}
bool _data__profile_GLES( const ParserChar* text, size_t textLength );
bool _end__profile_GLES(){return mImpl->end__profile_GLES();}
bool _validateBegin__profile_GLES( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES();
bool _freeAttributes__profile_GLES( void* attributeData );

bool _begin__newparam____gles_newparam( void* attributeData ){return mImpl->begin__newparam____gles_newparam(*static_cast<newparam____gles_newparam__AttributeData*>(attributeData));}
bool _data__newparam____gles_newparam( const ParserChar* text, size_t textLength );
bool _end__newparam____gles_newparam(){return mImpl->end__newparam____gles_newparam();}
bool _validateBegin__newparam____gles_newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____gles_newparam();
bool _freeAttributes__newparam____gles_newparam( void* attributeData );

bool _begin__texture_pipeline____gles_texture_pipeline( void* attributeData ){return mImpl->begin__texture_pipeline____gles_texture_pipeline(*static_cast<texture_pipeline____gles_texture_pipeline__AttributeData*>(attributeData));}
bool _data__texture_pipeline____gles_texture_pipeline( const ParserChar* text, size_t textLength );
bool _end__texture_pipeline____gles_texture_pipeline(){return mImpl->end__texture_pipeline____gles_texture_pipeline();}
bool _validateBegin__texture_pipeline____gles_texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_pipeline____gles_texture_pipeline();
bool _freeAttributes__texture_pipeline____gles_texture_pipeline( void* attributeData );

bool _begin__texcombiner( void* attributeData ){return mImpl->begin__texcombiner();}
bool _data__texcombiner( const ParserChar* text, size_t textLength );
bool _end__texcombiner(){return mImpl->end__texcombiner();}
bool _validateBegin__texcombiner( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texcombiner();
bool _freeAttributes__texcombiner( void* attributeData );

bool _begin__constant____gles_texture_constant_type( void* attributeData ){return mImpl->begin__constant____gles_texture_constant_type(*static_cast<constant____gles_texture_constant_type__AttributeData*>(attributeData));}
bool _data__constant____gles_texture_constant_type( const ParserChar* text, size_t textLength );
bool _end__constant____gles_texture_constant_type(){return mImpl->end__constant____gles_texture_constant_type();}
bool _validateBegin__constant____gles_texture_constant_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__constant____gles_texture_constant_type();
bool _freeAttributes__constant____gles_texture_constant_type( void* attributeData );

bool _begin__RGB( void* attributeData ){return mImpl->begin__RGB(*static_cast<RGB__AttributeData*>(attributeData));}
bool _data__RGB( const ParserChar* text, size_t textLength );
bool _end__RGB(){return mImpl->end__RGB();}
bool _validateBegin__RGB( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__RGB();
bool _freeAttributes__RGB( void* attributeData );


ENUM__gles_texcombiner_operatorRGB_enums toEnumDataPrefix_ENUM__gles_texcombiner_operatorRGB_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operatorRGB_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operatorRGB_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operatorRGB_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operatorRGB_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operatorRGB_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operatorRGB_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__argument____gles_texcombiner_argumentRGB_type( void* attributeData ){return mImpl->begin__argument____gles_texcombiner_argumentRGB_type(*static_cast<argument____gles_texcombiner_argumentRGB_type__AttributeData*>(attributeData));}
bool _data__argument____gles_texcombiner_argumentRGB_type( const ParserChar* text, size_t textLength );
bool _end__argument____gles_texcombiner_argumentRGB_type(){return mImpl->end__argument____gles_texcombiner_argumentRGB_type();}
bool _validateBegin__argument____gles_texcombiner_argumentRGB_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__argument____gles_texcombiner_argumentRGB_type();
bool _freeAttributes__argument____gles_texcombiner_argumentRGB_type( void* attributeData );


ENUM__gles_texcombiner_source_enums toEnumDataPrefix_ENUM__gles_texcombiner_source_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_source_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_source_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_source_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_source_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_source_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_source_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_source_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gles_texcombiner_operandRGB_enums toEnumDataPrefix_ENUM__gles_texcombiner_operandRGB_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operandRGB_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operandRGB_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operandRGB_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operandRGB_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operandRGB_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operandRGB_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__alpha____gles_texcombiner_commandAlpha_type( void* attributeData ){return mImpl->begin__alpha____gles_texcombiner_commandAlpha_type(*static_cast<alpha____gles_texcombiner_commandAlpha_type__AttributeData*>(attributeData));}
bool _data__alpha____gles_texcombiner_commandAlpha_type( const ParserChar* text, size_t textLength );
bool _end__alpha____gles_texcombiner_commandAlpha_type(){return mImpl->end__alpha____gles_texcombiner_commandAlpha_type();}
bool _validateBegin__alpha____gles_texcombiner_commandAlpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__alpha____gles_texcombiner_commandAlpha_type();
bool _freeAttributes__alpha____gles_texcombiner_commandAlpha_type( void* attributeData );


ENUM__gles_texcombiner_operatorAlpha_enums toEnumDataPrefix_ENUM__gles_texcombiner_operatorAlpha_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operatorAlpha_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operatorAlpha_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operatorAlpha_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operatorAlpha_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operatorAlpha_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operatorAlpha_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__argument____gles_texcombiner_argumentAlpha_type( void* attributeData ){return mImpl->begin__argument____gles_texcombiner_argumentAlpha_type(*static_cast<argument____gles_texcombiner_argumentAlpha_type__AttributeData*>(attributeData));}
bool _data__argument____gles_texcombiner_argumentAlpha_type( const ParserChar* text, size_t textLength );
bool _end__argument____gles_texcombiner_argumentAlpha_type(){return mImpl->end__argument____gles_texcombiner_argumentAlpha_type();}
bool _validateBegin__argument____gles_texcombiner_argumentAlpha_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__argument____gles_texcombiner_argumentAlpha_type();
bool _freeAttributes__argument____gles_texcombiner_argumentAlpha_type( void* attributeData );


ENUM__gles_texcombiner_operandAlpha_enums toEnumDataPrefix_ENUM__gles_texcombiner_operandAlpha_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texcombiner_operandAlpha_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operandAlpha_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texcombiner_operandAlpha_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texcombiner_operandAlpha_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texcombiner_operandAlpha_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texcombiner_operandAlpha_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__texenv( void* attributeData ){return mImpl->begin__texenv(*static_cast<texenv__AttributeData*>(attributeData));}
bool _data__texenv( const ParserChar* text, size_t textLength );
bool _end__texenv(){return mImpl->end__texenv();}
bool _validateBegin__texenv( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texenv();
bool _freeAttributes__texenv( void* attributeData );


ENUM__gles_texenv_mode_enums toEnumDataPrefix_ENUM__gles_texenv_mode_enums (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_texenv_mode_enums (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texenv_mode_enums*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_texenv_mode_enums (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_texenv_mode_enums*, size_t ),
    const std::pair<StringHash, ENUM__gles_texenv_mode_enums>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_texenv_mode_enums (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_texenv_mode_enums>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__sampler_state____gles_sampler_state( void* attributeData ){return mImpl->begin__sampler_state____gles_sampler_state(*static_cast<sampler_state____gles_sampler_state__AttributeData*>(attributeData));}
bool _data__sampler_state____gles_sampler_state( const ParserChar* text, size_t textLength );
bool _end__sampler_state____gles_sampler_state(){return mImpl->end__sampler_state____gles_sampler_state();}
bool _validateBegin__sampler_state____gles_sampler_state( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler_state____gles_sampler_state();
bool _freeAttributes__sampler_state____gles_sampler_state( void* attributeData );

bool _begin__wrap_s____gles_sampler_wrap( void* attributeData ){return mImpl->begin__wrap_s____gles_sampler_wrap();}
bool _data__wrap_s____gles_sampler_wrap( const ParserChar* text, size_t textLength );
bool _end__wrap_s____gles_sampler_wrap(){return mImpl->end__wrap_s____gles_sampler_wrap();}
bool _validateBegin__wrap_s____gles_sampler_wrap( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_s____gles_sampler_wrap();
bool _freeAttributes__wrap_s____gles_sampler_wrap( void* attributeData );


ENUM__gles_sampler_wrap toEnumDataPrefix_ENUM__gles_sampler_wrap (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_sampler_wrap (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_sampler_wrap*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_sampler_wrap (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_sampler_wrap*, size_t ),
    const std::pair<StringHash, ENUM__gles_sampler_wrap>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_sampler_wrap (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_sampler_wrap>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__wrap_t____gles_sampler_wrap( void* attributeData ){return mImpl->begin__wrap_t____gles_sampler_wrap();}
bool _data__wrap_t____gles_sampler_wrap( const ParserChar* text, size_t textLength );
bool _end__wrap_t____gles_sampler_wrap(){return mImpl->end__wrap_t____gles_sampler_wrap();}
bool _validateBegin__wrap_t____gles_sampler_wrap( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__wrap_t____gles_sampler_wrap();
bool _freeAttributes__wrap_t____gles_sampler_wrap( void* attributeData );

bool _begin__texture_unit( void* attributeData ){return mImpl->begin__texture_unit(*static_cast<texture_unit__AttributeData*>(attributeData));}
bool _data__texture_unit( const ParserChar* text, size_t textLength );
bool _end__texture_unit(){return mImpl->end__texture_unit();}
bool _validateBegin__texture_unit( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_unit();
bool _freeAttributes__texture_unit( void* attributeData );

bool _begin__surface____NCName( void* attributeData ){return mImpl->begin__surface____NCName();}
bool _data__surface____NCName( const ParserChar* text, size_t textLength );
bool _end__surface____NCName(){return mImpl->end__surface____NCName();}
bool _validateBegin__surface____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface____NCName();
bool _freeAttributes__surface____NCName( void* attributeData );

bool _begin__sampler_state____NCName( void* attributeData ){return mImpl->begin__sampler_state____NCName();}
bool _data__sampler_state____NCName( const ParserChar* text, size_t textLength );
bool _end__sampler_state____NCName(){return mImpl->end__sampler_state____NCName();}
bool _validateBegin__sampler_state____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler_state____NCName();
bool _freeAttributes__sampler_state____NCName( void* attributeData );

bool _begin__texcoord( void* attributeData ){return mImpl->begin__texcoord(*static_cast<texcoord__AttributeData*>(attributeData));}
bool _data__texcoord( const ParserChar* text, size_t textLength );
bool _end__texcoord(){return mImpl->end__texcoord();}
bool _validateBegin__texcoord( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texcoord();
bool _freeAttributes__texcoord( void* attributeData );

bool _begin__enum____gles_enumeration( void* attributeData ){return mImpl->begin__enum____gles_enumeration();}
bool _data__enum____gles_enumeration( const ParserChar* text, size_t textLength );
bool _end__enum____gles_enumeration(){return mImpl->end__enum____gles_enumeration();}
bool _validateBegin__enum____gles_enumeration( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____gles_enumeration();
bool _freeAttributes__enum____gles_enumeration( void* attributeData );


ENUM__gl_blend_type toEnumDataPrefix_ENUM__gl_blend_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_blend_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_blend_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_blend_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_blend_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_blend_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_blend_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_blend_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_face_type toEnumDataPrefix_ENUM__gl_face_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_face_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_face_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_face_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_face_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_face_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_face_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_func_type toEnumDataPrefix_ENUM__gl_func_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_func_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_func_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_func_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_func_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_func_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_func_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_func_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_stencil_op_type toEnumDataPrefix_ENUM__gl_stencil_op_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_stencil_op_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_stencil_op_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_stencil_op_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_stencil_op_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_stencil_op_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_stencil_op_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_material_type toEnumDataPrefix_ENUM__gl_material_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_material_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_material_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_material_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_material_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_material_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_material_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_material_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_material_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_fog_type toEnumDataPrefix_ENUM__gl_fog_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_fog_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_fog_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_fog_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_fog_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_fog_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_fog_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_fog_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_front_face_type toEnumDataPrefix_ENUM__gl_front_face_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_front_face_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_front_face_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_front_face_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_front_face_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_front_face_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_front_face_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_front_face_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_light_model_color_control_type toEnumDataPrefix_ENUM__gl_light_model_color_control_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_light_model_color_control_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_light_model_color_control_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_light_model_color_control_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_light_model_color_control_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_light_model_color_control_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_light_model_color_control_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_light_model_color_control_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_light_model_color_control_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_logic_op_type toEnumDataPrefix_ENUM__gl_logic_op_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_logic_op_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_logic_op_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_logic_op_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_logic_op_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_logic_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_logic_op_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_logic_op_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_polygon_mode_type toEnumDataPrefix_ENUM__gl_polygon_mode_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_polygon_mode_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_polygon_mode_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_polygon_mode_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_polygon_mode_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_polygon_mode_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_polygon_mode_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_polygon_mode_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_polygon_mode_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_shade_model_type toEnumDataPrefix_ENUM__gl_shade_model_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_shade_model_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_shade_model_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_shade_model_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_shade_model_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_shade_model_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_shade_model_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_shade_model_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




UNION__gles_enumeration toUnionPrefix_UNION__gles_enumeration (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed
);



bool _begin__profile_GLES__technique( void* attributeData ){return mImpl->begin__profile_GLES__technique(*static_cast<profile_GLES__technique__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique(){return mImpl->end__profile_GLES__technique();}
bool _validateBegin__profile_GLES__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique();
bool _freeAttributes__profile_GLES__technique( void* attributeData );

bool _begin__profile_GLES__technique__setparam( void* attributeData ){return mImpl->begin__profile_GLES__technique__setparam(*static_cast<profile_GLES__technique__setparam__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__setparam( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__setparam(){return mImpl->end__profile_GLES__technique__setparam();}
bool _validateBegin__profile_GLES__technique__setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__setparam();
bool _freeAttributes__profile_GLES__technique__setparam( void* attributeData );

bool _begin__profile_GLES__technique__pass( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass(*static_cast<profile_GLES__technique__pass__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass(){return mImpl->end__profile_GLES__technique__pass();}
bool _validateBegin__profile_GLES__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass();
bool _freeAttributes__profile_GLES__technique__pass( void* attributeData );

bool _begin__color_target____gles_rendertarget_common( void* attributeData ){return mImpl->begin__color_target____gles_rendertarget_common();}
bool _data__color_target____gles_rendertarget_common( const ParserChar* text, size_t textLength );
bool _end__color_target____gles_rendertarget_common(){return mImpl->end__color_target____gles_rendertarget_common();}
bool _validateBegin__color_target____gles_rendertarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_target____gles_rendertarget_common();
bool _freeAttributes__color_target____gles_rendertarget_common( void* attributeData );

bool _begin__depth_target____gles_rendertarget_common( void* attributeData ){return mImpl->begin__depth_target____gles_rendertarget_common();}
bool _data__depth_target____gles_rendertarget_common( const ParserChar* text, size_t textLength );
bool _end__depth_target____gles_rendertarget_common(){return mImpl->end__depth_target____gles_rendertarget_common();}
bool _validateBegin__depth_target____gles_rendertarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_target____gles_rendertarget_common();
bool _freeAttributes__depth_target____gles_rendertarget_common( void* attributeData );

bool _begin__stencil_target____gles_rendertarget_common( void* attributeData ){return mImpl->begin__stencil_target____gles_rendertarget_common();}
bool _data__stencil_target____gles_rendertarget_common( const ParserChar* text, size_t textLength );
bool _end__stencil_target____gles_rendertarget_common(){return mImpl->end__stencil_target____gles_rendertarget_common();}
bool _validateBegin__stencil_target____gles_rendertarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_target____gles_rendertarget_common();
bool _freeAttributes__stencil_target____gles_rendertarget_common( void* attributeData );

bool _begin__color_clear____fx_color_common( void* attributeData ){return mImpl->begin__color_clear____fx_color_common();}
bool _data__color_clear____fx_color_common( const ParserChar* text, size_t textLength );
bool _end__color_clear____fx_color_common(){return mImpl->end__color_clear____fx_color_common();}
bool _validateBegin__color_clear____fx_color_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_clear____fx_color_common();
bool _freeAttributes__color_clear____fx_color_common( void* attributeData );

bool _begin__depth_clear____float( void* attributeData ){return mImpl->begin__depth_clear____float();}
bool _data__depth_clear____float( const ParserChar* text, size_t textLength );
bool _end__depth_clear____float(){return mImpl->end__depth_clear____float();}
bool _validateBegin__depth_clear____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_clear____float();
bool _freeAttributes__depth_clear____float( void* attributeData );

bool _begin__stencil_clear____byte( void* attributeData ){return mImpl->begin__stencil_clear____byte();}
bool _data__stencil_clear____byte( const ParserChar* text, size_t textLength );
bool _end__stencil_clear____byte(){return mImpl->end__stencil_clear____byte();}
bool _validateBegin__stencil_clear____byte( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_clear____byte();
bool _freeAttributes__stencil_clear____byte( void* attributeData );

bool _begin__draw( void* attributeData ){return mImpl->begin__draw();}
bool _data__draw( const ParserChar* text, size_t textLength );
bool _end__draw(){return mImpl->end__draw();}
bool _validateBegin__draw( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__draw();
bool _freeAttributes__draw( void* attributeData );

bool _begin__profile_GLES__technique__pass__alpha_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__alpha_func();}
bool _data__profile_GLES__technique__pass__alpha_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__alpha_func(){return mImpl->end__profile_GLES__technique__pass__alpha_func();}
bool _validateBegin__profile_GLES__technique__pass__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__alpha_func();
bool _freeAttributes__profile_GLES__technique__pass__alpha_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__alpha_func__func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__alpha_func__func(*static_cast<profile_GLES__technique__pass__alpha_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__alpha_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__alpha_func__func(){return mImpl->end__profile_GLES__technique__pass__alpha_func__func();}
bool _validateBegin__profile_GLES__technique__pass__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__alpha_func__func();
bool _freeAttributes__profile_GLES__technique__pass__alpha_func__func( void* attributeData );

bool _begin__profile_GLES__technique__pass__alpha_func__value( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__alpha_func__value(*static_cast<profile_GLES__technique__pass__alpha_func__value__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__alpha_func__value( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__alpha_func__value(){return mImpl->end__profile_GLES__technique__pass__alpha_func__value();}
bool _validateBegin__profile_GLES__technique__pass__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__alpha_func__value();
bool _freeAttributes__profile_GLES__technique__pass__alpha_func__value( void* attributeData );

bool _begin__profile_GLES__technique__pass__blend_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__blend_func();}
bool _data__profile_GLES__technique__pass__blend_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__blend_func(){return mImpl->end__profile_GLES__technique__pass__blend_func();}
bool _validateBegin__profile_GLES__technique__pass__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__blend_func();
bool _freeAttributes__profile_GLES__technique__pass__blend_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__blend_func__src( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__blend_func__src(*static_cast<profile_GLES__technique__pass__blend_func__src__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__blend_func__src( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__blend_func__src(){return mImpl->end__profile_GLES__technique__pass__blend_func__src();}
bool _validateBegin__profile_GLES__technique__pass__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__blend_func__src();
bool _freeAttributes__profile_GLES__technique__pass__blend_func__src( void* attributeData );

bool _begin__profile_GLES__technique__pass__blend_func__dest( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__blend_func__dest(*static_cast<profile_GLES__technique__pass__blend_func__dest__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__blend_func__dest( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__blend_func__dest(){return mImpl->end__profile_GLES__technique__pass__blend_func__dest();}
bool _validateBegin__profile_GLES__technique__pass__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__blend_func__dest();
bool _freeAttributes__profile_GLES__technique__pass__blend_func__dest( void* attributeData );

bool _begin__profile_GLES__technique__pass__clear_color( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__clear_color(*static_cast<profile_GLES__technique__pass__clear_color__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__clear_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__clear_color(){return mImpl->end__profile_GLES__technique__pass__clear_color();}
bool _validateBegin__profile_GLES__technique__pass__clear_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__clear_color();
bool _freeAttributes__profile_GLES__technique__pass__clear_color( void* attributeData );

bool _begin__profile_GLES__technique__pass__clear_stencil( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__clear_stencil(*static_cast<profile_GLES__technique__pass__clear_stencil__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__clear_stencil( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__clear_stencil(){return mImpl->end__profile_GLES__technique__pass__clear_stencil();}
bool _validateBegin__profile_GLES__technique__pass__clear_stencil( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__clear_stencil();
bool _freeAttributes__profile_GLES__technique__pass__clear_stencil( void* attributeData );

bool _begin__profile_GLES__technique__pass__clear_depth( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__clear_depth(*static_cast<profile_GLES__technique__pass__clear_depth__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__clear_depth( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__clear_depth(){return mImpl->end__profile_GLES__technique__pass__clear_depth();}
bool _validateBegin__profile_GLES__technique__pass__clear_depth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__clear_depth();
bool _freeAttributes__profile_GLES__technique__pass__clear_depth( void* attributeData );

bool _begin__profile_GLES__technique__pass__clip_plane( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__clip_plane(*static_cast<profile_GLES__technique__pass__clip_plane__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__clip_plane( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__clip_plane(){return mImpl->end__profile_GLES__technique__pass__clip_plane();}
bool _validateBegin__profile_GLES__technique__pass__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__clip_plane();
bool _freeAttributes__profile_GLES__technique__pass__clip_plane( void* attributeData );

bool _begin__profile_GLES__technique__pass__color_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__color_mask(*static_cast<profile_GLES__technique__pass__color_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__color_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__color_mask(){return mImpl->end__profile_GLES__technique__pass__color_mask();}
bool _validateBegin__profile_GLES__technique__pass__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__color_mask();
bool _freeAttributes__profile_GLES__technique__pass__color_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__cull_face( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__cull_face(*static_cast<profile_GLES__technique__pass__cull_face__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__cull_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__cull_face(){return mImpl->end__profile_GLES__technique__pass__cull_face();}
bool _validateBegin__profile_GLES__technique__pass__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__cull_face();
bool _freeAttributes__profile_GLES__technique__pass__cull_face( void* attributeData );

bool _begin__profile_GLES__technique__pass__depth_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__depth_func(*static_cast<profile_GLES__technique__pass__depth_func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__depth_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__depth_func(){return mImpl->end__profile_GLES__technique__pass__depth_func();}
bool _validateBegin__profile_GLES__technique__pass__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__depth_func();
bool _freeAttributes__profile_GLES__technique__pass__depth_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__depth_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__depth_mask(*static_cast<profile_GLES__technique__pass__depth_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__depth_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__depth_mask(){return mImpl->end__profile_GLES__technique__pass__depth_mask();}
bool _validateBegin__profile_GLES__technique__pass__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__depth_mask();
bool _freeAttributes__profile_GLES__technique__pass__depth_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__depth_range( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__depth_range(*static_cast<profile_GLES__technique__pass__depth_range__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__depth_range( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__depth_range(){return mImpl->end__profile_GLES__technique__pass__depth_range();}
bool _validateBegin__profile_GLES__technique__pass__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__depth_range();
bool _freeAttributes__profile_GLES__technique__pass__depth_range( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_color( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_color(*static_cast<profile_GLES__technique__pass__fog_color__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_color(){return mImpl->end__profile_GLES__technique__pass__fog_color();}
bool _validateBegin__profile_GLES__technique__pass__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_color();
bool _freeAttributes__profile_GLES__technique__pass__fog_color( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_density( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_density(*static_cast<profile_GLES__technique__pass__fog_density__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_density( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_density(){return mImpl->end__profile_GLES__technique__pass__fog_density();}
bool _validateBegin__profile_GLES__technique__pass__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_density();
bool _freeAttributes__profile_GLES__technique__pass__fog_density( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_mode( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_mode(*static_cast<profile_GLES__technique__pass__fog_mode__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_mode( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_mode(){return mImpl->end__profile_GLES__technique__pass__fog_mode();}
bool _validateBegin__profile_GLES__technique__pass__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_mode();
bool _freeAttributes__profile_GLES__technique__pass__fog_mode( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_start( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_start(*static_cast<profile_GLES__technique__pass__fog_start__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_start( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_start(){return mImpl->end__profile_GLES__technique__pass__fog_start();}
bool _validateBegin__profile_GLES__technique__pass__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_start();
bool _freeAttributes__profile_GLES__technique__pass__fog_start( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_end( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_end(*static_cast<profile_GLES__technique__pass__fog_end__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_end( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_end(){return mImpl->end__profile_GLES__technique__pass__fog_end();}
bool _validateBegin__profile_GLES__technique__pass__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_end();
bool _freeAttributes__profile_GLES__technique__pass__fog_end( void* attributeData );

bool _begin__profile_GLES__technique__pass__front_face( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__front_face(*static_cast<profile_GLES__technique__pass__front_face__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__front_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__front_face(){return mImpl->end__profile_GLES__technique__pass__front_face();}
bool _validateBegin__profile_GLES__technique__pass__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__front_face();
bool _freeAttributes__profile_GLES__technique__pass__front_face( void* attributeData );

bool _begin__profile_GLES__technique__pass__texture_pipeline( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__texture_pipeline(*static_cast<profile_GLES__technique__pass__texture_pipeline__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__texture_pipeline( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__texture_pipeline(){return mImpl->end__profile_GLES__technique__pass__texture_pipeline();}
bool _validateBegin__profile_GLES__technique__pass__texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__texture_pipeline();
bool _freeAttributes__profile_GLES__technique__pass__texture_pipeline( void* attributeData );

bool _begin__value____gles_texture_pipeline( void* attributeData ){return mImpl->begin__value____gles_texture_pipeline(*static_cast<value____gles_texture_pipeline__AttributeData*>(attributeData));}
bool _data__value____gles_texture_pipeline( const ParserChar* text, size_t textLength );
bool _end__value____gles_texture_pipeline(){return mImpl->end__value____gles_texture_pipeline();}
bool _validateBegin__value____gles_texture_pipeline( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gles_texture_pipeline();
bool _freeAttributes__value____gles_texture_pipeline( void* attributeData );

bool _begin__profile_GLES__technique__pass__logic_op( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__logic_op(*static_cast<profile_GLES__technique__pass__logic_op__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__logic_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__logic_op(){return mImpl->end__profile_GLES__technique__pass__logic_op();}
bool _validateBegin__profile_GLES__technique__pass__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__logic_op();
bool _freeAttributes__profile_GLES__technique__pass__logic_op( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_ambient(*static_cast<profile_GLES__technique__pass__light_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_ambient(){return mImpl->end__profile_GLES__technique__pass__light_ambient();}
bool _validateBegin__profile_GLES__technique__pass__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_ambient();
bool _freeAttributes__profile_GLES__technique__pass__light_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_diffuse( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_diffuse(*static_cast<profile_GLES__technique__pass__light_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_diffuse(){return mImpl->end__profile_GLES__technique__pass__light_diffuse();}
bool _validateBegin__profile_GLES__technique__pass__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_diffuse();
bool _freeAttributes__profile_GLES__technique__pass__light_diffuse( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_specular( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_specular(*static_cast<profile_GLES__technique__pass__light_specular__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_specular(){return mImpl->end__profile_GLES__technique__pass__light_specular();}
bool _validateBegin__profile_GLES__technique__pass__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_specular();
bool _freeAttributes__profile_GLES__technique__pass__light_specular( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_position( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_position(*static_cast<profile_GLES__technique__pass__light_position__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_position( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_position(){return mImpl->end__profile_GLES__technique__pass__light_position();}
bool _validateBegin__profile_GLES__technique__pass__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_position();
bool _freeAttributes__profile_GLES__technique__pass__light_position( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_constant_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_constant_attenuation(*static_cast<profile_GLES__technique__pass__light_constant_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_constant_attenuation(){return mImpl->end__profile_GLES__technique__pass__light_constant_attenuation();}
bool _validateBegin__profile_GLES__technique__pass__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_constant_attenuation();
bool _freeAttributes__profile_GLES__technique__pass__light_constant_attenuation( void* attributeData );

bool _begin__light_linear_attenutation( void* attributeData ){return mImpl->begin__light_linear_attenutation(*static_cast<light_linear_attenutation__AttributeData*>(attributeData));}
bool _data__light_linear_attenutation( const ParserChar* text, size_t textLength );
bool _end__light_linear_attenutation(){return mImpl->end__light_linear_attenutation();}
bool _validateBegin__light_linear_attenutation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_linear_attenutation();
bool _freeAttributes__light_linear_attenutation( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_quadratic_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_quadratic_attenuation(*static_cast<profile_GLES__technique__pass__light_quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_quadratic_attenuation(){return mImpl->end__profile_GLES__technique__pass__light_quadratic_attenuation();}
bool _validateBegin__profile_GLES__technique__pass__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_quadratic_attenuation();
bool _freeAttributes__profile_GLES__technique__pass__light_quadratic_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_spot_cutoff( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_spot_cutoff(*static_cast<profile_GLES__technique__pass__light_spot_cutoff__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_spot_cutoff( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_spot_cutoff(){return mImpl->end__profile_GLES__technique__pass__light_spot_cutoff();}
bool _validateBegin__profile_GLES__technique__pass__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_spot_cutoff();
bool _freeAttributes__profile_GLES__technique__pass__light_spot_cutoff( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_spot_direction( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_spot_direction(*static_cast<profile_GLES__technique__pass__light_spot_direction__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_spot_direction( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_spot_direction(){return mImpl->end__profile_GLES__technique__pass__light_spot_direction();}
bool _validateBegin__profile_GLES__technique__pass__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_spot_direction();
bool _freeAttributes__profile_GLES__technique__pass__light_spot_direction( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_spot_exponent( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_spot_exponent(*static_cast<profile_GLES__technique__pass__light_spot_exponent__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_spot_exponent( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_spot_exponent(){return mImpl->end__profile_GLES__technique__pass__light_spot_exponent();}
bool _validateBegin__profile_GLES__technique__pass__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_spot_exponent();
bool _freeAttributes__profile_GLES__technique__pass__light_spot_exponent( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_model_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_model_ambient(*static_cast<profile_GLES__technique__pass__light_model_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_model_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_model_ambient(){return mImpl->end__profile_GLES__technique__pass__light_model_ambient();}
bool _validateBegin__profile_GLES__technique__pass__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_model_ambient();
bool _freeAttributes__profile_GLES__technique__pass__light_model_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__line_width( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__line_width(*static_cast<profile_GLES__technique__pass__line_width__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__line_width( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__line_width(){return mImpl->end__profile_GLES__technique__pass__line_width();}
bool _validateBegin__profile_GLES__technique__pass__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__line_width();
bool _freeAttributes__profile_GLES__technique__pass__line_width( void* attributeData );

bool _begin__profile_GLES__technique__pass__material_ambient( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__material_ambient(*static_cast<profile_GLES__technique__pass__material_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__material_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__material_ambient(){return mImpl->end__profile_GLES__technique__pass__material_ambient();}
bool _validateBegin__profile_GLES__technique__pass__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__material_ambient();
bool _freeAttributes__profile_GLES__technique__pass__material_ambient( void* attributeData );

bool _begin__profile_GLES__technique__pass__material_diffuse( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__material_diffuse(*static_cast<profile_GLES__technique__pass__material_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__material_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__material_diffuse(){return mImpl->end__profile_GLES__technique__pass__material_diffuse();}
bool _validateBegin__profile_GLES__technique__pass__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__material_diffuse();
bool _freeAttributes__profile_GLES__technique__pass__material_diffuse( void* attributeData );

bool _begin__profile_GLES__technique__pass__material_emission( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__material_emission(*static_cast<profile_GLES__technique__pass__material_emission__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__material_emission( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__material_emission(){return mImpl->end__profile_GLES__technique__pass__material_emission();}
bool _validateBegin__profile_GLES__technique__pass__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__material_emission();
bool _freeAttributes__profile_GLES__technique__pass__material_emission( void* attributeData );

bool _begin__profile_GLES__technique__pass__material_shininess( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__material_shininess(*static_cast<profile_GLES__technique__pass__material_shininess__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__material_shininess( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__material_shininess(){return mImpl->end__profile_GLES__technique__pass__material_shininess();}
bool _validateBegin__profile_GLES__technique__pass__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__material_shininess();
bool _freeAttributes__profile_GLES__technique__pass__material_shininess( void* attributeData );

bool _begin__profile_GLES__technique__pass__material_specular( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__material_specular(*static_cast<profile_GLES__technique__pass__material_specular__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__material_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__material_specular(){return mImpl->end__profile_GLES__technique__pass__material_specular();}
bool _validateBegin__profile_GLES__technique__pass__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__material_specular();
bool _freeAttributes__profile_GLES__technique__pass__material_specular( void* attributeData );

bool _begin__profile_GLES__technique__pass__model_view_matrix( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__model_view_matrix(*static_cast<profile_GLES__technique__pass__model_view_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__model_view_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__model_view_matrix(){return mImpl->end__profile_GLES__technique__pass__model_view_matrix();}
bool _validateBegin__profile_GLES__technique__pass__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__model_view_matrix();
bool _freeAttributes__profile_GLES__technique__pass__model_view_matrix( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_distance_attenuation( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_distance_attenuation(*static_cast<profile_GLES__technique__pass__point_distance_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_distance_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_distance_attenuation(){return mImpl->end__profile_GLES__technique__pass__point_distance_attenuation();}
bool _validateBegin__profile_GLES__technique__pass__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_distance_attenuation();
bool _freeAttributes__profile_GLES__technique__pass__point_distance_attenuation( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_fade_threshold_size( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_fade_threshold_size(*static_cast<profile_GLES__technique__pass__point_fade_threshold_size__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_fade_threshold_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_fade_threshold_size(){return mImpl->end__profile_GLES__technique__pass__point_fade_threshold_size();}
bool _validateBegin__profile_GLES__technique__pass__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_fade_threshold_size();
bool _freeAttributes__profile_GLES__technique__pass__point_fade_threshold_size( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_size( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_size(*static_cast<profile_GLES__technique__pass__point_size__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_size(){return mImpl->end__profile_GLES__technique__pass__point_size();}
bool _validateBegin__profile_GLES__technique__pass__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_size();
bool _freeAttributes__profile_GLES__technique__pass__point_size( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_size_min( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_size_min(*static_cast<profile_GLES__technique__pass__point_size_min__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_size_min( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_size_min(){return mImpl->end__profile_GLES__technique__pass__point_size_min();}
bool _validateBegin__profile_GLES__technique__pass__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_size_min();
bool _freeAttributes__profile_GLES__technique__pass__point_size_min( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_size_max( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_size_max(*static_cast<profile_GLES__technique__pass__point_size_max__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_size_max( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_size_max(){return mImpl->end__profile_GLES__technique__pass__point_size_max();}
bool _validateBegin__profile_GLES__technique__pass__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_size_max();
bool _freeAttributes__profile_GLES__technique__pass__point_size_max( void* attributeData );

bool _begin__profile_GLES__technique__pass__polygon_offset( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__polygon_offset(*static_cast<profile_GLES__technique__pass__polygon_offset__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__polygon_offset( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__polygon_offset(){return mImpl->end__profile_GLES__technique__pass__polygon_offset();}
bool _validateBegin__profile_GLES__technique__pass__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__polygon_offset();
bool _freeAttributes__profile_GLES__technique__pass__polygon_offset( void* attributeData );

bool _begin__profile_GLES__technique__pass__projection_matrix( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__projection_matrix(*static_cast<profile_GLES__technique__pass__projection_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__projection_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__projection_matrix(){return mImpl->end__profile_GLES__technique__pass__projection_matrix();}
bool _validateBegin__profile_GLES__technique__pass__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__projection_matrix();
bool _freeAttributes__profile_GLES__technique__pass__projection_matrix( void* attributeData );

bool _begin__profile_GLES__technique__pass__scissor( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__scissor(*static_cast<profile_GLES__technique__pass__scissor__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__scissor( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__scissor(){return mImpl->end__profile_GLES__technique__pass__scissor();}
bool _validateBegin__profile_GLES__technique__pass__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__scissor();
bool _freeAttributes__profile_GLES__technique__pass__scissor( void* attributeData );

bool _begin__profile_GLES__technique__pass__shade_model( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__shade_model(*static_cast<profile_GLES__technique__pass__shade_model__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__shade_model( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__shade_model(){return mImpl->end__profile_GLES__technique__pass__shade_model();}
bool _validateBegin__profile_GLES__technique__pass__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__shade_model();
bool _freeAttributes__profile_GLES__technique__pass__shade_model( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_func();}
bool _data__profile_GLES__technique__pass__stencil_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_func(){return mImpl->end__profile_GLES__technique__pass__stencil_func();}
bool _validateBegin__profile_GLES__technique__pass__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_func();
bool _freeAttributes__profile_GLES__technique__pass__stencil_func( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_func__func( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_func__func(*static_cast<profile_GLES__technique__pass__stencil_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_func__func(){return mImpl->end__profile_GLES__technique__pass__stencil_func__func();}
bool _validateBegin__profile_GLES__technique__pass__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_func__func();
bool _freeAttributes__profile_GLES__technique__pass__stencil_func__func( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_func__ref( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_func__ref(*static_cast<profile_GLES__technique__pass__stencil_func__ref__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_func__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_func__ref(){return mImpl->end__profile_GLES__technique__pass__stencil_func__ref();}
bool _validateBegin__profile_GLES__technique__pass__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_func__ref();
bool _freeAttributes__profile_GLES__technique__pass__stencil_func__ref( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_func__mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_func__mask(*static_cast<profile_GLES__technique__pass__stencil_func__mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_func__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_func__mask(){return mImpl->end__profile_GLES__technique__pass__stencil_func__mask();}
bool _validateBegin__profile_GLES__technique__pass__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_func__mask();
bool _freeAttributes__profile_GLES__technique__pass__stencil_func__mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_mask( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_mask(*static_cast<profile_GLES__technique__pass__stencil_mask__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_mask(){return mImpl->end__profile_GLES__technique__pass__stencil_mask();}
bool _validateBegin__profile_GLES__technique__pass__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_mask();
bool _freeAttributes__profile_GLES__technique__pass__stencil_mask( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_op( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_op();}
bool _data__profile_GLES__technique__pass__stencil_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_op(){return mImpl->end__profile_GLES__technique__pass__stencil_op();}
bool _validateBegin__profile_GLES__technique__pass__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_op();
bool _freeAttributes__profile_GLES__technique__pass__stencil_op( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_op__fail( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_op__fail(*static_cast<profile_GLES__technique__pass__stencil_op__fail__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_op__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_op__fail(){return mImpl->end__profile_GLES__technique__pass__stencil_op__fail();}
bool _validateBegin__profile_GLES__technique__pass__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_op__fail();
bool _freeAttributes__profile_GLES__technique__pass__stencil_op__fail( void* attributeData );


ENUM__gles_stencil_op_type toEnumDataPrefix_ENUM__gles_stencil_op_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gles_stencil_op_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_stencil_op_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gles_stencil_op_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gles_stencil_op_type*, size_t ),
    const std::pair<StringHash, ENUM__gles_stencil_op_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gles_stencil_op_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gles_stencil_op_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__profile_GLES__technique__pass__stencil_op__zfail( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_op__zfail(*static_cast<profile_GLES__technique__pass__stencil_op__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_op__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_op__zfail(){return mImpl->end__profile_GLES__technique__pass__stencil_op__zfail();}
bool _validateBegin__profile_GLES__technique__pass__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_op__zfail();
bool _freeAttributes__profile_GLES__technique__pass__stencil_op__zfail( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_op__zpass( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_op__zpass(*static_cast<profile_GLES__technique__pass__stencil_op__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_op__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_op__zpass(){return mImpl->end__profile_GLES__technique__pass__stencil_op__zpass();}
bool _validateBegin__profile_GLES__technique__pass__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_op__zpass();
bool _freeAttributes__profile_GLES__technique__pass__stencil_op__zpass( void* attributeData );

bool _begin__profile_GLES__technique__pass__alpha_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__alpha_test_enable(*static_cast<profile_GLES__technique__pass__alpha_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__alpha_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__alpha_test_enable(){return mImpl->end__profile_GLES__technique__pass__alpha_test_enable();}
bool _validateBegin__profile_GLES__technique__pass__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__alpha_test_enable();
bool _freeAttributes__profile_GLES__technique__pass__alpha_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__blend_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__blend_enable(*static_cast<profile_GLES__technique__pass__blend_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__blend_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__blend_enable(){return mImpl->end__profile_GLES__technique__pass__blend_enable();}
bool _validateBegin__profile_GLES__technique__pass__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__blend_enable();
bool _freeAttributes__profile_GLES__technique__pass__blend_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__clip_plane_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__clip_plane_enable(*static_cast<profile_GLES__technique__pass__clip_plane_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__clip_plane_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__clip_plane_enable(){return mImpl->end__profile_GLES__technique__pass__clip_plane_enable();}
bool _validateBegin__profile_GLES__technique__pass__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__clip_plane_enable();
bool _freeAttributes__profile_GLES__technique__pass__clip_plane_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__color_logic_op_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__color_logic_op_enable(*static_cast<profile_GLES__technique__pass__color_logic_op_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__color_logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__color_logic_op_enable(){return mImpl->end__profile_GLES__technique__pass__color_logic_op_enable();}
bool _validateBegin__profile_GLES__technique__pass__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__color_logic_op_enable();
bool _freeAttributes__profile_GLES__technique__pass__color_logic_op_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__color_material_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__color_material_enable(*static_cast<profile_GLES__technique__pass__color_material_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__color_material_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__color_material_enable(){return mImpl->end__profile_GLES__technique__pass__color_material_enable();}
bool _validateBegin__profile_GLES__technique__pass__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__color_material_enable();
bool _freeAttributes__profile_GLES__technique__pass__color_material_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__cull_face_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__cull_face_enable(*static_cast<profile_GLES__technique__pass__cull_face_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__cull_face_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__cull_face_enable(){return mImpl->end__profile_GLES__technique__pass__cull_face_enable();}
bool _validateBegin__profile_GLES__technique__pass__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__cull_face_enable();
bool _freeAttributes__profile_GLES__technique__pass__cull_face_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__depth_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__depth_test_enable(*static_cast<profile_GLES__technique__pass__depth_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__depth_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__depth_test_enable(){return mImpl->end__profile_GLES__technique__pass__depth_test_enable();}
bool _validateBegin__profile_GLES__technique__pass__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__depth_test_enable();
bool _freeAttributes__profile_GLES__technique__pass__depth_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__dither_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__dither_enable(*static_cast<profile_GLES__technique__pass__dither_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__dither_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__dither_enable(){return mImpl->end__profile_GLES__technique__pass__dither_enable();}
bool _validateBegin__profile_GLES__technique__pass__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__dither_enable();
bool _freeAttributes__profile_GLES__technique__pass__dither_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__fog_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__fog_enable(*static_cast<profile_GLES__technique__pass__fog_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__fog_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__fog_enable(){return mImpl->end__profile_GLES__technique__pass__fog_enable();}
bool _validateBegin__profile_GLES__technique__pass__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__fog_enable();
bool _freeAttributes__profile_GLES__technique__pass__fog_enable( void* attributeData );

bool _begin__texture_pipeline_enable( void* attributeData ){return mImpl->begin__texture_pipeline_enable(*static_cast<texture_pipeline_enable__AttributeData*>(attributeData));}
bool _data__texture_pipeline_enable( const ParserChar* text, size_t textLength );
bool _end__texture_pipeline_enable(){return mImpl->end__texture_pipeline_enable();}
bool _validateBegin__texture_pipeline_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_pipeline_enable();
bool _freeAttributes__texture_pipeline_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_enable(*static_cast<profile_GLES__technique__pass__light_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_enable(){return mImpl->end__profile_GLES__technique__pass__light_enable();}
bool _validateBegin__profile_GLES__technique__pass__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_enable();
bool _freeAttributes__profile_GLES__technique__pass__light_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__lighting_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__lighting_enable(*static_cast<profile_GLES__technique__pass__lighting_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__lighting_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__lighting_enable(){return mImpl->end__profile_GLES__technique__pass__lighting_enable();}
bool _validateBegin__profile_GLES__technique__pass__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__lighting_enable();
bool _freeAttributes__profile_GLES__technique__pass__lighting_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__light_model_two_side_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__light_model_two_side_enable(*static_cast<profile_GLES__technique__pass__light_model_two_side_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__light_model_two_side_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__light_model_two_side_enable(){return mImpl->end__profile_GLES__technique__pass__light_model_two_side_enable();}
bool _validateBegin__profile_GLES__technique__pass__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__light_model_two_side_enable();
bool _freeAttributes__profile_GLES__technique__pass__light_model_two_side_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__line_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__line_smooth_enable(*static_cast<profile_GLES__technique__pass__line_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__line_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__line_smooth_enable(){return mImpl->end__profile_GLES__technique__pass__line_smooth_enable();}
bool _validateBegin__profile_GLES__technique__pass__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__line_smooth_enable();
bool _freeAttributes__profile_GLES__technique__pass__line_smooth_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__multisample_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__multisample_enable(*static_cast<profile_GLES__technique__pass__multisample_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__multisample_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__multisample_enable(){return mImpl->end__profile_GLES__technique__pass__multisample_enable();}
bool _validateBegin__profile_GLES__technique__pass__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__multisample_enable();
bool _freeAttributes__profile_GLES__technique__pass__multisample_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__normalize_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__normalize_enable(*static_cast<profile_GLES__technique__pass__normalize_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__normalize_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__normalize_enable(){return mImpl->end__profile_GLES__technique__pass__normalize_enable();}
bool _validateBegin__profile_GLES__technique__pass__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__normalize_enable();
bool _freeAttributes__profile_GLES__technique__pass__normalize_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__point_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__point_smooth_enable(*static_cast<profile_GLES__technique__pass__point_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__point_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__point_smooth_enable(){return mImpl->end__profile_GLES__technique__pass__point_smooth_enable();}
bool _validateBegin__profile_GLES__technique__pass__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__point_smooth_enable();
bool _freeAttributes__profile_GLES__technique__pass__point_smooth_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__polygon_offset_fill_enable(*static_cast<profile_GLES__technique__pass__polygon_offset_fill_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__polygon_offset_fill_enable(){return mImpl->end__profile_GLES__technique__pass__polygon_offset_fill_enable();}
bool _validateBegin__profile_GLES__technique__pass__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__polygon_offset_fill_enable();
bool _freeAttributes__profile_GLES__technique__pass__polygon_offset_fill_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__rescale_normal_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__rescale_normal_enable(*static_cast<profile_GLES__technique__pass__rescale_normal_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__rescale_normal_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__rescale_normal_enable(){return mImpl->end__profile_GLES__technique__pass__rescale_normal_enable();}
bool _validateBegin__profile_GLES__technique__pass__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__rescale_normal_enable();
bool _freeAttributes__profile_GLES__technique__pass__rescale_normal_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__sample_alpha_to_coverage_enable(*static_cast<profile_GLES__technique__pass__sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__sample_alpha_to_coverage_enable(){return mImpl->end__profile_GLES__technique__pass__sample_alpha_to_coverage_enable();}
bool _validateBegin__profile_GLES__technique__pass__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__sample_alpha_to_coverage_enable();
bool _freeAttributes__profile_GLES__technique__pass__sample_alpha_to_coverage_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__sample_alpha_to_one_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__sample_alpha_to_one_enable(*static_cast<profile_GLES__technique__pass__sample_alpha_to_one_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__sample_alpha_to_one_enable(){return mImpl->end__profile_GLES__technique__pass__sample_alpha_to_one_enable();}
bool _validateBegin__profile_GLES__technique__pass__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__sample_alpha_to_one_enable();
bool _freeAttributes__profile_GLES__technique__pass__sample_alpha_to_one_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__sample_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__sample_coverage_enable(*static_cast<profile_GLES__technique__pass__sample_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__sample_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__sample_coverage_enable(){return mImpl->end__profile_GLES__technique__pass__sample_coverage_enable();}
bool _validateBegin__profile_GLES__technique__pass__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__sample_coverage_enable();
bool _freeAttributes__profile_GLES__technique__pass__sample_coverage_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__scissor_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__scissor_test_enable(*static_cast<profile_GLES__technique__pass__scissor_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__scissor_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__scissor_test_enable(){return mImpl->end__profile_GLES__technique__pass__scissor_test_enable();}
bool _validateBegin__profile_GLES__technique__pass__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__scissor_test_enable();
bool _freeAttributes__profile_GLES__technique__pass__scissor_test_enable( void* attributeData );

bool _begin__profile_GLES__technique__pass__stencil_test_enable( void* attributeData ){return mImpl->begin__profile_GLES__technique__pass__stencil_test_enable(*static_cast<profile_GLES__technique__pass__stencil_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLES__technique__pass__stencil_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLES__technique__pass__stencil_test_enable(){return mImpl->end__profile_GLES__technique__pass__stencil_test_enable();}
bool _validateBegin__profile_GLES__technique__pass__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLES__technique__pass__stencil_test_enable();
bool _freeAttributes__profile_GLES__technique__pass__stencil_test_enable( void* attributeData );

bool _begin__size____float3( void* attributeData ){return mImpl->begin__size____float3();}
bool _data__size____float3( const ParserChar* text, size_t textLength );
bool _end__size____float3(){return mImpl->end__size____float3();}
bool _validateBegin__size____float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__size____float3();
bool _freeAttributes__size____float3( void* attributeData );

bool _begin__profile_GLSL( void* attributeData ){return mImpl->begin__profile_GLSL(*static_cast<profile_GLSL__AttributeData*>(attributeData));}
bool _data__profile_GLSL( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL(){return mImpl->end__profile_GLSL();}
bool _validateBegin__profile_GLSL( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL();
bool _freeAttributes__profile_GLSL( void* attributeData );

bool _begin__code( void* attributeData ){return mImpl->begin__code(*static_cast<code__AttributeData*>(attributeData));}
bool _data__code( const ParserChar* text, size_t textLength );
bool _end__code(){return mImpl->end__code();}
bool _validateBegin__code( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__code();
bool _freeAttributes__code( void* attributeData );

bool _begin__include( void* attributeData ){return mImpl->begin__include(*static_cast<include__AttributeData*>(attributeData));}
bool _data__include( const ParserChar* text, size_t textLength );
bool _end__include(){return mImpl->end__include();}
bool _validateBegin__include( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__include();
bool _freeAttributes__include( void* attributeData );

bool _begin__newparam____glsl_newparam( void* attributeData ){return mImpl->begin__newparam____glsl_newparam(*static_cast<newparam____glsl_newparam__AttributeData*>(attributeData));}
bool _data__newparam____glsl_newparam( const ParserChar* text, size_t textLength );
bool _end__newparam____glsl_newparam(){return mImpl->end__newparam____glsl_newparam();}
bool _validateBegin__newparam____glsl_newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____glsl_newparam();
bool _freeAttributes__newparam____glsl_newparam( void* attributeData );

bool _begin__bool____glsl_bool( void* attributeData ){return mImpl->begin__bool____glsl_bool();}
bool _data__bool____glsl_bool( const ParserChar* text, size_t textLength );
bool _end__bool____glsl_bool(){return mImpl->end__bool____glsl_bool();}
bool _validateBegin__bool____glsl_bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool____glsl_bool();
bool _freeAttributes__bool____glsl_bool( void* attributeData );

bool _begin__bool2____glsl_bool2( void* attributeData ){return mImpl->begin__bool2____glsl_bool2();}
bool _data__bool2____glsl_bool2( const ParserChar* text, size_t textLength );
bool _end__bool2____glsl_bool2(){return mImpl->end__bool2____glsl_bool2();}
bool _validateBegin__bool2____glsl_bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2____glsl_bool2();
bool _freeAttributes__bool2____glsl_bool2( void* attributeData );

bool _begin__bool3____glsl_bool3( void* attributeData ){return mImpl->begin__bool3____glsl_bool3();}
bool _data__bool3____glsl_bool3( const ParserChar* text, size_t textLength );
bool _end__bool3____glsl_bool3(){return mImpl->end__bool3____glsl_bool3();}
bool _validateBegin__bool3____glsl_bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3____glsl_bool3();
bool _freeAttributes__bool3____glsl_bool3( void* attributeData );

bool _begin__bool4____glsl_bool4( void* attributeData ){return mImpl->begin__bool4____glsl_bool4();}
bool _data__bool4____glsl_bool4( const ParserChar* text, size_t textLength );
bool _end__bool4____glsl_bool4(){return mImpl->end__bool4____glsl_bool4();}
bool _validateBegin__bool4____glsl_bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4____glsl_bool4();
bool _freeAttributes__bool4____glsl_bool4( void* attributeData );

bool _begin__float____glsl_float( void* attributeData ){return mImpl->begin__float____glsl_float();}
bool _data__float____glsl_float( const ParserChar* text, size_t textLength );
bool _end__float____glsl_float(){return mImpl->end__float____glsl_float();}
bool _validateBegin__float____glsl_float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float____glsl_float();
bool _freeAttributes__float____glsl_float( void* attributeData );

bool _begin__float2____glsl_float2( void* attributeData ){return mImpl->begin__float2____glsl_float2();}
bool _data__float2____glsl_float2( const ParserChar* text, size_t textLength );
bool _end__float2____glsl_float2(){return mImpl->end__float2____glsl_float2();}
bool _validateBegin__float2____glsl_float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2____glsl_float2();
bool _freeAttributes__float2____glsl_float2( void* attributeData );

bool _begin__float3____glsl_float3( void* attributeData ){return mImpl->begin__float3____glsl_float3();}
bool _data__float3____glsl_float3( const ParserChar* text, size_t textLength );
bool _end__float3____glsl_float3(){return mImpl->end__float3____glsl_float3();}
bool _validateBegin__float3____glsl_float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3____glsl_float3();
bool _freeAttributes__float3____glsl_float3( void* attributeData );

bool _begin__float4____glsl_float4( void* attributeData ){return mImpl->begin__float4____glsl_float4();}
bool _data__float4____glsl_float4( const ParserChar* text, size_t textLength );
bool _end__float4____glsl_float4(){return mImpl->end__float4____glsl_float4();}
bool _validateBegin__float4____glsl_float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4____glsl_float4();
bool _freeAttributes__float4____glsl_float4( void* attributeData );

bool _begin__float2x2____glsl_float2x2( void* attributeData ){return mImpl->begin__float2x2____glsl_float2x2();}
bool _data__float2x2____glsl_float2x2( const ParserChar* text, size_t textLength );
bool _end__float2x2____glsl_float2x2(){return mImpl->end__float2x2____glsl_float2x2();}
bool _validateBegin__float2x2____glsl_float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x2____glsl_float2x2();
bool _freeAttributes__float2x2____glsl_float2x2( void* attributeData );

bool _begin__float3x3____glsl_float3x3( void* attributeData ){return mImpl->begin__float3x3____glsl_float3x3();}
bool _data__float3x3____glsl_float3x3( const ParserChar* text, size_t textLength );
bool _end__float3x3____glsl_float3x3(){return mImpl->end__float3x3____glsl_float3x3();}
bool _validateBegin__float3x3____glsl_float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x3____glsl_float3x3();
bool _freeAttributes__float3x3____glsl_float3x3( void* attributeData );

bool _begin__float4x4____glsl_float4x4( void* attributeData ){return mImpl->begin__float4x4____glsl_float4x4();}
bool _data__float4x4____glsl_float4x4( const ParserChar* text, size_t textLength );
bool _end__float4x4____glsl_float4x4(){return mImpl->end__float4x4____glsl_float4x4();}
bool _validateBegin__float4x4____glsl_float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x4____glsl_float4x4();
bool _freeAttributes__float4x4____glsl_float4x4( void* attributeData );

bool _begin__int____glsl_int( void* attributeData ){return mImpl->begin__int____glsl_int();}
bool _data__int____glsl_int( const ParserChar* text, size_t textLength );
bool _end__int____glsl_int(){return mImpl->end__int____glsl_int();}
bool _validateBegin__int____glsl_int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int____glsl_int();
bool _freeAttributes__int____glsl_int( void* attributeData );

bool _begin__int2____glsl_int2( void* attributeData ){return mImpl->begin__int2____glsl_int2();}
bool _data__int2____glsl_int2( const ParserChar* text, size_t textLength );
bool _end__int2____glsl_int2(){return mImpl->end__int2____glsl_int2();}
bool _validateBegin__int2____glsl_int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2____glsl_int2();
bool _freeAttributes__int2____glsl_int2( void* attributeData );

bool _begin__int3____glsl_int3( void* attributeData ){return mImpl->begin__int3____glsl_int3();}
bool _data__int3____glsl_int3( const ParserChar* text, size_t textLength );
bool _end__int3____glsl_int3(){return mImpl->end__int3____glsl_int3();}
bool _validateBegin__int3____glsl_int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3____glsl_int3();
bool _freeAttributes__int3____glsl_int3( void* attributeData );

bool _begin__int4____glsl_int4( void* attributeData ){return mImpl->begin__int4____glsl_int4();}
bool _data__int4____glsl_int4( const ParserChar* text, size_t textLength );
bool _end__int4____glsl_int4(){return mImpl->end__int4____glsl_int4();}
bool _validateBegin__int4____glsl_int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4____glsl_int4();
bool _freeAttributes__int4____glsl_int4( void* attributeData );

bool _begin__surface____glsl_surface_type( void* attributeData ){return mImpl->begin__surface____glsl_surface_type(*static_cast<surface____glsl_surface_type__AttributeData*>(attributeData));}
bool _data__surface____glsl_surface_type( const ParserChar* text, size_t textLength );
bool _end__surface____glsl_surface_type(){return mImpl->end__surface____glsl_surface_type();}
bool _validateBegin__surface____glsl_surface_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface____glsl_surface_type();
bool _freeAttributes__surface____glsl_surface_type( void* attributeData );

bool _begin__glsl_surface_type____generator( void* attributeData ){return mImpl->begin__glsl_surface_type____generator();}
bool _data__glsl_surface_type____generator( const ParserChar* text, size_t textLength );
bool _end__glsl_surface_type____generator(){return mImpl->end__glsl_surface_type____generator();}
bool _validateBegin__glsl_surface_type____generator( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__glsl_surface_type____generator();
bool _freeAttributes__glsl_surface_type____generator( void* attributeData );

bool _begin__profile_GLSL__newparam__surface__generator__name( void* attributeData ){return mImpl->begin__profile_GLSL__newparam__surface__generator__name(*static_cast<profile_GLSL__newparam__surface__generator__name__AttributeData*>(attributeData));}
bool _data__profile_GLSL__newparam__surface__generator__name( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__newparam__surface__generator__name(){return mImpl->end__profile_GLSL__newparam__surface__generator__name();}
bool _validateBegin__profile_GLSL__newparam__surface__generator__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__newparam__surface__generator__name();
bool _freeAttributes__profile_GLSL__newparam__surface__generator__name( void* attributeData );

bool _begin__setparam____glsl_setparam_simple( void* attributeData ){return mImpl->begin__setparam____glsl_setparam_simple(*static_cast<setparam____glsl_setparam_simple__AttributeData*>(attributeData));}
bool _data__setparam____glsl_setparam_simple( const ParserChar* text, size_t textLength );
bool _end__setparam____glsl_setparam_simple(){return mImpl->end__setparam____glsl_setparam_simple();}
bool _validateBegin__setparam____glsl_setparam_simple( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____glsl_setparam_simple();
bool _freeAttributes__setparam____glsl_setparam_simple( void* attributeData );

bool _begin__sampler1D____gl_sampler1D( void* attributeData ){return mImpl->begin__sampler1D____gl_sampler1D();}
bool _data__sampler1D____gl_sampler1D( const ParserChar* text, size_t textLength );
bool _end__sampler1D____gl_sampler1D(){return mImpl->end__sampler1D____gl_sampler1D();}
bool _validateBegin__sampler1D____gl_sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler1D____gl_sampler1D();
bool _freeAttributes__sampler1D____gl_sampler1D( void* attributeData );

bool _begin__sampler2D____gl_sampler2D( void* attributeData ){return mImpl->begin__sampler2D____gl_sampler2D();}
bool _data__sampler2D____gl_sampler2D( const ParserChar* text, size_t textLength );
bool _end__sampler2D____gl_sampler2D(){return mImpl->end__sampler2D____gl_sampler2D();}
bool _validateBegin__sampler2D____gl_sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler2D____gl_sampler2D();
bool _freeAttributes__sampler2D____gl_sampler2D( void* attributeData );

bool _begin__sampler3D____gl_sampler3D( void* attributeData ){return mImpl->begin__sampler3D____gl_sampler3D();}
bool _data__sampler3D____gl_sampler3D( const ParserChar* text, size_t textLength );
bool _end__sampler3D____gl_sampler3D(){return mImpl->end__sampler3D____gl_sampler3D();}
bool _validateBegin__sampler3D____gl_sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler3D____gl_sampler3D();
bool _freeAttributes__sampler3D____gl_sampler3D( void* attributeData );

bool _begin__samplerCUBE____gl_samplerCUBE( void* attributeData ){return mImpl->begin__samplerCUBE____gl_samplerCUBE();}
bool _data__samplerCUBE____gl_samplerCUBE( const ParserChar* text, size_t textLength );
bool _end__samplerCUBE____gl_samplerCUBE(){return mImpl->end__samplerCUBE____gl_samplerCUBE();}
bool _validateBegin__samplerCUBE____gl_samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerCUBE____gl_samplerCUBE();
bool _freeAttributes__samplerCUBE____gl_samplerCUBE( void* attributeData );

bool _begin__samplerRECT____gl_samplerRECT( void* attributeData ){return mImpl->begin__samplerRECT____gl_samplerRECT();}
bool _data__samplerRECT____gl_samplerRECT( const ParserChar* text, size_t textLength );
bool _end__samplerRECT____gl_samplerRECT(){return mImpl->end__samplerRECT____gl_samplerRECT();}
bool _validateBegin__samplerRECT____gl_samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerRECT____gl_samplerRECT();
bool _freeAttributes__samplerRECT____gl_samplerRECT( void* attributeData );

bool _begin__samplerDEPTH____gl_samplerDEPTH( void* attributeData ){return mImpl->begin__samplerDEPTH____gl_samplerDEPTH();}
bool _data__samplerDEPTH____gl_samplerDEPTH( const ParserChar* text, size_t textLength );
bool _end__samplerDEPTH____gl_samplerDEPTH(){return mImpl->end__samplerDEPTH____gl_samplerDEPTH();}
bool _validateBegin__samplerDEPTH____gl_samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerDEPTH____gl_samplerDEPTH();
bool _freeAttributes__samplerDEPTH____gl_samplerDEPTH( void* attributeData );

bool _begin__enum____gl_enumeration( void* attributeData ){return mImpl->begin__enum____gl_enumeration();}
bool _data__enum____gl_enumeration( const ParserChar* text, size_t textLength );
bool _end__enum____gl_enumeration(){return mImpl->end__enum____gl_enumeration();}
bool _validateBegin__enum____gl_enumeration( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__enum____gl_enumeration();
bool _freeAttributes__enum____gl_enumeration( void* attributeData );


ENUM__gl_blend_equation_type toEnumDataPrefix_ENUM__gl_blend_equation_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_blend_equation_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_blend_equation_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_blend_equation_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_blend_equation_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_blend_equation_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_blend_equation_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_blend_equation_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_blend_equation_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




ENUM__gl_fog_coord_src_type toEnumDataPrefix_ENUM__gl_fog_coord_src_type (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__gl_fog_coord_src_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__gl_fog_coord_src_type (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_fog_coord_src_type*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__gl_fog_coord_src_type (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__gl_fog_coord_src_type*, size_t ),
    const std::pair<StringHash, ENUM__gl_fog_coord_src_type>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__gl_fog_coord_src_type (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__gl_fog_coord_src_type>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);




UNION__gl_enumeration toUnionPrefix_UNION__gl_enumeration (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed
);



bool _begin__array____glsl_newarray_type( void* attributeData ){return mImpl->begin__array____glsl_newarray_type(*static_cast<array____glsl_newarray_type__AttributeData*>(attributeData));}
bool _data__array____glsl_newarray_type( const ParserChar* text, size_t textLength );
bool _end__array____glsl_newarray_type(){return mImpl->end__array____glsl_newarray_type();}
bool _validateBegin__array____glsl_newarray_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____glsl_newarray_type();
bool _freeAttributes__array____glsl_newarray_type( void* attributeData );

bool _begin__profile_GLSL__technique( void* attributeData ){return mImpl->begin__profile_GLSL__technique(*static_cast<profile_GLSL__technique__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique(){return mImpl->end__profile_GLSL__technique();}
bool _validateBegin__profile_GLSL__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique();
bool _freeAttributes__profile_GLSL__technique( void* attributeData );

bool _begin__setparam____glsl_setparam( void* attributeData ){return mImpl->begin__setparam____glsl_setparam(*static_cast<setparam____glsl_setparam__AttributeData*>(attributeData));}
bool _data__setparam____glsl_setparam( const ParserChar* text, size_t textLength );
bool _end__setparam____glsl_setparam(){return mImpl->end__setparam____glsl_setparam();}
bool _validateBegin__setparam____glsl_setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____glsl_setparam();
bool _freeAttributes__setparam____glsl_setparam( void* attributeData );

bool _begin__array____glsl_setarray_type( void* attributeData ){return mImpl->begin__array____glsl_setarray_type(*static_cast<array____glsl_setarray_type__AttributeData*>(attributeData));}
bool _data__array____glsl_setarray_type( const ParserChar* text, size_t textLength );
bool _end__array____glsl_setarray_type(){return mImpl->end__array____glsl_setarray_type();}
bool _validateBegin__array____glsl_setarray_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____glsl_setarray_type();
bool _freeAttributes__array____glsl_setarray_type( void* attributeData );

bool _begin__profile_GLSL__technique__pass( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass(*static_cast<profile_GLSL__technique__pass__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass(){return mImpl->end__profile_GLSL__technique__pass();}
bool _validateBegin__profile_GLSL__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass();
bool _freeAttributes__profile_GLSL__technique__pass( void* attributeData );

bool _begin__color_target____fx_colortarget_common( void* attributeData ){return mImpl->begin__color_target____fx_colortarget_common(*static_cast<color_target____fx_colortarget_common__AttributeData*>(attributeData));}
bool _data__color_target____fx_colortarget_common( const ParserChar* text, size_t textLength );
bool _end__color_target____fx_colortarget_common(){return mImpl->end__color_target____fx_colortarget_common();}
bool _validateBegin__color_target____fx_colortarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_target____fx_colortarget_common();
bool _freeAttributes__color_target____fx_colortarget_common( void* attributeData );

bool _begin__depth_target____fx_depthtarget_common( void* attributeData ){return mImpl->begin__depth_target____fx_depthtarget_common(*static_cast<depth_target____fx_depthtarget_common__AttributeData*>(attributeData));}
bool _data__depth_target____fx_depthtarget_common( const ParserChar* text, size_t textLength );
bool _end__depth_target____fx_depthtarget_common(){return mImpl->end__depth_target____fx_depthtarget_common();}
bool _validateBegin__depth_target____fx_depthtarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_target____fx_depthtarget_common();
bool _freeAttributes__depth_target____fx_depthtarget_common( void* attributeData );

bool _begin__stencil_target____fx_stenciltarget_common( void* attributeData ){return mImpl->begin__stencil_target____fx_stenciltarget_common(*static_cast<stencil_target____fx_stenciltarget_common__AttributeData*>(attributeData));}
bool _data__stencil_target____fx_stenciltarget_common( const ParserChar* text, size_t textLength );
bool _end__stencil_target____fx_stenciltarget_common(){return mImpl->end__stencil_target____fx_stenciltarget_common();}
bool _validateBegin__stencil_target____fx_stenciltarget_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_target____fx_stenciltarget_common();
bool _freeAttributes__stencil_target____fx_stenciltarget_common( void* attributeData );

bool _begin__color_clear____fx_clearcolor_common( void* attributeData ){return mImpl->begin__color_clear____fx_clearcolor_common(*static_cast<color_clear____fx_clearcolor_common__AttributeData*>(attributeData));}
bool _data__color_clear____fx_clearcolor_common( const ParserChar* text, size_t textLength );
bool _end__color_clear____fx_clearcolor_common(){return mImpl->end__color_clear____fx_clearcolor_common();}
bool _validateBegin__color_clear____fx_clearcolor_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_clear____fx_clearcolor_common();
bool _freeAttributes__color_clear____fx_clearcolor_common( void* attributeData );

bool _begin__depth_clear____fx_cleardepth_common( void* attributeData ){return mImpl->begin__depth_clear____fx_cleardepth_common(*static_cast<depth_clear____fx_cleardepth_common__AttributeData*>(attributeData));}
bool _data__depth_clear____fx_cleardepth_common( const ParserChar* text, size_t textLength );
bool _end__depth_clear____fx_cleardepth_common(){return mImpl->end__depth_clear____fx_cleardepth_common();}
bool _validateBegin__depth_clear____fx_cleardepth_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_clear____fx_cleardepth_common();
bool _freeAttributes__depth_clear____fx_cleardepth_common( void* attributeData );

bool _begin__stencil_clear____fx_clearstencil_common( void* attributeData ){return mImpl->begin__stencil_clear____fx_clearstencil_common(*static_cast<stencil_clear____fx_clearstencil_common__AttributeData*>(attributeData));}
bool _data__stencil_clear____fx_clearstencil_common( const ParserChar* text, size_t textLength );
bool _end__stencil_clear____fx_clearstencil_common(){return mImpl->end__stencil_clear____fx_clearstencil_common();}
bool _validateBegin__stencil_clear____fx_clearstencil_common( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_clear____fx_clearstencil_common();
bool _freeAttributes__stencil_clear____fx_clearstencil_common( void* attributeData );

bool _begin__profile_GLSL__technique__pass__alpha_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__alpha_func();}
bool _data__profile_GLSL__technique__pass__alpha_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__alpha_func(){return mImpl->end__profile_GLSL__technique__pass__alpha_func();}
bool _validateBegin__profile_GLSL__technique__pass__alpha_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__alpha_func();
bool _freeAttributes__profile_GLSL__technique__pass__alpha_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__alpha_func__func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__alpha_func__func(*static_cast<profile_GLSL__technique__pass__alpha_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__alpha_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__alpha_func__func(){return mImpl->end__profile_GLSL__technique__pass__alpha_func__func();}
bool _validateBegin__profile_GLSL__technique__pass__alpha_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__alpha_func__func();
bool _freeAttributes__profile_GLSL__technique__pass__alpha_func__func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__alpha_func__value( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__alpha_func__value(*static_cast<profile_GLSL__technique__pass__alpha_func__value__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__alpha_func__value( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__alpha_func__value(){return mImpl->end__profile_GLSL__technique__pass__alpha_func__value();}
bool _validateBegin__profile_GLSL__technique__pass__alpha_func__value( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__alpha_func__value();
bool _freeAttributes__profile_GLSL__technique__pass__alpha_func__value( void* attributeData );

bool _begin__profile_GLSL__technique__pass__blend_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__blend_func();}
bool _data__profile_GLSL__technique__pass__blend_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__blend_func(){return mImpl->end__profile_GLSL__technique__pass__blend_func();}
bool _validateBegin__profile_GLSL__technique__pass__blend_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__blend_func();
bool _freeAttributes__profile_GLSL__technique__pass__blend_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__blend_func__src( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__blend_func__src(*static_cast<profile_GLSL__technique__pass__blend_func__src__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__blend_func__src( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__blend_func__src(){return mImpl->end__profile_GLSL__technique__pass__blend_func__src();}
bool _validateBegin__profile_GLSL__technique__pass__blend_func__src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__blend_func__src();
bool _freeAttributes__profile_GLSL__technique__pass__blend_func__src( void* attributeData );

bool _begin__profile_GLSL__technique__pass__blend_func__dest( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__blend_func__dest(*static_cast<profile_GLSL__technique__pass__blend_func__dest__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__blend_func__dest( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__blend_func__dest(){return mImpl->end__profile_GLSL__technique__pass__blend_func__dest();}
bool _validateBegin__profile_GLSL__technique__pass__blend_func__dest( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__blend_func__dest();
bool _freeAttributes__profile_GLSL__technique__pass__blend_func__dest( void* attributeData );

bool _begin__blend_func_separate( void* attributeData ){return mImpl->begin__blend_func_separate();}
bool _data__blend_func_separate( const ParserChar* text, size_t textLength );
bool _end__blend_func_separate(){return mImpl->end__blend_func_separate();}
bool _validateBegin__blend_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blend_func_separate();
bool _freeAttributes__blend_func_separate( void* attributeData );

bool _begin__src_rgb( void* attributeData ){return mImpl->begin__src_rgb(*static_cast<src_rgb__AttributeData*>(attributeData));}
bool _data__src_rgb( const ParserChar* text, size_t textLength );
bool _end__src_rgb(){return mImpl->end__src_rgb();}
bool _validateBegin__src_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__src_rgb();
bool _freeAttributes__src_rgb( void* attributeData );

bool _begin__dest_rgb( void* attributeData ){return mImpl->begin__dest_rgb(*static_cast<dest_rgb__AttributeData*>(attributeData));}
bool _data__dest_rgb( const ParserChar* text, size_t textLength );
bool _end__dest_rgb(){return mImpl->end__dest_rgb();}
bool _validateBegin__dest_rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__dest_rgb();
bool _freeAttributes__dest_rgb( void* attributeData );

bool _begin__src_alpha( void* attributeData ){return mImpl->begin__src_alpha(*static_cast<src_alpha__AttributeData*>(attributeData));}
bool _data__src_alpha( const ParserChar* text, size_t textLength );
bool _end__src_alpha(){return mImpl->end__src_alpha();}
bool _validateBegin__src_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__src_alpha();
bool _freeAttributes__src_alpha( void* attributeData );

bool _begin__dest_alpha( void* attributeData ){return mImpl->begin__dest_alpha(*static_cast<dest_alpha__AttributeData*>(attributeData));}
bool _data__dest_alpha( const ParserChar* text, size_t textLength );
bool _end__dest_alpha(){return mImpl->end__dest_alpha();}
bool _validateBegin__dest_alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__dest_alpha();
bool _freeAttributes__dest_alpha( void* attributeData );

bool _begin__blend_equation( void* attributeData ){return mImpl->begin__blend_equation(*static_cast<blend_equation__AttributeData*>(attributeData));}
bool _data__blend_equation( const ParserChar* text, size_t textLength );
bool _end__blend_equation(){return mImpl->end__blend_equation();}
bool _validateBegin__blend_equation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blend_equation();
bool _freeAttributes__blend_equation( void* attributeData );

bool _begin__blend_equation_separate( void* attributeData ){return mImpl->begin__blend_equation_separate();}
bool _data__blend_equation_separate( const ParserChar* text, size_t textLength );
bool _end__blend_equation_separate(){return mImpl->end__blend_equation_separate();}
bool _validateBegin__blend_equation_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blend_equation_separate();
bool _freeAttributes__blend_equation_separate( void* attributeData );

bool _begin__rgb( void* attributeData ){return mImpl->begin__rgb(*static_cast<rgb__AttributeData*>(attributeData));}
bool _data__rgb( const ParserChar* text, size_t textLength );
bool _end__rgb(){return mImpl->end__rgb();}
bool _validateBegin__rgb( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__rgb();
bool _freeAttributes__rgb( void* attributeData );

bool _begin__blend_equation_separate__alpha( void* attributeData ){return mImpl->begin__blend_equation_separate__alpha(*static_cast<blend_equation_separate__alpha__AttributeData*>(attributeData));}
bool _data__blend_equation_separate__alpha( const ParserChar* text, size_t textLength );
bool _end__blend_equation_separate__alpha(){return mImpl->end__blend_equation_separate__alpha();}
bool _validateBegin__blend_equation_separate__alpha( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blend_equation_separate__alpha();
bool _freeAttributes__blend_equation_separate__alpha( void* attributeData );

bool _begin__color_material( void* attributeData ){return mImpl->begin__color_material();}
bool _data__color_material( const ParserChar* text, size_t textLength );
bool _end__color_material(){return mImpl->end__color_material();}
bool _validateBegin__color_material( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material();
bool _freeAttributes__color_material( void* attributeData );

bool _begin__color_material__face( void* attributeData ){return mImpl->begin__color_material__face(*static_cast<color_material__face__AttributeData*>(attributeData));}
bool _data__color_material__face( const ParserChar* text, size_t textLength );
bool _end__color_material__face(){return mImpl->end__color_material__face();}
bool _validateBegin__color_material__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material__face();
bool _freeAttributes__color_material__face( void* attributeData );

bool _begin__color_material__mode( void* attributeData ){return mImpl->begin__color_material__mode(*static_cast<color_material__mode__AttributeData*>(attributeData));}
bool _data__color_material__mode( const ParserChar* text, size_t textLength );
bool _end__color_material__mode(){return mImpl->end__color_material__mode();}
bool _validateBegin__color_material__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__color_material__mode();
bool _freeAttributes__color_material__mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__cull_face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__cull_face(*static_cast<profile_GLSL__technique__pass__cull_face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__cull_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__cull_face(){return mImpl->end__profile_GLSL__technique__pass__cull_face();}
bool _validateBegin__profile_GLSL__technique__pass__cull_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__cull_face();
bool _freeAttributes__profile_GLSL__technique__pass__cull_face( void* attributeData );

bool _begin__profile_GLSL__technique__pass__depth_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__depth_func(*static_cast<profile_GLSL__technique__pass__depth_func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__depth_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__depth_func(){return mImpl->end__profile_GLSL__technique__pass__depth_func();}
bool _validateBegin__profile_GLSL__technique__pass__depth_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__depth_func();
bool _freeAttributes__profile_GLSL__technique__pass__depth_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_mode( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_mode(*static_cast<profile_GLSL__technique__pass__fog_mode__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_mode( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_mode(){return mImpl->end__profile_GLSL__technique__pass__fog_mode();}
bool _validateBegin__profile_GLSL__technique__pass__fog_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_mode();
bool _freeAttributes__profile_GLSL__technique__pass__fog_mode( void* attributeData );

bool _begin__fog_coord_src( void* attributeData ){return mImpl->begin__fog_coord_src(*static_cast<fog_coord_src__AttributeData*>(attributeData));}
bool _data__fog_coord_src( const ParserChar* text, size_t textLength );
bool _end__fog_coord_src(){return mImpl->end__fog_coord_src();}
bool _validateBegin__fog_coord_src( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fog_coord_src();
bool _freeAttributes__fog_coord_src( void* attributeData );

bool _begin__profile_GLSL__technique__pass__front_face( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__front_face(*static_cast<profile_GLSL__technique__pass__front_face__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__front_face( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__front_face(){return mImpl->end__profile_GLSL__technique__pass__front_face();}
bool _validateBegin__profile_GLSL__technique__pass__front_face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__front_face();
bool _freeAttributes__profile_GLSL__technique__pass__front_face( void* attributeData );

bool _begin__light_model_color_control( void* attributeData ){return mImpl->begin__light_model_color_control(*static_cast<light_model_color_control__AttributeData*>(attributeData));}
bool _data__light_model_color_control( const ParserChar* text, size_t textLength );
bool _end__light_model_color_control(){return mImpl->end__light_model_color_control();}
bool _validateBegin__light_model_color_control( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_model_color_control();
bool _freeAttributes__light_model_color_control( void* attributeData );

bool _begin__profile_GLSL__technique__pass__logic_op( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__logic_op(*static_cast<profile_GLSL__technique__pass__logic_op__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__logic_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__logic_op(){return mImpl->end__profile_GLSL__technique__pass__logic_op();}
bool _validateBegin__profile_GLSL__technique__pass__logic_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__logic_op();
bool _freeAttributes__profile_GLSL__technique__pass__logic_op( void* attributeData );

bool _begin__polygon_mode( void* attributeData ){return mImpl->begin__polygon_mode();}
bool _data__polygon_mode( const ParserChar* text, size_t textLength );
bool _end__polygon_mode(){return mImpl->end__polygon_mode();}
bool _validateBegin__polygon_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode();
bool _freeAttributes__polygon_mode( void* attributeData );

bool _begin__polygon_mode__face( void* attributeData ){return mImpl->begin__polygon_mode__face(*static_cast<polygon_mode__face__AttributeData*>(attributeData));}
bool _data__polygon_mode__face( const ParserChar* text, size_t textLength );
bool _end__polygon_mode__face(){return mImpl->end__polygon_mode__face();}
bool _validateBegin__polygon_mode__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode__face();
bool _freeAttributes__polygon_mode__face( void* attributeData );

bool _begin__polygon_mode__mode( void* attributeData ){return mImpl->begin__polygon_mode__mode(*static_cast<polygon_mode__mode__AttributeData*>(attributeData));}
bool _data__polygon_mode__mode( const ParserChar* text, size_t textLength );
bool _end__polygon_mode__mode(){return mImpl->end__polygon_mode__mode();}
bool _validateBegin__polygon_mode__mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_mode__mode();
bool _freeAttributes__polygon_mode__mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__shade_model( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shade_model(*static_cast<profile_GLSL__technique__pass__shade_model__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__shade_model( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shade_model(){return mImpl->end__profile_GLSL__technique__pass__shade_model();}
bool _validateBegin__profile_GLSL__technique__pass__shade_model( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shade_model();
bool _freeAttributes__profile_GLSL__technique__pass__shade_model( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_func();}
bool _data__profile_GLSL__technique__pass__stencil_func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_func(){return mImpl->end__profile_GLSL__technique__pass__stencil_func();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_func();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_func__func( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_func__func(*static_cast<profile_GLSL__technique__pass__stencil_func__func__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_func__func( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_func__func(){return mImpl->end__profile_GLSL__technique__pass__stencil_func__func();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_func__func( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_func__func();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_func__func( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_func__ref( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_func__ref(*static_cast<profile_GLSL__technique__pass__stencil_func__ref__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_func__ref( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_func__ref(){return mImpl->end__profile_GLSL__technique__pass__stencil_func__ref();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_func__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_func__ref();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_func__ref( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_func__mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_func__mask(*static_cast<profile_GLSL__technique__pass__stencil_func__mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_func__mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_func__mask(){return mImpl->end__profile_GLSL__technique__pass__stencil_func__mask();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_func__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_func__mask();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_func__mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_op( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_op();}
bool _data__profile_GLSL__technique__pass__stencil_op( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_op(){return mImpl->end__profile_GLSL__technique__pass__stencil_op();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_op( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_op();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_op( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_op__fail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_op__fail(*static_cast<profile_GLSL__technique__pass__stencil_op__fail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_op__fail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_op__fail(){return mImpl->end__profile_GLSL__technique__pass__stencil_op__fail();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_op__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_op__fail();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_op__fail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_op__zfail( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_op__zfail(*static_cast<profile_GLSL__technique__pass__stencil_op__zfail__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_op__zfail( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_op__zfail(){return mImpl->end__profile_GLSL__technique__pass__stencil_op__zfail();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_op__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_op__zfail();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_op__zfail( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_op__zpass( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_op__zpass(*static_cast<profile_GLSL__technique__pass__stencil_op__zpass__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_op__zpass( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_op__zpass(){return mImpl->end__profile_GLSL__technique__pass__stencil_op__zpass();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_op__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_op__zpass();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_op__zpass( void* attributeData );

bool _begin__stencil_func_separate( void* attributeData ){return mImpl->begin__stencil_func_separate();}
bool _data__stencil_func_separate( const ParserChar* text, size_t textLength );
bool _end__stencil_func_separate(){return mImpl->end__stencil_func_separate();}
bool _validateBegin__stencil_func_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_func_separate();
bool _freeAttributes__stencil_func_separate( void* attributeData );

bool _begin__front( void* attributeData ){return mImpl->begin__front(*static_cast<front__AttributeData*>(attributeData));}
bool _data__front( const ParserChar* text, size_t textLength );
bool _end__front(){return mImpl->end__front();}
bool _validateBegin__front( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__front();
bool _freeAttributes__front( void* attributeData );

bool _begin__back( void* attributeData ){return mImpl->begin__back(*static_cast<back__AttributeData*>(attributeData));}
bool _data__back( const ParserChar* text, size_t textLength );
bool _end__back(){return mImpl->end__back();}
bool _validateBegin__back( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__back();
bool _freeAttributes__back( void* attributeData );

bool _begin__stencil_func_separate__ref( void* attributeData ){return mImpl->begin__stencil_func_separate__ref(*static_cast<stencil_func_separate__ref__AttributeData*>(attributeData));}
bool _data__stencil_func_separate__ref( const ParserChar* text, size_t textLength );
bool _end__stencil_func_separate__ref(){return mImpl->end__stencil_func_separate__ref();}
bool _validateBegin__stencil_func_separate__ref( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_func_separate__ref();
bool _freeAttributes__stencil_func_separate__ref( void* attributeData );

bool _begin__stencil_func_separate__mask( void* attributeData ){return mImpl->begin__stencil_func_separate__mask(*static_cast<stencil_func_separate__mask__AttributeData*>(attributeData));}
bool _data__stencil_func_separate__mask( const ParserChar* text, size_t textLength );
bool _end__stencil_func_separate__mask(){return mImpl->end__stencil_func_separate__mask();}
bool _validateBegin__stencil_func_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_func_separate__mask();
bool _freeAttributes__stencil_func_separate__mask( void* attributeData );

bool _begin__stencil_op_separate( void* attributeData ){return mImpl->begin__stencil_op_separate();}
bool _data__stencil_op_separate( const ParserChar* text, size_t textLength );
bool _end__stencil_op_separate(){return mImpl->end__stencil_op_separate();}
bool _validateBegin__stencil_op_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_op_separate();
bool _freeAttributes__stencil_op_separate( void* attributeData );

bool _begin__stencil_op_separate__face( void* attributeData ){return mImpl->begin__stencil_op_separate__face(*static_cast<stencil_op_separate__face__AttributeData*>(attributeData));}
bool _data__stencil_op_separate__face( const ParserChar* text, size_t textLength );
bool _end__stencil_op_separate__face(){return mImpl->end__stencil_op_separate__face();}
bool _validateBegin__stencil_op_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_op_separate__face();
bool _freeAttributes__stencil_op_separate__face( void* attributeData );

bool _begin__stencil_op_separate__fail( void* attributeData ){return mImpl->begin__stencil_op_separate__fail(*static_cast<stencil_op_separate__fail__AttributeData*>(attributeData));}
bool _data__stencil_op_separate__fail( const ParserChar* text, size_t textLength );
bool _end__stencil_op_separate__fail(){return mImpl->end__stencil_op_separate__fail();}
bool _validateBegin__stencil_op_separate__fail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_op_separate__fail();
bool _freeAttributes__stencil_op_separate__fail( void* attributeData );

bool _begin__stencil_op_separate__zfail( void* attributeData ){return mImpl->begin__stencil_op_separate__zfail(*static_cast<stencil_op_separate__zfail__AttributeData*>(attributeData));}
bool _data__stencil_op_separate__zfail( const ParserChar* text, size_t textLength );
bool _end__stencil_op_separate__zfail(){return mImpl->end__stencil_op_separate__zfail();}
bool _validateBegin__stencil_op_separate__zfail( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_op_separate__zfail();
bool _freeAttributes__stencil_op_separate__zfail( void* attributeData );

bool _begin__stencil_op_separate__zpass( void* attributeData ){return mImpl->begin__stencil_op_separate__zpass(*static_cast<stencil_op_separate__zpass__AttributeData*>(attributeData));}
bool _data__stencil_op_separate__zpass( const ParserChar* text, size_t textLength );
bool _end__stencil_op_separate__zpass(){return mImpl->end__stencil_op_separate__zpass();}
bool _validateBegin__stencil_op_separate__zpass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_op_separate__zpass();
bool _freeAttributes__stencil_op_separate__zpass( void* attributeData );

bool _begin__stencil_mask_separate( void* attributeData ){return mImpl->begin__stencil_mask_separate();}
bool _data__stencil_mask_separate( const ParserChar* text, size_t textLength );
bool _end__stencil_mask_separate(){return mImpl->end__stencil_mask_separate();}
bool _validateBegin__stencil_mask_separate( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_mask_separate();
bool _freeAttributes__stencil_mask_separate( void* attributeData );

bool _begin__stencil_mask_separate__face( void* attributeData ){return mImpl->begin__stencil_mask_separate__face(*static_cast<stencil_mask_separate__face__AttributeData*>(attributeData));}
bool _data__stencil_mask_separate__face( const ParserChar* text, size_t textLength );
bool _end__stencil_mask_separate__face(){return mImpl->end__stencil_mask_separate__face();}
bool _validateBegin__stencil_mask_separate__face( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_mask_separate__face();
bool _freeAttributes__stencil_mask_separate__face( void* attributeData );

bool _begin__stencil_mask_separate__mask( void* attributeData ){return mImpl->begin__stencil_mask_separate__mask(*static_cast<stencil_mask_separate__mask__AttributeData*>(attributeData));}
bool _data__stencil_mask_separate__mask( const ParserChar* text, size_t textLength );
bool _end__stencil_mask_separate__mask(){return mImpl->end__stencil_mask_separate__mask();}
bool _validateBegin__stencil_mask_separate__mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__stencil_mask_separate__mask();
bool _freeAttributes__stencil_mask_separate__mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_enable(*static_cast<profile_GLSL__technique__pass__light_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_enable(){return mImpl->end__profile_GLSL__technique__pass__light_enable();}
bool _validateBegin__profile_GLSL__technique__pass__light_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_enable();
bool _freeAttributes__profile_GLSL__technique__pass__light_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_ambient(*static_cast<profile_GLSL__technique__pass__light_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_ambient(){return mImpl->end__profile_GLSL__technique__pass__light_ambient();}
bool _validateBegin__profile_GLSL__technique__pass__light_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_ambient();
bool _freeAttributes__profile_GLSL__technique__pass__light_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_diffuse( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_diffuse(*static_cast<profile_GLSL__technique__pass__light_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_diffuse(){return mImpl->end__profile_GLSL__technique__pass__light_diffuse();}
bool _validateBegin__profile_GLSL__technique__pass__light_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_diffuse();
bool _freeAttributes__profile_GLSL__technique__pass__light_diffuse( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_specular( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_specular(*static_cast<profile_GLSL__technique__pass__light_specular__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_specular(){return mImpl->end__profile_GLSL__technique__pass__light_specular();}
bool _validateBegin__profile_GLSL__technique__pass__light_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_specular();
bool _freeAttributes__profile_GLSL__technique__pass__light_specular( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_position( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_position(*static_cast<profile_GLSL__technique__pass__light_position__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_position( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_position(){return mImpl->end__profile_GLSL__technique__pass__light_position();}
bool _validateBegin__profile_GLSL__technique__pass__light_position( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_position();
bool _freeAttributes__profile_GLSL__technique__pass__light_position( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_constant_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_constant_attenuation(*static_cast<profile_GLSL__technique__pass__light_constant_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_constant_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_constant_attenuation(){return mImpl->end__profile_GLSL__technique__pass__light_constant_attenuation();}
bool _validateBegin__profile_GLSL__technique__pass__light_constant_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_constant_attenuation();
bool _freeAttributes__profile_GLSL__technique__pass__light_constant_attenuation( void* attributeData );

bool _begin__light_linear_attenuation( void* attributeData ){return mImpl->begin__light_linear_attenuation(*static_cast<light_linear_attenuation__AttributeData*>(attributeData));}
bool _data__light_linear_attenuation( const ParserChar* text, size_t textLength );
bool _end__light_linear_attenuation(){return mImpl->end__light_linear_attenuation();}
bool _validateBegin__light_linear_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_linear_attenuation();
bool _freeAttributes__light_linear_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_quadratic_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_quadratic_attenuation(*static_cast<profile_GLSL__technique__pass__light_quadratic_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_quadratic_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_quadratic_attenuation(){return mImpl->end__profile_GLSL__technique__pass__light_quadratic_attenuation();}
bool _validateBegin__profile_GLSL__technique__pass__light_quadratic_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_quadratic_attenuation();
bool _freeAttributes__profile_GLSL__technique__pass__light_quadratic_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_spot_cutoff( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_spot_cutoff(*static_cast<profile_GLSL__technique__pass__light_spot_cutoff__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_spot_cutoff( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_spot_cutoff(){return mImpl->end__profile_GLSL__technique__pass__light_spot_cutoff();}
bool _validateBegin__profile_GLSL__technique__pass__light_spot_cutoff( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_spot_cutoff();
bool _freeAttributes__profile_GLSL__technique__pass__light_spot_cutoff( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_spot_direction( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_spot_direction(*static_cast<profile_GLSL__technique__pass__light_spot_direction__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_spot_direction( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_spot_direction(){return mImpl->end__profile_GLSL__technique__pass__light_spot_direction();}
bool _validateBegin__profile_GLSL__technique__pass__light_spot_direction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_spot_direction();
bool _freeAttributes__profile_GLSL__technique__pass__light_spot_direction( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_spot_exponent( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_spot_exponent(*static_cast<profile_GLSL__technique__pass__light_spot_exponent__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_spot_exponent( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_spot_exponent(){return mImpl->end__profile_GLSL__technique__pass__light_spot_exponent();}
bool _validateBegin__profile_GLSL__technique__pass__light_spot_exponent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_spot_exponent();
bool _freeAttributes__profile_GLSL__technique__pass__light_spot_exponent( void* attributeData );

bool _begin__texture1D( void* attributeData ){return mImpl->begin__texture1D(*static_cast<texture1D__AttributeData*>(attributeData));}
bool _data__texture1D( const ParserChar* text, size_t textLength );
bool _end__texture1D(){return mImpl->end__texture1D();}
bool _validateBegin__texture1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture1D();
bool _freeAttributes__texture1D( void* attributeData );

bool _begin__value____gl_sampler1D( void* attributeData ){return mImpl->begin__value____gl_sampler1D();}
bool _data__value____gl_sampler1D( const ParserChar* text, size_t textLength );
bool _end__value____gl_sampler1D(){return mImpl->end__value____gl_sampler1D();}
bool _validateBegin__value____gl_sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_sampler1D();
bool _freeAttributes__value____gl_sampler1D( void* attributeData );

bool _begin__param____NCName( void* attributeData ){return mImpl->begin__param____NCName();}
bool _data__param____NCName( const ParserChar* text, size_t textLength );
bool _end__param____NCName(){return mImpl->end__param____NCName();}
bool _validateBegin__param____NCName( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__param____NCName();
bool _freeAttributes__param____NCName( void* attributeData );

bool _begin__texture2D( void* attributeData ){return mImpl->begin__texture2D(*static_cast<texture2D__AttributeData*>(attributeData));}
bool _data__texture2D( const ParserChar* text, size_t textLength );
bool _end__texture2D(){return mImpl->end__texture2D();}
bool _validateBegin__texture2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture2D();
bool _freeAttributes__texture2D( void* attributeData );

bool _begin__value____gl_sampler2D( void* attributeData ){return mImpl->begin__value____gl_sampler2D();}
bool _data__value____gl_sampler2D( const ParserChar* text, size_t textLength );
bool _end__value____gl_sampler2D(){return mImpl->end__value____gl_sampler2D();}
bool _validateBegin__value____gl_sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_sampler2D();
bool _freeAttributes__value____gl_sampler2D( void* attributeData );

bool _begin__texture3D( void* attributeData ){return mImpl->begin__texture3D(*static_cast<texture3D__AttributeData*>(attributeData));}
bool _data__texture3D( const ParserChar* text, size_t textLength );
bool _end__texture3D(){return mImpl->end__texture3D();}
bool _validateBegin__texture3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture3D();
bool _freeAttributes__texture3D( void* attributeData );

bool _begin__value____gl_sampler3D( void* attributeData ){return mImpl->begin__value____gl_sampler3D();}
bool _data__value____gl_sampler3D( const ParserChar* text, size_t textLength );
bool _end__value____gl_sampler3D(){return mImpl->end__value____gl_sampler3D();}
bool _validateBegin__value____gl_sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_sampler3D();
bool _freeAttributes__value____gl_sampler3D( void* attributeData );

bool _begin__textureCUBE( void* attributeData ){return mImpl->begin__textureCUBE(*static_cast<textureCUBE__AttributeData*>(attributeData));}
bool _data__textureCUBE( const ParserChar* text, size_t textLength );
bool _end__textureCUBE(){return mImpl->end__textureCUBE();}
bool _validateBegin__textureCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureCUBE();
bool _freeAttributes__textureCUBE( void* attributeData );

bool _begin__value____gl_samplerCUBE( void* attributeData ){return mImpl->begin__value____gl_samplerCUBE();}
bool _data__value____gl_samplerCUBE( const ParserChar* text, size_t textLength );
bool _end__value____gl_samplerCUBE(){return mImpl->end__value____gl_samplerCUBE();}
bool _validateBegin__value____gl_samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_samplerCUBE();
bool _freeAttributes__value____gl_samplerCUBE( void* attributeData );

bool _begin__textureRECT( void* attributeData ){return mImpl->begin__textureRECT(*static_cast<textureRECT__AttributeData*>(attributeData));}
bool _data__textureRECT( const ParserChar* text, size_t textLength );
bool _end__textureRECT(){return mImpl->end__textureRECT();}
bool _validateBegin__textureRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureRECT();
bool _freeAttributes__textureRECT( void* attributeData );

bool _begin__value____gl_samplerRECT( void* attributeData ){return mImpl->begin__value____gl_samplerRECT();}
bool _data__value____gl_samplerRECT( const ParserChar* text, size_t textLength );
bool _end__value____gl_samplerRECT(){return mImpl->end__value____gl_samplerRECT();}
bool _validateBegin__value____gl_samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_samplerRECT();
bool _freeAttributes__value____gl_samplerRECT( void* attributeData );

bool _begin__textureDEPTH( void* attributeData ){return mImpl->begin__textureDEPTH(*static_cast<textureDEPTH__AttributeData*>(attributeData));}
bool _data__textureDEPTH( const ParserChar* text, size_t textLength );
bool _end__textureDEPTH(){return mImpl->end__textureDEPTH();}
bool _validateBegin__textureDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureDEPTH();
bool _freeAttributes__textureDEPTH( void* attributeData );

bool _begin__value____gl_samplerDEPTH( void* attributeData ){return mImpl->begin__value____gl_samplerDEPTH();}
bool _data__value____gl_samplerDEPTH( const ParserChar* text, size_t textLength );
bool _end__value____gl_samplerDEPTH(){return mImpl->end__value____gl_samplerDEPTH();}
bool _validateBegin__value____gl_samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__value____gl_samplerDEPTH();
bool _freeAttributes__value____gl_samplerDEPTH( void* attributeData );

bool _begin__texture1D_enable( void* attributeData ){return mImpl->begin__texture1D_enable(*static_cast<texture1D_enable__AttributeData*>(attributeData));}
bool _data__texture1D_enable( const ParserChar* text, size_t textLength );
bool _end__texture1D_enable(){return mImpl->end__texture1D_enable();}
bool _validateBegin__texture1D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture1D_enable();
bool _freeAttributes__texture1D_enable( void* attributeData );

bool _begin__texture2D_enable( void* attributeData ){return mImpl->begin__texture2D_enable(*static_cast<texture2D_enable__AttributeData*>(attributeData));}
bool _data__texture2D_enable( const ParserChar* text, size_t textLength );
bool _end__texture2D_enable(){return mImpl->end__texture2D_enable();}
bool _validateBegin__texture2D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture2D_enable();
bool _freeAttributes__texture2D_enable( void* attributeData );

bool _begin__texture3D_enable( void* attributeData ){return mImpl->begin__texture3D_enable(*static_cast<texture3D_enable__AttributeData*>(attributeData));}
bool _data__texture3D_enable( const ParserChar* text, size_t textLength );
bool _end__texture3D_enable(){return mImpl->end__texture3D_enable();}
bool _validateBegin__texture3D_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture3D_enable();
bool _freeAttributes__texture3D_enable( void* attributeData );

bool _begin__textureCUBE_enable( void* attributeData ){return mImpl->begin__textureCUBE_enable(*static_cast<textureCUBE_enable__AttributeData*>(attributeData));}
bool _data__textureCUBE_enable( const ParserChar* text, size_t textLength );
bool _end__textureCUBE_enable(){return mImpl->end__textureCUBE_enable();}
bool _validateBegin__textureCUBE_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureCUBE_enable();
bool _freeAttributes__textureCUBE_enable( void* attributeData );

bool _begin__textureRECT_enable( void* attributeData ){return mImpl->begin__textureRECT_enable(*static_cast<textureRECT_enable__AttributeData*>(attributeData));}
bool _data__textureRECT_enable( const ParserChar* text, size_t textLength );
bool _end__textureRECT_enable(){return mImpl->end__textureRECT_enable();}
bool _validateBegin__textureRECT_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureRECT_enable();
bool _freeAttributes__textureRECT_enable( void* attributeData );

bool _begin__textureDEPTH_enable( void* attributeData ){return mImpl->begin__textureDEPTH_enable(*static_cast<textureDEPTH_enable__AttributeData*>(attributeData));}
bool _data__textureDEPTH_enable( const ParserChar* text, size_t textLength );
bool _end__textureDEPTH_enable(){return mImpl->end__textureDEPTH_enable();}
bool _validateBegin__textureDEPTH_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__textureDEPTH_enable();
bool _freeAttributes__textureDEPTH_enable( void* attributeData );

bool _begin__texture_env_color( void* attributeData ){return mImpl->begin__texture_env_color(*static_cast<texture_env_color__AttributeData*>(attributeData));}
bool _data__texture_env_color( const ParserChar* text, size_t textLength );
bool _end__texture_env_color(){return mImpl->end__texture_env_color();}
bool _validateBegin__texture_env_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_env_color();
bool _freeAttributes__texture_env_color( void* attributeData );

bool _begin__texture_env_mode( void* attributeData ){return mImpl->begin__texture_env_mode(*static_cast<texture_env_mode__AttributeData*>(attributeData));}
bool _data__texture_env_mode( const ParserChar* text, size_t textLength );
bool _end__texture_env_mode(){return mImpl->end__texture_env_mode();}
bool _validateBegin__texture_env_mode( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture_env_mode();
bool _freeAttributes__texture_env_mode( void* attributeData );

bool _begin__profile_GLSL__technique__pass__clip_plane( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__clip_plane(*static_cast<profile_GLSL__technique__pass__clip_plane__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__clip_plane( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__clip_plane(){return mImpl->end__profile_GLSL__technique__pass__clip_plane();}
bool _validateBegin__profile_GLSL__technique__pass__clip_plane( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__clip_plane();
bool _freeAttributes__profile_GLSL__technique__pass__clip_plane( void* attributeData );

bool _begin__profile_GLSL__technique__pass__clip_plane_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__clip_plane_enable(*static_cast<profile_GLSL__technique__pass__clip_plane_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__clip_plane_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__clip_plane_enable(){return mImpl->end__profile_GLSL__technique__pass__clip_plane_enable();}
bool _validateBegin__profile_GLSL__technique__pass__clip_plane_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__clip_plane_enable();
bool _freeAttributes__profile_GLSL__technique__pass__clip_plane_enable( void* attributeData );

bool _begin__blend_color( void* attributeData ){return mImpl->begin__blend_color(*static_cast<blend_color__AttributeData*>(attributeData));}
bool _data__blend_color( const ParserChar* text, size_t textLength );
bool _end__blend_color(){return mImpl->end__blend_color();}
bool _validateBegin__blend_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blend_color();
bool _freeAttributes__blend_color( void* attributeData );

bool _begin__profile_GLSL__technique__pass__clear_color( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__clear_color(*static_cast<profile_GLSL__technique__pass__clear_color__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__clear_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__clear_color(){return mImpl->end__profile_GLSL__technique__pass__clear_color();}
bool _validateBegin__profile_GLSL__technique__pass__clear_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__clear_color();
bool _freeAttributes__profile_GLSL__technique__pass__clear_color( void* attributeData );

bool _begin__profile_GLSL__technique__pass__clear_stencil( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__clear_stencil(*static_cast<profile_GLSL__technique__pass__clear_stencil__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__clear_stencil( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__clear_stencil(){return mImpl->end__profile_GLSL__technique__pass__clear_stencil();}
bool _validateBegin__profile_GLSL__technique__pass__clear_stencil( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__clear_stencil();
bool _freeAttributes__profile_GLSL__technique__pass__clear_stencil( void* attributeData );

bool _begin__profile_GLSL__technique__pass__clear_depth( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__clear_depth(*static_cast<profile_GLSL__technique__pass__clear_depth__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__clear_depth( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__clear_depth(){return mImpl->end__profile_GLSL__technique__pass__clear_depth();}
bool _validateBegin__profile_GLSL__technique__pass__clear_depth( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__clear_depth();
bool _freeAttributes__profile_GLSL__technique__pass__clear_depth( void* attributeData );

bool _begin__profile_GLSL__technique__pass__color_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__color_mask(*static_cast<profile_GLSL__technique__pass__color_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__color_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__color_mask(){return mImpl->end__profile_GLSL__technique__pass__color_mask();}
bool _validateBegin__profile_GLSL__technique__pass__color_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__color_mask();
bool _freeAttributes__profile_GLSL__technique__pass__color_mask( void* attributeData );

bool _begin__depth_bounds( void* attributeData ){return mImpl->begin__depth_bounds(*static_cast<depth_bounds__AttributeData*>(attributeData));}
bool _data__depth_bounds( const ParserChar* text, size_t textLength );
bool _end__depth_bounds(){return mImpl->end__depth_bounds();}
bool _validateBegin__depth_bounds( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_bounds();
bool _freeAttributes__depth_bounds( void* attributeData );

bool _begin__profile_GLSL__technique__pass__depth_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__depth_mask(*static_cast<profile_GLSL__technique__pass__depth_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__depth_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__depth_mask(){return mImpl->end__profile_GLSL__technique__pass__depth_mask();}
bool _validateBegin__profile_GLSL__technique__pass__depth_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__depth_mask();
bool _freeAttributes__profile_GLSL__technique__pass__depth_mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__depth_range( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__depth_range(*static_cast<profile_GLSL__technique__pass__depth_range__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__depth_range( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__depth_range(){return mImpl->end__profile_GLSL__technique__pass__depth_range();}
bool _validateBegin__profile_GLSL__technique__pass__depth_range( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__depth_range();
bool _freeAttributes__profile_GLSL__technique__pass__depth_range( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_density( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_density(*static_cast<profile_GLSL__technique__pass__fog_density__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_density( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_density(){return mImpl->end__profile_GLSL__technique__pass__fog_density();}
bool _validateBegin__profile_GLSL__technique__pass__fog_density( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_density();
bool _freeAttributes__profile_GLSL__technique__pass__fog_density( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_start( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_start(*static_cast<profile_GLSL__technique__pass__fog_start__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_start( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_start(){return mImpl->end__profile_GLSL__technique__pass__fog_start();}
bool _validateBegin__profile_GLSL__technique__pass__fog_start( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_start();
bool _freeAttributes__profile_GLSL__technique__pass__fog_start( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_end( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_end(*static_cast<profile_GLSL__technique__pass__fog_end__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_end( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_end(){return mImpl->end__profile_GLSL__technique__pass__fog_end();}
bool _validateBegin__profile_GLSL__technique__pass__fog_end( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_end();
bool _freeAttributes__profile_GLSL__technique__pass__fog_end( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_color( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_color(*static_cast<profile_GLSL__technique__pass__fog_color__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_color( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_color(){return mImpl->end__profile_GLSL__technique__pass__fog_color();}
bool _validateBegin__profile_GLSL__technique__pass__fog_color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_color();
bool _freeAttributes__profile_GLSL__technique__pass__fog_color( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_model_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_model_ambient(*static_cast<profile_GLSL__technique__pass__light_model_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_model_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_model_ambient(){return mImpl->end__profile_GLSL__technique__pass__light_model_ambient();}
bool _validateBegin__profile_GLSL__technique__pass__light_model_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_model_ambient();
bool _freeAttributes__profile_GLSL__technique__pass__light_model_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__lighting_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__lighting_enable(*static_cast<profile_GLSL__technique__pass__lighting_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__lighting_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__lighting_enable(){return mImpl->end__profile_GLSL__technique__pass__lighting_enable();}
bool _validateBegin__profile_GLSL__technique__pass__lighting_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__lighting_enable();
bool _freeAttributes__profile_GLSL__technique__pass__lighting_enable( void* attributeData );

bool _begin__line_stipple( void* attributeData ){return mImpl->begin__line_stipple(*static_cast<line_stipple__AttributeData*>(attributeData));}
bool _data__line_stipple( const ParserChar* text, size_t textLength );
bool _end__line_stipple(){return mImpl->end__line_stipple();}
bool _validateBegin__line_stipple( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__line_stipple();
bool _freeAttributes__line_stipple( void* attributeData );

bool _begin__profile_GLSL__technique__pass__line_width( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__line_width(*static_cast<profile_GLSL__technique__pass__line_width__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__line_width( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__line_width(){return mImpl->end__profile_GLSL__technique__pass__line_width();}
bool _validateBegin__profile_GLSL__technique__pass__line_width( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__line_width();
bool _freeAttributes__profile_GLSL__technique__pass__line_width( void* attributeData );

bool _begin__profile_GLSL__technique__pass__material_ambient( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__material_ambient(*static_cast<profile_GLSL__technique__pass__material_ambient__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__material_ambient( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__material_ambient(){return mImpl->end__profile_GLSL__technique__pass__material_ambient();}
bool _validateBegin__profile_GLSL__technique__pass__material_ambient( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__material_ambient();
bool _freeAttributes__profile_GLSL__technique__pass__material_ambient( void* attributeData );

bool _begin__profile_GLSL__technique__pass__material_diffuse( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__material_diffuse(*static_cast<profile_GLSL__technique__pass__material_diffuse__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__material_diffuse( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__material_diffuse(){return mImpl->end__profile_GLSL__technique__pass__material_diffuse();}
bool _validateBegin__profile_GLSL__technique__pass__material_diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__material_diffuse();
bool _freeAttributes__profile_GLSL__technique__pass__material_diffuse( void* attributeData );

bool _begin__profile_GLSL__technique__pass__material_emission( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__material_emission(*static_cast<profile_GLSL__technique__pass__material_emission__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__material_emission( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__material_emission(){return mImpl->end__profile_GLSL__technique__pass__material_emission();}
bool _validateBegin__profile_GLSL__technique__pass__material_emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__material_emission();
bool _freeAttributes__profile_GLSL__technique__pass__material_emission( void* attributeData );

bool _begin__profile_GLSL__technique__pass__material_shininess( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__material_shininess(*static_cast<profile_GLSL__technique__pass__material_shininess__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__material_shininess( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__material_shininess(){return mImpl->end__profile_GLSL__technique__pass__material_shininess();}
bool _validateBegin__profile_GLSL__technique__pass__material_shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__material_shininess();
bool _freeAttributes__profile_GLSL__technique__pass__material_shininess( void* attributeData );

bool _begin__profile_GLSL__technique__pass__material_specular( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__material_specular(*static_cast<profile_GLSL__technique__pass__material_specular__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__material_specular( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__material_specular(){return mImpl->end__profile_GLSL__technique__pass__material_specular();}
bool _validateBegin__profile_GLSL__technique__pass__material_specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__material_specular();
bool _freeAttributes__profile_GLSL__technique__pass__material_specular( void* attributeData );

bool _begin__profile_GLSL__technique__pass__model_view_matrix( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__model_view_matrix(*static_cast<profile_GLSL__technique__pass__model_view_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__model_view_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__model_view_matrix(){return mImpl->end__profile_GLSL__technique__pass__model_view_matrix();}
bool _validateBegin__profile_GLSL__technique__pass__model_view_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__model_view_matrix();
bool _freeAttributes__profile_GLSL__technique__pass__model_view_matrix( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_distance_attenuation( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_distance_attenuation(*static_cast<profile_GLSL__technique__pass__point_distance_attenuation__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_distance_attenuation( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_distance_attenuation(){return mImpl->end__profile_GLSL__technique__pass__point_distance_attenuation();}
bool _validateBegin__profile_GLSL__technique__pass__point_distance_attenuation( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_distance_attenuation();
bool _freeAttributes__profile_GLSL__technique__pass__point_distance_attenuation( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_fade_threshold_size( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_fade_threshold_size(*static_cast<profile_GLSL__technique__pass__point_fade_threshold_size__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_fade_threshold_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_fade_threshold_size(){return mImpl->end__profile_GLSL__technique__pass__point_fade_threshold_size();}
bool _validateBegin__profile_GLSL__technique__pass__point_fade_threshold_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_fade_threshold_size();
bool _freeAttributes__profile_GLSL__technique__pass__point_fade_threshold_size( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_size( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_size(*static_cast<profile_GLSL__technique__pass__point_size__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_size( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_size(){return mImpl->end__profile_GLSL__technique__pass__point_size();}
bool _validateBegin__profile_GLSL__technique__pass__point_size( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_size();
bool _freeAttributes__profile_GLSL__technique__pass__point_size( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_size_min( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_size_min(*static_cast<profile_GLSL__technique__pass__point_size_min__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_size_min( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_size_min(){return mImpl->end__profile_GLSL__technique__pass__point_size_min();}
bool _validateBegin__profile_GLSL__technique__pass__point_size_min( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_size_min();
bool _freeAttributes__profile_GLSL__technique__pass__point_size_min( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_size_max( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_size_max(*static_cast<profile_GLSL__technique__pass__point_size_max__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_size_max( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_size_max(){return mImpl->end__profile_GLSL__technique__pass__point_size_max();}
bool _validateBegin__profile_GLSL__technique__pass__point_size_max( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_size_max();
bool _freeAttributes__profile_GLSL__technique__pass__point_size_max( void* attributeData );

bool _begin__profile_GLSL__technique__pass__polygon_offset( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__polygon_offset(*static_cast<profile_GLSL__technique__pass__polygon_offset__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__polygon_offset( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__polygon_offset(){return mImpl->end__profile_GLSL__technique__pass__polygon_offset();}
bool _validateBegin__profile_GLSL__technique__pass__polygon_offset( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__polygon_offset();
bool _freeAttributes__profile_GLSL__technique__pass__polygon_offset( void* attributeData );

bool _begin__profile_GLSL__technique__pass__projection_matrix( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__projection_matrix(*static_cast<profile_GLSL__technique__pass__projection_matrix__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__projection_matrix( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__projection_matrix(){return mImpl->end__profile_GLSL__technique__pass__projection_matrix();}
bool _validateBegin__profile_GLSL__technique__pass__projection_matrix( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__projection_matrix();
bool _freeAttributes__profile_GLSL__technique__pass__projection_matrix( void* attributeData );

bool _begin__profile_GLSL__technique__pass__scissor( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__scissor(*static_cast<profile_GLSL__technique__pass__scissor__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__scissor( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__scissor(){return mImpl->end__profile_GLSL__technique__pass__scissor();}
bool _validateBegin__profile_GLSL__technique__pass__scissor( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__scissor();
bool _freeAttributes__profile_GLSL__technique__pass__scissor( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_mask( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_mask(*static_cast<profile_GLSL__technique__pass__stencil_mask__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_mask( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_mask(){return mImpl->end__profile_GLSL__technique__pass__stencil_mask();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_mask( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_mask();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_mask( void* attributeData );

bool _begin__profile_GLSL__technique__pass__alpha_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__alpha_test_enable(*static_cast<profile_GLSL__technique__pass__alpha_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__alpha_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__alpha_test_enable(){return mImpl->end__profile_GLSL__technique__pass__alpha_test_enable();}
bool _validateBegin__profile_GLSL__technique__pass__alpha_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__alpha_test_enable();
bool _freeAttributes__profile_GLSL__technique__pass__alpha_test_enable( void* attributeData );

bool _begin__auto_normal_enable( void* attributeData ){return mImpl->begin__auto_normal_enable(*static_cast<auto_normal_enable__AttributeData*>(attributeData));}
bool _data__auto_normal_enable( const ParserChar* text, size_t textLength );
bool _end__auto_normal_enable(){return mImpl->end__auto_normal_enable();}
bool _validateBegin__auto_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__auto_normal_enable();
bool _freeAttributes__auto_normal_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__blend_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__blend_enable(*static_cast<profile_GLSL__technique__pass__blend_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__blend_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__blend_enable(){return mImpl->end__profile_GLSL__technique__pass__blend_enable();}
bool _validateBegin__profile_GLSL__technique__pass__blend_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__blend_enable();
bool _freeAttributes__profile_GLSL__technique__pass__blend_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__color_logic_op_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__color_logic_op_enable(*static_cast<profile_GLSL__technique__pass__color_logic_op_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__color_logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__color_logic_op_enable(){return mImpl->end__profile_GLSL__technique__pass__color_logic_op_enable();}
bool _validateBegin__profile_GLSL__technique__pass__color_logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__color_logic_op_enable();
bool _freeAttributes__profile_GLSL__technique__pass__color_logic_op_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__color_material_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__color_material_enable(*static_cast<profile_GLSL__technique__pass__color_material_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__color_material_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__color_material_enable(){return mImpl->end__profile_GLSL__technique__pass__color_material_enable();}
bool _validateBegin__profile_GLSL__technique__pass__color_material_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__color_material_enable();
bool _freeAttributes__profile_GLSL__technique__pass__color_material_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__cull_face_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__cull_face_enable(*static_cast<profile_GLSL__technique__pass__cull_face_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__cull_face_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__cull_face_enable(){return mImpl->end__profile_GLSL__technique__pass__cull_face_enable();}
bool _validateBegin__profile_GLSL__technique__pass__cull_face_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__cull_face_enable();
bool _freeAttributes__profile_GLSL__technique__pass__cull_face_enable( void* attributeData );

bool _begin__depth_bounds_enable( void* attributeData ){return mImpl->begin__depth_bounds_enable(*static_cast<depth_bounds_enable__AttributeData*>(attributeData));}
bool _data__depth_bounds_enable( const ParserChar* text, size_t textLength );
bool _end__depth_bounds_enable(){return mImpl->end__depth_bounds_enable();}
bool _validateBegin__depth_bounds_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_bounds_enable();
bool _freeAttributes__depth_bounds_enable( void* attributeData );

bool _begin__depth_clamp_enable( void* attributeData ){return mImpl->begin__depth_clamp_enable(*static_cast<depth_clamp_enable__AttributeData*>(attributeData));}
bool _data__depth_clamp_enable( const ParserChar* text, size_t textLength );
bool _end__depth_clamp_enable(){return mImpl->end__depth_clamp_enable();}
bool _validateBegin__depth_clamp_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__depth_clamp_enable();
bool _freeAttributes__depth_clamp_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__depth_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__depth_test_enable(*static_cast<profile_GLSL__technique__pass__depth_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__depth_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__depth_test_enable(){return mImpl->end__profile_GLSL__technique__pass__depth_test_enable();}
bool _validateBegin__profile_GLSL__technique__pass__depth_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__depth_test_enable();
bool _freeAttributes__profile_GLSL__technique__pass__depth_test_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__dither_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__dither_enable(*static_cast<profile_GLSL__technique__pass__dither_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__dither_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__dither_enable(){return mImpl->end__profile_GLSL__technique__pass__dither_enable();}
bool _validateBegin__profile_GLSL__technique__pass__dither_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__dither_enable();
bool _freeAttributes__profile_GLSL__technique__pass__dither_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__fog_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__fog_enable(*static_cast<profile_GLSL__technique__pass__fog_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__fog_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__fog_enable(){return mImpl->end__profile_GLSL__technique__pass__fog_enable();}
bool _validateBegin__profile_GLSL__technique__pass__fog_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__fog_enable();
bool _freeAttributes__profile_GLSL__technique__pass__fog_enable( void* attributeData );

bool _begin__light_model_local_viewer_enable( void* attributeData ){return mImpl->begin__light_model_local_viewer_enable(*static_cast<light_model_local_viewer_enable__AttributeData*>(attributeData));}
bool _data__light_model_local_viewer_enable( const ParserChar* text, size_t textLength );
bool _end__light_model_local_viewer_enable(){return mImpl->end__light_model_local_viewer_enable();}
bool _validateBegin__light_model_local_viewer_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__light_model_local_viewer_enable();
bool _freeAttributes__light_model_local_viewer_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__light_model_two_side_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__light_model_two_side_enable(*static_cast<profile_GLSL__technique__pass__light_model_two_side_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__light_model_two_side_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__light_model_two_side_enable(){return mImpl->end__profile_GLSL__technique__pass__light_model_two_side_enable();}
bool _validateBegin__profile_GLSL__technique__pass__light_model_two_side_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__light_model_two_side_enable();
bool _freeAttributes__profile_GLSL__technique__pass__light_model_two_side_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__line_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__line_smooth_enable(*static_cast<profile_GLSL__technique__pass__line_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__line_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__line_smooth_enable(){return mImpl->end__profile_GLSL__technique__pass__line_smooth_enable();}
bool _validateBegin__profile_GLSL__technique__pass__line_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__line_smooth_enable();
bool _freeAttributes__profile_GLSL__technique__pass__line_smooth_enable( void* attributeData );

bool _begin__line_stipple_enable( void* attributeData ){return mImpl->begin__line_stipple_enable(*static_cast<line_stipple_enable__AttributeData*>(attributeData));}
bool _data__line_stipple_enable( const ParserChar* text, size_t textLength );
bool _end__line_stipple_enable(){return mImpl->end__line_stipple_enable();}
bool _validateBegin__line_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__line_stipple_enable();
bool _freeAttributes__line_stipple_enable( void* attributeData );

bool _begin__logic_op_enable( void* attributeData ){return mImpl->begin__logic_op_enable(*static_cast<logic_op_enable__AttributeData*>(attributeData));}
bool _data__logic_op_enable( const ParserChar* text, size_t textLength );
bool _end__logic_op_enable(){return mImpl->end__logic_op_enable();}
bool _validateBegin__logic_op_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__logic_op_enable();
bool _freeAttributes__logic_op_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__multisample_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__multisample_enable(*static_cast<profile_GLSL__technique__pass__multisample_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__multisample_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__multisample_enable(){return mImpl->end__profile_GLSL__technique__pass__multisample_enable();}
bool _validateBegin__profile_GLSL__technique__pass__multisample_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__multisample_enable();
bool _freeAttributes__profile_GLSL__technique__pass__multisample_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__normalize_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__normalize_enable(*static_cast<profile_GLSL__technique__pass__normalize_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__normalize_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__normalize_enable(){return mImpl->end__profile_GLSL__technique__pass__normalize_enable();}
bool _validateBegin__profile_GLSL__technique__pass__normalize_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__normalize_enable();
bool _freeAttributes__profile_GLSL__technique__pass__normalize_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__point_smooth_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__point_smooth_enable(*static_cast<profile_GLSL__technique__pass__point_smooth_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__point_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__point_smooth_enable(){return mImpl->end__profile_GLSL__technique__pass__point_smooth_enable();}
bool _validateBegin__profile_GLSL__technique__pass__point_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__point_smooth_enable();
bool _freeAttributes__profile_GLSL__technique__pass__point_smooth_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__polygon_offset_fill_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__polygon_offset_fill_enable(*static_cast<profile_GLSL__technique__pass__polygon_offset_fill_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__polygon_offset_fill_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__polygon_offset_fill_enable(){return mImpl->end__profile_GLSL__technique__pass__polygon_offset_fill_enable();}
bool _validateBegin__profile_GLSL__technique__pass__polygon_offset_fill_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__polygon_offset_fill_enable();
bool _freeAttributes__profile_GLSL__technique__pass__polygon_offset_fill_enable( void* attributeData );

bool _begin__polygon_offset_line_enable( void* attributeData ){return mImpl->begin__polygon_offset_line_enable(*static_cast<polygon_offset_line_enable__AttributeData*>(attributeData));}
bool _data__polygon_offset_line_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_offset_line_enable(){return mImpl->end__polygon_offset_line_enable();}
bool _validateBegin__polygon_offset_line_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_offset_line_enable();
bool _freeAttributes__polygon_offset_line_enable( void* attributeData );

bool _begin__polygon_offset_point_enable( void* attributeData ){return mImpl->begin__polygon_offset_point_enable(*static_cast<polygon_offset_point_enable__AttributeData*>(attributeData));}
bool _data__polygon_offset_point_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_offset_point_enable(){return mImpl->end__polygon_offset_point_enable();}
bool _validateBegin__polygon_offset_point_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_offset_point_enable();
bool _freeAttributes__polygon_offset_point_enable( void* attributeData );

bool _begin__polygon_smooth_enable( void* attributeData ){return mImpl->begin__polygon_smooth_enable(*static_cast<polygon_smooth_enable__AttributeData*>(attributeData));}
bool _data__polygon_smooth_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_smooth_enable(){return mImpl->end__polygon_smooth_enable();}
bool _validateBegin__polygon_smooth_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_smooth_enable();
bool _freeAttributes__polygon_smooth_enable( void* attributeData );

bool _begin__polygon_stipple_enable( void* attributeData ){return mImpl->begin__polygon_stipple_enable(*static_cast<polygon_stipple_enable__AttributeData*>(attributeData));}
bool _data__polygon_stipple_enable( const ParserChar* text, size_t textLength );
bool _end__polygon_stipple_enable(){return mImpl->end__polygon_stipple_enable();}
bool _validateBegin__polygon_stipple_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__polygon_stipple_enable();
bool _freeAttributes__polygon_stipple_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__rescale_normal_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__rescale_normal_enable(*static_cast<profile_GLSL__technique__pass__rescale_normal_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__rescale_normal_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__rescale_normal_enable(){return mImpl->end__profile_GLSL__technique__pass__rescale_normal_enable();}
bool _validateBegin__profile_GLSL__technique__pass__rescale_normal_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__rescale_normal_enable();
bool _freeAttributes__profile_GLSL__technique__pass__rescale_normal_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable(*static_cast<profile_GLSL__technique__pass__sample_alpha_to_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable(){return mImpl->end__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable();}
bool _validateBegin__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable();
bool _freeAttributes__profile_GLSL__technique__pass__sample_alpha_to_coverage_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__sample_alpha_to_one_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__sample_alpha_to_one_enable(*static_cast<profile_GLSL__technique__pass__sample_alpha_to_one_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__sample_alpha_to_one_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__sample_alpha_to_one_enable(){return mImpl->end__profile_GLSL__technique__pass__sample_alpha_to_one_enable();}
bool _validateBegin__profile_GLSL__technique__pass__sample_alpha_to_one_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__sample_alpha_to_one_enable();
bool _freeAttributes__profile_GLSL__technique__pass__sample_alpha_to_one_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__sample_coverage_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__sample_coverage_enable(*static_cast<profile_GLSL__technique__pass__sample_coverage_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__sample_coverage_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__sample_coverage_enable(){return mImpl->end__profile_GLSL__technique__pass__sample_coverage_enable();}
bool _validateBegin__profile_GLSL__technique__pass__sample_coverage_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__sample_coverage_enable();
bool _freeAttributes__profile_GLSL__technique__pass__sample_coverage_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__scissor_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__scissor_test_enable(*static_cast<profile_GLSL__technique__pass__scissor_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__scissor_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__scissor_test_enable(){return mImpl->end__profile_GLSL__technique__pass__scissor_test_enable();}
bool _validateBegin__profile_GLSL__technique__pass__scissor_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__scissor_test_enable();
bool _freeAttributes__profile_GLSL__technique__pass__scissor_test_enable( void* attributeData );

bool _begin__profile_GLSL__technique__pass__stencil_test_enable( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__stencil_test_enable(*static_cast<profile_GLSL__technique__pass__stencil_test_enable__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__stencil_test_enable( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__stencil_test_enable(){return mImpl->end__profile_GLSL__technique__pass__stencil_test_enable();}
bool _validateBegin__profile_GLSL__technique__pass__stencil_test_enable( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__stencil_test_enable();
bool _freeAttributes__profile_GLSL__technique__pass__stencil_test_enable( void* attributeData );

bool _begin__gl_hook_abstract( void* attributeData ){return mImpl->begin__gl_hook_abstract();}
bool _data__gl_hook_abstract( const ParserChar* text, size_t textLength );
bool _end__gl_hook_abstract(){return mImpl->end__gl_hook_abstract();}
bool _validateBegin__gl_hook_abstract( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__gl_hook_abstract();
bool _freeAttributes__gl_hook_abstract( void* attributeData );

bool _begin__profile_GLSL__technique__pass__shader( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shader(*static_cast<profile_GLSL__technique__pass__shader__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__shader( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shader(){return mImpl->end__profile_GLSL__technique__pass__shader();}
bool _validateBegin__profile_GLSL__technique__pass__shader( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shader();
bool _freeAttributes__profile_GLSL__technique__pass__shader( void* attributeData );


ENUM__glsl_pipeline_stage toEnumDataPrefix_ENUM__glsl_pipeline_stage (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__glsl_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__glsl_pipeline_stage (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__glsl_pipeline_stage*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__glsl_pipeline_stage (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__glsl_pipeline_stage*, size_t ),
    const std::pair<StringHash, ENUM__glsl_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__glsl_pipeline_stage (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__glsl_pipeline_stage>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__profile_GLSL__technique__pass__shader__compiler_target( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shader__compiler_target();}
bool _data__profile_GLSL__technique__pass__shader__compiler_target( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shader__compiler_target(){return mImpl->end__profile_GLSL__technique__pass__shader__compiler_target();}
bool _validateBegin__profile_GLSL__technique__pass__shader__compiler_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shader__compiler_target();
bool _freeAttributes__profile_GLSL__technique__pass__shader__compiler_target( void* attributeData );

bool _begin__compiler_options( void* attributeData ){return mImpl->begin__compiler_options();}
bool _data__compiler_options( const ParserChar* text, size_t textLength );
bool _end__compiler_options(){return mImpl->end__compiler_options();}
bool _validateBegin__compiler_options( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__compiler_options();
bool _freeAttributes__compiler_options( void* attributeData );

bool _begin__profile_GLSL__technique__pass__shader__name( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shader__name(*static_cast<profile_GLSL__technique__pass__shader__name__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__shader__name( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shader__name(){return mImpl->end__profile_GLSL__technique__pass__shader__name();}
bool _validateBegin__profile_GLSL__technique__pass__shader__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shader__name();
bool _freeAttributes__profile_GLSL__technique__pass__shader__name( void* attributeData );

bool _begin__profile_GLSL__technique__pass__shader__bind( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shader__bind(*static_cast<profile_GLSL__technique__pass__shader__bind__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__shader__bind( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shader__bind(){return mImpl->end__profile_GLSL__technique__pass__shader__bind();}
bool _validateBegin__profile_GLSL__technique__pass__shader__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shader__bind();
bool _freeAttributes__profile_GLSL__technique__pass__shader__bind( void* attributeData );

bool _begin__profile_GLSL__technique__pass__shader__bind__param( void* attributeData ){return mImpl->begin__profile_GLSL__technique__pass__shader__bind__param(*static_cast<profile_GLSL__technique__pass__shader__bind__param__AttributeData*>(attributeData));}
bool _data__profile_GLSL__technique__pass__shader__bind__param( const ParserChar* text, size_t textLength );
bool _end__profile_GLSL__technique__pass__shader__bind__param(){return mImpl->end__profile_GLSL__technique__pass__shader__bind__param();}
bool _validateBegin__profile_GLSL__technique__pass__shader__bind__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_GLSL__technique__pass__shader__bind__param();
bool _freeAttributes__profile_GLSL__technique__pass__shader__bind__param( void* attributeData );

bool _begin__profile_CG( void* attributeData ){return mImpl->begin__profile_CG(*static_cast<profile_CG__AttributeData*>(attributeData));}
bool _data__profile_CG( const ParserChar* text, size_t textLength );
bool _end__profile_CG(){return mImpl->end__profile_CG();}
bool _validateBegin__profile_CG( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG();
bool _freeAttributes__profile_CG( void* attributeData );

bool _begin__newparam____cg_newparam( void* attributeData ){return mImpl->begin__newparam____cg_newparam(*static_cast<newparam____cg_newparam__AttributeData*>(attributeData));}
bool _data__newparam____cg_newparam( const ParserChar* text, size_t textLength );
bool _end__newparam____cg_newparam(){return mImpl->end__newparam____cg_newparam();}
bool _validateBegin__newparam____cg_newparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____cg_newparam();
bool _freeAttributes__newparam____cg_newparam( void* attributeData );

bool _begin__bool____cg_bool( void* attributeData ){return mImpl->begin__bool____cg_bool();}
bool _data__bool____cg_bool( const ParserChar* text, size_t textLength );
bool _end__bool____cg_bool(){return mImpl->end__bool____cg_bool();}
bool _validateBegin__bool____cg_bool( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool____cg_bool();
bool _freeAttributes__bool____cg_bool( void* attributeData );

bool _begin__bool1( void* attributeData ){return mImpl->begin__bool1();}
bool _data__bool1( const ParserChar* text, size_t textLength );
bool _end__bool1(){return mImpl->end__bool1();}
bool _validateBegin__bool1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool1();
bool _freeAttributes__bool1( void* attributeData );

bool _begin__bool2____cg_bool2( void* attributeData ){return mImpl->begin__bool2____cg_bool2();}
bool _data__bool2____cg_bool2( const ParserChar* text, size_t textLength );
bool _end__bool2____cg_bool2(){return mImpl->end__bool2____cg_bool2();}
bool _validateBegin__bool2____cg_bool2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2____cg_bool2();
bool _freeAttributes__bool2____cg_bool2( void* attributeData );

bool _begin__bool3____cg_bool3( void* attributeData ){return mImpl->begin__bool3____cg_bool3();}
bool _data__bool3____cg_bool3( const ParserChar* text, size_t textLength );
bool _end__bool3____cg_bool3(){return mImpl->end__bool3____cg_bool3();}
bool _validateBegin__bool3____cg_bool3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3____cg_bool3();
bool _freeAttributes__bool3____cg_bool3( void* attributeData );

bool _begin__bool4____cg_bool4( void* attributeData ){return mImpl->begin__bool4____cg_bool4();}
bool _data__bool4____cg_bool4( const ParserChar* text, size_t textLength );
bool _end__bool4____cg_bool4(){return mImpl->end__bool4____cg_bool4();}
bool _validateBegin__bool4____cg_bool4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4____cg_bool4();
bool _freeAttributes__bool4____cg_bool4( void* attributeData );

bool _begin__bool1x1( void* attributeData ){return mImpl->begin__bool1x1();}
bool _data__bool1x1( const ParserChar* text, size_t textLength );
bool _end__bool1x1(){return mImpl->end__bool1x1();}
bool _validateBegin__bool1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool1x1();
bool _freeAttributes__bool1x1( void* attributeData );

bool _begin__bool1x2( void* attributeData ){return mImpl->begin__bool1x2();}
bool _data__bool1x2( const ParserChar* text, size_t textLength );
bool _end__bool1x2(){return mImpl->end__bool1x2();}
bool _validateBegin__bool1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool1x2();
bool _freeAttributes__bool1x2( void* attributeData );

bool _begin__bool1x3( void* attributeData ){return mImpl->begin__bool1x3();}
bool _data__bool1x3( const ParserChar* text, size_t textLength );
bool _end__bool1x3(){return mImpl->end__bool1x3();}
bool _validateBegin__bool1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool1x3();
bool _freeAttributes__bool1x3( void* attributeData );

bool _begin__bool1x4( void* attributeData ){return mImpl->begin__bool1x4();}
bool _data__bool1x4( const ParserChar* text, size_t textLength );
bool _end__bool1x4(){return mImpl->end__bool1x4();}
bool _validateBegin__bool1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool1x4();
bool _freeAttributes__bool1x4( void* attributeData );

bool _begin__bool2x1( void* attributeData ){return mImpl->begin__bool2x1();}
bool _data__bool2x1( const ParserChar* text, size_t textLength );
bool _end__bool2x1(){return mImpl->end__bool2x1();}
bool _validateBegin__bool2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x1();
bool _freeAttributes__bool2x1( void* attributeData );

bool _begin__bool2x2( void* attributeData ){return mImpl->begin__bool2x2();}
bool _data__bool2x2( const ParserChar* text, size_t textLength );
bool _end__bool2x2(){return mImpl->end__bool2x2();}
bool _validateBegin__bool2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x2();
bool _freeAttributes__bool2x2( void* attributeData );

bool _begin__bool2x3( void* attributeData ){return mImpl->begin__bool2x3();}
bool _data__bool2x3( const ParserChar* text, size_t textLength );
bool _end__bool2x3(){return mImpl->end__bool2x3();}
bool _validateBegin__bool2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x3();
bool _freeAttributes__bool2x3( void* attributeData );

bool _begin__bool2x4( void* attributeData ){return mImpl->begin__bool2x4();}
bool _data__bool2x4( const ParserChar* text, size_t textLength );
bool _end__bool2x4(){return mImpl->end__bool2x4();}
bool _validateBegin__bool2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool2x4();
bool _freeAttributes__bool2x4( void* attributeData );

bool _begin__bool3x1( void* attributeData ){return mImpl->begin__bool3x1();}
bool _data__bool3x1( const ParserChar* text, size_t textLength );
bool _end__bool3x1(){return mImpl->end__bool3x1();}
bool _validateBegin__bool3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x1();
bool _freeAttributes__bool3x1( void* attributeData );

bool _begin__bool3x2( void* attributeData ){return mImpl->begin__bool3x2();}
bool _data__bool3x2( const ParserChar* text, size_t textLength );
bool _end__bool3x2(){return mImpl->end__bool3x2();}
bool _validateBegin__bool3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x2();
bool _freeAttributes__bool3x2( void* attributeData );

bool _begin__bool3x3( void* attributeData ){return mImpl->begin__bool3x3();}
bool _data__bool3x3( const ParserChar* text, size_t textLength );
bool _end__bool3x3(){return mImpl->end__bool3x3();}
bool _validateBegin__bool3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x3();
bool _freeAttributes__bool3x3( void* attributeData );

bool _begin__bool3x4( void* attributeData ){return mImpl->begin__bool3x4();}
bool _data__bool3x4( const ParserChar* text, size_t textLength );
bool _end__bool3x4(){return mImpl->end__bool3x4();}
bool _validateBegin__bool3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool3x4();
bool _freeAttributes__bool3x4( void* attributeData );

bool _begin__bool4x1( void* attributeData ){return mImpl->begin__bool4x1();}
bool _data__bool4x1( const ParserChar* text, size_t textLength );
bool _end__bool4x1(){return mImpl->end__bool4x1();}
bool _validateBegin__bool4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x1();
bool _freeAttributes__bool4x1( void* attributeData );

bool _begin__bool4x2( void* attributeData ){return mImpl->begin__bool4x2();}
bool _data__bool4x2( const ParserChar* text, size_t textLength );
bool _end__bool4x2(){return mImpl->end__bool4x2();}
bool _validateBegin__bool4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x2();
bool _freeAttributes__bool4x2( void* attributeData );

bool _begin__bool4x3( void* attributeData ){return mImpl->begin__bool4x3();}
bool _data__bool4x3( const ParserChar* text, size_t textLength );
bool _end__bool4x3(){return mImpl->end__bool4x3();}
bool _validateBegin__bool4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x3();
bool _freeAttributes__bool4x3( void* attributeData );

bool _begin__bool4x4( void* attributeData ){return mImpl->begin__bool4x4();}
bool _data__bool4x4( const ParserChar* text, size_t textLength );
bool _end__bool4x4(){return mImpl->end__bool4x4();}
bool _validateBegin__bool4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__bool4x4();
bool _freeAttributes__bool4x4( void* attributeData );

bool _begin__float____cg_float( void* attributeData ){return mImpl->begin__float____cg_float();}
bool _data__float____cg_float( const ParserChar* text, size_t textLength );
bool _end__float____cg_float(){return mImpl->end__float____cg_float();}
bool _validateBegin__float____cg_float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float____cg_float();
bool _freeAttributes__float____cg_float( void* attributeData );

bool _begin__float1( void* attributeData ){return mImpl->begin__float1();}
bool _data__float1( const ParserChar* text, size_t textLength );
bool _end__float1(){return mImpl->end__float1();}
bool _validateBegin__float1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1();
bool _freeAttributes__float1( void* attributeData );

bool _begin__float2____cg_float2( void* attributeData ){return mImpl->begin__float2____cg_float2();}
bool _data__float2____cg_float2( const ParserChar* text, size_t textLength );
bool _end__float2____cg_float2(){return mImpl->end__float2____cg_float2();}
bool _validateBegin__float2____cg_float2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2____cg_float2();
bool _freeAttributes__float2____cg_float2( void* attributeData );

bool _begin__float3____cg_float3( void* attributeData ){return mImpl->begin__float3____cg_float3();}
bool _data__float3____cg_float3( const ParserChar* text, size_t textLength );
bool _end__float3____cg_float3(){return mImpl->end__float3____cg_float3();}
bool _validateBegin__float3____cg_float3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3____cg_float3();
bool _freeAttributes__float3____cg_float3( void* attributeData );

bool _begin__float4____cg_float4( void* attributeData ){return mImpl->begin__float4____cg_float4();}
bool _data__float4____cg_float4( const ParserChar* text, size_t textLength );
bool _end__float4____cg_float4(){return mImpl->end__float4____cg_float4();}
bool _validateBegin__float4____cg_float4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4____cg_float4();
bool _freeAttributes__float4____cg_float4( void* attributeData );

bool _begin__float1x1____cg_float1x1( void* attributeData ){return mImpl->begin__float1x1____cg_float1x1();}
bool _data__float1x1____cg_float1x1( const ParserChar* text, size_t textLength );
bool _end__float1x1____cg_float1x1(){return mImpl->end__float1x1____cg_float1x1();}
bool _validateBegin__float1x1____cg_float1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x1____cg_float1x1();
bool _freeAttributes__float1x1____cg_float1x1( void* attributeData );

bool _begin__float1x2____cg_float1x2( void* attributeData ){return mImpl->begin__float1x2____cg_float1x2();}
bool _data__float1x2____cg_float1x2( const ParserChar* text, size_t textLength );
bool _end__float1x2____cg_float1x2(){return mImpl->end__float1x2____cg_float1x2();}
bool _validateBegin__float1x2____cg_float1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x2____cg_float1x2();
bool _freeAttributes__float1x2____cg_float1x2( void* attributeData );

bool _begin__float1x3____cg_float1x3( void* attributeData ){return mImpl->begin__float1x3____cg_float1x3();}
bool _data__float1x3____cg_float1x3( const ParserChar* text, size_t textLength );
bool _end__float1x3____cg_float1x3(){return mImpl->end__float1x3____cg_float1x3();}
bool _validateBegin__float1x3____cg_float1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x3____cg_float1x3();
bool _freeAttributes__float1x3____cg_float1x3( void* attributeData );

bool _begin__float1x4____cg_float1x4( void* attributeData ){return mImpl->begin__float1x4____cg_float1x4();}
bool _data__float1x4____cg_float1x4( const ParserChar* text, size_t textLength );
bool _end__float1x4____cg_float1x4(){return mImpl->end__float1x4____cg_float1x4();}
bool _validateBegin__float1x4____cg_float1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float1x4____cg_float1x4();
bool _freeAttributes__float1x4____cg_float1x4( void* attributeData );

bool _begin__float2x1____cg_float2x1( void* attributeData ){return mImpl->begin__float2x1____cg_float2x1();}
bool _data__float2x1____cg_float2x1( const ParserChar* text, size_t textLength );
bool _end__float2x1____cg_float2x1(){return mImpl->end__float2x1____cg_float2x1();}
bool _validateBegin__float2x1____cg_float2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x1____cg_float2x1();
bool _freeAttributes__float2x1____cg_float2x1( void* attributeData );

bool _begin__float2x2____cg_float2x2( void* attributeData ){return mImpl->begin__float2x2____cg_float2x2();}
bool _data__float2x2____cg_float2x2( const ParserChar* text, size_t textLength );
bool _end__float2x2____cg_float2x2(){return mImpl->end__float2x2____cg_float2x2();}
bool _validateBegin__float2x2____cg_float2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x2____cg_float2x2();
bool _freeAttributes__float2x2____cg_float2x2( void* attributeData );

bool _begin__float2x3____cg_float2x3( void* attributeData ){return mImpl->begin__float2x3____cg_float2x3();}
bool _data__float2x3____cg_float2x3( const ParserChar* text, size_t textLength );
bool _end__float2x3____cg_float2x3(){return mImpl->end__float2x3____cg_float2x3();}
bool _validateBegin__float2x3____cg_float2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x3____cg_float2x3();
bool _freeAttributes__float2x3____cg_float2x3( void* attributeData );

bool _begin__float2x4____cg_float2x4( void* attributeData ){return mImpl->begin__float2x4____cg_float2x4();}
bool _data__float2x4____cg_float2x4( const ParserChar* text, size_t textLength );
bool _end__float2x4____cg_float2x4(){return mImpl->end__float2x4____cg_float2x4();}
bool _validateBegin__float2x4____cg_float2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float2x4____cg_float2x4();
bool _freeAttributes__float2x4____cg_float2x4( void* attributeData );

bool _begin__float3x1____cg_float3x1( void* attributeData ){return mImpl->begin__float3x1____cg_float3x1();}
bool _data__float3x1____cg_float3x1( const ParserChar* text, size_t textLength );
bool _end__float3x1____cg_float3x1(){return mImpl->end__float3x1____cg_float3x1();}
bool _validateBegin__float3x1____cg_float3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x1____cg_float3x1();
bool _freeAttributes__float3x1____cg_float3x1( void* attributeData );

bool _begin__float3x2____cg_float3x2( void* attributeData ){return mImpl->begin__float3x2____cg_float3x2();}
bool _data__float3x2____cg_float3x2( const ParserChar* text, size_t textLength );
bool _end__float3x2____cg_float3x2(){return mImpl->end__float3x2____cg_float3x2();}
bool _validateBegin__float3x2____cg_float3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x2____cg_float3x2();
bool _freeAttributes__float3x2____cg_float3x2( void* attributeData );

bool _begin__float3x3____cg_float3x3( void* attributeData ){return mImpl->begin__float3x3____cg_float3x3();}
bool _data__float3x3____cg_float3x3( const ParserChar* text, size_t textLength );
bool _end__float3x3____cg_float3x3(){return mImpl->end__float3x3____cg_float3x3();}
bool _validateBegin__float3x3____cg_float3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x3____cg_float3x3();
bool _freeAttributes__float3x3____cg_float3x3( void* attributeData );

bool _begin__float3x4____cg_float3x4( void* attributeData ){return mImpl->begin__float3x4____cg_float3x4();}
bool _data__float3x4____cg_float3x4( const ParserChar* text, size_t textLength );
bool _end__float3x4____cg_float3x4(){return mImpl->end__float3x4____cg_float3x4();}
bool _validateBegin__float3x4____cg_float3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float3x4____cg_float3x4();
bool _freeAttributes__float3x4____cg_float3x4( void* attributeData );

bool _begin__float4x1____cg_float4x1( void* attributeData ){return mImpl->begin__float4x1____cg_float4x1();}
bool _data__float4x1____cg_float4x1( const ParserChar* text, size_t textLength );
bool _end__float4x1____cg_float4x1(){return mImpl->end__float4x1____cg_float4x1();}
bool _validateBegin__float4x1____cg_float4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x1____cg_float4x1();
bool _freeAttributes__float4x1____cg_float4x1( void* attributeData );

bool _begin__float4x2____cg_float4x2( void* attributeData ){return mImpl->begin__float4x2____cg_float4x2();}
bool _data__float4x2____cg_float4x2( const ParserChar* text, size_t textLength );
bool _end__float4x2____cg_float4x2(){return mImpl->end__float4x2____cg_float4x2();}
bool _validateBegin__float4x2____cg_float4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x2____cg_float4x2();
bool _freeAttributes__float4x2____cg_float4x2( void* attributeData );

bool _begin__float4x3____cg_float4x3( void* attributeData ){return mImpl->begin__float4x3____cg_float4x3();}
bool _data__float4x3____cg_float4x3( const ParserChar* text, size_t textLength );
bool _end__float4x3____cg_float4x3(){return mImpl->end__float4x3____cg_float4x3();}
bool _validateBegin__float4x3____cg_float4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x3____cg_float4x3();
bool _freeAttributes__float4x3____cg_float4x3( void* attributeData );

bool _begin__float4x4____cg_float4x4( void* attributeData ){return mImpl->begin__float4x4____cg_float4x4();}
bool _data__float4x4____cg_float4x4( const ParserChar* text, size_t textLength );
bool _end__float4x4____cg_float4x4(){return mImpl->end__float4x4____cg_float4x4();}
bool _validateBegin__float4x4____cg_float4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__float4x4____cg_float4x4();
bool _freeAttributes__float4x4____cg_float4x4( void* attributeData );

bool _begin__int____cg_int( void* attributeData ){return mImpl->begin__int____cg_int();}
bool _data__int____cg_int( const ParserChar* text, size_t textLength );
bool _end__int____cg_int(){return mImpl->end__int____cg_int();}
bool _validateBegin__int____cg_int( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int____cg_int();
bool _freeAttributes__int____cg_int( void* attributeData );

bool _begin__int1( void* attributeData ){return mImpl->begin__int1();}
bool _data__int1( const ParserChar* text, size_t textLength );
bool _end__int1(){return mImpl->end__int1();}
bool _validateBegin__int1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int1();
bool _freeAttributes__int1( void* attributeData );

bool _begin__int2____cg_int2( void* attributeData ){return mImpl->begin__int2____cg_int2();}
bool _data__int2____cg_int2( const ParserChar* text, size_t textLength );
bool _end__int2____cg_int2(){return mImpl->end__int2____cg_int2();}
bool _validateBegin__int2____cg_int2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2____cg_int2();
bool _freeAttributes__int2____cg_int2( void* attributeData );

bool _begin__int3____cg_int3( void* attributeData ){return mImpl->begin__int3____cg_int3();}
bool _data__int3____cg_int3( const ParserChar* text, size_t textLength );
bool _end__int3____cg_int3(){return mImpl->end__int3____cg_int3();}
bool _validateBegin__int3____cg_int3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3____cg_int3();
bool _freeAttributes__int3____cg_int3( void* attributeData );

bool _begin__int4____cg_int4( void* attributeData ){return mImpl->begin__int4____cg_int4();}
bool _data__int4____cg_int4( const ParserChar* text, size_t textLength );
bool _end__int4____cg_int4(){return mImpl->end__int4____cg_int4();}
bool _validateBegin__int4____cg_int4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4____cg_int4();
bool _freeAttributes__int4____cg_int4( void* attributeData );

bool _begin__int1x1( void* attributeData ){return mImpl->begin__int1x1();}
bool _data__int1x1( const ParserChar* text, size_t textLength );
bool _end__int1x1(){return mImpl->end__int1x1();}
bool _validateBegin__int1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int1x1();
bool _freeAttributes__int1x1( void* attributeData );

bool _begin__int1x2( void* attributeData ){return mImpl->begin__int1x2();}
bool _data__int1x2( const ParserChar* text, size_t textLength );
bool _end__int1x2(){return mImpl->end__int1x2();}
bool _validateBegin__int1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int1x2();
bool _freeAttributes__int1x2( void* attributeData );

bool _begin__int1x3( void* attributeData ){return mImpl->begin__int1x3();}
bool _data__int1x3( const ParserChar* text, size_t textLength );
bool _end__int1x3(){return mImpl->end__int1x3();}
bool _validateBegin__int1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int1x3();
bool _freeAttributes__int1x3( void* attributeData );

bool _begin__int1x4( void* attributeData ){return mImpl->begin__int1x4();}
bool _data__int1x4( const ParserChar* text, size_t textLength );
bool _end__int1x4(){return mImpl->end__int1x4();}
bool _validateBegin__int1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int1x4();
bool _freeAttributes__int1x4( void* attributeData );

bool _begin__int2x1( void* attributeData ){return mImpl->begin__int2x1();}
bool _data__int2x1( const ParserChar* text, size_t textLength );
bool _end__int2x1(){return mImpl->end__int2x1();}
bool _validateBegin__int2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x1();
bool _freeAttributes__int2x1( void* attributeData );

bool _begin__int2x2( void* attributeData ){return mImpl->begin__int2x2();}
bool _data__int2x2( const ParserChar* text, size_t textLength );
bool _end__int2x2(){return mImpl->end__int2x2();}
bool _validateBegin__int2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x2();
bool _freeAttributes__int2x2( void* attributeData );

bool _begin__int2x3( void* attributeData ){return mImpl->begin__int2x3();}
bool _data__int2x3( const ParserChar* text, size_t textLength );
bool _end__int2x3(){return mImpl->end__int2x3();}
bool _validateBegin__int2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x3();
bool _freeAttributes__int2x3( void* attributeData );

bool _begin__int2x4( void* attributeData ){return mImpl->begin__int2x4();}
bool _data__int2x4( const ParserChar* text, size_t textLength );
bool _end__int2x4(){return mImpl->end__int2x4();}
bool _validateBegin__int2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int2x4();
bool _freeAttributes__int2x4( void* attributeData );

bool _begin__int3x1( void* attributeData ){return mImpl->begin__int3x1();}
bool _data__int3x1( const ParserChar* text, size_t textLength );
bool _end__int3x1(){return mImpl->end__int3x1();}
bool _validateBegin__int3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x1();
bool _freeAttributes__int3x1( void* attributeData );

bool _begin__int3x2( void* attributeData ){return mImpl->begin__int3x2();}
bool _data__int3x2( const ParserChar* text, size_t textLength );
bool _end__int3x2(){return mImpl->end__int3x2();}
bool _validateBegin__int3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x2();
bool _freeAttributes__int3x2( void* attributeData );

bool _begin__int3x3( void* attributeData ){return mImpl->begin__int3x3();}
bool _data__int3x3( const ParserChar* text, size_t textLength );
bool _end__int3x3(){return mImpl->end__int3x3();}
bool _validateBegin__int3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x3();
bool _freeAttributes__int3x3( void* attributeData );

bool _begin__int3x4( void* attributeData ){return mImpl->begin__int3x4();}
bool _data__int3x4( const ParserChar* text, size_t textLength );
bool _end__int3x4(){return mImpl->end__int3x4();}
bool _validateBegin__int3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int3x4();
bool _freeAttributes__int3x4( void* attributeData );

bool _begin__int4x1( void* attributeData ){return mImpl->begin__int4x1();}
bool _data__int4x1( const ParserChar* text, size_t textLength );
bool _end__int4x1(){return mImpl->end__int4x1();}
bool _validateBegin__int4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x1();
bool _freeAttributes__int4x1( void* attributeData );

bool _begin__int4x2( void* attributeData ){return mImpl->begin__int4x2();}
bool _data__int4x2( const ParserChar* text, size_t textLength );
bool _end__int4x2(){return mImpl->end__int4x2();}
bool _validateBegin__int4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x2();
bool _freeAttributes__int4x2( void* attributeData );

bool _begin__int4x3( void* attributeData ){return mImpl->begin__int4x3();}
bool _data__int4x3( const ParserChar* text, size_t textLength );
bool _end__int4x3(){return mImpl->end__int4x3();}
bool _validateBegin__int4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x3();
bool _freeAttributes__int4x3( void* attributeData );

bool _begin__int4x4( void* attributeData ){return mImpl->begin__int4x4();}
bool _data__int4x4( const ParserChar* text, size_t textLength );
bool _end__int4x4(){return mImpl->end__int4x4();}
bool _validateBegin__int4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__int4x4();
bool _freeAttributes__int4x4( void* attributeData );

bool _begin__half( void* attributeData ){return mImpl->begin__half();}
bool _data__half( const ParserChar* text, size_t textLength );
bool _end__half(){return mImpl->end__half();}
bool _validateBegin__half( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half();
bool _freeAttributes__half( void* attributeData );

bool _begin__half1( void* attributeData ){return mImpl->begin__half1();}
bool _data__half1( const ParserChar* text, size_t textLength );
bool _end__half1(){return mImpl->end__half1();}
bool _validateBegin__half1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half1();
bool _freeAttributes__half1( void* attributeData );

bool _begin__half2( void* attributeData ){return mImpl->begin__half2();}
bool _data__half2( const ParserChar* text, size_t textLength );
bool _end__half2(){return mImpl->end__half2();}
bool _validateBegin__half2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2();
bool _freeAttributes__half2( void* attributeData );

bool _begin__half3( void* attributeData ){return mImpl->begin__half3();}
bool _data__half3( const ParserChar* text, size_t textLength );
bool _end__half3(){return mImpl->end__half3();}
bool _validateBegin__half3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3();
bool _freeAttributes__half3( void* attributeData );

bool _begin__half4( void* attributeData ){return mImpl->begin__half4();}
bool _data__half4( const ParserChar* text, size_t textLength );
bool _end__half4(){return mImpl->end__half4();}
bool _validateBegin__half4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4();
bool _freeAttributes__half4( void* attributeData );

bool _begin__half1x1( void* attributeData ){return mImpl->begin__half1x1();}
bool _data__half1x1( const ParserChar* text, size_t textLength );
bool _end__half1x1(){return mImpl->end__half1x1();}
bool _validateBegin__half1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half1x1();
bool _freeAttributes__half1x1( void* attributeData );

bool _begin__half1x2( void* attributeData ){return mImpl->begin__half1x2();}
bool _data__half1x2( const ParserChar* text, size_t textLength );
bool _end__half1x2(){return mImpl->end__half1x2();}
bool _validateBegin__half1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half1x2();
bool _freeAttributes__half1x2( void* attributeData );

bool _begin__half1x3( void* attributeData ){return mImpl->begin__half1x3();}
bool _data__half1x3( const ParserChar* text, size_t textLength );
bool _end__half1x3(){return mImpl->end__half1x3();}
bool _validateBegin__half1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half1x3();
bool _freeAttributes__half1x3( void* attributeData );

bool _begin__half1x4( void* attributeData ){return mImpl->begin__half1x4();}
bool _data__half1x4( const ParserChar* text, size_t textLength );
bool _end__half1x4(){return mImpl->end__half1x4();}
bool _validateBegin__half1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half1x4();
bool _freeAttributes__half1x4( void* attributeData );

bool _begin__half2x1( void* attributeData ){return mImpl->begin__half2x1();}
bool _data__half2x1( const ParserChar* text, size_t textLength );
bool _end__half2x1(){return mImpl->end__half2x1();}
bool _validateBegin__half2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x1();
bool _freeAttributes__half2x1( void* attributeData );

bool _begin__half2x2( void* attributeData ){return mImpl->begin__half2x2();}
bool _data__half2x2( const ParserChar* text, size_t textLength );
bool _end__half2x2(){return mImpl->end__half2x2();}
bool _validateBegin__half2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x2();
bool _freeAttributes__half2x2( void* attributeData );

bool _begin__half2x3( void* attributeData ){return mImpl->begin__half2x3();}
bool _data__half2x3( const ParserChar* text, size_t textLength );
bool _end__half2x3(){return mImpl->end__half2x3();}
bool _validateBegin__half2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x3();
bool _freeAttributes__half2x3( void* attributeData );

bool _begin__half2x4( void* attributeData ){return mImpl->begin__half2x4();}
bool _data__half2x4( const ParserChar* text, size_t textLength );
bool _end__half2x4(){return mImpl->end__half2x4();}
bool _validateBegin__half2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half2x4();
bool _freeAttributes__half2x4( void* attributeData );

bool _begin__half3x1( void* attributeData ){return mImpl->begin__half3x1();}
bool _data__half3x1( const ParserChar* text, size_t textLength );
bool _end__half3x1(){return mImpl->end__half3x1();}
bool _validateBegin__half3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x1();
bool _freeAttributes__half3x1( void* attributeData );

bool _begin__half3x2( void* attributeData ){return mImpl->begin__half3x2();}
bool _data__half3x2( const ParserChar* text, size_t textLength );
bool _end__half3x2(){return mImpl->end__half3x2();}
bool _validateBegin__half3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x2();
bool _freeAttributes__half3x2( void* attributeData );

bool _begin__half3x3( void* attributeData ){return mImpl->begin__half3x3();}
bool _data__half3x3( const ParserChar* text, size_t textLength );
bool _end__half3x3(){return mImpl->end__half3x3();}
bool _validateBegin__half3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x3();
bool _freeAttributes__half3x3( void* attributeData );

bool _begin__half3x4( void* attributeData ){return mImpl->begin__half3x4();}
bool _data__half3x4( const ParserChar* text, size_t textLength );
bool _end__half3x4(){return mImpl->end__half3x4();}
bool _validateBegin__half3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half3x4();
bool _freeAttributes__half3x4( void* attributeData );

bool _begin__half4x1( void* attributeData ){return mImpl->begin__half4x1();}
bool _data__half4x1( const ParserChar* text, size_t textLength );
bool _end__half4x1(){return mImpl->end__half4x1();}
bool _validateBegin__half4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x1();
bool _freeAttributes__half4x1( void* attributeData );

bool _begin__half4x2( void* attributeData ){return mImpl->begin__half4x2();}
bool _data__half4x2( const ParserChar* text, size_t textLength );
bool _end__half4x2(){return mImpl->end__half4x2();}
bool _validateBegin__half4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x2();
bool _freeAttributes__half4x2( void* attributeData );

bool _begin__half4x3( void* attributeData ){return mImpl->begin__half4x3();}
bool _data__half4x3( const ParserChar* text, size_t textLength );
bool _end__half4x3(){return mImpl->end__half4x3();}
bool _validateBegin__half4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x3();
bool _freeAttributes__half4x3( void* attributeData );

bool _begin__half4x4( void* attributeData ){return mImpl->begin__half4x4();}
bool _data__half4x4( const ParserChar* text, size_t textLength );
bool _end__half4x4(){return mImpl->end__half4x4();}
bool _validateBegin__half4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__half4x4();
bool _freeAttributes__half4x4( void* attributeData );

bool _begin__fixed( void* attributeData ){return mImpl->begin__fixed();}
bool _data__fixed( const ParserChar* text, size_t textLength );
bool _end__fixed(){return mImpl->end__fixed();}
bool _validateBegin__fixed( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed();
bool _freeAttributes__fixed( void* attributeData );

bool _begin__fixed1( void* attributeData ){return mImpl->begin__fixed1();}
bool _data__fixed1( const ParserChar* text, size_t textLength );
bool _end__fixed1(){return mImpl->end__fixed1();}
bool _validateBegin__fixed1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed1();
bool _freeAttributes__fixed1( void* attributeData );

bool _begin__fixed2( void* attributeData ){return mImpl->begin__fixed2();}
bool _data__fixed2( const ParserChar* text, size_t textLength );
bool _end__fixed2(){return mImpl->end__fixed2();}
bool _validateBegin__fixed2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2();
bool _freeAttributes__fixed2( void* attributeData );

bool _begin__fixed3( void* attributeData ){return mImpl->begin__fixed3();}
bool _data__fixed3( const ParserChar* text, size_t textLength );
bool _end__fixed3(){return mImpl->end__fixed3();}
bool _validateBegin__fixed3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3();
bool _freeAttributes__fixed3( void* attributeData );

bool _begin__fixed4( void* attributeData ){return mImpl->begin__fixed4();}
bool _data__fixed4( const ParserChar* text, size_t textLength );
bool _end__fixed4(){return mImpl->end__fixed4();}
bool _validateBegin__fixed4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4();
bool _freeAttributes__fixed4( void* attributeData );

bool _begin__fixed1x1( void* attributeData ){return mImpl->begin__fixed1x1();}
bool _data__fixed1x1( const ParserChar* text, size_t textLength );
bool _end__fixed1x1(){return mImpl->end__fixed1x1();}
bool _validateBegin__fixed1x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed1x1();
bool _freeAttributes__fixed1x1( void* attributeData );

bool _begin__fixed1x2( void* attributeData ){return mImpl->begin__fixed1x2();}
bool _data__fixed1x2( const ParserChar* text, size_t textLength );
bool _end__fixed1x2(){return mImpl->end__fixed1x2();}
bool _validateBegin__fixed1x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed1x2();
bool _freeAttributes__fixed1x2( void* attributeData );

bool _begin__fixed1x3( void* attributeData ){return mImpl->begin__fixed1x3();}
bool _data__fixed1x3( const ParserChar* text, size_t textLength );
bool _end__fixed1x3(){return mImpl->end__fixed1x3();}
bool _validateBegin__fixed1x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed1x3();
bool _freeAttributes__fixed1x3( void* attributeData );

bool _begin__fixed1x4( void* attributeData ){return mImpl->begin__fixed1x4();}
bool _data__fixed1x4( const ParserChar* text, size_t textLength );
bool _end__fixed1x4(){return mImpl->end__fixed1x4();}
bool _validateBegin__fixed1x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed1x4();
bool _freeAttributes__fixed1x4( void* attributeData );

bool _begin__fixed2x1( void* attributeData ){return mImpl->begin__fixed2x1();}
bool _data__fixed2x1( const ParserChar* text, size_t textLength );
bool _end__fixed2x1(){return mImpl->end__fixed2x1();}
bool _validateBegin__fixed2x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x1();
bool _freeAttributes__fixed2x1( void* attributeData );

bool _begin__fixed2x2( void* attributeData ){return mImpl->begin__fixed2x2();}
bool _data__fixed2x2( const ParserChar* text, size_t textLength );
bool _end__fixed2x2(){return mImpl->end__fixed2x2();}
bool _validateBegin__fixed2x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x2();
bool _freeAttributes__fixed2x2( void* attributeData );

bool _begin__fixed2x3( void* attributeData ){return mImpl->begin__fixed2x3();}
bool _data__fixed2x3( const ParserChar* text, size_t textLength );
bool _end__fixed2x3(){return mImpl->end__fixed2x3();}
bool _validateBegin__fixed2x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x3();
bool _freeAttributes__fixed2x3( void* attributeData );

bool _begin__fixed2x4( void* attributeData ){return mImpl->begin__fixed2x4();}
bool _data__fixed2x4( const ParserChar* text, size_t textLength );
bool _end__fixed2x4(){return mImpl->end__fixed2x4();}
bool _validateBegin__fixed2x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed2x4();
bool _freeAttributes__fixed2x4( void* attributeData );

bool _begin__fixed3x1( void* attributeData ){return mImpl->begin__fixed3x1();}
bool _data__fixed3x1( const ParserChar* text, size_t textLength );
bool _end__fixed3x1(){return mImpl->end__fixed3x1();}
bool _validateBegin__fixed3x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x1();
bool _freeAttributes__fixed3x1( void* attributeData );

bool _begin__fixed3x2( void* attributeData ){return mImpl->begin__fixed3x2();}
bool _data__fixed3x2( const ParserChar* text, size_t textLength );
bool _end__fixed3x2(){return mImpl->end__fixed3x2();}
bool _validateBegin__fixed3x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x2();
bool _freeAttributes__fixed3x2( void* attributeData );

bool _begin__fixed3x3( void* attributeData ){return mImpl->begin__fixed3x3();}
bool _data__fixed3x3( const ParserChar* text, size_t textLength );
bool _end__fixed3x3(){return mImpl->end__fixed3x3();}
bool _validateBegin__fixed3x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x3();
bool _freeAttributes__fixed3x3( void* attributeData );

bool _begin__fixed3x4( void* attributeData ){return mImpl->begin__fixed3x4();}
bool _data__fixed3x4( const ParserChar* text, size_t textLength );
bool _end__fixed3x4(){return mImpl->end__fixed3x4();}
bool _validateBegin__fixed3x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed3x4();
bool _freeAttributes__fixed3x4( void* attributeData );

bool _begin__fixed4x1( void* attributeData ){return mImpl->begin__fixed4x1();}
bool _data__fixed4x1( const ParserChar* text, size_t textLength );
bool _end__fixed4x1(){return mImpl->end__fixed4x1();}
bool _validateBegin__fixed4x1( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x1();
bool _freeAttributes__fixed4x1( void* attributeData );

bool _begin__fixed4x2( void* attributeData ){return mImpl->begin__fixed4x2();}
bool _data__fixed4x2( const ParserChar* text, size_t textLength );
bool _end__fixed4x2(){return mImpl->end__fixed4x2();}
bool _validateBegin__fixed4x2( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x2();
bool _freeAttributes__fixed4x2( void* attributeData );

bool _begin__fixed4x3( void* attributeData ){return mImpl->begin__fixed4x3();}
bool _data__fixed4x3( const ParserChar* text, size_t textLength );
bool _end__fixed4x3(){return mImpl->end__fixed4x3();}
bool _validateBegin__fixed4x3( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x3();
bool _freeAttributes__fixed4x3( void* attributeData );

bool _begin__fixed4x4( void* attributeData ){return mImpl->begin__fixed4x4();}
bool _data__fixed4x4( const ParserChar* text, size_t textLength );
bool _end__fixed4x4(){return mImpl->end__fixed4x4();}
bool _validateBegin__fixed4x4( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__fixed4x4();
bool _freeAttributes__fixed4x4( void* attributeData );

bool _begin__surface____cg_surface_type( void* attributeData ){return mImpl->begin__surface____cg_surface_type(*static_cast<surface____cg_surface_type__AttributeData*>(attributeData));}
bool _data__surface____cg_surface_type( const ParserChar* text, size_t textLength );
bool _end__surface____cg_surface_type(){return mImpl->end__surface____cg_surface_type();}
bool _validateBegin__surface____cg_surface_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__surface____cg_surface_type();
bool _freeAttributes__surface____cg_surface_type( void* attributeData );

bool _begin__cg_surface_type____generator( void* attributeData ){return mImpl->begin__cg_surface_type____generator();}
bool _data__cg_surface_type____generator( const ParserChar* text, size_t textLength );
bool _end__cg_surface_type____generator(){return mImpl->end__cg_surface_type____generator();}
bool _validateBegin__cg_surface_type____generator( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__cg_surface_type____generator();
bool _freeAttributes__cg_surface_type____generator( void* attributeData );

bool _begin__profile_CG__newparam__surface__generator__name( void* attributeData ){return mImpl->begin__profile_CG__newparam__surface__generator__name(*static_cast<profile_CG__newparam__surface__generator__name__AttributeData*>(attributeData));}
bool _data__profile_CG__newparam__surface__generator__name( const ParserChar* text, size_t textLength );
bool _end__profile_CG__newparam__surface__generator__name(){return mImpl->end__profile_CG__newparam__surface__generator__name();}
bool _validateBegin__profile_CG__newparam__surface__generator__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__newparam__surface__generator__name();
bool _freeAttributes__profile_CG__newparam__surface__generator__name( void* attributeData );

bool _begin__setparam____cg_setparam_simple( void* attributeData ){return mImpl->begin__setparam____cg_setparam_simple(*static_cast<setparam____cg_setparam_simple__AttributeData*>(attributeData));}
bool _data__setparam____cg_setparam_simple( const ParserChar* text, size_t textLength );
bool _end__setparam____cg_setparam_simple(){return mImpl->end__setparam____cg_setparam_simple();}
bool _validateBegin__setparam____cg_setparam_simple( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____cg_setparam_simple();
bool _freeAttributes__setparam____cg_setparam_simple( void* attributeData );

bool _begin__sampler1D____cg_sampler1D( void* attributeData ){return mImpl->begin__sampler1D____cg_sampler1D();}
bool _data__sampler1D____cg_sampler1D( const ParserChar* text, size_t textLength );
bool _end__sampler1D____cg_sampler1D(){return mImpl->end__sampler1D____cg_sampler1D();}
bool _validateBegin__sampler1D____cg_sampler1D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler1D____cg_sampler1D();
bool _freeAttributes__sampler1D____cg_sampler1D( void* attributeData );

bool _begin__sampler2D____cg_sampler2D( void* attributeData ){return mImpl->begin__sampler2D____cg_sampler2D();}
bool _data__sampler2D____cg_sampler2D( const ParserChar* text, size_t textLength );
bool _end__sampler2D____cg_sampler2D(){return mImpl->end__sampler2D____cg_sampler2D();}
bool _validateBegin__sampler2D____cg_sampler2D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler2D____cg_sampler2D();
bool _freeAttributes__sampler2D____cg_sampler2D( void* attributeData );

bool _begin__sampler3D____cg_sampler3D( void* attributeData ){return mImpl->begin__sampler3D____cg_sampler3D();}
bool _data__sampler3D____cg_sampler3D( const ParserChar* text, size_t textLength );
bool _end__sampler3D____cg_sampler3D(){return mImpl->end__sampler3D____cg_sampler3D();}
bool _validateBegin__sampler3D____cg_sampler3D( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__sampler3D____cg_sampler3D();
bool _freeAttributes__sampler3D____cg_sampler3D( void* attributeData );

bool _begin__samplerRECT____cg_samplerRECT( void* attributeData ){return mImpl->begin__samplerRECT____cg_samplerRECT();}
bool _data__samplerRECT____cg_samplerRECT( const ParserChar* text, size_t textLength );
bool _end__samplerRECT____cg_samplerRECT(){return mImpl->end__samplerRECT____cg_samplerRECT();}
bool _validateBegin__samplerRECT____cg_samplerRECT( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerRECT____cg_samplerRECT();
bool _freeAttributes__samplerRECT____cg_samplerRECT( void* attributeData );

bool _begin__samplerCUBE____cg_samplerCUBE( void* attributeData ){return mImpl->begin__samplerCUBE____cg_samplerCUBE();}
bool _data__samplerCUBE____cg_samplerCUBE( const ParserChar* text, size_t textLength );
bool _end__samplerCUBE____cg_samplerCUBE(){return mImpl->end__samplerCUBE____cg_samplerCUBE();}
bool _validateBegin__samplerCUBE____cg_samplerCUBE( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerCUBE____cg_samplerCUBE();
bool _freeAttributes__samplerCUBE____cg_samplerCUBE( void* attributeData );

bool _begin__samplerDEPTH____cg_samplerDEPTH( void* attributeData ){return mImpl->begin__samplerDEPTH____cg_samplerDEPTH();}
bool _data__samplerDEPTH____cg_samplerDEPTH( const ParserChar* text, size_t textLength );
bool _end__samplerDEPTH____cg_samplerDEPTH(){return mImpl->end__samplerDEPTH____cg_samplerDEPTH();}
bool _validateBegin__samplerDEPTH____cg_samplerDEPTH( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__samplerDEPTH____cg_samplerDEPTH();
bool _freeAttributes__samplerDEPTH____cg_samplerDEPTH( void* attributeData );

bool _begin__usertype( void* attributeData ){return mImpl->begin__usertype(*static_cast<usertype__AttributeData*>(attributeData));}
bool _data__usertype( const ParserChar* text, size_t textLength );
bool _end__usertype(){return mImpl->end__usertype();}
bool _validateBegin__usertype( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__usertype();
bool _freeAttributes__usertype( void* attributeData );

bool _begin__array____cg_setarray_type( void* attributeData ){return mImpl->begin__array____cg_setarray_type(*static_cast<array____cg_setarray_type__AttributeData*>(attributeData));}
bool _data__array____cg_setarray_type( const ParserChar* text, size_t textLength );
bool _end__array____cg_setarray_type(){return mImpl->end__array____cg_setarray_type();}
bool _validateBegin__array____cg_setarray_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____cg_setarray_type();
bool _freeAttributes__array____cg_setarray_type( void* attributeData );

bool _begin__connect_param( void* attributeData ){return mImpl->begin__connect_param(*static_cast<connect_param__AttributeData*>(attributeData));}
bool _data__connect_param( const ParserChar* text, size_t textLength );
bool _end__connect_param(){return mImpl->end__connect_param();}
bool _validateBegin__connect_param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__connect_param();
bool _freeAttributes__connect_param( void* attributeData );

bool _begin__setparam____cg_setparam( void* attributeData ){return mImpl->begin__setparam____cg_setparam(*static_cast<setparam____cg_setparam__AttributeData*>(attributeData));}
bool _data__setparam____cg_setparam( const ParserChar* text, size_t textLength );
bool _end__setparam____cg_setparam(){return mImpl->end__setparam____cg_setparam();}
bool _validateBegin__setparam____cg_setparam( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__setparam____cg_setparam();
bool _freeAttributes__setparam____cg_setparam( void* attributeData );

bool _begin__array____cg_newarray_type( void* attributeData ){return mImpl->begin__array____cg_newarray_type(*static_cast<array____cg_newarray_type__AttributeData*>(attributeData));}
bool _data__array____cg_newarray_type( const ParserChar* text, size_t textLength );
bool _end__array____cg_newarray_type(){return mImpl->end__array____cg_newarray_type();}
bool _validateBegin__array____cg_newarray_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__array____cg_newarray_type();
bool _freeAttributes__array____cg_newarray_type( void* attributeData );

bool _begin__profile_CG__technique( void* attributeData ){return mImpl->begin__profile_CG__technique(*static_cast<profile_CG__technique__AttributeData*>(attributeData));}
bool _data__profile_CG__technique( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique(){return mImpl->end__profile_CG__technique();}
bool _validateBegin__profile_CG__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique();
bool _freeAttributes__profile_CG__technique( void* attributeData );

bool _begin__profile_CG__technique__pass( void* attributeData ){return mImpl->begin__profile_CG__technique__pass(*static_cast<profile_CG__technique__pass__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass(){return mImpl->end__profile_CG__technique__pass();}
bool _validateBegin__profile_CG__technique__pass( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass();
bool _freeAttributes__profile_CG__technique__pass( void* attributeData );

bool _begin__profile_CG__technique__pass__shader( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__shader(*static_cast<profile_CG__technique__pass__shader__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__shader( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__shader(){return mImpl->end__profile_CG__technique__pass__shader();}
bool _validateBegin__profile_CG__technique__pass__shader( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__shader();
bool _freeAttributes__profile_CG__technique__pass__shader( void* attributeData );


ENUM__cg_pipeline_stage toEnumDataPrefix_ENUM__cg_pipeline_stage (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__cg_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__cg_pipeline_stage (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__cg_pipeline_stage*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__cg_pipeline_stage (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__cg_pipeline_stage*, size_t ),
    const std::pair<StringHash, ENUM__cg_pipeline_stage>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__cg_pipeline_stage (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__cg_pipeline_stage>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__profile_CG__technique__pass__shader__compiler_target( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__shader__compiler_target();}
bool _data__profile_CG__technique__pass__shader__compiler_target( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__shader__compiler_target(){return mImpl->end__profile_CG__technique__pass__shader__compiler_target();}
bool _validateBegin__profile_CG__technique__pass__shader__compiler_target( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__shader__compiler_target();
bool _freeAttributes__profile_CG__technique__pass__shader__compiler_target( void* attributeData );

bool _begin__profile_CG__technique__pass__shader__name( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__shader__name(*static_cast<profile_CG__technique__pass__shader__name__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__shader__name( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__shader__name(){return mImpl->end__profile_CG__technique__pass__shader__name();}
bool _validateBegin__profile_CG__technique__pass__shader__name( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__shader__name();
bool _freeAttributes__profile_CG__technique__pass__shader__name( void* attributeData );

bool _begin__profile_CG__technique__pass__shader__bind( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__shader__bind(*static_cast<profile_CG__technique__pass__shader__bind__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__shader__bind( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__shader__bind(){return mImpl->end__profile_CG__technique__pass__shader__bind();}
bool _validateBegin__profile_CG__technique__pass__shader__bind( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__shader__bind();
bool _freeAttributes__profile_CG__technique__pass__shader__bind( void* attributeData );

bool _begin__profile_CG__technique__pass__shader__bind__param( void* attributeData ){return mImpl->begin__profile_CG__technique__pass__shader__bind__param(*static_cast<profile_CG__technique__pass__shader__bind__param__AttributeData*>(attributeData));}
bool _data__profile_CG__technique__pass__shader__bind__param( const ParserChar* text, size_t textLength );
bool _end__profile_CG__technique__pass__shader__bind__param(){return mImpl->end__profile_CG__technique__pass__shader__bind__param();}
bool _validateBegin__profile_CG__technique__pass__shader__bind__param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_CG__technique__pass__shader__bind__param();
bool _freeAttributes__profile_CG__technique__pass__shader__bind__param( void* attributeData );

bool _begin__profile_COMMON( void* attributeData ){return mImpl->begin__profile_COMMON(*static_cast<profile_COMMON__AttributeData*>(attributeData));}
bool _data__profile_COMMON( const ParserChar* text, size_t textLength );
bool _end__profile_COMMON(){return mImpl->end__profile_COMMON();}
bool _validateBegin__profile_COMMON( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_COMMON();
bool _freeAttributes__profile_COMMON( void* attributeData );

bool _begin__newparam____common_newparam_type( void* attributeData ){return mImpl->begin__newparam____common_newparam_type(*static_cast<newparam____common_newparam_type__AttributeData*>(attributeData));}
bool _data__newparam____common_newparam_type( const ParserChar* text, size_t textLength );
bool _end__newparam____common_newparam_type(){return mImpl->end__newparam____common_newparam_type();}
bool _validateBegin__newparam____common_newparam_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__newparam____common_newparam_type();
bool _freeAttributes__newparam____common_newparam_type( void* attributeData );

bool _begin__profile_COMMON__technique( void* attributeData ){return mImpl->begin__profile_COMMON__technique(*static_cast<profile_COMMON__technique__AttributeData*>(attributeData));}
bool _data__profile_COMMON__technique( const ParserChar* text, size_t textLength );
bool _end__profile_COMMON__technique(){return mImpl->end__profile_COMMON__technique();}
bool _validateBegin__profile_COMMON__technique( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_COMMON__technique();
bool _freeAttributes__profile_COMMON__technique( void* attributeData );

bool _begin__profile_COMMON__technique__constant( void* attributeData ){return mImpl->begin__profile_COMMON__technique__constant();}
bool _data__profile_COMMON__technique__constant( const ParserChar* text, size_t textLength );
bool _end__profile_COMMON__technique__constant(){return mImpl->end__profile_COMMON__technique__constant();}
bool _validateBegin__profile_COMMON__technique__constant( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__profile_COMMON__technique__constant();
bool _freeAttributes__profile_COMMON__technique__constant( void* attributeData );

bool _begin__emission( void* attributeData ){return mImpl->begin__emission();}
bool _data__emission( const ParserChar* text, size_t textLength );
bool _end__emission(){return mImpl->end__emission();}
bool _validateBegin__emission( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__emission();
bool _freeAttributes__emission( void* attributeData );

bool _begin__common_color_or_texture_type____color( void* attributeData ){return mImpl->begin__common_color_or_texture_type____color(*static_cast<common_color_or_texture_type____color__AttributeData*>(attributeData));}
bool _data__common_color_or_texture_type____color( const ParserChar* text, size_t textLength );
bool _end__common_color_or_texture_type____color(){return mImpl->end__common_color_or_texture_type____color();}
bool _validateBegin__common_color_or_texture_type____color( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__common_color_or_texture_type____color();
bool _freeAttributes__common_color_or_texture_type____color( void* attributeData );

bool _begin__common_color_or_texture_type____param( void* attributeData ){return mImpl->begin__common_color_or_texture_type____param(*static_cast<common_color_or_texture_type____param__AttributeData*>(attributeData));}
bool _data__common_color_or_texture_type____param( const ParserChar* text, size_t textLength );
bool _end__common_color_or_texture_type____param(){return mImpl->end__common_color_or_texture_type____param();}
bool _validateBegin__common_color_or_texture_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__common_color_or_texture_type____param();
bool _freeAttributes__common_color_or_texture_type____param( void* attributeData );

bool _begin__texture( void* attributeData ){return mImpl->begin__texture(*static_cast<texture__AttributeData*>(attributeData));}
bool _data__texture( const ParserChar* text, size_t textLength );
bool _end__texture(){return mImpl->end__texture();}
bool _validateBegin__texture( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__texture();
bool _freeAttributes__texture( void* attributeData );

bool _begin__reflective( void* attributeData ){return mImpl->begin__reflective();}
bool _data__reflective( const ParserChar* text, size_t textLength );
bool _end__reflective(){return mImpl->end__reflective();}
bool _validateBegin__reflective( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__reflective();
bool _freeAttributes__reflective( void* attributeData );

bool _begin__reflectivity( void* attributeData ){return mImpl->begin__reflectivity();}
bool _data__reflectivity( const ParserChar* text, size_t textLength );
bool _end__reflectivity(){return mImpl->end__reflectivity();}
bool _validateBegin__reflectivity( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__reflectivity();
bool _freeAttributes__reflectivity( void* attributeData );

bool _begin__common_float_or_param_type____float( void* attributeData ){return mImpl->begin__common_float_or_param_type____float(*static_cast<common_float_or_param_type____float__AttributeData*>(attributeData));}
bool _data__common_float_or_param_type____float( const ParserChar* text, size_t textLength );
bool _end__common_float_or_param_type____float(){return mImpl->end__common_float_or_param_type____float();}
bool _validateBegin__common_float_or_param_type____float( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__common_float_or_param_type____float();
bool _freeAttributes__common_float_or_param_type____float( void* attributeData );

bool _begin__common_float_or_param_type____param( void* attributeData ){return mImpl->begin__common_float_or_param_type____param(*static_cast<common_float_or_param_type____param__AttributeData*>(attributeData));}
bool _data__common_float_or_param_type____param( const ParserChar* text, size_t textLength );
bool _end__common_float_or_param_type____param(){return mImpl->end__common_float_or_param_type____param();}
bool _validateBegin__common_float_or_param_type____param( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__common_float_or_param_type____param();
bool _freeAttributes__common_float_or_param_type____param( void* attributeData );

bool _begin__transparent( void* attributeData ){return mImpl->begin__transparent(*static_cast<transparent__AttributeData*>(attributeData));}
bool _data__transparent( const ParserChar* text, size_t textLength );
bool _end__transparent(){return mImpl->end__transparent();}
bool _validateBegin__transparent( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__transparent();
bool _freeAttributes__transparent( void* attributeData );


ENUM__fx_opaque_enum toEnumDataPrefix_ENUM__fx_opaque_enum (
    const ParserChar* prefixedBuffer,
    const ParserChar* prefixedBufferEnd,
    const ParserChar** buffer,
    const ParserChar* bufferEnd,
    bool& failed,
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool characterData2EnumData_ENUM__fx_opaque_enum (
    const ParserChar* text,
    size_t textLength,
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_opaque_enum*, size_t ),
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& )
);


bool dataEnumEnd_ENUM__fx_opaque_enum (
    bool ( ColladaParserAutoGen::*dataFunction )(const ENUM__fx_opaque_enum*, size_t ),
    const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap,
    StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ),
    ENUM__fx_opaque_enum (*toEnumFunc)( const ParserChar**, const ParserChar*, bool&, const std::pair<StringHash, ENUM__fx_opaque_enum>* enumMap, StringHash (*baseConversionFunc)( const ParserChar**, const ParserChar*, bool& ))
);



bool _begin__transparency( void* attributeData ){return mImpl->begin__transparency();}
bool _data__transparency( const ParserChar* text, size_t textLength );
bool _end__transparency(){return mImpl->end__transparency();}
bool _validateBegin__transparency( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__transparency();
bool _freeAttributes__transparency( void* attributeData );

bool _begin__index_of_refraction( void* attributeData ){return mImpl->begin__index_of_refraction();}
bool _data__index_of_refraction( const ParserChar* text, size_t textLength );
bool _end__index_of_refraction(){return mImpl->end__index_of_refraction();}
bool _validateBegin__index_of_refraction( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__index_of_refraction();
bool _freeAttributes__index_of_refraction( void* attributeData );

bool _begin__lambert( void* attributeData ){return mImpl->begin__lambert();}
bool _data__lambert( const ParserChar* text, size_t textLength );
bool _end__lambert(){return mImpl->end__lambert();}
bool _validateBegin__lambert( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__lambert();
bool _freeAttributes__lambert( void* attributeData );

bool _begin__ambient____common_color_or_texture_type( void* attributeData ){return mImpl->begin__ambient____common_color_or_texture_type();}
bool _data__ambient____common_color_or_texture_type( const ParserChar* text, size_t textLength );
bool _end__ambient____common_color_or_texture_type(){return mImpl->end__ambient____common_color_or_texture_type();}
bool _validateBegin__ambient____common_color_or_texture_type( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__ambient____common_color_or_texture_type();
bool _freeAttributes__ambient____common_color_or_texture_type( void* attributeData );

bool _begin__diffuse( void* attributeData ){return mImpl->begin__diffuse();}
bool _data__diffuse( const ParserChar* text, size_t textLength );
bool _end__diffuse(){return mImpl->end__diffuse();}
bool _validateBegin__diffuse( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__diffuse();
bool _freeAttributes__diffuse( void* attributeData );

bool _begin__phong( void* attributeData ){return mImpl->begin__phong();}
bool _data__phong( const ParserChar* text, size_t textLength );
bool _end__phong(){return mImpl->end__phong();}
bool _validateBegin__phong( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__phong();
bool _freeAttributes__phong( void* attributeData );

bool _begin__specular( void* attributeData ){return mImpl->begin__specular();}
bool _data__specular( const ParserChar* text, size_t textLength );
bool _end__specular(){return mImpl->end__specular();}
bool _validateBegin__specular( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__specular();
bool _freeAttributes__specular( void* attributeData );

bool _begin__shininess( void* attributeData ){return mImpl->begin__shininess();}
bool _data__shininess( const ParserChar* text, size_t textLength );
bool _end__shininess(){return mImpl->end__shininess();}
bool _validateBegin__shininess( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__shininess();
bool _freeAttributes__shininess( void* attributeData );

bool _begin__blinn( void* attributeData ){return mImpl->begin__blinn();}
bool _data__blinn( const ParserChar* text, size_t textLength );
bool _end__blinn(){return mImpl->end__blinn();}
bool _validateBegin__blinn( const ParserAttributes& attributes, void ** attributeDataPtr, void ** validationDataPtr );
bool _validateEnd__blinn();
bool _freeAttributes__blinn( void* attributeData );



private:
/** Disable default copy ctor. */
ColladaParserAutoGenPrivate( const ColladaParserAutoGenPrivate& pre );
/** Disable default assignment operator. */
const ColladaParserAutoGenPrivate& operator= ( const ColladaParserAutoGenPrivate& pre );

void initFunctionMap();
void initNameMap();

protected:
virtual bool findElementHash( ElementData& elementData );

};

} // namespace
#endif
